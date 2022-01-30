#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<filesystem>


using namespace std;
using std::filesystem::exists;


// Model - Plate N. - characteristics - price - rent calcul - available cars
class car{
    private:
    string modelA = "Renault"; int stockA=1,priceA=25;//files
    string modelB = "Volkswagen"; int stockB=6,priceB=35;
    string modelC = "Tesla"; int stockC=4,priceC=45;


    public:
    void ChooseCar(string name,string LN){
        char choice;int days;
        system("cls");
        cout <<"\n\t\t\t\t\t\t  Choose a car for "<<name<<" #"<<LN<<endl;
        cout<<"\t\t\t\t\t-------------------------------------------------------\n";	
        cout <<"\n\t\t\t\t\t\t\t   A : "<<modelA<<endl;
        cout <<"\n\t\t\t\t\t\t\t   B : "<<modelB<<endl;
        cout <<"\n\t\t\t\t\t\t\t   C : "<<modelC<<endl;
        cout <<"\n\t\t\t\t\t\t\t Your choice : ";
        cin >> choice;
        cout <<"\n\t\t\t\t\t\t\t   Days : ";
        cin >> days;
        
        if(choice =='A'){
            if(stockA>0){
                cout << "\nMarhba\n";
                stockA-=1;
            }
            else    
                cout<<"No more carmodel available\n";
        }

        else if(choice =='B'){

        }

        else if(choice =='C'){
            
        }

        else
            cout<<"Please enter a correct choice !\n";


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
    welcome();
    A.Login();
    customer Ab;
    Ab.Info();

    
    
    system("PAUSE");
    return 0;
    
}