.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BC8
/* 87B7A8 80241BC8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 87B7AC 80241BCC AFB3001C */  sw        $s3, 0x1c($sp)
/* 87B7B0 80241BD0 0080982D */  daddu     $s3, $a0, $zero
/* 87B7B4 80241BD4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 87B7B8 80241BD8 AFB20018 */  sw        $s2, 0x18($sp)
/* 87B7BC 80241BDC AFB10014 */  sw        $s1, 0x14($sp)
/* 87B7C0 80241BE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 87B7C4 80241BE4 8E720148 */  lw        $s2, 0x148($s3)
/* 87B7C8 80241BE8 86440008 */  lh        $a0, 8($s2)
/* 87B7CC 80241BEC 0C00EABB */  jal       get_npc_unsafe
/* 87B7D0 80241BF0 00A0882D */   daddu    $s1, $a1, $zero
/* 87B7D4 80241BF4 8E240008 */  lw        $a0, 8($s1)
/* 87B7D8 80241BF8 0040802D */  daddu     $s0, $v0, $zero
/* 87B7DC 80241BFC 00041FC2 */  srl       $v1, $a0, 0x1f
/* 87B7E0 80241C00 00832021 */  addu      $a0, $a0, $v1
/* 87B7E4 80241C04 00042043 */  sra       $a0, $a0, 1
/* 87B7E8 80241C08 0C00A67F */  jal       rand_int
/* 87B7EC 80241C0C 24840001 */   addiu    $a0, $a0, 1
/* 87B7F0 80241C10 8E230008 */  lw        $v1, 8($s1)
/* 87B7F4 80241C14 240400B4 */  addiu     $a0, $zero, 0xb4
/* 87B7F8 80241C18 00032FC2 */  srl       $a1, $v1, 0x1f
/* 87B7FC 80241C1C 00651821 */  addu      $v1, $v1, $a1
/* 87B800 80241C20 00031843 */  sra       $v1, $v1, 1
/* 87B804 80241C24 00621821 */  addu      $v1, $v1, $v0
/* 87B808 80241C28 0C00A67F */  jal       rand_int
/* 87B80C 80241C2C A603008E */   sh       $v1, 0x8e($s0)
/* 87B810 80241C30 C60C000C */  lwc1      $f12, 0xc($s0)
/* 87B814 80241C34 44820000 */  mtc1      $v0, $f0
/* 87B818 80241C38 00000000 */  nop       
/* 87B81C 80241C3C 46800020 */  cvt.s.w   $f0, $f0
/* 87B820 80241C40 46006300 */  add.s     $f12, $f12, $f0
/* 87B824 80241C44 3C0142B4 */  lui       $at, 0x42b4
/* 87B828 80241C48 44810000 */  mtc1      $at, $f0
/* 87B82C 80241C4C 0C00A6C9 */  jal       clamp_angle
/* 87B830 80241C50 46006301 */   sub.s    $f12, $f12, $f0
/* 87B834 80241C54 E600000C */  swc1      $f0, 0xc($s0)
/* 87B838 80241C58 8E4200CC */  lw        $v0, 0xcc($s2)
/* 87B83C 80241C5C 8C420000 */  lw        $v0, ($v0)
/* 87B840 80241C60 AE020028 */  sw        $v0, 0x28($s0)
/* 87B844 80241C64 24020003 */  addiu     $v0, $zero, 3
/* 87B848 80241C68 AE620070 */  sw        $v0, 0x70($s3)
/* 87B84C 80241C6C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 87B850 80241C70 8FB3001C */  lw        $s3, 0x1c($sp)
/* 87B854 80241C74 8FB20018 */  lw        $s2, 0x18($sp)
/* 87B858 80241C78 8FB10014 */  lw        $s1, 0x14($sp)
/* 87B85C 80241C7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 87B860 80241C80 03E00008 */  jr        $ra
/* 87B864 80241C84 27BD0028 */   addiu    $sp, $sp, 0x28
