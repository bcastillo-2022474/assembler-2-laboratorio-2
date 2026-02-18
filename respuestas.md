# Universidad del Valle de Guatemala
## Facultad de Ingeniería — CC3086 Programación de Microprocesadores
### Laboratorio 02 — Ciclo 1 de 2026 — Respuestas

---

## Asignación 3 — Corrección de errores de compilación (15 pts)

### errores1.cpp

| Archivo | Línea | Descripción del error | Corrección propuesta |
|---|---|---|---|
| **errores1.cpp** | 1-2 | Falta `#include <iomanip>` necesario para `setprecision` en la línea 22 | Agregar `#include <iomanip>` en los includes |
| **errores1.cpp** | 8 | `cin >> x` sin punto y coma al final | Cambiar a `cin >> x;` |
| **errores1.cpp** | 21 | División entera: `suma / n` donde ambos son `int`, el resultado truncado se asigna a `double` | Cambiar a `(double)suma / n` para hacer division en punto flotante |
| **errores1.cpp** | 24 | `return 0` sin punto y coma al final | Cambiar a `return 0;` |

#### Diff errores1.cpp

```diff
+#include <iomanip>

-    cin >> x
+    cin >> x;

-    double promedio = suma / n;
+    double promedio = (double)suma / n;

-    return 0
+    return 0;
```

---

### errores2.cpp

| Archivo | Línea | Descripción del error | Corrección propuesta |
|---|---|---|---|
| **errores2.cpp** | 15-20 | `case 1:` declara la variable `double lado` sin llaves `{}`. En C++ es ilegal saltar sobre la inicialización de una variable, lo que causa error de compilación | Encerrar el cuerpo de `case 1:` con llaves `{ }` |
| **errores2.cpp** | 41 | `cout << "Fin del programa" << endl` sin punto y coma al final | Agregar `;` al final de la línea |

#### Diff errores2.cpp

```diff
-        case 1:
-            cout << "Ingrese el lado: ";
-            double lado;
-            cin >> lado;
-            cout << "Area: " << lado * lado << endl;
-            break;
+        case 1: {
+            cout << "Ingrese el lado: ";
+            double lado;
+            cin >> lado;
+            cout << "Area: " << lado * lado << endl;
+            break;
+        }

-    cout << "Fin del programa" << endl
+    cout << "Fin del programa" << endl;
```

---

### errores3.cpp

| Archivo | Línea | Descripción del error | Corrección propuesta |
|---|---|---|---|
| **errores3.cpp** | 10 | `const int limite;` — constante declarada sin inicializar. En C++ una variable `const` **debe** inicializarse en la declaración | Cambiar a `const int limite = n;` |
| **errores3.cpp** | 15 | `for (int i = 0; i <= limite; i++)` — usa `<=` en lugar de `<`, lo que provoca acceso fuera de rango en el vector (`valores[limite]` no existe) | Cambiar a `i < limite` |

#### Diff errores3.cpp

```diff
-    const int limite;
+    const int limite = n;

-    for (int i = 0; i <= limite; i++) {
+    for (int i = 0; i < limite; i++) {
```

---

## Asignación 4 — Programas que compilan pero no funcionan (10 pts)

### programa1.cpp

| Pregunta | Respuesta |
|---|---|
| ¿Qué esperas que haga este programa? | Leer `n` valores enteros del usuario, calcular su promedio como número decimal con 2 dígitos de precisión e imprimirlo en pantalla. |
| ¿Qué realmente hace? | Imprime el promedio truncado a entero (sin decimales), aunque lo asigna a `double`. Por ejemplo, si la suma es 7 y n es 2, imprime `3.00` en lugar de `3.50`. |
| ¿Cuál es el problema específico? | La expresión `suma / n` realiza **división entera** porque ambos operandos (`suma` e `n`) son de tipo `int`. El cociente entero se asigna luego a `double`, pero el dato ya está truncado. |
| ¿Por qué no hay error de compilación? | C++ permite asignar un `int` a un `double` de forma implícita (conversión implícita de tipos). La operación `suma / n` es válida para enteros; el compilador no puede saber que el programador quería división en punto flotante. |
| Código corregido | `double promedio = (double)suma / n;` — el cast fuerza que al menos un operando sea `double`, lo que convierte la operación a división de punto flotante. |

#### Diff programa1.cpp

```diff
-    double promedio = suma / n;
+    double promedio = (double)suma / n;
```

---

### programa2.cpp

| Pregunta | Respuesta |
|---|---|
| ¿Qué esperas que haga este programa? | Intercambiar los valores de dos variables enteras `x` e `y` usando la función `intercambiar`, e imprimir los valores después del intercambio. |
| ¿Qué realmente hace? | Imprime los valores originales sin cambio alguno. Si el usuario ingresa `x=3, y=7`, el programa seguirá mostrando `x=3 y=7`. |
| ¿Cuál es el problema específico? | La función `intercambiar(int a, int b)` recibe los parámetros **por valor**. Eso significa que `a` y `b` son copias locales; cualquier cambio dentro de la función no afecta a `x` e `y` en `main`. |
| ¿Por qué no hay error de compilación? | Pasar argumentos por valor es completamente válido en C++. El compilador no sabe si la intención era modificar las variables originales; simplemente cumple la sintaxis correcta. |
| Código corregido | `void intercambiar(int& a, int& b)` — agregar `&` convierte los parámetros en **referencias**, haciendo que `a` y `b` sean alias de `x` e `y`, y los cambios dentro de la función sí afectan a las variables originales. |

