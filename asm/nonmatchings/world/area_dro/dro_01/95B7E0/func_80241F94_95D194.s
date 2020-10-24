.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F94_95D194
/* 95D194 80241F94 3C028025 */  lui       $v0, 0x8025
/* 95D198 80241F98 8C42DFE8 */  lw        $v0, -0x2018($v0)
/* 95D19C 80241F9C 8C43000C */  lw        $v1, 0xc($v0)
/* 95D1A0 80241FA0 24020002 */  addiu     $v0, $zero, 2
/* 95D1A4 80241FA4 03E00008 */  jr        $ra
/* 95D1A8 80241FA8 AC62001C */   sw       $v0, 0x1c($v1)
