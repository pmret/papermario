.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802C9C70
/* EE620 802C9C70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE624 802C9C74 AFB10014 */  sw        $s1, 0x14($sp)
/* EE628 802C9C78 0080882D */  daddu     $s1, $a0, $zero
/* EE62C 802C9C7C AFBF001C */  sw        $ra, 0x1c($sp)
/* EE630 802C9C80 AFB20018 */  sw        $s2, 0x18($sp)
/* EE634 802C9C84 AFB00010 */  sw        $s0, 0x10($sp)
/* EE638 802C9C88 8E30000C */  lw        $s0, 0xc($s1)
/* EE63C 802C9C8C 8E050000 */  lw        $a1, ($s0)
/* EE640 802C9C90 0C0B1EAF */  jal       get_variable
/* EE644 802C9C94 26100004 */   addiu    $s0, $s0, 4
/* EE648 802C9C98 8E050000 */  lw        $a1, ($s0)
/* EE64C 802C9C9C 26100004 */  addiu     $s0, $s0, 4
/* EE650 802C9CA0 0220202D */  daddu     $a0, $s1, $zero
/* EE654 802C9CA4 0C0B1EAF */  jal       get_variable
/* EE658 802C9CA8 0040902D */   daddu    $s2, $v0, $zero
/* EE65C 802C9CAC 0220202D */  daddu     $a0, $s1, $zero
/* EE660 802C9CB0 8E050000 */  lw        $a1, ($s0)
/* EE664 802C9CB4 0C0B1EAF */  jal       get_variable
/* EE668 802C9CB8 0040802D */   daddu    $s0, $v0, $zero
/* EE66C 802C9CBC 0240202D */  daddu     $a0, $s2, $zero
/* EE670 802C9CC0 3205FFFF */  andi      $a1, $s0, 0xffff
/* EE674 802C9CC4 0C047059 */  jal       func_8011C164
/* EE678 802C9CC8 0040302D */   daddu    $a2, $v0, $zero
/* EE67C 802C9CCC 8FBF001C */  lw        $ra, 0x1c($sp)
/* EE680 802C9CD0 8FB20018 */  lw        $s2, 0x18($sp)
/* EE684 802C9CD4 8FB10014 */  lw        $s1, 0x14($sp)
/* EE688 802C9CD8 8FB00010 */  lw        $s0, 0x10($sp)
/* EE68C 802C9CDC 24020002 */  addiu     $v0, $zero, 2
/* EE690 802C9CE0 03E00008 */  jr        $ra
/* EE694 802C9CE4 27BD0020 */   addiu    $sp, $sp, 0x20
