.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel hide_foreground_models
/* 196594 80267CB4 3C02800E */  lui   $v0, 0x800e
/* 196598 80267CB8 8C42C4A8 */  lw    $v0, -0x3b58($v0)
/* 19659C 80267CBC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1965A0 80267CC0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 1965A4 80267CC4 10400014 */  beqz  $v0, .L80267D18
/* 1965A8 80267CC8 AFB00010 */   sw    $s0, 0x10($sp)
/* 1965AC 80267CCC 8C420018 */  lw    $v0, 0x18($v0)
/* 1965B0 80267CD0 10400011 */  beqz  $v0, .L80267D18
/* 1965B4 80267CD4 0040802D */   daddu $s0, $v0, $zero
/* 1965B8 80267CD8 8E020000 */  lw    $v0, ($s0)
/* 1965BC 80267CDC 1040000E */  beqz  $v0, .L80267D18
/* 1965C0 80267CE0 00000000 */   nop   
.L80267CE4:
/* 1965C4 80267CE4 8E040000 */  lw    $a0, ($s0)
/* 1965C8 80267CE8 0480000B */  bltz  $a0, .L80267D18
/* 1965CC 80267CEC 26100004 */   addiu $s0, $s0, 4
/* 1965D0 80267CF0 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 1965D4 80267CF4 00000000 */   nop   
/* 1965D8 80267CF8 0C046B4C */  jal   get_model_from_list_index
/* 1965DC 80267CFC 0040202D */   daddu $a0, $v0, $zero
/* 1965E0 80267D00 94430000 */  lhu   $v1, ($v0)
/* 1965E4 80267D04 34630002 */  ori   $v1, $v1, 2
/* 1965E8 80267D08 A4430000 */  sh    $v1, ($v0)
/* 1965EC 80267D0C 8E020000 */  lw    $v0, ($s0)
/* 1965F0 80267D10 1440FFF4 */  bnez  $v0, .L80267CE4
/* 1965F4 80267D14 00000000 */   nop   
.L80267D18:
/* 1965F8 80267D18 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1965FC 80267D1C 8FB00010 */  lw    $s0, 0x10($sp)
/* 196600 80267D20 03E00008 */  jr    $ra
/* 196604 80267D24 27BD0018 */   addiu $sp, $sp, 0x18

