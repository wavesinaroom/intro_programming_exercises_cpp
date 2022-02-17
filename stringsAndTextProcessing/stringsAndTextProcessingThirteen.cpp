/*Write a program that parses an URL in following format:
[protocol]://[server]/[resource]

It should extract from the URL the protocol, server and resource parts. 
For example, when http://www.cnn.com/video is passed, the result is:

[protocol]="http"
[server]="www.cnn.com"
[resource]="/video"*/

#include <iostream>

void cut_url(std::string input_url)
{
    std::string protocol = input_url.substr(0, input_url.find(":"));
    std::string server = input_url.substr(input_url.find("w"),input_url.find("com")-4);
    std::string resource = input_url.substr(input_url.find("com/")+3, input_url.length()-1); 

    std::cout<<"[Protocol] = "<<protocol<<'\n';
    std::cout<<"[Server] = "<<server<<'\n';
    std::cout<<"[Resource] = "<<resource<<'\n';

}

int main(int argc, char const *argv[])
{
    cut_url("http://www.theodinproject.com/video");
    return 0;
}
