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
    string titulo;       // Título breve de la cita
    string descripcion;  // la descripción detallada de la cita
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
    void guardarEnArchivo(); // Función para guardar
    void cargarDesdeArchivo(); // Función para cargar archivos ya existentes

// main
int main() {
    //variables 
    int opcion = 0; // Variable para la opcion del menu seleccionada por el usuario
    char continuar;

    cargarDesdeArchivo(); // Llamar a la función para ver si hay un archivo existente, sino, crearlo con la primera cita

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
        } else if (opcion == 6) { //opción #6 para cerrar programa
            system("cls");
            system("color 0C"); 
            cout << "\n==========================================================\n";
            cout << "\n\tEste programa ha finalizado. Gracias por utilizarlo.\n";
            cout << "\n=======================================================\n";
            system("pause");
        } else {
            cout << "\nOpcion invalida. Por favor, elija una opcion del 1 al 6.\n";
        }
    } while (opcion != 6);
    return 0;
}

//FUNCIONES

void pantallaBienvenida(){   // Esta función  es la pantalla de bienvenida aca va el Art ASCII y pues la bienvenida 
    system("cls"); // Limpiar la pantalla
    system("color 01");  

    //Bienvenida y logo ASCII
    cout << "===================================================================\n";
    cout << "\n\n \t\t  UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS\n";
    cout << "\t===============================================================\n\n";
        
    cout << "\t\t      ********     *****   ****   **  **   ****      ***       \n";
    cout << "\t\t      **    **    **       *      *** **   **  *    **  **        \n";
    cout << "\t\t      **    **    **       *      *** **   **  *    **  **        \n";
    cout << "\t\t      ********   **  ***   ****   ** ***   **  *   ********   \n";
    cout << "\t\t      **    **   **    *   **     **  **   **  *   **    **   \n";
    cout << "\t\t      **    **    *****    *****  **  **   ****    **    **        \n\n\n";
    
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


//Guardar en archivo teniendo en cuenta registros
void guardarEnArchivo() {
    ofstream archivo("agenda.txt");
    if (archivo.is_open()) {
        int i = 0;
        while (i < totalCitas) {
            archivo << agenda[i].fecha << "," << agenda[i].hora << "," << agenda[i].titulo << "," << agenda[i].descripcion << "\n";
            i++;
        }
        archivo.close();
    } else {
        system("color 4F");
        cout << "\t\t!! Error al guardar en el archivo.\n\n";
        system("pause");
    }
}

// Función para agregar una nueva cita 
void agregarCita(){
    cout << "\n\t\t====== AGREGAR NUEVA CITA ======\n\n";
    if (totalCitas >= 100) { // Validación para que no se exceda el límite del arreglo
        system("color 4F");
        cout << "\t\t La agenda esta llena. No se pueden agregar mas citas.\n\n";
        system("pause");
        return;
    }

    // --- FECHA ---
    string fecha; // Variable para almacenar la fecha ingresada
    int diaNum, mesNum, anioNum; // Variables para validar la fecha como números
    int fechaOk = 0; 

    cout << "\t\tIngrese la fecha (DD/MM/AAAA): ";
    cin >> fecha;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada para evitar problemas con getline después de cin

    // Validar formato: longitud 10, separadores en posicion 2 y 5
    if (fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/') { // Validar formato básico 
        // extraer dia, mes, anio como numeros
        diaNum  = (fecha[0]-'0')*10 + (fecha[1]-'0'); // Convertir los de dianum de caracteres a números enteros
        mesNum  = (fecha[3]-'0')*10 + (fecha[4]-'0'); // Convertir los de mesnum de caracteres a números enteros
        anioNum = (fecha[6]-'0')*1000 + (fecha[7]-'0')*100 + (fecha[8]-'0')*10   + (fecha[9]-'0');  // convertir los de anionum de caracteres a números enteros

        if (mesNum >= 1 && mesNum <= 12 && diaNum >= 1 && diaNum <= 31 // Validar mes entre 1 y 12, el día entre 1 y 31, y el año entre 1900 y 2100
            && anioNum >= 1900 && anioNum <= 2100) {
            fechaOk = 1; // Si la fecha es válida, marcar como ok
        }
    }
    while (fechaOk == 0) { // por si fecha no es valida
        system("color 4F");
        cout << "\t\t !! Fecha invalida. Use el formato DD/MM/AAAA.\n"; // saca mensaje de fecha incorrecta
        system("color 3F");
        cout << "\t\tIngrese la fecha (DD/MM/AAAA): "; // vuelve a pedir la fecha
        cin >> fecha;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        fechaOk = 0; // Reiniciar la validación
        if (fecha.size() == 10 && fecha[2] == '/' && fecha[5] == '/') {
            diaNum  = (fecha[0]-'0')*10 + (fecha[1]-'0');
            mesNum  = (fecha[3]-'0')*10 + (fecha[4]-'0');
            anioNum = (fecha[6]-'0')*1000 + (fecha[7]-'0')*100
                    + (fecha[8]-'0')*10   + (fecha[9]-'0');
            // Validar nuevamente la fecha ingresada
            if (mesNum >= 1 && mesNum <= 12 && diaNum >= 1 && diaNum <= 31 && anioNum >= 1900 && anioNum <= 2100) {
                fechaOk = 1; // Si la fecha es válida, marcar como ok
            }
        }
    }
    // --- HORA ---
    string hora; // Variable para almacenar la hora ingresada
    int horaNum, minNum; // Variables para validar la hora como números
    int horaOk = 0;// Variable para validar la hora
    cout << "\t\tIngrese la hora (HH:MM): "; // Pedir la hora al usuario
    cin >> hora;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (hora.size() == 5 && hora[2] == ':') { // Validar formato básico de hora: longitud 5, separador en posición 2
        horaNum = (hora[0]-'0')*10 + (hora[1]-'0'); // Convertir los de horanum de caracteres a números enteros
        minNum  = (hora[3]-'0')*10 + (hora[4]-'0'); // Convertir los de minnum de caracteres a números enteros
        if (horaNum >= 0 && horaNum <= 23 && minNum >= 0 && minNum <= 59) { horaOk = 1; // Validar que la hora esté entre 00 y 23 y los minutos entre 00 y 59, si es así, marcar como ok
        }
    } 
    while (horaOk == 0) { // Si la hora no es válida, mostrar mensaje de error y volver a pedir la hora
        system("color 4F");
        cout << "\t\t!! Hora invalida. Use el formato HH:MM (00:00 a 23:59).\n";
        system("color 3F");
        cout << "\t\tIngrese la hora (HH:MM): ";
        cin >> hora;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        horaOk = 0; // Reiniciar la validación
        if (hora.size() == 5 && hora[2] == ':') { // validacion
            horaNum = (hora[0]-'0')*10 + (hora[1]-'0');
            minNum  = (hora[3]-'0')*10 + (hora[4]-'0');

            if (horaNum >= 0 && horaNum <= 23 && minNum >= 0 && minNum <= 59) {horaOk = 1;
            }
        }
    }
    // Ingresar título y descripción de la cita
    string titulo;
    cout << "\t\tIngrese el titulo de la cita (max. 50 caracteres): "; // Pedir el título de la cita al usuario
    getline(cin, titulo); // para espacios de cadena 

    if ((int)titulo.size() > 50) { // validar que no exceda de 50 caracteres y si pasa trunc
        titulo = titulo.substr(0, 50); // substr es el trunc para el titutulo
        cout << "\t\t!! Titulo truncado a 50 caracteres.\n"; // por si el usuario ingresa un titulo de mas de 50 caracteres, truncarlo
    }
    // DEsCRIPCION
    string descripcion;
    cout << "\t\tIngrese la descripcion (max. 150 caracteres): "; // Pedir la descripción de la cita al usuario
    getline(cin, descripcion); 

    if ((int)descripcion.size() > 150) { // validar que no exceda de 150 caracteres y si pasa truncarlo
        descripcion = descripcion.substr(0, 150);  //truncar la descripcion a 150 caracteres
        cout << "\t\t!! Descripcion truncada a 150 caracteres.\n"; // mensaje por si se trunco 
    }

  // Guardar la nueva cita en el arreglo global y aumentar el contador de citas
    agenda[totalCitas].fecha       = fecha; // al campo de fecha del arreglo
    agenda[totalCitas].hora        = hora; // al campo de hora del arreglo
    agenda[totalCitas].titulo      = titulo;   // al campo de titulo del arreglo
    agenda[totalCitas].descripcion = descripcion; // al campo de descripcion del arreglo
    totalCitas++; // Incrementar el contador de citas registradas

    guardarEnArchivo(); // Guardar la nueva cita en el archivo plano de texto de forma inmediata

    system("color 2F");
    cout << "\n\t\t[OK] Cita guardada correctamente.\n\n";
    system("pause");
}



// Consultar las citas que hay guardadas
void consultarCitas() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== CONSULTAR TODAS LAS CITAS ======\n\n"; // mensaje de titulo para consultar citas

    if (totalCitas == 0) { // Validar si no hay citas registradas y mostrar mensaje de que no hay citas
        cout << "\t!! No hay citas registradas en la agenda.\n\n";
        system("pause");
        return;
    }

    cout << "\t\tID\tFECHA\t\tHORA\tTITULO\tDESCRIPCION\n"; // si si hay citas
    cout << "\t\t---------------------------------------------------------------------\n";
    // Recorrer el arreglo de citas y mostrar cada una con su ID (índice + 1)
    for (int i = 0; i < totalCitas; i++) {
        cout << "\t\t[" << (i + 1) << "]\t" 
             << agenda[i].fecha << "\t" 
             << agenda[i].hora << "\t" 
             << agenda[i].titulo << "\t" 
             << agenda[i].descripcion << "\n";
    }

    cout << "\n";
    system("pause");
}

