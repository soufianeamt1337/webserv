/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 22:43:02 by fech-cha          #+#    #+#             */
/*   Updated: 2023/03/31 06:44:16 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP
# define SOCKET_HPP

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>  
#include <string.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <poll.h>
#include <vector>

# define HTTP_PORT 80
# define BACKLOG 100

//temp buff size
# define BUFFER_SIZE 1024
/* getaddrinfo => socket => bind => listen => accept*/
class mySocket
{
    private:
        //server/client addresses info
        struct sockaddr_in  webservAddr;
        int                 webservAddrlen;
        struct sockaddr_in  clientAddr;
        int                 clientAddrlen;
        
        
        int sockfd;
        int bindRes;
        int acceptSockFd;
        int sendRes;
        int recvRes;
        int sockName;
        char    buffer[BUFFER_SIZE];

        std::vector<pollfd> _pollfds;
        
    public:
        mySocket();
        ~mySocket();
        void    testSysCall(int fd);
        void    rerunServ(void);
        void    listenRequest(void);
        void    acceptConnection(void);
        void    closeConnection(void);
        void    sendReq(int sockfd, const void *buf, int len, int flags);
        void    recvReq(int sockfd, void *buf, int len, int flags);

        //still not clear about this part
        void    printLogs(void);
        void     retrieveClientAdd(void);
        
        //getter functions
        int                 getSockFd(void) const;
        int                 getBindValue(void) const;
        int                 getAcceptFd(void) const;
        int                 getSockName(void) const;
        const char                *getBuffer(void) const;

        //setters
        void    pushFd(int sockfd, int event);
};

#endif