.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240334_A60D04
/* A60D04 80240334 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A60D08 80240338 AFB20038 */  sw        $s2, 0x38($sp)
/* A60D0C 8024033C 0080902D */  daddu     $s2, $a0, $zero
/* A60D10 80240340 AFBF003C */  sw        $ra, 0x3c($sp)
/* A60D14 80240344 AFB10034 */  sw        $s1, 0x34($sp)
/* A60D18 80240348 AFB00030 */  sw        $s0, 0x30($sp)
/* A60D1C 8024034C 8E510148 */  lw        $s1, 0x148($s2)
/* A60D20 80240350 0C00EABB */  jal       get_npc_unsafe
/* A60D24 80240354 86240008 */   lh       $a0, 8($s1)
/* A60D28 80240358 0040802D */  daddu     $s0, $v0, $zero
/* A60D2C 8024035C 9602008E */  lhu       $v0, 0x8e($s0)
/* A60D30 80240360 2442FFFF */  addiu     $v0, $v0, -1
/* A60D34 80240364 A602008E */  sh        $v0, 0x8e($s0)
/* A60D38 80240368 00021400 */  sll       $v0, $v0, 0x10
/* A60D3C 8024036C 1C40002B */  bgtz      $v0, .L8024041C
/* A60D40 80240370 00000000 */   nop
/* A60D44 80240374 0C090000 */  jal       func_80240000_A609D0
/* A60D48 80240378 0240202D */   daddu    $a0, $s2, $zero
/* A60D4C 8024037C 0040202D */  daddu     $a0, $v0, $zero
/* A60D50 80240380 0481001A */  bgez      $a0, .L802403EC
/* A60D54 80240384 2402000F */   addiu    $v0, $zero, 0xf
/* A60D58 80240388 24040002 */  addiu     $a0, $zero, 2
/* A60D5C 8024038C 860300A8 */  lh        $v1, 0xa8($s0)
/* A60D60 80240390 AFA2001C */  sw        $v0, 0x1c($sp)
/* A60D64 80240394 27A20028 */  addiu     $v0, $sp, 0x28
/* A60D68 80240398 0200282D */  daddu     $a1, $s0, $zero
/* A60D6C 8024039C 3C013F80 */  lui       $at, 0x3f80
/* A60D70 802403A0 44810000 */  mtc1      $at, $f0
/* A60D74 802403A4 3C014000 */  lui       $at, 0x4000
/* A60D78 802403A8 44811000 */  mtc1      $at, $f2
/* A60D7C 802403AC 3C01C1A0 */  lui       $at, 0xc1a0
/* A60D80 802403B0 44812000 */  mtc1      $at, $f4
/* A60D84 802403B4 44833000 */  mtc1      $v1, $f6
/* A60D88 802403B8 00000000 */  nop
/* A60D8C 802403BC 468031A0 */  cvt.s.w   $f6, $f6
/* A60D90 802403C0 44073000 */  mfc1      $a3, $f6
/* A60D94 802403C4 0000302D */  daddu     $a2, $zero, $zero
/* A60D98 802403C8 AFA20020 */  sw        $v0, 0x20($sp)
/* A60D9C 802403CC E7A00010 */  swc1      $f0, 0x10($sp)
/* A60DA0 802403D0 E7A20014 */  swc1      $f2, 0x14($sp)
/* A60DA4 802403D4 0C01BFA4 */  jal       fx_emote
/* A60DA8 802403D8 E7A40018 */   swc1     $f4, 0x18($sp)
/* A60DAC 802403DC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A60DB0 802403E0 8C420000 */  lw        $v0, ($v0)
/* A60DB4 802403E4 08090103 */  j         .L8024040C
/* A60DB8 802403E8 AE020028 */   sw       $v0, 0x28($s0)
.L802403EC:
/* A60DBC 802403EC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A60DC0 802403F0 8C420024 */  lw        $v0, 0x24($v0)
/* A60DC4 802403F4 0C00FB3A */  jal       get_enemy
/* A60DC8 802403F8 AE020028 */   sw       $v0, 0x28($s0)
/* A60DCC 802403FC 86240008 */  lh        $a0, 8($s1)
/* A60DD0 80240400 24030001 */  addiu     $v1, $zero, 1
/* A60DD4 80240404 AC43006C */  sw        $v1, 0x6c($v0)
/* A60DD8 80240408 AC44007C */  sw        $a0, 0x7c($v0)
.L8024040C:
/* A60DDC 8024040C 96220076 */  lhu       $v0, 0x76($s1)
/* A60DE0 80240410 A602008E */  sh        $v0, 0x8e($s0)
/* A60DE4 80240414 24020021 */  addiu     $v0, $zero, 0x21
/* A60DE8 80240418 AE420070 */  sw        $v0, 0x70($s2)
.L8024041C:
/* A60DEC 8024041C 8FBF003C */  lw        $ra, 0x3c($sp)
/* A60DF0 80240420 8FB20038 */  lw        $s2, 0x38($sp)
/* A60DF4 80240424 8FB10034 */  lw        $s1, 0x34($sp)
/* A60DF8 80240428 8FB00030 */  lw        $s0, 0x30($sp)
/* A60DFC 8024042C 03E00008 */  jr        $ra
/* A60E00 80240430 27BD0040 */   addiu    $sp, $sp, 0x40
