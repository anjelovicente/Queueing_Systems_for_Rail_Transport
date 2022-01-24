#include<iostream> 
#include<conio.h> 
#include<string.h>
#include<string>
#include<stdlib.h>

#include <fstream>
#include <stack>
#include <queue>
using namespace std; 
int adminPassCode[3] = {11815507, 11824999, 11817933};

void firstPart(bool);
void printLRT1(void);
void printLRT2(void);
void printMRT1(void);
void transactions(int, int);
int priceOfCard(string, string);
void mainPrint(int[]);

void secondPart();
void allLRT1();
void allLRT2();
void allMRT();
void viewAllTrans();
void print(void);
void deleteBetweenNodes(void);
void search(void);
void editBetweenNodes(void);
int discount(int);
void transactionSlip(string, string, string, string, string, string);


//Stack, Tree*

struct data{
	string fromStation;
	string toStation;
	string modeOfTrans;
	string storedStamp; 		//to see if card is already registered
	string load;
	string fee;
	string change;
	string station;
	data *next;
}; data *head = NULL;

int main(){
	bool start=true;
	int user, choice;
	//we could register beep card via loop
	cout<<"\t\t\tGood Day to Our Beloved Passengers\n\t\t\t   Welcome to Light Rail Transit\n\n"<<endl;
	while(start){
		cout <<"\t\t\t[1] - Customer" << endl;
		cout <<"\t\t\t[2] - Admin"<< endl;;
		cout <<"\t\t\t[3] - Exit" << endl;
		cout <<"\t\t\tChoice: ";
		cin >> user;
		if (user == 1){
			cout<<endl;
			firstPart(start);
		}
		
		else if (user == 2){
			cout<<"\n\t\t\tInput Admin Code: ";
			cin>> choice;
			int x;
			for(int i=0; i<3; i++){
				if (choice == adminPassCode[i]){
					cout<<"\t\t\tCorrect Admin Code. Proceeding to Admin Page";
					secondPart();
					x=1;
					break;
				}
				x=0;
			}
			if (x == 1){ cout<<"\t\t\tGoing Back to Log In Page\n"<<endl;}
			else if (x == 0){ cout<<"\t\t\tIncorrect Admin Code. Back to Log In Page\n"<<endl;}
		}
		else if (user == 3){
			cout<<"\n\t\t\tWe Thank You For Using Our Program. May You Have a Safe and Comfortable Journey Experience\n"<<endl;
			start = false;
		}
		else{
			cout<<"\n\t\t\tWrong Input. Try Again.\n"<<endl;
		}
	}
}

void firstPart(bool start){
	int stat, load_trans, another, complaintCount, ticketVal;
	char ch;
	string complaint;
	queue<string> complaintDatabase;
	
	while (start){
		cout<<"\t\tWhich Light Rail Transit would you like to go?\n \t\t [1] - LRT1 \t [2] - LRT2 \t [3] - MRT1 "<<endl;
		cout<<"\t\tInput your preferred Light Rail Transit below:\n\t\t\t\t      ";
		cin>> stat;
		if(stat == 1){
			printLRT1();
		} else if (stat ==2){
			printLRT2();
		} else if (stat == 3){
			printMRT1();
		} else{
			firstPart(start);
		}
		
		cout<<"\n       \t\t\tPick a Loading Transaction\n \t\t\t    [1] - Stored Value \n\t\t\t    [2] - Single Journey \n\t\t\t    [3] - Reloading\t";
		cout<<"\n\t\t   Input your Loading Transaction below:\n\t\t\t\t    ";
		cin>> load_trans;
		transactions(load_trans, stat);
		
		cout << "\n\t   Thank you for using our Light Rail Queueing System!";
		cout <<"\n\t   For any concerns and problems press [C] to let us know ";
		cout <<"\n\t\t   If you have no concerns, press [N]\n\t\t\t\t    ";
		cin >> ch;
		if(ch == 'C'|| ch =='c'){
			cout << "\n\t\t   Railway Transit Complaints and Concerns \n\t\t   Type your major concern below: ";
			cin.ignore(100,'\n');
			getline(cin, complaint);
			complaintDatabase.push(complaint);
			complaintCount++;
			cout <<"\n\t\t\tThank you for your cooperation!";
		}
		else{
			cout << "\t\t\tThank you for your cooperation!";
		}
		
		cout<< "\n\t\tAnother Customer? [1] - Yes \t [2] - No\t";
		cin >> another;
		if (another == 2){
			viewAllTrans();
			cout << "\n\t\t\t\t   Summary of Complaints: \n";
			if(!complaintDatabase.empty()){
				for(int i=0; i<complaintCount; i++){
					cout << "\t\t\t\t" << i+1 << ".\t" << complaintDatabase.front();
					cout << "\n";
					complaintDatabase.pop();
				}
			}else{
				cout << "\n\t\t\t\t\tNo Complaints Filed Yet" << endl;
			}
			print();
			start = false;
		}
		cout<< "\n\n";
	}
	return;
}

void secondPart(){
	bool loop=true;
	int salesch;
	
	while(loop){
		int choice;
		viewAllTrans();
		cout << "\n\n\t\t\t\t\t   Pick an option: " << endl;
		cout << "\t\t\t\t\t   1. View Sales Reports" << endl;
		cout << "\t\t\t\t\t   2. Edit by Position" << endl;
		cout << "\t\t\t\t\t   3. Delete by Position" << endl;
		cout << "\t\t\t\t\t   4. Search" << endl;
		cout << "\t\t\t\t\t   5. Print Text File" << endl;
		cout << "\t\t\t\t\t   6. Exit" << endl;
		cout << "\n\t\t\t\t\t\t   Choice:  ";
		cin>>choice;
		
		switch (choice){
			case 1:
				cout << "\n\t\t\t\t\t   [1] - LRT1\n\t\t\t\t\t   [2] - LRT2\n\t\t\t\t\t   [3] - MRT \t";
				cout << "\n\t\t\t\t\t   Input your choice: ";
				cin >> salesch;
				if (salesch == 1){
					allLRT1();
				}else if(salesch == 2){
					allLRT2();
				}else if(salesch == 3){
					allMRT();
				}
				cout<<"\n\n";
				break;
			case 2:
				editBetweenNodes();
				break;
			case 3:
				deleteBetweenNodes();
				break;	
			case 4:
				search();
				break;	
			case 5:
				print();
				break;
			case 6:
				loop=false;
				break;
			default:
				cout<< "\n\t\t\t\t\t   Wrong Option." << endl;;
				break;
		}
	}
	
}

void printLRT1(){
	cout<<"\n\n\tLegends: (0)--Station\t ()--Last Station    (*)--Interchange Station"<<endl;
	
	cout<<"\n\t\t\t\t()----Roosevelt"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Balintawak"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Monumento"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----5th Avenue"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----R.Papa"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Abad Santos"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Blumentritt"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Tayuman"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Bambang"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(*)----Doroteo Jose (Transfer to MRT1)"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Carriedo"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Central Terminal"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----United Nations"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Pedro Gil"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Quirino"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Vito Cruz"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Gil Puyat"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Libertad"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----EDSA"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t()----Baclaran"<<endl;
	
}

