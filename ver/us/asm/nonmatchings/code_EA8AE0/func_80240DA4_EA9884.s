.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA4_EA9884
/* EA9884 80240DA4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA9888 80240DA8 AFB10014 */  sw        $s1, 0x14($sp)
/* EA988C 80240DAC 0080882D */  daddu     $s1, $a0, $zero
/* EA9890 80240DB0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA9894 80240DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* EA9898 80240DB8 8E30000C */  lw        $s0, 0xc($s1)
/* EA989C 80240DBC 8E050000 */  lw        $a1, ($s0)
/* EA98A0 80240DC0 0C0B53A3 */  jal       dead_get_variable
/* EA98A4 80240DC4 26100004 */   addiu    $s0, $s0, 4
/* EA98A8 80240DC8 8E050000 */  lw        $a1, ($s0)
/* EA98AC 80240DCC 26100004 */  addiu     $s0, $s0, 4
/* EA98B0 80240DD0 0C0B53A3 */  jal       dead_get_variable
/* EA98B4 80240DD4 0220202D */   daddu    $a0, $s1, $zero
/* EA98B8 80240DD8 8E050000 */  lw        $a1, ($s0)
/* EA98BC 80240DDC 26100004 */  addiu     $s0, $s0, 4
/* EA98C0 80240DE0 0C0B53A3 */  jal       dead_get_variable
/* EA98C4 80240DE4 0220202D */   daddu    $a0, $s1, $zero
/* EA98C8 80240DE8 8E050000 */  lw        $a1, ($s0)
/* EA98CC 80240DEC 26100004 */  addiu     $s0, $s0, 4
/* EA98D0 80240DF0 0C0B53A3 */  jal       dead_get_variable
/* EA98D4 80240DF4 0220202D */   daddu    $a0, $s1, $zero
/* EA98D8 80240DF8 8E050000 */  lw        $a1, ($s0)
/* EA98DC 80240DFC 0C0B53A3 */  jal       dead_get_variable
/* EA98E0 80240E00 0220202D */   daddu    $a0, $s1, $zero
/* EA98E4 80240E04 0000202D */  daddu     $a0, $zero, $zero
/* EA98E8 80240E08 3C05FD05 */  lui       $a1, 0xfd05
/* EA98EC 80240E0C 0C0B53A3 */  jal       dead_get_variable
/* EA98F0 80240E10 34A50F80 */   ori      $a1, $a1, 0xf80
/* EA98F4 80240E14 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA98F8 80240E18 8FB10014 */  lw        $s1, 0x14($sp)
/* EA98FC 80240E1C 8FB00010 */  lw        $s0, 0x10($sp)
/* EA9900 80240E20 24020002 */  addiu     $v0, $zero, 2
/* EA9904 80240E24 03E00008 */  jr        $ra
/* EA9908 80240E28 27BD0020 */   addiu    $sp, $sp, 0x20
