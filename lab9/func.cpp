void free (spis* a){
    spis* z;
    for (p=a;p->next!=NULL;){
        z=p;
        p=p->next;
        delete (z);
	}
    }

void fillincS(spis* a){
    int z=0;
    for (p=a;p->next!=NULL;p=p->next)
        p->data=z++;
    }

void fillrandS(spis* a){
    for (p=a;p->next!=NULL;p=p->next)
        p->data=rand()%100;
    }

void runnumberS(spis* a){
    int nser=1;
    for (p=a;p->next->next!=NULL;p=p->next)
    if (a->data>a->next->data) nser++;
    printf("%i",nser);
    }

void contsumS(spis* a){
    int sum=0;
    for (p=a;p->next!=NULL;p=p->next){
        sum+=p->data;
        }
    printf("\n%i",sum);
    }
    
void filldecS(spis* a){
    int z=100;
    for (p=a;p->next!=NULL;p=p->next)
        p->data=z--;
    }

void printS(spis* a){
    for (p=a;p->next!=NULL;p=p->next)
        printf("%i ",p->data);
    }
