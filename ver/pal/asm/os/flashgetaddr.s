.include "macro.inc"

/* assembler directives */
.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */
.set gp=64     /* allow use of 64-bit general purpose registers */

.section .text, "ax"

/* Generated by spimdisasm 1.11.5 */

glabel func_PAL_8006C6D0
/* 47AD0 8006C6D0 3C028009 */  lui       $v0, %hi(D_80096990)
/* 47AD4 8006C6D4 8C426990 */  lw        $v0, %lo(D_80096990)($v0)
/* 47AD8 8006C6D8 14400002 */  bnez      $v0, .LPAL_8006C6E4
/* 47ADC 8006C6DC 000411C0 */   sll      $v0, $a0, 7
/* 47AE0 8006C6E0 00041180 */  sll       $v0, $a0, 6
.LPAL_8006C6E4:
/* 47AE4 8006C6E4 03E00008 */  jr        $ra
/* 47AE8 8006C6E8 00000000 */   nop
/* 47AEC 8006C6EC 00000000 */  nop