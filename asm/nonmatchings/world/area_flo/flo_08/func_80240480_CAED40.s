.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480_CAF1C0
/* CAF1C0 80240480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CAF1C4 80240484 AFB1001C */  sw        $s1, 0x1c($sp)
/* CAF1C8 80240488 0080882D */  daddu     $s1, $a0, $zero
/* CAF1CC 8024048C AFBF0020 */  sw        $ra, 0x20($sp)
/* CAF1D0 80240490 AFB00018 */  sw        $s0, 0x18($sp)
/* CAF1D4 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* CAF1D8 80240498 8E050000 */  lw        $a1, ($s0)
/* CAF1DC 8024049C 0C0B1EAF */  jal       get_variable
/* CAF1E0 802404A0 26100004 */   addiu    $s0, $s0, 4
/* CAF1E4 802404A4 0C04417A */  jal       get_entity_by_index
/* CAF1E8 802404A8 0040202D */   daddu    $a0, $v0, $zero
/* CAF1EC 802404AC 8E100000 */  lw        $s0, ($s0)
/* CAF1F0 802404B0 C444004C */  lwc1      $f4, 0x4c($v0)
/* CAF1F4 802404B4 3C014148 */  lui       $at, 0x4148
/* CAF1F8 802404B8 44810000 */  mtc1      $at, $f0
/* CAF1FC 802404BC 3C013F33 */  lui       $at, 0x3f33
/* CAF200 802404C0 34213333 */  ori       $at, $at, 0x3333
/* CAF204 802404C4 44811000 */  mtc1      $at, $f2
/* CAF208 802404C8 AFA00014 */  sw        $zero, 0x14($sp)
/* CAF20C 802404CC 46002100 */  add.s     $f4, $f4, $f0
/* CAF210 802404D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* CAF214 802404D4 8C450048 */  lw        $a1, 0x48($v0)
/* CAF218 802404D8 8C470050 */  lw        $a3, 0x50($v0)
/* CAF21C 802404DC 44062000 */  mfc1      $a2, $f4
/* CAF220 802404E0 0C01C5D4 */  jal       func_80071750
/* CAF224 802404E4 0000202D */   daddu    $a0, $zero, $zero
/* CAF228 802404E8 0220202D */  daddu     $a0, $s1, $zero
/* CAF22C 802404EC 0200282D */  daddu     $a1, $s0, $zero
/* CAF230 802404F0 0C0B2026 */  jal       set_variable
/* CAF234 802404F4 0040302D */   daddu    $a2, $v0, $zero
/* CAF238 802404F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* CAF23C 802404FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* CAF240 80240500 8FB00018 */  lw        $s0, 0x18($sp)
/* CAF244 80240504 24020002 */  addiu     $v0, $zero, 2
/* CAF248 80240508 03E00008 */  jr        $ra
/* CAF24C 8024050C 27BD0028 */   addiu    $sp, $sp, 0x28
