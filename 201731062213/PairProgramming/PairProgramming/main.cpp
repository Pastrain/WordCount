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

	// 1.ͳ���ļ����ַ�����
	int cntChar = 0;
	countChar(iFile, &cntChar);
	cout << cntChar;

	// 2.ͳ���ļ�����Ч����
	int cntLines = 0;
	countLine(iFile, &cntLines);
	cout << cntLines;

	// 3.ͳ���ļ��ĵ��ʵĳ��ִ����������ǰnum������
	int IDX, IDY, allwords;
	map<string, int> freqeuncy;
	// frequencyΪ��Ƶmap��IDXΪ������IDYΪ������allwordsΪ�ļ����ܵ���������Ϊ����
	string** str = countWords(iFile, freqeuncy, IDX, IDY, allwords); // �õ����ص�string[][]...

		// ��mapת�浽vector������ֵ����������ȡƵ������num������
	int num;
	cin >> num;
	vector<string, int> vec(freqeuncy.begin(), freqeuncy.end());
	sort(vec.begin(), vec.end(), cmp_by_value);
	mostWords(vec, num);	// �˺����ڼ���ӡ

	// 4.ͳ���ļ��ĵ�������
	cout << allwords;

	// 5.�������
	int zip;
	cin >> zip;		// ����������zip��һ��Ĵ��飬�Ҿ����
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