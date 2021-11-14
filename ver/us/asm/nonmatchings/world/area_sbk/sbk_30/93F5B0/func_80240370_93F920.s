.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802448A0_943E50
.double 32767.0

.section .text

glabel func_80240370_93F920
/* 93F920 80240370 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 93F924 80240374 AFB00010 */  sw        $s0, 0x10($sp)
/* 93F928 80240378 0080802D */  daddu     $s0, $a0, $zero
/* 93F92C 8024037C AFBF001C */  sw        $ra, 0x1c($sp)
/* 93F930 80240380 AFB20018 */  sw        $s2, 0x18($sp)
/* 93F934 80240384 AFB10014 */  sw        $s1, 0x14($sp)
/* 93F938 80240388 8E110148 */  lw        $s1, 0x148($s0)
/* 93F93C 8024038C 86240008 */  lh        $a0, 8($s1)
/* 93F940 80240390 0C00EABB */  jal       get_npc_unsafe
/* 93F944 80240394 00A0902D */   daddu    $s2, $a1, $zero
/* 93F948 80240398 8E2300CC */  lw        $v1, 0xcc($s1)
/* 93F94C 8024039C 0040202D */  daddu     $a0, $v0, $zero
/* 93F950 802403A0 8C630000 */  lw        $v1, ($v1)
/* 93F954 802403A4 24020001 */  addiu     $v0, $zero, 1
/* 93F958 802403A8 AC830028 */  sw        $v1, 0x28($a0)
/* 93F95C 802403AC AE020070 */  sw        $v0, 0x70($s0)
/* 93F960 802403B0 8E220000 */  lw        $v0, ($s1)
/* 93F964 802403B4 3C030010 */  lui       $v1, 0x10
/* 93F968 802403B8 00431024 */  and       $v0, $v0, $v1
/* 93F96C 802403BC 10400004 */  beqz      $v0, .L802403D0
/* 93F970 802403C0 00000000 */   nop
/* 93F974 802403C4 C620006C */  lwc1      $f0, 0x6c($s1)
/* 93F978 802403C8 46800020 */  cvt.s.w   $f0, $f0
/* 93F97C 802403CC E480000C */  swc1      $f0, 0xc($a0)
.L802403D0:
/* 93F980 802403D0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 93F984 802403D4 8C420014 */  lw        $v0, 0x14($v0)
/* 93F988 802403D8 1C400004 */  bgtz      $v0, .L802403EC
/* 93F98C 802403DC 00000000 */   nop
/* 93F990 802403E0 C640000C */  lwc1      $f0, 0xc($s2)
/* 93F994 802403E4 08090103 */  j         .L8024040C
/* 93F998 802403E8 E4800018 */   swc1     $f0, 0x18($a0)
.L802403EC:
/* 93F99C 802403EC 3C018024 */  lui       $at, %hi(D_802448A0_943E50)
/* 93F9A0 802403F0 D42248A0 */  ldc1      $f2, %lo(D_802448A0_943E50)($at)
/* 93F9A4 802403F4 44820000 */  mtc1      $v0, $f0
/* 93F9A8 802403F8 00000000 */  nop
/* 93F9AC 802403FC 46800021 */  cvt.d.w   $f0, $f0
/* 93F9B0 80240400 46220003 */  div.d     $f0, $f0, $f2
/* 93F9B4 80240404 46200020 */  cvt.s.d   $f0, $f0
/* 93F9B8 80240408 E4800018 */  swc1      $f0, 0x18($a0)
.L8024040C:
/* 93F9BC 8024040C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 93F9C0 80240410 8FB20018 */  lw        $s2, 0x18($sp)
/* 93F9C4 80240414 8FB10014 */  lw        $s1, 0x14($sp)
/* 93F9C8 80240418 8FB00010 */  lw        $s0, 0x10($sp)
/* 93F9CC 8024041C 03E00008 */  jr        $ra
/* 93F9D0 80240420 27BD0020 */   addiu    $sp, $sp, 0x20
