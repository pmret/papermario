.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80148040
/* 0DE740 80148040 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DE744 80148044 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0DE748 80148048 0C05203C */  jal   func_801480F0
/* 0DE74C 8014804C 00000000 */   nop   
/* 0DE750 80148050 0000202D */  daddu $a0, $zero, $zero
/* 0DE754 80148054 3C068015 */  lui   $a2, 0x8015
/* 0DE758 80148058 24C61328 */  addiu $a2, $a2, 0x1328
/* 0DE75C 8014805C 3C058015 */  lui   $a1, 0x8015
/* 0DE760 80148060 24A512B0 */  addiu $a1, $a1, 0x12b0
/* 0DE764 80148064 0080182D */  daddu $v1, $a0, $zero
.L80148068:
/* 0DE768 80148068 8CC20000 */  lw    $v0, ($a2)
/* 0DE76C 8014806C 00431021 */  addu  $v0, $v0, $v1
/* 0DE770 80148070 A0400004 */  sb    $zero, 4($v0)
/* 0DE774 80148074 8CA20000 */  lw    $v0, ($a1)
/* 0DE778 80148078 24840001 */  addiu $a0, $a0, 1
/* 0DE77C 8014807C 00431021 */  addu  $v0, $v0, $v1
/* 0DE780 80148080 A0400004 */  sb    $zero, 4($v0)
/* 0DE784 80148084 28820007 */  slti  $v0, $a0, 7
/* 0DE788 80148088 1440FFF7 */  bnez  $v0, .L80148068
/* 0DE78C 8014808C 24630018 */   addiu $v1, $v1, 0x18
/* 0DE790 80148090 3C048015 */  lui   $a0, 0x8015
/* 0DE794 80148094 24841328 */  addiu $a0, $a0, 0x1328
/* 0DE798 80148098 8C820000 */  lw    $v0, ($a0)
/* 0DE79C 8014809C 24030032 */  addiu $v1, $zero, 0x32
/* 0DE7A0 801480A0 A4400000 */  sh    $zero, ($v0)
/* 0DE7A4 801480A4 A04300AE */  sb    $v1, 0xae($v0)
/* 0DE7A8 801480A8 A04300AD */  sb    $v1, 0xad($v0)
/* 0DE7AC 801480AC A04300AC */  sb    $v1, 0xac($v0)
/* 0DE7B0 801480B0 8C840000 */  lw    $a0, ($a0)
/* 0DE7B4 801480B4 2402000A */  addiu $v0, $zero, 0xa
/* 0DE7B8 801480B8 A08200AF */  sb    $v0, 0xaf($a0)
/* 0DE7BC 801480BC 3C048015 */  lui   $a0, 0x8015
/* 0DE7C0 801480C0 248412B0 */  addiu $a0, $a0, 0x12b0
/* 0DE7C4 801480C4 8C820000 */  lw    $v0, ($a0)
/* 0DE7C8 801480C8 A4400000 */  sh    $zero, ($v0)
/* 0DE7CC 801480CC A04300AE */  sb    $v1, 0xae($v0)
/* 0DE7D0 801480D0 A04300AD */  sb    $v1, 0xad($v0)
/* 0DE7D4 801480D4 A04300AC */  sb    $v1, 0xac($v0)
/* 0DE7D8 801480D8 8C830000 */  lw    $v1, ($a0)
/* 0DE7DC 801480DC 24020014 */  addiu $v0, $zero, 0x14
/* 0DE7E0 801480E0 A06200AF */  sb    $v0, 0xaf($v1)
/* 0DE7E4 801480E4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0DE7E8 801480E8 03E00008 */  jr    $ra
/* 0DE7EC 801480EC 27BD0018 */   addiu $sp, $sp, 0x18

