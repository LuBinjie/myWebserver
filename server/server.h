#ifndef _SERVER_H_
#define _SERVER_H_

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define IPADDRESS "127.0.0.1"
#define PORT 6666
#define MAXSIZE 2024
#define LISTENQ 5
#define FDSIZE 1000
#define EPOLLEVENTS 100

/* 函数声明 */

// 创建套接字并进行绑定
int socket_bind(const char *ip, int port);

// IO多路复用epoll
void do_epoll(int listenfd);

// 事件处理函数
void handle_events(int epollfd, struct epoll_event *events, int num, int listenfd, char *buf);

// 处理接收到的连接
void handle_accept(int epollfd, int listenfd);

// 读处理
void do_read(int epollfd, int fd, char *buf);

// 写处理
void do_write(int epollfd, int fd, char *buf);

// 添加事件
void add_event(int epollfd, int fd, int state);

// 修改事件
void modify_event(int epollfd, int fd, int state);

// 删除事件
void delete_event(int epollfd, int fd, int state);

#endif