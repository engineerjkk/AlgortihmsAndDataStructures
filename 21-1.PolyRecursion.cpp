#include <stdio.h>

#define MAX_TERM 100
#pragma warning (disable: 4996)

typedef int Polynomial[2 * (MAX_TERM + 1)];					// Polynomial: ���׽��� �����Ѵ�

void main()
{
	Polynomial polyA = { 6, 3, -1, 2, -2, 1, 0, -1, };		// �� ǥ��, (���, ����)
	Polynomial polyB = { 5, 4, -1, 2, 2, 1, 8, 0, 0, -1, };
	Polynomial polyC;
	int InputPolynomial(Polynomial A, const char* szMsg);
	void OutputPolynomial(Polynomial A, const char* szMsg);
	int CheckPolynomial(Polynomial A);
	int Attach(Polynomial aPoly, int nCoef, int nExpon);
	int AddPolynomial(Polynomial A, Polynomial B, Polynomial C);
	int SubPolynomial(Polynomial A, Polynomial B, Polynomial C);
	int SimpleMulPolynomial(Polynomial A, int nCoef, int nExpon, Polynomial B);
	int MultiplyPolynomial(Polynomial A, Polynomial B, Polynomial C);
	CheckPolynomial(polyA);
	CheckPolynomial(polyB);
	int bContinue = true;
	while (bContinue) {
		int nFtn;
		printf("1: A, 2: B, 3: Add, 4: Sub, 5: Simple, 6: Mul, 7: pr ? ");
		scanf_s("%d", &nFtn);
		switch (nFtn) {
		case 1:
			if (InputPolynomial(polyA, "A") == 0)					// ���׽� A�� �Է��Ѵ�.
				printf("Input Error\n");
			break;
		case 2:
			if (InputPolynomial(polyB, "B") == 0)					// ���׽� B�� �Է��Ѵ�.
				printf("Input Error\n");
			break;
		case 3:
			polyC[1] = -1;
			if (AddPolynomial(polyA, polyB, polyC))					// ���Ѵ�.
				OutputPolynomial(polyC, "C(X) = ");					// C�� ����Ѵ�.
			break;
		case 4:
			polyC[1] = -1;
			if (SubPolynomial(polyA, polyB, polyC))					// ����.
				OutputPolynomial(polyC, "C(X) = ");					// C�� ����Ѵ�.
			break;
		case 5:
			polyC[1] = -1;
			SimpleMulPolynomial(polyA, polyB[0], polyB[1], polyC);	// �� ���� ���Ѵ�.
			OutputPolynomial(polyC, "C(X) = ");						// C�� ����Ѵ�.
			polyC[1] = -1;
			SimpleMulPolynomial(polyB, polyA[0], polyA[1], polyC);	// �� ���� ���Ѵ�.
			OutputPolynomial(polyC, "C(X) = ");						// C�� ����Ѵ�.
			break;
		case 6:
			if (MultiplyPolynomial(polyA, polyB, polyC))			// ���Ѵ�.
				OutputPolynomial(polyC, "C(X) = ");					// C�� ����Ѵ�.
			break;
		case 7:
			OutputPolynomial(polyA, "A(X) = ");						// A�� ����Ѵ�.
			OutputPolynomial(polyB, "B(X) = ");						// B�� ����Ѵ�.
			break;
		default:
			bContinue = false;
		}
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Attach(Polynomial aPoly, int nCoef, int nExpon)
{	// ������ ������ �ִ��� �����Ͽ� �� ���� ���� �����ϰ� T/F�� ��ȯ�Ѵ�.
	if (aPoly[1] < 0)
		return (aPoly[0] = nCoef, aPoly[1] = nExpon, aPoly[3] = -1);
	return Attach(aPoly + 2, nCoef, nExpon);
}

int AddPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	
	if (A[1] < 0 || B[1] < 0) {//���� �ϳ� ���� ������,
		for (int i = 0; A[i + 1] >= 0; i += 2)
			if (Attach(C, A[i], A[i + 1]) == false)
				return false;
		for (int i = 0; B[i + 1] >= 0; i += 2)
			if (Attach(C, B[i], B[i + 1]) == false)
				return false;
		return true; //������� �°Ÿ� ������ �������ϱ� true�� ��ȯ���ݴϴ�.
	}
	if (A[1] > B[1]) { //���� A�� ������ B�� �������� ũ��
		if (Attach(C, A[0], A[1]) == false)//�ϴ�  Attach�� �����ѹ��ϰ� 
			return false;
		return AddPolynomial(A + 2, B, C); //��Ŀ������ A�� ���������� �Ѿ�� �ٽ� ��Ŀ���Ѵ�.
	}
	if (A[1] == B[1]) {//���� A�� B�� ������ ������
		int nCoef = A[0] + B[0];//������� ������ �ϴµ�
		if (nCoef)
			if (Attach(C, nCoef, A[1]) == false)//���⵵ ���� Attach�Լ��ȿ� �־ ������ �Ѵ�.
				return false;
		return AddPolynomial(A + 2, B + 2, C); //�׸��� ������ ���� ������ �Ѿ��.
	}
	if (Attach(C, B[0], B[1]) == false)
		return false;
	return AddPolynomial(A, B + 2, C);//else��, ���� B�� ������ A�� �������� ũ�� B�� ������ ���� ������ �Ѿ��. 
	// �� ���׽� A, B�� ���Ͽ� ���׽� C�� �����ϰ� T/F�� ��ȯ�Ѵ�.
	// �ݵ�� ��ȯ�Լ��� �ۼ��Ѵ�
	return true;
}

int SubPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	
	if (A[1] < 0 || B[1] < 0) {//���� �ϳ� ���� ������,
		for (int i = 0; A[i + 1] >= 0; i += 2)
			if (Attach(C, A[i], A[i + 1]) == false)
				return false;
		for (int i = 0; B[i + 1] >= 0; i += 2)
			if (Attach(C, -B[i], B[i + 1]) == false)
				return false;
		return true; //������� �°Ÿ� ������ �������ϱ� true�� ��ȯ���ݴϴ�.
	}
	if (A[1] > B[1]) { //���� A�� ������ B�� �������� ũ��
		if (Attach(C, A[0], A[1]) == false)//�ϴ�  Attach�� �����ѹ��ϰ� 
			return false;
		return SubPolynomial(A + 2, B, C); //��Ŀ������ A�� ���������� �Ѿ�� �ٽ� ��Ŀ���Ѵ�.
	}
	if (A[1] == B[1]) {//���� A�� B�� ������ ������
		int nCoef = A[0] - B[0];//������� ������ �ϴµ�
		if (nCoef)
			if (Attach(C, nCoef, A[1]) == false)//���⵵ ���� Attach�Լ��ȿ� �־ ������ �Ѵ�.
				return false;
		return SubPolynomial(A + 2, B + 2, C); //�׸��� ������ ���� ������ �Ѿ��.
	}
	if (Attach(C, -B[0], B[1]) == false)
		return false;
	return SubPolynomial(A, B + 2, C);//else��, ���� B�� ������ A�� �������� ũ�� B�� ������ ���� ������ �Ѿ��. 
	// ���׽� A���� ���׽� B�� ���� ���׽� C�� �����ϰ� T/F�� ��ȯ�Ѵ�.
	// �ݵ�� ��ȯ�Լ��� �ۼ��Ѵ�
	return true;
}

