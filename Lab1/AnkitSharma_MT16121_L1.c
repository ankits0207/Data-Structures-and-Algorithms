#include <stdio.h>
#include <string.h>

char* checkPalind(char *s);

int main(void) {
    int T,i;
    char* ansp;
    scanf("%d",&T);
    char ptr[105];
    for(i=0;i<T;i++)
    {
        scanf("%s",ptr);
        ansp=checkPalind(ptr);
        printf("%s\n",ansp);
    }
    
    return 0;
}

char* checkPalind(char *s)
{ 
    int i,j,counte = 0,counto = 0,occ[105],myArr[26] = {0};
    char* answer;
    int num=strlen(s);
    if((num%2)==0)
    {
        for(i=0;i<num;i++)
        {
            for(j=0;j<num;j++)
            {
                if(s[i]==s[j])
                {
                    counte++;
                }
            }
            if((counte-1)%2==0)
             {
                 answer = "NO";
             }
             else {
                 answer = "YES";
             }
            counte = 0;
        }
    }
    else
    {
        i=0;
        while(s[i]!='\0') {
            myArr[s[i] - 'a']++;
            i++;
        }
        for(i=0;i<26;i++) {
            if(myArr[i] %2 != 0) {
                counto++;
            }
        }
        if(counto > 1) {
            answer = "NO";
        }
        else {
            answer = "YES";
        }
        
    }
    return answer;
}