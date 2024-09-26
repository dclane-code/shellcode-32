

global _start
section .text
bits 32

_start:

;   execve("/bin/sh", ["/bin/sh",0], 0)
;             ebx         ecx       edx

    jmp bottom
top:
    pop eax
    xor edx, edx
    push edx
;    lea ebx, [eax]
    mov ebx, eax
    push ebx
    mov ecx, esp
    mov eax, 0xb
    int 0x80
    
bottom:
    call top
    db '/bin/sh',0
    
