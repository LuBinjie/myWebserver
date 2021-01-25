#ifndef CLIENT_H_
#define CLIENT_H_


#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/epoll.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAXSIZE 1024
#define IPADDRESS "127.0.0.1"
#define SERV_PORT 6666
#define FDSIZE 1024
#define EPOLLEVENTS 20

void handle_connection(int sockfd);
void handle_events(int epollfd, struct epoll_event *events, int num, int sockfd, char *buf);
void do_read(int epollfd, int fd, int sockfd, char *buf);
void do_write(int epollfd, int fd, int sockfd, char *buf);
void add_event(int epollfd, int fd, int state);
void delete_event(int epollfd, int fd, int state);
void modify_event(int epollfd, int fd, int state);


#endif