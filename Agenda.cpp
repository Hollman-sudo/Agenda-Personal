/*
 PROYECTO 7 - AGENDA PERSONAL  Programacion Basica - Universidad Distrital F.J. de Caldas
 Autores : Daniel Gomez, Nicolas Pulido, Hollman Castillo
 Fecha : 2/06/2024
 agenda digital que permite registrar, consultar, modificar y eliminar citas o tareas pendientes,
 organizadas por fecha y hora. en (agenda.txt) */
 
#include <iostream> // para entrada y salida de datos de cin y cout
#include <fstream>  // para manejo de archivos con ifstream y ofstream
#include <string>    // manejar de cadenas de texto 
#include <limits>    // para evitar leer datos mal de un usuario
#include <ctime>
#include <cstdlib>    //  las 2 librerias para manejar fechas y horas
using namespace std; 


//  ESTRUCTURA: Cita
struct Cita {
    string fecha;        // DD/MM/AAAA
    string hora;         // HH:MM
    string descripcion; 
};
// ARREGLO GLOBAL de citas y contador
Cita agenda[100]; // Arreglo para almacenar hasta 100 citas
int totalCitas = 0; // Contador de citas registradas

//Prototipos de funciones 
    void pantallaBienvenida(); //funcion para mostrar la pantalla de bienvenida
    void mostrarMenu(); // para mostrar el menu de opciones al usuario
    void agregarCita(); // para agregar una nueva cita a la agenda
    void consultarCitas(); // funcion para mostrar todas las citas registradas en la agenda
    void buscarCita(); // funcion para buscar y mostrar las citas registradas en una fecha especifica
    void editarCita(); // funcion para editar una cita existente en la agenda
    void eliminarCita(); // funcion para eliminar una cita de la agenda
    void guardarEnArchivo(); // Funnción para guardar

// main
int main() {
    //variables 
    int opcion = 0; // Variable para la opcion del menu seleccionada por el usuario
    char continuar;
    pantallaBienvenida(); // Mostrar pantalla de bienvenida antes del menu
    system("cls"); // Limpiar la pantalla
    system("color 1F");   

    //mensaje de que ha ingresado a la agenda 
    cout << "\n\n\t\t==========================================\n"; 
    cout << "\t\t      BIENVENIDO A LA AGENDA PERSONAL     \n";
    cout << "\t\t==========================================\n";

    // Bucle para no salir del programa hasta que se ponga la opcion de salir
    do {
        mostrarMenu(); // Mostrar el menu de opciones al usuario
        cout<< "\t\tseleccione una opcion: ";
        cin >> opcion; // Leer la opcion seleccionada por el usuario

        if (opcion == 1) { //opción #1
            agregarCita(); // Llamar a la función para agregar una nueva cita a la agenda
        } else if (opcion == 2) {//opción #2
            consultarCitas(); // Llamar a la función para mostrar todas las citas registradas en la agenda
        } else if (opcion == 3) { //opción #3
            buscarCita(); // Llamar a la función para buscar y mostrar las citas registradas en una fecha especifica
        } else if (opcion == 4) { //opción #4
            editarCita(); // Llamar a la función para editar una cita existente en la agenda
        } else if (opcion == 5) { //opción #5
            eliminarCita(); // Llamar a la función para eliminar una cita de la agenda
        } else if (opcion == 6) { //opción #6
            system("cls");
            system("color 0C"); 
            cout << "\n=======================================================\n";
            cout << "\n\tEste programa ha finalizado. Gracias por utilizarlo.\n";
            cout << "\n=======================================================\n";
        } else {
            cout << "\nOpcion invalida. Por favor, elija una opcion del 1 al 6.\n";
        }
    } while (opcion != 6);
    return 0;
}

//FUNCIONES

