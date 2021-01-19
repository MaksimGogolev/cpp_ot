#include "ip4_handler.h"


bool operator<(const ip4 &lhs, const ip4 &rhs) {
    return std::tie(lhs.ip[0], lhs.ip[1], lhs.ip[2], lhs.ip[3])
           < std::tie(rhs.ip[0], rhs.ip[1], rhs.ip[2], rhs.ip[3]);
}

std::ostream &operator<<(std::ostream &out, const ip4 &ip) {
    out << ip.ip[0] << '.' << ip.ip[1] << '.' << ip.ip[2] << '.' << ip.ip[3];
    return out;
}

std::istream &operator>>(std::istream &in, ip4 &ip) {
    for(int i = 0; i < 4; ++i){
        in >> ip.ip[i];
        in.ignore();
    }
    return in;
}

//void ip4_handler::storeIP(const ip4 &ip) {
//    storage.emplace(ip);
//}

bool ip4_handler::storeIP(std::istream &in) {
    ip4 ip{};
    for(int i = 0; i < 4; ++i){
        if(!(in >> ip.ip[i])) return false;
        in.ignore();
    }
    storage.emplace(ip);
    return true;
}

std::multiset<ip4> &ip4_handler::getStorage() {
    return storage;
}
