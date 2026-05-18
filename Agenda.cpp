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

using namespace std; 


//  ESTRUCTURA: Cita
struct Cita {
    string fecha;        // DD/MM/AAAA
    string hora;         // HH:MM
    string descripcion; 
};

//Prototipos de funciones 
void pantallaBienvenida(); //funcion para mostrar la pantalla de bienvenida
    void mostrarMenu(); // para mostrar el menu de opciones al usuario
    void agregarCita(); // para agregar una nueva cita a la agenda
    void consultarTodasLasCitas(); // funcion para mostrar todas las citas registradas en la agenda
    void buscarCitaPorFecha(); // funcion para buscar y mostrar las citas registradas en una fecha especifica
    void editarCita(); // funcion para editar una cita existente en la agenda
    void eliminarCita(); // funcion para eliminar una cita de la agenda



// main
int main() {
    pantallaBienvenida(); // Mostrar pantalla de bienvenida antes del menu
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

    cout << "================================================================================ \n\n";
    cout << "\t\t  [ Presione ENTER para INGRESAR al programa ] \n\n";

    //Valida solo que ingrese enter
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <streamsize>::max es no tener limite de caracteres ignorados
    
}