void pantallaBienvenida(){   // Esta función  es la pantalla de bienvenida aca va el Art ASCII y pues la bienvenida 
    system("cls"); // Limpiar la pantalla
    system("color F1");  

    //Bienvenida y logo ASCII
    cout << "===================================================================\n";
    cout << "\n\n \t\t  UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS\n";
    cout << "\t\t =================================================\n\n";


    cout << "\t\t      ********    *****  ****  **  **   ****     ***       \n";
    cout << "\t\t      **    **   **      *     *** **   **  *   **  **        \n";
    cout << "\t\t      **    **   **      *     *** **   **  *   **  **        \n";
    cout << "\t\t      ********  **  ***  ****  ** ***   **  *  ********   \n";
    cout << "\t\t      **    **  **    *  **    **  **   **  *  **    **   \n";
    cout << "\t\t      **    **   *****   ***** **  **   ****   **    **        \n\n\n";
    
    cout <<"\t\t    ******  *****   ******   *****   ******  **  **   *******   **  \n";
    cout <<"\t\t    **  **  **      **  **    **     ******  *** **   **   **   **  \n";
    cout <<"\t\t    **  **  *****   **  **     **    *    *  ******   **   **   **  \n";
    cout <<"\t\t    ******  **      ******      **   *    *  ** ***   *******   **  \n";
    cout <<"\t\t    **      **      **  *    *   *   *    *  **  **   **   **   **  \n";
    cout <<"\t\t    **      **  *   **   *   *   **  ******  **  **   **   **   ***  \n";
    cout <<"\t\t    **      *****   **   *    *****  ******  **  **   **   **   ********\n\n\n";
    cout <<"\t======================================================================================\n\n";
    // Boton de ingreso

    cout << "\t\t  [ Presione ENTER para INGRESAR al programa ] \n\n";
    cout << "===================================================================\n\n";
    //Valida solo que ingrese enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <streamsize>::max es no tener limite de caracteres ignorados

}

// Función para mostrar el menu de opciones al usuario
void mostrarMenu() {
    cout << "\n\t\t ==========================================\n";
    cout << "\t\t              MENU PRINCIPAL                 \n";
    cout << "\t\t ==========================================\n";
    cout << "\t\t  1. Agregar nueva cita\n";
    cout << "\t\t  2. Consultar todas las citas\n";
    cout << "\t\t  3. Buscar cita por fecha\n";
    cout << "\t\t  4. Editar cita\n";
    cout << "\t\t  5. Eliminar cita\n";
    cout << "\t\t  6. Salir del programa\n";
    cout << "\t\t ==========================================\n";
}

void agregarCita(){
    cout << "\n\t\t====== AGREGAR NUEVA CITA ======\n\n";

    if (totalCitas >= 100) {
        system("color 4F");
        cout << "\t\t[!] La agenda esta llena. No se pueden agregar mas citas.\n\n";
        system("pause");
        return;
    }

    // --- FECHA ---
    string fecha;
    int diaNum, mesNum, anioNum;
    int fechaOk = 0;

    cout << "\t\tIngrese la fecha (DD/MM/AAAA): ";
    cin >> fecha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Validar formato: longitud 10, separadores en posicion 2 y 5
    if (fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/') {
        // extraer dia, mes, anio como numeros
        diaNum  = (fecha[0]-'0')*10 + (fecha[1]-'0');
        mesNum  = (fecha[3]-'0')*10 + (fecha[4]-'0');
        anioNum = (fecha[6]-'0')*1000 + (fecha[7]-'0')*100
                + (fecha[8]-'0')*10   + (fecha[9]-'0');

        if (mesNum >= 1 && mesNum <= 12 && diaNum >= 1 && diaNum <= 31
            && anioNum >= 1900 && anioNum <= 2100) {
            fechaOk = 1;
        }
    }

    while (fechaOk == 0) {
        system("color 4F");
        cout << "\t\t[!] Fecha invalida. Use el formato DD/MM/AAAA.\n";
        system("color 3F");
        cout << "\t\tIngrese la fecha (DD/MM/AAAA): ";
        cin >> fecha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        fechaOk = 0;
        if (fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/') {
            diaNum  = (fecha[0]-'0')*10 + (fecha[1]-'0');
            mesNum  = (fecha[3]-'0')*10 + (fecha[4]-'0');
            anioNum = (fecha[6]-'0')*1000 + (fecha[7]-'0')*100
                    + (fecha[8]-'0')*10   + (fecha[9]-'0');

            if (mesNum >= 1 && mesNum <= 12 && diaNum >= 1 && diaNum <= 31
                && anioNum >= 1900 && anioNum <= 2100) {
                fechaOk = 1;
            }
        }
    }

    // --- HORA ---
    string hora;
    int horaNum, minNum;
    int horaOk = 0;

    cout << "\t\tIngrese la hora (HH:MM): ";
    cin >> hora;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (hora.size() == 5 && hora[2] == ':') {
        horaNum = (hora[0]-'0')*10 + (hora[1]-'0');
        minNum  = (hora[3]-'0')*10 + (hora[4]-'0');

        if (horaNum >= 0 && horaNum <= 23 && minNum >= 0 && minNum <= 59) {
            horaOk = 1;
        }
    }

    while (horaOk == 0) {
        system("color 4F");
        cout << "\t\t[!] Hora invalida. Use el formato HH:MM (00:00 a 23:59).\n";
        system("color 3F");
        cout << "\t\tIngrese la hora (HH:MM): ";
        cin >> hora;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        horaOk = 0;
        if (hora.size() == 5 && hora[2] == ':') {
            horaNum = (hora[0]-'0')*10 + (hora[1]-'0');
            minNum  = (hora[3]-'0')*10 + (hora[4]-'0');

            if (horaNum >= 0 && horaNum <= 23 && minNum >= 0 && minNum <= 59) {
                horaOk = 1;
            }
        }
    }

    // --- DESCRIPCION ---
    string descripcion;
    cout << "\t\tIngrese la descripcion (max. 100 caracteres): ";
    getline(cin, descripcion);

    if ((int)descripcion.size() > 100) {
        descripcion = descripcion.substr(0, 100);
        cout << "\t\t[!] Descripcion truncada a 100 caracteres.\n";
    }

    // --- GUARDAR EN ARREGLO Y ARCHIVO ---
    agenda[totalCitas].fecha       = fecha;
    agenda[totalCitas].hora        = hora;
    agenda[totalCitas].descripcion = descripcion;
    totalCitas++;

    guardarEnArchivo();

    system("color 2F");
    cout << "\n\t\t[OK] Cita guardada correctamente.\n\n";
    system("pause");
}

