#include "globals.h"

void menu()
{
    int x;
    printf("Menu:\n");
    printf(" 1.Add Contact \t\t 2.Search Contact \n 3.Sort Contacts \t 4.Modify Contact \n 5.Delete Contact \t 6.Save Contact \n 7.Print \t\t 8.Exit\n");
    printf("Choose a number from 1 to 8 :");
    scanf("%d",&x);
    
    switch(x)
    {
        case 1:
            add();
            count++;
            menu();
            break;
        case 2:
            search();
            menu();
            break;
        case 3:
            printf("1.Sort using last name:\t 2. Sort using birthday:\n");
            scanf("%d",&sor);
            switch(sor)
        {
            case 1:
                sortlname();
                break;
            case 2:
                datesort();
                break;
        }
            menu();
            break;
        case 4:
            modify();
            menu();
            break;
        case 5:
            delet();
            menu();
            break;
        case 6:
            save();
            menu();
            break;
        case 7:
            print();
            menu();
            break;
        case 8:
            exi();
            
            
    }
}
void add ()
{
    printf("enter first name :");
    scanf("%s",p[count].fname);
    
    verifyname(p[count].fname);
    while (checkname==0)
    {
        printf ("Not a valid name\n");
        printf("enter first name :");
        scanf("%s",p[count].fname);
        verifyname(p[count].fname);
    }
    
    printf("enter last name :");
    scanf("%s",p[count].lname);
    verifyname(p[count].lname);
    while (checkname==0)
    {
        printf ("Not a valid name\n");
        printf("enter last name :");
        scanf("%s",p[count].lname);
        verifyname(p[count].lname);
    }
    printf("enter phone number :");
    scanf("%s",p[count].number);
    verifynum(p[count].number);
    while (checknumber==0)
    {
        printf("enter number:");
        scanf("%s",p[count].number);
        verifynum(p[count].number);
    }
    printf("enter birthday :\n");
    printf("Day:\n");
    scanf("%d",&p[count].date.day);
    printf("Month:\n");
    scanf("%d",&p[count].date.month);
    printf("Year:\n");
    scanf("%d",&p[count].date.year);
    dateverfication();
    if (day==1 || month==1 || year==1){
        do{
            
            printf ("\nPlease enter date correctly");
            printf("\nDay:");
            scanf("%d",&p[count].date.day);
            printf("\nMonth:");
            scanf("%d",&p[count].date.month);
            printf("\nYear:");
            scanf("%d",&p[count].date.year);
            dateverfication();
        }
        while (day==1 || month==1 || year==1);}
    
    printf("enter email : ");
    scanf("%s",p[count].mail);
    
    printf("enter address :");
    getchar();
    gets(p[count].address);
    
}
void verifynum(char *y)
{
    int j=0;
    while (y[j]!='\0'){
        
        if(y[j]=='0'|| y[j]=='1'|| y[j]=='2'||
           y[j]=='3'|| y[j]=='4'|| y[j]=='5'||
           y[j]=='6'|| y[j]=='7'|| y[j]=='8'|| y[j]=='9'||y[j]=='-'||y[j]=='+')
        {
            checknumber=1;
            j++;
        }
        else {
            printf ("Number cannot contain characters\n");
            checknumber=0;
            break;
        }
        
    }
    
}
void verifyname(char *y)
{
    int j=0;
    for(j=0; j<=strlen(y); j++)
    {
        if(y[j]=='0'|| y[j]=='1'|| y[j]=='2'||
           y[j]=='3'|| y[j]=='4'|| y[j]=='5'||
           y[j]=='6'|| y[j]=='7'|| y[j]=='8'|| y[j]=='9')
        {
            printf ("Name cannot contain numbers \n");
            checkname=0;
            break;
        }
        else
            checkname = 1;
    }
    
}

