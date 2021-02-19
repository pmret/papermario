.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nonmatchings_UnkPartnerPosFunc
/* EEDEA0 80240DA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEDEA4 80240DA4 AFBF0018 */  sw        $ra, 0x18($sp)
/* EEDEA8 80240DA8 0C00F94D */  jal       func_8003E534
/* EEDEAC 80240DAC 2404FFFC */   addiu    $a0, $zero, -4
/* EEDEB0 80240DB0 3C0141F0 */  lui       $at, 0x41f0
/* EEDEB4 80240DB4 44810000 */  mtc1      $at, $f0
/* EEDEB8 80240DB8 C442003C */  lwc1      $f2, 0x3c($v0)
/* EEDEBC 80240DBC 46001080 */  add.s     $f2, $f2, $f0
/* EEDEC0 80240DC0 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEDEC4 80240DC4 8C450038 */  lw        $a1, 0x38($v0)
/* EEDEC8 80240DC8 8C470040 */  lw        $a3, 0x40($v0)
/* EEDECC 80240DCC 44061000 */  mfc1      $a2, $f2
/* EEDED0 80240DD0 0C01D45C */  jal       func_80075170
/* EEDED4 80240DD4 24040004 */   addiu    $a0, $zero, 4
/* EEDED8 80240DD8 8FBF0018 */  lw        $ra, 0x18($sp)
/* EEDEDC 80240DDC 24020002 */  addiu     $v0, $zero, 2
/* EEDEE0 80240DE0 03E00008 */  jr        $ra
/* EEDEE4 80240DE4 27BD0020 */   addiu    $sp, $sp, 0x20
