#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    string fileName;
    int n;

    // Solicita el nombre del archivo y el valor de n
    cout << "Introduce el nombre del archivo: ";
    cin >> fileName;

    cout << "Introduce el valor de n (múltiplo de 4, entre 16 y 64): ";
    cin >> n;

    // Verificar que n sea múltiplo de 4 y esté en el rango
    if (n % 4 != 0 || n < 16 || n > 64) {
        cout << "El valor de n debe ser múltiplo de 4 y estar entre 16 y 64." << endl;
        return 1;
    }

    // Abrir el archivo
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer el archivo y almacenarlo en una cadena
    vector<char> fileContent;
    char ch;
    while (file.get(ch)) {
        fileContent.push_back(ch);
    }
    file.close();

    // Calcular el número de filas necesarias para la tabla
    int rows = (fileContent.size() + n - 1) / n;  // Redondeo hacia arriba

    // Crear la tabla
    vector<vector<char>> table(rows, vector<char>(n, n)); // Rellenar con n por defecto
    for (size_t i = 0; i < fileContent.size(); ++i) {
        table[i / n][i % n] = fileContent[i];
    }

    // Mostrar la tabla generada
    cout << "\nTabla generada:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < n; ++j) {
            if (table[i][j] >= 32 && table[i][j] <= 126) // Caracter imprimible
                cout << table[i][j] << ' ';
            else
                cout << ". "; // Sustituir caracteres no imprimibles por un punto
        }
        cout << endl;
    }

    // Calcular el arreglo 'a'
    vector<int> a(n, 0);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < rows; ++i) {
            a[j] = (a[j] + table[i][j]) % 256;
        }
    }

    // Mostrar el arreglo 'a'
    cout << "\nArreglo a:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << setw(3) << a[i] << " ";
    }
    cout << endl;

    // Generar la cadena de salida en hexadecimal
    string output;
    for (int i = 0; i < n; i += 4) {
        int sum = 0;
        for (int j = i; j < i + 4; ++j) {
            sum += a[j];
        }
        sum = sum % 256;
        stringstream ss;
        ss << setw(2) << setfill('0') << hex << uppercase << sum;
        output += ss.str();
    }

    // Mostrar la cadena de salida
    cout << "\nCadena de salida: " << output << endl;

    return 0;
}
