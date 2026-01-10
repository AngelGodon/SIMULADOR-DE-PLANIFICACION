@echo off
REM Script de Compilación y Ejecución de Tests
REM Para Windows

echo ========================================
echo   SIMULADOR DE PLANIFICACION - TESTS
echo ========================================
echo.

:menu
echo Selecciona una opción:
echo [1] Compilar Test Runner
echo [2] Ejecutar Tests
echo [3] Compilar y Ejecutar Tests
echo [4] Compilar Interfaz Principal
echo [5] Ejecutar Interfaz Principal
echo [6] Compilar Todo
echo [0] Salir
echo.
set /p option="Opción: "

if "%option%"=="1" goto compile_tests
if "%option%"=="2" goto run_tests
if "%option%"=="3" goto compile_and_run_tests
if "%option%"=="4" goto compile_interface
if "%option%"=="5" goto run_interface
if "%option%"=="6" goto compile_all
if "%option%"=="0" goto end
goto menu

:compile_tests
echo.
echo [Compilando Test Runner...]
g++ -std=c++17 Utils\test_runner.cpp -o tester.exe
if errorlevel 1 (
    echo [ERROR] Falló la compilación
    pause
    goto menu
)
echo [OK] Test Runner compilado exitosamente: tester.exe
pause
goto menu

:run_tests
echo.
if not exist "tester.exe" (
    echo [ERROR] No existe tester.exe. Primero debes compilar.
    pause
    goto menu
)
echo [Ejecutando Tests...]
echo.
tester.exe
echo.
pause
goto menu

:compile_and_run_tests
call :compile_tests
if exist "tester.exe" (
    echo.
    call :run_tests
)
goto menu

:compile_interface
echo.
echo [Compilando Interfaz Principal...]
cd UI
g++ -std=c++17 interface.cpp -o simulador.exe
if errorlevel 1 (
    echo [ERROR] Falló la compilación
    cd ..
    pause
    goto menu
)
echo [OK] Interfaz compilada exitosamente: UI\simulador.exe
cd ..
pause
goto menu

:run_interface
echo.
if not exist "UI\simulador.exe" (
    echo [ERROR] No existe UI\simulador.exe. Primero debes compilar.
    pause
    goto menu
)
echo [Ejecutando Simulador...]
echo.
cd UI
simulador.exe
cd ..
pause
goto menu

:compile_all
echo.
echo [Compilando todos los módulos...]
call :compile_tests
call :compile_interface
echo.
echo [OK] Compilación completa
pause
goto menu

:end
echo.
echo Saliendo...
exit /b 0
