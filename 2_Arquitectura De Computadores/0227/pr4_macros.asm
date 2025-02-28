; ================================
; macros.asm - Librería de Macros
; ================================

; Macro para inicializar DS con un segmento dado
IniciaDS Macro NombreSegmento
    push ax
    xor ax, ax         ; Limpia AX (equivalente a mov ax, 0)
    mov ax, NombreSegmento
    mov ds, ax         ; DS apunta al segmento especificado
    pop ax
EndM

; Macro para leer un carácter del teclado y almacenarlo en una variable
LeerCaracter Macro CaracterLeido
    mov ah, 01h        ; AH = 01h: espera la pulsación de una tecla
    int 21h            ; Llama a la interrupción 21h
    mov CaracterLeido, al  ; Almacena el carácter leído en la variable pasada
EndM

; Macro para limpiar la pantalla o una parte de ella utilizando INT 10h
LimpiarPantalla Macro numeroLineas, TextColor, filaSuperior, columnaSuperior, filaInferior, columnaInferior
    mov ah, 06h
    mov al, numeroLineas   ; Número de líneas a desplazar (0 borra toda el área)
    mov bh, TextColor      ; Color de fondo y atributos del texto
    mov ch, filaSuperior   ; Fila superior del área a limpiar
    mov cl, columnaSuperior; Columna superior
    mov dh, filaInferior   ; Fila inferior
    mov dl, columnaInferior; Columna inferior
    int 10h
EndM

; Macro para finalizar el programa correctamente en DOS
FinProgra Macro
    mov ax, 4c00h
    int 21h
EndM
