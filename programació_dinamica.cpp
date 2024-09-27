#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Función para el algoritmo avaro (greedy)
vector<int> greedyChange(vector<int>& coins, int change) {
    vector<int> result(coins.size(), 0);
    
    sort(coins.begin(), coins.end(), greater<int>());
    
    for (int i = 0; i < coins.size(); i++) {
        while (change >= coins[i]) {
            change -= coins[i];
            result[i]++;
        }
    }
    return result;
}

// Función para la programación dinámica
vector<int> dpChange(vector<int>& coins, int change) {
    int n = coins.size();
    vector<int> dp(change + 1, INT_MAX);
    vector<int> coinCount(change + 1, 0);
    dp[0] = 0;
    
    for (int i = 1; i <= change; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                if (dp[i] > dp[i - coins[j]] + 1) {
                    dp[i] = dp[i - coins[j]] + 1;
                    coinCount[i] = j;
                }
            }
        }
    }

    vector<int> result(n, 0);
    while (change > 0 && dp[change] != INT_MAX) {
        result[coinCount[change]]++;
        change -= coins[coinCount[change]];
    }
    
    return result;
}

int main() {
    int n;
    cout << "Inserta el número de denominaciones: ";
    cin >> n;
    
    vector<int> coins(n);
    cout << "Inserta los valores de las monedas: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int p, q;
    cout << "Inserta el precio del producto: ";
    cin >> p;
    cout << "Inserta el valor del billete: ";
    cin >> q;

    int change = q - p;

    // Solución utilizando algoritmo avaro (greedy)
    vector<int> greedyResult = greedyChange(coins, change);
    
    // Solución utilizando programación dinámica
    vector<int> dpResult = dpChange(coins, change);
    
    cout << "Resultado con el algoritmo avaro (de mayor a menor):" << endl;
    for (int i = 0; i < n; i++) {
        cout << greedyResult[i] << endl;
    }
    
    cout << "Resultado con programación dinámica (de mayor a menor):" << endl;
    for (int i = 0; i < n; i++) {
        cout << dpResult[i] << endl;
    }

    return 0;
}

