#include "string"

using namespace std;
 
int main()
{
    char temporal[100];
 
    printf("Tu nombre?\n");
    scanf("%100s", temporal);
    
    string nombre = temporal;
 
    printf("Te doy la bienvenida %s", nombre.c_str());
 
    return 0;
}
