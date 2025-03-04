include macros.asm

Datos Segment  ; Declaración del segmento de datos
    numeroLineas EQU 24
    negro   EQU 0
    azul    EQU 1
    verde   EQU 2
    rojo    EQU 4
    amarillo EQU 0Eh
    blanco  EQU 0Fh

    tecla  db ?
    tecla2 db ?
Datos Ends
; -----------------------------------------------------

Codigo Segment  ; Declaración del segmento de código
    Assume CS:Codigo, DS:Datos

inicio:
    ; Inicializa DS con el segmento de datos "Datos" usando el macro IniciaDS
    IniciaDS datos

    ; Limpia toda la pantalla con el color amarillo usando el macro LimpiarPantalla
    ; Parámetros: (número de líneas, color, fila superior, columna superior, fila inferior, columna inferior)
    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79

    ; Mueve el cursor a la posición (0,0) (esto se hace de forma directa, no mediante macro)
    mov ah, 02h
    xor bh, bh       ; Página de memoria activa = 0
    xor dx, dx       ; Establece DH=0 y DL=0, es decir, la posición (0,0)
    int 10h

    ; Lee dos caracteres del teclado y los almacena en las variables tecla y tecla2
    LeerCaracter tecla
    LeerCaracter tecla2

    ; Se carga AH con 87h y se lee otro carácter (según la lógica del programa)
    mov ah, 87h
    LeerCaracter ah

    ; Finaliza el programa usando el macro FinProgra
    FinProgra

Codigo Ends
End inicio
