#include "main.h"

int main(int argc, char *argv[]){
    double a, b, x, res;
    printf("a = ");
    scanf("%lf", &a);
    printf("b = ");
    scanf("%lf", &b);
    printf("x = ");
    scanf("%lf", &x);
    res = b * pow(x, 3) * log(x) + a;
    printf("F(x) = %.2f\n\n", res);
    return 0;
}
