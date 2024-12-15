#include<stdio.h>
#include<sys/types.h>
 #include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
void main() 
{
int sockfd;
struct sockaddr_in serv_addr;
char msg[100],msg1[100];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("socket failed"); 
exit(0);
}
serv_addr.sin_family=AF_INET,
serv_addr.sin_addr.s_addr=inet_addr("192.168.200.131");
serv_addr.sin_port=htons(1500);
 if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0)
 {
printf("connection failed");
exit(0);
}
printf("Enter the msg: \n");
scanf("%s",msg);
write(sockfd,msg,100);
read(sockfd,msg1,100);
printf("Client Received Message %s", msg1);
close(sockfd);
}
