.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240064_8EBE84
/* 8EBE84 80240064 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 8EBE88 80240068 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 8EBE8C 8024006C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EBE90 80240070 AFB00010 */  sw        $s0, 0x10($sp)
/* 8EBE94 80240074 0080802D */  daddu     $s0, $a0, $zero
/* 8EBE98 80240078 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8EBE9C 8024007C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 8EBEA0 80240080 10620003 */  beq       $v1, $v0, .L80240090
/* 8EBEA4 80240084 24020002 */   addiu    $v0, $zero, 2
/* 8EBEA8 80240088 08090044 */  j         .L80240110
/* 8EBEAC 8024008C AE000084 */   sw       $zero, 0x84($s0)
.L80240090:
/* 8EBEB0 80240090 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 8EBEB4 80240094 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8EBEB8 80240098 80620040 */  lb        $v0, 0x40($v1)
/* 8EBEBC 8024009C 80670044 */  lb        $a3, 0x44($v1)
/* 8EBEC0 802400A0 04420001 */  bltzl     $v0, .L802400A8
/* 8EBEC4 802400A4 00021023 */   negu     $v0, $v0
.L802400A8:
/* 8EBEC8 802400A8 14400003 */  bnez      $v0, .L802400B8
/* 8EBECC 802400AC 00000000 */   nop
/* 8EBED0 802400B0 50E00017 */  beql      $a3, $zero, .L80240110
/* 8EBED4 802400B4 0000102D */   daddu    $v0, $zero, $zero
.L802400B8:
/* 8EBED8 802400B8 44822000 */  mtc1      $v0, $f4
/* 8EBEDC 802400BC 00000000 */  nop
/* 8EBEE0 802400C0 46802120 */  cvt.s.w   $f4, $f4
/* 8EBEE4 802400C4 44062000 */  mfc1      $a2, $f4
/* 8EBEE8 802400C8 44872000 */  mtc1      $a3, $f4
/* 8EBEEC 802400CC 00000000 */  nop
/* 8EBEF0 802400D0 46802120 */  cvt.s.w   $f4, $f4
/* 8EBEF4 802400D4 44806000 */  mtc1      $zero, $f12
/* 8EBEF8 802400D8 44072000 */  mfc1      $a3, $f4
/* 8EBEFC 802400DC 0C00A720 */  jal       atan2
/* 8EBF00 802400E0 46006386 */   mov.s    $f14, $f12
/* 8EBF04 802400E4 3C014270 */  lui       $at, 0x4270
/* 8EBF08 802400E8 44811000 */  mtc1      $at, $f2
/* 8EBF0C 802400EC 00000000 */  nop
/* 8EBF10 802400F0 4602003C */  c.lt.s    $f0, $f2
/* 8EBF14 802400F4 00000000 */  nop
/* 8EBF18 802400F8 45000004 */  bc1f      .L8024010C
/* 8EBF1C 802400FC 24020001 */   addiu    $v0, $zero, 1
/* 8EBF20 80240100 AE020084 */  sw        $v0, 0x84($s0)
/* 8EBF24 80240104 08090044 */  j         .L80240110
/* 8EBF28 80240108 24020002 */   addiu    $v0, $zero, 2
.L8024010C:
/* 8EBF2C 8024010C 0000102D */  daddu     $v0, $zero, $zero
.L80240110:
/* 8EBF30 80240110 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8EBF34 80240114 8FB00010 */  lw        $s0, 0x10($sp)
/* 8EBF38 80240118 03E00008 */  jr        $ra
/* 8EBF3C 8024011C 27BD0018 */   addiu    $sp, $sp, 0x18
