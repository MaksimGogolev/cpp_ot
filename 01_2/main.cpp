#include "ip4_handler.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

int main (int, char **)
{

//    std::string str1 = "222.173.235.246 \t text2 \t text3\n"
//                       "222.130.177.64\t text2 \t text3\n"
//                       "222.82.198.61\t text2 \t text3\n"
//                       "1.70.44.170\t text2 \t text3\n"
//                       "1.29.168.152\t text2 \t text3\n"
//                       "1.1.234.8\t text2 \t text3\n";
//    std::stringstream stream(str1);

    auto& stream = std::cin;
//    std::ifstream stream("../ip_filter.txt");

    ip4_handler handler;
    std::string tmpString;

    while(handler.storeIP(stream) && std::getline(stream,tmpString))
    {
    }

    std::vector<ip4> out1;
    std::vector<ip4> out4670;
    std::vector<ip4> out46;


    for(auto it = handler.getStorage().rbegin();
        it != handler.getStorage().rend();
        ++it
    ){
        std::cout << *it << "\n";
        if(it->ip[0] == 1) out1.push_back(*it);
        if(it->ip[0] == 46 && it->ip[1] == 70) out4670.push_back(*it);
        if(it->ip[0] == 46 || it->ip[1] == 46 || it->ip[2] == 46 || it->ip[3] == 46) out46.push_back(*it);
    }

    for(const auto& ip: out1){
        std::cout << ip << "\n";
    }

    for(const auto& ip: out4670){
        std::cout << ip << "\n";
    }

    for(const auto& ip: out46){
        std::cout << ip << "\n";
    }
//    std::cout << handler.getStorage().size() ;
    return 0;
}