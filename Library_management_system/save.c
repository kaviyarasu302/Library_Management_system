#include"header.h"


void save(LIB *ptr,usr *temp)
{
    if(ptr==NULL)
    {
        puts("NO DATA AVAILABLE TO SAVE!!!");
        return;
    }

    FILE *fp=fopen("books_details.dat","w");

    fprintf(fp,"%-25s%-25s%-13s%-7s\n","Book name","Author name","Book id","Book count" );

    while(ptr!=NULL)
    {
         fprintf(fp,"%-25s%-28s%-13d%-7d\n",ptr->book_name,ptr->book_author_name,ptr->book_id,ptr->book_count);
         ptr=ptr->next;
     }

    fclose(fp);
    puts("BOOKS DETAILS SAVED SUCESSFULLY IN books_details.dat FILE");
    
    if(temp!=NULL)
    {

        FILE *fp=fopen("issue_record.dat","w");

        fprintf(fp,"%-10s%-10s%-25s%-17s%-17s%-14s%-14s%-15s\n","Book ID", "User ID", "User Name", "Issue Date", "Due Date", "Return date", "fine amount", "Status");        
	while(temp!=NULL)
        {

            fprintf(fp,"%5d%5s%5d%5s%-25s%-17s%-17s%-14s%7d%7s%-15s\n", temp->book_id, "", temp->user_id, "",temp->user_name, temp->issue_date, temp->due_date, temp->ret_date, temp->fine, "", temp->status);
            temp=temp->next;    
        }

        fclose(fp);
        puts("ISSUE RECORDS SAVED SUCCESSFULLY IN issue_record.dat FILE");
    
    }

}



