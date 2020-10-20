.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240830_B2CCA0
/* B2CCA0 80240830 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B2CCA4 80240834 AFB3001C */  sw        $s3, 0x1c($sp)
/* B2CCA8 80240838 0080982D */  daddu     $s3, $a0, $zero
/* B2CCAC 8024083C AFBF0020 */  sw        $ra, 0x20($sp)
/* B2CCB0 80240840 AFB20018 */  sw        $s2, 0x18($sp)
/* B2CCB4 80240844 AFB10014 */  sw        $s1, 0x14($sp)
/* B2CCB8 80240848 AFB00010 */  sw        $s0, 0x10($sp)
/* B2CCBC 8024084C 8E720148 */  lw        $s2, 0x148($s3)
/* B2CCC0 80240850 86440008 */  lh        $a0, 8($s2)
/* B2CCC4 80240854 0C00EABB */  jal       get_npc_unsafe
/* B2CCC8 80240858 00A0882D */   daddu    $s1, $a1, $zero
/* B2CCCC 8024085C 8E240008 */  lw        $a0, 8($s1)
/* B2CCD0 80240860 0040802D */  daddu     $s0, $v0, $zero
/* B2CCD4 80240864 00041FC2 */  srl       $v1, $a0, 0x1f
/* B2CCD8 80240868 00832021 */  addu      $a0, $a0, $v1
/* B2CCDC 8024086C 00042043 */  sra       $a0, $a0, 1
/* B2CCE0 80240870 0C00A67F */  jal       rand_int
/* B2CCE4 80240874 24840001 */   addiu    $a0, $a0, 1
/* B2CCE8 80240878 8E230008 */  lw        $v1, 8($s1)
/* B2CCEC 8024087C 240400B4 */  addiu     $a0, $zero, 0xb4
/* B2CCF0 80240880 00032FC2 */  srl       $a1, $v1, 0x1f
/* B2CCF4 80240884 00651821 */  addu      $v1, $v1, $a1
/* B2CCF8 80240888 00031843 */  sra       $v1, $v1, 1
/* B2CCFC 8024088C 00621821 */  addu      $v1, $v1, $v0
/* B2CD00 80240890 0C00A67F */  jal       rand_int
/* B2CD04 80240894 A603008E */   sh       $v1, 0x8e($s0)
/* B2CD08 80240898 C60C000C */  lwc1      $f12, 0xc($s0)
/* B2CD0C 8024089C 44820000 */  mtc1      $v0, $f0
/* B2CD10 802408A0 00000000 */  nop       
/* B2CD14 802408A4 46800020 */  cvt.s.w   $f0, $f0
/* B2CD18 802408A8 46006300 */  add.s     $f12, $f12, $f0
/* B2CD1C 802408AC 3C0142B4 */  lui       $at, 0x42b4
/* B2CD20 802408B0 44810000 */  mtc1      $at, $f0
/* B2CD24 802408B4 0C00A6C9 */  jal       clamp_angle
/* B2CD28 802408B8 46006301 */   sub.s    $f12, $f12, $f0
/* B2CD2C 802408BC E600000C */  swc1      $f0, 0xc($s0)
/* B2CD30 802408C0 8E4200CC */  lw        $v0, 0xcc($s2)
/* B2CD34 802408C4 8C420000 */  lw        $v0, ($v0)
/* B2CD38 802408C8 AE020028 */  sw        $v0, 0x28($s0)
/* B2CD3C 802408CC 24020003 */  addiu     $v0, $zero, 3
/* B2CD40 802408D0 AE620070 */  sw        $v0, 0x70($s3)
/* B2CD44 802408D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* B2CD48 802408D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2CD4C 802408DC 8FB20018 */  lw        $s2, 0x18($sp)
/* B2CD50 802408E0 8FB10014 */  lw        $s1, 0x14($sp)
/* B2CD54 802408E4 8FB00010 */  lw        $s0, 0x10($sp)
/* B2CD58 802408E8 03E00008 */  jr        $ra
/* B2CD5C 802408EC 27BD0028 */   addiu    $sp, $sp, 0x28
