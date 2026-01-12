# Lectura de Archivos CSV

## Formato del Archivo CSV

```
ID,TiempoLlegada,TiempoRafaga,Prioridad
```

**Ejemplo:**
```
P1,0,8,2
P2,1,4,1
P3,2,9,3
```

## Compilación

```bash
cd UI
g++ -std=c++17 "Ruta directa del archivo interface.cpp (elimminando las comillas)" -o simulador.exe
```

## Uso

1. Ejecutar el programa:
```bash
simulador.exe
```

2. Seleccionar opción 2 (Archivo)

3. Ingresar el nombre del archivo, por ejemplo: `procesos_prueba.csv`

4. El programa cargará los procesos automáticamente

## Validaciones Implementadas

✅ Archivo existe y se puede abrir  
✅ Formato CSV correcto (4 columnas)  
✅ Conversión de strings a números válida  
✅ Tiempo de llegada >= 0  
✅ Tiempo de ráfaga > 0  
✅ Al menos un proceso válido en el archivo  
✅ Manejo de líneas vacías  
✅ Mensajes de error descriptivos  

## Características de Robustez

- **Manejo de excepciones**: Try-catch para todos los posibles errores
- **Validación estricta**: Verifica tipos de datos y rangos
- **Feedback al usuario**: Mensajes claros indicando número de línea con error
- **Limpieza de recursos**: Cierre correcto de archivos incluso en caso de error
- **Confirmación de carga**: Muestra cantidad de procesos cargados exitosamente

## Ejemplo de Salida Exitosa

```
SIMULADOR DE PLANIFICACION

Cual va a ser la entrada de datos:
1. Manual
2. Archivo
Opcion: 2
Ingresa el nombre del archivo (ej: procesos_prueba.csv): procesos_prueba.csv
Se cargaron exitosamente 5 procesos desde el archivo.
```

## Ejemplo de Salida con Error

```
Opcion: 2
Ingresa el nombre del archivo (ej: procesos_prueba.csv): datos.csv
ERROR: No se pudo abrir el archivo 'datos.csv'

No se pudieron cargar los procesos. El programa terminará.
```

## Notas Técnicas

- **Standard**: C++17
- **Encoding**: Los archivos CSV deben usar UTF-8 o ASCII
- **Separador**: Coma (,)
- **Sin espacios**: Los valores no deben contener espacios adicionales
- **Sin encabezado**: El CSV no debe tener línea de encabezado
