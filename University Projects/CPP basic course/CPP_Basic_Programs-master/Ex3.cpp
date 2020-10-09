// homework.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <math.h>       /* pow */

void menu();
bool Isprime(int x) {
    double y;
    y = sqrt(x);
    for (int i = 2; i < y; i++) {
        if (x % i == 0) {
            return true;
        }
    }
    return false;
}
void ass1() {
    printf("\n");

    printf("ASS1");

    printf("\n");
    int x = 25;
    int y = x;
    int z = x;
    bool UP = true;
    bool DOWN = true;
    printf("Enter a number");
    std::cin >> x;
    if (x < 0) {
        printf("Enter a positive number");
        std::cin >> x;
    }
//picking a divisable number from 1 to sqrt(x)
    while (UP && DOWN) {
        y++;
        z--;
        UP = Isprime(y);
        DOWN = Isprime(z);
     
    }

    if (y - x < x - z) {
        printf("\n");
        printf("%d", y);
    }

    else {
        printf("\n");
        printf("%d", z);
    }
    

    printf("\n");
    printf("\n");
    printf("%d", z);


   // menu();
}

bool DivSum(int x) { //Sum up all the divisible numbers 
    printf("\n");
    int sum=0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) {
            printf("\n");
            printf("%d", i);
            sum = i + sum;
        }
    }
    printf("\n");
    printf("%d", sum);
    printf("\n");
    if (x == sum) {
        return true;
    }
    else {
        return false;

    }
    printf("\n");
}
void ass2() {
    printf("\n");
    printf("Enter a number");
    printf("\n");
    int x;
    std::cin >> x;
    printf(DivSum(x) ? "true" : "false");
    printf("\n");
    menu();
}

int contains(int big[], int bigsize, int small[], int smallsize) {
    printf("\n");
    int temp = 0;
    int index = 0;
    int compare = small[temp];
    for (int i = 0; i < bigsize; i++) {
        if (big[i] == small[0]) {
            printf("\n");

            index = i;
        }
        if (big[i]==small[temp]) {
            printf("\n");

            temp++;
        }
        
    }
    printf("\n");

    if (temp == smallsize) {
        return (index);
    }
    else {
        return (-1);

    }
}
void ass3() {
int arrbig[] = {1,2,3,4,6,9,5};
int arrsmall[] = {4,2,6,9 };
printf("%d", contains(arrbig, 7, arrsmall, 3));
printf("\n");

    menu();
}



int sub_seq_of_zeros(int arr[], int size) {
    int counter=0;
    int longest=0;
    for (int i = 0; i < size; i++) {
        if (arr[i]==1)
        {
            counter = 0;
        }
        else if (arr[i]==0) {
            counter++;
            if (counter > longest) {
                longest = counter;
            }
        }

    }
    return longest;

}
void ass4() {
    printf("\n");
    int arr1[] = { 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d", sub_seq_of_zeros(arr1, size));
    //zeroLen(arr1,size);
    printf("\n");
    menu();
}

double arraymean(double arr[], int size) {
    double sum=0;
    for (int i = 0; i < size; i++) {
        sum = (sum + arr[i]);
    }
    return sum / size;
}

double arrayStdev(double arr[], int size)
{
    double mean = arraymean(arr, size);
    double sum = 0;
    double mean = arraymean(arr, size);
    for (int i = 1; i <= size; i++) {
        sum = sum + arr[i] - mean;
        pow(sum, 2);
    }
    sum = sum * 1 / size;
    sqrt(sum);
    return sum;
}


void ass5() {
    printf("\n");
    int arr1[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    printf("%f", sub_seq_of_zeros(arr1, size));
    printf("\n");
    menu();
}

void menu() {

    printf("ex3, please enter a number to run a certain assigment");
    printf("\n");
    printf("enter 0 to exit the program");
    printf("\n");
    printf("enter 1 to display nearest prime ");
    printf("\n");
    printf("enter 2 to check perfect number");
    printf("\n");
    printf("enter 3 to contain another array");
    printf("\n");
    printf("enter 4 for longest subseqence of zero");
    printf("\n");
    printf("enter 5 for Standard deviation");
    int menu;
    std::cin >> menu;
    if (menu == 0) {
        exit(0);
    }
    else if (menu == 1) {
        ass1();
    }
    else if (menu== 2)
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
    else if (menu == 5)
    {
        ass5();
    }
    else
    {
        printf("Number range is 1-5");
        main();
    }
}
int main()
{

    menu();
}
