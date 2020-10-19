.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A80_B451F0
/* B451F0 80240A80 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B451F4 80240A84 AFB10014 */  sw        $s1, 0x14($sp)
/* B451F8 80240A88 0080882D */  daddu     $s1, $a0, $zero
/* B451FC 80240A8C AFBF001C */  sw        $ra, 0x1c($sp)
/* B45200 80240A90 AFB20018 */  sw        $s2, 0x18($sp)
/* B45204 80240A94 AFB00010 */  sw        $s0, 0x10($sp)
/* B45208 80240A98 F7B80030 */  sdc1      $f24, 0x30($sp)
/* B4520C 80240A9C F7B60028 */  sdc1      $f22, 0x28($sp)
/* B45210 80240AA0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B45214 80240AA4 8E30000C */  lw        $s0, 0xc($s1)
/* B45218 80240AA8 8E050000 */  lw        $a1, ($s0)
/* B4521C 80240AAC 0C0B1EAF */  jal       get_variable
/* B45220 80240AB0 26100004 */   addiu    $s0, $s0, 4
/* B45224 80240AB4 8E050000 */  lw        $a1, ($s0)
/* B45228 80240AB8 26100004 */  addiu     $s0, $s0, 4
/* B4522C 80240ABC 0220202D */  daddu     $a0, $s1, $zero
/* B45230 80240AC0 0C0B1EAF */  jal       get_variable
/* B45234 80240AC4 0040902D */   daddu    $s2, $v0, $zero
/* B45238 80240AC8 8E050000 */  lw        $a1, ($s0)
/* B4523C 80240ACC 26100004 */  addiu     $s0, $s0, 4
/* B45240 80240AD0 4482C000 */  mtc1      $v0, $f24
/* B45244 80240AD4 00000000 */  nop       
/* B45248 80240AD8 4680C620 */  cvt.s.w   $f24, $f24
/* B4524C 80240ADC 0C0B1EAF */  jal       get_variable
/* B45250 80240AE0 0220202D */   daddu    $a0, $s1, $zero
/* B45254 80240AE4 8E050000 */  lw        $a1, ($s0)
/* B45258 80240AE8 4482B000 */  mtc1      $v0, $f22
/* B4525C 80240AEC 00000000 */  nop       
/* B45260 80240AF0 4680B5A0 */  cvt.s.w   $f22, $f22
/* B45264 80240AF4 0C0B1EAF */  jal       get_variable
/* B45268 80240AF8 0220202D */   daddu    $a0, $s1, $zero
/* B4526C 80240AFC 4482A000 */  mtc1      $v0, $f20
/* B45270 80240B00 00000000 */  nop       
/* B45274 80240B04 4680A520 */  cvt.s.w   $f20, $f20
/* B45278 80240B08 0C04417A */  jal       get_entity_by_index
/* B4527C 80240B0C 0240202D */   daddu    $a0, $s2, $zero
/* B45280 80240B10 0040182D */  daddu     $v1, $v0, $zero
/* B45284 80240B14 E4780048 */  swc1      $f24, 0x48($v1)
/* B45288 80240B18 E476004C */  swc1      $f22, 0x4c($v1)
/* B4528C 80240B1C E4740050 */  swc1      $f20, 0x50($v1)
/* B45290 80240B20 8FBF001C */  lw        $ra, 0x1c($sp)
/* B45294 80240B24 8FB20018 */  lw        $s2, 0x18($sp)
/* B45298 80240B28 8FB10014 */  lw        $s1, 0x14($sp)
/* B4529C 80240B2C 8FB00010 */  lw        $s0, 0x10($sp)
/* B452A0 80240B30 D7B80030 */  ldc1      $f24, 0x30($sp)
/* B452A4 80240B34 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B452A8 80240B38 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B452AC 80240B3C 24020002 */  addiu     $v0, $zero, 2
/* B452B0 80240B40 03E00008 */  jr        $ra
/* B452B4 80240B44 27BD0038 */   addiu    $sp, $sp, 0x38
