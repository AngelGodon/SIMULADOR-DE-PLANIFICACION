# 🧪 TEST SUITE - File Handler Module

## Descripción

Suite de pruebas automatizada para validar la robustez del módulo de persistencia (`file_handler.cpp`).

## Estructura de Tests

```
Tests/
├── test_ok.csv              ✅ Archivo válido estándar
├── test_empty.csv           ❌ Archivo vacío
├── test_bad_header.csv      ❌ Headers + datos corruptos
├── test_wrong_types.csv     ❌ Texto en campo numérico
├── test_missing_cols.csv    ❌ Columnas faltantes
├── test_negative_values.csv ❌ Valores negativos
├── test_zero_burst.csv      ❌ Tiempo de ráfaga = 0
└── test_blank_lines.csv     ✅ Líneas en blanco (válido)
```

## Compilación

### Compilar Test Runner

```bash
g++ -std=c++17 Utils/test_runner.cpp -o tester.exe
```

### Compilar Interfaz Principal

```bash
cd UI
g++ -std=c++17 interface.cpp -o simulador.exe
```

## Ejecución

### Ejecutar Tests Automatizados

```bash
./tester.exe
```

**Salida esperada:**
```
========================================
  TEST SUITE - FILE HANDLER MODULE
========================================

--- Ejecutando: Archivo válido estándar con 5 procesos
[TEST 1] test_ok -> PASÓ (5 procesos cargados)

--- Ejecutando: Archivo con líneas en blanco (debe ignorarlas)
[TEST 2] test_blank_lines -> PASÓ (2 procesos cargados)

...

========================================
  RESUMEN DE RESULTADOS
========================================
Tests Pasados: 9
Tests Fallados: 0
Total: 9

Tasa de Éxito: 100.00%

✓ TODOS LOS TESTS PASARON
```

## Casos de Prueba

### ✅ Tests que DEBEN PASAR

| Test | Archivo | Descripción |
|------|---------|-------------|
| 1 | `test_ok.csv` | 5 procesos válidos |
| 2 | `test_blank_lines.csv` | Procesos con líneas vacías entre ellos |

### ❌ Tests que DEBEN FALLAR (y capturar excepción)

| Test | Archivo | Error Esperado |
|------|---------|----------------|
| 3 | `test_empty.csv` | Archivo vacío |
| 4 | `test_bad_header.csv` | Texto en campo numérico |
| 5 | `test_wrong_types.csv` | "Alta" en lugar de número |
| 6 | `test_missing_cols.csv` | Solo 3 columnas |
| 7 | `test_negative_values.csv` | Tiempo de ráfaga negativo |
| 8 | `test_zero_burst.csv` | Tiempo de ráfaga = 0 |
| 9 | `test_nonexistent.csv` | Archivo no existe |

## Interpretación de Resultados

### Si todos los tests pasan (100%)
✅ El módulo `file_handler.cpp` es robusto y maneja correctamente:
- Archivos válidos
- Archivos vacíos
- Datos corruptos
- Tipos incorrectos
- Valores fuera de rango
- Archivos inexistentes

### Si algún test falla
❌ Hay un problema en la implementación:

**Test de archivo válido falla:**
- Problema: El parser no está leyendo correctamente datos válidos
- Acción: Revisar la lógica de `std::stringstream` y parsing

**Test de archivo inválido NO falla:**
- Problema: No se está validando correctamente o no se lanzan excepciones
- Acción: Revisar validaciones y try-catch blocks

## Validación Manual Adicional

Después de ejecutar los tests automatizados, completa el checklist:

```bash
# Abrir checklist
cat VALIDATION_CHECKLIST.md
```

Este checklist incluye:
- ✅ Pruebas de integración con la UI
- ✅ Validación de mensajes de error
- ✅ Pruebas de estrés (opcional)
- ✅ Checklist de calidad de código

## Troubleshooting

### El tester no compila

**Error:** `file_handler.h: No such file or directory`

**Solución:** Asegúrate de ejecutar desde la raíz del proyecto:
```bash
cd SIMULADOR-DE-PLANIFICACION
g++ -std=c++17 Utils/test_runner.cpp -o tester.exe
```

### Los colores ANSI no se muestran en Windows

**Solución:** Usa PowerShell o Windows Terminal en lugar de CMD, o desactiva los colores eliminando las constantes `COLOR_*`.

### Algunos tests fallan inesperadamente

**Diagnóstico:**
1. Verifica que los archivos CSV estén en `Tests/`
2. Revisa que no tengas espacios extra en los CSVs
3. Comprueba la codificación del archivo (debe ser UTF-8 o ASCII)

## Próximos Pasos

Una vez que todos los tests pasen:

1. ✅ Ejecutar tests automatizados → `./tester.exe`
2. ✅ Completar VALIDATION_CHECKLIST.md
3. ✅ Probar integración con UI
4. ✅ Marcar módulo como "APROBADO"
5. 🚀 Continuar con siguiente feature

## Contribuir

Para agregar más tests:

1. Crear archivo CSV en `Tests/`
2. Agregar caso en `test_runner.cpp` dentro del vector `tests`
3. Definir si `deberiaFallar` es true o false
4. Re-compilar y ejecutar

## Licencia

Este test suite es parte del proyecto SIMULADOR-DE-PLANIFICACION.
