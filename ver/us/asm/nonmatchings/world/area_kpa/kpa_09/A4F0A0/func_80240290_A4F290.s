.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240290_A4F290
/* A4F290 80240290 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A4F294 80240294 AFB20038 */  sw        $s2, 0x38($sp)
/* A4F298 80240298 0080902D */  daddu     $s2, $a0, $zero
/* A4F29C 8024029C AFB00030 */  sw        $s0, 0x30($sp)
/* A4F2A0 802402A0 AFBF003C */  sw        $ra, 0x3c($sp)
/* A4F2A4 802402A4 AFB10034 */  sw        $s1, 0x34($sp)
/* A4F2A8 802402A8 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A4F2AC 802402AC F7B40040 */  sdc1      $f20, 0x40($sp)
/* A4F2B0 802402B0 8E510148 */  lw        $s1, 0x148($s2)
/* A4F2B4 802402B4 4485A000 */  mtc1      $a1, $f20
/* A4F2B8 802402B8 86240008 */  lh        $a0, 8($s1)
/* A4F2BC 802402BC 4486B000 */  mtc1      $a2, $f22
/* A4F2C0 802402C0 0C00EABB */  jal       get_npc_unsafe
/* A4F2C4 802402C4 00E0802D */   daddu    $s0, $a3, $zero
/* A4F2C8 802402C8 0200202D */  daddu     $a0, $s0, $zero
/* A4F2CC 802402CC 0220282D */  daddu     $a1, $s1, $zero
/* A4F2D0 802402D0 24030001 */  addiu     $v1, $zero, 1
/* A4F2D4 802402D4 4406A000 */  mfc1      $a2, $f20
/* A4F2D8 802402D8 4407B000 */  mfc1      $a3, $f22
/* A4F2DC 802402DC 0040802D */  daddu     $s0, $v0, $zero
/* A4F2E0 802402E0 0C01242D */  jal       func_800490B4
/* A4F2E4 802402E4 AFA30010 */   sw       $v1, 0x10($sp)
/* A4F2E8 802402E8 1440001D */  bnez      $v0, .L80240360
/* A4F2EC 802402EC 24040002 */   addiu    $a0, $zero, 2
/* A4F2F0 802402F0 0200282D */  daddu     $a1, $s0, $zero
/* A4F2F4 802402F4 0000302D */  daddu     $a2, $zero, $zero
/* A4F2F8 802402F8 860300A8 */  lh        $v1, 0xa8($s0)
/* A4F2FC 802402FC 3C013F80 */  lui       $at, 0x3f80
/* A4F300 80240300 44810000 */  mtc1      $at, $f0
/* A4F304 80240304 3C014000 */  lui       $at, 0x4000
/* A4F308 80240308 44811000 */  mtc1      $at, $f2
/* A4F30C 8024030C 3C01C1A0 */  lui       $at, 0xc1a0
/* A4F310 80240310 44812000 */  mtc1      $at, $f4
/* A4F314 80240314 2402000F */  addiu     $v0, $zero, 0xf
/* A4F318 80240318 AFA2001C */  sw        $v0, 0x1c($sp)
/* A4F31C 8024031C 44833000 */  mtc1      $v1, $f6
/* A4F320 80240320 00000000 */  nop
/* A4F324 80240324 468031A0 */  cvt.s.w   $f6, $f6
/* A4F328 80240328 44073000 */  mfc1      $a3, $f6
/* A4F32C 8024032C 27A20028 */  addiu     $v0, $sp, 0x28
/* A4F330 80240330 AFA20020 */  sw        $v0, 0x20($sp)
/* A4F334 80240334 E7A00010 */  swc1      $f0, 0x10($sp)
/* A4F338 80240338 E7A20014 */  swc1      $f2, 0x14($sp)
/* A4F33C 8024033C 0C01BFA4 */  jal       fx_emote
/* A4F340 80240340 E7A40018 */   swc1     $f4, 0x18($sp)
/* A4F344 80240344 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4F348 80240348 8C430000 */  lw        $v1, ($v0)
/* A4F34C 8024034C 24020014 */  addiu     $v0, $zero, 0x14
/* A4F350 80240350 A602008E */  sh        $v0, 0x8e($s0)
/* A4F354 80240354 24020021 */  addiu     $v0, $zero, 0x21
/* A4F358 80240358 080900EC */  j         .L802403B0
/* A4F35C 8024035C AE030028 */   sw       $v1, 0x28($s0)
.L80240360:
/* A4F360 80240360 0C090028 */  jal       func_802400A0_A4F0A0
/* A4F364 80240364 0240202D */   daddu    $a0, $s2, $zero
/* A4F368 80240368 0040202D */  daddu     $a0, $v0, $zero
/* A4F36C 8024036C 2402FFFF */  addiu     $v0, $zero, -1
/* A4F370 80240370 10820010 */  beq       $a0, $v0, .L802403B4
/* A4F374 80240374 00000000 */   nop
/* A4F378 80240378 0C00FB3A */  jal       get_enemy
/* A4F37C 8024037C 00000000 */   nop
/* A4F380 80240380 8C42006C */  lw        $v0, 0x6c($v0)
/* A4F384 80240384 1440000B */  bnez      $v0, .L802403B4
/* A4F388 80240388 00000000 */   nop
/* A4F38C 8024038C 8602008C */  lh        $v0, 0x8c($s0)
/* A4F390 80240390 14400008 */  bnez      $v0, .L802403B4
/* A4F394 80240394 00000000 */   nop
/* A4F398 80240398 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4F39C 8024039C 8C420020 */  lw        $v0, 0x20($v0)
/* A4F3A0 802403A0 AE020028 */  sw        $v0, 0x28($s0)
/* A4F3A4 802403A4 96220072 */  lhu       $v0, 0x72($s1)
/* A4F3A8 802403A8 A602008E */  sh        $v0, 0x8e($s0)
/* A4F3AC 802403AC 2402001E */  addiu     $v0, $zero, 0x1e
.L802403B0:
/* A4F3B0 802403B0 AE420070 */  sw        $v0, 0x70($s2)
.L802403B4:
/* A4F3B4 802403B4 8FBF003C */  lw        $ra, 0x3c($sp)
/* A4F3B8 802403B8 8FB20038 */  lw        $s2, 0x38($sp)
/* A4F3BC 802403BC 8FB10034 */  lw        $s1, 0x34($sp)
/* A4F3C0 802403C0 8FB00030 */  lw        $s0, 0x30($sp)
/* A4F3C4 802403C4 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A4F3C8 802403C8 D7B40040 */  ldc1      $f20, 0x40($sp)
/* A4F3CC 802403CC 03E00008 */  jr        $ra
/* A4F3D0 802403D0 27BD0050 */   addiu    $sp, $sp, 0x50
