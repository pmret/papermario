.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400C4_BC4344
/* BC4344 802400C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC4348 802400C8 AFB20018 */  sw        $s2, 0x18($sp)
/* BC434C 802400CC 0080902D */  daddu     $s2, $a0, $zero
/* BC4350 802400D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* BC4354 802400D4 AFB10014 */  sw        $s1, 0x14($sp)
/* BC4358 802400D8 AFB00010 */  sw        $s0, 0x10($sp)
/* BC435C 802400DC 8E50000C */  lw        $s0, 0xc($s2)
/* BC4360 802400E0 8E050000 */  lw        $a1, ($s0)
/* BC4364 802400E4 0C0B1EAF */  jal       get_variable
/* BC4368 802400E8 26100004 */   addiu    $s0, $s0, 4
/* BC436C 802400EC 0C04417A */  jal       get_entity_by_index
/* BC4370 802400F0 0040202D */   daddu    $a0, $v0, $zero
/* BC4374 802400F4 8E050000 */  lw        $a1, ($s0)
/* BC4378 802400F8 26100004 */  addiu     $s0, $s0, 4
/* BC437C 802400FC 0040882D */  daddu     $s1, $v0, $zero
/* BC4380 80240100 C6200048 */  lwc1      $f0, 0x48($s1)
/* BC4384 80240104 4600008D */  trunc.w.s $f2, $f0
/* BC4388 80240108 44061000 */  mfc1      $a2, $f2
/* BC438C 8024010C 0C0B2026 */  jal       set_variable
/* BC4390 80240110 0240202D */   daddu    $a0, $s2, $zero
/* BC4394 80240114 8E050000 */  lw        $a1, ($s0)
/* BC4398 80240118 26100004 */  addiu     $s0, $s0, 4
/* BC439C 8024011C C620004C */  lwc1      $f0, 0x4c($s1)
/* BC43A0 80240120 4600008D */  trunc.w.s $f2, $f0
/* BC43A4 80240124 44061000 */  mfc1      $a2, $f2
/* BC43A8 80240128 0C0B2026 */  jal       set_variable
/* BC43AC 8024012C 0240202D */   daddu    $a0, $s2, $zero
/* BC43B0 80240130 C6200050 */  lwc1      $f0, 0x50($s1)
/* BC43B4 80240134 8E050000 */  lw        $a1, ($s0)
/* BC43B8 80240138 4600008D */  trunc.w.s $f2, $f0
/* BC43BC 8024013C 44061000 */  mfc1      $a2, $f2
/* BC43C0 80240140 0C0B2026 */  jal       set_variable
/* BC43C4 80240144 0240202D */   daddu    $a0, $s2, $zero
/* BC43C8 80240148 8FBF001C */  lw        $ra, 0x1c($sp)
/* BC43CC 8024014C 8FB20018 */  lw        $s2, 0x18($sp)
/* BC43D0 80240150 8FB10014 */  lw        $s1, 0x14($sp)
/* BC43D4 80240154 8FB00010 */  lw        $s0, 0x10($sp)
/* BC43D8 80240158 24020002 */  addiu     $v0, $zero, 2
/* BC43DC 8024015C 03E00008 */  jr        $ra
/* BC43E0 80240160 27BD0020 */   addiu    $sp, $sp, 0x20
/* BC43E4 80240164 00000000 */  nop       
/* BC43E8 80240168 00000000 */  nop       
/* BC43EC 8024016C 00000000 */  nop       
