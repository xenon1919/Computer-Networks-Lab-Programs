#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<stdlib.h>
#include<string.h>
void main() {
int sockfd,newsockfd,newsockfd1,clilen,pid,pid1;
struct sockaddr_in serv_addr,cli_addr;
char msg[100];
int cnt=80;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("socket failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.200.131");
serv_addr.sin_port=htons(1500);
if (bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
{
printf("Bind failed");
exit(1);
}
if(listen(sockfd,5)<0)
{
printf("\n listen failed");
exit(0);
}
clilen= sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
pid=fork();
if(pid==0) {
close(sockfd);
printf("Server ready");
read(newsockfd,msg,50);
printf("\n Server received: %s",msg);
write(newsockfd,msg,50);
}
close(newsockfd);
newsockfd1=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
pid1=fork();
if(pid1==0) {
close(sockfd);
printf("Server ready");
read(newsockfd,msg,50);
printf("\nServer received: %s",msg);
write(newsockfd,msg,50);
}
close(newsockfd1);
}