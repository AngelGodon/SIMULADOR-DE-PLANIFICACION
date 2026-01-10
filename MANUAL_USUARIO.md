# 📖 Manual de Usuario - Simulador de Planificación de Procesos

## Carga de Procesos desde Archivo

---

## 📌 Introducción

El **Simulador de Planificación de Procesos** ahora incluye la funcionalidad de **carga masiva de procesos desde archivo**. Esta característica permite importar grandes conjuntos de datos de procesos sin necesidad de ingresarlos manualmente uno por uno, facilitando:

- ✅ Pruebas con conjuntos de datos predefinidos
- ✅ Reproducibilidad de experimentos
- ✅ Análisis comparativo entre diferentes algoritmos
- ✅ Ahorro significativo de tiempo en la entrada de datos
- ✅ Reducción de errores de captura manual

En lugar de ingresar cada proceso individualmente, puede preparar un archivo con todos sus datos y cargarlos en segundos.

---

## 📄 Formato del Archivo de Entrada

### Especificaciones Técnicas

El archivo de entrada debe cumplir con los siguientes requisitos:

| Característica | Especificación |
|----------------|----------------|
| **Tipo de archivo** | Archivo de texto plano (`.txt`) o CSV (`.csv`) |
| **Codificación** | UTF-8 o ASCII |
| **Separador** | Coma (`,`) |
| **Encabezados** | No incluir línea de encabezados |
| **Líneas vacías** | Permitidas (se ignoran automáticamente) |

### Estructura de Columnas

Cada línea del archivo representa un proceso y debe contener **exactamente 4 valores** separados por comas:

| Columna | Nombre | Tipo de Dato | Rango Válido | Descripción |
|---------|--------|--------------|--------------|-------------|
| 1 | **ID** | String | Cualquier texto | Identificador único del proceso (ej: P1, Proc_A, Tarea1) |
| 2 | **TiempoLlegada** | Entero | >= 0 | Momento en que el proceso llega al sistema |
| 3 | **TiempoRafaga** | Entero | > 0 | Tiempo de CPU requerido por el proceso |
| 4 | **Prioridad** | Entero | Cualquier valor | Prioridad del proceso (menor número = mayor prioridad) |

### ⚠️ Reglas de Validación

El sistema valida automáticamente cada archivo antes de cargarlo:

- ✅ **TiempoLlegada** debe ser mayor o igual a cero (>= 0)
- ✅ **TiempoRafaga** debe ser estrictamente mayor a cero (> 0)
- ✅ Cada línea debe tener exactamente 4 valores
- ✅ Los valores numéricos no deben contener texto
- ❌ El archivo no puede estar vacío

### 📝 Ejemplo de Archivo Válido

A continuación se presenta un ejemplo completo de un archivo CSV válido que puede copiar y utilizar:

#### `procesos_ejemplo.csv`

```csv
P1,0,10,3
P2,2,5,1
P3,4,8,2
P4,6,3,4
P5,8,7,2
```

**Interpretación de los datos:**

- **P1**: Llega en t=0, requiere 10 unidades de CPU, prioridad 3
- **P2**: Llega en t=2, requiere 5 unidades de CPU, prioridad 1 (mayor prioridad)
- **P3**: Llega en t=4, requiere 8 unidades de CPU, prioridad 2
- **P4**: Llega en t=6, requiere 3 unidades de CPU, prioridad 4 (menor prioridad)
- **P5**: Llega en t=8, requiere 7 unidades de CPU, prioridad 2

### 📋 Plantilla para Crear sus Propios Archivos

```csv
ID_Proceso,TiempoLlegada,TiempoRafaga,Prioridad
```

**Ejemplo con más procesos:**

```csv
A,0,12,2
B,1,8,1
C,3,6,3
D,5,15,1
E,7,4,2
F,9,10,4
G,11,7,2
H,13,5,3
```

💡 **Tip:** Puede crear este archivo en cualquier editor de texto (Notepad, VS Code, Notepad++) o en una hoja de cálculo (Excel, Google Sheets) y guardarlo como CSV.

---

## 🚀 Guía de Uso Paso a Paso

### Paso 1: Preparar el Archivo de Datos

1. Cree un archivo de texto nuevo (extensión `.csv` o `.txt`)
2. Ingrese los datos de sus procesos siguiendo el formato especificado
3. Guarde el archivo en una ubicación conocida

💡 **Recomendación:** Guarde el archivo en la misma carpeta donde se encuentra el ejecutable del simulador para usar rutas relativas simples.

---

### Paso 2: Iniciar el Simulador

Ejecute el programa del simulador:

**Windows:**
```bash
simulador.exe
```

**Linux/Mac:**
```bash
./simulador
```

