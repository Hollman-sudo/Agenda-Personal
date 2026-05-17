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



// FUNCION PRINCIPAL
int main() {
    system("cls"); // Limpiar la consola 
    system("color F1"); // Color de texto y fondo 
    cout << "\n\n\t\t UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS\n";   // !Esto se tiene que mandar a función de la pantalla de bienvenida
    cout << "\t\t=========================================================\n\n";

    cout << "Agendita"; 
    return 0;
}