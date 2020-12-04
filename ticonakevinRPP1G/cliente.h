#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct{
    int id;
    int dni;
    char nombre[51];
    char apellido[51];
    int isEmpty;
}eCliente;


#endif // CLIENTE_H_INCLUDED
int inicializar_Cliente(eCliente* lista, int tam);
int altaCliente(eCliente listCliente[], int tamC, int id);
int modificarCliente(eCliente listCliente[], int tamC);
int bajaCliente(eCliente* listCliente, int tamC);
void mostrarCliente(eCliente listCliente);
int mostrarClientes(eCliente* listClientes, int tamC);
int findClienteById(eCliente list[], int len,int id);
int obtenerDescripcionCliente(eCliente lista[], int len, int ID, char descripcion[]);

