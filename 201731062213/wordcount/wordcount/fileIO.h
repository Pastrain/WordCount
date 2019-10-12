#pragma once

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class fileIO
{
public:
	string filename;
	ifstream ifile;
	fileIO(string filename)
	{
		this->filename = filename;
	}
	fileIO(){}
	~fileIO(){}

	void fileOpen(string filename);

};