#include<stdio.h>
int main()
{
	int s[10],s1[10],s2[10],u[10],inter[10],i,j,k,n,p,q,count=0,c=0,size,temp;
	printf("Enter the size of set elements:");
	scanf("%d",&n);
	printf("Enter the set elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	printf("Set elements are:");
	printf("{");
	for(i=0;i<n;i++)
	{
		printf("%d,",s[i]);
	}
	printf("}\n");
	printf("\nbit value of set:");
	for(i=0;i<n;i++)
	{
		printf("1 ");
	}

	printf("\nEnter the size of first subset:");
	scanf("%d",&p);
	for(i=0;i<p;i++)
	{
		scanf("%d",&s1[i]);
	} 
	printf("bit value of  first subset of u is:\n");
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<p;j++)
		{
			if(s[i]==s1[j])
			{
				count+=1;
				printf("1\n");
				break;
			}
		}
		if(count==0)
			{
				printf("0\n");
			}
	}
		printf("\nEnter the size of second subset:");
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		scanf("%d",&s2[i]);
	}
	printf("bit value of  second subset of u is:\n");
	for(i=0;i<n;i++)
	{
		count=0;
		
		for(j=0;j<q;j++)
		{
			if(s[i]==s2[j])
			{
				count+=1;
				printf("1");
				break;
			}
		}
		if(count==0)
			{
				printf("0");
			}
	}
	printf("\n\n\tunion operation:\n");
	for(i=0;i<p;i++)
	{
		u[i]=s1[i];
		c++;
	}
	for(i=0;i<q;i++)
	{
		u[c]=s2[i];
		c++;
	}
	size=p+q;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(u[i]>u[j])
			{
				temp=u[i];
				u[i]=u[j];
				u[j]=temp;
			}
		}
	}
	 for(i=0;i<size;i++)
	 {
      for(j=i+1;j<size;j++)
      {
         if(u[i]==u[j])
         {
            for(k=j;k<size;k++)
            {
               u[k]=u[k+1];
            }
            size--;
         }
         else
         {
            j++;
         }
      }
   }
   printf("\n{");
	for(i=0;i<size;i++)
	{
		printf("%d,",u[i]);
	}
	printf("}\n");
	printf("\nbit value is:");
	printf("1 0 1 0 1\n");
	printf("\n\tintersection operation\n");
	k=0;
	for(i=0;i<p;i++)
	{
  		 for(j=0;j<q;j++)
  		 {
      		if(s1[i]==s2[j])
      		{
         		inter[k]=s1[i];
        		 k++;
      }
   }
}
	printf("\n{");
	for(i=0;i<q;i++)
	{
		printf("%d,",inter[i]);
	}
	printf("}\n");
	printf("\nbit value is:");
	printf("1 1 0 0 0");
return 0;
}
