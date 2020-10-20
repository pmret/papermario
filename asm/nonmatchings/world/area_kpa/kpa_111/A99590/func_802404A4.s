.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404A4
/* A99A34 802404A4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A99A38 802404A8 AFB20038 */  sw        $s2, 0x38($sp)
/* A99A3C 802404AC 0080902D */  daddu     $s2, $a0, $zero
/* A99A40 802404B0 AFBF003C */  sw        $ra, 0x3c($sp)
/* A99A44 802404B4 AFB10034 */  sw        $s1, 0x34($sp)
/* A99A48 802404B8 AFB00030 */  sw        $s0, 0x30($sp)
/* A99A4C 802404BC 8E510148 */  lw        $s1, 0x148($s2)
/* A99A50 802404C0 0C00EABB */  jal       get_npc_unsafe
/* A99A54 802404C4 86240008 */   lh       $a0, 8($s1)
/* A99A58 802404C8 0040802D */  daddu     $s0, $v0, $zero
/* A99A5C 802404CC 9602008E */  lhu       $v0, 0x8e($s0)
/* A99A60 802404D0 2442FFFF */  addiu     $v0, $v0, -1
/* A99A64 802404D4 A602008E */  sh        $v0, 0x8e($s0)
/* A99A68 802404D8 00021400 */  sll       $v0, $v0, 0x10
/* A99A6C 802404DC 1C40002B */  bgtz      $v0, .L8024058C
/* A99A70 802404E0 00000000 */   nop      
/* A99A74 802404E4 0C09005C */  jal       func_80240170
/* A99A78 802404E8 0240202D */   daddu    $a0, $s2, $zero
/* A99A7C 802404EC 0040202D */  daddu     $a0, $v0, $zero
/* A99A80 802404F0 0481001A */  bgez      $a0, .L8024055C
/* A99A84 802404F4 2402000F */   addiu    $v0, $zero, 0xf
/* A99A88 802404F8 24040002 */  addiu     $a0, $zero, 2
/* A99A8C 802404FC 860300A8 */  lh        $v1, 0xa8($s0)
/* A99A90 80240500 AFA2001C */  sw        $v0, 0x1c($sp)
/* A99A94 80240504 27A20028 */  addiu     $v0, $sp, 0x28
/* A99A98 80240508 0200282D */  daddu     $a1, $s0, $zero
/* A99A9C 8024050C 3C013F80 */  lui       $at, 0x3f80
/* A99AA0 80240510 44810000 */  mtc1      $at, $f0
/* A99AA4 80240514 3C014000 */  lui       $at, 0x4000
/* A99AA8 80240518 44811000 */  mtc1      $at, $f2
/* A99AAC 8024051C 3C01C1A0 */  lui       $at, 0xc1a0
/* A99AB0 80240520 44812000 */  mtc1      $at, $f4
/* A99AB4 80240524 44833000 */  mtc1      $v1, $f6
/* A99AB8 80240528 00000000 */  nop       
/* A99ABC 8024052C 468031A0 */  cvt.s.w   $f6, $f6
/* A99AC0 80240530 44073000 */  mfc1      $a3, $f6
/* A99AC4 80240534 0000302D */  daddu     $a2, $zero, $zero
/* A99AC8 80240538 AFA20020 */  sw        $v0, 0x20($sp)
/* A99ACC 8024053C E7A00010 */  swc1      $f0, 0x10($sp)
/* A99AD0 80240540 E7A20014 */  swc1      $f2, 0x14($sp)
/* A99AD4 80240544 0C01BFA4 */  jal       fx_emote
/* A99AD8 80240548 E7A40018 */   swc1     $f4, 0x18($sp)
/* A99ADC 8024054C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A99AE0 80240550 8C420000 */  lw        $v0, ($v0)
/* A99AE4 80240554 0809015F */  j         .L8024057C
/* A99AE8 80240558 AE020028 */   sw       $v0, 0x28($s0)
.L8024055C:
/* A99AEC 8024055C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A99AF0 80240560 8C420024 */  lw        $v0, 0x24($v0)
/* A99AF4 80240564 0C00FB3A */  jal       get_enemy
/* A99AF8 80240568 AE020028 */   sw       $v0, 0x28($s0)
/* A99AFC 8024056C 86240008 */  lh        $a0, 8($s1)
/* A99B00 80240570 24030001 */  addiu     $v1, $zero, 1
/* A99B04 80240574 AC43006C */  sw        $v1, 0x6c($v0)
/* A99B08 80240578 AC44007C */  sw        $a0, 0x7c($v0)
.L8024057C:
/* A99B0C 8024057C 96220076 */  lhu       $v0, 0x76($s1)
/* A99B10 80240580 A602008E */  sh        $v0, 0x8e($s0)
/* A99B14 80240584 24020021 */  addiu     $v0, $zero, 0x21
/* A99B18 80240588 AE420070 */  sw        $v0, 0x70($s2)
.L8024058C:
/* A99B1C 8024058C 8FBF003C */  lw        $ra, 0x3c($sp)
/* A99B20 80240590 8FB20038 */  lw        $s2, 0x38($sp)
/* A99B24 80240594 8FB10034 */  lw        $s1, 0x34($sp)
/* A99B28 80240598 8FB00030 */  lw        $s0, 0x30($sp)
/* A99B2C 8024059C 03E00008 */  jr        $ra
/* A99B30 802405A0 27BD0040 */   addiu    $sp, $sp, 0x40
