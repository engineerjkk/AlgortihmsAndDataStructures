#include <stdio.h>

#pragma warning(disable: 4996)

typedef int NatNo;

NatNo Zero();
int   IsZero(NatNo x);
NatNo Succ(NatNo x);
NatNo Pred(NatNo x);
NatNo Add(NatNo x, NatNo y);

// Practise
int   Equal(NatNo x, NatNo y);
int   Greater(NatNo x, NatNo y);
NatNo Sub(NatNo x, NatNo y);		// Error example

// HW
NatNo Mul(NatNo x, NatNo y);
NatNo Div(NatNo x, NatNo y);		// Error case
NatNo Mod(NatNo x, NatNo y);		// Error case

void main()
{
	while (1) {
		int nFtn;
		NatNo x, y, z;
		printf("Is1, Su2, Ad3, Eq4, Gt5, Sb6, Mu7, Di8, Mo9: ? ");

		scanf_s("%d", &nFtn);
		if (nFtn < 1 || nFtn > 9)
			break;
		printf("x ? ");

		scanf_s("%d", &x);
		if (nFtn > 2) {
			printf("y ? ");
			scanf_s("%d", &y);
		}

		switch (nFtn) {
		case 1:
			z = IsZero(x);
			break;
		case 2:
			z = Succ(x);
			break;
		case 3:
			z = Add(x, y);
			break;
		case 4:
			z = Equal(x, y);
			break;
		case 5:
			z = Greater(x, y);
			break;
		case 6:
			z = Sub(x, y);
			break;
		case 7:
			z = Mul(x, y);
			break;
		case 8:
			z = Div(x, y);
			break;
		case 9:
			z = Mod(x, y);
		}
		printf("return %d\n\n", z);
	}
}

NatNo Error()
{
	printf("Error:: not applicable operator!!!\n");
	return Zero();
}

NatNo Zero()
{
	return 0;
}

int IsZero(NatNo x)//1
{
	// [1]:(Z)	IsZero(Zero) ::= true
	// [2]:(N)	IsZero(Succ(x)) ::= false

	if (x == Zero())	// ==�� ��¿ �� ����
		return true;	// [1]
	return false;		// [2]
}

NatNo Succ(NatNo x)//2
{
	return x + 1;		// +�� ��¿ �� ����
}

NatNo Pred(NatNo x)
{
	if (IsZero(x))
		return Error();
	return x - 1;		// -�� ��¿ �� ����
}

/*** 
	�����ϱ� ���Ͽ� ��������� ��¿ �� ���� 
	�ٸ� �����ڸ� ����Ͽ�����
	���⼭���ʹ� ������ ���ǵ� ������ �̿ܿ�
	�ٸ� �����ڴ� ����� ����� �� ����.
***/

NatNo Add(NatNo x, NatNo y)//3
{	// x + y
	/*** Method 1 Begin ***
	// Add(x + 1, y) ::= Add(x, y) + 1			;; �Ϲ� ����
	//     x  y
	// (1) Z  A --> y							;; �ߴ� ����
	// [1]:(Z,A)	Add(Zero(), y) ::= y
	// [2]:(N,A)	Add(Succ(x), y) ::= Succ(Add(x, y))
	*/
	if (IsZero(x))
		return y;
	return Succ(Add(Pred(x), y));
	/*** Method 1 End *****/

	/*** Method 2 Begin ***
	// Add(x, y + 1) ::= Add(x, y) + 1			;; �Ϲ� ����
	//     x  y
	// (1) ?  ? --> ?						;; �ߴ� ����
	// (2) ~~~~
	// [1]:(?,?)	Add(?, ?) ::= ?
	// [2]:(?,?)	Add(?, ?) ::= ?

	return Zero();
	/*** Method 2 End *****/
}

