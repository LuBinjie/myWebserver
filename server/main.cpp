#include <stdio.h>
#include "server.h"

int main(int argc, char *argv[])
{
    int listenfd;
    listenfd = socket_bind(IPADDRESS, PORT);
    listen(listenfd, LISTENQ);
    do_epoll(listenfd);

    return 0;
}