// Buscar citas en especifico mediante fechas
void buscarCita() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== BUSCAR CITA POR FECHA ======\n\n"; // mensaje de titulo para buscar citas por fecha

    if (totalCitas == 0) { // Validar si no hay citas registradas y mostrar mensaje de que no hay citas
        cout << "\t\t!! No hay citas registradas en la agenda.\n\n";
        system("pause");
        return;
    }

    string fechaBusqueda; // Variable para almacenar la fecha que el usuario desea buscar
    cout << "\t\tIngrese la fecha a buscar (DD/MM/AAAA): "; // Pedir al usuario que ingrese la fecha a buscar
    cin >> fechaBusqueda; 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignorar el salto de línea después de leer la fecha

    cout << "\n\t\tResultados para la fecha [" << fechaBusqueda << "]:\n"; // mensaje de resultados para la fecha ingresada por el usuario
    cout << "\t\t-----------------------------------------------------------\n";

    int encontrado = 0; // Para saber si encontramos al menos una cita en esa fecha

    // Recorrer el arreglo buscando coincidencias
    for (int i = 0; i < totalCitas; i++) {
        if (agenda[i].fecha == fechaBusqueda) { // Si la fecha de la cita coincide con la fecha buscada, mostrar los detalles de esa cita
            cout << "\t\t-> Hora: " << agenda[i].hora  // mostrar la hora de la cita encontrada
                 << " | Titulo: " << agenda[i].titulo // mostrar el titulo de la cita encontrada
                 << " | Descripcion: " << agenda[i].descripcion << "\n"; // mostrar la descripcion de la cita encontrada
             encontrado = 1; // Marcar que se encontró al menos una cita para esa fecha
        }
    }
    // Si terminó el ciclo y no se encontró nada
    if (encontrado == 0) { // Si no se encontró ninguna cita para esa fecha, mostrar mensaje de que no se encontraron citas
        system("color 4F");
        cout << "\t\t No se encontraron citas pendientes para esa fecha.\n";
    }
    system("pause");    
}


