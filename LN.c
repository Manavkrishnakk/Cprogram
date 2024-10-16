#include<stdio.h>
#include<stdlib.h>
int c;
void push();
void pop();
void display();
struct node
{
	int data;
	struct node *next;
}*top,*temp,*newnode;
int main()
{
	while(c!=4)
	{
	printf("please select the choice\n\n1.push\n2.pop\n3.display\n4.exit\n");
	printf("Enter the option:");
	scanf("%d",&c);

	
		switch(c)
		{
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:break;
		}
	}
return 0;
}
void push()
{
	int v;
	printf("Enter the element to be inserted:");
	scanf("%d",&v);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=v;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("stack is empty..\n");
	}
	else
	{
		top=top->next;
	}
}
void display()
{
	if(top==NULL)
	{
		printf("stack is empty..\n");
	}
	else
	{
		temp=top;
		while(temp!=NULL)
		{
			printf("%d\n\n",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
