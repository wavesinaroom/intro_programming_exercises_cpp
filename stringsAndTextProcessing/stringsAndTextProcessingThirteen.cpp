/*Write a program that parses an URL in following format:
[protocol]://[server]/[resource]

It should extract from the URL the protocol, server and resource parts. 
For example, when http://www.cnn.com/video is passed, the result is:

[protocol]="http"
[server]="www.cnn.com"
[resource]="/video"*/

#include <iostream>

void parse_url(std::string input_url)
{
    //Find : (SLD or Second Level Domain)
    //Find second . (TLD or Top Level Domain) 
    //Find what comes next to the server
}
