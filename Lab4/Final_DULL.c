#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Submitted by
Ankit Sharma MT16121
Ankit Rehani MT16085
*/

struct llistnode
{
    int data;
    struct llistnode * next;
};
typedef struct llistnode Node;

Node* deleteDuplicate(Node* head);
Node* Insert(Node* head, int val);

static Node* head=NULL;
int main(void) {

    int T,i,val,j,capval,count=1,delflag,oper,chkflg=0;
    char arr[20];
    char operarr[15];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        head=NULL;
        scanf("%d",&val);
        while(val!=0)
        {
            Insert(head,val);
            scanf("%d",&val);
        }
        scanf("%d",&oper);
        for(j=0;j<oper;j++)
        {
            scanf("%s",arr);
            sscanf(arr, "%s", operarr);

            if(!strcmp(operarr,"Insert"))
                {
                    Node* myp1;
                    scanf("%d",&capval);
                    myp1=Insert(head,capval);
					if(i==(T-1)&&j==(oper-1))
						printf("%d",myp1->data);
					else
						printf("%d\n",myp1->data);
                }
             else if(!strcmp(operarr,"Delete"))
                {
                    delflag=0;
                    Node* myp2;
                    myp2=deleteDuplicate(head);
                    if(myp2==NULL)
                        {
                            delflag=1;
							if(i==(T-1)&&j==(oper-1))
								printf("%d",-1);
							else
								printf("%d\n",-1);
                        }
                    while(myp2!=NULL)
                        {
                            printf("%d",myp2->data);
                            free(myp2);
                            myp2=deleteDuplicate(head);
							if(myp2!=NULL)
							{
								printf(" ");
							}
                        }
                    if(myp2==NULL&&delflag!=1)
                        {
							if(i==(T-1)&&j==(oper-1))
							{}
							else
								printf("\n");

                        }

                }
             else if(!strcmp(operarr,"Print"))
                {
                    scanf("%d",&capval);
					count=0;
					chkflg=0;
					Node* myp3;
					myp3=head;
					while(count!=capval)
					{
						count++;
						myp3=myp3->next;
						if(myp3==NULL)
						{
							chkflg=1;
							break;
						}
					}
					if(chkflg==1)
					{
						if(i==(T-1)&&j==(oper-1))
							printf("%d",-1);
						else
							printf("%d\n",-1);
					}
					else
					{
						if(i==(T-1)&&j==(oper-1))
						printf("%d",myp3->data);
						else
						 printf("%d\n",myp3->data);
					}
                }
        }
    }
	return 0;
}

Node* Insert(Node* headloc, int val)
{
    int flag=0;
    Node* tempptr1=headloc;
    Node* tempptr2=headloc;
    Node* ptr;
    ptr=(Node*)malloc(sizeof(Node));
    ptr->data=val;
    if(headloc!=NULL)
    {
            while(tempptr1->data<=val)
            {
                    flag=1;
                    tempptr2=tempptr1;
                    tempptr1=tempptr1->next;
                    if(tempptr1==NULL)
                    {
                        break;
                    }
            }
        if(flag==1)
        {
            tempptr2->next=ptr;
            ptr->next=tempptr1;
            return ptr;
        }
        else
        {
            ptr->next=head;
            head=ptr;
            return ptr;
        }
    }
    else
    {
        head=ptr;
        ptr->next=NULL;
    }
    return NULL;
}

Node* deleteDuplicate(Node* head)
{

    int counter,flag=0;
	Node* p1;
	Node* p2;
	Node* p3;
	p1=head;
	while(p1!=NULL)
	{
	    counter=0;
		p2=p1;
		while(p2!=NULL)
		{
			if(p1->data==p2->data)
			{
				counter++;
				if(counter>1)
				{
					flag=1;
					p3->next=p2->next;
					p2->next=NULL;
					return p2;
				}
				else
				{
					p3=p2;
					p2=p2->next;
				}
			}
			else
			{
				p3=p2;
				p2=p2->next;
			}
		}
		p1=p1->next;
	}
	if(flag==0)
	{
		return NULL;
	}

}


