#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//initialization of functions
int load_cash();
int show_customer_details();
int show_atm_operations();
int Check_Balance(int);
int Withdraw_Money(int);
int Transfer_Money();
int check_ATM_balance();
int isvalid(int);
int user_account(int);
int total_balance_in_ATM =10000,no_of_customers = 5;

//struct declaration for customer details
struct customer_entry{
    int acc_no;
    char Name[50];
    int pin;
    int acc_balance;

}s[100];
//struct declaration for cash denominations
struct denominations{
    int two_thousands,five_hundreds,hundreds;

}m;

//to chech the available ATM balance
int check_ATM_balance()
{
	printf("Denomination\tNumber\t\tValue\n");
	printf("-----------------------------------------------------\n");
	printf("2000\t\t%d\t\t%d\n",2,2*2000);
	printf("-----------------------------------------------------\n");
	printf("500\t\t%d\t\t%d\n",6,6*500);
	printf("-----------------------------------------------------\n");
	printf("100\t\t%d\t\t%d\n",30,30*100);
	printf("-----------------------------------------------------\n");
	printf("\nThe Available Balance in ATM  %d\n",total_balance_in_ATM);
}
//to show the customer details
int show_customer_details(){
    
    int i;
    printf("-----------------------------------------------------\n");
    printf("Acc_No\tCus_Name Pin\tAcc_Bal\n");
    printf("---------------------------------------------------\n");
    for(i=0;i<no_of_customers;i++)
    		printf(" %d\t %s\t %d\t %d\n",s[i].acc_no,s[i].Name,s[i].pin,s[i].acc_balance);
			printf("---------------------------------------------------\n");     
}
//to point out the user account
int user_account(int p){
	int i;
	if(p == (s[0].pin || s[1].pin || s[2].pin || s[3].pin))
	    return 1;
	return -1;
}
//to check the index of the account user is valid or not
int isvalid(int p){
	
	if(user_account(p) == 1)
	    return 0;
	return 1;
}
//to transfer the money to the another account
int Transfer_Money(int p)
{
      int amt,i,j,acc,valid;
	  printf("NOTE: Max transfer limit per transaction is above 1000 and below 10000\n");
 	  printf("Enter the Amount to be transfered : ");
 	  scanf("%d",&amt);
 	  i = user_account(p);
 	  if(amt > s[i].acc_balance)
		   printf("Account balance is lower than entered amount\n"); 
	  else
	  {
	  	printf("Enter the account Number to which the money has to be transfered : ");
	  	scanf("%d",&acc);
	  	for(j=0;j<no_of_customers;j++)
	  	{
	  		if(s[j].acc_no == acc)
	  		   {
				 valid = 1;
	  		     break;
				} 
		  }
		if(valid)
		{
		  	s[i].acc_balance -= amt;
		  	s[j].acc_balance += amt;
		  	printf("-------------TRANSACTION SUCCESSFULL-------------\n");
		}
		else
		 printf("Invalid Account number\n");
		
	  }
	  
 } 
 //to withdraw the money of the user from their account
 int Withdraw_Money(int p)
{
	
	int i,amt;
	printf("NOTE : Your withdrawal money should be above 100 and below 10000\n");
	printf("Enter the Amount to be Withdrawn twice : ");
	scanf("%d\n",&amt);
	if ((amt<100 || amt >10000) && ((amt%100) == 0))
	   printf("Enter the valid amount\n");
	else if(amt > total_balance_in_ATM)
	   printf("The ATM does not have enough money to vend\n");
	else
	{
		i = user_account(p);
		if(amt > s[i].acc_balance)
		   printf("Account balance is lower than entered withdrawal amount\n");
		else
		  {
		  	s[i].acc_balance -= amt;
		   		m.two_thousands -= amt/2000;
		  		amt -= amt/2000;
		  		m.five_hundreds -= amt/1000;
		  		amt -= amt/1000;
		  		m.hundreds -= amt/100;
		  		amt -= 100;
			total_balance_in_ATM -= amt;
			printf("---Please Collect the Cash---Visit again------\n");
		  }
	}
	
	
}

 //To check the available balance of the customer
