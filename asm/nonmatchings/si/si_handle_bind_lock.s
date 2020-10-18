.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_bind_lock
/* EB504 802C6B54 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EB508 802C6B58 AFB10034 */  sw        $s1, 0x34($sp)
/* EB50C 802C6B5C 0080882D */  daddu     $s1, $a0, $zero
/* EB510 802C6B60 AFBF004C */  sw        $ra, 0x4c($sp)
/* EB514 802C6B64 AFB60048 */  sw        $s6, 0x48($sp)
/* EB518 802C6B68 AFB50044 */  sw        $s5, 0x44($sp)
/* EB51C 802C6B6C AFB40040 */  sw        $s4, 0x40($sp)
/* EB520 802C6B70 AFB3003C */  sw        $s3, 0x3c($sp)
/* EB524 802C6B74 AFB20038 */  sw        $s2, 0x38($sp)
/* EB528 802C6B78 AFB00030 */  sw        $s0, 0x30($sp)
/* EB52C 802C6B7C 8E30000C */  lw        $s0, 0xc($s1)
/* EB530 802C6B80 8E050000 */  lw        $a1, ($s0)
/* EB534 802C6B84 0C0B1EAF */  jal       get_variable
/* EB538 802C6B88 26100004 */   addiu    $s0, $s0, 4
/* EB53C 802C6B8C 8E120000 */  lw        $s2, ($s0)
/* EB540 802C6B90 26100004 */  addiu     $s0, $s0, 4
/* EB544 802C6B94 8E130000 */  lw        $s3, ($s0)
/* EB548 802C6B98 26100004 */  addiu     $s0, $s0, 4
/* EB54C 802C6B9C 8E050000 */  lw        $a1, ($s0)
/* EB550 802C6BA0 26100004 */  addiu     $s0, $s0, 4
/* EB554 802C6BA4 0220202D */  daddu     $a0, $s1, $zero
/* EB558 802C6BA8 0C0B1EAF */  jal       get_variable
/* EB55C 802C6BAC 0040B02D */   daddu    $s6, $v0, $zero
/* EB560 802C6BB0 0220202D */  daddu     $a0, $s1, $zero
/* EB564 802C6BB4 0260282D */  daddu     $a1, $s3, $zero
/* EB568 802C6BB8 3C030100 */  lui       $v1, 0x100
/* EB56C 802C6BBC 02439025 */  or        $s2, $s2, $v1
/* EB570 802C6BC0 8E140000 */  lw        $s4, ($s0)
/* EB574 802C6BC4 8E150004 */  lw        $s5, 4($s0)
/* EB578 802C6BC8 0040802D */  daddu     $s0, $v0, $zero
/* EB57C 802C6BCC 0C0B1EAF */  jal       get_variable
/* EB580 802C6BD0 AFB20010 */   sw       $s2, 0x10($sp)
/* EB584 802C6BD4 0220202D */  daddu     $a0, $s1, $zero
/* EB588 802C6BD8 0260282D */  daddu     $a1, $s3, $zero
/* EB58C 802C6BDC 0C0B1F6A */  jal       get_variable_index
/* EB590 802C6BE0 AFA20018 */   sw       $v0, 0x18($sp)
/* EB594 802C6BE4 27A40010 */  addiu     $a0, $sp, 0x10
/* EB598 802C6BE8 A7A20014 */  sh        $v0, 0x14($sp)
/* EB59C 802C6BEC 3C02802C */  lui       $v0, %hi(si_standard_trigger_executor)
/* EB5A0 802C6BF0 24426AD0 */  addiu     $v0, $v0, %lo(si_standard_trigger_executor)
/* EB5A4 802C6BF4 AFB0002C */  sw        $s0, 0x2c($sp)
/* EB5A8 802C6BF8 AFA2001C */  sw        $v0, 0x1c($sp)
/* EB5AC 802C6BFC AFB40024 */  sw        $s4, 0x24($sp)
/* EB5B0 802C6C00 0C0515DB */  jal       create_trigger
/* EB5B4 802C6C04 AFB50028 */   sw       $s5, 0x28($sp)
/* EB5B8 802C6C08 0040802D */  daddu     $s0, $v0, $zero
/* EB5BC 802C6C0C AE160010 */  sw        $s6, 0x10($s0)
/* EB5C0 802C6C10 AE000014 */  sw        $zero, 0x14($s0)
/* EB5C4 802C6C14 92220003 */  lbu       $v0, 3($s1)
/* EB5C8 802C6C18 AE020018 */  sw        $v0, 0x18($s0)
/* EB5CC 802C6C1C 8E250084 */  lw        $a1, 0x84($s1)
/* EB5D0 802C6C20 0C0B1EAF */  jal       get_variable
/* EB5D4 802C6C24 0220202D */   daddu    $a0, $s1, $zero
/* EB5D8 802C6C28 AE02001C */  sw        $v0, 0x1c($s0)
/* EB5DC 802C6C2C 8E250088 */  lw        $a1, 0x88($s1)
/* EB5E0 802C6C30 0C0B1EAF */  jal       get_variable
/* EB5E4 802C6C34 0220202D */   daddu    $a0, $s1, $zero
/* EB5E8 802C6C38 AE020020 */  sw        $v0, 0x20($s0)
/* EB5EC 802C6C3C 8E25008C */  lw        $a1, 0x8c($s1)
/* EB5F0 802C6C40 0C0B1EAF */  jal       get_variable
/* EB5F4 802C6C44 0220202D */   daddu    $a0, $s1, $zero
/* EB5F8 802C6C48 AE020024 */  sw        $v0, 0x24($s0)
/* EB5FC 802C6C4C 8FBF004C */  lw        $ra, 0x4c($sp)
/* EB600 802C6C50 8FB60048 */  lw        $s6, 0x48($sp)
/* EB604 802C6C54 8FB50044 */  lw        $s5, 0x44($sp)
/* EB608 802C6C58 8FB40040 */  lw        $s4, 0x40($sp)
/* EB60C 802C6C5C 8FB3003C */  lw        $s3, 0x3c($sp)
/* EB610 802C6C60 8FB20038 */  lw        $s2, 0x38($sp)
/* EB614 802C6C64 8FB10034 */  lw        $s1, 0x34($sp)
/* EB618 802C6C68 8FB00030 */  lw        $s0, 0x30($sp)
/* EB61C 802C6C6C 24020002 */  addiu     $v0, $zero, 2
/* EB620 802C6C70 03E00008 */  jr        $ra
/* EB624 802C6C74 27BD0050 */   addiu    $sp, $sp, 0x50
