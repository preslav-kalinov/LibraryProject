#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define SIZE 100

typedef struct books
    {
       char title [32];
       char genre [32];
       char author [32];
       int pagesNum;
       float price;
    }sBooks;

    typedef struct library
    {
        char libName [32];
         sBooks *arrLib;
         int booksNum;
    }sLilb;

extern void addBook (sLilb *biblioteka, sBooks kniga1);
extern void output(sLilb *biblioteka);
extern void editBooks(sLilb *biblioteka, sBooks kniga1);
extern void infoForBook(sLilb *biblioteka);
extern void sortPrice(sLilb *biblioteka);
extern void sortTitle(sLilb *biblioteka);
extern void sortAuthor(sLilb *biblioteka);
extern void sortGenre(sLilb *biblioteka);
extern void removeBook(sLilb *biblioteka);
extern void readFileBin(sLilb *biblioteka);

#endif // MAIN_H_INCLUDED
