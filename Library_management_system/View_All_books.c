#include"header.h"
void view_all_books(LIB *ptr){
	    
	    if(ptr==NULL){
	         printf("There is no book available!!\n");
		 return;
	    }

            printf("---------------------------------------------------------------------------\n");
	    printf("|%-25s%-25s%-13s%-7s|\n","Book name","Author name","Book id","Book count" );
	    printf("---------------------------------------------------------------------------\n");
	    while(ptr!=NULL){
	    
		    printf("|%-25s%-28s%-13d%-7d|\n",ptr->book_name,ptr->book_author_name,ptr->book_id,ptr->book_count);
		    ptr=ptr->next;
	    }
	      printf("---------------------------------------------------------------------------\n");
}
