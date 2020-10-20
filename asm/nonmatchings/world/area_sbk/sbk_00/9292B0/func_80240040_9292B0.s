.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_9292B0
/* 9292B0 80240040 8C830148 */  lw        $v1, 0x148($a0)
/* 9292B4 80240044 24020003 */  addiu     $v0, $zero, 3
/* 9292B8 80240048 A06200B5 */  sb        $v0, 0xb5($v1)
/* 9292BC 8024004C 03E00008 */  jr        $ra
/* 9292C0 80240050 24020002 */   addiu    $v0, $zero, 2
/* 9292C4 80240054 00000000 */  nop       
/* 9292C8 80240058 00000000 */  nop       
/* 9292CC 8024005C 00000000 */  nop       
