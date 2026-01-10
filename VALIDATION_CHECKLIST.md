# VALIDATION CHECKLIST - Módulo de Persistencia

## 📋 Instrucciones de Uso
Este checklist debe completarse después de ejecutar el test automatizado. Marca cada escenario con `[OK]` si pasó o `[FAIL]` si falló.

---

## 🧪 TESTS AUTOMATIZADOS

### Ejecución del Test Suite

| Acción | Comando | Estado |
|--------|---------|--------|
| Compilar test runner | `g++ -std=c++17 Utils/test_runner.cpp -o tester.exe` | [ ] |
| Ejecutar tests | `./tester.exe` | [ ] |
| Verificar tasa de éxito | Debe ser 100% | [ ] |

---

## ✅ ESCENARIOS DE VALIDACIÓN FUNCIONAL

### 1. Casos de Éxito (Archivos Válidos)

| # | Archivo | Entrada | Comportamiento Esperado | Estado |
|---|---------|---------|-------------------------|--------|
| 1.1 | `test_ok.csv` | Archivo con 5 procesos válidos | ✓ Carga 5 procesos correctamente<br>✓ Muestra mensaje "Se cargaron exitosamente 5 procesos" | [ ] |
| 1.2 | `test_blank_lines.csv` | Archivo con líneas en blanco entre procesos | ✓ Ignora líneas vacías<br>✓ Carga solo los procesos válidos<br>✓ No genera error | [ ] |
| 1.3 | `procesos_prueba.csv` | Archivo original de ejemplo | ✓ Carga correctamente<br>✓ Permite continuar con el algoritmo | [ ] |

### 2. Casos de Error - Archivo No Encontrado

| # | Archivo | Entrada | Comportamiento Esperado | Estado |
|---|---------|---------|-------------------------|--------|
| 2.1 | Archivo inexistente | `archivo_falso.csv` | ✗ Muestra: "ERROR: No se pudo abrir el archivo"<br>✗ Lanza excepción<br>✗ Programa termina con mensaje claro | [ ] |
| 2.2 | Ruta incorrecta | `C:/inexistente/datos.csv` | ✗ Mismo comportamiento que 2.1 | [ ] |

### 3. Casos de Error - Formato Incorrecto

| # | Archivo | Entrada | Comportamiento Esperado | Estado |
|---|---------|---------|-------------------------|--------|
| 3.1 | `test_empty.csv` | Archivo vacío (0 bytes) | ✗ Muestra: "ERROR: El archivo no contiene procesos válidos"<br>✗ Lanza excepción | [ ] |
| 3.2 | `test_bad_header.csv` | Headers + dato corrupto | ✗ Muestra: "ERROR: Formato incorrecto en línea 2"<br>✗ Indica que no pudo leer el tiempo de llegada | [ ] |
| 3.3 | `test_wrong_types.csv` | Texto ("Alta") en campo numérico | ✗ Muestra: "ERROR: Conversión de datos inválida en línea 2"<br>✗ Sugiere verificar valores numéricos | [ ] |
| 3.4 | `test_missing_cols.csv` | Fila con solo 3 columnas | ✗ Muestra: "ERROR: Formato incorrecto en línea 2"<br>✗ Indica qué columna falta | [ ] |

### 4. Casos de Error - Validación de Datos

| # | Archivo | Entrada | Comportamiento Esperado | Estado |
|---|---------|---------|-------------------------|--------|
| 4.1 | `test_negative_values.csv` | Tiempo de ráfaga = -5 | ✗ Muestra: "ERROR: Valores inválidos en línea 1"<br>✗ Indica que los tiempos deben ser positivos | [ ] |
| 4.2 | `test_zero_burst.csv` | Tiempo de ráfaga = 0 | ✗ Muestra: "ERROR: Valores inválidos"<br>✗ Indica que la ráfaga debe ser > 0 | [ ] |

---

## 🎯 INTEGRACIÓN CON UI

### Pruebas desde interface.cpp

