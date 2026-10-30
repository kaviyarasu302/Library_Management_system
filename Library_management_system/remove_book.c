#include "header.h"

int count;

void remove_book(LIB **ptr)
{
    char bookname[100];
    int id;

    if ((*ptr) == NULL)
    {
        puts("There is no books to remove");
        return;
    }

    char op;
    int n;

    do
    {
        puts("------------------------");
        printf("|1) Remove by book name|\n|2) Remove by book id   |\n|3) main menu           |\n");
        puts("------------------------");

        puts("Enter your choice:");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
            {
                if (*ptr == NULL)
                {
                    puts("No books found to remove");
                    return;
                }

                puts("Enter the book name to remove:");
                scanf("%s", bookname);

                LIB *temp = *ptr, *prv = NULL;
                int found = 0, same = 0;

                while (temp != NULL)
                {
                    if (strcmp(temp->book_name, bookname) == 0)
                        same++;

                    temp = temp->next;
                }

                if (same == 0)
                {
                    puts("Book not found");
                    break;
                }

                if (same > 1)
                {
                    puts("Same book name found more than once");
                    puts("Enter the book id to remove:");
                    scanf("%d", &id);

                    temp = *ptr;
                    prv = NULL;

                    while (temp != NULL)
                    {
                        if (strcmp(temp->book_name, bookname) == 0 && temp->book_id == id)
                        {
                            if (prv == NULL)
                                *ptr = temp->next;
                            else
                                prv->next = temp->next;

                            free(temp);
                            count--;
                            found = 1;
                            break;
                        }

                        prv = temp;
                        temp = temp->next;
                    }

                    if (found)
                        puts("Removed successfully");
                    else
                        puts("Book name and id not found");
                }
                else
                {
                    temp = *ptr;
                    prv = NULL;

                    while (temp != NULL)
                    {
                        if (strcmp(temp->book_name, bookname) == 0)
                        {
                            if (prv == NULL)
                                *ptr = temp->next;
                            else
                                prv->next = temp->next;

                            free(temp);
                            count--;
                            found = 1;
                            break;
                        }

                        prv = temp;
                        temp = temp->next;
                    }

                    if (found)
                        puts("Removed successfully");
                }

                break;
            }

            case 2:
            {
                if (*ptr == NULL)
                {
                    puts("No books found to remove");
                    return;
                }

                puts("Enter the book id to remove:");
                scanf("%d", &id);

                LIB *temp1 = *ptr, *prv1 = NULL;
                int found = 0;

                while (temp1 != NULL)
                {
                    if (temp1->book_id == id)
                    {
                        if (prv1 == NULL)
                            *ptr = temp1->next;
                        else
                            prv1->next = temp1->next;

                        free(temp1);
                        count--;
                        found = 1;
                        break;
                    }

                    prv1 = temp1;
                    temp1 = temp1->next;
                }

                if (found)
                    puts("Removed successfully");
                else
                    puts("Book id not found");

                break;
            }

            case 3:
                return;

            default:
                puts("Invalid choice");
        }

        puts("Do you want to remove again (y/n):");
        scanf(" %c", &op);

    } while (op == 'y' || op == 'Y');
}


