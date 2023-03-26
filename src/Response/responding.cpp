/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responding.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:58:01 by samajat           #+#    #+#             */
/*   Updated: 2023/03/25 16:57:12 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "responding.hpp"
#include <string>


responsePreparation::responsePreparation(const http_message_t& request, const  StatusCode& statusCode):_request(request), _statusCode(statusCode), _response("")
{
    if(_statusCode.is_error_status())
        sendError();
    else if (_request.first["Method"] == "GET")
        exceute_get();
    else if (_request.first["Method"] == "POST")
        exceute_post();
    else if (_request.first["Method"] == "DELETE")
        exceute_delete();
}

responsePreparation::response_t responsePreparation::get_response() const
{
    return _response;
}

void responsePreparation::prepare_statusLine()
{
    _response += "HTTP/1.1 " + std::string(_statusCode.what());
    _response += CRLF;
}

void responsePreparation::prepare_other_headers()
{
    _response += "Server: Webserv/1.0";
    _response += CRLF;
    _response += "Date: " + utility::get_date();
    _response += CRLF;
    _response += "Content-Type: text/html";
    _response += CRLF;
}

void responsePreparation::prepare_body() //I'm gonna assume for now that the uri is a file
{
    std::string appropriate_page ;
    if (_statusCode.is_error_status())
    {
        appropriate_page = _statusCode.get_associated_page();
        _response += "Content-Length: " + std::to_string(appropriate_page.length());
        _response += CRLF;
        _response += CRLF;
        _response += appropriate_page;
        return;
    }
    appropriate_page = utility::get_file_content(_request.first["URI"]);
    _response += "Content-Length: " + std::to_string(appropriate_page.length());
    _response += CRLF;
    _response += CRLF;
    _response += appropriate_page;
}


// void responsePreparation::prepare_content_length()
// {
//     _response += "Content-Length: " + std::to_string(_response.length());
//     _response += CRLF;
// }

void    responsePreparation::exceute_get()
{
    prepare_statusLine();
    prepare_other_headers();
    prepare_body();
}

void    responsePreparation::exceute_post()
{
}

void    responsePreparation::exceute_delete()
{
}


void   responsePreparation::sendError()
{
    prepare_statusLine();
    prepare_other_headers();
    prepare_body();
}