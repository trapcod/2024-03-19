#include <stdio.h>
#include <time.h>

double power_iter(double x, int n); //함수가 main보다 밑에 있어 오류 발생가능성 때문에 적음
double power_rec(double x, int n);

int main(void) {
    clock_t start, stop;
    float duration;
    start = clock(); //시간 측정시작
    double result_iter = power_iter(13, 21); //함수 호출 변수에 저장
    double result_rec = power_rec(13, 21);
    stop = clock();  //시간 측정 종료
    duration = (float)(stop - start) / CLOCKS_PER_SEC;  //측정 시간 저장
    printf("13^21 값 : %f(반복)\n", result_iter);
    printf("13^21 값 : %f(재귀)\n", result_rec);
    printf("수행시간은 %f초입니다.\n", duration);
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