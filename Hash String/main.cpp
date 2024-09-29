#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    string inputName;
    string line;
    cout << "Ingresa el nombre del archivo (sin extensión): ";
    cin >> inputName;
    ifstream myFile(inputName + ".txt");

    while(getline(myFile, line)){
        cout << line << endl;
    }
      
    return 0;
}