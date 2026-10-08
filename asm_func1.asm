; Windows x64 calling convention
;   rcx = const double* in
;   rdx = double* out
;   r8d = int size (element count)
;
; void asm_func(const double* in, double* out, int size);

global asm_func

section .data
    ; TODO: constants, if any

section .text
asm_func:
    ; TODO: prologue (save callee-saved registers / allocate stack if needed)

    movsxd r8, r8d              ; sign-extend the 32-bit int size into r8
    xor    rax, rax             ; loop index / offset

    ; TODO: setup before loop (bounds, constants, broadcast, etc.)

.loop:
    cmp    rax, r8              ; TODO: bound compare must match the units of rax
    jge    .done

    ; TODO: load
    ; TODO: operate
    ; TODO: store

    ; TODO: advance rax by the amount processed per iteration
    jmp    .loop

.done:
    ; TODO: epilogue (restore registers, vzeroupper if using ymm)
    ret
