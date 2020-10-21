.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241898_833098
/* 833098 80241898 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 83309C 8024189C AFB10014 */  sw        $s1, 0x14($sp)
/* 8330A0 802418A0 0080882D */  daddu     $s1, $a0, $zero
/* 8330A4 802418A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8330A8 802418A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8330AC 802418AC 8E30000C */  lw        $s0, 0xc($s1)
/* 8330B0 802418B0 8E050000 */  lw        $a1, ($s0)
/* 8330B4 802418B4 0C0B1EAF */  jal       get_variable
/* 8330B8 802418B8 26100004 */   addiu    $s0, $s0, 4
/* 8330BC 802418BC AE22008C */  sw        $v0, 0x8c($s1)
/* 8330C0 802418C0 8E050000 */  lw        $a1, ($s0)
/* 8330C4 802418C4 26100004 */  addiu     $s0, $s0, 4
/* 8330C8 802418C8 0C0B1EAF */  jal       get_variable
/* 8330CC 802418CC 0220202D */   daddu    $a0, $s1, $zero
/* 8330D0 802418D0 AE220090 */  sw        $v0, 0x90($s1)
/* 8330D4 802418D4 8E050000 */  lw        $a1, ($s0)
/* 8330D8 802418D8 26100004 */  addiu     $s0, $s0, 4
/* 8330DC 802418DC 0C0B1EAF */  jal       get_variable
/* 8330E0 802418E0 0220202D */   daddu    $a0, $s1, $zero
/* 8330E4 802418E4 AE220094 */  sw        $v0, 0x94($s1)
/* 8330E8 802418E8 8E050000 */  lw        $a1, ($s0)
/* 8330EC 802418EC 26100004 */  addiu     $s0, $s0, 4
/* 8330F0 802418F0 0C0B1EAF */  jal       get_variable
/* 8330F4 802418F4 0220202D */   daddu    $a0, $s1, $zero
/* 8330F8 802418F8 AE220098 */  sw        $v0, 0x98($s1)
/* 8330FC 802418FC 8E050000 */  lw        $a1, ($s0)
/* 833100 80241900 26100004 */  addiu     $s0, $s0, 4
/* 833104 80241904 0C0B1EAF */  jal       get_variable
/* 833108 80241908 0220202D */   daddu    $a0, $s1, $zero
/* 83310C 8024190C AE22009C */  sw        $v0, 0x9c($s1)
/* 833110 80241910 8E050000 */  lw        $a1, ($s0)
/* 833114 80241914 26100004 */  addiu     $s0, $s0, 4
/* 833118 80241918 0C0B1EAF */  jal       get_variable
/* 83311C 8024191C 0220202D */   daddu    $a0, $s1, $zero
/* 833120 80241920 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 833124 80241924 8E050000 */  lw        $a1, ($s0)
/* 833128 80241928 26100004 */  addiu     $s0, $s0, 4
/* 83312C 8024192C 0C0B1EAF */  jal       get_variable
/* 833130 80241930 0220202D */   daddu    $a0, $s1, $zero
/* 833134 80241934 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 833138 80241938 8E050000 */  lw        $a1, ($s0)
/* 83313C 8024193C 26100004 */  addiu     $s0, $s0, 4
/* 833140 80241940 0C0B1EAF */  jal       get_variable
/* 833144 80241944 0220202D */   daddu    $a0, $s1, $zero
/* 833148 80241948 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 83314C 8024194C 8E050000 */  lw        $a1, ($s0)
/* 833150 80241950 26100004 */  addiu     $s0, $s0, 4
/* 833154 80241954 0C0B1EAF */  jal       get_variable
/* 833158 80241958 0220202D */   daddu    $a0, $s1, $zero
/* 83315C 8024195C AE2200AC */  sw        $v0, 0xac($s1)
/* 833160 80241960 8E050000 */  lw        $a1, ($s0)
/* 833164 80241964 0C0B1EAF */  jal       get_variable
/* 833168 80241968 0220202D */   daddu    $a0, $s1, $zero
/* 83316C 8024196C AE2200B0 */  sw        $v0, 0xb0($s1)
/* 833170 80241970 8FBF0018 */  lw        $ra, 0x18($sp)
/* 833174 80241974 8FB10014 */  lw        $s1, 0x14($sp)
/* 833178 80241978 8FB00010 */  lw        $s0, 0x10($sp)
/* 83317C 8024197C 24020002 */  addiu     $v0, $zero, 2
/* 833180 80241980 03E00008 */  jr        $ra
/* 833184 80241984 27BD0020 */   addiu    $sp, $sp, 0x20
