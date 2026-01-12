#pragma once
#include <string>

//estados para los procesos:
enum class Estado { NUEVO, LISTO, EJECUTANDO, TERMINADO };

struct Proceso {
    //datos de entrada:
    std::string id;     
    int tiempoLlegada;    
    int tiempoRafaga;
    //esto solo lo implementa el algoritmo de  de prioirdad:       
    int prioirdad;
    //y esto solo para el round robin        
    int tiempoRestante;   

    //datos de salida (metricas):
    int tiempoInicio;
    int tiempoFinalizacion;
    int tiempoEspera;
    int tiempoRetorno;
    int tiempoRespuesta;
    Estado estadoActual;

    Proceso(std::string e_id, int e_nec, int e_ej, int e_prio = 0) {
        id = e_id;
        tiempoLlegada = e_nec;
        tiempoRafaga = e_ej;
        prioirdad = e_prio;
        //al inicio lo que resta es igual al total
        tiempoRestante = e_ej; 
        
        tiempoInicio = -1; 
        tiempoFinalizacion = 0;
        tiempoEspera = 0;
        tiempoRetorno = 0;
        tiempoRespuesta = 0;
        estadoActual = Estado::NUEVO;
    }
};