.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_call
/* EAD98 802C63E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EAD9C 802C63EC AFB10014 */  sw        $s1, 0x14($sp)
/* EADA0 802C63F0 0080882D */  daddu     $s1, $a0, $zero
/* EADA4 802C63F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* EADA8 802C63F8 AFB00010 */  sw        $s0, 0x10($sp)
/* EADAC 802C63FC 82220005 */  lb        $v0, 5($s1)
/* EADB0 802C6400 8E30000C */  lw        $s0, 0xc($s1)
/* EADB4 802C6404 10400004 */  beqz      $v0, .L802C6418
/* EADB8 802C6408 0000282D */   daddu    $a1, $zero, $zero
/* EADBC 802C640C 8E260080 */  lw        $a2, 0x80($s1)
/* EADC0 802C6410 080B1914 */  j         .L802C6450
/* EADC4 802C6414 00000000 */   nop      
.L802C6418:
/* EADC8 802C6418 8E050000 */  lw        $a1, ($s0)
/* EADCC 802C641C 26100004 */  addiu     $s0, $s0, 4
/* EADD0 802C6420 0C0B1EAF */  jal       get_variable
/* EADD4 802C6424 0220202D */   daddu    $a0, $s1, $zero
/* EADD8 802C6428 0220202D */  daddu     $a0, $s1, $zero
/* EADDC 802C642C AC820080 */  sw        $v0, 0x80($a0)
/* EADE0 802C6430 0040302D */  daddu     $a2, $v0, $zero
/* EADE4 802C6434 24050001 */  addiu     $a1, $zero, 1
/* EADE8 802C6438 90820001 */  lbu       $v0, 1($a0)
/* EADEC 802C643C 00A0182D */  daddu     $v1, $a1, $zero
/* EADF0 802C6440 AC90000C */  sw        $s0, 0xc($a0)
/* EADF4 802C6444 A0830005 */  sb        $v1, 5($a0)
/* EADF8 802C6448 2442FFFF */  addiu     $v0, $v0, -1
/* EADFC 802C644C A0820001 */  sb        $v0, 1($a0)
.L802C6450:
/* EAE00 802C6450 00C0F809 */  jalr      $a2
/* EAE04 802C6454 00000000 */   nop      
/* EAE08 802C6458 8FBF0018 */  lw        $ra, 0x18($sp)
/* EAE0C 802C645C 8FB10014 */  lw        $s1, 0x14($sp)
/* EAE10 802C6460 8FB00010 */  lw        $s0, 0x10($sp)
/* EAE14 802C6464 03E00008 */  jr        $ra
/* EAE18 802C6468 27BD0020 */   addiu    $sp, $sp, 0x20
