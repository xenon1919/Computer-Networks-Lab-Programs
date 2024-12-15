#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
int sockfd;
struct sockaddr_in serv_addr;
char a[50],a1[50];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("sock failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.220.55");
serv_addr.sin_port=htons(4500);
if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("connection failed");
exit(0);
}
write(sockfd,"Hello",50);
sleep(2);
read(sockfd,a,50);
printf("\n client received message %s",a);
close(sockfd);
}