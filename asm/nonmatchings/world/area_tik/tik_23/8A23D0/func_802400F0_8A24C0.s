.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F0_8A24C0
/* 8A24C0 802400F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A24C4 802400F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A24C8 802400F8 0080882D */  daddu     $s1, $a0, $zero
/* 8A24CC 802400FC AFBF001C */  sw        $ra, 0x1c($sp)
/* 8A24D0 80240100 AFB20018 */  sw        $s2, 0x18($sp)
/* 8A24D4 80240104 0C016AFA */  jal       get_current_map_header
/* 8A24D8 80240108 AFB00010 */   sw       $s0, 0x10($sp)
/* 8A24DC 8024010C 0220202D */  daddu     $a0, $s1, $zero
/* 8A24E0 80240110 3C05FE36 */  lui       $a1, 0xfe36
/* 8A24E4 80240114 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8A24E8 80240118 0C0B1EAF */  jal       get_variable
/* 8A24EC 8024011C 0040902D */   daddu    $s2, $v0, $zero
/* 8A24F0 80240120 0220202D */  daddu     $a0, $s1, $zero
/* 8A24F4 80240124 3C05FE36 */  lui       $a1, 0xfe36
/* 8A24F8 80240128 8E430014 */  lw        $v1, 0x14($s2)
/* 8A24FC 8024012C 00028100 */  sll       $s0, $v0, 4
/* 8A2500 80240130 02031821 */  addu      $v1, $s0, $v1
/* 8A2504 80240134 C4600000 */  lwc1      $f0, ($v1)
/* 8A2508 80240138 4600008D */  trunc.w.s $f2, $f0
/* 8A250C 8024013C 44061000 */  mfc1      $a2, $f2
/* 8A2510 80240140 0C0B2026 */  jal       set_variable
/* 8A2514 80240144 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8A2518 80240148 0220202D */  daddu     $a0, $s1, $zero
/* 8A251C 8024014C 8E420014 */  lw        $v0, 0x14($s2)
/* 8A2520 80240150 3C05FE36 */  lui       $a1, 0xfe36
/* 8A2524 80240154 02021021 */  addu      $v0, $s0, $v0
/* 8A2528 80240158 C4400004 */  lwc1      $f0, 4($v0)
/* 8A252C 8024015C 4600008D */  trunc.w.s $f2, $f0
/* 8A2530 80240160 44061000 */  mfc1      $a2, $f2
/* 8A2534 80240164 0C0B2026 */  jal       set_variable
/* 8A2538 80240168 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8A253C 8024016C 0220202D */  daddu     $a0, $s1, $zero
/* 8A2540 80240170 8E420014 */  lw        $v0, 0x14($s2)
/* 8A2544 80240174 3C05FE36 */  lui       $a1, 0xfe36
/* 8A2548 80240178 02021021 */  addu      $v0, $s0, $v0
/* 8A254C 8024017C C4400008 */  lwc1      $f0, 8($v0)
/* 8A2550 80240180 4600008D */  trunc.w.s $f2, $f0
/* 8A2554 80240184 44061000 */  mfc1      $a2, $f2
/* 8A2558 80240188 0C0B2026 */  jal       set_variable
/* 8A255C 8024018C 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 8A2560 80240190 0220202D */  daddu     $a0, $s1, $zero
/* 8A2564 80240194 8E420014 */  lw        $v0, 0x14($s2)
/* 8A2568 80240198 3C05FE36 */  lui       $a1, 0xfe36
/* 8A256C 8024019C 02028021 */  addu      $s0, $s0, $v0
/* 8A2570 802401A0 C600000C */  lwc1      $f0, 0xc($s0)
/* 8A2574 802401A4 4600008D */  trunc.w.s $f2, $f0
/* 8A2578 802401A8 44061000 */  mfc1      $a2, $f2
/* 8A257C 802401AC 0C0B2026 */  jal       set_variable
/* 8A2580 802401B0 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 8A2584 802401B4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8A2588 802401B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A258C 802401BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A2590 802401C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A2594 802401C4 24020002 */  addiu     $v0, $zero, 2
/* 8A2598 802401C8 03E00008 */  jr        $ra
/* 8A259C 802401CC 27BD0020 */   addiu    $sp, $sp, 0x20
