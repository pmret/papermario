.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_956A30
/* 956A30 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 956A34 80240044 24020003 */  addiu     $v0, $zero, 3
/* 956A38 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 956A3C 8024004C 03E00008 */  jr        $ra
/* 956A40 80240050 24020002 */   addiu    $v0, $zero, 2
/* 956A44 80240054 00000000 */  nop       
/* 956A48 80240058 00000000 */  nop       
/* 956A4C 8024005C 00000000 */  nop       
