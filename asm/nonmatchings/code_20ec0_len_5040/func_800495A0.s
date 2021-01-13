.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800495A0
/* 249A0 800495A0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 249A4 800495A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 249A8 800495A8 0080982D */  daddu     $s3, $a0, $zero
/* 249AC 800495AC AFBF0020 */  sw        $ra, 0x20($sp)
/* 249B0 800495B0 AFB20018 */  sw        $s2, 0x18($sp)
/* 249B4 800495B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 249B8 800495B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 249BC 800495BC 8E710148 */  lw        $s1, 0x148($s3)
/* 249C0 800495C0 86240008 */  lh        $a0, 8($s1)
/* 249C4 800495C4 0C00EABB */  jal       get_npc_unsafe
/* 249C8 800495C8 00A0902D */   daddu    $s2, $a1, $zero
/* 249CC 800495CC 8E440004 */  lw        $a0, 4($s2)
/* 249D0 800495D0 0040802D */  daddu     $s0, $v0, $zero
/* 249D4 800495D4 00041FC2 */  srl       $v1, $a0, 0x1f
/* 249D8 800495D8 00832021 */  addu      $a0, $a0, $v1
/* 249DC 800495DC 00042043 */  sra       $a0, $a0, 1
/* 249E0 800495E0 0C00A67F */  jal       rand_int
/* 249E4 800495E4 24840001 */   addiu    $a0, $a0, 1
/* 249E8 800495E8 8E430004 */  lw        $v1, 4($s2)
/* 249EC 800495EC 2404003C */  addiu     $a0, $zero, 0x3c
/* 249F0 800495F0 00032FC2 */  srl       $a1, $v1, 0x1f
/* 249F4 800495F4 00651821 */  addu      $v1, $v1, $a1
/* 249F8 800495F8 00031843 */  sra       $v1, $v1, 1
/* 249FC 800495FC 00621821 */  addu      $v1, $v1, $v0
/* 24A00 80049600 0C00A67F */  jal       rand_int
/* 24A04 80049604 A603008E */   sh       $v1, 0x8e($s0)
/* 24A08 80049608 C60C000C */  lwc1      $f12, 0xc($s0)
/* 24A0C 8004960C 44820000 */  mtc1      $v0, $f0
/* 24A10 80049610 00000000 */  nop
/* 24A14 80049614 46800020 */  cvt.s.w   $f0, $f0
/* 24A18 80049618 46006300 */  add.s     $f12, $f12, $f0
/* 24A1C 8004961C 3C0141F0 */  lui       $at, 0x41f0
/* 24A20 80049620 44810000 */  mtc1      $at, $f0
/* 24A24 80049624 0C00A6C9 */  jal       clamp_angle
/* 24A28 80049628 46006301 */   sub.s    $f12, $f12, $f0
/* 24A2C 8004962C E600000C */  swc1      $f0, 0xc($s0)
/* 24A30 80049630 8E2200CC */  lw        $v0, 0xcc($s1)
/* 24A34 80049634 8C420004 */  lw        $v0, 4($v0)
/* 24A38 80049638 AE020028 */  sw        $v0, 0x28($s0)
/* 24A3C 8004963C AE600074 */  sw        $zero, 0x74($s3)
/* 24A40 80049640 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 24A44 80049644 8C420014 */  lw        $v0, 0x14($v0)
/* 24A48 80049648 04410004 */  bgez      $v0, .L8004965C
/* 24A4C 8004964C 00000000 */   nop
/* 24A50 80049650 C6400000 */  lwc1      $f0, ($s2)
/* 24A54 80049654 0801259F */  j         .L8004967C
/* 24A58 80049658 E6000018 */   swc1     $f0, 0x18($s0)
.L8004965C:
/* 24A5C 8004965C 3C01800A */  lui       $at, %hi(D_80098720)
/* 24A60 80049660 D4228720 */  ldc1      $f2, %lo(D_80098720)($at)
/* 24A64 80049664 44820000 */  mtc1      $v0, $f0
/* 24A68 80049668 00000000 */  nop
/* 24A6C 8004966C 46800021 */  cvt.d.w   $f0, $f0
/* 24A70 80049670 46220003 */  div.d     $f0, $f0, $f2
/* 24A74 80049674 46200020 */  cvt.s.d   $f0, $f0
/* 24A78 80049678 E6000018 */  swc1      $f0, 0x18($s0)
.L8004967C:
/* 24A7C 8004967C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 24A80 80049680 2403FFBF */  addiu     $v1, $zero, -0x41
/* 24A84 80049684 00431024 */  and       $v0, $v0, $v1
/* 24A88 80049688 2403FFDF */  addiu     $v1, $zero, -0x21
/* 24A8C 8004968C 00431024 */  and       $v0, $v0, $v1
/* 24A90 80049690 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 24A94 80049694 24020001 */  addiu     $v0, $zero, 1
/* 24A98 80049698 AE620070 */  sw        $v0, 0x70($s3)
/* 24A9C 8004969C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 24AA0 800496A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 24AA4 800496A4 8FB20018 */  lw        $s2, 0x18($sp)
/* 24AA8 800496A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 24AAC 800496AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 24AB0 800496B0 03E00008 */  jr        $ra
/* 24AB4 800496B4 27BD0028 */   addiu    $sp, $sp, 0x28
