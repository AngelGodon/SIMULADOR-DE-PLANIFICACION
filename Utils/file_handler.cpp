#include "file_handler.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

std::vector<Proceso> leerProcesosDesdeArchivo(const std::string& nombreArchivo) {
    std::vector<Proceso> procesos;
    std::ifstream archivo(nombreArchivo);
    
    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "ERROR: No se pudo abrir el archivo '" << nombreArchivo << "'" << std::endl;
        throw std::runtime_error("No se pudo abrir el archivo");
    }
    
    std::string linea;
    int numeroLinea = 0;
    
    try {
        // Leer el archivo línea por línea
        while (std::getline(archivo, linea)) {
            numeroLinea++;
            
            // Saltar líneas vacías
            if (linea.empty() || linea.find_first_not_of(" \t\r\n") == std::string::npos) {
                continue;
            }
            
            // Parsear la línea usando stringstream
            std::stringstream ss(linea);
            std::string id;
            std::string temp;
            int tiempoLlegada, tiempoRafaga, prioridad;
            
            // Leer ID (hasta la primera coma)
            if (!std::getline(ss, id, ',')) {
                std::cerr << "ERROR: Formato incorrecto en línea " << numeroLinea 
                         << " - No se pudo leer el ID" << std::endl;
                throw std::runtime_error("Formato de archivo incorrecto");
            }
            
            // Leer Tiempo de Llegada
            if (!std::getline(ss, temp, ',')) {
                std::cerr << "ERROR: Formato incorrecto en línea " << numeroLinea 
                         << " - No se pudo leer el tiempo de llegada" << std::endl;
                throw std::runtime_error("Formato de archivo incorrecto");
            }
            tiempoLlegada = std::stoi(temp);
            
            // Leer Tiempo de Ráfaga
            if (!std::getline(ss, temp, ',')) {
                std::cerr << "ERROR: Formato incorrecto en línea " << numeroLinea 
                         << " - No se pudo leer el tiempo de ráfaga" << std::endl;
                throw std::runtime_error("Formato de archivo incorrecto");
            }
            tiempoRafaga = std::stoi(temp);
            
            // Leer Prioridad
            if (!std::getline(ss, temp)) {
                std::cerr << "ERROR: Formato incorrecto en línea " << numeroLinea 
                         << " - No se pudo leer la prioridad" << std::endl;
                throw std::runtime_error("Formato de archivo incorrecto");
            }
            prioridad = std::stoi(temp);
            
            // Validar que los valores sean positivos
            if (tiempoLlegada < 0 || tiempoRafaga <= 0) {
                std::cerr << "ERROR: Valores inválidos en línea " << numeroLinea 
                         << " - Los tiempos deben ser positivos (ráfaga > 0)" << std::endl;
                throw std::runtime_error("Valores de proceso inválidos");
            }
            
            // Crear y agregar el proceso al vector
            procesos.push_back(Proceso(id, tiempoLlegada, tiempoRafaga, prioridad));
            
        }
        
        archivo.close();
        
        // Verificar que se leyó al menos un proceso
        if (procesos.empty()) {
            std::cerr << "ERROR: El archivo no contiene procesos válidos" << std::endl;
            throw std::runtime_error("Archivo vacío o sin datos válidos");
        }
        
        std::cout << "Se cargaron exitosamente " << procesos.size() << " procesos desde el archivo." << std::endl;
        
    } catch (const std::invalid_argument& e) {
        std::cerr << "ERROR: Conversión de datos inválida en línea " << numeroLinea 
                 << " - Verifica que los valores numéricos sean correctos" << std::endl;
        archivo.close();
        throw std::runtime_error("Error al convertir datos numéricos");
    } catch (const std::out_of_range& e) {
        std::cerr << "ERROR: Valor numérico fuera de rango en línea " << numeroLinea << std::endl;
        archivo.close();
        throw std::runtime_error("Valor numérico fuera de rango");
    }
    
    return procesos;
}
