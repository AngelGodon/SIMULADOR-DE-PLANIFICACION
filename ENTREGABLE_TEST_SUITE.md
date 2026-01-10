# 📦 ENTREGABLE COMPLETO - TEST SUITE

## ✅ TAREA 1: Archivos CSV de Prueba Generados

### Ubicación: `Tests/`

| Archivo | Tipo | Descripción |
|---------|------|-------------|
| ✅ `test_ok.csv` | VÁLIDO | 5 procesos estándar bien formados |
| ✅ `test_blank_lines.csv` | VÁLIDO | Procesos con líneas vacías (debe ignorarlas) |
| ❌ `test_empty.csv` | INVÁLIDO | Archivo completamente vacío (0 bytes) |
| ❌ `test_bad_header.csv` | INVÁLIDO | Headers + línea con "abc" en campo numérico |
| ❌ `test_wrong_types.csv` | INVÁLIDO | "Alta" en lugar de número de prioridad |
| ❌ `test_missing_cols.csv` | INVÁLIDO | Fila con solo 3 columnas en vez de 4 |
| ❌ `test_negative_values.csv` | INVÁLIDO | Tiempo de ráfaga negativo (-5) |
| ❌ `test_zero_burst.csv` | INVÁLIDO | Tiempo de ráfaga igual a cero |

**Total:** 8 archivos de prueba + 1 caso de archivo inexistente = **9 test cases**

---

## ✅ TAREA 2: Script de Validación Automática

### Archivo Creado: `Utils/test_runner.cpp`

#### Características:

✅ **Main independiente** - No necesita la UI  
✅ **Incluye file_handler.h** correctamente  
✅ **9 casos de prueba** definidos en un vector  
✅ **Colorización ANSI** para resultados claros  
✅ **Sistema PASÓ/FALLÓ** automático  
✅ **Resumen estadístico** con porcentaje de éxito  
✅ **Exit code** apropiado (0 = éxito, 1 = fallos)  

#### Lógica de Validación:

```
Para cada test:
  SI el archivo debería ser válido:
    - Intenta cargar
    - SI carga → PASÓ ✓
    - SI lanza excepción → FALLÓ ✗
  
  SI el archivo debería ser inválido:
    - Intenta cargar
    - SI lanza excepción → PASÓ ✓
    - SI carga → FALLÓ ✗
```

#### Salida del Programa:

```
========================================
  TEST SUITE - FILE HANDLER MODULE
========================================

--- Ejecutando: Archivo válido estándar con 5 procesos
[TEST 1] test_ok -> PASÓ (5 procesos cargados)

--- Ejecutando: Archivo completamente vacío
[TEST 3] test_empty -> PASÓ (Excepción capturada correctamente)

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

---

## ✅ TAREA 3: Checklist de Validación Manual

### Archivo Creado: `VALIDATION_CHECKLIST.md`

#### Contenido:

📋 **35+ escenarios de validación** organizados en:

1. **Tests Automatizados** (9 casos)
   - Compilación y ejecución del test suite
   
2. **Validación Funcional** (11 casos)
   - Archivos válidos
   - Archivos no encontrados
   - Formato incorrecto
   - Validación de datos

3. **Integración con UI** (3 casos)
   - Carga exitosa desde interfaz
   - Manejo de errores en interfaz
   - Terminación limpia del programa

4. **Calidad de Código** (5 verificaciones)
   - Manejo de excepciones
   - Mensajes descriptivos
   - Validación de datos
   - Sin memory leaks
   - Código portable

5. **Pruebas de Estrés** (3 casos opcionales)
   - Archivos grandes
   - Caracteres especiales
   - Líneas muy largas

#### Formato de Tabla:

| # | Archivo | Entrada | Comportamiento Esperado | Estado |
|---|---------|---------|-------------------------|--------|
| 1.1 | test_ok.csv | 5 procesos válidos | ✓ Carga correctamente | [ ] |

Cada fila tiene un checkbox `[ ]` para marcar manualmente.

---

## 🚀 COMANDOS DE COMPILACIÓN Y EJECUCIÓN

### Opción 1: Línea de Comandos

```bash
# Compilar Test Runner
g++ -std=c++17 Utils/test_runner.cpp -o tester.exe

# Ejecutar Tests
./tester.exe

# Compilar Interfaz Principal
cd UI
g++ -std=c++17 interface.cpp -o simulador.exe
cd ..

# Ejecutar Interfaz
./UI/simulador.exe
```

### Opción 2: Script Automatizado (Windows)

```bash
# Ejecutar script interactivo
build.bat

