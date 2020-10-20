.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024386C
/* 7EE57C 8024386C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EE580 80243870 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EE584 80243874 0080882D */  daddu     $s1, $a0, $zero
/* 7EE588 80243878 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EE58C 8024387C AFB00010 */  sw        $s0, 0x10($sp)
/* 7EE590 80243880 8E30000C */  lw        $s0, 0xc($s1)
/* 7EE594 80243884 8E050000 */  lw        $a1, ($s0)
/* 7EE598 80243888 0C0B1EAF */  jal       get_variable
/* 7EE59C 8024388C 26100004 */   addiu    $s0, $s0, 4
/* 7EE5A0 80243890 AE22008C */  sw        $v0, 0x8c($s1)
/* 7EE5A4 80243894 8E050000 */  lw        $a1, ($s0)
/* 7EE5A8 80243898 26100004 */  addiu     $s0, $s0, 4
/* 7EE5AC 8024389C 0C0B1EAF */  jal       get_variable
/* 7EE5B0 802438A0 0220202D */   daddu    $a0, $s1, $zero
/* 7EE5B4 802438A4 AE220090 */  sw        $v0, 0x90($s1)
/* 7EE5B8 802438A8 8E050000 */  lw        $a1, ($s0)
/* 7EE5BC 802438AC 26100004 */  addiu     $s0, $s0, 4
/* 7EE5C0 802438B0 0C0B1EAF */  jal       get_variable
/* 7EE5C4 802438B4 0220202D */   daddu    $a0, $s1, $zero
/* 7EE5C8 802438B8 AE220094 */  sw        $v0, 0x94($s1)
/* 7EE5CC 802438BC 8E050000 */  lw        $a1, ($s0)
/* 7EE5D0 802438C0 26100004 */  addiu     $s0, $s0, 4
/* 7EE5D4 802438C4 0C0B1EAF */  jal       get_variable
/* 7EE5D8 802438C8 0220202D */   daddu    $a0, $s1, $zero
/* 7EE5DC 802438CC AE220098 */  sw        $v0, 0x98($s1)
/* 7EE5E0 802438D0 8E050000 */  lw        $a1, ($s0)
/* 7EE5E4 802438D4 26100004 */  addiu     $s0, $s0, 4
/* 7EE5E8 802438D8 0C0B1EAF */  jal       get_variable
/* 7EE5EC 802438DC 0220202D */   daddu    $a0, $s1, $zero
/* 7EE5F0 802438E0 AE22009C */  sw        $v0, 0x9c($s1)
/* 7EE5F4 802438E4 8E050000 */  lw        $a1, ($s0)
/* 7EE5F8 802438E8 26100004 */  addiu     $s0, $s0, 4
/* 7EE5FC 802438EC 0C0B1EAF */  jal       get_variable
/* 7EE600 802438F0 0220202D */   daddu    $a0, $s1, $zero
/* 7EE604 802438F4 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 7EE608 802438F8 8E050000 */  lw        $a1, ($s0)
/* 7EE60C 802438FC 26100004 */  addiu     $s0, $s0, 4
/* 7EE610 80243900 0C0B1EAF */  jal       get_variable
/* 7EE614 80243904 0220202D */   daddu    $a0, $s1, $zero
/* 7EE618 80243908 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 7EE61C 8024390C 8E050000 */  lw        $a1, ($s0)
/* 7EE620 80243910 26100004 */  addiu     $s0, $s0, 4
/* 7EE624 80243914 0C0B1EAF */  jal       get_variable
/* 7EE628 80243918 0220202D */   daddu    $a0, $s1, $zero
/* 7EE62C 8024391C AE2200A8 */  sw        $v0, 0xa8($s1)
/* 7EE630 80243920 8E050000 */  lw        $a1, ($s0)
/* 7EE634 80243924 26100004 */  addiu     $s0, $s0, 4
/* 7EE638 80243928 0C0B1EAF */  jal       get_variable
/* 7EE63C 8024392C 0220202D */   daddu    $a0, $s1, $zero
/* 7EE640 80243930 AE2200AC */  sw        $v0, 0xac($s1)
/* 7EE644 80243934 8E050000 */  lw        $a1, ($s0)
/* 7EE648 80243938 0C0B1EAF */  jal       get_variable
/* 7EE64C 8024393C 0220202D */   daddu    $a0, $s1, $zero
/* 7EE650 80243940 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 7EE654 80243944 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EE658 80243948 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EE65C 8024394C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EE660 80243950 24020002 */  addiu     $v0, $zero, 2
/* 7EE664 80243954 03E00008 */  jr        $ra
/* 7EE668 80243958 27BD0020 */   addiu    $sp, $sp, 0x20
