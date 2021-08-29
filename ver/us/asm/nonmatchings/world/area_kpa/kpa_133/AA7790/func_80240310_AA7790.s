.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_AA7790
/* AA7790 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AA7794 80240314 AFB20018 */  sw        $s2, 0x18($sp)
/* AA7798 80240318 0080902D */  daddu     $s2, $a0, $zero
/* AA779C 8024031C 0000202D */  daddu     $a0, $zero, $zero
/* AA77A0 80240320 3C05FD05 */  lui       $a1, 0xfd05
/* AA77A4 80240324 AFBF001C */  sw        $ra, 0x1c($sp)
/* AA77A8 80240328 AFB10014 */  sw        $s1, 0x14($sp)
/* AA77AC 8024032C AFB00010 */  sw        $s0, 0x10($sp)
/* AA77B0 80240330 8E50000C */  lw        $s0, 0xc($s2)
/* AA77B4 80240334 0C0B1EAF */  jal       evt_get_variable
/* AA77B8 80240338 34A50F80 */   ori      $a1, $a1, 0xf80
/* AA77BC 8024033C 0C04417A */  jal       get_entity_by_index
/* AA77C0 80240340 0040202D */   daddu    $a0, $v0, $zero
/* AA77C4 80240344 0240202D */  daddu     $a0, $s2, $zero
/* AA77C8 80240348 0040882D */  daddu     $s1, $v0, $zero
/* AA77CC 8024034C 8E050000 */  lw        $a1, ($s0)
/* AA77D0 80240350 0C0B1EAF */  jal       evt_get_variable
/* AA77D4 80240354 26100004 */   addiu    $s0, $s0, 4
/* AA77D8 80240358 44820000 */  mtc1      $v0, $f0
/* AA77DC 8024035C 00000000 */  nop
/* AA77E0 80240360 46800020 */  cvt.s.w   $f0, $f0
/* AA77E4 80240364 E6200060 */  swc1      $f0, 0x60($s1)
/* AA77E8 80240368 8E050000 */  lw        $a1, ($s0)
/* AA77EC 8024036C 26100004 */  addiu     $s0, $s0, 4
/* AA77F0 80240370 0C0B1EAF */  jal       evt_get_variable
/* AA77F4 80240374 0240202D */   daddu    $a0, $s2, $zero
/* AA77F8 80240378 44820000 */  mtc1      $v0, $f0
/* AA77FC 8024037C 00000000 */  nop
/* AA7800 80240380 46800020 */  cvt.s.w   $f0, $f0
/* AA7804 80240384 E6200064 */  swc1      $f0, 0x64($s1)
/* AA7808 80240388 8E050000 */  lw        $a1, ($s0)
/* AA780C 8024038C 0C0B1EAF */  jal       evt_get_variable
/* AA7810 80240390 0240202D */   daddu    $a0, $s2, $zero
/* AA7814 80240394 44820000 */  mtc1      $v0, $f0
/* AA7818 80240398 00000000 */  nop
/* AA781C 8024039C 46800020 */  cvt.s.w   $f0, $f0
/* AA7820 802403A0 E6200068 */  swc1      $f0, 0x68($s1)
/* AA7824 802403A4 8FBF001C */  lw        $ra, 0x1c($sp)
/* AA7828 802403A8 8FB20018 */  lw        $s2, 0x18($sp)
/* AA782C 802403AC 8FB10014 */  lw        $s1, 0x14($sp)
/* AA7830 802403B0 8FB00010 */  lw        $s0, 0x10($sp)
/* AA7834 802403B4 24020002 */  addiu     $v0, $zero, 2
/* AA7838 802403B8 03E00008 */  jr        $ra
/* AA783C 802403BC 27BD0020 */   addiu    $sp, $sp, 0x20
