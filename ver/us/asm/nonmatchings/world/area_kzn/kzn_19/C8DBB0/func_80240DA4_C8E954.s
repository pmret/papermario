.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DA4_C8E954
/* C8E954 80240DA4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8E958 80240DA8 AFB10014 */  sw        $s1, 0x14($sp)
/* C8E95C 80240DAC 0080882D */  daddu     $s1, $a0, $zero
/* C8E960 80240DB0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C8E964 80240DB4 AFB00010 */  sw        $s0, 0x10($sp)
/* C8E968 80240DB8 8E30000C */  lw        $s0, 0xc($s1)
/* C8E96C 80240DBC 8E050000 */  lw        $a1, ($s0)
/* C8E970 80240DC0 0C0B1EAF */  jal       evt_get_variable
/* C8E974 80240DC4 26100004 */   addiu    $s0, $s0, 4
/* C8E978 80240DC8 8E050000 */  lw        $a1, ($s0)
/* C8E97C 80240DCC 26100004 */  addiu     $s0, $s0, 4
/* C8E980 80240DD0 0C0B1EAF */  jal       evt_get_variable
/* C8E984 80240DD4 0220202D */   daddu    $a0, $s1, $zero
/* C8E988 80240DD8 8E050000 */  lw        $a1, ($s0)
/* C8E98C 80240DDC 26100004 */  addiu     $s0, $s0, 4
/* C8E990 80240DE0 0C0B1EAF */  jal       evt_get_variable
/* C8E994 80240DE4 0220202D */   daddu    $a0, $s1, $zero
/* C8E998 80240DE8 8E050000 */  lw        $a1, ($s0)
/* C8E99C 80240DEC 26100004 */  addiu     $s0, $s0, 4
/* C8E9A0 80240DF0 0C0B1EAF */  jal       evt_get_variable
/* C8E9A4 80240DF4 0220202D */   daddu    $a0, $s1, $zero
/* C8E9A8 80240DF8 8E050000 */  lw        $a1, ($s0)
/* C8E9AC 80240DFC 0C0B1EAF */  jal       evt_get_variable
/* C8E9B0 80240E00 0220202D */   daddu    $a0, $s1, $zero
/* C8E9B4 80240E04 0000202D */  daddu     $a0, $zero, $zero
/* C8E9B8 80240E08 3C05FD05 */  lui       $a1, 0xfd05
/* C8E9BC 80240E0C 0C0B1EAF */  jal       evt_get_variable
/* C8E9C0 80240E10 34A50F80 */   ori      $a1, $a1, 0xf80
/* C8E9C4 80240E14 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8E9C8 80240E18 8FB10014 */  lw        $s1, 0x14($sp)
/* C8E9CC 80240E1C 8FB00010 */  lw        $s0, 0x10($sp)
/* C8E9D0 80240E20 24020002 */  addiu     $v0, $zero, 2
/* C8E9D4 80240E24 03E00008 */  jr        $ra
/* C8E9D8 80240E28 27BD0020 */   addiu    $sp, $sp, 0x20
