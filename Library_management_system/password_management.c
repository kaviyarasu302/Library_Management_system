#include"header.h"

int flag=0;
char get[20];

char * change_pass(char *get)
{
	REPEAT:
	system("clear");
	puts("--------------------");
	puts("| 1)Change User ID |");
	puts("| 2)Change Password|");
	puts("--------------------");

	int n;
	puts("Enter Your Choice");
	scanf("%d",&n);

	switch(n)
	{
		case 1 : puts("Enter new User ID:");
			 scanf("%s",get);
			 flag=1;
			 break;
		
		case 2 : 
			 PASS:
			 system("clear");
			 puts("Enter the new password:");
			 char pass[20];
			 scanf("%s",pass);
      	
    			 puts("Confirm your password:");
			 char con_pass[20];
			 scanf("%s",con_pass);

			 if(strcmp(pass,con_pass)!=0)
			 {
			 	puts("PASSWORD MISMATCH! PLEASE TRY AGAIN");
				sleep(2);
				goto PASS;
			 }
			 else
			 {
				 flag=2;
				 strcpy(get,pass);
				 break;
                         }

		default : puts("INVALID OPTION");
			  sleep(2); 
			  goto REPEAT;
			 

	}

}

int password(int c)
{
	int try=1;
	char str[100],org_user[20],org_pass[20];
	FILE *fp=fopen("password","r");

	if(fp==NULL)
	{
		puts("CREATE USER ID:");
		char new_user[20];
		scanf("%s",new_user);
		PASS:
		system("clear");
		puts("CREATE A PASSWORD:");
		char new_pass[20];
		scanf("%s",new_pass);
		puts("CONFIRM YOUR PASSWORD:");
		char con_pass[20];
		scanf("%s",con_pass);

		if(strcmp(new_pass,con_pass)!=0)
		{
			puts("PASSWORD MISMATCH! PLEASE TRY AGAIN");
			sleep(2);
			goto PASS;
		}
		else
		{
			fp=fopen("password","w");
			fprintf(fp,"%-25s%-25s\n","USER ID","PASSWORD");
			fprintf(fp,"%-25s%-25s\n",new_user,new_pass);
			fclose(fp);
			puts("USER ID AND PASSWORD CREATED SUCCESSFULLY");

		}


	}

	fp=fopen("password","r");
	
	fgets(str,100,fp);

	fscanf(fp,"%s%s",org_user,org_pass);

	LOGIN:
	system("clear");
	puts("ENTER THE USER ID:");
	char user[20];
	scanf("%s",user);
	puts("ENTER YOUR PASSWORD:");
	char pass[20];
	scanf("%s",pass);

	if((strcmp(org_user,user)==0) && (strcmp(org_pass,pass)==0))
	{
		fclose(fp);
		if(c==0)
		puts("LOGGED IN SUCCESSFULLY");
		if(c==1)
		{	
			change_pass(get);
			if(flag==1)
			{
				fp=fopen("password","w");
					
				fprintf(fp,"%-25s%-25s\n","USER ID","PASSWORD");
				fprintf(fp,"%-25s%-25s\n",get,org_pass);

				puts("USER ID CHANGED SUCCESSFULLY");

				fclose(fp);

			}

			
			if(flag==2)
			{
				fp=fopen("password","w");
					
				fprintf(fp,"%-25s%-25s\n","USER ID","PASSWORD");
				fprintf(fp,"%-25s%-25s\n",org_user,get);

				puts("PASSWORD CHANGED SUCCESSFULLY");
				fclose(fp);

			}



		}
		sleep(2);
		system("clear");
		return 1;
			
	}
	else
	{
		puts("INVALID USER ID PASSWORD");
		try++;
		sleep(2);
		if(try<=3)
		goto LOGIN;
		else
		{
			puts("ATTEMPT EXCEEDED");
			fclose(fp);
			return 0;
		}


	}
	
	
	
	


}