//Guardar en archivo teniendo en cuenta registros
void guardarEnArchivo() {
    ofstream archivo("agenda.txt");
    if (archivo.is_open()) {
        int i = 0;
        while (i < totalCitas) {
            archivo << agenda[i].fecha << "," << agenda[i].hora << "," << agenda[i].descripcion << "\n";
            i++;
        }
        archivo.close();
    } else {
        system("color 4F");
        cout << "\t\t[!] Error al guardar en el archivo.\n\n";
        system("pause");
    }
}

// Consultar las citas que hay guardadas
void consultarCitas() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== CONSULTAR TODAS LAS CITAS ======\n\n";

    if (totalCitas == 0) {
        cout << "\t\t[!] No hay citas registradas en la agenda.\n\n";
        system("pause");
        return;
    }

    cout << "\t\tID\tFECHA\t\tHORA\tDESCRIPCION\n";
    cout << "\t\t-----------------------------------------------------------\n";
    
    for (int i = 0; i < totalCitas; i++) {
        cout << "\t\t[" << (i + 1) << "]\t" 
             << agenda[i].fecha << "\t" 
             << agenda[i].hora << "\t" 
             << agenda[i].descripcion << "\n";
    }

    cout << "\n";
    system("pause");
}

// Buscar citas en especifico mediante fechas
void buscarCita() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== BUSCAR CITA POR FECHA ======\n\n";

    if (totalCitas == 0) {
        cout << "\t\t[!] No hay citas registradas en la agenda.\n\n";
        system("pause");
        return;
    }

    string fechaBusqueda;
    cout << "\t\tIngrese la fecha a buscar (DD/MM/AAAA): ";
    cin >> fechaBusqueda;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n\t\tResultados para la fecha [" << fechaBusqueda << "]:\n";
    cout << "\t\t-----------------------------------------------------------\n";

    bool encontrado = false; // Para saber si encontramos al menos una

    // Recorrer el arreglo buscando coincidencias
    for (int i = 0; i < totalCitas; i++) {
        if (agenda[i].fecha == fechaBusqueda) {
            cout << "\t\t-> Hora: " << agenda[i].hora 
                 << " | Descripcion: " << agenda[i].descripcion << "\n";
            encontrado = true;
        }
    }

    // Si terminó el ciclo y no se encontró nada
    if (!encontrado) {
        system("color 4F");
        cout << "\t\t[!] No se encontraron citas pendientes para esa fecha.\n";
    }

    cout << "\n";
    system("pause");
}


