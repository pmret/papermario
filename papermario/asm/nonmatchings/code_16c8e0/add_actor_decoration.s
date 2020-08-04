.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_actor_decoration
/* 195A70 80267190 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 195A74 80267194 AFB20018 */  sw    $s2, 0x18($sp)
/* 195A78 80267198 00A0902D */  daddu $s2, $a1, $zero
/* 195A7C 8026719C AFBF0020 */  sw    $ra, 0x20($sp)
/* 195A80 802671A0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 195A84 802671A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 195A88 802671A8 AFB00010 */  sw    $s0, 0x10($sp)
/* 195A8C 802671AC 8C9001F4 */  lw    $s0, 0x1f4($a0)
/* 195A90 802671B0 12000012 */  beqz  $s0, .L802671FC
/* 195A94 802671B4 00C0982D */   daddu $s3, $a2, $zero
/* 195A98 802671B8 3C110010 */  lui   $s1, 0x10
/* 195A9C 802671BC 36310001 */  ori   $s1, $s1, 1
.L802671C0:
/* 195AA0 802671C0 8E030000 */  lw    $v1, ($s0)
/* 195AA4 802671C4 00711024 */  and   $v0, $v1, $s1
/* 195AA8 802671C8 14400009 */  bnez  $v0, .L802671F0
/* 195AAC 802671CC 00000000 */   nop   
/* 195AB0 802671D0 8E020094 */  lw    $v0, 0x94($s0)
/* 195AB4 802671D4 10400006 */  beqz  $v0, .L802671F0
/* 195AB8 802671D8 30620002 */   andi  $v0, $v1, 2
/* 195ABC 802671DC 14400004 */  bnez  $v0, .L802671F0
/* 195AC0 802671E0 0200202D */   daddu $a0, $s0, $zero
/* 195AC4 802671E4 0240282D */  daddu $a1, $s2, $zero
/* 195AC8 802671E8 0C099C45 */  jal   add_part_decoration
/* 195ACC 802671EC 0260302D */   daddu $a2, $s3, $zero
.L802671F0:
/* 195AD0 802671F0 8E10000C */  lw    $s0, 0xc($s0)
/* 195AD4 802671F4 1600FFF2 */  bnez  $s0, .L802671C0
/* 195AD8 802671F8 00000000 */   nop   
.L802671FC:
/* 195ADC 802671FC 8FBF0020 */  lw    $ra, 0x20($sp)
/* 195AE0 80267200 8FB3001C */  lw    $s3, 0x1c($sp)
/* 195AE4 80267204 8FB20018 */  lw    $s2, 0x18($sp)
/* 195AE8 80267208 8FB10014 */  lw    $s1, 0x14($sp)
/* 195AEC 8026720C 8FB00010 */  lw    $s0, 0x10($sp)
/* 195AF0 80267210 03E00008 */  jr    $ra
/* 195AF4 80267214 27BD0028 */   addiu $sp, $sp, 0x28

