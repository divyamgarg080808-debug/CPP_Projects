#include <iostream>
using namespace std;
#include<string.h>
#include<iomanip>
#include <fstream>

class bank
{
	int acc_no; 
	char name[30]; 
	char contact[10];
	int balance; 
	char password[10];
	
	public:
	void assignacc();
	
	
	void openaccount()
{
	fflush(stdin);
	cout<<"enter name:";
	gets(name);
	cout<<"enter contact no : ";
	gets(contact);
	cout<<"make a password:";
	gets(password);			
	cout<<"enter amount u want to deposit :";
	cin>>balance;
	assignacc();
	
}


	void details()
{
	cout<<acc_no;
	puts(name);
	puts(contact);
	cout<<balance;		
}

	
	
	void credit()
{
	int credit; 
	cout<<"amount to be credited is : ";
	cin>>credit;
	ofstream obj4;
	obj4.open("transaction.txt",ios::app);
	obj4<<credit<<"rs have been credited to account number "<<acc_no;
	obj4.close();
	
	balance= balance + credit ;
	cout<<"new balance is : "<<balance; 
	
}


	void debit()
{
	int debit;
	cout<<"amount to be debited is : ";
	fflush(stdin);
	cin>>debit;

	for( int tries = 0; tries<3; tries++)
{	
	if( debit <= balance )
{
	ofstream obj5 ("transaction.txt",ios::app);
	obj5<<debit<<"rs have been debited to account number "<<acc_no;
	obj5.close();
	balance= balance - debit ; 
	cout<<"new balance is : "<<balance;

}
	else
	cout<<"you don't have enough balance";
}
}


	void write()
{	
	ofstream obj1;
	obj1.open("BANK.txt",ios::app);
	obj1.write((char *) &*this,sizeof(*this));
	obj1.close();
}



	int finding()
{
	ifstream obj;
	int temp,flag = 0 ;
	cout<<"enter your account number";
	cin>>temp;
	obj.open("BANK.txt");
	while(obj.read((char *) &*this,sizeof(*this)))
{
	
	if( acc_no == temp )
{     
	flag = 1;
	return(1);		
}
		
}		
	if( flag ==0 )
{
	cout<<"your account doesn't exist";
	obj.close();		
	return(0);
}
	return(0);
}



	int askpassword()
{
	char askpassword[10];
	int tries; 
	
	for( tries = 0; tries<3; tries++)
{	
	cout<<"enter te password:";
	fflush(stdin);
	gets(askpassword);
	
	if(strcmp( password , askpassword )==0)
{
	return(1);
}
	else 
{
	cout<<"!!wrong password!!";
}
	
}
	cout<<"password inputting tries are over";

	return(0);
}



	void updation()
{
	fstream obj4 ; 
	obj4.open("BANK.txt",ios::out|ios::in);
	obj4.seekg(sizeof(*this)*(acc_no-1));
	int pos = obj4.tellg();
	obj4.seekp(pos);
	obj4.write((char *) &*this,sizeof(*this));
	obj4.close();	
}

		
};


	
	void bank :: assignacc()
{
	int temp2=0;
	bank zz;	
	ifstream obj3;
	obj3.open("BANK.txt");
		
	while(obj3.read((char *) &zz,sizeof(zz)))
{
	temp2++;		
}
	this->acc_no = temp2 + 1  ; 
	obj3.close();
	cout<<"your acc_no is :"<< this-> acc_no ;	
}





	int main()
{
	bank account ; 
	int t,k;
	std::cout<<setw(80)<<"**********WELCOME TO MY BANK**********";
	int task;
	while(1)
{
	
	printf("\n\n1 open account\n2 credit \n3 debit\n4 see details\n5 end task\n\nenter te number of task u want : ");
	cin>>task;
	
		
	if(task==1)
{	
	account.openaccount();
	account.write();
}


	else if(task==2)
{
	k= account.finding();
	
    if(k==1)
{
	t = account.askpassword();    	
	if(t==1)
{
	account.credit();
	account.updation();
}

}

}
	else if(task==3)
{
	k=account.finding();
	
    if(k==1)
{
	t = account.askpassword();    	
	if(t==1)
{
	account.debit();
	account.updation();
}

}

}

	else if(task==4)
{
	k=account.finding();
	
    if(k==1)
{
	t = account.askpassword();    	
	if(t==1)
{
	account.details();
}

}

}

	else
	return 0;
	
			
}
cout<<"process complete"; 

}
