#pragma once
#include <vector>
#include <iostream>
#include "process.cpp"

struct ResultadosFinales {
    double promedioEspera;
    double promedioRetorno;
    double promedioRespuesta;
    double utilizacionCPU;
    double rendimiento;
};

ResultadosFinales calcularMetricasGlobales(std::vector<Proceso>& procesos, int tiempoTotal) {
    double totEsp = 0;
    double totRet = 0;
    double totResp = 0;
    double totEj = 0;

    for (const auto& p : procesos) {
        totEsp += p.tiempoEspera;
        totRet += p.tiempoRetorno;
        totResp += p.tiempoRespuesta;
        totEj += p.tiempoRafaga;
    }

    int cantProcesos = procesos.size();
    ResultadosFinales resultados;
    resultados.promedioEspera = totEsp / cantProcesos;
    resultados.promedioRetorno = totRet / cantProcesos;
    resultados.promedioRespuesta = totResp / cantProcesos;

    if (tiempoTotal > 0) {
        resultados.utilizacionCPU = (totEj / tiempoTotal) * 100;
        resultados.rendimiento = (double)cantProcesos / tiempoTotal;
    } else {
        resultados.utilizacionCPU = 0;
        resultados.rendimiento = 0;
    }

    return resultados;
}