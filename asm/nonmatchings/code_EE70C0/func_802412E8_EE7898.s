.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412E8_EE7898
/* EE7898 802412E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* EE789C 802412EC AFB3001C */  sw        $s3, 0x1c($sp)
/* EE78A0 802412F0 0080982D */  daddu     $s3, $a0, $zero
/* EE78A4 802412F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* EE78A8 802412F8 AFB20018 */  sw        $s2, 0x18($sp)
/* EE78AC 802412FC AFB10014 */  sw        $s1, 0x14($sp)
/* EE78B0 80241300 AFB00010 */  sw        $s0, 0x10($sp)
/* EE78B4 80241304 8E720148 */  lw        $s2, 0x148($s3)
/* EE78B8 80241308 86440008 */  lh        $a0, 8($s2)
/* EE78BC 8024130C 0C00F92F */  jal       func_8003E4BC
/* EE78C0 80241310 00A0882D */   daddu    $s1, $a1, $zero
/* EE78C4 80241314 8E240008 */  lw        $a0, 8($s1)
/* EE78C8 80241318 0040802D */  daddu     $s0, $v0, $zero
/* EE78CC 8024131C 00041FC2 */  srl       $v1, $a0, 0x1f
/* EE78D0 80241320 00832021 */  addu      $a0, $a0, $v1
/* EE78D4 80241324 00042043 */  sra       $a0, $a0, 1
/* EE78D8 80241328 0C00AB3B */  jal       func_8002ACEC
/* EE78DC 8024132C 24840001 */   addiu    $a0, $a0, 1
/* EE78E0 80241330 8E230008 */  lw        $v1, 8($s1)
/* EE78E4 80241334 240400B4 */  addiu     $a0, $zero, 0xb4
/* EE78E8 80241338 00032FC2 */  srl       $a1, $v1, 0x1f
/* EE78EC 8024133C 00651821 */  addu      $v1, $v1, $a1
/* EE78F0 80241340 00031843 */  sra       $v1, $v1, 1
/* EE78F4 80241344 00621821 */  addu      $v1, $v1, $v0
/* EE78F8 80241348 0C00AB3B */  jal       func_8002ACEC
/* EE78FC 8024134C A603008E */   sh       $v1, 0x8e($s0)
/* EE7900 80241350 C60C000C */  lwc1      $f12, 0xc($s0)
/* EE7904 80241354 44820000 */  mtc1      $v0, $f0
/* EE7908 80241358 00000000 */  nop       
/* EE790C 8024135C 46800020 */  cvt.s.w   $f0, $f0
/* EE7910 80241360 46006300 */  add.s     $f12, $f12, $f0
/* EE7914 80241364 3C0142B4 */  lui       $at, 0x42b4
/* EE7918 80241368 44810000 */  mtc1      $at, $f0
/* EE791C 8024136C 0C00AB85 */  jal       func_8002AE14
/* EE7920 80241370 46006301 */   sub.s    $f12, $f12, $f0
/* EE7924 80241374 E600000C */  swc1      $f0, 0xc($s0)
/* EE7928 80241378 8E4200CC */  lw        $v0, 0xcc($s2)
/* EE792C 8024137C 8C420000 */  lw        $v0, ($v0)
/* EE7930 80241380 AE020028 */  sw        $v0, 0x28($s0)
/* EE7934 80241384 24020003 */  addiu     $v0, $zero, 3
/* EE7938 80241388 AE620070 */  sw        $v0, 0x70($s3)
/* EE793C 8024138C 8FBF0020 */  lw        $ra, 0x20($sp)
/* EE7940 80241390 8FB3001C */  lw        $s3, 0x1c($sp)
/* EE7944 80241394 8FB20018 */  lw        $s2, 0x18($sp)
/* EE7948 80241398 8FB10014 */  lw        $s1, 0x14($sp)
/* EE794C 8024139C 8FB00010 */  lw        $s0, 0x10($sp)
/* EE7950 802413A0 03E00008 */  jr        $ra
/* EE7954 802413A4 27BD0028 */   addiu    $sp, $sp, 0x28
