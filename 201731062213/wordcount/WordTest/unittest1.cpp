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
			// TODO: �ڴ�������Դ���
			wordCount wordC("test.txt");

			//��������ͳ��
			wordC.countLine();
			//�����ַ�ͳ��
			wordC.countChar();
			//���Ե���ͳ��
			wordC.countWord();
			//���Դ�Ƶͳ��
			wordC.frequency();


			//���Դ���ͳ��
			wordC.Phrases(3);

			//���������Ƶͳ��
			wordC.outputWordFre(5);

			//�����������Ļ
			wordC.outPut(cout);

			//����������ļ�
			string filename("hello.txt");
			ofstream ofile(filename);
			wordC.outPut(ofile);
		}

	};
}