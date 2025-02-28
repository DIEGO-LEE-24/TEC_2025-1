IniciaDS Macro NombreSegmento
    push ax
    xor ax, ax         ; mov ax, 0  → ax = 0
    mov ax, NombreSegmento
    mov ds, ax
    pop ax
EndM

LeerCaracter Macro CaracterLeido
    mov ah, 01h
    int 21h
    mov CaracterLeido, al
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

FinProgra Macro
    mov ax, 4c00h
    int 21h
EndM
