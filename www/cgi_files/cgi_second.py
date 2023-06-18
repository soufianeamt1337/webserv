# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cgi_second.py                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fech-cha <fech-cha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/25 15:45:47 by fech-cha          #+#    #+#              #
#    Updated: 2023/06/16 19:58:48 by fech-cha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# !/usr/local/bin/python3

import cgi

print("HTTP/1.1 200 OK\r")
print("Content-type: text/html\r\n\r")
print ("<html>")
print ("<head><title> CGI Programming is fun </title></head>")
print ("<body>")
print ("<h1>Welcome To Webserv CGI Execution!</h1>")


form = cgi.FieldStorage();

if form.getvalue("name"):
    name = form.getvalue("name");
    print ("<h2>Hi " +  name + "! Enjoy our experience :) </h2><br>");
if form.getvalue("Linux"):
    print ("<p>Man of culture!</p>")
if form.getvalue("Windows"):
    print ("<p>Trash!</p>")

print ("<form method=\"post\" action=\"cgi_second.py\">")
print ("<p>Name: <input type=\"text\" name=\"name\"/></p>")
print ("<input type=\"checkbox\" name=\"Linux\"/> Linux")
print ("<input type=\"checkbox\" name=\"Windows\"/> Windows")
print ("<input type=\"Submit\" value=\"Submit\"/>")
print ("</form>")

print ("</body>")
print ("</html>")