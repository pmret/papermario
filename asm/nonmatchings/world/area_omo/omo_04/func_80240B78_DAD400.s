.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B78_DADF78
/* DADF78 80240B78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DADF7C 80240B7C AFB3001C */  sw        $s3, 0x1c($sp)
/* DADF80 80240B80 0080982D */  daddu     $s3, $a0, $zero
/* DADF84 80240B84 AFBF0020 */  sw        $ra, 0x20($sp)
/* DADF88 80240B88 AFB20018 */  sw        $s2, 0x18($sp)
/* DADF8C 80240B8C AFB10014 */  sw        $s1, 0x14($sp)
/* DADF90 80240B90 AFB00010 */  sw        $s0, 0x10($sp)
/* DADF94 80240B94 8E720148 */  lw        $s2, 0x148($s3)
/* DADF98 80240B98 86440008 */  lh        $a0, 8($s2)
/* DADF9C 80240B9C 0C00EABB */  jal       get_npc_unsafe
/* DADFA0 80240BA0 00A0882D */   daddu    $s1, $a1, $zero
/* DADFA4 80240BA4 8E240008 */  lw        $a0, 8($s1)
/* DADFA8 80240BA8 0040802D */  daddu     $s0, $v0, $zero
/* DADFAC 80240BAC 00041FC2 */  srl       $v1, $a0, 0x1f
/* DADFB0 80240BB0 00832021 */  addu      $a0, $a0, $v1
/* DADFB4 80240BB4 00042043 */  sra       $a0, $a0, 1
/* DADFB8 80240BB8 0C00A67F */  jal       rand_int
/* DADFBC 80240BBC 24840001 */   addiu    $a0, $a0, 1
/* DADFC0 80240BC0 8E230008 */  lw        $v1, 8($s1)
/* DADFC4 80240BC4 240400B4 */  addiu     $a0, $zero, 0xb4
/* DADFC8 80240BC8 00032FC2 */  srl       $a1, $v1, 0x1f
/* DADFCC 80240BCC 00651821 */  addu      $v1, $v1, $a1
/* DADFD0 80240BD0 00031843 */  sra       $v1, $v1, 1
/* DADFD4 80240BD4 00621821 */  addu      $v1, $v1, $v0
/* DADFD8 80240BD8 0C00A67F */  jal       rand_int
/* DADFDC 80240BDC A603008E */   sh       $v1, 0x8e($s0)
/* DADFE0 80240BE0 C60C000C */  lwc1      $f12, 0xc($s0)
/* DADFE4 80240BE4 44820000 */  mtc1      $v0, $f0
/* DADFE8 80240BE8 00000000 */  nop       
/* DADFEC 80240BEC 46800020 */  cvt.s.w   $f0, $f0
/* DADFF0 80240BF0 46006300 */  add.s     $f12, $f12, $f0
/* DADFF4 80240BF4 3C0142B4 */  lui       $at, 0x42b4
/* DADFF8 80240BF8 44810000 */  mtc1      $at, $f0
/* DADFFC 80240BFC 0C00A6C9 */  jal       clamp_angle
/* DAE000 80240C00 46006301 */   sub.s    $f12, $f12, $f0
/* DAE004 80240C04 E600000C */  swc1      $f0, 0xc($s0)
/* DAE008 80240C08 8E4200CC */  lw        $v0, 0xcc($s2)
/* DAE00C 80240C0C 8C420000 */  lw        $v0, ($v0)
/* DAE010 80240C10 AE020028 */  sw        $v0, 0x28($s0)
/* DAE014 80240C14 24020003 */  addiu     $v0, $zero, 3
/* DAE018 80240C18 AE620070 */  sw        $v0, 0x70($s3)
/* DAE01C 80240C1C 8FBF0020 */  lw        $ra, 0x20($sp)
/* DAE020 80240C20 8FB3001C */  lw        $s3, 0x1c($sp)
/* DAE024 80240C24 8FB20018 */  lw        $s2, 0x18($sp)
/* DAE028 80240C28 8FB10014 */  lw        $s1, 0x14($sp)
/* DAE02C 80240C2C 8FB00010 */  lw        $s0, 0x10($sp)
/* DAE030 80240C30 03E00008 */  jr        $ra
/* DAE034 80240C34 27BD0028 */   addiu    $sp, $sp, 0x28
