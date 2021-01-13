.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183F8_47F4A8
/* 47F4A8 802183F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 47F4AC 802183FC AFB10014 */  sw        $s1, 0x14($sp)
/* 47F4B0 80218400 0080882D */  daddu     $s1, $a0, $zero
/* 47F4B4 80218404 AFBF0018 */  sw        $ra, 0x18($sp)
/* 47F4B8 80218408 AFB00010 */  sw        $s0, 0x10($sp)
/* 47F4BC 8021840C 8E30000C */  lw        $s0, 0xc($s1)
/* 47F4C0 80218410 8E050000 */  lw        $a1, ($s0)
/* 47F4C4 80218414 0C0B1EAF */  jal       get_variable
/* 47F4C8 80218418 26100004 */   addiu    $s0, $s0, 4
/* 47F4CC 8021841C 0040202D */  daddu     $a0, $v0, $zero
/* 47F4D0 80218420 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 47F4D4 80218424 14820002 */  bne       $a0, $v0, .L80218430
/* 47F4D8 80218428 00000000 */   nop
/* 47F4DC 8021842C 8E240148 */  lw        $a0, 0x148($s1)
.L80218430:
/* 47F4E0 80218430 0C09A75B */  jal       get_actor
/* 47F4E4 80218434 00000000 */   nop
/* 47F4E8 80218438 0040202D */  daddu     $a0, $v0, $zero
/* 47F4EC 8021843C 90830136 */  lbu       $v1, 0x136($a0)
/* 47F4F0 80218440 24020047 */  addiu     $v0, $zero, 0x47
/* 47F4F4 80218444 1062000B */  beq       $v1, $v0, .L80218474
/* 47F4F8 80218448 0062102A */   slt      $v0, $v1, $v0
/* 47F4FC 8021844C 54400011 */  bnel      $v0, $zero, .L80218494
/* 47F500 80218450 0220202D */   daddu    $a0, $s1, $zero
/* 47F504 80218454 28620065 */  slti      $v0, $v1, 0x65
/* 47F508 80218458 1040000D */  beqz      $v0, .L80218490
/* 47F50C 8021845C 2862004D */   slti     $v0, $v1, 0x4d
/* 47F510 80218460 1440000C */  bnez      $v0, .L80218494
/* 47F514 80218464 0220202D */   daddu    $a0, $s1, $zero
/* 47F518 80218468 8E050000 */  lw        $a1, ($s0)
/* 47F51C 8021846C 08086127 */  j         .L8021849C
/* 47F520 80218470 2406FFFF */   addiu    $a2, $zero, -1
.L80218474:
/* 47F524 80218474 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 47F528 80218478 24020001 */  addiu     $v0, $zero, 1
/* 47F52C 8021847C 14620005 */  bne       $v1, $v0, .L80218494
/* 47F530 80218480 0220202D */   daddu    $a0, $s1, $zero
/* 47F534 80218484 8E050000 */  lw        $a1, ($s0)
/* 47F538 80218488 08086127 */  j         .L8021849C
/* 47F53C 8021848C 2406FFFF */   addiu    $a2, $zero, -1
.L80218490:
/* 47F540 80218490 0220202D */  daddu     $a0, $s1, $zero
.L80218494:
/* 47F544 80218494 8E050000 */  lw        $a1, ($s0)
/* 47F548 80218498 0000302D */  daddu     $a2, $zero, $zero
.L8021849C:
/* 47F54C 8021849C 0C0B2026 */  jal       set_variable
/* 47F550 802184A0 00000000 */   nop
/* 47F554 802184A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 47F558 802184A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 47F55C 802184AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 47F560 802184B0 24020002 */  addiu     $v0, $zero, 2
/* 47F564 802184B4 03E00008 */  jr        $ra
/* 47F568 802184B8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 47F56C 802184BC 00000000 */  nop
