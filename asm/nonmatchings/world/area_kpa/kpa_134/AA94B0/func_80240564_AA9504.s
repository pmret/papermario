.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240564_AA9504
/* AA9504 80240564 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AA9508 80240568 AFB10014 */  sw        $s1, 0x14($sp)
/* AA950C 8024056C 0080882D */  daddu     $s1, $a0, $zero
/* AA9510 80240570 AFBF0020 */  sw        $ra, 0x20($sp)
/* AA9514 80240574 AFB3001C */  sw        $s3, 0x1c($sp)
/* AA9518 80240578 AFB20018 */  sw        $s2, 0x18($sp)
/* AA951C 8024057C AFB00010 */  sw        $s0, 0x10($sp)
/* AA9520 80240580 8E30000C */  lw        $s0, 0xc($s1)
/* AA9524 80240584 8E050000 */  lw        $a1, ($s0)
/* AA9528 80240588 0C0B1EAF */  jal       get_variable
/* AA952C 8024058C 26100004 */   addiu    $s0, $s0, 4
/* AA9530 80240590 8E050000 */  lw        $a1, ($s0)
/* AA9534 80240594 26100004 */  addiu     $s0, $s0, 4
/* AA9538 80240598 0220202D */  daddu     $a0, $s1, $zero
/* AA953C 8024059C 0C0B1EAF */  jal       get_variable
/* AA9540 802405A0 0040982D */   daddu    $s3, $v0, $zero
/* AA9544 802405A4 8E050000 */  lw        $a1, ($s0)
/* AA9548 802405A8 26100004 */  addiu     $s0, $s0, 4
/* AA954C 802405AC 0220202D */  daddu     $a0, $s1, $zero
/* AA9550 802405B0 0C0B1EAF */  jal       get_variable
/* AA9554 802405B4 0040902D */   daddu    $s2, $v0, $zero
/* AA9558 802405B8 0220202D */  daddu     $a0, $s1, $zero
/* AA955C 802405BC 8E050000 */  lw        $a1, ($s0)
/* AA9560 802405C0 0C0B1EAF */  jal       get_variable
/* AA9564 802405C4 0040882D */   daddu    $s1, $v0, $zero
/* AA9568 802405C8 0260202D */  daddu     $a0, $s3, $zero
/* AA956C 802405CC 0C04417A */  jal       get_entity_by_index
/* AA9570 802405D0 0040802D */   daddu    $s0, $v0, $zero
/* AA9574 802405D4 0040182D */  daddu     $v1, $v0, $zero
/* AA9578 802405D8 44920000 */  mtc1      $s2, $f0
/* AA957C 802405DC 00000000 */  nop
/* AA9580 802405E0 46800020 */  cvt.s.w   $f0, $f0
/* AA9584 802405E4 E4600048 */  swc1      $f0, 0x48($v1)
/* AA9588 802405E8 44910000 */  mtc1      $s1, $f0
/* AA958C 802405EC 00000000 */  nop
/* AA9590 802405F0 46800020 */  cvt.s.w   $f0, $f0
/* AA9594 802405F4 E460004C */  swc1      $f0, 0x4c($v1)
/* AA9598 802405F8 44900000 */  mtc1      $s0, $f0
/* AA959C 802405FC 00000000 */  nop
/* AA95A0 80240600 46800020 */  cvt.s.w   $f0, $f0
/* AA95A4 80240604 E4600050 */  swc1      $f0, 0x50($v1)
/* AA95A8 80240608 8FBF0020 */  lw        $ra, 0x20($sp)
/* AA95AC 8024060C 8FB3001C */  lw        $s3, 0x1c($sp)
/* AA95B0 80240610 8FB20018 */  lw        $s2, 0x18($sp)
/* AA95B4 80240614 8FB10014 */  lw        $s1, 0x14($sp)
/* AA95B8 80240618 8FB00010 */  lw        $s0, 0x10($sp)
/* AA95BC 8024061C 24020002 */  addiu     $v0, $zero, 2
/* AA95C0 80240620 03E00008 */  jr        $ra
/* AA95C4 80240624 27BD0028 */   addiu    $sp, $sp, 0x28
