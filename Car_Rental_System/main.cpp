#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<filesystem>
#include <sstream>


using namespace std;
using std::filesystem::exists;


// Model - Plate N. - characteristics - price - rent calcul - available cars
class car{
    private:
    string modelA = "Renault"; int stockA,priceA=25;//files
    string modelB = "Volkswagen"; int stockB,priceB=35;
    string modelC = "Tesla"; int stockC,priceC=45;

    friend class customer;

    car(){   
        //ofstream stockfile;  
        int cpt=1;
        ifstream stockfile("stock.txt");
        string num;     
        while (getline(stockfile, num)) {
            if(cpt==1)
                stockA=stoi(num);
            if(cpt==2)
                stockB=stoi(num); 
            if(cpt==3)
                stockC=stoi(num); 

            cpt+=1;    
        }
    }

    void removeCar(string model,int sA, int sB, int sC){
    
        if(model==modelA){
            sA-=1;
            stockA-=1;
            }            
        
        if(model==modelB){ 
            sB-=1;
            stockB-=1;   
            }    
            
        if(model==modelC){
            sC-=1;       
            stockC-=1;
            }

        ofstream file;
        file.open("stock.txt",ios::out);//write
        
        if(file.is_open()){
            file << sA <<endl<<sB <<endl<<sC;
            file.close();
        }

    }

    public:
    
    void ChooseCar(string name,string LN){
        char choice;
        system("cls");
        cout <<"\n\t\t\t\t\t\t  Choose a car for "<<name<<" #"<<LN<<endl;
        cout<<"\t\t\t\t\t-------------------------------------------------------\n";	
        cout <<"\n\t\t\t\t\t\t\t   A : "<<modelA<<endl;
        cout <<"\n\t\t\t\t\t\t\t   B : "<<modelB<<endl;
        cout <<"\n\t\t\t\t\t\t\t   C : "<<modelC<<endl;
        cout <<"\n\t\t\t\t\t\t\t Your choice : ";
        cin >> choice;
 
       
        if(choice=='A'){ 
            if(stockA>0){
            cout << "\n You chosen "<< modelA<<endl;
            removeCar(modelA,stockA,stockB,stockC);
            cout <<"Cars left: "<<stockA<<endl;
            rent(modelA);
             }
            else{    
                cout<<"No more carmodel available, please choose another model\n";
                system("PAUSE");
                ChooseCar(name,LN);
            }
        }
        
        else if(choice=='B'){
            if(stockB>0){
            cout << "\n You chosen "<< modelB<<endl;
            removeCar(modelB,stockA,stockB,stockC);
            cout <<"Cars left: "<<stockB<<endl;
            rent(modelB);
            }
            else{    
                cout<<"No more carmodel available, please choose another model\n";
                system("PAUSE");
                ChooseCar(name,LN);}
        }

        else if(choice=='C') {
            if(stockC>0){
                cout << "\n You chosen\n";
                removeCar(modelC,stockA,stockB,stockC);
                cout <<"Cars left: "<<stockC<<endl;
                rent(modelC);
                
            }
            else {   
                cout<<"No more carmodel available, please choose another model\n";
                system("PAUSE");
                ChooseCar(name,LN);}
        }

        else{
            cout<<"\n \t\t\t\t Please enter a correct choice !\n";
           // system("PAUSE");
            system ("CLS");
            ChooseCar(name,LN);
            }
    }

    void rent(string model){
        int days; int payment;
        cout<<"How many days to rent ?"<<endl; cin >> days;

        if(model==modelA){
            payment=days*priceA;
        }
        else if(model==modelB){
            payment=days*priceB;
        }
        else 
            payment=days*priceC;

        cout<<"You should pay "<<payment<<endl;
        system("PAUSE");
        return;
    }
};

// Name - Driving licence N. - historique
class customer: public car{
    private:
    string name,LicenceNumber;
 
    public:
    void Info(){
        cout <<"\n\t\t\t\t\t\t Let's enter the customer informations"<<endl;
        cout<<"\t\t\t\t\t-------------------------------------------------------\n";	
        cout<<"\t\t\t\t\t Name: ";
        cin >> name;

        ofstream file;
        string str;
        int cpt=1;

        if(exists(name+".txt")){ 
            cout<<"\n\t\t\t\t\t\t\t Old customer\n";
    
            ifstream file(name+".txt");
            
            while (getline(file, str)) {
                if(cpt==1)
                    name=str;
                if(cpt==2)
                    LicenceNumber=str; 

                cpt+=1;    
            }
            
            
            cout << "\n\t\t\t\t\t\t Name : " <<name<< " - Licence Number : "<< LicenceNumber <<endl;
            ChooseCar(name,LicenceNumber);
        }

        else{ 
            cout<<"\t\t\t\t\t LicenceNumber: ";
            cin >> LicenceNumber;
            file.open(name+".txt",ios::out);//write
            
            if(file.is_open()){
                cout<<"\n\t\t\t\t\t\t\t New Customer"<<endl;
                file << name << "\n"<< LicenceNumber;
                file.close();
              }

            ChooseCar(name,LicenceNumber);
        }
        return;
    }
    
};


class user : public customer{
    private:
    string password="pass";

    public:
    void Login(){
        char ch;
        string pass;
        cout<<"\n\t\t\t\t\tEnter Password : ";
        ch = _getch();
        while(ch != 13){//character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
        }
        cout << "\n";
    
        if (pass==password){
            cout << "\t\t\t\t\tSuccesfly logged in!"<<endl;
            system("CLS");
            Info();
        }
        else{
            cout << "\t\t\t\t\tWrong Password \n\t\t\t\t\t\tTry again !"<<endl;
            cout << "	----------------------------------------------------------------------------------------------"<<endl;
            system("CLS");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t       CAR RENTAL SYSTEM \n";
            cout<<"\t\t\t\t\t------------------------------";
            cout<<"\n\t\t\t\t\t\t     LOGIN \n";	
            cout<<"\t\t\t\t\t------------------------------\n";	
            Login();
            }
    }

};




void welcome(){
    ifstream welcome_file("welcome.txt");

    if (welcome_file.is_open()){
        cout << welcome_file.rdbuf();
    }
    cout << "\n";
    cout << "	----------------------------------------------------------------------------------------------"<<endl;
  }


int main(){   
   //customer A;
    user A;
    //welcome();
    //A.Login();
    customer Ab;
    Ab.Info();

    
    cout << "Thank You!"<<endl;
    system("PAUSE");
    return 0;
    
}