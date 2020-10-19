.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240448_D2C178
/* D2C178 80240448 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* D2C17C 8024044C AFB10014 */  sw        $s1, 0x14($sp)
/* D2C180 80240450 0080882D */  daddu     $s1, $a0, $zero
/* D2C184 80240454 AFBF001C */  sw        $ra, 0x1c($sp)
/* D2C188 80240458 AFB20018 */  sw        $s2, 0x18($sp)
/* D2C18C 8024045C AFB00010 */  sw        $s0, 0x10($sp)
/* D2C190 80240460 F7B80030 */  sdc1      $f24, 0x30($sp)
/* D2C194 80240464 F7B60028 */  sdc1      $f22, 0x28($sp)
/* D2C198 80240468 F7B40020 */  sdc1      $f20, 0x20($sp)
/* D2C19C 8024046C 8E30000C */  lw        $s0, 0xc($s1)
/* D2C1A0 80240470 8E050000 */  lw        $a1, ($s0)
/* D2C1A4 80240474 0C0B1EAF */  jal       get_variable
/* D2C1A8 80240478 26100004 */   addiu    $s0, $s0, 4
/* D2C1AC 8024047C 8E050000 */  lw        $a1, ($s0)
/* D2C1B0 80240480 26100004 */  addiu     $s0, $s0, 4
/* D2C1B4 80240484 0220202D */  daddu     $a0, $s1, $zero
/* D2C1B8 80240488 0C0B1EAF */  jal       get_variable
/* D2C1BC 8024048C 0040902D */   daddu    $s2, $v0, $zero
/* D2C1C0 80240490 8E050000 */  lw        $a1, ($s0)
/* D2C1C4 80240494 26100004 */  addiu     $s0, $s0, 4
/* D2C1C8 80240498 4482C000 */  mtc1      $v0, $f24
/* D2C1CC 8024049C 00000000 */  nop       
/* D2C1D0 802404A0 4680C620 */  cvt.s.w   $f24, $f24
/* D2C1D4 802404A4 0C0B1EAF */  jal       get_variable
/* D2C1D8 802404A8 0220202D */   daddu    $a0, $s1, $zero
/* D2C1DC 802404AC 8E050000 */  lw        $a1, ($s0)
/* D2C1E0 802404B0 4482B000 */  mtc1      $v0, $f22
/* D2C1E4 802404B4 00000000 */  nop       
/* D2C1E8 802404B8 4680B5A0 */  cvt.s.w   $f22, $f22
/* D2C1EC 802404BC 0C0B1EAF */  jal       get_variable
/* D2C1F0 802404C0 0220202D */   daddu    $a0, $s1, $zero
/* D2C1F4 802404C4 4482A000 */  mtc1      $v0, $f20
/* D2C1F8 802404C8 00000000 */  nop       
/* D2C1FC 802404CC 4680A520 */  cvt.s.w   $f20, $f20
/* D2C200 802404D0 0C04417A */  jal       get_entity_by_index
/* D2C204 802404D4 0240202D */   daddu    $a0, $s2, $zero
/* D2C208 802404D8 0040182D */  daddu     $v1, $v0, $zero
/* D2C20C 802404DC E4780048 */  swc1      $f24, 0x48($v1)
/* D2C210 802404E0 E476004C */  swc1      $f22, 0x4c($v1)
/* D2C214 802404E4 E4740050 */  swc1      $f20, 0x50($v1)
/* D2C218 802404E8 8FBF001C */  lw        $ra, 0x1c($sp)
/* D2C21C 802404EC 8FB20018 */  lw        $s2, 0x18($sp)
/* D2C220 802404F0 8FB10014 */  lw        $s1, 0x14($sp)
/* D2C224 802404F4 8FB00010 */  lw        $s0, 0x10($sp)
/* D2C228 802404F8 D7B80030 */  ldc1      $f24, 0x30($sp)
/* D2C22C 802404FC D7B60028 */  ldc1      $f22, 0x28($sp)
/* D2C230 80240500 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D2C234 80240504 24020002 */  addiu     $v0, $zero, 2
/* D2C238 80240508 03E00008 */  jr        $ra
/* D2C23C 8024050C 27BD0038 */   addiu    $sp, $sp, 0x38
