include macros.asm

Datos Segment    ; declaración del segmento de datos.
    tecla1  db  11111111b ;ff = 255
    tecla2  db  0feh      ;fe = 254
    tecla3  db  253d,0fh  ;fd, fc = 253, 15
    tecla4  db  0fd07h
    tecla5  dw  00ffh
    tecla6  dw  0ff00h
    tecla7  dw  1112h
    tecla8  dw  1,3322h
    tecla9  db  374o

    CaracterLeido db ?

    dividendo dw 7
    divisor   dw 2
    cociente  dw ?
    residuo   dw ?

    numerolineas EQU 24
    negro        EQU 0
    azul         EQU 1
    verde        EQU 2
    rojo         EQU 4
    amarillo     EQU 0eh
    blanco       EQU 0fh
Datos Ends
; --------------------------------------------

Codigo Segment    ; declaración del segmento de código.
Assume CS:Codigo, DS:Datos
; acá van los procedimientos...

LeerCaracterP1 Proc Near
    mov ah, 01h
    int 21h
    mov CaracterLeido, al
    ret 
LeerCaracterP1 EndP

LeerCaracterP2 Proc Far
    mov ah, 01h
    int 21h
    mov CaracterLeido, al
    retF
LeerCaracterP2 EndP

; hasta acá van los procedimientos...

inicio:
    IniciaDatos datos 


    call LeerCaracterP1
    call LeerCaracterP4

    xor bx, bx
    mov bx, offset tecla2
    mov ax, bx

    mov ax, [bx]
    mov ax, [bx + 2]

    add bx, 2
    mov ax, [bx]

    xor ax, ax
    mov ax, 2[bx] ; bx * 2 pero sin alterar el valor de bx

    divida bx, divisor, bx, residuo  ; bx = 3, divisor = 2
    xor ax, ax
    mov ax, Byte ptr [bx]

    divida dividendo, divisor, cociente, residuo
    jmp short salte 

LeerCaracterP4 Proc
    mov ah, 01h
    int 21h
    mov CaracterLeido, al
    ret
LeerCaracterP4 EndP

salte:
    xor bx, bx
    mov bl, offset tecla1
    xor bl, bl
    mov Word ptr [bx], 0cffch
    mov al, tecla1
    mov ah, tecla2

    call LeerCaracterP4

    mov bx, 0ffffh
    mov Byte ptr [bx], 77h
    inc bx
    mov Byte ptr [bx], 07h

    mov bx, offset tecla1
    dec bx
    mov Byte ptr [bx], 66h ;mov Byte ptr [bx-2*6/4+1], 66h

    mov ah, tecla1
    mov al, offset tecla4
    add al, 1
    inc al
    mov al, offset tecla5
    mov al, Byte Ptr tecla5 ; al = ff
    mov al, Byte Ptr tecla6 ; al = 00
    mov al, Byte Ptr tecla7 ; al = 12h

    xor bx, bx
    mov bl, offset tecla7  ; procedimiento para obtener el byte más significativo de una variable dw
    inc bl
    mov al, byte ptr [bx]

    mov bx, tecla7
    shr bx, 8
    mov al, bl  ; al = 11h

    mov ax, tecla4

    LimpiarPantalla numerolineas, amarillo, 0, 0, 24, 79
    gotoXY 0,0

    LeerCaracter tecla1
    LeerCaracter tecla2
    mov ah, 87h
    LeerCaracter ah

    FinProgra

; acá van los procedimientos...

LeerCaracterP3 Proc
    mov ah, 01h
    int 21h
    mov CaracterLeido, al
    ret
LeerCaracterP3 EndP

; hasta acá van los procedimientos...
Codigo Ends
    End inicio
