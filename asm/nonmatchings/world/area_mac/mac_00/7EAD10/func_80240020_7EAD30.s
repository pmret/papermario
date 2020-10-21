.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_7EAD30
/* 7EAD30 80240020 3C028016 */  lui       $v0, 0x8016
/* 7EAD34 80240024 8442A552 */  lh        $v0, -0x5aae($v0)
/* 7EAD38 80240028 AC820084 */  sw        $v0, 0x84($a0)
/* 7EAD3C 8024002C 03E00008 */  jr        $ra
/* 7EAD40 80240030 24020002 */   addiu    $v0, $zero, 2
