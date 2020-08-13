.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_call
/* 0EAD98 802C63E8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAD9C 802C63EC AFB10014 */  sw    $s1, 0x14($sp)
/* 0EADA0 802C63F0 0080882D */  daddu $s1, $a0, $zero
/* 0EADA4 802C63F4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EADA8 802C63F8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EADAC 802C63FC 82220005 */  lb    $v0, 5($s1)
/* 0EADB0 802C6400 8E30000C */  lw    $s0, 0xc($s1)
/* 0EADB4 802C6404 10400004 */  beqz  $v0, .L802C6418
/* 0EADB8 802C6408 0000282D */   daddu $a1, $zero, $zero
/* 0EADBC 802C640C 8E260080 */  lw    $a2, 0x80($s1)
/* 0EADC0 802C6410 080B1914 */  j     .L802C6450
/* 0EADC4 802C6414 00000000 */   nop   

.L802C6418:
/* 0EADC8 802C6418 8E050000 */  lw    $a1, ($s0)
/* 0EADCC 802C641C 26100004 */  addiu $s0, $s0, 4
/* 0EADD0 802C6420 0C0B1EAF */  jal   get_variable
/* 0EADD4 802C6424 0220202D */   daddu $a0, $s1, $zero
/* 0EADD8 802C6428 0220202D */  daddu $a0, $s1, $zero
/* 0EADDC 802C642C AC820080 */  sw    $v0, 0x80($a0)
/* 0EADE0 802C6430 0040302D */  daddu $a2, $v0, $zero
/* 0EADE4 802C6434 24050001 */  addiu $a1, $zero, 1
/* 0EADE8 802C6438 90820001 */  lbu   $v0, 1($a0)
/* 0EADEC 802C643C 00A0182D */  daddu $v1, $a1, $zero
/* 0EADF0 802C6440 AC90000C */  sw    $s0, 0xc($a0)
/* 0EADF4 802C6444 A0830005 */  sb    $v1, 5($a0)
/* 0EADF8 802C6448 2442FFFF */  addiu $v0, $v0, -1
/* 0EADFC 802C644C A0820001 */  sb    $v0, 1($a0)
.L802C6450:
/* 0EAE00 802C6450 00C0F809 */  jalr  $a2
/* 0EAE04 802C6454 00000000 */  nop   
/* 0EAE08 802C6458 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EAE0C 802C645C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAE10 802C6460 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAE14 802C6464 03E00008 */  jr    $ra
/* 0EAE18 802C6468 27BD0020 */   addiu $sp, $sp, 0x20

