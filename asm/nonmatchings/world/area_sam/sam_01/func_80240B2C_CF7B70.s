.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B2C_CF869C
/* CF869C 80240B2C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CF86A0 80240B30 AFB10014 */  sw        $s1, 0x14($sp)
/* CF86A4 80240B34 0080882D */  daddu     $s1, $a0, $zero
/* CF86A8 80240B38 AFBF0024 */  sw        $ra, 0x24($sp)
/* CF86AC 80240B3C AFB40020 */  sw        $s4, 0x20($sp)
/* CF86B0 80240B40 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF86B4 80240B44 AFB20018 */  sw        $s2, 0x18($sp)
/* CF86B8 80240B48 10A00033 */  beqz      $a1, .L80240C18
/* CF86BC 80240B4C AFB00010 */   sw       $s0, 0x10($sp)
/* CF86C0 80240B50 0C04760B */  jal       func_8011D82C
/* CF86C4 80240B54 24040001 */   addiu    $a0, $zero, 1
/* CF86C8 80240B58 0000202D */  daddu     $a0, $zero, $zero
/* CF86CC 80240B5C 0080282D */  daddu     $a1, $a0, $zero
/* CF86D0 80240B60 0080302D */  daddu     $a2, $a0, $zero
/* CF86D4 80240B64 0080382D */  daddu     $a3, $a0, $zero
/* CF86D8 80240B68 0080802D */  daddu     $s0, $a0, $zero
/* CF86DC 80240B6C 2414FFFC */  addiu     $s4, $zero, -4
/* CF86E0 80240B70 2413000E */  addiu     $s3, $zero, 0xe
/* CF86E4 80240B74 3C120080 */  lui       $s2, 0x80
/* CF86E8 80240B78 3C038015 */  lui       $v1, 0x8015
/* CF86EC 80240B7C 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* CF86F0 80240B80 24020001 */  addiu     $v0, $zero, 1
/* CF86F4 80240B84 0C046F97 */  jal       set_background_color_blend
/* CF86F8 80240B88 A0620000 */   sb       $v0, ($v1)
.L80240B8C:
/* CF86FC 80240B8C 0C00E2B7 */  jal       get_npc_by_index
/* CF8700 80240B90 0200202D */   daddu    $a0, $s0, $zero
/* CF8704 80240B94 0040202D */  daddu     $a0, $v0, $zero
/* CF8708 80240B98 5080000B */  beql      $a0, $zero, .L80240BC8
/* CF870C 80240B9C 26100001 */   addiu    $s0, $s0, 1
/* CF8710 80240BA0 8C820000 */  lw        $v0, ($a0)
/* CF8714 80240BA4 50400008 */  beql      $v0, $zero, .L80240BC8
/* CF8718 80240BA8 26100001 */   addiu    $s0, $s0, 1
/* CF871C 80240BAC 808300A4 */  lb        $v1, 0xa4($a0)
/* CF8720 80240BB0 10740005 */  beq       $v1, $s4, .L80240BC8
/* CF8724 80240BB4 26100001 */   addiu    $s0, $s0, 1
/* CF8728 80240BB8 10730003 */  beq       $v1, $s3, .L80240BC8
/* CF872C 80240BBC 00000000 */   nop      
/* CF8730 80240BC0 00521025 */  or        $v0, $v0, $s2
/* CF8734 80240BC4 AC820000 */  sw        $v0, ($a0)
.L80240BC8:
/* CF8738 80240BC8 2A020040 */  slti      $v0, $s0, 0x40
/* CF873C 80240BCC 1440FFEF */  bnez      $v0, .L80240B8C
/* CF8740 80240BD0 00000000 */   nop      
/* CF8744 80240BD4 0000802D */  daddu     $s0, $zero, $zero
/* CF8748 80240BD8 3C120800 */  lui       $s2, 0x800
.L80240BDC:
/* CF874C 80240BDC 0C04C3D6 */  jal       get_item_entity
/* CF8750 80240BE0 0200202D */   daddu    $a0, $s0, $zero
/* CF8754 80240BE4 0040182D */  daddu     $v1, $v0, $zero
/* CF8758 80240BE8 10600007 */  beqz      $v1, .L80240C08
/* CF875C 80240BEC 26100001 */   addiu    $s0, $s0, 1
/* CF8760 80240BF0 8C640000 */  lw        $a0, ($v1)
/* CF8764 80240BF4 30820010 */  andi      $v0, $a0, 0x10
/* CF8768 80240BF8 10400003 */  beqz      $v0, .L80240C08
/* CF876C 80240BFC 00000000 */   nop      
/* CF8770 80240C00 00921025 */  or        $v0, $a0, $s2
/* CF8774 80240C04 AC620000 */  sw        $v0, ($v1)
.L80240C08:
/* CF8778 80240C08 2A020100 */  slti      $v0, $s0, 0x100
/* CF877C 80240C0C 1440FFF3 */  bnez      $v0, .L80240BDC
/* CF8780 80240C10 00000000 */   nop      
/* CF8784 80240C14 AE200070 */  sw        $zero, 0x70($s1)
.L80240C18:
/* CF8788 80240C18 8E220070 */  lw        $v0, 0x70($s1)
/* CF878C 80240C1C 24420008 */  addiu     $v0, $v0, 8
/* CF8790 80240C20 AE220070 */  sw        $v0, 0x70($s1)
/* CF8794 80240C24 28420100 */  slti      $v0, $v0, 0x100
/* CF8798 80240C28 14400003 */  bnez      $v0, .L80240C38
/* CF879C 80240C2C 0000202D */   daddu    $a0, $zero, $zero
/* CF87A0 80240C30 240200FF */  addiu     $v0, $zero, 0xff
/* CF87A4 80240C34 AE220070 */  sw        $v0, 0x70($s1)
.L80240C38:
/* CF87A8 80240C38 0080282D */  daddu     $a1, $a0, $zero
/* CF87AC 80240C3C 92270073 */  lbu       $a3, 0x73($s1)
/* CF87B0 80240C40 0C046F97 */  jal       set_background_color_blend
/* CF87B4 80240C44 0080302D */   daddu    $a2, $a0, $zero
/* CF87B8 80240C48 8E220070 */  lw        $v0, 0x70($s1)
/* CF87BC 80240C4C 8FBF0024 */  lw        $ra, 0x24($sp)
/* CF87C0 80240C50 8FB40020 */  lw        $s4, 0x20($sp)
/* CF87C4 80240C54 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF87C8 80240C58 8FB20018 */  lw        $s2, 0x18($sp)
/* CF87CC 80240C5C 8FB10014 */  lw        $s1, 0x14($sp)
/* CF87D0 80240C60 8FB00010 */  lw        $s0, 0x10($sp)
/* CF87D4 80240C64 384200FF */  xori      $v0, $v0, 0xff
/* CF87D8 80240C68 2C420001 */  sltiu     $v0, $v0, 1
/* CF87DC 80240C6C 00021040 */  sll       $v0, $v0, 1
/* CF87E0 80240C70 03E00008 */  jr        $ra
/* CF87E4 80240C74 27BD0028 */   addiu    $sp, $sp, 0x28