int Check_Balance(int p){
	int i;
	i = user_account(p);
	printf("---------------------------------------------------\n");
    printf("Your Available Account Balance : %d",s[i].acc_balance);
    printf("\n---------------------------------------------------\n");
	return 0;
	   
}
 //to show the atm operations
int show_atm_operations(){
	int choice,pin;
	printf("Enter your PIN number: ");
	scanf("%d",&pin);
	if(isvalid(pin))
	{
		
	printf("1. Check Balance\n");
	printf("2. Withdraw Money\n");
	printf("3. Transfer Money\n");
	printf("Enter the right choice to be performed: ");
	scanf("%d",&choice);
	switch(choice)
        {
            case(1):
            	Check_Balance(pin);
                break;
            case(2):
                Withdraw_Money(pin);
                break;
            case(3):
               Transfer_Money(pin);
                break;
            default:
                printf("Invalid Entry");
                break;
        }
    }
    else
    printf("Invalid PIN number");
	return 0;
}
//To load the cash in the atm
int load_cash(){
	
	printf("Enter the no of Two thousands:\t");
	scanf("%d",&(m.two_thousands));
	printf("Enter the no of Five hundrens:\t");
	scanf("%d",&(m.five_hundreds));
	printf("Enter the no of Hundreds:\t");
	scanf("%d",&(m.hundreds));
	total_balance_in_ATM += ((2000*m.two_thousands)+4000)+((500*m.two_thousands)+3000)+((100*m.hundreds)+3000);
	printf("\n-------------------------------------------------------\n");
	printf("Denomination\tNumber\t\tValue\n");
	printf("-------------------------------------------------------\n");
	printf("2000\t\t%d\t\t%d\n",(m.two_thousands)+2,((2000*m.two_thousands)+4000));
	printf("-------------------------------------------------------\n");
	printf("500\t\t%d\t\t%d\n",(m.five_hundreds)+6,((500*m.two_thousands)+3000));
	printf("-------------------------------------------------------\n");
	printf("100\t\t%d\t\t%d\n",(m.hundreds)+30,((100*m.hundreds)+3000));
	printf("-------------------------------------------------------\n");
	
	printf("The total available balance in the ATM is : %d\n",total_balance_in_ATM);
	  	
}
//customer details entry
int customer_details_entry(){
    s[0].acc_no =101;
    strcpy(s[0].Name,"Suresh");
    s[0].pin = 2343;
    s[0].acc_balance = 25234;
    
    s[1].acc_no =102;
    strcpy(s[1].Name,"Ganesh");
    s[1].pin = 5432;
    s[1].acc_balance = 34123;
    
    s[2].acc_no =103;
    strcpy(s[2].Name,"Magesh");
    s[2].pin = 7854;
    s[2].acc_balance = 26100;
    
    s[3].acc_no =104;
    strcpy(s[3].Name,"Naresh");
    s[3].pin = 2345;
    s[3].acc_balance = 80000;
    
    s[4].acc_no =105;
    strcpy(s[4].Name,"Harish");
    s[4].pin = 1907;
    s[4].acc_balance = 103400;
   
}

//Main function
int main()
{
    customer_details_entry();
	int choice;
    do{
        printf("\n-----------Welcome to the ATM service--------------\n");
		printf("1. Load cash to ATM\n");
		printf("2. Show customer details\n");
		printf("3. Show ATM Operations\n");
		printf("4. Check ATM Balance\n");
		printf("5. Quit\n");
		printf("--------------------------------------------------\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
        switch(choice)
        {
            case(1):
            	load_cash();
            	break;
            case(2):
            	show_customer_details();
                break;
            case(3):
                show_atm_operations();
                break;
            case(4):
            	check_ATM_balance();
            	break;
            case(5):
            	printf("-------------Thank you for using our ATM------------");
            	break;
            default:
                printf("Invalid Entry");
                break;
        }
    }while(choice!=5);

    return 0;
}