void dateverfication()
{
    
    day=0;
    month=0;
    year=0;
    if (p[count].date.year>=1900 && p[count].date.year<=2020){
        
        if (p[count].date.month>=1 && p[count].date.month<=12) {
            
            if ((p[count].date.day>=1 && p[count].date.day<=31) && (p[count].date.month==1 || p[count].date.month==3 || p[count].date.month==5 || p[count].date.month==7 || p[count].date.month==8 || p[count].date.month==10 || p[count].date.month==12))
            {
                day=0;
                month=0;
                year=0;
            }
            else if((p[count].date.day>=1 && p[count].date.day<=30) && (p[count].date.month==4 || p[count].date.month==6 || p[count].date.month==9 || p[count].date.month==11))
            {
                day=0;
                month=0;
                year=0;
            }
            
            else if((p[count].date.day>=1 && p[count].date.day<=28) && (p[count].date.month==2))
            {
                day=0;
                month=0;
                year=0;
            }
            
            
            else if(p[count].date.day==29 && p[count].date.month==2 && (p[count].date.year%400==0 ||(p[count].date.year%4==0 && p[count].date.year%100!=0)))
            {
                day=0;
                month=0;
                year=0;
                
            }
            
            else {
                
                day=1;//1=invalid
                printf ("\nDay is invalid");
                
            }
        }
        else
        {
            month=1;//invalid
            printf ("\nMonth is invalid");
            if ((p[count].date.day>=1 && p[count].date.day<=31) )
            {
                day=0;
                month=1;
                year=0;
            }
            else if(p[count].date.day>=1 && p[count].date.day<=30)
            {
                day=0;
                month=1;
                year=0;
            }
            
            else if((p[count].date.day>=1 && p[count].date.day<=28) )
            {
                day=0;
                month=1;
                year=0;
            }
            
            
            else if(p[count].date.day==29 && (p[count].date.year%400==0 ||(p[count].date.year%4==0 && p[count].date.year%100!=0)))
            {
                day=0;
                month=1;
                year=0;
                
            }
            
            else {
                
                day=1;//1=invalid
                printf ("\nDay is invalid");
                
            }
        }}
    
    else
    {
        year=1;//invalid
        printf ("\nYear is invalid");
        if (p[count].date.month>=1 && p[count].date.month<=12) {
            
            if ((p[count].date.day>=1 && p[count].date.day<=31) && (p[count].date.month==1 || p[count].date.month==3 || p[count].date.month==5 || p[count].date.month==7 || p[count].date.month==8 || p[count].date.month==10 || p[count].date.month==12))
            {
                day=0;
                month=0;
                year=1;
            }
            else if((p[count].date.day>=1 && p[count].date.day<=30) && (p[count].date.month==4 || p[count].date.month==6 || p[count].date.month==9 || p[count].date.month==11))
            {
                day=0;
                month=0;
                year=1;
            }
            
            else if((p[count].date.day>=1 && p[count].date.day<=28) && (p[count].date.month==2))
            {
                day=0;
                month=0;
                year=1;
            }
            
            
            else if(p[count].date.day==29 && p[count].date.month==2 && (p[count].date.year%400==0 ||(p[count].date.year%4==0 && p[count].date.year%100!=0)))
            {
                day=0;
                month=0;
                year=1;
                
            }
            
            else {
                
                day=1;//1=invalid
                printf ("\nDay is invalid");
                
            }
        }
        else
        {
            month=1;//invalid
            printf ("\nMonth is invalid");
            if ((p[count].date.day>=1 && p[count].date.day<=31))
            {
                day=0;
                month=1;
                year=1;
            }
            else if((p[count].date.day>=1 && p[count].date.day<=30) )
            {
                day=0;
                month=1;
                year=1;
            }
            
            else if((p[count].date.day>=1 && p[count].date.day<=28) )
            {
                day=0;
                month=1;
                year=1;
            }
            
            
            else if(p[count].date.day==29)
            {
                day=0;
                month=1;
                year=1;
                
            }
            
            else {
                
                day=1;//1=invalid
                printf ("\nDay is invalid");
                
            }
            
        }
    }
    
    
}

