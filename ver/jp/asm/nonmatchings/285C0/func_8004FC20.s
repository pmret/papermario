.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC20
/* 2B020 8004FC20 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B024 8004FC24 24030001 */  addiu     $v1, $zero, 1
/* 2B028 8004FC28 A0A30041 */  sb        $v1, 0x41($a1)
/* 2B02C 8004FC2C 3042007F */  andi      $v0, $v0, 0x7f
/* 2B030 8004FC30 03E00008 */  jr        $ra
/* 2B034 8004FC34 A0A20049 */   sb       $v0, 0x49($a1)
