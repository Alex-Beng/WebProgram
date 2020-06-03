#include "base64.h"

#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    // const std::string orig =
    // "René Nyffenegger\n"
    // "http://www.renenyffenegger.ch\n"
    // "passion for data\n";

    // std::string encoded = base64_encode(reinterpret_cast<const unsigned char*>(orig.c_str()), orig.length());
    // std::string decoded = base64_decode(encoded);

    // cout<<decoded<<endl;



    string inputFilename("./test.jpg");
    ifstream ifs(inputFilename, ifstream::in|ifstream::binary);
    std::ofstream out("out.hex", ios_base::out | ios_base::binary);
    
    if (!ifs)
        return -1;

    ifs.seekg (0, ios::end);   
    size_t length = ifs.tellg();  
    ifs.seekg (0, ios::beg);
    cout<<length<<endl;
    char buffer[length];
    ifs.read(buffer, length);
    cout<<ifs.gcount()<<endl;

    std::string encoded = base64_encode(string(buffer, buffer+length), length);
    std::string decoded = base64_decode(encoded);
    cout<<decoded.length()<<endl;
    out.write(decoded.c_str(), decoded.length());
    out.close();
    // cout<<decoded<<endl;
    // char s_buf[213];
    // while(ifs.read(s_buf, 213)) { //一直读到文件结束
    //     int readedBytes = ifs.gcount(); //看刚才读了多少字节
    //     std::string encoded = base64_encode(s_buf, readedBytes);
    //     cout<<encoded<<endl;
    //     std::string decoded = base64_decode(encoded);
    //     // cout<<decoded;
    // }
    ifs.close();
    // cout<<endl;

    return 0;
}