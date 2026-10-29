
#include"header.h"
int count;
void remove_book(LIB **ptr){

       char bookname[100];
       int id;       
	if((*ptr)==NULL){
	
		puts("There is no books to remove");
	} 
	char op;
	int n;
	do{

		puts("------------------------");
		printf("|1)Remove by book name|\n|2) Remove by book id  |\n|3) main menu          |\n");
		puts("------------------------");
		puts("Enter your choice:\n");
		scanf("%d",&n);
		switch(n){
		
			case 1 :
			         if(*ptr==NULL){
				 
					 puts("No books found to remove");
					 return;
				 }	
				 puts("Enter the book name to remove:");
				 scanf("%s",bookname);
				 LIB *temp=(*ptr),*prv;
				 while(temp!=NULL){
				       if((strcmp(temp->book_name,bookname))==0){
				       
					       if(temp==NULL){
					       
						       (*ptr)=temp->next;
					       }
					       else
						       prv->next=temp->next;
					       free(temp);
					       count--;

				       }
				       prv=temp;
				       temp=temp->next;
				 }
				 puts("Removed successfully");
				 break;
			case 2: 
				if(*ptr==NULL){
				
					puts("No books found to remove");
					return;
				}
				puts("Enter the book id to remove");
				scanf("%d",&id);
				LIB *temp1=(*ptr),*prv1;
				while(temp1!=NULL){
				
					if(temp1->book_id==id){
					
						if(temp1==NULL)
							(*ptr)=temp1->next;
						else
							prv1->next=temp1->next;
						free(temp1);
					
						count--;
					}
					prv1=temp1;
					temp1=temp1->next;
				}
				puts("Removed successfully");
				break;

			case 3: return;
		        
		        default: puts("invalid choice");
				 
		}
		puts("do you want to remove again(y/n):");
		scanf(" %c",&op);


	}while(op=='y');
}
