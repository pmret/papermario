.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BFC_C487DC
/* C487DC 80241BFC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C487E0 80241C00 AFB3001C */  sw        $s3, 0x1c($sp)
/* C487E4 80241C04 0080982D */  daddu     $s3, $a0, $zero
/* C487E8 80241C08 AFBF0020 */  sw        $ra, 0x20($sp)
/* C487EC 80241C0C AFB20018 */  sw        $s2, 0x18($sp)
/* C487F0 80241C10 AFB10014 */  sw        $s1, 0x14($sp)
/* C487F4 80241C14 AFB00010 */  sw        $s0, 0x10($sp)
/* C487F8 80241C18 8E720148 */  lw        $s2, 0x148($s3)
/* C487FC 80241C1C 86440008 */  lh        $a0, 8($s2)
/* C48800 80241C20 0C00EABB */  jal       get_npc_unsafe
/* C48804 80241C24 00A0882D */   daddu    $s1, $a1, $zero
/* C48808 80241C28 8E240008 */  lw        $a0, 8($s1)
/* C4880C 80241C2C 0040802D */  daddu     $s0, $v0, $zero
/* C48810 80241C30 00041FC2 */  srl       $v1, $a0, 0x1f
/* C48814 80241C34 00832021 */  addu      $a0, $a0, $v1
/* C48818 80241C38 00042043 */  sra       $a0, $a0, 1
/* C4881C 80241C3C 0C00A67F */  jal       rand_int
/* C48820 80241C40 24840001 */   addiu    $a0, $a0, 1
/* C48824 80241C44 8E230008 */  lw        $v1, 8($s1)
/* C48828 80241C48 240400B4 */  addiu     $a0, $zero, 0xb4
/* C4882C 80241C4C 00032FC2 */  srl       $a1, $v1, 0x1f
/* C48830 80241C50 00651821 */  addu      $v1, $v1, $a1
/* C48834 80241C54 00031843 */  sra       $v1, $v1, 1
/* C48838 80241C58 00621821 */  addu      $v1, $v1, $v0
/* C4883C 80241C5C 0C00A67F */  jal       rand_int
/* C48840 80241C60 A603008E */   sh       $v1, 0x8e($s0)
/* C48844 80241C64 C60C000C */  lwc1      $f12, 0xc($s0)
/* C48848 80241C68 44820000 */  mtc1      $v0, $f0
/* C4884C 80241C6C 00000000 */  nop       
/* C48850 80241C70 46800020 */  cvt.s.w   $f0, $f0
/* C48854 80241C74 46006300 */  add.s     $f12, $f12, $f0
/* C48858 80241C78 3C0142B4 */  lui       $at, 0x42b4
/* C4885C 80241C7C 44810000 */  mtc1      $at, $f0
/* C48860 80241C80 0C00A6C9 */  jal       clamp_angle
/* C48864 80241C84 46006301 */   sub.s    $f12, $f12, $f0
/* C48868 80241C88 E600000C */  swc1      $f0, 0xc($s0)
/* C4886C 80241C8C 8E4200CC */  lw        $v0, 0xcc($s2)
/* C48870 80241C90 8C420000 */  lw        $v0, ($v0)
/* C48874 80241C94 AE020028 */  sw        $v0, 0x28($s0)
/* C48878 80241C98 24020003 */  addiu     $v0, $zero, 3
/* C4887C 80241C9C AE620070 */  sw        $v0, 0x70($s3)
/* C48880 80241CA0 8FBF0020 */  lw        $ra, 0x20($sp)
/* C48884 80241CA4 8FB3001C */  lw        $s3, 0x1c($sp)
/* C48888 80241CA8 8FB20018 */  lw        $s2, 0x18($sp)
/* C4888C 80241CAC 8FB10014 */  lw        $s1, 0x14($sp)
/* C48890 80241CB0 8FB00010 */  lw        $s0, 0x10($sp)
/* C48894 80241CB4 03E00008 */  jr        $ra
/* C48898 80241CB8 27BD0028 */   addiu    $sp, $sp, 0x28
