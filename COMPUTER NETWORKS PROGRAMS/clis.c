#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<stdlib.h>
void main()
{
int sockfd,clien;
struct sockaddr_in serv_addr,cli_addr;
char msg[100];
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printf("socket failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.1.104");
serv_addr.sin_port=htons(1500);
if (bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
printf("Bind failed");
exit(0);
}
clien= sizeof(cli_addr);
recvfrom(sockfd,msg,100,0,(struct sockaddr *)&cli_addr,&clien);
printf("\n Server Received: %s", msg);
sendto(sockfd,msg,100,0,(struct sockaddr *)&cli_addr,clien);
close(sockfd);
}