import spidev#spidev module 추가
import time#time module 추가

dig_T=[]#온도 교정 값을 위한 빈 리스트 생성
dig_P=[]#기압 교정 값을 위한 빈 리스트 생성

def ReadReg(addr):#Addr을 가져와서 센서 레지스터를 읽는 함수
    addr = addr | 0x80#레지스터 읽기 위해 최상위 비트 MSB를 1로 설정
    dummy = 0xFF#SPI에서 데이타를 보내는 방식
    val = spi.xfer2([addr, dummy])#2개 데이타 전송이므로 2개 데이타 수신 
    return val[1]#두 번째 데이타가 유효
def ResetDevice():							
    addr=0xE0 & 0x80#센서를 리셋
    data = 0xB6#레지스터에 값을 쓰기 위해 MSB를 0으로 설정
    spi.xfer2([addr, data])
    #데이타 쓰기. spi.xfer2([a,b]) a, b 변수값을 리스트 형태로 차례로 전송

def ReadTempPressure():#기압과 온도를 읽는 함수
    adc_T=(ReadReg (0XFA) << 12) (ReadReg(0XFB) << 4) | ReadReg(0xFC)
    # adc_T 온도변수
    adc_P=(ReadReg(0XF7) << 12) | (ReadReg(0XF8) << 4) | ReadReg(0XF9)
    # adc_P 기압변수

    # 온도계산
    var1=(adc_T/16384 - dig_T[0]/1024) * dig_T[1]
    var2=pow(adc_T/131072 -dig_T[0]/8192,2) *dig_T[2]
    t_fine=var1+var2
    temp=(var1+var2)/5120

    # 압력 계산 
    var1=t_fine/2 -64000
    var2=var1*var1*dig_P[5]/32768
    var2=var2+vari*dig_P[4]*2
    var2=var2/4 + dig_P[3] * 65536
    var1=(dig_P[2] *var1*var1/524288+dig_P[1]*var1)/524288
    var1=(1+var1/32768) *dig_P[0]

    if var1 ==0:
        print('vari should not bo zero')
        return [0,0]

    p=1048576 - adc_P
    p= (p-var2/4096) * 6250 /vari
    var1= dig_P[8] * p * p /2147483648
    var2=p*dig_P[7]/32768
    p=p+(var1 + var2 + dig_P[6])/16

    return [temp,p]

def ReadCalibrationData():# Read calibration data for temperature
    dig_T.append((ReadReg(0x89)<<8) | ReadReg(0x88))# dig_T[0]
    dig_T.append((ReadReg(0X8B)<<8) | ReadReg(0x8A))# dig_T[1]
    dig_T.append((ReadReg(0x8D)<<8) | ReadReg(0x8C))# dig_T[2]

    dig_P.append((ReadReg(0x8F)<<8) | ReadReg(0x8E))# dig_P[0]
    dig_P.append((ReadReg(0x91)<<8) | ReadReg(0x90))# dig_P[1]
    dig_P.append((ReadReg(0x93)<<8) | ReadReg(0x92))# dig_P[2]
    dig_P.append((ReadReg(0x95)<<8) | ReadReg(0x94))# dig_P[3]
    dig_P.append((ReadReg(0x97)<<8) | ReadReg(0x96))# dig P[4]
    dig_P.append((ReadReg(0x99)<<8) | ReadReg(0x98))# dig P[5]
    dig_P.append((ReadReg(0x9B)<<8) | ReadReg(0x9A))# dig P[6]
    dig_P.append((ReadReg(0x9D)<<8) | ReadReg(0x9C))# dig P[7]
    dig_P.append((ReadReg(0x9F)<<8) | ReadReg(0x9E))# dig P[8]

    for k in range(1, len(dig_T)):
        if dig_T[k] >= 32768:
            dig_T[k]=-65536 + dig_T[k]

    for k in range(1, len(dig_P)):
        if dig_P[k] >= 32768:
            dig_P[k]=-65536 + dig_P[k]

def SetCtrlMeasure():#샘플링 및 동작모드 설정
    addr = 0xF4 & ~ 0x80
    data = (0x2 << 5) | (0x2 << 2) | 0x3
    spi.xfer2([addr,data])

#실제 동작을 위한 메인 코드
def ReadDeviceID():#디바이스 정보 읽음(0x58)
    id=ReadReg(0xD0)
    return id

# SPI 객체 생성
spi = spidev.SpiDev()#SPI는 객체를 지시하는 변수
#장치열기
spi.open(0,1)#0번 버스 및 1번 (CE1) 채널 선택
#라즈베리 파이에는 0번 버스만 있고, 0번 버스에 0번과 1번 채널이 있음
spi.max_speed_hz = 1*1000*1000#1MHz SPI Clok 속도 설정
spi.mode=0#spi mode(0), mode 3도 가능
#전송모드 설정(극성과 위상에 따른 4가지 선택모드중 SPI장치에 맞는 모드 선택)

ResetDevice()
time.sleep(0.01)

SetCtrlMeasure()
time.sleep(0.01)

ReadCalibrationData()#레지스터에 저장된 교정 데이타 읽음

try:
    while True:
        [temp,pressure]=ReadTempPressure()
        print(round(temp,2), 'c', '\t', end='')
        print(round(pressure),'Pa', '\t')
        time.sleep(1)

except keyboardInterrupt:
    print('SPI is closed...')
    #장치닫기
    spi.close()
