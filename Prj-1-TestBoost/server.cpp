#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <vector>

using boost::asio::ip::tcp;

typedef  boost::shared_ptr<tcp::socket> socket_ptr;

std::vector <socket_ptr> clientList;

void session(socket_ptr sock);


int main()
{
    while(1)
    {
        boost::asio::io_service io_service;
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));
        socket_ptr sock(new tcp::socket(io_service));
        acceptor.accept(*sock);
        new boost::thread (boost::bind(session, sock));
        clientList.push_back(sock);
    }
}


void session(socket_ptr sock)
{
    char data[1024];
    std::cout<<"connect!"<<std::endl;
    while(1)
    {
        if(sock->read_some(boost::asio::buffer(data)))
        {
            std::cout<<data<<std::endl;
            for(int i=0;i<clientList.size();i++)
                if(sock!=clientList[i])
                clientList[i]->write_some(boost::asio::buffer(data));
            std::cout.flush();
            memset(data,0,strlen(data));
        }
    }
}
