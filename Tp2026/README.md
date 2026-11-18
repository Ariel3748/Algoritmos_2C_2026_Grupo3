# Sistema de Bicicletas Públicas

Trabajo Práctico de Algoritmos — Licenciatura en Informática (UNAHUR), 2.º cuatrimestre 2026.

Sistema en C++ (orientado a objetos, memoria dinámica) que gestiona la red de estaciones de bicicletas públicas de la Ciudad de Buenos Aires: estaciones, bicicletas, viajes y redistribución de bicicletas.

**Integrantes:** Lisandro Rubianes, Ariel Oliva

---

## Índice

1. [Instrucciones de compilación](#1-instrucciones-de-compilación)
2. [Estructura del proyecto](#2-estructura-del-proyecto)
3. [Descripción de los módulos](#3-descripción-de-los-módulos)
4. [Respuestas a las consignas de análisis](#4-respuestas-a-las-consignas-de-análisis)

---

## 1. Instrucciones de compilación

**Compilación:**

```bash
g++ -std=c++17 -Wall -Wextra -I. -IEstructuras/ABB -IEstructuras/Cola -IEstructuras/Grafo -IEstructuras/LIstaEnlazadaViajes -IEstructuras/Lista -IEstructuras/TablaHash -ITDA/Bicicleta -ITDA/Estacion -ITDA/GestorArchivos -ITDA/GestorEstaciones -ITDA/Menu -ITDA/Ordenador -ITDA/Redistribucion -ITDA/RegistroBicicletas -ITDA/RegistroViajes -ITDA/Taller -ITDA/Viaje main.cpp TDA/Bicicleta/Bicicleta.cpp TDA/Estacion/Estacion.cpp TDA/GestorArchivos/GestorArchivos.cpp TDA/GestorEstaciones/GestorEstaciones.cpp TDA/Menu/Menu.cpp TDA/Ordenador/Ordenador.cpp TDA/Redistribucion/Redistribucion.cpp TDA/RegistroBicicletas/RegistroBicicletas.cpp TDA/RegistroViajes/RegistroViajes.cpp TDA/Taller/Taller.cpp TDA/Viaje/Viaje.cpp Estructuras/TablaHash/NodoHash.cpp Estructuras/TablaHash/TablaHash.cpp Estructuras/Cola/Cola.cpp Estructuras/Cola/NodoCola.cpp Estructuras/LIstaEnlazadaViajes/ListaViajes.cpp Estructuras/LIstaEnlazadaViajes/NodoViaje.cpp Estructuras/Grafo/Grafo.cpp -o app
```

**Ejecución:**

```bash
./app
```
---

## 2. Estructura del proyecto

```
Tp2026/
├── main.cpp
├── TDA/                      # Clases del dominio
│   ├── Estacion/
│   ├── Bicicleta/
│   ├── Viaje/
│   ├── RegistroViajes/
│   ├── Taller/
│   ├── Menu/
│   ├── Ordenador/
│   ├── Redistribucion/
│   ├── RegistroBicicletas/
│   ├── RegistroViajes/
│   └── GestorEstaciones/
│   └── GestorArchivos/
└── Estructuras/              # Estructuras de datos implementadas a mano
    ├── Cola/
    ├── LIstaEnlazadaViajes/
    ├── ABB/
    ├── Grafo/
    ├── Lista/
    └── Tabla Hash/
```
---
## 3. Descripción de los módulos
---
### 3.1. Clases del dominio (`TDA/`)

#### `Estacion`
Representa una estación de la red: código, nombre, barrio, capacidad de anclajes y bicicletas disponibles. Contiene una `Cola` de espera de usuarios, identificados por DNI.
- `retirarBici(dni)`: si hay bicicletas disponibles descuenta una; si no, encola al usuario.
- `devolverBici()`: si hay usuarios esperando, asigna la bicicleta directamente al primero de la cola; si no, suma una disponible.
- `getOcupacion()`: devuelve bicis disponibles / capacidad (usado para listar estaciones con menos del 20 % de ocupación).

#### `Bicicleta`
Guarda ID, estación, tipo (`Mecanica` / `Electrica`), estado (`OK` / `Averiada`), kilómetros y prioridad de reparación. El setter de prioridad aplica la regla de que las eléctricas siempre entran con prioridad 1. Es el dato que almacenan el ABB de bicicletas y el taller.

#### `Viaje`
Registro de un viaje: ID, bicicleta, DNI del usuario, estación de origen y destino, fecha (`AAAAMMDD`) y duración en minutos.

#### `RegistroViajes`
Colección de todos los viajes del sistema. Se construye sobre `ListaViajes`.
- `contarViajesDesdeEstacion(codigo, fechaDesde, fechaHasta)`: cuenta los viajes que salieron de una estación en un rango de fechas.
- `buscarPorDni(dni)`: muestra los viajes de un usuario y devuelve el total de minutos pedaleados.

#### `Taller`
Cola de prioridad (**min-heap**) para las reparaciones, implementada sobre un arreglo dinámico de `Bicicleta*` que se duplica cuando se llena. La prioridad (1 a 3) es un atributo de `Bicicleta`. Operaciones: `insertar` y `extraerMasUrgente`, con los auxiliares `subir` y `bajar` para mantener la propiedad de heap. El taller **no es dueño** de las bicicletas: no las libera en su destructor.

### 3.2. Estructuras de datos (`Estructuras/`)

#### `Cola` y `NodoCola`
Cola FIFO enlazada con punteros `frente` y `final`, que guarda enteros (DNI). Se usa en dos lugares:
- Como cola de espera dentro de cada `Estacion`.
- Como cola auxiliar del recorrido BFS entre estaciones.

#### `ListaViajes` y `NodoViaje`
Lista simplemente enlazada de `Viaje*` con inserción al principio en O(1). Es **dueña de los viajes**: su destructor libera cada `Viaje` y cada nodo. Es la base de `RegistroViajes`.

#### `Lista<T>` y `NodoLista<T>` (lista enlazada con templates)
Lista simplemente enlazada **genérica**: `agregar` (al principio, O(1)), `eliminarPrimero`, `getPrimero`, `getCantidad` y `estaVacia`. Funciona como una pila, por eso se usa en `Redistribucion` para ir armando y deshaciendo la selección de estaciones durante el backtracking (`Lista<Estacion*>`). La lista **no es dueña** de los elementos: solo libera sus nodos.

#### Tabla de hash
Indexa las estaciones por código con resolución de colisiones. Se usa el metodo de hash mid square y resolucion de colisiones mediante hashing abierto

#### Grafo de ciclovías 
Representa las conexiones bidireccionales entre estaciones. Se utilizo una matriz de adyacencia pare representar al grafo

#### `ABB<T>` y `NodoABB<T>` (árbol binario de búsqueda con templates)
Árbol genérico que usa los operadores `<` y `==` del tipo almacenado. Operaciones: `insertarNodo`, `buscarABB`, `recorrer` (inorder, recibe una función como parámetro), `getAlturaArbol` (altura de un árbol vacío = −1, de una hoja = 0) y liberación de memoria en **postorder** desde el destructor.


#### `Grafo`
Representa la red de **ciclovías** entre estaciones. Las conexiones son bidireccionales (grafo no dirigido y no ponderado).

### 3.2. Clases del dominio (`TDA/`)
 
#### `Estacion`
 
Representa una estación: código, nombre, barrio, capacidad de anclajes y bicicletas disponibles. Contiene (por composición) una `Cola` de espera de usuarios identificados por DNI.
 
- `retirarBici(dni)`: si hay bicicletas disponibles descuenta una; si no, encola al usuario.
- `devolverBici()`: si hay usuarios esperando, asigna la bicicleta directamente al primero; si no, suma una disponible.
- `getOcupacion()`: bicis disponibles / capacidad (usado para listar estaciones con menos del 20 %).
#### `GestorEstaciones`
 
Fachada de la sección A. Contiene la `TablaHash` y el `Ordenador` por composición.
 
- `agregarEstacion`: rechaza códigos repetidos (busca antes en la tabla) y crea la `Estacion` con `new`.
- `mostrarEstacion` / `eliminarEstacion`: delegan en la tabla e informan si el código no existe.
- `listarOrdenadas(porCapacidad)`: obtiene todas las estaciones de la tabla, las ordena con el `Ordenador` y las muestra. Libera solo el arreglo de punteros, porque las estaciones pertenecen a la tabla.
- `listarPocaOcupacion`: lista las estaciones con ocupación menor a 0,20.
- `getColisiones` / `getFactorCarga`: exponen las métricas de la tabla.
#### `Ordenador`
 
Ordena un arreglo de `Estacion*` por capacidad de anclajes o por bicicletas disponibles con **ordenamiento por inserción** hecho a mano (O(n²) en el peor caso, O(n) si ya está casi ordenado).
 
#### `Bicicleta`
 
ID, estación, tipo (`Mecanica` / `Electrica`), estado (`OK` / `Averiada`), kilómetros y prioridad de reparación. El setter de prioridad aplica la regla de que las eléctricas siempre entran con prioridad 1.
 
#### `Viaje`
 
Registro de un viaje: ID, bicicleta, DNI, estación de origen y destino, fecha (`AAAAMMDD`) y duración en minutos.
 
#### `RegistroViajes`
 
Colección de todos los viajes, construida por composición sobre `ListaViajes`.
 
- `contarViajesDesdeEstacion(codigo, fechaDesde, fechaHasta)`: cuenta los viajes que salieron de una estación en un rango de fechas.
- `buscarPorDni(dni)`: muestra los viajes de un usuario y devuelve el total de minutos pedaleados.
#### `RegistroBicicletas`
 
Contiene un `ABB<Bicicleta>` ordenado por `biciId`. Operaciones: agregar, buscar por ID, listar en orden (inorder), contar averiadas (recorriendo el árbol) y listar las bicicletas con más de X kilómetros.
 
#### `Taller`
 
Cola de prioridad (**min-heap**) sobre un arreglo dinámico de `Bicicleta*` que se duplica al llenarse. Operaciones: `insertar` y `extraerMasUrgente`, con los auxiliares `subir` y `bajar`. El taller **no es dueño** de las bicicletas.
 
#### `Redistribucion`
 
Resuelve el punto D con **backtracking**. Recibe la capacidad del camión y una `Lista<Estacion*>`; el faltante de cada estación es `capacidadAnclajes − bicisDisponibles`. Va armando subconjuntos con una lista auxiliar que funciona como pila: agrega una estación, llama recursivamente con las que siguen, y la quita al volver. Poda cuando la suma supera C e imprime el subconjunto cuando la suma es exactamente C. Si no encuentra ninguno, informa que no hay solución.
 
#### `Menu`
 
Menú por consola con submenús por sección: Estaciones (A), Viajes y cola de espera (B), Registro de bicicletas (C) y Redistribución (D). 

#### `GestorArchivos`

Carga nuestra data desde los archivos .txt a las clases correspondientes.
 
#### `main.cpp`
 Carga de los cuatro archivos de entrada, creación del menú y liberación de memoria.
 
---


## 4. Respuestas a las consignas de análisis

### Sección A — Gestión de estaciones

Estaciones: 12
Tamanio: 13
Colisiones: 5
Factor de carga: 0.923077
Justificación de la función de hash y de la resolución de colisiones

Función de hash (cuadrado medio). Convertimos el código de la estación en un número interpretando sus caracteres ASCII como dígitos en base 256, lo elevamos al cuadrado y nos quedamos con los dígitos del medio, aplicando después el módulo del tamaño de la tabla. Elegimos este método por tres motivos:

La base 256 le da un peso distinto a cada posición del código, por lo que códigos con las mismas letras en distinto orden (por ejemplo PAL y LAP) generan claves distintas. Una simple suma de los valores ASCII los haría colisionar siempre.
Al elevar al cuadrado, los dígitos del medio dependen de todos los caracteres del código y no solo de los primeros o los últimos. Esto reparte mejor códigos parecidos entre los casilleros.
Es fácil de implementar y de explicar.

Como limitación, con códigos de más de 8 caracteres la clave se trunca módulo 2^64. Los códigos de estación tienen 3 letras, así que no es un problema en este sistema.

Resolución de colisiones (encadenamiento separado). Cada casillero de la tabla apunta a una lista enlazada, y las estaciones que caen en el mismo casillero se guardan en esa lista. Elegimos este método porque:

La tabla nunca se llena: el factor de carga puede superar 1 y se pueden agregar estaciones sin redimensionar.
La baja de una estación, que es un requisito del sistema, se resuelve simplemente reenganchando la lista. Con direccionamiento abierto habría que usar marcas de borrado para no cortar las búsquedas.
Una colisión no desplaza a otras claves hacia casilleros vecinos, así que no hay agrupamiento.
Es simple de implementar y reutiliza el concepto de lista enlazada ya usado en el proyecto.

El costo es la memoria adicional de un puntero por nodo, que para la cantidad de estaciones de este sistema es despreciable.

### Sección B — Viajes y colas de espera

Para cada punto: complejidad temporal en notación Big O y por qué se eligió la estructura (2 o 3 oraciones).

1) Complejidad O(V), se utilizo una lista enlazada ya que no hay ningun orden que aprovechar

2) Complejidad: O(V). Se recorre la lista una vez, se muestran los viajes cuyo dniUsuario coincide y se acumulan los minutos en un contador. No hay forma de saltarse viajes sin una estructura auxiliar, y con una sola pasada alcanza.

4) Complejidad O(1) al ecnolar y desencolar. Se utilizo una lista enlazada con frente y final ya que era lo mas eficiente para el tipo de problema que se plantea, aprovechando el principio FIFO

5) Insertar y extraer cuestan O(log n) en el peor caso, porque el heap es un árbol completo de altura log n y ambas operaciones recorren a lo sumo un camino de la raíz a una hoja
Se utilizo un array conjunto en memoria y dinamico ya que era mas eficiente que armar un arbol izquierdista que cumpla con la propiedad de heap

