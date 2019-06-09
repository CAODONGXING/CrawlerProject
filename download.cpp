#include <fstream>
#include <iostream>
#include <string>

using namespace std;
extern "C" void download(const char* url,const char* connections){
    ifstream in("extList.txt", ios::in | ios::binary);
    if (!in)
    {
        cout << "File " << "extList.txt" << " not found!\n";
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(in, line))
    {
        string c_url = url;
	string c_connections = connections;
        //string tmp = "wget "+ c_url +line;
	string tmp = "axel -n "+ c_connections+" " + c_url +line;
        const char *cmd = tmp.c_str();
        system(cmd);
    }

    in.close();
}
