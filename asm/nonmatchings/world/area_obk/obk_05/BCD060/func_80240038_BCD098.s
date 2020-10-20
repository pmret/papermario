.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240038_BCD098
/* BCD098 80240038 3C028016 */  lui       $v0, 0x8016
/* BCD09C 8024003C 8442A552 */  lh        $v0, -0x5aae($v0)
/* BCD0A0 80240040 38420014 */  xori      $v0, $v0, 0x14
/* BCD0A4 80240044 2C420001 */  sltiu     $v0, $v0, 1
/* BCD0A8 80240048 03E00008 */  jr        $ra
/* BCD0AC 8024004C 00021040 */   sll      $v0, $v0, 1
