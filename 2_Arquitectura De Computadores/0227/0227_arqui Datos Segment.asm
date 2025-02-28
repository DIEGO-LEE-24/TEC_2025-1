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
    IniciaDatos datos  ; Inicializa DS con el segmento de datos "Datos"

    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79  ; Borra toda la pantalla con amarillo

    mov ah, 02h
    xor bh, bh       ; Página de memoria activa = 0
    xor dx, dx       ; Pone la fila y la columna en 0.
    int 10h

    LeerCaracter tecla
    LeerCaracter tecla2
    mov ah, 87h
    LeerCaracter ah

    FinProgra

Codigo Ends
End inicio