#include <stdio.h>
#include <stdlib.h>

/* inline과 일반 함수 차이
	일반 함수는 프로그램이 진행하다가 함수를 찾아가서 실행하고 리턴되서 오는데
	inline 함수는 함수호출지점에 함수 내부내용을 가져와서 그냥 사용한다.
*/
inline int randfunc(int n)
{
	return rand() % n;
}

int main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("난수 \ %d,%d,%d\n", i, j, k);
}