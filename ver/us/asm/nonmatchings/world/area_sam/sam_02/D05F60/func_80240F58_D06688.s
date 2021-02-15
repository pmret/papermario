.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F58_D06688
/* D06688 80240F58 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D0668C 80240F5C AFB10014 */  sw        $s1, 0x14($sp)
/* D06690 80240F60 0080882D */  daddu     $s1, $a0, $zero
/* D06694 80240F64 AFBF0024 */  sw        $ra, 0x24($sp)
/* D06698 80240F68 AFB40020 */  sw        $s4, 0x20($sp)
/* D0669C 80240F6C AFB3001C */  sw        $s3, 0x1c($sp)
/* D066A0 80240F70 AFB20018 */  sw        $s2, 0x18($sp)
/* D066A4 80240F74 10A00033 */  beqz      $a1, .L80241044
/* D066A8 80240F78 AFB00010 */   sw       $s0, 0x10($sp)
/* D066AC 80240F7C 0C04760B */  jal       func_8011D82C
/* D066B0 80240F80 24040001 */   addiu    $a0, $zero, 1
/* D066B4 80240F84 0000202D */  daddu     $a0, $zero, $zero
/* D066B8 80240F88 0080282D */  daddu     $a1, $a0, $zero
/* D066BC 80240F8C 0080302D */  daddu     $a2, $a0, $zero
/* D066C0 80240F90 0080382D */  daddu     $a3, $a0, $zero
/* D066C4 80240F94 0080802D */  daddu     $s0, $a0, $zero
/* D066C8 80240F98 2414FFFC */  addiu     $s4, $zero, -4
/* D066CC 80240F9C 24130008 */  addiu     $s3, $zero, 8
/* D066D0 80240FA0 3C120080 */  lui       $s2, 0x80
/* D066D4 80240FA4 3C038015 */  lui       $v1, %hi(D_801512F0)
/* D066D8 80240FA8 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* D066DC 80240FAC 24020001 */  addiu     $v0, $zero, 1
/* D066E0 80240FB0 0C046F97 */  jal       set_background_color_blend
/* D066E4 80240FB4 A0620000 */   sb       $v0, ($v1)
.L80240FB8:
/* D066E8 80240FB8 0C00E2B7 */  jal       get_npc_by_index
/* D066EC 80240FBC 0200202D */   daddu    $a0, $s0, $zero
/* D066F0 80240FC0 0040202D */  daddu     $a0, $v0, $zero
/* D066F4 80240FC4 5080000B */  beql      $a0, $zero, .L80240FF4
/* D066F8 80240FC8 26100001 */   addiu    $s0, $s0, 1
/* D066FC 80240FCC 8C820000 */  lw        $v0, ($a0)
/* D06700 80240FD0 50400008 */  beql      $v0, $zero, .L80240FF4
/* D06704 80240FD4 26100001 */   addiu    $s0, $s0, 1
/* D06708 80240FD8 808300A4 */  lb        $v1, 0xa4($a0)
/* D0670C 80240FDC 10740005 */  beq       $v1, $s4, .L80240FF4
/* D06710 80240FE0 26100001 */   addiu    $s0, $s0, 1
/* D06714 80240FE4 10730003 */  beq       $v1, $s3, .L80240FF4
/* D06718 80240FE8 00000000 */   nop
/* D0671C 80240FEC 00521025 */  or        $v0, $v0, $s2
/* D06720 80240FF0 AC820000 */  sw        $v0, ($a0)
.L80240FF4:
/* D06724 80240FF4 2A020040 */  slti      $v0, $s0, 0x40
/* D06728 80240FF8 1440FFEF */  bnez      $v0, .L80240FB8
/* D0672C 80240FFC 00000000 */   nop
/* D06730 80241000 0000802D */  daddu     $s0, $zero, $zero
/* D06734 80241004 3C120800 */  lui       $s2, 0x800
.L80241008:
/* D06738 80241008 0C04C3D6 */  jal       get_item_entity
/* D0673C 8024100C 0200202D */   daddu    $a0, $s0, $zero
/* D06740 80241010 0040182D */  daddu     $v1, $v0, $zero
/* D06744 80241014 10600007 */  beqz      $v1, .L80241034
/* D06748 80241018 26100001 */   addiu    $s0, $s0, 1
/* D0674C 8024101C 8C640000 */  lw        $a0, ($v1)
/* D06750 80241020 30820010 */  andi      $v0, $a0, 0x10
/* D06754 80241024 10400003 */  beqz      $v0, .L80241034
/* D06758 80241028 00000000 */   nop
/* D0675C 8024102C 00921025 */  or        $v0, $a0, $s2
/* D06760 80241030 AC620000 */  sw        $v0, ($v1)
.L80241034:
/* D06764 80241034 2A020100 */  slti      $v0, $s0, 0x100
/* D06768 80241038 1440FFF3 */  bnez      $v0, .L80241008
/* D0676C 8024103C 00000000 */   nop
/* D06770 80241040 AE200070 */  sw        $zero, 0x70($s1)
.L80241044:
/* D06774 80241044 8E220070 */  lw        $v0, 0x70($s1)
/* D06778 80241048 24420008 */  addiu     $v0, $v0, 8
/* D0677C 8024104C AE220070 */  sw        $v0, 0x70($s1)
/* D06780 80241050 28420100 */  slti      $v0, $v0, 0x100
/* D06784 80241054 14400003 */  bnez      $v0, .L80241064
/* D06788 80241058 0000202D */   daddu    $a0, $zero, $zero
/* D0678C 8024105C 240200FF */  addiu     $v0, $zero, 0xff
/* D06790 80241060 AE220070 */  sw        $v0, 0x70($s1)
.L80241064:
/* D06794 80241064 0080282D */  daddu     $a1, $a0, $zero
/* D06798 80241068 92270073 */  lbu       $a3, 0x73($s1)
/* D0679C 8024106C 0C046F97 */  jal       set_background_color_blend
/* D067A0 80241070 0080302D */   daddu    $a2, $a0, $zero
/* D067A4 80241074 8E220070 */  lw        $v0, 0x70($s1)
/* D067A8 80241078 8FBF0024 */  lw        $ra, 0x24($sp)
/* D067AC 8024107C 8FB40020 */  lw        $s4, 0x20($sp)
/* D067B0 80241080 8FB3001C */  lw        $s3, 0x1c($sp)
/* D067B4 80241084 8FB20018 */  lw        $s2, 0x18($sp)
/* D067B8 80241088 8FB10014 */  lw        $s1, 0x14($sp)
/* D067BC 8024108C 8FB00010 */  lw        $s0, 0x10($sp)
/* D067C0 80241090 384200FF */  xori      $v0, $v0, 0xff
/* D067C4 80241094 2C420001 */  sltiu     $v0, $v0, 1
/* D067C8 80241098 00021040 */  sll       $v0, $v0, 1
/* D067CC 8024109C 03E00008 */  jr        $ra
/* D067D0 802410A0 27BD0028 */   addiu    $sp, $sp, 0x28