//A���ٰ� B�������� ����־��.
int CopyRemainder(Polynomial A, Polynomial R, int nSign)	// nSign = 1 or -1
{	// ���׽� A�� ������ ���׽� R�� nSign�� ���� (+/-)�� �߰��Ѵ�.
	if (R[1] < 0)//
		return true;
	return Attach(A, R[0] * nSign, R[1]) && CopyRemainder(A, R + 2, nSign);
	//A�� ���� �߰��� �ش�.�� R�� 2 �����Ѵ�. �� ������, 
	//R�� ������ ����, A���ٰ� ������ �ݴϴ�.
}

int SimpleMulPolynomial(Polynomial A, int nCoef, int nExpon, Polynomial B)
{   // ���׽� A�� �� ���� ���Ͽ� ���׽� B�� �����Ѵ�. ���⼭ nCoef�� ������ ���� ����κ�, nExpon�� �����κ��Դϴ�.
   /****
   for (int nNdx = 0; A[nNdx + 1] >= 0; nNdx += 2) {
	  B[nNdx] = A[nNdx] * nCoef;//����� �����ְ�
	  B[nNdx + 1] = A[nNdx + 1] + nExpon;//������ ��������
	  //Attach(B, A[nNdx], A[nNdx + 1]);
   }
   /****/
   /****///��~����
	B[1] = -1; //�׻� B�� �ʱ�ȭ ��Ű�� ���� �������� ! �ʱ�ȭ�� �����־�� Attach�� �����ϱ� ��������.
	for (int nNdx = 0; A[nNdx + 1] >= 0; nNdx += 2) //index�� 0���� polyA�� -1�� �ö�����, ����κи��� �˻����ݴϴ�.
		Attach(B, A[nNdx] * nCoef, A[nNdx + 1] + nExpon);//����� �����ְ�, ������ �����ָ鼭 polyA�� -1�� ���������� �����ݴϴ�.
	 /****/
	return true;
}
int MultiplyPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	// �� ���׽� A, B�� ���Ͽ� ���׽� C�� �����ϰ� T/F�� ��ȯ�Ѵ�.
	if (B[1] == -1)												// ���� �������� ������
		return C[1] = -1; //or true�ص��ȴ�.					// ���� ����, -1�� true
	Polynomial smplPoly, nextPoly;
	SimpleMulPolynomial(A, B[0], B[1], smplPoly);				// �� �װ� ���׽��� ���Ѵ�.
	//A�� B�� ������ ���ؼ� smplPoly�� �����Ѵ�.
	return MultiplyPolynomial(A, B + 2, nextPoly) &&			// ������ ���׽��� ���Ѵ�.
		AddPolynomial(smplPoly, nextPoly, C);					// �� ����� ���Ѵ�.
	//A�� B�� �������� �ٽ� ��ȯ�Լ��� SimplePoly�� ���ѵڿ� nextPoly�� �����Ѵ�.
	//�׷��鼭 ����ؼ� SmplPoly�� nextPoly�� �����ָ� �����Ѵ�.
	//���� B�� ���� ������ C[1]���� -1�� �־��ش�. 
}

