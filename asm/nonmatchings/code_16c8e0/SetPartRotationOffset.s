.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPartRotationOffset
/* 19B020 8026C740 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19B024 8026C744 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B028 8026C748 0080882D */  daddu $s1, $a0, $zero
/* 19B02C 8026C74C AFBF0024 */  sw    $ra, 0x24($sp)
/* 19B030 8026C750 AFB40020 */  sw    $s4, 0x20($sp)
/* 19B034 8026C754 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19B038 8026C758 AFB20018 */  sw    $s2, 0x18($sp)
/* 19B03C 8026C75C AFB00010 */  sw    $s0, 0x10($sp)
/* 19B040 8026C760 8E30000C */  lw    $s0, 0xc($s1)
/* 19B044 8026C764 8E050000 */  lw    $a1, ($s0)
/* 19B048 8026C768 0C0B1EAF */  jal   get_variable
/* 19B04C 8026C76C 26100004 */   addiu $s0, $s0, 4
/* 19B050 8026C770 0040982D */  daddu $s3, $v0, $zero
/* 19B054 8026C774 8E050000 */  lw    $a1, ($s0)
/* 19B058 8026C778 26100004 */  addiu $s0, $s0, 4
/* 19B05C 8026C77C 0C0B1EAF */  jal   get_variable
/* 19B060 8026C780 0220202D */   daddu $a0, $s1, $zero
/* 19B064 8026C784 0040A02D */  daddu $s4, $v0, $zero
/* 19B068 8026C788 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B06C 8026C78C 16620002 */  bne   $s3, $v0, .L8026C798
/* 19B070 8026C790 00000000 */   nop   
/* 19B074 8026C794 8E330148 */  lw    $s3, 0x148($s1)
.L8026C798:
/* 19B078 8026C798 8E050000 */  lw    $a1, ($s0)
/* 19B07C 8026C79C 26100004 */  addiu $s0, $s0, 4
/* 19B080 8026C7A0 0C0B210B */  jal   get_float_variable
/* 19B084 8026C7A4 0220202D */   daddu $a0, $s1, $zero
/* 19B088 8026C7A8 8E050000 */  lw    $a1, ($s0)
/* 19B08C 8026C7AC 26100004 */  addiu $s0, $s0, 4
/* 19B090 8026C7B0 4600008D */  trunc.w.s $f2, $f0
/* 19B094 8026C7B4 44121000 */  mfc1  $s2, $f2
/* 19B098 8026C7B8 0C0B210B */  jal   get_float_variable
/* 19B09C 8026C7BC 0220202D */   daddu $a0, $s1, $zero
/* 19B0A0 8026C7C0 0220202D */  daddu $a0, $s1, $zero
/* 19B0A4 8026C7C4 8E050000 */  lw    $a1, ($s0)
/* 19B0A8 8026C7C8 4600008D */  trunc.w.s $f2, $f0
/* 19B0AC 8026C7CC 44111000 */  mfc1  $s1, $f2
/* 19B0B0 8026C7D0 0C0B210B */  jal   get_float_variable
/* 19B0B4 8026C7D4 00000000 */   nop   
/* 19B0B8 8026C7D8 4600008D */  trunc.w.s $f2, $f0
/* 19B0BC 8026C7DC 44101000 */  mfc1  $s0, $f2
/* 19B0C0 8026C7E0 0C09A75B */  jal   get_actor
/* 19B0C4 8026C7E4 0260202D */   daddu $a0, $s3, $zero
/* 19B0C8 8026C7E8 0040202D */  daddu $a0, $v0, $zero
/* 19B0CC 8026C7EC 0C099117 */  jal   get_actor_part
/* 19B0D0 8026C7F0 0280282D */   daddu $a1, $s4, $zero
/* 19B0D4 8026C7F4 0040182D */  daddu $v1, $v0, $zero
/* 19B0D8 8026C7F8 A4720044 */  sh    $s2, 0x44($v1)
/* 19B0DC 8026C7FC A4710046 */  sh    $s1, 0x46($v1)
/* 19B0E0 8026C800 A4700048 */  sh    $s0, 0x48($v1)
/* 19B0E4 8026C804 8FBF0024 */  lw    $ra, 0x24($sp)
/* 19B0E8 8026C808 8FB40020 */  lw    $s4, 0x20($sp)
/* 19B0EC 8026C80C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19B0F0 8026C810 8FB20018 */  lw    $s2, 0x18($sp)
/* 19B0F4 8026C814 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B0F8 8026C818 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B0FC 8026C81C 24020002 */  addiu $v0, $zero, 2
/* 19B100 8026C820 03E00008 */  jr    $ra
/* 19B104 8026C824 27BD0028 */   addiu $sp, $sp, 0x28

