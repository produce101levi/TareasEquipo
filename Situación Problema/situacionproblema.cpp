#include <iostream>
#include <fstream>

using namespace std;

void getZarr(string str, int Z[]);

bool search(string text, string pattern);

void findPattern();

int main(){
    
    findPattern();


    return 0;
}

bool search(string text, string pattern)
{

    string concat = pattern + "$" + text;
    int l = concat.length();

    int Z[l];
    getZarr(concat, Z);

    // Print Z array
    // for (int i = 0; i < l; i++){
    //     if (i != l - 1){
    //         cout << Z[i] << ", ";
    //     } else {
    //         cout << Z[i] << endl;
    //     }
    // }

    for (int i = 0; i < l; ++i)
    {
  
        if (Z[i] == pattern.length()){
            printf("Patrón %s encontrado en índice Z[%zu]\n", pattern.c_str(), i - pattern.length() - 1);
            return true;
        }
    }
    return false;
}

// Fills Z array for given string str[]
void getZarr(string str, int Z[])
{
    int n = str.length();
    int k, R, L;

    L = R = 0;
    for (int i = 1; i < n; i++){
        if(i > R){
            L = R = i;

            // Extend the Z window
            while(R < n && str[R-L] == str[R]){
                R++;
            }
            Z[i] = R-L;
            R--;
        }else{
            k = i - L;
            if(Z[k] < R - i + 1){
                Z[i] = Z[k];
            }else{
                L = i;
                while(R < n && str[R-L] == str[R]){
                    R++;
                }
                Z[i] = R-L;
                R--;
            }
        }
    }
}

void findPattern(){

    string myText1;
    string myText2;
    string pattern1;
    string pattern2;
    string pattern3;
    string line;

    ifstream myReadFile1("transmission01.txt");
    ifstream myReadFile2("transmission02.txt");

    ifstream mCode1("mcode01.txt");
    ifstream mCode2("mcode02.txt");
    ifstream mCode3("mcode03.txt");

    vector<string> trans1;
    vector<string> trans2;

    // Transimission 01
    while(getline(myReadFile1, myText1)){
        trans1.push_back(myText1);
    }

    // Transimission 02
    while(getline(myReadFile2, myText2)){
        trans2.push_back(myText2);
    }

    while(getline(mCode1, line)){
        pattern1 += line;
    }

    while(getline(mCode2, line)){
        pattern2 += line;
    }

    // Malicious Pattern 3
    while(getline(mCode3, line)){
        pattern3 += line;
    }

    myReadFile1.close();
    myReadFile2.close();
    mCode1.close();
    mCode2.close();
    mCode3.close();


    cout << "-=- TRANSMISIÓN 01 -=-" << endl;
    for(int i = 0; i < trans1.size(); i++){
        cout << "--- Línea " << i + 1 << " ---" << endl;
        bool patternFound1 = search(trans1[i], pattern1);
        bool patternFound2 = search(trans1[i], pattern2);
        bool patternFound3 = search(trans1[i], pattern3);
        if (patternFound1 == 1 || patternFound2 == 1 || patternFound3 == 1){
            cout << "Patrón Encontrado: True" << endl;
        } else {
            cout << "Patrón Encontrado: False" << endl;
        }
    }
    cout << endl;
    
    cout << "-=- TRANSMISIÓN 02 -=-" << endl;
    for(int i = 0; i < trans2.size(); i++){
        cout << "--- Línea " << i + 1 << " ---" << endl;
        bool patternFound1 = search(trans2[i], pattern1);
        bool patternFound2 = search(trans2[i], pattern2);
        bool patternFound3 = search(trans2[i], pattern3);
        if (patternFound1 == 1 || patternFound2 == 1 || patternFound3 == 1){
            cout << "Patrón Encontrado: True" << endl;
        } else {
            cout << "Patrón Encontrado: False" << endl;
        }
    }
}