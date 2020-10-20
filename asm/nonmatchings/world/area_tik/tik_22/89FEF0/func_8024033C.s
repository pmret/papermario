.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024033C
/* 8A01FC 8024033C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8A0200 80240340 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8A0204 80240344 8C430004 */  lw        $v1, 4($v0)
/* 8A0208 80240348 3C040010 */  lui       $a0, 0x10
/* 8A020C 8024034C 00641825 */  or        $v1, $v1, $a0
/* 8A0210 80240350 AC430004 */  sw        $v1, 4($v0)
/* 8A0214 80240354 03E00008 */  jr        $ra
/* 8A0218 80240358 24020002 */   addiu    $v0, $zero, 2
