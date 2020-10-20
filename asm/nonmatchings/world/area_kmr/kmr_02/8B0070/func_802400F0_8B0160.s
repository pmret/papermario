.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_8B0160
/* 8B0160 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B0164 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B0168 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 8B016C 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B0170 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B0174 80240104 0C016AFA */  jal       get_current_map_header
/* 8B0178 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 8B017C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 8B0180 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 8B0184 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8B0188 80240118 0C0B1EAF */  jal       get_variable
/* 8B018C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 8B0190 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 8B0194 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 8B0198 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 8B019C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 8B01A0 80240130 02031821 */  addu      $v1, $s0, $v1
/* 8B01A4 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 8B01A8 80240138 4600008D */  trunc.w.s $f2, $f0
/* 8B01AC 8024013C 44061000 */  mfc1      $a2, $f2
/* 8B01B0 80240140 0C0B2026 */  jal       set_variable
/* 8B01B4 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8B01B8 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 8B01BC 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 8B01C0 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 8B01C4 80240154 02021021 */  addu      $v0, $s0, $v0
/* 8B01C8 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 8B01CC 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 8B01D0 80240160 44061000 */  mfc1      $a2, $f2
/* 8B01D4 80240164 0C0B2026 */  jal       set_variable
/* 8B01D8 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8B01DC 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 8B01E0 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 8B01E4 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 8B01E8 80240178 02021021 */  addu      $v0, $s0, $v0
/* 8B01EC 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 8B01F0 80240180 4600008D */  trunc.w.s $f2, $f0
/* 8B01F4 80240184 44061000 */  mfc1      $a2, $f2
/* 8B01F8 80240188 0C0B2026 */  jal       set_variable
/* 8B01FC 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 8B0200 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 8B0204 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 8B0208 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 8B020C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 8B0210 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 8B0214 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 8B0218 802401A8 44061000 */  mfc1      $a2, $f2
/* 8B021C 802401AC 0C0B2026 */  jal       set_variable
/* 8B0220 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 8B0224 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B0228 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B022C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B0230 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B0234 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 8B0238 802401C8 03E00008 */  jr        $ra
/* 8B023C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
