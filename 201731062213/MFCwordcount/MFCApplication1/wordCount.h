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
	fileIO filepro;			//文件操作类
	int cntlines;			//行数
	int cntchars;			//字符数
	int cntwords;			//单词数
	string wordstr[1000];	//全部单词
	map<string, int> freq;	//单词及频数


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

	//判断函数
	bool isValid(char ch);
	bool isNum(char ch);
	bool isSplit(char chSplit);
	bool isWord(string word);

	//统计函数
	void countLine();
	void countChar();
	void countWord();
	void frequency();
	void Phrases(int m , ostream  &out);

	//输出函数
	void outPut(ostream &out);
	void outputWordFre(int flag = 10);

	void openFile(string filename);

	void outPutToStr();
};
