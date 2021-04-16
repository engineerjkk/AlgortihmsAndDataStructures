#include <iostream>
using namespace std;
typedef char itemType;
//Last-in-first-out 구조로 역순으로 조회합니다.
//푸시다운 스택 클래스를 그대로 사용하도록 하겠습니다.
class Stack
{
private:
    itemType* stack;
    int p;
public:
    Stack(int max = 100)
    {
        stack = new itemType[max]; p = 0;
    };
    ~Stack()
    {
        delete stack;
    };
    inline void push(itemType v)
    {
        stack[p++] = v;
    }
    inline itemType pop()
    {
        return stack[--p];
    }
    inline int empty()
    {
        return !p;
    }
};// 클래스 종료
/*
1.숫자는 출력한다.
2.연산자는 스택에 push한다.
3.)는 pop한다.
4.'(' 와 ' '는 무시한다.
*/
int main(void) {
    char c; //문자열을 받습니다.
    int i;
    int x;
    Stack acc(500);//연산에 사용할 Stack
    Stack save(500);//후위변환에 사용할 Stack
    char str[500];//후위변환한 문자열을 str에 받습니다.
    cout << "수식을 입력하세요." << endl;
    //5 * ( ( ( 17 - 6 ) / ( 5 - 3 ) ) + 7 )
    //5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) 
    i = 0;
    while (cin.get(c)) {//str=5         9  8 +     4  6 * * 7 +*0
        if (c == ')')str[i++] = save.pop();//)를 만나면 pop 해 str에 저장합니다.
        if (c == '+')save.push(c);
        if (c == '*')save.push(c);
        if (c == '/')save.push(c);
        if (c == '-')save.push(c);
        while (c >= '0' && c <= '9') {
            str[i++] = c; cin.get(c);//숫자를 만나면 str에 집어넣고 연속된 숫자일경우 또한번 다시 넣습니다.
        }
        if (c != ')') str[i++] = ' ';// ) 아닌이상 모두 스페이스바도 함께 넣어줍니다.
        if (c == '\n')break;
    }
    while (!save.empty())
        str[i++] = save.pop();//스택이 모두 빌 때 까지 팝해서 str에다 담습니다.
    str[i] = NULL;//str 마지막값은 0 값을 줍니다.

    cout << "2. 후위 표기 결과\n" << str << endl;
    i = 0;
    while (str[i] != NULL) {//0을 만날 때 까지 while 루프를 돕니다 = 즉 문자열만 
        c = str[i++]; //각각의 문자열 하나를 c에 담습니다.
        x = 0;
        while (c == ' ') { c = str[i++]; }//c가 스페이스바를 만나면 한칸 건너 뛰고 다음문자열로갑니다.
        if (c == '+') { x = acc.pop() + acc.pop();  } //+를 만나면 두개를 pop 해 더해줘 x에 저장합니다. 
        if (c == '-') { x = -acc.pop() + acc.pop();  } // ex) 6 4 - 일경우 -4+6이기 때문입니다. 먼저나온 스택을 음수 취해주어야합니다.
        if (c == '*') { x = acc.pop() * acc.pop();  }
        if (c == '/') { x = 1 / ((float)acc.pop() / (float)acc.pop());  } //10 / 2  == 10 2 /  == 1/(2/10) ==5
        while (c >= '0' && c <= '9')//아토이 함수입니다. ASKII to Integer로 문자열을 정수형으로 바꾸어 줍니다. 그대로 사용했습니다. 
        {
            x = 10 * x + (c - '0'); c = str[i++];
        }
        acc.push(x);//연산을 한번 할때마다 x값을 푸시합니다.
       
    }
    printf("3. 결과값\n%d\n", acc.pop());
    return 0;
}

//x는 인트 값이므로 최종 결과값은 다를 수 있습니다. 

