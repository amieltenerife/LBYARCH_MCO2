section .data
sdot dq 0

section .text
bits 64
default rel
global dotprod

dotprod:
    movsd xmm0, [sdot]
    L1:
        movsd xmm2, qword [rdx]
        movsd xmm3, qword [r8]
        mulsd xmm2, xmm3
        addsd xmm0, xmm2
        add rdx, 8
        add r8, 8
        loop L1
    ret