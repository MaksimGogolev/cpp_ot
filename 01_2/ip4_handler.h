#pragma once

#include <tuple>
#include <array>
#include <set>
#include <iostream>

struct ip4{
    std::array<int, 4> ip;
    friend bool operator<(const ip4& lhs, const ip4& rhs);
};

bool operator<(const ip4& lhs, const ip4& rhs);

std::ostream& operator<<(std::ostream& out, const ip4& ip);

std::istream& operator>>(std::istream& in, ip4& ip);

class ip4_handler {
public:
    ip4_handler() = default;
//    void storeIP(const ip4& ip);
    bool storeIP(std::istream& in);
    std::multiset<ip4>& getStorage();
private:
    std::multiset<ip4> storage;
};



