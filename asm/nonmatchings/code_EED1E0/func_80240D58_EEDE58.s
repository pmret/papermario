.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nonmatchings_UnkPartnerPosFunc
/* EEDE58 80240D58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEDE5C 80240D5C AFBF0018 */  sw        $ra, 0x18($sp)
/* EEDE60 80240D60 0C00F94D */  jal       func_8003E534
/* EEDE64 80240D64 2404FFFC */   addiu    $a0, $zero, -4
/* EEDE68 80240D68 3C0141F0 */  lui       $at, 0x41f0
/* EEDE6C 80240D6C 44810000 */  mtc1      $at, $f0
/* EEDE70 80240D70 C442003C */  lwc1      $f2, 0x3c($v0)
/* EEDE74 80240D74 46001080 */  add.s     $f2, $f2, $f0
/* EEDE78 80240D78 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEDE7C 80240D7C 8C450038 */  lw        $a1, 0x38($v0)
/* EEDE80 80240D80 8C470040 */  lw        $a3, 0x40($v0)
/* EEDE84 80240D84 44061000 */  mfc1      $a2, $f2
/* EEDE88 80240D88 0C01D45C */  jal       func_80075170
/* EEDE8C 80240D8C 24040002 */   addiu    $a0, $zero, 2
/* EEDE90 80240D90 8FBF0018 */  lw        $ra, 0x18($sp)
/* EEDE94 80240D94 24020002 */  addiu     $v0, $zero, 2
/* EEDE98 80240D98 03E00008 */  jr        $ra
/* EEDE9C 80240D9C 27BD0020 */   addiu    $sp, $sp, 0x20
