#include"header.h"



void load_file(LIB **ptr,usr **temp)
{
	LIB lb;
	if((*ptr)!=NULL)
	{
		return;
	}

	int c=0;
	FILE *fp=fopen("books_details.dat","r");

	char str[500];
	fgets(str,500,fp);

	while(fscanf(fp,"%s%s%d%d",lb.book_name,lb.book_author_name,&lb.book_id,&lb.book_count)==4)
	{
		c++;
	}

	rewind(fp);
	fgets(str,500,fp);

	if(c>0)
	{
		for(int i=0;i<c;i++)
		{
			LIB *new =(LIB *)malloc(sizeof(LIB));

			fscanf(fp,"%s%s%d%d",new->book_name,new->book_author_name,&new->book_id,&new->book_count);

			if((*ptr)==NULL)
			{
				new->next=(*ptr);
				(*ptr)=new;
			}
			else
			{
				LIB *last=(*ptr);
				while(last->next != NULL)
				{
					last=last->next;

				}
				new->next=last->next;
				last->next=new;
			}

		}

		node_count=c;
		id=c;
		fclose(fp);



	}

	
	usr us;
	
	  c=0;
	 fp=fopen("issue_record.dat","r");

	fgets(str,500,fp);

	while (fscanf(fp, "%d%d%s%s%s%s%d%s",&us.book_id,&us.user_id,us.user_name,us.issue_date,us.due_date,us.ret_date,&us.fine,us.status) == 8)	    {
		c++;
	}

	rewind(fp);
	fgets(str,500,fp);

	
	if(c>0)

	{
		for(int i=0;i<c;i++)
		{
			usr *neww =(usr *)malloc(sizeof(usr));

			fscanf(fp,"%d%d%s%s%s%s%d%s",&neww->book_id,&neww->user_id,neww->user_name,neww->issue_date,neww->due_date,neww->ret_date,&neww->fine,neww->status);		
			if((*temp)==NULL)
			{
				neww->next=(*temp);
				(*temp)=neww;
			}
			else
			{
				usr *lastt=(*temp);
				while(lastt->next != NULL)
				{
					lastt=lastt->next;

				}
				neww->next=lastt->next;
				lastt->next=neww;
			}

		}
	}
	fclose(fp);



	

}
