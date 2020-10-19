.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_876F00
/* 876F00 80240020 3C028016 */  lui       $v0, 0x8016
/* 876F04 80240024 8442A552 */  lh        $v0, -0x5aae($v0)
/* 876F08 80240028 AC820084 */  sw        $v0, 0x84($a0)
/* 876F0C 8024002C 03E00008 */  jr        $ra
/* 876F10 80240030 24020002 */   addiu    $v0, $zero, 2
