#include "stdafx.h"
#include "CppUnitTest.h"

#include "../wordcount/wordCount.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WordTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			wordCount wordC("test.txt");

			//测试行数统计
			wordC.countLine();
			//测试字符统计
			wordC.countChar();
			//测试单词统计
			wordC.countWord();
			//测试词频统计
			wordC.frequency();


			//测试词组统计
			wordC.Phrases(3);

			//测试输出词频统计
			wordC.outputWordFre(5);

			//测试输出到屏幕
			wordC.outPut(cout);

			//测试输出到文件
			string filename("hello.txt");
			ofstream ofile(filename);
			wordC.outPut(ofile);
		}

	};
}