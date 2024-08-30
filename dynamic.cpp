#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int Burronacci(int n){
    if(n < 2){
        return n + 1;
    }

    return 4 * Burronacci(n - 1) + 2 * Burronacci(n - 2);
    
}

// Complejidad: O(2^n)

int main(){

    int number;

    cout << "Insertar número: " << endl;
    cin >> number;

    int result = Burronacci(number);

    cout << result << endl;

    return 0;
}