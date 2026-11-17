# Sistema de Bicicletas Públicas

Trabajo Práctico de Algoritmos — Licenciatura en Informática (UNAHUR), 2.º cuatrimestre 2026.

Sistema en C++ (orientado a objetos, memoria dinámica) que gestiona la red de estaciones de bicicletas públicas de la Ciudad de Buenos Aires: estaciones, bicicletas, viajes y redistribución de bicicletas.

**Integrantes:** _(completar)_

---

## Índice

1. [Instrucciones de compilación](#1-instrucciones-de-compilación)
2. [Estructura del proyecto](#2-estructura-del-proyecto)
3. [Descripción de los módulos](#3-descripción-de-los-módulos)
4. [Respuestas a las consignas de análisis](#4-respuestas-a-las-consignas-de-análisis)
5. [Datos de la tabla de hash](#5-datos-de-la-tabla-de-hash)

---

## 1. Instrucciones de compilación

> _Pendiente: se completa cuando el proyecto esté finalizado._

**Requisitos:** _(completar)_

**Compilación:**

```bash
# (completar)
```

**Ejecución:**

```bash
# (completar)
```

**Verificación de memoria (Valgrind):**

```bash
# (completar)
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
│   ├─ Taller/
│   ├── Menu/
│   ├── Ordenador/
│   ├── Redistribucion/
│   ├── RegistroBicicletas/
│   ├── RegistroViajes/
│   └── GestorEstaciones/
└── Estructuras/              # Estructuras de datos implementadas a mano
    ├── Cola/
    ├── LIstaEnlazadaViajes/
    ├── ABB/
    ├── Grafo/
    ├── Lista/
    └── Tabla Hash/
```

_(Ajustar al árbol final del proyecto.)_

---

## 3. Descripción de los módulos

Ninguna estructura usa contenedores de la STL (`vector`, `map`, `queue`, etc.). Todas se implementaron a mano; solo se usa `std::string` y la STL para leer archivos.

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

#### `Lista<T>` (lista enlazada con templates)
_(Verificar si queda o no)_
Lista enlazada genérica implementada con templates, que permite almacenar distintos tipos de dato sin duplicar código. _(Indicar dónde se usa: por ejemplo, en la tabla de hash para resolver colisiones por encadenamiento, o para otras listas del sistema.)_

#### Tabla de hash
Indexa las estaciones por código con resolución de colisiones. Se usa el metodo de hash mid square y resolucion de colisiones mediante hashing abierto

#### Grafo de ciclovías 
Representa las conexiones bidireccionales entre estaciones. Se utilizo una matriz de adyacencia pare representar al grafo

#### Árbol binario de búsqueda (ABB) 
Registro de todas las bicicletas, ordenado por `bici_id`. 

### 3.3. Gestión y menú

#### Gestor de estaciones _(pendiente de documentar)_
_(Completar)_

#### Redistribución con backtracking _(pendiente de documentar)_

#### Carga de archivos _(pendiente de documentar)_
_(Completar: lectura de `estaciones.txt`, `bicicletas.txt`, `viajes.txt` y `ciclovias.txt`.)_

#### `main.cpp` — menú por consola
_(Completar: lista de opciones del menú y a qué funcionalidad corresponde cada una.)_

---


## 4. Respuestas a las consignas de análisis

### Sección A — Gestión de estaciones

_(Opcional: complejidad de cada operación sobre la tabla de hash, del ordenamiento elegido y del BFS.)_

### Sección B — Viajes y colas de espera

Para cada punto: complejidad temporal en notación Big O y por qué se eligió la estructura (2 o 3 oraciones).

**B.1. Cantidad de viajes desde una estación en un rango de fechas**
- Complejidad: _(completar)_
- Estructura elegida y justificación: _(completar)_

**B.2. Viajes de un usuario por DNI y total de minutos**
- Complejidad: _(completar)_
- Estructura elegida y justificación: _(completar)_

**B.3. Bicicletas con más de X kilómetros**
- Complejidad: _(completar)_
- Estructura elegida y justificación: _(completar)_

**B.4. Cola de espera por estación**
- Complejidad (`encolar` / `desencolar`): _(completar)_
- Estructura elegida y justificación: _(completar)_

**B.5. Cola de prioridad (min-heap) para el taller**
- Complejidad (`insertar` / `extraerMasUrgente`): _(completar)_
- Estructura elegida y justificación: _(completar)_

### Sección C — Árbol binario de búsqueda

**¿Qué altura tendría el árbol si las bicicletas se cargaran ordenadas por ID? ¿Cómo afecta eso al costo de la búsqueda?**

Ejemplo con 5 bicicletas: _(completar con IDs, dibujo del árbol, altura y cantidad de comparaciones en la búsqueda)_

### Sección D — Backtracking

**Complejidad temporal en el peor caso:** _(completar)_

---

## 5. Datos de la tabla de hash

Datos de prueba utilizados: _(completar)_

| Dato | Valor |
|---|---|
| Cantidad de estaciones cargadas | _(completar)_ |
| Tamaño de la tabla | _(completar)_ |
| Cantidad de colisiones | _(completar)_ |
| Factor de carga final | _(completar)_ |
