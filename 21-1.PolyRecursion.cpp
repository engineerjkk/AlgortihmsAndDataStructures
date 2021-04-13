#include <stdio.h>

#define MAX_TERM 100
#pragma warning (disable: 4996)

typedef int Polynomial[2 * (MAX_TERM + 1)];					// Polynomial: 다항식을 정의한다

void main()
{
	Polynomial polyA = { 6, 3, -1, 2, -2, 1, 0, -1, };		// 끝 표시, (계수, 지수)
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
			if (InputPolynomial(polyA, "A") == 0)					// 다항식 A를 입력한다.
				printf("Input Error\n");
			break;
		case 2:
			if (InputPolynomial(polyB, "B") == 0)					// 다항식 B를 입력한다.
				printf("Input Error\n");
			break;
		case 3:
			polyC[1] = -1;
			if (AddPolynomial(polyA, polyB, polyC))					// 더한다.
				OutputPolynomial(polyC, "C(X) = ");					// C를 출력한다.
			break;
		case 4:
			polyC[1] = -1;
			if (SubPolynomial(polyA, polyB, polyC))					// 뺀다.
				OutputPolynomial(polyC, "C(X) = ");					// C를 출력한다.
			break;
		case 5:
			polyC[1] = -1;
			SimpleMulPolynomial(polyA, polyB[0], polyB[1], polyC);	// 한 항을 곱한다.
			OutputPolynomial(polyC, "C(X) = ");						// C를 출력한다.
			polyC[1] = -1;
			SimpleMulPolynomial(polyB, polyA[0], polyA[1], polyC);	// 한 항을 곱한다.
			OutputPolynomial(polyC, "C(X) = ");						// C를 출력한다.
			break;
		case 6:
			if (MultiplyPolynomial(polyA, polyB, polyC))			// 곱한다.
				OutputPolynomial(polyC, "C(X) = ");					// C를 출력한다.
			break;
		case 7:
			OutputPolynomial(polyA, "A(X) = ");						// A를 출력한다.
			OutputPolynomial(polyB, "B(X) = ");						// B를 출력한다.
			break;
		default:
			bContinue = false;
		}
		putchar('\n');
	}
	printf("Bye, ....\n\n");
}

int Attach(Polynomial aPoly, int nCoef, int nExpon)
{	// 저장할 공간이 있는지 조사하여 한 항을 끝에 저장하고 T/F를 반환한다.
	if (aPoly[1] < 0)
		return (aPoly[0] = nCoef, aPoly[1] = nExpon, aPoly[3] = -1);
	return Attach(aPoly + 2, nCoef, nExpon);
}

int AddPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	
	if (A[1] < 0 || B[1] < 0) {//둘중 하나 식이 없으면,
		for (int i = 0; A[i + 1] >= 0; i += 2)
			if (Attach(C, A[i], A[i + 1]) == false)
				return false;
		for (int i = 0; B[i + 1] >= 0; i += 2)
			if (Attach(C, B[i], B[i + 1]) == false)
				return false;
		return true; //여기까지 온거면 끝까지 돌았으니까 true를 반환해줍니다.
	}
	if (A[1] > B[1]) { //만약 A의 지수가 B의 지수보다 크면
		if (Attach(C, A[0], A[1]) == false)//일단  Attach로 점검한번하고 
			return false;
		return AddPolynomial(A + 2, B, C); //리커젼으로 A가 다음지수로 넘어가서 다시 리커젼한다.
	}
	if (A[1] == B[1]) {//만약 A와 B의 지수가 같으면
		int nCoef = A[0] + B[0];//계수끼리 연산을 하는데
		if (nCoef)
			if (Attach(C, nCoef, A[1]) == false)//여기도 역시 Attach함수안에 넣어서 점검을 한다.
				return false;
		return AddPolynomial(A + 2, B + 2, C); //그리고 지수는 다음 차수로 넘어간다.
	}
	if (Attach(C, B[0], B[1]) == false)
		return false;
	return AddPolynomial(A, B + 2, C);//else로, 만약 B의 지수가 A의 지수보다 크면 B의 차수가 다음 차수로 넘어간다. 
	// 두 다항식 A, B를 더하여 다항식 C에 저장하고 T/F를 반환한다.
	// 반드시 순환함수로 작성한다
	return true;
}

int SubPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	
	if (A[1] < 0 || B[1] < 0) {//둘중 하나 식이 없으면,
		for (int i = 0; A[i + 1] >= 0; i += 2)
			if (Attach(C, A[i], A[i + 1]) == false)
				return false;
		for (int i = 0; B[i + 1] >= 0; i += 2)
			if (Attach(C, -B[i], B[i + 1]) == false)
				return false;
		return true; //여기까지 온거면 끝까지 돌았으니까 true를 반환해줍니다.
	}
	if (A[1] > B[1]) { //만약 A의 지수가 B의 지수보다 크면
		if (Attach(C, A[0], A[1]) == false)//일단  Attach로 점검한번하고 
			return false;
		return SubPolynomial(A + 2, B, C); //리커젼으로 A가 다음지수로 넘어가서 다시 리커젼한다.
	}
	if (A[1] == B[1]) {//만약 A와 B의 지수가 같으면
		int nCoef = A[0] - B[0];//계수끼리 연산을 하는데
		if (nCoef)
			if (Attach(C, nCoef, A[1]) == false)//여기도 역시 Attach함수안에 넣어서 점검을 한다.
				return false;
		return SubPolynomial(A + 2, B + 2, C); //그리고 지수는 다음 차수로 넘어간다.
	}
	if (Attach(C, -B[0], B[1]) == false)
		return false;
	return SubPolynomial(A, B + 2, C);//else로, 만약 B의 지수가 A의 지수보다 크면 B의 차수가 다음 차수로 넘어간다. 
	// 다항식 A에서 다항식 B를 빼서 다항식 C에 저장하고 T/F를 반환한다.
	// 반드시 순환함수로 작성한다
	return true;
}

//A에다가 B나머지를 집어넣어라.
int CopyRemainder(Polynomial A, Polynomial R, int nSign)	// nSign = 1 or -1
{	// 다항식 A에 나머지 다항식 R을 nSign에 따라 (+/-)로 추가한다.
	if (R[1] < 0)//
		return true;
	return Attach(A, R[0] * nSign, R[1]) && CopyRemainder(A, R + 2, nSign);
	//A에 항을 추가해 준다.또 R을 2 증가한다. 즉 나머지, 
	//R을 끝까지 돌며, A에다가 저장해 줍니다.
}

int SimpleMulPolynomial(Polynomial A, int nCoef, int nExpon, Polynomial B)
{   // 다항식 A와 한 항을 곱하여 다항식 B에 저장한다. 여기서 nCoef는 곱해줄 항의 계수부분, nExpon은 지수부분입니다.
   /****
   for (int nNdx = 0; A[nNdx + 1] >= 0; nNdx += 2) {
	  B[nNdx] = A[nNdx] * nCoef;//계수는 곱해주고
	  B[nNdx + 1] = A[nNdx + 1] + nExpon;//지수는 더해주죠
	  //Attach(B, A[nNdx], A[nNdx + 1]);
   }
   /****/
   /****///긴~버전
	B[1] = -1; //항상 B를 초기화 시키는 것을 잊지말자 ! 초기화를 시켜주어야 Attach가 가능하기 때문이죠.
	for (int nNdx = 0; A[nNdx + 1] >= 0; nNdx += 2) //index가 0부터 polyA의 -1이 올때까지, 계수부분만을 검사해줍니다.
		Attach(B, A[nNdx] * nCoef, A[nNdx + 1] + nExpon);//계수는 곱해주고, 지수는 더해주면서 polyA가 -1을 만날때까지 돌아줍니다.
	 /****/
	return true;
}
int MultiplyPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	// 두 다항식 A, B를 곱하여 다항식 C에 저장하고 T/F를 반환한다.
	if (B[1] == -1)												// 항이 존재하지 않으면
		return C[1] = -1; //or true해도된다.					// 항이 없음, -1은 true
	Polynomial smplPoly, nextPoly;
	SimpleMulPolynomial(A, B[0], B[1], smplPoly);				// 한 항과 다항식을 곱한다.
	//A와 B의 한항을 곱해서 smplPoly에 저장한다.
	return MultiplyPolynomial(A, B + 2, nextPoly) &&			// 나머지 다항식을 곱한다.
		AddPolynomial(smplPoly, nextPoly, C);					// 두 결과를 더한다.
	//A와 B의 다음항을 다시 순환함수로 SimplePoly로 곱한뒤에 nextPoly에 저장한다.
	//그러면서 계속해서 SmplPoly와 nextPoly를 더해주며 누적한다.
	//만약 B가 항이 끝나면 C[1]에도 -1을 넣어준다. 
}

