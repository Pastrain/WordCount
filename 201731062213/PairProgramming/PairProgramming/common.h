#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<string, int> PAIR;

bool isValid(char ch);
bool isNum(char ch);
bool isSplit(char chSplit);
map<string, int> frequency(string **str, int& count);
void countLine(ifstream &ifile, int *cntLines);
void countChar(ifstream &ifile, int *cntChar);
map<string, int> countWords(ifstream &ifile, int &idx)