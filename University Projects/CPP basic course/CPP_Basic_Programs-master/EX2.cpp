

#include <iostream>
#include <math.h>       /* pow */
void ass1() {
    printf("Enter a number");
    int n = 3;
    double sum = 0;
    for (int a = 1; a <= n; a = a + 1) {
        sum = sum + 1 / (pow(a, 2));
    }
    printf("%f", sum);
    menu();
}
void ass2() {
    for (int i = 1; i <= 1000; i++)
    {
        if (i < 10) {
            if (i % i == 0) {
                printf("%d\n", i);
            }
        }
        if (i > 10 && i < 100) {
            if (i % (i / 10 + i % 10) == 0) {
                printf("%d\n", i);

            }
        }
        if (i > 10 && i > 100 && i < 1001) {
            if (i % (i / 100 + ((i / 10) % 10) + i % 10) == 0) {
                printf("%d\n", i);

            }
        }
    }
    {

    }
    menu();
}
void ass3() {
    printf("Enter 1 for an arithmetic series, 2 for a geometric series");
    int menufun = 2;
    std::cin >> menufun;
    int first = 25;
    printf("Enter first element: ");
   std::cin >> first;
    int sum;
    if (menufun == 1) {
        printf("Enter difference: ");
        int dif = 2;
        std::cin >> dif;
        for (int a = 1; a <= 10; a = a + 1) {
            sum = (a / 2) * (2 * first + dif);
            printf("%d ", first + (a - 1) * dif);
        }
    }
    else if (menufun == 2) {
        printf("Enter factor: ");
        int dif = 2;
        std::cin >> dif;
        printf("%d ", first);
        for (int a = 1; a <= 9; a = a + 1) {
            first = first * dif;
            printf("%d ", first);
        }
    }
    else {
        printf("wrong menu value\n");
            ass3();
    }
    menu();
}
int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
void ass4() {
    int x=3;
    int n=5;
    double sum= 1+x;
    printf("Enter x: \n");
    std::cin >> x;
    printf("Enter n: \n");
    std::cin >> n;
    printf("e^");
    printf("%d",x);
    printf("= 1 + ");
    printf("%d", x);
    printf(" + ");
    for (int i = 2; i < n; i = i + 1) {
        sum = sum + pow(x, i) / factorial(i);
        printf("% f", pow(x, i));
        printf("/");
        printf("%d", factorial(i));
        if (i != n-1) {
        printf(" +");
    }
        else
        {
            printf(" = ");
            printf("%f", sum);

        }

    }
    menu();
}


    void menu() {
        printf("ex2, please enter a number to run a certain assigment");
        printf("\n");
        printf("enter 0 to exit the program");
        printf("\n");
        printf("enter 1 to 	for sum of 1/n^2 ");
        printf("\n");
        printf("enter 2 to print numbers that are divided by sum of digits");
        printf("\n");
        printf("enter 3 to print arithmetic or geometric progression");
        printf("\n");
        printf("enter 4 to Tylor series");
        printf("\n");
        int menu;
        std::cin >> menu;
        if (menu == 0) {
            exit(0);
        }
        else if (menu == 1) {
            ass1();
        }
        else if (menu == 2)
        {
            ass2();
        }
        else if (menu == 3)
        {
            ass3();
        }
        else if (menu == 4)
        {
            ass4();
        }
    }
    int main()
    {

        menu();
    }