/*int MultiplyPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	

	if (B[1] < 0) { C = 0; true; }//B�� �����κ��� -1�̸� �ߴ��մϴ�. Bsms+2�������ϴ� �� ��������.
	Polynomial C1, C2;// ���׽� �迭 C1�� C2�� �����մϴ�. �� �迭�� ������ ���̴� �ʱ�ȭ�ϸ� �ȵ˴ϴ�.
	SimpleMulPolynomial(A, B[0], B[1], C2); //A ���׽İ� B�� ù��° ����� ������ �־��ݴϴ�. �׸��� C2�� �����մϴ�. C2������ -1�� ����.
	CopyRemainder(C1, C2, 1);//C2�� -1�϶����� ���鼭 C1���ٰ� ���� �������ݴϴ�. C1���ٰ� �����������ִ� ������.
	C[1] = -1;//�ʱ�ȭ??//
	AddPolynomial(C1, C2, C);//
	return MultiplyPolynomial(A, B+2, );//A�� �ǵ����� �ʴ´�. B�� �����ϰ� ��	�� �����ؼ� �����ִ� ���̴�.
	// �� ���׽� A, B�� ���Ͽ� ���׽� C�� �����ϰ� T/F�� ��ȯ�Ѵ�.
	// �ݵ�� ��ȯ�Լ��� �ۼ��Ѵ�
}*/

int CheckPolynomial(Polynomial aPoly)
{	// ���׽��� �ùٸ��� üũ
	int bRight = true;
	int nExpon, nPrvExpon = aPoly[1] + 1;
	for (int i = 0; i <= 2 * MAX_TERM; i += 2) {
		nExpon = aPoly[i + 1];
		if (nExpon == -1)
			return bRight;
		if (aPoly[i] == 0) {									// ����� 0���� üũ
			fprintf(stderr, "%d ��° ���� ����� 0 �Դϴ�.\n", i / 2 + 1);
			bRight = false;
		}
		if (nExpon < 0 || nExpon >= nPrvExpon) {				// ������ ����̸鼭 ��������
			fprintf(stderr, "%d ��° ���� ������ �߸� �Ǿ����ϴ�.\n", i / 2 + 1);
			bRight = false;
		}
		nPrvExpon = nExpon;
	}
	return false;
}

int InputPolynomial(Polynomial aPoly, const char* szMsg)
{	// ���׽��� �Է�
	int nCtr;
	fprintf(stderr, "%s ���׽��� �Է��մϴ�.\n", szMsg);
	do {
		fprintf(stderr, "���� ������ ? ");
		scanf_s("%d", &nCtr);
	} while (nCtr < 0);
	if (nCtr > MAX_TERM) {
		fprintf(stderr, "���� �ʹ� �����ϴ�.\n");
		return false;
	}
	nCtr *= 2;
	int nNdx;
	for (nNdx = 0; nNdx < nCtr; nNdx += 2) {
		fprintf(stderr, "%d ��° ���� ����� ? ", nNdx / 2 + 1);
		scanf_s("%d", &aPoly[nNdx]);
		fprintf(stderr, "%d ��° ���� ������ ? ", nNdx / 2 + 1);
		scanf_s("%d", &aPoly[nNdx + 1]);
	}
	aPoly[nNdx + 1] = -1;	/* ���� ǥ���Ѵ� */
	return CheckPolynomial(aPoly);
}

void OutputPolynomial(Polynomial aPoly, const char* szMsg)
{	// ���׽��� ���
	printf(szMsg);
	if (aPoly[1] == -1)
		putchar('0');
	else {
		for (int i = 0; aPoly[i + 1] >= 0; i += 2) {
			int nCoeff = aPoly[i];					// ���
			int nExpon = aPoly[i + 1];				// ����
			char cSign = '+';
			if (nCoeff < 0) {						// +/- �غ�
				cSign = '-';
				nCoeff = -nCoeff;
			}
			if (i || cSign == '-')					// ù ���� ����� ��츸 ����
				if (i == 0 && cSign == '-')			// ù ���� ����
					printf("-");
				else
					printf(" %c ", cSign);			// ��ȣ ���
			if (nCoeff != 1 || nExpon == 0)
				printf("%d", nCoeff);				// ��� ���
			if (nExpon > 0) {
				putchar('X');
				if (nExpon > 1)
					printf("^%d", nExpon);			// ���� ���
			}
		}
	}
	putchar('\n');
}