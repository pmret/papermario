.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241770_ECB470
/* ECB470 80241770 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECB474 80241774 AFB10014 */  sw        $s1, 0x14($sp)
/* ECB478 80241778 0080882D */  daddu     $s1, $a0, $zero
/* ECB47C 8024177C AFBF0018 */  sw        $ra, 0x18($sp)
/* ECB480 80241780 AFB00010 */  sw        $s0, 0x10($sp)
/* ECB484 80241784 8E30000C */  lw        $s0, 0xc($s1)
/* ECB488 80241788 8E050000 */  lw        $a1, ($s0)
/* ECB48C 8024178C 0C0B53A3 */  jal       dead_evt_get_variable
/* ECB490 80241790 26100004 */   addiu    $s0, $s0, 4
/* ECB494 80241794 0C00F94D */  jal       func_8003E534
/* ECB498 80241798 0040202D */   daddu    $a0, $v0, $zero
/* ECB49C 8024179C 10400005 */  beqz      $v0, .L802417B4
/* ECB4A0 802417A0 00000000 */   nop
/* ECB4A4 802417A4 8E050000 */  lw        $a1, ($s0)
/* ECB4A8 802417A8 844600A8 */  lh        $a2, 0xa8($v0)
/* ECB4AC 802417AC 0C0B551A */  jal       dead_evt_set_variable
/* ECB4B0 802417B0 0220202D */   daddu    $a0, $s1, $zero
.L802417B4:
/* ECB4B4 802417B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* ECB4B8 802417B8 8FB10014 */  lw        $s1, 0x14($sp)
/* ECB4BC 802417BC 8FB00010 */  lw        $s0, 0x10($sp)
/* ECB4C0 802417C0 24020002 */  addiu     $v0, $zero, 2
/* ECB4C4 802417C4 03E00008 */  jr        $ra
/* ECB4C8 802417C8 27BD0020 */   addiu    $sp, $sp, 0x20
