.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AB4_A079B4
/* A079B4 80240AB4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A079B8 80240AB8 AFB3002C */  sw        $s3, 0x2c($sp)
/* A079BC 80240ABC 0080982D */  daddu     $s3, $a0, $zero
/* A079C0 80240AC0 AFBF0030 */  sw        $ra, 0x30($sp)
/* A079C4 80240AC4 AFB20028 */  sw        $s2, 0x28($sp)
/* A079C8 80240AC8 AFB10024 */  sw        $s1, 0x24($sp)
/* A079CC 80240ACC AFB00020 */  sw        $s0, 0x20($sp)
/* A079D0 80240AD0 8E710148 */  lw        $s1, 0x148($s3)
/* A079D4 80240AD4 86240008 */  lh        $a0, 8($s1)
/* A079D8 80240AD8 0C00EABB */  jal       get_npc_unsafe
/* A079DC 80240ADC 00A0902D */   daddu    $s2, $a1, $zero
/* A079E0 80240AE0 8E440004 */  lw        $a0, 4($s2)
/* A079E4 80240AE4 0040802D */  daddu     $s0, $v0, $zero
/* A079E8 80240AE8 00041FC2 */  srl       $v1, $a0, 0x1f
/* A079EC 80240AEC 00832021 */  addu      $a0, $a0, $v1
/* A079F0 80240AF0 00042043 */  sra       $a0, $a0, 1
/* A079F4 80240AF4 0C00A67F */  jal       rand_int
/* A079F8 80240AF8 24840001 */   addiu    $a0, $a0, 1
/* A079FC 80240AFC 8E430004 */  lw        $v1, 4($s2)
/* A07A00 80240B00 000327C2 */  srl       $a0, $v1, 0x1f
/* A07A04 80240B04 00641821 */  addu      $v1, $v1, $a0
/* A07A08 80240B08 00031843 */  sra       $v1, $v1, 1
/* A07A0C 80240B0C 00621821 */  addu      $v1, $v1, $v0
/* A07A10 80240B10 A603008E */  sh        $v1, 0x8e($s0)
/* A07A14 80240B14 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A07A18 80240B18 C6000040 */  lwc1      $f0, 0x40($s0)
/* A07A1C 80240B1C C4640000 */  lwc1      $f4, ($v1)
/* A07A20 80240B20 46802120 */  cvt.s.w   $f4, $f4
/* A07A24 80240B24 C4620008 */  lwc1      $f2, 8($v1)
/* A07A28 80240B28 468010A0 */  cvt.s.w   $f2, $f2
/* A07A2C 80240B2C E7A00010 */  swc1      $f0, 0x10($sp)
/* A07A30 80240B30 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A07A34 80240B34 44061000 */  mfc1      $a2, $f2
/* A07A38 80240B38 C440000C */  lwc1      $f0, 0xc($v0)
/* A07A3C 80240B3C 46800020 */  cvt.s.w   $f0, $f0
/* A07A40 80240B40 E7A00014 */  swc1      $f0, 0x14($sp)
/* A07A44 80240B44 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A07A48 80240B48 44052000 */  mfc1      $a1, $f4
/* A07A4C 80240B4C C4400010 */  lwc1      $f0, 0x10($v0)
/* A07A50 80240B50 46800020 */  cvt.s.w   $f0, $f0
/* A07A54 80240B54 E7A00018 */  swc1      $f0, 0x18($sp)
/* A07A58 80240B58 8C640018 */  lw        $a0, 0x18($v1)
/* A07A5C 80240B5C 0C0123F5 */  jal       is_point_within_region
/* A07A60 80240B60 8E070038 */   lw       $a3, 0x38($s0)
/* A07A64 80240B64 1040000E */  beqz      $v0, .L80240BA0
/* A07A68 80240B68 00000000 */   nop      
/* A07A6C 80240B6C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A07A70 80240B70 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A07A74 80240B74 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A07A78 80240B78 C4460000 */  lwc1      $f6, ($v0)
/* A07A7C 80240B7C 468031A0 */  cvt.s.w   $f6, $f6
/* A07A80 80240B80 44063000 */  mfc1      $a2, $f6
/* A07A84 80240B84 C4460008 */  lwc1      $f6, 8($v0)
/* A07A88 80240B88 468031A0 */  cvt.s.w   $f6, $f6
/* A07A8C 80240B8C 44073000 */  mfc1      $a3, $f6
/* A07A90 80240B90 0C00A720 */  jal       atan2
/* A07A94 80240B94 00000000 */   nop      
/* A07A98 80240B98 080902F4 */  j         .L80240BD0
/* A07A9C 80240B9C E600000C */   swc1     $f0, 0xc($s0)
.L80240BA0:
/* A07AA0 80240BA0 0C00A67F */  jal       rand_int
/* A07AA4 80240BA4 2404003C */   addiu    $a0, $zero, 0x3c
/* A07AA8 80240BA8 C60C000C */  lwc1      $f12, 0xc($s0)
/* A07AAC 80240BAC 44820000 */  mtc1      $v0, $f0
/* A07AB0 80240BB0 00000000 */  nop       
/* A07AB4 80240BB4 46800020 */  cvt.s.w   $f0, $f0
/* A07AB8 80240BB8 46006300 */  add.s     $f12, $f12, $f0
/* A07ABC 80240BBC 3C0141F0 */  lui       $at, 0x41f0
/* A07AC0 80240BC0 44810000 */  mtc1      $at, $f0
/* A07AC4 80240BC4 0C00A6C9 */  jal       clamp_angle
/* A07AC8 80240BC8 46006301 */   sub.s    $f12, $f12, $f0
/* A07ACC 80240BCC E600000C */  swc1      $f0, 0xc($s0)
.L80240BD0:
/* A07AD0 80240BD0 8E2200CC */  lw        $v0, 0xcc($s1)
/* A07AD4 80240BD4 8C420004 */  lw        $v0, 4($v0)
/* A07AD8 80240BD8 AE020028 */  sw        $v0, 0x28($s0)
/* A07ADC 80240BDC AE600074 */  sw        $zero, 0x74($s3)
/* A07AE0 80240BE0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A07AE4 80240BE4 8C420014 */  lw        $v0, 0x14($v0)
/* A07AE8 80240BE8 04410004 */  bgez      $v0, .L80240BFC
/* A07AEC 80240BEC 00000000 */   nop      
/* A07AF0 80240BF0 C6400000 */  lwc1      $f0, ($s2)
/* A07AF4 80240BF4 08090307 */  j         .L80240C1C
/* A07AF8 80240BF8 E6000018 */   swc1     $f0, 0x18($s0)
.L80240BFC:
/* A07AFC 80240BFC 3C018024 */  lui       $at, %hi(D_80244D50)
/* A07B00 80240C00 D4224D50 */  ldc1      $f2, %lo(D_80244D50)($at)
/* A07B04 80240C04 44820000 */  mtc1      $v0, $f0
/* A07B08 80240C08 00000000 */  nop       
/* A07B0C 80240C0C 46800021 */  cvt.d.w   $f0, $f0
/* A07B10 80240C10 46220003 */  div.d     $f0, $f0, $f2
/* A07B14 80240C14 46200020 */  cvt.s.d   $f0, $f0
/* A07B18 80240C18 E6000018 */  swc1      $f0, 0x18($s0)
.L80240C1C:
/* A07B1C 80240C1C C600003C */  lwc1      $f0, 0x3c($s0)
/* A07B20 80240C20 3C014059 */  lui       $at, 0x4059
/* A07B24 80240C24 44811800 */  mtc1      $at, $f3
/* A07B28 80240C28 44801000 */  mtc1      $zero, $f2
/* A07B2C 80240C2C 46000021 */  cvt.d.s   $f0, $f0
/* A07B30 80240C30 46220002 */  mul.d     $f0, $f0, $f2
/* A07B34 80240C34 00000000 */  nop       
/* A07B38 80240C38 24020001 */  addiu     $v0, $zero, 1
/* A07B3C 80240C3C 4620018D */  trunc.w.d $f6, $f0
/* A07B40 80240C40 E626007C */  swc1      $f6, 0x7c($s1)
/* A07B44 80240C44 AE620070 */  sw        $v0, 0x70($s3)
/* A07B48 80240C48 8FBF0030 */  lw        $ra, 0x30($sp)
/* A07B4C 80240C4C 8FB3002C */  lw        $s3, 0x2c($sp)
/* A07B50 80240C50 8FB20028 */  lw        $s2, 0x28($sp)
/* A07B54 80240C54 8FB10024 */  lw        $s1, 0x24($sp)
/* A07B58 80240C58 8FB00020 */  lw        $s0, 0x20($sp)
/* A07B5C 80240C5C 03E00008 */  jr        $ra
/* A07B60 80240C60 27BD0038 */   addiu    $sp, $sp, 0x38
