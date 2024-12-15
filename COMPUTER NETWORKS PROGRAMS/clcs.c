#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
int main()
{
int sockfd,newsockfd,clilen,pid,pid1,n,n1;
struct sockaddr_inserv_addr,cli_addr;
char msg[50];
int cnt=80;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
if(sockfd<0)
{
printf(“\n Socket Failed”);
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
serv_addr.sin_port=htons(3100);
if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
printf(“\n Bind Failed”);
exit(0);
}
clilen=sizeof(cli_addr);
n=recvfrom(sockfd,msg,80,0,(struct sockaddr *)&cli_addr,&clilen);
if(n<0)
{
printf(“First Client Recv error”);
exit(1);
}
pid=fork();
if(pid==0)
{
printf("Server Ready”);
printf("Server Received: %s”,msg);
sendto(sockfd,msg,80,0,(struct sockaddr *) &cli_addr,clilen);
}
n1=recvfrom(sockfd,msg,80,0,(struct sockaddr *)&cli_addr,&clilen);
if(n1<0)
{
printf(“Second Client Recv error”);
exit(1);
}
pid1=fork();
if(pid1==0)
{
printf("Server Ready”);
printf("Server Received: %s”,msg);
sendto(sockfd,msg,80,0,(struct sockaddr *) &cli_addr,clilen);
}
close(sockfd);
}