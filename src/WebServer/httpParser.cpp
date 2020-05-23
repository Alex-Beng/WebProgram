#include "httpParser.h"

httpParser::httpParser() {
    method = "";
    path = "";
    http_version = "";
}

void httpParser::process(char* buf, size_t size) {
    enum {BEGIN, METHOD, WS1, WS2, PATH, HTTP_VERSION, END};
    int status = BEGIN;

    for (size_t i=0; i<size; i++) {
        char t_c = buf[i];
        // FSM part
        switch (status) {
        case BEGIN:
            if (!isWS(t_c)) {
                status = METHOD;
                method += t_c;
            }
            break;
        case METHOD:
            if (isWS(t_c)) {
                status = WS1;
            }
            else {
                method += t_c;
            }
            break;
        case WS1:
            if (!isWS(t_c)) {
                status = PATH;
                path += t_c;
            }
            break;
        case WS2:
            if (!isWS(t_c)) {
                status = HTTP_VERSION;
                http_version += t_c;
            }
            break;
        case PATH:
            if (isWS(t_c)) {
                status = WS2;
            }
            else {
                path += t_c;
            }
            break;
        case HTTP_VERSION:
            if (t_c == '\r') {
                status = END;
            }
            else {
                http_version += t_c;
            }
            break;
        case END:
            return;
            break;
        }
        // FSM end
    }
}

bool httpParser::isWS(char t_c) {
    if (t_c == ' ' || t_c == '\t' ) {
        return true;
    }
    else {
        return false;
    }
}