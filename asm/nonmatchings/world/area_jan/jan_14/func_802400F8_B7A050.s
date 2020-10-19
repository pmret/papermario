.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F8_B7A148
/* B7A148 802400F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B7A14C 802400FC AFB10014 */  sw        $s1, 0x14($sp)
/* B7A150 80240100 0080882D */  daddu     $s1, $a0, $zero
/* B7A154 80240104 AFBF0018 */  sw        $ra, 0x18($sp)
/* B7A158 80240108 AFB00010 */  sw        $s0, 0x10($sp)
/* B7A15C 8024010C F7B40020 */  sdc1      $f20, 0x20($sp)
/* B7A160 80240110 8E30000C */  lw        $s0, 0xc($s1)
/* B7A164 80240114 8E050000 */  lw        $a1, ($s0)
/* B7A168 80240118 0C0B210B */  jal       get_float_variable
/* B7A16C 8024011C 26100004 */   addiu    $s0, $s0, 4
/* B7A170 80240120 8E050000 */  lw        $a1, ($s0)
/* B7A174 80240124 26100004 */  addiu     $s0, $s0, 4
/* B7A178 80240128 0220202D */  daddu     $a0, $s1, $zero
/* B7A17C 8024012C 0C0B210B */  jal       get_float_variable
/* B7A180 80240130 46000506 */   mov.s    $f20, $f0
/* B7A184 80240134 46140001 */  sub.s     $f0, $f0, $f20
/* B7A188 80240138 3C014120 */  lui       $at, 0x4120
/* B7A18C 8024013C 44811000 */  mtc1      $at, $f2
/* B7A190 80240140 8E050000 */  lw        $a1, ($s0)
/* B7A194 80240144 46020003 */  div.s     $f0, $f0, $f2
/* B7A198 80240148 44060000 */  mfc1      $a2, $f0
/* B7A19C 8024014C 0C0B2190 */  jal       set_float_variable
/* B7A1A0 80240150 0220202D */   daddu    $a0, $s1, $zero
/* B7A1A4 80240154 8FBF0018 */  lw        $ra, 0x18($sp)
/* B7A1A8 80240158 8FB10014 */  lw        $s1, 0x14($sp)
/* B7A1AC 8024015C 8FB00010 */  lw        $s0, 0x10($sp)
/* B7A1B0 80240160 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B7A1B4 80240164 24020002 */  addiu     $v0, $zero, 2
/* B7A1B8 80240168 03E00008 */  jr        $ra
/* B7A1BC 8024016C 27BD0028 */   addiu    $sp, $sp, 0x28
