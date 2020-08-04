.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel sync_status_menu
/* 08301C 800E9B6C 3C028011 */  lui   $v0, 0x8011
/* 083020 800E9B70 2442F290 */  addiu $v0, $v0, -0xd70
/* 083024 800E9B74 90430010 */  lbu   $v1, 0x10($v0)
/* 083028 800E9B78 90440002 */  lbu   $a0, 2($v0)
/* 08302C 800E9B7C 90450005 */  lbu   $a1, 5($v0)
/* 083030 800E9B80 94460290 */  lhu   $a2, 0x290($v0)
/* 083034 800E9B84 9447000C */  lhu   $a3, 0xc($v0)
/* 083038 800E9B88 3C028011 */  lui   $v0, 0x8011
/* 08303C 800E9B8C 2442EF58 */  addiu $v0, $v0, -0x10a8
/* 083040 800E9B90 00031E00 */  sll   $v1, $v1, 0x18
/* 083044 800E9B94 00031E03 */  sra   $v1, $v1, 0x18
/* 083048 800E9B98 A044003D */  sb    $a0, 0x3d($v0)
/* 08304C 800E9B9C A045003E */  sb    $a1, 0x3e($v0)
/* 083050 800E9BA0 A4460048 */  sh    $a2, 0x48($v0)
/* 083054 800E9BA4 A4470040 */  sh    $a3, 0x40($v0)
/* 083058 800E9BA8 03E00008 */  jr    $ra
/* 08305C 800E9BAC A4430042 */   sh    $v1, 0x42($v0)

