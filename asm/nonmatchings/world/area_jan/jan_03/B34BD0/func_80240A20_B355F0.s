.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A20_B355F0
/* B355F0 80240A20 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B355F4 80240A24 AFB3001C */  sw        $s3, 0x1c($sp)
/* B355F8 80240A28 0080982D */  daddu     $s3, $a0, $zero
/* B355FC 80240A2C AFBF0020 */  sw        $ra, 0x20($sp)
/* B35600 80240A30 AFB20018 */  sw        $s2, 0x18($sp)
/* B35604 80240A34 AFB10014 */  sw        $s1, 0x14($sp)
/* B35608 80240A38 AFB00010 */  sw        $s0, 0x10($sp)
/* B3560C 80240A3C 8E720148 */  lw        $s2, 0x148($s3)
/* B35610 80240A40 86440008 */  lh        $a0, 8($s2)
/* B35614 80240A44 0C00EABB */  jal       get_npc_unsafe
/* B35618 80240A48 00A0882D */   daddu    $s1, $a1, $zero
/* B3561C 80240A4C 8E240008 */  lw        $a0, 8($s1)
/* B35620 80240A50 0040802D */  daddu     $s0, $v0, $zero
/* B35624 80240A54 00041FC2 */  srl       $v1, $a0, 0x1f
/* B35628 80240A58 00832021 */  addu      $a0, $a0, $v1
/* B3562C 80240A5C 00042043 */  sra       $a0, $a0, 1
/* B35630 80240A60 0C00A67F */  jal       rand_int
/* B35634 80240A64 24840001 */   addiu    $a0, $a0, 1
/* B35638 80240A68 8E230008 */  lw        $v1, 8($s1)
/* B3563C 80240A6C 240400B4 */  addiu     $a0, $zero, 0xb4
/* B35640 80240A70 00032FC2 */  srl       $a1, $v1, 0x1f
/* B35644 80240A74 00651821 */  addu      $v1, $v1, $a1
/* B35648 80240A78 00031843 */  sra       $v1, $v1, 1
/* B3564C 80240A7C 00621821 */  addu      $v1, $v1, $v0
/* B35650 80240A80 0C00A67F */  jal       rand_int
/* B35654 80240A84 A603008E */   sh       $v1, 0x8e($s0)
/* B35658 80240A88 C60C000C */  lwc1      $f12, 0xc($s0)
/* B3565C 80240A8C 44820000 */  mtc1      $v0, $f0
/* B35660 80240A90 00000000 */  nop       
/* B35664 80240A94 46800020 */  cvt.s.w   $f0, $f0
/* B35668 80240A98 46006300 */  add.s     $f12, $f12, $f0
/* B3566C 80240A9C 3C0142B4 */  lui       $at, 0x42b4
/* B35670 80240AA0 44810000 */  mtc1      $at, $f0
/* B35674 80240AA4 0C00A6C9 */  jal       clamp_angle
/* B35678 80240AA8 46006301 */   sub.s    $f12, $f12, $f0
/* B3567C 80240AAC E600000C */  swc1      $f0, 0xc($s0)
/* B35680 80240AB0 8E4200CC */  lw        $v0, 0xcc($s2)
/* B35684 80240AB4 8C420000 */  lw        $v0, ($v0)
/* B35688 80240AB8 AE020028 */  sw        $v0, 0x28($s0)
/* B3568C 80240ABC 24020003 */  addiu     $v0, $zero, 3
/* B35690 80240AC0 AE620070 */  sw        $v0, 0x70($s3)
/* B35694 80240AC4 8FBF0020 */  lw        $ra, 0x20($sp)
/* B35698 80240AC8 8FB3001C */  lw        $s3, 0x1c($sp)
/* B3569C 80240ACC 8FB20018 */  lw        $s2, 0x18($sp)
/* B356A0 80240AD0 8FB10014 */  lw        $s1, 0x14($sp)
/* B356A4 80240AD4 8FB00010 */  lw        $s0, 0x10($sp)
/* B356A8 80240AD8 03E00008 */  jr        $ra
/* B356AC 80240ADC 27BD0028 */   addiu    $sp, $sp, 0x28
