.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mac_02_UnkFunc25
/* 8232F4 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 8232F8 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 8232FC 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 823300 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* 823304 80240044 0080802D */  daddu     $s0, $a0, $zero
/* 823308 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* 82330C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 823310 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* 823314 80240054 24020002 */   addiu    $v0, $zero, 2
/* 823318 80240058 08090038 */  j         .L802400E0
/* 82331C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* 823320 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 823324 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 823328 80240068 80620040 */  lb        $v0, 0x40($v1)
/* 82332C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* 823330 80240070 04420001 */  bltzl     $v0, .L80240078
/* 823334 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* 823338 80240078 14400003 */  bnez      $v0, .L80240088
/* 82333C 8024007C 00000000 */   nop
/* 823340 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* 823344 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* 823348 80240088 44822000 */  mtc1      $v0, $f4
/* 82334C 8024008C 00000000 */  nop
/* 823350 80240090 46802120 */  cvt.s.w   $f4, $f4
/* 823354 80240094 44062000 */  mfc1      $a2, $f4
/* 823358 80240098 44872000 */  mtc1      $a3, $f4
/* 82335C 8024009C 00000000 */  nop
/* 823360 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* 823364 802400A4 44806000 */  mtc1      $zero, $f12
/* 823368 802400A8 44072000 */  mfc1      $a3, $f4
/* 82336C 802400AC 0C00A720 */  jal       atan2
/* 823370 802400B0 46006386 */   mov.s    $f14, $f12
/* 823374 802400B4 3C014270 */  lui       $at, 0x4270
/* 823378 802400B8 44811000 */  mtc1      $at, $f2
/* 82337C 802400BC 00000000 */  nop
/* 823380 802400C0 4602003C */  c.lt.s    $f0, $f2
/* 823384 802400C4 00000000 */  nop
/* 823388 802400C8 45000004 */  bc1f      .L802400DC
/* 82338C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* 823390 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* 823394 802400D4 08090038 */  j         .L802400E0
/* 823398 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* 82339C 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* 8233A0 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8233A4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8233A8 802400E8 03E00008 */  jr        $ra
/* 8233AC 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18
