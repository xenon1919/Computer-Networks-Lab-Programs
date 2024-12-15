#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    struct hostent *host;
    char name[20];

    printf("Enter host name: ");
    scanf("%s", name);

    host = gethostbyname(name);

    if (host == NULL) {
        printf("Host not found\n");
    } else {
        printf("Host name is: %s\n", host->h_name);
        printf("IP address is: %s\n", inet_ntoa(*((struct in_addr *)host->h_addr)));
    }

    return 0;
}