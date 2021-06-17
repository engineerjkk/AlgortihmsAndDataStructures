#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void pcount(char* mystr, int* cnt, int* sort, int* c);
void pdad(int* count, int* sort, int* dad, int total_cnt);
void printALPHABET(int* count, int n1, int n2);
void printK(int* count, int n1, int n2);
void printCOUNT(int* count, int n1, int n2);
void printDAD(int* count, int* dad, int n1, int n2);
void printCODE(int* count, int* dad, int* code, int* len);
void printBC(int* count, int* code, int binary[][MAX], int* len);
int main() {
	char myStr[MAX];
	int sort[MAX] = { 0 };
	int code[MAX] = { 0 };
	int count[MAX] = { 0 };
	int dad[MAX] = { 0 };
	int len[MAX] = { 0 };
	int binary[26][MAX] = { 0 };
	int total_cnt = 0;
	int x = 27;
	printf("String을 입력하시오 : \n");
	gets_s(myStr);
	pcount(myStr, count, sort, &total_cnt);
	pdad(count, sort, dad, total_cnt);
	printf("\n\n");
	printALPHABET(count, 0, 26);
	printK(count, 0, 26);
	printCOUNT(count, 0, 26);
	printf("\n\n");
	printALPHABET(count, 0, 26);
	printK(count, 0, 26);
	printCOUNT(count, 0, 26);
	printDAD(count, dad, 0, 26);
	printf("\n\n");
	printK(count, 27, 52);
	printCOUNT(count, 27, 52);
	printDAD(count, dad, 27, 52);
	printf("\n\n");
	printALPHABET(count, 0, 26);
	printK(count, 0, 26);
	printCODE(count, dad, code, len);
	printf("\n");
	printf("결과\n ");
	printBC(count, code, binary, len);
	
}
void pcount(char* mystr, int* count, int* sort, int* c) {
	for (int i = 0; mystr[i] != NULL; i++) {
		if (mystr[i] == 32)
			continue;
		if (mystr[i] < 'A' || mystr[i] > 'Z')
			break;
	}
	for (int i = 0; mystr[i] != NULL; i++) {
		if (mystr[i] == 32)
			count[0]++;
		else
			count[mystr[i] - 64]++;
	}
	for (int i = 0; i <= 26; i++) {
		if (count[i])
			sort[(*c)++] = i;
	}
}
void pdad(int* count, int* sort, int* dad, int total_cnt) {
	int i = 0, j = 0, temp = 0, x = 27;
	for (i = 0; i < total_cnt; i++) {
		for (j = i; j < total_cnt; j++) {
			if (count[sort[i]] >= count[sort[j]]) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}
		}
	}
	for (i = 0; i < total_cnt - 1; i++) {
		count[x] = count[sort[i]] + count[sort[i + 1]];
		int* p = dad;
		*(p + sort[i]) = x;
		*(p + sort[i + 1]) = -x;
		for (j = i + 1; j < total_cnt - 1; j++) {
			if (count[x] <= count[sort[j + 1]]) {
				sort[j] = x;
				break;
			}
			else {
				sort[j] = sort[j + 1];
				if (j == total_cnt - 2)
					sort[j + 1] = x;
			}
		}
		x++;
	}
}
void printALPHABET(int* count, int n1, int n2) {
	
		printf("%9c", ' ');
	for (int i = n1; i <= n2; i++) {
		if (i == 0)
			printf(" ");
		else if (count[i])
			printf("%5c", i + 64);
		else
			continue;
	}
	printf("\n");
}
void printK(int* count, int n1, int n2) {
	printf("%8c", 'k');
	for (int i = n1; i <= n2; i++) {
		if (count[i])
			printf("%5d", i);
	}
}
void printCOUNT(int* count, int n1, int n2) {
	printf("\ncount[k]");
	for (int i = n1; i <= n2; i++) {
		if (count[i])
			printf("%5d", count[i]);
	}
}
void printDAD(int* count, int* dad, int n1, int n2) {
	printf("\n dad[k]");
	for (int i = n1; i <= n2; i++) {
		if (count[i])
			printf("%5d", dad[i]);
	}
}
void printCODE(int* count, int* dad, int* code, int* len) {
	int i, x, j;
	for (int k = 0; k <= 26; k++) {
		i = 0, x = 0, j = 1;
		if (count[k])
			for (int t = dad[k]; t; t = dad[t], j += j, i++)
				if (t < 0) { x += j; t = -t; }
		code[k] = x; len[k] = i;
	}
	printf("\n code[k]");
	for (i = 0; i <= 26; i++) {
		if (count[i])
			printf("%5d", code[i]);
	}
	printf("\n len[k]");
	for (i = 0; i <= 26; i++) {
			if (count[i])
				printf("%5d", len[i]);
	}
	printf("\n");
}
void printBC(int* count, int* code, int binary[][MAX], int* len) {
	int i = 0, j = 0, k = 0;
	for (i = 0; i <= 26; i++) {
		if (count[i]) {
			int num = code[i];
			int allocC = 0;
			if (num > 0) {
				for (j = 0; num > 0; j++) {
					binary[k][j] = num % 2;
					num = num / 2;
					allocC = j + 1;
				}
			}
			else
				binary[k][j] = 0;
			int allocL = allocC;
			for (j = 0; j < len[i] - allocL; j++) {
				binary[k][allocL + j] = 0;
				allocC++;
			}
			for (j = allocC - 1; j >= 0; j--)
				printf("%d", binary[k][j]);
			printf(" ");
			k++;
		}
	}
}