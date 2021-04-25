# DataStructure and Algorithm

해당 코드에 수정하지 못한 부분이 있습니다.    

height = calloc(number, sizeof(int)); 부분에서 **calloc** 앞에 **(int*)**를 선언해 주어야 에러가 나지 않습니다. 정수형 포인터에 대입해야 하므로 **(int*)**로 캐스팅을 해주어야 합니다. 
->
height = **(int*)** calloc(number, sizeof(int));  

부가 설명을 하자면 **malloc**이 "**몇 바이트 할당해 주세요**" 라고 요청하는 것에 비해 **calloc**은 "**몇 바이트짜리 몇개 할당해 주세요**"라고 요청하는 것이다. 따라서 아래는 같은 표현입니다.  

ar=(int *)malloc(10*sizeof(int));  
ar=(int *)calloc(10,sizeof(int));
