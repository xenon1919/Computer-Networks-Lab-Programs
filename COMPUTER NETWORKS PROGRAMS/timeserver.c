#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
int main()
{
int sockfd,newsockfd,clilen;
struct sockaddr_in serv_addr,cli_addr;
char str[100],a[50];
time_t tick;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd<0)
{
printf("sock failed");
exit(0);
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("192.168.220.55");
serv_addr.sin_port=htons(4500);
if(bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
{
printf("bind failed");
exit(0);
}
if(listen(sockfd,5)<0)
{
printf("\n listen failed");
exit(0);
}
clilen=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clilen);
tick=time(NULL);
snprintf(str,sizeof(str),"%s\n",ctime(&tick));
printf("%s",str);
read(newsockfd,a,50);
printf("\n %s",a);
write(newsockfd,str,100);
close(newsockfd);
}