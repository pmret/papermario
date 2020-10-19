.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_8B0090
/* 8B0090 80240020 3C028016 */  lui       $v0, 0x8016
/* 8B0094 80240024 8442A552 */  lh        $v0, -0x5aae($v0)
/* 8B0098 80240028 AC820084 */  sw        $v0, 0x84($a0)
/* 8B009C 8024002C 03E00008 */  jr        $ra
/* 8B00A0 80240030 24020002 */   addiu    $v0, $zero, 2
