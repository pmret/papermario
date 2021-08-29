.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218EE8_5B2398
/* 5B2398 80218EE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B239C 80218EEC AFB10014 */  sw        $s1, 0x14($sp)
/* 5B23A0 80218EF0 0080882D */  daddu     $s1, $a0, $zero
/* 5B23A4 80218EF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B23A8 80218EF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B23AC 80218EFC 8E30000C */  lw        $s0, 0xc($s1)
/* 5B23B0 80218F00 8E050000 */  lw        $a1, ($s0)
/* 5B23B4 80218F04 0C0B1EAF */  jal       get_variable
/* 5B23B8 80218F08 26100004 */   addiu    $s0, $s0, 4
/* 5B23BC 80218F0C 0040202D */  daddu     $a0, $v0, $zero
/* 5B23C0 80218F10 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 5B23C4 80218F14 14820002 */  bne       $a0, $v0, .L80218F20
/* 5B23C8 80218F18 00000000 */   nop
/* 5B23CC 80218F1C 8E240148 */  lw        $a0, 0x148($s1)
.L80218F20:
/* 5B23D0 80218F20 0C09A75B */  jal       get_actor
/* 5B23D4 80218F24 00000000 */   nop
/* 5B23D8 80218F28 0040202D */  daddu     $a0, $v0, $zero
/* 5B23DC 80218F2C 90830136 */  lbu       $v1, 0x136($a0)
/* 5B23E0 80218F30 24020047 */  addiu     $v0, $zero, 0x47
/* 5B23E4 80218F34 1062000B */  beq       $v1, $v0, .L80218F64
/* 5B23E8 80218F38 0062102A */   slt      $v0, $v1, $v0
/* 5B23EC 80218F3C 54400011 */  bnel      $v0, $zero, .L80218F84
/* 5B23F0 80218F40 0220202D */   daddu    $a0, $s1, $zero
/* 5B23F4 80218F44 28620065 */  slti      $v0, $v1, 0x65
/* 5B23F8 80218F48 1040000D */  beqz      $v0, .L80218F80
/* 5B23FC 80218F4C 2862004D */   slti     $v0, $v1, 0x4d
/* 5B2400 80218F50 1440000C */  bnez      $v0, .L80218F84
/* 5B2404 80218F54 0220202D */   daddu    $a0, $s1, $zero
/* 5B2408 80218F58 8E050000 */  lw        $a1, ($s0)
/* 5B240C 80218F5C 080863E3 */  j         .L80218F8C
/* 5B2410 80218F60 2406FFFF */   addiu    $a2, $zero, -1
.L80218F64:
/* 5B2414 80218F64 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 5B2418 80218F68 24020001 */  addiu     $v0, $zero, 1
/* 5B241C 80218F6C 14620005 */  bne       $v1, $v0, .L80218F84
/* 5B2420 80218F70 0220202D */   daddu    $a0, $s1, $zero
/* 5B2424 80218F74 8E050000 */  lw        $a1, ($s0)
/* 5B2428 80218F78 080863E3 */  j         .L80218F8C
/* 5B242C 80218F7C 2406FFFF */   addiu    $a2, $zero, -1
.L80218F80:
/* 5B2430 80218F80 0220202D */  daddu     $a0, $s1, $zero
.L80218F84:
/* 5B2434 80218F84 8E050000 */  lw        $a1, ($s0)
/* 5B2438 80218F88 0000302D */  daddu     $a2, $zero, $zero
.L80218F8C:
/* 5B243C 80218F8C 0C0B2026 */  jal       evt_set_variable
/* 5B2440 80218F90 00000000 */   nop
/* 5B2444 80218F94 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B2448 80218F98 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B244C 80218F9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B2450 80218FA0 24020002 */  addiu     $v0, $zero, 2
/* 5B2454 80218FA4 03E00008 */  jr        $ra
/* 5B2458 80218FA8 27BD0020 */   addiu    $sp, $sp, 0x20
