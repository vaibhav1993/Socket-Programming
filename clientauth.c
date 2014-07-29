//client side authentication
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#define serv_tcp_port 5002
#define serv_host_addr "10.10.131.132"
main()
{
char msgg[120];
int s,sid,clien,nsid;
char buff[20],rep;
char msg[120];
char usr[20]; char pass[20];
struct sockaddr_in servaddr;
sid=socket(AF_INET,SOCK_STREAM,0);
if(sid>0)
printf("success");
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);
connect(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));
printf(" enter the message\n");
scanf("%s",&buff);
send(sid,buff,20,0);
recv(sid,msg,sizeof(msg),0);
printf("username  :\n");
scanf("%s",&usr);
printf("password :\n");
scanf("%s",&pass);
send(sid,usr,sizeof(usr),0);
send(sid,pass,sizeof(pass),0);
recv(sid,msgg,sizeof(msgg),0);
printf("%s",msgg);
close(sid);
}
