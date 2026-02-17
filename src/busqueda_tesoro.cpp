#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 9 misiones -> 9 dígitos
int codigo[9] = {0};
bool completadas[9] = {false};
int completadasTotal = 0;

void normalizar(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

bool contiene(const string& s, const string& sub) {
    return s.find(sub) != string::npos;
}

void imprimirCodigoSiGana() {
    if (completadasTotal == 9) {
        cout << "\n🏆 ¡TESORO ENCONTRADO!\n";
        cout << "🔐 Código final: ";
        for (int i = 0; i < 9; i++) cout << codigo[i];
        cout << "\n✅ Completaste las 9 misiones.\n";
    }
}

void marcarMision(int idx, int digito) {
    if (!completadas[idx]) {
        completadas[idx] = true;
        codigo[idx] = digito;
        completadasTotal++;
    }
    cout << "🎉 Misión superada. Dígito desbloqueado: " << digito << "\n";
    imprimirCodigoSiGana();
}

/* -------------------- MISIONES (6 preguntas cada una) -------------------- */
/* Nota: Se mantiene la esencia de las preguntas, pero se cambió el wording. */

void misionCapitulo3() {
    cout << "\n🧩 Misión Capítulo 3: Compiladores y toolchain\n";
    int puntos = 0; 
    string entrada;

    // 1) Texto
    cout << "1) ¿Qué extensión suele usarse para un archivo fuente de C++? (ej: .docx): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == ".cpp" || entrada == ".cc" || entrada == ".cxx") puntos++;

    // 2) Texto
    cout << "2) En consola, ¿qué comando de GCC compila normalmente C++? ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "g++") puntos++;

    // 3) Código
    cout << "3) Escribe UNA línea que imprima: Hola mundo\n> ";
    cin.ignore();
    getline(cin, entrada);
    if (contiene(entrada, "cout") && (contiene(entrada, "hola") || contiene(entrada, "Hola"))) puntos++;

    // 4) Código
    cout << "4) Escribe el comando (solo el texto) para compilar archivo.cpp a ejecutable 'prog' usando C++17:\n> ";
    getline(cin, entrada);
    normalizar(entrada);
    if (contiene(entrada, "g++") && contiene(entrada, "-std=c++17") && contiene(entrada, "archivo.cpp")) puntos++;

    // 5) Texto
    cout << "5) ¿La compilación ocurre ANTES de ejecutar el programa? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    // 6) Texto
    cout << "6) GCC/MinGW es principalmente: (compilador/ide): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "compilador") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(0, 9);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo4() {
    cout << "\n🧩 Misión Capítulo 4: Tu primer programa\n";
    int puntos = 0; 
    string entrada;

    cout << "1) ¿Cómo se llama la función donde inicia un programa C++?: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "main" || entrada == "main()") puntos++;

    cout << "2) Header típico para usar cout: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "<iostream>") puntos++;

    cout << "3) Escribe UNA línea válida que imprima \"UVG\" en consola:\n> ";
    cin.ignore();
    getline(cin, entrada);
    if (contiene(entrada, "cout") && (contiene(entrada, "UVG") || contiene(entrada, "uvg"))) puntos++;

    cout << "4) En C++, ¿cada sentencia normalmente termina con ';'? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "5) ¿Qué símbolo usas con cout para enviar datos a la salida? (escríbelo): ";
    cin >> entrada;
    if (entrada == "<<") puntos++;

    cout << "6) ¿Qué inicia un comentario de una sola línea?: ";
    cin >> entrada;
    if (entrada == "//") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(1, 4);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo5() {
    cout << "\n🧩 Misión Capítulo 5: Tipos de datos y variables\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Tipo entero más común en ejemplos: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "int") puntos++;

    cout << "2) Un tipo de punto flotante (decimal): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "float" || entrada == "double") puntos++;

    cout << "3) Escribe una declaración que cree un entero x con valor 5 usando llaves {}:\n> ";
    cin.ignore();
    getline(cin, entrada);
    if (contiene(entrada, "int") && contiene(entrada, "x") && contiene(entrada, "{5}")) puntos++;

    cout << "4) Tipo que almacena un solo carácter: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "char") puntos++;

    cout << "5) ¿bool representa true/false? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "6) sizeof suele devolver el tamaño en: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "bytes") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(2, 1);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo6() {
    cout << "\n🧩 Misión Capítulo 6: Exercises (práctica básica)\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Bucle que repite mientras una condición sea verdadera: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "while") puntos++;

    cout << "2) ¿for se usa cuando quieres repetir N veces? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "3) Escribe una línea que declare una variable llamada nombre de tipo string:\n> ";
    cin.ignore();
    getline(cin, entrada);
    normalizar(entrada);
    if (contiene(entrada, "string") && contiene(entrada, "nombre")) puntos++;

    cout << "4) ¿En C++ los arreglos se indexan desde 0? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "5) Operador de asignación (el de 'darle' un valor a una variable): ";
    cin >> entrada;
    if (entrada == "=") puntos++;

    cout << "6) endl imprime salto de línea y vacía el buffer? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(3, 6);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo7() {
    cout << "\n🧩 Misión Capítulo 7: Strings\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Tipo estándar para cadenas de texto en C++: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "string") puntos++;

    cout << "2) Header que normalmente se incluye para usar string (según ejemplos): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "<string>") puntos++;

    cout << "3) Operador típico para concatenar strings: ";
    cin >> entrada;
    if (entrada == "+") puntos++;

    cout << "4) ¿Qué método te da el tamaño de un string? (length/size): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "length" || entrada == "size") puntos++;

    cout << "5) Para leer una línea con espacios, se recomienda: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "getline" || entrada == "std::getline") puntos++;

    cout << "6) ¿Un string puede contener espacios? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(4, 7);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo8() {
    cout << "\n🧩 Misión Capítulo 8: Loops y arrays\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Loop común cuando tienes un contador (i=0; i<n; i++): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "for") puntos++;

    cout << "2) ¿Un array puede guardar varios valores del mismo tipo? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "3) Escribe una declaración para un array de 5 enteros llamado a:\n> ";
    cin.ignore();
    getline(cin, entrada);
    normalizar(entrada);
    if (contiene(entrada, "int") && contiene(entrada, "a") && contiene(entrada, "[5]")) puntos++;

    cout << "4) En un array de tamaño 5, el último índice es: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "4") puntos++;

    cout << "5) break termina el loop actual? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "6) continue salta al siguiente ciclo? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(5, 8);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo16() {
    cout << "\n🧩 Misión Capítulo 16: Statements y control\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Palabra clave para una condición: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "if") puntos++;

    cout << "2) Rama alternativa cuando el if no se cumple: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "else") puntos++;

    cout << "3) Operador para comparar igualdad: ";
    cin >> entrada;
    if (entrada == "==") puntos++;

    cout << "4) Operador lógico AND (ambas condiciones verdaderas): ";
    cin >> entrada;
    if (entrada == "&&") puntos++;

    cout << "5) En switch, el caso por defecto se escribe como: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "default") puntos++;

    cout << "6) ¿Puedes anidar if dentro de otro if? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(6, 3);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo17() {
    cout << "\n🧩 Misión Capítulo 17: Const y constexpr\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Palabra clave para declarar una variable constante: ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "const") puntos++;

    cout << "2) constexpr sugiere evaluación en compilación? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "3) Escribe una línea válida: const int x = 5;\n> ";
    cin.ignore();
    getline(cin, entrada);
    normalizar(entrada);
    if (contiene(entrada, "const") && contiene(entrada, "int") && contiene(entrada, "x") && contiene(entrada, "5")) puntos++;

    cout << "4) ¿Se puede reasignar una variable const? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "no") puntos++;

    cout << "5) ¿constexpr puede usarse para constantes 'de verdad' conocidas en compile-time? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "6) ¿const ayuda a evitar cambios accidentales? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(7, 2);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

