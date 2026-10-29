#include"header.h"


void print(LIB *ptr)
{
	printf("|%-25s%-28s%-13d%-7d|\n",ptr->book_name,ptr->book_author_name,ptr->book_id,ptr->book_count);

}



LIB *search_book(LIB *ptr,int n,int m)
{
	
	if(ptr==NULL)
	{
		puts("CURRENTLY NO DATA IS AVAILABLE TO UPDATE!!!");
		return 0;

	}

	int print_count=0;

	int op,book_id;
	issue_flag=0;
	char book_name[100],author_name[100];
	char ch;
	LIB *ret;
	do
	{
	int flag=0;
	
	if(n==-1||n==-2)
	{
	puts("--------------------");
	puts("|SEARCH BOOK BY:   |");
	puts("| 1)BY BOOK NAME   |");
	puts("| 2)BY AUTHOR NAME |");
	puts("| 3)BY BOOK ID     |");
	if(m!=4)
	puts("| 4)MAIN MENU      |");
	puts("--------------------");

	
	puts("Enter your choice:");
	scanf("%d",&op);
	}
	if((n!=-1)&&(m==3))
	{
		op=3;
	}

	LIB *temp=ptr;

	switch(op)
	{
		case 1 :puts("Enter the book name:");
			scanf("%s",book_name);
		         while(temp!=NULL)
			 {
				if(strcmp(temp->book_name,book_name)==0)
				{
					print_count++;
					flag=1;
					printf("---------------------------------------------------------------------------\n");
					if(print_count==1)
					{
        				printf("|%-25s%-25s%-13s%-7s|\n","Book name","Author name","Book id","Book count" );
					printf("---------------------------------------------------------------------------\n");
					}
					print(temp);
					ret=temp;
					
				}
				temp=temp->next;

			 }
			 
			 print_count=0;
			 
			  break;

		case 2 :puts("Enter the Author Name:");
			scanf("%s",author_name);
			while(temp!=NULL)
			{
				if(strcmp(temp->book_author_name,author_name)==0)
				{
					flag=1;
					printf("---------------------------------------------------------------------------\n");
					print_count++;
					if(print_count==1)
					{
       		 			printf("|%-25s%-25s%-13s%-7s|\n","Book name","Author name","Book id","Book count" );
					printf("---------------------------------------------------------------------------\n");
					}
					print(temp);
					ret=temp;

					

				}
				temp=temp->next;

			}
			print_count=0;
			break;

		case 3 : 
		   	if(m!=3)
			{
		       	 puts("Enter the Book Id:");
			 scanf("%d",&book_id);
			}
			if(m==3)
				book_id=n;

			 while(temp!=NULL)
			 {
				 if(temp->book_id==book_id)
				 {
					flag=1;
					if(!((n!=-1)&&(m==3)))
					{
					printf("---------------------------------------------------------------------------\n");
        				printf("|%-25s%-25s%-13s%-7s|\n","Book name","Author name","Book id","Book count" );
					printf("---------------------------------------------------------------------------\n");
					print(temp);
					}
					ret=temp;
					
				        

				 }
				 temp=temp->next;
			 }
			 break;

		case 4 : return 0;
 
		default : printf("INVALID CHOICE\n\n");return 0;

	}
	if(flag==1 && m!=3)
	printf("---------------------------------------------------------------------------\n");
	if(flag==0)
	{
		puts("SEARCHED BOOK IS NOT FOUND!!!");
		issue_flag=1;
		return NULL;
	}
	if(n!=-1)
		break;
	puts("Do you want to search again (y/n):");
	scanf(" %c",&ch);
	}while(ch=='y'||ch=='Y');

	return ret;
}

