#include<stdio.h>
#include <stdlib.h>
#include "function.h"
#include "function_q1.c"


  
int main(){
   int k;
     A=(int*)malloc(i*sizeof(int));
     int temp=take(20);
     temp= take(10);
     temp= take(30);
     temp= take(5);
     temp= take(40);
    
     printf("Middle number : %d ",temp);
     free(A);
     
     A=(int*)malloc(i*sizeof(int));
     int temp2=take2(20);
     temp= take2(10);
     temp= take2(30);
     temp= take2(5);
     temp= take2(40);
    
     printf("\nMedian number: %d ",temp2);
     free(A);
  
    return 0;
   
}