int Equal(NatNo x, NatNo y)//4
{	// x == y
	// Equal(x + 1, y + 1) ::= Equal(x, y)		;; �Ϲ� ����
	//     x  y
	// (1) Z  Z --> true						;; �ߴ� ����
	// (2) Z  N --> false
	// (3) N  Z --> false
	/*** Method 1 Begin ***/
	// (1)�� (2)�� ��ħ(�� ����� ���� true, false)
	// [1]:(Z,A)	Equal(Zero(), y) ::= IsZero(y)				;; IF IsZero(y) THEN true ELSE false
	// [2]:(N,Z)	Equal(Succ(x), Zero()) ::= false
	// [3]:(N,N)	Equal(Succ(x), Succ(y)) ::= Equal(x, y)
	if (IsZero(x))//x�� 0�̸�
		return IsZero(y);//Iszero�� �����ߴµ�
	if (IsZero(y))//y�� 0�̸�
		return false;//false ����
	return Equal(Pred(x), Pred(y));// , printf(" : %d,%d\n", x, y);//���� �ϳ��� ����. �ٵ� ���� 0�� �����ϸ�, �߰��� false�� �����ϰ���
	/*** Method 1 End *****/

	/*** Method 2 Begin ***
	//     x  y
	// (1) Z  Z --> true						;; �ߴ� ����
	// (2) Z  N --> false
	// (3) N  Z --> false
	// (1)�� (3)�� ��ħ
	// [1]:(A,Z)	Equal(x, Zero()) ::= IsZero(x)
	// [2]:(Z,N)	Equal(Zero(), ?) ::= false
	// [3]:(N,N)	Equal(Succ(x), Succ(y)) ::= Equal(x,y)
	*/
	if (IsZero(y))
		return IsZero(x);
	if (IsZero(x))
		return false;
	return Equal(Pred(x),Pred(y));
	/*** Method 2 End *****/
}

int Greater(NatNo x, NatNo y)//5
{	// x > y
	// Greater(x + 1, y + 1) ::= Greater(x , y)			;; �Ϲ� ����
	/*** Method 1 Begin ***/ //Ȯ���� ���1�� ����
	//     x  y
	// (1) Z  Z --> false						;; �ߴ� ����
	// (2) Z  N --> false
	// (3) N  Z --> true
	// (1)�� (2)�� ��ħ
	// [1]:(Z,A)	Greater(Zero(), y) ::= false
	// [2]:(N,Z)	Greater(Succ(x), Zero()) ::= true
	// [3]:(N,N)	Greater(Succ(x), Succ(y)) ::= Greater(x,y)
	if (IsZero(x))
		return false;
	if (IsZero(y))
		return true;
	return Greater(Pred(x),Pred(y));	
	/*** Method 1 End *****/

	/*** Method 2 Begin ***
	// (1) Z  Z --> false						;; �ߴ� ����
	// (2) N  Z --> true
	// (3) Z  N --> false
	// (1)�� (3)�� ��ħ
	// [1]:(A,Z)	Greater(x, Zeero()) ::= IF (IsZero(x)) THEN false ELSE true
	// [2]:(Z,N)	Greater(Zero(), Succ(y)) ::= false
	// [3]:(N,N)	Greater(Succ(x), Succ(y)) ::= Greater(x,y)
	*/
	if (IsZero(y))
		return IsZero(x) ? false : true;
	if (IsZero(x))
		return false; 
	return Greater(Pred(x), Pred(y));
	/*** Method 2 End *****/
}

