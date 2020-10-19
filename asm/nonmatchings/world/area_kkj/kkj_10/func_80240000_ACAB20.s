.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_ACAB20
/* ACAB20 80240000 0000202D */  daddu     $a0, $zero, $zero
/* ACAB24 80240004 3C058015 */  lui       $a1, %hi(D_80151328)
/* ACAB28 80240008 24A51328 */  addiu     $a1, $a1, %lo(D_80151328)
/* ACAB2C 8024000C 0080182D */  daddu     $v1, $a0, $zero
.L80240010:
/* ACAB30 80240010 8CA20000 */  lw        $v0, ($a1)
/* ACAB34 80240014 24840001 */  addiu     $a0, $a0, 1
/* ACAB38 80240018 00431021 */  addu      $v0, $v0, $v1
/* ACAB3C 8024001C A0400004 */  sb        $zero, 4($v0)
/* ACAB40 80240020 28820007 */  slti      $v0, $a0, 7
/* ACAB44 80240024 1440FFFA */  bnez      $v0, .L80240010
/* ACAB48 80240028 24630018 */   addiu    $v1, $v1, 0x18
/* ACAB4C 8024002C 03E00008 */  jr        $ra
/* ACAB50 80240030 24020002 */   addiu    $v0, $zero, 2
