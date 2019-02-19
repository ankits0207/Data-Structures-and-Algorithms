#include <stdio.h>
#include <string.h>

/*
    Lab 3 assignment submitted by:

                                    Ankit Sharma - MT16121
                                    Ankit Rehani - MT16085

*/

struct Stack
{
    int top;
    char arr[1000];
};
typedef struct Stack STK;

int IsEmpty(STK*s);
int IsFull(STK*s);
int Push(STK*s,char c);
char Pop(STK*s);


int main(void) {
	STK *s=(STK*)malloc(sizeof(STK));
	s->top=-1;
	int T,i,j,len,flag=0,chkpush;
	char chkchar;
	scanf("%d",&T);
	char inarr[1000];
	for(i=0;i<T;i++)
	{
	    flag=0;
		scanf("%s",inarr);
		if(inarr[0]=='\0')
		{
		    printf("YES\n");
		    break;
		}
		len=strlen(inarr);
		for(j=0;j<len;j++)
		{
			if((inarr[j]=='{') || (inarr[j]=='[') || (inarr[j]=='('))
				{
					chkpush=Push(s,inarr[j]);
					if(chkpush==0)
					return -1;
				}
			else if((inarr[j]=='}') || (inarr[j]==']') || (inarr[j]==')'))
				{
					if(inarr[j]=='}')
					{
						chkchar=Pop(s);
						if(chkchar=='{')
						{
								
						}
						else if(chkchar==NULL)
						{
						    flag=1;
						}
						else
						{
						    flag=1;
						}
					}
					else if(inarr[j]==']')
					{
					chkchar=Pop(s);
						if(chkchar=='[')
						{
								
						}
						else if(chkchar==NULL)
						{
							flag=1;
						}
						else
						{
						    flag=1;
						}
					}
					else if(inarr[j]==')')
					{
						chkchar=Pop(s);
						if(chkchar=='(')
						{
								
						}
						else if(chkchar==NULL)
						{
							flag=1;
						}
						else
						{
						    flag=1;
						}
					}
					
				}
				else
				{
				    flag=1;
				}
		}
		if(flag==0)
		{
		    if(IsEmpty(s))
		    {
		        printf("YES\n");
		    }
		    else
		    	printf("NO\n");
		}
		else
		{
		    printf("NO\n");
		}
		
	}
	// your code goes here
	return 0;
}


int IsEmpty(STK*s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;    
}
int IsFull(STK*s)
{
    if(s->top==999)
        return 1;
    else
        return 0;    
}
int Push(STK*s,char c)
{
    if(IsFull(s))
	{
		return 0;
	}
	else
	{
		s->top++;
		s->arr[s->top]=c;		
		return 1;
	}
}
char Pop(STK*s)
{
	char c;
    if(IsEmpty(s))
	{
		return NULL;
	}
	else
	{
		c=s->arr[s->top];
		s->top--;		
		return c;
	}
}