Verá el menú principal:

```
SIMULADOR DE PLANIFICACION

Cual va a ser la entrada de datos:
1. Manual
2. Archivo
Opcion: 
```

---

### Paso 3: Seleccionar la Opción de Carga desde Archivo

Ingrese el número **2** y presione Enter:

```
Opcion: 2
```

El sistema le solicitará el nombre del archivo:

```
Ingresa el nombre del archivo (ej: procesos_prueba.csv): 
```

---

### Paso 4: Ingresar la Ruta del Archivo

Tiene dos opciones para especificar la ubicación del archivo:

#### Opción A: Ruta Relativa (Recomendado)

Si el archivo está en la misma carpeta que el ejecutable:

```
Ingresa el nombre del archivo (ej: procesos_prueba.csv): procesos_ejemplo.csv
```

Si está en una subcarpeta:

```
Ingresa el nombre del archivo (ej: procesos_prueba.csv): datos/procesos.csv
```

#### Opción B: Ruta Absoluta

Puede especificar la ruta completa:

**Windows:**
```
Ingresa el nombre del archivo (ej: procesos_prueba.csv): C:\Usuarios\MiUsuario\Documentos\procesos.csv
```

**Linux/Mac:**
```
Ingresa el nombre del archivo (ej: procesos_prueba.csv): /home/usuario/documentos/procesos.csv
```

---

### Paso 5: Verificar la Carga Exitosa

Si el archivo es válido, verá el siguiente mensaje:

```
Se cargaron exitosamente 5 procesos desde el archivo.
```

El sistema continuará automáticamente al menú de selección de algoritmo:

```
Selecciona el Algoritmo:
1. FCFS
2. SJF
3. Round Robin
4. Prioridad
Opcion: 
```

---

### Paso 6: Ejecutar el Algoritmo de Planificación

Seleccione el algoritmo deseado y el simulador procesará los datos cargados, mostrando los resultados en una tabla detallada con las métricas de rendimiento.

---

## 🔧 Solución de Problemas (Troubleshooting)

### ❌ Error: "No se pudo abrir el archivo"

**Mensaje completo:**
```
ERROR: No se pudo abrir el archivo 'nombre_archivo.csv'
No se pudieron cargar los procesos. El programa terminará.
```

**Causas posibles:**

1. **El archivo no existe en la ubicación especificada**
   - Verifique que el nombre del archivo esté escrito correctamente
   - Revise que la extensión sea la correcta (`.csv` o `.txt`)
   - Confirme que el archivo esté en la carpeta indicada

2. **Ruta incorrecta**
   - Si usó ruta relativa, asegúrese de que el archivo esté en la carpeta del ejecutable
   - Si usó ruta absoluta, verifique que la ruta completa sea correcta

3. **Permisos insuficientes**
   - Verifique que tenga permisos de lectura sobre el archivo

**Solución:**
```bash
# Verificar que el archivo existe (Windows)
dir nombre_archivo.csv

# Verificar que el archivo existe (Linux/Mac)
ls -l nombre_archivo.csv
```

---

### ❌ Error: "Formato incorrecto en línea X"

**Mensajes posibles:**
```
ERROR: Formato incorrecto en línea 2 - No se pudo leer el tiempo de llegada
ERROR: Formato incorrecto en línea 3 - No se pudo leer el tiempo de ráfaga
ERROR: Formato incorrecto en línea 5 - No se pudo leer la prioridad
```

**Causas posibles:**

1. **Datos no numéricos en columnas numéricas**
   ```csv
   P1,0,diez,2        ❌ "diez" no es un número
   P2,abc,5,1         ❌ "abc" no es un número
   P3,3,7,Alta        ❌ "Alta" no es un número
   ```

2. **Columnas faltantes**
   ```csv
   P1,0,10            ❌ Falta la columna de prioridad
   P2,5               ❌ Faltan dos columnas
   ```

3. **Separadores incorrectos**
   ```csv
   P1;0;10;2          ❌ Usa punto y coma en lugar de coma
   P2 0 10 2          ❌ Usa espacios en lugar de comas
   ```

**Solución:**

Revise la línea indicada en el mensaje de error y corrija el formato:

```csv
✅ Formato Correcto:
P1,0,10,2
P2,2,5,1
P3,4,8,3

❌ Formato Incorrecto:
P1,0,diez,2
P2,abc,5
P3;4;8;3
```

---

### ❌ Error: "Conversión de datos inválida en línea X"

**Mensaje completo:**
```
ERROR: Conversión de datos inválida en línea 3 - Verifica que los valores numéricos sean correctos
```

**Causas posibles:**

