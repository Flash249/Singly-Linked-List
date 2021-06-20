#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
};
struct node * head=NULL;
int create_ll()
{
	struct node * new_node, *ptr;
	int num;
	printf("\n    Enter -1 to end\n");
	printf("\n Enter the data: ");
	scanf("%d",&num);
	while(num!=-1)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data=num;
		if(head==NULL)
		{
			new_node->next=NULL;
			head=new_node;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next = new_node;
			new_node->next=NULL;
		}
		printf("\n Enter the data: ");
		scanf("%d",&num);
	}
	return;
}
int ins_beg()
{
	struct node * new_node;
	int num;
	printf("\n Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	new_node->next=head;
	head=new_node;
	return;
}
int ins_end()
{
	struct node * new_node, *ptr;
	int num;
	printf("\n Enter the data: ");
	scanf("%d",&num);
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=num;
	ptr=head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=new_node;
	new_node->next=NULL;
	return;
}
int ins_bef()
{
	struct node *new_node,*ptr,*ptr1;
	int num,a,cnt=0;
	printf("\n Enter the node before which node is to be added: ");
	scanf("%d",&a);
	ptr=head;
	ptr1=ptr;
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;
	}
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",a);
	else
	{
		ptr=head;
		while(ptr->data!=a)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		if(ptr==head)
			ins_beg();
		else
		{
			printf("\n Enter the data: ");
			scanf("%d",&num);
			new_node=(struct node *)malloc(sizeof(struct node));
			new_node->data=num;
			ptr1->next=new_node;
			new_node->next=ptr;
		}
    }
	return;
}
int ins_aft()
{
	struct node *new_node, *ptr;
	int a,num,cnt=0;
	printf("\nEnter the data after which node to be inserted: ");
	scanf("%d",&a);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;
	}
	
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",a);
	else
	{
		printf("\nEnter the data: ");
		scanf("%d",&num);
		new_node=(struct node*)malloc(sizeof(struct node));
		new_node->data=num;
		ptr=head;
		while(ptr->data!=a)
			ptr=ptr->next;
		new_node->next=ptr->next;
		ptr->next=new_node;
	}
	return;
}
void display()
{
	struct node * ptr;
	if(head==NULL)
		{
			printf("\n !!!No Linked list !!!\a\n");
			return;
		}
	else
	{
		ptr = head;
		printf("\n");
		while(ptr->next!=NULL)
		{
			printf("\t%d",ptr->data);
			ptr=ptr->next;
		}
		printf("\t%d\n",ptr->data);
	}
}
int sort()
{
	struct node *ptr, *ptr1;
	int temp;
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr1=ptr->next;
		while(ptr1!=NULL)
		{
			if(ptr->data > ptr1->data)
			{
				temp=ptr->data;
				ptr->data=ptr1->data;
				ptr1->data=temp;
			}
			ptr1=ptr1->next;
		}
		ptr=ptr->next;
	}
	return;
}
int del_beg()
{
	struct node *ptr;
	ptr=head;
	if(head==NULL)
		printf("\n !!!No nodes present!!!\a\n");
	else
	{
		head=ptr->next;
		free(ptr);
	}
	return;	
}
int del_end()
{
	struct node * ptr,*ptr1;
	ptr=head;
	if(head==NULL)
		printf("\n !!!No node present!!!\a\n");
	else
	{
		if(ptr->next==NULL)
		{
			head=NULL;
			free(ptr);
		}
		else
		{
			while(ptr->next!=NULL)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			ptr1->next=NULL;
			free(ptr);
		}
	}
	return;
}
int del_giv()
{
	struct node * ptr,*ptr1;
	int a,cnt=0;
	printf("\n Enter the data of node you want to delete: ");
	scanf("%d",&a);
	ptr=head;
	ptr1=ptr;
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;	
	}
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",a);
	else
	{
		ptr=head;
		if(ptr->data==a)
			del_beg();
		else
		{
			while(ptr->data!=a)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			ptr1->next=ptr->next;
			free(ptr);
		}
	}
	return;
}
int del_aft()
{
	struct node *ptr,*ptr1;
	int a,cnt=0;
	printf("\n Enter the node after which you want to delete: ");
	scanf("%d",&a);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;	
	}
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",a);
	else
	{
		ptr=head;
		ptr1=ptr->next;
		while(ptr->data!=a)
		{
			ptr1=ptr1->next;
			ptr=ptr->next;
		}
		if(ptr->next==NULL)
		{
			printf("\n !!!No node after given node!!!\a\n");
			return;
		}
		else
		{
			ptr->next=ptr1->next;
			free(ptr1);
	    }
	}    
    return;
}
int del_bef()
{
	struct node *ptr,*ptr1,*ptr2;
	int a,cnt;
	printf("\n Enter the node before which, node to be deleted: ");
	scanf("%d",&a);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;	
	}
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",a);
	else
	{
		ptr=head;
		ptr1=ptr;
		ptr2=ptr1;
		if(ptr->data==a)
			printf("\n !!!No node available before this node!!!\a\n");
		else
		{
			while(ptr->data!=a)
			{
				ptr2=ptr1;
				ptr1=ptr;
				ptr=ptr->next;
			}
			if(ptr1==head)
			{
				del_beg();
				return;
			}
			ptr2->next=ptr;
			free(ptr1);
	    }
	}
	return;
}
int del_by_index()
{
	struct node *ptr,*ptr1;
	int cnt=1,num;
	printf("\n Enter the index of node to be deleted: ");
	scanf("%d",&num);
	ptr=head;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	if(num>cnt||num<0)
		printf("\n !!!Number exceeded from linked list!!!\a\n");
	else if(num==1)
		del_beg();
	else if(num=cnt)
		del_end();
	else
	{
		if(num==0)
			printf("\n !!!Enter number greater than 0!!!\a\n");
		else
		{
			ptr=head;
			while(ptr->data!=num)
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
			ptr1->next=ptr->next;
			free(ptr);
		}
	}
	return;
}
int del_data()
{
	struct node *ptr,*ptr1;
	int num,cnt=0;
	ptr=head;
	printf("\n Enter data whose all nodes to be deleted: ");
	scanf("%d",&num);
	while(ptr!=NULL)
	{
		if(ptr->data==num)
			cnt++;
		ptr=ptr->next;
	}
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",num);
	else
	{
		ptr=head;
		ptr1=ptr;
		while(ptr!=NULL)
		{
			if(ptr->data==num)
			{
				if(ptr==head)
				{
					head=ptr->next;
					free(ptr);
					ptr=head;
					ptr1=ptr;
				}
				else
				{
					ptr1->next=ptr->next;
					free(ptr);
					ptr=ptr1;
					ptr=ptr->next;
				}
			}
			else
			{
				ptr1=ptr;
				ptr=ptr->next;
			}
		}
	}
	return;
}
int count()
{
	struct node * ptr;
	int cnt=1;
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	printf("\n Number of nodes in linked list is %d \n",cnt);
	return;
}
int search_by_index()
{
	struct node * ptr;
	int cnt=1,num,cnt1=1;
	ptr=head;
	printf("\n Enter the number of node whose data you want to find: ");
	scanf("%d",&num);
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	ptr=head;
	if(num>cnt||num<0)
		printf("\n !!!Number exceeded from linked list!!!\a\n");
	else
	{
		if(num==0)
			printf("\n !!!Enter number greater than 0!!!\a\n");
		else
		{
			while(cnt1!=num)
			{
				ptr=ptr->next;
				cnt1++;
			}
			printf("\n Data on %d node is %d \n",num,ptr->data);
		}
    }
    return;
}
int reverse()
{
	struct node *ptr,*ptr1;
	int temp;
	ptr=head;
	ptr1=ptr;
	while(ptr1->next!=NULL)
	{
		ptr=ptr1->next;
		while(ptr!=NULL)
		{
			temp=ptr1->data;
			ptr1->data=ptr->data;
			ptr->data=temp;
			ptr=ptr->next;
		}
		ptr1=ptr1->next;
	}
	return;
}
int search_by_data()
{
	struct node *ptr;
	int cnt=0,a;
	printf("\n Enter the data whose position you want: ");
	scanf("%d",&a);
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;
	}	
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\n");
	else
	{
		cnt=1;
		ptr=head;
		while(ptr->data!=a)
		{
			cnt++;
			ptr=ptr->next;
		}
		printf("\n Node with data %d is at index %d \n",a,cnt);
	}
	return;
}
int last_nth_node()
{
	struct node * ptr;
	int cnt=1,cnt1=1,num;
	printf("\n Enter the n to find last nth node: ");
	scanf("%d",&num);
	ptr=head;
	reverse();
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	ptr=head;
	if(num>cnt||num<0)
		printf("\n !!!Number exceeded from linked list!!!\a\n");
	else
	{
		if(num==0)
			printf("\n !!!Enter number greater than 0!!!\a\n");
		else
		{
			while(cnt1!=num)
			{
				ptr=ptr->next;
				cnt1++;
			}
			printf("\n Data on last %d node is %d \n",num,ptr->data);
		}
		reverse();
    }
    return;	
}
int same_nodes()
{
	struct node *ptr;
	int cnt=0,cnt1,a;
	ptr=head;
	printf("\n Enter data whose reptition you want to find: ");
	scanf("%d",&a);
	while(ptr!=NULL)
	{
		if(ptr->data==a)
			cnt++;
		ptr=ptr->next;
	}
	if(cnt==0)
		printf("\n !!!No node available as %d !!!\a\n",a);
	else
	{
		cnt1=0;
		ptr=head;
		printf("\n There are %d nodes of data %d \n",cnt,a);
		printf("\n The node %d is available at index\t",a);
		while(ptr!=NULL)
		{	
			cnt1++;
			if(ptr->data==a)
			{
				printf("%d \t",cnt1);	
			}
			ptr=ptr->next;
		}
		printf("\n");
	}
	return;
}
int main()
{
	int ch; 
	do
	{
		printf("\n 01.Create\n 02.Insert at beginning\n 03.Insert at last\n 04.Insert before given node\n 05.Insert after given node");
		printf("\n 06.Display\n 07.Sort");
		printf("\n 08.Delete at beginning\n 09.Delete at end\n 10.Delete a node\n 11.Delete after given node");
		printf("\n 12.Delete before given node\n 13.Delete node at given index\n 14.Delete all nodes with given data");
		printf("\n 15.Count nodes\n 16.Search node at index number\n 17.Reverse the list\n 18.Search node by data");
		printf("\n 19.Find nth node from end\n 20.Find position of same nodes\n 21.Exit");
		printf("\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create_ll();
				break;
			case 2:ins_beg();
				break;
			case 3:ins_end();
				break;
			case 4:ins_bef();
				break;
			case 5:ins_aft();
				break;
			case 6:display();
				break;
			case 7:sort();
				break;
			case 8:del_beg();
				break;
			case 9:del_end();
				break;
			case 10:del_giv();
				break;
			case 11:del_aft();
				break;
			case 12:del_bef();
				break;
			case 13:del_by_index();
				break;
			case 14:del_data();
				break;
			case 15:count();
				break;
			case 16:search_by_index();
				break;
			case 17:reverse();
				break;
			case 18:search_by_data();
				break;
			case 19:last_nth_node();
				break;
			case 20:same_nodes();
				break;
			case 21:break;
			default: printf("\n !!!Enter a valid choice!!!\n");	
		}
	}while(ch!=21);
	return;
}
