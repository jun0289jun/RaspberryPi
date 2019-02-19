#include <stdio.h>
#include <mysql.h>

void main() {

int temp=24,humi=40;
char query[1024];


MYSQL *connector;

connector = mysql_init(NULL);

if(!mysql_real_connect(connector,"192.168.0.20","aaa","bbb","raspberry",3306,NULL,0)) {
	printf("fail");
}
printf("success");

sprintf(query,"insert into dht11 values(%d,%d,now())",temp,humi);

if(mysql_query(connector,query)==0)
	printf("success");
else
	printf("fail");

mysql_close(connector);
}
