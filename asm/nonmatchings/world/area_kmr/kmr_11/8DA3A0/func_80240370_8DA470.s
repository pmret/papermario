.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240370_8DA470
/* 8DA470 80240370 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8DA474 80240374 AFB00010 */  sw        $s0, 0x10($sp)
/* 8DA478 80240378 0080802D */  daddu     $s0, $a0, $zero
/* 8DA47C 8024037C AFBF001C */  sw        $ra, 0x1c($sp)
/* 8DA480 80240380 AFB20018 */  sw        $s2, 0x18($sp)
/* 8DA484 80240384 AFB10014 */  sw        $s1, 0x14($sp)
/* 8DA488 80240388 8E110148 */  lw        $s1, 0x148($s0)
/* 8DA48C 8024038C 86240008 */  lh        $a0, 8($s1)
/* 8DA490 80240390 0C00EABB */  jal       get_npc_unsafe
/* 8DA494 80240394 00A0902D */   daddu    $s2, $a1, $zero
/* 8DA498 80240398 8E2300CC */  lw        $v1, 0xcc($s1)
/* 8DA49C 8024039C 0040202D */  daddu     $a0, $v0, $zero
/* 8DA4A0 802403A0 8C630000 */  lw        $v1, ($v1)
/* 8DA4A4 802403A4 24020001 */  addiu     $v0, $zero, 1
/* 8DA4A8 802403A8 AC830028 */  sw        $v1, 0x28($a0)
/* 8DA4AC 802403AC AE020070 */  sw        $v0, 0x70($s0)
/* 8DA4B0 802403B0 8E220000 */  lw        $v0, ($s1)
/* 8DA4B4 802403B4 3C030010 */  lui       $v1, 0x10
/* 8DA4B8 802403B8 00431024 */  and       $v0, $v0, $v1
/* 8DA4BC 802403BC 10400004 */  beqz      $v0, .L802403D0
/* 8DA4C0 802403C0 00000000 */   nop
/* 8DA4C4 802403C4 C620006C */  lwc1      $f0, 0x6c($s1)
/* 8DA4C8 802403C8 46800020 */  cvt.s.w   $f0, $f0
/* 8DA4CC 802403CC E480000C */  swc1      $f0, 0xc($a0)
.L802403D0:
/* 8DA4D0 802403D0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 8DA4D4 802403D4 8C420014 */  lw        $v0, 0x14($v0)
/* 8DA4D8 802403D8 1C400004 */  bgtz      $v0, .L802403EC
/* 8DA4DC 802403DC 00000000 */   nop
/* 8DA4E0 802403E0 C640000C */  lwc1      $f0, 0xc($s2)
/* 8DA4E4 802403E4 08090103 */  j         .L8024040C
/* 8DA4E8 802403E8 E4800018 */   swc1     $f0, 0x18($a0)
.L802403EC:
/* 8DA4EC 802403EC 3C018025 */  lui       $at, %hi(D_802510B0_8EB1B0)
/* 8DA4F0 802403F0 D42210B0 */  ldc1      $f2, %lo(D_802510B0_8EB1B0)($at)
/* 8DA4F4 802403F4 44820000 */  mtc1      $v0, $f0
/* 8DA4F8 802403F8 00000000 */  nop
/* 8DA4FC 802403FC 46800021 */  cvt.d.w   $f0, $f0
/* 8DA500 80240400 46220003 */  div.d     $f0, $f0, $f2
/* 8DA504 80240404 46200020 */  cvt.s.d   $f0, $f0
/* 8DA508 80240408 E4800018 */  swc1      $f0, 0x18($a0)
.L8024040C:
/* 8DA50C 8024040C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8DA510 80240410 8FB20018 */  lw        $s2, 0x18($sp)
/* 8DA514 80240414 8FB10014 */  lw        $s1, 0x14($sp)
/* 8DA518 80240418 8FB00010 */  lw        $s0, 0x10($sp)
/* 8DA51C 8024041C 03E00008 */  jr        $ra
/* 8DA520 80240420 27BD0020 */   addiu    $sp, $sp, 0x20
