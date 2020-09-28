.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AddAnimModelPosition
/* F1ADC 802CD12C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F1AE0 802CD130 AFB20018 */  sw        $s2, 0x18($sp)
/* F1AE4 802CD134 0080902D */  daddu     $s2, $a0, $zero
/* F1AE8 802CD138 AFBF001C */  sw        $ra, 0x1c($sp)
/* F1AEC 802CD13C AFB10014 */  sw        $s1, 0x14($sp)
/* F1AF0 802CD140 AFB00010 */  sw        $s0, 0x10($sp)
/* F1AF4 802CD144 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F1AF8 802CD148 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F1AFC 802CD14C 8E50000C */  lw        $s0, 0xc($s2)
/* F1B00 802CD150 8E050000 */  lw        $a1, ($s0)
/* F1B04 802CD154 0C0B1EAF */  jal       get_variable
/* F1B08 802CD158 26100004 */   addiu    $s0, $s0, 4
/* F1B0C 802CD15C 8E050000 */  lw        $a1, ($s0)
/* F1B10 802CD160 26100004 */  addiu     $s0, $s0, 4
/* F1B14 802CD164 0240202D */  daddu     $a0, $s2, $zero
/* F1B18 802CD168 0C0B210B */  jal       get_float_variable
/* F1B1C 802CD16C 0040882D */   daddu    $s1, $v0, $zero
/* F1B20 802CD170 8E050000 */  lw        $a1, ($s0)
/* F1B24 802CD174 26100004 */  addiu     $s0, $s0, 4
/* F1B28 802CD178 0240202D */  daddu     $a0, $s2, $zero
/* F1B2C 802CD17C 0C0B210B */  jal       get_float_variable
/* F1B30 802CD180 46000586 */   mov.s    $f22, $f0
/* F1B34 802CD184 0240202D */  daddu     $a0, $s2, $zero
/* F1B38 802CD188 8E050000 */  lw        $a1, ($s0)
/* F1B3C 802CD18C 0C0B210B */  jal       get_float_variable
/* F1B40 802CD190 46000506 */   mov.s    $f20, $f0
/* F1B44 802CD194 3C02802E */  lui       $v0, 0x802e
/* F1B48 802CD198 8C42AE30 */  lw        $v0, -0x51d0($v0)
/* F1B4C 802CD19C 00118880 */  sll       $s1, $s1, 2
/* F1B50 802CD1A0 02228821 */  addu      $s1, $s1, $v0
/* F1B54 802CD1A4 8E230000 */  lw        $v1, ($s1)
/* F1B58 802CD1A8 C4660004 */  lwc1      $f6, 4($v1)
/* F1B5C 802CD1AC 46163180 */  add.s     $f6, $f6, $f22
/* F1B60 802CD1B0 C4640008 */  lwc1      $f4, 8($v1)
/* F1B64 802CD1B4 46142100 */  add.s     $f4, $f4, $f20
/* F1B68 802CD1B8 C462000C */  lwc1      $f2, 0xc($v1)
/* F1B6C 802CD1BC 46001080 */  add.s     $f2, $f2, $f0
/* F1B70 802CD1C0 E4660004 */  swc1      $f6, 4($v1)
/* F1B74 802CD1C4 E4640008 */  swc1      $f4, 8($v1)
/* F1B78 802CD1C8 E462000C */  swc1      $f2, 0xc($v1)
/* F1B7C 802CD1CC 8FBF001C */  lw        $ra, 0x1c($sp)
/* F1B80 802CD1D0 8FB20018 */  lw        $s2, 0x18($sp)
/* F1B84 802CD1D4 8FB10014 */  lw        $s1, 0x14($sp)
/* F1B88 802CD1D8 8FB00010 */  lw        $s0, 0x10($sp)
/* F1B8C 802CD1DC D7B60028 */  ldc1      $f22, 0x28($sp)
/* F1B90 802CD1E0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F1B94 802CD1E4 24020002 */  addiu     $v0, $zero, 2
/* F1B98 802CD1E8 03E00008 */  jr        $ra
/* F1B9C 802CD1EC 27BD0030 */   addiu    $sp, $sp, 0x30
