//Decryption at server side
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#define serv_tcp_port 6754
#define serv_host_addr "127.0.0.1"

main()
{
int i,s,sid,nsid,clien;
char buff[20];
struct sockaddr_in servaddr;
struct sockaddr_in clienaddr;

sid=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

s=bind(sid,(struct sockaddr *)& servaddr,sizeof(servaddr));

listen(sid,1);

clien=sizeof(clienaddr);
nsid=accept(sid,(struct sockaddr *)& clienaddr,&clien);
recv(nsid,buff,sizeof(buff),0);
printf("encrypted string is %s ",buff);
for(i=0;i<strlen(buff);i++)
{
if(buff[i]=='a')
buff[i]=buff[i]+25;
else
buff[i]=buff[i]-1;
}

printf("decrypted string %s ",buff);
send(nsid,buff,sizeof(buff),0);
close(nsid);
}

