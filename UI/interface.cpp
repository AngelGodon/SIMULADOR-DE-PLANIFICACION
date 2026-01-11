#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
#include <cstdlib>

#include "../Core/metrics.cpp"
#include "../Core/algorithms/fcfs.cpp"
#include "../Core/algorithms/sjf.cpp"
#include "../Core/algorithms/round_robin.cpp"
#include "../Core/algorithms/priority.cpp"
#include "../Utils/file_handler.cpp"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void imprimirTabla(const vector<Proceso>& procesos) {
    cout << "\n" << string(85, '-') << endl;
    cout << "| ID | Llegada | Ejecucion | Prioridad | Inicio | Fin | Espera | Retorno | Espera |" << endl;
    cout << string(85, '-') << endl;
    
    for (const auto& p : procesos) {
        cout << "| " << left << setw(2) << p.id << " | " 
             << right << setw(7) << p.tiempoLlegada << " | " 
             << setw(9) << p.tiempoRafaga << " | "
             << setw(9) << p.prioirdad << " | "
             << setw(6) << p.tiempoInicio << " | " 
             << setw(3) << p.tiempoFinalizacion << " | "
             << setw(6) << p.tiempoEspera << " | " 
             << setw(7) << p.tiempoRetorno << " | "
             << setw(5) << p.tiempoRespuesta << " |" << endl;
    }
    cout << string(85, '-') << endl;
}

int main() {
    int n, opcion, q, tipo;
    vector<Proceso> procesos;
    while (true) { // bucle principal del programa
        cout << "SIMULADOR DE PLANIFICACION" << endl;
        procesos.clear();
        // Bucle de carga de datos: permite volver al inicio si falla la lectura de archivo
        bool datosCargados = false;
        while (!datosCargados) {
        // Validar tipo de entrada: solo 1 o 2
        while (true) {
            cout << "\nCual va a ser la entrada de datos:\n1. Manual\n2. Archivo\nOpcion: ";
            if (!(cin >> tipo)) {
                cout << "\nEntrada invalida. Ingresa 1 (Manual) o 2 (Archivo)." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (tipo == 1 || tipo == 2) break;
            cout << "\nEntrada invalida. Ingresa 1 (Manual) o 2 (Archivo)." << endl;
        }
    
    if(tipo == 1){
        clearScreen();
        // Validar cantidad de procesos: entero > 0
        while (true) {
            cout << "Cuantos procesos vas a registrar?: ";
            if (!(cin >> n)) {
                cout << "\nEntrada invalida. Ingresa un numero entero mayor a 0." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (n > 0) break;
            cout << "\nEntrada invalida. Ingresa un numero entero mayor a 0." << endl;
        }

        for (int i = 0; i < n; i++) {
            string id;
            int lleg, ejec, prio;
            cout << "\n--- Proceso " << i + 1 << " ---" << endl;
            // Nombre/ID: permitir espacios y no vacio
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar salto previo antes de getline
            while (true) {
                cout << "Nombre/ID: ";
                getline(cin, id);
                // Validar que no sea vacio o solo espacios
                if (id.find_first_not_of(" \t") != string::npos) break;
                cout << "\nEntrada invalida. El Nombre/ID no puede estar vacio." << endl;
            }
            // Tiempo de Llegada: entero >= 0
            while (true) {
                cout << "Tiempo de Llegada: ";
                if (!(cin >> lleg)) {
                    cout << "\nEntrada invalida. Ingresa un numero entero mayor o igual a 0." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (lleg >= 0) break;
                cout << "\nEntrada invalida. Ingresa un numero entero mayor o igual a 0." << endl;
            }
            // Tiempo de Rafaga: entero > 0
            while (true) {
                cout << "Tiempo de Rafaga: ";
                if (!(cin >> ejec)) {
                    cout << "\nEntrada invalida. Ingresa un numero entero mayor a 0." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (ejec > 0) break;
                cout << "\nEntrada invalida. Ingresa un numero entero mayor a 0." << endl;
            }
            // Prioridad: entero >= 0
            while (true) {
                cout << "Prioridad: ";
                if (!(cin >> prio)) {
                    cout << "\nEntrada invalida. Ingresa un numero entero mayor o igual a 0." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                if (prio >= 0) break;
                cout << "\nEntrada invalida. Ingresa un numero entero mayor o igual a 0." << endl;
            }
            
            procesos.push_back(Proceso(id, lleg, ejec, prio));
        }
        clearScreen();
        datosCargados = true; // datos manuales cargados
    } else if(tipo == 2) {
        // Lectura desde archivo CSV
        clearScreen();
        string nombreArchivo;
        cout << "Ingresa el nombre del archivo (ej: procesos_prueba.csv): ";
        cin >> nombreArchivo;
        
        try {
            procesos = leerProcesosDesdeArchivo(nombreArchivo);
            cout << "\nArchivo '" << nombreArchivo << "' leido correctamente. Continua con la seleccion de algoritmo." << endl;
            datosCargados = true; // datos desde archivo cargados correctamente
        } catch (const exception& e) {
            cerr << "\nNo se pudieron cargar los procesos desde archivo. Verifica el nombre y el formato. Volviendo al menu inicial..." << endl;
            // Limpiar flujo por si quedan caracteres, y continuar el bucle para reintentar desde el inicio
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
        }
        
        // Validar seleccion de algoritmo: solo 1 a 4
        while (true) {
            cout << "\nSelecciona el Algoritmo:\n1. FCFS\n2. SJF\n3. Round Robin\n4. Prioridad\nOpcion: ";
            if (!(cin >> opcion)) {
                cout << "\nEntrada invalida. Ingresa un numero del 1 al 4." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (opcion >= 1 && opcion <= 4) break;
            cout << "\nEntrada invalida. Ingresa un numero del 1 al 4." << endl;
        }
    clearScreen();

    if (opcion == 1) {
        ejecutarFCFS(procesos);
    }else if (opcion == 2) {
        ejecutarSJF(procesos);
    }else if (opcion == 3) {
        // Validar quantum: entero > 0
        while (true) {
            cout << "Quantum: ";
            if (!(cin >> q)) {
                cout << "\nEntrada invalida. Ingresa un numero entero mayor a 0 para el quantum." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (q > 0) break;
            cout << "\nEntrada invalida. Ingresa un numero entero mayor a 0 para el quantum." << endl;
        }
        clearScreen();
        ejecutarRoundRobin(procesos, q);
    }else if (opcion == 4) {
        ejecutarPrioridad(procesos);
    }

    int tMax = 0;
    for(const auto& p : procesos) if(p.tiempoFinalizacion > tMax) tMax = p.tiempoFinalizacion;

    imprimirTabla(procesos);
    
    ResultadosFinales rf = calcularMetricasGlobales(procesos, tMax);
    
        cout << "\nRESUMEN DE RENDIMIENTO:" << endl;
        cout << "> Espera Promedio:    " << rf.promedioEspera << endl;
        cout << "> Retorno Promedio:   " << rf.promedioRetorno << endl;
        cout << "> Respuesta Promedio: " << rf.promedioRespuesta << endl;
        cout << "> Utilizacion CPU:    " << rf.utilizacionCPU << "%" << endl;

        // Pausa y opcion para salir o volver al inicio
        cout << "\nPresiona Enter para volver al inicio, o escribe 'salir' para terminar: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string accion;
        getline(cin, accion);
        if (accion == "salir" || accion == "SALIR") {
            break; // salir del bucle principal
        }
        // cualquier otro caso (incluyendo Enter vacio) continua al inicio
        cout << string(85, '-') << "\n"; // separador visual
    }
    return 0;
}