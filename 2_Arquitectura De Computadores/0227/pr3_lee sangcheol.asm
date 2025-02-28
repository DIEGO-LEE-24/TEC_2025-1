Datos Segment
    tecla db ?               ; declaración del segmento de datos
Datos Ends
; -----------------------------------------------------

Codigo Segment
    Assume CS:Codigo, DS:Datos  ; declaración del segmento de código.

inicio:
    ; Inicializar el segmento de datos en DS
    mov ax, 0
    mov ds, ax

    ; (Opcional) Configuración del "color del texto" o pantalla
    ; A continuación se muestran registros que podrían usarse para
    ; manipular la pantalla con int 10h, pero la lógica exacta depende
    ; de lo que se desee hacer (parte no totalmente clara en la captura).
    mov ah, 0bh
    mov bh, 0fh
    mov ah, 0eh
    mov al, 24
    mov ch, 0
    mov cl, 24
    mov dh, 0
    mov dl, 50
    int 10h

    ; Pone la fila y la columna en 0
    mov ah, 02h       ; Función de BIOS para mover el cursor
    xor bh, bh        ; BH = 0 (página 0)
    xor dx, dx        ; DX = 0 -> DH=0, DL=0 (cursor a (0,0))
    int 10h

    ; Espera una tecla y la guarda en 'tecla'
    mov ah, 01h
    int 21h
    mov tecla, al

    ; Termina el programa
    mov ax, 4c00h
    int 21h

Codigo Ends
End inicio
