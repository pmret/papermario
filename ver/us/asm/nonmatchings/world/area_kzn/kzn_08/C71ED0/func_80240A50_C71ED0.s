.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A50_C71ED0
/* C71ED0 80240A50 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* C71ED4 80240A54 AFB3002C */  sw        $s3, 0x2c($sp)
/* C71ED8 80240A58 0080982D */  daddu     $s3, $a0, $zero
/* C71EDC 80240A5C AFBF0030 */  sw        $ra, 0x30($sp)
/* C71EE0 80240A60 AFB20028 */  sw        $s2, 0x28($sp)
/* C71EE4 80240A64 AFB10024 */  sw        $s1, 0x24($sp)
/* C71EE8 80240A68 AFB00020 */  sw        $s0, 0x20($sp)
/* C71EEC 80240A6C 8E710148 */  lw        $s1, 0x148($s3)
/* C71EF0 80240A70 86240008 */  lh        $a0, 8($s1)
/* C71EF4 80240A74 0C00EABB */  jal       get_npc_unsafe
/* C71EF8 80240A78 00A0902D */   daddu    $s2, $a1, $zero
/* C71EFC 80240A7C 8E440004 */  lw        $a0, 4($s2)
/* C71F00 80240A80 0040802D */  daddu     $s0, $v0, $zero
/* C71F04 80240A84 00041FC2 */  srl       $v1, $a0, 0x1f
/* C71F08 80240A88 00832021 */  addu      $a0, $a0, $v1
/* C71F0C 80240A8C 00042043 */  sra       $a0, $a0, 1
/* C71F10 80240A90 0C00A67F */  jal       rand_int
/* C71F14 80240A94 24840001 */   addiu    $a0, $a0, 1
/* C71F18 80240A98 8E430004 */  lw        $v1, 4($s2)
/* C71F1C 80240A9C 000327C2 */  srl       $a0, $v1, 0x1f
/* C71F20 80240AA0 00641821 */  addu      $v1, $v1, $a0
/* C71F24 80240AA4 00031843 */  sra       $v1, $v1, 1
/* C71F28 80240AA8 00621821 */  addu      $v1, $v1, $v0
/* C71F2C 80240AAC A603008E */  sh        $v1, 0x8e($s0)
/* C71F30 80240AB0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C71F34 80240AB4 C6000040 */  lwc1      $f0, 0x40($s0)
/* C71F38 80240AB8 C4640000 */  lwc1      $f4, ($v1)
/* C71F3C 80240ABC 46802120 */  cvt.s.w   $f4, $f4
/* C71F40 80240AC0 C4620008 */  lwc1      $f2, 8($v1)
/* C71F44 80240AC4 468010A0 */  cvt.s.w   $f2, $f2
/* C71F48 80240AC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* C71F4C 80240ACC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C71F50 80240AD0 44061000 */  mfc1      $a2, $f2
/* C71F54 80240AD4 C440000C */  lwc1      $f0, 0xc($v0)
/* C71F58 80240AD8 46800020 */  cvt.s.w   $f0, $f0
/* C71F5C 80240ADC E7A00014 */  swc1      $f0, 0x14($sp)
/* C71F60 80240AE0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C71F64 80240AE4 44052000 */  mfc1      $a1, $f4
/* C71F68 80240AE8 C4400010 */  lwc1      $f0, 0x10($v0)
/* C71F6C 80240AEC 46800020 */  cvt.s.w   $f0, $f0
/* C71F70 80240AF0 E7A00018 */  swc1      $f0, 0x18($sp)
/* C71F74 80240AF4 8C640018 */  lw        $a0, 0x18($v1)
/* C71F78 80240AF8 0C0123F5 */  jal       is_point_within_region
/* C71F7C 80240AFC 8E070038 */   lw       $a3, 0x38($s0)
/* C71F80 80240B00 1040000E */  beqz      $v0, .L80240B3C
/* C71F84 80240B04 00000000 */   nop
/* C71F88 80240B08 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C71F8C 80240B0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C71F90 80240B10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C71F94 80240B14 C4460000 */  lwc1      $f6, ($v0)
/* C71F98 80240B18 468031A0 */  cvt.s.w   $f6, $f6
/* C71F9C 80240B1C 44063000 */  mfc1      $a2, $f6
/* C71FA0 80240B20 C4460008 */  lwc1      $f6, 8($v0)
/* C71FA4 80240B24 468031A0 */  cvt.s.w   $f6, $f6
/* C71FA8 80240B28 44073000 */  mfc1      $a3, $f6
/* C71FAC 80240B2C 0C00A720 */  jal       atan2
/* C71FB0 80240B30 00000000 */   nop
/* C71FB4 80240B34 080902DB */  j         .L80240B6C
/* C71FB8 80240B38 E600000C */   swc1     $f0, 0xc($s0)
.L80240B3C:
/* C71FBC 80240B3C 0C00A67F */  jal       rand_int
/* C71FC0 80240B40 2404003C */   addiu    $a0, $zero, 0x3c
/* C71FC4 80240B44 C60C000C */  lwc1      $f12, 0xc($s0)
/* C71FC8 80240B48 44820000 */  mtc1      $v0, $f0
/* C71FCC 80240B4C 00000000 */  nop
/* C71FD0 80240B50 46800020 */  cvt.s.w   $f0, $f0
/* C71FD4 80240B54 46006300 */  add.s     $f12, $f12, $f0
/* C71FD8 80240B58 3C0141F0 */  lui       $at, 0x41f0
/* C71FDC 80240B5C 44810000 */  mtc1      $at, $f0
/* C71FE0 80240B60 0C00A6C9 */  jal       clamp_angle
/* C71FE4 80240B64 46006301 */   sub.s    $f12, $f12, $f0
/* C71FE8 80240B68 E600000C */  swc1      $f0, 0xc($s0)
.L80240B6C:
/* C71FEC 80240B6C 8E2200CC */  lw        $v0, 0xcc($s1)
/* C71FF0 80240B70 8C420004 */  lw        $v0, 4($v0)
/* C71FF4 80240B74 AE020028 */  sw        $v0, 0x28($s0)
/* C71FF8 80240B78 AE600074 */  sw        $zero, 0x74($s3)
/* C71FFC 80240B7C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C72000 80240B80 8C420014 */  lw        $v0, 0x14($v0)
/* C72004 80240B84 04410004 */  bgez      $v0, .L80240B98
/* C72008 80240B88 00000000 */   nop
/* C7200C 80240B8C C6400000 */  lwc1      $f0, ($s2)
/* C72010 80240B90 080902EE */  j         .L80240BB8
/* C72014 80240B94 E6000018 */   swc1     $f0, 0x18($s0)
.L80240B98:
/* C72018 80240B98 3C018024 */  lui       $at, %hi(D_802455E0_C76A60)
/* C7201C 80240B9C D42255E0 */  ldc1      $f2, %lo(D_802455E0_C76A60)($at)
/* C72020 80240BA0 44820000 */  mtc1      $v0, $f0
/* C72024 80240BA4 00000000 */  nop
/* C72028 80240BA8 46800021 */  cvt.d.w   $f0, $f0
/* C7202C 80240BAC 46220003 */  div.d     $f0, $f0, $f2
/* C72030 80240BB0 46200020 */  cvt.s.d   $f0, $f0
/* C72034 80240BB4 E6000018 */  swc1      $f0, 0x18($s0)
.L80240BB8:
/* C72038 80240BB8 C600003C */  lwc1      $f0, 0x3c($s0)
/* C7203C 80240BBC 3C014059 */  lui       $at, 0x4059
/* C72040 80240BC0 44811800 */  mtc1      $at, $f3
/* C72044 80240BC4 44801000 */  mtc1      $zero, $f2
/* C72048 80240BC8 46000021 */  cvt.d.s   $f0, $f0
/* C7204C 80240BCC 46220002 */  mul.d     $f0, $f0, $f2
/* C72050 80240BD0 00000000 */  nop
/* C72054 80240BD4 24020001 */  addiu     $v0, $zero, 1
/* C72058 80240BD8 4620018D */  trunc.w.d $f6, $f0
/* C7205C 80240BDC E626007C */  swc1      $f6, 0x7c($s1)
/* C72060 80240BE0 AE620070 */  sw        $v0, 0x70($s3)
/* C72064 80240BE4 8FBF0030 */  lw        $ra, 0x30($sp)
/* C72068 80240BE8 8FB3002C */  lw        $s3, 0x2c($sp)
/* C7206C 80240BEC 8FB20028 */  lw        $s2, 0x28($sp)
/* C72070 80240BF0 8FB10024 */  lw        $s1, 0x24($sp)
/* C72074 80240BF4 8FB00020 */  lw        $s0, 0x20($sp)
/* C72078 80240BF8 03E00008 */  jr        $ra
/* C7207C 80240BFC 27BD0038 */   addiu    $sp, $sp, 0x38
