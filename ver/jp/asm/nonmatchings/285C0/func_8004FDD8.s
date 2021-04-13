.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FDD8
/* 2B1D8 8004FDD8 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B1DC 8004FDDC 00821821 */  addu      $v1, $a0, $v0
/* 2B1E0 8004FDE0 2C420004 */  sltiu     $v0, $v0, 4
/* 2B1E4 8004FDE4 9063004C */  lbu       $v1, 0x4c($v1)
/* 2B1E8 8004FDE8 10400005 */  beqz      $v0, .L8004FE00
/* 2B1EC 8004FDEC 00031600 */   sll      $v0, $v1, 0x18
/* 2B1F0 8004FDF0 04400003 */  bltz      $v0, .L8004FE00
/* 2B1F4 8004FDF4 00000000 */   nop
/* 2B1F8 8004FDF8 03E00008 */  jr        $ra
/* 2B1FC 8004FDFC A0A3005B */   sb       $v1, 0x5b($a1)
.L8004FE00:
/* 2B200 8004FE00 90820235 */  lbu       $v0, 0x235($a0)
/* 2B204 8004FE04 03E00008 */  jr        $ra
/* 2B208 8004FE08 A0A2005B */   sb       $v0, 0x5b($a1)
