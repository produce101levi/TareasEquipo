#include <iostream>
#include <fstream>

using namespace std;

void getZarr(string str, int Z[]);


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


int main(){
    
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

    cout << "-=- MALICIOUS PATTERN -=-" << endl;
    while(getline(mCode1, line)){
        pattern1 += line;
    }

    cout << "-=- MALICIOUS PATTERN -=-" << endl;
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


    cout << "Transmission 01:" << endl;
    for(int i = 0; i < trans1.size(); i++){
        cout << "LINE " << i + 1 << endl;
        bool patternFound = search(trans1[i], pattern3);
        if (patternFound == 1){
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }

    // search("abclevi", "levi");

    return 0;
}
