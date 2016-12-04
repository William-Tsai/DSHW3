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
}
listPointer addlistNode(listNode *p,int n){
}
listPointer reverselist(listNode *p){
}
listPointer combinelist(listNode *p1,listNode *p2){
}
