#pragma once

#include <tuple>
#include <set>
#include <iostream>

struct ip4{
    int one;
    int two;
    int three;
    int four;
    friend bool operator<(const ip4& lhs, const ip4& rhs);
};

bool operator<(const ip4& lhs, const ip4& rhs);

std::ostream& operator<<(std::ostream& out, const ip4& ip);

std::istream& operator>>(std::istream& in, ip4& ip);

class ip4_handler {
public:
    ip4_handler(){};
//    void storeIP(const ip4& ip);
    bool storeIP(std::istream& in);
    std::set<ip4>& getStorage();
private:
    std::set<ip4> storage;
};



