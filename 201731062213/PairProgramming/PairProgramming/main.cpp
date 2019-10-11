#include"common.h"

// 判断是否属于数字或者字母范围
bool isValid(char ch)
{
	if ((ch >= 'A' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		return true;
	else
		return false;
}

// 判断是否是数字
bool isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}


// 判断是否属标点符号（即分隔符）
bool isSplit(char chSplit)
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
void countLine(ifstream &ifile, int *cntLines)
{
	char line[1000];
	while (!ifile.eof())
	{
		ifile.getline(line, 1000, '\n');
		*cntLines++;
	}
}
// 统计字符数
void countChar(ifstream &ifile, int *cntChar)
{
	char c;
	cntChar = 0;
	while (ifile.get(c))
		*cntChar++;
	cout << *cntChar << endl;
}

#if 1
// 统计单词数升级版
map<string, int> countWords(ifstream &ifile, int &idx, int &numPhrases)
{
	char ch;
	string str[100][256];	// [100]存的是第i行，[256]存的是该行第j个单词
	idx = 0;		// 用于str的下标
	string lineStr;		// lineStr为临时的一行
	//numPhrases = 0;		// 用于计算词组

	int tmp = 0;
	for (int iLine = 0; !ifile.eof(); iLine++)
	{
		getline(ifile, lineStr);
		int i = 0;			// 用来循环一行(lineStr)

		string wordStr = "";

		while (i++ != lineStr.length()) {
			//if (lineStr[i] == 字母 / 数字)
			if (isValid(lineStr[i]))
				wordStr += lineStr[i];
			else {
				bool flag = 1;
				// 如果当前临时存储的wordStr长度超过了4个字符，就可能属于单词了
				if (wordStr.length() >= 4)
				{
					for (int in = 0; in < 4; in++)
					{
						//if (wordStr[newi] == 数字)
						if (isNum(lineStr[in])) {
							flag = false;
							break;
						}
					}
					// 如果前4个字符里面没有数字，那就确定属于字符了
					if (flag == true) {
						str[iLine][idx] = wordStr;
						wordStr = "";
					}
				}
				else{
					str[iLine][idx] = wordStr;
					wordStr = "";
				}
			}
		}
	}
	auto freq = frequency((string**)str, idx);		// 返回统计字频的freq
	return freq;
}

// map字典序，求每种单词的频数
map<string, int> frequency(string **str, int& cntLine, int& cnt)
{
	map<string, int> freq;
	map<string, int>::iterator it;

	// 当前第current行string数组 < 总的string数组行数时，就造
	for (int curLine = 0; curLine < cntLine; curLine++)
		for (int curIdx = 0; curIdx < cnt;  curIdx++)
		{
			// 遍历map，如果有重复的，对应单词种类的个数++
			for (it = freq.begin(); it != freq.end(); it++)
			{
				if (it->first == str[curLine][curIdx]) {
					it->second++;
					break;
				}
			}
			// 如果没有重复的，就添加进去
			if (it != freq.end())
				freq.insert(make_pair(str[curLine][curIdx], 1));
		}
	return freq;
}

#endif

#if 0
// 统计单词数原版
map<string, int> countWords(ifstream &ifile, int &idx, int &numPhrases)
{
	char ch;
	string str[1000];	// 存出现的单词（不重复）
	idx = 0;		// 用于str的下标
	string lineStr;		// lineStr为临时的一行
	numPhrases = 0;		// 用于计算词组

	int tmp = 0;
	while (!ifile.eof())
	{
		getline(ifile, lineStr);
		int i = 0;			// 用来循环一行(lineStr)
		string str[1000];

		string wordStr = "";

		while (i++ != lineStr.length()) {
			//if (lineStr[i] == 字母 / 数字)
			if (isValid(lineStr[i]))
				wordStr += lineStr[i];
			else {
				bool flag = 1;
				// 如果当前临时存储的wordStr长度超过了4个字符，就可能属于单词了
				if (wordStr.length() >= 4)
				{
					for (int in = 0; in < 4; in++)
					{
						//if (wordStr[newi] == 数字)
						if (isNum(lineStr[in])) {
							flag = false;
							break;
						}
					}
					// 如果前4个字符里面没有数字，那就确定属于字符了
					if (flag == true) {
						str[idx] = wordStr;
						wordStr = "";
					}
				}
				else {
					str[idx] = wordStr;
					wordStr = "";
				}
			}
		}
	}
	auto freq = frequency(str, idx, );		// 返回统计字频的freq
	return freq;
}
#endif

// 比较值大小的函数，用于main函数中sort
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
}
// 选择频数最多的前num个词,输出
void mostWords(vector<string, int> &vec, int num)
{
	// 本for循环仅用于测试，后面要改成输出到文件？
	for (int i = 0; i < num; ++i)
		cout << vec[i] << endl;
}

int main(int argc, char *argv[])
{
	string infilename;
	infilename = argv[1];
	ifstream ifile(infilename);

	if (ifile.is_open())
	{
		
	}

	int cnt = 1000;

	
	/*****************************************************************************************/

	// 1.统计文件的字符总数
	int cntChar = 0;
	countChar(ifile, &cntChar);
	cout << cntChar;

	// 2.统计文件的有效行数
	int cntLines = 0;
	countLine(ifile, &cntLines);
	cout << cntLines;

	// 3.统计文件的单词的出现次数，并输出前num个单词
	int allWords;
	auto freq = countWords(ifile, allWords);
		// 将map转存到vector，并按值排序，用于提取频数最多的num个单词
	int num;
	cin >> num;
	vector<string, int> vec(freq.begin(), freq.end());
	sort(vec.begin(), vec.end(), cmp_by_value);
	mostWords(vec, num);	// 此函数内即打印

	// 4.统计文件的单词总数
	cout << allWords;

	/*****************************************************************************************/


	string outfilename;

	outfilename = argv[2];

	ofstream out(outfilename);
	if (out.is_open())
	{
		out << "This is a line.\n";
		out << "This is another line.\n";
		out.close();
	}
	system("pause");
}