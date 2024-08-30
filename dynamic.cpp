#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Burronacci(int n){
    if(n < 2){
        return n;
    }

    return 4 * Burronacci(n - 1) + 2 * Burronacci(n - 2);
    
}


int main(){

    int result = Burronacci(2);

    cout << result << endl;

    return 0;
}