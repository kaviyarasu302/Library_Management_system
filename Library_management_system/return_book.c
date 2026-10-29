#include"header.h"

void printt(usr *ptr,int search,int i )
{
	int flag=0;

			 while(ptr!=NULL)
			 {
				 
				 if ((i == 1 && ptr->book_id == search) || (i == 2 && ptr->user_id == search))

				 {
					if(flag==0)
					{

						printf("----------------------------------------------------------------------------------------------------------------------------\n");
						printf("|%-10s%-10s%-25s%-17s%-17s%-14s%-14s%-15s|\n","Book ID", "User ID", "User Name", "Issue Date", "Due Date", "Returned date", "fine amount", "Status");
						printf("----------------------------------------------------------------------------------------------------------------------------\n");
						flag=1;
					}	

					
					printf("|%5d%5s%5d%5s%-25s%-17s%-17s%-14s%7d%7s%-15s|\n", ptr->book_id, "", ptr->user_id, "",ptr->user_name, ptr->issue_date, ptr->due_date, ptr->ret_date, ptr->fine, "", ptr->status);

					printf("----------------------------------------------------------------------------------------------------------------------------\n");
				 }

				 ptr=ptr->next;
			 }
			 
}




void return_book(usr **ptr)
{
	if((*ptr)==NULL)

	{
		puts("NO BOOK IS ISSUED TO RETURN");
		return;
	}

	SEARCH:
	puts("----------------------");
	puts("|1) Search By BOOK ID|");
	puts("|2) Search By USER ID|");
	puts("----------------------");

	int op;
	puts("Enter Your Choice:");
	scanf("%d",&op);
	int search;

	switch(op)
	{
		case 1 : puts("Enter the BOOK ID:");
			 scanf("%d",&search);

			 printt(hdptr,search,1);
			 break;

		case 2 : puts("Enter the USER ID:");
			 scanf("%d",&search);

			 printt(hdptr,search,2);
			 break;
		
		default : puts("INVALID OPTION ENTER CORRECTLY!!!");\
			  goto SEARCH;


	}

	puts("Enter the USER ID and BOOK_ID to Confirm return:");
	scanf("%d%d",&search,&op);

	LIB *temp=hptr;
	usr *temp1=(*ptr);
	int data_ava_flag=0;
	int f_flag=0,fine=0;
	
	while(temp1!=NULL)
	{
		
		if((temp1->user_id==search)&&((temp1->book_id)==op))
		{

			if (strcmp(temp1->status, "R") == 0)
			{
    				puts("BOOK ALREADY RETURNED");
    				return;
			}
		

    			time_t t1 = time(NULL);
    			struct tm *ret_date = localtime(&t1);


			int day,month,year;
			
			sscanf(temp1->due_date,"%d-%d-%d",&day,&month,&year);

			struct tm due={0};

			due.tm_mday=day;
			due.tm_mon=month-1;
			due.tm_year=year-1900;

			time_t due_time = mktime(&due);

			double diff = difftime(t1, due_time);

			int days=(diff/(60*60*24));


			if(days>0)
			{
				fine=days*5;
				printf("over due:%d days\n fine: %d\n",days,fine);
			}

			if(fine>0)
			{
				FINE:
				puts("WHAT IS FINE STATUS 1)PAID 2)NOT PAID?");
				int fs;
				scanf("%d",&fs);

				if(fs<1||fs>2)
				{
					puts("INVALID CHOICE ENTER AGAIN");
					goto FINE;
				}

				if(fs==1)
				{
					f_flag=1;		
				
				}
				else
				{
					puts("FINE NOT PAID & BOOK NOT RETURNED!!!");
					return;

				}


			}


			if(fine==0||f_flag==1)
			{
				

				char rd[20];

   				sprintf(rd,"%d-%d-%d", ret_date->tm_mday, ret_date->tm_mon + 1, ret_date->tm_year + 1900);
				strcpy(temp1->ret_date,rd);
				strcpy(temp1->status,"R");
				temp1->fine=fine;


				while(temp!=NULL)
				{
					if(temp->book_id == op)
					{
						temp->book_count++;
						break;
					}
					temp=temp->next;
				}

				data_ava_flag=1;
				break;
				

			}

	



		}
		temp1=temp1->next;
	}


	if(data_ava_flag==1)
	puts("BOOK RETURNED SUCCESSFULLY!!!");
	else
		puts("GIVE USER ID AND BOOK ID IS NOT AVAILABLE IN THE LIST");





}
