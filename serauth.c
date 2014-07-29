//server authentication
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define serv_tcp_port 5002
#define serv_host_addr "10.10.131.132"
main()
{


char username[20]="hello";
char password[20]="hello";
char msgg[120]="wrong username and password";
char usr[20];
char msg[120]="enter username and password";
char pass[20];
int s,sid,pid,clien,nsid;
char buff[20];
struct sockaddr_in servaddr;
struct sockaddr_in clienaddr;
sid=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(serv_tcp_port);

s=bind(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));
listen(sid,1);
clien=sizeof(clienaddr);

nsid=accept(sid,(struct sockaddr *)&clienaddr,&clien);

recv(nsid,buff,sizeof(buff),0);


send(nsid,msg,sizeof(msg),0);

recv(nsid,usr,sizeof(usr),0);
recv(nsid,pass,sizeof(pass),0);



if(strcmp(usr,username)==0)
{
if(strcmp(pass,password)==0)
{
printf("authentication done !");
}
else
{
send(nsid,msgg,sizeof(msgg),0);
}
}
else
{
send(nsid,msgg,sizeof(msgg),0);
}
close(nsid);
}
