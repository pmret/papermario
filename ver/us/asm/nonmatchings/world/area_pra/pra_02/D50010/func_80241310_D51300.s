.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241310_D51300
/* D51300 80241310 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* D51304 80241314 AFB10014 */  sw        $s1, 0x14($sp)
/* D51308 80241318 0080882D */  daddu     $s1, $a0, $zero
/* D5130C 8024131C AFBF001C */  sw        $ra, 0x1c($sp)
/* D51310 80241320 AFB20018 */  sw        $s2, 0x18($sp)
/* D51314 80241324 AFB00010 */  sw        $s0, 0x10($sp)
/* D51318 80241328 F7B80030 */  sdc1      $f24, 0x30($sp)
/* D5131C 8024132C F7B60028 */  sdc1      $f22, 0x28($sp)
/* D51320 80241330 F7B40020 */  sdc1      $f20, 0x20($sp)
/* D51324 80241334 8E30000C */  lw        $s0, 0xc($s1)
/* D51328 80241338 8E050000 */  lw        $a1, ($s0)
/* D5132C 8024133C 0C0B1EAF */  jal       evt_get_variable
/* D51330 80241340 26100004 */   addiu    $s0, $s0, 4
/* D51334 80241344 8E050000 */  lw        $a1, ($s0)
/* D51338 80241348 26100004 */  addiu     $s0, $s0, 4
/* D5133C 8024134C 0220202D */  daddu     $a0, $s1, $zero
/* D51340 80241350 0C0B1EAF */  jal       evt_get_variable
/* D51344 80241354 0040902D */   daddu    $s2, $v0, $zero
/* D51348 80241358 8E050000 */  lw        $a1, ($s0)
/* D5134C 8024135C 26100004 */  addiu     $s0, $s0, 4
/* D51350 80241360 4482C000 */  mtc1      $v0, $f24
/* D51354 80241364 00000000 */  nop
/* D51358 80241368 4680C620 */  cvt.s.w   $f24, $f24
/* D5135C 8024136C 0C0B1EAF */  jal       evt_get_variable
/* D51360 80241370 0220202D */   daddu    $a0, $s1, $zero
/* D51364 80241374 8E050000 */  lw        $a1, ($s0)
/* D51368 80241378 4482B000 */  mtc1      $v0, $f22
/* D5136C 8024137C 00000000 */  nop
/* D51370 80241380 4680B5A0 */  cvt.s.w   $f22, $f22
/* D51374 80241384 0C0B1EAF */  jal       evt_get_variable
/* D51378 80241388 0220202D */   daddu    $a0, $s1, $zero
/* D5137C 8024138C 4482A000 */  mtc1      $v0, $f20
/* D51380 80241390 00000000 */  nop
/* D51384 80241394 4680A520 */  cvt.s.w   $f20, $f20
/* D51388 80241398 0C04417A */  jal       get_entity_by_index
/* D5138C 8024139C 0240202D */   daddu    $a0, $s2, $zero
/* D51390 802413A0 0040182D */  daddu     $v1, $v0, $zero
/* D51394 802413A4 E4780048 */  swc1      $f24, 0x48($v1)
/* D51398 802413A8 E476004C */  swc1      $f22, 0x4c($v1)
/* D5139C 802413AC E4740050 */  swc1      $f20, 0x50($v1)
/* D513A0 802413B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* D513A4 802413B4 8FB20018 */  lw        $s2, 0x18($sp)
/* D513A8 802413B8 8FB10014 */  lw        $s1, 0x14($sp)
/* D513AC 802413BC 8FB00010 */  lw        $s0, 0x10($sp)
/* D513B0 802413C0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* D513B4 802413C4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* D513B8 802413C8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D513BC 802413CC 24020002 */  addiu     $v0, $zero, 2
/* D513C0 802413D0 03E00008 */  jr        $ra
/* D513C4 802413D4 27BD0038 */   addiu    $sp, $sp, 0x38
