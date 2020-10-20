.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240048_B028C8
/* B028C8 80240048 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B028CC 8024004C AFBF0010 */  sw        $ra, 0x10($sp)
/* B028D0 80240050 8C82000C */  lw        $v0, 0xc($a0)
/* B028D4 80240054 0C0B210B */  jal       get_float_variable
/* B028D8 80240058 8C450000 */   lw       $a1, ($v0)
/* B028DC 8024005C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B028E0 80240060 4600008D */  trunc.w.s $f2, $f0
/* B028E4 80240064 44021000 */  mfc1      $v0, $f2
/* B028E8 80240068 00000000 */  nop       
/* B028EC 8024006C 3C018011 */  lui       $at, 0x8011
/* B028F0 80240070 A022EFD5 */  sb        $v0, -0x102b($at)
/* B028F4 80240074 24020002 */  addiu     $v0, $zero, 2
/* B028F8 80240078 03E00008 */  jr        $ra
/* B028FC 8024007C 27BD0018 */   addiu    $sp, $sp, 0x18
