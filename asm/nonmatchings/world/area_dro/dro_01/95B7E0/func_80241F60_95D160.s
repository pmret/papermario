.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F60_95D160
/* 95D160 80241F60 3C028025 */  lui       $v0, 0x8025
/* 95D164 80241F64 8C42DFE8 */  lw        $v0, -0x2018($v0)
/* 95D168 80241F68 8C42000C */  lw        $v0, 0xc($v0)
/* 95D16C 80241F6C AC40001C */  sw        $zero, 0x1c($v0)
/* 95D170 80241F70 03E00008 */  jr        $ra
/* 95D174 80241F74 24020002 */   addiu    $v0, $zero, 2
