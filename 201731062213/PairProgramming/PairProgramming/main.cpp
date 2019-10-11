#include"common.h"

int main(int argc, char *argv[])
{
	string infilename;
	infilename = argv[1];
	ifstream iFile(infilename);

	if (iFile.is_open())
	{
		
	}

	int cnt = 1000;

	
	/*****************************************************************************************/

	// 1.统计文件的字符总数
	int cntChar = 0;
	countChar(iFile, &cntChar);
	cout << cntChar;

	// 2.统计文件的有效行数
	int cntLines = 0;
	countLine(iFile, &cntLines);
	cout << cntLines;

	// 3.统计文件的单词的出现次数，并输出前num个单词
	int IDX, IDY, allwords;
	map<string, int> freqeuncy;
	// frequency为字频map，IDX为行数，IDY为列数，allwords为文件的总单词数，皆为引用
	string** str = countWords(iFile, freqeuncy, IDX, IDY, allwords); // 得到返回的string[][]...

		// 将map转存到vector，并按值排序，用于提取频数最多的num个单词
	int num;
	cin >> num;
	vector<string, int> vec(freqeuncy.begin(), freqeuncy.end());
	sort(vec.begin(), vec.end(), cmp_by_value);
	mostWords(vec, num);	// 此函数内即打印

	// 4.统计文件的单词总数
	cout << allwords;

	// 5.输出词组
	int zip;
	cin >> zip;		// 你让我输入zip个一组的词组，我就输出
	for (int zipIdx = 0; zipIdx < IDX; zipIdx++)
	{
		for (int zipIdy = 0; zipIdy < IDY; zipIdy++)
		{
			cout << str[zipIdx][zipIdy];
		}
	}

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