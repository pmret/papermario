.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_D89700
/* D89700 80240020 3C02FEFF */  lui       $v0, 0xfeff
/* D89704 80240024 3442FFFF */  ori       $v0, $v0, 0xffff
/* D89708 80240028 00822024 */  and       $a0, $a0, $v0
/* D8970C 8024002C 3C02FFF9 */  lui       $v0, 0xfff9
/* D89710 80240030 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D89714 80240034 00821821 */  addu      $v1, $a0, $v0
/* D89718 80240038 2C620010 */  sltiu     $v0, $v1, 0x10
/* D8971C 8024003C 10400003 */  beqz      $v0, .L8024004C
/* D89720 80240040 30620001 */   andi     $v0, $v1, 1
/* D89724 80240044 54400001 */  bnel      $v0, $zero, .L8024004C
/* D89728 80240048 2484FFFF */   addiu    $a0, $a0, -1
.L8024004C:
/* D8972C 8024004C 03E00008 */  jr        $ra
/* D89730 80240050 0080102D */   daddu    $v0, $a0, $zero
