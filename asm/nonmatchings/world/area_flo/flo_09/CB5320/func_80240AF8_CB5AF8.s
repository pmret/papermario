.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AF8_CB5AF8
/* CB5AF8 80240AF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CB5AFC 80240AFC AFB3001C */  sw        $s3, 0x1c($sp)
/* CB5B00 80240B00 0080982D */  daddu     $s3, $a0, $zero
/* CB5B04 80240B04 AFBF0020 */  sw        $ra, 0x20($sp)
/* CB5B08 80240B08 AFB20018 */  sw        $s2, 0x18($sp)
/* CB5B0C 80240B0C AFB10014 */  sw        $s1, 0x14($sp)
/* CB5B10 80240B10 AFB00010 */  sw        $s0, 0x10($sp)
/* CB5B14 80240B14 8E720148 */  lw        $s2, 0x148($s3)
/* CB5B18 80240B18 86440008 */  lh        $a0, 8($s2)
/* CB5B1C 80240B1C 0C00EABB */  jal       get_npc_unsafe
/* CB5B20 80240B20 00A0882D */   daddu    $s1, $a1, $zero
/* CB5B24 80240B24 8E240008 */  lw        $a0, 8($s1)
/* CB5B28 80240B28 0040802D */  daddu     $s0, $v0, $zero
/* CB5B2C 80240B2C 00041FC2 */  srl       $v1, $a0, 0x1f
/* CB5B30 80240B30 00832021 */  addu      $a0, $a0, $v1
/* CB5B34 80240B34 00042043 */  sra       $a0, $a0, 1
/* CB5B38 80240B38 0C00A67F */  jal       rand_int
/* CB5B3C 80240B3C 24840001 */   addiu    $a0, $a0, 1
/* CB5B40 80240B40 8E230008 */  lw        $v1, 8($s1)
/* CB5B44 80240B44 240400B4 */  addiu     $a0, $zero, 0xb4
/* CB5B48 80240B48 00032FC2 */  srl       $a1, $v1, 0x1f
/* CB5B4C 80240B4C 00651821 */  addu      $v1, $v1, $a1
/* CB5B50 80240B50 00031843 */  sra       $v1, $v1, 1
/* CB5B54 80240B54 00621821 */  addu      $v1, $v1, $v0
/* CB5B58 80240B58 0C00A67F */  jal       rand_int
/* CB5B5C 80240B5C A603008E */   sh       $v1, 0x8e($s0)
/* CB5B60 80240B60 C60C000C */  lwc1      $f12, 0xc($s0)
/* CB5B64 80240B64 44820000 */  mtc1      $v0, $f0
/* CB5B68 80240B68 00000000 */  nop       
/* CB5B6C 80240B6C 46800020 */  cvt.s.w   $f0, $f0
/* CB5B70 80240B70 46006300 */  add.s     $f12, $f12, $f0
/* CB5B74 80240B74 3C0142B4 */  lui       $at, 0x42b4
/* CB5B78 80240B78 44810000 */  mtc1      $at, $f0
/* CB5B7C 80240B7C 0C00A6C9 */  jal       clamp_angle
/* CB5B80 80240B80 46006301 */   sub.s    $f12, $f12, $f0
/* CB5B84 80240B84 E600000C */  swc1      $f0, 0xc($s0)
/* CB5B88 80240B88 8E4200CC */  lw        $v0, 0xcc($s2)
/* CB5B8C 80240B8C 8C420000 */  lw        $v0, ($v0)
/* CB5B90 80240B90 AE020028 */  sw        $v0, 0x28($s0)
/* CB5B94 80240B94 24020003 */  addiu     $v0, $zero, 3
/* CB5B98 80240B98 AE620070 */  sw        $v0, 0x70($s3)
/* CB5B9C 80240B9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* CB5BA0 80240BA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* CB5BA4 80240BA4 8FB20018 */  lw        $s2, 0x18($sp)
/* CB5BA8 80240BA8 8FB10014 */  lw        $s1, 0x14($sp)
/* CB5BAC 80240BAC 8FB00010 */  lw        $s0, 0x10($sp)
/* CB5BB0 80240BB0 03E00008 */  jr        $ra
/* CB5BB4 80240BB4 27BD0028 */   addiu    $sp, $sp, 0x28
