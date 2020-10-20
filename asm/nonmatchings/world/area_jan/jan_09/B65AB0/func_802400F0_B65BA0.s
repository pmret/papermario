.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_B65BA0
/* B65BA0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B65BA4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* B65BA8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* B65BAC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* B65BB0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* B65BB4 80240104 0C016AFA */  jal       get_current_map_header
/* B65BB8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* B65BBC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* B65BC0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* B65BC4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* B65BC8 80240118 0C0B1EAF */  jal       get_variable
/* B65BCC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* B65BD0 80240120 0220202D */  daddu     $a0, $s1, $zero
/* B65BD4 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* B65BD8 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* B65BDC 8024012C 00028100 */  sll       $s0, $v0, 4
/* B65BE0 80240130 02031821 */  addu      $v1, $s0, $v1
/* B65BE4 80240134 C4600000 */  lwc1      $f0, ($v1)
/* B65BE8 80240138 4600008D */  trunc.w.s $f2, $f0
/* B65BEC 8024013C 44061000 */  mfc1      $a2, $f2
/* B65BF0 80240140 0C0B2026 */  jal       set_variable
/* B65BF4 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* B65BF8 80240148 0220202D */  daddu     $a0, $s1, $zero
/* B65BFC 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* B65C00 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* B65C04 80240154 02021021 */  addu      $v0, $s0, $v0
/* B65C08 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* B65C0C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* B65C10 80240160 44061000 */  mfc1      $a2, $f2
/* B65C14 80240164 0C0B2026 */  jal       set_variable
/* B65C18 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* B65C1C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* B65C20 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* B65C24 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* B65C28 80240178 02021021 */  addu      $v0, $s0, $v0
/* B65C2C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* B65C30 80240180 4600008D */  trunc.w.s $f2, $f0
/* B65C34 80240184 44061000 */  mfc1      $a2, $f2
/* B65C38 80240188 0C0B2026 */  jal       set_variable
/* B65C3C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* B65C40 80240190 0220202D */  daddu     $a0, $s1, $zero
/* B65C44 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* B65C48 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* B65C4C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* B65C50 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* B65C54 802401A4 4600008D */  trunc.w.s $f2, $f0
/* B65C58 802401A8 44061000 */  mfc1      $a2, $f2
/* B65C5C 802401AC 0C0B2026 */  jal       set_variable
/* B65C60 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* B65C64 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* B65C68 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* B65C6C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* B65C70 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* B65C74 802401C4 24020002 */  addiu     $v0, $zero, 2
/* B65C78 802401C8 03E00008 */  jr        $ra
/* B65C7C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
