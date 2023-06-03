/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appendClientSide.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:06:16 by fech-cha          #+#    #+#             */
/*   Updated: 2023/06/03 06:00:04 by fech-cha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APPENDCIENTSIDE_HPP
# define APPENDCIENTSIDE_HPP

#include "/Users/fech-cha/Desktop/webserv/inc/pollingServ.hpp"
# define chunked 1
# define contentlength 2 

class appendClient
{
    private:
        int         _checkHead;
        int         _checkBody;
        int         _clientFd;
        int         _bodyType;
        int         _responseStatus;
        std::string _tmp;
        std::string _header;
        std::string _body;
    public:
        appendClient();
        ~appendClient();
        
        
        // I/O methods for servers
        void    sendReq(int sockfd);
        void    recvHead();
        void    recvBody(std::string req);

        //getters & setters
        int     getClientFd(void);
        void    setClientFd(int fd);
        
        int     getHeadStatus();
        int     getBodyStatus();
        
        void    setHeadStatus(int head);
        void    setBodyStatus(int body);
        
        std::string getHeader();
        std::string getBody();

        void    setBody(std::string body);
        
        void                    parseChunked(std::string& chunkedData);
        void                    copyReq(char *req, int size);
        std::string::size_type  checkCRLForChunk(std::string test);
        std::string             getRestOfRes(int size);
        
        void    getBodyRest();

};

#endif