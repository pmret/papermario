.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F4
/* 91E664 802400F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91E668 802400F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 91E66C 802400FC 0080802D */  daddu     $s0, $a0, $zero
/* 91E670 80240100 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91E674 80240104 AFB10014 */  sw        $s1, 0x14($sp)
/* 91E678 80240108 8E02000C */  lw        $v0, 0xc($s0)
/* 91E67C 8024010C 8C510000 */  lw        $s1, ($v0)
/* 91E680 80240110 0C0B1EAF */  jal       get_variable
/* 91E684 80240114 0220282D */   daddu    $a1, $s1, $zero
/* 91E688 80240118 3C03FFF0 */  lui       $v1, 0xfff0
/* 91E68C 8024011C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 91E690 80240120 0200202D */  daddu     $a0, $s0, $zero
/* 91E694 80240124 00431024 */  and       $v0, $v0, $v1
/* 91E698 80240128 00021140 */  sll       $v0, $v0, 5
/* 91E69C 8024012C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 91E6A0 80240130 00C23021 */  addu      $a2, $a2, $v0
/* 91E6A4 80240134 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 91E6A8 80240138 0C0B2026 */  jal       set_variable
/* 91E6AC 8024013C 0220282D */   daddu    $a1, $s1, $zero
/* 91E6B0 80240140 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91E6B4 80240144 8FB10014 */  lw        $s1, 0x14($sp)
/* 91E6B8 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* 91E6BC 8024014C 24020002 */  addiu     $v0, $zero, 2
/* 91E6C0 80240150 03E00008 */  jr        $ra
/* 91E6C4 80240154 27BD0020 */   addiu    $sp, $sp, 0x20
/* 91E6C8 80240158 00000000 */  nop       
/* 91E6CC 8024015C 00000000 */  nop       
