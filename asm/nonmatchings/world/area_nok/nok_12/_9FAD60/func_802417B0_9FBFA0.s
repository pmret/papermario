.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417B0_9FBFA0
/* 9FBFA0 802417B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9FBFA4 802417B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FBFA8 802417B8 0080882D */  daddu     $s1, $a0, $zero
/* 9FBFAC 802417BC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9FBFB0 802417C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FBFB4 802417C4 8E300148 */  lw        $s0, 0x148($s1)
/* 9FBFB8 802417C8 0C00EABB */  jal       get_npc_unsafe
/* 9FBFBC 802417CC 86040008 */   lh       $a0, 8($s0)
/* 9FBFC0 802417D0 9443008E */  lhu       $v1, 0x8e($v0)
/* 9FBFC4 802417D4 2463FFFF */  addiu     $v1, $v1, -1
/* 9FBFC8 802417D8 A443008E */  sh        $v1, 0x8e($v0)
/* 9FBFCC 802417DC 00031C00 */  sll       $v1, $v1, 0x10
/* 9FBFD0 802417E0 14600008 */  bnez      $v1, .L80241804
/* 9FBFD4 802417E4 00000000 */   nop      
/* 9FBFD8 802417E8 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 9FBFDC 802417EC 30420080 */  andi      $v0, $v0, 0x80
/* 9FBFE0 802417F0 10400003 */  beqz      $v0, .L80241800
/* 9FBFE4 802417F4 2402000F */   addiu    $v0, $zero, 0xf
/* 9FBFE8 802417F8 08090601 */  j         .L80241804
/* 9FBFEC 802417FC AE220070 */   sw       $v0, 0x70($s1)
.L80241800:
/* 9FBFF0 80241800 AE200070 */  sw        $zero, 0x70($s1)
.L80241804:
/* 9FBFF4 80241804 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9FBFF8 80241808 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FBFFC 8024180C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FC000 80241810 03E00008 */  jr        $ra
/* 9FC004 80241814 27BD0020 */   addiu    $sp, $sp, 0x20
