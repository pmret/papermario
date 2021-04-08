.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242034_EE85E4
/* EE85E4 80242034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE85E8 80242038 AFB10014 */  sw        $s1, 0x14($sp)
/* EE85EC 8024203C 0080882D */  daddu     $s1, $a0, $zero
/* EE85F0 80242040 AFBF0018 */  sw        $ra, 0x18($sp)
/* EE85F4 80242044 AFB00010 */  sw        $s0, 0x10($sp)
/* EE85F8 80242048 8E30000C */  lw        $s0, 0xc($s1)
/* EE85FC 8024204C 8E050000 */  lw        $a1, ($s0)
/* EE8600 80242050 0C0B53A3 */  jal       dead_get_variable
/* EE8604 80242054 26100004 */   addiu    $s0, $s0, 4
/* EE8608 80242058 0C00F94D */  jal       func_8003E534
/* EE860C 8024205C 0040202D */   daddu    $a0, $v0, $zero
/* EE8610 80242060 10400005 */  beqz      $v0, .L80242078
/* EE8614 80242064 00000000 */   nop
/* EE8618 80242068 8E050000 */  lw        $a1, ($s0)
/* EE861C 8024206C 844600A8 */  lh        $a2, 0xa8($v0)
/* EE8620 80242070 0C0B551A */  jal       dead_set_variable
/* EE8624 80242074 0220202D */   daddu    $a0, $s1, $zero
.L80242078:
/* EE8628 80242078 8FBF0018 */  lw        $ra, 0x18($sp)
/* EE862C 8024207C 8FB10014 */  lw        $s1, 0x14($sp)
/* EE8630 80242080 8FB00010 */  lw        $s0, 0x10($sp)
/* EE8634 80242084 24020002 */  addiu     $v0, $zero, 2
/* EE8638 80242088 03E00008 */  jr        $ra
/* EE863C 8024208C 27BD0020 */   addiu    $sp, $sp, 0x20