NatNo Sub(NatNo x, NatNo y)//6
{	// x - y
	// Sub(x + 1, y + 1) ::= Sub(x, y)			;; �Ϲ� ����
	/*** Method 1 Begin ***/
	// (1) Z  Z --> 0						;; �ߴ� ����
	// (2) Z  N --> Error
	// (3) N  Z --> x
	// (1)�� (2)�� ��ħ
	// [1]:(Z,A)	Sub(Zero(), y) ::= IF IsZero(y) THEN Zero() ELSE Error
	// [2]:(N,Z)	Sub(Succ(x), Zero()) ::= x
	// [3]:(?,?)	Sub(Succ(x), Succ(y)) ::= Sub(x,y)
	if (IsZero(x))
		return IsZero(y) ? Zero() : Error();
	if (IsZero(y))
		return x;
	return Sub(Pred(x), Pred(y));

	return Zero();
	/*** Method 1 End *****/
	/*** Method 2 Begin ***
	//     x  y
	// (1) Z  Z --> 0						;; �ߴ� ����
	// (2) Z  N --> Error
	// (3) N  Z --> x
	// (1)�� (3)�� ��ħ
	// [1]:(A,Z)	Sub(x, Zero()) ::= ?
	// [2]:(Z,N)	Sub(Zero(), Succ(y)) ::= Error 
	// [3]:(?,?)	Sub(Succ(x), Succ(y)) ::= Sub(x,y)
	*/
	if (IsZero(y))
		return x;
	if (IsZero(x))
		return Error();
	return Sub(Pred(x), Pred(y));

	return Zero();
	/*** Method 2 End *****/
}

NatNo Mul(NatNo x, NatNo y)//7
{	// x * y
	/*** Method 1 Begin ***/
	// Mul(x + 1, y) ::= Mul(x, y) + y			�ᱹ�� X�� �پ��� �������� ���� �ȴ�.
	//     x  y
	// (1) Z   A --> Mul(0,y)::=0						X�� �پ��ٰ� 0�̵Ǹ� 0�� �ǰ�,
	// (2) N  A --> Mul(x+1,y)::=Mul(x,y)+y            X�� ��� �ڿ����� X�� 1�� �پ��� �ȴ�.  
	
	// [1]:(Z,A)	Mul(Zero(), y) ::= Zero()        X�� ���θ� ����,
	// [2]:(N,A)	Mul(Succ(x), y) ::= Add(Mul(x,y),y) X�� �ڿ����� �ϳ��� �پ��鼭 ���ϱ⸦ �Ѵ�. 
	if (IsZero(x))
		return Zero();
	return Add(Mul(Pred(x), y), y);

	return Zero();
	/*** Method 1 End *****/

	/*** Method 2 Begin ***
	// Mul(x, y + 1) ::= Mul(x, y) + x			;; �Ϲ� ����
	//     x  y
	// (1) A  Z --> Mul(x,0)::=0						;; �ߴ� ����
	// (2) A  N --> Mul(x,Succ(y))::=Add(Mul(x,y),x)
	
	// [1]:(A,Z)	Mul(x,Zero())::=Zero()
	// [2]:(A,N)	Mul(x, Succ(y))) ::= Add(Mul(x,y),x)
	i*/
	if (IsZero(y))
		return Zero();
	return Add(Mul(x, Pred(y)), x);
	/*** Method 2 End *****/
}

NatNo Div(NatNo x, NatNo y)//8
{	// x / y
	// Div(x + y, y) ::= Div(x, y) + 1			;; �Ϲ� ����
	//     x  y
	// (1) A  Z --> Div(x,0) ::= Error						;; �ߴ� ����
	// (2) A  N --> Div(x,y)::= IF(x,y) THEN 0 : Div(x-y,y)+1
	// (3) Let w=Succ(y)
	// [1]:(A,Z)	Div(x, Zero()) ::= Error
	// [2]:(A,N)	Sub(x, w) ::=  IF(Greater(w,x) THEN Zero() ELSE Succ(Div(Sub(x,w),w))
	if (IsZero(y))
		return Error();
	return Greater(y, x) ? Zero() : Succ(Div(Sub(x, y), y));
}

NatNo Mod(NatNo x, NatNo y)//9
{	// x % y
	// Mod(x + y, y) ::= Mod(x, y)				;; �Ϲ� ����
	//     x  y
	// (1) A  Z --> Mod(x,0) ::= Error						;; �ߴ� ����
	// (2) A  N --> Mod(x,y) ::= IF (x<y) THEN x ELSE Mod(x-y,y)
	// Let w=Succ(y)
	// [1]:(A,Z)	Mod(x, Zero()) ::= Error
	// [2]:(A,N)	Mod(x, w) ::= IF (Greater(w,x)) THEB x ELSE Mod(Sub(x,w),w)
	if (IsZero(y))
		return Error();
	return Greater(y, x) ? x : Mod(Sub(x, y), y);

	return Zero();
}

