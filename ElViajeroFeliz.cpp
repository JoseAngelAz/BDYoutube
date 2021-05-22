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
    string testCodigo_cliente;
    //Cliente
    struct 
    {
        string nombre;
        string telefono;
        string correo;
        string NIT;
        string CodigoCliente;

    } Cliente;
    //Array Renta
    //int Renta_Array[3] = {1,2,3};
    //Renta
     struct
    {
        string nombre_vehiculo;
        string tipo_vehiculo;
        string precio;
        string kilometros;        
        string Codigo_Renta;
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
        string msg = "*** Registro de clientes de El Viajefo Feliz ***\n1. Insertar Cliente\n2. Insertar Renta\n3. Listar Clientes\n4. Modificar Cliente\n5. Eliminar Renta\n6. Salir\nOpci\242n:\n";
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
    cout<<"\n";
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

//Insertar Rentas
void menu::InsertarRentas(){
ofstream escritura;
ifstream verificador;
string Codigo_temp;
bool coincidencia = false;

verificador.open("Rentas.txt",ios::in);
escritura.open("Rentas.txt",ios::app);

//validar que este abierta la escritura y verificador
if (escritura.is_open() && verificador.is_open())
{
    /* code */
    cout<<"***REGISTRAR RENTA DE AUTO***\nIngresa el codigo de la Renta: ";
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
        getline(verificador,Renta.Codigo_Renta);
        while (!verificador.eof())
        {
            /* code */
            getline(verificador, Renta.nombre_vehiculo);
            getline(verificador, Renta.kilometros);
            getline(verificador, Renta.precio);
            getline(verificador, Renta.tipo_vehiculo);
            //validar si es igual el codigo
            if (Renta.Codigo_Renta == Codigo_temp)
            {
                /* code */
                coincidencia = true;
                cout<< "\nYa existe una Renta con ese codigo de Renta\nLa Renta con ese codigo es: "<<Renta.Codigo_Renta<<"\nIngrese un codigo valido";
                getline(cin,Codigo_temp);
                if(Codigo_temp == "")
                    do{
                        cout<<"Codigo de Renta invalido, intentelo nuevamente: ";
                        getline(cin, Codigo_temp);
                    }
                    while(Codigo_temp == "");
                break;
            }
            getline(verificador, Renta.Codigo_Renta);
        }
        if(verificador.eof() && Codigo_temp != Renta.Codigo_Renta)
        coincidencia = false;
        
    }
    while(coincidencia == true);
    system(CLEAR);
    Cliente.CodigoCliente = Codigo_temp;
    cout<<"**Ingresar Renta**\nIngresa el codigo del Renta";
    cout<< Renta.Codigo_Renta;
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingresa el nombre del vehiculo: ";
    getline(cin,Renta.nombre_vehiculo);
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingresa el tipo de vehiculo: ";
    getline(cin,Renta.tipo_vehiculo);
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingrea la cantidad de kilometros a rrecorrer: ";
    getline(cin, Renta.kilometros);
    cout<<"\n";
    fflush(stdin);
    cout<<"Ingresa el precio de la renta: ";
    getline(cin,Renta.precio);
    cout<<"\n";
    fflush(stdin);
    
    //escribir los datos
    escritura<<Renta.Codigo_Renta<<"\n"<<Renta.nombre_vehiculo<<"\n"<<Renta.tipo_vehiculo<<"\n"<<Renta.kilometros<<"\n"<<Renta.precio<<"\n";
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
//Buscar Clientes
void menu::BuscarClientes(){
	int i=0;
    ifstream lectura;
    lectura.open("Clientes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"***LISTA DE CLIENTES***\n";
        getline(lectura,Cliente.CodigoCliente);
        while(!lectura.eof())
        {
            i++;
            getline(lectura,Cliente.nombre);
            getline(lectura,Cliente.correo);
            getline(lectura,Cliente.NIT);
            getline(lectura,Cliente.telefono);
            cout<<"C\242digo: "<<Cliente.CodigoCliente<<endl;
            cout<<"Nombre: "<<Cliente.nombre<<endl;
            cout<<"Correo: "<<Cliente.correo<<endl;
            cout<<"Celular: "<<Cliente.telefono<<endl;
            cout<<"NIT\n: "<<Cliente.NIT<<endl;            
            getline(lectura,Cliente.CodigoCliente);
        }
        if(i==1)
            cout<<"Hay un solo cliente registrado en El Viajero Feliz\n\n";
        else
            cout<<"Hay un total de "<<i<<" clientes registrados en El Viajero Feliz\n\n";
    }
    else
    {
        error();
    }
    lectura.close();
    pausa();
}

//Modificar clientes
void menu::ModificarClientes(){
	ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string Codigo_temp;
    string codigoModif;
 
    //estructura auxiliar para el cliente
    struct 
    {
        string nombre;
        string telefono;
        string correo;
        string NIT;
        string CodigoCliente;

    } ClienteAuxiliar;
    //
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("Clientes.txt",ios::in);
    verificador.open("Clientes.txt",ios::in);
    auxiliar.open("Auxiliar.txt",ios::out);
    cout<<"*** Modificar los datos de un cliente ***\n";
    //abrimos los manejadores de archivos
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {/*
    la función del fflush, realiza la limpieza del buffer de entrada (stdin) standar input. usualmente quedan almacenados algunos datos en el buffer sobre todo saltos de linea y espacio y se debería usar antes de cada scanf con el fin de garantizar que el buffer este limpio.
    */
        fflush(stdin);
        cout<<"Ingresa el c\242digo del cliente que deseas modificar: ";
        getline(cin,Codigo_temp);

        if(Codigo_temp=="")
        {
            do
            {
                cout<<"c\242digo de cliente no v\240lido!, intentalo nuevamente: ";
                getline(cin,Codigo_temp);
            }
            while(Codigo_temp=="");
        }

        codigoModif = Codigo_temp;

        getline(lectura,Cliente.CodigoCliente);
        while(!lectura.eof())
        {
            getline(lectura,Cliente.nombre);
            getline(lectura,Cliente.NIT);
            getline(lectura,Cliente.correo);
            getline(lectura,Cliente.telefono);

            if(Codigo_temp==Cliente.CodigoCliente)
            {
                encontrado = true;
                mostarRegistro(codigoModif);

                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el cliente\n\n";
                fflush(stdin);
                cout<<"Ingresa el c\242digo del cliente: ";
                getline(cin,Codigo_temp);
                if(Codigo_temp==codigoModif)
                {
                    mismoCodigo=true;
                }
                if(mismoCodigo==false)
                {
                    do
                    {
                        if(Codigo_temp==codigoModif)
                        {
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,Cliente.CodigoCliente);
                        while(!verificador.eof())
                        {
                            getline(verificador,Cliente.nombre);
                            getline(verificador,Cliente.NIT);
                            getline(verificador,Cliente.correo);
                            getline(verificador,Cliente.telefono);

                            if(Codigo_temp==Cliente.CodigoCliente)
                            {
                                coincidencia=true;
                                cout<<"\n\nYa existe un cliente con ese c\242digo!\n\n";
                                cout<<"El cliente con ese c\242digo es: "<<Cliente.nombre<<"\n\n";
                                cout<<"Ingresa un c\242digo v\240lido!: ";
                                getline(cin,Codigo_temp);

                                if(Codigo_temp=="")
                                {
                                    do
                                    {
                                        cout<<"\nc\242digo de cliente no v\240lido!, ";
                                        cout<<"intentalo nuevamente: ";
                                        getline(cin,Codigo_temp);
                                    }
                                    while(Codigo_temp=="");
                                }
                                break;
                            }

                            getline(verificador,Cliente.CodigoCliente);
                        }

                        if(verificador.eof()&&Codigo_temp!=Cliente.CodigoCliente)
                        {
                            coincidencia=false;
                        }

                    }
                    while(coincidencia==true);
                }
                system(CLEAR);
                cout<<"***Modificar los datos de un cliente***\n\n";
                cout<<"Ingresa el c\242digo del cliente que deseas modificar: ";
                cout<<codigoModif;
                mostarRegistro(codigoModif);
                cout<<"**********************************************";
                cout<<"\n\n";
                cout<<"Ingresa la nueva informaci\242n para el cliente\n\n";
                cout<<"Ingresa el c\242digo del cliente: ";
                cout<<Codigo_temp;
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el nombre del cliente: ";
                getline(cin,ClienteAuxiliar.nombre);;
                fflush(stdin);
                cout<<"\n\n";
                cout<<"Ingresa el domicilio del cliente: ";
                getline(cin,ClienteAuxiliar.NIT);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa el n\243mero de telefono del cliente: ";
                getline(cin,ClienteAuxiliar.correo);
                cout<<"\n\n";
                fflush(stdin);
                cout<<"Ingresa la fecha de inscripci\242n del cliente: ";
                getline(cin,ClienteAuxiliar.telefono);
                cout<<"\n\n";
                auxiliar<<Codigo_temp<<"\n"<<ClienteAuxiliar.nombre<<"\n"<<ClienteAuxiliar.NIT<<"\n"<<ClienteAuxiliar.correo
                        <<"\n"<<ClienteAuxiliar.telefono<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }


            else
            {

                auxiliar<<Cliente.CodigoCliente<<"\n"<<Cliente.nombre<<"\n"<<Cliente.NIT<<"\n"<<Cliente.correo
                        <<"\n"<<Cliente.telefono<<"\n";
            }


            getline(lectura,Cliente.CodigoCliente);
        }

    }
    else
    {
        error();
    }

    if(encontrado==false)
    {
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("Clientes.txt");
    rename("Auxiliar.txt","Clientes.txt");
    pausa();

}

//Eliminar Rentas
void menu::EliminarRentas(){
	
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
void menu::mostarRegistro(string codigo)
{

    ifstream mostrar;
    mostrar.open("Clientes.txt",ios::in);
    getline(mostrar,Cliente.CodigoCliente);
    while(!mostrar.eof())
    {
        getline(mostrar,Cliente.nombre);
        getline(mostrar,Cliente.NIT);
        getline(mostrar,Cliente.correo);
        getline(mostrar,Cliente.telefono);

        if(codigo==Cliente.CodigoCliente)
        {
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<"C\242digo: "<<Cliente.CodigoCliente<<endl;
            cout<<"Nombre: "<<Cliente.nombre<<endl;
            cout<<"Domicilio: "<<Cliente.NIT<<endl;
            cout<<"Celular: "<<Cliente.correo<<endl;
            cout<<"Fecha de inscripci\242n: "<<Cliente.telefono<<endl;
            cout<<"\n\n";
        }

        getline(mostrar,Cliente.CodigoCliente);
    }

    mostrar.close();
}
//Metodo MAIN
int main(){
    system("color f0");
    menu incio;
    incio.MenuPrincipal();
    return 0;
}
