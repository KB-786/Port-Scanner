#pragma once
#include <iostream>
#include <SFML/Network.hpp>
#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

static bool port_is_open(const std::string& address, int port)
{
    return (sf::TcpSocket().connect(address, port) == sf::Socket::Done);
}

static int strToInt(const std::string str)
{
    int i = std::stoi(str);
    return i;
}

static std::string sysToStr(System::String^ str)
{
    using namespace msclr::interop;
    marshal_context context;
    std::string nativeString = context.marshal_as<std::string>(str);
    return nativeString;
}
