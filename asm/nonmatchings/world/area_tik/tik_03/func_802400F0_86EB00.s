.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_86EBF0
/* 86EBF0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 86EBF4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 86EBF8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 86EBFC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 86EC00 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 86EC04 80240104 0C016AFA */  jal       get_current_map_header
/* 86EC08 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 86EC0C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 86EC10 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 86EC14 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 86EC18 80240118 0C0B1EAF */  jal       get_variable
/* 86EC1C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 86EC20 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 86EC24 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 86EC28 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 86EC2C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 86EC30 80240130 02031821 */  addu      $v1, $s0, $v1
/* 86EC34 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 86EC38 80240138 4600008D */  trunc.w.s $f2, $f0
/* 86EC3C 8024013C 44061000 */  mfc1      $a2, $f2
/* 86EC40 80240140 0C0B2026 */  jal       set_variable
/* 86EC44 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 86EC48 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 86EC4C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 86EC50 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 86EC54 80240154 02021021 */  addu      $v0, $s0, $v0
/* 86EC58 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 86EC5C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 86EC60 80240160 44061000 */  mfc1      $a2, $f2
/* 86EC64 80240164 0C0B2026 */  jal       set_variable
/* 86EC68 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 86EC6C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 86EC70 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 86EC74 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 86EC78 80240178 02021021 */  addu      $v0, $s0, $v0
/* 86EC7C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 86EC80 80240180 4600008D */  trunc.w.s $f2, $f0
/* 86EC84 80240184 44061000 */  mfc1      $a2, $f2
/* 86EC88 80240188 0C0B2026 */  jal       set_variable
/* 86EC8C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 86EC90 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 86EC94 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 86EC98 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 86EC9C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 86ECA0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 86ECA4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 86ECA8 802401A8 44061000 */  mfc1      $a2, $f2
/* 86ECAC 802401AC 0C0B2026 */  jal       set_variable
/* 86ECB0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 86ECB4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 86ECB8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 86ECBC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 86ECC0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 86ECC4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 86ECC8 802401C8 03E00008 */  jr        $ra
/* 86ECCC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
