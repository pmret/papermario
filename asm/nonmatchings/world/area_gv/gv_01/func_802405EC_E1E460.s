.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_E1EA4C
/* E1EA4C 802405EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1EA50 802405F0 AFB00010 */  sw        $s0, 0x10($sp)
/* E1EA54 802405F4 0080802D */  daddu     $s0, $a0, $zero
/* E1EA58 802405F8 10A00008 */  beqz      $a1, .L8024061C
/* E1EA5C 802405FC AFBF0014 */   sw       $ra, 0x14($sp)
/* E1EA60 80240600 3C013F80 */  lui       $at, 0x3f80
/* E1EA64 80240604 44816000 */  mtc1      $at, $f12
/* E1EA68 80240608 0C00AFB7 */  jal       set_curtain_scale_goal
/* E1EA6C 8024060C AE000070 */   sw       $zero, 0x70($s0)
/* E1EA70 80240610 44806000 */  mtc1      $zero, $f12
/* E1EA74 80240614 0C00AFC9 */  jal       set_curtain_fade
/* E1EA78 80240618 00000000 */   nop      
.L8024061C:
/* E1EA7C 8024061C 8E020070 */  lw        $v0, 0x70($s0)
/* E1EA80 80240620 24420005 */  addiu     $v0, $v0, 5
/* E1EA84 80240624 AE020070 */  sw        $v0, 0x70($s0)
/* E1EA88 80240628 28420100 */  slti      $v0, $v0, 0x100
/* E1EA8C 8024062C 14400003 */  bnez      $v0, .L8024063C
/* E1EA90 80240630 24040001 */   addiu    $a0, $zero, 1
/* E1EA94 80240634 240200FF */  addiu     $v0, $zero, 0xff
/* E1EA98 80240638 AE020070 */  sw        $v0, 0x70($s0)
.L8024063C:
/* E1EA9C 8024063C 240500D0 */  addiu     $a1, $zero, 0xd0
/* E1EAA0 80240640 00A0302D */  daddu     $a2, $a1, $zero
/* E1EAA4 80240644 0C04DF84 */  jal       func_80137E10
/* E1EAA8 80240648 00A0382D */   daddu    $a3, $a1, $zero
/* E1EAAC 8024064C C6000070 */  lwc1      $f0, 0x70($s0)
/* E1EAB0 80240650 46800020 */  cvt.s.w   $f0, $f0
/* E1EAB4 80240654 44050000 */  mfc1      $a1, $f0
/* E1EAB8 80240658 0C04DF69 */  jal       func_80137DA4
/* E1EABC 8024065C 0000202D */   daddu    $a0, $zero, $zero
/* E1EAC0 80240660 24040001 */  addiu     $a0, $zero, 1
/* E1EAC4 80240664 0C04E035 */  jal       func_801380D4
/* E1EAC8 80240668 0000282D */   daddu    $a1, $zero, $zero
/* E1EACC 8024066C 8E020070 */  lw        $v0, 0x70($s0)
/* E1EAD0 80240670 8FBF0014 */  lw        $ra, 0x14($sp)
/* E1EAD4 80240674 8FB00010 */  lw        $s0, 0x10($sp)
/* E1EAD8 80240678 384200FF */  xori      $v0, $v0, 0xff
/* E1EADC 8024067C 2C420001 */  sltiu     $v0, $v0, 1
/* E1EAE0 80240680 03E00008 */  jr        $ra
/* E1EAE4 80240684 27BD0018 */   addiu    $sp, $sp, 0x18
