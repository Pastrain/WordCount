#include "fileIO.h"

void fileIO::fileOpen(string filename)
{
	this->filename = filename;
	ifile.open(filename);
	if (!ifile.is_open())
	{
		cout << "打不开指定文件！" << endl;

	}
}
