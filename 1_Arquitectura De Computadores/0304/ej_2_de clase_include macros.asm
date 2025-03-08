Datos Segment  ; declaración del segmento de datos
    tecla  db  11111111b
    tecla2 db  0ffh
    tecla3  db  255d
    tecla4  db  377o


    numeroLineas EQU 24
    negro    EQU 0
    azul     EQU 1
    verde    EQU 2
    rojo     EQU 4
    amarillo EQU 0Eh
    blanco   EQU 0Fh



Datos Ends
; -------------------------------------------

Codigo Segment  ; declaración del segmento de código
    Assume CS:Codigo, DS:Datos

inicio:
    IniciaDatos datos

    mov ah, tecla1
    mov al, offset tecla4


    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79  ; Borra la pantalla con color amarillo

    gotoXY 0,0  ; Coloca el cursor en la posición (0,0)

    LeerCaracter tecla   ; Espera y almacena un carácter en tecla
    LeerCaracter tecla2  ; Espera y almacena otro carácter en tecla2
    mov ah, 87h         ; Configuración especial (significado depende del contexto)
    LeerCaracter ah     ; Lee un carácter en el registro AH

    FinProgra

Codigo Ends
End inicio
