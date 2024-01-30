#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <climits>

using namespace std;

char opcion;
string nombre[] = {"Martina", "Alejandro", "Isabella", "Mateo", "Camila", "Juan", "Yandira", "Jesus", "Eduardo", "Rosa"};
string apellido[] = {"Torres", "Lopez", "Salame", "Fernandez", "Rodriguez", "Escobal", "Salvatierra", "Flores", "Escudero", "Gutierrez"};
int notas[10];
string contra[10];
string nombreOfuscado[10];
string apellidoOfuscado[10];

void cambiarVocales(string& valor_dos, char vocal, char numero)//Funcion para Cambiar las letras por numero
{
	size_t site = 0;
	do {
		site = valor_dos.find(vocal, site);
		if (site != string::npos)
			valor_dos[site] = numero;
		if (site != string::npos)
			site++;
	} while (site != string::npos);
}

void ofuscar()//Funcion para ejecutar la ufuscado de los nombres y apellidos y usarlos como contraseña
{
	for (int i = 0; i < 10; i++) {
		nombreOfuscado[i] = nombre[i];
		apellidoOfuscado[i] = apellido[i];
		
		cambiarVocales(nombreOfuscado[i], 'a', '4');
		cambiarVocales(nombreOfuscado[i], 'e', '3');
		cambiarVocales(nombreOfuscado[i], 'i', '1');
		cambiarVocales(nombreOfuscado[i], 'o', '0');
		cambiarVocales(nombreOfuscado[i], 's', '5');
		cambiarVocales(nombreOfuscado[i], 't', '7');
		
		cambiarVocales(apellidoOfuscado[i], 'a', '4');
		cambiarVocales(apellidoOfuscado[i], 'e', '3');
		cambiarVocales(apellidoOfuscado[i], 'i', '1');
		cambiarVocales(apellidoOfuscado[i], 'o', '0');
		cambiarVocales(apellidoOfuscado[i], 's', '5');
		cambiarVocales(apellidoOfuscado[i], 't', '7');
		
		contra[i] = nombreOfuscado[i] + apellidoOfuscado[i]; // Contraseña es la concatenación de nombre y apellido ofuscados
	}
}

void generarCon() //Funcion para generar la contraseña ofusgada
{
	ofuscar(); // Llamar a la función de ofuscación
	cout << "Contraseñas" << endl;
	for (int i = 0; i < 10; i++) {
		cout << contra[i] << endl;
	}
}

void imprimirContra()//Funcion para poder imprimir la contraseña
{
	for (int i = 0; i < 10; i++) {
		cout << contra[i] << endl;
	}
}

int generarNota() //Genera valores aleatorios entre 0 - 30
{
	return rand() % 31;
}

string nombreU() //Genera un orden aleatorio de nombres de la cadena nombre[]
{
	return nombre[rand() % 10];
}

string apellidoU() //Genera un orden aleatorio de nombres de la cadena apellido[]
{
	return apellido[rand() % 10];
}


void imprimir() //Muestra los valores de nombre, apellido y nota
{
	cout << "Datos de los estudiantes" << endl;
	cout << "Nombre   \t    Apellido   \t    Nota" << endl;
	for (int i = 0; i < 10; i++) {
		cout << nombre[i] << "   \t"<<"  |  "<< apellido[i] << "   \t"<<"  |  "<< notas[i] << endl;
	}
}

void imprimirTodo() //Muestra los valores de nombre, apellido, nota y contraseña
{
	cout << "Datos de los estudiantes" << endl;
	cout << "Nombre\t          Apellido\t   Nota\t      contraseña" << endl;
	for (int i = 0; i < 10; i++) {
		cout << nombre[i] << "\t  " << " | " << apellido[i] << " \t " << " | "<< notas[i]<<"\t  "<< " | "<< contra[i] << endl;
	}
}

void antDuplicadoNom() //Evita que se duplique cierta cantidad de nombres
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = i + 1; j < 10; j++) 
		{
			while (nombre[i] == nombre[j]) 
			{
				nombre[j] = nombreU();
			}
		}
	}
}

void MediaNota()//Funcion para verificar la medio de calificaciones
{
	int suma = 0;
	for (int i = 0; i < 10; i++) 
	{
		suma += notas[i];
	}
	double media = static_cast<double>(suma) / 10;
	cout << "Media de todas las notas: " << media << endl;
}

void MayorAndMenor() //Funcion para ver la mayor y menor nota total
{
	int notaMayor = INT_MIN;
	int notaMenor = INT_MAX;
	string estudianteMayor, estudianteMenor;
	
	for (int i = 0; i < 10; i++) 
	{
		if (notas[i] > notaMayor) 
		{
			notaMayor = notas[i];
			estudianteMayor = nombre[i] + " " + apellido[i];
		}
		
		if (notas[i] < notaMenor) 
		{
			notaMenor = notas[i];
			estudianteMenor = nombre[i] + " " + apellido[i];
		}
	}
	
	cout << "Estudiante con la nota más alta: " << estudianteMayor << ", Nota: " << notaMayor << endl;
	cout << "Estudiante con la nota más baja: " << estudianteMenor << ", Nota: " << notaMenor << endl;
}

void antDuplicadoApe()////Evita que se duplique cierta cantidad de apellidos
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = i + 1; j < 10; j++) 
		{
			while (apellido[i] == apellido[j]) 
			{
				apellido[j] = apellidoU();
			}
		}
	}
}

void generar()//Genera un orden aleatorio de nombres
{
	for (int i = 0; i < 10; i++) 
	{
		nombre[i] = nombreU();
		antDuplicadoNom();
		apellido[i] = apellidoU();
		antDuplicadoApe();
	}
}

void generarNotas() // Genera un orden aleatorio de valores de notas
{
	for (int i = 0; i < 10; i++) 
	{
		notas[i] = generarNota();
	}
}

void menu() //Menu principal
{
	cout << "(1)- Llenar nombres, apellidos y notas de forma aleatoria" << endl;
	cout << "(2)- Ofuscar nombres y apellidos para llenar las contraseñas" << endl;
	cout << "(3)- Sacar la media, el mayor y menor de todas las notas" << endl;
	cout << "(4)- Imprimir datos" << endl;
	cout << "(s/S)- Salir" << endl;
	cin >> opcion;
}

int main(int argc, char *argv[]) 
{
	srand(time(nullptr));
	do {
		menu();
		opcion = tolower(opcion);
			switch(opcion) 
			{
				case '1':
					system("cls");
					generar();
					generarNotas();
					imprimir();
				break;
				case '2':
					system("cls");
					generarCon();
				break;
				case '3':
					system("cls");
					MediaNota();
					MayorAndMenor();
				break;
				case '4':
					system("cls");
					imprimirContra();
					imprimirTodo();
				break;
				case 's':
					cout << "Saliendo del programa" << endl;
				break;
				default:
					cout << "Opción no válida. Inténtelo de nuevo." << endl;
				break;
		}
	} while(opcion != 's');
	
	return 0;
}
