include macros.asm           ; Incluir las macros definidas (IniciaDatos, divida, etc.)

Datos Segment                ; Segmento de datos
    tecla1          db  11111111b    ; 0FFh = 255
    tecla2          db  0FEh         ; 0FEh = 254
    tecla3          db  253d, 0Fh    ; FD, FC = 253, 15
    tecla4          dw  0FD07h
    tecla5          dw  00FFh
    tecla6          dw  0FF00h
    tecla7          dw  1h, 1112h
    tecla8          db  1, 3322h
    tecla9          db  374o
    CaracterLeido   db ?


    divisor   dw 2           ; Valor del divisor
    dividendo dw 10          ; Valor del dividendo
    cociente  dw ?           ; Para almacenar el cociente
    residuo   dw ?           ; Para almacenar el residuo

    numerolineas EQU 24
    negro        EQU 0
    azul         EQU 1
    verde        EQU 2
    rojo         EQU 4
    amarillo     EQU 0Eh
    blanco       EQU 0Fh
Datos Ends

Codigo Segment               ; Segmento de código
Assume CS:Codigo, DS:Datos
;aca van los procedimientos....

LeerCaracterP1 Proc near far 
 mov,ah,01h
 int 21h
 mov CaracterLeido,al
LeerCaracter P1 EndP

LeerCaracterP2 Proc near far 
 mov,ah,01h
 int 21h
 mov CaracterLeido,al
LeerCaracter P2 EndP

;hasta aca van los procedimientos...
   inicio:
    ; --------------------------------------------------------
    ; 1) Inicializar el segmento de datos
    IniciaDatos datos

    ; --------------------------------------------------------
    ; 2) Ejemplo de operaciones con BX y AX para ilustrar acceso a memoria
    xor bx, bx
    mov bx, offset tecla2      ; BX apunta a 'tecla2'
    mov ax, [bx]               ; AX = palabra en DS:[BX]
    mov ax, [bx + 2]           ; AX = palabra en DS:[BX + 2]
    add bx, 2
    xor ax, ax
    mov ax, 2[bx]              ; Equivalente a mov ax, [bx + 2]

    ; --------------------------------------------------------
    ; 3) Uso de la macro divida con parámetros (dividendo, divisor, cociente, residuo)
    ;    Aquí: 'bx' es el dividendo, 'divisor' la variable en datos,
    ;    'bx' guardará el cociente, 'residuo' en memoria.
    divida bx, divisor, bx, residuo ;bx = 3 divisor =2 3/2 = cociente = 1 resultado ax, y el residuo = 1 = dx.

    ; Se puede verificar el contenido de [bx]
    mov ah, Byte ptr [bx]

    ; --------------------------------------------------------
    ; 4) Otra división: 'dividendo' / 'divisor', guardando en 'cociente' y 'residuo'
    divida dividendo, divisor, cociente, residuo
    LeerCaracterP1 Proc near far 
     mov,ah,01h
     int 21h
    mov CaracterLeido,al
LeerCaracter P1 EndP
    ; --------------------------------------------------------
    ; 5) Más ejemplos de manipulación de memoria (como en la captura)
    mov Word ptr [bx], 0CFFCh  ; Escribir 0CFFCh en la dirección DS:[BX]
    mov al, tecla1            ; AL = 0FFh
    mov ah, tecla2            ; AH = 0FEh

    mov bx, 0FFFFh
    mov Byte ptr [bx], 77h    ; En DS:[0FFFFh] se escribe 77h
    inc bx
    mov Byte ptr [bx], 07h    ; En DS:[10000h] se escribe 07h (desbordamiento típico en modo real)

    mov bx, offset tecla1
    dec bx
    mov Byte ptr [bx], 66h    ; Escribir 66h justo antes de 'tecla1'
    ; mov Byte ptr [bx-2*6/4+1], 66h ; Ejemplo de cálculo en tiempo de ensamblado

    mov ah, tecla1            ; AH = 0FFh
    mov al, offset tecla4     ; AL = parte baja del offset de tecla4
    add al, 1
    inc al
    mov al, offset tecla5
    mov al, Byte Ptr tecla5   ; AL = FFh (byte bajo de tecla5)
    mov al, Byte Ptr tecla6   ; AL = 00h (byte bajo de tecla6)
    mov al, Byte Ptr tecla7 l ; AL = 12h (byte bajo de 1112h)

    xor bx, bx
    mov bl, offset tecla7
    inc bl
    mov al, byte ptr [bx]     ; AL = byte alto de tecla7 (depende de la organización)

    mov bx, tecla7
    shr bx, 8
    mov al, bl                ; AL = byte alto (11h si tecla7 = 1112h)

    mov ax, tecla4            ; AX = 0FD07h

    ; --------------------------------------------------------
    ; 6) Finalizar el programa con la macro FinProgra
    FinProgra
;aca van los procedimientos....

LeerCaracterP4 Proc near far 
 mov,ah,01h
 int 21h
 mov CaracterLeido,al
LeerCaracter LeerCaracterP4 EndP

;hasta aca van los procedimientos...
Codigo Ends
End inicio