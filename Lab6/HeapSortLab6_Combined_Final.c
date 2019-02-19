#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Submitted by:
                    Ankit Rehani: MT16085
                    Ankit Sharma: MT16121
*/

struct Element
{
    char first_name[100];
    char last_name[100];
    int heap_index;
};
typedef struct Element Element;


void InitHeap (char* first_name, char* last_name);
int Insert (char *first_name, char* last_name);
Element* FindMin();
Element* DeleteMin();
Element* Delete(int index);
void heapify(Element* arr[],int i);
char compare(Element *first, Element *second);
void BuildminHeap(Element *arr[]);
void heapSort();

Element* heapArray[1000];
int nodeCounter=0;
int front=0;
int main(void) {
        Element *del1,*del2,*minElement;
    int T,i,position,index,j;
	char fname[100];
	char sname[100];
	char operation[20];
	scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%s",operation);
        if(!strcmp(operation,"InitHeap"))
        {
            scanf("%s",fname);
            scanf("%s",sname);
			InitHeap(fname,sname);
		}

		if(!strcmp(operation,"Insert")) {
			scanf("%s %s",fname,sname);
			position = Insert(fname,sname);
			if(i==T-1)
			printf("%d",position);
			else
			printf("%d\n",position);
		}

		if(!strcmp(operation,"DeleteMin")) {
            del1 = DeleteMin();
            if(del1 != NULL) {
                if(i==T-1)
    			printf("%s %s",del1->first_name,del1->last_name);
    			else
    		    printf("%s %s\n",del1->first_name,del1->last_name);
            }
            else {
                if(i==T-1)
    			printf("%d",-1);
    			else
    		    printf("%d\n",-1);
            }
		}

		if(!strcmp(operation,"FindMin")) {
            minElement = FindMin();
            if(minElement != NULL) {
                if(i==T-1)
    			printf("%s %s",minElement->first_name,minElement->last_name);
    			else
    		    printf("%s %s\n",minElement->first_name,minElement->last_name);
            }
            else {
                if(i==T-1)
    			printf("%d",-1);
    			else
    		    printf("%d\n",-1);
            }
		}

        if(!strcmp(operation,"Delete")) {
            scanf("%d",&index);
            del2 = Delete(index);
            if(del2 != NULL) {
                if(i==T-1)
    			printf("%s %s",del2->first_name,del2->last_name);
    			else
    		    printf("%s %s\n",del2->first_name,del2->last_name);
            }
            else {
                if(i==T-1)
    			printf("%d",-1);
    			else
    		    printf("%d\n",-1);
            }
        }

    }
	return 0;
}
void InitHeap (char* first_name, char* last_name)
{
	Element* ptr=(Element*)malloc(sizeof(Element));
	strcpy(ptr->first_name,first_name);
	strcpy(ptr->last_name,last_name);
	ptr->heap_index=1;
	heapArray[0]=ptr;
	nodeCounter++;
}
int Insert (char *first_name, char* last_name){
	int i;
    Element* ptr=(Element*)malloc(sizeof(Element));
    strcpy(ptr->first_name,first_name);
	strcpy(ptr->last_name,last_name);
	heapArray[nodeCounter]=ptr;
	nodeCounter++;
	//heapSort();
	BuildminHeap(heapArray);
	for(i = front;i<nodeCounter;i++) {
		if((strcmp(heapArray[i]->first_name,first_name) == 0) && (strcmp(heapArray[i]->last_name,last_name) == 0))
		{
			heapArray[i]->heap_index = i+1;
			return i+1;
		}
	}
}
void heapSort()
{
    //int i;
   // Element* temp;
   // int n=nodeCounter;
    BuildminHeap(heapArray);
   // for(i=n-1;i>1;i--)
    //{
      //  temp=heapArray[0];
       // heapArray[0]=heapArray[i];
        //heapArray[i]=temp;
        //n--;
        //heapify(heapArray,0);
    //}
}
void heapify(Element* arr[],int i)
{
    Element* temp;
    char tempchar1,tempchar2;
    int l=2*i+1;
    int r=2*i+2;
    int min=i;
    if(arr[l]!=NULL)
    {
        tempchar1=compare(arr[i],arr[l]);
    }
    if(arr[r]!=NULL)
    {
        tempchar2=compare(arr[min],arr[r]);
    }
    if(tempchar1=='f' && l<nodeCounter)
        min=l;
    if(tempchar2=='f' && r<nodeCounter)
        min=r;
    if(min!=i)
    {
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        heapify(arr,min);
    }
}
char compare(Element *first, Element *second) {
    int firstCmp, secondCmp;
    firstCmp = strcmp(first->first_name,second->first_name);
    if(firstCmp == 0) {
        secondCmp = strcmp(first->last_name,second->last_name);
        if(secondCmp == 1)
            return 'f';
        if(secondCmp == -1)
            return 's';
    }
    else {
        if(firstCmp == 1)
            return 'f';
        if(firstCmp == -1)
            return 's';
    }
}
void BuildminHeap(Element *arr[]) {
    int i;
    for(i = nodeCounter/2; i>=(front+1) ;i--) {
        heapify(arr,i-1);
    }
}

Element* DeleteMin() {
    Element *elementDeleted = heapArray[front];
    int i;
    if(elementDeleted != NULL) {
//        heapArray[front] = NULL;
        nodeCounter--;
//        front++;
        for(i = 0;i<nodeCounter;i++) {
            heapArray[i] = heapArray[i+1];
            heapArray[i]->heap_index--;
        }
        heapArray[i] = NULL;
    }
    BuildminHeap(heapArray);
    return elementDeleted;
}

Element* Delete(int index) {
    int origIndex = index - 1,i;
    Element *elementDeleted = heapArray[origIndex];
    if(elementDeleted != NULL) {
        for(i = origIndex ; i<nodeCounter-1 ; i++) {
            heapArray[i] = heapArray[i+1];
            heapArray[i]->heap_index--;
        }
        heapArray[i] = NULL;
        nodeCounter--;
    }
    heapify(heapArray,front);
    return elementDeleted;
}
Element* FindMin() {
    return heapArray[front];
}
