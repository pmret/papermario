.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80266FD8
/* 1958B8 80266FD8 8C820094 */  lw    $v0, 0x94($a0)
/* 1958BC 80266FDC 1040000C */  beqz  $v0, .L80267010
/* 1958C0 80266FE0 00000000 */   nop   
/* 1958C4 80266FE4 8C820000 */  lw    $v0, ($a0)
/* 1958C8 80266FE8 30420002 */  andi  $v0, $v0, 2
/* 1958CC 80266FEC 14400008 */  bnez  $v0, .L80267010
/* 1958D0 80266FF0 00000000 */   nop   
/* 1958D4 80266FF4 8C8400C0 */  lw    $a0, 0xc0($a0)
/* 1958D8 80266FF8 80820764 */  lb    $v0, 0x764($a0)
/* 1958DC 80266FFC 10450004 */  beq   $v0, $a1, .L80267010
/* 1958E0 80267000 24020001 */   addiu $v0, $zero, 1
/* 1958E4 80267004 A0850764 */  sb    $a1, 0x764($a0)
/* 1958E8 80267008 A0800766 */  sb    $zero, 0x766($a0)
/* 1958EC 8026700C A0820765 */  sb    $v0, 0x765($a0)
.L80267010:
/* 1958F0 80267010 03E00008 */  jr    $ra
/* 1958F4 80267014 00000000 */   nop   

