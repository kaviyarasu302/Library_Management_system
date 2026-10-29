#include"header.h"



void list_issued_books(usr *ptr)
{

	if(ptr==NULL)
	{
		puts("NO RECORD IS AVAILABLE TO DISPLAY");
		return;

	}

	printf("----------------------------------------------------------------------------------------------------------------------------\n");
	printf("|%-10s%-10s%-25s%-17s%-17s%-14s%-14s%-15s|\n","Book ID", "User ID", "User Name", "Issue Date", "Due Date", "Returned date", "fine amount", "Status");
	printf("----------------------------------------------------------------------------------------------------------------------------\n");

	while(ptr!=NULL)
	{
		printf("|%5d%5s%5d%5s%-25s%-17s%-17s%-14s%7d%7s%-15s|\n", ptr->book_id, "", ptr->user_id, "",ptr->user_name, ptr->issue_date, ptr->due_date, ptr->ret_date, ptr->fine, "", ptr->status);

		printf("----------------------------------------------------------------------------------------------------------------------------\n");

		ptr=ptr->next;

	}




}
