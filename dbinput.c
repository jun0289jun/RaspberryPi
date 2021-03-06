#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAXTIMINGS    85
#define DHTPIN        7  //wPi pin. physical num 7
int dht11_dat[5] = { 0, 0, 0, 0, 0 };
 
int read_dht11_dat(int *temp, int *humidity)
{
    uint8_t laststate    = 0;
    uint8_t counter        = 0;
    uint8_t j        = 0, i;
    float    f; 
 
    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
 
    pinMode( DHTPIN, OUTPUT );
	digitalWrite( DHTPIN, HIGH );
	delay( 50 );
    digitalWrite( DHTPIN, LOW );
    delay( 20 );
    digitalWrite( DHTPIN, HIGH );
    delayMicroseconds( 30 );
    pinMode( DHTPIN, INPUT );
	delayMicroseconds( 20 );
 
    for ( i = 0; i < 82; i++ )
    {
        counter = 0;
        while ( digitalRead( DHTPIN ) == laststate )
        {
            counter++;
            delayMicroseconds( 1 );
            if ( counter == 255 )
            {
               // printf("%d번째 %d 신호읽기 에러 \n", i,(int)laststate);
				break;
            }
        }
        laststate = digitalRead( DHTPIN );
 
        if ( counter == 255 )
            break;
 
        if ( (i >= 3) && (i % 2 == 1) )
        {
            dht11_dat[j / 8] <<= 1;
            if ( counter > 50 )
                dht11_dat[j / 8] |= 1;
            j++;
        }
    }
 
    if ( (j >= 40) &&
         (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
    {
        f = dht11_dat[2] * 9. / 5. + 32;
        printf( "Humidity = %d.%d %% Temperature = %d.%d C (%.1f F)\n",
            dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f );
			*humidity = dht11_dat[0];
			*temp = dht11_dat[2];
			return 0;
			
    }else  {
        printf( "Data not good, skip\n" );
		return -1;
    }
}
 
int main( void )
{
    printf( "Raspberry Pi wiringPi DHT11 Temperature test program\n" );
 
    if ( wiringPiSetup() == -1 )
        exit( 1 );
 
    while ( 1 )
    {
        int temp=0,humidity=0;
			if (read_dht11_dat(&temp,&humidity) ==0){
				printf("Temperature = %d, Humidity = %d",temp,humidity);
			}
		delay( 2000 ); 
    }
 
    return(0);
}