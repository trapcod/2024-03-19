#include <stdio.h>
#include <time.h>


long factorial_iter(int n); //�Լ��� main���� �ؿ� �־� ���� �߻����ɼ� ������ ����
long factorial_rec(int n);

int main(void) {
	clock_t start, stop; 
	float duration;
	start = clock(); //�ð� ��������
	double result_iter = factorial_iter(20); //�Լ� ȣ�� ������ ����
	double result_rec = factorial_rec(20);
	stop = clock(); //�ð� ���� ����
	duration = (float)(stop - start) / CLOCKS_PER_SEC; //���� �ð� ����
	printf("20! �� : %f(�ݺ�)\n",result_iter);
	printf("20! �� : %f(���)\n", result_rec);
	printf("����ð��� %f���Դϴ�.\n", duration);
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