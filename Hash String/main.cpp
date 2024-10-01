#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(){

    // Declarar variables
    string inputName;
    string fileContent = "";
    string fileMatrix = "";
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

    char c;
    while (myFile.get(c)) {
        
        fileContent += c;
        if (c == '\n'){
            c = '-';
            fileMatrix += c;
        }else{
            fileMatrix += c;
        }
    }
    myFile.close();

    int l = fileContent.length();
    int numRows = (l + n - 1) / n;
    fileContent.resize(numRows * n, n);
    if (l % n != 0){
        int filling = n - (l % n);
        fileMatrix.append(filling, '[');
    }

    // Crear arreglo a
    vector<int> a(n, 0);

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < n; j++) {
            a[j] = (a[j] + fileContent[i * n + j]) % 256;
        }
    }

    // Generar output hexadecimal
    string hexOutput;
    for (int i = 0; i < n; ++i) {
        stringstream ss;
        ss << hex << uppercase << setw(2) << setfill('0') << a[i]; 
        hexOutput += ss.str();
        

        if ((i + 1) % 4 == 0 && (i + 1) != n) {
            hexOutput += " ";
        }
    }

    cout << "-=- MATRIZ -=-" << endl;
    for (int i = 0; i < numRows; ++i) {
        cout << fileMatrix.substr(i * n, n) << " " << endl;
    }
    cout << endl;

    cout << "-=- ARREGLO A -=-" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "-=- HEX STRING -=-" << endl;
    cout << hexOutput << endl;

    return 0;
}