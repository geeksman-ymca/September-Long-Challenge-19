
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 



int main(void) {
	// your code goes here 
	unsigned int n,k; 
	unsigned int x,y; 
	unsigned long int a[100009],gcd,min;
	unsigned long int *b;
	unsigned long int temp,p,i,j,num;
	scanf("%u",&n);
    b = (unsigned long int*)malloc(1000001L*sizeof(long int));
    for(i=0;i<n;++i)
    { scanf("%lu",a+i);
      if(*(a+i)<1000001L)
       ++*(b+*(a+i));
    }
    min = 1; 
	for(i=0;i<n;++i)
	{  
	   x = *(a+i);
	   if((x==1)&&(min<1000001L))
	   {  *(b+min)+=n-i-1;
	       continue;
	   } 
	   temp = 1; 
	   for(j=i+1;j<n;++j)
	   {   y=*(a+j);
	       gcd = 1;
	       while(x!=y) 
	       {
	           if(x&y&temp)
	           { if(x>y)
	              x=(x-y)>>1;
	             else
	              y=(y-x)>>1;
	           }
	           else if(x&temp)
	            y>>=1;
	           else if(y&temp)
	            x>>=1;
	           else {
	               gcd<<=1;x>>=1;
	               y>>=1; }
	       }
	       gcd *=x;
	       x = gcd; 
	     if((gcd==1)&&(min<1000001L))
	     { *(b+min)+=n-j; break; }
	     else if(gcd*min<1000001L) 
	      ++*(b+gcd*min); 
	   } 
	   if((j==n)&&(x!=1))
	   { min = min*x;
	     for(k=i+1;k<n;k++)
	       a[k]/=x;
	   } 
	}
	for(i=500000L;i>1;--i)
	{ if(*(b+i))
	  { for(j=i<<1;j<1000001L;j+=i)
	      *(b+j)+=*(b+i);
	  }
	} 
	scanf("%u",&k); 
	for(i=0;i<k;++i)
	{
	    scanf("%lu",&num);
	    if(num==1) printf("%lu\n",*(b+1));
	    else 
	    printf("%lu\n",*(b+num)+*(b+1));
	} 
	return 0;
}
