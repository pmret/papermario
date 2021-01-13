.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E24920
/* E24920 802B6000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E24924 802B6004 AFB1001C */  sw        $s1, 0x1c($sp)
/* E24928 802B6008 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* E2492C 802B600C 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* E24930 802B6010 AFB00018 */  sw        $s0, 0x18($sp)
/* E24934 802B6014 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24938 802B6018 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E2493C 802B601C AFBF0024 */  sw        $ra, 0x24($sp)
/* E24940 802B6020 AFB20020 */  sw        $s2, 0x20($sp)
/* E24944 802B6024 8E050004 */  lw        $a1, 4($s0)
/* E24948 802B6028 3C12800B */  lui       $s2, %hi(gCameras)
/* E2494C 802B602C 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* E24950 802B6030 30A21000 */  andi      $v0, $a1, 0x1000
/* E24954 802B6034 10400005 */  beqz      $v0, .L802B604C
/* E24958 802B6038 00000000 */   nop
/* E2495C 802B603C 0C0AD8B3 */  jal       func_802B62CC_E24BEC
/* E24960 802B6040 00000000 */   nop
/* E24964 802B6044 080AD86A */  j         .L802B61A8
/* E24968 802B6048 00000000 */   nop
.L802B604C:
/* E2496C 802B604C 8E030000 */  lw        $v1, ($s0)
/* E24970 802B6050 0461002E */  bgez      $v1, .L802B610C
/* E24974 802B6054 3C027F77 */   lui      $v0, 0x7f77
/* E24978 802B6058 3442FFF1 */  ori       $v0, $v0, 0xfff1
/* E2497C 802B605C C6000028 */  lwc1      $f0, 0x28($s0)
/* E24980 802B6060 C6020030 */  lwc1      $f2, 0x30($s0)
/* E24984 802B6064 00621024 */  and       $v0, $v1, $v0
/* E24988 802B6068 AE020000 */  sw        $v0, ($s0)
/* E2498C 802B606C 30A24000 */  andi      $v0, $a1, 0x4000
/* E24990 802B6070 A20000B6 */  sb        $zero, 0xb6($s0)
/* E24994 802B6074 A60000C0 */  sh        $zero, 0xc0($s0)
/* E24998 802B6078 A60000C2 */  sh        $zero, 0xc2($s0)
/* E2499C 802B607C E6000044 */  swc1      $f0, 0x44($s0)
/* E249A0 802B6080 10400004 */  beqz      $v0, .L802B6094
/* E249A4 802B6084 E6020048 */   swc1     $f2, 0x48($s0)
/* E249A8 802B6088 3C040009 */  lui       $a0, 9
/* E249AC 802B608C 080AD82B */  j         .L802B60AC
/* E249B0 802B6090 34840002 */   ori      $a0, $a0, 2
.L802B6094:
/* E249B4 802B6094 3C040006 */  lui       $a0, 6
/* E249B8 802B6098 30A20001 */  andi      $v0, $a1, 1
/* E249BC 802B609C 14400003 */  bnez      $v0, .L802B60AC
/* E249C0 802B60A0 3484000B */   ori      $a0, $a0, 0xb
/* E249C4 802B60A4 3C040001 */  lui       $a0, 1
/* E249C8 802B60A8 34840009 */  ori       $a0, $a0, 9
.L802B60AC:
/* E249CC 802B60AC 0C037FBF */  jal       func_800DFEFC
/* E249D0 802B60B0 00000000 */   nop
/* E249D4 802B60B4 34048161 */  ori       $a0, $zero, 0x8161
/* E249D8 802B60B8 0C052736 */  jal       play_sound_at_player
/* E249DC 802B60BC 0000282D */   daddu    $a1, $zero, $zero
/* E249E0 802B60C0 24040148 */  addiu     $a0, $zero, 0x148
/* E249E4 802B60C4 0C052736 */  jal       play_sound_at_player
/* E249E8 802B60C8 0000282D */   daddu    $a1, $zero, $zero
/* E249EC 802B60CC 96220002 */  lhu       $v0, 2($s1)
/* E249F0 802B60D0 30424000 */  andi      $v0, $v0, 0x4000
/* E249F4 802B60D4 14400004 */  bnez      $v0, .L802B60E8
/* E249F8 802B60D8 3C04FFFB */   lui      $a0, 0xfffb
/* E249FC 802B60DC 0C03954C */  jal       func_800E5530
/* E24A00 802B60E0 00000000 */   nop
/* E24A04 802B60E4 3C04FFFB */  lui       $a0, 0xfffb
.L802B60E8:
/* E24A08 802B60E8 3484FFFF */  ori       $a0, $a0, 0xffff
/* E24A0C 802B60EC 2402FFFF */  addiu     $v0, $zero, -1
/* E24A10 802B60F0 A6220004 */  sh        $v0, 4($s1)
/* E24A14 802B60F4 8E020004 */  lw        $v0, 4($s0)
/* E24A18 802B60F8 96430002 */  lhu       $v1, 2($s2)
/* E24A1C 802B60FC 00441024 */  and       $v0, $v0, $a0
/* E24A20 802B6100 3063FFFB */  andi      $v1, $v1, 0xfffb
/* E24A24 802B6104 AE020004 */  sw        $v0, 4($s0)
/* E24A28 802B6108 A6430002 */  sh        $v1, 2($s2)
.L802B610C:
/* E24A2C 802B610C C6000054 */  lwc1      $f0, 0x54($s0)
/* E24A30 802B6110 3C013F19 */  lui       $at, 0x3f19
/* E24A34 802B6114 3421999A */  ori       $at, $at, 0x999a
/* E24A38 802B6118 44811000 */  mtc1      $at, $f2
/* E24A3C 802B611C 27A40010 */  addiu     $a0, $sp, 0x10
/* E24A40 802B6120 46020002 */  mul.s     $f0, $f0, $f2
/* E24A44 802B6124 00000000 */  nop
/* E24A48 802B6128 920200B6 */  lbu       $v0, 0xb6($s0)
/* E24A4C 802B612C 27A50014 */  addiu     $a1, $sp, 0x14
/* E24A50 802B6130 24420001 */  addiu     $v0, $v0, 1
/* E24A54 802B6134 A20200B6 */  sb        $v0, 0xb6($s0)
/* E24A58 802B6138 0C0388C1 */  jal       input_to_move_vector
/* E24A5C 802B613C E6000054 */   swc1     $f0, 0x54($s0)
/* E24A60 802B6140 0C039858 */  jal       check_input_jump
/* E24A64 802B6144 00000000 */   nop
/* E24A68 802B6148 0040182D */  daddu     $v1, $v0, $zero
/* E24A6C 802B614C 14600005 */  bnez      $v1, .L802B6164
/* E24A70 802B6150 00000000 */   nop
/* E24A74 802B6154 820200B6 */  lb        $v0, 0xb6($s0)
/* E24A78 802B6158 0062102A */  slt       $v0, $v1, $v0
/* E24A7C 802B615C 10400012 */  beqz      $v0, .L802B61A8
/* E24A80 802B6160 00000000 */   nop
.L802B6164:
/* E24A84 802B6164 C7A00014 */  lwc1      $f0, 0x14($sp)
/* E24A88 802B6168 44801000 */  mtc1      $zero, $f2
/* E24A8C 802B616C 00000000 */  nop
/* E24A90 802B6170 46020032 */  c.eq.s    $f0, $f2
/* E24A94 802B6174 00000000 */  nop
/* E24A98 802B6178 45000005 */  bc1f      .L802B6190
/* E24A9C 802B617C 00000000 */   nop
/* E24AA0 802B6180 0C039769 */  jal       set_action_state
/* E24AA4 802B6184 0000202D */   daddu    $a0, $zero, $zero
/* E24AA8 802B6188 080AD86A */  j         .L802B61A8
/* E24AAC 802B618C 00000000 */   nop
.L802B6190:
/* E24AB0 802B6190 45010003 */  bc1t      .L802B61A0
/* E24AB4 802B6194 00000000 */   nop
/* E24AB8 802B6198 C7A00010 */  lwc1      $f0, 0x10($sp)
/* E24ABC 802B619C E6000080 */  swc1      $f0, 0x80($s0)
.L802B61A0:
/* E24AC0 802B61A0 0C0397DA */  jal       update_locomotion_state
/* E24AC4 802B61A4 00000000 */   nop
.L802B61A8:
/* E24AC8 802B61A8 8FBF0024 */  lw        $ra, 0x24($sp)
/* E24ACC 802B61AC 8FB20020 */  lw        $s2, 0x20($sp)
/* E24AD0 802B61B0 8FB1001C */  lw        $s1, 0x1c($sp)
/* E24AD4 802B61B4 8FB00018 */  lw        $s0, 0x18($sp)
/* E24AD8 802B61B8 03E00008 */  jr        $ra
/* E24ADC 802B61BC 27BD0028 */   addiu    $sp, $sp, 0x28
