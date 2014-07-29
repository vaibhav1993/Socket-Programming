//prime check between server and client....cient Program
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#define serv_tcp_port 4270
#define serv_host_addr "10.10.131.132"
main()
{

int i,sid;
char buff[20];
char bf[20];
char buff1[200];
struct sockaddr_in servaddr;
sid=socket(AF_INET,SOCK_STREAM,0);
if(sid>0)
printf("success");

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);
connect(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));

printf("enter the number of numbers you want to check");
scanf("%s",&bf);

send(sid,bf,sizeof(bf),0);

int n = atoi(bf);

for(i=0;i<n;i++)
{
	printf("enter the number");
	scanf("%s",&buff);
	send(sid,buff,20,0);
recv(sid,buff1,sizeof(buff1),0);
printf("Result is:%s\n",buff1);
}
close(sid);
}
