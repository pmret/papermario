.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_exec1
/* EAE1C 802C646C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EAE20 802C6470 AFB00010 */  sw        $s0, 0x10($sp)
/* EAE24 802C6474 0080802D */  daddu     $s0, $a0, $zero
/* EAE28 802C6478 AFBF0014 */  sw        $ra, 0x14($sp)
/* EAE2C 802C647C 8E02000C */  lw        $v0, 0xc($s0)
/* EAE30 802C6480 0C0B1EAF */  jal       get_variable
/* EAE34 802C6484 8C450000 */   lw       $a1, ($v0)
/* EAE38 802C6488 0040202D */  daddu     $a0, $v0, $zero
/* EAE3C 802C648C 92050003 */  lbu       $a1, 3($s0)
/* EAE40 802C6490 92070004 */  lbu       $a3, 4($s0)
/* EAE44 802C6494 0C0B0D74 */  jal       start_script_in_group
/* EAE48 802C6498 0000302D */   daddu    $a2, $zero, $zero
/* EAE4C 802C649C 0000202D */  daddu     $a0, $zero, $zero
/* EAE50 802C64A0 0200282D */  daddu     $a1, $s0, $zero
/* EAE54 802C64A4 8E030148 */  lw        $v1, 0x148($s0)
/* EAE58 802C64A8 0040302D */  daddu     $a2, $v0, $zero
/* EAE5C 802C64AC ACC30148 */  sw        $v1, 0x148($a2)
/* EAE60 802C64B0 8E02014C */  lw        $v0, 0x14c($s0)
/* EAE64 802C64B4 00C0182D */  daddu     $v1, $a2, $zero
/* EAE68 802C64B8 ACC2014C */  sw        $v0, 0x14c($a2)
.L802C64BC:
/* EAE6C 802C64BC 8CA20084 */  lw        $v0, 0x84($a1)
/* EAE70 802C64C0 24A50004 */  addiu     $a1, $a1, 4
/* EAE74 802C64C4 24840001 */  addiu     $a0, $a0, 1
/* EAE78 802C64C8 AC620084 */  sw        $v0, 0x84($v1)
/* EAE7C 802C64CC 28820010 */  slti      $v0, $a0, 0x10
/* EAE80 802C64D0 1440FFFA */  bnez      $v0, .L802C64BC
/* EAE84 802C64D4 24630004 */   addiu    $v1, $v1, 4
/* EAE88 802C64D8 0000202D */  daddu     $a0, $zero, $zero
/* EAE8C 802C64DC 0200282D */  daddu     $a1, $s0, $zero
/* EAE90 802C64E0 00C0182D */  daddu     $v1, $a2, $zero
.L802C64E4:
/* EAE94 802C64E4 8CA200C4 */  lw        $v0, 0xc4($a1)
/* EAE98 802C64E8 24A50004 */  addiu     $a1, $a1, 4
/* EAE9C 802C64EC 24840001 */  addiu     $a0, $a0, 1
/* EAEA0 802C64F0 AC6200C4 */  sw        $v0, 0xc4($v1)
/* EAEA4 802C64F4 28820003 */  slti      $v0, $a0, 3
/* EAEA8 802C64F8 1440FFFA */  bnez      $v0, .L802C64E4
/* EAEAC 802C64FC 24630004 */   addiu    $v1, $v1, 4
/* EAEB0 802C6500 8E02013C */  lw        $v0, 0x13c($s0)
/* EAEB4 802C6504 ACC2013C */  sw        $v0, 0x13c($a2)
/* EAEB8 802C6508 8E030140 */  lw        $v1, 0x140($s0)
/* EAEBC 802C650C ACC30140 */  sw        $v1, 0x140($a2)
/* EAEC0 802C6510 8FBF0014 */  lw        $ra, 0x14($sp)
/* EAEC4 802C6514 8FB00010 */  lw        $s0, 0x10($sp)
/* EAEC8 802C6518 24020002 */  addiu     $v0, $zero, 2
/* EAECC 802C651C 03E00008 */  jr        $ra
/* EAED0 802C6520 27BD0018 */   addiu    $sp, $sp, 0x18
