#include <stdio.h>
#include <stdlib.h>

char* checkfunny(char *s);
char* stringrev(char *orgstr,int len);
int slen(char * mystr);

int main(void) {
    int T,i;
    char* ansp;
    char ptr[1000];
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
    scanf("%s",ptr);
    ansp=checkfunny(ptr);
    printf("%s\n",ansp);
    }
	return 0;
}
char* checkfunny(char * s)
{
    char* retp;
    int len = slen(s);
    char* revptr = stringrev(s,len);
    int flag=0;
    int j;
    for(j=1;j<=(len-1);j++)
    {
        if(abs(s[j]-s[j-1])!=abs(revptr[j]-revptr[j-1]))
        flag=1;
    }
    if(flag==0)
    {
        retp="Funny";
        return retp;   
    }
    else
    {
        retp="Not Funny";
        return retp;   
    }
}
char * stringrev(char * orgstr,int len)
{
    int k;
    char a[len];
    for(k=0;k<len;k++)
    {
        a[k]=orgstr[len-1-k];
    }
    char * retptr = a;
    return retptr;
}
int slen(char * mystr)
{
    char * temp;
    temp=mystr;
    while(*temp!='\0')
    {
        temp=temp+1;
    }
    return temp-mystr;
}
