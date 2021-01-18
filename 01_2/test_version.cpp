#define BOOST_TEST_MODULE test_version
#include "ip4_handler.h"
#include <iostream>
#include <sstream>
#include <string>

#include <boost/test/unit_test.hpp>





BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_valid_version)
{
    std::string str1 = "222.173.235.246 \t text2 \t text3\n"
                       "222.130.177.64\t text2 \t text3\n"
                       "222.82.198.61\t text2 \t text3\n"
                       "1.70.44.170\t text2 \t text3\n"
                       "1.29.168.152\t text2 \t text3\n"
                       "1.1.234.8\t text2 \t text3";
    std::stringstream stream(str1);
    ip4_handler handler;
    std::string tmpString;
   ;
    while( handler.storeIP(stream) && std::getline(stream,tmpString))
    {

    }
    std::cout << handler.getStorage().size();
    BOOST_CHECK(handler.getStorage().size()==6);
}

}