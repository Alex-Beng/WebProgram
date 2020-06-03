#include "client.h"
#include "clientwin.h"  

#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
using namespace std;

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ClientWin cw;
    cw.show();

    return a.exec();

    // client ct("Alex Beng", "127.0.0.1", 20131);
    // ct.run();

    // std::ifstream t("test.json");
    // std::string str((std::istreambuf_iterator<char>(t)),  
    //                 std::istreambuf_iterator<char>()); 
    // auto j = json::parse(str);
    // for (auto& element : j) {
    //     cout<<element.is_array()<<endl;
    // }
    // std::string s = j.dump();

    // cout<<s<<endl;
}
