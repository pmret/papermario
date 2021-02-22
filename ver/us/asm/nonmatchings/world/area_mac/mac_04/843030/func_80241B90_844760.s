.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B90_844760
/* 844760 80241B90 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 844764 80241B94 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 844768 80241B98 80620003 */  lb        $v0, 3($v1)
/* 84476C 80241B9C AC820084 */  sw        $v0, 0x84($a0)
/* 844770 80241BA0 80620006 */  lb        $v0, 6($v1)
/* 844774 80241BA4 AC820088 */  sw        $v0, 0x88($a0)
/* 844778 80241BA8 80620008 */  lb        $v0, 8($v1)
/* 84477C 80241BAC AC82008C */  sw        $v0, 0x8c($a0)
/* 844780 80241BB0 03E00008 */  jr        $ra
/* 844784 80241BB4 24020002 */   addiu    $v0, $zero, 2
