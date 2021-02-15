.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240340_89DAE0
/* 89DAE0 80240340 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 89DAE4 80240344 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 89DAE8 80240348 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 89DAEC 8024034C AFB00010 */  sw        $s0, 0x10($sp)
/* 89DAF0 80240350 0080802D */  daddu     $s0, $a0, $zero
/* 89DAF4 80240354 AFBF0014 */  sw        $ra, 0x14($sp)
/* 89DAF8 80240358 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 89DAFC 8024035C 10620003 */  beq       $v1, $v0, .L8024036C
/* 89DB00 80240360 24020002 */   addiu    $v0, $zero, 2
/* 89DB04 80240364 080900FB */  j         .L802403EC
/* 89DB08 80240368 AE000084 */   sw       $zero, 0x84($s0)
.L8024036C:
/* 89DB0C 8024036C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 89DB10 80240370 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 89DB14 80240374 80620040 */  lb        $v0, 0x40($v1)
/* 89DB18 80240378 80670044 */  lb        $a3, 0x44($v1)
/* 89DB1C 8024037C 04420001 */  bltzl     $v0, .L80240384
/* 89DB20 80240380 00021023 */   negu     $v0, $v0
.L80240384:
/* 89DB24 80240384 14400003 */  bnez      $v0, .L80240394
/* 89DB28 80240388 00000000 */   nop
/* 89DB2C 8024038C 50E00017 */  beql      $a3, $zero, .L802403EC
/* 89DB30 80240390 0000102D */   daddu    $v0, $zero, $zero
.L80240394:
/* 89DB34 80240394 44822000 */  mtc1      $v0, $f4
/* 89DB38 80240398 00000000 */  nop
/* 89DB3C 8024039C 46802120 */  cvt.s.w   $f4, $f4
/* 89DB40 802403A0 44062000 */  mfc1      $a2, $f4
/* 89DB44 802403A4 44872000 */  mtc1      $a3, $f4
/* 89DB48 802403A8 00000000 */  nop
/* 89DB4C 802403AC 46802120 */  cvt.s.w   $f4, $f4
/* 89DB50 802403B0 44806000 */  mtc1      $zero, $f12
/* 89DB54 802403B4 44072000 */  mfc1      $a3, $f4
/* 89DB58 802403B8 0C00A720 */  jal       atan2
/* 89DB5C 802403BC 46006386 */   mov.s    $f14, $f12
/* 89DB60 802403C0 3C014270 */  lui       $at, 0x4270
/* 89DB64 802403C4 44811000 */  mtc1      $at, $f2
/* 89DB68 802403C8 00000000 */  nop
/* 89DB6C 802403CC 4602003C */  c.lt.s    $f0, $f2
/* 89DB70 802403D0 00000000 */  nop
/* 89DB74 802403D4 45000004 */  bc1f      .L802403E8
/* 89DB78 802403D8 24020001 */   addiu    $v0, $zero, 1
/* 89DB7C 802403DC AE020084 */  sw        $v0, 0x84($s0)
/* 89DB80 802403E0 080900FB */  j         .L802403EC
/* 89DB84 802403E4 24020002 */   addiu    $v0, $zero, 2
.L802403E8:
/* 89DB88 802403E8 0000102D */  daddu     $v0, $zero, $zero
.L802403EC:
/* 89DB8C 802403EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 89DB90 802403F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 89DB94 802403F4 03E00008 */  jr        $ra
/* 89DB98 802403F8 27BD0018 */   addiu    $sp, $sp, 0x18
