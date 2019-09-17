#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int comp(const void *a,const void *b)
{ if(*(long int *)a-*(long int *)b>0)
    return 1;
  else return -1;
} 

int main(void) {
	// your code goes here
	long int m,n,a[100009],b,i,j,k,sets,temp,count;
	long int x[200009],y[200009];
	char* edges; 
	scanf("%ld %ld",&n,&m);
	if(m==(n*(n-1))/2)
	{
	    sets = n;
	    b=0;
	    temp = 1;
	    while(temp<sets)
	    { b++; temp=temp<<1; }
	    if(b*n>1000000L)
	      printf("-1");
	    else
	    { printf("%ld\n",b);
	      for(i=0;i<b;i++)
	      {  count = 1L<<i;
	         for(j=0;j<n;j++)
	         {
	            if((j/count)%2) printf("0");
	            else printf("1"); 
	         } 
	         printf("\n");
	      }
	    } 
	    
	}
	else
	 { for(i=0;i<n;i++)
	   a[i]=0;
	   sets = 0;
	   edges = (char *)malloc(n*n*sizeof(char)); 
	   for(i=0;i<m;i++)
	   { scanf("%ld %ld",&x[i],&y[i]);
	   x[i]--; y[i]--;
	   edges[n*x[i]+y[i]]=1;
	   edges[n*y[i]+x[i]]=1;
	   }
	   //calculate disjoints sets
	   for(i=0;i<m;i++)
	    { if(a[x[i]]==a[y[i]])
	      { sets++;
	        a[y[i]]=sets;
	        for(k=0;k<x[i];k++)
	        { if(a[k]==a[x[i]])
	          { if(edges[n*k+x[i]])
	             { a[k]=sets;} 
	            else if(edges[n*k+y[i]])
	             { continue; }
	            else
	             { printf("-1"); exit(0);
	             }
	          }
	        }
	        for(k=x[i]+1;k<n;k++)
	        {
	            if(a[k]==a[x[i]])
	            { if(edges[n*x[i]+k])
	              { a[k]=sets; }
	             else if(edges[n*y[i]+k])
	              continue;
	             else
	             { printf("-1"); exit(0);
	             }
	            } 
	        }
	      }
	    }
	  //print them
	  b=0; temp =1; sets++; 
	  while(temp<sets)
	  { b++; temp = temp<<1; }
	  if(b*n>1000000L)
	   printf("-1");
	  else
	  { printf("%ld\n",b);
	    for(i=0;i<b;i++)
	    { count =1L<<i;
	      for(j=0;j<n;j++)
	      {
	          if((a[j]/count)%2) printf("0");
	          else printf("1");
	      }
	      printf("\n");
	    }
	  }
	 } 
	return 0;
}

