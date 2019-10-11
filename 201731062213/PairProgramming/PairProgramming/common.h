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
string** countWords(ifstream &ifile, map<string, int> &freq, int &idx, int &idy, int &allWords);

bool cmp_by_value(const PAIR& lhs, const PAIR& rhs);
void mostWords(vector<string, int> &vec, int num);