void printLRT2(){
	cout<<"\n\n\tLegends: (0)--Station\t ()--Last Station    (*)--Interchange Station"<<endl;
	cout<<"\n\t\t\t\t(*)----Recto (Transfer to LRT1)"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Legarda"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Pureza"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----V.Mapa"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----J.Ruiz"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Gilmore"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Betty-Go Belmonte"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(*)----Cubao (Transfer to LRT2)"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Anonas"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Katipunan"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t()----Santolan"<<endl;
}

void printMRT1(){
	cout<<"\n\n\tLegends: (0)--Station\t ()--Last Station    (*)--Interchange Station"<<endl;
	cout<<"\n\t\t\t\t()----North Avenue"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Quezon Avenue"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Kamuning"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(*)----Araneta Center (Transfer to LRT2)"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Santolan"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Ortigas"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Shaw Boulevard"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Boni Avenue"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Guadalupe"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Buendia"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Ayala"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t(0)----Magallanes"<<endl;
	cout<<"\t\t\t\t||"<<endl;
	cout<<"\t\t\t\t()----Taft"<<endl;
}

int discount(int fee){
	string pwdDisc = "PWDDiscount", seniorDisc = "SeniorDiscount";
	string discount;
	int choice2, originialFee;
	
	cout<<"\n\t\tAre you a Person-With-Disability / Senior Citizen? \n\t\t\t[1] - Yes \t [2] - No\t";
	cin>> choice2;
	
	
	if(choice2==1){
		cout<<"\n\t\tInput Discount Code: ";
		cin>> discount;
		
		if(discount == pwdDisc || discount == seniorDisc){
			fee = fee - (fee*.2);
			
			
			cout<< "\n\t\tYour discounted price is "<<fee<<". ";
			return fee;
		}
		
		else{
			cout<<"\n\t\tWrong input for discount code. No discount, proceeding back to the transaction.";
		}
	}
	else{
		return fee;
	}
}

void transactions(int load_trans, int stat){
	int change=0, stampNum, fee=0, price;
	data *tail = new data;  
	data *temp = new data;
	
	if(stat == 1){
		tail->station = "LRT1";
	} else if (stat ==2){
		tail->station = "LRT2";
	} else if (stat == 3){
		tail->station = "MRT";
	}
	
	if (load_trans == 1){
		cout << "\n\t\t\t     <Stored Value>" << endl;
		cout << "\t\t The price for a store value card is P100. \n\t\t\t     Pay amount of: ";
		cin >> tail->fee;
		change = stoi(tail->fee) - 100;
		while(change < 0){ 
			cout << "\n\t\t\t    Insufficient Fee"<<endl;  
			cout << "\n\t\tThe price for a store value card is P100. \n\t\t\t     Pay amount of: ";
			cin >> tail->fee;
			change = stoi(tail->fee) - 100;
		}
		cout<< "\n\t\t\tCurrent Station: ";
		cin.ignore(100,'\n');
		getline(cin, tail->fromStation);
		cout<< "\t\t\tTo Station: ";
		getline(cin, tail->toStation);
		price = priceOfCard(tail->fromStation, tail->toStation);
		if (price != 0){
			cout << "\n\t\tThe travel fare is P"<<  price << endl;
		}else {
			while(price == 0){
				cout<< "\n\t\t\tInvalid Input";
				cout<< "\n\t\t\tCurrent Station:";
				getline(cin, tail->fromStation);
				cout<< "\t\t\tTo Station: ";
				getline(cin, tail->toStation);
				price = priceOfCard(tail->fromStation, tail->toStation);
				if (price != 0){
					cout << "\n\t\tThe travel fare is P"<< price << endl;
				}
			}
		}
		int load = 100 - price;
		tail->load = to_string(load);
		tail->change = to_string(change);
		stampNum = rand()%100+1;
		cout << "\t\t\tBeep Card's Stamp Number is #" << stampNum << endl;
		tail->storedStamp = to_string(stampNum);
		tail->modeOfTrans = "Stored Value";

	}

	else if (load_trans == 2){
		cout << "\n\t\t\t     <Single Journey>" << endl;
		cout<< "\n\t\t\tCurrent Station: ";
		cin.ignore(100,'\n');
		getline(cin, tail->fromStation);
		cout<< "\t\t\tTo Station: ";
		getline(cin, tail->toStation);
		price = priceOfCard(tail->fromStation, tail->toStation);
		if (price != 0) {
			cout << "\n\t\tThe price for a single journey card is P"<< price <<". \n\t\t\t" ;
		}else{
			while(price == 0){
				cout<< "\n\t\t\tInvalid Input";
				cout<< "\n\t\t\tCurrent Station:";
				getline(cin, tail->fromStation);
				cout<< "\t\t\tTo Station: ";
				getline(cin, tail->toStation);
				price = priceOfCard(tail->fromStation, tail->toStation);
				if (price != 0) {
					cout << "\n\t\tThe price for a single journey card is P"<< price <<". \n\t\t\t" ;
				}
			} 
		}
		cout << "Pay Amount Of: ";
		cin >> tail->fee;
		
		price = discount(priceOfCard(tail->fromStation, tail->toStation));
		change = stoi(tail->fee) - price;
		if (change != 0){
			cout<< "\n\t\t\tYour change is " << change <<"."<< endl;
		}
		else{
			while(change < 0){
				cout << "\n\t\t\t     Insufficient Fee" << endl;
				cout << "\t\tThe price for a single journey card is P"<< price <<". \n\t\t\t     Pay amount of: " ;
				cin >> tail->fee;
				price = discount(priceOfCard(tail->fromStation, tail->toStation));
				change = stoi(tail->fee) - price;
				if (change != 0){
					cout<< "\n\t\t\tYour change is " << change <<"."<< endl;
				}
			}
		}
		tail->load = to_string(price);
		tail->change =to_string(change);
		tail->storedStamp = to_string(0);
		tail->modeOfTrans = "Single Journey";
	}
	
	else if (load_trans == 3){
		string stamp;
		int load=0;
		cout << "\n\t\t\t<Reloading Stored Value>" << endl;
		cout << "\n\t\tRegistered Stored Card Stamp Numbers: " << endl;
		
		temp = head;
		if (temp == NULL){
			cout << "\n\t\t\tNo Registered Beep Cards"<< endl;
			firstPart(true);
		}
		while (temp != NULL){
			if (temp->storedStamp != "0"){
				cout << "\n\t\t" << temp->storedStamp;
			}
			temp = temp->next;
		}
		
		cout << "\t\t\tInput Card Stamp Number: ";
		cin >> stamp;
		
		//checks if beep card has registered stamp
		data *check = new data;
		check = head;
		while (check != NULL){
			if (stamp == check->storedStamp){
				cout << "\n\t\t\tBeep Card Found! \n\t\t\tReloading Amount: ";
				cin >> tail->fee;
				while(stoi(tail->fee) <= 0){
					cout << "\t\t\t\tInvalid Fee"<<endl;
					cout << "\n\t\t\tBeep Card Found! \n\t\t\tReloading Amount: ";
					cin >> tail->fee;
				}
				int x = stoi(check->load);
				load = stoi(tail->fee) + x;
				tail->load =to_string(load);
				tail->change = to_string(0);
				tail->storedStamp = check->storedStamp;
				tail->modeOfTrans = "Reloading Stored Value";
				break;
			}
			check = check->next;
		}
		
		cout<< "\n\t\t\tCurrent Station: ";
		cin.ignore(100,'\n');
		getline(cin, tail->fromStation);
		cout<< "\t\t\tTo Station: ";
		getline(cin, tail->toStation);
		price = priceOfCard(tail->fromStation, tail->toStation);
		if (price != 0){
			cout << "\n\t\tThe travel fare is P"<<  price << endl;
		}else {
			while(price == 0){
				cout<< "\n\t\t\tInvalid Input";
				cout<< "\n\t\t\tCurrent Station: ";
				getline(cin, tail->fromStation);
				cout<< "\t\t\tTo Station: ";
				getline(cin, tail->toStation);
				price = priceOfCard(tail->fromStation, tail->toStation);
				if (price != 0){
					cout << "\n\t\tThe travel fare is P"<< price << endl;
				}
			}
		}
		load = stoi(tail->load) - price;
		tail->load = to_string(load);
	}
	transactionSlip(tail->fromStation, tail->toStation, tail->change, tail->load, tail->modeOfTrans, tail->storedStamp);
	
	//adds input data to linkList(data)
	tail->next = NULL;  
	if (head == NULL) { 
 		head = tail; 
 	}  
	else { 
 		temp = head; 
 		while (temp->next != NULL) { 
			temp = temp->next; 
		} 
	temp->next = tail; 
 	} 
 	return;
}

