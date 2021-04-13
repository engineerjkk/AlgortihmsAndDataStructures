#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning( disable : 4996 )

void main()
{
	char sMsg[80];
	int nKey = 3, nMore = true;
	while (nMore) {
		printf("? ");
		//
		// 한줄을 입력하여 암호화 하여 출력한다
		//
		printf("\n");
	}
	printf("Bye, ....\n");
}

char Encrypt(char chr, int nKey)
{
	// 대소문자만 암호화
	return chr;
}

/*****
? I Love You
  L Oryh Brx

? @
Key ? -3

? L Oryh Brx
  I Love You

?
Bye, ....
*****/