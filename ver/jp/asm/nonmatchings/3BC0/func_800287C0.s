.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800287C0
/* 3BC0 800287C0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 3BC4 800287C4 2463417C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 3BC8 800287C8 8C620000 */  lw        $v0, ($v1)
/* 3BCC 800287CC A0400040 */  sb        $zero, 0x40($v0)
/* 3BD0 800287D0 8C640000 */  lw        $a0, ($v1)
/* 3BD4 800287D4 AC400000 */  sw        $zero, ($v0)
/* 3BD8 800287D8 AC400010 */  sw        $zero, 0x10($v0)
/* 3BDC 800287DC AC400020 */  sw        $zero, 0x20($v0)
/* 3BE0 800287E0 A0800044 */  sb        $zero, 0x44($a0)
/* 3BE4 800287E4 8C630000 */  lw        $v1, ($v1)
/* 3BE8 800287E8 24020004 */  addiu     $v0, $zero, 4
/* 3BEC 800287EC A4620050 */  sh        $v0, 0x50($v1)
/* 3BF0 800287F0 2402000F */  addiu     $v0, $zero, 0xf
/* 3BF4 800287F4 AC600030 */  sw        $zero, 0x30($v1)
/* 3BF8 800287F8 A4620048 */  sh        $v0, 0x48($v1)
/* 3BFC 800287FC A4600060 */  sh        $zero, 0x60($v1)
/* 3C00 80028800 03E00008 */  jr        $ra
/* 3C04 80028804 A4600058 */   sh       $zero, 0x58($v1)
