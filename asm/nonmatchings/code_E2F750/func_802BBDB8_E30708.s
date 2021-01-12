.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBDB8_E30708
/* E30708 802BBDB8 C4800054 */  lwc1      $f0, 0x54($a0)
/* E3070C 802BBDBC 3C01802C */  lui       $at, %hi(D_802BCB90)
/* E30710 802BBDC0 D422CB90 */  ldc1      $f2, %lo(D_802BCB90)($at)
/* E30714 802BBDC4 46000021 */  cvt.d.s   $f0, $f0
/* E30718 802BBDC8 46220000 */  add.d     $f0, $f0, $f2
/* E3071C 802BBDCC 3C013FF0 */  lui       $at, 0x3ff0
/* E30720 802BBDD0 44811800 */  mtc1      $at, $f3
/* E30724 802BBDD4 44801000 */  mtc1      $zero, $f2
/* E30728 802BBDD8 46200020 */  cvt.s.d   $f0, $f0
/* E3072C 802BBDDC E4800054 */  swc1      $f0, 0x54($a0)
/* E30730 802BBDE0 46000021 */  cvt.d.s   $f0, $f0
/* E30734 802BBDE4 4620103E */  c.le.d    $f2, $f0
/* E30738 802BBDE8 00000000 */  nop       
/* E3073C 802BBDEC 45000005 */  bc1f      .L802BBE04
/* E30740 802BBDF0 00000000 */   nop      
/* E30744 802BBDF4 3C013F80 */  lui       $at, 0x3f80
/* E30748 802BBDF8 44810000 */  mtc1      $at, $f0
/* E3074C 802BBDFC 00000000 */  nop       
/* E30750 802BBE00 E4800054 */  swc1      $f0, 0x54($a0)
.L802BBE04:
/* E30754 802BBE04 C4800054 */  lwc1      $f0, 0x54($a0)
/* E30758 802BBE08 E4800058 */  swc1      $f0, 0x58($a0)
/* E3075C 802BBE0C 03E00008 */  jr        $ra
/* E30760 802BBE10 E480005C */   swc1     $f0, 0x5c($a0)
