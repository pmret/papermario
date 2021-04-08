.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_09_UnkFunc20
/* C77160 80240480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C77164 80240484 AFB1001C */  sw        $s1, 0x1c($sp)
/* C77168 80240488 0080882D */  daddu     $s1, $a0, $zero
/* C7716C 8024048C AFBF0020 */  sw        $ra, 0x20($sp)
/* C77170 80240490 AFB00018 */  sw        $s0, 0x18($sp)
/* C77174 80240494 8E30000C */  lw        $s0, 0xc($s1)
/* C77178 80240498 8E050000 */  lw        $a1, ($s0)
/* C7717C 8024049C 0C0B1EAF */  jal       get_variable
/* C77180 802404A0 26100004 */   addiu    $s0, $s0, 4
/* C77184 802404A4 0C04417A */  jal       get_entity_by_index
/* C77188 802404A8 0040202D */   daddu    $a0, $v0, $zero
/* C7718C 802404AC 8E100000 */  lw        $s0, ($s0)
/* C77190 802404B0 C444004C */  lwc1      $f4, 0x4c($v0)
/* C77194 802404B4 3C014148 */  lui       $at, 0x4148
/* C77198 802404B8 44810000 */  mtc1      $at, $f0
/* C7719C 802404BC 3C013F33 */  lui       $at, 0x3f33
/* C771A0 802404C0 34213333 */  ori       $at, $at, 0x3333
/* C771A4 802404C4 44811000 */  mtc1      $at, $f2
/* C771A8 802404C8 AFA00014 */  sw        $zero, 0x14($sp)
/* C771AC 802404CC 46002100 */  add.s     $f4, $f4, $f0
/* C771B0 802404D0 E7A20010 */  swc1      $f2, 0x10($sp)
/* C771B4 802404D4 8C450048 */  lw        $a1, 0x48($v0)
/* C771B8 802404D8 8C470050 */  lw        $a3, 0x50($v0)
/* C771BC 802404DC 44062000 */  mfc1      $a2, $f4
/* C771C0 802404E0 0C01C5D4 */  jal       func_80071750
/* C771C4 802404E4 0000202D */   daddu    $a0, $zero, $zero
/* C771C8 802404E8 0220202D */  daddu     $a0, $s1, $zero
/* C771CC 802404EC 0200282D */  daddu     $a1, $s0, $zero
/* C771D0 802404F0 0C0B2026 */  jal       set_variable
/* C771D4 802404F4 0040302D */   daddu    $a2, $v0, $zero
/* C771D8 802404F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* C771DC 802404FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* C771E0 80240500 8FB00018 */  lw        $s0, 0x18($sp)
/* C771E4 80240504 24020002 */  addiu     $v0, $zero, 2
/* C771E8 80240508 03E00008 */  jr        $ra
/* C771EC 8024050C 27BD0028 */   addiu    $sp, $sp, 0x28
