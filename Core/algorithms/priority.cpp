#pragma once
#include <vector>
#include <algorithm>
#include "../process.cpp"

void ejecutarPrioridad(std::vector<Proceso>& procesos) {
    int tamProcesos = procesos.size();
    int tActual = 0;
    int completados = 0;
    
    std::vector<bool> terminado(tamProcesos, false);

    while (completados < tamProcesos) {
        int pPrioritario = -1;
        // la explicacion del 999999999 esta en sjf :)
        int prioridadMasAlta = 999999999;

        for (int i = 0; i < tamProcesos; i++) {
            if (procesos[i].tiempoLlegada <= tActual && !terminado[i]) {
                if (procesos[i].prioirdad < prioridadMasAlta) {
                    prioridadMasAlta = procesos[i].prioirdad;
                    pPrioritario = i;
                }
                else if (procesos[i].prioirdad == prioridadMasAlta) {
                    if (pPrioritario == -1 || procesos[i].tiempoLlegada < procesos[pPrioritario].tiempoLlegada) {
                        pPrioritario = i;
                    }
                }
            }
        }
        if (pPrioritario != -1) {
            Proceso& p = procesos[pPrioritario];
            p.tiempoInicio = tActual;
            p.tiempoRespuesta = p.tiempoInicio - p.tiempoLlegada;
            tActual += p.tiempoRafaga;
            p.tiempoFinalizacion = tActual;
            p.tiempoRetorno = p.tiempoFinalizacion - p.tiempoLlegada;
            p.tiempoEspera = p.tiempoRetorno - p.tiempoRafaga;
            p.estadoActual = Estado::TERMINADO;
            terminado[pPrioritario] = true;
            completados++;
        } else {
            tActual++;
        }
    }
}