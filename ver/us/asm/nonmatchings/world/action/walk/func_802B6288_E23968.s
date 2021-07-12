.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6288_E23968
/* E23968 802B6288 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E2396C 802B628C AFB30024 */  sw        $s3, 0x24($sp)
/* E23970 802B6290 AFB00018 */  sw        $s0, 0x18($sp)
/* E23974 802B6294 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E23978 802B6298 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E2397C 802B629C AFBF002C */  sw        $ra, 0x2c($sp)
/* E23980 802B62A0 AFB40028 */  sw        $s4, 0x28($sp)
/* E23984 802B62A4 AFB20020 */  sw        $s2, 0x20($sp)
/* E23988 802B62A8 AFB1001C */  sw        $s1, 0x1c($sp)
/* E2398C 802B62AC 8E050004 */  lw        $a1, 4($s0)
/* E23990 802B62B0 3C148011 */  lui       $s4, %hi(gPlayerData)
/* E23994 802B62B4 2694F290 */  addiu     $s4, $s4, %lo(gPlayerData)
/* E23998 802B62B8 30A21000 */  andi      $v0, $a1, 0x1000
/* E2399C 802B62BC 10400005 */  beqz      $v0, .L802B62D4
/* E239A0 802B62C0 0000982D */   daddu    $s3, $zero, $zero
/* E239A4 802B62C4 0C0AD9CE */  jal       func_802B6738_E23E18
/* E239A8 802B62C8 00000000 */   nop
/* E239AC 802B62CC 080AD94C */  j         .L802B6530
/* E239B0 802B62D0 00000000 */   nop
.L802B62D4:
/* E239B4 802B62D4 8E030000 */  lw        $v1, ($s0)
/* E239B8 802B62D8 04610019 */  bgez      $v1, .L802B6340
/* E239BC 802B62DC 3C027F77 */   lui      $v0, 0x7f77
/* E239C0 802B62E0 3442FFFF */  ori       $v0, $v0, 0xffff
/* E239C4 802B62E4 24130001 */  addiu     $s3, $zero, 1
/* E239C8 802B62E8 00621024 */  and       $v0, $v1, $v0
/* E239CC 802B62EC AE020000 */  sw        $v0, ($s0)
/* E239D0 802B62F0 30624000 */  andi      $v0, $v1, 0x4000
/* E239D4 802B62F4 3C018011 */  lui       $at, %hi(D_8010C980)
/* E239D8 802B62F8 AC20C980 */  sw        $zero, %lo(D_8010C980)($at)
/* E239DC 802B62FC 14400003 */  bnez      $v0, .L802B630C
/* E239E0 802B6300 AE000060 */   sw       $zero, 0x60($s0)
/* E239E4 802B6304 C600005C */  lwc1      $f0, 0x5c($s0)
/* E239E8 802B6308 E6000054 */  swc1      $f0, 0x54($s0)
.L802B630C:
/* E239EC 802B630C 30A24000 */  andi      $v0, $a1, 0x4000
/* E239F0 802B6310 10400003 */  beqz      $v0, .L802B6320
/* E239F4 802B6314 3C040009 */   lui      $a0, 9
/* E239F8 802B6318 080AD8CE */  j         .L802B6338
/* E239FC 802B631C 34840003 */   ori      $a0, $a0, 3
.L802B6320:
/* E23A00 802B6320 3C040006 */  lui       $a0, 6
/* E23A04 802B6324 30A20001 */  andi      $v0, $a1, 1
/* E23A08 802B6328 14400003 */  bnez      $v0, .L802B6338
/* E23A0C 802B632C 34840002 */   ori      $a0, $a0, 2
/* E23A10 802B6330 3C040001 */  lui       $a0, 1
/* E23A14 802B6334 34840005 */  ori       $a0, $a0, 5
.L802B6338:
/* E23A18 802B6338 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E23A1C 802B633C 00000000 */   nop
.L802B6340:
/* E23A20 802B6340 8E020000 */  lw        $v0, ($s0)
/* E23A24 802B6344 30424000 */  andi      $v0, $v0, 0x4000
/* E23A28 802B6348 10400006 */  beqz      $v0, .L802B6364
/* E23A2C 802B634C 24040004 */   addiu    $a0, $zero, 4
/* E23A30 802B6350 C60000A0 */  lwc1      $f0, 0xa0($s0)
/* E23A34 802B6354 0C039426 */  jal       try_player_footstep_sounds
/* E23A38 802B6358 E6000080 */   swc1     $f0, 0x80($s0)
/* E23A3C 802B635C 080AD94C */  j         .L802B6530
/* E23A40 802B6360 00000000 */   nop
.L802B6364:
/* E23A44 802B6364 3C038011 */  lui       $v1, %hi(D_8010C980)
/* E23A48 802B6368 2463C980 */  addiu     $v1, $v1, %lo(D_8010C980)
/* E23A4C 802B636C 8C620000 */  lw        $v0, ($v1)
/* E23A50 802B6370 3C013F80 */  lui       $at, 0x3f80
/* E23A54 802B6374 44811000 */  mtc1      $at, $f2
/* E23A58 802B6378 24420001 */  addiu     $v0, $v0, 1
/* E23A5C 802B637C AC620000 */  sw        $v0, ($v1)
/* E23A60 802B6380 8E020004 */  lw        $v0, 4($s0)
/* E23A64 802B6384 3C030001 */  lui       $v1, 1
/* E23A68 802B6388 00431024 */  and       $v0, $v0, $v1
/* E23A6C 802B638C 10400003 */  beqz      $v0, .L802B639C
/* E23A70 802B6390 00000000 */   nop
/* E23A74 802B6394 3C013FC0 */  lui       $at, 0x3fc0
/* E23A78 802B6398 44811000 */  mtc1      $at, $f2
.L802B639C:
/* E23A7C 802B639C C600005C */  lwc1      $f0, 0x5c($s0)
/* E23A80 802B63A0 46020002 */  mul.s     $f0, $f0, $f2
/* E23A84 802B63A4 00000000 */  nop
/* E23A88 802B63A8 27B20010 */  addiu     $s2, $sp, 0x10
/* E23A8C 802B63AC 0240202D */  daddu     $a0, $s2, $zero
/* E23A90 802B63B0 27B10014 */  addiu     $s1, $sp, 0x14
/* E23A94 802B63B4 0220282D */  daddu     $a1, $s1, $zero
/* E23A98 802B63B8 0C0388C1 */  jal       player_input_to_move_vector
/* E23A9C 802B63BC E6000054 */   swc1     $f0, 0x54($s0)
/* E23AA0 802B63C0 0C039454 */  jal       phys_update_interact_collider
/* E23AA4 802B63C4 00000000 */   nop
/* E23AA8 802B63C8 0C039858 */  jal       check_input_jump
/* E23AAC 802B63CC 00000000 */   nop
/* E23AB0 802B63D0 14400057 */  bnez      $v0, .L802B6530
/* E23AB4 802B63D4 00000000 */   nop
/* E23AB8 802B63D8 16600006 */  bnez      $s3, .L802B63F4
/* E23ABC 802B63DC 0240202D */   daddu    $a0, $s2, $zero
/* E23AC0 802B63E0 0C039838 */  jal       check_input_hammer
/* E23AC4 802B63E4 00000000 */   nop
/* E23AC8 802B63E8 14400051 */  bnez      $v0, .L802B6530
/* E23ACC 802B63EC 00000000 */   nop
/* E23AD0 802B63F0 0240202D */  daddu     $a0, $s2, $zero
.L802B63F4:
/* E23AD4 802B63F4 0C0388C1 */  jal       player_input_to_move_vector
/* E23AD8 802B63F8 0220282D */   daddu    $a1, $s1, $zero
/* E23ADC 802B63FC C7A20014 */  lwc1      $f2, 0x14($sp)
/* E23AE0 802B6400 44800000 */  mtc1      $zero, $f0
/* E23AE4 802B6404 00000000 */  nop
/* E23AE8 802B6408 46001032 */  c.eq.s    $f2, $f0
/* E23AEC 802B640C 00000000 */  nop
/* E23AF0 802B6410 45000005 */  bc1f      .L802B6428
/* E23AF4 802B6414 00000000 */   nop
/* E23AF8 802B6418 0C039769 */  jal       set_action_state
/* E23AFC 802B641C 0000202D */   daddu    $a0, $zero, $zero
/* E23B00 802B6420 080AD94C */  j         .L802B6530
/* E23B04 802B6424 00000000 */   nop
.L802B6428:
/* E23B08 802B6428 C7A40010 */  lwc1      $f4, 0x10($sp)
/* E23B0C 802B642C 3C01800F */  lui       $at, %hi(D_800F7B40)
/* E23B10 802B6430 C4207B40 */  lwc1      $f0, %lo(D_800F7B40)($at)
/* E23B14 802B6434 46800020 */  cvt.s.w   $f0, $f0
/* E23B18 802B6438 46040001 */  sub.s     $f0, $f0, $f4
/* E23B1C 802B643C 3C0142B4 */  lui       $at, 0x42b4
/* E23B20 802B6440 44811000 */  mtc1      $at, $f2
/* E23B24 802B6444 46000005 */  abs.s     $f0, $f0
/* E23B28 802B6448 4602003E */  c.le.s    $f0, $f2
/* E23B2C 802B644C 00000000 */  nop
/* E23B30 802B6450 45000009 */  bc1f      .L802B6478
/* E23B34 802B6454 00000000 */   nop
/* E23B38 802B6458 8E020004 */  lw        $v0, 4($s0)
/* E23B3C 802B645C 04430001 */  bgezl     $v0, .L802B6464
/* E23B40 802B6460 E6040080 */   swc1     $f4, 0x80($s0)
.L802B6464:
/* E23B44 802B6464 3C037FFF */  lui       $v1, 0x7fff
/* E23B48 802B6468 8E020004 */  lw        $v0, 4($s0)
/* E23B4C 802B646C 3463FFFF */  ori       $v1, $v1, 0xffff
/* E23B50 802B6470 080AD924 */  j         .L802B6490
/* E23B54 802B6474 00431024 */   and      $v0, $v0, $v1
.L802B6478:
/* E23B58 802B6478 8E020004 */  lw        $v0, 4($s0)
/* E23B5C 802B647C 04410003 */  bgez      $v0, .L802B648C
/* E23B60 802B6480 3C038000 */   lui      $v1, 0x8000
/* E23B64 802B6484 080AD925 */  j         .L802B6494
/* E23B68 802B6488 E6040080 */   swc1     $f4, 0x80($s0)
.L802B648C:
/* E23B6C 802B648C 00431025 */  or        $v0, $v0, $v1
.L802B6490:
/* E23B70 802B6490 AE020004 */  sw        $v0, 4($s0)
.L802B6494:
/* E23B74 802B6494 0C03A752 */  jal       is_ability_active
/* E23B78 802B6498 2404000B */   addiu    $a0, $zero, 0xb
/* E23B7C 802B649C 1440001B */  bnez      $v0, .L802B650C
/* E23B80 802B64A0 00000000 */   nop
/* E23B84 802B64A4 8E0200E8 */  lw        $v0, 0xe8($s0)
/* E23B88 802B64A8 00420018 */  mult      $v0, $v0
/* E23B8C 802B64AC 00001812 */  mflo      $v1
/* E23B90 802B64B0 8E0200EC */  lw        $v0, 0xec($s0)
/* E23B94 802B64B4 00000000 */  nop
/* E23B98 802B64B8 00420018 */  mult      $v0, $v0
/* E23B9C 802B64BC 00003812 */  mflo      $a3
/* E23BA0 802B64C0 00671021 */  addu      $v0, $v1, $a3
/* E23BA4 802B64C4 44826000 */  mtc1      $v0, $f12
/* E23BA8 802B64C8 00000000 */  nop
/* E23BAC 802B64CC 46806320 */  cvt.s.w   $f12, $f12
/* E23BB0 802B64D0 46006084 */  sqrt.s    $f2, $f12
/* E23BB4 802B64D4 46021032 */  c.eq.s    $f2, $f2
/* E23BB8 802B64D8 00000000 */  nop
/* E23BBC 802B64DC 45010004 */  bc1t      .L802B64F0
/* E23BC0 802B64E0 00000000 */   nop
/* E23BC4 802B64E4 0C0187BC */  jal       sqrtf
/* E23BC8 802B64E8 00000000 */   nop
/* E23BCC 802B64EC 46000086 */  mov.s     $f2, $f0
.L802B64F0:
/* E23BD0 802B64F0 3C01425C */  lui       $at, 0x425c
/* E23BD4 802B64F4 44810000 */  mtc1      $at, $f0
/* E23BD8 802B64F8 00000000 */  nop
/* E23BDC 802B64FC 4600103E */  c.le.s    $f2, $f0
/* E23BE0 802B6500 00000000 */  nop
/* E23BE4 802B6504 45000005 */  bc1f      .L802B651C
/* E23BE8 802B6508 00000000 */   nop
.L802B650C:
/* E23BEC 802B650C 0C039769 */  jal       set_action_state
/* E23BF0 802B6510 24040001 */   addiu    $a0, $zero, 1
/* E23BF4 802B6514 080AD94C */  j         .L802B6530
/* E23BF8 802B6518 00000000 */   nop
.L802B651C:
/* E23BFC 802B651C 0C039426 */  jal       try_player_footstep_sounds
/* E23C00 802B6520 24040004 */   addiu    $a0, $zero, 4
/* E23C04 802B6524 8E8202B0 */  lw        $v0, 0x2b0($s4)
/* E23C08 802B6528 24420001 */  addiu     $v0, $v0, 1
/* E23C0C 802B652C AE8202B0 */  sw        $v0, 0x2b0($s4)
.L802B6530:
/* E23C10 802B6530 8FBF002C */  lw        $ra, 0x2c($sp)
/* E23C14 802B6534 8FB40028 */  lw        $s4, 0x28($sp)
/* E23C18 802B6538 8FB30024 */  lw        $s3, 0x24($sp)
/* E23C1C 802B653C 8FB20020 */  lw        $s2, 0x20($sp)
/* E23C20 802B6540 8FB1001C */  lw        $s1, 0x1c($sp)
/* E23C24 802B6544 8FB00018 */  lw        $s0, 0x18($sp)
/* E23C28 802B6548 03E00008 */  jr        $ra
/* E23C2C 802B654C 27BD0030 */   addiu    $sp, $sp, 0x30