1. **Números con formato incorrecto**
   ```csv
   P1,0.5,10,2        ❌ Decimales no permitidos (debe ser entero)
   P2,2,5.5,1         ❌ Decimales no permitidos
   P3,4,1e10,2        ❌ Notación científica no permitida
   ```

2. **Espacios extra en los números**
   ```csv
   P1, 0 ,10,2        ⚠️ Espacios alrededor de los números
   ```

**Solución:**

Use solo números enteros sin decimales ni espacios:

```csv
✅ Correcto:
P1,0,10,2
P2,5,15,1

❌ Incorrecto:
P1,0.5,10,2
P2, 5 , 15 ,1
```

---

### ❌ Error: "Valores inválidos en línea X"

**Mensaje completo:**
```
ERROR: Valores inválidos en línea 2 - Los tiempos deben ser positivos (ráfaga > 0)
```

**Causas posibles:**

1. **Tiempo de llegada negativo**
   ```csv
   P1,-5,10,2         ❌ Tiempo de llegada < 0
   ```

2. **Tiempo de ráfaga cero o negativo**
   ```csv
   P2,0,0,1           ❌ Tiempo de ráfaga = 0
   P3,2,-5,2          ❌ Tiempo de ráfaga < 0
   ```

**Solución:**

Asegúrese de que:
- **TiempoLlegada >= 0** (puede ser cero)
- **TiempoRafaga > 0** (debe ser mayor a cero)

```csv
✅ Correcto:
P1,0,10,2          (llegada=0 está permitido)
P2,5,1,1           (ráfaga=1 está permitido)

❌ Incorrecto:
P1,-1,10,2         (llegada negativa)
P2,0,0,1           (ráfaga=0 no permitido)
P3,5,-3,2          (ráfaga negativa)
```

---

### ❌ Error: "El archivo no contiene procesos válidos"

**Mensaje completo:**
```
ERROR: El archivo no contiene procesos válidos
```

**Causas posibles:**

1. **Archivo completamente vacío**
2. **Solo contiene líneas vacías o espacios**
3. **Todas las líneas tienen errores de formato**

**Solución:**

Verifique que el archivo contenga al menos una línea válida con datos:

```csv
✅ Correcto (al menos un proceso):
P1,0,10,2

❌ Incorrecto (archivo vacío):
[archivo sin contenido]

❌ Incorrecto (solo líneas vacías):


```

---

### ⚠️ Advertencia: Líneas en Blanco

Las líneas vacías se **ignoran automáticamente**. Esto es normal y no genera errores:

```csv
✅ Válido (líneas vacías son ignoradas):
P1,0,10,2

P2,2,5,1

P3,4,8,3
```

💡 **Tip:** Puede usar líneas vacías para separar grupos de procesos y mejorar la legibilidad.

---

## 💡 Consejos y Mejores Prácticas

### 1. Organización de Archivos

Mantenga sus archivos de prueba organizados:

```
proyecto/
├── simulador.exe
├── datos/
│   ├── test_fcfs.csv
│   ├── test_sjf.csv
│   ├── test_rr.csv
│   └── test_priority.csv
└── resultados/
```

### 2. Nomenclatura de Archivos

Use nombres descriptivos que indiquen el propósito:

- ✅ `procesos_fcfs_10.csv` - 10 procesos para prueba FCFS
- ✅ `datos_prioridad_alta.csv` - Procesos con alta prioridad
- ✅ `escenario_mixto.csv` - Escenario con procesos variados
- ❌ `datos.csv` - Nombre genérico poco descriptivo
- ❌ `test1.csv` - No indica qué contiene

### 3. Documentación de Conjuntos de Datos

Agregue comentarios en un archivo README asociado:

```markdown
# test_fcfs_10.csv
- 10 procesos con llegadas escalonadas
- Tiempos de ráfaga variados (3-15 unidades)
- Prioridades aleatorias
- Propósito: Validar algoritmo FCFS
```

### 4. Validación Previa

Antes de ejecutar el simulador, revise su archivo:

```bash
# Ver el contenido del archivo (Windows)
type procesos.csv

# Ver el contenido del archivo (Linux/Mac)
cat procesos.csv

# Contar procesos en el archivo
wc -l procesos.csv
```

### 5. Backup de Datos

Mantenga copias de respaldo de sus conjuntos de datos importantes:

```bash
# Crear copia de seguridad
cp procesos.csv procesos_backup.csv
```

### 6. Pruebas Incrementales

Empiece con archivos pequeños y aumente gradualmente:

1. Primero: 3-5 procesos (validar formato)
2. Luego: 10-20 procesos (pruebas estándar)
3. Finalmente: 50+ procesos (pruebas de estrés)

---

## 📊 Ejemplos de Uso por Algoritmo

