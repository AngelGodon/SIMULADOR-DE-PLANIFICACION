# ⚡ QUICK REFERENCE - Testing Commands

## 🚀 Ejecución Rápida (Copy-Paste)

### Windows (CMD/PowerShell)

```batch
REM Compilar y ejecutar tests
g++ -std=c++17 Utils\test_runner.cpp -o tester.exe && tester.exe

REM Compilar interfaz
cd UI && g++ -std=c++17 interface.cpp -o simulador.exe && cd ..

REM Ejecutar interfaz
UI\simulador.exe

REM Script automatizado
build.bat
```

### Linux/Mac

```bash
# Compilar y ejecutar tests
g++ -std=c++17 Utils/test_runner.cpp -o tester && ./tester

# Compilar interfaz
cd UI && g++ -std=c++17 interface.cpp -o simulador && cd ..

# Ejecutar interfaz
./UI/simulador
```

---

## 📋 Checklist Rápido

```
[ ] Compilar test_runner.cpp
[ ] Ejecutar ./tester.exe
[ ] Verificar 9/9 tests pasados
[ ] Compilar interface.cpp
[ ] Probar carga de procesos_prueba.csv
[ ] Probar archivo inválido
[ ] Completar VALIDATION_CHECKLIST.md
[ ] Marcar módulo como APROBADO
```

---

## 🎯 Resultados Esperados

### Test Runner
```
Tests Pasados: 9
Tests Fallados: 0
Total: 9
Tasa de Éxito: 100.00%
✓ TODOS LOS TESTS PASARON
```

### Interfaz con archivo válido
```
Se cargaron exitosamente 5 procesos desde el archivo.
```

### Interfaz con archivo inválido
```
ERROR: [mensaje descriptivo]
No se pudieron cargar los procesos. El programa terminará.
```

---

## 📁 Archivos Clave

| Archivo | Propósito |
|---------|-----------|
| `Utils/test_runner.cpp` | Suite de tests automatizada |
| `Tests/*.csv` | Casos de prueba (8 archivos) |
| `VALIDATION_CHECKLIST.md` | Checklist manual completo |
| `build.bat` | Script de compilación Windows |
| `ENTREGABLE_TEST_SUITE.md` | Documentación completa |

---

## 🐛 Errores Comunes

| Error | Solución |
|-------|----------|
| `file_handler.h not found` | Ejecutar desde raíz del proyecto |
| `No such file or directory` | Verificar que `Tests/` existe |
| Test falla inesperadamente | Revisar formato CSV (sin espacios extra) |
| Colores no se ven | Usar PowerShell/Terminal en Windows |

---

## 📞 Ayuda Rápida

**¿Cómo sé si todo está bien?**
→ Ejecuta `./tester.exe` y verifica que muestre "100.00%"

**¿Cómo pruebo desde la UI?**
→ Opción 2 → Escribir `procesos_prueba.csv`

**¿Dónde reporto bugs?**
→ En el campo "Observaciones" de `VALIDATION_CHECKLIST.md`

---

Generated: $(date)
