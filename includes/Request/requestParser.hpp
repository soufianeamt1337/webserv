/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestParser.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <samajat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:44:09 by samajat           #+#    #+#             */
/*   Updated: 2023/03/17 18:51:03 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef REQUESTPARSER_HPP
# define REQUESTPARSER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "utils.hpp"






class clientRequestParser
{
    private:
    typedef    std::vector<std::string>             tokens_t;
    typedef    std::map <std::string, std::string>  request_t;





    tokens_t                    _tokens;
    request_t                   _request;
    
    public:
    
    clientRequestParser(std::string clientRequestMsg); //if one of the tokens  has more than one line please declare it as an error;
    std::string getValue (std::string key);

    private:
    void    parseFirstLine ();
    void    parseOtherLines (std::string line);
    void    parseHeader ();

    public:
    void    displayRequest ();
};

#endif