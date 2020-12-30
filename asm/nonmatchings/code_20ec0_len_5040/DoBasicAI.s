.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DoBasicAI
/* 2587C 8004A47C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 25880 8004A480 AFB20038 */  sw        $s2, 0x38($sp)
/* 25884 8004A484 0080902D */  daddu     $s2, $a0, $zero
/* 25888 8004A488 AFBF0048 */  sw        $ra, 0x48($sp)
/* 2588C 8004A48C AFB50044 */  sw        $s5, 0x44($sp)
/* 25890 8004A490 AFB40040 */  sw        $s4, 0x40($sp)
/* 25894 8004A494 AFB3003C */  sw        $s3, 0x3c($sp)
/* 25898 8004A498 AFB10034 */  sw        $s1, 0x34($sp)
/* 2589C 8004A49C AFB00030 */  sw        $s0, 0x30($sp)
/* 258A0 8004A4A0 8E510148 */  lw        $s1, 0x148($s2)
/* 258A4 8004A4A4 86240008 */  lh        $a0, 8($s1)
/* 258A8 8004A4A8 0C00EABB */  jal       get_npc_unsafe
/* 258AC 8004A4AC 00A0802D */   daddu    $s0, $a1, $zero
/* 258B0 8004A4B0 8E43000C */  lw        $v1, 0xc($s2)
/* 258B4 8004A4B4 0240202D */  daddu     $a0, $s2, $zero
/* 258B8 8004A4B8 8C650000 */  lw        $a1, ($v1)
/* 258BC 8004A4BC 0C0B1EAF */  jal       get_variable
/* 258C0 8004A4C0 0040A82D */   daddu    $s5, $v0, $zero
/* 258C4 8004A4C4 AFA00010 */  sw        $zero, 0x10($sp)
/* 258C8 8004A4C8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 258CC 8004A4CC 8C630030 */  lw        $v1, 0x30($v1)
/* 258D0 8004A4D0 AFA30014 */  sw        $v1, 0x14($sp)
/* 258D4 8004A4D4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 258D8 8004A4D8 8C63001C */  lw        $v1, 0x1c($v1)
/* 258DC 8004A4DC AFA30018 */  sw        $v1, 0x18($sp)
/* 258E0 8004A4E0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 258E4 8004A4E4 8C630024 */  lw        $v1, 0x24($v1)
/* 258E8 8004A4E8 AFA3001C */  sw        $v1, 0x1c($sp)
/* 258EC 8004A4EC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 258F0 8004A4F0 8C630028 */  lw        $v1, 0x28($v1)
/* 258F4 8004A4F4 27B40010 */  addiu     $s4, $sp, 0x10
/* 258F8 8004A4F8 AFA30020 */  sw        $v1, 0x20($sp)
/* 258FC 8004A4FC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 25900 8004A500 3C014282 */  lui       $at, 0x4282
/* 25904 8004A504 44810000 */  mtc1      $at, $f0
/* 25908 8004A508 8C63002C */  lw        $v1, 0x2c($v1)
/* 2590C 8004A50C 0040982D */  daddu     $s3, $v0, $zero
/* 25910 8004A510 E7A00028 */  swc1      $f0, 0x28($sp)
/* 25914 8004A514 A7A0002C */  sh        $zero, 0x2c($sp)
/* 25918 8004A518 16000005 */  bnez      $s0, .L8004A530
/* 2591C 8004A51C AFA30024 */   sw       $v1, 0x24($sp)
/* 25920 8004A520 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 25924 8004A524 30420004 */  andi      $v0, $v0, 4
/* 25928 8004A528 1040002B */  beqz      $v0, .L8004A5D8
/* 2592C 8004A52C 00000000 */   nop
.L8004A530:
/* 25930 8004A530 2404F7FF */  addiu     $a0, $zero, -0x801
/* 25934 8004A534 AE400070 */  sw        $zero, 0x70($s2)
/* 25938 8004A538 A6A0008E */  sh        $zero, 0x8e($s5)
/* 2593C 8004A53C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 25940 8004A540 8EA30000 */  lw        $v1, ($s5)
/* 25944 8004A544 8C420000 */  lw        $v0, ($v0)
/* 25948 8004A548 00641824 */  and       $v1, $v1, $a0
/* 2594C 8004A54C AEA30000 */  sw        $v1, ($s5)
/* 25950 8004A550 AEA20028 */  sw        $v0, 0x28($s5)
/* 25954 8004A554 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 25958 8004A558 8C420034 */  lw        $v0, 0x34($v0)
/* 2595C 8004A55C 54400005 */  bnel      $v0, $zero, .L8004A574
/* 25960 8004A560 2402FDFF */   addiu    $v0, $zero, -0x201
/* 25964 8004A564 34620200 */  ori       $v0, $v1, 0x200
/* 25968 8004A568 2403FFF7 */  addiu     $v1, $zero, -9
/* 2596C 8004A56C 0801295F */  j         .L8004A57C
/* 25970 8004A570 00431024 */   and      $v0, $v0, $v1
.L8004A574:
/* 25974 8004A574 00621024 */  and       $v0, $v1, $v0
/* 25978 8004A578 34420008 */  ori       $v0, $v0, 8
.L8004A57C:
/* 2597C 8004A57C AEA20000 */  sw        $v0, ($s5)
/* 25980 8004A580 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 25984 8004A584 30420004 */  andi      $v0, $v0, 4
/* 25988 8004A588 10400004 */  beqz      $v0, .L8004A59C
/* 2598C 8004A58C 24020063 */   addiu    $v0, $zero, 0x63
/* 25990 8004A590 AE420070 */  sw        $v0, 0x70($s2)
/* 25994 8004A594 0801296D */  j         .L8004A5B4
/* 25998 8004A598 AE400074 */   sw       $zero, 0x74($s2)
.L8004A59C:
/* 2599C 8004A59C 8E220000 */  lw        $v0, ($s1)
/* 259A0 8004A5A0 3C034000 */  lui       $v1, 0x4000
/* 259A4 8004A5A4 00431024 */  and       $v0, $v0, $v1
/* 259A8 8004A5A8 10400002 */  beqz      $v0, .L8004A5B4
/* 259AC 8004A5AC 2402000C */   addiu    $v0, $zero, 0xc
/* 259B0 8004A5B0 AE420070 */  sw        $v0, 0x70($s2)
.L8004A5B4:
/* 259B4 8004A5B4 3C05BFFF */  lui       $a1, 0xbfff
/* 259B8 8004A5B8 34A5FFFF */  ori       $a1, $a1, 0xffff
/* 259BC 8004A5BC 2404FFFB */  addiu     $a0, $zero, -5
/* 259C0 8004A5C0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 259C4 8004A5C4 8E230000 */  lw        $v1, ($s1)
/* 259C8 8004A5C8 00441024 */  and       $v0, $v0, $a0
/* 259CC 8004A5CC 00651824 */  and       $v1, $v1, $a1
/* 259D0 8004A5D0 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 259D4 8004A5D4 AE230000 */  sw        $v1, ($s1)
.L8004A5D8:
/* 259D8 8004A5D8 8E430070 */  lw        $v1, 0x70($s2)
/* 259DC 8004A5DC 2C620064 */  sltiu     $v0, $v1, 0x64
/* 259E0 8004A5E0 10400038 */  beqz      $v0, .L8004A6C4
/* 259E4 8004A5E4 00031080 */   sll      $v0, $v1, 2
/* 259E8 8004A5E8 3C01800A */  lui       $at, %hi(D_80098728)
/* 259EC 8004A5EC 00220821 */  addu      $at, $at, $v0
/* 259F0 8004A5F0 8C228728 */  lw        $v0, %lo(D_80098728)($at)
/* 259F4 8004A5F4 00400008 */  jr        $v0
/* 259F8 8004A5F8 00000000 */   nop
/* 259FC 8004A5FC 0240202D */  daddu     $a0, $s2, $zero
/* 25A00 8004A600 0260282D */  daddu     $a1, $s3, $zero
/* 25A04 8004A604 0C012568 */  jal       func_800495A0
/* 25A08 8004A608 0280302D */   daddu    $a2, $s4, $zero
/* 25A0C 8004A60C 0240202D */  daddu     $a0, $s2, $zero
/* 25A10 8004A610 0260282D */  daddu     $a1, $s3, $zero
/* 25A14 8004A614 0C0125AE */  jal       func_800496B8
/* 25A18 8004A618 0280302D */   daddu    $a2, $s4, $zero
/* 25A1C 8004A61C 080129B1 */  j         .L8004A6C4
/* 25A20 8004A620 00000000 */   nop
/* 25A24 8004A624 0240202D */  daddu     $a0, $s2, $zero
/* 25A28 8004A628 0260282D */  daddu     $a1, $s3, $zero
/* 25A2C 8004A62C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 25A30 8004A630 0280302D */   daddu    $a2, $s4, $zero
/* 25A34 8004A634 0240202D */  daddu     $a0, $s2, $zero
/* 25A38 8004A638 0260282D */  daddu     $a1, $s3, $zero
/* 25A3C 8004A63C 0C012701 */  jal       func_80049C04
/* 25A40 8004A640 0280302D */   daddu    $a2, $s4, $zero
/* 25A44 8004A644 080129B1 */  j         .L8004A6C4
/* 25A48 8004A648 00000000 */   nop
/* 25A4C 8004A64C 0240202D */  daddu     $a0, $s2, $zero
/* 25A50 8004A650 0260282D */  daddu     $a1, $s3, $zero
/* 25A54 8004A654 0C01278F */  jal       func_80049E3C
/* 25A58 8004A658 0280302D */   daddu    $a2, $s4, $zero
/* 25A5C 8004A65C 0240202D */  daddu     $a0, $s2, $zero
/* 25A60 8004A660 0260282D */  daddu     $a1, $s3, $zero
/* 25A64 8004A664 0C0127B3 */  jal       func_80049ECC
/* 25A68 8004A668 0280302D */   daddu    $a2, $s4, $zero
/* 25A6C 8004A66C 080129B1 */  j         .L8004A6C4
/* 25A70 8004A670 00000000 */   nop
/* 25A74 8004A674 0240202D */  daddu     $a0, $s2, $zero
/* 25A78 8004A678 0260282D */  daddu     $a1, $s3, $zero
/* 25A7C 8004A67C 0C0127DF */  jal       func_80049F7C
/* 25A80 8004A680 0280302D */   daddu    $a2, $s4, $zero
/* 25A84 8004A684 0240202D */  daddu     $a0, $s2, $zero
/* 25A88 8004A688 0260282D */  daddu     $a1, $s3, $zero
/* 25A8C 8004A68C 0C012849 */  jal       func_8004A124
/* 25A90 8004A690 0280302D */   daddu    $a2, $s4, $zero
/* 25A94 8004A694 8E430070 */  lw        $v1, 0x70($s2)
/* 25A98 8004A698 2402000E */  addiu     $v0, $zero, 0xe
/* 25A9C 8004A69C 14620009 */  bne       $v1, $v0, .L8004A6C4
/* 25AA0 8004A6A0 00000000 */   nop
/* 25AA4 8004A6A4 0240202D */  daddu     $a0, $s2, $zero
/* 25AA8 8004A6A8 0260282D */  daddu     $a1, $s3, $zero
/* 25AAC 8004A6AC 0C0128FA */  jal       func_8004A3E8
/* 25AB0 8004A6B0 0280302D */   daddu    $a2, $s4, $zero
/* 25AB4 8004A6B4 080129B1 */  j         .L8004A6C4
/* 25AB8 8004A6B8 00000000 */   nop
/* 25ABC 8004A6BC 0C0129CF */  jal       func_8004A73C
/* 25AC0 8004A6C0 0240202D */   daddu    $a0, $s2, $zero
.L8004A6C4:
/* 25AC4 8004A6C4 8FBF0048 */  lw        $ra, 0x48($sp)
/* 25AC8 8004A6C8 8FB50044 */  lw        $s5, 0x44($sp)
/* 25ACC 8004A6CC 8FB40040 */  lw        $s4, 0x40($sp)
/* 25AD0 8004A6D0 8FB3003C */  lw        $s3, 0x3c($sp)
/* 25AD4 8004A6D4 8FB20038 */  lw        $s2, 0x38($sp)
/* 25AD8 8004A6D8 8FB10034 */  lw        $s1, 0x34($sp)
/* 25ADC 8004A6DC 8FB00030 */  lw        $s0, 0x30($sp)
/* 25AE0 8004A6E0 0000102D */  daddu     $v0, $zero, $zero
/* 25AE4 8004A6E4 03E00008 */  jr        $ra
/* 25AE8 8004A6E8 27BD0050 */   addiu    $sp, $sp, 0x50
/* 25AEC 8004A6EC 00000000 */  nop