| # | Escenario | Pasos | Comportamiento Esperado | Estado |
|---|-----------|-------|-------------------------|--------|
| 5.1 | Carga exitosa | 1. Ejecutar interface.exe<br>2. Opción 2 (Archivo)<br>3. Escribir `procesos_prueba.csv` | ✓ Muestra "Se cargaron exitosamente X procesos"<br>✓ Continúa al menú de algoritmos<br>✓ Procesos se muestran en la tabla final | [ ] |
| 5.2 | Archivo inválido | 1. Ejecutar interface.exe<br>2. Opción 2<br>3. Escribir `test_wrong_types.csv` | ✗ Muestra mensaje de error en rojo<br>✗ Muestra "No se pudieron cargar los procesos"<br>✗ Programa termina limpiamente | [ ] |
| 5.3 | Archivo no existe | 1. Ejecutar interface.exe<br>2. Opción 2<br>3. Escribir `noexiste.csv` | ✗ Error claro indicando que no se encontró<br>✗ Programa termina sin crash | [ ] |

---

## 🔍 VALIDACIONES DE CALIDAD DE CÓDIGO

### Checklist de Código Limpio

| # | Criterio | Descripción | Estado |
|---|----------|-------------|--------|
| 6.1 | Manejo de excepciones | ✓ Todo código de lectura está en try-catch<br>✓ Se cierran archivos incluso en caso de error | [ ] |
| 6.2 | Mensajes descriptivos | ✓ Los errores indican el número de línea<br>✓ Explican qué salió mal específicamente | [ ] |
| 6.3 | Validación de datos | ✓ Verifica que tiempoLlegada >= 0<br>✓ Verifica que tiempoRafaga > 0<br>✓ Verifica 4 columnas por línea | [ ] |
| 6.4 | Sin memory leaks | ✓ Los archivos se cierran correctamente<br>✓ No hay punteros sin liberar | [ ] |
| 6.5 | Código portable | ✓ Usa C++17 standard<br>✓ No depende de librerías no estándar | [ ] |

---

## 🧪 PRUEBAS DE ESTRÉS (Opcional)

| # | Escenario | Entrada | Comportamiento Esperado | Estado |
|---|-----------|---------|-------------------------|--------|
| 7.1 | Archivo grande | CSV con 1000+ procesos | ✓ Carga en tiempo razonable (<5 seg)<br>✓ No se queda sin memoria | [ ] |
| 7.2 | Caracteres especiales | ID con tildes: "Próc€ß0" | ✓ Maneja UTF-8 correctamente<br>O ✗ Da error claro sobre encoding | [ ] |
| 7.3 | Líneas muy largas | Fila con 1000 caracteres | ✓ Parsea correctamente<br>O ✗ Error claro de formato | [ ] |

---

## 📊 RESUMEN FINAL

### Conteo de Resultados

- **Tests Automáticos**: ___ de 9 pasados (___%)
- **Validación Funcional**: ___ de 11 pasados (___%)
- **Integración UI**: ___ de 3 pasados (___%)
- **Calidad de Código**: ___ de 5 verificados (___%)

### Decisión

- [ ] ✅ **APROBADO** - El módulo está listo para producción
- [ ] ⚠️ **APROBADO CON OBSERVACIONES** - Funciona pero necesita mejoras menores
- [ ] ❌ **RECHAZADO** - Requiere correcciones antes de integrar

### Observaciones:

```
[Escribe aquí cualquier bug encontrado, comportamiento inesperado o mejora sugerida]




```

---

## 📝 Notas del Tester

**Fecha de prueba**: ___________  
**Testeado por**: ___________  
**Compilador usado**: ___________  
**SO**: ___________  

---

## 🚀 Comandos Rápidos de Referencia

```bash
# Compilar test suite
g++ -std=c++17 Utils/test_runner.cpp -o tester.exe

# Ejecutar tests
./tester.exe

# Compilar interfaz principal
cd UI
g++ -std=c++17 interface.cpp -o simulador.exe

# Ejecutar simulador
./simulador.exe
```
