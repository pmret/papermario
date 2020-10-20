.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240038_953FF8
/* 953FF8 80240038 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 953FFC 8024003C 0000202D */  daddu     $a0, $zero, $zero
/* 954000 80240040 AFBF0010 */  sw        $ra, 0x10($sp)
/* 954004 80240044 0C052AED */  jal       func_8014ABB4
/* 954008 80240048 24050001 */   addiu    $a1, $zero, 1
/* 95400C 8024004C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 954010 80240050 24020002 */  addiu     $v0, $zero, 2
/* 954014 80240054 03E00008 */  jr        $ra
/* 954018 80240058 27BD0018 */   addiu    $sp, $sp, 0x18
