#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void welcome(){
    ifstream welcome_file("welcome.txt");

    if (welcome_file.is_open()){
        cout << welcome_file.rdbuf();
    }
    cout << "\n";
}

int main()
{   
    string name;
    welcome();
    cin >> name;
    cout << "\n \tWelcome "<<name<<endl;
    system("PAUSE");
}