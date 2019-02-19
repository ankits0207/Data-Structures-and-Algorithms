#include <stdio.h>
#include <stdlib.h>

struct NODE
{
	struct NODE* left;
	struct NODE* right;
	int data;
};
typedef struct NODE Node;
struct myQueue
{
	int front,rear;
	struct Que* qarr[1000];
};
typedef struct myQueue Que;

Node* insertTree(Node* p,int val);
char checkBST(Node* cp,int num);
void inorderTraversal(Node* tp);
void Enqueue(Que* q,Node* n);
Node* Dequeue(Que* q);
int IsEmpty(Que* q);

Node* head=NULL;
int indx;
int myarr[10000];
int main(void)
{
	int T,N,value,i,j,extcounter,internalcounter,controlcounter;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&N);
		indx=0,extcounter=0,internalcounter=0,controlcounter=0;
		Que* q=(Que*)malloc(sizeof(Que));
        q->front=-1;
		q->rear=-1;
		for(j=0;j<N;j++)
		{
			Node* temp;
			scanf("%d",&value);
			if(extcounter==0)
			{
				Node* ptr=(Node*)malloc(sizeof(Node));
				ptr->data=value;
				ptr->left=NULL;
				ptr->right=NULL;
				head=ptr;
				extcounter++;
				Enqueue(q,ptr);
			}
			else
			{
				if(controlcounter%2==0)
				{
					temp=Dequeue(q);
				}
				controlcounter++;
				{
					temp=insertTree(temp,value);
					internalcounter++;
					if(internalcounter%2==1)
					{
						Enqueue(q,temp->left);
					}
					else
					{
						Enqueue(q,temp->right);
					}
				}
			}
		}
        //inorderTraversal(head);
		if(checkBST(head,N)=='y')
            if(i==T-1)
            {
                printf("YES");
            }
            else
            {
                printf("YES\n");
            }
			
		else
			if(i==T-1)
            {
                printf("NO");
            }
            else
            {
                printf("NO\n");
            }
	}
	return 0;
}
Node* insertTree(Node* p,int val)
{
	if(p==NULL)
	{
		Node* ptr=(Node*)malloc(sizeof(Node));
		ptr->data=val;
		ptr->left=NULL;
		ptr->right=NULL;
		p=ptr;
	}
	else if(p->left==NULL)
	{
		p->left=insertTree(p->left,val);
	}
	else if(p->right==NULL)
	{
		p->right=insertTree(p->right,val);
	}
	return p;
}
char checkBST(Node* cp,int num)
{
	int k,flag=0;
	inorderTraversal(cp);
	for(k=0;k<num-1;k++)
	{
		if(myarr[k]<=myarr[k+1])
		{

		}
		else
		{
			flag=1;
		}
	}
	if(flag==0)
		return 'y';
	else
		return 'n';
}
void inorderTraversal(Node* tp)
{
	if(tp!=NULL)
	{
		inorderTraversal(tp->left);
		//printf("%d\n",tp->data);
		myarr[indx]=tp->data;
		indx++;
		inorderTraversal(tp->right);
	}
}
void Enqueue(Que* q,Node* n)
{
    if(q->front==-1&&q->rear==-1)
    {
        q->front++;
        q->rear++;
        q->qarr[q->rear]=n;
    }
    else
    {
        q->rear++;
        q->qarr[q->rear]=n;
    }
}
Node* Dequeue(Que*q)
{
    Node* temp;
    if(q->front==q->rear)
    {
        temp=q->qarr[q->front];
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        temp=q->qarr[q->front];
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
