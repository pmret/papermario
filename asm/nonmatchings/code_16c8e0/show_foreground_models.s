.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel show_foreground_models
/* 196608 80267D28 3C02800E */  lui   $v0, 0x800e
/* 19660C 80267D2C 8C42C4A8 */  lw    $v0, -0x3b58($v0)
/* 196610 80267D30 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 196614 80267D34 AFBF0014 */  sw    $ra, 0x14($sp)
/* 196618 80267D38 10400014 */  beqz  $v0, .L80267D8C
/* 19661C 80267D3C AFB00010 */   sw    $s0, 0x10($sp)
/* 196620 80267D40 8C420018 */  lw    $v0, 0x18($v0)
/* 196624 80267D44 10400011 */  beqz  $v0, .L80267D8C
/* 196628 80267D48 0040802D */   daddu $s0, $v0, $zero
/* 19662C 80267D4C 8E020000 */  lw    $v0, ($s0)
/* 196630 80267D50 1040000E */  beqz  $v0, .L80267D8C
/* 196634 80267D54 00000000 */   nop   
.L80267D58:
/* 196638 80267D58 8E040000 */  lw    $a0, ($s0)
/* 19663C 80267D5C 0480000B */  bltz  $a0, .L80267D8C
/* 196640 80267D60 26100004 */   addiu $s0, $s0, 4
/* 196644 80267D64 0C046C04 */  jal   get_model_list_index_from_tree_index
/* 196648 80267D68 00000000 */   nop   
/* 19664C 80267D6C 0C046B4C */  jal   get_model_from_list_index
/* 196650 80267D70 0040202D */   daddu $a0, $v0, $zero
/* 196654 80267D74 94430000 */  lhu   $v1, ($v0)
/* 196658 80267D78 3063FFFD */  andi  $v1, $v1, 0xfffd
/* 19665C 80267D7C A4430000 */  sh    $v1, ($v0)
/* 196660 80267D80 8E020000 */  lw    $v0, ($s0)
/* 196664 80267D84 1440FFF4 */  bnez  $v0, .L80267D58
/* 196668 80267D88 00000000 */   nop   
.L80267D8C:
/* 19666C 80267D8C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 196670 80267D90 8FB00010 */  lw    $s0, 0x10($sp)
/* 196674 80267D94 03E00008 */  jr    $ra
/* 196678 80267D98 27BD0018 */   addiu $sp, $sp, 0x18

