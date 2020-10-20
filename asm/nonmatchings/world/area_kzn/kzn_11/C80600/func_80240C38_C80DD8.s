.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C38_C80DD8
/* C80DD8 80240C38 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C80DDC 80240C3C AFB3001C */  sw        $s3, 0x1c($sp)
/* C80DE0 80240C40 0080982D */  daddu     $s3, $a0, $zero
/* C80DE4 80240C44 AFBF0020 */  sw        $ra, 0x20($sp)
/* C80DE8 80240C48 AFB20018 */  sw        $s2, 0x18($sp)
/* C80DEC 80240C4C AFB10014 */  sw        $s1, 0x14($sp)
/* C80DF0 80240C50 AFB00010 */  sw        $s0, 0x10($sp)
/* C80DF4 80240C54 8E720148 */  lw        $s2, 0x148($s3)
/* C80DF8 80240C58 86440008 */  lh        $a0, 8($s2)
/* C80DFC 80240C5C 0C00EABB */  jal       get_npc_unsafe
/* C80E00 80240C60 00A0882D */   daddu    $s1, $a1, $zero
/* C80E04 80240C64 8E240008 */  lw        $a0, 8($s1)
/* C80E08 80240C68 0040802D */  daddu     $s0, $v0, $zero
/* C80E0C 80240C6C 00041FC2 */  srl       $v1, $a0, 0x1f
/* C80E10 80240C70 00832021 */  addu      $a0, $a0, $v1
/* C80E14 80240C74 00042043 */  sra       $a0, $a0, 1
/* C80E18 80240C78 0C00A67F */  jal       rand_int
/* C80E1C 80240C7C 24840001 */   addiu    $a0, $a0, 1
/* C80E20 80240C80 8E230008 */  lw        $v1, 8($s1)
/* C80E24 80240C84 240400B4 */  addiu     $a0, $zero, 0xb4
/* C80E28 80240C88 00032FC2 */  srl       $a1, $v1, 0x1f
/* C80E2C 80240C8C 00651821 */  addu      $v1, $v1, $a1
/* C80E30 80240C90 00031843 */  sra       $v1, $v1, 1
/* C80E34 80240C94 00621821 */  addu      $v1, $v1, $v0
/* C80E38 80240C98 0C00A67F */  jal       rand_int
/* C80E3C 80240C9C A603008E */   sh       $v1, 0x8e($s0)
/* C80E40 80240CA0 C60C000C */  lwc1      $f12, 0xc($s0)
/* C80E44 80240CA4 44820000 */  mtc1      $v0, $f0
/* C80E48 80240CA8 00000000 */  nop       
/* C80E4C 80240CAC 46800020 */  cvt.s.w   $f0, $f0
/* C80E50 80240CB0 46006300 */  add.s     $f12, $f12, $f0
/* C80E54 80240CB4 3C0142B4 */  lui       $at, 0x42b4
/* C80E58 80240CB8 44810000 */  mtc1      $at, $f0
/* C80E5C 80240CBC 0C00A6C9 */  jal       clamp_angle
/* C80E60 80240CC0 46006301 */   sub.s    $f12, $f12, $f0
/* C80E64 80240CC4 E600000C */  swc1      $f0, 0xc($s0)
/* C80E68 80240CC8 8E4200CC */  lw        $v0, 0xcc($s2)
/* C80E6C 80240CCC 8C420000 */  lw        $v0, ($v0)
/* C80E70 80240CD0 AE020028 */  sw        $v0, 0x28($s0)
/* C80E74 80240CD4 24020003 */  addiu     $v0, $zero, 3
/* C80E78 80240CD8 AE620070 */  sw        $v0, 0x70($s3)
/* C80E7C 80240CDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C80E80 80240CE0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C80E84 80240CE4 8FB20018 */  lw        $s2, 0x18($sp)
/* C80E88 80240CE8 8FB10014 */  lw        $s1, 0x14($sp)
/* C80E8C 80240CEC 8FB00010 */  lw        $s0, 0x10($sp)
/* C80E90 80240CF0 03E00008 */  jr        $ra
/* C80E94 80240CF4 27BD0028 */   addiu    $sp, $sp, 0x28
