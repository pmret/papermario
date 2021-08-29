.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240038_BBD1D8
/* BBD1D8 80240038 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBD1DC 8024003C AFBF0010 */  sw        $ra, 0x10($sp)
/* BBD1E0 80240040 8C82000C */  lw        $v0, 0xc($a0)
/* BBD1E4 80240044 0C0B210B */  jal       evt_get_float_variable
/* BBD1E8 80240048 8C450000 */   lw       $a1, ($v0)
/* BBD1EC 8024004C 4600008D */  trunc.w.s $f2, $f0
/* BBD1F0 80240050 44021000 */  mfc1      $v0, $f2
/* BBD1F4 80240054 00000000 */  nop
/* BBD1F8 80240058 44820000 */  mtc1      $v0, $f0
/* BBD1FC 8024005C 00000000 */  nop
/* BBD200 80240060 46800020 */  cvt.s.w   $f0, $f0
/* BBD204 80240064 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBD208 80240068 24020002 */  addiu     $v0, $zero, 2
/* BBD20C 8024006C 3C01800B */  lui       $at, %hi(gCameras+0x18)
/* BBD210 80240070 E4201D98 */  swc1      $f0, %lo(gCameras+0x18)($at)
/* BBD214 80240074 03E00008 */  jr        $ra
/* BBD218 80240078 27BD0018 */   addiu    $sp, $sp, 0x18
