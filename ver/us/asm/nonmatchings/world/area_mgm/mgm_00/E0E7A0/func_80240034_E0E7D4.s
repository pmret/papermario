.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_E0E7D4
/* E0E7D4 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* E0E7D8 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* E0E7DC 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E0E7E0 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* E0E7E4 80240044 0080802D */  daddu     $s0, $a0, $zero
/* E0E7E8 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* E0E7EC 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* E0E7F0 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* E0E7F4 80240054 24020002 */   addiu    $v0, $zero, 2
/* E0E7F8 80240058 08090038 */  j         .L802400E0
/* E0E7FC 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* E0E800 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E0E804 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E0E808 80240068 80620040 */  lb        $v0, 0x40($v1)
/* E0E80C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* E0E810 80240070 04420001 */  bltzl     $v0, .L80240078
/* E0E814 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* E0E818 80240078 14400003 */  bnez      $v0, .L80240088
/* E0E81C 8024007C 00000000 */   nop
/* E0E820 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* E0E824 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* E0E828 80240088 44822000 */  mtc1      $v0, $f4
/* E0E82C 8024008C 00000000 */  nop
/* E0E830 80240090 46802120 */  cvt.s.w   $f4, $f4
/* E0E834 80240094 44062000 */  mfc1      $a2, $f4
/* E0E838 80240098 44872000 */  mtc1      $a3, $f4
/* E0E83C 8024009C 00000000 */  nop
/* E0E840 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* E0E844 802400A4 44806000 */  mtc1      $zero, $f12
/* E0E848 802400A8 44072000 */  mfc1      $a3, $f4
/* E0E84C 802400AC 0C00A720 */  jal       atan2
/* E0E850 802400B0 46006386 */   mov.s    $f14, $f12
/* E0E854 802400B4 3C014270 */  lui       $at, 0x4270
/* E0E858 802400B8 44811000 */  mtc1      $at, $f2
/* E0E85C 802400BC 00000000 */  nop
/* E0E860 802400C0 4602003C */  c.lt.s    $f0, $f2
/* E0E864 802400C4 00000000 */  nop
/* E0E868 802400C8 45000004 */  bc1f      .L802400DC
/* E0E86C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* E0E870 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* E0E874 802400D4 08090038 */  j         .L802400E0
/* E0E878 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* E0E87C 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* E0E880 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* E0E884 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* E0E888 802400E8 03E00008 */  jr        $ra
/* E0E88C 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18
