#include <stdio.h>

int main(void) {
	int T,n,i,rem,j=0,counter;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
	        counter=0;
	    	scanf("%d",&n);
	    	while(n!=0)
	    	{
	    	    rem=n%2;
	    	    if(rem==1)
	    	    {
	    	        counter++;
	    	    }
	    	    n=n/2;
	    	    j++;
	    	}
	    	printf("%d\n",counter);
	}
	return 0;
}

