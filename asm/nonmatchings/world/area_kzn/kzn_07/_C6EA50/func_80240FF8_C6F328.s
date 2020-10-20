.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FF8_C6F328
/* C6F328 80240FF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C6F32C 80240FFC AFB3001C */  sw        $s3, 0x1c($sp)
/* C6F330 80241000 0080982D */  daddu     $s3, $a0, $zero
/* C6F334 80241004 AFBF0020 */  sw        $ra, 0x20($sp)
/* C6F338 80241008 AFB20018 */  sw        $s2, 0x18($sp)
/* C6F33C 8024100C AFB10014 */  sw        $s1, 0x14($sp)
/* C6F340 80241010 AFB00010 */  sw        $s0, 0x10($sp)
/* C6F344 80241014 8E720148 */  lw        $s2, 0x148($s3)
/* C6F348 80241018 86440008 */  lh        $a0, 8($s2)
/* C6F34C 8024101C 0C00EABB */  jal       get_npc_unsafe
/* C6F350 80241020 00A0882D */   daddu    $s1, $a1, $zero
/* C6F354 80241024 8E240008 */  lw        $a0, 8($s1)
/* C6F358 80241028 0040802D */  daddu     $s0, $v0, $zero
/* C6F35C 8024102C 00041FC2 */  srl       $v1, $a0, 0x1f
/* C6F360 80241030 00832021 */  addu      $a0, $a0, $v1
/* C6F364 80241034 00042043 */  sra       $a0, $a0, 1
/* C6F368 80241038 0C00A67F */  jal       rand_int
/* C6F36C 8024103C 24840001 */   addiu    $a0, $a0, 1
/* C6F370 80241040 8E230008 */  lw        $v1, 8($s1)
/* C6F374 80241044 240400B4 */  addiu     $a0, $zero, 0xb4
/* C6F378 80241048 00032FC2 */  srl       $a1, $v1, 0x1f
/* C6F37C 8024104C 00651821 */  addu      $v1, $v1, $a1
/* C6F380 80241050 00031843 */  sra       $v1, $v1, 1
/* C6F384 80241054 00621821 */  addu      $v1, $v1, $v0
/* C6F388 80241058 0C00A67F */  jal       rand_int
/* C6F38C 8024105C A603008E */   sh       $v1, 0x8e($s0)
/* C6F390 80241060 C60C000C */  lwc1      $f12, 0xc($s0)
/* C6F394 80241064 44820000 */  mtc1      $v0, $f0
/* C6F398 80241068 00000000 */  nop       
/* C6F39C 8024106C 46800020 */  cvt.s.w   $f0, $f0
/* C6F3A0 80241070 46006300 */  add.s     $f12, $f12, $f0
/* C6F3A4 80241074 3C0142B4 */  lui       $at, 0x42b4
/* C6F3A8 80241078 44810000 */  mtc1      $at, $f0
/* C6F3AC 8024107C 0C00A6C9 */  jal       clamp_angle
/* C6F3B0 80241080 46006301 */   sub.s    $f12, $f12, $f0
/* C6F3B4 80241084 E600000C */  swc1      $f0, 0xc($s0)
/* C6F3B8 80241088 8E4200CC */  lw        $v0, 0xcc($s2)
/* C6F3BC 8024108C 8C420000 */  lw        $v0, ($v0)
/* C6F3C0 80241090 AE020028 */  sw        $v0, 0x28($s0)
/* C6F3C4 80241094 24020003 */  addiu     $v0, $zero, 3
/* C6F3C8 80241098 AE620070 */  sw        $v0, 0x70($s3)
/* C6F3CC 8024109C 8FBF0020 */  lw        $ra, 0x20($sp)
/* C6F3D0 802410A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C6F3D4 802410A4 8FB20018 */  lw        $s2, 0x18($sp)
/* C6F3D8 802410A8 8FB10014 */  lw        $s1, 0x14($sp)
/* C6F3DC 802410AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C6F3E0 802410B0 03E00008 */  jr        $ra
/* C6F3E4 802410B4 27BD0028 */   addiu    $sp, $sp, 0x28
