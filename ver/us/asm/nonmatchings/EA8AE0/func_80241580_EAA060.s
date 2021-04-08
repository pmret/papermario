.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241580_EAA060
/* EAA060 80241580 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EAA064 80241584 AFB10014 */  sw        $s1, 0x14($sp)
/* EAA068 80241588 0080882D */  daddu     $s1, $a0, $zero
/* EAA06C 8024158C AFBF0018 */  sw        $ra, 0x18($sp)
/* EAA070 80241590 AFB00010 */  sw        $s0, 0x10($sp)
/* EAA074 80241594 8E30000C */  lw        $s0, 0xc($s1)
/* EAA078 80241598 8E050000 */  lw        $a1, ($s0)
/* EAA07C 8024159C 0C0B53A3 */  jal       dead_get_variable
/* EAA080 802415A0 26100004 */   addiu    $s0, $s0, 4
/* EAA084 802415A4 0C00F94D */  jal       func_8003E534
/* EAA088 802415A8 0040202D */   daddu    $a0, $v0, $zero
/* EAA08C 802415AC 10400005 */  beqz      $v0, .L802415C4
/* EAA090 802415B0 00000000 */   nop
/* EAA094 802415B4 8E050000 */  lw        $a1, ($s0)
/* EAA098 802415B8 844600A8 */  lh        $a2, 0xa8($v0)
/* EAA09C 802415BC 0C0B551A */  jal       dead_set_variable
/* EAA0A0 802415C0 0220202D */   daddu    $a0, $s1, $zero
.L802415C4:
/* EAA0A4 802415C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* EAA0A8 802415C8 8FB10014 */  lw        $s1, 0x14($sp)
/* EAA0AC 802415CC 8FB00010 */  lw        $s0, 0x10($sp)
/* EAA0B0 802415D0 24020002 */  addiu     $v0, $zero, 2
/* EAA0B4 802415D4 03E00008 */  jr        $ra
/* EAA0B8 802415D8 27BD0020 */   addiu    $sp, $sp, 0x20
