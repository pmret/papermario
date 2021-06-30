.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_child_thread
/* EB71C 802C6D6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB720 802C6D70 AFB00010 */  sw        $s0, 0x10($sp)
/* EB724 802C6D74 0080802D */  daddu     $s0, $a0, $zero
/* EB728 802C6D78 AFBF0014 */  sw        $ra, 0x14($sp)
/* EB72C 802C6D7C 8E050008 */  lw        $a1, 8($s0)
/* EB730 802C6D80 24060059 */  addiu     $a2, $zero, 0x59
/* EB734 802C6D84 00A0202D */  daddu     $a0, $a1, $zero
.L802C6D88:
/* EB738 802C6D88 8C830000 */  lw        $v1, ($a0)
/* EB73C 802C6D8C 24840004 */  addiu     $a0, $a0, 4
/* EB740 802C6D90 8C820000 */  lw        $v0, ($a0)
/* EB744 802C6D94 24840004 */  addiu     $a0, $a0, 4
/* EB748 802C6D98 00021080 */  sll       $v0, $v0, 2
/* EB74C 802C6D9C 1466FFFA */  bne       $v1, $a2, .L802C6D88
/* EB750 802C6DA0 00822021 */   addu     $a0, $a0, $v0
/* EB754 802C6DA4 AE040008 */  sw        $a0, 8($s0)
/* EB758 802C6DA8 0200202D */  daddu     $a0, $s0, $zero
/* EB75C 802C6DAC 0C0B0E7E */  jal       func_802C39F8
/* EB760 802C6DB0 24060060 */   addiu    $a2, $zero, 0x60
/* EB764 802C6DB4 8E040148 */  lw        $a0, 0x148($s0)
/* EB768 802C6DB8 0040182D */  daddu     $v1, $v0, $zero
/* EB76C 802C6DBC AC640148 */  sw        $a0, 0x148($v1)
/* EB770 802C6DC0 8E02014C */  lw        $v0, 0x14c($s0)
/* EB774 802C6DC4 AC62014C */  sw        $v0, 0x14c($v1)
/* EB778 802C6DC8 92020004 */  lbu       $v0, 4($s0)
/* EB77C 802C6DCC A0620004 */  sb        $v0, 4($v1)
/* EB780 802C6DD0 8E02013C */  lw        $v0, 0x13c($s0)
/* EB784 802C6DD4 AC62013C */  sw        $v0, 0x13c($v1)
/* EB788 802C6DD8 8E040140 */  lw        $a0, 0x140($s0)
/* EB78C 802C6DDC AC640140 */  sw        $a0, 0x140($v1)
/* EB790 802C6DE0 8FBF0014 */  lw        $ra, 0x14($sp)
/* EB794 802C6DE4 8FB00010 */  lw        $s0, 0x10($sp)
/* EB798 802C6DE8 24020002 */  addiu     $v0, $zero, 2
/* EB79C 802C6DEC 03E00008 */  jr        $ra
/* EB7A0 802C6DF0 27BD0018 */   addiu    $sp, $sp, 0x18
