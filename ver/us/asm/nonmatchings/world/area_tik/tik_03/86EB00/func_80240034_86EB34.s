.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_86EB34
/* 86EB34 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 86EB38 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 86EB3C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 86EB40 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* 86EB44 80240044 0080802D */  daddu     $s0, $a0, $zero
/* 86EB48 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* 86EB4C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 86EB50 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* 86EB54 80240054 24020002 */   addiu    $v0, $zero, 2
/* 86EB58 80240058 08090038 */  j         .L802400E0
/* 86EB5C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* 86EB60 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 86EB64 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 86EB68 80240068 80620040 */  lb        $v0, 0x40($v1)
/* 86EB6C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* 86EB70 80240070 04420001 */  bltzl     $v0, .L80240078
/* 86EB74 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* 86EB78 80240078 14400003 */  bnez      $v0, .L80240088
/* 86EB7C 8024007C 00000000 */   nop
/* 86EB80 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* 86EB84 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* 86EB88 80240088 44822000 */  mtc1      $v0, $f4
/* 86EB8C 8024008C 00000000 */  nop
/* 86EB90 80240090 46802120 */  cvt.s.w   $f4, $f4
/* 86EB94 80240094 44062000 */  mfc1      $a2, $f4
/* 86EB98 80240098 44872000 */  mtc1      $a3, $f4
/* 86EB9C 8024009C 00000000 */  nop
/* 86EBA0 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* 86EBA4 802400A4 44806000 */  mtc1      $zero, $f12
/* 86EBA8 802400A8 44072000 */  mfc1      $a3, $f4
/* 86EBAC 802400AC 0C00A720 */  jal       atan2
/* 86EBB0 802400B0 46006386 */   mov.s    $f14, $f12
/* 86EBB4 802400B4 3C014270 */  lui       $at, 0x4270
/* 86EBB8 802400B8 44811000 */  mtc1      $at, $f2
/* 86EBBC 802400BC 00000000 */  nop
/* 86EBC0 802400C0 4602003C */  c.lt.s    $f0, $f2
/* 86EBC4 802400C4 00000000 */  nop
/* 86EBC8 802400C8 45000004 */  bc1f      .L802400DC
/* 86EBCC 802400CC 24020001 */   addiu    $v0, $zero, 1
/* 86EBD0 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* 86EBD4 802400D4 08090038 */  j         .L802400E0
/* 86EBD8 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* 86EBDC 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* 86EBE0 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 86EBE4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 86EBE8 802400E8 03E00008 */  jr        $ra
/* 86EBEC 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18
