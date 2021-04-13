.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FBEC
/* 2AFEC 8004FBEC 908300D4 */  lbu       $v1, 0xd4($a0)
/* 2AFF0 8004FBF0 24020001 */  addiu     $v0, $zero, 1
/* 2AFF4 8004FBF4 A0A00057 */  sb        $zero, 0x57($a1)
/* 2AFF8 8004FBF8 A0A20042 */  sb        $v0, 0x42($a1)
/* 2AFFC 8004FBFC 3063007F */  andi      $v1, $v1, 0x7f
/* 2B000 8004FC00 03E00008 */  jr        $ra
/* 2B004 8004FC04 A0A3004A */   sb       $v1, 0x4a($a1)
