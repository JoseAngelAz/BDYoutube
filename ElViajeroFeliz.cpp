#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
#include <stdlib.h>
//Limpiar pantalla
#ifdef _WIN32
#define CLEAR "cls"
#elif defined(unix)||defined(__unix__)||defined(__unix)||defined(__APPLE__)||defined(__MACH__)
#define CLEAR "clear"
#else
#error "SO no soportado para limpiar pantalla"
#endif

using namespace std;

//clase menu
class menu
{
private:
    float km_extra;
    //Cliente
    struct 
    {
        string nombre;
        string telefono;
        string correo;
        string NIT;
        int CodigoCliente;

    } Cliente;
    
    //Renta
     struct
    {
        string nombre_vehiculo;
        string tipo_vehiculo;
        float precio;
        float kilometros;        
    } Renta;

public:
    void MenuPrincipal();
    void InsertarClientes();
    void InsertarRentas();
    void BuscarClientes();
    void ModificarClientes();
    void EliminarRentas();
    void mostarRegistro(string codigo);
};

//metodos para pausar y mostrar errores
void pausa();
void error();

//manejador del menu
void menu::MenuPrincipal()
{
    int opcion;
    do
    {
        string msg = "*** Registro de clientes de El Viajefo Feliz ***\n1. Dar de alta un cliente\n2. Mostrar detalles de un cliente\n3. Listar clientes\n4. Dar de baja un cliente\n5. Modificar un cliente\n6. Insertar Renta\n7. Eliminar Renta\n8. Salir\nOpci\242n: ";
        cout<< msg;
        cin>>opcion;
        system(CLEAR);
        switch(opcion)
        {
        default:
            cout<<"Esa opcion no es valida\nElija nuevamente\n";
            break;

        case 1:
            InsertarClientes();
            break;

        case 2:
            InsertarRentas();
            break;

        case 3:
            BuscarClientes();
            break;

        case 4:
            ModificarClientes();
            break;

        case 5:
            EliminarRentas();
            break;        
        case 6:
            break;
        }
    }
    while(opcion!=6);
}

//Insertar Clientes
void menu::InsertarClientes(){
ofstream escritura;
ifstream verificador;
string Codigo_temp;
bool coincidencia = false;

verificador.open("Clientes.txt",ios::in);
escritura.open("Clientes.txt",ios::app);

//validar que este abierta la escritura y verificador
if (escritura.is_open() && verificador.is_open())
{
    /* code */
    cout<<"***Dar de alta un cliente***\nIngresa el codigo del cliente: ";
    getline(cin,Codigo_temp);
    //validar el codigo 
    if(Codigo_temp == "")
    do{
        cout<< "Codigo invalido, intentelo nuevamente: ";
        getline(cin,Codigo_temp);
    }
    while (Codigo_temp == "");
    //hace cuando
    do{
        verificador.seekg(0);
        getline(verificador,Cliente.CodigoCliente);
        while (!verificador.eof())
        {
            /* code */
            getline(verificador, Cliente.nombre);
            getline(verificador, Cliente.telefono);
            getline(verificador, Cliente.NIT);
            getline(verificador, Cliente.correo);
            //validar si es igual el codigo
            if (Cliente.CodigoCliente == Codigo_temp)
            {
                /* code */
                coincidencia = true;
                cout<< "\nYa existe un cliente con ese codigo de cliente\nEl cliente con ese codigo es: "<<Cliente.CodigoCliente<<"\nIngrese un codigo valido";
                getline(cin,Codigo_temp);
                if(Codigo_temp == "")
                    do{
                        cout<<"Codigo de Cliente invalido, intentelo nuevamente: ";
                        getline(cin, Codigo_temp);
                    }
                    while(Codigo_temp == "");
                break;
            }
            getline(verificador, Cliente.CodigoCliente);
        }
        if(verificador.eof() && Codigo_temp != Cliente.CodigoCliente)
        coincidencia = false;
        
    }
    while(coincidencia == true);
    system(CLEAR);
    Cliente.CodigoCliente = Codigo_temp;
    cout<<"**Ingresar Cliente**\nIngresa el codigo del cliente";
    cout<< Cliente.CodigoCliente;
    cout<<"\n"
    fflush(stdin);
    cout<<"Ingresa el nombre del cliente: ";
    getline(cin,Cliente.CodigoCliente);
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingrea el NIT del cliente: ";
    getline(cin, Cliente.NIT);
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingresa el telefono del cliente: ";
    getline(cin,Cliente.telefono);
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingresa el Email del cliente: ";
    getline(cin,Cliente.correo);
    cout<<"\n";
    fflush(stdin);
    //escribir los datos
    escritura<<Cliente.CodigoCliente<<"\n"<<Cliente.nombre<<"\n"<<Cliente.NIT<<"\n"<<Cliente.telefono<<"\n"<<Cliente.correo<<"\n";
    cout<<"El registro se ha completado correctamente.\n";
}
else{
    error();
}
//
escritura.close();
verificador.close();
pausa();
}

//pausar el programa
void pausa(){
    cout<<"Presiona Enter para continuar con el programa...";
    getch();
    system(CLEAR);
}
//mandar errores
void error(){
    cout<<"No se pudo abrir el archivo de registro\nasegurese que el archivo se encuente en la misma ubicacion que el\nprograma o que el archivo de texto se llame: Clientes.txt,\n si el archivo tiene otro nombre\ncambielo al mencionado anteriormente";
}

//Metodo MAIN
int main(){
    system("color f0");
    menu incio;
    incio.MenuPrincipal();
    return 0;
}