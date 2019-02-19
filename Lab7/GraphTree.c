#include <stdio.h>
#include <stdlib.h>

struct llnode
{
	int vertex;
	struct llnode* next;
};
typedef struct llnode Node;
struct myQueue
{
	int front,rear;
	struct llnode* arr[1000];
};
typedef struct myQueue Que;

Node* createNode(int val);
Node* insertEnd(Node* p,Node* head);
void bfsArray(Node* arr[],Que* q,int size);
int isPresent(int intarr[],int size,int value);
int isPresentQueue(Que* q,Node* temp,int size);
void Enqueue(Que* q,Node* n);
Node* Dequeue(Que* q);
int IsEmpty(Que* q);
int bfsarr[1000];
int nodearr[1000];

int main(void)
{
	int T,i,j,N,M,x,y,nodearrcount,k,con1=1,con2=1,l;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{	con1=1;
	    scanf("%d",&N);
		scanf("%d",&M);
		if(M==N-1)
		{

		}
		else
        {
            con1=0;
        }
		Node* myarr[1000]={NULL};

		Node* temp1;
		Node* temp2;
		Que* q=(Que*)malloc(sizeof(Que));
        q->front=-1;
		q->rear=-1;
		nodearrcount=0;
		con2=1;
		if(con1==1)
        {
            for(j=0;j<M;j++)
            {
                scanf("%d",&x);
                scanf("%d",&y);
                if(!isPresent(nodearr,N,x))
                {
                    nodearr[nodearrcount]=x;
                    nodearrcount++;
                }
                if(!isPresent(nodearr,N,y))
                {
                    nodearr[nodearrcount]=y;
                    nodearrcount++;
                }
                temp1=createNode(x);
                temp2=createNode(y);
                myarr[x-1]=insertEnd(temp2,myarr[x-1]);
                myarr[y-1]=insertEnd(temp1,myarr[y-1]);
            }
            bfsArray(myarr,q,N);
            /*for(l=0;l<N;l++)
            {
                printf("%d\n",bfsarr[l]);
            }
            for(l=0;l<N;l++)
            {
                printf("%d\n",nodearr[l]);
            }*/
            for(k=0;k<N;k++)
            {
                if(isPresent(bfsarr,N,nodearr[k]))
                {

                }
                else
                {
                    con2=0;
                }
            }
        }
		if(con1==1&&con2==1)
		{
		    if(i==T-1)
                printf("YES");
            else
                printf("YES\n");
		}
		else
        {
            if(i==T-1)
                printf("NO");
            else
                printf("NO\n");
        }
	}

	return 0;
}
Node* createNode(int val)
{
	Node* ptr=(Node*)malloc(sizeof(Node));
	ptr->vertex=val;
	ptr->next=NULL;
	return ptr;
}
Node* insertEnd(Node* p,Node* head)
{
	Node* temp;
	temp=head;
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
	return head;
}
void bfsArray(Node* arr[],Que* q,int size)
{
	int count1=0,count2=0,val;
	Node* temp;
	while(arr[count1]==NULL)
	{
		count1++;
	}
	Enqueue(q,arr[count1]);
	while(!IsEmpty(q))
	{
		val=Dequeue(q)->vertex;
		bfsarr[count2]=val;
		count2++;
		temp=arr[val-1];
		while(temp!=NULL)
		{
			if(!isPresentQueue(q,temp,size))
			{
				if(!isPresent(bfsarr,size,temp->vertex))
				{
					Enqueue(q,temp);
				}
			}
			temp=temp->next;
		}
	}
}
int isPresent(int intarr[],int size,int value)
{
	int i,flag=0;
	for(i=0;i<size;i++)
	{
		if(intarr[i]==value)
		{
			flag=1;
		}
		else
		{

		}
	}
	return flag;

}
int isPresentQueue(Que* q,Node* temp,int size)
{
	int num,flag=0;
	for(num=0;num<size;num++)
	{
		if(q->arr[num]==temp)
		{
			flag=1;
		}
		else
		{

		}
	}
	return flag;
}
void Enqueue(Que* q,Node* n)
{
    if(q->front==-1&&q->rear==-1)
    {
        q->front++;
        q->rear++;
        q->arr[q->rear]=n;
    }
    else
    {
        q->rear++;
        q->arr[q->rear]=n;
    }
}
Node* Dequeue(Que*q)
{
    Node* temp;
    if(q->front==q->rear)
    {
        temp=q->arr[q->front];
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        temp=q->arr[q->front];
        q->front++;
    }
    return temp;
}
int IsEmpty(Que* q)
{
    if(q->front==-1&&q->rear==-1)
        return 1;
    else
        return 0;
}
