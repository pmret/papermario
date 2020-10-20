.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_87EEE0
/* 87EEE0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87EEE4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 87EEE8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 87EEEC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 87EEF0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 87EEF4 80240104 0C016AFA */  jal       get_current_map_header
/* 87EEF8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 87EEFC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 87EF00 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 87EF04 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 87EF08 80240118 0C0B1EAF */  jal       get_variable
/* 87EF0C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 87EF10 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 87EF14 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 87EF18 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 87EF1C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 87EF20 80240130 02031821 */  addu      $v1, $s0, $v1
/* 87EF24 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 87EF28 80240138 4600008D */  trunc.w.s $f2, $f0
/* 87EF2C 8024013C 44061000 */  mfc1      $a2, $f2
/* 87EF30 80240140 0C0B2026 */  jal       set_variable
/* 87EF34 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 87EF38 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 87EF3C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 87EF40 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 87EF44 80240154 02021021 */  addu      $v0, $s0, $v0
/* 87EF48 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 87EF4C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 87EF50 80240160 44061000 */  mfc1      $a2, $f2
/* 87EF54 80240164 0C0B2026 */  jal       set_variable
/* 87EF58 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 87EF5C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 87EF60 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 87EF64 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 87EF68 80240178 02021021 */  addu      $v0, $s0, $v0
/* 87EF6C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 87EF70 80240180 4600008D */  trunc.w.s $f2, $f0
/* 87EF74 80240184 44061000 */  mfc1      $a2, $f2
/* 87EF78 80240188 0C0B2026 */  jal       set_variable
/* 87EF7C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 87EF80 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 87EF84 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 87EF88 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 87EF8C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 87EF90 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 87EF94 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 87EF98 802401A8 44061000 */  mfc1      $a2, $f2
/* 87EF9C 802401AC 0C0B2026 */  jal       set_variable
/* 87EFA0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 87EFA4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 87EFA8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 87EFAC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 87EFB0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 87EFB4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 87EFB8 802401C8 03E00008 */  jr        $ra
/* 87EFBC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
