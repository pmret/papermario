.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241780_8ED5A0
/* 8ED5A0 80241780 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8ED5A4 80241784 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8ED5A8 80241788 8C430004 */  lw        $v1, 4($v0)
/* 8ED5AC 8024178C 3C040010 */  lui       $a0, 0x10
/* 8ED5B0 80241790 00641825 */  or        $v1, $v1, $a0
/* 8ED5B4 80241794 AC430004 */  sw        $v1, 4($v0)
/* 8ED5B8 80241798 03E00008 */  jr        $ra
/* 8ED5BC 8024179C 24020002 */   addiu    $v0, $zero, 2
