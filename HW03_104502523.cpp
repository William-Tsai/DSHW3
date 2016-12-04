#include <iostream>  //C++ IO
#include <cstdio>    //C   IO
#include <stdlib.h>

using namespace std;

typedef struct listNode *listPointer;
typedef struct listNode{
    int value;
    listPointer next;
};
void printall(listNode *p);                                      // print all content in linklist
listPointer addlistNode(listNode *p,int n);                // add one node and sorting in the same time
listPointer reverselist(listNode *p);                         // reverse list
listPointer combinelist(listNode *p1,listNode *p2);   // combine two list

int main() {
    int a[10]={0,9,8,8,6,3,2,1,5,4};
    listPointer start1=NULL;
    for(int i=0;i<10;i++){
        start1=addlistNode(start1,a[i]);
    }
    printall(start1);
    start1=reverselist(start1);
    printall(start1);
    start1=reverselist(start1);
    printall(start1);
    int b[10]={3,7,0,4,6,9,1,2,5,7};
    listPointer start2=NULL;
    for(int i=0;i<10;i++){
        start2=addlistNode(start2,b[i]);
    }
    printall(start2);
    listPointer result=NULL;
    result=combinelist(start1,start2);
    printall(result);
    return 0;
}

void printall(listNode *p){
    for(listPointer i = p; i != NULL; i = i->next) printf("%d ", i->value);
    printf("\n");
}
listPointer addlistNode(listNode *p,int n){
    listPointer i = p, temp = new listNode;
    temp->value = n; temp->next = NULL;
    if(!i) return temp;
    while(i->next && i->next->value < n) i = i->next;
    if(i == p){
	if(n < i->value){
	    temp->next = p;
	    return temp;
	}
    }
    temp->next = i->next;
    i->next = temp;
    return p;
}
listPointer reverselist(listNode *p){
    if(!p->next) return p;
    listPointer end = p, temp = reverselist(p->next), i = temp;
    while(i->next)  i = i->next;
    i->next = end;
    end->next = NULL;
    return temp;
}
listPointer combinelist(listNode *p1,listNode *p2){
    listPointer i = NULL, *temp = &i;
    while(p1 || p2){
	if(!p2 || (p1 && p1->value < p2->value)){
	    *temp = p1;
	    p1 = p1->next;
	}else if(p2){
	    *temp = p2;
	    p2 = p2->next;
	}
	(*temp)->next = NULL;
	temp = &((*temp)->next);
    }
    return i;
}
