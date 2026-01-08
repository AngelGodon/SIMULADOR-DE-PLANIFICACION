#pragma once
#include <vector>
#include <algorithm> 
#include "../process.cpp"

void ejecutarFCFS(std::vector<Proceso>& procesos) {
    
    //ordeno los procesos por tiempo de llegada, esto es por si no vienen ya en ese orden
    //como los procesos se guardan en un vector solo uso esta funcion de aca (el sort):
    std::sort(procesos.begin(), procesos.end(), [](const Proceso& a, const Proceso& b) {
        return a.tiempoLlegada < b.tiempoLlegada;
    });





    int tiempoActual = 0;

    for (int i = 0; i < procesos.size(); i++) {
        //comprobamos si no esta ocioso
        if (tiempoActual < procesos[i].tiempoLlegada) {
            tiempoActual = procesos[i].tiempoLlegada;
        }
        procesos[i].tiempoInicio = tiempoActual;
        procesos[i].tiempoRespuesta = procesos[i].tiempoInicio - procesos[i].tiempoLlegada;
        tiempoActual += procesos[i].tiempoRafaga;
        procesos[i].tiempoFinalizacion = tiempoActual;
        procesos[i].tiempoRetorno = procesos[i].tiempoFinalizacion - procesos[i].tiempoLlegada;
        procesos[i].tiempoEspera = procesos[i].tiempoRetorno - procesos[i].tiempoRafaga;
        procesos[i].estadoActual = Estado::TERMINADO;
    }
}