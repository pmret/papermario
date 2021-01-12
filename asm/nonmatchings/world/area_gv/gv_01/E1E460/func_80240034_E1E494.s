.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_E1E494
/* E1E494 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* E1E498 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* E1E49C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1E4A0 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* E1E4A4 80240044 0080802D */  daddu     $s0, $a0, $zero
/* E1E4A8 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* E1E4AC 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* E1E4B0 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* E1E4B4 80240054 24020002 */   addiu    $v0, $zero, 2
/* E1E4B8 80240058 08090038 */  j         .L802400E0
/* E1E4BC 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* E1E4C0 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E1E4C4 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E1E4C8 80240068 80620040 */  lb        $v0, 0x40($v1)
/* E1E4CC 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* E1E4D0 80240070 04420001 */  bltzl     $v0, .L80240078
/* E1E4D4 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* E1E4D8 80240078 14400003 */  bnez      $v0, .L80240088
/* E1E4DC 8024007C 00000000 */   nop
/* E1E4E0 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* E1E4E4 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* E1E4E8 80240088 44822000 */  mtc1      $v0, $f4
/* E1E4EC 8024008C 00000000 */  nop
/* E1E4F0 80240090 46802120 */  cvt.s.w   $f4, $f4
/* E1E4F4 80240094 44062000 */  mfc1      $a2, $f4
/* E1E4F8 80240098 44872000 */  mtc1      $a3, $f4
/* E1E4FC 8024009C 00000000 */  nop
/* E1E500 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* E1E504 802400A4 44806000 */  mtc1      $zero, $f12
/* E1E508 802400A8 44072000 */  mfc1      $a3, $f4
/* E1E50C 802400AC 0C00A720 */  jal       atan2
/* E1E510 802400B0 46006386 */   mov.s    $f14, $f12
/* E1E514 802400B4 3C014270 */  lui       $at, 0x4270
/* E1E518 802400B8 44811000 */  mtc1      $at, $f2
/* E1E51C 802400BC 00000000 */  nop
/* E1E520 802400C0 4602003C */  c.lt.s    $f0, $f2
/* E1E524 802400C4 00000000 */  nop
/* E1E528 802400C8 45000004 */  bc1f      .L802400DC
/* E1E52C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* E1E530 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* E1E534 802400D4 08090038 */  j         .L802400E0
/* E1E538 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* E1E53C 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* E1E540 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* E1E544 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* E1E548 802400E8 03E00008 */  jr        $ra
/* E1E54C 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18