int priceOfCard(string from, string to){
	int price = 0;
	if(from == "Baclaran" || from == "Recto"){
		if(to == "Baclaran" || to == "Recto"){
			return 0;
		}
		else if(to == "EDSA" || to == "Libertad" || to == "Gil Puyat" ||
		to == "Vito Cruz" || to == "Quirino" || to == "Legarda" || to == "Pureza" 
		|| to == "V. Mapa"){
			price = 15;
		}
		else if(to == "Pedro Gil" || to == "United Nations" || to == "Central Terminal" 
		|| to == "Carriedo" || to == "Doroteo Jose" || to == "Bambang" || to == "J. Ruiz" 
		|| to == "Gilmore"|| to == "Betty Go" || to == "Cubao" ){
			price = 20;
		}
		else if(to == "Anonas" || to == "Katipunan" || to == "Santolan") {
			price = 25;
		}
		else if(to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos" || to == "R. Papa" 
		|| to == "5th Avenue" || to == "Roosevelt" || to == "Monumento" || to == "Balintawak"){
			price = 30;
		}
		
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	
	else if(from == "EDSA" || from == "Legarda"){
		if(to == "EDSA" || to == "Legarda"){
			return 0;
		}
		else if(to == "Baclaran" || to == "Libertad" || to == "Gil Puyat" 
		|| to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" || to == "Recto" 
		|| to == "Pureza" || to == "J. Ruiz" || to == "V. Mapa"){
			price = 15;
		}
		else if(to == "United Nations" || to == "Central Terminal" || to == "Tayuman" 
		|| to == "Carriedo" || to == "Doroteo Jose" || to == "Bambang" || to == "Gilmore"
		|| to == "Betty Go" || to == "Anonas" || to == "Cubao"){
			price = 20;
		}
		else if(to == "Katipunan" || to == "Santolan") {
			price = 25;
		}
		else if(to == "Blumentrit" || to == "Abad Santos" || to == "R. Papa" 
		|| to == "5th Avenue" || to == "Roosevelt" || to == "Monumento" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	
	else if(from == "Libertad" || from == "Pureza"){
		if(to == "Libertad" || to == "Pureza"){
			return 0;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Gil Puyat" ||
		to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" || to == "United Nations"
		|| to == "Recto" || to == "Legarda" || to == "J. Ruiz" || to == "V. Mapa" || to == "Gilmore"){
			price = 15;
		}
		else if(to == "Central Terminal" || to == "Tayuman" || to == "Carriedo" 
		|| to == "Doroteo Jose" || to == "Bambang" || to == "Blumentrit"
		|| to == "Betty Go" || to == "Cubao" || to == "Anonas" || to == "Katipunan"){
			price = 20;
		}
		else if(to == "Santolan") {
			price = 25;
		}
		else if(to == "Abad Santos" || to == "R. Papa" || to == "5th Avenue" || 
		to == "Roosevelt" || to == "Monumento" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Gil Puyat" || from == "V. Mapa"){
		if(to == "Gil Puyat" || to == "V. Mapa"){
			return 0;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad" ||
		to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" || to == "United Nations"
		|| to == "Recto" || to == "Legarda" || to == "J. Ruiz" 
		|| to == "Pureza" || to == "Gilmore" || to == "Betty Go"){
			price = 15;
		}
		else if(to == "Central Terminal" || to == "Tayuman" || to == "Carriedo" 
		|| to == "Doroteo Jose" || to == "Bambang" || to == "Blumentrit" || to == "Abad Santos"
		|| to == "Cubao" || to == "Anonas" || to == "Katipunan"){
			price = 20;
		}
		else if(to == "Santolan") {
			price = 25;
		}
		else if(to == "R. Papa" || to == "5th Avenue" || 
		to == "Roosevelt" || to == "Monumento" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Vito Cruz" || from == "J. Ruiz"){
		if(to == "Vito Cruz" || to == "J. Ruiz"){
			return 0;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad" ||
		to == "Gil Puyat" || to == "Quirino" || to == "Pedro Gil" || 
		to == "United Nations" || to == "Central Terminal" || to == "Carriedo" ||
		to == "Legarda" || to == "V. Mapa" || to == "Pureza" || to == "Gilmore" 
		|| to == "Betty Go" || to == "Cubao"){
			price = 15;
		}
		else if(to == "Tayuman" || to == "Doroteo Jose" || to == "Bambang" || 
		to == "Blumentrit" || to == "Abad Santos" || to == "R. Papa" ||
		to == "Recto"  || to == "Anonas" || to == "Katipunan" || to == "Santolan"){
			price = 20;
		}
		else if(to == "5th Avenue" || to == "Roosevelt" || to == "Monumento" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Quirino" || from == "Gilmore"){
		
		if(to == "Quirino" || to == "Gilmore"){
			return 0;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad" ||
		to == "Gil Puyat" || to == "Vito Cruz" || to == "Pedro Gil" || 
		to == "United Nations" || to == "Central Terminal" || to == "Carriedo"
		|| to == "Doroteo Jose" || to == "J. Ruiz" || to == "Pureza" || to == "V. Mapa" 
		|| to == "Betty Go" || to == "Cubao" || to == "Anonas"){
			price = 15;
		}
		
		else if(to == "Tayuman" || to == "Bambang" || to == "5th Avenue" ||
		to == "Blumentrit" || to == "Abad Santos" || to == "R. Papa" ||
		to == "Recto" || to == "Legarda"  || to == "Katipunan" || to == "Santolan" ){
			price = 20;
		}
		else if( to == "Roosevelt" || to == "Monumento" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	
	else if(from == "Pedro Gil" || from == "Betty Go"){
		if(to == "Pedro Gil" || to == "Betty Go"){
			
			return 0;
		}
		else if( to == "EDSA" || to == "Libertad" ||
		to == "Gil Puyat" || to == "Vito Cruz" || to == "Quirino" || 
		to == "United Nations" || to == "Central Terminal" || to == "Carriedo"
		|| to == "Doroteo Jose" || to == "Bambang" ||to == "J. Ruiz" 
		|| to == "V. Mapa" || to == "Gilmore" || to == "Cubao" 
		|| to == "Anonas" || to == "Katipunan"){
			price = 15;
		}
		else if(to == "Baclaran" || to == "Tayuman" || to == "5th Avenue" ||
		to == "Blumentrit" || to == "Abad Santos" || to == "R. Papa" || to == "Monumento"
		|| to == "Recto" || to == "Legarda"  ||  to == "Santolan"|| to == "Pureza"){
			price = 20;
		}
		else if( to == "Roosevelt" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
		
	}
	else if(from == "United Nations" || from == "Cubao"){
		if(to == "United Nations" || to == "Cubao"){
			
			return 0;
		}
		else if(to == "Libertad" || to == "Gil Puyat" || to == "Vito Cruz" || to == "Quirino" || 
		to == "Pedro Gil" || to == "Central Terminal" || to == "Carriedo"
		|| to == "Doroteo Jose" || to == "Bambang" || to == "Tayuman"
		||  to == "J. Ruiz" || to == "Gilmore" || to == "Betty Go"
		|| to == "Santolan"|| to == "Anonas" || to == "Katipunan"){
			price = 15;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "5th Avenue" 
		|| to == "Blumentrit" || to == "Abad Santos" || to == "R. Papa" || to == "Monumento"
		|| to == "Recto" || to == "Legarda" || to == "Pureza" || to == "V. Mapa"){
			price = 20;
		}
		else if( to == "Roosevelt" || to == "Balintawak"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Central Terminal" || from == "Anonas"){
		if(to == "Central Terminal" || to == "Anonas"){
			
			return 0;
		}
		else if( to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "United Nations" || to == "Carriedo"|| to == "Doroteo Jose" 
		|| to == "Bambang" || to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos"
		|| to == "Gilmore" || to == "Betty Go"|| to == "Santolan"|| to == "Cubao" || to == "Katipunan"){
			price = 15;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "5th Avenue" || to == "Libertad" || 
		to == "Gil Puyat"  || to == "R. Papa" || to == "Monumento" || to == "Balintawak"
		|| to == "Legarda" || to == "Pureza" || to == "V. Mapa" || to == "J. Ruiz"){
			price = 20;
		}
		else if(to == "Recto"){
			price = 25;
		}
		else if( to == "Roosevelt"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Carriedo" || from == "Katipunan"){
		if(to == "Carriedo" || to == "Katipunan"){
			
			return 0;
		}
		else if( to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "United Nations" || to == "Bambang"|| to == "Doroteo Jose" 
		|| to == "Central Terminal" || to == "Tayuman" || to == "Blumentrit" 
		|| to == "Abad Santos" || to == "R. Papa" || to == "Betty Go"
		|| to == "Santolan" || to == "Cubao" || to == "Anonas"){
			price = 15;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "5th Avenue" || to == "Libertad" 
		|| to == "Gil Puyat"  || to == "Monumento" || to == "Balintawak" || to == "Pureza" 
		|| to == "V. Mapa" || to == "J. Ruiz" || to == "Gilmore"){
			price = 20;
		}
		else if(to == "Recto" || to == "Legarda"){
			price = 25;
		}
		else if( to == "Roosevelt"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Doroteo Jose" || from == "Santolan"){
		if(to == "Doroteo Jose" || to == "Santolan"){
			
			return 0;
		}
		else if(to == "Quirino" || to == "Pedro Gil" 
		|| to == "United Nations" || to == "Bambang"|| to == "Carriedo" 
		|| to == "Central Terminal" || to == "Tayuman" || to == "Blumentrit" 
		|| to == "Abad Santos" || to == "R. Papa" || to == "Katipunan" 
		|| to == "Cubao" || to == "Anonas"){
			price = 15;
		}
		else if(to == "Vito Cruz" || to == "Baclaran" || to == "EDSA" || to == "5th Avenue" 
		|| to == "Libertad" || to == "Gil Puyat"  || to == "Monumento" || to == "Balintawak" 
		|| to == "Roosevelt" || to == "J. Ruiz" || to == "Gilmore" || to == "Betty Go" ){
			price = 20;
		}
		else if(to == "Recto" || to == "Legarda" || to == "Pureza" || to == "V. Mapa"){
			price = 25;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Bambang"){
		if(to == "Bambang"){
			
			return 0;
		}
		else if(to == "Pedro Gil" || to == "United Nations" || to == "Carriedo"|| to == "Doroteo Jose" 
		|| to == "Central Terminal" || to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos" 
		|| to == "R. Papa" || to == "5th Avenue"){
			price = 15;
		}
		else if(to == "Vito Cruz" || to == "Quirino" || to == "Baclaran" || to == "EDSA"  || to == "Libertad" 
		|| to == "Gil Puyat"  || to == "Monumento" || to == "Balintawak" || to == "Roosevelt"){
			price = 20;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Tayuman"){
		if(to == "Tayuman"){
			
			return 0;
		}
		else if(to == "United Nations" || to == "Bambang"|| to == "Doroteo Jose" 
		|| to == "Central Terminal" || to == "Carriedo" || to == "Blumentrit" 
		|| to == "Abad Santos" || to == "R. Papa" || to == "5th Avenue" || to == "Monumento"){
			price = 15;
		}
		else if( to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "EDSA" || to == "Libertad" || to == "Gil Puyat" 
		|| to == "Balintawak" || to == "Roosevelt" ){
			price = 20;
		}
		else if(to == "Baclaran"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Blumentrit"){
		if(to == "Blumentrit"){
			
			return 0;
		}
		else if( to == "Bambang"|| to == "Doroteo Jose" 
		|| to == "Central Terminal" || to == "Carriedo" || to == "Tayuman" 
		|| to == "Abad Santos" || to == "R. Papa" || to == "5th Avenue" || to == "Monumento"){
			price = 15;
		}
		else if(to == "United Nations" || to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "Libertad" || to == "Gil Puyat" 
		|| to == "Balintawak" || to == "Roosevelt" ){
			price = 20;
		}
		else if(to == "Baclaran" || to == "EDSA"){
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Abad Santos"){
		if(to == "Abad Santos"){
			
			return 0;
		}
		else if( to == "Bambang"|| to == "Doroteo Jose" 
		|| to == "Central Terminal" || to == "Carriedo" || to == "Tayuman" 
		|| to == "Blumentrit" || to == "R. Papa" || to == "5th Avenue" || to == "Monumento"){
			price = 15;
		}
		else if(to == "United Nations" || to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "Gil Puyat" || to == "Balintawak" || to == "Roosevelt" ){
			price = 20;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad") {
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "R. Papa"){
		if(to == "R. Papa"){
			
			return 0;
		}
		else if( to == "Bambang"|| to == "Doroteo Jose" || to == "Carriedo" 
		|| to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos" 
		|| to == "5th Avenue" || to == "Monumento"|| to == "Balintawak"){
			price = 15;
		}
		else if(to == "United Nations" || to == "Vito Cruz" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "Roosevelt" || to == "Central Terminal" ){
			price = 20;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad" || to == "Gil Puyat") {
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "5th Avenue"){
		if(to == "5th Avenue"){
			
			return 0;
		}
		else if( to == "Bambang"|| to == "Doroteo Jose"  
		|| to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos" 
		|| to == "R. Papa" || to == "Monumento"|| to == "Balintawak"){
			price = 15;
		}
		else if(to == "United Nations" || to == "Quirino" || to == "Pedro Gil" 
		|| to == "Roosevelt" || to == "Central Terminal" || to == "Carriedo" ){
			price = 20;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad" 
		|| to == "Gil Puyat" || to == "Vito Cruz") {
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Monumento"){
		if(to == "Monumento"){
			
			return 0;
		}
		else if(to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos" 
		|| to == "R. Papa" || to == "5th Avenue"|| to == "Balintawak" || to == "Roosevelt"){
			price = 15;
		}
		else if(to == "United Nations" || to == "Pedro Gil" || to == "Bambang"
		|| to == "Doroteo Jose"  || to == "Central Terminal" 
		|| to == "Carriedo" ){
			price = 20;
		}
		else if(to == "Baclaran" || to == "EDSA" || to == "Libertad" 
		|| to == "Gil Puyat" || to == "Vito Cruz" || to == "Quirino") {
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Balintawak"){
		if(to == "Balintawak"){
			
			return 0;
		}
		else if(to == "R. Papa" || to == "5th Avenue"|| to == "Monumento" || to == "Roosevelt"){
			price = 15;
		}
		else if(to == "Tayuman" || to == "Blumentrit" || to == "Abad Santos" || to == "Bambang"
		|| to == "Doroteo Jose"  || to == "Central Terminal" || to == "Carriedo" ){
			price = 20;
		}
		else if(to == "United Nations" || to == "Pedro Gil" ||to == "Baclaran" 
		|| to == "EDSA" || to == "Libertad" || to == "Gil Puyat" || to == "Vito Cruz" 
		|| to == "Quirino") {
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Roosevelt"){
		if(to == "Roosevelt"){
			
			return 0;
		}
		else if( to == "Monumento" || to == "Balintawak"){
			price = 15;
		}
		else if(to == "R. Papa" || to == "5th Avenue"|| to == "Tayuman" 
		|| to == "Blumentrit" || to == "Abad Santos" || to == "Bambang"){
			price = 20;
		}
		else if(to == "United Nations" || to == "Pedro Gil" ||to == "Baclaran" 
		|| to == "EDSA" || to == "Libertad" || to == "Gil Puyat" || to == "Vito Cruz" 
		|| to == "Quirino" || to == "Doroteo Jose"  || to == "Central Terminal" || to == "Carriedo") {
			price = 30;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	
	else if(from == "North Avenue"){
		if(to == "North Avenue"){
			
			return 0;
		}
		else if( to == "Quezon Avenue" || to == "Kamuning"){
			price = 13;
		}
		else if(to == "Cubao" || to == "Santolan"){
			price = 16;
		}
		else if(to == "Ortigas" || to == "Shaw Boulevard" || to == "Boni Avenue") {
			price = 20;
		}
		else if(to == "Guadalupe" || to == "Buendia" || to == "Ayala") {
			price = 24;
		}
		else if(to == "Magallanes" || to == "Taft") {
			price = 28;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Quezon Avenue"){
		if(to == "Quezon Avenue"){
			
			return 0;
		}
		else if( to == "North Avenue" || to == "Kamuning" || to == "Cubao"){
			price = 13;
		}
		else if(to == "Santolan" || to == "Ortigas"){
			price = 16;
		}
		else if(to == "Shaw Boulevard" || to == "Boni Avenue" || to == "Guadalupe") {
			price = 20;
		}
		else if(to == "Buendia" || to == "Ayala" || to == "Magallanes") {
			price = 24;
		}
		else if(to == "Taft") {
			price = 28;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Kamuning"){
		if(to == "Kamuning"){
			
			return 0;
		}
		else if( to == "North Avenue" || to == "Quezon Avenue" || to == "Cubao" || to == "Santolan"){
			price = 13;
		}
		else if(to == "Ortigas" || to == "Shaw Boulevard"){
			price = 16;
		}
		else if(to == "Boni Avenue" || to == "Guadalupe" || to == "Buendia") {
			price = 20;
		}
		else if(to == "Ayala" || to == "Magallanes" || to == "Taft") {
			price = 24;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Cubao"){
		if(to == "Cubao"){
			
			return 0;
		}
		else if(to == "Quezon Avenue" || to == "Kamuning" || to == "Santolan" || to == "Ortigas"){
			price = 13;
		}
		else if(to == "North Avenue" || to == "Shaw Boulevard" || to == "Boni Avenue"){
			price = 16;
		}
		else if(to == "Guadalupe" || to == "Buendia" || to == "Ayala" ) {
			price = 20;
		}
		else if(to == "Magallanes" || to == "Taft") {
			price = 24;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Santolan"){
		if(to == "Santolan"){
			return 0;
		}
		else if(to == "Kamuning" || to == "Cubao" || to == "Ortigas" || to == "Shaw Boulevard"){
			price = 13;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue" || to == "Boni Avenue" || to == "Guadalupe"){
			price = 16;
		}
		else if(to == "Buendia" || to == "Ayala" || to == "Magallanes") {
			price = 20;
		}
		else if(to == "Taft") {
			price = 24;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Ortigas"){
		if(to == "Ortigas"){
			
			return 0;
		}
		else if( to == "Cubao" || to == "Santolan" || to == "Shaw Boulevard" || to == "Boni Avenue"){
			price = 13;
		}
		else if(to == "Quezon Avenue" || to == "Kamuning" || to == "Guadalupe" || to == "Buendia"){
			price = 16;
		}
		else if(to == "North Avenue" || to == "Ayala" || to == "Magallanes" || to == "Taft") {
			price = 20;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Shaw Boulevard"){
		if(to == "Shaw Boulevard"){
			
			return 0;
		}
		else if(to == "Santolan" || to == "Ortigas" || to == "Boni Avenue" || to == "Guadalupe"){
			price = 13;
		}
		else if(to == "Kamuning" || to == "Cubao" || to == "Buendia" ||  to == "Ayala"){
			price = 16;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue" || to == "Magallanes" || to == "Taft") {
			price = 20;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Boni Avenue"){
		if(to == "Boni Avenue"){
			
			return 0;
		}
		else if(to == "Ortigas" || to == "Shaw Boulevard" || to == "Guadalupe" || to == "Buendia"){
			price = 13;
		}
		else if(to == "Cubao" || to == "Santolan" || to == "Ayala" || to == "Magallanes"){
			price = 16;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue" || to == "Kamuning" || to == "Taft") {
			price = 20;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Boni Avenue"){
		if(to == "Boni Avenue"){
			
			return 0;
		}
		else if(to == "Ortigas" || to == "Shaw Boulevard" || to == "Guadalupe" || to == "Buendia"){
			price = 13;
		}
		else if(to == "Cubao" || to == "Santolan" || to == "Ayala" || to == "Magallanes"){
			price = 16;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue" || to == "Kamuning" || to == "Taft") {
			price = 20;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Guadalupe"){
		if(to == "Guadalupe"){
			
			return 0;
		}
		else if(to == "Shaw Boulevard" || to == "Boni Avenue" || to == "Ayala" || to == "Buendia"){
			price = 13;
		}
		else if(to == "Santolan" || to == "Ortigas" ||to == "Magallanes" || to == "Taft"){
			price = 16;
		}
		else if(to == "Quezon Avenue" || to == "Kamuning" || to == "Cubao") {
			price = 20;
		}
		else if(to == "North Avenue") {
			price = 24;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Buendia"){
		if(to == "Buendia"){
			
			return 0;
		}
		else if(to == "Boni Avenue" || to == "Ayala" || to == "Guadalupe" || to == "Magallanes"){
			price = 13;
		}
		else if(to == "Ortigas" || to == "Shaw Boulevard" || to == "Taft"){
			price = 16;
		}
		else if(to == "Kamuning" || to == "Cubao" || to == "Santolan") {
			price = 20;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue") {
			price = 24;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Ayala"){
		if(to == "Ayala"){
			
			return 0;
		}
		else if(to == "Buendia" || to == "Guadalupe" || to == "Magallanes" || to == "Taft"){
			price = 13;
		}
		else if(to == "Shaw Boulevard" || to == "Boni Avenue"){
			price = 16;
		}
		else if(to == "Cubao" || to == "Santolan" || to == "Ortigas") {
			price = 20;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue" || to == "Kamuning") {
			price = 24;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Magallanes"){
		if(to == "Magallanes"){
			
			return 0;
		}
		else if(to == "Buendia" || to == "Ayala" || to == "Taft"){
			price = 13;
		}
		else if(to == "Boni Avenue" || to == "Guadalupe"){
			price = 16;
		}
		else if(to == "Santolan" || to == "Ortigas" || to == "Shaw Boulevard") {
			price = 20;
		}
		else if(to == "Quezon Avenue" || to == "Kamuning" || to == "Cubao") {
			price = 24;
		}
		else if(to == "North Avenue") {
			price = 28;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	else if(from == "Taft"){
		if(to == "Taft"){
			
			return 0;
		}
		else if(to == "Ayala" || to == "Magallanes"){
			price = 13;
		}
		else if(to == "Buendia" || to == "Guadalupe"){
			price = 16;
		}
		else if(to == "Ortigas" || to == "Shaw Boulevard" || to == "Boni Avenue") {
			price = 20;
		}
		else if(to == "Kamuning" || to == "Cubao" || to == "Santolan") {
			price = 24;
		}
		else if(to == "North Avenue" || to == "Quezon Avenue") {
			price = 28;
		}
		else{
			cout << "Incorrect Input. Try Again.";
			return 0;
		}
	}
	return price;
}

void viewAllTrans() { 
	data *temp = new data; 
	int count=0;
	int totalSales=0, t1=0, t2=0, t3=0;
	temp = head; 
	cout << "\n\n\n\n\n\t-----------------------------------Summary of All Transactions-----------------------------------" <<endl;
	cout << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
	if (temp == NULL){
		cout << "\n\t\t No Transaction Recorded Yet" << endl;
		return;
	}
	
	while (temp != NULL) { 
		if (temp->modeOfTrans == "Reloading Stored Value"){
			cout << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << endl; 

		}
		else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
			cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << endl; 

		}
		else{
			cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << endl; 
		}		
		temp = temp->next;
		count++;
	}
	cout << "\n\t\t\t\t   Total Number of Transactions: " << count << endl;
	
	count = 0;
	temp = head;
	while(temp != NULL){
		if (temp->modeOfTrans == "Single Journey"){
			count++;
		}
		temp = temp->next;
	}
	cout << "\n\t\t\t\t   Total Number of Single Journey Card Released: " <<  count << endl;
	
	count = 0;
	temp = head;
	while(temp != NULL){
		if (temp->modeOfTrans == "Stored Value"){
			count++;
		}
		temp = temp->next;
	}
	cout << "\n\t\t\t\t   Total Number of Stored Value Card Released: " <<  count << endl;
	
	temp = head;
	while(temp != NULL){
		if (temp->modeOfTrans == "Single Journey"){
				t1 = t1 + stoi(temp->load); 
			}
			else if (temp->modeOfTrans == "Stored Value"){
				t2 = t2 + 100;
			}
			else if (temp->modeOfTrans == "Reloading Stored Value"){
				t3 = t3 + stoi(temp->fee);
			}
		temp = temp->next;
	}
	totalSales = t1 + t2 + t3;
	cout << "\n\t\t\t\t   Total Sales of All Railways Systems is: P" << totalSales << endl;
	return; 
}

void print(){
	data *temp = new data; 
	int count=0;
	int totalSales=0, t1=0, t2=0, t3=0;
	ofstream file;
	string filename;
	cout << "\n\t\t\t Enter File Name: \t";
	cin >> filename; 
	file.open(filename);
	temp = head; 
	file << "\t-----------------------------------Summary of All Transactions-----------------------------------" <<endl;
	file << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
	if (temp == NULL){
		file << "\n\t\t No Transaction Recorded Yet" << endl;
		file.close();
		return;
	}
	while (temp != NULL) { 
		if (temp->modeOfTrans == "Reloading Stored Value"){
			file << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 

		}
		else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
			file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 

		}
		else{
			file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		}		
		temp = temp->next;
		count++;
	}
	file << "\n\t\t\t\t   Total Number of Transactions: " << count << endl;
	
	count = 0;
	temp = head;
	while(temp != NULL){
		if (temp->modeOfTrans == "Single Journey"){
			count++;
		}
		temp = temp->next;
	}
	file << "\n\t\t\t\t   Total Number of Single Journey Card Released: " <<  count << endl;
	
	count = 0;
	temp = head;
	while(temp != NULL){
		if (temp->modeOfTrans == "Stored Value"){
			count++;
		}
		temp = temp->next;
	}
	file << "\n\t\t\t\t   Total Number of Stored Value Card Released: " <<  count << endl;
	
	temp = head;
	while(temp != NULL){
		if (temp->modeOfTrans == "Single Journey"){
				t1 = t1 + stoi(temp->load); 
			}
			else if (temp->modeOfTrans == "Stored Value"){
				t2 = t2 + 100;
			}
			else if (temp->modeOfTrans == "Reloading Stored Value"){
				t3 = t3 + stoi(temp->fee);
			}
		temp = temp->next;
	}
	totalSales = t1 + t2 + t3;
	file << "\n\t\t\t\t   Total Sales of All Railways Systems is: P" << totalSales << endl;
	file.close();
	return; 
}

void allLRT1(){
	data *temp = new data; 
	int count=0, choice;
	int totalSales=0, t1=0, t2=0, t3=0;
	temp = head;
	cout << "\n\n\n\n\n\t-----------------------------------Sales Report of LRT1 Transactions-----------------------------------" <<endl;
	cout << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
	if (temp == NULL){
		cout << "\n\t\t No Transaction Recorded Yet "<< endl;
		return;
	}
	
	while (temp != NULL) { 
		if ("LRT1" == temp->station){
			if (temp->modeOfTrans == "Reloading Stored Value"){
				cout << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
	
			}
			else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
				cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
	
			}
			else{
				cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
			}		
			count++;
		}
		temp = temp->next;
	}
	cout << "\n\t\t\t\t   Total Number of LRT1 Transactions: " << count << endl;
	temp = head;
	while(temp != NULL){
		if ("LRT1" == temp->station){
			if (temp->modeOfTrans == "Single Journey"){
				t1 = t1 + stoi(temp->load); 
			}
			else if (temp->modeOfTrans == "Stored Value"){
				t2 = t2 + 100;
			}
			else if (temp->modeOfTrans == "Reloading Stored Value"){
				t3 = t3 + stoi(temp->fee);
			}
		}
		temp = temp->next;
	}
	totalSales = t1 + t2 + t3;
	cout << "\n\t\t\t\t   Total Sales of LRT1 is: P" << totalSales << endl;
	
	
	cout << "\n\t\t\t Print Sales Report? [1] - Yes or [2] - No\t" ;
	cin >> choice;
	while(choice > 2){
		cout << "\n\t\t\t Print Sales Report? [1] - Yes or [2] - No\t" ;
		cin >> choice;
	}
	if (choice == 1){
		count=0; totalSales=0; t1=0; t2=0; t3=0;
		ofstream file;
		string filename;
		cout << "\n\t\t\t Enter File Name: \t";
		cin >> filename; 
		file.open(filename);
		temp = head;
		
		file << "\n\n\n\n\n\t-----------------------------------Sales Report of LRT1 Transactions-----------------------------------" <<endl;
		file << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
		if (temp == NULL){
			file << "\n\t\t No Transaction Recorded Yet "<< endl;
			return;
		}
		while (temp != NULL) { 
			if ("LRT1" == temp->station){
				if (temp->modeOfTrans == "Reloading Stored Value"){
					file << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		
				}
				else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
					file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		
				}
				else{
					file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
				}		
				count++;
			}
			temp = temp->next;
		}
		file << "\n\t\t\t\t   Total Number of LRT1 Transactions: " << count << endl;
		temp = head;
		while(temp != NULL){
			if ("LRT1" == temp->station){
				if (temp->modeOfTrans == "Single Journey"){
					t1 = t1 + stoi(temp->load); 
				}
				else if (temp->modeOfTrans == "Stored Value"){
					t2 = t2 + 100;
				}
				else if (temp->modeOfTrans == "Reloading Stored Value"){
					t3 = t3 + stoi(temp->fee);
				}
			}
			temp = temp->next;
		}
		totalSales = t1 + t2 + t3;
		file << "\n\t\t\t\t   Total Sales of LRT1 is: P" << totalSales << endl;
		file.close();
	}
	return;
}

void allLRT2(){
	data *temp = new data; 
	int count=0, choice;
	int totalSales=0, t1=0, t2=0, t3=0;
	temp = head;
	cout << "\n\n\n\n\n\t-----------------------------------Sales Report of LRT2 Transactions-----------------------------------" <<endl;
	cout << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
	if (temp == NULL){
		cout << "\n\t\t No Transaction Recorded Yet "<< endl;
		return;
	}
	
	while (temp != NULL) { 
		if ("LRT2" == temp->station){
			if (temp->modeOfTrans == "Reloading Stored Value"){
				cout << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
	
			}
			else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
				cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
	
			}
			else{
				cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
			}		
			count++;
		}
		temp = temp->next;
	}
	cout << "\n\t\t\t\t   Total Number of LRT2 Transactions: " << count << endl;
	temp = head;
	while(temp != NULL){
		if ("LRT2" == temp->station){
			if (temp->modeOfTrans == "Single Journey"){
				t1 = t1 + stoi(temp->load); 
			}
			else if (temp->modeOfTrans == "Stored Value"){
				t2 = t2 + 100;
			}
			else if (temp->modeOfTrans == "Reloading Stored Value"){
				t3 = t3 + stoi(temp->fee);
			}
		}
		temp = temp->next;
	}
	totalSales = t1 + t2 + t3;
	cout << "\n\t\t\t\t   Total Sales of LRT2 is: P" << totalSales << endl;
	
	cout << "\n\t\t\t Print Sales Report? [1] - Yes or [2] - No\t" ;
	cin >> choice;
	while(choice > 2){
		cout << "\n\t\t\t Print Sales Report? [1] - Yes or [2] - No\t" ;
		cin >> choice;
	}
	if (choice == 1){
		count=0; totalSales=0; t1=0; t2=0; t3=0;
		ofstream file;
		string filename;
		cout << "\n\t\t\t Enter File Name: \t";
		cin >> filename; 
		file.open(filename);
		temp = head;
		
		file << "\n\n\n\n\n\t-----------------------------------Sales Report of LRT2 Transactions-----------------------------------" <<endl;
		file << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
		if (temp == NULL){
			file << "\n\t\t No Transaction Recorded Yet "<< endl;
			return;
		}
		while (temp != NULL) { 
			if ("LRT2" == temp->station){
				if (temp->modeOfTrans == "Reloading Stored Value"){
					file << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		
				}
				else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
					file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		
				}
				else{
					file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
				}		
				count++;
			}
			temp = temp->next;
		}
		file << "\n\t\t\t\t   Total Number of LRT2 Transactions: " << count << endl;
		temp = head;
		while(temp != NULL){
			if ("LRT2" == temp->station){
				if (temp->modeOfTrans == "Single Journey"){
					t1 = t1 + stoi(temp->load); 
				}
				else if (temp->modeOfTrans == "Stored Value"){
					t2 = t2 + 100;
				}
				else if (temp->modeOfTrans == "Reloading Stored Value"){
					t3 = t3 + stoi(temp->fee);
				}
			}
			temp = temp->next;
		}
		totalSales = t1 + t2 + t3;
		file << "\n\t\t\t\t   Total Sales of LRT2 is: P" << totalSales << endl;
		file.close();
	}
	return;
}

void allMRT(){
	data *temp = new data; 
	int count=0, choice;
	int totalSales=0, t1=0, t2=0, t3=0;
	temp = head;
	cout << "\n\n\n\n\n\t-----------------------------------Sales Report of MRT Transactions-----------------------------------" <<endl;
	cout << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
	if (temp == NULL){
		cout << "\n\t\t No Transaction Recorded Yet "<< endl;
		return;
	}
	
	while (temp != NULL) { 
		if ("MRT" == temp->station){
			if (temp->modeOfTrans == "Reloading Stored Value"){
				cout << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
	
			}
			else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
				cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
	
			}
			else{
				cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
			}		
			count++;
		}
		temp = temp->next;
	}
	cout << "\n\t\t\t\t   Total Number of MRT Transactions: " << count << endl;
	temp = head;
	while(temp != NULL){
		if ("MRT" == temp->station){
			if (temp->modeOfTrans == "Single Journey"){
				t1 = t1 + stoi(temp->load); 
			}
			else if (temp->modeOfTrans == "Stored Value"){
				t2 = t2 + 100;
			}
			else if (temp->modeOfTrans == "Reloading Stored Value"){
				t3 = t3 + stoi(temp->fee);
			}
		}
		temp = temp->next;
	}
	totalSales = t1 + t2 + t3;
	cout << "\n\t\t\t\t   Total Sales of MRT is: P" << totalSales << endl;
	
	cout << "\n\t\t\t Print Sales Report? [1] - Yes or [2] - No\t" ;
	cin >> choice;
	while(choice > 2){
		cout << "\n\t\t\t Print Sales Report? [1] - Yes or [2] - No\t" ;
		cin >> choice;
	}
	if (choice == 1){
		count=0; totalSales=0; t1=0; t2=0; t3=0;
		ofstream file;
		string filename;
		cout << "\n\t\t\t Enter File Name: \t";
		cin >> filename; 
		file.open(filename);
		temp = head;
		
		file << "\n\n\n\n\n\t-----------------------------------Sales Report of MRT Transactions-----------------------------------" <<endl;
		file << "	Mode Of Transaction: \t From Station: \t To Station: \t Load: \t\t Change: \t Stamp Number:\n";
		if (temp == NULL){
			file << "\n\t\t No Transaction Recorded Yet "<< endl;
			return;
		}
		while (temp != NULL) { 
			if ("MRT" == temp->station){
				if (temp->modeOfTrans == "Reloading Stored Value"){
					file << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		
				}
				else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
					file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
		
				}
				else{
					file << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
				}		
				count++;
			}
			temp = temp->next;
		}
		file << "\n\t\t\t\t   Total Number of MRT Transactions: " << count << endl;
		temp = head;
		while(temp != NULL){
			if ("MRT" == temp->station){
				if (temp->modeOfTrans == "Single Journey"){
					t1 = t1 + stoi(temp->load); 
				}
				else if (temp->modeOfTrans == "Stored Value"){
					t2 = t2 + 100;
				}
				else if (temp->modeOfTrans == "Reloading Stored Value"){
					t3 = t3 + stoi(temp->fee);
				}
			}
			temp = temp->next;
		}
		totalSales = t1 + t2 + t3;
		file << "\n\t\t\t\t   Total Sales of MRT is: P" << totalSales << endl;
		file.close();
	}
	return;
}

void search(){
	data *temp = new data; 
	int choice;
	temp = head;
	if (temp == NULL){
		cout << "\n\t\t No Transaction Recorded Yet"<< endl;
		return;
	}
	string Trans;
	cout << "\n\t\t\tSearch Mode of Transaction: ";
	cin.ignore(100,'\n');
	getline(cin, Trans);
	cout << "\t-----------------------------------All " << Trans << "-----------------------------------"<< endl;
	while(temp != NULL){
		if (Trans == temp->modeOfTrans){
			if (temp->modeOfTrans == "Reloading Stored Value"){
				cout << " \t" << temp->modeOfTrans << " \t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
			}
			else if ((temp->fromStation != "N/A") && (temp->toStation != "N/A")){
						cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t " << temp->toStation << " \t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
			}
			else{
					cout << " \t" << temp->modeOfTrans << " \t\t " << temp->fromStation << " \t\t " << temp->toStation << " \t\t " << temp->load << " \t\t " << temp->change << " \t\t " << temp->storedStamp << " "<< endl; 
			}		
		}
		temp = temp->next;
	}
	return;
}

void deleteBetweenNodes() {
	//1 as start index
	data *body = new data; 
 	data *temp = new data;  
 	data *temp1 = new data; 
 	temp1 = head;
 	if (temp1 == NULL){
		cout << "\n\t\t No Transaction Recorded Yet"<< endl;
		return;
	}
	int position; 
 	cout << "\n\t\t\tDelete at position? (Starts at 1): ";  
	cin >> position;  
	
	temp=head;
	if(position==1){
		head=temp->next;
	}
	for (int i=0;i<position-1;i++){
		body = temp;
		temp = temp->next;
	}
	body->next = temp->next;
	delete temp;
 	return; 
}

void editBetweenNodes(){
	data *temp = new data;
	data *temp1 = new data; 
 	temp1 = head;
 	if (temp1 == NULL){
		cout << "\n\t\t No Transaction Recorded Yet"<< endl;
		return;
	}
	int position;
	cout<<"\n\t\t\tEdit at position (Starts from 1): ";
	cin>>position;
	
	temp = head;
	for (int i=0;i<position-1;i++){
		temp = temp->next;
	}
	
	cout << "\n\t\t\tMode of Transaction: ";
	cin.ignore(100,'\n');
	getline(cin, temp->modeOfTrans);
	cout << "\t\t\tFrom Station: ";
	getline(cin, temp->fromStation);
	cout << "\t\t\tTo Station: ";
	getline(cin, temp->toStation);
	cout << "\t\t\tLoad: ";
	cin >> temp->load;
	cout << "\t\t\tChange: ";
	cin >> temp->change;
	cout << "\t\t\tStampNum: ";
	cin >> temp->storedStamp;
	cout << "\t\t\tStampNum: ";
	return;
}

void transactionSlip(string fromstation, string tostation, string change, string load, string modeoftrans, string stampnum){
	cout << "\n\tTransaction Slip: " << endl;
	cout << "\n\t---------------------------------------------------------------------------------" << endl;
 	cout << "\t|	From Station: " << fromstation << "\t\t\t\t\t\t\t|"<< endl;
 	cout << "\t|	To Station: " << tostation << "\t\t\t\t\t\t\t|"<< endl;
 	if (modeoftrans == "Reloading Stored Value"){
 		cout << "\t|	Mode of Transaction: " << modeoftrans << "\t\t\t\t|"<< endl;
	 }else{
	 	cout << "\t|	Mode of Transaction: " << modeoftrans << "\t\t\t\t\t|"<< endl;
	 }
 	cout << "\t|	Load: " << load << "\t\t\t\t\t\t\t\t|"<< endl;
 	if (stampnum == "0"){
 		cout << "\t|	Stamp Number: " << stampnum << "\t\t\t\t\t\t\t\t|"<< endl;
	 }else{
	 	cout << "\t|	Stamp Number: " << stampnum << "\t\t\t\t\t\t\t|"<< endl;
	 }
	cout << "\t|	Change: " << change<< "\t\t\t\t\t\t\t\t|"<< endl;
	cout << "\t---------------------------------------------------------------------------------" << endl;
	return;
}
