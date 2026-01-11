#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "../Core/metrics.cpp"
#include "../Core/algorithms/fcfs.cpp"
#include "../Core/algorithms/sjf.cpp"
#include "../Core/algorithms/round_robin.cpp"
#include "../Core/algorithms/priority.cpp"
#include "../Utils/file_handler.cpp"

using namespace std;

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
    cout << "SIMULADOR DE PLANIFICACION" << endl;
    cout << "\nCual va a ser la entrada de datos:\n1. Manual\n2. Archivo\nOpcion: ";
    cin >> tipo;
    
    if(tipo == 1){
        cout << "Cuantos procesos vas a registrar?: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
            string id;
            int lleg, ejec, prio;
            cout << "\n--- Proceso " << i + 1 << " ---" << endl;
            cout << "Nombre/ID: "; cin >> id;
            cout << "Tiempo de Llegada: "; cin >> lleg;
            cout << "Tiempo de Rafaga: "; cin >> ejec;
            cout << "Prioridad: "; cin >> prio;
            
            procesos.push_back(Proceso(id, lleg, ejec, prio));
        }
    } else if(tipo == 2) {
        // Lectura desde archivo CSV
        string nombreArchivo;
        cout << "Ingresa el nombre del archivo (ej: procesos_prueba.csv): ";
        cin >> nombreArchivo;
        
        try {
            procesos = leerProcesosDesdeArchivo(nombreArchivo);
        } catch (const exception& e) {
            cerr << "\nNo se pudieron cargar los procesos." << endl;
            return 1;
        }
    }
    

    cout << "\nSelecciona el Algoritmo:\n1. FCFS\n2. SJF\n3. Round Robin\n4. Prioridad\nOpcion: ";
    cin >> opcion;

    if (opcion == 1) {
        ejecutarFCFS(procesos);
    }else if (opcion == 2) {
        ejecutarSJF(procesos);
    }else if (opcion == 3) {
        cout << "Quantum: "; cin >> q;
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

    return 0;
}