Dependencias

Este proyecto depende de las siguientes bibliotecas:

   Qt5 (Widgets y Charts)
   CMake para la configuración del proyecto

Instalación de Dependencias en Ubuntu/Debian

  Para instalar las dependencias necesarias en Ubuntu/Debian, ejecuta los siguientes comandos en la terminal:
  
    sudo apt update
    sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools libqt5charts5-dev cmake g++


Instalación de Dependencias en Windows

  Instala Qt Creator asegurandose de instalar el módulo Qt5 y QtCharts durante la instalación.

  Instala CMake desde el sitio oficial de CMake.


Compilación e Instalación

  En Ubuntu/Debian

   Clona el repositorio o copia los archivos del proyecto en un directorio.

   Crea un directorio de compilación dentro del proyecto:
  
  En la terminal

    mkdir build
    cd build

  Ejecuta CMake para generar los archivos de construcción:

    cmake ..
    
  Compila el proyecto:

    make

  Ejecuta el programa:

    ./GraficarResultados

En Windows

  Clona el repositorio o copia los archivos del proyecto en un directorio de tu preferencia.

  Abre Qt Creator y selecciona la opción para abrir un proyecto existente (Open Project), luego selecciona el archivo CMakeLists.txt.

  Configura el compilador y el kit de Qt:
      En Qt Creator, selecciona el kit apropiado (como MinGW o MSVC con soporte para QtCharts).

  Ejecuta el proyecto:
      Desde Qt Creator, compila el proyecto
      Luego ejecuta el programa


Descripción del Código

  main.cpp: El archivo principal del programa. Contiene la lógica para generar los arreglos de prueba, medir los tiempos de ejecución de los algoritmos de ordenamiento, y graficar los resultados utilizando QtCharts.

  generateCases.cpp: Contiene funciones para generar los diferentes casos de prueba (mejor, promedio, y peor).

  times.cpp: Incluye las implementaciones de los algoritmos de ordenamiento y funciones para medir su tiempo de ejecución.

  guardarResultados.cpp: Contiene la logica para guardar los tiempos obtenidos en un archivo .txt

  ordenamiento.cpp: Contiene los metodos de ordenamiento

Uso del Programa

  El programa primero generará arreglos con los diferentes tamaños de N y ejecutará los algoritmos de ordenamiento.
  Medirá el tiempo que tarda cada algoritmo en ordenar los arreglos en tres casos diferentes (mejor, promedio y peor).
  Los resultados se guardan en un archivo Resultados.txt.
  El programa leerá este archivo para graficar los tiempos de ejecución de cada algoritmo para los tres casos mencionados, mostrando una ventana con las gráficas.

Resultados Esperados

El programa generará tres gráficas:
    
   BubbleSort - Todos los Casos
   SelectionSort - Todos los Casos
   MergeSort - Todos los Casos

Cada gráfica mostrará el tiempo de ejecución de cada algoritmo para los tres casos:

   Mejor caso
   Caso promedio
   Peor caso

El eje X representará el tamaño de la entrada N, y el eje Y representará el tiempo de ejecución en segundos.

PD: Tomar en cuenta que el codigo debe de crear arreglos grnades para luego crearlos, tomando esto en cuenta la espera aproximada para obtener resultados es de 30s
