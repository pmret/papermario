.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240848_EF2E58
/* EF2E58 80240848 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EF2E5C 8024084C AFB3001C */  sw        $s3, 0x1c($sp)
/* EF2E60 80240850 0080982D */  daddu     $s3, $a0, $zero
/* EF2E64 80240854 AFBF0020 */  sw        $ra, 0x20($sp)
/* EF2E68 80240858 AFB20018 */  sw        $s2, 0x18($sp)
/* EF2E6C 8024085C AFB10014 */  sw        $s1, 0x14($sp)
/* EF2E70 80240860 AFB00010 */  sw        $s0, 0x10($sp)
/* EF2E74 80240864 8E720148 */  lw        $s2, 0x148($s3)
/* EF2E78 80240868 86440008 */  lh        $a0, 8($s2)
/* EF2E7C 8024086C 0C00F92F */  jal       func_8003E4BC
/* EF2E80 80240870 00A0882D */   daddu    $s1, $a1, $zero
/* EF2E84 80240874 8E240008 */  lw        $a0, 8($s1)
/* EF2E88 80240878 0040802D */  daddu     $s0, $v0, $zero
/* EF2E8C 8024087C 00041FC2 */  srl       $v1, $a0, 0x1f
/* EF2E90 80240880 00832021 */  addu      $a0, $a0, $v1
/* EF2E94 80240884 00042043 */  sra       $a0, $a0, 1
/* EF2E98 80240888 0C00AB3B */  jal       func_8002ACEC
/* EF2E9C 8024088C 24840001 */   addiu    $a0, $a0, 1
/* EF2EA0 80240890 8E230008 */  lw        $v1, 8($s1)
/* EF2EA4 80240894 240400B4 */  addiu     $a0, $zero, 0xb4
/* EF2EA8 80240898 00032FC2 */  srl       $a1, $v1, 0x1f
/* EF2EAC 8024089C 00651821 */  addu      $v1, $v1, $a1
/* EF2EB0 802408A0 00031843 */  sra       $v1, $v1, 1
/* EF2EB4 802408A4 00621821 */  addu      $v1, $v1, $v0
/* EF2EB8 802408A8 0C00AB3B */  jal       func_8002ACEC
/* EF2EBC 802408AC A603008E */   sh       $v1, 0x8e($s0)
/* EF2EC0 802408B0 C60C000C */  lwc1      $f12, 0xc($s0)
/* EF2EC4 802408B4 44820000 */  mtc1      $v0, $f0
/* EF2EC8 802408B8 00000000 */  nop       
/* EF2ECC 802408BC 46800020 */  cvt.s.w   $f0, $f0
/* EF2ED0 802408C0 46006300 */  add.s     $f12, $f12, $f0
/* EF2ED4 802408C4 3C0142B4 */  lui       $at, 0x42b4
/* EF2ED8 802408C8 44810000 */  mtc1      $at, $f0
/* EF2EDC 802408CC 0C00AB85 */  jal       func_8002AE14
/* EF2EE0 802408D0 46006301 */   sub.s    $f12, $f12, $f0
/* EF2EE4 802408D4 E600000C */  swc1      $f0, 0xc($s0)
/* EF2EE8 802408D8 8E4200CC */  lw        $v0, 0xcc($s2)
/* EF2EEC 802408DC 8C420000 */  lw        $v0, ($v0)
/* EF2EF0 802408E0 AE020028 */  sw        $v0, 0x28($s0)
/* EF2EF4 802408E4 24020003 */  addiu     $v0, $zero, 3
/* EF2EF8 802408E8 AE620070 */  sw        $v0, 0x70($s3)
/* EF2EFC 802408EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* EF2F00 802408F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* EF2F04 802408F4 8FB20018 */  lw        $s2, 0x18($sp)
/* EF2F08 802408F8 8FB10014 */  lw        $s1, 0x14($sp)
/* EF2F0C 802408FC 8FB00010 */  lw        $s0, 0x10($sp)
/* EF2F10 80240900 03E00008 */  jr        $ra
/* EF2F14 80240904 27BD0028 */   addiu    $sp, $sp, 0x28
