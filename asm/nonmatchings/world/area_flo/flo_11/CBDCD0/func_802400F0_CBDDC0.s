.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_CBDDC0
/* CBDDC0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CBDDC4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* CBDDC8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* CBDDCC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* CBDDD0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* CBDDD4 80240104 0C016AFA */  jal       get_current_map_header
/* CBDDD8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* CBDDDC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* CBDDE0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* CBDDE4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* CBDDE8 80240118 0C0B1EAF */  jal       get_variable
/* CBDDEC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* CBDDF0 80240120 0220202D */  daddu     $a0, $s1, $zero
/* CBDDF4 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* CBDDF8 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* CBDDFC 8024012C 00028100 */  sll       $s0, $v0, 4
/* CBDE00 80240130 02031821 */  addu      $v1, $s0, $v1
/* CBDE04 80240134 C4600000 */  lwc1      $f0, ($v1)
/* CBDE08 80240138 4600008D */  trunc.w.s $f2, $f0
/* CBDE0C 8024013C 44061000 */  mfc1      $a2, $f2
/* CBDE10 80240140 0C0B2026 */  jal       set_variable
/* CBDE14 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* CBDE18 80240148 0220202D */  daddu     $a0, $s1, $zero
/* CBDE1C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* CBDE20 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* CBDE24 80240154 02021021 */  addu      $v0, $s0, $v0
/* CBDE28 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* CBDE2C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* CBDE30 80240160 44061000 */  mfc1      $a2, $f2
/* CBDE34 80240164 0C0B2026 */  jal       set_variable
/* CBDE38 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* CBDE3C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* CBDE40 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* CBDE44 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* CBDE48 80240178 02021021 */  addu      $v0, $s0, $v0
/* CBDE4C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* CBDE50 80240180 4600008D */  trunc.w.s $f2, $f0
/* CBDE54 80240184 44061000 */  mfc1      $a2, $f2
/* CBDE58 80240188 0C0B2026 */  jal       set_variable
/* CBDE5C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* CBDE60 80240190 0220202D */  daddu     $a0, $s1, $zero
/* CBDE64 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* CBDE68 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* CBDE6C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* CBDE70 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* CBDE74 802401A4 4600008D */  trunc.w.s $f2, $f0
/* CBDE78 802401A8 44061000 */  mfc1      $a2, $f2
/* CBDE7C 802401AC 0C0B2026 */  jal       set_variable
/* CBDE80 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* CBDE84 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* CBDE88 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* CBDE8C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* CBDE90 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* CBDE94 802401C4 24020002 */  addiu     $v0, $zero, 2
/* CBDE98 802401C8 03E00008 */  jr        $ra
/* CBDE9C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
