#include "httpParser.h"
#include "httpServer.h"

#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {	
	if (argc > 2) {
        std::cout << "Usage: ./main [<file>]" << std::endl;
        return -1;
    }
    if (argc == 2 and not std::fopen(argv[1], "r")) {
        std::cout << "No such file: " << argv[1] << std::endl;
        return -1;
    }

	int port;
	int buf_size;
	char main_path[256];
	char main_page[256];

	FILE* param_file = std::fopen(argv[1], "r");
	fscanf(param_file, "%d %d %s %s", &port, &buf_size, main_path, main_page);
	cout<<port<<' '<<buf_size<<' '<<main_path<<' '<<main_page<<endl;
	
	// httpServer server(80, 10240, "./html", "/index.html");
	httpServer server(port, buf_size, string(main_path), string(main_page));
	server.run();
	return 0;
}