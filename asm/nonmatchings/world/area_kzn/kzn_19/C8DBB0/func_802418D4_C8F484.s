.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418D4_C8F484
/* C8F484 802418D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8F488 802418D8 AFB10014 */  sw        $s1, 0x14($sp)
/* C8F48C 802418DC 0080882D */  daddu     $s1, $a0, $zero
/* C8F490 802418E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* C8F494 802418E4 AFB00010 */  sw        $s0, 0x10($sp)
/* C8F498 802418E8 8E30000C */  lw        $s0, 0xc($s1)
/* C8F49C 802418EC 8E050000 */  lw        $a1, ($s0)
/* C8F4A0 802418F0 0C0B1EAF */  jal       get_variable
/* C8F4A4 802418F4 26100004 */   addiu    $s0, $s0, 4
/* C8F4A8 802418F8 AE22008C */  sw        $v0, 0x8c($s1)
/* C8F4AC 802418FC 8E050000 */  lw        $a1, ($s0)
/* C8F4B0 80241900 26100004 */  addiu     $s0, $s0, 4
/* C8F4B4 80241904 0C0B1EAF */  jal       get_variable
/* C8F4B8 80241908 0220202D */   daddu    $a0, $s1, $zero
/* C8F4BC 8024190C AE220090 */  sw        $v0, 0x90($s1)
/* C8F4C0 80241910 8E050000 */  lw        $a1, ($s0)
/* C8F4C4 80241914 26100004 */  addiu     $s0, $s0, 4
/* C8F4C8 80241918 0C0B1EAF */  jal       get_variable
/* C8F4CC 8024191C 0220202D */   daddu    $a0, $s1, $zero
/* C8F4D0 80241920 AE220094 */  sw        $v0, 0x94($s1)
/* C8F4D4 80241924 8E050000 */  lw        $a1, ($s0)
/* C8F4D8 80241928 26100004 */  addiu     $s0, $s0, 4
/* C8F4DC 8024192C 0C0B1EAF */  jal       get_variable
/* C8F4E0 80241930 0220202D */   daddu    $a0, $s1, $zero
/* C8F4E4 80241934 AE220098 */  sw        $v0, 0x98($s1)
/* C8F4E8 80241938 8E050000 */  lw        $a1, ($s0)
/* C8F4EC 8024193C 26100004 */  addiu     $s0, $s0, 4
/* C8F4F0 80241940 0C0B1EAF */  jal       get_variable
/* C8F4F4 80241944 0220202D */   daddu    $a0, $s1, $zero
/* C8F4F8 80241948 AE22009C */  sw        $v0, 0x9c($s1)
/* C8F4FC 8024194C 8E050000 */  lw        $a1, ($s0)
/* C8F500 80241950 26100004 */  addiu     $s0, $s0, 4
/* C8F504 80241954 0C0B1EAF */  jal       get_variable
/* C8F508 80241958 0220202D */   daddu    $a0, $s1, $zero
/* C8F50C 8024195C AE2200A0 */  sw        $v0, 0xa0($s1)
/* C8F510 80241960 8E050000 */  lw        $a1, ($s0)
/* C8F514 80241964 26100004 */  addiu     $s0, $s0, 4
/* C8F518 80241968 0C0B1EAF */  jal       get_variable
/* C8F51C 8024196C 0220202D */   daddu    $a0, $s1, $zero
/* C8F520 80241970 AE2200A4 */  sw        $v0, 0xa4($s1)
/* C8F524 80241974 8E050000 */  lw        $a1, ($s0)
/* C8F528 80241978 26100004 */  addiu     $s0, $s0, 4
/* C8F52C 8024197C 0C0B1EAF */  jal       get_variable
/* C8F530 80241980 0220202D */   daddu    $a0, $s1, $zero
/* C8F534 80241984 AE2200A8 */  sw        $v0, 0xa8($s1)
/* C8F538 80241988 8E050000 */  lw        $a1, ($s0)
/* C8F53C 8024198C 26100004 */  addiu     $s0, $s0, 4
/* C8F540 80241990 0C0B1EAF */  jal       get_variable
/* C8F544 80241994 0220202D */   daddu    $a0, $s1, $zero
/* C8F548 80241998 AE2200AC */  sw        $v0, 0xac($s1)
/* C8F54C 8024199C 8E050000 */  lw        $a1, ($s0)
/* C8F550 802419A0 0C0B1EAF */  jal       get_variable
/* C8F554 802419A4 0220202D */   daddu    $a0, $s1, $zero
/* C8F558 802419A8 AE2200B0 */  sw        $v0, 0xb0($s1)
/* C8F55C 802419AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C8F560 802419B0 8FB10014 */  lw        $s1, 0x14($sp)
/* C8F564 802419B4 8FB00010 */  lw        $s0, 0x10($sp)
/* C8F568 802419B8 24020002 */  addiu     $v0, $zero, 2
/* C8F56C 802419BC 03E00008 */  jr        $ra
/* C8F570 802419C0 27BD0020 */   addiu    $sp, $sp, 0x20
