.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB298_E2DBC8
/* E2DBC8 802BB298 3C028016 */  lui       $v0, %hi(D_8015C7D0)
/* E2DBCC 802BB29C 2442C7D0 */  addiu     $v0, $v0, %lo(D_8015C7D0)
/* E2DBD0 802BB2A0 8C460000 */  lw        $a2, ($v0)
/* E2DBD4 802BB2A4 8C430004 */  lw        $v1, 4($v0)
/* E2DBD8 802BB2A8 8C450008 */  lw        $a1, 8($v0)
/* E2DBDC 802BB2AC 8C870040 */  lw        $a3, 0x40($a0)
/* E2DBE0 802BB2B0 00C31025 */  or        $v0, $a2, $v1
/* E2DBE4 802BB2B4 00451025 */  or        $v0, $v0, $a1
/* E2DBE8 802BB2B8 1440000E */  bnez      $v0, .L802BB2F4
/* E2DBEC 802BB2BC 00000000 */   nop      
/* E2DBF0 802BB2C0 C482004C */  lwc1      $f2, 0x4c($a0)
/* E2DBF4 802BB2C4 3C0142C8 */  lui       $at, 0x42c8
/* E2DBF8 802BB2C8 44810000 */  mtc1      $at, $f0
/* E2DBFC 802BB2CC 00000000 */  nop       
/* E2DC00 802BB2D0 46001080 */  add.s     $f2, $f2, $f0
/* E2DC04 802BB2D4 C4800048 */  lwc1      $f0, 0x48($a0)
/* E2DC08 802BB2D8 C4840050 */  lwc1      $f4, 0x50($a0)
/* E2DC0C 802BB2DC 4600018D */  trunc.w.s $f6, $f0
/* E2DC10 802BB2E0 44063000 */  mfc1      $a2, $f6
/* E2DC14 802BB2E4 4600218D */  trunc.w.s $f6, $f4
/* E2DC18 802BB2E8 44053000 */  mfc1      $a1, $f6
/* E2DC1C 802BB2EC 4600118D */  trunc.w.s $f6, $f2
/* E2DC20 802BB2F0 44033000 */  mfc1      $v1, $f6
.L802BB2F4:
/* E2DC24 802BB2F4 3C02802C */  lui       $v0, %hi(func_802BAE00_E2D730)
/* E2DC28 802BB2F8 2442AE00 */  addiu     $v0, $v0, %lo(func_802BAE00_E2D730)
/* E2DC2C 802BB2FC A4E60028 */  sh        $a2, 0x28($a3)
/* E2DC30 802BB300 A4E3002A */  sh        $v1, 0x2a($a3)
/* E2DC34 802BB304 A4E5002C */  sh        $a1, 0x2c($a3)
/* E2DC38 802BB308 A0E00002 */  sb        $zero, 2($a3)
/* E2DC3C 802BB30C 03E00008 */  jr        $ra
/* E2DC40 802BB310 AC82003C */   sw       $v0, 0x3c($a0)
