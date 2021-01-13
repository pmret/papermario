.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_CBDD04
/* CBDD04 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* CBDD08 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* CBDD0C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CBDD10 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* CBDD14 80240044 0080802D */  daddu     $s0, $a0, $zero
/* CBDD18 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* CBDD1C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* CBDD20 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* CBDD24 80240054 24020002 */   addiu    $v0, $zero, 2
/* CBDD28 80240058 08090038 */  j         .L802400E0
/* CBDD2C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* CBDD30 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* CBDD34 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* CBDD38 80240068 80620040 */  lb        $v0, 0x40($v1)
/* CBDD3C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* CBDD40 80240070 04420001 */  bltzl     $v0, .L80240078
/* CBDD44 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* CBDD48 80240078 14400003 */  bnez      $v0, .L80240088
/* CBDD4C 8024007C 00000000 */   nop
/* CBDD50 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* CBDD54 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* CBDD58 80240088 44822000 */  mtc1      $v0, $f4
/* CBDD5C 8024008C 00000000 */  nop
/* CBDD60 80240090 46802120 */  cvt.s.w   $f4, $f4
/* CBDD64 80240094 44062000 */  mfc1      $a2, $f4
/* CBDD68 80240098 44872000 */  mtc1      $a3, $f4
/* CBDD6C 8024009C 00000000 */  nop
/* CBDD70 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* CBDD74 802400A4 44806000 */  mtc1      $zero, $f12
/* CBDD78 802400A8 44072000 */  mfc1      $a3, $f4
/* CBDD7C 802400AC 0C00A720 */  jal       atan2
/* CBDD80 802400B0 46006386 */   mov.s    $f14, $f12
/* CBDD84 802400B4 3C014270 */  lui       $at, 0x4270
/* CBDD88 802400B8 44811000 */  mtc1      $at, $f2
/* CBDD8C 802400BC 00000000 */  nop
/* CBDD90 802400C0 4602003C */  c.lt.s    $f0, $f2
/* CBDD94 802400C4 00000000 */  nop
/* CBDD98 802400C8 45000004 */  bc1f      .L802400DC
/* CBDD9C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* CBDDA0 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* CBDDA4 802400D4 08090038 */  j         .L802400E0
/* CBDDA8 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* CBDDAC 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* CBDDB0 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CBDDB4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* CBDDB8 802400E8 03E00008 */  jr        $ra
/* CBDDBC 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18
