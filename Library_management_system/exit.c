#include"header.h"

void lib_exit(void)
{
	puts("---------------------------");
	puts("| 1)Save and exit         |");
	puts("| 2)Exit without saving   |"); 
	puts("---------------------------");

	int op;
	puts("Enter your choice");
	scanf("%d",&op);


	switch(op)
	{
		case 1 : save(hptr,hdptr); break;


		case 2 : puts ("EXITED WITHOUT SAVING THE DETAILS !!!"); return;
	}
}
