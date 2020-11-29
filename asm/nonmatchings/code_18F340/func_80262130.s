.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80262130
/* 190A10 80262130 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 190A14 80262134 AFB20038 */  sw        $s2, 0x38($sp)
/* 190A18 80262138 0000902D */  daddu     $s2, $zero, $zero
/* 190A1C 8026213C AFB00030 */  sw        $s0, 0x30($sp)
/* 190A20 80262140 0240802D */  daddu     $s0, $s2, $zero
/* 190A24 80262144 0240202D */  daddu     $a0, $s2, $zero
/* 190A28 80262148 27A2002C */  addiu     $v0, $sp, 0x2c
/* 190A2C 8026214C C7A20058 */  lwc1      $f2, 0x58($sp)
/* 190A30 80262150 27A50020 */  addiu     $a1, $sp, 0x20
/* 190A34 80262154 AFA60028 */  sw        $a2, 0x28($sp)
/* 190A38 80262158 27A60024 */  addiu     $a2, $sp, 0x24
/* 190A3C 8026215C F7B40040 */  sdc1      $f20, 0x40($sp)
/* 190A40 80262160 4487A000 */  mtc1      $a3, $f20
/* 190A44 80262164 3C0142B4 */  lui       $at, 0x42b4
/* 190A48 80262168 44810000 */  mtc1      $at, $f0
/* 190A4C 8026216C 27A70028 */  addiu     $a3, $sp, 0x28
/* 190A50 80262170 AFBF003C */  sw        $ra, 0x3c($sp)
/* 190A54 80262174 AFB10034 */  sw        $s1, 0x34($sp)
/* 190A58 80262178 E7AC0020 */  swc1      $f12, 0x20($sp)
/* 190A5C 8026217C E7AE0024 */  swc1      $f14, 0x24($sp)
/* 190A60 80262180 E7B4002C */  swc1      $f20, 0x2c($sp)
/* 190A64 80262184 AFA20010 */  sw        $v0, 0x10($sp)
/* 190A68 80262188 E7A00014 */  swc1      $f0, 0x14($sp)
/* 190A6C 8026218C 0C0371DE */  jal       func_800DC778
/* 190A70 80262190 E7A20018 */   swc1     $f2, 0x18($sp)
/* 190A74 80262194 10400013 */  beqz      $v0, .L802621E4
/* 190A78 80262198 24020001 */   addiu    $v0, $zero, 1
/* 190A7C 8026219C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 190A80 802621A0 4614003E */  c.le.s    $f0, $f20
/* 190A84 802621A4 00000000 */  nop       
/* 190A88 802621A8 4500000E */  bc1f      .L802621E4
/* 190A8C 802621AC 00000000 */   nop      
/* 190A90 802621B0 3C118011 */  lui       $s1, %hi(D_8010C98C)
/* 190A94 802621B4 2631C98C */  addiu     $s1, $s1, %lo(D_8010C98C)
/* 190A98 802621B8 0C016F6A */  jal       get_collider_type_by_id
/* 190A9C 802621BC 92240003 */   lbu      $a0, 3($s1)
/* 190AA0 802621C0 3C048011 */  lui       $a0, %hi(D_8010C96B)
/* 190AA4 802621C4 9084C96B */  lbu       $a0, %lo(D_8010C96B)($a0)
/* 190AA8 802621C8 0C016F6A */  jal       get_collider_type_by_id
/* 190AAC 802621CC 0040802D */   daddu    $s0, $v0, $zero
/* 190AB0 802621D0 92230003 */  lbu       $v1, 3($s1)
/* 190AB4 802621D4 02028024 */  and       $s0, $s0, $v0
/* 190AB8 802621D8 56030001 */  bnel      $s0, $v1, .L802621E0
/* 190ABC 802621DC 0240802D */   daddu    $s0, $s2, $zero
.L802621E0:
/* 190AC0 802621E0 24020001 */  addiu     $v0, $zero, 1
.L802621E4:
/* 190AC4 802621E4 52020001 */  beql      $s0, $v0, .L802621EC
/* 190AC8 802621E8 0040902D */   daddu    $s2, $v0, $zero
.L802621EC:
/* 190ACC 802621EC 0240102D */  daddu     $v0, $s2, $zero
/* 190AD0 802621F0 8FBF003C */  lw        $ra, 0x3c($sp)
/* 190AD4 802621F4 8FB20038 */  lw        $s2, 0x38($sp)
/* 190AD8 802621F8 8FB10034 */  lw        $s1, 0x34($sp)
/* 190ADC 802621FC 8FB00030 */  lw        $s0, 0x30($sp)
/* 190AE0 80262200 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 190AE4 80262204 03E00008 */  jr        $ra
/* 190AE8 80262208 27BD0048 */   addiu    $sp, $sp, 0x48
