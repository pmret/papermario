.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400A0_C4C430
/* C4C430 802400A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C4C434 802400A4 AFB00010 */  sw        $s0, 0x10($sp)
/* C4C438 802400A8 0080802D */  daddu     $s0, $a0, $zero
/* C4C43C 802400AC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* C4C440 802400B0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* C4C444 802400B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* C4C448 802400B8 8E02013C */  lw        $v0, 0x13c($s0)
/* C4C44C 802400BC C46C0028 */  lwc1      $f12, 0x28($v1)
/* C4C450 802400C0 C46E0030 */  lwc1      $f14, 0x30($v1)
/* C4C454 802400C4 C4460008 */  lwc1      $f6, 8($v0)
/* C4C458 802400C8 468031A0 */  cvt.s.w   $f6, $f6
/* C4C45C 802400CC 44063000 */  mfc1      $a2, $f6
/* C4C460 802400D0 C4460010 */  lwc1      $f6, 0x10($v0)
/* C4C464 802400D4 468031A0 */  cvt.s.w   $f6, $f6
/* C4C468 802400D8 44073000 */  mfc1      $a3, $f6
/* C4C46C 802400DC 0C00A7B5 */  jal       dist2D
/* C4C470 802400E0 00000000 */   nop      
/* C4C474 802400E4 3C0142E1 */  lui       $at, 0x42e1
/* C4C478 802400E8 44811000 */  mtc1      $at, $f2
/* C4C47C 802400EC 46000106 */  mov.s     $f4, $f0
/* C4C480 802400F0 4602203C */  c.lt.s    $f4, $f2
/* C4C484 802400F4 00000000 */  nop       
/* C4C488 802400F8 45000003 */  bc1f      .L80240108
/* C4C48C 802400FC AE000084 */   sw       $zero, 0x84($s0)
/* C4C490 80240100 24020002 */  addiu     $v0, $zero, 2
/* C4C494 80240104 AE020084 */  sw        $v0, 0x84($s0)
.L80240108:
/* C4C498 80240108 3C014216 */  lui       $at, 0x4216
/* C4C49C 8024010C 44810000 */  mtc1      $at, $f0
/* C4C4A0 80240110 00000000 */  nop       
/* C4C4A4 80240114 4600203C */  c.lt.s    $f4, $f0
/* C4C4A8 80240118 00000000 */  nop       
/* C4C4AC 8024011C 45000002 */  bc1f      .L80240128
/* C4C4B0 80240120 24020001 */   addiu    $v0, $zero, 1
/* C4C4B4 80240124 AE020084 */  sw        $v0, 0x84($s0)
.L80240128:
/* C4C4B8 80240128 8FBF0014 */  lw        $ra, 0x14($sp)
/* C4C4BC 8024012C 8FB00010 */  lw        $s0, 0x10($sp)
/* C4C4C0 80240130 24020002 */  addiu     $v0, $zero, 2
/* C4C4C4 80240134 03E00008 */  jr        $ra
/* C4C4C8 80240138 27BD0018 */   addiu    $sp, $sp, 0x18
