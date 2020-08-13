.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osFlashWriteArray
/* 04AA1C 8006F61C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 04AA20 8006F620 AFBF0014 */  sw    $ra, 0x14($sp)
/* 04AA24 8006F624 AFA40020 */  sw    $a0, 0x20($sp)
/* 04AA28 8006F628 3C0E800B */  lui   $t6, 0x800b
/* 04AA2C 8006F62C 8DCE0CE8 */  lw    $t6, 0xce8($t6)
/* 04AA30 8006F630 24010001 */  addiu $at, $zero, 1
/* 04AA34 8006F634 15C1000B */  bne   $t6, $at, .L8006F664
/* 04AA38 8006F638 00000000 */   nop   
/* 04AA3C 8006F63C 3C04800B */  lui   $a0, 0x800b
/* 04AA40 8006F640 24840C70 */  addiu $a0, $a0, 0xc70
/* 04AA44 8006F644 3C05800B */  lui   $a1, 0x800b
/* 04AA48 8006F648 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04AA4C 8006F64C 3C010001 */  lui   $at, 1
/* 04AA50 8006F650 00A17825 */  or    $t7, $a1, $at
/* 04AA54 8006F654 01E02825 */  or    $a1, $t7, $zero
/* 04AA58 8006F658 3C06B400 */  lui   $a2, 0xb400
/* 04AA5C 8006F65C 0C018358 */  jal   osEPiWriteIo
/* 04AA60 8006F660 00000000 */   nop   
.L8006F664:
/* 04AA64 8006F664 3C04800B */  lui   $a0, 0x800b
/* 04AA68 8006F668 24840C70 */  addiu $a0, $a0, 0xc70
/* 04AA6C 8006F66C 3C05800B */  lui   $a1, 0x800b
/* 04AA70 8006F670 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04AA74 8006F674 3C010001 */  lui   $at, 1
/* 04AA78 8006F678 00A1C025 */  or    $t8, $a1, $at
/* 04AA7C 8006F67C 03002825 */  or    $a1, $t8, $zero
/* 04AA80 8006F680 8FA60020 */  lw    $a2, 0x20($sp)
/* 04AA84 8006F684 3C01A500 */  lui   $at, 0xa500
/* 04AA88 8006F688 00C1C825 */  or    $t9, $a2, $at
/* 04AA8C 8006F68C 03203025 */  or    $a2, $t9, $zero
/* 04AA90 8006F690 0C018358 */  jal   osEPiWriteIo
/* 04AA94 8006F694 00000000 */   nop   
.L8006F698:
/* 04AA98 8006F698 3C04800B */  lui   $a0, 0x800b
/* 04AA9C 8006F69C 24840C70 */  addiu $a0, $a0, 0xc70
/* 04AAA0 8006F6A0 3C05800B */  lui   $a1, 0x800b
/* 04AAA4 8006F6A4 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04AAA8 8006F6A8 27A6001C */  addiu $a2, $sp, 0x1c
/* 04AAAC 8006F6AC 0C018370 */  jal   osEPiReadIo
/* 04AAB0 8006F6B0 00000000 */   nop   
/* 04AAB4 8006F6B4 8FA8001C */  lw    $t0, 0x1c($sp)
/* 04AAB8 8006F6B8 00000000 */  nop   
/* 04AABC 8006F6BC 31090001 */  andi  $t1, $t0, 1
/* 04AAC0 8006F6C0 24010001 */  addiu $at, $zero, 1
/* 04AAC4 8006F6C4 1121FFF4 */  beq   $t1, $at, .L8006F698
/* 04AAC8 8006F6C8 00000000 */   nop   
/* 04AACC 8006F6CC 3C04800B */  lui   $a0, 0x800b
/* 04AAD0 8006F6D0 24840C70 */  addiu $a0, $a0, 0xc70
/* 04AAD4 8006F6D4 3C05800B */  lui   $a1, 0x800b
/* 04AAD8 8006F6D8 8CA50C7C */  lw    $a1, 0xc7c($a1)
/* 04AADC 8006F6DC 27A6001C */  addiu $a2, $sp, 0x1c
/* 04AAE0 8006F6E0 0C018370 */  jal   osEPiReadIo
/* 04AAE4 8006F6E4 00000000 */   nop   
/* 04AAE8 8006F6E8 0C01BCA7 */  jal   osFlashClearStatus
/* 04AAEC 8006F6EC 00000000 */   nop   
/* 04AAF0 8006F6F0 8FAA001C */  lw    $t2, 0x1c($sp)
/* 04AAF4 8006F6F4 00000000 */  nop   
/* 04AAF8 8006F6F8 314B00FF */  andi  $t3, $t2, 0xff
/* 04AAFC 8006F6FC 24010004 */  addiu $at, $zero, 4
/* 04AB00 8006F700 11610008 */  beq   $t3, $at, .L8006F724
/* 04AB04 8006F704 00000000 */   nop   
/* 04AB08 8006F708 24010044 */  addiu $at, $zero, 0x44
/* 04AB0C 8006F70C 11610005 */  beq   $t3, $at, .L8006F724
/* 04AB10 8006F710 00000000 */   nop   
/* 04AB14 8006F714 314C0004 */  andi  $t4, $t2, 4
/* 04AB18 8006F718 24010004 */  addiu $at, $zero, 4
/* 04AB1C 8006F71C 15810006 */  bne   $t4, $at, .L8006F738
/* 04AB20 8006F720 00000000 */   nop   
.L8006F724:
/* 04AB24 8006F724 00001025 */  or    $v0, $zero, $zero
/* 04AB28 8006F728 10000008 */  b     .L8006F74C
/* 04AB2C 8006F72C 00000000 */   nop   
/* 04AB30 8006F730 10000004 */  b     .L8006F744
/* 04AB34 8006F734 00000000 */   nop   
.L8006F738:
/* 04AB38 8006F738 2402FFFF */  addiu $v0, $zero, -1
/* 04AB3C 8006F73C 10000003 */  b     .L8006F74C
/* 04AB40 8006F740 00000000 */   nop   
.L8006F744:
/* 04AB44 8006F744 10000001 */  b     .L8006F74C
/* 04AB48 8006F748 00000000 */   nop   
.L8006F74C:
/* 04AB4C 8006F74C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 04AB50 8006F750 27BD0020 */  addiu $sp, $sp, 0x20
/* 04AB54 8006F754 03E00008 */  jr    $ra
/* 04AB58 8006F758 00000000 */   nop   

