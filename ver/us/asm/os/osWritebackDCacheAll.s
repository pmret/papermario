.include "macro.inc"

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .text, "ax"

glabel osWritebackDCacheAll
    lui       $t0, 0x8000
    addiu     $t2, $zero, 0x2000
    addu      $t1, $t0, $t2
    addiu     $t1, $t1, -0x10
.L800618E0:
    cache     1, ($t0)
    sltu      $at, $t0, $t1
    bnez      $at, .L800618E0
       addiu    $t0, $t0, 0x10
      jr        $ra
