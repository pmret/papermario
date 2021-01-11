.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC630_E2EF60
/* E2EF60 802BC630 8C820040 */  lw        $v0, 0x40($a0)
/* E2EF64 802BC634 3C018016 */  lui       $at, %hi(D_8015C7D0)
/* E2EF68 802BC638 C420C7D0 */  lwc1      $f0, %lo(D_8015C7D0)($at)
/* E2EF6C 802BC63C 46800020 */  cvt.s.w   $f0, $f0
/* E2EF70 802BC640 E4400004 */  swc1      $f0, 4($v0)
/* E2EF74 802BC644 E4400008 */  swc1      $f0, 8($v0)
/* E2EF78 802BC648 3C02802C */  lui       $v0, %hi(func_802BC4B0_E2EDE0)
/* E2EF7C 802BC64C 2442C4B0 */  addiu     $v0, $v0, %lo(func_802BC4B0_E2EDE0)
/* E2EF80 802BC650 03E00008 */  jr        $ra
/* E2EF84 802BC654 AC82003C */   sw       $v0, 0x3c($a0)
