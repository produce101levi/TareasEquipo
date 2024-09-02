#include <iostream>

using namespace std;

// Función para determinar la cantidad de cada moneda a regresar
vector<int> coinChange(int n, vector<int> coins, int p, int q){
    vector<int> result;
    int change = abs(p - q);
    // O(1)

    sort(coins.begin(), coins.end(), greater<int>());
    // O(n log n)

    // Ciclo para restar del cambio el valor de la moneda
    // y además aumentar el valor del contador
    for (int i = 0; i < n; i++){
        int counter = 0;
        while(change >= coins[i]){
            change -= coins[i];
            counter++;
        }
        result.push_back(counter);
    }
    // Complejidad: O(n)

    return result;
}

int main(){

    int n; // Número de monedas disponibles
    vector<int> coins; // Valores de cada moneda
    int p; // Precio del producto
    int q; // Billete utilizado para pagar

    cout << "Inserta número de monedas disponibles N: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        int value;
        cout << "Inserta el valor de la moneda #" << i + 1 << endl;
        cin >> value;
        coins.push_back(value);
    }
    cout << "Inserta el precio del producto: ";
    cin >> p;
    cout << "Inserta el valor del billete utilizado para pagar el producto: ";
    cin >> q;

    vector<int> result = coinChange(n, coins, p, q);

    for (int c : result){
        cout << c << endl;
    }

    return 0;
}