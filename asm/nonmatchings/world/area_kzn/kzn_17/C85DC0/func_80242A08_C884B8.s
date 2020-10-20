.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242A08_C884B8
/* C884B8 80242A08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C884BC 80242A0C AFB10014 */  sw        $s1, 0x14($sp)
/* C884C0 80242A10 0080882D */  daddu     $s1, $a0, $zero
/* C884C4 80242A14 AFBF0018 */  sw        $ra, 0x18($sp)
/* C884C8 80242A18 AFB00010 */  sw        $s0, 0x10($sp)
/* C884CC 80242A1C 8E30000C */  lw        $s0, 0xc($s1)
/* C884D0 80242A20 8E050000 */  lw        $a1, ($s0)
/* C884D4 80242A24 0C0B1EAF */  jal       get_variable
/* C884D8 80242A28 26100004 */   addiu    $s0, $s0, 4
/* C884DC 80242A2C AE22008C */  sw        $v0, 0x8c($s1)
/* C884E0 80242A30 8E050000 */  lw        $a1, ($s0)
/* C884E4 80242A34 26100004 */  addiu     $s0, $s0, 4
/* C884E8 80242A38 0C0B1EAF */  jal       get_variable
/* C884EC 80242A3C 0220202D */   daddu    $a0, $s1, $zero
/* C884F0 80242A40 AE220090 */  sw        $v0, 0x90($s1)
/* C884F4 80242A44 8E050000 */  lw        $a1, ($s0)
/* C884F8 80242A48 26100004 */  addiu     $s0, $s0, 4
/* C884FC 80242A4C 0C0B1EAF */  jal       get_variable
/* C88500 80242A50 0220202D */   daddu    $a0, $s1, $zero
/* C88504 80242A54 AE220094 */  sw        $v0, 0x94($s1)
/* C88508 80242A58 8E050000 */  lw        $a1, ($s0)
/* C8850C 80242A5C 26100004 */  addiu     $s0, $s0, 4
/* C88510 80242A60 0C0B1EAF */  jal       get_variable
/* C88514 80242A64 0220202D */   daddu    $a0, $s1, $zero
/* C88518 80242A68 AE220098 */  sw        $v0, 0x98($s1)
/* C8851C 80242A6C 8E050000 */  lw        $a1, ($s0)
/* C88520 80242A70 26100004 */  addiu     $s0, $s0, 4
/* C88524 80242A74 0C0B1EAF */  jal       get_variable
/* C88528 80242A78 0220202D */   daddu    $a0, $s1, $zero
/* C8852C 80242A7C AE22009C */  sw        $v0, 0x9c($s1)
/* C88530 80242A80 8E050000 */  lw        $a1, ($s0)
/* C88534 80242A84 26100004 */  addiu     $s0, $s0, 4
/* C88538 80242A88 0C0B1EAF */  jal       get_variable
/* C8853C 80242A8C 0220202D */   daddu    $a0, $s1, $zero
/* C88540 80242A90 AE2200A0 */  sw        $v0, 0xa0($s1)
/* C88544 80242A94 8E050000 */  lw        $a1, ($s0)
/* C88548 80242A98 26100004 */  addiu     $s0, $s0, 4
/* C8854C 80242A9C 0C0B1EAF */  jal       get_variable
/* C88550 80242AA0 0220202D */   daddu    $a0, $s1, $zero
/* C88554 80242AA4 AE2200A4 */  sw        $v0, 0xa4($s1)
/* C88558 80242AA8 8E050000 */  lw        $a1, ($s0)
/* C8855C 80242AAC 26100004 */  addiu     $s0, $s0, 4
/* C88560 80242AB0 0C0B1EAF */  jal       get_variable
/* C88564 80242AB4 0220202D */   daddu    $a0, $s1, $zero
/* C88568 80242AB8 AE2200A8 */  sw        $v0, 0xa8($s1)
/* C8856C 80242ABC 8E050000 */  lw        $a1, ($s0)
/* C88570 80242AC0 26100004 */  addiu     $s0, $s0, 4
/* C88574 80242AC4 0C0B1EAF */  jal       get_variable
/* C88578 80242AC8 0220202D */   daddu    $a0, $s1, $zero
/* C8857C 80242ACC AE2200AC */  sw        $v0, 0xac($s1)
/* C88580 80242AD0 8E050000 */  lw        $a1, ($s0)
/* C88584 80242AD4 0C0B1EAF */  jal       get_variable
/* C88588 80242AD8 0220202D */   daddu    $a0, $s1, $zero
/* C8858C 80242ADC AE2200B0 */  sw        $v0, 0xb0($s1)
/* C88590 80242AE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C88594 80242AE4 8FB10014 */  lw        $s1, 0x14($sp)
/* C88598 80242AE8 8FB00010 */  lw        $s0, 0x10($sp)
/* C8859C 80242AEC 24020002 */  addiu     $v0, $zero, 2
/* C885A0 80242AF0 03E00008 */  jr        $ra
/* C885A4 80242AF4 27BD0020 */   addiu    $sp, $sp, 0x20