# Menú:
# [1] Compilar Test Runner
# [2] Ejecutar Tests
# [3] Compilar y Ejecutar Tests (RECOMENDADO)
# [4] Compilar Interfaz Principal
# [5] Ejecutar Interfaz Principal
# [6] Compilar Todo
```

---

## 📁 ESTRUCTURA DE ARCHIVOS CREADOS

```
SIMULADOR-DE-PLANIFICACION/
│
├── Tests/                          ← 🆕 Carpeta de pruebas
│   ├── test_ok.csv                 ← 🆕 Válido: 5 procesos
│   ├── test_empty.csv              ← 🆕 Inválido: vacío
│   ├── test_bad_header.csv         ← 🆕 Inválido: datos corruptos
│   ├── test_wrong_types.csv        ← 🆕 Inválido: tipo incorrecto
│   ├── test_missing_cols.csv       ← 🆕 Inválido: columnas faltantes
│   ├── test_negative_values.csv    ← 🆕 Inválido: valores negativos
│   ├── test_zero_burst.csv         ← 🆕 Inválido: ráfaga = 0
│   ├── test_blank_lines.csv        ← 🆕 Válido: con líneas vacías
│   └── README.md                   ← 🆕 Documentación de tests
│
├── Utils/
│   ├── file_handler.h              ← Ya existía
│   ├── file_handler.cpp            ← Ya existía
│   └── test_runner.cpp             ← 🆕 Suite de tests
│
├── VALIDATION_CHECKLIST.md         ← 🆕 Checklist manual
├── build.bat                       ← 🆕 Script de compilación
└── README_PERSISTENCIA.md          ← Ya existía
```

---

## 🎯 PROCESO DE VALIDACIÓN RECOMENDADO

### Paso 1: Compilar y Ejecutar Tests Automatizados

```bash
g++ -std=c++17 Utils/test_runner.cpp -o tester.exe
./tester.exe
```

**Verificar:** Todos los tests deben pasar (9/9 = 100%)

### Paso 2: Validación Manual con la UI

```bash
cd UI
g++ -std=c++17 interface.cpp -o simulador.exe
./simulador.exe
```

**Probar:**
1. Opción 2 → `procesos_prueba.csv` → Debe cargar ✅
2. Opción 2 → `test_wrong_types.csv` → Debe fallar ❌
3. Opción 2 → `noexiste.csv` → Debe fallar ❌

### Paso 3: Completar Checklist

Abre `VALIDATION_CHECKLIST.md` y marca cada escenario probado.

### Paso 4: Revisión Final

```
Si 100% de tests automatizados pasaron
Y   100% de validación manual pasada
Y   Checklist completo
→ Módulo APROBADO ✅
```

---

## 📊 MÉTRICAS DE COBERTURA

### Tests Automatizados
- ✅ Archivo válido estándar
- ✅ Manejo de líneas vacías
- ✅ Archivo vacío
- ✅ Datos corruptos
- ✅ Tipos incorrectos
- ✅ Columnas faltantes
- ✅ Valores negativos
- ✅ Valor cero en ráfaga
- ✅ Archivo inexistente

**Total: 9 escenarios**

### Validación Manual
- ✅ 11 casos funcionales
- ✅ 3 casos de integración UI
- ✅ 5 verificaciones de calidad
- ✅ 3 casos de estrés (opcional)

**Total: 22 escenarios**

---

## 🐛 TROUBLESHOOTING

### El tester no compila

**Error:**
```
file_handler.h: No such file or directory
```

**Solución:**
```bash
cd SIMULADOR-DE-PLANIFICACION
g++ -std=c++17 Utils/test_runner.cpp -o tester.exe
```

### Los colores no se ven en Windows

**Solución 1:** Usa PowerShell o Windows Terminal  
**Solución 2:** Comenta las líneas `#define COLOR_*` en test_runner.cpp

### Algún test falla inesperadamente

1. Verifica que los archivos CSV estén en `Tests/`
2. Asegúrate de no tener espacios extra
3. Usa UTF-8 o ASCII en los archivos

---

## 🎓 CONCLUSIÓN

Has recibido:

✅ **8 archivos CSV** de prueba con casos válidos e inválidos  
✅ **1 script de tests** (`test_runner.cpp`) con 9 casos automatizados  
✅ **1 checklist completo** (`VALIDATION_CHECKLIST.md`) con 35+ escenarios  
✅ **1 script de compilación** (`build.bat`) para Windows  
✅ **Documentación completa** en `Tests/README.md`  

**Resultado esperado:** 100% de tests pasando si la implementación de `file_handler.cpp` es correcta.

---

## 📞 SOPORTE

Si encuentras bugs o comportamientos inesperados:

1. Revisa el archivo `VALIDATION_CHECKLIST.md`
2. Anota en "Observaciones" el problema encontrado
3. Marca el estado como `[FAIL]`
4. Reporta para corrección

**¡Buena suerte con la validación! 🚀**
