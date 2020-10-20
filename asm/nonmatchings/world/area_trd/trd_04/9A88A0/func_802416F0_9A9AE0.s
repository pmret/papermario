.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416F0_9A9AE0
/* 9A9AE0 802416F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9A9AE4 802416F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9A9AE8 802416F8 0080882D */  daddu     $s1, $a0, $zero
/* 9A9AEC 802416FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9A9AF0 80241700 AFB00010 */  sw        $s0, 0x10($sp)
/* 9A9AF4 80241704 8E300148 */  lw        $s0, 0x148($s1)
/* 9A9AF8 80241708 0C00EABB */  jal       get_npc_unsafe
/* 9A9AFC 8024170C 86040008 */   lh       $a0, 8($s0)
/* 9A9B00 80241710 9443008E */  lhu       $v1, 0x8e($v0)
/* 9A9B04 80241714 2463FFFF */  addiu     $v1, $v1, -1
/* 9A9B08 80241718 A443008E */  sh        $v1, 0x8e($v0)
/* 9A9B0C 8024171C 00031C00 */  sll       $v1, $v1, 0x10
/* 9A9B10 80241720 14600008 */  bnez      $v1, .L80241744
/* 9A9B14 80241724 00000000 */   nop      
/* 9A9B18 80241728 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 9A9B1C 8024172C 30420080 */  andi      $v0, $v0, 0x80
/* 9A9B20 80241730 10400003 */  beqz      $v0, .L80241740
/* 9A9B24 80241734 2402000F */   addiu    $v0, $zero, 0xf
/* 9A9B28 80241738 080905D1 */  j         .L80241744
/* 9A9B2C 8024173C AE220070 */   sw       $v0, 0x70($s1)
.L80241740:
/* 9A9B30 80241740 AE200070 */  sw        $zero, 0x70($s1)
.L80241744:
/* 9A9B34 80241744 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9A9B38 80241748 8FB10014 */  lw        $s1, 0x14($sp)
/* 9A9B3C 8024174C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9A9B40 80241750 03E00008 */  jr        $ra
/* 9A9B44 80241754 27BD0020 */   addiu    $sp, $sp, 0x20