/*int MultiplyPolynomial(Polynomial A, Polynomial B, Polynomial C)
{	

	if (B[1] < 0) { C = 0; true; }//B의 지수부분이 -1이면 중단합니다. Bsms+2씩증가하니 곧 도달하죠.
	Polynomial C1, C2;// 다항식 배열 C1과 C2를 선언합니다. 이 배열에 누적할 것이니 초기화하면 안됩니다.
	SimpleMulPolynomial(A, B[0], B[1], C2); //A 다항식과 B의 첫번째 계수와 지수를 넣어줍니다. 그리고 C2에 저장합니다. C2끝에는 -1이 있죠.
	CopyRemainder(C1, C2, 1);//C2가 -1일때까지 돌면서 C1에다가 전부 저장해줍니다. C1에다가 누적저장해주는 것이죠.
	C[1] = -1;//초기화??//
	AddPolynomial(C1, C2, C);//
	return MultiplyPolynomial(A, B+2, );//A는 건들이지 않는다. B가 증가하고 그	걸 누적해서 더해주는 것이다.
	// 두 다항식 A, B를 곱하여 다항식 C에 저장하고 T/F를 반환한다.
	// 반드시 순환함수로 작성한다
}*/

int CheckPolynomial(Polynomial aPoly)
{	// 다항식이 올바른지 체크
	int bRight = true;
	int nExpon, nPrvExpon = aPoly[1] + 1;
	for (int i = 0; i <= 2 * MAX_TERM; i += 2) {
		nExpon = aPoly[i + 1];
		if (nExpon == -1)
			return bRight;
		if (aPoly[i] == 0) {									// 계수가 0인지 체크
			fprintf(stderr, "%d 번째 항의 계수가 0 입니다.\n", i / 2 + 1);
			bRight = false;
		}
		if (nExpon < 0 || nExpon >= nPrvExpon) {				// 지수가 양수이면서 내림차순
			fprintf(stderr, "%d 번째 항의 지수가 잘못 되었습니다.\n", i / 2 + 1);
			bRight = false;
		}
		nPrvExpon = nExpon;
	}
	return false;
}

int InputPolynomial(Polynomial aPoly, const char* szMsg)
{	// 다항식을 입력
	int nCtr;
	fprintf(stderr, "%s 다항식을 입력합니다.\n", szMsg);
	do {
		fprintf(stderr, "항의 갯수는 ? ");
		scanf_s("%d", &nCtr);
	} while (nCtr < 0);
	if (nCtr > MAX_TERM) {
		fprintf(stderr, "항이 너무 많습니다.\n");
		return false;
	}
	nCtr *= 2;
	int nNdx;
	for (nNdx = 0; nNdx < nCtr; nNdx += 2) {
		fprintf(stderr, "%d 번째 항의 계수는 ? ", nNdx / 2 + 1);
		scanf_s("%d", &aPoly[nNdx]);
		fprintf(stderr, "%d 번째 항의 지수는 ? ", nNdx / 2 + 1);
		scanf_s("%d", &aPoly[nNdx + 1]);
	}
	aPoly[nNdx + 1] = -1;	/* 끝을 표시한다 */
	return CheckPolynomial(aPoly);
}

void OutputPolynomial(Polynomial aPoly, const char* szMsg)
{	// 다항식을 출력
	printf(szMsg);
	if (aPoly[1] == -1)
		putchar('0');
	else {
		for (int i = 0; aPoly[i + 1] >= 0; i += 2) {
			int nCoeff = aPoly[i];					// 계수
			int nExpon = aPoly[i + 1];				// 지수
			char cSign = '+';
			if (nCoeff < 0) {						// +/- 준비
				cSign = '-';
				nCoeff = -nCoeff;
			}
			if (i || cSign == '-')					// 첫 항이 양수일 경우만 제외
				if (i == 0 && cSign == '-')			// 첫 항이 음수
					printf("-");
				else
					printf(" %c ", cSign);			// 부호 출력
			if (nCoeff != 1 || nExpon == 0)
				printf("%d", nCoeff);				// 계수 출력
			if (nExpon > 0) {
				putchar('X');
				if (nExpon > 1)
					printf("^%d", nExpon);			// 지수 출력
			}
		}
	}
	putchar('\n');
}