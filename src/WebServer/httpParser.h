#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include "debug.h"

#include <map>
#include <string>
using namespace std;

class httpParser {
private:
    std::string method;
    std::string path;
    std::string http_version;

    std::map<std::string, std::string> headers;
public:
    httpParser();
    void process(char* buf, size_t size);
private:
    bool isWS(char t_c);
};

#endif