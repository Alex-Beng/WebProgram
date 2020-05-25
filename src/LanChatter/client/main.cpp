#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[]) {
    std::ifstream t("test.json");
    std::string str((std::istreambuf_iterator<char>(t)),  
                    std::istreambuf_iterator<char>()); 
    auto j = json::parse(str);
    std::string s = j.dump();

    cout<<s<<endl;

    return 0;
}
