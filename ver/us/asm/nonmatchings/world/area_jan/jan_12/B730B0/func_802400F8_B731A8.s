.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F8_B731A8
/* B731A8 802400F8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B731AC 802400FC AFB10014 */  sw        $s1, 0x14($sp)
/* B731B0 80240100 0080882D */  daddu     $s1, $a0, $zero
/* B731B4 80240104 AFBF0018 */  sw        $ra, 0x18($sp)
/* B731B8 80240108 AFB00010 */  sw        $s0, 0x10($sp)
/* B731BC 8024010C F7B40020 */  sdc1      $f20, 0x20($sp)
/* B731C0 80240110 8E30000C */  lw        $s0, 0xc($s1)
/* B731C4 80240114 8E050000 */  lw        $a1, ($s0)
/* B731C8 80240118 0C0B210B */  jal       evt_get_float_variable
/* B731CC 8024011C 26100004 */   addiu    $s0, $s0, 4
/* B731D0 80240120 8E050000 */  lw        $a1, ($s0)
/* B731D4 80240124 26100004 */  addiu     $s0, $s0, 4
/* B731D8 80240128 0220202D */  daddu     $a0, $s1, $zero
/* B731DC 8024012C 0C0B210B */  jal       evt_get_float_variable
/* B731E0 80240130 46000506 */   mov.s    $f20, $f0
/* B731E4 80240134 46140001 */  sub.s     $f0, $f0, $f20
/* B731E8 80240138 3C014120 */  lui       $at, 0x4120
/* B731EC 8024013C 44811000 */  mtc1      $at, $f2
/* B731F0 80240140 8E050000 */  lw        $a1, ($s0)
/* B731F4 80240144 46020003 */  div.s     $f0, $f0, $f2
/* B731F8 80240148 44060000 */  mfc1      $a2, $f0
/* B731FC 8024014C 0C0B2190 */  jal       evt_set_float_variable
/* B73200 80240150 0220202D */   daddu    $a0, $s1, $zero
/* B73204 80240154 8FBF0018 */  lw        $ra, 0x18($sp)
/* B73208 80240158 8FB10014 */  lw        $s1, 0x14($sp)
/* B7320C 8024015C 8FB00010 */  lw        $s0, 0x10($sp)
/* B73210 80240160 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B73214 80240164 24020002 */  addiu     $v0, $zero, 2
/* B73218 80240168 03E00008 */  jr        $ra
/* B7321C 8024016C 27BD0028 */   addiu    $sp, $sp, 0x28
