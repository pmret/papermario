.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_exec2
/* 0EAED4 802C6524 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAED8 802C6528 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EAEDC 802C652C 0080882D */  daddu $s1, $a0, $zero
/* 0EAEE0 802C6530 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EAEE4 802C6534 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAEE8 802C6538 8E30000C */  lw    $s0, 0xc($s1)
/* 0EAEEC 802C653C 8E050000 */  lw    $a1, ($s0)
/* 0EAEF0 802C6540 0C0B1EAF */  jal   get_variable
/* 0EAEF4 802C6544 26100004 */   addiu $s0, $s0, 4
/* 0EAEF8 802C6548 0040202D */  daddu $a0, $v0, $zero
/* 0EAEFC 802C654C 92250003 */  lbu   $a1, 3($s1)
/* 0EAF00 802C6550 92270004 */  lbu   $a3, 4($s1)
/* 0EAF04 802C6554 8E100000 */  lw    $s0, ($s0)
/* 0EAF08 802C6558 0C0B0D74 */  jal   start_script_in_group
/* 0EAF0C 802C655C 0000302D */   daddu $a2, $zero, $zero
/* 0EAF10 802C6560 0000202D */  daddu $a0, $zero, $zero
/* 0EAF14 802C6564 0220282D */  daddu $a1, $s1, $zero
/* 0EAF18 802C6568 8E230148 */  lw    $v1, 0x148($s1)
/* 0EAF1C 802C656C 0040382D */  daddu $a3, $v0, $zero
/* 0EAF20 802C6570 ACE30148 */  sw    $v1, 0x148($a3)
/* 0EAF24 802C6574 8E22014C */  lw    $v0, 0x14c($s1)
/* 0EAF28 802C6578 00E0182D */  daddu $v1, $a3, $zero
/* 0EAF2C 802C657C ACE2014C */  sw    $v0, 0x14c($a3)
.L802C6580:
/* 0EAF30 802C6580 8CA20084 */  lw    $v0, 0x84($a1)
/* 0EAF34 802C6584 24A50004 */  addiu $a1, $a1, 4
/* 0EAF38 802C6588 24840001 */  addiu $a0, $a0, 1
/* 0EAF3C 802C658C AC620084 */  sw    $v0, 0x84($v1)
/* 0EAF40 802C6590 28820010 */  slti  $v0, $a0, 0x10
/* 0EAF44 802C6594 1440FFFA */  bnez  $v0, .L802C6580
/* 0EAF48 802C6598 24630004 */   addiu $v1, $v1, 4
/* 0EAF4C 802C659C 0000202D */  daddu $a0, $zero, $zero
/* 0EAF50 802C65A0 0220282D */  daddu $a1, $s1, $zero
/* 0EAF54 802C65A4 00E0182D */  daddu $v1, $a3, $zero
.L802C65A8:
/* 0EAF58 802C65A8 8CA200C4 */  lw    $v0, 0xc4($a1)
/* 0EAF5C 802C65AC 24A50004 */  addiu $a1, $a1, 4
/* 0EAF60 802C65B0 24840001 */  addiu $a0, $a0, 1
/* 0EAF64 802C65B4 AC6200C4 */  sw    $v0, 0xc4($v1)
/* 0EAF68 802C65B8 28820003 */  slti  $v0, $a0, 3
/* 0EAF6C 802C65BC 1440FFFA */  bnez  $v0, .L802C65A8
/* 0EAF70 802C65C0 24630004 */   addiu $v1, $v1, 4
/* 0EAF74 802C65C4 8CE60144 */  lw    $a2, 0x144($a3)
/* 0EAF78 802C65C8 8E22013C */  lw    $v0, 0x13c($s1)
/* 0EAF7C 802C65CC 0220202D */  daddu $a0, $s1, $zero
/* 0EAF80 802C65D0 ACE2013C */  sw    $v0, 0x13c($a3)
/* 0EAF84 802C65D4 8C820140 */  lw    $v0, 0x140($a0)
/* 0EAF88 802C65D8 0200282D */  daddu $a1, $s0, $zero
/* 0EAF8C 802C65DC 0C0B2026 */  jal   set_variable
/* 0EAF90 802C65E0 ACE20140 */   sw    $v0, 0x140($a3)
/* 0EAF94 802C65E4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EAF98 802C65E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAF9C 802C65EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAFA0 802C65F0 24020002 */  addiu $v0, $zero, 2
/* 0EAFA4 802C65F4 03E00008 */  jr    $ra
/* 0EAFA8 802C65F8 27BD0020 */   addiu $sp, $sp, 0x20

