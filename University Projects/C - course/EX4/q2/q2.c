#include<stdio.h>
#include<stdlib.h>
#define bool int
#include "function.h"

struct Node{
char data;
struct Node *next;
};

void push(struct Node** top_ref, char new_data);
int pop(struct Node** top_ref);


int main(){
char *sen[] = {"{()}[]", "{()}[]","(())"};
if (isStringBalanced(sen,3))
	printf("Balanced ");
else
	printf("Not Balanced "); 
return 0;
}

bool isMatchingPair(char character1, char character2){
if (character1 == '(' && character2 == ')')
	return 1;
else if (character1 == '{' && character2 == '}')
	return 1;
else if (character1 == '[' && character2 == ']')
	return 1;
else
	return 0;
}

bool isStringBalanced(char** sentence, int size){
int i = 0;
int j;
struct Node *stack = NULL;

for(j=0; j<size;j++){
	char *tmp=sentence[j];
while (*tmp!='\0'){
	
		if (*tmp == '{' || *tmp== '(' || *tmp == '[')
			push(&stack, *tmp);
		if (*tmp == '}' || *tmp == ')' || *tmp == ']'){
		if (stack == NULL)
		return 0; 
		else if (!isMatchingPair(pop(&stack), *tmp ))
		return 0;
		}
	tmp++;
}
}
	
if (stack == NULL)
	return 1; //balanced/
else
	return 0; //not balanced/
} 

void push(struct Node** top_ref, char new_data){

struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

if (new_node == NULL){
	printf("Stack overflow n");
	return;
}		 
new_node->data = new_data;
new_node->next = (*top_ref); 
(*top_ref) = new_node;
}

int pop(struct Node** top_ref){
char res;
struct Node *top;

if (*top_ref == NULL){
	printf("Stack overflow n");
	return 0;
}
else{
	top = *top_ref;
	res = top->data;
	*top_ref = top->next;
	free(top);
	return res;
}
}

