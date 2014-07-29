#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define serv_tcp_port 7375
#define serv_host_addr "10.10.131.132"

main()
{
int s,sid,clien,nsid;
char buff[100];
struct sockaddr_in servaddr;
int fp;
sid=socket(AF_INET, SOCK_STREAM, 0);

if(sid>0)
printf("Succes");

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);

connect(sid,(struct sockaddr*)& servaddr,sizeof(servaddr));
//printf("enter the content");
//scanf("%s",buff);

fp=open("sample.txt",O_RDONLY);
if(fp>0)
{
while(read(fp,buff,sizeof(buff))>0)
write(sid,buff,strlen(buff));
printf("success Done");
close(fp);
}
close(sid);
}
