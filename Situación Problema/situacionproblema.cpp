#include <iostream>
#include <fstream>

using namespace std;

void readFiles(){
    string myText1;
    string myText2;
    string myText3;
    string myText4;
    string myText5;

    ifstream myReadFile1("transmission01.txt");
    ifstream myReadFile2("transmission02.txt");

    ifstream mCode1("mcode01.txt");
    ifstream mCode2("mcode02.txt");
    ifstream mCode3("mcode03.txt");

    cout << "-=- TEXT 1 -=-" << endl;
    while(getline(myReadFile1, myText1)){
        cout << myText1 << endl;
    }

    cout << "-=- TEXT 2 -=-" << endl;
    while(getline(myReadFile2, myText2)){
        cout << myText2 << endl;
    }

    cout << "-=- MALICIOUS PATTERN -=-" << endl;
    while(getline(mCode1, myText3)){
        cout << myText3 << endl;
    }

    cout << "-=- MALICIOUS PATTERN -=-" << endl;
    while(getline(mCode2, myText4)){
        cout << myText4 << endl;
    }

    cout << "-=- MALICIOUS PATTERN -=-" << endl;
    while(getline(mCode3, myText5)){
        cout << myText5 << endl;
    }

    myReadFile1.close();
    myReadFile2.close();
    mCode1.close();
    mCode2.close();
    mCode3.close();

}

int main(){
    
    readFiles();
    
    return 0;
}