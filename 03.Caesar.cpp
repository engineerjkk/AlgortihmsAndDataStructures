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
		// ������ �Է��Ͽ� ��ȣȭ �Ͽ� ����Ѵ�
		//
		printf("\n");
	}
	printf("Bye, ....\n");
}

char Encrypt(char chr, int nKey)
{
	// ��ҹ��ڸ� ��ȣȭ
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