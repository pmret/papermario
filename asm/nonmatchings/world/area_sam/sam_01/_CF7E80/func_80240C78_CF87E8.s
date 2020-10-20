.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C78_CF87E8
/* CF87E8 80240C78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* CF87EC 80240C7C AFB00010 */  sw        $s0, 0x10($sp)
/* CF87F0 80240C80 0080802D */  daddu     $s0, $a0, $zero
/* CF87F4 80240C84 AFBF0020 */  sw        $ra, 0x20($sp)
/* CF87F8 80240C88 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF87FC 80240C8C AFB20018 */  sw        $s2, 0x18($sp)
/* CF8800 80240C90 10A00009 */  beqz      $a1, .L80240CB8
/* CF8804 80240C94 AFB10014 */   sw       $s1, 0x14($sp)
/* CF8808 80240C98 0000202D */  daddu     $a0, $zero, $zero
/* CF880C 80240C9C 0080282D */  daddu     $a1, $a0, $zero
/* CF8810 80240CA0 0080302D */  daddu     $a2, $a0, $zero
/* CF8814 80240CA4 0C046F97 */  jal       set_background_color_blend
/* CF8818 80240CA8 240700FF */   addiu    $a3, $zero, 0xff
/* CF881C 80240CAC 240200FF */  addiu     $v0, $zero, 0xff
/* CF8820 80240CB0 AE020070 */  sw        $v0, 0x70($s0)
/* CF8824 80240CB4 AE000074 */  sw        $zero, 0x74($s0)
.L80240CB8:
/* CF8828 80240CB8 8E020070 */  lw        $v0, 0x70($s0)
/* CF882C 80240CBC 2442FFF8 */  addiu     $v0, $v0, -8
/* CF8830 80240CC0 04410002 */  bgez      $v0, .L80240CCC
/* CF8834 80240CC4 AE020070 */   sw       $v0, 0x70($s0)
/* CF8838 80240CC8 AE000070 */  sw        $zero, 0x70($s0)
.L80240CCC:
/* CF883C 80240CCC 0000202D */  daddu     $a0, $zero, $zero
/* CF8840 80240CD0 0080282D */  daddu     $a1, $a0, $zero
/* CF8844 80240CD4 92070073 */  lbu       $a3, 0x73($s0)
/* CF8848 80240CD8 0C046F97 */  jal       set_background_color_blend
/* CF884C 80240CDC 0080302D */   daddu    $a2, $a0, $zero
/* CF8850 80240CE0 8E020070 */  lw        $v0, 0x70($s0)
/* CF8854 80240CE4 14400006 */  bnez      $v0, .L80240D00
/* CF8858 80240CE8 00000000 */   nop      
/* CF885C 80240CEC 8E020074 */  lw        $v0, 0x74($s0)
/* CF8860 80240CF0 14400003 */  bnez      $v0, .L80240D00
/* CF8864 80240CF4 24020001 */   addiu    $v0, $zero, 1
/* CF8868 80240CF8 08090373 */  j         .L80240DCC
/* CF886C 80240CFC AE020074 */   sw       $v0, 0x74($s0)
.L80240D00:
/* CF8870 80240D00 8E030074 */  lw        $v1, 0x74($s0)
/* CF8874 80240D04 24020001 */  addiu     $v0, $zero, 1
/* CF8878 80240D08 14620031 */  bne       $v1, $v0, .L80240DD0
/* CF887C 80240D0C 0000102D */   daddu    $v0, $zero, $zero
/* CF8880 80240D10 0C04760B */  jal       func_8011D82C
/* CF8884 80240D14 0000202D */   daddu    $a0, $zero, $zero
/* CF8888 80240D18 0000802D */  daddu     $s0, $zero, $zero
/* CF888C 80240D1C 2413FFFC */  addiu     $s3, $zero, -4
/* CF8890 80240D20 2412000E */  addiu     $s2, $zero, 0xe
/* CF8894 80240D24 3C11FF7F */  lui       $s1, 0xff7f
/* CF8898 80240D28 3C028015 */  lui       $v0, 0x8015
/* CF889C 80240D2C 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* CF88A0 80240D30 3631FFFF */  ori       $s1, $s1, 0xffff
/* CF88A4 80240D34 A0400000 */  sb        $zero, ($v0)
.L80240D38:
/* CF88A8 80240D38 0C00E2B7 */  jal       get_npc_by_index
/* CF88AC 80240D3C 0200202D */   daddu    $a0, $s0, $zero
/* CF88B0 80240D40 0040202D */  daddu     $a0, $v0, $zero
/* CF88B4 80240D44 5080000B */  beql      $a0, $zero, .L80240D74
/* CF88B8 80240D48 26100001 */   addiu    $s0, $s0, 1
/* CF88BC 80240D4C 8C820000 */  lw        $v0, ($a0)
/* CF88C0 80240D50 50400008 */  beql      $v0, $zero, .L80240D74
/* CF88C4 80240D54 26100001 */   addiu    $s0, $s0, 1
/* CF88C8 80240D58 808300A4 */  lb        $v1, 0xa4($a0)
/* CF88CC 80240D5C 10730005 */  beq       $v1, $s3, .L80240D74
/* CF88D0 80240D60 26100001 */   addiu    $s0, $s0, 1
/* CF88D4 80240D64 10720003 */  beq       $v1, $s2, .L80240D74
/* CF88D8 80240D68 00000000 */   nop      
/* CF88DC 80240D6C 00511024 */  and       $v0, $v0, $s1
/* CF88E0 80240D70 AC820000 */  sw        $v0, ($a0)
.L80240D74:
/* CF88E4 80240D74 2A020040 */  slti      $v0, $s0, 0x40
/* CF88E8 80240D78 1440FFEF */  bnez      $v0, .L80240D38
/* CF88EC 80240D7C 00000000 */   nop      
/* CF88F0 80240D80 0000802D */  daddu     $s0, $zero, $zero
/* CF88F4 80240D84 3C11F7FF */  lui       $s1, 0xf7ff
/* CF88F8 80240D88 3631FFFF */  ori       $s1, $s1, 0xffff
.L80240D8C:
/* CF88FC 80240D8C 0C04C3D6 */  jal       get_item_entity
/* CF8900 80240D90 0200202D */   daddu    $a0, $s0, $zero
/* CF8904 80240D94 0040182D */  daddu     $v1, $v0, $zero
/* CF8908 80240D98 10600007 */  beqz      $v1, .L80240DB8
/* CF890C 80240D9C 26100001 */   addiu    $s0, $s0, 1
/* CF8910 80240DA0 8C640000 */  lw        $a0, ($v1)
/* CF8914 80240DA4 30820010 */  andi      $v0, $a0, 0x10
/* CF8918 80240DA8 10400003 */  beqz      $v0, .L80240DB8
/* CF891C 80240DAC 00000000 */   nop      
/* CF8920 80240DB0 00911024 */  and       $v0, $a0, $s1
/* CF8924 80240DB4 AC620000 */  sw        $v0, ($v1)
.L80240DB8:
/* CF8928 80240DB8 2A020100 */  slti      $v0, $s0, 0x100
/* CF892C 80240DBC 1440FFF3 */  bnez      $v0, .L80240D8C
/* CF8930 80240DC0 24020002 */   addiu    $v0, $zero, 2
/* CF8934 80240DC4 08090374 */  j         .L80240DD0
/* CF8938 80240DC8 00000000 */   nop      
.L80240DCC:
/* CF893C 80240DCC 0000102D */  daddu     $v0, $zero, $zero
.L80240DD0:
/* CF8940 80240DD0 8FBF0020 */  lw        $ra, 0x20($sp)
/* CF8944 80240DD4 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF8948 80240DD8 8FB20018 */  lw        $s2, 0x18($sp)
/* CF894C 80240DDC 8FB10014 */  lw        $s1, 0x14($sp)
/* CF8950 80240DE0 8FB00010 */  lw        $s0, 0x10($sp)
/* CF8954 80240DE4 03E00008 */  jr        $ra
/* CF8958 80240DE8 27BD0028 */   addiu    $sp, $sp, 0x28
