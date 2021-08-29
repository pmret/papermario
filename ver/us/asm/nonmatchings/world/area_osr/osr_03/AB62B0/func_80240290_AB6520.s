.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240290_AB6520
/* AB6520 80240290 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB6524 80240294 AFB10014 */  sw        $s1, 0x14($sp)
/* AB6528 80240298 0080882D */  daddu     $s1, $a0, $zero
/* AB652C 8024029C AFBF0018 */  sw        $ra, 0x18($sp)
/* AB6530 802402A0 AFB00010 */  sw        $s0, 0x10($sp)
/* AB6534 802402A4 10A0002A */  beqz      $a1, .L80240350
/* AB6538 802402A8 8E30000C */   lw       $s0, 0xc($s1)
/* AB653C 802402AC 8E050000 */  lw        $a1, ($s0)
/* AB6540 802402B0 0C0B1EAF */  jal       get_variable
/* AB6544 802402B4 26100004 */   addiu    $s0, $s0, 4
/* AB6548 802402B8 0220202D */  daddu     $a0, $s1, $zero
/* AB654C 802402BC 8E050000 */  lw        $a1, ($s0)
/* AB6550 802402C0 0C0B210B */  jal       evt_get_float_variable
/* AB6554 802402C4 0040802D */   daddu    $s0, $v0, $zero
/* AB6558 802402C8 46000000 */  add.s     $f0, $f0, $f0
/* AB655C 802402CC 3C014120 */  lui       $at, 0x4120
/* AB6560 802402D0 44812000 */  mtc1      $at, $f4
/* AB6564 802402D4 00000000 */  nop
/* AB6568 802402D8 4600203C */  c.lt.s    $f4, $f0
/* AB656C 802402DC 00000000 */  nop
/* AB6570 802402E0 45000002 */  bc1f      .L802402EC
/* AB6574 802402E4 AE300070 */   sw       $s0, 0x70($s1)
/* AB6578 802402E8 46002006 */  mov.s     $f0, $f4
.L802402EC:
/* AB657C 802402EC 3C014380 */  lui       $at, 0x4380
/* AB6580 802402F0 44811000 */  mtc1      $at, $f2
/* AB6584 802402F4 46040003 */  div.s     $f0, $f0, $f4
/* AB6588 802402F8 46020002 */  mul.s     $f0, $f0, $f2
/* AB658C 802402FC 00000000 */  nop
/* AB6590 80240300 3C014F00 */  lui       $at, 0x4f00
/* AB6594 80240304 44811000 */  mtc1      $at, $f2
/* AB6598 80240308 00000000 */  nop
/* AB659C 8024030C 4600103E */  c.le.s    $f2, $f0
/* AB65A0 80240310 00000000 */  nop
/* AB65A4 80240314 45030005 */  bc1tl     .L8024032C
/* AB65A8 80240318 46020001 */   sub.s    $f0, $f0, $f2
/* AB65AC 8024031C 4600018D */  trunc.w.s $f6, $f0
/* AB65B0 80240320 44043000 */  mfc1      $a0, $f6
/* AB65B4 80240324 080900D1 */  j         .L80240344
/* AB65B8 80240328 308400FF */   andi     $a0, $a0, 0xff
.L8024032C:
/* AB65BC 8024032C 3C028000 */  lui       $v0, 0x8000
/* AB65C0 80240330 4600018D */  trunc.w.s $f6, $f0
/* AB65C4 80240334 44043000 */  mfc1      $a0, $f6
/* AB65C8 80240338 00000000 */  nop
/* AB65CC 8024033C 00822025 */  or        $a0, $a0, $v0
/* AB65D0 80240340 308400FF */  andi      $a0, $a0, 0xff
.L80240344:
/* AB65D4 80240344 3205FFFF */  andi      $a1, $s0, 0xffff
/* AB65D8 80240348 0C00A3C2 */  jal       start_rumble
/* AB65DC 8024034C 00052840 */   sll      $a1, $a1, 1
.L80240350:
/* AB65E0 80240350 8E230070 */  lw        $v1, 0x70($s1)
/* AB65E4 80240354 2463FFFF */  addiu     $v1, $v1, -1
/* AB65E8 80240358 AE230070 */  sw        $v1, 0x70($s1)
/* AB65EC 8024035C 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB65F0 80240360 8FB10014 */  lw        $s1, 0x14($sp)
/* AB65F4 80240364 8FB00010 */  lw        $s0, 0x10($sp)
/* AB65F8 80240368 2C620001 */  sltiu     $v0, $v1, 1
/* AB65FC 8024036C 03E00008 */  jr        $ra
/* AB6600 80240370 27BD0020 */   addiu    $sp, $sp, 0x20
/* AB6604 80240374 00000000 */  nop
/* AB6608 80240378 00000000 */  nop
/* AB660C 8024037C 00000000 */  nop
