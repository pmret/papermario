.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_BBDDEC
/* BBDDEC 80240C4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBDDF0 80240C50 AFB10014 */  sw        $s1, 0x14($sp)
/* BBDDF4 80240C54 0080882D */  daddu     $s1, $a0, $zero
/* BBDDF8 80240C58 AFBF0018 */  sw        $ra, 0x18($sp)
/* BBDDFC 80240C5C AFB00010 */  sw        $s0, 0x10($sp)
/* BBDE00 80240C60 8E30000C */  lw        $s0, 0xc($s1)
/* BBDE04 80240C64 8E050000 */  lw        $a1, ($s0)
/* BBDE08 80240C68 0C0B1EAF */  jal       get_variable
/* BBDE0C 80240C6C 26100004 */   addiu    $s0, $s0, 4
/* BBDE10 80240C70 AE22008C */  sw        $v0, 0x8c($s1)
/* BBDE14 80240C74 8E050000 */  lw        $a1, ($s0)
/* BBDE18 80240C78 26100004 */  addiu     $s0, $s0, 4
/* BBDE1C 80240C7C 0C0B1EAF */  jal       get_variable
/* BBDE20 80240C80 0220202D */   daddu    $a0, $s1, $zero
/* BBDE24 80240C84 AE220090 */  sw        $v0, 0x90($s1)
/* BBDE28 80240C88 8E050000 */  lw        $a1, ($s0)
/* BBDE2C 80240C8C 26100004 */  addiu     $s0, $s0, 4
/* BBDE30 80240C90 0C0B1EAF */  jal       get_variable
/* BBDE34 80240C94 0220202D */   daddu    $a0, $s1, $zero
/* BBDE38 80240C98 AE220094 */  sw        $v0, 0x94($s1)
/* BBDE3C 80240C9C 8E050000 */  lw        $a1, ($s0)
/* BBDE40 80240CA0 26100004 */  addiu     $s0, $s0, 4
/* BBDE44 80240CA4 0C0B1EAF */  jal       get_variable
/* BBDE48 80240CA8 0220202D */   daddu    $a0, $s1, $zero
/* BBDE4C 80240CAC AE220098 */  sw        $v0, 0x98($s1)
/* BBDE50 80240CB0 8E050000 */  lw        $a1, ($s0)
/* BBDE54 80240CB4 26100004 */  addiu     $s0, $s0, 4
/* BBDE58 80240CB8 0C0B1EAF */  jal       get_variable
/* BBDE5C 80240CBC 0220202D */   daddu    $a0, $s1, $zero
/* BBDE60 80240CC0 AE22009C */  sw        $v0, 0x9c($s1)
/* BBDE64 80240CC4 8E050000 */  lw        $a1, ($s0)
/* BBDE68 80240CC8 26100004 */  addiu     $s0, $s0, 4
/* BBDE6C 80240CCC 0C0B1EAF */  jal       get_variable
/* BBDE70 80240CD0 0220202D */   daddu    $a0, $s1, $zero
/* BBDE74 80240CD4 AE2200A0 */  sw        $v0, 0xa0($s1)
/* BBDE78 80240CD8 8E050000 */  lw        $a1, ($s0)
/* BBDE7C 80240CDC 26100004 */  addiu     $s0, $s0, 4
/* BBDE80 80240CE0 0C0B1EAF */  jal       get_variable
/* BBDE84 80240CE4 0220202D */   daddu    $a0, $s1, $zero
/* BBDE88 80240CE8 AE2200A4 */  sw        $v0, 0xa4($s1)
/* BBDE8C 80240CEC 8E050000 */  lw        $a1, ($s0)
/* BBDE90 80240CF0 26100004 */  addiu     $s0, $s0, 4
/* BBDE94 80240CF4 0C0B1EAF */  jal       get_variable
/* BBDE98 80240CF8 0220202D */   daddu    $a0, $s1, $zero
/* BBDE9C 80240CFC AE2200A8 */  sw        $v0, 0xa8($s1)
/* BBDEA0 80240D00 8E050000 */  lw        $a1, ($s0)
/* BBDEA4 80240D04 26100004 */  addiu     $s0, $s0, 4
/* BBDEA8 80240D08 0C0B1EAF */  jal       get_variable
/* BBDEAC 80240D0C 0220202D */   daddu    $a0, $s1, $zero
/* BBDEB0 80240D10 AE2200AC */  sw        $v0, 0xac($s1)
/* BBDEB4 80240D14 8E050000 */  lw        $a1, ($s0)
/* BBDEB8 80240D18 0C0B1EAF */  jal       get_variable
/* BBDEBC 80240D1C 0220202D */   daddu    $a0, $s1, $zero
/* BBDEC0 80240D20 AE2200B0 */  sw        $v0, 0xb0($s1)
/* BBDEC4 80240D24 8FBF0018 */  lw        $ra, 0x18($sp)
/* BBDEC8 80240D28 8FB10014 */  lw        $s1, 0x14($sp)
/* BBDECC 80240D2C 8FB00010 */  lw        $s0, 0x10($sp)
/* BBDED0 80240D30 24020002 */  addiu     $v0, $zero, 2
/* BBDED4 80240D34 03E00008 */  jr        $ra
/* BBDED8 80240D38 27BD0020 */   addiu    $sp, $sp, 0x20
