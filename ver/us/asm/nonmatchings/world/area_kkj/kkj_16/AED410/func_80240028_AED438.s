.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240028_AED438
/* AED438 80240028 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AED43C 8024002C AFBF0010 */  sw        $ra, 0x10($sp)
/* AED440 80240030 8C82000C */  lw        $v0, 0xc($a0)
/* AED444 80240034 0C0B210B */  jal       evt_get_float_variable
/* AED448 80240038 8C450000 */   lw       $a1, ($v0)
/* AED44C 8024003C 8FBF0010 */  lw        $ra, 0x10($sp)
/* AED450 80240040 4600008D */  trunc.w.s $f2, $f0
/* AED454 80240044 44021000 */  mfc1      $v0, $f2
/* AED458 80240048 00000000 */  nop
/* AED45C 8024004C 3C018011 */  lui       $at, %hi(gPlayerStatus+0xD)
/* AED460 80240050 A022EFD5 */  sb        $v0, %lo(gPlayerStatus+0xD)($at)
/* AED464 80240054 24020002 */  addiu     $v0, $zero, 2
/* AED468 80240058 03E00008 */  jr        $ra
/* AED46C 8024005C 27BD0018 */   addiu    $sp, $sp, 0x18
