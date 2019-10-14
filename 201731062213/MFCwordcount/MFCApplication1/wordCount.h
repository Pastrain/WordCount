#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "fileIO.h"


using namespace std;

typedef pair<string, int> PAIR;

class wordCount
{
private:
	fileIO filepro;			//�ļ�������
	int cntlines;			//����
	int cntchars;			//�ַ���
	int cntwords;			//������
	string wordstr[1000];	//ȫ������
	map<string, int> freq;	//���ʼ�Ƶ��


public:

	string outputStr[1000];
	int t;

	wordCount(string filename){
		filepro.filename = filename;
		cntchars = 0;
		cntlines = 0;
		cntwords = 0;
		t = 0;
	}
	wordCount(){
		
		cntchars = 0;
		cntlines = 0;
		cntwords = 0;
	}

	//�жϺ���
	bool isValid(char ch);
	bool isNum(char ch);
	bool isSplit(char chSplit);
	bool isWord(string word);

	//ͳ�ƺ���
	void countLine();
	void countChar();
	void countWord();
	void frequency();
	void Phrases(int m , ostream  &out);

	//�������
	void outPut(ostream &out);
	void outputWordFre(int flag = 10);

	void openFile(string filename);

	void outPutToStr();
};
