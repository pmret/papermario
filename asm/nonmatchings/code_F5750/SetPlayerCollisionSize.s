.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPlayerCollisionSize
/* F5960 802D0FB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F5964 802D0FB4 AFB10014 */  sw        $s1, 0x14($sp)
/* F5968 802D0FB8 0080882D */  daddu     $s1, $a0, $zero
/* F596C 802D0FBC AFBF0018 */  sw        $ra, 0x18($sp)
/* F5970 802D0FC0 AFB00010 */  sw        $s0, 0x10($sp)
/* F5974 802D0FC4 8E30000C */  lw        $s0, 0xc($s1)
/* F5978 802D0FC8 8E050000 */  lw        $a1, ($s0)
/* F597C 802D0FCC 0C0B1EAF */  jal       get_variable
/* F5980 802D0FD0 26100004 */   addiu    $s0, $s0, 4
/* F5984 802D0FD4 0220202D */  daddu     $a0, $s1, $zero
/* F5988 802D0FD8 8E050000 */  lw        $a1, ($s0)
/* F598C 802D0FDC 0C0B1EAF */  jal       get_variable
/* F5990 802D0FE0 0040802D */   daddu    $s0, $v0, $zero
/* F5994 802D0FE4 3C03802E */  lui       $v1, %hi(gPlayerNpcPtr)
/* F5998 802D0FE8 8C639D20 */  lw        $v1, %lo(gPlayerNpcPtr)($v1)
/* F599C 802D0FEC 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* F59A0 802D0FF0 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* F59A4 802D0FF4 A47000A8 */  sh        $s0, 0xa8($v1)
/* F59A8 802D0FF8 A46200A6 */  sh        $v0, 0xa6($v1)
/* F59AC 802D0FFC 0200102D */  daddu     $v0, $s0, $zero
/* F59B0 802D1000 A48200B0 */  sh        $v0, 0xb0($a0)
/* F59B4 802D1004 946300A6 */  lhu       $v1, 0xa6($v1)
/* F59B8 802D1008 A48300B2 */  sh        $v1, 0xb2($a0)
/* F59BC 802D100C 8FBF0018 */  lw        $ra, 0x18($sp)
/* F59C0 802D1010 8FB10014 */  lw        $s1, 0x14($sp)
/* F59C4 802D1014 8FB00010 */  lw        $s0, 0x10($sp)
/* F59C8 802D1018 24020002 */  addiu     $v0, $zero, 2
/* F59CC 802D101C 03E00008 */  jr        $ra
/* F59D0 802D1020 27BD0020 */   addiu    $sp, $sp, 0x20
