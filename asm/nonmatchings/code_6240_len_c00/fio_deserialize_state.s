.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_deserialize_state
/* 6890 8002B490 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 6894 8002B494 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 6898 8002B498 3C07800E */  lui       $a3, %hi(gCurrentSaveFile)
/* 689C 8002B49C 24E7ACC0 */  addiu     $a3, $a3, %lo(gCurrentSaveFile)
/* 68A0 8002B4A0 24E20040 */  addiu     $v0, $a3, 0x40
/* 68A4 8002B4A4 24E40460 */  addiu     $a0, $a3, 0x460
.L8002B4A8:
/* 68A8 8002B4A8 8C490000 */  lw        $t1, ($v0)
/* 68AC 8002B4AC 8C4A0004 */  lw        $t2, 4($v0)
/* 68B0 8002B4B0 8C4B0008 */  lw        $t3, 8($v0)
/* 68B4 8002B4B4 8C4C000C */  lw        $t4, 0xc($v0)
/* 68B8 8002B4B8 AC690000 */  sw        $t1, ($v1)
/* 68BC 8002B4BC AC6A0004 */  sw        $t2, 4($v1)
/* 68C0 8002B4C0 AC6B0008 */  sw        $t3, 8($v1)
/* 68C4 8002B4C4 AC6C000C */  sw        $t4, 0xc($v1)
/* 68C8 8002B4C8 24420010 */  addiu     $v0, $v0, 0x10
/* 68CC 8002B4CC 1444FFF6 */  bne       $v0, $a0, .L8002B4A8
/* 68D0 8002B4D0 24630010 */   addiu    $v1, $v1, 0x10
/* 68D4 8002B4D4 8C490000 */  lw        $t1, ($v0)
/* 68D8 8002B4D8 8C4A0004 */  lw        $t2, 4($v0)
/* 68DC 8002B4DC AC690000 */  sw        $t1, ($v1)
/* 68E0 8002B4E0 AC6A0004 */  sw        $t2, 4($v1)
/* 68E4 8002B4E4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 68E8 8002B4E8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 68EC 8002B4EC 94E20468 */  lhu       $v0, 0x468($a3)
/* 68F0 8002B4F0 A4620086 */  sh        $v0, 0x86($v1)
/* 68F4 8002B4F4 94E2046A */  lhu       $v0, 0x46a($a3)
/* 68F8 8002B4F8 A462008C */  sh        $v0, 0x8c($v1)
/* 68FC 8002B4FC 94E2046C */  lhu       $v0, 0x46c($a3)
/* 6900 8002B500 A462008E */  sh        $v0, 0x8e($v1)
/* 6904 8002B504 94E212E6 */  lhu       $v0, 0x12e6($a3)
/* 6908 8002B508 A4620160 */  sh        $v0, 0x160($v1)
/* 690C 8002B50C 94E212E8 */  lhu       $v0, 0x12e8($a3)
/* 6910 8002B510 0000302D */  daddu     $a2, $zero, $zero
/* 6914 8002B514 A4620162 */  sh        $v0, 0x162($v1)
/* 6918 8002B518 94E212EA */  lhu       $v0, 0x12ea($a3)
/* 691C 8002B51C 3C08800B */  lui       $t0, %hi(gCurrentEncounter)
/* 6920 8002B520 25080F10 */  addiu     $t0, $t0, %lo(gCurrentEncounter)
/* 6924 8002B524 A4620164 */  sh        $v0, 0x164($v1)
/* 6928 8002B528 0000282D */  daddu     $a1, $zero, $zero
.L8002B52C:
/* 692C 8002B52C 00062080 */  sll       $a0, $a2, 2
.L8002B530:
/* 6930 8002B530 00881821 */  addu      $v1, $a0, $t0
/* 6934 8002B534 00E41021 */  addu      $v0, $a3, $a0
/* 6938 8002B538 8C420470 */  lw        $v0, 0x470($v0)
/* 693C 8002B53C 24A50001 */  addiu     $a1, $a1, 1
/* 6940 8002B540 AC6200B0 */  sw        $v0, 0xb0($v1)
/* 6944 8002B544 28A2003C */  slti      $v0, $a1, 0x3c
/* 6948 8002B548 1440FFF9 */  bnez      $v0, .L8002B530
/* 694C 8002B54C 24840030 */   addiu    $a0, $a0, 0x30
/* 6950 8002B550 24C60001 */  addiu     $a2, $a2, 1
/* 6954 8002B554 28C2000C */  slti      $v0, $a2, 0xc
/* 6958 8002B558 1440FFF4 */  bnez      $v0, .L8002B52C
/* 695C 8002B55C 0000282D */   daddu    $a1, $zero, $zero
/* 6960 8002B560 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 6964 8002B564 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* 6968 8002B568 8C620000 */  lw        $v0, ($v1)
/* 696C 8002B56C A0400074 */  sb        $zero, 0x74($v0)
/* 6970 8002B570 8C620000 */  lw        $v0, ($v1)
/* 6974 8002B574 A0400076 */  sb        $zero, 0x76($v0)
/* 6978 8002B578 8C620000 */  lw        $v0, ($v1)
/* 697C 8002B57C A0400077 */  sb        $zero, 0x77($v0)
/* 6980 8002B580 8C640000 */  lw        $a0, ($v1)
/* 6984 8002B584 24020001 */  addiu     $v0, $zero, 1
/* 6988 8002B588 A082007A */  sb        $v0, 0x7a($a0)
/* 698C 8002B58C 8C620000 */  lw        $v0, ($v1)
/* 6990 8002B590 90430166 */  lbu       $v1, 0x166($v0)
/* 6994 8002B594 00031040 */  sll       $v0, $v1, 1
/* 6998 8002B598 00431021 */  addu      $v0, $v0, $v1
/* 699C 8002B59C 000210C0 */  sll       $v0, $v0, 3
/* 69A0 8002B5A0 8CE912EC */  lw        $t1, 0x12ec($a3)
/* 69A4 8002B5A4 8CEA12F0 */  lw        $t2, 0x12f0($a3)
/* 69A8 8002B5A8 8CEB12F4 */  lw        $t3, 0x12f4($a3)
/* 69AC 8002B5AC 8CEC12F8 */  lw        $t4, 0x12f8($a3)
/* 69B0 8002B5B0 3C018007 */  lui       $at, %hi(D_800779C4)
/* 69B4 8002B5B4 00220821 */  addu      $at, $at, $v0
/* 69B8 8002B5B8 AC2979C4 */  sw        $t1, %lo(D_800779C4)($at)
/* 69BC 8002B5BC 3C018007 */  lui       $at, %hi(D_800779C8)
/* 69C0 8002B5C0 00220821 */  addu      $at, $at, $v0
/* 69C4 8002B5C4 AC2A79C8 */  sw        $t2, %lo(D_800779C8)($at)
/* 69C8 8002B5C8 3C018007 */  lui       $at, %hi(D_800779CC)
/* 69CC 8002B5CC 00220821 */  addu      $at, $at, $v0
/* 69D0 8002B5D0 AC2B79CC */  sw        $t3, %lo(D_800779CC)($at)
/* 69D4 8002B5D4 3C018007 */  lui       $at, %hi(D_800779D0)
/* 69D8 8002B5D8 00220821 */  addu      $at, $at, $v0
/* 69DC 8002B5DC AC2C79D0 */  sw        $t4, %lo(D_800779D0)($at)
/* 69E0 8002B5E0 8CE912FC */  lw        $t1, 0x12fc($a3)
/* 69E4 8002B5E4 8CEA1300 */  lw        $t2, 0x1300($a3)
/* 69E8 8002B5E8 3C018007 */  lui       $at, %hi(D_800779D4)
/* 69EC 8002B5EC 00220821 */  addu      $at, $at, $v0
/* 69F0 8002B5F0 AC2979D4 */  sw        $t1, %lo(D_800779D4)($at)
/* 69F4 8002B5F4 3C018007 */  lui       $at, %hi(D_800779D8)
/* 69F8 8002B5F8 00220821 */  addu      $at, $at, $v0
/* 69FC 8002B5FC AC2A79D8 */  sw        $t2, %lo(D_800779D8)($at)
/* 6A00 8002B600 03E00008 */  jr        $ra
/* 6A04 8002B604 00000000 */   nop      