/****

[����]
NatNo Add(NatNo x, NatNo y)
{
	// Add(x + 1, y) = Add(x, y) + 1
	//     x  y
	// (1) 0  y --> y		;; simple solution

	// Rule
	// Z�� Zero�̰�, N�� Nonzero�̰�, A�� All �� Zero/Nonzero���� �ǹ��Ѵ�.
	// [1]:(Z,A)	Add(Zero(), y) ::= y						;; 0 + y ::= y
	// [2]:(N,A)	Add(Succ(x), y) ::= Succ(Add(x, y))

	// Coding
	if (IsZero(x))						// y�� �ƹ��� ���������� ����
		return y;						// [1]
	// ���⼭���� x�� Zero�� �ƴ�
	return Succ(Add(Pred(x), y));		// [2]

}

���� ������ ���캸��
(1) �����ڿ� ���� ��Ģ�� �����
(2) ��� ��Ȳ�� ���Ͽ� ������ ��Ģ�� �׻� �����ϴ� ���� �����ϰ�
(3) ��� ��Ȳ������ �����ϰ� �ϳ��� �ִٴ� ���� �����ϰ�
(4) �� ��Ģ�� ���� �ڵ��� �Ǿ���.

���� ������ �߿��� ��� �ִ� ������ �Լ��� ���Ͽ�
���� (1), (2), (3), (4)�� ������ ���� �ڵ��϶�


NatNo Operator(NatNo x, NatNo y)
{
	// 
	// �� �������� ��� ��쿡���� ����ǰ�
	// ���� �ϳ��� ��Ģ�� ����ȴٴ� ���� ���δ�
	//
	
	.......
	.......		// ���� ��Ģ�� ���� ������ �ڵ��� �Ѵ�.
	.......
}

�� ������ �Ǿ� �ִ� ��� �����ڿ� ���Ͽ�
���� ���� ���� ������� ä�� �ִ´�.

****/

/*
	Structure NatNo
		Declare Zero()--> NatNo 
		IsZero(NatNo)-->Boolean
		Succ(NatNo)-->NatNo
		Add(NatNo,NatNo)-->NatNo)
		Equal(NatNo,NatNo)-->Boolean
		Greater(NatNo,NatNo)-->Boolean
		Sub(NatNo,NatNo)-->NatNo
		Mul(NatNo,NatNo)-->NatNo
		Div(NatNo,NatNo)-->NatNo
		Mod(NatNo,NatNo)-->NatNo

	For All x,y �� NatNo, w= Succ(x) Let
		IsZero(Zero()) ::=true
		IsZero(Succ(x)) ::=false

		Add(Zero(),y)::=y
		Add(Succ(x),y)::=Succ(Add(x,y))
		Equal(x,Zero())::=IsZero(x)
		Equal(Zero(),Succ(y))::=false
		Equal(Succ(x),Succ(y)::=Equal(x,y)
		Greater(Zero(),y)::=false
		Greater(Succ(x),Zero()) ::= true
		Greater(Succ(X),Succ(y))::=Greater(x,y)
		Sub(Zero(),y)::= IF IsZero(y) THEN Zero() ELSE Error
		Sub(Succ(x),Zero()) ::=x
		Sub(Succ(x),Succ(y)) ::=Sub(x,y)
		Mul(Zero(),y)::=Zero()
		Mul(Succ(x),y)::=Add(Mul(x,y),y)
		Div(x,Zero())::=Error
		Div(x,w)::=IF (Greater(w,x) THEN Zero() ELSE Succ(Div(Sub(x,w),w))
		Mod(x,Zero()) ::=Error
		Mod(x,w)::=IF(Greater(w,x)) THEN x ELSE Mod(Sub(x,w),w)
	End
End NatNo
*/