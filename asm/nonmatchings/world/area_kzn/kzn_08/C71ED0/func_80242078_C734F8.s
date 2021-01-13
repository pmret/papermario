.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242078_C734F8
/* C734F8 80242078 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C734FC 8024207C AFB3004C */  sw        $s3, 0x4c($sp)
/* C73500 80242080 0080982D */  daddu     $s3, $a0, $zero
/* C73504 80242084 AFBF0050 */  sw        $ra, 0x50($sp)
/* C73508 80242088 AFB20048 */  sw        $s2, 0x48($sp)
/* C7350C 8024208C AFB10044 */  sw        $s1, 0x44($sp)
/* C73510 80242090 AFB00040 */  sw        $s0, 0x40($sp)
/* C73514 80242094 8E720148 */  lw        $s2, 0x148($s3)
/* C73518 80242098 00A0882D */  daddu     $s1, $a1, $zero
/* C7351C 8024209C 86440008 */  lh        $a0, 8($s2)
/* C73520 802420A0 0C00EABB */  jal       get_npc_unsafe
/* C73524 802420A4 00C0802D */   daddu    $s0, $a2, $zero
/* C73528 802420A8 0200202D */  daddu     $a0, $s0, $zero
/* C7352C 802420AC 0240282D */  daddu     $a1, $s2, $zero
/* C73530 802420B0 24030001 */  addiu     $v1, $zero, 1
/* C73534 802420B4 AFA30010 */  sw        $v1, 0x10($sp)
/* C73538 802420B8 8E260024 */  lw        $a2, 0x24($s1)
/* C7353C 802420BC 8E270028 */  lw        $a3, 0x28($s1)
/* C73540 802420C0 0C01242D */  jal       func_800490B4
/* C73544 802420C4 0040802D */   daddu    $s0, $v0, $zero
/* C73548 802420C8 14400020 */  bnez      $v0, .L8024214C
/* C7354C 802420CC 24040002 */   addiu    $a0, $zero, 2
/* C73550 802420D0 0200282D */  daddu     $a1, $s0, $zero
/* C73554 802420D4 0000302D */  daddu     $a2, $zero, $zero
/* C73558 802420D8 860300A8 */  lh        $v1, 0xa8($s0)
/* C7355C 802420DC 3C013F80 */  lui       $at, 0x3f80
/* C73560 802420E0 44810000 */  mtc1      $at, $f0
/* C73564 802420E4 3C014000 */  lui       $at, 0x4000
/* C73568 802420E8 44811000 */  mtc1      $at, $f2
/* C7356C 802420EC 3C01C1A0 */  lui       $at, 0xc1a0
/* C73570 802420F0 44812000 */  mtc1      $at, $f4
/* C73574 802420F4 2402000F */  addiu     $v0, $zero, 0xf
/* C73578 802420F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* C7357C 802420FC 44834000 */  mtc1      $v1, $f8
/* C73580 80242100 00000000 */  nop
/* C73584 80242104 46804220 */  cvt.s.w   $f8, $f8
/* C73588 80242108 44074000 */  mfc1      $a3, $f8
/* C7358C 8024210C 27A20028 */  addiu     $v0, $sp, 0x28
/* C73590 80242110 AFA20020 */  sw        $v0, 0x20($sp)
/* C73594 80242114 E7A00010 */  swc1      $f0, 0x10($sp)
/* C73598 80242118 E7A20014 */  swc1      $f2, 0x14($sp)
/* C7359C 8024211C 0C01BFA4 */  jal       fx_emote
/* C735A0 80242120 E7A40018 */   swc1     $f4, 0x18($sp)
/* C735A4 80242124 8E4200CC */  lw        $v0, 0xcc($s2)
/* C735A8 80242128 8C430000 */  lw        $v1, ($v0)
/* C735AC 8024212C 2402001E */  addiu     $v0, $zero, 0x1e
/* C735B0 80242130 A602008E */  sh        $v0, 0x8e($s0)
/* C735B4 80242134 24020014 */  addiu     $v0, $zero, 0x14
/* C735B8 80242138 AE030028 */  sw        $v1, 0x28($s0)
/* C735BC 8024213C AE620070 */  sw        $v0, 0x70($s3)
/* C735C0 80242140 2402001E */  addiu     $v0, $zero, 0x1e
/* C735C4 80242144 080908B7 */  j         .L802422DC
/* C735C8 80242148 AE420090 */   sw       $v0, 0x90($s2)
.L8024214C:
/* C735CC 8024214C 8E050018 */  lw        $a1, 0x18($s0)
/* C735D0 80242150 8E06000C */  lw        $a2, 0xc($s0)
/* C735D4 80242154 0C00EA95 */  jal       npc_move_heading
/* C735D8 80242158 0200202D */   daddu    $a0, $s0, $zero
/* C735DC 8024215C 8E020000 */  lw        $v0, ($s0)
/* C735E0 80242160 30420008 */  andi      $v0, $v0, 8
/* C735E4 80242164 14400028 */  bnez      $v0, .L80242208
/* C735E8 80242168 0000882D */   daddu    $s1, $zero, $zero
/* C735EC 8024216C 27A5002C */  addiu     $a1, $sp, 0x2c
/* C735F0 80242170 27A60030 */  addiu     $a2, $sp, 0x30
/* C735F4 80242174 860200A8 */  lh        $v0, 0xa8($s0)
/* C735F8 80242178 C6000038 */  lwc1      $f0, 0x38($s0)
/* C735FC 8024217C 44821000 */  mtc1      $v0, $f2
/* C73600 80242180 00000000 */  nop
/* C73604 80242184 468010A0 */  cvt.s.w   $f2, $f2
/* C73608 80242188 E7A0002C */  swc1      $f0, 0x2c($sp)
/* C7360C 8024218C 860200A8 */  lh        $v0, 0xa8($s0)
/* C73610 80242190 C604003C */  lwc1      $f4, 0x3c($s0)
/* C73614 80242194 C6060040 */  lwc1      $f6, 0x40($s0)
/* C73618 80242198 44820000 */  mtc1      $v0, $f0
/* C7361C 8024219C 00000000 */  nop
/* C73620 802421A0 46800021 */  cvt.d.w   $f0, $f0
/* C73624 802421A4 46022100 */  add.s     $f4, $f4, $f2
/* C73628 802421A8 3C014008 */  lui       $at, 0x4008
/* C7362C 802421AC 44811800 */  mtc1      $at, $f3
/* C73630 802421B0 44801000 */  mtc1      $zero, $f2
/* C73634 802421B4 27A20038 */  addiu     $v0, $sp, 0x38
/* C73638 802421B8 46220000 */  add.d     $f0, $f0, $f2
/* C7363C 802421BC E7A60034 */  swc1      $f6, 0x34($sp)
/* C73640 802421C0 E7A40030 */  swc1      $f4, 0x30($sp)
/* C73644 802421C4 46200020 */  cvt.s.d   $f0, $f0
/* C73648 802421C8 E7A00038 */  swc1      $f0, 0x38($sp)
/* C7364C 802421CC AFA20010 */  sw        $v0, 0x10($sp)
/* C73650 802421D0 8E040080 */  lw        $a0, 0x80($s0)
/* C73654 802421D4 0C0372DF */  jal       func_800DCB7C
/* C73658 802421D8 27A70034 */   addiu    $a3, $sp, 0x34
/* C7365C 802421DC 1040000A */  beqz      $v0, .L80242208
/* C73660 802421E0 00000000 */   nop
/* C73664 802421E4 860200A8 */  lh        $v0, 0xa8($s0)
/* C73668 802421E8 C7A20038 */  lwc1      $f2, 0x38($sp)
/* C7366C 802421EC 44820000 */  mtc1      $v0, $f0
/* C73670 802421F0 00000000 */  nop
/* C73674 802421F4 46800020 */  cvt.s.w   $f0, $f0
/* C73678 802421F8 4600103C */  c.lt.s    $f2, $f0
/* C7367C 802421FC 00000000 */  nop
/* C73680 80242200 45030001 */  bc1tl     .L80242208
/* C73684 80242204 24110001 */   addiu    $s1, $zero, 1
.L80242208:
/* C73688 80242208 12200008 */  beqz      $s1, .L8024222C
/* C7368C 8024220C 00000000 */   nop
/* C73690 80242210 C7A00030 */  lwc1      $f0, 0x30($sp)
/* C73694 80242214 3C013FF0 */  lui       $at, 0x3ff0
/* C73698 80242218 44811800 */  mtc1      $at, $f3
/* C7369C 8024221C 44801000 */  mtc1      $zero, $f2
/* C736A0 80242220 46000021 */  cvt.d.s   $f0, $f0
/* C736A4 80242224 080908AD */  j         .L802422B4
/* C736A8 80242228 46220000 */   add.d    $f0, $f0, $f2
.L8024222C:
/* C736AC 8024222C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C736B0 80242230 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C736B4 80242234 3C014018 */  lui       $at, 0x4018
/* C736B8 80242238 44811800 */  mtc1      $at, $f3
/* C736BC 8024223C 44801000 */  mtc1      $zero, $f2
/* C736C0 80242240 C440002C */  lwc1      $f0, 0x2c($v0)
/* C736C4 80242244 C604003C */  lwc1      $f4, 0x3c($s0)
/* C736C8 80242248 46000021 */  cvt.d.s   $f0, $f0
/* C736CC 8024224C 46220000 */  add.d     $f0, $f0, $f2
/* C736D0 80242250 46002121 */  cvt.d.s   $f4, $f4
/* C736D4 80242254 46202001 */  sub.d     $f0, $f4, $f0
/* C736D8 80242258 462001A0 */  cvt.s.d   $f6, $f0
/* C736DC 8024225C 44800000 */  mtc1      $zero, $f0
/* C736E0 80242260 44800800 */  mtc1      $zero, $f1
/* C736E4 80242264 460030A1 */  cvt.d.s   $f2, $f6
/* C736E8 80242268 4620103C */  c.lt.d    $f2, $f0
/* C736EC 8024226C 00000000 */  nop
/* C736F0 80242270 45010009 */  bc1t      .L80242298
/* C736F4 80242274 00000000 */   nop
/* C736F8 80242278 3C014010 */  lui       $at, 0x4010
/* C736FC 8024227C 44810800 */  mtc1      $at, $f1
/* C73700 80242280 44800000 */  mtc1      $zero, $f0
/* C73704 80242284 00000000 */  nop
/* C73708 80242288 4622003C */  c.lt.d    $f0, $f2
/* C7370C 8024228C 00000000 */  nop
/* C73710 80242290 4500000A */  bc1f      .L802422BC
/* C73714 80242294 00000000 */   nop
.L80242298:
/* C73718 80242298 3C018024 */  lui       $at, %hi(D_80245638)
/* C7371C 8024229C D4225638 */  ldc1      $f2, %lo(D_80245638)($at)
/* C73720 802422A0 46003187 */  neg.s     $f6, $f6
/* C73724 802422A4 46003021 */  cvt.d.s   $f0, $f6
/* C73728 802422A8 46220002 */  mul.d     $f0, $f0, $f2
/* C7372C 802422AC 00000000 */  nop
/* C73730 802422B0 46202000 */  add.d     $f0, $f4, $f0
.L802422B4:
/* C73734 802422B4 46200020 */  cvt.s.d   $f0, $f0
/* C73738 802422B8 E600003C */  swc1      $f0, 0x3c($s0)
.L802422BC:
/* C7373C 802422BC 8602008E */  lh        $v0, 0x8e($s0)
/* C73740 802422C0 9603008E */  lhu       $v1, 0x8e($s0)
/* C73744 802422C4 18400003 */  blez      $v0, .L802422D4
/* C73748 802422C8 2462FFFF */   addiu    $v0, $v1, -1
/* C7374C 802422CC 080908B7 */  j         .L802422DC
/* C73750 802422D0 A602008E */   sh       $v0, 0x8e($s0)
.L802422D4:
/* C73754 802422D4 2402000C */  addiu     $v0, $zero, 0xc
/* C73758 802422D8 AE620070 */  sw        $v0, 0x70($s3)
.L802422DC:
/* C7375C 802422DC 8FBF0050 */  lw        $ra, 0x50($sp)
/* C73760 802422E0 8FB3004C */  lw        $s3, 0x4c($sp)
/* C73764 802422E4 8FB20048 */  lw        $s2, 0x48($sp)
/* C73768 802422E8 8FB10044 */  lw        $s1, 0x44($sp)
/* C7376C 802422EC 8FB00040 */  lw        $s0, 0x40($sp)
/* C73770 802422F0 03E00008 */  jr        $ra
/* C73774 802422F4 27BD0058 */   addiu    $sp, $sp, 0x58
