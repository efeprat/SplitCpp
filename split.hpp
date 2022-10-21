#ifndef SPLIT_INCLUDED_
#define SPLIT_INCLUDED_

#include <vector>
#include <string>

namespace misstr {

    std::vector<std::string> split(const std::string& str, const std::string& sep = "");

    std::vector<std::string> split(const std::string& str, char csep);

}

// Como el split de Python, pero:
//
// 1. Sin parámetro maxsplit.
//
// 2. El separador especial None de Python será aquí la cadena vacía.

#endif
