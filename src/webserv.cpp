/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:56:03 by samajat           #+#    #+#             */
/*   Updated: 2023/03/17 14:37:41 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "requestParser.hpp"
std::string msg= "GET / HTTP/1.1\r\n"
            "Host: 192.241.213.46:6880\r\n"
            "Upgrade-Insecure-Requests: 1\r\n"
            "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
            "User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/602.4.8 (KHTML, like Gecko) Version/10.0.3 Safari/602.4.8\r\n"
            "Accept-Language: en-us\r\n"
            "Accept-Encoding: gzip, deflate\r\n"
            "Connection: keep-alive\r\n\r\n";

int main ()
{
    clientRequestParser test(msg);
    test.displayRequest();
}