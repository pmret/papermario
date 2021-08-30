.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_C9C610
/* C9C610 80240310 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C9C614 80240314 AFB10014 */  sw        $s1, 0x14($sp)
/* C9C618 80240318 0080882D */  daddu     $s1, $a0, $zero
/* C9C61C 8024031C AFBF001C */  sw        $ra, 0x1c($sp)
/* C9C620 80240320 AFB20018 */  sw        $s2, 0x18($sp)
/* C9C624 80240324 AFB00010 */  sw        $s0, 0x10($sp)
/* C9C628 80240328 F7B80030 */  sdc1      $f24, 0x30($sp)
/* C9C62C 8024032C F7B60028 */  sdc1      $f22, 0x28($sp)
/* C9C630 80240330 F7B40020 */  sdc1      $f20, 0x20($sp)
/* C9C634 80240334 8E30000C */  lw        $s0, 0xc($s1)
/* C9C638 80240338 8E050000 */  lw        $a1, ($s0)
/* C9C63C 8024033C 0C0B1EAF */  jal       evt_get_variable
/* C9C640 80240340 26100004 */   addiu    $s0, $s0, 4
/* C9C644 80240344 8E050000 */  lw        $a1, ($s0)
/* C9C648 80240348 26100004 */  addiu     $s0, $s0, 4
/* C9C64C 8024034C 0220202D */  daddu     $a0, $s1, $zero
/* C9C650 80240350 0C0B1EAF */  jal       evt_get_variable
/* C9C654 80240354 0040902D */   daddu    $s2, $v0, $zero
/* C9C658 80240358 8E050000 */  lw        $a1, ($s0)
/* C9C65C 8024035C 26100004 */  addiu     $s0, $s0, 4
/* C9C660 80240360 4482C000 */  mtc1      $v0, $f24
/* C9C664 80240364 00000000 */  nop
/* C9C668 80240368 4680C620 */  cvt.s.w   $f24, $f24
/* C9C66C 8024036C 0C0B1EAF */  jal       evt_get_variable
/* C9C670 80240370 0220202D */   daddu    $a0, $s1, $zero
/* C9C674 80240374 8E050000 */  lw        $a1, ($s0)
/* C9C678 80240378 4482B000 */  mtc1      $v0, $f22
/* C9C67C 8024037C 00000000 */  nop
/* C9C680 80240380 4680B5A0 */  cvt.s.w   $f22, $f22
/* C9C684 80240384 0C0B1EAF */  jal       evt_get_variable
/* C9C688 80240388 0220202D */   daddu    $a0, $s1, $zero
/* C9C68C 8024038C 4482A000 */  mtc1      $v0, $f20
/* C9C690 80240390 00000000 */  nop
/* C9C694 80240394 4680A520 */  cvt.s.w   $f20, $f20
/* C9C698 80240398 0C04417A */  jal       get_entity_by_index
/* C9C69C 8024039C 0240202D */   daddu    $a0, $s2, $zero
/* C9C6A0 802403A0 0040182D */  daddu     $v1, $v0, $zero
/* C9C6A4 802403A4 E4780048 */  swc1      $f24, 0x48($v1)
/* C9C6A8 802403A8 E476004C */  swc1      $f22, 0x4c($v1)
/* C9C6AC 802403AC E4740050 */  swc1      $f20, 0x50($v1)
/* C9C6B0 802403B0 8FBF001C */  lw        $ra, 0x1c($sp)
/* C9C6B4 802403B4 8FB20018 */  lw        $s2, 0x18($sp)
/* C9C6B8 802403B8 8FB10014 */  lw        $s1, 0x14($sp)
/* C9C6BC 802403BC 8FB00010 */  lw        $s0, 0x10($sp)
/* C9C6C0 802403C0 D7B80030 */  ldc1      $f24, 0x30($sp)
/* C9C6C4 802403C4 D7B60028 */  ldc1      $f22, 0x28($sp)
/* C9C6C8 802403C8 D7B40020 */  ldc1      $f20, 0x20($sp)
/* C9C6CC 802403CC 24020002 */  addiu     $v0, $zero, 2
/* C9C6D0 802403D0 03E00008 */  jr        $ra
/* C9C6D4 802403D4 27BD0038 */   addiu    $sp, $sp, 0x38
