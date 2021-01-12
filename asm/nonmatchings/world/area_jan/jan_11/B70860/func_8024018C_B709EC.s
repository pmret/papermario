.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024018C_B709EC
/* B709EC 8024018C 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* B709F0 80240190 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* B709F4 80240194 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B709F8 80240198 AFB00010 */  sw        $s0, 0x10($sp)
/* B709FC 8024019C 0080802D */  daddu     $s0, $a0, $zero
/* B70A00 802401A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* B70A04 802401A4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* B70A08 802401A8 10620003 */  beq       $v1, $v0, .L802401B8
/* B70A0C 802401AC 24020002 */   addiu    $v0, $zero, 2
/* B70A10 802401B0 0809008E */  j         .L80240238
/* B70A14 802401B4 AE000084 */   sw       $zero, 0x84($s0)
.L802401B8:
/* B70A18 802401B8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B70A1C 802401BC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B70A20 802401C0 80620040 */  lb        $v0, 0x40($v1)
/* B70A24 802401C4 80670044 */  lb        $a3, 0x44($v1)
/* B70A28 802401C8 04420001 */  bltzl     $v0, .L802401D0
/* B70A2C 802401CC 00021023 */   negu     $v0, $v0
.L802401D0:
/* B70A30 802401D0 14400003 */  bnez      $v0, .L802401E0
/* B70A34 802401D4 00000000 */   nop
/* B70A38 802401D8 50E00017 */  beql      $a3, $zero, .L80240238
/* B70A3C 802401DC 0000102D */   daddu    $v0, $zero, $zero
.L802401E0:
/* B70A40 802401E0 44822000 */  mtc1      $v0, $f4
/* B70A44 802401E4 00000000 */  nop
/* B70A48 802401E8 46802120 */  cvt.s.w   $f4, $f4
/* B70A4C 802401EC 44062000 */  mfc1      $a2, $f4
/* B70A50 802401F0 44872000 */  mtc1      $a3, $f4
/* B70A54 802401F4 00000000 */  nop
/* B70A58 802401F8 46802120 */  cvt.s.w   $f4, $f4
/* B70A5C 802401FC 44806000 */  mtc1      $zero, $f12
/* B70A60 80240200 44072000 */  mfc1      $a3, $f4
/* B70A64 80240204 0C00A720 */  jal       atan2
/* B70A68 80240208 46006386 */   mov.s    $f14, $f12
/* B70A6C 8024020C 3C014270 */  lui       $at, 0x4270
/* B70A70 80240210 44811000 */  mtc1      $at, $f2
/* B70A74 80240214 00000000 */  nop
/* B70A78 80240218 4602003C */  c.lt.s    $f0, $f2
/* B70A7C 8024021C 00000000 */  nop
/* B70A80 80240220 45000004 */  bc1f      .L80240234
/* B70A84 80240224 24020001 */   addiu    $v0, $zero, 1
/* B70A88 80240228 AE020084 */  sw        $v0, 0x84($s0)
/* B70A8C 8024022C 0809008E */  j         .L80240238
/* B70A90 80240230 24020002 */   addiu    $v0, $zero, 2
.L80240234:
/* B70A94 80240234 0000102D */  daddu     $v0, $zero, $zero
.L80240238:
/* B70A98 80240238 8FBF0014 */  lw        $ra, 0x14($sp)
/* B70A9C 8024023C 8FB00010 */  lw        $s0, 0x10($sp)
/* B70AA0 80240240 03E00008 */  jr        $ra
/* B70AA4 80240244 27BD0018 */   addiu    $sp, $sp, 0x18
