#include <iostream>
#include <string>
#include <vector>
#include "../Utils/file_handler.h"

using namespace std;

// Colores ANSI para la consola
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[36m"
#define COLOR_RESET "\033[0m"

struct TestCase {
    string nombre;
    string archivo;
    bool deberiaFallar;
    string descripcion;
};

void imprimirEncabezado() {
    cout << "\n";
    cout << "========================================\n";
    cout << "  TEST SUITE - FILE HANDLER MODULE\n";
    cout << "========================================\n";
    cout << "\n";
}

void imprimirResultado(int testNum, const string& nombre, bool paso, const string& mensaje = "") {
    string status = paso ? COLOR_GREEN "PASÓ" COLOR_RESET : COLOR_RED "FALLÓ" COLOR_RESET;
    cout << "[TEST " << testNum << "] " << nombre << " -> " << status;
    if (!mensaje.empty()) {
        cout << " (" << mensaje << ")";
    }
    cout << endl;
}

void ejecutarTest(int testNum, const TestCase& test, int& pasados, int& fallados) {
    cout << COLOR_BLUE << "\n--- Ejecutando: " << test.descripcion << COLOR_RESET << endl;
    
    try {
        vector<Proceso> procesos = leerProcesosDesdeArchivo(test.archivo);
        
        if (test.deberiaFallar) {
            // Este test DEBERÍA haber fallado pero NO lo hizo
            imprimirResultado(testNum, test.nombre, false, 
                "Se esperaba una excepción pero se cargaron " + to_string(procesos.size()) + " procesos");
            fallados++;
        } else {
            // El archivo se cargó correctamente como se esperaba
            imprimirResultado(testNum, test.nombre, true, 
                to_string(procesos.size()) + " procesos cargados");
            pasados++;
        }
        
    } catch (const exception& e) {
        if (test.deberiaFallar) {
            // Este test DEBERÍA fallar y SÍ falló correctamente
            imprimirResultado(testNum, test.nombre, true, 
                "Excepción capturada correctamente");
            pasados++;
        } else {
            // El archivo DEBERÍA haber cargado pero falló
            imprimirResultado(testNum, test.nombre, false, 
                string("Excepción inesperada: ") + e.what());
            fallados++;
        }
    }
}

int main() {
    imprimirEncabezado();
    
    // Definir todos los casos de prueba
    vector<TestCase> tests = {
        // Tests que DEBEN PASAR (archivos válidos)
        {
            "test_ok",
            "Tests/test_ok.csv",
            false,
            "Archivo válido estándar con 5 procesos"
        },
        {
            "test_blank_lines",
            "Tests/test_blank_lines.csv",
            false,
            "Archivo con líneas en blanco (debe ignorarlas)"
        },
        
        // Tests que DEBEN FALLAR (archivos inválidos)
        {
            "test_empty",
            "Tests/test_empty.csv",
            true,
            "Archivo completamente vacío"
        },
        {
            "test_bad_header",
            "Tests/test_bad_header.csv",
            true,
            "Datos corruptos en línea 2 (texto 'abc' en campo numérico)"
        },
        {
            "test_wrong_types",
            "Tests/test_wrong_types.csv",
            true,
            "Texto 'Alta' en campo de prioridad numérica"
        },
        {
            "test_missing_cols",
            "Tests/test_missing_cols.csv",
            true,
            "Fila con columna faltante (solo 3 valores)"
        },
        {
            "test_negative_values",
            "Tests/test_negative_values.csv",
            true,
            "Tiempo de ráfaga negativo (-5)"
        },
        {
            "test_zero_burst",
            "Tests/test_zero_burst.csv",
            true,
            "Tiempo de ráfaga igual a cero"
        },
        {
            "test_nonexistent",
            "Tests/archivo_que_no_existe.csv",
            true,
            "Archivo que no existe en el sistema"
        }
    };
    
    int pasados = 0;
    int fallados = 0;
    
    // Ejecutar todos los tests
    for (size_t i = 0; i < tests.size(); i++) {
        ejecutarTest(i + 1, tests[i], pasados, fallados);
    }
    
    // Resumen final
    cout << "\n========================================\n";
    cout << "  RESUMEN DE RESULTADOS\n";
    cout << "========================================\n";
    cout << COLOR_GREEN << "Tests Pasados: " << pasados << COLOR_RESET << endl;
    cout << COLOR_RED << "Tests Fallados: " << fallados << COLOR_RESET << endl;
    cout << "Total: " << tests.size() << endl;
    
    double porcentaje = (static_cast<double>(pasados) / tests.size()) * 100.0;
    cout << "\nTasa de Éxito: " << fixed << porcentaje << "%\n";
    
    if (fallados == 0) {
        cout << COLOR_GREEN << "\n✓ TODOS LOS TESTS PASARON\n" << COLOR_RESET;
        return 0;
    } else {
        cout << COLOR_YELLOW << "\n⚠ ALGUNOS TESTS FALLARON - Revisa la implementación\n" << COLOR_RESET;
        return 1;
    }
}
