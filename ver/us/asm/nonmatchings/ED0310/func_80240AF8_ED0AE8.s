.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AF8_ED0AE8
/* ED0AE8 80240AF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* ED0AEC 80240AFC AFB3001C */  sw        $s3, 0x1c($sp)
/* ED0AF0 80240B00 0080982D */  daddu     $s3, $a0, $zero
/* ED0AF4 80240B04 AFBF0020 */  sw        $ra, 0x20($sp)
/* ED0AF8 80240B08 AFB20018 */  sw        $s2, 0x18($sp)
/* ED0AFC 80240B0C AFB10014 */  sw        $s1, 0x14($sp)
/* ED0B00 80240B10 AFB00010 */  sw        $s0, 0x10($sp)
/* ED0B04 80240B14 8E720148 */  lw        $s2, 0x148($s3)
/* ED0B08 80240B18 86440008 */  lh        $a0, 8($s2)
/* ED0B0C 80240B1C 0C00F92F */  jal       dead_get_npc_unsafe
/* ED0B10 80240B20 00A0882D */   daddu    $s1, $a1, $zero
/* ED0B14 80240B24 8E240008 */  lw        $a0, 8($s1)
/* ED0B18 80240B28 0040802D */  daddu     $s0, $v0, $zero
/* ED0B1C 80240B2C 00041FC2 */  srl       $v1, $a0, 0x1f
/* ED0B20 80240B30 00832021 */  addu      $a0, $a0, $v1
/* ED0B24 80240B34 00042043 */  sra       $a0, $a0, 1
/* ED0B28 80240B38 0C00AB3B */  jal       dead_rand_int
/* ED0B2C 80240B3C 24840001 */   addiu    $a0, $a0, 1
/* ED0B30 80240B40 8E230008 */  lw        $v1, 8($s1)
/* ED0B34 80240B44 240400B4 */  addiu     $a0, $zero, 0xb4
/* ED0B38 80240B48 00032FC2 */  srl       $a1, $v1, 0x1f
/* ED0B3C 80240B4C 00651821 */  addu      $v1, $v1, $a1
/* ED0B40 80240B50 00031843 */  sra       $v1, $v1, 1
/* ED0B44 80240B54 00621821 */  addu      $v1, $v1, $v0
/* ED0B48 80240B58 0C00AB3B */  jal       dead_rand_int
/* ED0B4C 80240B5C A603008E */   sh       $v1, 0x8e($s0)
/* ED0B50 80240B60 C60C000C */  lwc1      $f12, 0xc($s0)
/* ED0B54 80240B64 44820000 */  mtc1      $v0, $f0
/* ED0B58 80240B68 00000000 */  nop
/* ED0B5C 80240B6C 46800020 */  cvt.s.w   $f0, $f0
/* ED0B60 80240B70 46006300 */  add.s     $f12, $f12, $f0
/* ED0B64 80240B74 3C0142B4 */  lui       $at, 0x42b4
/* ED0B68 80240B78 44810000 */  mtc1      $at, $f0
/* ED0B6C 80240B7C 0C00AB85 */  jal       dead_clamp_angle
/* ED0B70 80240B80 46006301 */   sub.s    $f12, $f12, $f0
/* ED0B74 80240B84 E600000C */  swc1      $f0, 0xc($s0)
/* ED0B78 80240B88 8E4200CC */  lw        $v0, 0xcc($s2)
/* ED0B7C 80240B8C 8C420000 */  lw        $v0, ($v0)
/* ED0B80 80240B90 AE020028 */  sw        $v0, 0x28($s0)
/* ED0B84 80240B94 24020003 */  addiu     $v0, $zero, 3
/* ED0B88 80240B98 AE620070 */  sw        $v0, 0x70($s3)
/* ED0B8C 80240B9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* ED0B90 80240BA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* ED0B94 80240BA4 8FB20018 */  lw        $s2, 0x18($sp)
/* ED0B98 80240BA8 8FB10014 */  lw        $s1, 0x14($sp)
/* ED0B9C 80240BAC 8FB00010 */  lw        $s0, 0x10($sp)
/* ED0BA0 80240BB0 03E00008 */  jr        $ra
/* ED0BA4 80240BB4 27BD0028 */   addiu    $sp, $sp, 0x28
