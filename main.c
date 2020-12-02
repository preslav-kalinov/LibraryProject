#include "main.h"

int main()
{
    char option1[10];
    sLilb library;
    sBooks kniga;

    printf("\tLIBRARY PROJECT\n");

    printf("Enter how many books you want: ");
    scanf("%d", &(library.booksNum));
    library.arrLib = (sBooks*)malloc(library.booksNum * sizeof(sBooks));

    //readFileBin(&library);

        do
        {

            printf("\n\n\t\t1. Add book\n");
            printf("\t\t2. Show books\n");
            printf("\t\t3. Remove book\n");
            printf("\t\t4. Edit book\n");
            printf("\t\t5. Info for a book\n");
            printf("\t\t6. Sort books\n");
            printf("\t\t7. Exit the library\n");

             gets(option1);

            if(strcmp(option1, "1") == 0)
            {
                printf("\n");
                addBook(&library, kniga);
            }
            else if(strcmp(option1, "2") == 0)
            {
                output(&library);
            }
            else if(strcmp(option1, "3") == 0)
            {
                removeBook(&library);
            }
            else if(strcmp(option1, "4") == 0)
            {
               editBooks(&library, kniga);

            }

            else if(strcmp(option1, "5") == 0)
            {
                infoForBook(&library);
            }

            else if(strcmp(option1, "6") == 0)
            {
                printf("In which criteria you want the books to be sorted?\n");
                printf("1. By price\n");
                printf("2. By title\n");
                printf("3. By genre\n");
                printf("4. By author\n");
                gets(option1);

                if(strcmp(option1, "1")==0)
                {
                    printf("|1. Sort|");
                    sortPrice(&library);
                    output(&library);
                }
                else if(strcmp(option1, "2")==0)
                {
                    printf("|2. Sort|");
                    sortTitle(&library);
                    output(&library);
                }
                else if(strcmp(option1, "3")==0)
                {
                    printf("|3. Sort|");
                    sortGenre(&library);
                    output(&library);
                }
                 else if(strcmp(option1, "4")==0)
                 {
                     printf("|4. Sort|");
                     sortAuthor(&library);
                     output(&library);
                 }
            }
        }
        while(strcmp(option1, "7") != 0);
    printf("Hello world!\n");
    return 0;

    }



void addBook (sLilb *biblioteka, sBooks kniga1)
{
    int i=0;
    biblioteka->arrLib = realloc(biblioteka->arrLib, biblioteka->booksNum * sizeof(sBooks));

   for(i=0;i<biblioteka->booksNum;i++)
        {
            printf("\t=:Book %d Detail:=\n",i+1);

            fflush(stdin);
            printf("\nEnter the Book Name:");
            fgets(biblioteka->arrLib[i].title, sizeof(kniga1.title), stdin);

            printf("Enter the Genre of Book:\n");
            //scanf("%s",b[i].genre);
            fgets(biblioteka->arrLib[i].genre, sizeof(kniga1.genre), stdin);

            printf("Enter the Author of Book:\n");
            fgets(biblioteka->arrLib[i].author, sizeof(kniga1.author), stdin);
            //scanf("%s",b[i].author);

            printf("Enter the Pages of Book:\n");
            scanf("%d",&(biblioteka->arrLib[i].pagesNum));

            printf("Enter the Price of Book:\n");
            scanf("%f",&(biblioteka->arrLib[i].price));
        }
}

void output(sLilb *biblioteka)
{
    int i=0,t=1;

    for(i=0;i<biblioteka->booksNum;i++)
        {
            printf("\n");
            printf("Book No.%d\n",t);
            printf("\t\tBook %d Name is:",t);
            puts(biblioteka->arrLib[i].title);
            printf("\t\tBook %d Genre is:",t);
            puts(biblioteka->arrLib[i].genre);
            printf("\t\tBook %d Author is:",t);
            puts(biblioteka->arrLib[i].author);
            printf("\t\tBook %d Pages is: %d\n\n ",t,biblioteka->arrLib[i].pagesNum);
            printf("\t\tBook %d Price is: %0.2f\n ",t,biblioteka->arrLib[i].price);
            t++;
        }
}

void editBooks(sLilb *biblioteka, sBooks kniga1)
{
    char edit[32];
    int i=0;
    printf("Enter the book you want to edit: ");
    fgets(edit, sizeof(edit), stdin);

    for(i=0;i<biblioteka->booksNum;i++)
    {
        if(strcmp(edit, biblioteka->arrLib[i].title)==0)
        {
            printf("New name of the book: ");
            fgets(biblioteka->arrLib[i].title, sizeof(kniga1.title), stdin);
            printf("New genre of the book: ");
            fgets(biblioteka->arrLib[i].genre, sizeof(kniga1.genre), stdin);
            printf("New author of the book: ");
            fgets(biblioteka->arrLib[i].author, sizeof(kniga1.author), stdin);
            printf("New page count of the book: ");
            scanf("%d", &(biblioteka->arrLib[i].pagesNum));
            printf("New price of the book: ");
            scanf("%f", &(biblioteka->arrLib[i].price));
        }
        else if(i==biblioteka->booksNum)
        {
            printf("|ERROR| No book found!");
            break;
        }
    }
}