// Editar las citas existentes
void editarCita() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== EDITAR CITA EXISTENTE ======\n\n";

    if (totalCitas == 0) {
        cout << "\t\t[!] No hay citas registradas para editar.\n\n";
        system("pause");
        return;
    }

    // Mostrar las citas actuales para que el usuario conozca los IDs disponibles
    cout << "\t\tCitas disponibles:\n";
    cout << "\t\t-----------------------------------------------------------\n";
    for (int i = 0; i < totalCitas; i++) {
        cout << "\t\t[" << (i + 1) << "] " << agenda[i].fecha << " - " << agenda[i].hora << " : " << agenda[i].descripcion << "\n";
    }

    int numeroCita;
    cout << "\n\t\tSeleccione el numero de ID de la cita a editar: ";
    cin >> numeroCita;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Validar que el índice ingresado exista en el arreglo
    if (numeroCita < 1 || numeroCita > totalCitas) {
        system("color 4F");
        cout << "\t\t[!] Numero de ID invalido.\n\n";
        system("pause");
        return;
    }

    int idx = numeroCita - 1; // Ajustar al índice real del arreglo (0-indexed)

    string nuevaFecha, nuevaHora, nuevaDescripcion;

    cout << "\n\t\t--- Deje en blanco (presione ENTER) si no desea cambiar el campo ---\n";
    
    // Editar Fecha
    cout << "\t\tNueva fecha (Actual: " << agenda[idx].fecha << "): ";
    getline(cin, nuevaFecha);
    if (!nuevaFecha.empty()) {
        // Guardamos directamente si el usuario digita algo nuevo
        agenda[idx].fecha = nuevaFecha;
    }

    // Editar Hora
    cout << "\t\tNueva hora (Actual: " << agenda[idx].hora << "): ";
    getline(cin, nuevaHora);
    if (!nuevaHora.empty()) {
        agenda[idx].hora = nuevaHora;
    }

    // Editar Descripción
    cout << "\t\tNueva descripcion (Actual: " << agenda[idx].descripcion << "): ";
    getline(cin, nuevaDescripcion);
    if (!nuevaDescripcion.empty()) {
        if ((int)nuevaDescripcion.size() > 100) {
            nuevaDescripcion = nuevaDescripcion.substr(0, 100);
        }
        agenda[idx].descripcion = nuevaDescripcion;
    }

    // Criterio 15: Guardar los cambios automáticamente en el archivo físico
    guardarEnArchivo();

    system("color 2F");
    cout << "\n\t\t[OK] Cita modificada y guardada con exito.\n\n";
    system("pause");
}


// Eliminar una cita existente
void eliminarCita() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== ELIMINAR CITA DE LA AGENDA ======\n\n";

    if (totalCitas == 0) {
        cout << "\t\t[!] No hay citas registradas para eliminar.\n\n";
        system("pause");
        return;
    }

    // Mostrar las citas actuales
    cout << "\t\tCitas registradas:\n";
    cout << "\t\t-----------------------------------------------------------\n";
    for (int i = 0; i < totalCitas; i++) {
        cout << "\t\t[" << (i + 1) << "] " << agenda[i].fecha << " - " << agenda[i].hora << " : " << agenda[i].descripcion << "\n";
    }

    int numeroCita;
    cout << "\n\t\tSeleccione el numero de ID de la cita que desea eliminar: ";
    cin >> numeroCita;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Validar el rango de selección
    if (numeroCita < 1 || numeroCita > totalCitas) {
        system("color 4F");
        cout << "\t\t[!] Numero de ID invalido.\n\n";
        system("pause");
        return;
    }

    int idx = numeroCita - 1; // Ajustar al índice del arreglo (0 a totalCitas-1)

    // Pedir confirmación explícita de seguridad
    char confirmacion;
    cout << "\t\t¿Esta seguro de que desea eliminar esta cita? (s/n): ";
    cin >> confirmacion;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmacion == 's' || confirmacion == 'S') {
        // Ciclo para reorganizar el arreglo y "borrar" el elemento
        for (int i = idx; i < totalCitas - 1; i++) {
            agenda[i] = agenda[i + 1];
        }
        
        // Reducir la cantidad total de citas activas
        totalCitas--;

        // Guardar los cambios actualizados de forma inmediata en el archivo plano
        guardarEnArchivo();

        system("color 2F");
        cout << "\n\t\t[OK] Cita eliminada satisfactoriamente.\n\n";
    } else {
        cout << "\n\t\tOperacion cancelada. La cita no fue borrada.\n\n";
    }

    system("pause");
}