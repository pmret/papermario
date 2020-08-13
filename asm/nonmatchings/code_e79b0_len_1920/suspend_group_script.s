.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel suspend_group_script
/* 0E8C88 802C42D8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E8C8C 802C42DC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E8C90 802C42E0 0080882D */  daddu $s1, $a0, $zero
/* 0E8C94 802C42E4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E8C98 802C42E8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0E8C9C 802C42EC AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8CA0 802C42F0 8E240068 */  lw    $a0, 0x68($s1)
/* 0E8CA4 802C42F4 10800003 */  beqz  $a0, .L802C4304
/* 0E8CA8 802C42F8 00A0902D */   daddu $s2, $a1, $zero
/* 0E8CAC 802C42FC 0C0B10B6 */  jal   suspend_group_script
/* 0E8CB0 802C4300 00000000 */   nop   
.L802C4304:
/* 0E8CB4 802C4304 0000802D */  daddu $s0, $zero, $zero
.L802C4308:
/* 0E8CB8 802C4308 3C03802E */  lui   $v1, 0x802e
/* 0E8CBC 802C430C 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8CC0 802C4310 00101080 */  sll   $v0, $s0, 2
/* 0E8CC4 802C4314 00431021 */  addu  $v0, $v0, $v1
/* 0E8CC8 802C4318 8C440000 */  lw    $a0, ($v0)
/* 0E8CCC 802C431C 50800007 */  beql  $a0, $zero, .L802C433C
/* 0E8CD0 802C4320 26100001 */   addiu $s0, $s0, 1
/* 0E8CD4 802C4324 8C82006C */  lw    $v0, 0x6c($a0)
/* 0E8CD8 802C4328 54510004 */  bnel  $v0, $s1, .L802C433C
/* 0E8CDC 802C432C 26100001 */   addiu $s0, $s0, 1
/* 0E8CE0 802C4330 0C0B10B6 */  jal   suspend_group_script
/* 0E8CE4 802C4334 0240282D */   daddu $a1, $s2, $zero
/* 0E8CE8 802C4338 26100001 */  addiu $s0, $s0, 1
.L802C433C:
/* 0E8CEC 802C433C 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8CF0 802C4340 1440FFF1 */  bnez  $v0, .L802C4308
/* 0E8CF4 802C4344 00000000 */   nop   
/* 0E8CF8 802C4348 92220004 */  lbu   $v0, 4($s1)
/* 0E8CFC 802C434C 00521024 */  and   $v0, $v0, $s2
/* 0E8D00 802C4350 10400004 */  beqz  $v0, .L802C4364
/* 0E8D04 802C4354 00000000 */   nop   
/* 0E8D08 802C4358 92220000 */  lbu   $v0, ($s1)
/* 0E8D0C 802C435C 34420002 */  ori   $v0, $v0, 2
/* 0E8D10 802C4360 A2220000 */  sb    $v0, ($s1)
.L802C4364:
/* 0E8D14 802C4364 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E8D18 802C4368 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E8D1C 802C436C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E8D20 802C4370 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8D24 802C4374 03E00008 */  jr    $ra
/* 0E8D28 802C4378 27BD0020 */   addiu $sp, $sp, 0x20

