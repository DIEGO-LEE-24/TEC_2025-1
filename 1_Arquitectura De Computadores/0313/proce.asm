Procedimientos Segment
 public LeerCaracter

 LeerCaracter proc
       mov bp, sp
       int 21h
       mov Byte ptr 4 bp,al
       mov Byte ptr 6[bp],al
       retF                   ;cuando termina el registro el contiene el caracter leido....
 LeerCaracter Endp

 codigo Ends    
        End