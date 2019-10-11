#include"common.h"

// �ж��Ƿ��������ֻ�����ĸ��Χ
bool isValid(char ch)
{
	if ((ch >= 'A' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		return true;
	else
		return false;
}

// �ж��Ƿ�������
bool isNum(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	else
		return false;
}


// �ж��Ƿ��������ţ����ָ�����
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

// ͳ������
void countLine(ifstream &ifile, int *cntLines)
{
	char line[1000];
	while (!ifile.eof())
	{
		ifile.getline(line, 1000, '\n');
		*cntLines++;
	}
}
// ͳ���ַ���
void countChar(ifstream &ifile, int *cntChar)
{
	char c;
	cntChar = 0;
	while (ifile.get(c))
		*cntChar++;
	cout << *cntChar << endl;
}

#if 1
// ͳ�Ƶ�����������(ifile:�ļ�����    freq:Ƶ��ͳ��   idx:����str�����±�   idy:���±�    allWords:�ܹ��ĵ�����)
// ����һ��string[][]
string** countWords(ifstream &ifile, map<string, int> &freq, int &idx, int &idy, int &allWords)
{
	char ch;
	string str[100][256];	// [100]����ǵ�i�У�[256]����Ǹ��е�j������
	idx = 0;		// ����str���±�
	string lineStr;		// lineStrΪ��ʱ��һ��
	//numPhrases = 0;		// ���ڼ������

	int tmp = 0;
	for (int iLine = 0; !ifile.eof(); iLine++)
	{
		getline(ifile, lineStr);
		int i = 0;			// ����ѭ��һ��(lineStr)

		string wordStr = "";	// �洢��ǰ�����ǵ��ʵ��ַ�

		while (i++ != lineStr.length()) {
			//if (lineStr[i] == ��ĸ / ����)
			if (isValid(lineStr[i]))
				wordStr += lineStr[i];
			else {
				bool flag = 1;
				// �����ǰ��ʱ�洢��wordStr���ȳ�����4���ַ����Ϳ������ڵ�����
				if (wordStr.length() >= 4)
				{
					for (int in = 0; in < 4; in++)
					{
						//if (wordStr[newi] == ����)
						if (isNum(lineStr[in])) {
							flag = false;
							break;
						}
					}
					// ���ǰ4���ַ�����û�����֣��Ǿ�ȷ�������ַ���
					if (flag == true) {
						str[iLine][idx] = wordStr;
						allWords++;
						wordStr = "";
					}
				}
				/*else {
					str[iLine][idx] = wordStr;
					wordStr = "";
				}*/
			}
		}
	}
	freq = frequency((string**)str, idx);		// ����ͳ����Ƶ��freq

	return (string**)str;
}

// map�ֵ�����ÿ�ֵ��ʵ�Ƶ��
map<string, int> frequency(string **str, int& cntLine, int& cnt)
{
	map<string, int> freq;
	map<string, int>::iterator it;

	// ��ǰ��current��string���� < �ܵ�string��������ʱ������
	for (int curLine = 0; curLine < cntLine; curLine++)
		for (int curIdx = 0; curIdx < cnt; curIdx++)
		{
			// ����map��������ظ��ģ���Ӧ��������ĸ���++
			for (it = freq.begin(); it != freq.end(); it++)
			{
				if (it->first == str[curLine][curIdx]) {
					it->second++;
					break;
				}
			}
			// ���û���ظ��ģ�����ӽ�ȥ
			if (it != freq.end())
				freq.insert(make_pair(str[curLine][curIdx], 1));
		}
	return freq;
}
#endif

#if 0
// ͳ�Ƶ�����ԭ��
map<string, int> countWords(ifstream &ifile, int &idx, int &numPhrases)
{
	char ch;
	string str[1000];	// ����ֵĵ��ʣ����ظ���
	idx = 0;		// ����str���±�
	string lineStr;		// lineStrΪ��ʱ��һ��
	numPhrases = 0;		// ���ڼ������

	int tmp = 0;
	while (!ifile.eof())
	{
		getline(ifile, lineStr);
		int i = 0;			// ����ѭ��һ��(lineStr)
		string str[1000];

		string wordStr = "";

		while (i++ != lineStr.length()) {
			//if (lineStr[i] == ��ĸ / ����)
			if (isValid(lineStr[i]))
				wordStr += lineStr[i];
			else {
				bool flag = 1;
				// �����ǰ��ʱ�洢��wordStr���ȳ�����4���ַ����Ϳ������ڵ�����
				if (wordStr.length() >= 4)
				{
					for (int in = 0; in < 4; in++)
					{
						//if (wordStr[newi] == ����)
						if (isNum(lineStr[in])) {
							flag = false;
							break;
						}
					}
					// ���ǰ4���ַ�����û�����֣��Ǿ�ȷ�������ַ���
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
	auto freq = frequency(str, idx, );		// ����ͳ����Ƶ��freq
	return freq;
}
#endif

// �Ƚ�ֵ��С�ĺ���������main������sort
bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
	return lhs.second < rhs.second;
}
// ѡ��Ƶ������ǰnum����,���
void mostWords(vector<string, int> &vec, int num)
{
	// ��forѭ�������ڲ��ԣ�����Ҫ�ĳ�������ļ���
	for (int i = 0; i < num; ++i)
		cout << vec[i] << endl;
}