// Editar las citas existentes
void editarCita() {
    system("cls");
    system("color 1F");
    cout << "\n\t\t====== EDITAR CITA EXISTENTE ======\n\n"; // mensaje de titulo para editar citas existentes

    if (totalCitas == 0) { // valida si hay citas 
        cout << "\t\t!! No hay citas registradas para editar.\n\n"; // mensaje de que no hay citas para editar
        system("pause");
        return;
    }

    // Mostrar las citas actuales para que el usuario conozca los IDs disponibles
    cout << "\t\tCitas disponibles:\n"; // mensaje de citas disponibles para editar
    cout << "\t\t-----------------------------------------------------------\n";
    for (int i = 0; i < totalCitas; i++) { // mostrar cada cita con su ID (índice + 1) para que el usuario pueda seleccionar cuál editar
        // Mostrar ID, fecha, hora y descripción de cada cita
        cout << "\t\t[" << (i + 1) << "] " << agenda[i].fecha << " - " << agenda[i].hora << " : " << agenda[i].descripcion << "\n"; 
    }

    int numeroCita;// Variable para almacenar el número de ID de la cita que el usuario desea editar
    cout << "\n\t\tSeleccione el numero de ID de la cita a editar: "; // Pedir al usuario que ingrese el número de ID  de cita a editar
    cin >> numeroCita;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Validar que el índice ingresado exista en el arreglo
    if (numeroCita < 1 || numeroCita > totalCitas) { // Validar que el número de ID esté dentro del rango válido (1 a totalCitas)
        system("color 4F"); 
        cout << "\t\t!! Numero de ID invalido.\n\n";// mensaje de que el número de ID es inválido
        system("pause");
        return;
    }

    int idx = numeroCita - 1; // Ajustar al índice real del arreglo (0-indexed) 

    string nuevaFecha, nuevaHora, nuevoTitulo, nuevaDescripcion; // Variables para almacenar los nuevos valores ingresados por el usuario
    cout << "\n\t\t--- Deje en blanco (presione ENTER) si no desea cambiar el campo ---\n"; 
    
    // Editar Fecha
    cout << "\t\tNueva fecha (Actual: " << agenda[idx].fecha << "): "; //actual y a cual se le va a cambiar la fecha
    getline(cin, nuevaFecha);
    if (!nuevaFecha.empty()) { // Si el usuario ingresó una nueva fecha (no dejó en blanco), actualizar la fecha de la cita
        agenda[idx].fecha = nuevaFecha; // Actualizar la fecha de la cita en el arreglo
    }

    // Editar Hora
    cout << "\t\tNueva hora (Actual: " << agenda[idx].hora << "): "; // mostrar la hora actual y a cual se le va a cambiar la hora
    getline(cin, nuevaHora);
    if (!nuevaHora.empty()) {
        agenda[idx].hora = nuevaHora; // Actualizar la hora de la cita en el arreglo
    }

    // Editar Título
    cout << "\t\tNuevo titulo (Actual: " << agenda[idx].titulo << "): "; // mostrar el título actual y a cual se le va a cambiar el título
    getline(cin, nuevoTitulo); // Si el usuario ingresó un nuevo título (no dejó en blanco), actualizar el título de la cita
    if (!nuevoTitulo.empty()) {
        if ((int)nuevoTitulo.size() > 50) {// Validar que el nuevo título no exceda los 50 caracteres y si pasa truncarlo
            nuevoTitulo = nuevoTitulo.substr(0, 50); // Truncar el nuevo título a 50 caracteres si excede el límite
        }
        agenda[idx].titulo = nuevoTitulo; // Actualizar el título de la cita en el arreglo
    }

    // Editar Descripción
    cout << "\t\tNueva descripcion (Actual: " << agenda[idx].descripcion << "): "; // mostrar la descripción actual y a cual se le va a cambiar la descripción
    getline(cin, nuevaDescripcion);// Si el usuario ingresó una nueva descripción (no dejó en blanco), actualizar la descripción de la cita
    if (!nuevaDescripcion.empty()) {// Validar que la nueva descripción no exceda los 150 caracteres y si pasa truncarla
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
        cout << "\t\t!! No hay citas registradas para eliminar.\n\n";
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
        cout << "\t\t!! Numero de ID invalido.\n\n";
        system("pause");
        return;
    }

    int idx = numeroCita - 1; // Ajustar al índice del arreglo (0 a totalCitas-1)

    // Pedir confirmación explícita de seguridad
    char confirmacion;
    cout << "\t\t¿Esta seguro de que desea eliminar esta cita? (s/n): "; // mensaje de confirmación para eliminar la cita seleccionada por el usuario
    cin >> confirmacion; // Leer la confirmación del usuario (s para sí, n para no)
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (confirmacion == 's' || confirmacion == 'S') { // Si el usuario confirma la eliminación, proceder a eliminar la cita del arreglo
        // Ciclo para reorganizar el arreglo y "borrar" el elemento
        for (int i = idx; i < totalCitas - 1; i++) {
            agenda[i] = agenda[i + 1];
        }
        
        // Reducir la cantidad total de citas activas
        totalCitas--;

        // Guardar los cambios actualizados de forma inmediata en el archivo plano
        guardarEnArchivo();

        system("color 2F");
        cout << "\n\t\t[OK] Cita eliminada satisfactoriamente.\n\n";// mensaje de que la cita fue eliminada exitosamente
    } else {
        cout << "\n\t\tOperacion cancelada. La cita no fue borrada.\n\n"; // mensaje de que la operación de eliminación fue cancelada por el usuario
    }

    system("pause");
}


