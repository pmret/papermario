.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCamPosition
/* 0F0C54 802CC2A4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F0C58 802CC2A8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0C5C 802CC2AC 0080902D */  daddu $s2, $a0, $zero
/* 0F0C60 802CC2B0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F0C64 802CC2B4 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F0C68 802CC2B8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0C6C 802CC2BC AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0C70 802CC2C0 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0C74 802CC2C4 8E250000 */  lw    $a1, ($s1)
/* 0F0C78 802CC2C8 0C0B1EAF */  jal   get_variable
/* 0F0C7C 802CC2CC 26310004 */   addiu $s1, $s1, 4
/* 0F0C80 802CC2D0 8E250000 */  lw    $a1, ($s1)
/* 0F0C84 802CC2D4 26310004 */  addiu $s1, $s1, 4
/* 0F0C88 802CC2D8 3C03800B */  lui   $v1, 0x800b
/* 0F0C8C 802CC2DC 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0C90 802CC2E0 00028080 */  sll   $s0, $v0, 2
/* 0F0C94 802CC2E4 02028021 */  addu  $s0, $s0, $v0
/* 0F0C98 802CC2E8 00108080 */  sll   $s0, $s0, 2
/* 0F0C9C 802CC2EC 02028023 */  subu  $s0, $s0, $v0
/* 0F0CA0 802CC2F0 001010C0 */  sll   $v0, $s0, 3
/* 0F0CA4 802CC2F4 02028021 */  addu  $s0, $s0, $v0
/* 0F0CA8 802CC2F8 001080C0 */  sll   $s0, $s0, 3
/* 0F0CAC 802CC2FC 02038021 */  addu  $s0, $s0, $v1
/* 0F0CB0 802CC300 8E0604B0 */  lw    $a2, 0x4b0($s0)
/* 0F0CB4 802CC304 8E330000 */  lw    $s3, ($s1)
/* 0F0CB8 802CC308 8E310004 */  lw    $s1, 4($s1)
/* 0F0CBC 802CC30C 0C0B2190 */  jal   set_float_variable
/* 0F0CC0 802CC310 0240202D */   daddu $a0, $s2, $zero
/* 0F0CC4 802CC314 0240202D */  daddu $a0, $s2, $zero
/* 0F0CC8 802CC318 8E0604B4 */  lw    $a2, 0x4b4($s0)
/* 0F0CCC 802CC31C 0C0B2190 */  jal   set_float_variable
/* 0F0CD0 802CC320 0260282D */   daddu $a1, $s3, $zero
/* 0F0CD4 802CC324 0240202D */  daddu $a0, $s2, $zero
/* 0F0CD8 802CC328 8E0604B8 */  lw    $a2, 0x4b8($s0)
/* 0F0CDC 802CC32C 0C0B2190 */  jal   set_float_variable
/* 0F0CE0 802CC330 0220282D */   daddu $a1, $s1, $zero
/* 0F0CE4 802CC334 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F0CE8 802CC338 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F0CEC 802CC33C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0CF0 802CC340 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0CF4 802CC344 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0CF8 802CC348 24020002 */  addiu $v0, $zero, 2
/* 0F0CFC 802CC34C 03E00008 */  jr    $ra
/* 0F0D00 802CC350 27BD0028 */   addiu $sp, $sp, 0x28

