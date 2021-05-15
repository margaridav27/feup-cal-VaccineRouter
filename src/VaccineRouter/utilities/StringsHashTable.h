#ifndef VACCINEROUTER_STRINGSHASHTABLE_H
#define VACCINEROUTER_STRINGSHASHTABLE_H

#include <unordered_set>

struct StrHash {
    int operator()(const std::string str) const {
        int hash = 0;
        for (int i = 0; i < str.length(); i++) {
            hash = 37 * hash + str[i];
        }
        return hash;
    }

    bool operator()(const std::string str1, const std::string str2) const {
        return str1 == str2;
    }
};

typedef std::unordered_set<std::string, StrHash, StrHash> StringsHashTable;


#endif //VACCINEROUTER_STRINGSHASHTABLE_H
