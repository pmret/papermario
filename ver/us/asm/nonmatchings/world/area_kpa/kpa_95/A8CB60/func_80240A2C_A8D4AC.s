.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kpa_95_UnkFunc15
/* A8D4AC 80240A2C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A8D4B0 80240A30 AFB3003C */  sw        $s3, 0x3c($sp)
/* A8D4B4 80240A34 0080982D */  daddu     $s3, $a0, $zero
/* A8D4B8 80240A38 AFBF0040 */  sw        $ra, 0x40($sp)
/* A8D4BC 80240A3C AFB20038 */  sw        $s2, 0x38($sp)
/* A8D4C0 80240A40 AFB10034 */  sw        $s1, 0x34($sp)
/* A8D4C4 80240A44 AFB00030 */  sw        $s0, 0x30($sp)
/* A8D4C8 80240A48 8E720148 */  lw        $s2, 0x148($s3)
/* A8D4CC 80240A4C 00A0882D */  daddu     $s1, $a1, $zero
/* A8D4D0 80240A50 86440008 */  lh        $a0, 8($s2)
/* A8D4D4 80240A54 0C00EABB */  jal       get_npc_unsafe
/* A8D4D8 80240A58 00C0802D */   daddu    $s0, $a2, $zero
/* A8D4DC 80240A5C 0200202D */  daddu     $a0, $s0, $zero
/* A8D4E0 80240A60 0240282D */  daddu     $a1, $s2, $zero
/* A8D4E4 80240A64 24030001 */  addiu     $v1, $zero, 1
/* A8D4E8 80240A68 AFA30010 */  sw        $v1, 0x10($sp)
/* A8D4EC 80240A6C 8E260024 */  lw        $a2, 0x24($s1)
/* A8D4F0 80240A70 8E270028 */  lw        $a3, 0x28($s1)
/* A8D4F4 80240A74 0C01242D */  jal       func_800490B4
/* A8D4F8 80240A78 0040802D */   daddu    $s0, $v0, $zero
/* A8D4FC 80240A7C 1440001E */  bnez      $v0, .L80240AF8
/* A8D500 80240A80 0200202D */   daddu    $a0, $s0, $zero
/* A8D504 80240A84 24040002 */  addiu     $a0, $zero, 2
/* A8D508 80240A88 0200282D */  daddu     $a1, $s0, $zero
/* A8D50C 80240A8C 0000302D */  daddu     $a2, $zero, $zero
/* A8D510 80240A90 860300A8 */  lh        $v1, 0xa8($s0)
/* A8D514 80240A94 3C013F80 */  lui       $at, 0x3f80
/* A8D518 80240A98 44810000 */  mtc1      $at, $f0
/* A8D51C 80240A9C 3C014000 */  lui       $at, 0x4000
/* A8D520 80240AA0 44811000 */  mtc1      $at, $f2
/* A8D524 80240AA4 3C01C1A0 */  lui       $at, 0xc1a0
/* A8D528 80240AA8 44812000 */  mtc1      $at, $f4
/* A8D52C 80240AAC 2402000F */  addiu     $v0, $zero, 0xf
/* A8D530 80240AB0 AFA2001C */  sw        $v0, 0x1c($sp)
/* A8D534 80240AB4 44833000 */  mtc1      $v1, $f6
/* A8D538 80240AB8 00000000 */  nop
/* A8D53C 80240ABC 468031A0 */  cvt.s.w   $f6, $f6
/* A8D540 80240AC0 44073000 */  mfc1      $a3, $f6
/* A8D544 80240AC4 27A20028 */  addiu     $v0, $sp, 0x28
/* A8D548 80240AC8 AFA20020 */  sw        $v0, 0x20($sp)
/* A8D54C 80240ACC E7A00010 */  swc1      $f0, 0x10($sp)
/* A8D550 80240AD0 E7A20014 */  swc1      $f2, 0x14($sp)
/* A8D554 80240AD4 0C01BFA4 */  jal       fx_emote
/* A8D558 80240AD8 E7A40018 */   swc1     $f4, 0x18($sp)
/* A8D55C 80240ADC 8E4200CC */  lw        $v0, 0xcc($s2)
/* A8D560 80240AE0 8C430000 */  lw        $v1, ($v0)
/* A8D564 80240AE4 24020019 */  addiu     $v0, $zero, 0x19
/* A8D568 80240AE8 A602008E */  sh        $v0, 0x8e($s0)
/* A8D56C 80240AEC 2402000E */  addiu     $v0, $zero, 0xe
/* A8D570 80240AF0 080902CB */  j         .L80240B2C
/* A8D574 80240AF4 AE030028 */   sw       $v1, 0x28($s0)
.L80240AF8:
/* A8D578 80240AF8 0C00F598 */  jal       func_8003D660
/* A8D57C 80240AFC 24050001 */   addiu    $a1, $zero, 1
/* A8D580 80240B00 8E050018 */  lw        $a1, 0x18($s0)
/* A8D584 80240B04 8E06000C */  lw        $a2, 0xc($s0)
/* A8D588 80240B08 0C00EA95 */  jal       npc_move_heading
/* A8D58C 80240B0C 0200202D */   daddu    $a0, $s0, $zero
/* A8D590 80240B10 8602008E */  lh        $v0, 0x8e($s0)
/* A8D594 80240B14 9603008E */  lhu       $v1, 0x8e($s0)
/* A8D598 80240B18 18400003 */  blez      $v0, .L80240B28
/* A8D59C 80240B1C 2462FFFF */   addiu    $v0, $v1, -1
/* A8D5A0 80240B20 080902CC */  j         .L80240B30
/* A8D5A4 80240B24 A602008E */   sh       $v0, 0x8e($s0)
.L80240B28:
/* A8D5A8 80240B28 2402000C */  addiu     $v0, $zero, 0xc
.L80240B2C:
/* A8D5AC 80240B2C AE620070 */  sw        $v0, 0x70($s3)
.L80240B30:
/* A8D5B0 80240B30 8FBF0040 */  lw        $ra, 0x40($sp)
/* A8D5B4 80240B34 8FB3003C */  lw        $s3, 0x3c($sp)
/* A8D5B8 80240B38 8FB20038 */  lw        $s2, 0x38($sp)
/* A8D5BC 80240B3C 8FB10034 */  lw        $s1, 0x34($sp)
/* A8D5C0 80240B40 8FB00030 */  lw        $s0, 0x30($sp)
/* A8D5C4 80240B44 03E00008 */  jr        $ra
/* A8D5C8 80240B48 27BD0048 */   addiu    $sp, $sp, 0x48
