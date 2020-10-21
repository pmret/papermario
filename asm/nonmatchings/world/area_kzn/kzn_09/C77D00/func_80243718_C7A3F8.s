.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243718_C7A3F8
/* C7A3F8 80243718 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7A3FC 8024371C AFB10014 */  sw        $s1, 0x14($sp)
/* C7A400 80243720 0080882D */  daddu     $s1, $a0, $zero
/* C7A404 80243724 AFBF0018 */  sw        $ra, 0x18($sp)
/* C7A408 80243728 AFB00010 */  sw        $s0, 0x10($sp)
/* C7A40C 8024372C 8E30000C */  lw        $s0, 0xc($s1)
/* C7A410 80243730 8E050000 */  lw        $a1, ($s0)
/* C7A414 80243734 0C0B1EAF */  jal       get_variable
/* C7A418 80243738 26100004 */   addiu    $s0, $s0, 4
/* C7A41C 8024373C AE22008C */  sw        $v0, 0x8c($s1)
/* C7A420 80243740 8E050000 */  lw        $a1, ($s0)
/* C7A424 80243744 26100004 */  addiu     $s0, $s0, 4
/* C7A428 80243748 0C0B1EAF */  jal       get_variable
/* C7A42C 8024374C 0220202D */   daddu    $a0, $s1, $zero
/* C7A430 80243750 AE220090 */  sw        $v0, 0x90($s1)
/* C7A434 80243754 8E050000 */  lw        $a1, ($s0)
/* C7A438 80243758 26100004 */  addiu     $s0, $s0, 4
/* C7A43C 8024375C 0C0B1EAF */  jal       get_variable
/* C7A440 80243760 0220202D */   daddu    $a0, $s1, $zero
/* C7A444 80243764 AE220094 */  sw        $v0, 0x94($s1)
/* C7A448 80243768 8E050000 */  lw        $a1, ($s0)
/* C7A44C 8024376C 26100004 */  addiu     $s0, $s0, 4
/* C7A450 80243770 0C0B1EAF */  jal       get_variable
/* C7A454 80243774 0220202D */   daddu    $a0, $s1, $zero
/* C7A458 80243778 AE220098 */  sw        $v0, 0x98($s1)
/* C7A45C 8024377C 8E050000 */  lw        $a1, ($s0)
/* C7A460 80243780 26100004 */  addiu     $s0, $s0, 4
/* C7A464 80243784 0C0B1EAF */  jal       get_variable
/* C7A468 80243788 0220202D */   daddu    $a0, $s1, $zero
/* C7A46C 8024378C AE22009C */  sw        $v0, 0x9c($s1)
/* C7A470 80243790 8E050000 */  lw        $a1, ($s0)
/* C7A474 80243794 26100004 */  addiu     $s0, $s0, 4
/* C7A478 80243798 0C0B1EAF */  jal       get_variable
/* C7A47C 8024379C 0220202D */   daddu    $a0, $s1, $zero
/* C7A480 802437A0 AE2200A0 */  sw        $v0, 0xa0($s1)
/* C7A484 802437A4 8E050000 */  lw        $a1, ($s0)
/* C7A488 802437A8 26100004 */  addiu     $s0, $s0, 4
/* C7A48C 802437AC 0C0B1EAF */  jal       get_variable
/* C7A490 802437B0 0220202D */   daddu    $a0, $s1, $zero
/* C7A494 802437B4 AE2200A4 */  sw        $v0, 0xa4($s1)
/* C7A498 802437B8 8E050000 */  lw        $a1, ($s0)
/* C7A49C 802437BC 26100004 */  addiu     $s0, $s0, 4
/* C7A4A0 802437C0 0C0B1EAF */  jal       get_variable
/* C7A4A4 802437C4 0220202D */   daddu    $a0, $s1, $zero
/* C7A4A8 802437C8 AE2200A8 */  sw        $v0, 0xa8($s1)
/* C7A4AC 802437CC 8E050000 */  lw        $a1, ($s0)
/* C7A4B0 802437D0 26100004 */  addiu     $s0, $s0, 4
/* C7A4B4 802437D4 0C0B1EAF */  jal       get_variable
/* C7A4B8 802437D8 0220202D */   daddu    $a0, $s1, $zero
/* C7A4BC 802437DC AE2200AC */  sw        $v0, 0xac($s1)
/* C7A4C0 802437E0 8E050000 */  lw        $a1, ($s0)
/* C7A4C4 802437E4 0C0B1EAF */  jal       get_variable
/* C7A4C8 802437E8 0220202D */   daddu    $a0, $s1, $zero
/* C7A4CC 802437EC AE2200B0 */  sw        $v0, 0xb0($s1)
/* C7A4D0 802437F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C7A4D4 802437F4 8FB10014 */  lw        $s1, 0x14($sp)
/* C7A4D8 802437F8 8FB00010 */  lw        $s0, 0x10($sp)
/* C7A4DC 802437FC 24020002 */  addiu     $v0, $zero, 2
/* C7A4E0 80243800 03E00008 */  jr        $ra
/* C7A4E4 80243804 27BD0020 */   addiu    $sp, $sp, 0x20
