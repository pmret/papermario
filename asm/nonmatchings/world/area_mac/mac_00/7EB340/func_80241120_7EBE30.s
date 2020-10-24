.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241120_7EBE30
/* 7EBE30 80241120 3C028025 */  lui       $v0, 0x8025
/* 7EBE34 80241124 8C425B98 */  lw        $v0, 0x5b98($v0)
/* 7EBE38 80241128 8C42000C */  lw        $v0, 0xc($v0)
/* 7EBE3C 8024112C AC40001C */  sw        $zero, 0x1c($v0)
/* 7EBE40 80241130 03E00008 */  jr        $ra
/* 7EBE44 80241134 24020002 */   addiu    $v0, $zero, 2
