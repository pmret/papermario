.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel clear_script_flags
/* 0E9230 802C4880 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E9234 802C4884 AFB10014 */  sw    $s1, 0x14($sp)
/* 0E9238 802C4888 0080882D */  daddu $s1, $a0, $zero
/* 0E923C 802C488C AFB20018 */  sw    $s2, 0x18($sp)
/* 0E9240 802C4890 00A0902D */  daddu $s2, $a1, $zero
/* 0E9244 802C4894 00121827 */  nor   $v1, $zero, $s2
/* 0E9248 802C4898 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0E924C 802C489C AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9250 802C48A0 92220000 */  lbu   $v0, ($s1)
/* 0E9254 802C48A4 8E240068 */  lw    $a0, 0x68($s1)
/* 0E9258 802C48A8 00431024 */  and   $v0, $v0, $v1
/* 0E925C 802C48AC 10800003 */  beqz  $a0, .L802C48BC
/* 0E9260 802C48B0 A2220000 */   sb    $v0, ($s1)
/* 0E9264 802C48B4 0C0B1220 */  jal   clear_script_flags
/* 0E9268 802C48B8 00000000 */   nop   
.L802C48BC:
/* 0E926C 802C48BC 0000802D */  daddu $s0, $zero, $zero
.L802C48C0:
/* 0E9270 802C48C0 3C03802E */  lui   $v1, 0x802e
/* 0E9274 802C48C4 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E9278 802C48C8 00101080 */  sll   $v0, $s0, 2
/* 0E927C 802C48CC 00431021 */  addu  $v0, $v0, $v1
/* 0E9280 802C48D0 8C440000 */  lw    $a0, ($v0)
/* 0E9284 802C48D4 50800007 */  beql  $a0, $zero, .L802C48F4
/* 0E9288 802C48D8 26100001 */   addiu $s0, $s0, 1
/* 0E928C 802C48DC 8C82006C */  lw    $v0, 0x6c($a0)
/* 0E9290 802C48E0 54510004 */  bnel  $v0, $s1, .L802C48F4
/* 0E9294 802C48E4 26100001 */   addiu $s0, $s0, 1
/* 0E9298 802C48E8 0C0B1220 */  jal   clear_script_flags
/* 0E929C 802C48EC 0240282D */   daddu $a1, $s2, $zero
/* 0E92A0 802C48F0 26100001 */  addiu $s0, $s0, 1
.L802C48F4:
/* 0E92A4 802C48F4 2A020080 */  slti  $v0, $s0, 0x80
/* 0E92A8 802C48F8 1440FFF1 */  bnez  $v0, .L802C48C0
/* 0E92AC 802C48FC 00000000 */   nop   
/* 0E92B0 802C4900 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0E92B4 802C4904 8FB20018 */  lw    $s2, 0x18($sp)
/* 0E92B8 802C4908 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E92BC 802C490C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E92C0 802C4910 03E00008 */  jr    $ra
/* 0E92C4 802C4914 27BD0020 */   addiu $sp, $sp, 0x20

/* 0E92C8 802C4918 00000000 */  nop   
/* 0E92CC 802C491C 00000000 */  nop   


