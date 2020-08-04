.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80072BDC
/* 04DFDC 80072BDC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04DFE0 80072BE0 3C02800E */  lui   $v0, 0x800e
/* 04DFE4 80072BE4 9042C4EA */  lbu   $v0, -0x3b16($v0)
/* 04DFE8 80072BE8 3C038009 */  lui   $v1, 0x8009
/* 04DFEC 80072BEC 24635A30 */  addiu $v1, $v1, 0x5a30
/* 04DFF0 80072BF0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 04DFF4 80072BF4 AFB10014 */  sw    $s1, 0x14($sp)
/* 04DFF8 80072BF8 AFB00010 */  sw    $s0, 0x10($sp)
/* 04DFFC 80072BFC 00021140 */  sll   $v0, $v0, 5
/* 04E000 80072C00 00438821 */  addu  $s1, $v0, $v1
/* 04E004 80072C04 8E240004 */  lw    $a0, 4($s1)
/* 04E008 80072C08 8E250008 */  lw    $a1, 8($s1)
/* 04E00C 80072C0C 8E26000C */  lw    $a2, 0xc($s1)
/* 04E010 80072C10 3C10800E */  lui   $s0, 0x800e
/* 04E014 80072C14 9210C4EB */  lbu   $s0, -0x3b15($s0)
/* 04E018 80072C18 0C00A5CF */  jal   dma_copy
/* 04E01C 80072C1C 00000000 */   nop   
/* 04E020 80072C20 00101880 */  sll   $v1, $s0, 2
/* 04E024 80072C24 00701821 */  addu  $v1, $v1, $s0
/* 04E028 80072C28 00031880 */  sll   $v1, $v1, 2
/* 04E02C 80072C2C 8E220010 */  lw    $v0, 0x10($s1)
/* 04E030 80072C30 3C04800E */  lui   $a0, 0x800e
/* 04E034 80072C34 8C84C4EC */  lw    $a0, -0x3b14($a0)
/* 04E038 80072C38 00431021 */  addu  $v0, $v0, $v1
/* 04E03C 80072C3C 3C01800E */  lui   $at, 0x800e
/* 04E040 80072C40 AC22C4FC */  sw    $v0, -0x3b04($at)
/* 04E044 80072C44 04810005 */  bgez  $a0, .L80072C5C
/* 04E048 80072C48 000418C0 */   sll   $v1, $a0, 3
/* 04E04C 80072C4C 3C01800E */  lui   $at, 0x800e
/* 04E050 80072C50 AC20C064 */  sw    $zero, -0x3f9c($at)
/* 04E054 80072C54 0801CB1B */  j     .L80072C6C
/* 04E058 80072C58 00000000 */   nop   

.L80072C5C:
/* 04E05C 80072C5C 8E220014 */  lw    $v0, 0x14($s1)
/* 04E060 80072C60 00431021 */  addu  $v0, $v0, $v1
/* 04E064 80072C64 3C01800E */  lui   $at, 0x800e
/* 04E068 80072C68 AC22C064 */  sw    $v0, -0x3f9c($at)
.L80072C6C:
/* 04E06C 80072C6C 0C090464 */  jal   func_80241190
/* 04E070 80072C70 24040001 */   addiu $a0, $zero, 1
/* 04E074 80072C74 8FBF0018 */  lw    $ra, 0x18($sp)
/* 04E078 80072C78 8FB10014 */  lw    $s1, 0x14($sp)
/* 04E07C 80072C7C 8FB00010 */  lw    $s0, 0x10($sp)
/* 04E080 80072C80 3C01800E */  lui   $at, 0x800e
/* 04E084 80072C84 AC20C4D0 */  sw    $zero, -0x3b30($at)
/* 04E088 80072C88 03E00008 */  jr    $ra
/* 04E08C 80072C8C 27BD0020 */   addiu $sp, $sp, 0x20

