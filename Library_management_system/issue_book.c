#include"header.h"

void issue_book(usr **ptr,LIB **pptr)
{
	search_book(hptr,-1,4);

	if(issue_flag==0)
	{

		usr *new=(usr*)malloc(sizeof(usr));


		puts("Enter the Book ID:");
		scanf("%d",&new->book_id);
		
		LIB *temp=(*pptr);
		
		while(temp!=NULL)
		{
			if(temp->book_id==new->book_id)
			{
				if(temp->book_count==0)
				{
					puts("THE BOOK IS CURRENTLY NOT AVAILABLE TO ISSUE");
					return;
				}
			}
			temp=temp->next;
		}
		


		puts("Enter the User Name and ID:");
		scanf("%s%d",new->user_name,&new->user_id);

    		time_t t = time(NULL);
    		struct tm *date = localtime(&t);

		char temp1[20];

   		sprintf(temp1,"%d-%d-%d", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
		strcpy(new->issue_date,temp1);

    		date->tm_mday += 7;
  	        mktime(date);

   		sprintf(temp1,"%d-%d-%d", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
	      	strcpy(new->due_date,temp1);
		strcpy(new->ret_date,"-");
		new->fine=0;
		strcpy(new->status,"NR");	


		if((*ptr)==NULL)
		{
			new->next=(*ptr);
			(*ptr)=new;
		}

		else
		{
			usr *last=(*ptr);
			while(last->next!=NULL)
			{
				last=last->next;
			}
			
			new->next=last->next;
			last->next=new;

		}		
	
		user_node_count++;
		temp=(*pptr);

		while(temp->book_id!=new->book_id)
		{
			temp=temp->next;
		}
		temp->book_count--;

		

		printf("----------------------------------------------------------------------------------------------------------------------------\n");

		printf("|%-10s%-10s%-25s%-17s%-17s%-14s%-14s%-15s|\n","Book ID", "User ID", "User Name", "Issue Date", "Due Date", "Returned date", "fine amount", "Status");

		printf("----------------------------------------------------------------------------------------------------------------------------\n");

		printf("|%-10d%-10d%-25s%-17s%-17s%-14s%-14d%-15s|\n",new->book_id, new->user_id, new->user_name,new->issue_date, new->due_date, new->ret_date, new->fine, new->status);	
		printf("----------------------------------------------------------------------------------------------------------------------------\n");

	}


	
}
