#pragma once
#include <vector>
#include <algorithm>
#include "../process.cpp"

void ejecutarSJF(std::vector<Proceso>& procesos) {
    int tamProcesos = procesos.size();
    int tActual = 0;
    int completados = 0;
    
    //vector para saber qn ya temrinaron ya
    std::vector<bool> terminado(tamProcesos, false);

    while (completados < tamProcesos) {
        int mejorProceso = -1;
        //no se me otra forma para saber el minimo inicial asi que solo puse un numero muy grande y ya
        int minEjecucion = 999999999; 

        for (int i = 0; i < tamProcesos; i++) {
            // Requisitos: 
            // 1. Que haya llegado al sistema
            // 2. Que no se haya ejecutado todavía
            if (procesos[i].tiempoLlegada <= tActual && !terminado[i]) {
                
                // Si este proceso es más corto que el que habíamos visto antes...
                if (procesos[i].tiempoRafaga < minEjecucion) {
                    minEjecucion = procesos[i].tiempoRafaga;
                    mejorProceso = i;
                }
            }
        }

        if (mejorProceso != -1) {
            Proceso& p = procesos[mejorProceso];
            p.tiempoInicio = tActual;
            p.tiempoRespuesta = p.tiempoInicio - p.tiempoLlegada;
            tActual += p.tiempoRafaga;
            p.tiempoFinalizacion = tActual;
            p.tiempoRetorno = p.tiempoFinalizacion - p.tiempoLlegada;
            p.tiempoEspera = p.tiempoRetorno - p.tiempoRafaga;
            p.estadoActual = Estado::TERMINADO;
            terminado[mejorProceso] = true;
            completados++;
        } else {
            //si nadie a llegado el "reloj" igualito avanza
            tActual++;
        }
    }
}