Datos Segment
    tecla db ?  
Datos Ends

Codigo Segment
    Assume CS:Codigo, DS:Datos  ; Declaración del segmento de código

inicio:
    xor ax, ax
    mov ax, datos
    mov ds, ax  ; Inicializa el segmento de datos

    ; Configuración de la pantalla
    mov ah, 06h
    mov al, 20
    mov bh, 04h
    mov ch, 0
    mov cl, 0
    mov dh, 20
    mov dl, 50
    int 10h  ; Llama a la interrupción 10h para limpiar la pantalla

    ; Leer un carácter desde el teclado
    mov ah, 01h
    int 21h  ; Espera la entrada de un carácter
    mov tecla, al  ; Guarda el carácter en la variable 'tecla'

    ; Finalizar el programa
    mov ax, 4c00h
    int 21h

Codigo Ends
End inicio
