#include "main.h"

/**

1. Зіставте одновимірному масиву a[n] інший одновимірний
масив f[n], елементи якого обчислюються за формулою f[i] =
ln(a[i])/arctg(e*i/10). Елементи цього масиву переставте так, щоб
меншому номеру відповідав би менший елемент. Елементи усіх масивів
виведіть на екран в один рядок.

2. У двовимірному масиві знайдіть і виведіть на екран 5 найбільших
елементів із вказіванням їх індексів.
*/
char menu();
void swap (int *, int *);
void f_task(void);
void s_task(void);

int main()
{
    char ans;
    while((ans = toupper(menu())) != 'E')
    {
        if(ans == 'F')
        {
            f_task();
        }
        else if(ans == 'S')
        {
            s_task();
        }
    }
    return 0;
}

char menu()
{
    char choice;
    printf("_________________________________________________\n");
    printf("********|-----------MENU----------|**************\n");
    printf("*************************************************\n");
    printf("*************************************************\n");
    printf("*\t[F] Complete the first task\t\t*\n");
    printf("*\t[S] Complete the second task\t\t*\n");
    printf("*\t[E] Exit\t\t\t\t*\n");
    printf("*************************************************\n");
    printf("Your choice: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void f_task()
{
    unsigned int arr_size;
    do
    {
        printf("Enter array size (more than one): ");
        if(scanf("%d", &arr_size) != 1 && arr_size < 2)
        {
            printf("\nWrong value!!!\n");
            return -1;
        }
    } while (arr_size < 2);
    int *arr_a = (int*)(malloc(sizeof(int) * arr_size));
    int *arr_f = (int*)(malloc(sizeof(int) * arr_size));
    srand(time(NULL));
    printf("First array(a): ");
    for(int i = 0; i < arr_size; ++i)
    {
        arr_a[i] = rand()%20+1; //log(0) == NAN
        printf("%d ", arr_a[i]);
    }
    for (int i = 0; i < arr_size; ++i)
    {                                                   //the first element of this array will always be -214748364
        arr_f[i] = log(arr_a[i])/atan(exp(1.0)*i/10);   //because division by zero is impossible
    }
    for(int i = 0 ; i < arr_size - 1; ++i)
    {
        for(int j = 0 ; j < arr_size - i - 1 ; ++j)
        {
            if(arr_f[j] > arr_f[j+1])
            {
                swap(&arr_f[j], &arr_f[j+1]);
            }
        }
    }
    printf("\nSecond array(f): ");
    for (int i = 0; i < arr_size; ++i)
    {
        printf("%d ", arr_f[i]);
    }
    printf("\n\nArray comparison: ");
    for (int i = 0; i < arr_size; ++i)
    {
        if(arr_a[i] > arr_f[i])
        {
            printf("[%d] > [%d]\t", arr_a[i], arr_f[i]);
        }
        else if (arr_a[i] < arr_f[i])
        {
            printf("[%d] < [%d]\t", arr_a[i], arr_f[i]);
        }
        else
        {
            printf("[%d] = [%d]\t", arr_a[i], arr_f[i]);
        }
    }

    free(arr_a);
    free(arr_f);
    printf("\n");
}

void s_task()
{
    int row, col, counter = 0;
    printf("Enter number of rows: ");
    scanf_s("%d", &row);
    printf("Enter number of columns: ");
    int **matrix = (int**)malloc(row * sizeof(int));
    int *arr = (int*)malloc(row*col*sizeof(int));
    scanf_s("%d", &col);
    srand(time(NULL));
    for (int i = 0; i < row; ++i)
    {
        matrix[i] = (int*)malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            matrix[i][j] = rand() % 101-30;
        }
    }
    printf("\n");
    printf("Your matrix: \n");
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n\n");
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            arr[counter] = matrix[i][j];
            ++counter;
        }
    }
    for(int i = 0 ; i < row * col - 1; ++i)
    {
        for(int j = 0 ; j < row * col - i - 1 ; ++j)
        {
            if(arr[j] < arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    printf("Five maximum numbers(number[index]): ");
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            for (int k = 0; k < col; ++k)
            {
                if (matrix[j][k] == arr[i])
                {
                    printf("%d[%d][%d]\t", arr[i], j+1, k+1);
                }
            }
        }
    }

    for (int i = 0; i < row; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
    free(arr);
    printf("\n\n");
}
