Datos Segment      ; 데이터 세그먼트 선언
Datos EndS

Codigo Segment     ; 코드 세그먼트 선언
Assume CS:Codigo, DS:Datos

inicio:
    mov al, 10d    ; AL에 10 (십진수) 저장
    mov ah, 10     ; AH에 10 저장
    mov bl, 0ah    ; BL에 0A (16진수, 10) 저장
    mov bh, 1010b  ; BH에 1010 (2진수, 10) 저장

    mov ax, SEG Datos  ; AX에 'Datos' 세그먼트 주소 로드
    mov ds, ax         ; DS에 AX 값을 로드

    ; 여기에서 추가 코드를 작성할 수 있음

Codigo EndS
End Inicio

#2
;------------------------------------------
; 본 코드는 8086 어셈블리어로 작성되었으며,
; 데이터 세그먼트(DS)와 코드 세그먼트(CS)를 설정한 뒤
; DS를 통해 데이터를 접근할 수 있도록 준비하는 예제입니다.
;------------------------------------------

Datos Segment       ; (1) 데이터 세그먼트 선언
Datos EndS          ;     데이터 세그먼트의 끝

Codigo Segment      ; (2) 코드 세그먼트 선언
Assume CS:Codigo, DS:Datos  ; 어셈블러에게 "코드 세그먼트 = Codigo, 데이터 세그먼트 = Datos" 로 설정한다고 알림

inicio:             ; (3) 프로그램 시작 지점 (Entry Point)
    xor ax, ax      ; AX 레지스터를 0으로 초기화 (mov ax, 0과 동일)
    mov ax, Datos   ; 데이터 세그먼트 주소를 AX 레지스터에 로드
    mov ds, ax      ; DS 레지스터에 AX값을 대입 → DS가 'Datos' 세그먼트를 가리키게 됨

    ; (4) 여기서부터 필요한 명령어(코드)를 추가로 작성할 수 있음

Codigo EndS         ; (5) 코드 세그먼트의 끝
End Inicio          ; (6) 'inicio' 라벨에서 프로그램 시작



#3
Datos Segment       ; (1) 데이터 세그먼트 선언
Datos EndS          ;     데이터 세그먼트 끝

Codigo Segment      ; (2) 코드 세그먼트 선언
Assume CS:Codigo, DS:Datos  ; 어셈블러에게 CS=Codigo, DS=Datos로 지정

inicio:             ; (3) 프로그램 시작 위치(라벨)
    mov ax, 0cbah   ; AX 레지스터에 0CBAh 저장
    xor ax, ax      ; AX 레지스터를 0으로 만듦 (즉, 위 명령은 덮어씌워짐)
    mov ax, Datos   ; AX에 'Datos' 세그먼트의 주소 로드
    mov ds, ax      ; DS 레지스터를 AX 값으로 설정 → DS가 'Datos' 세그먼트를 가리킴

    ; (4) 여기서부터 원하는 명령어를 추가 작성 가능

Codigo EndS         ; (5) 코드 세그먼트 끝
End Inicio          ; (6) 'inicio'에서 프로그램 시작


#4
Datos Segment          ; (1) 데이터 세그먼트 선언
Datos EndS

Codigo Segment         ; (2) 코드 세그먼트 선언
Assume CS:Codigo, DS:Datos  ; 어셈블러에게 "코드 세그먼트 = Codigo, 데이터 세그먼트 = Datos"라고 지정

inicio:                ; (3) 프로그램 시작 지점(Entry Point)
    xor ax, ax         ; (4) AX 레지스터를 0으로 초기화 (mov ax, 0과 동일)
    mov ax, Datos      ; (5) 'Datos' 세그먼트 주소를 AX에 로드
    mov ds, ax         ; (6) DS 레지스터에 AX 값을 대입 → DS가 'Datos' 세그먼트를 가리킴

    ; (7) 여기서부터 필요한 코드를 추가로 작성할 수 있음
    ; 예: 변수를 선언하고 DS를 통해 접근하는 로직 등

    mov ax, 4C00h      ; (8) AX에 4C00h 저장 → DOS 인터럽트 21h의 프로그램 종료 함수(4Ch) 사용
    int 21h            ; (9) 인터럽트 호출 → 프로그램 종료(종료 코드 0)

Codigo EndS
End Inicio             ; (10) 'inicio' 레이블에서 프로그램 시작
