.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242424_8B2494
/* 8B2494 80242424 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B2498 80242428 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B249C 8024242C 0080882D */  daddu     $s1, $a0, $zero
/* 8B24A0 80242430 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B24A4 80242434 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B24A8 80242438 8E30000C */  lw        $s0, 0xc($s1)
/* 8B24AC 8024243C 8E050000 */  lw        $a1, ($s0)
/* 8B24B0 80242440 0C0B1EAF */  jal       get_variable
/* 8B24B4 80242444 26100004 */   addiu    $s0, $s0, 4
/* 8B24B8 80242448 AE22008C */  sw        $v0, 0x8c($s1)
/* 8B24BC 8024244C 8E050000 */  lw        $a1, ($s0)
/* 8B24C0 80242450 26100004 */  addiu     $s0, $s0, 4
/* 8B24C4 80242454 0C0B1EAF */  jal       get_variable
/* 8B24C8 80242458 0220202D */   daddu    $a0, $s1, $zero
/* 8B24CC 8024245C AE220090 */  sw        $v0, 0x90($s1)
/* 8B24D0 80242460 8E050000 */  lw        $a1, ($s0)
/* 8B24D4 80242464 26100004 */  addiu     $s0, $s0, 4
/* 8B24D8 80242468 0C0B1EAF */  jal       get_variable
/* 8B24DC 8024246C 0220202D */   daddu    $a0, $s1, $zero
/* 8B24E0 80242470 AE220094 */  sw        $v0, 0x94($s1)
/* 8B24E4 80242474 8E050000 */  lw        $a1, ($s0)
/* 8B24E8 80242478 26100004 */  addiu     $s0, $s0, 4
/* 8B24EC 8024247C 0C0B1EAF */  jal       get_variable
/* 8B24F0 80242480 0220202D */   daddu    $a0, $s1, $zero
/* 8B24F4 80242484 AE220098 */  sw        $v0, 0x98($s1)
/* 8B24F8 80242488 8E050000 */  lw        $a1, ($s0)
/* 8B24FC 8024248C 26100004 */  addiu     $s0, $s0, 4
/* 8B2500 80242490 0C0B1EAF */  jal       get_variable
/* 8B2504 80242494 0220202D */   daddu    $a0, $s1, $zero
/* 8B2508 80242498 AE22009C */  sw        $v0, 0x9c($s1)
/* 8B250C 8024249C 8E050000 */  lw        $a1, ($s0)
/* 8B2510 802424A0 26100004 */  addiu     $s0, $s0, 4
/* 8B2514 802424A4 0C0B1EAF */  jal       get_variable
/* 8B2518 802424A8 0220202D */   daddu    $a0, $s1, $zero
/* 8B251C 802424AC AE2200A0 */  sw        $v0, 0xa0($s1)
/* 8B2520 802424B0 8E050000 */  lw        $a1, ($s0)
/* 8B2524 802424B4 26100004 */  addiu     $s0, $s0, 4
/* 8B2528 802424B8 0C0B1EAF */  jal       get_variable
/* 8B252C 802424BC 0220202D */   daddu    $a0, $s1, $zero
/* 8B2530 802424C0 AE2200A4 */  sw        $v0, 0xa4($s1)
/* 8B2534 802424C4 8E050000 */  lw        $a1, ($s0)
/* 8B2538 802424C8 26100004 */  addiu     $s0, $s0, 4
/* 8B253C 802424CC 0C0B1EAF */  jal       get_variable
/* 8B2540 802424D0 0220202D */   daddu    $a0, $s1, $zero
/* 8B2544 802424D4 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 8B2548 802424D8 8E050000 */  lw        $a1, ($s0)
/* 8B254C 802424DC 26100004 */  addiu     $s0, $s0, 4
/* 8B2550 802424E0 0C0B1EAF */  jal       get_variable
/* 8B2554 802424E4 0220202D */   daddu    $a0, $s1, $zero
/* 8B2558 802424E8 AE2200AC */  sw        $v0, 0xac($s1)
/* 8B255C 802424EC 8E050000 */  lw        $a1, ($s0)
/* 8B2560 802424F0 0C0B1EAF */  jal       get_variable
/* 8B2564 802424F4 0220202D */   daddu    $a0, $s1, $zero
/* 8B2568 802424F8 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 8B256C 802424FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B2570 80242500 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B2574 80242504 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B2578 80242508 24020002 */  addiu     $v0, $zero, 2
/* 8B257C 8024250C 03E00008 */  jr        $ra
/* 8B2580 80242510 27BD0020 */   addiu    $sp, $sp, 0x20
