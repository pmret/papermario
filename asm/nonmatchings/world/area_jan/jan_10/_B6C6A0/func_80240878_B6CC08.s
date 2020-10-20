.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240878_B6CC08
/* B6CC08 80240878 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B6CC0C 8024087C AFB3001C */  sw        $s3, 0x1c($sp)
/* B6CC10 80240880 0080982D */  daddu     $s3, $a0, $zero
/* B6CC14 80240884 AFBF0020 */  sw        $ra, 0x20($sp)
/* B6CC18 80240888 AFB20018 */  sw        $s2, 0x18($sp)
/* B6CC1C 8024088C AFB10014 */  sw        $s1, 0x14($sp)
/* B6CC20 80240890 AFB00010 */  sw        $s0, 0x10($sp)
/* B6CC24 80240894 8E720148 */  lw        $s2, 0x148($s3)
/* B6CC28 80240898 86440008 */  lh        $a0, 8($s2)
/* B6CC2C 8024089C 0C00EABB */  jal       get_npc_unsafe
/* B6CC30 802408A0 00A0882D */   daddu    $s1, $a1, $zero
/* B6CC34 802408A4 8E240008 */  lw        $a0, 8($s1)
/* B6CC38 802408A8 0040802D */  daddu     $s0, $v0, $zero
/* B6CC3C 802408AC 00041FC2 */  srl       $v1, $a0, 0x1f
/* B6CC40 802408B0 00832021 */  addu      $a0, $a0, $v1
/* B6CC44 802408B4 00042043 */  sra       $a0, $a0, 1
/* B6CC48 802408B8 0C00A67F */  jal       rand_int
/* B6CC4C 802408BC 24840001 */   addiu    $a0, $a0, 1
/* B6CC50 802408C0 8E230008 */  lw        $v1, 8($s1)
/* B6CC54 802408C4 240400B4 */  addiu     $a0, $zero, 0xb4
/* B6CC58 802408C8 00032FC2 */  srl       $a1, $v1, 0x1f
/* B6CC5C 802408CC 00651821 */  addu      $v1, $v1, $a1
/* B6CC60 802408D0 00031843 */  sra       $v1, $v1, 1
/* B6CC64 802408D4 00621821 */  addu      $v1, $v1, $v0
/* B6CC68 802408D8 0C00A67F */  jal       rand_int
/* B6CC6C 802408DC A603008E */   sh       $v1, 0x8e($s0)
/* B6CC70 802408E0 C60C000C */  lwc1      $f12, 0xc($s0)
/* B6CC74 802408E4 44820000 */  mtc1      $v0, $f0
/* B6CC78 802408E8 00000000 */  nop       
/* B6CC7C 802408EC 46800020 */  cvt.s.w   $f0, $f0
/* B6CC80 802408F0 46006300 */  add.s     $f12, $f12, $f0
/* B6CC84 802408F4 3C0142B4 */  lui       $at, 0x42b4
/* B6CC88 802408F8 44810000 */  mtc1      $at, $f0
/* B6CC8C 802408FC 0C00A6C9 */  jal       clamp_angle
/* B6CC90 80240900 46006301 */   sub.s    $f12, $f12, $f0
/* B6CC94 80240904 E600000C */  swc1      $f0, 0xc($s0)
/* B6CC98 80240908 8E4200CC */  lw        $v0, 0xcc($s2)
/* B6CC9C 8024090C 8C420000 */  lw        $v0, ($v0)
/* B6CCA0 80240910 AE020028 */  sw        $v0, 0x28($s0)
/* B6CCA4 80240914 24020003 */  addiu     $v0, $zero, 3
/* B6CCA8 80240918 AE620070 */  sw        $v0, 0x70($s3)
/* B6CCAC 8024091C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B6CCB0 80240920 8FB3001C */  lw        $s3, 0x1c($sp)
/* B6CCB4 80240924 8FB20018 */  lw        $s2, 0x18($sp)
/* B6CCB8 80240928 8FB10014 */  lw        $s1, 0x14($sp)
/* B6CCBC 8024092C 8FB00010 */  lw        $s0, 0x10($sp)
/* B6CCC0 80240930 03E00008 */  jr        $ra
/* B6CCC4 80240934 27BD0028 */   addiu    $sp, $sp, 0x28