void misionCapitulo18() {
    cout << "\n🧩 Misión Capítulo 18: Exercises (condicionales)\n";
    int puntos = 0; 
    string entrada;

    cout << "1) Operador 'mayor que' en C++: ";
    cin >> entrada;
    if (entrada == ">") puntos++;

    cout << "2) Operador lógico OR (una u otra condición): ";
    cin >> entrada;
    if (entrada == "||") puntos++;

    cout << "3) ¿'else if' es una construcción válida en C++? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "4) Escribe una condición que evalúe si n es par usando el operador % (solo la expresión):\n> ";
    cin.ignore();
    getline(cin, entrada);
    // aceptamos varias formas
    if (contiene(entrada, "%") && (contiene(entrada, "== 0") || contiene(entrada, "==0"))) puntos++;

    cout << "5) ¿return termina la función actual? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "6) ¿Puedes usar if anidados para decisiones múltiples? (si/no): ";
    cin >> entrada; normalizar(entrada);
    if (entrada == "si" || entrada == "sí") puntos++;

    cout << "Puntaje: " << puntos << "/6\n";
    if (puntos >= 5) marcarMision(8, 5);
    else cout << "❌ No se completó la misión. Inténtalo de nuevo.\n";
}

/* -------------------- MAIN / MENU -------------------- */

void mostrarMenu() {
    cout << "\n==============================\n";
    cout << "🗺️  BÚSQUEDA DEL TESORO (9 misiones)\n";
    cout << "==============================\n";
    cout << "Elige el capítulo/misión:\n";
    cout << " 3  -> Misión Cap. 3\n";
    cout << " 4  -> Misión Cap. 4\n";
    cout << " 5  -> Misión Cap. 5\n";
    cout << " 6  -> Misión Cap. 6\n";
    cout << " 7  -> Misión Cap. 7\n";
    cout << " 8  -> Misión Cap. 8\n";
    cout << " 16 -> Misión Cap. 16\n";
    cout << " 17 -> Misión Cap. 17\n";
    cout << " 18 -> Misión Cap. 18\n";
    cout << " 0  -> Salir\n";
    cout << "Opción: ";
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 3:  misionCapitulo3();  break;
            case 4:  misionCapitulo4();  break;
            case 5:  misionCapitulo5();  break;
            case 6:  misionCapitulo6();  break;
            case 7:  misionCapitulo7();  break;
            case 8:  misionCapitulo8();  break;
            case 16: misionCapitulo16(); break;
            case 17: misionCapitulo17(); break;
            case 18: misionCapitulo18(); break;
            case 0:  cout << "👋 Saliendo del programa.\n"; break;
            default: cout << "⚠️  Opción inválida. Intenta de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
