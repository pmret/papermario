.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218960_6BC4F0
/* 6BC4F0 80218960 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 6BC4F4 80218964 AFB20020 */  sw        $s2, 0x20($sp)
/* 6BC4F8 80218968 0080902D */  daddu     $s2, $a0, $zero
/* 6BC4FC 8021896C AFBF0028 */  sw        $ra, 0x28($sp)
/* 6BC500 80218970 AFB30024 */  sw        $s3, 0x24($sp)
/* 6BC504 80218974 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6BC508 80218978 AFB00018 */  sw        $s0, 0x18($sp)
/* 6BC50C 8021897C F7B40030 */  sdc1      $f20, 0x30($sp)
/* 6BC510 80218980 8E440148 */  lw        $a0, 0x148($s2)
/* 6BC514 80218984 0C09A75B */  jal       get_actor
/* 6BC518 80218988 00A0802D */   daddu    $s0, $a1, $zero
/* 6BC51C 8021898C 0040882D */  daddu     $s1, $v0, $zero
/* 6BC520 80218990 12000002 */  beqz      $s0, .L8021899C
/* 6BC524 80218994 2633000C */   addiu    $s3, $s1, 0xc
/* 6BC528 80218998 AE400070 */  sw        $zero, 0x70($s2)
.L8021899C:
/* 6BC52C 8021899C 8E420070 */  lw        $v0, 0x70($s2)
/* 6BC530 802189A0 14400008 */  bnez      $v0, .L802189C4
/* 6BC534 802189A4 24020001 */   addiu    $v0, $zero, 1
/* 6BC538 802189A8 C6200144 */  lwc1      $f0, 0x144($s1)
/* 6BC53C 802189AC C6220148 */  lwc1      $f2, 0x148($s1)
/* 6BC540 802189B0 C624014C */  lwc1      $f4, 0x14c($s1)
/* 6BC544 802189B4 E620000C */  swc1      $f0, 0xc($s1)
/* 6BC548 802189B8 E6220010 */  swc1      $f2, 0x10($s1)
/* 6BC54C 802189BC E6240014 */  swc1      $f4, 0x14($s1)
/* 6BC550 802189C0 AE420070 */  sw        $v0, 0x70($s2)
.L802189C4:
/* 6BC554 802189C4 C6200050 */  lwc1      $f0, 0x50($s1)
/* 6BC558 802189C8 4480A000 */  mtc1      $zero, $f20
/* 6BC55C 802189CC 00000000 */  nop
/* 6BC560 802189D0 4600A03C */  c.lt.s    $f20, $f0
/* 6BC564 802189D4 00000000 */  nop
/* 6BC568 802189D8 45000005 */  bc1f      .L802189F0
/* 6BC56C 802189DC 2404FF81 */   addiu    $a0, $zero, -0x7f
/* 6BC570 802189E0 8E260064 */  lw        $a2, 0x64($s1)
/* 6BC574 802189E4 0C098F3F */  jal       set_animation
/* 6BC578 802189E8 24050001 */   addiu    $a1, $zero, 1
/* 6BC57C 802189EC C6200050 */  lwc1      $f0, 0x50($s1)
.L802189F0:
/* 6BC580 802189F0 4614003C */  c.lt.s    $f0, $f20
/* 6BC584 802189F4 00000000 */  nop
/* 6BC588 802189F8 45000004 */  bc1f      .L80218A0C
/* 6BC58C 802189FC 2404FF81 */   addiu    $a0, $zero, -0x7f
/* 6BC590 80218A00 8E260068 */  lw        $a2, 0x68($s1)
/* 6BC594 80218A04 0C098F3F */  jal       set_animation
/* 6BC598 80218A08 24050001 */   addiu    $a1, $zero, 1
.L80218A0C:
/* 6BC59C 80218A0C C6240010 */  lwc1      $f4, 0x10($s1)
/* 6BC5A0 80218A10 C6200050 */  lwc1      $f0, 0x50($s1)
/* 6BC5A4 80218A14 8E25004C */  lw        $a1, 0x4c($s1)
/* 6BC5A8 80218A18 46002100 */  add.s     $f4, $f4, $f0
/* 6BC5AC 80218A1C C6220048 */  lwc1      $f2, 0x48($s1)
/* 6BC5B0 80218A20 8E260054 */  lw        $a2, 0x54($s1)
/* 6BC5B4 80218A24 46020001 */  sub.s     $f0, $f0, $f2
/* 6BC5B8 80218A28 0260202D */  daddu     $a0, $s3, $zero
/* 6BC5BC 80218A2C E6240010 */  swc1      $f4, 0x10($s1)
/* 6BC5C0 80218A30 0C09904A */  jal       add_xz_vec3f
/* 6BC5C4 80218A34 E6200050 */   swc1     $f0, 0x50($s1)
/* 6BC5C8 80218A38 C6200010 */  lwc1      $f0, 0x10($s1)
/* 6BC5CC 80218A3C C6220014 */  lwc1      $f2, 0x14($s1)
/* 6BC5D0 80218A40 E6200148 */  swc1      $f0, 0x148($s1)
/* 6BC5D4 80218A44 C620000C */  lwc1      $f0, 0xc($s1)
/* 6BC5D8 80218A48 C6240148 */  lwc1      $f4, 0x148($s1)
/* 6BC5DC 80218A4C E622014C */  swc1      $f2, 0x14c($s1)
/* 6BC5E0 80218A50 4614203C */  c.lt.s    $f4, $f20
/* 6BC5E4 80218A54 00000000 */  nop
/* 6BC5E8 80218A58 45010003 */  bc1t      .L80218A68
/* 6BC5EC 80218A5C E6200144 */   swc1     $f0, 0x144($s1)
/* 6BC5F0 80218A60 080862A5 */  j         .L80218A94
/* 6BC5F4 80218A64 0000102D */   daddu    $v0, $zero, $zero
.L80218A68:
/* 6BC5F8 80218A68 C620018C */  lwc1      $f0, 0x18c($s1)
/* 6BC5FC 80218A6C E6340148 */  swc1      $f20, 0x148($s1)
/* 6BC600 80218A70 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6BC604 80218A74 8E250144 */  lw        $a1, 0x144($s1)
/* 6BC608 80218A78 8E260148 */  lw        $a2, 0x148($s1)
/* 6BC60C 80218A7C 8E27014C */  lw        $a3, 0x14c($s1)
/* 6BC610 80218A80 0C0990BC */  jal       play_movement_dust_effects
/* 6BC614 80218A84 24040002 */   addiu    $a0, $zero, 2
/* 6BC618 80218A88 0C05272D */  jal       sfx_play_sound
/* 6BC61C 80218A8C 24040148 */   addiu    $a0, $zero, 0x148
/* 6BC620 80218A90 24020001 */  addiu     $v0, $zero, 1
.L80218A94:
/* 6BC624 80218A94 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6BC628 80218A98 8FB30024 */  lw        $s3, 0x24($sp)
/* 6BC62C 80218A9C 8FB20020 */  lw        $s2, 0x20($sp)
/* 6BC630 80218AA0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6BC634 80218AA4 8FB00018 */  lw        $s0, 0x18($sp)
/* 6BC638 80218AA8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 6BC63C 80218AAC 03E00008 */  jr        $ra
/* 6BC640 80218AB0 27BD0038 */   addiu    $sp, $sp, 0x38
