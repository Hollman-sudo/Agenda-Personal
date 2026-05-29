/*
 PROYECTO 7 - AGENDA PERSONAL  Programacion Basica - Universidad Distrital F.J. de Caldas
 Autores : Daniel Gomez, Nicolas Pulido, Hollman Castillo
 Fecha : 2/06/2024
 agenda digital que permite registrar, consultar, modificar y eliminar citas o tareas pendientes,
 organizadas por fecha y hora. en (agenda.txt) */
 
#include <iostream> // para entrada y salida de datos con cin y cout
#include <fstream>  // para manejo de archivos con ifstream y ofstream (lectura y escritura)
#include <string>    // para manejar de cadenas de texto 
#include <limits>    // para evitar leer datos mal de un usuario (poner datos minimos y maximos)

using namespace std; 


//  ESTRUCTURA: Cita
struct Cita {
    string fecha;        // DD/MM/AAAA
    string hora;         // HH:MM
    string descripcion; 
};

//Prototipos de funciones 
void pantallaBienvenida(); //funcion para mostrar la pantalla de bienvenida
    void menu(); // para mostrar el menu de opciones al usuario
    void agregarCita(); // para agregar una nueva cita a la agenda
    void consultarCitas(); // funcion para mostrar todas las citas registradas en la agenda
    void buscarCita(); // funcion para buscar y mostrar las citas registradas en una fecha especifica
    void editarCita(); // funcion para editar una cita existente en la agenda
    void eliminarCita(); // funcion para eliminar una cita de la agenda
    void finalizacion(); // funcion para terminar el programa

// main
int main() {
    pantallaBienvenida(); // Mostrar pantalla de bienvenida antes del menu
    int opcion=0; // Variable para la opcion del menu seleccionada por el usuario
	char continuar;
    system("cls"); // Limpiar la pantalla
    system("color 0E");   

    //mensaje de que ha ingresado a la agenda 
    cout << "\n\n\t\t==========================================\n"; 
    cout << "\t\t      BIENVENIDO A LA AGENDA PERSONAL     \n";
    cout << "\t\t==========================================\n";

    //bucle para no salir del programa hasta que sea ponga la opcion de salir
        menu(); // Mostrar el menu de opciones al usuario
    cout << "\t\tElige una de las 6 opciones anteriores :)\n\t\t";
	cin >>opcion;
	if (opcion==1){
		agregarCita();
	} else if (opcion==2){
		consultarCitas();
	}  else if (opcion==3){
		buscarCita();
	}  else if (opcion==4){
		editarCita();
	} else if (opcion==5){
		eliminarCita();
	}  else if (opcion==6){
		finalizacion();
	} else 
	  cout <<"Ingrese una opcion valida";
	return 0;
}

//FUNCIONES

void pantallaBienvenida(){   // Esta función  es la pantalla de bienvenida aca va el Art ASCII y pues la bienvenida 
    system("cls"); // Limpiar la pantalla
    system("color 03");  

    //Bienvenida y logo ASCII
    cout << "\t\t =================================================";
    cout << "\n \t\t  UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS :3\n";
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
    cout <<"\t====================================================================\n\n";
    // Boton de ingreso

    cout << "\t\t  [ Presione ENTER para INGRESAR al programa ] \n\n";
    cout << "\t===================================================================\n\n";
    //Valida solo que ingrese enter (deja entrar cualquier entrada)
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <streamsize>::max es no tener limite de caracteres ignorados

}

// Función para mostrar el menu de opciones al usuario
void menu() {
	int opcion;
	system("cls");
	system("color 03");
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
    cout << "\t\tElige una de las 6 opciones anteriores :)\n\t\t";
	cin >>opcion;
	if (opcion==1){
		agregarCita();
	} else if (opcion==2){
		consultarCitas();
	}  else if (opcion==3){
		buscarCita();
	}  else if (opcion==4){
		editarCita();
	} else if (opcion==5){
		eliminarCita();
	}  else if (opcion==6){
		finalizacion();
	} else 
	  cout <<"Ingrese una opcion valida";
}
 // Funcion para la primera opcion
void agregarCita(){
char continuar;
cout <<"Ingrese fecha";
cout <<"¿Desea continuar? s o n";
cin >> continuar;
if (continuar=='s'){
	agregarCita();
} else if (continuar=='n'){
	menu();	
} else 
	cout <<"Ingrese s o n";
	cin >> continuar;
}
// Funcion para la segunda opcion
void consultarCitas(){
cout <<"Lista de citas actualmente";
cout <<"¿Desea continuar? s/n";
}
// Funcion para la tercera opcion
void buscarCita(){
cout <<"Ingrese fecha o nombre de cita a buscar";
cout <<"¿Desea continuar? s/n";
}
// Funcion para la cuarta opcion
void editarCita(){
cout <<"Ingrese fecha o nombre de cita a editar";
cout <<"¿Desea continuar? s/n";
}
// Funcion para la quinta opcion
void eliminarCita(){
cout <<"Ingrese fecha o nombre de cita a eliminar";
cout <<"¿Desea continuar? s/n";
}
// Funcion para la sexta opcion
void finalizacion(){
	system("cls");
	system("color 04");
	char continuar;
	cout << "\t\t================================================================\n";
	cout <<"\t\tConfirma salir? No olvide guardar los datos ingresados. s o n\n\t\t";
	cout << "================================================================\n\t\t";
	cin >>continuar;
	if (continuar=='s'){
	system("cls"); // Limpiar la pantalla
    system("color 0c");  
    //Bienvenida y logo ASCII
    cout << "\t\t =================================================";
    cout << "\n \t\t  UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS :3\n";
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
    cout <<"\t====================================================================\n\n";
	cout <<"\tGracias por usar el programa :))";
	exit(0);
} else if (continuar=='n'){
  	menu();
} else 
	cout <<"\t\tIngrese s o n\n\t\t";
	cin >> continuar;
}

