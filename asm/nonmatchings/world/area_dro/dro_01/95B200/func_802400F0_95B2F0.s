.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_95B2F0
/* 95B2F0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95B2F4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 95B2F8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 95B2FC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 95B300 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 95B304 80240104 0C016AFA */  jal       get_current_map_header
/* 95B308 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 95B30C 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 95B310 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 95B314 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 95B318 80240118 0C0B1EAF */  jal       get_variable
/* 95B31C 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 95B320 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 95B324 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 95B328 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 95B32C 8024012C 00028100 */  sll       $s0, $v0, 4
/* 95B330 80240130 02031821 */  addu      $v1, $s0, $v1
/* 95B334 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 95B338 80240138 4600008D */  trunc.w.s $f2, $f0
/* 95B33C 8024013C 44061000 */  mfc1      $a2, $f2
/* 95B340 80240140 0C0B2026 */  jal       set_variable
/* 95B344 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 95B348 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 95B34C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 95B350 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 95B354 80240154 02021021 */  addu      $v0, $s0, $v0
/* 95B358 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 95B35C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 95B360 80240160 44061000 */  mfc1      $a2, $f2
/* 95B364 80240164 0C0B2026 */  jal       set_variable
/* 95B368 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 95B36C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 95B370 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 95B374 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 95B378 80240178 02021021 */  addu      $v0, $s0, $v0
/* 95B37C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 95B380 80240180 4600008D */  trunc.w.s $f2, $f0
/* 95B384 80240184 44061000 */  mfc1      $a2, $f2
/* 95B388 80240188 0C0B2026 */  jal       set_variable
/* 95B38C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 95B390 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 95B394 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 95B398 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 95B39C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 95B3A0 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 95B3A4 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 95B3A8 802401A8 44061000 */  mfc1      $a2, $f2
/* 95B3AC 802401AC 0C0B2026 */  jal       set_variable
/* 95B3B0 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 95B3B4 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 95B3B8 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 95B3BC 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 95B3C0 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 95B3C4 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 95B3C8 802401C8 03E00008 */  jr        $ra
/* 95B3CC 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
