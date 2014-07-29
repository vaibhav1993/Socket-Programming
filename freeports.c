//no of free ports
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

int main()
{
int sid;
char hostname[800];
struct sockaddr_in servaddr;
struct hostent *host;
struct in_addr address;
int port;

gethostname(hostname, sizeof(hostname));
host=gethostbyname(hostname);
address.s_addr = *(unsigned long *)host->h_addr;

for(port=0;port<=50000;port++)
{
sid=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(port);
servaddr.sin_addr.s_addr=inet_addr(inet_ntoa(address));

if(connect(sid,(struct sockaddr *)& servaddr,sizeof(servaddr))!=-1)
{
printf("%d\n",port);
}
}
close(sid);
}

