#include "wordCount.h"

// 判断是否属于数字或者字母范围
bool wordCount::isValid(char ch)
{
	if ((ch >= 'A' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		return true;
	else
		return false;
}

// 判断是否是数字
bool wordCount::isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}


// 判断是否属标点符号（即分隔符）
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

// 统计行数
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
// 统计字符数
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
	// 如果当前临时存储的wordStr长度超过了4个字符，就可能属于单词了
	if (word.length() >= 4)
	{
		for (int in = 0; in < 4; in++)
		{
			//if (wordStr[newi] == 数字)
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
	string lineStr;		// lineStr为临时的一行
	while (!Ifile.eof())
	{
		getline(Ifile, lineStr);
		int i = 0;

		string tmpStr = "";	// 存储当前可能是单词的字符

		while (i < lineStr.length()) {
			//if (lineStr[i] == 字母 / 数字)
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

	string str[100][256];	// [100]存的是第i行，[256]存的是该行第j个单词
	int idx = 0;		// 用于str的行标
	int idy[100] = { 0 };		// 用于str的列标
	string lineStr;		// lineStr为临时的一行

	// 计算出str数组
	int tmp = 0;
	for (idx = 0; !ifile.eof(); idx++)
	{
		getline(ifile, lineStr);

		int i = 0;			// 用来循环一行(lineStr)

		string wordStr = "";	// 存储当前可能是单词的字符

		while (i < lineStr.length()) {
			//if (lineStr[i] == 字母 / 数字)
			if (isValid(lineStr[i]))
			{
				wordStr += lineStr[i];
				if (i + 1 == lineStr.length())
				{
					if (isWord(wordStr) == true)
					{
						str[idx][idy[idx]] = wordStr;
						wordStr = "";
						idy[idx]++;		// 当前idx行，idy列这一个单词找到了，++
					}
				}
			}
			else {
				bool flag = 1;
				// 如果当前临时存储的wordStr长度超过了4个字符，就可能属于单词了
				if (wordStr.length() >= 4)
				{
					for (int in = 0; in < 4; in++)
					{
						//if (wordStr[newi] == 数字)
						if (isNum(wordStr[in])) {
							flag = false;
							break;
						}
					}
					// 如果前4个字符里面没有数字，那就确定属于字符了
					if (flag == true) {
						str[idx][idy[idx]] = wordStr;
						wordStr = "";
						idy[idx]++;		// 当前idx行，idy列这一个单词找到了，++
					}
				}
				else
					wordStr = "";
			}
			i++;
		}
	}

	// san层循环
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


