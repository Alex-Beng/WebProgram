# g++ ./*.cpp ../base64/base64.cpp -lws2_32 -I../../../3rdparty/ -I../base64/ -std=c++11 -Winvalid-pch

C:/Qt/Qt5.4.0/5.4/mingw491_32/bin/qmake.exe server.pro -r -spec win32-g++ 
C:/Qt/Qt5.4.0/Tools/mingw491_32/bin/mingw32-make -f Makefile.Debug -j8
