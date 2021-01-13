.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021B3B4_6A25B4
/* 6A25B4 8021B3B4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 6A25B8 8021B3B8 AFB3002C */  sw        $s3, 0x2c($sp)
/* 6A25BC 8021B3BC 0080982D */  daddu     $s3, $a0, $zero
/* 6A25C0 8021B3C0 AFB00020 */  sw        $s0, 0x20($sp)
/* 6A25C4 8021B3C4 0000802D */  daddu     $s0, $zero, $zero
/* 6A25C8 8021B3C8 AFB20028 */  sw        $s2, 0x28($sp)
/* 6A25CC 8021B3CC 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 6A25D0 8021B3D0 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 6A25D4 8021B3D4 AFB40030 */  sw        $s4, 0x30($sp)
/* 6A25D8 8021B3D8 3C148011 */  lui       $s4, %hi(gPlayerData)
/* 6A25DC 8021B3DC 2694F290 */  addiu     $s4, $s4, %lo(gPlayerData)
/* 6A25E0 8021B3E0 AFB50034 */  sw        $s5, 0x34($sp)
/* 6A25E4 8021B3E4 2404FFFF */  addiu     $a0, $zero, -1
/* 6A25E8 8021B3E8 AFBF0038 */  sw        $ra, 0x38($sp)
/* 6A25EC 8021B3EC AFB10024 */  sw        $s1, 0x24($sp)
/* 6A25F0 8021B3F0 824200AE */  lb        $v0, 0xae($s2)
/* 6A25F4 8021B3F4 8E71000C */  lw        $s1, 0xc($s3)
/* 6A25F8 8021B3F8 14440003 */  bne       $v0, $a0, .L8021B408
/* 6A25FC 8021B3FC 0280A82D */   daddu    $s5, $s4, $zero
/* 6A2600 8021B400 AFA00010 */  sw        $zero, 0x10($sp)
/* 6A2604 8021B404 24100001 */  addiu     $s0, $zero, 1
.L8021B408:
/* 6A2608 8021B408 824200AF */  lb        $v0, 0xaf($s2)
/* 6A260C 8021B40C 14440005 */  bne       $v0, $a0, .L8021B424
/* 6A2610 8021B410 00101080 */   sll      $v0, $s0, 2
/* 6A2614 8021B414 03A21821 */  addu      $v1, $sp, $v0
/* 6A2618 8021B418 24020001 */  addiu     $v0, $zero, 1
/* 6A261C 8021B41C AC620010 */  sw        $v0, 0x10($v1)
/* 6A2620 8021B420 02028021 */  addu      $s0, $s0, $v0
.L8021B424:
/* 6A2624 8021B424 824200B0 */  lb        $v0, 0xb0($s2)
/* 6A2628 8021B428 14440005 */  bne       $v0, $a0, .L8021B440
/* 6A262C 8021B42C 00101080 */   sll      $v0, $s0, 2
/* 6A2630 8021B430 03A21821 */  addu      $v1, $sp, $v0
/* 6A2634 8021B434 24020002 */  addiu     $v0, $zero, 2
/* 6A2638 8021B438 AC620010 */  sw        $v0, 0x10($v1)
/* 6A263C 8021B43C 26100001 */  addiu     $s0, $s0, 1
.L8021B440:
/* 6A2640 8021B440 0C00A67F */  jal       rand_int
/* 6A2644 8021B444 24040002 */   addiu    $a0, $zero, 2
/* 6A2648 8021B448 2604FFFF */  addiu     $a0, $s0, -1
/* 6A264C 8021B44C 0C00A67F */  jal       rand_int
/* 6A2650 8021B450 24500002 */   addiu    $s0, $v0, 2
/* 6A2654 8021B454 00021080 */  sll       $v0, $v0, 2
/* 6A2658 8021B458 03A21021 */  addu      $v0, $sp, $v0
/* 6A265C 8021B45C 8C430010 */  lw        $v1, 0x10($v0)
/* 6A2660 8021B460 24020001 */  addiu     $v0, $zero, 1
/* 6A2664 8021B464 1062001C */  beq       $v1, $v0, .L8021B4D8
/* 6A2668 8021B468 28620002 */   slti     $v0, $v1, 2
/* 6A266C 8021B46C 10400005 */  beqz      $v0, .L8021B484
/* 6A2670 8021B470 24020002 */   addiu    $v0, $zero, 2
/* 6A2674 8021B474 50600007 */  beql      $v1, $zero, .L8021B494
/* 6A2678 8021B478 A25000AE */   sb       $s0, 0xae($s2)
/* 6A267C 8021B47C 08086D52 */  j         .L8021B548
/* 6A2680 8021B480 00000000 */   nop
.L8021B484:
/* 6A2684 8021B484 50620026 */  beql      $v1, $v0, .L8021B520
/* 6A2688 8021B488 A25000B0 */   sb       $s0, 0xb0($s2)
/* 6A268C 8021B48C 08086D52 */  j         .L8021B548
/* 6A2690 8021B490 00000000 */   nop
.L8021B494:
/* 6A2694 8021B494 8E250000 */  lw        $a1, ($s1)
/* 6A2698 8021B498 82820001 */  lb        $v0, 1($s4)
/* 6A269C 8021B49C 26310004 */  addiu     $s1, $s1, 4
/* 6A26A0 8021B4A0 00021080 */  sll       $v0, $v0, 2
/* 6A26A4 8021B4A4 3C068023 */  lui       $a2, %hi(D_80229EBC)
/* 6A26A8 8021B4A8 00C23021 */  addu      $a2, $a2, $v0
/* 6A26AC 8021B4AC 8CC69EBC */  lw        $a2, %lo(D_80229EBC)($a2)
/* 6A26B0 8021B4B0 0C0B2026 */  jal       set_variable
/* 6A26B4 8021B4B4 0260202D */   daddu    $a0, $s3, $zero
/* 6A26B8 8021B4B8 82820001 */  lb        $v0, 1($s4)
/* 6A26BC 8021B4BC 8E250000 */  lw        $a1, ($s1)
/* 6A26C0 8021B4C0 00021080 */  sll       $v0, $v0, 2
/* 6A26C4 8021B4C4 3C068023 */  lui       $a2, %hi(D_80229EC8)
/* 6A26C8 8021B4C8 00C23021 */  addu      $a2, $a2, $v0
/* 6A26CC 8021B4CC 8CC69EC8 */  lw        $a2, %lo(D_80229EC8)($a2)
/* 6A26D0 8021B4D0 08086D50 */  j         .L8021B540
/* 6A26D4 8021B4D4 0260202D */   daddu    $a0, $s3, $zero
.L8021B4D8:
/* 6A26D8 8021B4D8 A25000AF */  sb        $s0, 0xaf($s2)
/* 6A26DC 8021B4DC 8E250000 */  lw        $a1, ($s1)
/* 6A26E0 8021B4E0 82A20000 */  lb        $v0, ($s5)
/* 6A26E4 8021B4E4 26310004 */  addiu     $s1, $s1, 4
/* 6A26E8 8021B4E8 00021080 */  sll       $v0, $v0, 2
/* 6A26EC 8021B4EC 3C068023 */  lui       $a2, %hi(D_80229ED4)
/* 6A26F0 8021B4F0 00C23021 */  addu      $a2, $a2, $v0
/* 6A26F4 8021B4F4 8CC69ED4 */  lw        $a2, %lo(D_80229ED4)($a2)
/* 6A26F8 8021B4F8 0C0B2026 */  jal       set_variable
/* 6A26FC 8021B4FC 0260202D */   daddu    $a0, $s3, $zero
/* 6A2700 8021B500 82A20000 */  lb        $v0, ($s5)
/* 6A2704 8021B504 8E250000 */  lw        $a1, ($s1)
/* 6A2708 8021B508 00021080 */  sll       $v0, $v0, 2
/* 6A270C 8021B50C 3C068023 */  lui       $a2, %hi(D_80229EE0)
/* 6A2710 8021B510 00C23021 */  addu      $a2, $a2, $v0
/* 6A2714 8021B514 8CC69EE0 */  lw        $a2, %lo(D_80229EE0)($a2)
/* 6A2718 8021B518 08086D50 */  j         .L8021B540
/* 6A271C 8021B51C 0260202D */   daddu    $a0, $s3, $zero
.L8021B520:
/* 6A2720 8021B520 8E250000 */  lw        $a1, ($s1)
/* 6A2724 8021B524 26310004 */  addiu     $s1, $s1, 4
/* 6A2728 8021B528 0260202D */  daddu     $a0, $s3, $zero
/* 6A272C 8021B52C 0C0B2026 */  jal       set_variable
/* 6A2730 8021B530 2406016C */   addiu    $a2, $zero, 0x16c
/* 6A2734 8021B534 0260202D */  daddu     $a0, $s3, $zero
/* 6A2738 8021B538 8E250000 */  lw        $a1, ($s1)
/* 6A273C 8021B53C 2406004F */  addiu     $a2, $zero, 0x4f
.L8021B540:
/* 6A2740 8021B540 0C0B2026 */  jal       set_variable
/* 6A2744 8021B544 00000000 */   nop
.L8021B548:
/* 6A2748 8021B548 8FBF0038 */  lw        $ra, 0x38($sp)
/* 6A274C 8021B54C 8FB50034 */  lw        $s5, 0x34($sp)
/* 6A2750 8021B550 8FB40030 */  lw        $s4, 0x30($sp)
/* 6A2754 8021B554 8FB3002C */  lw        $s3, 0x2c($sp)
/* 6A2758 8021B558 8FB20028 */  lw        $s2, 0x28($sp)
/* 6A275C 8021B55C 8FB10024 */  lw        $s1, 0x24($sp)
/* 6A2760 8021B560 8FB00020 */  lw        $s0, 0x20($sp)
/* 6A2764 8021B564 24020002 */  addiu     $v0, $zero, 2
/* 6A2768 8021B568 03E00008 */  jr        $ra
/* 6A276C 8021B56C 27BD0040 */   addiu    $sp, $sp, 0x40
