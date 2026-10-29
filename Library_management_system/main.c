#include"header.h"
int node_count=0;
LIB *hptr=NULL;
usr *hdptr=NULL;
int issue_flag=0;
int user_node_count=0;

int main()
{
	system("clear");
	int ret=password(0);
		
	if(ret!=1)
	{
		return 0;
	}
	int p;
	system("clear");
	load_file(&hptr,&hdptr);
	do{
	puts("+---------------------------------------------------+");
	puts("|		     Book Management Menu           |");
	puts("|---------------------------------------------------|");
	puts("|	1. Add New Book                             |");
	puts("|	2. Update Book Details                      |");	
	puts("|	3. Remove Book                              |");
	puts("|	4. Search Book                              |");
	puts("|	5. View All Books                           |");
	puts("|	6. Issue Book                               |");
	puts("|	7. Return Book                              |");
	puts("|	8. List Issued Books                        |");
	puts("|	9. Save                                     |");
	puts("|      10. Exit                                     |");
	puts("|      11. User name or password change             |");
	puts("+---------------------------------------------------+");

	
	puts("Enter your choice:");
        if (scanf("%d", &p) != 1)
        {
           printf("Invalid input! Please enter a number.\n");

           while (getchar() != '\n');

           continue;
        }


	switch(p){
	
	        case 1: book_add(&hptr); break;

		case 2: update_book_details(&hptr); break;

		case 3: remove_book(&hptr); break;
		 
		case 4: search_book(hptr,-1,-1); break;
	
	        case 5: view_all_books(hptr); break;

	        case 6: issue_book(&hdptr,&hptr) ; break;
	
	        case 7: return_book(&hdptr); break;

	        case 8: list_issued_books(hdptr); break;

	        case 9: save(hptr,hdptr); break;

	        case 10: lib_exit(); return 0;

		case 11: password(1);break;

	        default: printf(" Inavlid option\n");
	}

        } while(p!=10);

}

