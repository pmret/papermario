.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F8_D700A8
/* D700A8 802416F8 C4800084 */  lwc1      $f0, 0x84($a0)
/* D700AC 802416FC 46800020 */  cvt.s.w   $f0, $f0
/* D700B0 80241700 3C018011 */  lui       $at, 0x8011
/* D700B4 80241704 E420F070 */  swc1      $f0, -0xf90($at)
/* D700B8 80241708 03E00008 */  jr        $ra
/* D700BC 8024170C 24020002 */   addiu    $v0, $zero, 2
