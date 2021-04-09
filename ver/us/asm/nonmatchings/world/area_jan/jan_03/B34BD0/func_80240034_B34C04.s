.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_03_UnkFunc25
/* B34C04 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* B34C08 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* B34C0C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B34C10 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* B34C14 80240044 0080802D */  daddu     $s0, $a0, $zero
/* B34C18 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* B34C1C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* B34C20 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* B34C24 80240054 24020002 */   addiu    $v0, $zero, 2
/* B34C28 80240058 08090038 */  j         .L802400E0
/* B34C2C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* B34C30 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B34C34 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B34C38 80240068 80620040 */  lb        $v0, 0x40($v1)
/* B34C3C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* B34C40 80240070 04420001 */  bltzl     $v0, .L80240078
/* B34C44 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* B34C48 80240078 14400003 */  bnez      $v0, .L80240088
/* B34C4C 8024007C 00000000 */   nop
/* B34C50 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* B34C54 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* B34C58 80240088 44822000 */  mtc1      $v0, $f4
/* B34C5C 8024008C 00000000 */  nop
/* B34C60 80240090 46802120 */  cvt.s.w   $f4, $f4
/* B34C64 80240094 44062000 */  mfc1      $a2, $f4
/* B34C68 80240098 44872000 */  mtc1      $a3, $f4
/* B34C6C 8024009C 00000000 */  nop
/* B34C70 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* B34C74 802400A4 44806000 */  mtc1      $zero, $f12
/* B34C78 802400A8 44072000 */  mfc1      $a3, $f4
/* B34C7C 802400AC 0C00A720 */  jal       atan2
/* B34C80 802400B0 46006386 */   mov.s    $f14, $f12
/* B34C84 802400B4 3C014270 */  lui       $at, 0x4270
/* B34C88 802400B8 44811000 */  mtc1      $at, $f2
/* B34C8C 802400BC 00000000 */  nop
/* B34C90 802400C0 4602003C */  c.lt.s    $f0, $f2
/* B34C94 802400C4 00000000 */  nop
/* B34C98 802400C8 45000004 */  bc1f      .L802400DC
/* B34C9C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* B34CA0 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* B34CA4 802400D4 08090038 */  j         .L802400E0
/* B34CA8 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* B34CAC 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* B34CB0 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* B34CB4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* B34CB8 802400E8 03E00008 */  jr        $ra
/* B34CBC 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18
