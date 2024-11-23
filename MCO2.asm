section .text
bits 64
default rel
global dotprod

dotprod:
    L1:
        movsd xmm2, qword [rdx]
        movsd xmm3, qword [r8]
        mulsd xmm2, xmm3
        addsd xmm0, xmm2
        add rdx, 8
        add r8, 8
        loop L1
    ret