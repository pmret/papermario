.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FF58
/* 2B358 8004FF58 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B35C 8004FF5C 24030001 */  addiu     $v1, $zero, 1
/* 2B360 8004FF60 A0A30043 */  sb        $v1, 0x43($a1)
/* 2B364 8004FF64 3042007F */  andi      $v0, $v0, 0x7f
/* 2B368 8004FF68 03E00008 */  jr        $ra
/* 2B36C 8004FF6C A0A2004B */   sb       $v0, 0x4b($a1)
