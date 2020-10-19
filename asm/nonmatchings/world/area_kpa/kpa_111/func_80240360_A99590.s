.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_A998F0
/* A998F0 80240360 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A998F4 80240364 AFB20038 */  sw        $s2, 0x38($sp)
/* A998F8 80240368 0080902D */  daddu     $s2, $a0, $zero
/* A998FC 8024036C AFB00030 */  sw        $s0, 0x30($sp)
/* A99900 80240370 AFBF003C */  sw        $ra, 0x3c($sp)
/* A99904 80240374 AFB10034 */  sw        $s1, 0x34($sp)
/* A99908 80240378 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A9990C 8024037C F7B40040 */  sdc1      $f20, 0x40($sp)
/* A99910 80240380 8E510148 */  lw        $s1, 0x148($s2)
/* A99914 80240384 4485A000 */  mtc1      $a1, $f20
/* A99918 80240388 86240008 */  lh        $a0, 8($s1)
/* A9991C 8024038C 4486B000 */  mtc1      $a2, $f22
/* A99920 80240390 0C00EABB */  jal       get_npc_unsafe
/* A99924 80240394 00E0802D */   daddu    $s0, $a3, $zero
/* A99928 80240398 0200202D */  daddu     $a0, $s0, $zero
/* A9992C 8024039C 0220282D */  daddu     $a1, $s1, $zero
/* A99930 802403A0 24030001 */  addiu     $v1, $zero, 1
/* A99934 802403A4 4406A000 */  mfc1      $a2, $f20
/* A99938 802403A8 4407B000 */  mfc1      $a3, $f22
/* A9993C 802403AC 0040802D */  daddu     $s0, $v0, $zero
/* A99940 802403B0 0C01242D */  jal       func_800490B4
/* A99944 802403B4 AFA30010 */   sw       $v1, 0x10($sp)
/* A99948 802403B8 1440001D */  bnez      $v0, .L80240430
/* A9994C 802403BC 24040002 */   addiu    $a0, $zero, 2
/* A99950 802403C0 0200282D */  daddu     $a1, $s0, $zero
/* A99954 802403C4 0000302D */  daddu     $a2, $zero, $zero
/* A99958 802403C8 860300A8 */  lh        $v1, 0xa8($s0)
/* A9995C 802403CC 3C013F80 */  lui       $at, 0x3f80
/* A99960 802403D0 44810000 */  mtc1      $at, $f0
/* A99964 802403D4 3C014000 */  lui       $at, 0x4000
/* A99968 802403D8 44811000 */  mtc1      $at, $f2
/* A9996C 802403DC 3C01C1A0 */  lui       $at, 0xc1a0
/* A99970 802403E0 44812000 */  mtc1      $at, $f4
/* A99974 802403E4 2402000F */  addiu     $v0, $zero, 0xf
/* A99978 802403E8 AFA2001C */  sw        $v0, 0x1c($sp)
/* A9997C 802403EC 44833000 */  mtc1      $v1, $f6
/* A99980 802403F0 00000000 */  nop       
/* A99984 802403F4 468031A0 */  cvt.s.w   $f6, $f6
/* A99988 802403F8 44073000 */  mfc1      $a3, $f6
/* A9998C 802403FC 27A20028 */  addiu     $v0, $sp, 0x28
/* A99990 80240400 AFA20020 */  sw        $v0, 0x20($sp)
/* A99994 80240404 E7A00010 */  swc1      $f0, 0x10($sp)
/* A99998 80240408 E7A20014 */  swc1      $f2, 0x14($sp)
/* A9999C 8024040C 0C01BFA4 */  jal       fx_emote
/* A999A0 80240410 E7A40018 */   swc1     $f4, 0x18($sp)
/* A999A4 80240414 8E2200CC */  lw        $v0, 0xcc($s1)
/* A999A8 80240418 8C430000 */  lw        $v1, ($v0)
/* A999AC 8024041C 24020014 */  addiu     $v0, $zero, 0x14
/* A999B0 80240420 A602008E */  sh        $v0, 0x8e($s0)
/* A999B4 80240424 24020021 */  addiu     $v0, $zero, 0x21
/* A999B8 80240428 08090120 */  j         .L80240480
/* A999BC 8024042C AE030028 */   sw       $v1, 0x28($s0)
.L80240430:
/* A999C0 80240430 0C09005C */  jal       func_80240170
/* A999C4 80240434 0240202D */   daddu    $a0, $s2, $zero
/* A999C8 80240438 0040202D */  daddu     $a0, $v0, $zero
/* A999CC 8024043C 2402FFFF */  addiu     $v0, $zero, -1
/* A999D0 80240440 10820010 */  beq       $a0, $v0, .L80240484
/* A999D4 80240444 00000000 */   nop      
/* A999D8 80240448 0C00FB3A */  jal       get_enemy
/* A999DC 8024044C 00000000 */   nop      
/* A999E0 80240450 8C42006C */  lw        $v0, 0x6c($v0)
/* A999E4 80240454 1440000B */  bnez      $v0, .L80240484
/* A999E8 80240458 00000000 */   nop      
/* A999EC 8024045C 8602008C */  lh        $v0, 0x8c($s0)
/* A999F0 80240460 14400008 */  bnez      $v0, .L80240484
/* A999F4 80240464 00000000 */   nop      
/* A999F8 80240468 8E2200CC */  lw        $v0, 0xcc($s1)
/* A999FC 8024046C 8C420020 */  lw        $v0, 0x20($v0)
/* A99A00 80240470 AE020028 */  sw        $v0, 0x28($s0)
/* A99A04 80240474 96220072 */  lhu       $v0, 0x72($s1)
/* A99A08 80240478 A602008E */  sh        $v0, 0x8e($s0)
/* A99A0C 8024047C 2402001E */  addiu     $v0, $zero, 0x1e
.L80240480:
/* A99A10 80240480 AE420070 */  sw        $v0, 0x70($s2)
.L80240484:
/* A99A14 80240484 8FBF003C */  lw        $ra, 0x3c($sp)
/* A99A18 80240488 8FB20038 */  lw        $s2, 0x38($sp)
/* A99A1C 8024048C 8FB10034 */  lw        $s1, 0x34($sp)
/* A99A20 80240490 8FB00030 */  lw        $s0, 0x30($sp)
/* A99A24 80240494 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A99A28 80240498 D7B40040 */  ldc1      $f20, 0x40($sp)
/* A99A2C 8024049C 03E00008 */  jr        $ra
/* A99A30 802404A0 27BD0050 */   addiu    $sp, $sp, 0x50
