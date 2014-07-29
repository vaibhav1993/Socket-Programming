//prime number check between server and client
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define serv_tcp_port 4270
#define serv_host_addr "10.10.131.132"
main()
{
int i,j,s,sid,pid,clien,nsid,count;
char buff[20];
char bf[20];
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
recv(nsid,bf,sizeof(bf),0);
int n= atoi(bf);
for(i=0;i<n;i++)
{
	recv(nsid,buff,sizeof(buff),0);
	int temp = atoi(buff);
	count=0;
	for(j=2;j<temp;j++)
	{
		if(temp%j==0)
		count++;
	}
	if(count==0)
	send(nsid,"prime",20,0);
	else
	send(nsid,"not prime",20,0);
}
close(nsid);
}
