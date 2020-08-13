.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80144EFC
/* 0DB5FC 80144EFC 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB600 80144F00 00822024 */  and   $a0, $a0, $v0
/* 0DB604 80144F04 3C028015 */  lui   $v0, 0x8015
/* 0DB608 80144F08 8C427960 */  lw    $v0, 0x7960($v0)
/* 0DB60C 80144F0C 00042080 */  sll   $a0, $a0, 2
/* 0DB610 80144F10 00822021 */  addu  $a0, $a0, $v0
/* 0DB614 80144F14 8C820000 */  lw    $v0, ($a0)
/* 0DB618 80144F18 A045004B */  sb    $a1, 0x4b($v0)
/* 0DB61C 80144F1C A046004C */  sb    $a2, 0x4c($v0)
/* 0DB620 80144F20 03E00008 */  jr    $ra
/* 0DB624 80144F24 A047004D */   sb    $a3, 0x4d($v0)

/* 0DB628 80144F28 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0DB62C 80144F2C 2402F7FF */  addiu $v0, $zero, -0x801
/* 0DB630 80144F30 00821024 */  and   $v0, $a0, $v0
/* 0DB634 80144F34 3C038015 */  lui   $v1, 0x8015
/* 0DB638 80144F38 8C637960 */  lw    $v1, 0x7960($v1)
/* 0DB63C 80144F3C 00021080 */  sll   $v0, $v0, 2
/* 0DB640 80144F40 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0DB644 80144F44 AFB10014 */  sw    $s1, 0x14($sp)
/* 0DB648 80144F48 AFB00010 */  sw    $s0, 0x10($sp)
/* 0DB64C 80144F4C 00431021 */  addu  $v0, $v0, $v1
/* 0DB650 80144F50 8C510000 */  lw    $s1, ($v0)
/* 0DB654 80144F54 0C00AB0A */  jal   general_heap_malloc
/* 0DB658 80144F58 240400F0 */   addiu $a0, $zero, 0xf0
/* 0DB65C 80144F5C 0040802D */  daddu $s0, $v0, $zero
/* 0DB660 80144F60 16000003 */  bnez  $s0, .L80144F70
/* 0DB664 80144F64 AE30001C */   sw    $s0, 0x1c($s1)
.L80144F68:
/* 0DB668 80144F68 080513DA */  j     .L80144F68
/* 0DB66C 80144F6C 00000000 */   nop   

.L80144F70:
/* 0DB670 80144F70 24040001 */  addiu $a0, $zero, 1
/* 0DB674 80144F74 8E220000 */  lw    $v0, ($s1)
/* 0DB678 80144F78 3C030001 */  lui   $v1, 1
/* 0DB67C 80144F7C 00431025 */  or    $v0, $v0, $v1
/* 0DB680 80144F80 0C04E9C1 */  jal   func_8013A704
/* 0DB684 80144F84 AE220000 */   sw    $v0, ($s1)
/* 0DB688 80144F88 3C013F80 */  lui   $at, 0x3f80
/* 0DB68C 80144F8C 44810000 */  mtc1  $at, $f0
/* 0DB690 80144F90 AE020000 */  sw    $v0, ($s0)
/* 0DB694 80144F94 AE000004 */  sw    $zero, 4($s0)
/* 0DB698 80144F98 AE000008 */  sw    $zero, 8($s0)
/* 0DB69C 80144F9C AE00000C */  sw    $zero, 0xc($s0)
/* 0DB6A0 80144FA0 AE000010 */  sw    $zero, 0x10($s0)
/* 0DB6A4 80144FA4 AE000014 */  sw    $zero, 0x14($s0)
/* 0DB6A8 80144FA8 AE000018 */  sw    $zero, 0x18($s0)
/* 0DB6AC 80144FAC A6000028 */  sh    $zero, 0x28($s0)
/* 0DB6B0 80144FB0 A600002A */  sh    $zero, 0x2a($s0)
/* 0DB6B4 80144FB4 E600001C */  swc1  $f0, 0x1c($s0)
/* 0DB6B8 80144FB8 E6000020 */  swc1  $f0, 0x20($s0)
/* 0DB6BC 80144FBC 0C0504FE */  jal   func_801413F8
/* 0DB6C0 80144FC0 E6000024 */   swc1  $f0, 0x24($s0)
/* 0DB6C4 80144FC4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0DB6C8 80144FC8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0DB6CC 80144FCC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0DB6D0 80144FD0 03E00008 */  jr    $ra
/* 0DB6D4 80144FD4 27BD0020 */   addiu $sp, $sp, 0x20

