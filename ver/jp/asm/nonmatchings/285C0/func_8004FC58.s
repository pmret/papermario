.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC58
/* 2B058 8004FC58 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B05C 8004FC5C 03E00008 */  jr        $ra
/* 2B060 8004FC60 A0A20048 */   sb       $v0, 0x48($a1)
