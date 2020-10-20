.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_888CC0
/* 888CC0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 888CC4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 888CC8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 888CCC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 888CD0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 888CD4 80240104 0C016AFA */  jal       get_current_map_header
/* 888CD8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 888CDC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 888CE0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 888CE4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 888CE8 80240118 0C0B1EAF */  jal       get_variable
/* 888CEC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 888CF0 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 888CF4 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 888CF8 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 888CFC 8024012C 00028100 */  sll       $s0, $v0, 4
/* 888D00 80240130 02031821 */  addu      $v1, $s0, $v1
/* 888D04 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 888D08 80240138 4600008D */  trunc.w.s $f2, $f0
/* 888D0C 8024013C 44061000 */  mfc1      $a2, $f2
/* 888D10 80240140 0C0B2026 */  jal       set_variable
/* 888D14 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 888D18 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 888D1C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 888D20 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 888D24 80240154 02021021 */  addu      $v0, $s0, $v0
/* 888D28 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 888D2C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 888D30 80240160 44061000 */  mfc1      $a2, $f2
/* 888D34 80240164 0C0B2026 */  jal       set_variable
/* 888D38 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 888D3C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 888D40 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 888D44 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 888D48 80240178 02021021 */  addu      $v0, $s0, $v0
/* 888D4C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 888D50 80240180 4600008D */  trunc.w.s $f2, $f0
/* 888D54 80240184 44061000 */  mfc1      $a2, $f2
/* 888D58 80240188 0C0B2026 */  jal       set_variable
/* 888D5C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 888D60 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 888D64 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 888D68 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 888D6C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 888D70 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 888D74 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 888D78 802401A8 44061000 */  mfc1      $a2, $f2
/* 888D7C 802401AC 0C0B2026 */  jal       set_variable
/* 888D80 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 888D84 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 888D88 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 888D8C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 888D90 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 888D94 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 888D98 802401C8 03E00008 */  jr        $ra
/* 888D9C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
