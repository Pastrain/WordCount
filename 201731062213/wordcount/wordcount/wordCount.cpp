#include "wordCount.h"

// �ж��Ƿ��������ֻ�����ĸ��Χ
bool wordCount::isValid(char ch)
{
	if ((ch >= 'A' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		return true;
	else
		return false;
}

// �ж��Ƿ�������
bool wordCount::isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}


// �ж��Ƿ��������ţ����ָ�����
bool wordCount::isSplit(char chSplit)
{
	//if (ifile.peek() != '\n' && ifile.peek() != '!' && ifile.peek() != '.' && )
	if ((chSplit >= 0 && chSplit <= 47) ||
		(chSplit >= 58 && chSplit <= 64) ||
		(chSplit >= 91 && chSplit <= 96) ||
		(chSplit >= 123 && chSplit <= 127))
	{
		return true;
	}
	return false;
}

// ͳ������
void wordCount::countLine()
{
	char line[1000];
	ifstream Ifile(filepro.filename);
	while (!Ifile.eof())
	{
		Ifile.getline(line, 1000, '\n');
		cntlines++;
	}
}
// ͳ���ַ���
void wordCount::countChar()
{
	string line;
	ifstream Ifile(filepro.filename);
	while (!Ifile.eof())
	{
		getline(Ifile, line);
		cntchars += line.size();
	}
}

bool wordCount::isWord(string word)
{
	bool flag = 1;
	// �����ǰ��ʱ�洢��wordStr���ȳ�����4���ַ����Ϳ������ڵ�����
	if (word.length() >= 4)
	{
		for (int in = 0; in < 4; in++)
		{
			//if (wordStr[newi] == ����)
			if (isNum(word[in])) {
				flag = false;
			}
		}
		
	}
	else {
		flag = 0;
	}
	return flag;
}

void wordCount::countWord()
{
	ifstream Ifile(filepro.filename);
	string lineStr;		// lineStrΪ��ʱ��һ��
	while (!Ifile.eof())
	{
		getline(Ifile, lineStr);
		int i = 0;

		string tmpStr = "";	// �洢��ǰ�����ǵ��ʵ��ַ�

		while (i < lineStr.length()) {
			//if (lineStr[i] == ��ĸ / ����)
			if (isValid(lineStr[i]))
			{
				tmpStr += lineStr[i];
				if (i + 1 == lineStr.length())
				{
					if (isWord(tmpStr) == true) {

						wordstr[cntwords] = tmpStr;
						tmpStr = "";
						cntwords++;
					}
				}
			}
			else{
				if (isWord(tmpStr) == true) {

					wordstr[cntwords] = tmpStr;
					tmpStr = "";
					cntwords++;
				}
				else {
					tmpStr = "";
				}
			}
			i++;
		}
	}
}


void wordCount::frequency()
{
	map<string, int>::iterator it;

	for (int i = 0; i < cntwords; i++)
	{
		for (it = freq.begin(); it != freq.end(); it++)
		{
			if (it->first == wordstr[i]) {
				it->second++;
				break;
			}
		}
		if (it == freq.end())
			freq.insert(make_pair(wordstr[i], 1));
	}
}

void wordCount::outputWordFre(int flag)
{
	map<string, int> tmpM = freq;
	map<string, int>::iterator it,it2,it3;
	vector<PAIR> vec;

	vector<PAIR>::iterator vecit;
	int num = 0;
	string nstr;
	for (it2 = tmpM.begin(); it2 != tmpM.end(); it2++)
	{
		for (it = tmpM.begin(); it != tmpM.end(); it++)
		{
			if (it->second > num) {
				num = it->second;
				nstr = it->first;
				it3 = it;
			}
		}
		it3->second = 0;
		PAIR p(nstr, num);
		vec.push_back(p);
		num = 0;
	}
	int f = 0;
	for (vecit = vec.begin(); vecit != vec.end(); vecit++)
	{
		cout << "<" << vecit->first << ">:" << vecit->second << endl;
		f++;
		if (flag == f)
		{
			break;
		}
	}
		
}

void wordCount::Phrases(int m)
{
	ifstream ifile(filepro.filename);

	string str[100][256];	// [100]����ǵ�i�У�[256]����Ǹ��е�j������
	int idx = 0;		// ����str���б�
	int idy[100] = { 0 };		// ����str���б�
	string lineStr;		// lineStrΪ��ʱ��һ��

	// �����str����
	int tmp = 0;
	for (idx = 0; !ifile.eof(); idx++)
	{
		getline(ifile, lineStr);

		int i = 0;			// ����ѭ��һ��(lineStr)

		string wordStr = "";	// �洢��ǰ�����ǵ��ʵ��ַ�

		while (i < lineStr.length()) {
			//if (lineStr[i] == ��ĸ / ����)
			if (isValid(lineStr[i]))
			{
				wordStr += lineStr[i];
				if (i + 1 == lineStr.length())
				{
					if (isWord(wordStr) == true)
					{
						str[idx][idy[idx]] = wordStr;
						wordStr = "";
						idy[idx]++;		// ��ǰidx�У�idy����һ�������ҵ��ˣ�++
					}
				}
			}
			else {
				bool flag = 1;
				// �����ǰ��ʱ�洢��wordStr���ȳ�����4���ַ����Ϳ������ڵ�����
				if (wordStr.length() >= 4)
				{
					for (int in = 0; in < 4; in++)
					{
						//if (wordStr[newi] == ����)
						if (isNum(wordStr[in])) {
							flag = false;
							break;
						}
					}
					// ���ǰ4���ַ�����û�����֣��Ǿ�ȷ�������ַ���
					if (flag == true) {
						str[idx][idy[idx]] = wordStr;
						wordStr = "";
						idy[idx]++;		// ��ǰidx�У�idy����һ�������ҵ��ˣ�++
					}
				}
				else
					wordStr = "";
			}
			i++;
		}
	}

	// san��ѭ��
	for (int curIdx = 0; curIdx < idx; curIdx++) {
		for (int curIdy = 0; curIdy < idy[curIdx] - m + 1; curIdy++) {
			for (int cur = curIdy; cur < curIdy + m; cur++)
			{
				cout << str[curIdx][cur] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}


void wordCount::outPut(ostream &out)
{
	out << "characters:" << cntchars << endl;
	out << "words:" << cntwords << endl;
	out << "lines:" << cntlines << endl;

	map<string, int>::iterator it;
	for (it = freq.begin(); it != freq.end(); it++)
	{
		out <<"<" << it->first << ">:" << it->second << endl;
	}
}


