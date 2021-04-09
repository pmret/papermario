.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_04_UnkFunc25
/* 871D70 80240340 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 871D74 80240344 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 871D78 80240348 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 871D7C 8024034C AFB00010 */  sw        $s0, 0x10($sp)
/* 871D80 80240350 0080802D */  daddu     $s0, $a0, $zero
/* 871D84 80240354 AFBF0014 */  sw        $ra, 0x14($sp)
/* 871D88 80240358 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 871D8C 8024035C 10620003 */  beq       $v1, $v0, .L8024036C
/* 871D90 80240360 24020002 */   addiu    $v0, $zero, 2
/* 871D94 80240364 080900FB */  j         .L802403EC
/* 871D98 80240368 AE000084 */   sw       $zero, 0x84($s0)
.L8024036C:
/* 871D9C 8024036C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 871DA0 80240370 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 871DA4 80240374 80620040 */  lb        $v0, 0x40($v1)
/* 871DA8 80240378 80670044 */  lb        $a3, 0x44($v1)
/* 871DAC 8024037C 04420001 */  bltzl     $v0, .L80240384
/* 871DB0 80240380 00021023 */   negu     $v0, $v0
.L80240384:
/* 871DB4 80240384 14400003 */  bnez      $v0, .L80240394
/* 871DB8 80240388 00000000 */   nop
/* 871DBC 8024038C 50E00017 */  beql      $a3, $zero, .L802403EC
/* 871DC0 80240390 0000102D */   daddu    $v0, $zero, $zero
.L80240394:
/* 871DC4 80240394 44822000 */  mtc1      $v0, $f4
/* 871DC8 80240398 00000000 */  nop
/* 871DCC 8024039C 46802120 */  cvt.s.w   $f4, $f4
/* 871DD0 802403A0 44062000 */  mfc1      $a2, $f4
/* 871DD4 802403A4 44872000 */  mtc1      $a3, $f4
/* 871DD8 802403A8 00000000 */  nop
/* 871DDC 802403AC 46802120 */  cvt.s.w   $f4, $f4
/* 871DE0 802403B0 44806000 */  mtc1      $zero, $f12
/* 871DE4 802403B4 44072000 */  mfc1      $a3, $f4
/* 871DE8 802403B8 0C00A720 */  jal       atan2
/* 871DEC 802403BC 46006386 */   mov.s    $f14, $f12
/* 871DF0 802403C0 3C014270 */  lui       $at, 0x4270
/* 871DF4 802403C4 44811000 */  mtc1      $at, $f2
/* 871DF8 802403C8 00000000 */  nop
/* 871DFC 802403CC 4602003C */  c.lt.s    $f0, $f2
/* 871E00 802403D0 00000000 */  nop
/* 871E04 802403D4 45000004 */  bc1f      .L802403E8
/* 871E08 802403D8 24020001 */   addiu    $v0, $zero, 1
/* 871E0C 802403DC AE020084 */  sw        $v0, 0x84($s0)
/* 871E10 802403E0 080900FB */  j         .L802403EC
/* 871E14 802403E4 24020002 */   addiu    $v0, $zero, 2
.L802403E8:
/* 871E18 802403E8 0000102D */  daddu     $v0, $zero, $zero
.L802403EC:
/* 871E1C 802403EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 871E20 802403F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 871E24 802403F4 03E00008 */  jr        $ra
/* 871E28 802403F8 27BD0018 */   addiu    $sp, $sp, 0x18
