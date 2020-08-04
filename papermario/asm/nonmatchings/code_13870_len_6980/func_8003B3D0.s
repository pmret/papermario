.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003B3D0
/* 0167D0 8003B3D0 808200B4 */  lb    $v0, 0xb4($a0)
/* 0167D4 8003B3D4 908300B4 */  lbu   $v1, 0xb4($a0)
/* 0167D8 8003B3D8 10450005 */  beq   $v0, $a1, .L8003B3F0
/* 0167DC 8003B3DC 24020001 */   addiu $v0, $zero, 1
/* 0167E0 8003B3E0 A08300B5 */  sb    $v1, 0xb5($a0)
/* 0167E4 8003B3E4 A08500B4 */  sb    $a1, 0xb4($a0)
/* 0167E8 8003B3E8 A08000B7 */  sb    $zero, 0xb7($a0)
/* 0167EC 8003B3EC A08200B6 */  sb    $v0, 0xb6($a0)
.L8003B3F0:
/* 0167F0 8003B3F0 03E00008 */  jr    $ra
/* 0167F4 8003B3F4 00000000 */   nop   

/* 0167F8 8003B3F8 808200B4 */  lb    $v0, 0xb4($a0)
/* 0167FC 8003B3FC 908300B4 */  lbu   $v1, 0xb4($a0)
/* 016800 8003B400 10450005 */  beq   $v0, $a1, .L8003B418
/* 016804 8003B404 2402FFFF */   addiu $v0, $zero, -1
/* 016808 8003B408 A08300B5 */  sb    $v1, 0xb5($a0)
/* 01680C 8003B40C A08500B4 */  sb    $a1, 0xb4($a0)
/* 016810 8003B410 A08000B7 */  sb    $zero, 0xb7($a0)
/* 016814 8003B414 A08200B6 */  sb    $v0, 0xb6($a0)
.L8003B418:
/* 016818 8003B418 03E00008 */  jr    $ra
/* 01681C 8003B41C 00000000 */   nop   

/* 016820 8003B420 808200B5 */  lb    $v0, 0xb5($a0)
/* 016824 8003B424 908300B5 */  lbu   $v1, 0xb5($a0)
/* 016828 8003B428 14400003 */  bnez  $v0, .L8003B438
/* 01682C 8003B42C 24020001 */   addiu $v0, $zero, 1
/* 016830 8003B430 03E00008 */  jr    $ra
/* 016834 8003B434 A08000B4 */   sb    $zero, 0xb4($a0)

.L8003B438:
/* 016838 8003B438 A08300B4 */  sb    $v1, 0xb4($a0)
/* 01683C 8003B43C A08000B5 */  sb    $zero, 0xb5($a0)
/* 016840 8003B440 A08000B7 */  sb    $zero, 0xb7($a0)
/* 016844 8003B444 03E00008 */  jr    $ra
/* 016848 8003B448 A08200B6 */   sb    $v0, 0xb6($a0)

