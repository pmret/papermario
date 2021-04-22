.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8010C330
.word L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F13F8_8A8A8, L800F1414_8A8C4, L800F1414_8A8C4, L800F13F8_8A8A8, L800F1414_8A8C4

glabel jtbl_8010C368
.word L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F145C_8A90C, L800F1470_8A920, L800F1470_8A920, L800F145C_8A90C, L800F1470_8A920

.section .text

glabel func_800F13B0
/* 8A860 800F13B0 3C028011 */  lui       $v0, %hi(D_8010D68E)
/* 8A864 800F13B4 8042D68E */  lb        $v0, %lo(D_8010D68E)($v0)
/* 8A868 800F13B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A86C 800F13BC AFBF0018 */  sw        $ra, 0x18($sp)
/* 8A870 800F13C0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A874 800F13C4 1040001A */  beqz      $v0, .L800F1430
/* 8A878 800F13C8 AFB00010 */   sw       $s0, 0x10($sp)
/* 8A87C 800F13CC 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8A880 800F13D0 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8A884 800F13D4 8C430318 */  lw        $v1, 0x318($v0)
/* 8A888 800F13D8 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8A88C 800F13DC 10400012 */  beqz      $v0, .L800F1428
/* 8A890 800F13E0 00031080 */   sll      $v0, $v1, 2
/* 8A894 800F13E4 3C018011 */  lui       $at, %hi(jtbl_8010C330)
/* 8A898 800F13E8 00220821 */  addu      $at, $at, $v0
/* 8A89C 800F13EC 8C22C330 */  lw        $v0, %lo(jtbl_8010C330)($at)
/* 8A8A0 800F13F0 00400008 */  jr        $v0
/* 8A8A4 800F13F4 00000000 */   nop
glabel L800F13F8_8A8A8
/* 8A8A8 800F13F8 2404000E */  addiu     $a0, $zero, 0xe
/* 8A8AC 800F13FC 3C108014 */  lui       $s0, %hi(basic_hidden_window_update)
/* 8A8B0 800F1400 26107574 */  addiu     $s0, $s0, %lo(basic_hidden_window_update)
/* 8A8B4 800F1404 0C051F9F */  jal       set_window_update
/* 8A8B8 800F1408 0200282D */   daddu    $a1, $s0, $zero
/* 8A8BC 800F140C 0803C506 */  j         .L800F1418
/* 8A8C0 800F1410 24040013 */   addiu    $a0, $zero, 0x13
glabel L800F1414_8A8C4
/* 8A8C4 800F1414 2404000E */  addiu     $a0, $zero, 0xe
.L800F1418:
/* 8A8C8 800F1418 3C058014 */  lui       $a1, %hi(basic_hidden_window_update)
/* 8A8CC 800F141C 24A57574 */  addiu     $a1, $a1, %lo(basic_hidden_window_update)
/* 8A8D0 800F1420 0C051F9F */  jal       set_window_update
/* 8A8D4 800F1424 00000000 */   nop
.L800F1428:
/* 8A8D8 800F1428 0803C51D */  j         .L800F1474
/* 8A8DC 800F142C 24040015 */   addiu    $a0, $zero, 0x15
.L800F1430:
/* 8A8E0 800F1430 3C028011 */  lui       $v0, %hi(D_8010D69C)
/* 8A8E4 800F1434 8C42D69C */  lw        $v0, %lo(D_8010D69C)($v0)
/* 8A8E8 800F1438 8C430318 */  lw        $v1, 0x318($v0)
/* 8A8EC 800F143C 2C62000E */  sltiu     $v0, $v1, 0xe
/* 8A8F0 800F1440 1040000E */  beqz      $v0, .L800F147C
/* 8A8F4 800F1444 00031080 */   sll      $v0, $v1, 2
/* 8A8F8 800F1448 3C018011 */  lui       $at, %hi(jtbl_8010C368)
/* 8A8FC 800F144C 00220821 */  addu      $at, $at, $v0
/* 8A900 800F1450 8C22C368 */  lw        $v0, %lo(jtbl_8010C368)($at)
/* 8A904 800F1454 00400008 */  jr        $v0
/* 8A908 800F1458 00000000 */   nop
glabel L800F145C_8A90C
/* 8A90C 800F145C 2404000E */  addiu     $a0, $zero, 0xe
/* 8A910 800F1460 0C051F9F */  jal       set_window_update
/* 8A914 800F1464 24050002 */   addiu    $a1, $zero, 2
/* 8A918 800F1468 0803C51D */  j         .L800F1474
/* 8A91C 800F146C 24040013 */   addiu    $a0, $zero, 0x13
glabel L800F1470_8A920
/* 8A920 800F1470 2404000E */  addiu     $a0, $zero, 0xe
.L800F1474:
/* 8A924 800F1474 0C051F9F */  jal       set_window_update
/* 8A928 800F1478 24050002 */   addiu    $a1, $zero, 2
.L800F147C:
/* 8A92C 800F147C 3C118011 */  lui       $s1, %hi(D_8010D69C)
/* 8A930 800F1480 2631D69C */  addiu     $s1, $s1, %lo(D_8010D69C)
/* 8A934 800F1484 8E220000 */  lw        $v0, ($s1)
/* 8A938 800F1488 8C430318 */  lw        $v1, 0x318($v0)
/* 8A93C 800F148C 24020003 */  addiu     $v0, $zero, 3
/* 8A940 800F1490 14620008 */  bne       $v1, $v0, .L800F14B4
/* 8A944 800F1494 24040010 */   addiu    $a0, $zero, 0x10
/* 8A948 800F1498 3C108014 */  lui       $s0, %hi(basic_hidden_window_update)
/* 8A94C 800F149C 26107574 */  addiu     $s0, $s0, %lo(basic_hidden_window_update)
/* 8A950 800F14A0 0C051F9F */  jal       set_window_update
/* 8A954 800F14A4 0200282D */   daddu    $a1, $s0, $zero
/* 8A958 800F14A8 24040014 */  addiu     $a0, $zero, 0x14
/* 8A95C 800F14AC 0C051F9F */  jal       set_window_update
/* 8A960 800F14B0 0200282D */   daddu    $a1, $s0, $zero
.L800F14B4:
/* 8A964 800F14B4 8E220000 */  lw        $v0, ($s1)
/* 8A968 800F14B8 8C430318 */  lw        $v1, 0x318($v0)
/* 8A96C 800F14BC 24020004 */  addiu     $v0, $zero, 4
/* 8A970 800F14C0 14620005 */  bne       $v1, $v0, .L800F14D8
/* 8A974 800F14C4 00000000 */   nop
/* 8A978 800F14C8 3C058014 */  lui       $a1, %hi(basic_hidden_window_update)
/* 8A97C 800F14CC 24A57574 */  addiu     $a1, $a1, %lo(basic_hidden_window_update)
/* 8A980 800F14D0 0C051F9F */  jal       set_window_update
/* 8A984 800F14D4 24040012 */   addiu    $a0, $zero, 0x12
.L800F14D8:
/* 8A988 800F14D8 8E220000 */  lw        $v0, ($s1)
/* 8A98C 800F14DC 8C430318 */  lw        $v1, 0x318($v0)
/* 8A990 800F14E0 24020005 */  addiu     $v0, $zero, 5
/* 8A994 800F14E4 14620008 */  bne       $v1, $v0, .L800F1508
/* 8A998 800F14E8 24040010 */   addiu    $a0, $zero, 0x10
/* 8A99C 800F14EC 3C108014 */  lui       $s0, %hi(basic_hidden_window_update)
/* 8A9A0 800F14F0 26107574 */  addiu     $s0, $s0, %lo(basic_hidden_window_update)
/* 8A9A4 800F14F4 0C051F9F */  jal       set_window_update
/* 8A9A8 800F14F8 0200282D */   daddu    $a1, $s0, $zero
/* 8A9AC 800F14FC 24040014 */  addiu     $a0, $zero, 0x14
/* 8A9B0 800F1500 0C051F9F */  jal       set_window_update
/* 8A9B4 800F1504 0200282D */   daddu    $a1, $s0, $zero
.L800F1508:
/* 8A9B8 800F1508 3C038011 */  lui       $v1, %hi(D_8010D692)
/* 8A9BC 800F150C 8063D692 */  lb        $v1, %lo(D_8010D692)($v1)
/* 8A9C0 800F1510 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8A9C4 800F1514 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A9C8 800F1518 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A9CC 800F151C 2402000A */  addiu     $v0, $zero, 0xa
/* 8A9D0 800F1520 3C018011 */  lui       $at, %hi(D_8010D640)
/* 8A9D4 800F1524 AC22D640 */  sw        $v0, %lo(D_8010D640)($at)
/* 8A9D8 800F1528 3C018011 */  lui       $at, %hi(D_8010D644)
/* 8A9DC 800F152C AC23D644 */  sw        $v1, %lo(D_8010D644)($at)
/* 8A9E0 800F1530 03E00008 */  jr        $ra
/* 8A9E4 800F1534 27BD0020 */   addiu    $sp, $sp, 0x20
