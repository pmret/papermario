.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240500_A93C40
/* A93C40 80240500 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A93C44 80240504 AFB20038 */  sw        $s2, 0x38($sp)
/* A93C48 80240508 0080902D */  daddu     $s2, $a0, $zero
/* A93C4C 8024050C AFB00030 */  sw        $s0, 0x30($sp)
/* A93C50 80240510 AFBF003C */  sw        $ra, 0x3c($sp)
/* A93C54 80240514 AFB10034 */  sw        $s1, 0x34($sp)
/* A93C58 80240518 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A93C5C 8024051C F7B40040 */  sdc1      $f20, 0x40($sp)
/* A93C60 80240520 8E510148 */  lw        $s1, 0x148($s2)
/* A93C64 80240524 4485A000 */  mtc1      $a1, $f20
/* A93C68 80240528 86240008 */  lh        $a0, 8($s1)
/* A93C6C 8024052C 4486B000 */  mtc1      $a2, $f22
/* A93C70 80240530 0C00EABB */  jal       get_npc_unsafe
/* A93C74 80240534 00E0802D */   daddu    $s0, $a3, $zero
/* A93C78 80240538 0200202D */  daddu     $a0, $s0, $zero
/* A93C7C 8024053C 0220282D */  daddu     $a1, $s1, $zero
/* A93C80 80240540 24030001 */  addiu     $v1, $zero, 1
/* A93C84 80240544 4406A000 */  mfc1      $a2, $f20
/* A93C88 80240548 4407B000 */  mfc1      $a3, $f22
/* A93C8C 8024054C 0040802D */  daddu     $s0, $v0, $zero
/* A93C90 80240550 0C01242D */  jal       func_800490B4
/* A93C94 80240554 AFA30010 */   sw       $v1, 0x10($sp)
/* A93C98 80240558 1440001D */  bnez      $v0, .L802405D0
/* A93C9C 8024055C 24040002 */   addiu    $a0, $zero, 2
/* A93CA0 80240560 0200282D */  daddu     $a1, $s0, $zero
/* A93CA4 80240564 0000302D */  daddu     $a2, $zero, $zero
/* A93CA8 80240568 860300A8 */  lh        $v1, 0xa8($s0)
/* A93CAC 8024056C 3C013F80 */  lui       $at, 0x3f80
/* A93CB0 80240570 44810000 */  mtc1      $at, $f0
/* A93CB4 80240574 3C014000 */  lui       $at, 0x4000
/* A93CB8 80240578 44811000 */  mtc1      $at, $f2
/* A93CBC 8024057C 3C01C1A0 */  lui       $at, 0xc1a0
/* A93CC0 80240580 44812000 */  mtc1      $at, $f4
/* A93CC4 80240584 2402000F */  addiu     $v0, $zero, 0xf
/* A93CC8 80240588 AFA2001C */  sw        $v0, 0x1c($sp)
/* A93CCC 8024058C 44833000 */  mtc1      $v1, $f6
/* A93CD0 80240590 00000000 */  nop
/* A93CD4 80240594 468031A0 */  cvt.s.w   $f6, $f6
/* A93CD8 80240598 44073000 */  mfc1      $a3, $f6
/* A93CDC 8024059C 27A20028 */  addiu     $v0, $sp, 0x28
/* A93CE0 802405A0 AFA20020 */  sw        $v0, 0x20($sp)
/* A93CE4 802405A4 E7A00010 */  swc1      $f0, 0x10($sp)
/* A93CE8 802405A8 E7A20014 */  swc1      $f2, 0x14($sp)
/* A93CEC 802405AC 0C01BFA4 */  jal       fx_emote
/* A93CF0 802405B0 E7A40018 */   swc1     $f4, 0x18($sp)
/* A93CF4 802405B4 8E2200CC */  lw        $v0, 0xcc($s1)
/* A93CF8 802405B8 8C430000 */  lw        $v1, ($v0)
/* A93CFC 802405BC 24020014 */  addiu     $v0, $zero, 0x14
/* A93D00 802405C0 A602008E */  sh        $v0, 0x8e($s0)
/* A93D04 802405C4 24020021 */  addiu     $v0, $zero, 0x21
/* A93D08 802405C8 08090188 */  j         .L80240620
/* A93D0C 802405CC AE030028 */   sw       $v1, 0x28($s0)
.L802405D0:
/* A93D10 802405D0 0C0900C4 */  jal       func_80240310_A93A50
/* A93D14 802405D4 0240202D */   daddu    $a0, $s2, $zero
/* A93D18 802405D8 0040202D */  daddu     $a0, $v0, $zero
/* A93D1C 802405DC 2402FFFF */  addiu     $v0, $zero, -1
/* A93D20 802405E0 10820010 */  beq       $a0, $v0, .L80240624
/* A93D24 802405E4 00000000 */   nop
/* A93D28 802405E8 0C00FB3A */  jal       get_enemy
/* A93D2C 802405EC 00000000 */   nop
/* A93D30 802405F0 8C42006C */  lw        $v0, 0x6c($v0)
/* A93D34 802405F4 1440000B */  bnez      $v0, .L80240624
/* A93D38 802405F8 00000000 */   nop
/* A93D3C 802405FC 8602008C */  lh        $v0, 0x8c($s0)
/* A93D40 80240600 14400008 */  bnez      $v0, .L80240624
/* A93D44 80240604 00000000 */   nop
/* A93D48 80240608 8E2200CC */  lw        $v0, 0xcc($s1)
/* A93D4C 8024060C 8C420020 */  lw        $v0, 0x20($v0)
/* A93D50 80240610 AE020028 */  sw        $v0, 0x28($s0)
/* A93D54 80240614 96220072 */  lhu       $v0, 0x72($s1)
/* A93D58 80240618 A602008E */  sh        $v0, 0x8e($s0)
/* A93D5C 8024061C 2402001E */  addiu     $v0, $zero, 0x1e
.L80240620:
/* A93D60 80240620 AE420070 */  sw        $v0, 0x70($s2)
.L80240624:
/* A93D64 80240624 8FBF003C */  lw        $ra, 0x3c($sp)
/* A93D68 80240628 8FB20038 */  lw        $s2, 0x38($sp)
/* A93D6C 8024062C 8FB10034 */  lw        $s1, 0x34($sp)
/* A93D70 80240630 8FB00030 */  lw        $s0, 0x30($sp)
/* A93D74 80240634 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A93D78 80240638 D7B40040 */  ldc1      $f20, 0x40($sp)
/* A93D7C 8024063C 03E00008 */  jr        $ra
/* A93D80 80240640 27BD0050 */   addiu    $sp, $sp, 0x50
