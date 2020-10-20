.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240560
/* CD2390 80240560 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CD2394 80240564 AFB1001C */  sw        $s1, 0x1c($sp)
/* CD2398 80240568 0080882D */  daddu     $s1, $a0, $zero
/* CD239C 8024056C AFBF0020 */  sw        $ra, 0x20($sp)
/* CD23A0 80240570 AFB00018 */  sw        $s0, 0x18($sp)
/* CD23A4 80240574 8E30000C */  lw        $s0, 0xc($s1)
/* CD23A8 80240578 8E050000 */  lw        $a1, ($s0)
/* CD23AC 8024057C 0C0B1EAF */  jal       get_variable
/* CD23B0 80240580 26100004 */   addiu    $s0, $s0, 4
/* CD23B4 80240584 0C04417A */  jal       get_entity_by_index
/* CD23B8 80240588 0040202D */   daddu    $a0, $v0, $zero
/* CD23BC 8024058C 8E100000 */  lw        $s0, ($s0)
/* CD23C0 80240590 C444004C */  lwc1      $f4, 0x4c($v0)
/* CD23C4 80240594 3C014148 */  lui       $at, 0x4148
/* CD23C8 80240598 44810000 */  mtc1      $at, $f0
/* CD23CC 8024059C 3C013F33 */  lui       $at, 0x3f33
/* CD23D0 802405A0 34213333 */  ori       $at, $at, 0x3333
/* CD23D4 802405A4 44811000 */  mtc1      $at, $f2
/* CD23D8 802405A8 AFA00014 */  sw        $zero, 0x14($sp)
/* CD23DC 802405AC 46002100 */  add.s     $f4, $f4, $f0
/* CD23E0 802405B0 E7A20010 */  swc1      $f2, 0x10($sp)
/* CD23E4 802405B4 8C450048 */  lw        $a1, 0x48($v0)
/* CD23E8 802405B8 8C470050 */  lw        $a3, 0x50($v0)
/* CD23EC 802405BC 44062000 */  mfc1      $a2, $f4
/* CD23F0 802405C0 0C01C5D4 */  jal       func_80071750
/* CD23F4 802405C4 0000202D */   daddu    $a0, $zero, $zero
/* CD23F8 802405C8 0220202D */  daddu     $a0, $s1, $zero
/* CD23FC 802405CC 0200282D */  daddu     $a1, $s0, $zero
/* CD2400 802405D0 0C0B2026 */  jal       set_variable
/* CD2404 802405D4 0040302D */   daddu    $a2, $v0, $zero
/* CD2408 802405D8 8FBF0020 */  lw        $ra, 0x20($sp)
/* CD240C 802405DC 8FB1001C */  lw        $s1, 0x1c($sp)
/* CD2410 802405E0 8FB00018 */  lw        $s0, 0x18($sp)
/* CD2414 802405E4 24020002 */  addiu     $v0, $zero, 2
/* CD2418 802405E8 03E00008 */  jr        $ra
/* CD241C 802405EC 27BD0028 */   addiu    $sp, $sp, 0x28
