.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_7EAE00
/* 7EAE00 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EAE04 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EAE08 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 7EAE0C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 7EAE10 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 7EAE14 80240104 0C016AFA */  jal       get_current_map_header
/* 7EAE18 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 7EAE1C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 7EAE20 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAE24 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 7EAE28 80240118 0C0B1EAF */  jal       get_variable
/* 7EAE2C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 7EAE30 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 7EAE34 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAE38 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 7EAE3C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 7EAE40 80240130 02031821 */  addu      $v1, $s0, $v1
/* 7EAE44 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 7EAE48 80240138 4600008D */  trunc.w.s $f2, $f0
/* 7EAE4C 8024013C 44061000 */  mfc1      $a2, $f2
/* 7EAE50 80240140 0C0B2026 */  jal       set_variable
/* 7EAE54 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 7EAE58 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 7EAE5C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 7EAE60 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAE64 80240154 02021021 */  addu      $v0, $s0, $v0
/* 7EAE68 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 7EAE6C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 7EAE70 80240160 44061000 */  mfc1      $a2, $f2
/* 7EAE74 80240164 0C0B2026 */  jal       set_variable
/* 7EAE78 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 7EAE7C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 7EAE80 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 7EAE84 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAE88 80240178 02021021 */  addu      $v0, $s0, $v0
/* 7EAE8C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 7EAE90 80240180 4600008D */  trunc.w.s $f2, $f0
/* 7EAE94 80240184 44061000 */  mfc1      $a2, $f2
/* 7EAE98 80240188 0C0B2026 */  jal       set_variable
/* 7EAE9C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 7EAEA0 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 7EAEA4 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 7EAEA8 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 7EAEAC 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 7EAEB0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 7EAEB4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 7EAEB8 802401A8 44061000 */  mfc1      $a2, $f2
/* 7EAEBC 802401AC 0C0B2026 */  jal       set_variable
/* 7EAEC0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 7EAEC4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7EAEC8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EAECC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EAED0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EAED4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 7EAED8 802401C8 03E00008 */  jr        $ra
/* 7EAEDC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
