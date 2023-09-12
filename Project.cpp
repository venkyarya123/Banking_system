#include<string.h>
#include<iostream>
#include "valid.h"
using  namespace std;
class Bank
{
	public:
	char bankname[20];
	char IFSC[20];
	char address[20];
	
	Bank( )
	{
		strcpy(bankname,"Bank of AMDOCS");
		strcpy(IFSC,"AMID0000524");
		strcpy(address,"PUNE TOWER2");
	}
};
class SavingAccount: public Bank
{
	public :
	int acno;
	float bal;
	char  holdername[20];
	public:
		SavingAccount(){
			bal=0;
		}
		void accept( )
		{
			cout<<"Enter Account Number ";
			cin>>acno;
			while(true)
			{
				cout<<"Enter Name of Account Holder ";
				cin>>holdername;
				if (isNameValid(holdername))
					break;
				else
					cout<<"Name is not valid \n";
			}


			while(true)
			{
				cout<<"Enter Opening Balance ";
				cin>>bal;
				if (isBalance(bal))
					break;
				else
					cout<<"Opening Balance should be greater than 5000\n";
				
			}
			
		}
		void display()
		{
			cout<<"Bank Name is :"<<bankname<<endl;
			cout<<"Account number is :"<<acno<<endl;
			cout<<"Holder name is : "<<holdername<<endl;
			cout<<"Your balance is : "<<bal<<endl;
		}
		void withdraw(double amount) {
        if (bal >= amount) {
            bal -= amount;
            cout<<"withdrawn sucessfully"<<endl;
        }
		else
		{
		
        cout << "Insufficient balance!" << endl;
        }
    }
    void deposit(double amount) {
        bal += amount;
        cout<<"deposited sucessfully"<<endl;
    }
    void displayBalance() 
	{
        cout << "Account Number: " << acno << endl;
        cout << "Balance: $" << bal << endl;
    }	
};

class CurrentAccount: public Bank
{
	public :
	int acno;
	float bal;
	char holdername[20];	
	public:
		CurrentAccount(){
			bal=0;
		}
		void accept( )
		{
			cout<<"Enter Account Number ";
			cin>>acno;
			while(true)
			{
				cout<<"Enter Name of Account Holder ";
				cin>>holdername;
				if (isNameValid(holdername))
					break;
				else
					cout<<"Name is not valid \n";
			}

			while(true)
			{
				cout<<"Enter Opening Balance ";
				cin>>bal;
				if (isBalance(bal))
					break;
				else
					cout<<"Opening Balance should be greater than 5000\n";
				
			}
			
		}
		void display()
		{
			cout<<"Bank Name is :"<<bankname<<endl;
			cout<<"Account number is : "<<acno<<endl;
			cout<<"Holder name is : "<<holdername<<endl;
			cout<<"Your balance is : "<<bal<<endl;
		}
			void withdraw(double amount) {
        if (bal >= amount) {
            bal -= amount;
            cout<<"withdrawn sucessfully"<<endl;
        }
		else
		{
		
        cout << "Insufficient balance!" << endl;
        }
    }
    void deposit(double amount) {
        bal += amount;
        cout<<"deposited sucessfully"<<endl;
    }
    void displayBalance() 
	{
        cout << "Account Number: " << acno << endl;
        cout << "Balance: $" << bal<< endl;
    }    
    
};
int main()
{
	int n,m;
	bool flag , flag1;
	cout<<"Enter the number of records to be stored for CurrentAccount "<<endl;
	cin>>n;
	CurrentAccount ca[n];
	
	for(int i=0;i<n;i++)
		ca[i].accept( );
		
	for(int i=0;i<n;i++)
		ca[i].display( );
	cout<<"Enter the number of records to be added for savingaccount "<<endl;
		cin>>m;
	SavingAccount sa[m];
	
	for(int i=0;i<m;i++)
		sa[i].accept( );
		
	for(int i=0;i<m;i++)
		sa[i].display( );
		cout << "\nBank Accounts Created!" << endl;
    bool exit = false;
    while (!exit) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Deposit to Savings Account" << endl;
        cout << "2. Withdraw from Savings Account" << endl;
        cout << "3. Deposit to Current Account" << endl;
        cout << "4. Withdraw from Current Account" << endl;
        cout << "5. funds transfer from saving to saving accounts "<< endl;
        cout << "6. funds transfer from current to current accounts"<<endl;
        cout << "7. Display Balances" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                double savingsDepositAmount;
                int n1;
                cout << "Enter the amount to deposit into Savings Account and its number : ";
                cin >> savingsDepositAmount>>n1;
                sa[n1].deposit(savingsDepositAmount);
                break;
            case 2:
                double savingsWithdrawAmount;
                int n2;
                cout << "Enter the amount to withdraw from Savings Account and its number : ";
                cin >> savingsWithdrawAmount>>n2;
                sa[n2].withdraw(savingsWithdrawAmount);
                break;
            case 3:
                double currentDepositAmount;
                int n3;
                cout << "Enter the amount to deposit into Current Accountand its number : ";
                cin >> currentDepositAmount>>n3;
                ca[n].deposit(currentDepositAmount);
                break;
            case 4:
                double currentWithdrawAmount;
                int n4;
                cout << "Enter the amount to withdraw from Current Account and its number: ";
                cin >> currentWithdrawAmount;
                ca[n4].withdraw(currentWithdrawAmount);
                break;
            case 5:
            	int sea;
            	cout<<"enter senders saving account number "<<endl;
            	cin>>sea;
            	flag=true;
            	flag=true;
            	for(int i =0;i<m;i++)
            	{
            		if(sa[i].acno == sea)
            		{
            			flag=false;
            			int ra;
            			cout<<"enter receivers saving account number "<<endl;
            			cin>>ra;
            			for(int j=0;j<m;j++)
            			{
            				if(sa[j].acno == ra)
            				{
            					int a;
            					cout<<"enter amount to be transfered "<<endl;
            					cin>>a;
            					sa[i].withdraw(a);
            					sa[j].deposit(a);
            					flag=false;
           					
							}
			
						}
						if(flag)
						cout<<"enter proper  receivers saving account number "<<endl;
						break;
					}
					
					
				}
				if(flag)
				cout<<"enter proper senders saving account number "<<endl;
				break;
			 case 6:
            	int s;
            	cout<<"enter senders current account number "<<endl;
            	cin>>s;
            	flag=true;
            	flag=true;
            	for(int i =0;i<n;i++)
            	{
            		if(ca[i].acno == s)
            		{
            			flag=false;
            			int r;
            			cout<<"enter receivers current account number "<<endl;
            			cin>>r;
            			for(int j=0;j<n;j++)
            			{
            				if(ca[j].acno == r)
            				{
            					int b;
            					cout<<"enter amount to be transfered "<<endl;
            					cin>>b;
            					ca[i].withdraw(b);
            					ca[j].deposit(b);
            					flag=false;
           					
							}
			
						}
						if(flag)
						cout<<"enter proper  receivers current account number "<<endl;
						break;
					}
					
					
				}
				if(flag)
				cout<<"enter proper senders current account number "<<endl;
				break;
			
            case 7:
            	for(int i=0;i<m;i++)
				{
			
	                cout << "\nSavings Account:" <<i<< endl;
	                sa[i].displayBalance();
            	}
                for(int i=0;i<n;i++)
            	{
				
	                cout << "\nCurrent Account:" << i<<endl;
	                ca[i].displayBalance();
            	}
                break;
            case 8:
                exit = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

		

