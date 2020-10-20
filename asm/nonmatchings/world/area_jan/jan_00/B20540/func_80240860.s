.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240860
/* B20DA0 80240860 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B20DA4 80240864 AFB10014 */  sw        $s1, 0x14($sp)
/* B20DA8 80240868 0080882D */  daddu     $s1, $a0, $zero
/* B20DAC 8024086C AFBF0018 */  sw        $ra, 0x18($sp)
/* B20DB0 80240870 AFB00010 */  sw        $s0, 0x10($sp)
/* B20DB4 80240874 8E30000C */  lw        $s0, 0xc($s1)
/* B20DB8 80240878 8E050000 */  lw        $a1, ($s0)
/* B20DBC 8024087C 0C0B1EAF */  jal       get_variable
/* B20DC0 80240880 26100004 */   addiu    $s0, $s0, 4
/* B20DC4 80240884 AE22008C */  sw        $v0, 0x8c($s1)
/* B20DC8 80240888 8E050000 */  lw        $a1, ($s0)
/* B20DCC 8024088C 26100004 */  addiu     $s0, $s0, 4
/* B20DD0 80240890 0C0B1EAF */  jal       get_variable
/* B20DD4 80240894 0220202D */   daddu    $a0, $s1, $zero
/* B20DD8 80240898 AE220090 */  sw        $v0, 0x90($s1)
/* B20DDC 8024089C 8E050000 */  lw        $a1, ($s0)
/* B20DE0 802408A0 26100004 */  addiu     $s0, $s0, 4
/* B20DE4 802408A4 0C0B1EAF */  jal       get_variable
/* B20DE8 802408A8 0220202D */   daddu    $a0, $s1, $zero
/* B20DEC 802408AC AE220094 */  sw        $v0, 0x94($s1)
/* B20DF0 802408B0 8E050000 */  lw        $a1, ($s0)
/* B20DF4 802408B4 26100004 */  addiu     $s0, $s0, 4
/* B20DF8 802408B8 0C0B1EAF */  jal       get_variable
/* B20DFC 802408BC 0220202D */   daddu    $a0, $s1, $zero
/* B20E00 802408C0 AE220098 */  sw        $v0, 0x98($s1)
/* B20E04 802408C4 8E050000 */  lw        $a1, ($s0)
/* B20E08 802408C8 26100004 */  addiu     $s0, $s0, 4
/* B20E0C 802408CC 0C0B1EAF */  jal       get_variable
/* B20E10 802408D0 0220202D */   daddu    $a0, $s1, $zero
/* B20E14 802408D4 AE22009C */  sw        $v0, 0x9c($s1)
/* B20E18 802408D8 8E050000 */  lw        $a1, ($s0)
/* B20E1C 802408DC 26100004 */  addiu     $s0, $s0, 4
/* B20E20 802408E0 0C0B1EAF */  jal       get_variable
/* B20E24 802408E4 0220202D */   daddu    $a0, $s1, $zero
/* B20E28 802408E8 AE2200A0 */  sw        $v0, 0xa0($s1)
/* B20E2C 802408EC 8E050000 */  lw        $a1, ($s0)
/* B20E30 802408F0 26100004 */  addiu     $s0, $s0, 4
/* B20E34 802408F4 0C0B1EAF */  jal       get_variable
/* B20E38 802408F8 0220202D */   daddu    $a0, $s1, $zero
/* B20E3C 802408FC AE2200A4 */  sw        $v0, 0xa4($s1)
/* B20E40 80240900 8E050000 */  lw        $a1, ($s0)
/* B20E44 80240904 26100004 */  addiu     $s0, $s0, 4
/* B20E48 80240908 0C0B1EAF */  jal       get_variable
/* B20E4C 8024090C 0220202D */   daddu    $a0, $s1, $zero
/* B20E50 80240910 AE2200A8 */  sw        $v0, 0xa8($s1)
/* B20E54 80240914 8E050000 */  lw        $a1, ($s0)
/* B20E58 80240918 26100004 */  addiu     $s0, $s0, 4
/* B20E5C 8024091C 0C0B1EAF */  jal       get_variable
/* B20E60 80240920 0220202D */   daddu    $a0, $s1, $zero
/* B20E64 80240924 AE2200AC */  sw        $v0, 0xac($s1)
/* B20E68 80240928 8E050000 */  lw        $a1, ($s0)
/* B20E6C 8024092C 0C0B1EAF */  jal       get_variable
/* B20E70 80240930 0220202D */   daddu    $a0, $s1, $zero
/* B20E74 80240934 AE2200B0 */  sw        $v0, 0xb0($s1)
/* B20E78 80240938 8FBF0018 */  lw        $ra, 0x18($sp)
/* B20E7C 8024093C 8FB10014 */  lw        $s1, 0x14($sp)
/* B20E80 80240940 8FB00010 */  lw        $s0, 0x10($sp)
/* B20E84 80240944 24020002 */  addiu     $v0, $zero, 2
/* B20E88 80240948 03E00008 */  jr        $ra
/* B20E8C 8024094C 27BD0020 */   addiu    $sp, $sp, 0x20
