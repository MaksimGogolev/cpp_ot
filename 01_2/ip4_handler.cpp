#include "ip4_handler.h"


bool operator<(const ip4 &lhs, const ip4 &rhs) {
    return std::tie(lhs.one, lhs.two, lhs.three, lhs.four)
           < std::tie(rhs.one, rhs.two, rhs.three, rhs.four);
}

std::ostream &operator<<(std::ostream &out, const ip4 &ip) {
    out << ip.one << '.' << ip.two << '.' << ip.three << '.' << ip.four;
    return out;
}

std::istream &operator>>(std::istream &in, ip4 &ip) {
    in >> ip.one;
    in.ignore();
    in >> ip.two;
    in.ignore();
    in >> ip.three;
    in.ignore();
    in >> ip.four;
    return in;
}

//void ip4_handler::storeIP(const ip4 &ip) {
//    storage.emplace(ip);
//}

bool ip4_handler::storeIP(std::istream &in) {
    ip4 ip;
    if(!(in >> ip.one)) return false;
    in.ignore();
    if(!(in >> ip.two)) return false;
    in.ignore();
    if(!(in >> ip.three)) return false;
    in.ignore();
    if(!(in >> ip.four)) return false;
    storage.emplace(ip);
    return true;
}

std::set<ip4> &ip4_handler::getStorage() {
    return storage;
}
