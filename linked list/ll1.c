#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int count();
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;

node *start[20]={NULL};
char ln[10][50];
int nol,lk,loc;

node *getnode()
{
	return (node*)malloc(sizeof(node));
}

int isempty()
{
	return start[lk]==NULL;
}

void which()
{	int i;
	again1:
	printf("\nselect list you want to operate :\n");
	for(i=0;i<nol;i++)
		printf("%d-%s\n",i+1,ln[i]);
	scanf("%d",&lk);
	if(lk>nol)
		{
			printf("\n\ninvalid selection!!\n\n");
			goto again1;
		}
	lk--;
}

void where()
{
	printf("\nenter the location starting from 1:");
	scanf("%d",&loc);
}

int count()
{ int c=0;
node *temp;
temp=start[lk];
while(temp!=NULL)
{
c++;
temp=temp->next;
}
return c;

}

void newlist(int f)
{
	printf("\nEnter the name of list %d :",f);
	fflush(stdin);
	scanf("%s",ln[nol]);
	nol++;
}

void display()
{	node *temp;
	
	if(!isempty())
	{
		printf("\nlist \"%s\":\n",ln[lk]);
		temp=start[lk];
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
	else
		printf("\nlist is empty\n");
}


void insert()
{	int i,d,f=0,n;
	node *temp,*temp1,*temp2;	
	printf("\nhow many node u want to create?");
	scanf("%d",&n);
if(loc == 1)
{
	if(!isempty())
	{	
		temp=start[lk];
		temp1=getnode();
		start[lk]=temp1;
		for(i=0;i<n-1;i++)
		{
		temp1->next=getnode();
		temp1=temp1->next;
		}
		f=1;
		temp1->next=temp;
		temp=start[lk];
	}
	else
	{	
		temp1=getnode();
		temp=start[lk]=temp1;
		for(i=0;i<n-1;i++)
		{
		temp1->next=getnode();
		temp1=temp1->next;
		}
		f=1;
		temp1->next=NULL;
	}
}

else if(loc>1&&loc<(count()+1))
{
	if(!isempty())
	{	temp=start[lk];
		for(i=1;i<loc-1;i++)
			temp=temp->next;
		temp1=getnode();
		temp2=temp1;
		for(i=0;i<n-1;i++)
		{
		temp1->next=getnode();
		temp1=temp1->next;
		}
		 temp1->next=temp->next;
		 temp->next=temp2;
		f=1;
		temp=temp->next;
		// temp->next=temp1;
	}
	else
	{
		printf("\nyou cannot insert at this location because this list is empty\n");
	}
}

else if(loc==count()+1)
{
	if(!isempty())
	{
		temp=start[lk];
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=getnode();
		temp2=temp1;
		for(i=0;i<n-1;i++)
		{
		temp1->next=getnode();
		temp1=temp1->next;
		}
		temp->next=temp2;
		f=1;
		temp1->next=NULL;
		temp=temp->next;
	}
	else
	{	
		temp1=getnode();
		temp=start[lk]=temp1;
		for(i=0;i<n-1;i++)
		{
		temp1->next=getnode();
		temp1=temp1->next;
		}
		f=1;
		temp1->next=NULL;
	}
}

else
	printf("\nyour location should be greater than 0 and less than or equal to %d for link \"%s\"\n\n",count()+1,ln[lk]);
if(f==1)
{	for(i=0;i<n;i++)
	 {	//	fflush(stdin);
	printf("\nenter the data %d:",i+1);
		scanf("%d",&temp->data);
		temp=temp->next;
	}
}
}


void delete()
{	node *temp,*temp1;
	int i,f=0;
	if(loc==1)
	{
		temp=start[lk];
		start[lk]=start[lk]->next;
		f=1;
	}
	else if(loc>1&&loc<count())
	{
		temp=start[lk];
		for(i=1;i<loc-1;i++)
			temp=temp->next;
		temp1=temp;
		temp=temp->next;
		temp1->next=temp->next;
		f=1;

	}
	else if(loc==count())
	{	int i;
		temp=start[lk];
		for(i=1;i<loc-1;i++)
			temp=temp->next;
		temp1=temp;
		temp=temp->next;
		temp1->next=NULL;
		f=1;

	}
	else
	{
	printf("\nyour location should be greater than 0 and less than or equal to %d for link \"%s\"\n\n",count()+1,ln[lk]);
	}
	if(f)
	{
		free(temp);
		printf("\n**Deleted successfully**\n\n");
	}
}

void search(int n)
{	node *temp=start[lk];
	int c=0,f=0;
	if(!isempty())
	{
		while(temp!=NULL)
		{	c++;
			if(temp->data==n)
			{	
				f++;
				printf("\n****data found at location %d ***",c);
			}
			temp=temp->next;
		}

		if(f)
		{
			printf("\n----total count of occourance of data is %d----\n",f);
		}
		else
		{
			printf("\ndata not found!!");
		}	
	}
	else
	{
		printf("\nlist \"%s\" is empty",ln[lk]);
	}

}

void reverse()
{	int f=0;
	node *temp,*pre;
	if(!isempty())
	{
		temp=start[lk];
		temp=temp->next;
		start[lk]->next=NULL;
		while(temp!=NULL)
		{	pre=temp;
			temp=temp->next;
			if(temp==NULL)
			{	f=1;
				break;
			}
			// temp=temp->next;
			pre->next=start[lk];
			start[lk]=pre;
			
		}
		 if(f)
		 {
			pre->next=start[lk];
		 	start[lk]=pre;
		 }
		 printf("\n\n***list \"%s\" is reversed***\n\n",ln[lk]);
	}
	else
	{
		printf("\n list is empty\n");
	}
}

void split()
{	int p,i;
	node *temp,*temp1;
	if(!isempty())
	{
	display();
	printf("\n(the position you select will be 1st node of new list):");
	where();
	if(loc>=1&&loc<=count())
	{
		temp=start[lk];
		for(i=1;i<loc-1;i++)
			temp=temp->next;
		temp1=temp;
		temp=temp->next;
		if(temp!=NULL)
		{
			temp1->next=NULL;
			printf("\n**list splitted at %d and new list %d just created\n",loc,nol+1);
			newlist(nol+1);
			start[nol-1]=temp;
		}
		else
		{
			start[lk]=NULL;
			printf("\n**list splitted at %d and new list %d just created (you had single node ..now \"%s\" list is empty)\n",loc,nol+1,ln[lk]);
			newlist(nol+1);
			start[nol-1]=temp1;


		}
	}
	else
	{
	printf("\nyour location should be greater than 0 and less than or equal to %d for link \"%s\"\n\n",count(),ln[lk]);

	}	
	
	}
	else
	{
		printf("list \"%s\"is empty",ln[lk]);
	}
}

void merge(int a,int b)
{	node *temp;
	int i;
	a--;b--;
	temp=start[a];
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=start[b];
	printf("list \"%s\" merged with list \"%s\"",ln[b],ln[a]);
	for(i=b;i<nol-1;i++)
	{
		start[i]=start[i+1];
		strcpy(ln[i],ln[i+1]);
	}
	nol--;
	

}

void copy(int c)
{
	c--;
	node *temp,*temp1,*pre=NULL;
	temp=start[c];
	if(temp!=NULL)
	{	pre=temp1=getnode();
		temp1->data=temp->data;
		temp=temp->next;
		while(temp!=NULL)
		{
		temp1->next=getnode();
		temp1=temp1->next;
		temp1->data=temp->data;
		temp=temp->next;
		}
		temp1->next=NULL;
	}
	start[nol]=pre;
	printf("\n**copy of list \"%s\" created at %d\n ",ln[c],nol+1);
	newlist(nol+1);


}

void main()
{	int i,a,no,op,f=0,d,ns,l1=0,l2=0,c=0;
	
	again:
		 printf("\n\nMAIN MENU\npress the corresponding number:\n1-Create new list/lists\n2-select list\n3-exit\n\n");
	scanf("%d",&a);
	if(a==1)
	{	no=0;
again2: printf("how many list you want to make at this moment:");
		fflush(stdin);
		scanf("%d",&no);
		
		if(no>20||no==0)
		{
			printf("you can create max 20 lists ...invalid entry\n");
			goto again2;
		}
		for(i=0;i<no;i++)
			newlist(i+1);
		a=2;
		
	}		
	if(a==2)
	{	
mrg:	if(nol>1)
			which();
		else if(nol==1)
		{	printf("\n\n***you have only one list -\"%s\"***\n",ln[lk]);
			lk=0;
		}
		else
		{
			printf("\nyou dont have any existing list...create new list!!\n");
			goto again;
		}
		while(1)
		{   
			printf("\n\nselect any option to do corresponding operation on list \"%s\":\n1-Display\n2-Insert or Create\n3-Delete\n4-Search\n5-Reverse\n6-count nodes\n7-split\n8-merge\n9-Copy\n10-Goto MAIN MENU\n",ln[lk]);
			scanf("%d",&op);
			switch(op)
			{
				case 1: 
						display();
						break;
				case 2: 
						where();
						
						insert();
						break;
				case 3: display();
						where();
						delete();
						break;
				case 4:printf("\nenter number to search:");
						scanf("%d",&ns);
						search(ns);
						break;
				case 5:reverse();
						break;
				case 6: 
						printf("\nnumber of node(s) in list \"%s\" is/are %d\n",ln[lk],count());
						break;
				case 7:split();
						break;
				case 8: printf("\nselect 2 lists to merge among:\n");
						for(i=0;i<nol;i++)
							printf("%d-%s\n",i+1,ln[i]);
						printf("\nsr no of 1st list:");
						scanf("%d",&l1);
						printf("\nsr no of 2nd list:");
						scanf("%d",&l2);
						if(l1>nol||l2>nol||l1==0||l2==0)
							printf("\n**invalid selection**\n");
						else if(l1==l2)
							printf("\nselect 2 different lists..invalid selection\n");
						else
							merge(l1,l2);
						goto mrg;
						break;
				case 9: 
						printf("\n\nenter the sr. no. list u want to make a copy of: \n");
						for(i=0;i<nol;i++)
							printf("%d-%s\n",i+1,ln[i]);
						scanf("%d",&c);
						if(c<nol+1&&c>0)
							copy(c);
						else
							printf("\ninvalid selection\n");
							
						break;
				case 10:goto again;
				default:printf("\n!!  invalid option  !! try again\n");
						break;
			}
		}
	}
	else if(a==3)
	{
		printf("\nok bye..have a good day\n\n");
		printf("%38s author:HEiSENBERG\n"," ");
		printf("%38s last update:05/08/2019\n"," ");
		printf("%38s version:2.1.0\n"," ");
		printf("%38s bugs: unknown\n"," ");
		printf("%38s report address:abhijeetringe90@gmail.com\n"," ");


	}
	else
	{
		printf("\ninvalid option\n");
		goto again;
	}

}