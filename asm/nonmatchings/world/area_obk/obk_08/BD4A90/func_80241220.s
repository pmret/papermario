.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241220
/* BD4A90 80241220 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD4A94 80241224 AFB20018 */  sw        $s2, 0x18($sp)
/* BD4A98 80241228 0080902D */  daddu     $s2, $a0, $zero
/* BD4A9C 8024122C 2404000B */  addiu     $a0, $zero, 0xb
/* BD4AA0 80241230 AFBF001C */  sw        $ra, 0x1c($sp)
/* BD4AA4 80241234 AFB10014 */  sw        $s1, 0x14($sp)
/* BD4AA8 80241238 0C00EABB */  jal       get_npc_unsafe
/* BD4AAC 8024123C AFB00010 */   sw       $s0, 0x10($sp)
/* BD4AB0 80241240 0000202D */  daddu     $a0, $zero, $zero
/* BD4AB4 80241244 0C00EABB */  jal       get_npc_unsafe
/* BD4AB8 80241248 0040882D */   daddu    $s1, $v0, $zero
/* BD4ABC 8024124C 0040802D */  daddu     $s0, $v0, $zero
/* BD4AC0 80241250 C6000038 */  lwc1      $f0, 0x38($s0)
/* BD4AC4 80241254 E6200038 */  swc1      $f0, 0x38($s1)
/* BD4AC8 80241258 C6000040 */  lwc1      $f0, 0x40($s0)
/* BD4ACC 8024125C E6200040 */  swc1      $f0, 0x40($s1)
/* BD4AD0 80241260 C6440084 */  lwc1      $f4, 0x84($s2)
/* BD4AD4 80241264 46802120 */  cvt.s.w   $f4, $f4
/* BD4AD8 80241268 8E050010 */  lw        $a1, 0x10($s0)
/* BD4ADC 8024126C 44062000 */  mfc1      $a2, $f4
/* BD4AE0 80241270 0C00EA95 */  jal       npc_move_heading
/* BD4AE4 80241274 0220202D */   daddu    $a0, $s1, $zero
/* BD4AE8 80241278 C600003C */  lwc1      $f0, 0x3c($s0)
/* BD4AEC 8024127C 3C01447A */  lui       $at, 0x447a
/* BD4AF0 80241280 44811000 */  mtc1      $at, $f2
/* BD4AF4 80241284 00000000 */  nop       
/* BD4AF8 80241288 46020000 */  add.s     $f0, $f0, $f2
/* BD4AFC 8024128C 3C0141C8 */  lui       $at, 0x41c8
/* BD4B00 80241290 44811000 */  mtc1      $at, $f2
/* BD4B04 80241294 00000000 */  nop       
/* BD4B08 80241298 46020000 */  add.s     $f0, $f0, $f2
/* BD4B0C 8024129C E620003C */  swc1      $f0, 0x3c($s1)
/* BD4B10 802412A0 8FBF001C */  lw        $ra, 0x1c($sp)
/* BD4B14 802412A4 8FB20018 */  lw        $s2, 0x18($sp)
/* BD4B18 802412A8 8FB10014 */  lw        $s1, 0x14($sp)
/* BD4B1C 802412AC 8FB00010 */  lw        $s0, 0x10($sp)
/* BD4B20 802412B0 24020002 */  addiu     $v0, $zero, 2
/* BD4B24 802412B4 03E00008 */  jr        $ra
/* BD4B28 802412B8 27BD0020 */   addiu    $sp, $sp, 0x20
