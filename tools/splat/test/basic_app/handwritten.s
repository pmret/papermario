.section .text
.balign 16
.set noreorder

.global asm_func
.type asm_func, @function
.ent asm_func
asm_func:
    add $v0, $a0, $a1 # Instruction that a compiler will never emit
    jr $ra
     nop
.end asm_func
