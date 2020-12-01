.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E0514
/* 799C4 800E0514 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 799C8 800E0518 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 799CC 800E051C 8C430004 */  lw        $v1, 4($v0)
/* 799D0 800E0520 2404FFBF */  addiu     $a0, $zero, -0x41
/* 799D4 800E0524 3C018011 */  lui       $at, %hi(D_8010C920)
/* 799D8 800E0528 AC20C920 */  sw        $zero, %lo(D_8010C920)($at)
/* 799DC 800E052C 00641824 */  and       $v1, $v1, $a0
/* 799E0 800E0530 03E00008 */  jr        $ra
/* 799E4 800E0534 AC430004 */   sw       $v1, 4($v0)