// Cargar el archivo si existe
void cargarDesdeArchivo() {
    ifstream archivo("agenda.txt");// Abrir el archivo para lectura
    if (!archivo.is_open()) {
        // Si el archivo no existe, no hacemos nada (se creará al agregar la primera cita)
        return;
    }

    totalCitas = 0; // Reiniciar por seguridad
    string linea;

    // Leer el archivo línea por línea separando por comas
    while (getline(archivo, linea) && totalCitas < 100) { // Leer cada línea del archivo mientras no se alcance el límite de citas
        if (linea.empty()) continue; // Ignorar líneas vacías
        int pos1 = linea.find(',');
        int pos2 = linea.find(',', pos1 + 1);// Encontrar la posición de la primera y segunda coma para separar los campos de fecha, hora, título y descripción
        int pos3 = (pos2 != string::npos) ? linea.find(',', pos2 + 1) : string::npos;

        if (pos1 != string::npos && pos2 != string::npos) { // Validar que se encontraron al menos dos comas para tener fecha, hora y título/descripcion
            agenda[totalCitas].fecha = linea.substr(0, pos1); // Extraer la fecha desde el inicio de la línea hasta la primera coma
            agenda[totalCitas].hora = linea.substr(pos1 + 1, pos2 - pos1 - 1);
            if (pos3 != string::npos) {// Si hay una tercera coma, extraer el título y la descripción
                agenda[totalCitas].titulo = linea.substr(pos2 + 1, pos3 - pos2 - 1);
                agenda[totalCitas].descripcion = linea.substr(pos3 + 1);
            } else {// Si no hay una tercera coma, asumir que el título está vacío y el resto es la descripción
                agenda[totalCitas].titulo = "";
                agenda[totalCitas].descripcion = linea.substr(pos2 + 1); // Si no hay una tercera coma, asumimos que el título está vacío y el resto es la descripción
            }
            totalCitas++; // Incrementar el contador de citas cargadas desde el archivo
        }
        
    }
    archivo.close(); // Cerrar el archivo después de cargar los datos

}