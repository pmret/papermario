.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC1D0_E2EB00
/* E2EB00 802BC1D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2EB04 802BC1D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* E2EB08 802BC1D8 C4840048 */  lwc1      $f4, 0x48($a0)
/* E2EB0C 802BC1DC C486004C */  lwc1      $f6, 0x4c($a0)
/* E2EB10 802BC1E0 C4800064 */  lwc1      $f0, 0x64($a0)
/* E2EB14 802BC1E4 C4820050 */  lwc1      $f2, 0x50($a0)
/* E2EB18 802BC1E8 00A0202D */  daddu     $a0, $a1, $zero
/* E2EB1C 802BC1EC 4600020D */  trunc.w.s $f8, $f0
/* E2EB20 802BC1F0 E7A80010 */  swc1      $f8, 0x10($sp)
/* E2EB24 802BC1F4 4600220D */  trunc.w.s $f8, $f4
/* E2EB28 802BC1F8 44054000 */  mfc1      $a1, $f8
/* E2EB2C 802BC1FC 4600320D */  trunc.w.s $f8, $f6
/* E2EB30 802BC200 44064000 */  mfc1      $a2, $f8
/* E2EB34 802BC204 4600120D */  trunc.w.s $f8, $f2
/* E2EB38 802BC208 44074000 */  mfc1      $a3, $f8
/* E2EB3C 802BC20C 0C044631 */  jal       create_entity
/* E2EB40 802BC210 00000000 */   nop
/* E2EB44 802BC214 8FBF0018 */  lw        $ra, 0x18($sp)
/* E2EB48 802BC218 03E00008 */  jr        $ra
/* E2EB4C 802BC21C 27BD0020 */   addiu    $sp, $sp, 0x20
