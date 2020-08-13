.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8002C324
/* 007724 8002C324 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 007728 8002C328 AFB10014 */  sw    $s1, 0x14($sp)
/* 00772C 8002C32C 0080882D */  daddu $s1, $a0, $zero
/* 007730 8002C330 AFB00010 */  sw    $s0, 0x10($sp)
/* 007734 8002C334 3C100002 */  lui   $s0, 2
/* 007738 8002C338 2404001E */  addiu $a0, $zero, 0x1e
/* 00773C 8002C33C 2405009B */  addiu $a1, $zero, 0x9b
/* 007740 8002C340 3C06800A */  lui   $a2, 0x800a
/* 007744 8002C344 24C68050 */  addiu $a2, $a2, -0x7fb0
/* 007748 8002C348 AFBF0018 */  sw    $ra, 0x18($sp)
/* 00774C 8002C34C 0C00B082 */  jal   crash_printf_string
/* 007750 8002C350 0220382D */   daddu $a3, $s1, $zero
/* 007754 8002C354 0000182D */  daddu $v1, $zero, $zero
/* 007758 8002C358 3C078007 */  lui   $a3, 0x8007
/* 00775C 8002C35C 24E773D8 */  addiu $a3, $a3, 0x73d8
.L8002C360:
/* 007760 8002C360 02301024 */  and   $v0, $s1, $s0
/* 007764 8002C364 50400009 */  beql  $v0, $zero, .L8002C38C
/* 007768 8002C368 24E70004 */   addiu $a3, $a3, 4
/* 00776C 8002C36C 24040084 */  addiu $a0, $zero, 0x84
/* 007770 8002C370 8CE70000 */  lw    $a3, ($a3)
/* 007774 8002C374 3C06800A */  lui   $a2, 0x800a
/* 007778 8002C378 24C6805C */  addiu $a2, $a2, -0x7fa4
/* 00777C 8002C37C 0C00B082 */  jal   crash_printf_string
/* 007780 8002C380 2405009B */   addiu $a1, $zero, 0x9b
/* 007784 8002C384 0800B0E7 */  j     .L8002C39C
/* 007788 8002C388 00000000 */   nop   

.L8002C38C:
/* 00778C 8002C38C 24630001 */  addiu $v1, $v1, 1
/* 007790 8002C390 28620006 */  slti  $v0, $v1, 6
/* 007794 8002C394 1440FFF2 */  bnez  $v0, .L8002C360
/* 007798 8002C398 00108042 */   srl   $s0, $s0, 1
.L8002C39C:
/* 00779C 8002C39C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0077A0 8002C3A0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0077A4 8002C3A4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0077A8 8002C3A8 03E00008 */  jr    $ra
/* 0077AC 8002C3AC 27BD0020 */   addiu $sp, $sp, 0x20

