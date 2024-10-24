#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int choice;
struct account
{
    char account_holder[20];
    int day,month,year,balance,acc_num;
}AH[10];
int intro(){
    printf("\nPress 1 to see bank details\nPress 2 to enter new detail\nPress 3 to alter the data\n");
    scanf("%d",&choice);
    system("cls");
    return choice;
}
void details(int NOAH){
    for (int i = 0; i <NOAH; i++)
    {
        printf("Account holder's name : %s\nAccount holder's DOB : %d/%d/%d\nAccount number : %d\nAccount balance : %d\n\n",AH[i].account_holder,AH[i].day,AH[i].month,AH[i].year,AH[i].acc_num,AH[i].balance);
    }
}
int new_detail(int noah){
    srand(time(0));
    int acc_num_choice,ac_num,check=0;
    printf("Enter the name of the person to create account : ");
    scanf("%s",AH[noah].account_holder);
    system("cls");
    printf("Enter your date of birth(dd mm yyyy) : ");
    scanf("%d %d %d",&AH[noah].day,&AH[noah].month,&AH[noah].year);
    system("cls");
    printf("To create account number based on your choice press 1\nTo create random account number press 2\n");
    scanf("%d",&acc_num_choice);
    if (acc_num_choice==1)
    {
        do
        {
            printf("Enter account nuumber based on your choice(5 digits) : ");
            scanf("%d",&ac_num);
            for (int i = 0; i < noah; i++){
                if(ac_num==AH[i].acc_num){
                    printf("Number already exist try new number!!");
                    check=1;
                }
            }
        }while (check==1);
        AH[noah].acc_num=ac_num;
    }else{
        do{
            ac_num=rand();
            for (int i = 0; i < noah; i++){
                if(ac_num==AH[i].acc_num)
                    check=1;
        }
        } while (check==1);
        AH[noah].acc_num=ac_num;
    }
    system("cls");
    printf("Enter the account deposit : ");
    scanf("%d",&AH[noah].balance);
    printf("Successfully crated!!");
    return noah+1;
}
void replace(int noah){
    int search,confirmation=0,i=0,change,option;
    printf("Enter your account number to search : ");
    scanf("%d",&search);
    system("cls");
    do
    {
        if(search==AH[i].acc_num){
            printf("Account holder's name : %s\nAccount holder's DOB : %d/%d/%d\nAccount number : %d\nAccount balance : %d\n",AH[i].account_holder,AH[i].day,AH[i].month,AH[i].year,AH[i].acc_num,AH[i].balance);
            printf("Check weather it is your account!!\nIf yes press 1\nElse press 0\n");
            scanf("%d",&confirmation);
            system("cls");
        }
        i++;
    } while (confirmation==0);
    i--;
    printf("Enter which parameter you want to change\nTo change account holder name press 1\nTo change date of birth press 2\nTo update balance press 3\n");
    scanf("%d",&option);
    system("cls");
    if(option==1){
        printf("Enter your new name : ");
        scanf("%s",AH[i].account_holder);
    }else if(option==2){
        printf("Enter your new date of birth to update(dd mm yyyy) : ");
        scanf("%d %d %d",&AH[i].day,&AH[i].month,&AH[i].year);
    }else if(option==3){
        printf("Enter your new bank balance : ");
        scanf("%d",&AH[i].balance);
    }
    system("cls");
    printf("changed list");
    printf("Account holder's name : %s\nAccount holder's DOB : %d/%d/%d\nAccount number : %d\nAccount balance : %d\n",AH[i].account_holder,AH[i].day,AH[i].month,AH[i].year,AH[i].acc_num,AH[i].balance);

}
void main()
{
    int NOAH=0,explore;
    printf("WELCOME TO RAJAJEGAN'S BANK MANAGEMENT SYSTEM!!");
    do
    {
        choice=intro();
        if(choice==1){
            details(NOAH);
        }else if(choice==2){
            NOAH=new_detail(NOAH);
        }else if (choice==3)
        {
            replace(NOAH);
        }
        printf("Continue exploring our bank press 1 : ");
        scanf("%d",&explore);
        system("cls");
    } while (explore==1);
}
