.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fio_serialize_state
/* 6A30 8002B630 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6A34 8002B634 AFB20018 */  sw        $s2, 0x18($sp)
/* 6A38 8002B638 3C12800E */  lui       $s2, %hi(gCurrentSaveFile)
/* 6A3C 8002B63C 2652ACC0 */  addiu     $s2, $s2, %lo(gCurrentSaveFile)
/* 6A40 8002B640 26440040 */  addiu     $a0, $s2, 0x40
/* 6A44 8002B644 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 6A48 8002B648 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 6A4C 8002B64C 24430420 */  addiu     $v1, $v0, 0x420
/* 6A50 8002B650 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6A54 8002B654 AFB10014 */  sw        $s1, 0x14($sp)
/* 6A58 8002B658 AFB00010 */  sw        $s0, 0x10($sp)
.L8002B65C:
/* 6A5C 8002B65C 8C480000 */  lw        $t0, ($v0)
/* 6A60 8002B660 8C490004 */  lw        $t1, 4($v0)
/* 6A64 8002B664 8C4A0008 */  lw        $t2, 8($v0)
/* 6A68 8002B668 8C4B000C */  lw        $t3, 0xc($v0)
/* 6A6C 8002B66C AC880000 */  sw        $t0, ($a0)
/* 6A70 8002B670 AC890004 */  sw        $t1, 4($a0)
/* 6A74 8002B674 AC8A0008 */  sw        $t2, 8($a0)
/* 6A78 8002B678 AC8B000C */  sw        $t3, 0xc($a0)
/* 6A7C 8002B67C 24420010 */  addiu     $v0, $v0, 0x10
/* 6A80 8002B680 1443FFF6 */  bne       $v0, $v1, .L8002B65C
/* 6A84 8002B684 24840010 */   addiu    $a0, $a0, 0x10
/* 6A88 8002B688 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 6A8C 8002B68C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 6A90 8002B690 8C480000 */  lw        $t0, ($v0)
/* 6A94 8002B694 8C490004 */  lw        $t1, 4($v0)
/* 6A98 8002B698 AC880000 */  sw        $t0, ($a0)
/* 6A9C 8002B69C AC890004 */  sw        $t1, 4($a0)
/* 6AA0 8002B6A0 94620086 */  lhu       $v0, 0x86($v1)
/* 6AA4 8002B6A4 A6420468 */  sh        $v0, 0x468($s2)
/* 6AA8 8002B6A8 9462008C */  lhu       $v0, 0x8c($v1)
/* 6AAC 8002B6AC A642046A */  sh        $v0, 0x46a($s2)
/* 6AB0 8002B6B0 9462008E */  lhu       $v0, 0x8e($v1)
/* 6AB4 8002B6B4 A642046C */  sh        $v0, 0x46c($s2)
/* 6AB8 8002B6B8 94620160 */  lhu       $v0, 0x160($v1)
/* 6ABC 8002B6BC A64212E6 */  sh        $v0, 0x12e6($s2)
/* 6AC0 8002B6C0 94620162 */  lhu       $v0, 0x162($v1)
/* 6AC4 8002B6C4 0000302D */  daddu     $a2, $zero, $zero
/* 6AC8 8002B6C8 A64212E8 */  sh        $v0, 0x12e8($s2)
/* 6ACC 8002B6CC 94620164 */  lhu       $v0, 0x164($v1)
/* 6AD0 8002B6D0 3C07800B */  lui       $a3, %hi(gCurrentEncounter)
/* 6AD4 8002B6D4 24E70F10 */  addiu     $a3, $a3, %lo(gCurrentEncounter)
/* 6AD8 8002B6D8 A64212EA */  sh        $v0, 0x12ea($s2)
/* 6ADC 8002B6DC 0000282D */  daddu     $a1, $zero, $zero
.L8002B6E0:
/* 6AE0 8002B6E0 00062080 */  sll       $a0, $a2, 2
.L8002B6E4:
/* 6AE4 8002B6E4 02441821 */  addu      $v1, $s2, $a0
/* 6AE8 8002B6E8 00871021 */  addu      $v0, $a0, $a3
/* 6AEC 8002B6EC 8C4200B0 */  lw        $v0, 0xb0($v0)
/* 6AF0 8002B6F0 24A50001 */  addiu     $a1, $a1, 1
/* 6AF4 8002B6F4 AC620470 */  sw        $v0, 0x470($v1)
/* 6AF8 8002B6F8 28A2003C */  slti      $v0, $a1, 0x3c
/* 6AFC 8002B6FC 1440FFF9 */  bnez      $v0, .L8002B6E4
/* 6B00 8002B700 24840030 */   addiu    $a0, $a0, 0x30
/* 6B04 8002B704 24C60001 */  addiu     $a2, $a2, 1
/* 6B08 8002B708 28C2000C */  slti      $v0, $a2, 0xc
/* 6B0C 8002B70C 1440FFF4 */  bnez      $v0, .L8002B6E0
/* 6B10 8002B710 0000282D */   daddu    $a1, $zero, $zero
/* 6B14 8002B714 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 6B18 8002B718 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 6B1C 8002B71C 8E020000 */  lw        $v0, ($s0)
/* 6B20 8002B720 8E030000 */  lw        $v1, ($s0)
/* 6B24 8002B724 90420074 */  lbu       $v0, 0x74($v0)
/* 6B28 8002B728 A24212E0 */  sb        $v0, 0x12e0($s2)
/* 6B2C 8002B72C 90620076 */  lbu       $v0, 0x76($v1)
/* 6B30 8002B730 8E030000 */  lw        $v1, ($s0)
/* 6B34 8002B734 A24212E1 */  sb        $v0, 0x12e1($s2)
/* 6B38 8002B738 90620077 */  lbu       $v0, 0x77($v1)
/* 6B3C 8002B73C 8E030000 */  lw        $v1, ($s0)
/* 6B40 8002B740 A24212E2 */  sb        $v0, 0x12e2($s2)
/* 6B44 8002B744 9062007A */  lbu       $v0, 0x7a($v1)
/* 6B48 8002B748 8E030000 */  lw        $v1, ($s0)
/* 6B4C 8002B74C A24212E3 */  sb        $v0, 0x12e3($s2)
/* 6B50 8002B750 90630166 */  lbu       $v1, 0x166($v1)
/* 6B54 8002B754 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 6B58 8002B758 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 6B5C 8002B75C 00031040 */  sll       $v0, $v1, 1
/* 6B60 8002B760 00431021 */  addu      $v0, $v0, $v1
/* 6B64 8002B764 92230009 */  lbu       $v1, 9($s1)
/* 6B68 8002B768 000210C0 */  sll       $v0, $v0, 3
/* 6B6C 8002B76C 3C018007 */  lui       $at, %hi(D_800779CA)
/* 6B70 8002B770 00220821 */  addu      $at, $at, $v0
/* 6B74 8002B774 A02379CA */  sb        $v1, %lo(D_800779CA)($at)
/* 6B78 8002B778 0C00AB90 */  jal       get_spirits_rescued
/* 6B7C 8002B77C 00000000 */   nop
/* 6B80 8002B780 8E030000 */  lw        $v1, ($s0)
/* 6B84 8002B784 90640166 */  lbu       $a0, 0x166($v1)
/* 6B88 8002B788 00041840 */  sll       $v1, $a0, 1
/* 6B8C 8002B78C 00641821 */  addu      $v1, $v1, $a0
/* 6B90 8002B790 000318C0 */  sll       $v1, $v1, 3
/* 6B94 8002B794 3C018007 */  lui       $at, %hi(D_800779C8)
/* 6B98 8002B798 00230821 */  addu      $at, $at, $v1
/* 6B9C 8002B79C A02279C8 */  sb        $v0, %lo(D_800779C8)($at)
/* 6BA0 8002B7A0 8E040000 */  lw        $a0, ($s0)
/* 6BA4 8002B7A4 90830166 */  lbu       $v1, 0x166($a0)
/* 6BA8 8002B7A8 00031040 */  sll       $v0, $v1, 1
/* 6BAC 8002B7AC 00431021 */  addu      $v0, $v0, $v1
/* 6BB0 8002B7B0 8E2302BC */  lw        $v1, 0x2bc($s1)
/* 6BB4 8002B7B4 000210C0 */  sll       $v0, $v0, 3
/* 6BB8 8002B7B8 3C018007 */  lui       $at, %hi(D_800779C4)
/* 6BBC 8002B7BC 00220821 */  addu      $at, $at, $v0
/* 6BC0 8002B7C0 AC2379C4 */  sw        $v1, %lo(D_800779C4)($at)
/* 6BC4 8002B7C4 90830166 */  lbu       $v1, 0x166($a0)
/* 6BC8 8002B7C8 00031040 */  sll       $v0, $v1, 1
/* 6BCC 8002B7CC 00431021 */  addu      $v0, $v0, $v1
/* 6BD0 8002B7D0 000210C0 */  sll       $v0, $v0, 3
/* 6BD4 8002B7D4 3C088007 */  lui       $t0, %hi(D_800779C4)
/* 6BD8 8002B7D8 01024021 */  addu      $t0, $t0, $v0
/* 6BDC 8002B7DC 8D0879C4 */  lw        $t0, %lo(D_800779C4)($t0)
/* 6BE0 8002B7E0 3C098007 */  lui       $t1, %hi(D_800779C8)
/* 6BE4 8002B7E4 01224821 */  addu      $t1, $t1, $v0
/* 6BE8 8002B7E8 8D2979C8 */  lw        $t1, %lo(D_800779C8)($t1)
/* 6BEC 8002B7EC 3C0A8007 */  lui       $t2, %hi(D_800779CC)
/* 6BF0 8002B7F0 01425021 */  addu      $t2, $t2, $v0
/* 6BF4 8002B7F4 8D4A79CC */  lw        $t2, %lo(D_800779CC)($t2)
/* 6BF8 8002B7F8 3C0B8007 */  lui       $t3, %hi(D_800779D0)
/* 6BFC 8002B7FC 01625821 */  addu      $t3, $t3, $v0
/* 6C00 8002B800 8D6B79D0 */  lw        $t3, %lo(D_800779D0)($t3)
/* 6C04 8002B804 AE4812EC */  sw        $t0, 0x12ec($s2)
/* 6C08 8002B808 AE4912F0 */  sw        $t1, 0x12f0($s2)
/* 6C0C 8002B80C AE4A12F4 */  sw        $t2, 0x12f4($s2)
/* 6C10 8002B810 AE4B12F8 */  sw        $t3, 0x12f8($s2)
/* 6C14 8002B814 3C088007 */  lui       $t0, %hi(D_800779D4)
/* 6C18 8002B818 01024021 */  addu      $t0, $t0, $v0
/* 6C1C 8002B81C 8D0879D4 */  lw        $t0, %lo(D_800779D4)($t0)
/* 6C20 8002B820 3C098007 */  lui       $t1, %hi(D_800779D8)
/* 6C24 8002B824 01224821 */  addu      $t1, $t1, $v0
/* 6C28 8002B828 8D2979D8 */  lw        $t1, %lo(D_800779D8)($t1)
/* 6C2C 8002B82C AE4812FC */  sw        $t0, 0x12fc($s2)
/* 6C30 8002B830 AE491300 */  sw        $t1, 0x1300($s2)
/* 6C34 8002B834 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6C38 8002B838 8FB20018 */  lw        $s2, 0x18($sp)
/* 6C3C 8002B83C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6C40 8002B840 8FB00010 */  lw        $s0, 0x10($sp)
/* 6C44 8002B844 03E00008 */  jr        $ra
/* 6C48 8002B848 27BD0020 */   addiu    $sp, $sp, 0x20
