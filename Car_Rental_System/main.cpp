#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

using namespace std;

class user{
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
            return;
        }
        else
            cout << "\t\t\t\t\tWrong Password \n\t\t\t\t\t\tTry again !"<<endl;
            cout << "	----------------------------------------------------------------------------------------------"<<endl;
  
            Login();
    }

};

// Name - Driving licence N. - historique
class customer{
    public:
    string name,licence;

    
};

// Model - Plate N. - characteristics - price - rent calcul - available cars
class car{
    public:
    string model;

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
    system("PAUSE");
    
}