.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_D588B0
/* D588B0 80240020 3C02FEFF */  lui       $v0, 0xfeff
/* D588B4 80240024 3442FFFF */  ori       $v0, $v0, 0xffff
/* D588B8 80240028 00822024 */  and       $a0, $a0, $v0
/* D588BC 8024002C 3C02FFF9 */  lui       $v0, 0xfff9
/* D588C0 80240030 3442FFF4 */  ori       $v0, $v0, 0xfff4
/* D588C4 80240034 00821821 */  addu      $v1, $a0, $v0
/* D588C8 80240038 2C620010 */  sltiu     $v0, $v1, 0x10
/* D588CC 8024003C 10400003 */  beqz      $v0, .L8024004C
/* D588D0 80240040 30620001 */   andi     $v0, $v1, 1
/* D588D4 80240044 54400001 */  bnel      $v0, $zero, .L8024004C
/* D588D8 80240048 2484FFFF */   addiu    $a0, $a0, -1
.L8024004C:
/* D588DC 8024004C 03E00008 */  jr        $ra
/* D588E0 80240050 0080102D */   daddu    $v0, $a0, $zero
