.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel EE70C0_UnkNpcAIFunc23
/* EE70C0 80240B10 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EE70C4 80240B14 AFB3002C */  sw        $s3, 0x2c($sp)
/* EE70C8 80240B18 0080982D */  daddu     $s3, $a0, $zero
/* EE70CC 80240B1C AFBF0030 */  sw        $ra, 0x30($sp)
/* EE70D0 80240B20 AFB20028 */  sw        $s2, 0x28($sp)
/* EE70D4 80240B24 AFB10024 */  sw        $s1, 0x24($sp)
/* EE70D8 80240B28 AFB00020 */  sw        $s0, 0x20($sp)
/* EE70DC 80240B2C 8E710148 */  lw        $s1, 0x148($s3)
/* EE70E0 80240B30 86240008 */  lh        $a0, 8($s1)
/* EE70E4 80240B34 0C00F92F */  jal       dead_get_npc_unsafe
/* EE70E8 80240B38 00A0902D */   daddu    $s2, $a1, $zero
/* EE70EC 80240B3C 8E440004 */  lw        $a0, 4($s2)
/* EE70F0 80240B40 0040802D */  daddu     $s0, $v0, $zero
/* EE70F4 80240B44 00041FC2 */  srl       $v1, $a0, 0x1f
/* EE70F8 80240B48 00832021 */  addu      $a0, $a0, $v1
/* EE70FC 80240B4C 00042043 */  sra       $a0, $a0, 1
/* EE7100 80240B50 0C00AB3B */  jal       dead_rand_int
/* EE7104 80240B54 24840001 */   addiu    $a0, $a0, 1
/* EE7108 80240B58 8E430004 */  lw        $v1, 4($s2)
/* EE710C 80240B5C 000327C2 */  srl       $a0, $v1, 0x1f
/* EE7110 80240B60 00641821 */  addu      $v1, $v1, $a0
/* EE7114 80240B64 00031843 */  sra       $v1, $v1, 1
/* EE7118 80240B68 00621821 */  addu      $v1, $v1, $v0
/* EE711C 80240B6C A603008E */  sh        $v1, 0x8e($s0)
/* EE7120 80240B70 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EE7124 80240B74 C6000040 */  lwc1      $f0, 0x40($s0)
/* EE7128 80240B78 C4640000 */  lwc1      $f4, ($v1)
/* EE712C 80240B7C 46802120 */  cvt.s.w   $f4, $f4
/* EE7130 80240B80 C4620008 */  lwc1      $f2, 8($v1)
/* EE7134 80240B84 468010A0 */  cvt.s.w   $f2, $f2
/* EE7138 80240B88 E7A00010 */  swc1      $f0, 0x10($sp)
/* EE713C 80240B8C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EE7140 80240B90 44061000 */  mfc1      $a2, $f2
/* EE7144 80240B94 C440000C */  lwc1      $f0, 0xc($v0)
/* EE7148 80240B98 46800020 */  cvt.s.w   $f0, $f0
/* EE714C 80240B9C E7A00014 */  swc1      $f0, 0x14($sp)
/* EE7150 80240BA0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EE7154 80240BA4 44052000 */  mfc1      $a1, $f4
/* EE7158 80240BA8 C4400010 */  lwc1      $f0, 0x10($v0)
/* EE715C 80240BAC 46800020 */  cvt.s.w   $f0, $f0
/* EE7160 80240BB0 E7A00018 */  swc1      $f0, 0x18($sp)
/* EE7164 80240BB4 8C640018 */  lw        $a0, 0x18($v1)
/* EE7168 80240BB8 0C013431 */  jal       dead_is_point_within_region
/* EE716C 80240BBC 8E070038 */   lw       $a3, 0x38($s0)
/* EE7170 80240BC0 1040000E */  beqz      $v0, .L80240BFC
/* EE7174 80240BC4 00000000 */   nop
/* EE7178 80240BC8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EE717C 80240BCC C60C0038 */  lwc1      $f12, 0x38($s0)
/* EE7180 80240BD0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EE7184 80240BD4 C4460000 */  lwc1      $f6, ($v0)
/* EE7188 80240BD8 468031A0 */  cvt.s.w   $f6, $f6
/* EE718C 80240BDC 44063000 */  mfc1      $a2, $f6
/* EE7190 80240BE0 C4460008 */  lwc1      $f6, 8($v0)
/* EE7194 80240BE4 468031A0 */  cvt.s.w   $f6, $f6
/* EE7198 80240BE8 44073000 */  mfc1      $a3, $f6
/* EE719C 80240BEC 0C00ABDC */  jal       fio_validate_header_checksums
/* EE71A0 80240BF0 00000000 */   nop
/* EE71A4 80240BF4 0809030B */  j         .L80240C2C
/* EE71A8 80240BF8 E600000C */   swc1     $f0, 0xc($s0)
.L80240BFC:
/* EE71AC 80240BFC 0C00AB3B */  jal       dead_rand_int
/* EE71B0 80240C00 2404003C */   addiu    $a0, $zero, 0x3c
/* EE71B4 80240C04 C60C000C */  lwc1      $f12, 0xc($s0)
/* EE71B8 80240C08 44820000 */  mtc1      $v0, $f0
/* EE71BC 80240C0C 00000000 */  nop
/* EE71C0 80240C10 46800020 */  cvt.s.w   $f0, $f0
/* EE71C4 80240C14 46006300 */  add.s     $f12, $f12, $f0
/* EE71C8 80240C18 3C0141F0 */  lui       $at, 0x41f0
/* EE71CC 80240C1C 44810000 */  mtc1      $at, $f0
/* EE71D0 80240C20 0C00AB85 */  jal       dead_clamp_angle
/* EE71D4 80240C24 46006301 */   sub.s    $f12, $f12, $f0
/* EE71D8 80240C28 E600000C */  swc1      $f0, 0xc($s0)
.L80240C2C:
/* EE71DC 80240C2C 8E2200CC */  lw        $v0, 0xcc($s1)
/* EE71E0 80240C30 8C420004 */  lw        $v0, 4($v0)
/* EE71E4 80240C34 AE020028 */  sw        $v0, 0x28($s0)
/* EE71E8 80240C38 AE600074 */  sw        $zero, 0x74($s3)
/* EE71EC 80240C3C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EE71F0 80240C40 8C420014 */  lw        $v0, 0x14($v0)
/* EE71F4 80240C44 04410004 */  bgez      $v0, .L80240C58
/* EE71F8 80240C48 00000000 */   nop
/* EE71FC 80240C4C C6400000 */  lwc1      $f0, ($s2)
/* EE7200 80240C50 0809031E */  j         .L80240C78
/* EE7204 80240C54 E6000018 */   swc1     $f0, 0x18($s0)
.L80240C58:
/* EE7208 80240C58 3C018024 */  lui       $at, %hi(D_80245380_EEB930)
/* EE720C 80240C5C D4225380 */  ldc1      $f2, %lo(D_80245380_EEB930)($at)
/* EE7210 80240C60 44820000 */  mtc1      $v0, $f0
/* EE7214 80240C64 00000000 */  nop
/* EE7218 80240C68 46800021 */  cvt.d.w   $f0, $f0
/* EE721C 80240C6C 46220003 */  div.d     $f0, $f0, $f2
/* EE7220 80240C70 46200020 */  cvt.s.d   $f0, $f0
/* EE7224 80240C74 E6000018 */  swc1      $f0, 0x18($s0)
.L80240C78:
/* EE7228 80240C78 C600003C */  lwc1      $f0, 0x3c($s0)
/* EE722C 80240C7C 3C014059 */  lui       $at, 0x4059
/* EE7230 80240C80 44811800 */  mtc1      $at, $f3
/* EE7234 80240C84 44801000 */  mtc1      $zero, $f2
/* EE7238 80240C88 46000021 */  cvt.d.s   $f0, $f0
/* EE723C 80240C8C 46220002 */  mul.d     $f0, $f0, $f2
/* EE7240 80240C90 00000000 */  nop
/* EE7244 80240C94 24020001 */  addiu     $v0, $zero, 1
/* EE7248 80240C98 4620018D */  trunc.w.d $f6, $f0
/* EE724C 80240C9C E626007C */  swc1      $f6, 0x7c($s1)
/* EE7250 80240CA0 AE620070 */  sw        $v0, 0x70($s3)
/* EE7254 80240CA4 8FBF0030 */  lw        $ra, 0x30($sp)
/* EE7258 80240CA8 8FB3002C */  lw        $s3, 0x2c($sp)
/* EE725C 80240CAC 8FB20028 */  lw        $s2, 0x28($sp)
/* EE7260 80240CB0 8FB10024 */  lw        $s1, 0x24($sp)
/* EE7264 80240CB4 8FB00020 */  lw        $s0, 0x20($sp)
/* EE7268 80240CB8 03E00008 */  jr        $ra
/* EE726C 80240CBC 27BD0038 */   addiu    $sp, $sp, 0x38
