.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400A0_B1D800
/* B1D800 802400A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B1D804 802400A4 AFB00010 */  sw        $s0, 0x10($sp)
/* B1D808 802400A8 0080802D */  daddu     $s0, $a0, $zero
/* B1D80C 802400AC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* B1D810 802400B0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* B1D814 802400B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* B1D818 802400B8 8E02013C */  lw        $v0, 0x13c($s0)
/* B1D81C 802400BC C46C0028 */  lwc1      $f12, 0x28($v1)
/* B1D820 802400C0 C46E0030 */  lwc1      $f14, 0x30($v1)
/* B1D824 802400C4 C4460008 */  lwc1      $f6, 8($v0)
/* B1D828 802400C8 468031A0 */  cvt.s.w   $f6, $f6
/* B1D82C 802400CC 44063000 */  mfc1      $a2, $f6
/* B1D830 802400D0 C4460010 */  lwc1      $f6, 0x10($v0)
/* B1D834 802400D4 468031A0 */  cvt.s.w   $f6, $f6
/* B1D838 802400D8 44073000 */  mfc1      $a3, $f6
/* B1D83C 802400DC 0C00A7B5 */  jal       dist2D
/* B1D840 802400E0 00000000 */   nop      
/* B1D844 802400E4 3C0142E1 */  lui       $at, 0x42e1
/* B1D848 802400E8 44811000 */  mtc1      $at, $f2
/* B1D84C 802400EC 46000106 */  mov.s     $f4, $f0
/* B1D850 802400F0 4602203C */  c.lt.s    $f4, $f2
/* B1D854 802400F4 00000000 */  nop       
/* B1D858 802400F8 45000003 */  bc1f      .L80240108
/* B1D85C 802400FC AE000084 */   sw       $zero, 0x84($s0)
/* B1D860 80240100 24020002 */  addiu     $v0, $zero, 2
/* B1D864 80240104 AE020084 */  sw        $v0, 0x84($s0)
.L80240108:
/* B1D868 80240108 3C014216 */  lui       $at, 0x4216
/* B1D86C 8024010C 44810000 */  mtc1      $at, $f0
/* B1D870 80240110 00000000 */  nop       
/* B1D874 80240114 4600203C */  c.lt.s    $f4, $f0
/* B1D878 80240118 00000000 */  nop       
/* B1D87C 8024011C 45000002 */  bc1f      .L80240128
/* B1D880 80240120 24020001 */   addiu    $v0, $zero, 1
/* B1D884 80240124 AE020084 */  sw        $v0, 0x84($s0)
.L80240128:
/* B1D888 80240128 8FBF0014 */  lw        $ra, 0x14($sp)
/* B1D88C 8024012C 8FB00010 */  lw        $s0, 0x10($sp)
/* B1D890 80240130 24020002 */  addiu     $v0, $zero, 2
/* B1D894 80240134 03E00008 */  jr        $ra
/* B1D898 80240138 27BD0018 */   addiu    $sp, $sp, 0x18
