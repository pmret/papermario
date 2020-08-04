.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel free_npc
/* 013DCC 800389CC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 013DD0 800389D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 013DD4 800389D4 0080882D */  daddu $s1, $a0, $zero
/* 013DD8 800389D8 AFBF0018 */  sw    $ra, 0x18($sp)
/* 013DDC 800389DC AFB00010 */  sw    $s0, 0x10($sp)
/* 013DE0 800389E0 8E240020 */  lw    $a0, 0x20($s1)
/* 013DE4 800389E4 10800004 */  beqz  $a0, .L800389F8
/* 013DE8 800389E8 00000000 */   nop   
/* 013DEC 800389EC 0C00AB4B */  jal   heap_free
/* 013DF0 800389F0 00000000 */   nop   
/* 013DF4 800389F4 AE200020 */  sw    $zero, 0x20($s1)
.L800389F8:
/* 013DF8 800389F8 8E230000 */  lw    $v1, ($s1)
/* 013DFC 800389FC 3C024000 */  lui   $v0, 0x4000
/* 013E00 80038A00 00621024 */  and   $v0, $v1, $v0
/* 013E04 80038A04 1440000A */  bnez  $v0, .L80038A30
/* 013E08 80038A08 3C020100 */   lui   $v0, 0x100
/* 013E0C 80038A0C 00621024 */  and   $v0, $v1, $v0
/* 013E10 80038A10 14400007 */  bnez  $v0, .L80038A30
/* 013E14 80038A14 00000000 */   nop   
/* 013E18 80038A18 0C0B797A */  jal   func_802DE5E8
/* 013E1C 80038A1C 8E240024 */   lw    $a0, 0x24($s1)
/* 013E20 80038A20 10400003 */  beqz  $v0, .L80038A30
/* 013E24 80038A24 00000000 */   nop   
.L80038A28:
/* 013E28 80038A28 0800E28A */  j     .L80038A28
/* 013E2C 80038A2C 00000000 */   nop   

.L80038A30:
/* 013E30 80038A30 8E240078 */  lw    $a0, 0x78($s1)
/* 013E34 80038A34 0C0448CA */  jal   func_80112328
/* 013E38 80038A38 0000802D */   daddu $s0, $zero, $zero
/* 013E3C 80038A3C 0220202D */  daddu $a0, $s1, $zero
.L80038A40:
/* 013E40 80038A40 0C00F10A */  jal   func_8003C428
/* 013E44 80038A44 0200282D */   daddu $a1, $s0, $zero
/* 013E48 80038A48 26100001 */  addiu $s0, $s0, 1
/* 013E4C 80038A4C 2A020002 */  slti  $v0, $s0, 2
/* 013E50 80038A50 1440FFFB */  bnez  $v0, .L80038A40
/* 013E54 80038A54 0220202D */   daddu $a0, $s1, $zero
/* 013E58 80038A58 8E220000 */  lw    $v0, ($s1)
/* 013E5C 80038A5C 3C030010 */  lui   $v1, 0x10
/* 013E60 80038A60 00431024 */  and   $v0, $v0, $v1
/* 013E64 80038A64 10400003 */  beqz  $v0, .L80038A74
/* 013E68 80038A68 00000000 */   nop   
/* 013E6C 80038A6C 0C00EB6B */  jal   disable_npc_blur
/* 013E70 80038A70 0220202D */   daddu $a0, $s1, $zero
.L80038A74:
/* 013E74 80038A74 0C00AB4B */  jal   heap_free
/* 013E78 80038A78 0220202D */   daddu $a0, $s1, $zero
/* 013E7C 80038A7C 3C05800A */  lui   $a1, 0x800a
/* 013E80 80038A80 8CA50B90 */  lw    $a1, 0xb90($a1)
/* 013E84 80038A84 0000802D */  daddu $s0, $zero, $zero
/* 013E88 80038A88 00A0182D */  daddu $v1, $a1, $zero
.L80038A8C:
/* 013E8C 80038A8C 8C620000 */  lw    $v0, ($v1)
/* 013E90 80038A90 10510006 */  beq   $v0, $s1, .L80038AAC
/* 013E94 80038A94 00101080 */   sll   $v0, $s0, 2
/* 013E98 80038A98 26100001 */  addiu $s0, $s0, 1
/* 013E9C 80038A9C 2A020040 */  slti  $v0, $s0, 0x40
/* 013EA0 80038AA0 1440FFFA */  bnez  $v0, .L80038A8C
/* 013EA4 80038AA4 24630004 */   addiu $v1, $v1, 4
/* 013EA8 80038AA8 00101080 */  sll   $v0, $s0, 2
.L80038AAC:
/* 013EAC 80038AAC 3C04800A */  lui   $a0, 0x800a
/* 013EB0 80038AB0 2484A604 */  addiu $a0, $a0, -0x59fc
/* 013EB4 80038AB4 94830000 */  lhu   $v1, ($a0)
/* 013EB8 80038AB8 00451021 */  addu  $v0, $v0, $a1
/* 013EBC 80038ABC AC400000 */  sw    $zero, ($v0)
/* 013EC0 80038AC0 2463FFFF */  addiu $v1, $v1, -1
/* 013EC4 80038AC4 A4830000 */  sh    $v1, ($a0)
/* 013EC8 80038AC8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 013ECC 80038ACC 8FB10014 */  lw    $s1, 0x14($sp)
/* 013ED0 80038AD0 8FB00010 */  lw    $s0, 0x10($sp)
/* 013ED4 80038AD4 03E00008 */  jr    $ra
/* 013ED8 80038AD8 27BD0020 */   addiu $sp, $sp, 0x20

