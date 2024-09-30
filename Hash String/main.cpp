#include <iostream>
#include <fstream>

using namespace std;

int main(){

    // Declarar variables
    string inputName;
    string fileContent = "";
    int n;

    // Insertar nombre de archivo y n
    cout << "Ingresa el nombre del archivo (sin extensión): ";
    cin >> inputName;
    cout << "Ingresa un múltiplo de 4 entre 16 y 64: ";
    cin >> n;

    // Verificar que n sea múltiplo de 4 y esté
    // entre 16 y 64
    if (n % 4 != 0 || n < 16 || n > 64) {
        cout << "Error. El número debe ser un múltiplo de 4 entre 16 y 64." << endl;
    }

    // Leer archivo
    ifstream myFile(inputName + ".txt");
    
    // Pasar contenido a string
    int l = fileContent.length();
    int numRows = (l + n - 1) / n;

    if (l % n != 0){
        int filling = n - (l % n);
        fileContent.append(filling, '[');
    }

    // Crear arreglo a
    vector<int> a(n, 0);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < n; ++j) {
            a[j] = (a[j] + fileContent[i * n + j]) % 256;
        }
    }


    return 0;
}