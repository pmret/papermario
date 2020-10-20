.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_8EBE70
/* 8EBE70 80240050 3C028016 */  lui       $v0, 0x8016
/* 8EBE74 80240054 8442A552 */  lh        $v0, -0x5aae($v0)
/* 8EBE78 80240058 AC820084 */  sw        $v0, 0x84($a0)
/* 8EBE7C 8024005C 03E00008 */  jr        $ra
/* 8EBE80 80240060 24020002 */   addiu    $v0, $zero, 2
