#include"header.h"
int id=0;
void book_add(LIB **hptr){
	
	char op;
  	do{    
	LIB *temp=(*hptr);
         char bookname[100],author[100];
	 int c;
	 AGAIN:
	 printf("Enter the book name, author name& book count:\n");
	 scanf("%s %s %d",bookname,author,&c);
	 if(c<0)
	 {
		puts("INVALID BOOK COUNT!!!");
		printf("AGAIN ENTER CORRECTLY\n");
		goto AGAIN;
	 }

	 while(temp!=NULL){
	 
		 if((strcmp(temp->book_name,bookname))==0){
			 if((strcmp(temp->book_author_name,author))==0){
			       printf("This book is already available if you want to modify you can update book deatils\n");
			       return;
			 }

		 }
		 temp=temp->next;
	 }
       
	       
	LIB *new=(LIB*)malloc(sizeof(LIB));

       strcpy(new->book_name,bookname);
	strcpy(new->book_author_name,author);
	new->book_count=c;
	new->book_id = ++id;
	new->next=NULL;

	if(*hptr==NULL){
	
		(*hptr)=new;
	}

	else{
	
		LIB *last=(*hptr);

		while(last->next!=NULL)

			last=last->next;

		last->next=new;
	}
        node_count++;	

	printf("do you want to add another book (y/n):\n");

	scanf(" %c",&op);

       } while(op=='y');

}
