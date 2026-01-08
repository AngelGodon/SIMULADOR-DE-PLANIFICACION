#pragma once
#include <vector>
//encontre esta libreria que es super util para la cola
#include <queue>
#include <algorithm>
#include "../process.cpp"

void ejecutarRoundRobin(std::vector<Proceso>& procesos, int quantum) {
    int tamProcesos = procesos.size();
    int tActual = 0;
    int completados = 0;
    
    //una cola para saber a qn le toca
    std::queue<int> cola;
    //para no repetir dos veces a un proceso en la cola
    std::vector<bool> yaEnLaCola(tamProcesos, false);

    //hayyy que ordenarlo para saber cual va a ser ell primero en la cola
    //TODO: esta funcion tambien se usa en fcfs, se podria cambiar a process por ejemplo asi las dos pueden usarlo sin repetir codigo
    std::sort(procesos.begin(), procesos.end(), [](const Proceso& a, const Proceso& b) {
        return a.tiempoLlegada < b.tiempoLlegada;
    });

    cola.push(0);
    yaEnLaCola[0] = true;
    tActual = procesos[0].tiempoLlegada;

    while (completados < tamProcesos) {
        if (cola.empty()) {
            //si kla cola esta vacia pero aun faltan procesos que avanze el reloj igualito
            for(int i = 0; i < tamProcesos; i++) {
                if(!yaEnLaCola[i]) {
                    tActual = procesos[i].tiempoLlegada;
                    cola.push(i);
                    yaEnLaCola[i] = true;
                    break;
                }
            }
        }

        int i = cola.front();
        cola.pop();
        Proceso& p = procesos[i];
        if (p.tiempoInicio == -1) {
            p.tiempoInicio = tActual;
            p.tiempoRespuesta = p.tiempoInicio - p.tiempoLlegada;
        }

        int tQSeVaAEjecutar = std::min(p.tiempoRestante, quantum);
        tActual += tQSeVaAEjecutar;
        p.tiempoRestante -= tQSeVaAEjecutar;
        for (int j = 0; j < tamProcesos; j++) {
            if (!yaEnLaCola[j] && procesos[j].tiempoLlegada <= tActual) {
                cola.push(j);
                yaEnLaCola[j] = true;
            }
        }

        if (p.tiempoRestante > 0) {
            cola.push(i);
        } else {
            p.tiempoFinalizacion = tActual;
            p.tiempoRetorno = p.tiempoFinalizacion - p.tiempoLlegada;
            p.tiempoEspera = p.tiempoRetorno - p.tiempoRafaga;
            p.estadoActual = Estado::TERMINADO;
            completados++;
        }
    }
}