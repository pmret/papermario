.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_88FC90
/* 88FC90 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88FC94 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 88FC98 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 88FC9C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 88FCA0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 88FCA4 80240104 0C016AFA */  jal       get_current_map_header
/* 88FCA8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 88FCAC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 88FCB0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 88FCB4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 88FCB8 80240118 0C0B1EAF */  jal       get_variable
/* 88FCBC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 88FCC0 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 88FCC4 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 88FCC8 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 88FCCC 8024012C 00028100 */  sll       $s0, $v0, 4
/* 88FCD0 80240130 02031821 */  addu      $v1, $s0, $v1
/* 88FCD4 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 88FCD8 80240138 4600008D */  trunc.w.s $f2, $f0
/* 88FCDC 8024013C 44061000 */  mfc1      $a2, $f2
/* 88FCE0 80240140 0C0B2026 */  jal       set_variable
/* 88FCE4 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 88FCE8 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 88FCEC 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 88FCF0 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 88FCF4 80240154 02021021 */  addu      $v0, $s0, $v0
/* 88FCF8 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 88FCFC 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 88FD00 80240160 44061000 */  mfc1      $a2, $f2
/* 88FD04 80240164 0C0B2026 */  jal       set_variable
/* 88FD08 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 88FD0C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 88FD10 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 88FD14 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 88FD18 80240178 02021021 */  addu      $v0, $s0, $v0
/* 88FD1C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 88FD20 80240180 4600008D */  trunc.w.s $f2, $f0
/* 88FD24 80240184 44061000 */  mfc1      $a2, $f2
/* 88FD28 80240188 0C0B2026 */  jal       set_variable
/* 88FD2C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 88FD30 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 88FD34 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 88FD38 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 88FD3C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 88FD40 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 88FD44 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 88FD48 802401A8 44061000 */  mfc1      $a2, $f2
/* 88FD4C 802401AC 0C0B2026 */  jal       set_variable
/* 88FD50 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 88FD54 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 88FD58 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 88FD5C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 88FD60 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 88FD64 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 88FD68 802401C8 03E00008 */  jr        $ra
/* 88FD6C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
