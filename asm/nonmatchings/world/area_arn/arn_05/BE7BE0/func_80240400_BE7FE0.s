.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240400_BE7FE0
/* BE7FE0 80240400 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE7FE4 80240404 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE7FE8 80240408 0080982D */  daddu     $s3, $a0, $zero
/* BE7FEC 8024040C AFBF0020 */  sw        $ra, 0x20($sp)
/* BE7FF0 80240410 AFB20018 */  sw        $s2, 0x18($sp)
/* BE7FF4 80240414 AFB10014 */  sw        $s1, 0x14($sp)
/* BE7FF8 80240418 AFB00010 */  sw        $s0, 0x10($sp)
/* BE7FFC 8024041C 8E720148 */  lw        $s2, 0x148($s3)
/* BE8000 80240420 86440008 */  lh        $a0, 8($s2)
/* BE8004 80240424 0C00EABB */  jal       get_npc_unsafe
/* BE8008 80240428 00A0882D */   daddu    $s1, $a1, $zero
/* BE800C 8024042C 8E240008 */  lw        $a0, 8($s1)
/* BE8010 80240430 0040802D */  daddu     $s0, $v0, $zero
/* BE8014 80240434 00041FC2 */  srl       $v1, $a0, 0x1f
/* BE8018 80240438 00832021 */  addu      $a0, $a0, $v1
/* BE801C 8024043C 00042043 */  sra       $a0, $a0, 1
/* BE8020 80240440 0C00A67F */  jal       rand_int
/* BE8024 80240444 24840001 */   addiu    $a0, $a0, 1
/* BE8028 80240448 8E230008 */  lw        $v1, 8($s1)
/* BE802C 8024044C 240400B4 */  addiu     $a0, $zero, 0xb4
/* BE8030 80240450 00032FC2 */  srl       $a1, $v1, 0x1f
/* BE8034 80240454 00651821 */  addu      $v1, $v1, $a1
/* BE8038 80240458 00031843 */  sra       $v1, $v1, 1
/* BE803C 8024045C 00621821 */  addu      $v1, $v1, $v0
/* BE8040 80240460 0C00A67F */  jal       rand_int
/* BE8044 80240464 A603008E */   sh       $v1, 0x8e($s0)
/* BE8048 80240468 C60C000C */  lwc1      $f12, 0xc($s0)
/* BE804C 8024046C 44820000 */  mtc1      $v0, $f0
/* BE8050 80240470 00000000 */  nop       
/* BE8054 80240474 46800020 */  cvt.s.w   $f0, $f0
/* BE8058 80240478 46006300 */  add.s     $f12, $f12, $f0
/* BE805C 8024047C 3C0142B4 */  lui       $at, 0x42b4
/* BE8060 80240480 44810000 */  mtc1      $at, $f0
/* BE8064 80240484 0C00A6C9 */  jal       clamp_angle
/* BE8068 80240488 46006301 */   sub.s    $f12, $f12, $f0
/* BE806C 8024048C E600000C */  swc1      $f0, 0xc($s0)
/* BE8070 80240490 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE8074 80240494 8C420000 */  lw        $v0, ($v0)
/* BE8078 80240498 AE020028 */  sw        $v0, 0x28($s0)
/* BE807C 8024049C 24020003 */  addiu     $v0, $zero, 3
/* BE8080 802404A0 AE620070 */  sw        $v0, 0x70($s3)
/* BE8084 802404A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE8088 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE808C 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* BE8090 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* BE8094 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* BE8098 802404B8 03E00008 */  jr        $ra
/* BE809C 802404BC 27BD0028 */   addiu    $sp, $sp, 0x28