void load()
{
    FILE *fp;
    fp=fopen("/Users/faresmohamed/Downloads/Project\ v2/phonebook.txt","r");
    if (fp!=NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp,"%[^,],",p[count].fname);
            fscanf(fp,"%[^,],",p[count].lname);
            fscanf(fp,"%d-",&p[count].date.day);
            fscanf(fp,"%d-",&p[count].date.month);
            fscanf(fp,"%d,",&p[count].date.year);
            fscanf(fp,"%[^,],",p[count].address);
            fscanf(fp,"%[^,],",p[count].mail);
            fscanf(fp,"%[^\n]\n",p[count].number);
            count++;
        }
    }
    else
        printf("File is empty\n");
    fclose(fp);
}
void print()
{
    int i;
    for (i=0; i<count; i++)
    {
        printf("\nName:%s %s\n",p[i].fname, p[i].lname);
        
        printf("Phone:%s\n",p[i].number);
        
        printf("%d-%d-%d\n",p[i].date.day,p[i].date.month,p[i].date.year);
        
        printf("Email:%s\n",p[i].mail);
        
        printf("Address:%s\n\n",p[i].address);
        
        
        
        
    }
}

void search()
{
    printf("Search:\n 1.First Name \t 2.Last name \t 3.Number \t 4.Address\n");
    int cho;
    printf("Choose from 1 to 4:\n");
    scanf("%d",&cho);
    switch(cho)
    {
        case 1:
            searchfname();
            break;
        case 2:
            searchlname();
            break;
        case 3:
            searchnum();
            break;
        case 4:
            searchaddress();
            break;
    }
}
void searchfname()
{
    int i;
    int flag1=0;
    int r;
    printf("Search(First Name):\n");
    scanf("%s", searchfn);
    
    for(i=0; i<count; i++)
    {
        
        if( strcasecmp(p[i].fname,searchfn) == 0 )
        {
            
            flag1=1;
            r=i;
            printf("First name found!\n First Name: %s \nLast Name: %s \nAddress: %s \nEmail: %s \nPhone Number: %s \nBirthday: %d-%d-%d \n", p[r].fname,p[r].lname,p[r].address,p[r].mail,p[r].number, p[r].date.day, p[r].date.month, p[r].date.year );
            printf("\n\n");
        }
    }
    if(flag1==0)
        printf("First name not found!\n");
    
}
void searchlname()
{
    int i;
    int flag1=0;
    int r;
    printf("Search Last Name:\n");
    scanf("%s", searchln);
    
    for(i=0; i<count; i++)
    {
        
        if( strcasecmp(p[i].lname,searchln) == 0 )
        {
            
            flag1=1;
            r=i;
            printf("First Name: %s \nLast Name: %s \nAddress: %s \nEmail: %s \nPhone Number: %s \nBirthday: %d-%d-%d \n", p[r].fname,p[r].lname,p[r].address,p[r].mail,p[r].number, p[r].date.day, p[r].date.month, p[r].date.year );
            printf("\n\n");
        }
    }
    if(flag1==0)
        printf("Last name not found!\n");
    
}
void searchnum()
{
    int i;
    int flag1=0;
    int r;
    char searchnumber[20];
    printf("Search Number:\n");
    scanf("%s",searchnumber);
    
    for(i=0; i<count; i++)
    {
        
        if( strcasecmp(searchnumber,p[i].number )==0)
        {
            
            flag1=1;
            r=i;
            printf("First Name: %s \nLast Name: %s \nAddress: %s \nEmail: %s \nPhone Number: %s \nBirthday: %d-%d-%d \n", p[r].fname,p[r].lname,p[r].address,p[r].mail,p[r].number, p[r].date.day, p[r].date.month, p[r].date.year );
            printf("\n\n");
        }
    }
    if(flag1==0)
        printf("Number not found!\n");
    
}
void searchaddress()
{
    int i;
    int flag1=0;
    int r;
    char searchadd[20];
    printf("Search Address:\n");
    scanf("%s", searchadd);
    
    for(i=0; i<count; i++)
    {
        if( strcasecmp(p[i].address,searchadd) == 0 )
        {
            flag1=1;
            r=i;
            printf("Address found!\n First Name: %s \nLast Name: %s \nAddress: %s \nEmail: %s \nPhone Number: %s\nBirthday: %d-%d-%d \n", p[r].fname,p[r].lname,p[r].address,p[r].mail,p[r].number, p[r].date.day, p[r].date.month, p[r].date.year );
            printf("\n\n");
        }
    }
    if(flag1==0)
        printf("Address not found!\n");
}
void datesort()
{
    int j,i,m;
    info temp;
    for ( j=0; j<count-1; j++)
    {
        for (i=j+1; i<count; i++)
        {
            if ( p[j].date.year>p[i].date.year)
            {
                
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                
            }
            
            if ( p[j].date.year==p[i].date.year)
            {
                if ( p[j].date.month>p[i].date.month)
                {
                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
                }
            }
            
            if ( p[j].date.year==p[i].date.year && p[j].date.month==p[i].date.month )
            {
                if(p[j].date.day>p[i].date.day)
                {
                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
                }
            }
            
        }
    }
    
    for(m=0; m<count; m++)
    {
        printf("First Name: %s\nLast Name: %s\nDate: %d-%d-%d\nAddress: %s\nEmail: %s\nPhone Number: %s\n", p[m].fname, p[m].lname,p[m].date.day,p[m].date.month,p[m].date.year,p[m].address,p[m].mail,p[m].number );
        printf("\n");
    }
}
void sortlname()
{
    int j,i=0,m;
    info temp;
    for ( j=0; j<count-1; j++)
    {
        for (i=j+1; i<count; i++)
        {
            if (strcasecmp(p[j].lname, p[i].lname) > 0)
            {
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
            }
            if (strcasecmp(p[j].lname, p[i].lname)==0)
            {
                if(strcasecmp(p[j].fname, p[i].fname)>0)
                {
                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
                }
            }
            
            
        }
    }
    for (j=0; j<count-1; j++)
    {
        for (i=j+1; i<count; i++)
        {
            if( (strcasecmp(p[j].lname, p[i].lname)==0) && (strcasecmp(p[j].fname, p[i].fname)==0) )
            {
                if( strcasecmp(p[j].number , p[i].number) >0 )
                {
                    temp=p[j];
                    p[j]=p[i];
                    p[i]=temp;
                }
            }
        }
    }
    
    
    printf("Sorted Phone book is:\n");
    for(m=0; m<count; m++)
    {
        printf("Last Name: %s \nFast Name: %s \nPhone Number: %s \nBirthday: %d-%d-%d \nAddress: %s \nmail: %s \n", p[m].lname, p[m].fname, p[m].number, p[m].date.day, p[m].date.month, p[m].date.year, p[m].address, p[m].mail );
        printf("\n");
    }
}
void modify()
{
    printf("Modify:\n");
    int i;
    int r;
    int flag=0;
    printf("Search Last Name:\n");
    scanf("%s", searchln);
    int m[10];
    int z=0;
    for(i=0; i<count; i++)
    {
        
        if( strcasecmp(p[i].lname,searchln) == 0 )
        {
            
            m[z++]=i;
            flag++;
            r=i;
            printf("%d.\nFirst Name: %s \nLast Name: %s \nAddress: %s \nEmail: %s \nPhone Number: %s \nBirthday: %d-%d-%d \n",flag,p[r].fname,p[r].lname,p[r].address,p[r].mail,p[r].number, p[r].date.day, p[r].date.month, p[r].date.year );
            printf("\n\n");
            
        }
    }
    
    if(flag==0)
    {
        printf("Last name not found!\n");
    }
    if (flag==0);
    else{
        int ord;
        do {
            puts("enter order");
            scanf("%d",&ord);
        }
        while (ord < 1 && ord > flag );
        int j;
        j=m[ord-1];
        
        int modi;
        info mod;
        printf("1.Modify First Name \t 2.Modify Last Name \n 3.Modify Number \t 4.Modify Birthday \n 5.Modify Address \t 6.Modify Email\n");
        scanf("%d",&modi);
        switch (modi)
        {
            case 1:
            {printf("Modifying First name:\n");
                scanf("%s",mod.fname);
                verifyname(mod.fname);
                while (checkname==0)
                {
                    printf ("Not a valid name\n");
                    printf("enter first name :");
                    scanf("%s",mod.fname);
                    verifyname(mod.fname);
                }
                
                strcpy(p[j].fname,mod.fname);
                break;}
            case 2:
                printf("Modifying Last name:\n");
                scanf("%s",mod.lname);
                verifyname(mod.lname);
                while (checkname==0)
                {
                    printf ("Not a valid name\n");
                    printf("enter first name :");
                    scanf("%s",mod.lname);
                    verifyname(mod.lname);
                }
                strcpy(p[j].lname,mod.lname);
                break;
            case 3:
                printf("Modifying Number:\n");
                scanf("%s",mod.number);
                verifynum(mod.number);
                while (checknumber==0)
                {
                    printf("enter number:");
                    scanf("%s",mod.number);
                    verifynum(mod.number);
                }
                strcpy(p[j].number,mod.number);
                break;
            case 4:
                printf("Modifying Birthday:\n");
                printf("enter birthday :\n");
                printf("Day:\n");
                scanf("%d",&p[count].date.day);
                printf("Month:\n");
                scanf("%d",&p[count].date.month);
                printf("Year:\n");
                scanf("%d",&p[count].date.year);
                dateverfication();
                if (day==1 || month==1 || year==1){
                    do{
                        
                        printf ("\nPlease enter date correctly");
                        printf("\nDay:");
                        scanf("%d",&p[count].date.day);
                        printf("\nMonth:");
                        scanf("%d",&p[count].date.month);
                        printf("\nYear:");
                        scanf("%d",&p[count].date.year);
                        dateverfication();
                    }
                    while (day==1 || month==1 || year==1);}
                
                break;
            case 5:
                printf("Modifying Address:\n");
                scanf("%s",mod.address);
                strcpy(p[j].address,mod.address);
                break;
            case 6:
                printf("Modifying Email:\n");
                scanf("%s",mod.mail);
                strcpy(p[j].mail,mod.mail);
                break;
                
        }
    }
}
void delet()
{
    printf("Delete:\n");
    int i;
    int r;
    int flag=0;
    printf("Search Last Name:\n");
    scanf("%s", searchln);
    int m[10];
    int z=0;
    for(i=0; i<count; i++)
    {
        
        if( strcasecmp(p[i].lname,searchln) == 0 )
        {
            
            m[z++]=i;
            flag++;
            r=i;
            printf("%d.\nFirst Name: %s \nLast Name: %s \nAddress: %s \nEmail: %s \nPhone Number: %s\nBirthday: %d-%d-%d \n",flag,p[r].fname,p[r].lname,p[r].address,p[r].mail,p[r].number, p[r].date.day, p[r].date.month, p[r].date.year );
            printf("\n\n");
            
        }
    }
    
    if(flag==0)
    {
        printf("Last name not found!\n");
    }
    if (flag==0);
    else{
        int ord;
        do {
            puts("enter order");
            scanf("%d",&ord);
        }
        while (ord < 1 && ord > flag );
        int j;
        j=m[ord-1];
        p[j]=p[count];
        count--;
    }
}
void save()
{
    FILE *fp;
    int i;
    fp=fopen("phonebook.txt", "w");
    
    for(i=0; i<count; i++)
    {
        fprintf(fp,"%s,",p[i].fname);
        fprintf(fp,"%s,",p[i].lname);
        fprintf(fp,"%d-%d-%d,",p[i].date.day,p[i].date.month,p[i].date.year);
        fprintf(fp,"%s,",p[i].mail);
        fprintf(fp,"%s,",p[i].address);
        fprintf(fp,"%s\n",p[i].number);
    }
    fclose(fp);
    
}
void exi()
{
    printf("Are you sure you want to exit?(All Unsaved data will be lost)\n");
    printf("1.Exit Anyway \t 2. Save And Exit \t 3.Return to menu\n");
    int ex;
    scanf("%d",&ex);
    switch(ex)
    {
        case 1:
            break;
        case 2:
            save();
            break;
        case 3:
            menu();
            break;
            
    }
}
int main()
{
    load();
    menu();
    
    return 0;
}

