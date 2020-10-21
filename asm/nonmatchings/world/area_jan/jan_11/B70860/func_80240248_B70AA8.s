.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240248_B70AA8
/* B70AA8 80240248 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B70AAC 8024024C AFB10014 */  sw        $s1, 0x14($sp)
/* B70AB0 80240250 0080882D */  daddu     $s1, $a0, $zero
/* B70AB4 80240254 AFBF001C */  sw        $ra, 0x1c($sp)
/* B70AB8 80240258 AFB20018 */  sw        $s2, 0x18($sp)
/* B70ABC 8024025C 0C016AFA */  jal       get_current_map_header
/* B70AC0 80240260 AFB00010 */   sw       $s0, 0x10($sp)
/* B70AC4 80240264 0220202D */  daddu     $a0, $s1, $zero
/* B70AC8 80240268 3C05FE36 */  lui       $a1, 0xfe36
/* B70ACC 8024026C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* B70AD0 80240270 0C0B1EAF */  jal       get_variable
/* B70AD4 80240274 0040902D */   daddu    $s2, $v0, $zero
/* B70AD8 80240278 0220202D */  daddu     $a0, $s1, $zero
/* B70ADC 8024027C 3C05FE36 */  lui       $a1, 0xfe36
/* B70AE0 80240280 8E430014 */  lw        $v1, 0x14($s2)
/* B70AE4 80240284 00028100 */  sll       $s0, $v0, 4
/* B70AE8 80240288 02031821 */  addu      $v1, $s0, $v1
/* B70AEC 8024028C C4600000 */  lwc1      $f0, ($v1)
/* B70AF0 80240290 4600008D */  trunc.w.s $f2, $f0
/* B70AF4 80240294 44061000 */  mfc1      $a2, $f2
/* B70AF8 80240298 0C0B2026 */  jal       set_variable
/* B70AFC 8024029C 34A53C81 */   ori      $a1, $a1, 0x3c81
/* B70B00 802402A0 0220202D */  daddu     $a0, $s1, $zero
/* B70B04 802402A4 8E420014 */  lw        $v0, 0x14($s2)
/* B70B08 802402A8 3C05FE36 */  lui       $a1, 0xfe36
/* B70B0C 802402AC 02021021 */  addu      $v0, $s0, $v0
/* B70B10 802402B0 C4400004 */  lwc1      $f0, 4($v0)
/* B70B14 802402B4 4600008D */  trunc.w.s $f2, $f0
/* B70B18 802402B8 44061000 */  mfc1      $a2, $f2
/* B70B1C 802402BC 0C0B2026 */  jal       set_variable
/* B70B20 802402C0 34A53C82 */   ori      $a1, $a1, 0x3c82
/* B70B24 802402C4 0220202D */  daddu     $a0, $s1, $zero
/* B70B28 802402C8 8E420014 */  lw        $v0, 0x14($s2)
/* B70B2C 802402CC 3C05FE36 */  lui       $a1, 0xfe36
/* B70B30 802402D0 02021021 */  addu      $v0, $s0, $v0
/* B70B34 802402D4 C4400008 */  lwc1      $f0, 8($v0)
/* B70B38 802402D8 4600008D */  trunc.w.s $f2, $f0
/* B70B3C 802402DC 44061000 */  mfc1      $a2, $f2
/* B70B40 802402E0 0C0B2026 */  jal       set_variable
/* B70B44 802402E4 34A53C83 */   ori      $a1, $a1, 0x3c83
/* B70B48 802402E8 0220202D */  daddu     $a0, $s1, $zero
/* B70B4C 802402EC 8E420014 */  lw        $v0, 0x14($s2)
/* B70B50 802402F0 3C05FE36 */  lui       $a1, 0xfe36
/* B70B54 802402F4 02028021 */  addu      $s0, $s0, $v0
/* B70B58 802402F8 C600000C */  lwc1      $f0, 0xc($s0)
/* B70B5C 802402FC 4600008D */  trunc.w.s $f2, $f0
/* B70B60 80240300 44061000 */  mfc1      $a2, $f2
/* B70B64 80240304 0C0B2026 */  jal       set_variable
/* B70B68 80240308 34A53C84 */   ori      $a1, $a1, 0x3c84
/* B70B6C 8024030C 8FBF001C */  lw        $ra, 0x1c($sp)
/* B70B70 80240310 8FB20018 */  lw        $s2, 0x18($sp)
/* B70B74 80240314 8FB10014 */  lw        $s1, 0x14($sp)
/* B70B78 80240318 8FB00010 */  lw        $s0, 0x10($sp)
/* B70B7C 8024031C 24020002 */  addiu     $v0, $zero, 2
/* B70B80 80240320 03E00008 */  jr        $ra
/* B70B84 80240324 27BD0020 */   addiu    $sp, $sp, 0x20
