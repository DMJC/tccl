#ifndef DEBUG_H
#define DEBUG_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Debug
{
    public:
	Debug::Debug();
	Debug::Log_debug(string);
    private:
	ostream log_file;
};

Debug::Debug()
{
	
}

Debug::Log_debug (string debg_msg)
{
	/*writes debug message to console*/
	cout << debg_msg << endl;
	/*writes debug message to logfile*/
	this->log_file << "Debug" + dbg_msg << endl;
}
#endif //DEBUG_H
