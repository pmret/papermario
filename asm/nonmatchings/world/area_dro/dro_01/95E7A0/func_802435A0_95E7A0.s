.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435A0_95E7A0
/* 95E7A0 802435A0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 95E7A4 802435A4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 95E7A8 802435A8 8C430004 */  lw        $v1, 4($v0)
/* 95E7AC 802435AC 3C040010 */  lui       $a0, 0x10
/* 95E7B0 802435B0 00641825 */  or        $v1, $v1, $a0
/* 95E7B4 802435B4 AC430004 */  sw        $v1, 4($v0)
/* 95E7B8 802435B8 03E00008 */  jr        $ra
/* 95E7BC 802435BC 24020002 */   addiu    $v0, $zero, 2
