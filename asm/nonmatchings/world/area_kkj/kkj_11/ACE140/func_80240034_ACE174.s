.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_ACE174
/* ACE174 80240034 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ACE178 80240038 AFBF0010 */  sw        $ra, 0x10($sp)
/* ACE17C 8024003C 8C82000C */  lw        $v0, 0xc($a0)
/* ACE180 80240040 0C0B210B */  jal       get_float_variable
/* ACE184 80240044 8C450000 */   lw       $a1, ($v0)
/* ACE188 80240048 8FBF0010 */  lw        $ra, 0x10($sp)
/* ACE18C 8024004C 4600008D */  trunc.w.s $f2, $f0
/* ACE190 80240050 44021000 */  mfc1      $v0, $f2
/* ACE194 80240054 00000000 */  nop       
/* ACE198 80240058 3C018011 */  lui       $at, 0x8011
/* ACE19C 8024005C A022EFD5 */  sb        $v0, -0x102b($at)
/* ACE1A0 80240060 24020002 */  addiu     $v0, $zero, 2
/* ACE1A4 80240064 03E00008 */  jr        $ra
/* ACE1A8 80240068 27BD0018 */   addiu    $sp, $sp, 0x18
/* ACE1AC 8024006C 00000000 */  nop       
