// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include <string.h>
#include<cmath>
#include<string>
#include <openssl/md4.h>
char a[99999999999999],hs[99999999999999],s[99999999999999];
using namespace std;
int main()
{
	int len,i,j,v,h=0,f;
	double hh;
	hh = pow(2, 26);
	for (j = 1097940; j < (int)hh; )
	{
		f = j;
		_itoa_s(j, a, 16);//ʮ����תʮ�������ַ���
		len = strlen(a);
		//�ַ���������������Ϊż����
		if (len % 2 != 0)
		{
			a[len - 1] = '\0';
			j = j + 15;
		}
		strcpy_s(hs, a);
		i = 0;
		while (1)//ÿ����16�����ַ�ת��Ϊ�ı��ַ�
		{
			if (1 != sscanf_s(hs + i * 2, "%2x", &v))
				break;
			s[i] = (char)v;
			i++;
		}
		s[i] = 0;
		unsigned char digest[MD4_DIGEST_LENGTH];

		MD4((unsigned char*)&s, strlen(s), (unsigned char*)&digest);

		char mdString[33];
		for (int i = 0; i < MD4_DIGEST_LENGTH; i++)
			sprintf(&mdString[i * 2], "%02x", (unsigned int)digest[i]);
		if (mdString[31] == '0'&&mdString[30] == '0'&&mdString[29] == '0'&&mdString[28] == '8')
		{
			cout << "\n��������������ԭ���ҵ��ˣ�\n" << "\t10���Ʊ�ʾ=" << f << "\t16���Ʊ�ʾ=" << hs << "\t�ַ���ʾ=" << s;
			printf("\nmd4 digest: %s\n", mdString);
			h = 1;
			break;
		}
		j++;
	}
	if(h==0)
		cout << "\nû�ҵ�������������ֵ��";
	return 0;
}

