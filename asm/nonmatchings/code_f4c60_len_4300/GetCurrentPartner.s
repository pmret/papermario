.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCurrentPartner
/* 0F74BC 802D2B0C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F74C0 802D2B10 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F74C4 802D2B14 8C82000C */  lw    $v0, 0xc($a0)
/* 0F74C8 802D2B18 3C038011 */  lui   $v1, 0x8011
/* 0F74CC 802D2B1C 8063EBB0 */  lb    $v1, -0x1450($v1)
/* 0F74D0 802D2B20 8C450000 */  lw    $a1, ($v0)
/* 0F74D4 802D2B24 10600004 */  beqz  $v1, .L802D2B38
/* 0F74D8 802D2B28 0000302D */   daddu $a2, $zero, $zero
/* 0F74DC 802D2B2C 3C028011 */  lui   $v0, 0x8011
/* 0F74E0 802D2B30 2442F290 */  addiu $v0, $v0, -0xd70
/* 0F74E4 802D2B34 80460012 */  lb    $a2, 0x12($v0)
.L802D2B38:
/* 0F74E8 802D2B38 0C0B2026 */  jal   set_variable
/* 0F74EC 802D2B3C 00000000 */   nop   
/* 0F74F0 802D2B40 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F74F4 802D2B44 24020002 */  addiu $v0, $zero, 2
/* 0F74F8 802D2B48 03E00008 */  jr    $ra
/* 0F74FC 802D2B4C 27BD0018 */   addiu $sp, $sp, 0x18

/* 0F7500 802D2B50 3C038011 */  lui   $v1, 0x8011
/* 0F7504 802D2B54 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F7508 802D2B58 8C620004 */  lw    $v0, 4($v1)
/* 0F750C 802D2B5C 34420008 */  ori   $v0, $v0, 8
/* 0F7510 802D2B60 AC620004 */  sw    $v0, 4($v1)
/* 0F7514 802D2B64 03E00008 */  jr    $ra
/* 0F7518 802D2B68 24020002 */   addiu $v0, $zero, 2

/* 0F751C 802D2B6C 3C038011 */  lui   $v1, 0x8011
/* 0F7520 802D2B70 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F7524 802D2B74 8C620004 */  lw    $v0, 4($v1)
/* 0F7528 802D2B78 34420004 */  ori   $v0, $v0, 4
/* 0F752C 802D2B7C AC620004 */  sw    $v0, 4($v1)
/* 0F7530 802D2B80 03E00008 */  jr    $ra
/* 0F7534 802D2B84 24020002 */   addiu $v0, $zero, 2

