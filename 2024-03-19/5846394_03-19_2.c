#include <stdio.h>
#include <time.h>

double power_iter(double x, int n); //�Լ��� main���� �ؿ� �־� ���� �߻����ɼ� ������ ����
double power_rec(double x, int n);

int main(void) {
    clock_t start, stop;
    float duration;
    start = clock(); //�ð� ��������
    double result_iter = power_iter(13, 21); //�Լ� ȣ�� ������ ����
    double result_rec = power_rec(13, 21);
    stop = clock();  //�ð� ���� ����
    duration = (float)(stop - start) / CLOCKS_PER_SEC;  //���� �ð� ����
    printf("13^21 �� : %f(�ݺ�)\n", result_iter);
    printf("13^21 �� : %f(���)\n", result_rec);
    printf("����ð��� %f���Դϴ�.\n", duration);
    return 0;
}

double power_iter(double x, int n) {
    int i;
    double result = 1.0;
    for (i = 0; i < n; i++)
        result = result * x;
    return(result);
}

double power_rec(double x, int n) {
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power_rec(x * x, n / 2);
    else
        return x * power_rec(x * x, (n - 1) / 2);
}