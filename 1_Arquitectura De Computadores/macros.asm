IniciaDatos Macro NombreSegmento
    push ax
    xor ax, ax         ; mov ax, 0 → ax = 0
    mov ax, NombreSegmento
    mov ds, ax
    pop ax
EndM

divida Macro dividendo, divisor, cociente, residuo
    mov ax,dividendo
    div divisor
    mov cociente,ax
    mov residuo,dx
EndM

LeerCaracter Macro CaracterLeido
    mov ah, 01h
    int 21h
    mov CaracterLeido, al
    Local comienceAcA, vartemporal
    jmp comienceAcA

    vartemporal db ?

comienceAcA:
    mov ah, 01h
    int 21h
    mov vartemporal, al
    mov al, 0ffh
    mov bl, vartemporal
    mov CaracterLeido, bl
EndM

LimpiarPantalla Macro numeroLineas, TextColor, filaSuperior, columnaSuperior, filaInferior, columnaInferior
    mov ah, 06h
    mov al, numeroLineas
    mov bh, TextColor
    mov ch, filaSuperior
    mov cl, columnaSuperior
    mov dh, filaInferior
    mov dl, columnaInferior
    int 10h
EndM

GotoXY Macro fila, columna
    mov ah, 02h
    mov bh, 0         ; página de memoria activa = 0
    mov dh, fila      ; pone la fila en 0.
    mov dl, columna
    int 10h
EndM

FinProgra Macro
    mov ax, 4c00h
    int 21h
EndM
