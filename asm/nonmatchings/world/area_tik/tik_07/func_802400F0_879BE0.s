.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_879CD0
/* 879CD0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 879CD4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 879CD8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 879CDC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 879CE0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 879CE4 80240104 0C016AFA */  jal       get_current_map_header
/* 879CE8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 879CEC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 879CF0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 879CF4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 879CF8 80240118 0C0B1EAF */  jal       get_variable
/* 879CFC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 879D00 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 879D04 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 879D08 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 879D0C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 879D10 80240130 02031821 */  addu      $v1, $s0, $v1
/* 879D14 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 879D18 80240138 4600008D */  trunc.w.s $f2, $f0
/* 879D1C 8024013C 44061000 */  mfc1      $a2, $f2
/* 879D20 80240140 0C0B2026 */  jal       set_variable
/* 879D24 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 879D28 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 879D2C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 879D30 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 879D34 80240154 02021021 */  addu      $v0, $s0, $v0
/* 879D38 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 879D3C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 879D40 80240160 44061000 */  mfc1      $a2, $f2
/* 879D44 80240164 0C0B2026 */  jal       set_variable
/* 879D48 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 879D4C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 879D50 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 879D54 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 879D58 80240178 02021021 */  addu      $v0, $s0, $v0
/* 879D5C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 879D60 80240180 4600008D */  trunc.w.s $f2, $f0
/* 879D64 80240184 44061000 */  mfc1      $a2, $f2
/* 879D68 80240188 0C0B2026 */  jal       set_variable
/* 879D6C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 879D70 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 879D74 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 879D78 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 879D7C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 879D80 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 879D84 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 879D88 802401A8 44061000 */  mfc1      $a2, $f2
/* 879D8C 802401AC 0C0B2026 */  jal       set_variable
/* 879D90 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 879D94 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 879D98 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 879D9C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 879DA0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 879DA4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 879DA8 802401C8 03E00008 */  jr        $ra
/* 879DAC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
