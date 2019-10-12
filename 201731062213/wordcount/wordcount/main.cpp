#include "wordCount.h"
#include <algorithm>

struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
};

int main(int argc , char **argv)
{
	int n = 1;
	string filename;
	while (argv[n] != NULL)
	{
		if ((string )argv[n] == "-i")
		{
			filename = argv[n + 1];
			cout << "***" << endl;
		}
		n += 2;
	}
	if (filename == "")
	{
		filename = argv[1];
	}
	wordCount wordC(filename);
	wordC.countLine();
	wordC.countChar();
	wordC.countWord();
	wordC.frequency();
	wordC.outPut(cout);
	n = 1;
	while (argv[n] != NULL)
	{
		if ((string)argv[n] == "-m")
		{
			wordC.Phrases(atoi(argv[n+1]));
			
		}
		else if ((string)argv[n] == "-n")
		{
			int num = (int)argv[n + 1];
			wordC.outputWordFre(num);
		}
		else if ((string)argv[n] == "-o")
		{
			ofstream fout(argv[n + 1]);
			wordC.outPut(fout);
		}
		n++;
	}

	system("pause");
	return 0;
}