#include <stdio.h>
#include <stdlib.h>

struct MyNode
{
    int start,end,counter;
};
typedef struct MyNode Node; 

void insertArr(Node* myarr[100],int first,int last,int count,int loc);
int rangeCalculator(Node* myarr[100],int num);

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
    int k,l,temp=0,flag=0;
    for(k=0;k<num;k++)
    {
        for(l=k+1;l<num;l++)
        {
            if((myarr[k]->end)-(myarr[l]->start)>0)
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
                    if(myarr[k]->start>myarr[l]->start)
                    {
                        if(((myarr[k]->end)-(myarr[k]->start)+1)>(myarr[k]->counter))
                        {
                             myarr[k]->counter=(myarr[k]->end)-(myarr[k]->start)+1;
                        }  
                    }
                    else
                    {
                        if(((myarr[k]->end)-(myarr[l]->start)+1)>(myarr[k]->counter))
                        {
                             myarr[k]->counter=(myarr[k]->end)-(myarr[l]->start)+1;
                        }   
                    }
                }
                else if((myarr[k]->start==myarr[l]->start)&&(myarr[k]->end!=myarr[l]->end))
                {
                    if(myarr[k]->end>myarr[l]->end)
                    {
                        if(((myarr[k]->end)-(myarr[k]->end)+1)>(myarr[k]->counter))
                        {
                             myarr[k]->counter=(myarr[k]->end)-(myarr[k]->end)+1;
                        }  
                    }
                    else
                    {
                        if(((myarr[l]->end)-(myarr[l]->start)+1)>(myarr[k]->counter))
                        {
                             myarr[k]->counter=(myarr[l]->end)-(myarr[l]->start)+1;
                        }   
                    }
                }
                else
                {
                    
                }
                
                
            }
            else
            {}
        }
    }
    for(k=0;k<num;k++)
    {
        if((myarr[k]->counter)>temp)
        {
            temp=myarr[k]->counter;
        }
    }
    return temp;
}

