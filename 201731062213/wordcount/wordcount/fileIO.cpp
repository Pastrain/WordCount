#include "fileIO.h"

void fileIO::fileOpen(string filename)
{
	this->filename = filename;
	ifile.open(filename);
	if (!ifile.is_open())
	{
		cout << "�򲻿�ָ���ļ���" << endl;

	}
}
