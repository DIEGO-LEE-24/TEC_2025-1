@echo off
tasm /zi /l /w0 %1 > c:\error.txt
tasm /zi /l /w0 %2 > c:\error1.txt
IF not EXIST c:\%1.obj GOTO error
 IF EXIST c:\%2.obj GOTO fin
:error
    echo se produjo un error mire el archivo ERROR.TXT o ERROR1.TXT
    goto salir
:fin
    tlink /v %1 + %2
    td %1 %3 %4 %5 %6 %7 %8 %9
:salir