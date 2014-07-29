// display server date and time on client... SERVER Program
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>
#define serv_tcp_port 5286
#define serv_host_addr "10.10.131.132"

main()
{
time_t tick;
int s,sid,pid,clien,nsid;
char buff[20];
struct sockaddr_in seraddr;
struct sockaddr_in cliaddr;

sid = socket(AF_INET, SOCK_STREAM, 0);
seraddr.sin_family = AF_INET;
seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
seraddr.sin_port = htons(serv_tcp_port);

s = bind(sid, (struct sockaddr *)& seraddr, sizeof(seraddr));

listen(sid,1);
clien = sizeof(cliaddr);
nsid = accept(sid,(struct sockaddr *)&cliaddr, &clien);
tick=time(NULL);
send(nsid,ctime(&tick),100,0);
close(nsid);
}
