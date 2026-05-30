/*
Programa: Este programa da las notas de n estudiantes de una clase donde se tienen nombre, apellidos, codigos y notas parciales mas el promedio de las mismas.
Autor: Daniel Jose Gomez Supelano
Fecha: 22 de Mayo del 2026
*/

// declarar librerias
#include <iostream>
#include <fstream>  // para manejo de archivos
#include <locale.h>// para usar caracteres acentuados
#include <limits>
#include <string> // para usar strings
using namespace std;

    // Estructura que agrupa los datos de un estudiante
    struct Estudiante {
        string nombre;
        string apellido;
        string codigo;
        double parcialUno;   // Parcial I  (35%)
        double parcialDos;   // Parcial II (35%)
        double examenFinal;  // Examen Final (30%)
        double definitiva;   // Nota definitiva calculada
    };

    // Prototipo de funciones
    void ingresarDatos(Estudiante grupo[], int &numEstudiantes);
    void calcularDefinitivas(Estudiante grupo[], int numEstudiantes);
    void mostrarEstudiantes(Estudiante grupo[], int numEstudiantes);
    void calcularPromedioGrupal(Estudiante grupo[], int numEstudiantes);
    void guardarArchivo(Estudiante grupo[], int numEstudiantes);
    void cargarArchivo(Estudiante grupo[], int &numEstudiantes);
    void borrarArchivo();

    // Funcion principal
    int main() {
        setlocale(LC_ALL, ""); // permite usar caracteres acentuados en la consola
        system("cls");         // limpia la pantalla de la consola
        system("color 0F");    // establece el color de fondo y texto

        //VARIABLES
        char continuar;
        Estudiante grupo[30]; // arreglo de structs, maximo 30 estudiantes
        int numEstudiantes = 0; // contador de estudiantes ingresados
        int eleccion, errores;        // variable para la eleccion del menu

        // Mensaje de bienvenida
        cout << "====================================================================================================\n";
        cout << "\t\t Bienvenido\n Este programa permite ingresar datos de n estudiantes,\n";
        cout << " mostrar sus notas definitivas y el promedio del grupo.\n";
        cout << "====================================================================================================\n";

        do { //menu
            cout << "\t  Que accion desea realizar? ";
            cout << "\n=======================================================\n";
            cout << "\t\t MENU PRINCIPAL\n";
            cout << "1. Ingresar datos de estudiantes\n";
            cout << "2. mostrar datos y notas definitivas\n";
            cout << "3. Ver promedio grupal\n";
            cout << "4. Borrar archivo\n";
            cout << "5. Salir del programa\n";
            cout << "=======================================================\n";
            cin >> eleccion;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // para ignorar el salto de linea

            if (eleccion == 1) { //opcion #1
                numEstudiantes = 0; // Reiniciar el contador de estudiantes
                ingresarDatos(grupo, numEstudiantes);
                calcularDefinitivas(grupo, numEstudiantes);
                guardarArchivo(grupo, numEstudiantes); // guarda automaticamente al terminar de ingresar
                cout << "\nDatos ingresados correctamente. Total: " << numEstudiantes << " estudiantes.\n";
                cout << "\nLas definitivas se han calculado.\n";
                system("pause");
            }
            else if (eleccion == 2) { // opcion #2
                if (numEstudiantes == 0) {
                    cout << "\nNo hay estudiantes ingresados. Por favor, ingrese los datos primero.\n";
                }
                else {
                    mostrarEstudiantes(grupo, numEstudiantes);
                }
                system("pause");
            }
            else if (eleccion == 3) { // opcion #3
                cargarArchivo(grupo, numEstudiantes);
                if (numEstudiantes == 0) {
                    cout << "\nNo hay estudiantes ingresados. Por favor, ingrese los datos primero.\n";
                }
                else {
                    calcularPromedioGrupal(grupo, numEstudiantes);
                }
                system("pause");
            }
            else if (eleccion == 4) { // opcion #4
                borrarArchivo();
                numEstudiantes = 0; // Para que el contador se reinicie
                cout << "\nArchivo borrado exitosamente.\n";
                system("pause");
            }
            else if (eleccion == 5) {    //SALIDA
                system("cls");
                system("color 0C");
                cout << "\n=======================================================\n";
                cout << "\n\tEste programa ha finalizado. Gracias por utilizarlo.\n";
                cout << "\n=======================================================\n";
            }
            else {
                cout << "\nOpcion invalida. Por favor, elija una opcion del 1 al 5.\n";
                system("pause");
            }
        } while (eleccion != 5);

        system("pause");
        return 0;
    }

