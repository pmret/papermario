.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418D4_EAA3B4
/* EAA3B4 802418D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EAA3B8 802418D8 AFB10014 */  sw        $s1, 0x14($sp)
/* EAA3BC 802418DC 0080882D */  daddu     $s1, $a0, $zero
/* EAA3C0 802418E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EAA3C4 802418E4 AFB00010 */  sw        $s0, 0x10($sp)
/* EAA3C8 802418E8 8E30000C */  lw        $s0, 0xc($s1)
/* EAA3CC 802418EC 8E050000 */  lw        $a1, ($s0)
/* EAA3D0 802418F0 0C0B53A3 */  jal       dead_get_variable
/* EAA3D4 802418F4 26100004 */   addiu    $s0, $s0, 4
/* EAA3D8 802418F8 AE22008C */  sw        $v0, 0x8c($s1)
/* EAA3DC 802418FC 8E050000 */  lw        $a1, ($s0)
/* EAA3E0 80241900 26100004 */  addiu     $s0, $s0, 4
/* EAA3E4 80241904 0C0B53A3 */  jal       dead_get_variable
/* EAA3E8 80241908 0220202D */   daddu    $a0, $s1, $zero
/* EAA3EC 8024190C AE220090 */  sw        $v0, 0x90($s1)
/* EAA3F0 80241910 8E050000 */  lw        $a1, ($s0)
/* EAA3F4 80241914 26100004 */  addiu     $s0, $s0, 4
/* EAA3F8 80241918 0C0B53A3 */  jal       dead_get_variable
/* EAA3FC 8024191C 0220202D */   daddu    $a0, $s1, $zero
/* EAA400 80241920 AE220094 */  sw        $v0, 0x94($s1)
/* EAA404 80241924 8E050000 */  lw        $a1, ($s0)
/* EAA408 80241928 26100004 */  addiu     $s0, $s0, 4
/* EAA40C 8024192C 0C0B53A3 */  jal       dead_get_variable
/* EAA410 80241930 0220202D */   daddu    $a0, $s1, $zero
/* EAA414 80241934 AE220098 */  sw        $v0, 0x98($s1)
/* EAA418 80241938 8E050000 */  lw        $a1, ($s0)
/* EAA41C 8024193C 26100004 */  addiu     $s0, $s0, 4
/* EAA420 80241940 0C0B53A3 */  jal       dead_get_variable
/* EAA424 80241944 0220202D */   daddu    $a0, $s1, $zero
/* EAA428 80241948 AE22009C */  sw        $v0, 0x9c($s1)
/* EAA42C 8024194C 8E050000 */  lw        $a1, ($s0)
/* EAA430 80241950 26100004 */  addiu     $s0, $s0, 4
/* EAA434 80241954 0C0B53A3 */  jal       dead_get_variable
/* EAA438 80241958 0220202D */   daddu    $a0, $s1, $zero
/* EAA43C 8024195C AE2200A0 */  sw        $v0, 0xa0($s1)
/* EAA440 80241960 8E050000 */  lw        $a1, ($s0)
/* EAA444 80241964 26100004 */  addiu     $s0, $s0, 4
/* EAA448 80241968 0C0B53A3 */  jal       dead_get_variable
/* EAA44C 8024196C 0220202D */   daddu    $a0, $s1, $zero
/* EAA450 80241970 AE2200A4 */  sw        $v0, 0xa4($s1)
/* EAA454 80241974 8E050000 */  lw        $a1, ($s0)
/* EAA458 80241978 26100004 */  addiu     $s0, $s0, 4
/* EAA45C 8024197C 0C0B53A3 */  jal       dead_get_variable
/* EAA460 80241980 0220202D */   daddu    $a0, $s1, $zero
/* EAA464 80241984 AE2200A8 */  sw        $v0, 0xa8($s1)
/* EAA468 80241988 8E050000 */  lw        $a1, ($s0)
/* EAA46C 8024198C 26100004 */  addiu     $s0, $s0, 4
/* EAA470 80241990 0C0B53A3 */  jal       dead_get_variable
/* EAA474 80241994 0220202D */   daddu    $a0, $s1, $zero
/* EAA478 80241998 AE2200AC */  sw        $v0, 0xac($s1)
/* EAA47C 8024199C 8E050000 */  lw        $a1, ($s0)
/* EAA480 802419A0 0C0B53A3 */  jal       dead_get_variable
/* EAA484 802419A4 0220202D */   daddu    $a0, $s1, $zero
/* EAA488 802419A8 AE2200B0 */  sw        $v0, 0xb0($s1)
/* EAA48C 802419AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* EAA490 802419B0 8FB10014 */  lw        $s1, 0x14($sp)
/* EAA494 802419B4 8FB00010 */  lw        $s0, 0x10($sp)
/* EAA498 802419B8 24020002 */  addiu     $v0, $zero, 2
/* EAA49C 802419BC 03E00008 */  jr        $ra
/* EAA4A0 802419C0 27BD0020 */   addiu    $sp, $sp, 0x20
