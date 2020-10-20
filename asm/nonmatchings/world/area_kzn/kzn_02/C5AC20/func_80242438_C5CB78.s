.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242438_C5CB78
/* C5CB78 80242438 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5CB7C 8024243C AFB10014 */  sw        $s1, 0x14($sp)
/* C5CB80 80242440 0080882D */  daddu     $s1, $a0, $zero
/* C5CB84 80242444 AFBF0018 */  sw        $ra, 0x18($sp)
/* C5CB88 80242448 AFB00010 */  sw        $s0, 0x10($sp)
/* C5CB8C 8024244C 8E30000C */  lw        $s0, 0xc($s1)
/* C5CB90 80242450 8E050000 */  lw        $a1, ($s0)
/* C5CB94 80242454 0C0B1EAF */  jal       get_variable
/* C5CB98 80242458 26100004 */   addiu    $s0, $s0, 4
/* C5CB9C 8024245C AE22008C */  sw        $v0, 0x8c($s1)
/* C5CBA0 80242460 8E050000 */  lw        $a1, ($s0)
/* C5CBA4 80242464 26100004 */  addiu     $s0, $s0, 4
/* C5CBA8 80242468 0C0B1EAF */  jal       get_variable
/* C5CBAC 8024246C 0220202D */   daddu    $a0, $s1, $zero
/* C5CBB0 80242470 AE220090 */  sw        $v0, 0x90($s1)
/* C5CBB4 80242474 8E050000 */  lw        $a1, ($s0)
/* C5CBB8 80242478 26100004 */  addiu     $s0, $s0, 4
/* C5CBBC 8024247C 0C0B1EAF */  jal       get_variable
/* C5CBC0 80242480 0220202D */   daddu    $a0, $s1, $zero
/* C5CBC4 80242484 AE220094 */  sw        $v0, 0x94($s1)
/* C5CBC8 80242488 8E050000 */  lw        $a1, ($s0)
/* C5CBCC 8024248C 26100004 */  addiu     $s0, $s0, 4
/* C5CBD0 80242490 0C0B1EAF */  jal       get_variable
/* C5CBD4 80242494 0220202D */   daddu    $a0, $s1, $zero
/* C5CBD8 80242498 AE220098 */  sw        $v0, 0x98($s1)
/* C5CBDC 8024249C 8E050000 */  lw        $a1, ($s0)
/* C5CBE0 802424A0 26100004 */  addiu     $s0, $s0, 4
/* C5CBE4 802424A4 0C0B1EAF */  jal       get_variable
/* C5CBE8 802424A8 0220202D */   daddu    $a0, $s1, $zero
/* C5CBEC 802424AC AE22009C */  sw        $v0, 0x9c($s1)
/* C5CBF0 802424B0 8E050000 */  lw        $a1, ($s0)
/* C5CBF4 802424B4 26100004 */  addiu     $s0, $s0, 4
/* C5CBF8 802424B8 0C0B1EAF */  jal       get_variable
/* C5CBFC 802424BC 0220202D */   daddu    $a0, $s1, $zero
/* C5CC00 802424C0 AE2200A0 */  sw        $v0, 0xa0($s1)
/* C5CC04 802424C4 8E050000 */  lw        $a1, ($s0)
/* C5CC08 802424C8 26100004 */  addiu     $s0, $s0, 4
/* C5CC0C 802424CC 0C0B1EAF */  jal       get_variable
/* C5CC10 802424D0 0220202D */   daddu    $a0, $s1, $zero
/* C5CC14 802424D4 AE2200A4 */  sw        $v0, 0xa4($s1)
/* C5CC18 802424D8 8E050000 */  lw        $a1, ($s0)
/* C5CC1C 802424DC 26100004 */  addiu     $s0, $s0, 4
/* C5CC20 802424E0 0C0B1EAF */  jal       get_variable
/* C5CC24 802424E4 0220202D */   daddu    $a0, $s1, $zero
/* C5CC28 802424E8 AE2200A8 */  sw        $v0, 0xa8($s1)
/* C5CC2C 802424EC 8E050000 */  lw        $a1, ($s0)
/* C5CC30 802424F0 26100004 */  addiu     $s0, $s0, 4
/* C5CC34 802424F4 0C0B1EAF */  jal       get_variable
/* C5CC38 802424F8 0220202D */   daddu    $a0, $s1, $zero
/* C5CC3C 802424FC AE2200AC */  sw        $v0, 0xac($s1)
/* C5CC40 80242500 8E050000 */  lw        $a1, ($s0)
/* C5CC44 80242504 0C0B1EAF */  jal       get_variable
/* C5CC48 80242508 0220202D */   daddu    $a0, $s1, $zero
/* C5CC4C 8024250C AE2200B0 */  sw        $v0, 0xb0($s1)
/* C5CC50 80242510 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5CC54 80242514 8FB10014 */  lw        $s1, 0x14($sp)
/* C5CC58 80242518 8FB00010 */  lw        $s0, 0x10($sp)
/* C5CC5C 8024251C 24020002 */  addiu     $v0, $zero, 2
/* C5CC60 80242520 03E00008 */  jr        $ra
/* C5CC64 80242524 27BD0020 */   addiu    $sp, $sp, 0x20
