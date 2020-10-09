#include <stdio.h>
#include <stdlib.h>

typedef struct myClass{ //סעיף א
    int m_x;
    int (*add)(struct myClass*,int);
} class;

typedef struct Derived{ //סעיף ב1
  class c_1;
} der1;

typedef struct Derived2{ //סעיף ב2
    int m_y;
    int (*add2)(struct Derived2*,int);
    class c_2;
} der2;

int xor(class *a, int y){
    a->m_x ^=y;
    return a->m_x;
}

//
int add2(der2 *a, int y){
    // a->c2.m_x +=y;
    a->m_y = y;
    a->c_2.add(&a->c_2,y);
    return a->c_2.m_x;
}

int add(class *a, int y){
    a->m_x+=y;
    return a->m_x;
}

void init(class *a){
    a->add=add;
    a->m_x=5;
}

void init2(der1 *a){
    init(&a->c_1);
    a->c_1.add=xor;
}

void init3(der2 *a){
    init(&a->c_2);
    a->add2=add2;
}


int main(){
    class a;
    init(&a);
    a.m_x = 2; 
    printf("m_x 1= %d\n", a.m_x);
    a.add(&a, 8);
    printf("m_x after add function= %d\n",a.m_x);
    
    der1 d1;
    init2(&d1);
    d1.c_1.m_x = 4;
    printf("m_x 2= %d\n",d1.c_1.m_x);
    d1.c_1.add(&d1.c_1,14);
    printf("m_x after xor function= %d\n", d1.c_1.m_x);
    
    der2 d2;
    init3(&d2);
    d2.c_2.m_x = 50;
    printf("m_x 3= %d\n", d2.c_2.m_x);
    d2.add2(&d2,20);
    printf("m_x after add2= %d\nm_y = %d", d2.c_2.m_x, d2.m_y);
    
    return 0;
}