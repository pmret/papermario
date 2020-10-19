.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_982440
/* 982440 80240000 8C830148 */  lw        $v1, 0x148($a0)
/* 982444 80240004 24020003 */  addiu     $v0, $zero, 3
/* 982448 80240008 A06200B5 */  sb        $v0, 0xb5($v1)
/* 98244C 8024000C 03E00008 */  jr        $ra
/* 982450 80240010 24020002 */   addiu    $v0, $zero, 2