//FUNCIONES
// Funcion para ingresar los datos de los estudiantes
void ingresarDatos(Estudiante grupo[], int &numEstudiantes) {
    char continuar;
    int errores; // contador de errores para validaciones sin bool

    do {
        system("cls");
        system("color 0B");
        cout << "\n=======================================================\n";
        cout << " Ingreso de datos del estudiante #" << (numEstudiantes + 1) << "\n";
        cout << "=======================================================\n";

        // Limite maximo del arreglo
        if (numEstudiantes >= 30) {
            cout << "\nSe alcanzo el limite maximo de 30 estudiantes.\n";
            break;
        }

        // VALIDAR NOMBRE: no puede estar vacio y solo letras y espacios
        do {
            errores = 0;
            cout << "Ingrese el nombre del estudiante: ";
            getline(cin, grupo[numEstudiantes].nombre);

            if (grupo[numEstudiantes].nombre == "") {
                errores++;
                cout << "Error: el nombre no puede estar vacio.\n";
            }

            for (int j = 0; j < grupo[numEstudiantes].nombre.length(); j++) {
                char c = grupo[numEstudiantes].nombre[j];
                if (!(isalpha(c) || c == ' ')) {
                    errores++;
                    cout << "Error: el nombre solo debe contener letras.\n";
                    break;
                }
            }
        } while (errores > 0);

        // VALIDAR APELLIDO: no puede estar vacio y solo letras y espacios
        do {
            errores = 0;
            cout << "Ingrese el apellido del estudiante: ";
            getline(cin, grupo[numEstudiantes].apellido);

            if (grupo[numEstudiantes].apellido == "") {
                errores++;
                cout << "Error: el apellido no puede estar vacio.\n";
            }

            for (int j = 0; j < grupo[numEstudiantes].apellido.length(); j++) {
                char c = grupo[numEstudiantes].apellido[j];
                if (!(isalpha(c) || c == ' ')) {
                    errores++;
                    cout << "Error: el apellido solo debe contener letras.\n";
                    break;
                }
            }
        } while (errores > 0);

        // VALIDAR CODIGO: no puede estar vacio
        do {
            errores = 0;
            cout << "Ingrese el codigo del estudiante: ";
            getline(cin, grupo[numEstudiantes].codigo);

            if (grupo[numEstudiantes].codigo == "") {
                errores++;
                cout << "Error: el codigo no puede estar vacio.\n";
            }
        } while (errores > 0);

        // VALIDAR PARCIAL I: entre 0 y 5
        do {
            cout << "Ingrese la nota del Parcial I (0-5): ";
            cin >> grupo[numEstudiantes].parcialUno;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (grupo[numEstudiantes].parcialUno < 0 || grupo[numEstudiantes].parcialUno > 5) {
                cout << "Nota invalida. Debe estar entre 0 y 5. Intente de nuevo.\n";
            }
        } while (grupo[numEstudiantes].parcialUno < 0 || grupo[numEstudiantes].parcialUno > 5);

        // VALIDAR PARCIAL II: entre 0 y 5
        do {
            cout << "Ingrese la nota del Parcial II (0-5): ";
            cin >> grupo[numEstudiantes].parcialDos;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (grupo[numEstudiantes].parcialDos < 0 || grupo[numEstudiantes].parcialDos > 5) {
                cout << "Nota invalida. Debe estar entre 0 y 5. Intente de nuevo.\n";
            }
        } while (grupo[numEstudiantes].parcialDos < 0 || grupo[numEstudiantes].parcialDos > 5);

        // VALIDAR EXAMEN FINAL: entre 0 y 5
        do {
            cout << "Ingrese la nota obtenida en el examen final (0-5): ";
            cin >> grupo[numEstudiantes].examenFinal;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (grupo[numEstudiantes].examenFinal < 0 || grupo[numEstudiantes].examenFinal > 5) {
                cout << "Nota invalida. Debe estar entre 0 y 5. Intente de nuevo.\n";
            }
        } while (grupo[numEstudiantes].examenFinal < 0 || grupo[numEstudiantes].examenFinal > 5);

        // Incrementa el contador luego de guardar los datos
        numEstudiantes++;

        // Pregunta si desea ingresar otro estudiante
        cout << "\nDesea ingresar otro estudiante? (s/otra tecla): ";
        cin >> continuar;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Si no es s o S termina
        if (continuar != 's' && continuar != 'S') {
            break;
        }
    } while (continuar == 's' || continuar == 'S');
}