### Sección C — Árbol binario de búsqueda

**¿Qué altura tendría el árbol si las bicicletas se cargaran ordenadas por ID? ¿Cómo afecta eso al costo de la búsqueda?**

si las bicicletas se cargan ordenadas por ID, el árbol se degenera en una lista enlazada. En `insertarNodo`, un ID menor que el de la raíz va a la izquierda y, si no, a la derecha. Al cargar en orden ascendente, cada ID nuevo es mayor que todos los anteriores, así que siempre va al hijo derecho (en orden descendente iría siempre al izquierdo). El árbol no se ramifica: cada nodo tiene un solo hijo.
 
La altura pasa a ser proporcional a la cantidad de bicicletas N: el árbol tiene N niveles, la búsqueda deja de ser O(log N) y pasa a **O(N)**, porque en el peor caso hay que recorrer todos los nodos.

### Sección D — Backtracking

**Complejidad temporal en el peor caso:** 

Complejidad temporal en el peor caso: O(2ⁿ), donde n es la cantidad de estaciones. El backtracking decide, para cada estación, si se incluye o no en el camión, por lo que el árbol de decisiones tiene hasta 2ⁿ ramas. La poda por suma mayor a C reduce el trabajo en la práctica, pero no el peor caso: si los faltantes son chicos respecto de C, casi ningún subconjunto se descarta y hay que recorrerlos todos.

---
