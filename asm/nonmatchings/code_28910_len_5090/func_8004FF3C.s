.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FF3C
/* 2B33C 8004FF3C 908300D4 */  lbu       $v1, 0xd4($a0)
/* 2B340 8004FF40 24020001 */  addiu     $v0, $zero, 1
/* 2B344 8004FF44 A0A00057 */  sb        $zero, 0x57($a1)
/* 2B348 8004FF48 A0A20042 */  sb        $v0, 0x42($a1)
/* 2B34C 8004FF4C 3063007F */  andi      $v1, $v1, 0x7f
/* 2B350 8004FF50 03E00008 */  jr        $ra
/* 2B354 8004FF54 A0A3004A */   sb       $v1, 0x4a($a1)
