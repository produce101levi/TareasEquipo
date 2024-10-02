#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Función para calcular el Z-array
vector<int> calcularZ(const string& s) {
    int n = s.length();
    vector<int> Z(n);
    int L = 0, R = 0, K;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R] == s[R - L]) R++;
            Z[i] = R - L;
            R--;
        } else {
            K = i - L;
            if (Z[K] < R - i + 1) {
                Z[i] = Z[K];
            } else {
                L = i;
                while (R < n && s[R] == s[R - L]) R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    return Z;
}

// Función para buscar un patrón en un texto utilizando el algoritmo Z
void buscarPatronZ(const string& texto, const string& patron, int mcode_num) {
    string concatenado = patron + "$" + texto;
    vector<int> Z = calcularZ(concatenado);
    int patron_len = patron.length();

    bool encontrado = false;
    for (int i = 0; i < Z.size(); ++i) {
        if (Z[i] == patron_len) {
            int posicion_inicial = i - patron_len - 1;
            int posicion_final = posicion_inicial + patron_len - 1;
            cout << "(true) Posición inicial: " << posicion_inicial 
                 << " Posición final: " << posicion_final << endl;
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "(false) Cadena no encontrada en la transmisión" << endl;
    }
}

string lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    int maxLength = 0;  // Length of longest common substring
    int endIndex = 0;   // End index of the longest common substring in X

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    // Extract the longest common substring
    if (maxLength == 0) {
        return "";
    }
    return X.substr(endIndex - maxLength + 1, maxLength);
}




int main() {
    string transmissionFiles[] = {"transmission01.txt", "transmission02.txt"};
    string mcodeFiles[] = {"mcode01.txt", "mcode02.txt", "mcode03.txt"};
    vector<string> transmissions(2), mcodes(3);

    // Leer archivos de transmisión
    bool archivoEncontrado = true;
    for (int i = 0; i < 2; ++i) {
        ifstream file(transmissionFiles[i]);
        if (!file) {
            cout << "No se encontró el archivo " << transmissionFiles[i] << endl;
            archivoEncontrado = false;
            continue; 
        }
        getline(file, transmissions[i], '\0');
        file.close();
        cout << "\nArchivo " << transmissionFiles[i] << endl;
        cout << transmissions[i] << endl; // Muestra el contenido de la transmisión
    }

    // Leer archivos de código malicioso
    for (int i = 0; i < 3; ++i) {
        ifstream file(mcodeFiles[i]);
        if (!file) {
            cout << "Archivo " << mcodeFiles[i] << " no válido" << endl;
            mcodes[i] = ""; // Marcamos como no válido
            continue; 
        }
        getline(file, mcodes[i], '\0');
        file.close();
        cout << "Archivo " << mcodeFiles[i] << endl;
        cout << mcodes[i] << endl; // Muestra el contenido del código malicioso
    }

    //Verificar si los códigos están contenidos en las transmisiones
    for (int i = 0; i < 2; ++i) {
        cout << "\nT R A N S M I S S I O N   " << (i + 1) << endl;
        for (int j = 0; j < mcodes.size(); ++j) {
            cout << "mcode " << (j + 1) << " ";
            if (!mcodes[j].empty()) {
                buscarPatronZ(transmissions[i], mcodes[j], j + 1);
            } else {
                cout << "Archivo transmission no válido" << endl;
            }
        }
    }

    string result = lcs(transmissions[0], transmissions[1]);
    printf("\nLCS entre archivos de transmisión: %s\n", result.c_str());

    return 0;
}
