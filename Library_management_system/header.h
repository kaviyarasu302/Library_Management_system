#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
extern int id;
extern int node_count;
extern int issue_flag;
extern int user_node_count;



typedef struct library{

	char book_name[100];
	char book_author_name[100];
	int book_id;
	int book_count;
	struct library *next;
} LIB;
typedef struct user{

	char user_name[100];
	int user_id;
	int book_id;
	char issue_date[20];
	char due_date[20];
	char ret_date[20];
	int fine;
	char status[20];
	struct user *next;

}usr;

extern LIB *hptr;
extern usr *hdptr;


void book_add(LIB **);
void update_book_details(LIB **);
void remove_book(LIB**);
LIB *search_book(LIB *,int,int);
void view_all_books(LIB *);
void issue_book(usr **,LIB **);
void return_book(usr **);
void list_issued_books(usr *);
void save(LIB *,usr *);
void lib_exit(void);
void load_file(LIB **,usr **);
int password(int);
