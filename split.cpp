#include "split.hpp"

#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> misstr::split(const std::string& str, const std::string& sep) {
    size_t sepsize = sep.size();
    std::vector<std::string> rdo = {};
    if (sepsize == 0) {
        std::istringstream iss(str);
        std::string aux;
        while (iss >> aux) {
            rdo.push_back(aux);
        }
    } else {
        std::string aux;
        size_t posini = 0;
        size_t posfin = str.find(sep);
        while (posfin < std::string::npos) {
            aux = str.substr(posini, posfin - posini);
            rdo.push_back(aux);
            posini = posfin + sepsize;
            posfin = str.find(sep, posini);
        }
        aux = str.substr(posini);
        rdo.push_back(aux);
    }
    return rdo;
}

std::vector<std::string> misstr::split(const std::string& str, char csep) {
    std::string sep(1, csep);
    return split(str, std::string(sep));
}
