.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_EB7540
/* EB7540 80240310 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EB7544 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* EB7548 80240318 0080882D */  daddu     $s1, $a0, $zero
/* EB754C 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* EB7550 80240320 AFB20018 */  sw        $s2, 0x18($sp)
/* EB7554 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* EB7558 80240328 F7B80030 */  sdc1      $f24, 0x30($sp)
/* EB755C 8024032C F7B60028 */  sdc1      $f22, 0x28($sp)
/* EB7560 80240330 F7B40020 */  sdc1      $f20, 0x20($sp)
/* EB7564 80240334 8E30000C */  lw        $s0, 0xc($s1)
/* EB7568 80240338 8E050000 */  lw        $a1, ($s0)
/* EB756C 8024033C 0C0B53A3 */  jal       dead_get_variable
/* EB7570 80240340 26100004 */   addiu    $s0, $s0, 4
/* EB7574 80240344 8E050000 */  lw        $a1, ($s0)
/* EB7578 80240348 26100004 */  addiu     $s0, $s0, 4
/* EB757C 8024034C 0220202D */  daddu     $a0, $s1, $zero
/* EB7580 80240350 0C0B53A3 */  jal       dead_get_variable
/* EB7584 80240354 0040902D */   daddu    $s2, $v0, $zero
/* EB7588 80240358 8E050000 */  lw        $a1, ($s0)
/* EB758C 8024035C 26100004 */  addiu     $s0, $s0, 4
/* EB7590 80240360 4482C000 */  mtc1      $v0, $f24
/* EB7594 80240364 00000000 */  nop
/* EB7598 80240368 4680C620 */  cvt.s.w   $f24, $f24
/* EB759C 8024036C 0C0B53A3 */  jal       dead_get_variable
/* EB75A0 80240370 0220202D */   daddu    $a0, $s1, $zero
/* EB75A4 80240374 8E050000 */  lw        $a1, ($s0)
/* EB75A8 80240378 4482B000 */  mtc1      $v0, $f22
/* EB75AC 8024037C 00000000 */  nop
/* EB75B0 80240380 4680B5A0 */  cvt.s.w   $f22, $f22
/* EB75B4 80240384 0C0B53A3 */  jal       dead_get_variable
/* EB75B8 80240388 0220202D */   daddu    $a0, $s1, $zero
/* EB75BC 8024038C 4482A000 */  mtc1      $v0, $f20
/* EB75C0 80240390 00000000 */  nop
/* EB75C4 80240394 4680A520 */  cvt.s.w   $f20, $f20
/* EB75C8 80240398 0C0462EC */  jal       func_80118BB0
/* EB75CC 8024039C 0240202D */   daddu    $a0, $s2, $zero
/* EB75D0 802403A0 0040182D */  daddu     $v1, $v0, $zero
/* EB75D4 802403A4 E4780048 */  swc1      $f24, 0x48($v1)
/* EB75D8 802403A8 E476004C */  swc1      $f22, 0x4c($v1)
/* EB75DC 802403AC E4740050 */  swc1      $f20, 0x50($v1)
/* EB75E0 802403B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* EB75E4 802403B4 8FB20018 */  lw        $s2, 0x18($sp)
/* EB75E8 802403B8 8FB10014 */  lw        $s1, 0x14($sp)
/* EB75EC 802403BC 8FB00010 */  lw        $s0, 0x10($sp)
/* EB75F0 802403C0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* EB75F4 802403C4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* EB75F8 802403C8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* EB75FC 802403CC 24020002 */  addiu     $v0, $zero, 2
/* EB7600 802403D0 03E00008 */  jr        $ra
/* EB7604 802403D4 27BD0038 */   addiu    $sp, $sp, 0x38
