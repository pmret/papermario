.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DEEA0
/* 101F90 802DEEA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 101F94 802DEEA4 0080382D */  daddu $a3, $a0, $zero
/* 101F98 802DEEA8 AFB00010 */  sw    $s0, 0x10($sp)
/* 101F9C 802DEEAC 2410FFFF */  addiu $s0, $zero, -1
/* 101FA0 802DEEB0 3C02802E */  lui   $v0, 0x802e
/* 101FA4 802DEEB4 8C420C58 */  lw    $v0, 0xc58($v0)
/* 101FA8 802DEEB8 0000202D */  daddu $a0, $zero, $zero
/* 101FAC 802DEEBC 18400018 */  blez  $v0, .L802DEF20
/* 101FB0 802DEEC0 AFBF0014 */   sw    $ra, 0x14($sp)
/* 101FB4 802DEEC4 24090002 */  addiu $t1, $zero, 2
/* 101FB8 802DEEC8 0200402D */  daddu $t0, $s0, $zero
/* 101FBC 802DEECC 0040302D */  daddu $a2, $v0, $zero
/* 101FC0 802DEED0 3C03802E */  lui   $v1, 0x802e
/* 101FC4 802DEED4 24630C70 */  addiu $v1, $v1, 0xc70
.L802DEED8:
/* 101FC8 802DEED8 8C620000 */  lw    $v0, ($v1)
/* 101FCC 802DEEDC 1040000A */  beqz  $v0, .L802DEF08
/* 101FD0 802DEEE0 00000000 */   nop   
/* 101FD4 802DEEE4 8C620004 */  lw    $v0, 4($v1)
/* 101FD8 802DEEE8 1447000A */  bne   $v0, $a3, .L802DEF14
/* 101FDC 802DEEEC 24840001 */   addiu $a0, $a0, 1
/* 101FE0 802DEEF0 8C620008 */  lw    $v0, 8($v1)
/* 101FE4 802DEEF4 14450008 */  bne   $v0, $a1, .L802DEF18
/* 101FE8 802DEEF8 0086102A */   slt   $v0, $a0, $a2
/* 101FEC 802DEEFC 8C62000C */  lw    $v0, 0xc($v1)
/* 101FF0 802DEF00 080B7BE9 */  j     .L802DEFA4
/* 101FF4 802DEF04 AC690000 */   sw    $t1, ($v1)

.L802DEF08:
/* 101FF8 802DEF08 52080001 */  beql  $s0, $t0, .L802DEF10
/* 101FFC 802DEF0C 0080802D */   daddu $s0, $a0, $zero
.L802DEF10:
/* 102000 802DEF10 24840001 */  addiu $a0, $a0, 1
.L802DEF14:
/* 102004 802DEF14 0086102A */  slt   $v0, $a0, $a2
.L802DEF18:
/* 102008 802DEF18 1440FFEF */  bnez  $v0, .L802DEED8
/* 10200C 802DEF1C 24630010 */   addiu $v1, $v1, 0x10
.L802DEF20:
/* 102010 802DEF20 2402FFFF */  addiu $v0, $zero, -1
/* 102014 802DEF24 1202001E */  beq   $s0, $v0, .L802DEFA0
/* 102018 802DEF28 00108100 */   sll   $s0, $s0, 4
/* 10201C 802DEF2C 3C02802E */  lui   $v0, 0x802e
/* 102020 802DEF30 24420C70 */  addiu $v0, $v0, 0xc70
/* 102024 802DEF34 02028021 */  addu  $s0, $s0, $v0
/* 102028 802DEF38 24020002 */  addiu $v0, $zero, 2
/* 10202C 802DEF3C AE020000 */  sw    $v0, ($s0)
/* 102030 802DEF40 00451004 */  sllv  $v0, $a1, $v0
/* 102034 802DEF44 3C04000F */  lui   $a0, 0xf
/* 102038 802DEF48 3484FFFF */  ori   $a0, $a0, 0xffff
/* 10203C 802DEF4C AE070004 */  sw    $a3, 4($s0)
/* 102040 802DEF50 AE050008 */  sw    $a1, 8($s0)
/* 102044 802DEF54 3C01802E */  lui   $at, 0x802e
/* 102048 802DEF58 00220821 */  addu  $at, $at, $v0
/* 10204C 802DEF5C 8C220050 */  lw    $v0, 0x50($at)
/* 102050 802DEF60 8E05000C */  lw    $a1, 0xc($s0)
/* 102054 802DEF64 00471021 */  addu  $v0, $v0, $a3
/* 102058 802DEF68 00021080 */  sll   $v0, $v0, 2
/* 10205C 802DEF6C 3C06802E */  lui   $a2, 0x802e
/* 102060 802DEF70 00C23021 */  addu  $a2, $a2, $v0
/* 102064 802DEF74 8CC60090 */  lw    $a2, 0x90($a2)
/* 102068 802DEF78 3C02802E */  lui   $v0, 0x802e
/* 10206C 802DEF7C 8C420C60 */  lw    $v0, 0xc60($v0)
/* 102070 802DEF80 00C42024 */  and   $a0, $a2, $a0
/* 102074 802DEF84 00063402 */  srl   $a2, $a2, 0x10
/* 102078 802DEF88 00442021 */  addu  $a0, $v0, $a0
/* 10207C 802DEF8C 0C017D24 */  jal   nuPiReadRom
/* 102080 802DEF90 30C6FFF0 */   andi  $a2, $a2, 0xfff0
/* 102084 802DEF94 8E02000C */  lw    $v0, 0xc($s0)
/* 102088 802DEF98 080B7BE9 */  j     .L802DEFA4
/* 10208C 802DEF9C 00000000 */   nop   

.L802DEFA0:
/* 102090 802DEFA0 0000102D */  daddu $v0, $zero, $zero
.L802DEFA4:
/* 102094 802DEFA4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 102098 802DEFA8 8FB00010 */  lw    $s0, 0x10($sp)
/* 10209C 802DEFAC 03E00008 */  jr    $ra
/* 1020A0 802DEFB0 27BD0018 */   addiu $sp, $sp, 0x18