void infoForBook(sLilb *biblioteka)
{
    char info[32];
    int i=0;
    printf("Enter the book you want to recieve info for: ");
    fgets(info, sizeof(info), stdin);

    for(i=0;i<biblioteka->booksNum;i++)
    {
        if(strcmp(info, biblioteka->arrLib[i].title)==0)
        {
            printf("Info for Book\n");
            printf("\t\t|INFO|Book Name is: ");
            puts(biblioteka->arrLib[i].title);
            printf("\t\t|INFO|Book Genre is: ");
            puts(biblioteka->arrLib[i].genre);
            printf("\t\t|INFOBook Author is: ");
            puts(biblioteka->arrLib[i].author);
            printf("\t\t|INFO|Book Pages is: %d\n\n ",biblioteka->arrLib[i].pagesNum);
            printf("\t\t|INFO|Book Price is: %0.2f\n ",biblioteka->arrLib[i].price);
        }
        else if(i==biblioteka->booksNum)
        {
            printf("|ERROR| No book found!");
            break;
        }
    }
}

void sortPrice(sLilb *biblioteka)
{
    int i, j;
    sBooks temp = *biblioteka->arrLib;
    for(i=0;i<biblioteka->booksNum;i++)
    {
        for(j=i+1;j<(biblioteka->booksNum+1);j++)
        {
            if(biblioteka->arrLib[i].price > biblioteka->arrLib[j].price)
            {
                temp=biblioteka->arrLib[j];
                biblioteka->arrLib[j]=biblioteka->arrLib[i];
                biblioteka->arrLib[i]=temp;
            }
        }
    }
}

void sortTitle(sLilb *biblioteka)
{
    int i, j;
    sBooks temp = *biblioteka->arrLib;
    for(i=0;i<biblioteka->booksNum;i++)
    {
        for(j=i+1;j<(biblioteka->booksNum+1);j++)
        {
            if(biblioteka->arrLib[i].price > biblioteka->arrLib[j].price)
            {
                temp=biblioteka->arrLib[j];
                biblioteka->arrLib[j]=biblioteka->arrLib[i];
                biblioteka->arrLib[i]=temp;
            }
        }
    }
}

void sortAuthor(sLilb *biblioteka)
{
    int i,j;
    sBooks temp = *biblioteka->arrLib;
    for(i=0;i<biblioteka->booksNum;i++)
    {
        for(j=i+1;j<(biblioteka->booksNum);j++)
        {
            if(strcmp(biblioteka->arrLib[i].author, biblioteka->arrLib[j].author)>0)
            {
                temp=biblioteka->arrLib[j];
                biblioteka->arrLib[j]=biblioteka->arrLib[i];
                biblioteka->arrLib[i]=temp;
            }
        }
    }
}

void sortGenre(sLilb *biblioteka)
{
    int i,j;
    sBooks temp = *biblioteka->arrLib;
    for(i=0;i<biblioteka->booksNum;i++)
    {
        for(j=i+1;j<(biblioteka->booksNum);j++)
        {
            if(strcmp(biblioteka->arrLib[i].genre, biblioteka->arrLib[j].genre)>0)
            {
                temp=biblioteka->arrLib[j];
                biblioteka->arrLib[j]=biblioteka->arrLib[i];
                biblioteka->arrLib[i]=temp;
            }
        }
    }
}

void removeBook(sLilb *biblioteka)
{
    char remove[32];
    int i, j;
    printf("Enter the book you want to remove: ");
    fgets(remove, sizeof(remove), stdin);
        for(i=0;i<biblioteka->booksNum;i++)
    {
        if(strcmp(remove, biblioteka->arrLib[i].title)==0)
        {
            for(j=i; j<biblioteka->booksNum-1; j++)
            {
                biblioteka->arrLib[j]=biblioteka->arrLib[j+1];
            }
            printf("|INFO| Book deleted!");
               biblioteka->booksNum--;
            //biblioteka->arrLib = realloc(biblioteka->arrLib, biblioteka->booksNum* sizeof(sBooks));
        }
    }
}

void readFileBin(sLilb *biblioteka)
{
    int i;
    FILE *fp;

    fp = fopen("LibraryFile.bin", "rb");
    if(fp==NULL)
    {
     printf("Not existing file!");
     exit(1);
    }

     for(i=0;i<biblioteka->booksNum;i++)
    {
        if(feof(fp))
        {
            break;
        }
        fread(biblioteka->arrLib[i].title,sizeof(char),32,fp);
        fread(biblioteka->arrLib[i].genre,sizeof(char),32,fp);
        fread(biblioteka->arrLib[i].author,sizeof(char),32,fp);
        fread(&(biblioteka->arrLib[i].pagesNum),sizeof(int),1,fp);
        fread(&(biblioteka->arrLib[i].price),sizeof(float),1,fp);
        fclose(fp);
    }
}


