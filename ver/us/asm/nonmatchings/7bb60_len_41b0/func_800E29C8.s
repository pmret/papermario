.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E29C8
/* 7BE78 800E29C8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 7BE7C 800E29CC AFB00018 */  sw        $s0, 0x18($sp)
/* 7BE80 800E29D0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 7BE84 800E29D4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 7BE88 800E29D8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 7BE8C 800E29DC AFB30024 */  sw        $s3, 0x24($sp)
/* 7BE90 800E29E0 AFB20020 */  sw        $s2, 0x20($sp)
/* 7BE94 800E29E4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7BE98 800E29E8 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 7BE9C 800E29EC 8E030000 */  lw        $v1, ($s0)
/* 7BEA0 800E29F0 04610006 */  bgez      $v1, .L800E2A0C
/* 7BEA4 800E29F4 0200982D */   daddu    $s3, $s0, $zero
/* 7BEA8 800E29F8 3C027FFF */  lui       $v0, 0x7fff
/* 7BEAC 800E29FC 3442FFFF */  ori       $v0, $v0, 0xffff
/* 7BEB0 800E2A00 00621024 */  and       $v0, $v1, $v0
/* 7BEB4 800E2A04 AE020000 */  sw        $v0, ($s0)
/* 7BEB8 800E2A08 A20000B6 */  sb        $zero, 0xb6($s0)
.L800E2A0C:
/* 7BEBC 800E2A0C 820300B6 */  lb        $v1, 0xb6($s0)
/* 7BEC0 800E2A10 14600031 */  bnez      $v1, .L800E2AD8
/* 7BEC4 800E2A14 24020002 */   addiu    $v0, $zero, 2
/* 7BEC8 800E2A18 3C018011 */  lui       $at, %hi(D_8010C960)
/* 7BECC 800E2A1C C42CC960 */  lwc1      $f12, %lo(D_8010C960)($at)
/* 7BED0 800E2A20 3C018011 */  lui       $at, %hi(D_8010C97C)
/* 7BED4 800E2A24 C42EC97C */  lwc1      $f14, %lo(D_8010C97C)($at)
/* 7BED8 800E2A28 8E060028 */  lw        $a2, 0x28($s0)
/* 7BEDC 800E2A2C 8E070030 */  lw        $a3, 0x30($s0)
/* 7BEE0 800E2A30 0C00A7B5 */  jal       dist2D
/* 7BEE4 800E2A34 26110028 */   addiu    $s1, $s0, 0x28
/* 7BEE8 800E2A38 3C0141B0 */  lui       $at, 0x41b0
/* 7BEEC 800E2A3C 44811000 */  mtc1      $at, $f2
/* 7BEF0 800E2A40 00000000 */  nop
/* 7BEF4 800E2A44 4602003E */  c.le.s    $f0, $f2
/* 7BEF8 800E2A48 00000000 */  nop
/* 7BEFC 800E2A4C 45000006 */  bc1f      .L800E2A68
/* 7BF00 800E2A50 26120030 */   addiu    $s2, $s0, 0x30
/* 7BF04 800E2A54 0220202D */  daddu     $a0, $s1, $zero
/* 7BF08 800E2A58 3C0640A0 */  lui       $a2, 0x40a0
/* 7BF0C 800E2A5C 8E070080 */  lw        $a3, 0x80($s0)
/* 7BF10 800E2A60 0C00A7E7 */  jal       add_vec2D_polar
/* 7BF14 800E2A64 0240282D */   daddu    $a1, $s2, $zero
.L800E2A68:
/* 7BF18 800E2A68 0C038D12 */  jal       integrate_gravity
/* 7BF1C 800E2A6C 00000000 */   nop
/* 7BF20 800E2A70 C6020070 */  lwc1      $f2, 0x70($s0)
/* 7BF24 800E2A74 44800000 */  mtc1      $zero, $f0
/* 7BF28 800E2A78 00000000 */  nop
/* 7BF2C 800E2A7C 4600103E */  c.le.s    $f2, $f0
/* 7BF30 800E2A80 00000000 */  nop
/* 7BF34 800E2A84 45000009 */  bc1f      .L800E2AAC
/* 7BF38 800E2A88 00000000 */   nop
/* 7BF3C 800E2A8C 0C0389AC */  jal       record_jump_apex
/* 7BF40 800E2A90 00000000 */   nop
/* 7BF44 800E2A94 0C038C1B */  jal       gravity_use_fall_parms
/* 7BF48 800E2A98 00000000 */   nop
/* 7BF4C 800E2A9C 0C038D12 */  jal       integrate_gravity
/* 7BF50 800E2AA0 00000000 */   nop
/* 7BF54 800E2AA4 24020001 */  addiu     $v0, $zero, 1
/* 7BF58 800E2AA8 A20200B6 */  sb        $v0, 0xb6($s0)
.L800E2AAC:
/* 7BF5C 800E2AAC C6000070 */  lwc1      $f0, 0x70($s0)
/* 7BF60 800E2AB0 C602006C */  lwc1      $f2, 0x6c($s0)
/* 7BF64 800E2AB4 4600103C */  c.lt.s    $f2, $f0
/* 7BF68 800E2AB8 00000000 */  nop
/* 7BF6C 800E2ABC 45030001 */  bc1tl     .L800E2AC4
/* 7BF70 800E2AC0 E6020070 */   swc1     $f2, 0x70($s0)
.L800E2AC4:
/* 7BF74 800E2AC4 C600002C */  lwc1      $f0, 0x2c($s0)
/* 7BF78 800E2AC8 C6020070 */  lwc1      $f2, 0x70($s0)
/* 7BF7C 800E2ACC 46020000 */  add.s     $f0, $f0, $f2
/* 7BF80 800E2AD0 08038AE4 */  j         .L800E2B90
/* 7BF84 800E2AD4 E600002C */   swc1     $f0, 0x2c($s0)
.L800E2AD8:
/* 7BF88 800E2AD8 1462002D */  bne       $v1, $v0, .L800E2B90
/* 7BF8C 800E2ADC 00000000 */   nop
/* 7BF90 800E2AE0 3C018011 */  lui       $at, %hi(D_8010C960)
/* 7BF94 800E2AE4 C42CC960 */  lwc1      $f12, %lo(D_8010C960)($at)
/* 7BF98 800E2AE8 3C018011 */  lui       $at, %hi(D_8010C97C)
/* 7BF9C 800E2AEC C42EC97C */  lwc1      $f14, %lo(D_8010C97C)($at)
/* 7BFA0 800E2AF0 8E060028 */  lw        $a2, 0x28($s0)
/* 7BFA4 800E2AF4 8E070030 */  lw        $a3, 0x30($s0)
/* 7BFA8 800E2AF8 0C00A7B5 */  jal       dist2D
/* 7BFAC 800E2AFC 26110028 */   addiu    $s1, $s0, 0x28
/* 7BFB0 800E2B00 3C0141B0 */  lui       $at, 0x41b0
/* 7BFB4 800E2B04 44811000 */  mtc1      $at, $f2
/* 7BFB8 800E2B08 00000000 */  nop
/* 7BFBC 800E2B0C 4602003E */  c.le.s    $f0, $f2
/* 7BFC0 800E2B10 00000000 */  nop
/* 7BFC4 800E2B14 45000006 */  bc1f      .L800E2B30
/* 7BFC8 800E2B18 26120030 */   addiu    $s2, $s0, 0x30
/* 7BFCC 800E2B1C 0220202D */  daddu     $a0, $s1, $zero
/* 7BFD0 800E2B20 3C0640A0 */  lui       $a2, 0x40a0
/* 7BFD4 800E2B24 8E070080 */  lw        $a3, 0x80($s0)
/* 7BFD8 800E2B28 0C00A7E7 */  jal       add_vec2D_polar
/* 7BFDC 800E2B2C 0240282D */   daddu    $a1, $s2, $zero
.L800E2B30:
/* 7BFE0 800E2B30 0C038D36 */  jal       func_800E34D8
/* 7BFE4 800E2B34 00000000 */   nop
/* 7BFE8 800E2B38 46000306 */  mov.s     $f12, $f0
/* 7BFEC 800E2B3C 0C038D45 */  jal       player_check_collision_below
/* 7BFF0 800E2B40 27A50010 */   addiu    $a1, $sp, 0x10
/* 7BFF4 800E2B44 8FA40010 */  lw        $a0, 0x10($sp)
/* 7BFF8 800E2B48 0C038C57 */  jal       func_800E315C
/* 7BFFC 800E2B4C 46000506 */   mov.s    $f20, $f0
/* 7C000 800E2B50 8FA20010 */  lw        $v0, 0x10($sp)
/* 7C004 800E2B54 0440000E */  bltz      $v0, .L800E2B90
/* 7C008 800E2B58 E674002C */   swc1     $f20, 0x2c($s3)
/* 7C00C 800E2B5C 3C040006 */  lui       $a0, 6
/* 7C010 800E2B60 8E620004 */  lw        $v0, 4($s3)
/* 7C014 800E2B64 30420001 */  andi      $v0, $v0, 1
/* 7C018 800E2B68 14400003 */  bnez      $v0, .L800E2B78
/* 7C01C 800E2B6C 3484000B */   ori      $a0, $a0, 0xb
/* 7C020 800E2B70 3C040001 */  lui       $a0, 1
/* 7C024 800E2B74 34840009 */  ori       $a0, $a0, 9
.L800E2B78:
/* 7C028 800E2B78 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* 7C02C 800E2B7C 00000000 */   nop
/* 7C030 800E2B80 0C038069 */  jal       enable_player_input
/* 7C034 800E2B84 00000000 */   nop
/* 7C038 800E2B88 0C038C9E */  jal       phys_player_land
/* 7C03C 800E2B8C 00000000 */   nop
.L800E2B90:
/* 7C040 800E2B90 8FBF0028 */  lw        $ra, 0x28($sp)
/* 7C044 800E2B94 8FB30024 */  lw        $s3, 0x24($sp)
/* 7C048 800E2B98 8FB20020 */  lw        $s2, 0x20($sp)
/* 7C04C 800E2B9C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7C050 800E2BA0 8FB00018 */  lw        $s0, 0x18($sp)
/* 7C054 800E2BA4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 7C058 800E2BA8 03E00008 */  jr        $ra
/* 7C05C 800E2BAC 27BD0038 */   addiu    $sp, $sp, 0x38
