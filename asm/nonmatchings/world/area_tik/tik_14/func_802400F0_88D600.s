.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_88D6F0
/* 88D6F0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88D6F4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 88D6F8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 88D6FC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 88D700 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 88D704 80240104 0C016AFA */  jal       get_current_map_header
/* 88D708 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 88D70C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 88D710 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 88D714 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 88D718 80240118 0C0B1EAF */  jal       get_variable
/* 88D71C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 88D720 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 88D724 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 88D728 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 88D72C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 88D730 80240130 02031821 */  addu      $v1, $s0, $v1
/* 88D734 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 88D738 80240138 4600008D */  trunc.w.s $f2, $f0
/* 88D73C 8024013C 44061000 */  mfc1      $a2, $f2
/* 88D740 80240140 0C0B2026 */  jal       set_variable
/* 88D744 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 88D748 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 88D74C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 88D750 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 88D754 80240154 02021021 */  addu      $v0, $s0, $v0
/* 88D758 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 88D75C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 88D760 80240160 44061000 */  mfc1      $a2, $f2
/* 88D764 80240164 0C0B2026 */  jal       set_variable
/* 88D768 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 88D76C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 88D770 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 88D774 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 88D778 80240178 02021021 */  addu      $v0, $s0, $v0
/* 88D77C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 88D780 80240180 4600008D */  trunc.w.s $f2, $f0
/* 88D784 80240184 44061000 */  mfc1      $a2, $f2
/* 88D788 80240188 0C0B2026 */  jal       set_variable
/* 88D78C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 88D790 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 88D794 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 88D798 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 88D79C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 88D7A0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 88D7A4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 88D7A8 802401A8 44061000 */  mfc1      $a2, $f2
/* 88D7AC 802401AC 0C0B2026 */  jal       set_variable
/* 88D7B0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 88D7B4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 88D7B8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 88D7BC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 88D7C0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 88D7C4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 88D7C8 802401C8 03E00008 */  jr        $ra
/* 88D7CC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
