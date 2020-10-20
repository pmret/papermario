.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F78
/* 95D178 80241F78 3C028025 */  lui       $v0, 0x8025
/* 95D17C 80241F7C 8C42DFE8 */  lw        $v0, -0x2018($v0)
/* 95D180 80241F80 8C43000C */  lw        $v1, 0xc($v0)
/* 95D184 80241F84 24020001 */  addiu     $v0, $zero, 1
/* 95D188 80241F88 AC62001C */  sw        $v0, 0x1c($v1)
/* 95D18C 80241F8C 03E00008 */  jr        $ra
/* 95D190 80241F90 24020002 */   addiu    $v0, $zero, 2
