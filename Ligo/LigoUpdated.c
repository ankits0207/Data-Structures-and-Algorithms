#include <stdio.h>
#include <stdlib.h>

struct MyNode
{
    int start,end,counter;
};
typedef struct MyNode Node;

void insertArr(Node* myarr[100],int first,int last,int count,int loc);
int rangeCalculator(Node* myarr[100],int num);
int getMin(int a,int b);
int getMax(int a,int b);

Node* arr[100];
int main(void) {
	int T,N,i,j,first,last;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
	    scanf("%d",&N);
	    for(j=0;j<N;j++)
	    {
	        scanf("%d",&first);
            scanf("%d",&last);
            insertArr(arr,first,last,0,j);
	    }
	    if(i==T-1)
	    {
	        printf("%d",rangeCalculator(arr,N));
	    }
	    else
	    {
	        printf("%d\n",rangeCalculator(arr,N));
	    }
	}
	return 0;
}
void insertArr(Node* arr[100],int first,int last,int count,int loc)
{
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->start=first;
    ptr->end=last;
    ptr->counter=count;
    arr[loc]=ptr;
}
int rangeCalculator(Node* myarr[100],int num)
{
    int k,l,temp=0,getMinvar=0,getMaxvar=0;
    for(k=0;k<num;k++)
    {
        for(l=k+1;l<num;l++)
        {
            if((myarr[k]->start==myarr[l]->start)&&(myarr[k]->end==myarr[l]->end))
            {
                if(((myarr[k]->end)-(myarr[l]->start)+1)>(myarr[k]->counter))
                {
                        myarr[k]->counter=(myarr[k]->end)-(myarr[l]->start)+1;
                }
            }
            else if((myarr[k]->start!=myarr[l]->start)&&(myarr[k]->end==myarr[l]->end))
            {
                getMaxvar=getMax(myarr[k]->start,myarr[l]->start);
                if(((myarr[k]->end)-getMaxvar+1)>(myarr[k]->counter))
                    {
                        myarr[k]->counter=(myarr[k]->end)-getMaxvar+1;
                    }
            }
            else if((myarr[k]->start==myarr[l]->start)&&(myarr[k]->end!=myarr[l]->end))
            {
                getMinvar=getMin(myarr[k]->end,myarr[l]->end);
                if((getMinvar-(myarr[k]->start)+1)>(myarr[k]->counter))
                {
                    myarr[k]->counter=getMinvar-(myarr[k]->start)+1;
                }
            }
            else if((myarr[k]->start)<(myarr[l]->start)&&(myarr[l]->start)<(myarr[k]->end)&&(myarr[k]->end)<(myarr[l]->end))
            {
                if(((myarr[k]->end)-(myarr[l]->start)+1)>(myarr[k]->counter))
                {
                    myarr[k]->counter=((myarr[k]->end)-(myarr[l]->start)+1);
                }
            }
            else if((myarr[k]->start)>(myarr[l]->start)&&(myarr[k]->start)<(myarr[l]->end)&&(myarr[k]->end)>(myarr[l]->end))
            {
                if(((myarr[l]->end)-(myarr[k]->start)+1)>(myarr[k]->counter))
                {
                    myarr[k]->counter=((myarr[l]->end)-(myarr[k]->start)+1);
                }
            }
            else if((myarr[k]->start)<(myarr[l]->start)&&(myarr[k]->end)>(myarr[l]->end))
            {
                if(((myarr[l]->end)-(myarr[l]->start)+1)>(myarr[k]->counter))
                {
                    myarr[k]->counter=((myarr[l]->end)-(myarr[l]->start)+1);
                }
            }
            else if((myarr[k]->start)>(myarr[l]->start)&&(myarr[k]->end)<(myarr[l]->end))
            {
                if(((myarr[k]->end)-(myarr[k]->start)+1)>(myarr[k]->counter))
                {
                    myarr[k]->counter=((myarr[k]->end)-(myarr[k]->start)+1);
                }
            }
        }
    }
    for(k=0;k<num;k++)
    {
        if((myarr[k]->counter)>temp)
        {
            temp=myarr[k]->counter;
        }
    }
    if(temp!=0)
    return temp;
    else
    return 1;
}
int getMin(int a,int b)
{
    if(a>b)
    return b;
    else
    return a;
}
int getMax(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

