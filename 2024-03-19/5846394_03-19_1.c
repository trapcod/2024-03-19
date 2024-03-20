#include <stdio.h>
#include <time.h>


long factorial_iter(int n); //함수가 main보다 밑에 있어 오류 발생가능성 때문에 적음
long factorial_rec(int n);

int main(void) {
	clock_t start, stop; 
	float duration;
	start = clock(); //시간 측정시작
	double result_iter = factorial_iter(20); //함수 호출 변수에 담음
	double result_rec = factorial_rec(20);
	stop = clock(); //시간 측정 종료
	duration = (float)(stop - start) / CLOCKS_PER_SEC; //측정 시간 저장
	printf("20! 값 : %f(반복)\n",result_iter);
	printf("20! 값 : %f(재귀)\n", result_rec);
	printf("수행시간은 %f초입니다.\n", duration);
	return 0;
}

long factorial_iter(int n) {
	long sum = 1;
	
	for (int i = 2; i <= n; i++) {
		sum *= i;
	}
	return sum;
}

long factorial_rec(int n) {
	if (n <= 1)
		return (1);
	else return (n * factorial_rec(n - 1));
}