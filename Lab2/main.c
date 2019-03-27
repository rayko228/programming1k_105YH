#include "main.h"

char menu() {
    char choice;
    printf("***************************\n");
    printf("What do you want to do?\n");
    printf("***************************\n");
    printf("[C] Complete the first task\n");
    printf("[F] Complete the second task\n");
    printf("[Q] Quit\n");
    printf("***************************\n");
    printf("Your choice: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}

double count_y(double x){
    if (x <= -1){
        return pow(2, 1-x);
    } else if (x >-1 && x <= 4){
        return 2*x*x - fabs(1-x);
    } else if(x > 4){
        return x-1;
    }
}

double count_f(double x, double y){
    return log(x+y);
}


int main(int argc, char *argv[])
{
    char ans;
    while((ans = toupper(menu())) != 'Q') {
    if (ans == 'C') {

        double x, leftX = 0, rightX = 1;
        const int N = 5;
        printf("Enter x (0<x<1): ");
        if (scanf("%lf", &x) != 1) {
            printf("Invalid input\n");
            return -1;
        }
        if(x < leftX || x > rightX){
            char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
            printf(fmt, x, leftX, rightX);
            return -1;
        }
        double a = sin(x), S = a;
        for(int n = 1; n <= N; ++n){
            double q = -(x*x)/(2*pow(2*n+1, 2)); //errors in the condition
            a *= q;
            S += a;
        }
        double y = exp(sin(x)) * sin(cos(x));
        printf("S=%.7f\n", S);
        printf("y=%.7f\n\n", y);

    } else if (ans == 'F'){

        double a = -10, b = 10, h = 0.1;

        printf("*************** Part 1 ***************\n");

        printf("x:\t");
        for (double x = a; x <= b; x += h) {
            char c = x + h < b ? '\t' : '\n';
            printf("%.3f%c", x, c);
        }

        printf("y:\t");
        for (double x = a; x <= b; x += h) {
            char c = x + h < b ? '\t' : '\n';
            printf("%.3f%c", count_y(x), c);
        }

        printf("**************************************\n");

        printf("*************** Part 2 ***************\n");

        double a1 = 1, b1 = 2, h1 = 0.1;
        double c1=0, d1 = 4, h2 = 0.1;
        printf("y\\x\t");
        for (double x = a1; x <= b1; x += h1) {
            char c = x + h1 < b1 ? '\t' : '\n';
            printf("%.3f%c", x, c);
        }

        for (double y = c1; y <= d1; y += h2) {
            printf("%.3f\t", y);
            for (double x = a1; x <= b1; x += h1) {
                char c = x + h1 < b1 ? '\t' : '\n';
                printf("%.3f%c", count_f(x, y), c);
            }
        }

        printf("**************************************\n");
    }
    }
    return 0;
}
