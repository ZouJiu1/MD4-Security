// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
		_itoa_s(j, a, 16);//十进制转十六进制字符串
		len = strlen(a);
		//字符串个数是奇数补为偶数个
		if (len % 2 != 0)
		{
			a[len - 1] = '\0';
			j = j + 15;
		}
		strcpy_s(hs, a);
		i = 0;
		while (1)//每两个16进制字符转换为文本字符
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
			cout << "\n满足特殊条件的原像找到了！\n" << "\t10进制表示=" << f << "\t16进制表示=" << hs << "\t字符表示=" << s;
			printf("\nmd4 digest: %s\n", mdString);
			h = 1;
			break;
		}
		j++;
	}
	if(h==0)
		cout << "\n没找到符合条件的数值！";
	return 0;
}

