.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FCB4
/* 2B0B4 8004FCB4 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B0B8 8004FCB8 3042007F */  andi      $v0, $v0, 0x7f
/* 2B0BC 8004FCBC 54400001 */  bnel      $v0, $zero, .L8004FCC4
/* 2B0C0 8004FCC0 00021600 */   sll      $v0, $v0, 0x18
.L8004FCC4:
/* 2B0C4 8004FCC4 AC8200C0 */  sw        $v0, 0xc0($a0)
/* 2B0C8 8004FCC8 24020001 */  addiu     $v0, $zero, 1
/* 2B0CC 8004FCCC AC8000CC */  sw        $zero, 0xcc($a0)
/* 2B0D0 8004FCD0 AC8000C8 */  sw        $zero, 0xc8($a0)
/* 2B0D4 8004FCD4 AC8000C4 */  sw        $zero, 0xc4($a0)
/* 2B0D8 8004FCD8 A082021A */  sb        $v0, 0x21a($a0)
/* 2B0DC 8004FCDC 03E00008 */  jr        $ra
/* 2B0E0 8004FCE0 A0A20041 */   sb       $v0, 0x41($a1)
