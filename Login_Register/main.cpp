#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isLoggedIn(){
    string username,password, un, pw;
    cout << "Enter username : " << endl;
    cin >> username;

    cout << "Enter password : " << endl;
    cin >> password;

    ifstream read( username + ".txt");
    getline(read,un);
    getline(read,pw);

    if(un==username && pw==password){
        return true;
    }
    else 
        return false;
}


int main(){

    int choise;

    cout << "*****************"<< endl;
    cout << "1:Register"<< endl;
    cout << "2:Login"<< endl;
    cout << "3:Exit"<< endl;
    cout << "*****************"<< endl;
    cout << "Your choise : ";
    cin >> choise;
    
    if(choise==1){
        string username,password;

        cout << "Select a username : "; cin >> username;
        cout << "Select a password : "; cin >> password;

        ofstream file;
        file.open(username+".txt",ios::out);//write
        
        if(file.is_open()){
            file << username <<endl << password;
            file.close();
        }

        main();

    }
    else if (choise ==2){
        bool status=isLoggedIn();   

        if(!status){

            cout << "False Login!"<<endl;
            system("PAUSE");
            //return 0;
            main();
        }
        else{

            cout << "Succesfully logged in!"<<endl;
            system("PAUSE");
           //return 0;
            main();
        }
    }

    else if (choise==3){
            cout<<"Exiting..."<<endl;
            exit(0);
    }
    cout << "*****************"<< endl;

 return 0;
}