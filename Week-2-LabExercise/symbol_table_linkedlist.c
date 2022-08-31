#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
int size = 0;

struct symbtab
{
    char label[10];
    int addr;
    char type[100];
    struct symbtab *next;
} * first, *last;

int search(char lab[])
{
    int i, flag = 0;
    struct symbtab *temp;
    temp = first;
    for (i = 0; i < size; i++)
    {
        if (strcmp(temp->label, lab) == 0)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    return flag;
}
void printSearch(char lab[])
{
    int i, flag = 0;
    struct symbtab *temp;
    temp = first;
    for (i = 0; i < size; i++)
    {
        if (strcmp(temp->label, lab) == 0)
        {
            printf("Address\tType\n");
            printf("%d\t%s",temp->addr,temp->type);
            flag = 1;
            break;
        }
        temp = temp->next;
    }
}
void insert()
{
    int n,inp;
    char l[100],t[100];
    printf("Input the number of symbols to input : ");
    scanf("%d",&inp);
    for(int i=0;i<inp;i++)
    {
      printf("\nSymbol %d:",i+1);
      printf("\nInput type: ");
      scanf("%s",t);
      printf("\nInput label: ");
      scanf("%s", l);
      n = search(l);
      if (n == 1)
        printf("The label is already in the symbol table. Duplicate cant be inserted\n");
      else
      {
        struct symbtab *p;
        p = malloc(sizeof(struct symbtab));
        strcpy(p->label, l);
        strcpy(p->type,t);
        printf("Input address: ");
        scanf("%d", &p->addr);
        p->next = NULL;
        if (size == 0)
        {
            first = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        size++;
      }
    }
}

void display()
{
    int i;
    struct symbtab *p;
    p = first;
    printf("\nType\tAddress\tLabel\n");
    for (i = 0; i < size; i++)
    {
        printf("\n%s\t%d\t%s\n", p->type, p->addr, p->label);
        p = p->next;
    }
}

void main()
{
    int option;
    int y;
    char la[10];
    do
    {
        printf("\nSYMBOL TABLE (Linked List) \n");
        printf("1.INSERT\n");
        printf("2.DISPLAY\n");
        printf("3.SEARCH\n");
        printf("4.END\n");
        printf("\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            printf("\nSuccessfully inserted\n");
            break;
        case 2:
            display();
            break;
        case 3:
            printf("Enter the label to be searched: ");
            scanf("%s", la);
            printSearch(la);
            break;
        case 4:
            exit(0);
        }
    } while (option < 6);
}
