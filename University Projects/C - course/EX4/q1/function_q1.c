#include<stdio.h>
#include <stdlib.h>
#include "function.h"

 int *A,count=0,i=1;


int take(int num){
    int j,ans;
    
    A[count]=num;
    count++;
    
   
    i=i+1;
     A=(int*)realloc(A,i*sizeof(int));
     
    
    
    ans=A[count/2];
    
    return ans;
      
}
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}

int take2(int num){
    int j,ans,k;
    
    A[count]=num;
    count++;
  
    i=i+1;
    A=(int*)realloc(A,i*sizeof(int));
     
    
    qsort(A,count,sizeof(int),comp);
    
 
    ans=A[count/2];
    
    return ans;
      
}