// Funcion para calcular las notas definitivas de los estudiantes
void calcularDefinitivas(Estudiante grupo[], int numEstudiantes) {
    for (int i = 0; i < numEstudiantes; i++) {
        grupo[i].definitiva = (grupo[i].parcialUno * 0.35) + (grupo[i].parcialDos * 0.35) + (grupo[i].examenFinal * 0.30);
    }
}

// Funcion para mostrar los datos de los estudiantes y sus notas definitivas
void mostrarEstudiantes(Estudiante grupo[], int numEstudiantes) {
    system("cls");
    system("color 0A");
    cout << "\n=======================================================\n";
    cout << "\t\t Datos de los estudiantes\n";
    cout << "=======================================================\n";
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante #" << (i + 1) << ":\n";
        cout << "Nombre: " << grupo[i].nombre << " " << grupo[i].apellido << "\n";
        cout << "Codigo: " << grupo[i].codigo << "\n";
        cout << "Parcial I: " << grupo[i].parcialUno << "\n";
        cout << "Parcial II: " << grupo[i].parcialDos << "\n";
        cout << "Examen Final: " << grupo[i].examenFinal << "\n";
        cout << "Nota Definitiva: " << grupo[i].definitiva << "\n";
        // Estado segun la nota definitiva
        if (grupo[i].definitiva >= 3.0) {
            cout << "Estado: APROBADO\n";
        } else {
            cout << "Estado: REPROBADO\n";
        }
        cout << "-------------------------------------------------------\n";
    }
}

// Funcion que calcula y muestra el promedio de las notas definitivas del grupo
void calcularPromedioGrupal(Estudiante grupo[], int numEstudiantes) {
    double suma = 0; // acumula la suma de todas las definitivas

    for (int i = 0; i < numEstudiantes; i++) {
        suma += grupo[i].definitiva; // suma cada definitiva
    }

    double promedioGrupal = suma / numEstudiantes; // promedio simple

    system("color 0D");
    cout << "\n=======================================================\n";
    cout << "\t  PROMEDIO GRUPAL\n";
    cout << "=======================================================\n";
    cout << "Total estudiantes: " << numEstudiantes << "\n";
    cout << "Promedio grupal:   " << promedioGrupal << "\n";
}

// Funcion que guarda los datos en archivo .txt al terminar de ingresar
void guardarArchivo(Estudiante grupo[], int numEstudiantes) {
    ofstream archivo("calificaciones.txt"); // abre o crea el archivo

    if (!archivo) {
        system("color 0C");
        cout << "\nError: no se pudo crear el archivo.\n";
        return;
    }

    // Escribe el numero de estudiantes primero para poder cargar despues
    archivo << numEstudiantes << "\n";

    for (int i = 0; i < numEstudiantes; i++) {
        archivo << grupo[i].nombre << "\n";
        archivo << grupo[i].apellido << "\n";
        archivo << grupo[i].codigo << "\n";
        archivo << grupo[i].parcialUno << "\n";
        archivo << grupo[i].parcialDos << "\n";
        archivo << grupo[i].examenFinal << "\n";
        archivo << grupo[i].definitiva << "\n";
    }

    archivo.close(); // cierra el archivo al terminar
}

// Funcion que carga automaticamente los datos desde el archivo .txt
void cargarArchivo(Estudiante grupo[], int &numEstudiantes) {
    ifstream archivo("calificaciones.txt"); // abre el archivo para lectura

    if (!archivo) {
        // Si no existe el archivo simplemente no carga nada
        numEstudiantes = 0;
        return;
    }

    // Lee el numero de estudiantes guardados
    archivo >> numEstudiantes;
    archivo.ignore();

    for (int i = 0; i < numEstudiantes; i++) {
        getline(archivo, grupo[i].nombre);
        getline(archivo, grupo[i].apellido);
        getline(archivo, grupo[i].codigo);
        archivo >> grupo[i].parcialUno;
        archivo >> grupo[i].parcialDos;
        archivo >> grupo[i].examenFinal;
        archivo >> grupo[i].definitiva;
        archivo.ignore(); // limpia salto de linea entre registros
    }

    archivo.close();
}

// Funcion que borra el archivo de calificaciones
void borrarArchivo() {
    // remove() devuelve 0 si borro bien, distinto de 0 si hubo error
    if (remove("calificaciones.txt") == 0) {
        system("color 0A");
        cout << "\nArchivo calificaciones.txt borrado correctamente.\n";
    } else {
        system("color 0C");
        cout << "\nError: no se encontro el archivo o no se pudo borrar.\n";
        system("color 0F");
    }
}