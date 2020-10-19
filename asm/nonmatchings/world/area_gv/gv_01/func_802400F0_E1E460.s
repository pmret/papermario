.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_E1E550
/* E1E550 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E1E554 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* E1E558 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* E1E55C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* E1E560 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* E1E564 80240104 0C016AFA */  jal       get_current_map_header
/* E1E568 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* E1E56C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* E1E570 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* E1E574 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* E1E578 80240118 0C0B1EAF */  jal       get_variable
/* E1E57C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* E1E580 80240120 0220202D */  daddu     $a0, $s1, $zero
/* E1E584 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* E1E588 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* E1E58C 8024012C 00028100 */  sll       $s0, $v0, 4
/* E1E590 80240130 02031821 */  addu      $v1, $s0, $v1
/* E1E594 80240134 C4600000 */  lwc1      $f0, ($v1)
/* E1E598 80240138 4600008D */  trunc.w.s $f2, $f0
/* E1E59C 8024013C 44061000 */  mfc1      $a2, $f2
/* E1E5A0 80240140 0C0B2026 */  jal       set_variable
/* E1E5A4 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* E1E5A8 80240148 0220202D */  daddu     $a0, $s1, $zero
/* E1E5AC 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* E1E5B0 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* E1E5B4 80240154 02021021 */  addu      $v0, $s0, $v0
/* E1E5B8 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* E1E5BC 8024015C 4600008D */  trunc.w.s $f2, $f0
/* E1E5C0 80240160 44061000 */  mfc1      $a2, $f2
/* E1E5C4 80240164 0C0B2026 */  jal       set_variable
/* E1E5C8 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* E1E5CC 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* E1E5D0 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* E1E5D4 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* E1E5D8 80240178 02021021 */  addu      $v0, $s0, $v0
/* E1E5DC 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* E1E5E0 80240180 4600008D */  trunc.w.s $f2, $f0
/* E1E5E4 80240184 44061000 */  mfc1      $a2, $f2
/* E1E5E8 80240188 0C0B2026 */  jal       set_variable
/* E1E5EC 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* E1E5F0 80240190 0220202D */  daddu     $a0, $s1, $zero
/* E1E5F4 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* E1E5F8 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* E1E5FC 8024019C 02028021 */  addu      $s0, $s0, $v0
/* E1E600 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* E1E604 802401A4 4600008D */  trunc.w.s $f2, $f0
/* E1E608 802401A8 44061000 */  mfc1      $a2, $f2
/* E1E60C 802401AC 0C0B2026 */  jal       set_variable
/* E1E610 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* E1E614 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* E1E618 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* E1E61C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* E1E620 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* E1E624 802401C4 24020002 */  addiu     $v0, $zero, 2
/* E1E628 802401C8 03E00008 */  jr        $ra
/* E1E62C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
