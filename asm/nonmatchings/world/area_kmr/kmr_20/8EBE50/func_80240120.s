.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240120
/* 8EBF40 80240120 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8EBF44 80240124 AFB10014 */  sw        $s1, 0x14($sp)
/* 8EBF48 80240128 0080882D */  daddu     $s1, $a0, $zero
/* 8EBF4C 8024012C AFBF001C */  sw        $ra, 0x1c($sp)
/* 8EBF50 80240130 AFB20018 */  sw        $s2, 0x18($sp)
/* 8EBF54 80240134 0C016AFA */  jal       get_current_map_header
/* 8EBF58 80240138 AFB00010 */   sw       $s0, 0x10($sp)
/* 8EBF5C 8024013C 0220202D */  daddu     $a0, $s1, $zero
/* 8EBF60 80240140 3C05FE36 */  lui       $a1, 0xfe36
/* 8EBF64 80240144 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8EBF68 80240148 0C0B1EAF */  jal       get_variable
/* 8EBF6C 8024014C 0040902D */   daddu    $s2, $v0, $zero
/* 8EBF70 80240150 0220202D */  daddu     $a0, $s1, $zero
/* 8EBF74 80240154 3C05FE36 */  lui       $a1, 0xfe36
/* 8EBF78 80240158 8E430014 */  lw        $v1, 0x14($s2)
/* 8EBF7C 8024015C 00028100 */  sll       $s0, $v0, 4
/* 8EBF80 80240160 02031821 */  addu      $v1, $s0, $v1
/* 8EBF84 80240164 C4600000 */  lwc1      $f0, ($v1)
/* 8EBF88 80240168 4600008D */  trunc.w.s $f2, $f0
/* 8EBF8C 8024016C 44061000 */  mfc1      $a2, $f2
/* 8EBF90 80240170 0C0B2026 */  jal       set_variable
/* 8EBF94 80240174 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8EBF98 80240178 0220202D */  daddu     $a0, $s1, $zero
/* 8EBF9C 8024017C 8E420014 */  lw        $v0, 0x14($s2)
/* 8EBFA0 80240180 3C05FE36 */  lui       $a1, 0xfe36
/* 8EBFA4 80240184 02021021 */  addu      $v0, $s0, $v0
/* 8EBFA8 80240188 C4400004 */  lwc1      $f0, 4($v0)
/* 8EBFAC 8024018C 4600008D */  trunc.w.s $f2, $f0
/* 8EBFB0 80240190 44061000 */  mfc1      $a2, $f2
/* 8EBFB4 80240194 0C0B2026 */  jal       set_variable
/* 8EBFB8 80240198 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8EBFBC 8024019C 0220202D */  daddu     $a0, $s1, $zero
/* 8EBFC0 802401A0 8E420014 */  lw        $v0, 0x14($s2)
/* 8EBFC4 802401A4 3C05FE36 */  lui       $a1, 0xfe36
/* 8EBFC8 802401A8 02021021 */  addu      $v0, $s0, $v0
/* 8EBFCC 802401AC C4400008 */  lwc1      $f0, 8($v0)
/* 8EBFD0 802401B0 4600008D */  trunc.w.s $f2, $f0
/* 8EBFD4 802401B4 44061000 */  mfc1      $a2, $f2
/* 8EBFD8 802401B8 0C0B2026 */  jal       set_variable
/* 8EBFDC 802401BC 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 8EBFE0 802401C0 0220202D */  daddu     $a0, $s1, $zero
/* 8EBFE4 802401C4 8E420014 */  lw        $v0, 0x14($s2)
/* 8EBFE8 802401C8 3C05FE36 */  lui       $a1, 0xfe36
/* 8EBFEC 802401CC 02028021 */  addu      $s0, $s0, $v0
/* 8EBFF0 802401D0 C600000C */  lwc1      $f0, 0xc($s0)
/* 8EBFF4 802401D4 4600008D */  trunc.w.s $f2, $f0
/* 8EBFF8 802401D8 44061000 */  mfc1      $a2, $f2
/* 8EBFFC 802401DC 0C0B2026 */  jal       set_variable
/* 8EC000 802401E0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 8EC004 802401E4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8EC008 802401E8 8FB20018 */  lw        $s2, 0x18($sp)
/* 8EC00C 802401EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8EC010 802401F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EC014 802401F4 24020002 */  addiu     $v0, $zero, 2
/* 8EC018 802401F8 03E00008 */  jr        $ra
/* 8EC01C 802401FC 27BD0020 */   addiu    $sp, $sp, 0x20
