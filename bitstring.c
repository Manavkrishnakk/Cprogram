#include<stdio.h>
int main()
{
	int s[10],s1[10],s2[10],u[10],i,j,n,p,q,count=0,c=0;
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
	printf("Enter the size of first subset:");
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
				printf("1");
				break;
			}
		}
		if(count==0)
			{
				printf("0");
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
	printf("\nunion operation:\n");
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
	for(i=0;i<p+q;i++)
	{
		printf("%d",u[i]);
	}
return 0;
}
