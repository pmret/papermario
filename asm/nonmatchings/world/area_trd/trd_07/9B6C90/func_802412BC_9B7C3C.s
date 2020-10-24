.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412BC_9B7C3C
/* 9B7C3C 802412BC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9B7C40 802412C0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9B7C44 802412C4 0080982D */  daddu     $s3, $a0, $zero
/* 9B7C48 802412C8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9B7C4C 802412CC AFB20018 */  sw        $s2, 0x18($sp)
/* 9B7C50 802412D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B7C54 802412D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B7C58 802412D8 8E720148 */  lw        $s2, 0x148($s3)
/* 9B7C5C 802412DC 86440008 */  lh        $a0, 8($s2)
/* 9B7C60 802412E0 0C00EABB */  jal       get_npc_unsafe
/* 9B7C64 802412E4 00A0882D */   daddu    $s1, $a1, $zero
/* 9B7C68 802412E8 8E240008 */  lw        $a0, 8($s1)
/* 9B7C6C 802412EC 0040802D */  daddu     $s0, $v0, $zero
/* 9B7C70 802412F0 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9B7C74 802412F4 00832021 */  addu      $a0, $a0, $v1
/* 9B7C78 802412F8 00042043 */  sra       $a0, $a0, 1
/* 9B7C7C 802412FC 0C00A67F */  jal       rand_int
/* 9B7C80 80241300 24840001 */   addiu    $a0, $a0, 1
/* 9B7C84 80241304 8E230008 */  lw        $v1, 8($s1)
/* 9B7C88 80241308 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9B7C8C 8024130C 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9B7C90 80241310 00651821 */  addu      $v1, $v1, $a1
/* 9B7C94 80241314 00031843 */  sra       $v1, $v1, 1
/* 9B7C98 80241318 00621821 */  addu      $v1, $v1, $v0
/* 9B7C9C 8024131C 0C00A67F */  jal       rand_int
/* 9B7CA0 80241320 A603008E */   sh       $v1, 0x8e($s0)
/* 9B7CA4 80241324 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9B7CA8 80241328 44820000 */  mtc1      $v0, $f0
/* 9B7CAC 8024132C 00000000 */  nop       
/* 9B7CB0 80241330 46800020 */  cvt.s.w   $f0, $f0
/* 9B7CB4 80241334 46006300 */  add.s     $f12, $f12, $f0
/* 9B7CB8 80241338 3C0142B4 */  lui       $at, 0x42b4
/* 9B7CBC 8024133C 44810000 */  mtc1      $at, $f0
/* 9B7CC0 80241340 0C00A6C9 */  jal       clamp_angle
/* 9B7CC4 80241344 46006301 */   sub.s    $f12, $f12, $f0
/* 9B7CC8 80241348 E600000C */  swc1      $f0, 0xc($s0)
/* 9B7CCC 8024134C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9B7CD0 80241350 8C420000 */  lw        $v0, ($v0)
/* 9B7CD4 80241354 AE020028 */  sw        $v0, 0x28($s0)
/* 9B7CD8 80241358 24020003 */  addiu     $v0, $zero, 3
/* 9B7CDC 8024135C AE620070 */  sw        $v0, 0x70($s3)
/* 9B7CE0 80241360 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9B7CE4 80241364 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9B7CE8 80241368 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B7CEC 8024136C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B7CF0 80241370 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B7CF4 80241374 03E00008 */  jr        $ra
/* 9B7CF8 80241378 27BD0028 */   addiu    $sp, $sp, 0x28
