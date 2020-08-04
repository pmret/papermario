.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel heroes_is_ability_active
/* 195B8C 802672AC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 195B90 802672B0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 195B94 802672B4 94820192 */  lhu   $v0, 0x192($a0)
/* 195B98 802672B8 30430700 */  andi  $v1, $v0, 0x700
/* 195B9C 802672BC 24020100 */  addiu $v0, $zero, 0x100
/* 195BA0 802672C0 1062000F */  beq   $v1, $v0, .L80267300
/* 195BA4 802672C4 0000202D */   daddu $a0, $zero, $zero
/* 195BA8 802672C8 28620101 */  slti  $v0, $v1, 0x101
/* 195BAC 802672CC 1040000F */  beqz  $v0, .L8026730C
/* 195BB0 802672D0 00000000 */   nop   
/* 195BB4 802672D4 1460000D */  bnez  $v1, .L8026730C
/* 195BB8 802672D8 00000000 */   nop   
/* 195BBC 802672DC 3C02800E */  lui   $v0, 0x800e
/* 195BC0 802672E0 8C42C074 */  lw    $v0, -0x3f8c($v0)
/* 195BC4 802672E4 30420040 */  andi  $v0, $v0, 0x40
/* 195BC8 802672E8 14400008 */  bnez  $v0, .L8026730C
/* 195BCC 802672EC 00000000 */   nop   
/* 195BD0 802672F0 0C03A752 */  jal   is_ability_active
/* 195BD4 802672F4 00A0202D */   daddu $a0, $a1, $zero
/* 195BD8 802672F8 08099CC3 */  j     .L8026730C
/* 195BDC 802672FC 0040202D */   daddu $a0, $v0, $zero

.L80267300:
/* 195BE0 80267300 0C03A82E */  jal   is_partner_ability_active
/* 195BE4 80267304 00A0202D */   daddu $a0, $a1, $zero
/* 195BE8 80267308 0040202D */  daddu $a0, $v0, $zero
.L8026730C:
.L8026730C:
/* 195BEC 8026730C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 195BF0 80267310 0080102D */  daddu $v0, $a0, $zero
/* 195BF4 80267314 03E00008 */  jr    $ra
/* 195BF8 80267318 27BD0018 */   addiu $sp, $sp, 0x18

