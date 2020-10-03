.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CCDAC
/* F175C 802CCDAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F1760 802CCDB0 AFB10014 */  sw        $s1, 0x14($sp)
/* F1764 802CCDB4 0080882D */  daddu     $s1, $a0, $zero
/* F1768 802CCDB8 AFBF001C */  sw        $ra, 0x1c($sp)
/* F176C 802CCDBC AFB20018 */  sw        $s2, 0x18($sp)
/* F1770 802CCDC0 AFB00010 */  sw        $s0, 0x10($sp)
/* F1774 802CCDC4 8E30000C */  lw        $s0, 0xc($s1)
/* F1778 802CCDC8 8E050000 */  lw        $a1, ($s0)
/* F177C 802CCDCC 0C0B1EAF */  jal       get_variable
/* F1780 802CCDD0 26100004 */   addiu    $s0, $s0, 4
/* F1784 802CCDD4 0220202D */  daddu     $a0, $s1, $zero
/* F1788 802CCDD8 8E050000 */  lw        $a1, ($s0)
/* F178C 802CCDDC 0C0B1EAF */  jal       get_variable
/* F1790 802CCDE0 0040802D */   daddu    $s0, $v0, $zero
/* F1794 802CCDE4 0040902D */  daddu     $s2, $v0, $zero
/* F1798 802CCDE8 3C02802E */  lui       $v0, 0x802e
/* F179C 802CCDEC 8C42AE30 */  lw        $v0, -0x51d0($v0)
/* F17A0 802CCDF0 00108080 */  sll       $s0, $s0, 2
/* F17A4 802CCDF4 02028021 */  addu      $s0, $s0, $v0
/* F17A8 802CCDF8 8E100000 */  lw        $s0, ($s0)
/* F17AC 802CCDFC 0C04792E */  jal       func_8011E4B8
/* F17B0 802CCE00 0000202D */   daddu    $a0, $zero, $zero
/* F17B4 802CCE04 0040882D */  daddu     $s1, $v0, $zero
/* F17B8 802CCE08 0220202D */  daddu     $a0, $s1, $zero
/* F17BC 802CCE0C 0C04811D */  jal       func_80120474
/* F17C0 802CCE10 0240282D */   daddu    $a1, $s2, $zero
/* F17C4 802CCE14 3C013F80 */  lui       $at, 0x3f80
/* F17C8 802CCE18 44810000 */  mtc1      $at, $f0
/* F17CC 802CCE1C 26040028 */  addiu     $a0, $s0, 0x28
/* F17D0 802CCE20 AE110000 */  sw        $s1, ($s0)
/* F17D4 802CCE24 AE000004 */  sw        $zero, 4($s0)
/* F17D8 802CCE28 AE000008 */  sw        $zero, 8($s0)
/* F17DC 802CCE2C AE00000C */  sw        $zero, 0xc($s0)
/* F17E0 802CCE30 AE000010 */  sw        $zero, 0x10($s0)
/* F17E4 802CCE34 AE000014 */  sw        $zero, 0x14($s0)
/* F17E8 802CCE38 AE000018 */  sw        $zero, 0x18($s0)
/* F17EC 802CCE3C E600001C */  swc1      $f0, 0x1c($s0)
/* F17F0 802CCE40 E6000020 */  swc1      $f0, 0x20($s0)
/* F17F4 802CCE44 E6000024 */  swc1      $f0, 0x24($s0)
/* F17F8 802CCE48 0C019D10 */  jal       guMtxIdent
/* F17FC 802CCE4C AE000068 */   sw       $zero, 0x68($s0)
/* F1800 802CCE50 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1804 802CCE54 8FB20018 */  lw        $s2, 0x18($sp)
/* F1808 802CCE58 8FB10014 */  lw        $s1, 0x14($sp)
/* F180C 802CCE5C 8FB00010 */  lw        $s0, 0x10($sp)
/* F1810 802CCE60 24020002 */  addiu     $v0, $zero, 2
/* F1814 802CCE64 03E00008 */  jr        $ra
/* F1818 802CCE68 27BD0020 */   addiu    $sp, $sp, 0x20
