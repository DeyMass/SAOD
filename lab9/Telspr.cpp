#include <conio.h>
#include <ctime>

struct spis{
    int data;
    spis *next;
    }*head,*p;

#include <D:/projects/lab9/func.h>
int main(){
    srand(time(NULL));
    spis* tail;
    tail=new spis;
    head=new spis;
    p=new spis;
    
    head=tail;
    head->next=p;
    tail=p;
    
    p=new spis;
    tail->next=p;
    tail=p;
    
    p=new spis;
    tail->next=p;
    tail=p;
    
    tail->next=NULL;
    
    fillrandS(head);
    printS(head);
    filldecS(head);
    printS(head);
    runnumberS(head);
    free(head);
    
    printS(head);
        getch();
    }
    
