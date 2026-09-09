#include <iostream>
#include <string>
using namespace std;


//Ejercicio 40
struct Persona {
    string nombre;
    string telefono; 
};

//Uso cant para llevar registro la cantidad de contactos que tiene el vector
void cargarContacto(Persona agenda[], int &cant){
    int n;
    cout << "Ingrese la cantidad de contactos a cargar" << "\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Persona nuevoContacto;
        cout << "Ingrese nombre" << "\n";
        cin >> nuevoContacto.nombre;
        cout << "Ingrese el numero" << "\n";
        cin >> nuevoContacto.telefono;
        cant ++;
    }
    
}

void buscarNombrexNumero(Persona agenda[], string nombre, string numero){
    for (int i = 0; i < 50; i++)
    {
        if(agenda[i].nombre == nombre){
            numero = agenda[i].telefono;
        }
    }
}

void buscarNumeroxNumero(Persona agenda[], string nombre, string numero){
    for (int i = 0; i < 50; i++)
    {
        if(agenda[i].telefono == numero){
            nombre = agenda[i].nombre;
        }
    }
}

void modificarNumero(Persona persona, string numeroNuevo){
    persona.telefono = numeroNuevo;
}

void agregarContacto(Persona agenda[], int &cant, string nombre, string telefono) {

    agenda[cant].nombre = nombre;
    agenda[cant].telefono = telefono;
    cant++; 
}

void eliminarContacto(Persona agenda[], Persona contactoAEliminar){
    Persona contactoVacio;
    for (int i = 0; i < 50; i++)
    {
        if(agenda[i].telefono == contactoAEliminar.telefono){
            agenda[i] = contactoVacio;
        }
    }

}


//Ejercicio 42
struct Producto{
    string nombre;
    string codigoBarra;
    int precio;
    bool estaDeOferta;
};


void cargarProductosEnGondola(Producto gondola[], int tamañoGondola, int &articulosEnGondola){
    Producto nuevoProducto;
    do
    {
        cout << "Ingrese nombre del producto o "" para salir" << "\n";
        cin >> nuevoProducto.nombre;
        cout << "Ingrese el codigo de barras" << "\n";
        cin >> nuevoProducto.codigoBarra;
        cout << "Ingrese el precio" << "\n";
        cin >> nuevoProducto.precio;
        cout << "Ingrese si esta de Oferta" << "\n";
        cin >> nuevoProducto.estaDeOferta;
        gondola[articulosEnGondola] = nuevoProducto;
        articulosEnGondola ++;


    } while (nuevoProducto.nombre != "" || tamañoGondola > articulosEnGondola );
    
    
}


Producto buscarProductoxNombre(Producto gondola[], string nombreProducto, int articulosEnGondola){
    for (int i = 0; i < articulosEnGondola; i++)
    {
        if (gondola[i].nombre == nombreProducto)
        {
            return gondola[i];
        }
        
    }
    Producto productoVacio;
    return productoVacio;
}

Producto buscarProductoxCodigoBarra(Producto gondola[], string codigoBarra, int articulosEnGondola){
    for (int i = 0; i < articulosEnGondola; i++)
    {
        if (gondola[i].codigoBarra == codigoBarra)
        {
            return gondola[i];
        }
        
    }
    Producto productoVacio;
    return productoVacio;
}

void modificarPrecioDeProducto(Producto productoAModificar, int nuevoPrecio){
    productoAModificar.precio = nuevoPrecio;
}

void quitarProductoDeGondola(Producto productoAeliminar, Producto gondola[], int articulosEnGondola){
    for (int i = 0; i < articulosEnGondola; i++)
    {
        if(productoAeliminar.codigoBarra == gondola[i].codigoBarra){
            Producto productoVacio;
            gondola[i] = productoVacio;
        }
    }
    
}


int cantidadDeProdEnOferta(Producto gondola[], int articulosEnGondola){
    int ac = 0;
    for (int i = 0; i < articulosEnGondola; i++)
    {
        if(gondola[i].estaDeOferta){
            ac ++;
        }
    }
    return ac;
}

void pagarChango(Producto chango[], int artEnChango, float &precioFinal, float &ahorro){
    for (int i = 0; i < artEnChango; i++)
    {
        if(chango[i].estaDeOferta){
            ahorro += chango[i].precio * 0.1;
            precioFinal += chango[i].precio * 0.9;
    }
    else{
        precioFinal += chango[i].precio;
    }
    
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
