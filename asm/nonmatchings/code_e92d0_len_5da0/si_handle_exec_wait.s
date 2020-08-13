.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_exec_wait
/* 0EAFAC 802C65FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EAFB0 802C6600 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAFB4 802C6604 0080802D */  daddu $s0, $a0, $zero
/* 0EAFB8 802C6608 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EAFBC 802C660C 8E02000C */  lw    $v0, 0xc($s0)
/* 0EAFC0 802C6610 0C0B1EAF */  jal   get_variable
/* 0EAFC4 802C6614 8C450000 */   lw    $a1, ($v0)
/* 0EAFC8 802C6618 0200202D */  daddu $a0, $s0, $zero
/* 0EAFCC 802C661C 0040282D */  daddu $a1, $v0, $zero
/* 0EAFD0 802C6620 0C0B0DF2 */  jal   start_child_script
/* 0EAFD4 802C6624 0000302D */   daddu $a2, $zero, $zero
/* 0EAFD8 802C6628 A2000002 */  sb    $zero, 2($s0)
/* 0EAFDC 802C662C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EAFE0 802C6630 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAFE4 802C6634 240200FF */  addiu $v0, $zero, 0xff
/* 0EAFE8 802C6638 03E00008 */  jr    $ra
/* 0EAFEC 802C663C 27BD0018 */   addiu $sp, $sp, 0x18

