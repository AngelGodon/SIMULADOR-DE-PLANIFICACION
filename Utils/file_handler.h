#pragma once
#include <vector>
#include <string>
#include "../Core/process.cpp"

/**
 * Lee un archivo CSV con procesos y retorna un vector de Proceso
 * Formato esperado: ID,TiempoLlegada,TiempoRafaga,Prioridad
 * @param nombreArchivo Ruta del archivo CSV a leer
 * @return Vector con los procesos leídos
 * @throws std::runtime_error si el archivo no existe o el formato es incorrecto
 */
std::vector<Proceso> leerProcesosDesdeArchivo(const std::string& nombreArchivo);
