#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

using  boost::asio::ip::tcp;

void listener(tcp::socket *sock);

int main()
{
    try
    {
        boost::asio::io_service io_service;
        tcp::endpoint ep(boost::asio::ip::address::from_string("192.168.1.148"),1234);
        std::cout<<ep.address()<<std::endl;

        tcp::socket socket(io_service);
        socket.connect(ep);
        if(socket.is_open())
        {
            std::cout<<"connect!"<<std::endl;
            std::cout.flush();

            new boost::thread (boost::bind(listener,&socket));

            while(1)
            {
                std::string stream;
                std::getline(std::cin,stream);
                std::cin.clear();
                boost::asio::write(socket, boost::asio::buffer(stream, stream.size()));
                stream.clear();
            }
        }

        return 0;
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
}



void listener(tcp::socket *sock){

    char data[1024];

    while(1)
    {
        sock->read_some(boost::asio::buffer(data));
        std::cout<<data<<std::endl;
        memset(data,0,strlen(data));
        usleep(10000);
    }
}
