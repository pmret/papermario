.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_A9F0A0
/* A9F0A0 80240360 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A9F0A4 80240364 AFB20038 */  sw        $s2, 0x38($sp)
/* A9F0A8 80240368 0080902D */  daddu     $s2, $a0, $zero
/* A9F0AC 8024036C AFB00030 */  sw        $s0, 0x30($sp)
/* A9F0B0 80240370 AFBF003C */  sw        $ra, 0x3c($sp)
/* A9F0B4 80240374 AFB10034 */  sw        $s1, 0x34($sp)
/* A9F0B8 80240378 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A9F0BC 8024037C F7B40040 */  sdc1      $f20, 0x40($sp)
/* A9F0C0 80240380 8E510148 */  lw        $s1, 0x148($s2)
/* A9F0C4 80240384 4485A000 */  mtc1      $a1, $f20
/* A9F0C8 80240388 86240008 */  lh        $a0, 8($s1)
/* A9F0CC 8024038C 4486B000 */  mtc1      $a2, $f22
/* A9F0D0 80240390 0C00EABB */  jal       get_npc_unsafe
/* A9F0D4 80240394 00E0802D */   daddu    $s0, $a3, $zero
/* A9F0D8 80240398 0200202D */  daddu     $a0, $s0, $zero
/* A9F0DC 8024039C 0220282D */  daddu     $a1, $s1, $zero
/* A9F0E0 802403A0 24030001 */  addiu     $v1, $zero, 1
/* A9F0E4 802403A4 4406A000 */  mfc1      $a2, $f20
/* A9F0E8 802403A8 4407B000 */  mfc1      $a3, $f22
/* A9F0EC 802403AC 0040802D */  daddu     $s0, $v0, $zero
/* A9F0F0 802403B0 0C01242D */  jal       func_800490B4
/* A9F0F4 802403B4 AFA30010 */   sw       $v1, 0x10($sp)
/* A9F0F8 802403B8 1440001D */  bnez      $v0, .L80240430
/* A9F0FC 802403BC 24040002 */   addiu    $a0, $zero, 2
/* A9F100 802403C0 0200282D */  daddu     $a1, $s0, $zero
/* A9F104 802403C4 0000302D */  daddu     $a2, $zero, $zero
/* A9F108 802403C8 860300A8 */  lh        $v1, 0xa8($s0)
/* A9F10C 802403CC 3C013F80 */  lui       $at, 0x3f80
/* A9F110 802403D0 44810000 */  mtc1      $at, $f0
/* A9F114 802403D4 3C014000 */  lui       $at, 0x4000
/* A9F118 802403D8 44811000 */  mtc1      $at, $f2
/* A9F11C 802403DC 3C01C1A0 */  lui       $at, 0xc1a0
/* A9F120 802403E0 44812000 */  mtc1      $at, $f4
/* A9F124 802403E4 2402000F */  addiu     $v0, $zero, 0xf
/* A9F128 802403E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* A9F12C 802403EC 44833000 */  mtc1      $v1, $f6
/* A9F130 802403F0 00000000 */  nop
/* A9F134 802403F4 468031A0 */  cvt.s.w   $f6, $f6
/* A9F138 802403F8 44073000 */  mfc1      $a3, $f6
/* A9F13C 802403FC 27A20028 */  addiu     $v0, $sp, 0x28
/* A9F140 80240400 AFA20020 */  sw        $v0, 0x20($sp)
/* A9F144 80240404 E7A00010 */  swc1      $f0, 0x10($sp)
/* A9F148 80240408 E7A20014 */  swc1      $f2, 0x14($sp)
/* A9F14C 8024040C 0C01BFA4 */  jal       fx_emote
/* A9F150 80240410 E7A40018 */   swc1     $f4, 0x18($sp)
/* A9F154 80240414 8E2200CC */  lw        $v0, 0xcc($s1)
/* A9F158 80240418 8C430000 */  lw        $v1, ($v0)
/* A9F15C 8024041C 24020014 */  addiu     $v0, $zero, 0x14
/* A9F160 80240420 A602008E */  sh        $v0, 0x8e($s0)
/* A9F164 80240424 24020021 */  addiu     $v0, $zero, 0x21
/* A9F168 80240428 08090120 */  j         .L80240480
/* A9F16C 8024042C AE030028 */   sw       $v1, 0x28($s0)
.L80240430:
/* A9F170 80240430 0C09005C */  jal       func_80240170_A9EEB0
/* A9F174 80240434 0240202D */   daddu    $a0, $s2, $zero
/* A9F178 80240438 0040202D */  daddu     $a0, $v0, $zero
/* A9F17C 8024043C 2402FFFF */  addiu     $v0, $zero, -1
/* A9F180 80240440 10820010 */  beq       $a0, $v0, .L80240484
/* A9F184 80240444 00000000 */   nop
/* A9F188 80240448 0C00FB3A */  jal       get_enemy
/* A9F18C 8024044C 00000000 */   nop
/* A9F190 80240450 8C42006C */  lw        $v0, 0x6c($v0)
/* A9F194 80240454 1440000B */  bnez      $v0, .L80240484
/* A9F198 80240458 00000000 */   nop
/* A9F19C 8024045C 8602008C */  lh        $v0, 0x8c($s0)
/* A9F1A0 80240460 14400008 */  bnez      $v0, .L80240484
/* A9F1A4 80240464 00000000 */   nop
/* A9F1A8 80240468 8E2200CC */  lw        $v0, 0xcc($s1)
/* A9F1AC 8024046C 8C420020 */  lw        $v0, 0x20($v0)
/* A9F1B0 80240470 AE020028 */  sw        $v0, 0x28($s0)
/* A9F1B4 80240474 96220072 */  lhu       $v0, 0x72($s1)
/* A9F1B8 80240478 A602008E */  sh        $v0, 0x8e($s0)
/* A9F1BC 8024047C 2402001E */  addiu     $v0, $zero, 0x1e
.L80240480:
/* A9F1C0 80240480 AE420070 */  sw        $v0, 0x70($s2)
.L80240484:
/* A9F1C4 80240484 8FBF003C */  lw        $ra, 0x3c($sp)
/* A9F1C8 80240488 8FB20038 */  lw        $s2, 0x38($sp)
/* A9F1CC 8024048C 8FB10034 */  lw        $s1, 0x34($sp)
/* A9F1D0 80240490 8FB00030 */  lw        $s0, 0x30($sp)
/* A9F1D4 80240494 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A9F1D8 80240498 D7B40040 */  ldc1      $f20, 0x40($sp)
/* A9F1DC 8024049C 03E00008 */  jr        $ra
/* A9F1E0 802404A0 27BD0050 */   addiu    $sp, $sp, 0x50
