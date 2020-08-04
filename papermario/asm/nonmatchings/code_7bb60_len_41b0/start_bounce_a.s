.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel start_bounce_a
/* 07F4E4 800E6034 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07F4E8 800E6038 AFBF0010 */  sw    $ra, 0x10($sp)
/* 07F4EC 800E603C 0C039769 */  jal   set_action_state
/* 07F4F0 800E6040 24040004 */   addiu $a0, $zero, 4
/* 07F4F4 800E6044 3C014120 */  lui   $at, 0x4120
/* 07F4F8 800E6048 44810000 */  mtc1  $at, $f0
/* 07F4FC 800E604C 3C01C000 */  lui   $at, 0xc000
/* 07F500 800E6050 44811000 */  mtc1  $at, $f2
/* 07F504 800E6054 3C013F4C */  lui   $at, 0x3f4c
/* 07F508 800E6058 3421CCCD */  ori   $at, $at, 0xcccd
/* 07F50C 800E605C 44812000 */  mtc1  $at, $f4
/* 07F510 800E6060 3C01BF40 */  lui   $at, 0xbf40
/* 07F514 800E6064 44813000 */  mtc1  $at, $f6
/* 07F518 800E6068 3C028011 */  lui   $v0, 0x8011
/* 07F51C 800E606C 2442EFC8 */  addiu $v0, $v0, -0x1038
/* 07F520 800E6070 E4400070 */  swc1  $f0, 0x70($v0)
/* 07F524 800E6074 E4420074 */  swc1  $f2, 0x74($v0)
/* 07F528 800E6078 E4440078 */  swc1  $f4, 0x78($v0)
/* 07F52C 800E607C E446007C */  swc1  $f6, 0x7c($v0)
/* 07F530 800E6080 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07F534 800E6084 03E00008 */  jr    $ra
/* 07F538 800E6088 27BD0018 */   addiu $sp, $sp, 0x18

