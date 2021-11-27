#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct event
{
    int sold,people;
    char eventName[20];
    int dd,mm,yy;
    int rows,col;
};
typedef struct event e;
e EVENT={0,0};
struct node
{
    char name[20];
    char password[20];
    int seats[20],numseats,seatsbooked;
    struct node *next;
};
typedef struct node *NODE;
NODE first=NULL;
int a[100]={0};
int count=1;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("\nout of memory\n");
        exit(0);
    }
    return x;
}
void manager()
{
    char managerPassword[20];
    int choice;
    printf("\nWELCOME EVENT MANAGER\nPlease enter your password:");
    scanf("%s",&managerPassword);
    if(strcmp(managerPassword,"Rud")!=0)
    {
        printf("\nSORRY!!!!!\nwrong password\n");
        return;
    }
    while(1)
    {
    printf("\n1.Add an event\n2.Seats status\n3.Exit\n");
    scanf("%d",&choice);

        switch(choice)
        {
            case 1 : printf("\nName:");
                        scanf("%s",EVENT.eventName);
                        printf("\nDate:");
                        scanf("%d/%d/%d",&EVENT.dd,&EVENT.mm,&EVENT.yy);
                        printf("\nSeat pattern(rows and columns):");
                        scanf("%d%d",&EVENT.rows,&EVENT.col);
                        printf("\nYOUR EVENT IS SUCCESSFULLY UPLOADED\n");
                        break;
            case 2 : printf("\nSEATS STATISTICS\n");
                        printf("\nNumber of people regestered:1");
                        printf("\nSeats sold=%d\n",EVENT.sold);
                        printf("Seats left=%d",EVENT.rows*EVENT.col-EVENT.sold);
                        break;
            case 3 : return;
        }
    }
}
void existing()
{
    NODE cur;
    int id,i,j,choice,num,s;
    char userPassword[20];
    cur=first;
    printf("\nWELCOME USER\n");
    printf("\nPlease enter your ID:");
    scanf("%d",&id);
    for(i=1;i<id;i++)
        cur=cur->next;
    printf("\nPlease enter your password:");
    scanf("%s",userPassword);
    if(strcmp(userPassword,cur->password)!=0)
    {
        printf("\nSORRY!!!! Wrong password\n");
        return;
    }
    printf("\nHELLO %s",cur->name);
    printf("\nWELCOME TO THE EVENT %s",EVENT.eventName);
    while(1)
    {
        printf("\n1.Book seats\n2.See my seats\n3.Withdraw My seats\n4.Exit\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : if(EVENT.sold==EVENT.rows*EVENT.col)
                        {
                            printf("\nSORRY!!!!Seats are sold out\n");
                            break;
                        }
                        printf("\nAVAILABLE SEATS ARE\n");
                        for(i=1;i<=EVENT.rows*EVENT.col;i++)
                        {
                            if(a[i]!=1);
                                printf("%d ",i);
                        }
                        printf("\nEnter the number of seats you want:");
                        scanf("%d",&num);
                        printf("\nenter the seat numbers:");
                        for(i=0;i<num;i++)
                        {
                            scanf("%d",&s);
                            a[s]=1;
                            cur->seats[i]=s;
                        }
                        (cur->numseats)+=num;
                        (cur->seatsbooked)+=num;
                        (EVENT.sold)+=num;
                        printf("\nYour seats are successfully booked\n");
                        break;
            case 2 : if(cur->seatsbooked==0)
                        {
                            printf("\nNO SEATS BOOKED YET\N");
                            break;
                        }
                        printf("\nYOUR SEATS\n");
                        printf("\nNumber of seats booked=%d",cur->seatsbooked);
                        printf("\nSeat numbers are\n");
                        for(i=0;i<cur->numseats;i++)
                            if(cur->seats[i]!=-999)
                                printf("%d ",cur->seats[i]);
                        break;
            case 3 : if(cur->seatsbooked==0)
                        {
                            printf("\nNO SEATS BOOKED YET\n ");
                            break;
                        }
                        printf("\nSEATS WITHDRAWAL\n");
                        printf("\nEnter the number of seats you want to withdraw:");
                        scanf("%d",&num);
                        printf("\nEnter the seat numbers:");
                        for(i=0;i<num;i++)
                        {
                            scanf("%d",&s);
                            a[s]=0;
                            for(j=0;j<cur->numseats;j++)
                            {
                                if(s==cur->seats[j])
                                    cur->seats[j]=-999;
                            }
                            (cur->seatsbooked)-=num;
                            (EVENT.sold)-=num;
                        }
                        printf("\nSeats are withdrawn successfully\n");
                        break;
                case 4 : return;
        }
    }

}
void regester()
{
    NODE temp,cur;
    printf("\nWELCOME TO THE EVENT %s",EVENT.eventName);
    temp=getnode();
    temp->next=NULL;
    printf("\nEnter your name:");
    scanf("%s",temp->name);
    printf("\nSelect your password:");
    scanf("%s",temp->password);
    temp->numseats=0;
    temp->seatsbooked=0;
    if(first==NULL)
    {
        printf("\nNOTE!!! your ID is %d",count);
        first=temp;
        return;
    }
    cur=first;
    while(cur->next!=NULL)
        {
            cur=cur->next;
            count++;
        }
    cur->next=temp;
    printf("\nNOTE!!! your ID is %d",count);
    	EVENT.people++;
}
int main()
{
    int choice;
    printf("\nWELCOME");
    printf("\nEVENT MANAGEMENT SYSTEM\n");
    while(1)
    {
        printf("\n\n\n1.Event manager Login\n2.Existing User Login\n3.Regester Now\n4.Exit\nenter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : manager();break;
            case 2 : existing();break;
            case 3 : regester();break;
            default : exit(0);
        }
    }
    return 0;
}
