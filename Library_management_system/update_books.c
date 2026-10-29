#include"header.h"

void update_book_details(LIB **ptr)
{
	if((*ptr)==NULL)
	{
		puts("THERE IS NO BOOK DETAIL IS AVAILABLE TO UPDATE !!!");
		return;
	}

	LIB *temp=search_book(hptr,-2,-1);
	int op;
	char ch;
	
	if(temp!=NULL)
	{

	do
	{
	puts("What do you want to modify?");
	puts("--------------------");
	puts("| 1)BOOK NAME      |");
	puts("| 2)AUTHOR NAME    |");
	puts("| 3)BOOK COUNT	 |");
	puts("| 4)MAIN MENU      |");
	printf("--------------------\n\n");

	puts("Enter your choice:");
	scanf("%d",&op);
	
	
	char new_book_name[100];
        char new_author_name[100];
	int new_book_count;
	int con;

	switch(op)
	{
		case 1 : puts("Enter the Book id to confirm :");
			 scanf("%d",&con);
			 temp=search_book(hptr,con,3);
			 	
			 puts("Enter the book name to modify:");
		         scanf("%s",new_book_name);
		         strcpy(temp->book_name,new_book_name);
			 printf("BOOK NAME MODIFIED SUCCESSFULLY!!!\n\n");
			 break;

		case 2:  puts("Enter the Book id to confirm :");
			 scanf("%d",&con);
			 temp=search_book(hptr,con,3);
			 
			 
			 puts("Enter the Author name to modify:");
			 scanf("%s",new_author_name);
			 strcpy(temp->book_author_name,new_author_name);
			 printf("AUTHOR NAME MODIFIED SUCCESSFULLY\n\n");
			 break;

		
		case 3: 
			 puts("Enter the Book id to confirm :");
			 scanf("%d",&con);
			 temp=search_book(hptr,con,3);			 
			
			
			 puts("Enter the Book count to modify:");
			 scanf("%d",&new_book_count);
			 temp->book_count=new_book_count;
			 printf("BOOK COUNT MODIFIED SUCCESSFULLY\n\n");
			 break;

		case 4 : return ;
			 
		default : puts("INVALID CHOICE!!!"); return;

	}

	puts("Do you want to modify anything again(y/n):");
	scanf(" %c",&ch);
	}while(ch=='y'|ch=='Y');
	
	}



}
