#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct llnode{
    char* cp;
    struct llnode * Next;
};
typedef struct llnode Node;

Node* Ins(Node* head,char* ptr);
void sort(Node* head,char chkarr[26]);
char strcomp(char* p1,char* p2,char chkarr[26]);
int findpos(char mychar,char chkarr[26]);

Node* head=NULL;
Node* headf=NULL;
int main(void) {
	int T,i,N,j;
	char chkarr[26];
	char* strptr;
	strptr=malloc(80*(sizeof(char)));
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
	    head=NULL;
	    headf=NULL;
	    scanf("%s",chkarr);
	    scanf("%d",&N);
	    for(j=0;j<N;j++)
	    {
	       scanf("%s",strptr);
	       head=Ins(head,strptr);
	    }
        /*
	    Node* testptr=head;
	    while(testptr!=NULL)
	    {
	        printf("%s\n",testptr->cp);
	        testptr=testptr->Next;
	    }*/
	    sort(head,chkarr);
	    Node* readptr=headf;
	    while(readptr!=NULL)
	    {
	        if(readptr->Next==NULL&&i==(T-1))
	        {
	            printf("%s",readptr->cp);
                readptr=readptr->Next;
	        }
	        else
	        {
	            printf("%s\n",readptr->cp);
                readptr=readptr->Next;
	        }
	    }
	}

	return 0;
}
Node* Ins(Node* head,char* ptr)
{
    Node* p=(Node*)malloc(sizeof(Node));
    p->cp=strdup(ptr);
    p->Next=head;
    head=p;
    return head;
}
void sort(Node* head,char chkarr[26])
{
    char c;
    char* temp;
    Node* N1;
    Node* N2;
	Node* N3;
	Node* N4;
    N1=head;
	while(N1->Next!=NULL)
	{
	    N2=N1->Next;
	    N4=head;
		N3=N1;
		while(N2!=NULL)
		{
		   c=strcomp(N3->cp,N2->cp,chkarr);
		   if(c=='f')
		   {
			temp=N3->cp;
			N3->cp=N2->cp;
			N2->cp=temp;
		   }
		   else
		   {}
		   N2=N2->Next;
		   N3=N3->Next;
		}
		headf=Ins(headf,N3->cp);
		while(N4->Next!=N3)
		{
			N4=N4->Next;
		}
		N4->Next=NULL;
		free(N3);

	}
	headf=Ins(headf,N1->cp);
	free(N1);
}
int findpos(char mychar,char chkarr[26])
{
    int i;
    for(i=0;i<26;i++)
    {
        if(mychar==chkarr[i])
        {
            return i;
        }
    }
}
char strcomp(char* p1,char* p2,char chkarr[26])
{
    int l1,l2,count=0;
    l1=strlen(p1);
    l2=strlen(p2);
    if(l1<l2)
    {
        while(count<=l1-1)
        {
            if(findpos(p1[count],chkarr)==findpos(p2[count],chkarr))
            {
                count++;
            }
            else if(findpos(p1[count],chkarr)>findpos(p2[count],chkarr))
            {
                return 'f';
            }
            else if(findpos(p1[count],chkarr)<findpos(p2[count],chkarr))
            {
                return 's';
            }
        }
        return 's';
    }
    else if (l2<l1)
    {
        while(count<=l2-1)
        {
            if(findpos(p1[count],chkarr)==findpos(p2[count],chkarr))
            {
                count++;
            }
            else if(findpos(p1[count],chkarr)>findpos(p2[count],chkarr))
            {
                return 'f';
            }
            else if(findpos(p1[count],chkarr)<findpos(p2[count],chkarr))
            {
                return 's';
            }
        }
        return 'f';
    }
    else
    {
        while(count<=l1-1)
        {
            if(findpos(p1[count],chkarr)==findpos(p2[count],chkarr))
            {
                count++;
            }
            else if(findpos(p1[count],chkarr)>findpos(p2[count],chkarr))
            {
                return 'f';
            }
            else if(findpos(p1[count],chkarr)<findpos(p2[count],chkarr))
            {
                return 's';
            }
        }
        return 'f';
    }
}

