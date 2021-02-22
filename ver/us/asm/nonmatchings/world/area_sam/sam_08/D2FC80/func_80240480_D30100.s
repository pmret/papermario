.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480_D30100
/* D30100 80240480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D30104 80240484 AFB1001C */  sw        $s1, 0x1c($sp)
/* D30108 80240488 0080882D */  daddu     $s1, $a0, $zero
/* D3010C 8024048C AFBF0020 */  sw        $ra, 0x20($sp)
/* D30110 80240490 AFB00018 */  sw        $s0, 0x18($sp)
/* D30114 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* D30118 80240498 8E050000 */  lw        $a1, ($s0)
/* D3011C 8024049C 0C0B1EAF */  jal       get_variable
/* D30120 802404A0 26100004 */   addiu    $s0, $s0, 4
/* D30124 802404A4 0C04417A */  jal       get_entity_by_index
/* D30128 802404A8 0040202D */   daddu    $a0, $v0, $zero
/* D3012C 802404AC 8E100000 */  lw        $s0, ($s0)
/* D30130 802404B0 C444004C */  lwc1      $f4, 0x4c($v0)
/* D30134 802404B4 3C014148 */  lui       $at, 0x4148
/* D30138 802404B8 44810000 */  mtc1      $at, $f0
/* D3013C 802404BC 3C013F33 */  lui       $at, 0x3f33
/* D30140 802404C0 34213333 */  ori       $at, $at, 0x3333
/* D30144 802404C4 44811000 */  mtc1      $at, $f2
/* D30148 802404C8 AFA00014 */  sw        $zero, 0x14($sp)
/* D3014C 802404CC 46002100 */  add.s     $f4, $f4, $f0
/* D30150 802404D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* D30154 802404D4 8C450048 */  lw        $a1, 0x48($v0)
/* D30158 802404D8 8C470050 */  lw        $a3, 0x50($v0)
/* D3015C 802404DC 44062000 */  mfc1      $a2, $f4
/* D30160 802404E0 0C01C5D4 */  jal       func_80071750
/* D30164 802404E4 0000202D */   daddu    $a0, $zero, $zero
/* D30168 802404E8 0220202D */  daddu     $a0, $s1, $zero
/* D3016C 802404EC 0200282D */  daddu     $a1, $s0, $zero
/* D30170 802404F0 0C0B2026 */  jal       set_variable
/* D30174 802404F4 0040302D */   daddu    $a2, $v0, $zero
/* D30178 802404F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* D3017C 802404FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* D30180 80240500 8FB00018 */  lw        $s0, 0x18($sp)
/* D30184 80240504 24020002 */  addiu     $v0, $zero, 2
/* D30188 80240508 03E00008 */  jr        $ra
/* D3018C 8024050C 27BD0028 */   addiu    $sp, $sp, 0x28
