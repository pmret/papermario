.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_AD40C4
/* AD40C4 80240034 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AD40C8 80240038 AFBF0010 */  sw        $ra, 0x10($sp)
/* AD40CC 8024003C 8C82000C */  lw        $v0, 0xc($a0)
/* AD40D0 80240040 0C0B210B */  jal       get_float_variable
/* AD40D4 80240044 8C450000 */   lw       $a1, ($v0)
/* AD40D8 80240048 8FBF0010 */  lw        $ra, 0x10($sp)
/* AD40DC 8024004C 4600008D */  trunc.w.s $f2, $f0
/* AD40E0 80240050 44021000 */  mfc1      $v0, $f2
/* AD40E4 80240054 00000000 */  nop       
/* AD40E8 80240058 3C018011 */  lui       $at, 0x8011
/* AD40EC 8024005C A022EFD5 */  sb        $v0, -0x102b($at)
/* AD40F0 80240060 24020002 */  addiu     $v0, $zero, 2
/* AD40F4 80240064 03E00008 */  jr        $ra
/* AD40F8 80240068 27BD0018 */   addiu    $sp, $sp, 0x18
/* AD40FC 8024006C 00000000 */  nop       
