include macros.asm

Datos Segment    ; declaracion del segmento de datos.
    tecla1  db  11111111b
    tecla2  db  0feh
    tecla3  db  253d,0fh
    tecla4  db  0fd00h
    tecla5  dw  00ffh
    tecla6  dw  0ff00h
    tecla7  dw  1h, 1112h
    tecla8  db  1,3322h
    tecla9  db  374o

    numerolineas EQU 24
    negro        EQU 0
    azul         EQU 1
    verde        EQU 2
    rojo         EQU 4
    amarillo     EQU 0eh
    blanco       EQU 0fh
Datos Ends
; -----------------------------------------------------------------------------

Codigo Segment    ; declaracion del segmento de codigo.
Assume CS:Codigo, DS:Datos
inicio:
    IniciaDatos datos


    xor bx,bx
    mov bl,offset tecla1
    xor bl,bl 
    mov Word ptr p[bx], 0cffch
    mov al, tecla1
    mov ah, tecla2

    mov bx, 0ffffh
    mov Byte ptr [bx], 77h
    inc bx
    mov Byte ptr [bx], 07h

    mov bx,offset tecla1
    dec bx
    mov Byte ptr [bx],66h ;mov Byte ptr [bx-2*6/4+1],66h

    mov ah, tecla1
    mov al, offset tecla4
    add al, 1
    inc al
    mov al, offset tecla5
    mov al, Byte Ptr tecla5 ;al = ff
    mov al, Byte Ptr tecla6 ;al = 00
    mov al, Byte Ptr tecla7 l ;al = 12h

    
    xor bx,bx
    mov bl, offset tecla7  ; procedimiento para obtener el byte mas significativo de una variable dw
    inc bl
    mov al, byte ptr [bx]

    mov bx, tecla7
    shr bx,  8
    mov al,bl  ;al = 11h

    mov ax, tecla4

    LimpiarPantalla numerolineas, amarillo, 0, 0, 24, 79

    gotoXY 0,0

    LeerCaracter tecla1
    LeerCaracter tecla2
    mov ah,87h
    LeerCaracter ah

    FinProgra
Codigo  Ends
      End iniicio 


;vector [10] = [1,2,34,4]

;if i <= 0 and i > 9 then print ["error"];

  ;for i=i% i = 0 mod = 10
           ;i = 10 mod = 0
; ==================================================
; 📝 Resumen del manejo de memoria en Ensamblador
;📌Un byte está compuesto por 8 bits
;📌Una palabra (word) depende directamente de la arquitectura del procesador, y es la cantidad de bits que el procesador puede manejar (leer/escribir/procesar) en paralelo durante una operación.
    ;- Por ejemplo, en un procesador de 16 bits, una palabra son 16 bits (2 bytes).
    ;- En uno de 32 bits, una palabra es de 32 bits (4 bytes), y así sucesivamente

;📌 el decimal 1025 (que equivale a 0401H en hexadecimal)
    ;- 1024 decimal es exactamente 1 KB (Kilobyte)
    ;- 1025 requiere más de un byte porque excede 255, que es el máximo valor representable en 8 bits. Por lo tanto, requiere dos bytes para su almacenamiento

;📌Little Endian
    ;- En una arquitectura de 16 bits, una palabra está formada por dos bytes
    ;- Cada palabra tiene un byte alto (más significativo) y un byte bajo (menos significativo)
    ;- Por ejemplo, el número decimal 1025 equivale a 0401H en hexadecimal
       ;-04 → byte alto (más significativo)
       ;-01 → byte bajo (menos significativo)
    ;- En una arquitectura Little Endian, estos bytes se almacenan en memoria en orden inverso
        ;- Primero se almacena el byte menos significativo (01) en la dirección más baja (5612).
        ;- Luego se almacena el byte más significativo (04) en la dirección siguiente (5613).
    ;- cuando el procesador lea de memoria estas dos direcciones (5612 y 5613), reconstruirá correctamente la palabra original (0401H)
;📌Palabra original: 0401H
    ;- 04 → byte más significativo (orden alto).
    ;- 01 → byte menos significativo (orden bajo).
;📌Little Endian (Intel)
    ;-
;📌
;📌
;📌
;📌
;📌
;📌
;📌
; =======================================================