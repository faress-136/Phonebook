#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} dt;
typedef struct
{
    char fname[30];
    char lname[30];
    dt  date;
    char number[20];
    char mail[50];
    char address[100];
    
} info ;
info p[50];
int count =0;
void add();
void print();
void load();
void save();
void sortlname();
void datesort();
void exi();
void search();
void delet();
void searchfname();
void searchlname();
void searchnum();
void searchaddress();
void modify();
void verifyname();
void verifynum();
char searchfn[20];
char searchln[20];
int sor;
int checkname=1;
int checknumber=1;
int day;
int month;
int year;
void dateverfication();
#endif // GLOBALS_H_INCLUDED

