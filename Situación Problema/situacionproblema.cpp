#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string myText1;
    string myText2;
    string myText3;
    string myText4;
    string myText5;

    ifstream myReadFile1("transmission01.txt");
    ifstream myReadFile2("transmission02.txt");
    ifstream myReadFile3("mcode01.txt");
    ifstream myReadFile4("mcode02.txt");
    ifstream myReadFile5("mcode03.txt");

    cout << "-=- TEXT 1 -=-" << endl;
    while(getline(myReadFile1, myText1)){
        cout << myText1 << endl;
    }

    cout << "-=- TEXT 2 -=-" << endl;
    while(getline(myReadFile2, myText2)){
        cout << myText2 << endl;
    }

    cout << "-=- TEXT 3 -=-" << endl;
    while(getline(myReadFile3, myText3)){
        cout << myText3 << endl;
    }

    cout << "-=- TEXT 4 -=-" << endl;
    while(getline(myReadFile4, myText4)){
        cout << myText4 << endl;
    }

    cout << "-=- TEXT 5 -=-" << endl;
    while(getline(myReadFile5, myText5)){
        cout << myText5 << endl;
    }

    myReadFile1.close();
    myReadFile2.close();
    myReadFile3.close();
    myReadFile4.close();
    myReadFile5.close();

    return 0;
}