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
char buff[10];
struct sockaddr_in servaddr;
struct sockaddr_in clienaddr;
int fp;
sid=socket(AF_INET, SOCK_STREAM, 0);

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

s=bind(sid,(struct sockaddr *)& servaddr,sizeof(servaddr));

listen(sid,1);

clien=sizeof(clienaddr);

nsid=accept(sid,(struct sockaddr *)& clienaddr, &clien);

fp= open("samp2.txt",O_CREAT|O_WRONLY ));

if(fp>0)
{
while(read(nsid,buff,sizeof(buff))>0)
write(fp,buff,strlen(buff));
close(fp);
}
close(nsid);
}
