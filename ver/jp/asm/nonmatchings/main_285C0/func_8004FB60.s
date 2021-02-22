.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FB60
/* 2AF60 8004FB60 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2AF64 8004FB64 3042007F */  andi      $v0, $v0, 0x7f
/* 2AF68 8004FB68 54400001 */  bnel      $v0, $zero, .L8004FB70
/* 2AF6C 8004FB6C 00021600 */   sll      $v0, $v0, 0x18
.L8004FB70:
/* 2AF70 8004FB70 ACA20018 */  sw        $v0, 0x18($a1)
/* 2AF74 8004FB74 24020001 */  addiu     $v0, $zero, 1
/* 2AF78 8004FB78 03E00008 */  jr        $ra
/* 2AF7C 8004FB7C A0A20041 */   sb       $v0, 0x41($a1)
