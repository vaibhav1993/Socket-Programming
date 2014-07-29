//Encryption at client side
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#define serv_tcp_port 6754
#define serv_host_addr "127.0.0.1"

main()
{
int i,sid;
char buff[20];
struct sockaddr_in servaddr;
sid=socket(AF_INET,SOCK_STREAM,0);

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);

connect(sid,(struct sockaddr *)& servaddr,sizeof(servaddr));
printf("enter the string");
scanf("%s",&buff);

for(i=0;i<strlen(buff);i++)
{
if(buff[i]=='z')
buff[i]=buff[i]-25;
else
buff[i]=buff[i]+1;
}
printf("encrypted string is %s ",buff);
send(sid,buff,sizeof(buff),0);

recv(sid,buff,sizeof(buff),0);
printf("Decrypted string is %s",buff);
close(sid);
}
