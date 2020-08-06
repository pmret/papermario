.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osFlashReadArray
/* 04AB5C 8006F75C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04AB60 8006F760 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04AB64 8006F764 AFA40020 */  sw    $a0, 0x20($sp)
/* 04AB68 8006F768 AFA50024 */  sw    $a1, 0x24($sp)
/* 04AB6C 8006F76C AFA60028 */  sw    $a2, 0x28($sp)
/* 04AB70 8006F770 AFA7002C */  sw    $a3, 0x2c($sp)
/* 04AB74 8006F774 3C04800B */  lui   $a0, 0x800b
/* 04AB78 8006F778 24840C70 */  addiu $a0, $a0, 0xc70
/* 04AB7C 8006F77C 3C05800B */  lui   $a1, 0x800b
/* 04AB80 8006F780 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04AB84 8006F784 3C010001 */  lui   $at, 1
/* 04AB88 8006F788 00A17025 */  or    $t6, $a1, $at
/* 04AB8C 8006F78C 01C02825 */  or    $a1, $t6, $zero
/* 04AB90 8006F790 3C06F000 */  lui   $a2, 0xf000
/* 04AB94 8006F794 0C018358 */  jal   osEPiWriteIo
/* 04AB98 8006F798 00000000 */   nop   
/* 04AB9C 8006F79C 3C04800B */  lui   $a0, 0x800b
/* 04ABA0 8006F7A0 24840C70 */  addiu $a0, $a0, 0xc70
/* 04ABA4 8006F7A4 3C05800B */  lui   $a1, 0x800b
/* 04ABA8 8006F7A8 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04ABAC 8006F7AC 27A60018 */  addiu $a2, $sp, 0x18
/* 04ABB0 8006F7B0 0C018370 */  jal   osEPiReadIo
/* 04ABB4 8006F7B4 00000000 */   nop   
/* 04ABB8 8006F7B8 8FAF0024 */  lw    $t7, 0x24($sp)
/* 04ABBC 8006F7BC 8FB80020 */  lw    $t8, 0x20($sp)
/* 04ABC0 8006F7C0 00000000 */  nop   
/* 04ABC4 8006F7C4 A30F0002 */  sb    $t7, 2($t8)
/* 04ABC8 8006F7C8 8FB90034 */  lw    $t9, 0x34($sp)
/* 04ABCC 8006F7CC 8FA80020 */  lw    $t0, 0x20($sp)
/* 04ABD0 8006F7D0 00000000 */  nop   
/* 04ABD4 8006F7D4 AD190004 */  sw    $t9, 4($t0)
/* 04ABD8 8006F7D8 8FA9002C */  lw    $t1, 0x2c($sp)
/* 04ABDC 8006F7DC 8FAA0020 */  lw    $t2, 0x20($sp)
/* 04ABE0 8006F7E0 00000000 */  nop   
/* 04ABE4 8006F7E4 AD490008 */  sw    $t1, 8($t2)
/* 04ABE8 8006F7E8 8FAB0030 */  lw    $t3, 0x30($sp)
/* 04ABEC 8006F7EC 00000000 */  nop   
/* 04ABF0 8006F7F0 000B61C0 */  sll   $t4, $t3, 7
/* 04ABF4 8006F7F4 8FAD0020 */  lw    $t5, 0x20($sp)
/* 04ABF8 8006F7F8 00000000 */  nop   
/* 04ABFC 8006F7FC ADAC0010 */  sw    $t4, 0x10($t5)
/* 04AC00 8006F800 3C0E800B */  lui   $t6, 0x800b
/* 04AC04 8006F804 8DCE0CE8 */  lw    $t6, 0xce8($t6)
/* 04AC08 8006F808 00000000 */  nop   
/* 04AC0C 8006F80C 15C00009 */  bnez  $t6, .L8006F834
/* 04AC10 8006F810 00000000 */   nop   
/* 04AC14 8006F814 8FAF0028 */  lw    $t7, 0x28($sp)
/* 04AC18 8006F818 00000000 */  nop   
/* 04AC1C 8006F81C 000FC180 */  sll   $t8, $t7, 6
/* 04AC20 8006F820 8FB90020 */  lw    $t9, 0x20($sp)
/* 04AC24 8006F824 00000000 */  nop   
/* 04AC28 8006F828 AF38000C */  sw    $t8, 0xc($t9)
/* 04AC2C 8006F82C 10000007 */  b     .L8006F84C
/* 04AC30 8006F830 00000000 */   nop   
.L8006F834:
/* 04AC34 8006F834 8FA80028 */  lw    $t0, 0x28($sp)
/* 04AC38 8006F838 00000000 */  nop   
/* 04AC3C 8006F83C 000849C0 */  sll   $t1, $t0, 7
/* 04AC40 8006F840 8FAA0020 */  lw    $t2, 0x20($sp)
/* 04AC44 8006F844 00000000 */  nop   
/* 04AC48 8006F848 AD49000C */  sw    $t1, 0xc($t2)
.L8006F84C:
/* 04AC4C 8006F84C 3C04800B */  lui   $a0, 0x800b
/* 04AC50 8006F850 24840C70 */  addiu $a0, $a0, 0xc70
/* 04AC54 8006F854 8FA50020 */  lw    $a1, 0x20($sp)
/* 04AC58 8006F858 00003025 */  or    $a2, $zero, $zero
/* 04AC5C 8006F85C 0C018388 */  jal   osEPiStartDma
/* 04AC60 8006F860 00000000 */   nop   
/* 04AC64 8006F864 AFA2001C */  sw    $v0, 0x1c($sp)
/* 04AC68 8006F868 8FA2001C */  lw    $v0, 0x1c($sp)
/* 04AC6C 8006F86C 10000003 */  b     .L8006F87C
/* 04AC70 8006F870 00000000 */   nop   
/* 04AC74 8006F874 10000001 */  b     .L8006F87C
/* 04AC78 8006F878 00000000 */   nop   
.L8006F87C:
/* 04AC7C 8006F87C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04AC80 8006F880 27BD0020 */  addiu $sp, $sp, 0x20
/* 04AC84 8006F884 03E00008 */  jr    $ra
/* 04AC88 8006F888 00000000 */   nop   

/* 04AC8C 8006F88C 00000000 */  nop   


