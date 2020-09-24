.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D4364
/* F8D14 802D4364 3C02802E */  lui       $v0, 0x802e
/* F8D18 802D4368 8C42B7C0 */  lw        $v0, -0x4840($v0)
/* F8D1C 802D436C 00042080 */  sll       $a0, $a0, 2
/* F8D20 802D4370 00822021 */  addu      $a0, $a0, $v0
/* F8D24 802D4374 8C820000 */  lw        $v0, ($a0)
/* F8D28 802D4378 44850000 */  mtc1      $a1, $f0
/* F8D2C 802D437C 00000000 */  nop       
/* F8D30 802D4380 46800020 */  cvt.s.w   $f0, $f0
/* F8D34 802D4384 E4400004 */  swc1      $f0, 4($v0)
/* F8D38 802D4388 44860000 */  mtc1      $a2, $f0
/* F8D3C 802D438C 00000000 */  nop       
/* F8D40 802D4390 46800020 */  cvt.s.w   $f0, $f0
/* F8D44 802D4394 E4400008 */  swc1      $f0, 8($v0)
/* F8D48 802D4398 44870000 */  mtc1      $a3, $f0
/* F8D4C 802D439C 00000000 */  nop       
/* F8D50 802D43A0 46800020 */  cvt.s.w   $f0, $f0
/* F8D54 802D43A4 03E00008 */  jr        $ra
/* F8D58 802D43A8 E440000C */   swc1     $f0, 0xc($v0)
