#include "iostream"

using namespace std;

//SEGUNDO METODO PARA IMPRIMIR EN CONSOLA
void imprimirConsola(){
    string smg = "SEGUNDO METODO\n";
    string salida1 = "Ejemplo de salida";
    int numero = 2;
    string salida2 = "Desde mi Linux";
    cout<< salida1<<""<<numero<<". "<<salida2<<"\n";
}
//TERCER METODO IMPRIMIR POR CONSOLA PRINTF
void usarprintF(){
    printf("Este es un ejemplo de impersion en consola usando el metodo printf\n");
}
//CUARTO METODO CON PRINTF
void printF2(){
    string msg = "Cuarto metodo con PRINTF";
    string salida1 = "Esta es la salida UNO";
    int numero = 2;
    string salida2 = "Esta es la salida DOS";
    //Se concatenan y se muestran los valores por consola con parametros de printf
    printf("%s %s %d. %s \n", msg.c_str(),salida1.c_str(), numero,salida2.c_str());
}
//ENTRADA DE DATOS POR TECLADO UNO
void datosTeclado(){
     cout << "Hola! Este es un ejemplo en C++" << "\n" << "Por favor ingrese su nombre:" << "\n";
    //inicializamos la variable de tipo string nombre que almacenara el nombre del usuario.
    string nombre;
    //se lee el nombre por telcado y se asigna a la variable nombre
    cin >> nombre;
    cout << "Bienvenido al sistema " << nombre << " Gracias por usar nuestra App\n";
}

//ENTRADA DE DATOS POR TECLADO DOS
void tecladoDos(){
cout << "Hola! Este es un ejemplo en C++" << "\n" << "Por favor ingrese su nombre:" << "\n";
string nombre;//Seguimos usando string para almacenar el nombre
   //cin >> nombre; //Esta línea da problemas si se lee un valor con espacios
   // En su lugar, usamos getline, con el flujo de entrada de cin y lo asignamos as nombre
   getline(cin, nombre); //Esta línea no dará problemas con los espacios en el nombre

   cout << "Bienvenido al sistema " << nombre << ". Gracias por usar nuestra aplicación" << "\n";

}

int main(){
    //mensaje en pantalla
    cout<<"hola mundo"<<"desde mi lunux."<<"\n";
    imprimirConsola();
    usarprintF();
    printF2();
    //datosTeclado();
    tecladoDos();
    return 0;
}

