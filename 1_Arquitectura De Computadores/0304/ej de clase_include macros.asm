include macros.asm

Datos Segment  ; declaración del segmento de datos
    numeroLineas EQU 24
    negro    EQU 0
    azul     EQU 1
    verde    EQU 2
    rojo     EQU 4
    amarillo EQU 0Eh
    blanco   EQU 0Fh

    tecla  db ?
    tecla2 db ?
Datos Ends
; -------------------------------------------

Codigo Segment  ; declaración del segmento de código
    Assume CS:Codigo, DS:Datos

inicio:
    stc         ; Set carry flag (CF = 1)
    ;jc salteaqui  ; Jump if carry flag is set (CF = 1)
    jc puente1


    IniciaDatos datos  ; Inicializa el segmento de datos DS

    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79  ; Borra toda la pantalla con color amarillo




    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79
    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79
    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79
    LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79
    jmp saltepuente

puente1:
    jmp salteaqui
;LimpiarPantalla numeroLineas, amarillo, 0, 0, 24, 79

    gotoXY 0,0  ; Coloca el cursor en la posición (0,0)

    LeerCaracter tecla   ; Espera y almacena un carácter en tecla
    LeerCaracter tecla2  ; Espera y almacena otro carácter en tecla2
    mov ah, 87h         ; Configuración especial (significado depende del contexto)
    LeerCaracter ah     ; Lee un carácter en el registro AH

salteaqui:
    FinProgra  ; Termina el programa

Codigo Ends
End inicio
