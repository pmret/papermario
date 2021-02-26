.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC08
/* 2B008 8004FC08 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B00C 8004FC0C 24030001 */  addiu     $v1, $zero, 1
/* 2B010 8004FC10 A0A30043 */  sb        $v1, 0x43($a1)
/* 2B014 8004FC14 3042007F */  andi      $v0, $v0, 0x7f
/* 2B018 8004FC18 03E00008 */  jr        $ra
/* 2B01C 8004FC1C A0A2004B */   sb       $v0, 0x4b($a1)
