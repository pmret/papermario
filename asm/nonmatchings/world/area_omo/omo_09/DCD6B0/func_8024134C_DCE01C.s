.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024134C_DCE01C
/* DCE01C 8024134C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DCE020 80241350 AFB3001C */  sw        $s3, 0x1c($sp)
/* DCE024 80241354 0080982D */  daddu     $s3, $a0, $zero
/* DCE028 80241358 AFBF0020 */  sw        $ra, 0x20($sp)
/* DCE02C 8024135C AFB20018 */  sw        $s2, 0x18($sp)
/* DCE030 80241360 AFB10014 */  sw        $s1, 0x14($sp)
/* DCE034 80241364 AFB00010 */  sw        $s0, 0x10($sp)
/* DCE038 80241368 8E720148 */  lw        $s2, 0x148($s3)
/* DCE03C 8024136C 86440008 */  lh        $a0, 8($s2)
/* DCE040 80241370 0C00EABB */  jal       get_npc_unsafe
/* DCE044 80241374 00A0882D */   daddu    $s1, $a1, $zero
/* DCE048 80241378 8E240008 */  lw        $a0, 8($s1)
/* DCE04C 8024137C 0040802D */  daddu     $s0, $v0, $zero
/* DCE050 80241380 00041FC2 */  srl       $v1, $a0, 0x1f
/* DCE054 80241384 00832021 */  addu      $a0, $a0, $v1
/* DCE058 80241388 00042043 */  sra       $a0, $a0, 1
/* DCE05C 8024138C 0C00A67F */  jal       rand_int
/* DCE060 80241390 24840001 */   addiu    $a0, $a0, 1
/* DCE064 80241394 8E230008 */  lw        $v1, 8($s1)
/* DCE068 80241398 240400B4 */  addiu     $a0, $zero, 0xb4
/* DCE06C 8024139C 00032FC2 */  srl       $a1, $v1, 0x1f
/* DCE070 802413A0 00651821 */  addu      $v1, $v1, $a1
/* DCE074 802413A4 00031843 */  sra       $v1, $v1, 1
/* DCE078 802413A8 00621821 */  addu      $v1, $v1, $v0
/* DCE07C 802413AC 0C00A67F */  jal       rand_int
/* DCE080 802413B0 A603008E */   sh       $v1, 0x8e($s0)
/* DCE084 802413B4 C60C000C */  lwc1      $f12, 0xc($s0)
/* DCE088 802413B8 44820000 */  mtc1      $v0, $f0
/* DCE08C 802413BC 00000000 */  nop       
/* DCE090 802413C0 46800020 */  cvt.s.w   $f0, $f0
/* DCE094 802413C4 46006300 */  add.s     $f12, $f12, $f0
/* DCE098 802413C8 3C0142B4 */  lui       $at, 0x42b4
/* DCE09C 802413CC 44810000 */  mtc1      $at, $f0
/* DCE0A0 802413D0 0C00A6C9 */  jal       clamp_angle
/* DCE0A4 802413D4 46006301 */   sub.s    $f12, $f12, $f0
/* DCE0A8 802413D8 E600000C */  swc1      $f0, 0xc($s0)
/* DCE0AC 802413DC 8E4200CC */  lw        $v0, 0xcc($s2)
/* DCE0B0 802413E0 8C420000 */  lw        $v0, ($v0)
/* DCE0B4 802413E4 AE020028 */  sw        $v0, 0x28($s0)
/* DCE0B8 802413E8 24020003 */  addiu     $v0, $zero, 3
/* DCE0BC 802413EC AE620070 */  sw        $v0, 0x70($s3)
/* DCE0C0 802413F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* DCE0C4 802413F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* DCE0C8 802413F8 8FB20018 */  lw        $s2, 0x18($sp)
/* DCE0CC 802413FC 8FB10014 */  lw        $s1, 0x14($sp)
/* DCE0D0 80241400 8FB00010 */  lw        $s0, 0x10($sp)
/* DCE0D4 80241404 03E00008 */  jr        $ra
/* DCE0D8 80241408 27BD0028 */   addiu    $sp, $sp, 0x28
