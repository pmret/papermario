.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D90_8937B0
/* 8937B0 80240D90 3C028016 */  lui       $v0, 0x8016
/* 8937B4 80240D94 8442A552 */  lh        $v0, -0x5aae($v0)
/* 8937B8 80240D98 AC820084 */  sw        $v0, 0x84($a0)
/* 8937BC 80240D9C 03E00008 */  jr        $ra
/* 8937C0 80240DA0 24020002 */   addiu    $v0, $zero, 2
