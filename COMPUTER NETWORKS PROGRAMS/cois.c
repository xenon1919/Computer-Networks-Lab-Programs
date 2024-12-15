#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h> 
#include<stdlib.h>
void main()
{
int sockfd,newsockfd,clilen;
struct sockaddr_in serv_addr,cli_addr;
char a[100];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("socket failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.200.216");
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
printf("\n waiting for client");
newsockfd=accept(sockfd,(struct sockaddr *)&cli_addr,&clilen);
read(newsockfd,a,100);
printf("\n Server Received: %s", a);
write(newsockfd,a,100);
close(newsockfd);
}