#### Diff programa2.cpp

```diff
-void intercambiar(int a, int b) {
+void intercambiar(int& a, int& b) {
```

---

## Asignación 5 — Programa original con errores intencionales (30 pts)

### Descripción del programa

**Archivo:** `src/mi_programa.cpp` (versión con errores) y `src/mi_programa_corregido.cpp` (versión corregida)

El programa es una **calculadora de calificaciones estudiantiles** que:
- Lee el nombre del estudiante (`string`)
- Lee 5 notas (`double`) dentro de un rango válido usando un ciclo `while`
- Calcula el promedio
- Determina si el estudiante aprobó (nota ≥ 61)
- Asigna una categoría de letra (A/B/C/D/F)
- Usa constantes (`const`) para el número de notas y la nota mínima
- Usa conversión de tipos (`(int)`)

### Descripción del programa

**Calculadora de puntos para torneo de videojuego.** Lee el nombre del jugador, aplica una penalización de vidas, determina su rango y calcula un bonus. Los 5 errores son **quirks y trampas reales del lenguaje C++**, todos compilan sin errores (solo warnings en algunos casos).

### Conceptos incluidos

| Concepto | Implementación |
|---|---|
| Conversión/casteo de tipos | `static_cast<int>(jugador.size())` para comparación segura signed/unsigned |
| Estructuras condicionales | `if/else` para nivel y acceso; `switch` para rango |
| Ciclos | `switch` con fallthrough como trampa; lógica iterativa implícita |
| Constantes | `const int PUNTAJE_BASE = 100` |
| Diferentes tipos de datos | `string`, `unsigned int`, `int`, `double` |

### Los 5 errores intencionales

| # | Línea | Tipo de error | Descripción | Corrección |
|---|---|---|---|---|
| 1 | ~20 | **Quirk: `unsigned int` underflow** | `unsigned int vidas = 3; vidas -= penalizacion;` Si `penalizacion > 3`, el resultado en unsigned no puede ser negativo y hace *wrapping*: pasa a ~4,294,967,293 en lugar de un número negativo. | Cambiar `unsigned int` a `int` |
| 2 | ~28-32 | **Quirk sintáctico: Dangling `else`** | La indentación sugiere que el `else` pertenece al `if (vidas > 0)`, pero C++ siempre asocia el `else` al `if` más cercano (`if (puntos > 50)`). Si `vidas == 0`, no se imprime nada. El compilador incluso emite `-Wdangling-else`. | Encerrar el cuerpo del `if (vidas > 0)` con `{ }` |
| 3 | ~36-45 | **Quirk: Switch fallthrough** | Falta `break` en `case 1`. Si `rango == 1`, el programa imprime `"Rango: Plata"` y cae directamente al `case 0` imprimiendo también `"Rango: Bronce"`. Esto es comportamiento definido en C++, no un error de compilación. | Agregar `break;` al final de `case 1` |
| 4 | ~48-56 | **Quirk: Variable shadowing** | Dentro del bloque `{ }` se declara `int bonus = 5;` que **oculta** la variable exterior `double bonus = 20.0`. Las operaciones dentro del bloque modifican la copia interior; la exterior nunca cambia. | Eliminar la redeclaración; operar directamente sobre `bonus` exterior |
| 5 | ~59-65 | **Quirk: Comparación signed/unsigned** | `jugador.size()` retorna `size_t` (tipo unsigned). Al comparar con `intentos` (que es `-1`), C++ convierte el `-1` a `size_t`: se vuelve ~18 quintillones. La condición `(enorme > tamaño_real)` resulta `false`, bloqueando el acceso aunque `-1 < 6` parece obvio. | Castear `jugador.size()` a `int`: `static_cast<int>(jugador.size())` |

### Diff mi_programa.cpp → mi_programa_corregido.cpp

```diff
-    unsigned int vidas = 3;
+    int vidas = 3;

-    if (vidas > 0)
-        if (puntos > 50)
-            cout << jugador << " avanza al siguiente nivel." << endl;
-        else
-            cout << "Puntos insuficientes." << endl;
+    if (vidas > 0) {
+        if (puntos > 50)
+            cout << jugador << " avanza al siguiente nivel." << endl;
+        else
+            cout << "Puntos insuficientes." << endl;
+    }

         case 1:
             cout << "Rango: Plata" << endl;
+            break;   // break agregado

-        int bonus = 5;
-        bonus += 10;
+        bonus += 10;   // opera sobre la variable exterior directamente

-    if (intentos < jugador.size()) {
+    if (intentos < static_cast<int>(jugador.size())) {
```

---

## Resumen de archivos modificados/creados

| Archivo | Acción | Errores corregidos |
|---|---|---|
| `src/errores1.cpp` | Modificado | 4 errores (include, 2 semicolons, división entera) |
| `src/errores2.cpp` | Modificado | 2 errores (braces en case, semicolon) |
| `src/errores3.cpp` | Modificado | 2 errores (const sin inicializar, fuera de rango en loop) |
| `src/programa1.cpp` | Modificado | 1 error de lógica (división entera) |
| `src/programa2.cpp` | Modificado | 1 error de lógica (paso por valor en vez de referencia) |
| `src/mi_programa.cpp` | Creado | Programa original con 5 errores intencionales |
| `src/mi_programa_corregido.cpp` | Creado | Versión corregida del programa original |