### Ejemplo para FCFS (First Come First Served)

**Archivo:** `test_fcfs.csv`

```csv
P1,0,8,1
P2,1,4,1
P3,2,9,1
P4,3,5,1
```

**Características:**
- Todas las prioridades iguales (FCFS no usa prioridad)
- Llegadas consecutivas
- Tiempos de ráfaga variados

---

### Ejemplo para SJF (Shortest Job First)

**Archivo:** `test_sjf.csv`

```csv
Corto,0,3,1
Medio,0,8,1
Largo,0,15,1
MuyCorto,0,1,1
```

**Características:**
- Todos llegan al mismo tiempo
- Tiempos de ráfaga muy diferentes
- Ideal para observar el comportamiento SJF

---

### Ejemplo para Round Robin

**Archivo:** `test_rr.csv`

```csv
P1,0,10,1
P2,1,8,1
P3,2,6,1
P4,3,12,1
```

**Características:**
- Procesos con tiempos largos
- Llegadas espaciadas
- Quantum recomendado: 2-4 unidades

---

### Ejemplo para Prioridad

**Archivo:** `test_priority.csv`

```csv
Critico,0,5,1
Alto,0,8,2
Medio,0,10,3
Bajo,0,6,4
```

**Características:**
- Todos llegan al mismo tiempo
- Prioridades claramente diferenciadas (1=más alta, 4=más baja)
- Tiempos similares para comparar solo por prioridad

---

## 📚 Recursos Adicionales

### Archivos de Ejemplo Incluidos

El simulador incluye los siguientes archivos de ejemplo que puede usar inmediatamente:

| Archivo | Descripción | Procesos |
|---------|-------------|----------|
| `procesos_prueba.csv` | Conjunto general de prueba | 5 |
| `Tests/test_ok.csv` | Datos validados (testing) | 5 |
| `Tests/test_blank_lines.csv` | Con líneas vacías | 2 |

### Generar Datos Aleatorios

Si necesita generar grandes conjuntos de datos, puede usar herramientas externas o scripts:

**Python (ejemplo):**
```python
import random

with open('procesos_random.csv', 'w') as f:
    for i in range(1, 101):  # 100 procesos
        llegada = i - 1
        rafaga = random.randint(1, 20)
        prioridad = random.randint(1, 5)
        f.write(f'P{i},{llegada},{rafaga},{prioridad}\n')
```

---

## 🎓 Casos de Estudio Recomendados

### Caso 1: Comparación de Algoritmos

Prepare un único archivo de datos y ejecútelo con los 4 algoritmos:

```csv
P1,0,10,3
P2,2,4,1
P3,4,6,2
P4,6,8,4
P5,8,2,1
```

Compare:
- Tiempo de espera promedio
- Tiempo de retorno promedio
- Utilización de CPU

### Caso 2: Efecto del Quantum en Round Robin

Use el mismo archivo y pruebe con diferentes valores de quantum (2, 4, 8):

```csv
P1,0,20,1
P2,0,15,1
P3,0,10,1
```

### Caso 3: Inanición (Starvation)

Simule inanición con procesos de baja prioridad:

```csv
Alta1,0,5,1
Alta2,2,5,1
Alta3,4,5,1
Baja,0,10,5
```

Observe si el proceso "Baja" sufre inanición en el algoritmo de prioridad.

---

## ✅ Checklist Pre-Ejecución

Antes de ejecutar el simulador, verifique:

- [ ] El archivo CSV existe en la ubicación especificada
- [ ] El archivo tiene extensión `.csv` o `.txt`
- [ ] Cada línea tiene exactamente 4 valores separados por comas
- [ ] Todos los valores numéricos son enteros (sin decimales)
- [ ] TiempoLlegada >= 0 en todos los procesos
- [ ] TiempoRafaga > 0 en todos los procesos
- [ ] El archivo contiene al menos un proceso válido
- [ ] No hay espacios extra alrededor de los valores

---

## 📞 Soporte y Contacto

Si encuentra problemas no descritos en este manual o tiene sugerencias de mejora:

1. Revise el archivo `VALIDATION_CHECKLIST.md` para pruebas detalladas
2. Consulte `README_PERSISTENCIA.md` para detalles técnicos
3. Reporte issues en el repositorio del proyecto

---

## 📝 Historial de Versiones

| Versión | Fecha | Cambios |
|---------|-------|---------|
| 1.0 | 2026-01-10 | Versión inicial del manual |

---

**¡Gracias por usar el Simulador de Planificación de Procesos!** 🚀

---

*Documento generado para facilitar el uso académico y profesional del software.*
*Para más información técnica, consulte la documentación técnica completa del proyecto.*
