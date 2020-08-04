.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025C8A0
/* 18B180 8025C8A0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 18B184 8025C8A4 00A0382D */  daddu $a3, $a1, $zero
/* 18B188 8025C8A8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 18B18C 8025C8AC 8CE300C0 */  lw    $v1, 0xc0($a3)
/* 18B190 8025C8B0 80620751 */  lb    $v0, 0x751($v1)
/* 18B194 8025C8B4 10400015 */  beqz  $v0, .L8025C90C
/* 18B198 8025C8B8 00000000 */   nop   
/* 18B19C 8025C8BC 1480000B */  bnez  $a0, .L8025C8EC
/* 18B1A0 8025C8C0 A0600751 */   sb    $zero, 0x751($v1)
/* 18B1A4 8025C8C4 0000202D */  daddu $a0, $zero, $zero
/* 18B1A8 8025C8C8 0080282D */  daddu $a1, $a0, $zero
/* 18B1AC 8025C8CC 0080302D */  daddu $a2, $a0, $zero
/* 18B1B0 8025C8D0 0080382D */  daddu $a3, $a0, $zero
/* 18B1B4 8025C8D4 AFA00010 */  sw    $zero, 0x10($sp)
/* 18B1B8 8025C8D8 AFA00014 */  sw    $zero, 0x14($sp)
/* 18B1BC 8025C8DC 0C0B77FE */  jal   func_802DDFF8
/* 18B1C0 8025C8E0 AFA00018 */   sw    $zero, 0x18($sp)
/* 18B1C4 8025C8E4 08097243 */  j     .L8025C90C
/* 18B1C8 8025C8E8 00000000 */   nop   

.L8025C8EC:
/* 18B1CC 8025C8EC 0000282D */  daddu $a1, $zero, $zero
/* 18B1D0 8025C8F0 00A0302D */  daddu $a2, $a1, $zero
/* 18B1D4 8025C8F4 AFA00010 */  sw    $zero, 0x10($sp)
/* 18B1D8 8025C8F8 AFA00014 */  sw    $zero, 0x14($sp)
/* 18B1DC 8025C8FC AFA00018 */  sw    $zero, 0x18($sp)
/* 18B1E0 8025C900 8CE40084 */  lw    $a0, 0x84($a3)
/* 18B1E4 8025C904 0C0B7A25 */  jal   func_802DE894
/* 18B1E8 8025C908 00A0382D */   daddu $a3, $a1, $zero
.L8025C90C:
.L8025C90C:
/* 18B1EC 8025C90C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 18B1F0 8025C910 03E00008 */  jr    $ra
/* 18B1F4 8025C914 27BD0028 */   addiu $sp, $sp, 0x28

