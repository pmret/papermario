.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024189C_95CA9C
/* 95CA9C 8024189C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 95CAA0 802418A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 95CAA4 802418A4 0080882D */  daddu     $s1, $a0, $zero
/* 95CAA8 802418A8 AFBF0024 */  sw        $ra, 0x24($sp)
/* 95CAAC 802418AC AFB40020 */  sw        $s4, 0x20($sp)
/* 95CAB0 802418B0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 95CAB4 802418B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 95CAB8 802418B8 10A00033 */  beqz      $a1, .L80241988
/* 95CABC 802418BC AFB00010 */   sw       $s0, 0x10($sp)
/* 95CAC0 802418C0 0C04760B */  jal       func_8011D82C
/* 95CAC4 802418C4 24040001 */   addiu    $a0, $zero, 1
/* 95CAC8 802418C8 0000202D */  daddu     $a0, $zero, $zero
/* 95CACC 802418CC 0080282D */  daddu     $a1, $a0, $zero
/* 95CAD0 802418D0 0080302D */  daddu     $a2, $a0, $zero
/* 95CAD4 802418D4 0080382D */  daddu     $a3, $a0, $zero
/* 95CAD8 802418D8 0080802D */  daddu     $s0, $a0, $zero
/* 95CADC 802418DC 2414FFFC */  addiu     $s4, $zero, -4
/* 95CAE0 802418E0 2413000A */  addiu     $s3, $zero, 0xa
/* 95CAE4 802418E4 3C120080 */  lui       $s2, 0x80
/* 95CAE8 802418E8 3C038015 */  lui       $v1, 0x8015
/* 95CAEC 802418EC 8C6312F0 */  lw        $v1, 0x12f0($v1)
/* 95CAF0 802418F0 24020001 */  addiu     $v0, $zero, 1
/* 95CAF4 802418F4 0C046F97 */  jal       set_background_color_blend
/* 95CAF8 802418F8 A0620000 */   sb       $v0, ($v1)
.L802418FC:
/* 95CAFC 802418FC 0C00E2B7 */  jal       get_npc_by_index
/* 95CB00 80241900 0200202D */   daddu    $a0, $s0, $zero
/* 95CB04 80241904 0040202D */  daddu     $a0, $v0, $zero
/* 95CB08 80241908 5080000B */  beql      $a0, $zero, .L80241938
/* 95CB0C 8024190C 26100001 */   addiu    $s0, $s0, 1
/* 95CB10 80241910 8C820000 */  lw        $v0, ($a0)
/* 95CB14 80241914 50400008 */  beql      $v0, $zero, .L80241938
/* 95CB18 80241918 26100001 */   addiu    $s0, $s0, 1
/* 95CB1C 8024191C 808300A4 */  lb        $v1, 0xa4($a0)
/* 95CB20 80241920 10740005 */  beq       $v1, $s4, .L80241938
/* 95CB24 80241924 26100001 */   addiu    $s0, $s0, 1
/* 95CB28 80241928 10730003 */  beq       $v1, $s3, .L80241938
/* 95CB2C 8024192C 00000000 */   nop      
/* 95CB30 80241930 00521025 */  or        $v0, $v0, $s2
/* 95CB34 80241934 AC820000 */  sw        $v0, ($a0)
.L80241938:
/* 95CB38 80241938 2A020040 */  slti      $v0, $s0, 0x40
/* 95CB3C 8024193C 1440FFEF */  bnez      $v0, .L802418FC
/* 95CB40 80241940 00000000 */   nop      
/* 95CB44 80241944 0000802D */  daddu     $s0, $zero, $zero
/* 95CB48 80241948 3C120800 */  lui       $s2, 0x800
.L8024194C:
/* 95CB4C 8024194C 0C04C3D6 */  jal       get_item_entity
/* 95CB50 80241950 0200202D */   daddu    $a0, $s0, $zero
/* 95CB54 80241954 0040182D */  daddu     $v1, $v0, $zero
/* 95CB58 80241958 10600007 */  beqz      $v1, .L80241978
/* 95CB5C 8024195C 26100001 */   addiu    $s0, $s0, 1
/* 95CB60 80241960 8C640000 */  lw        $a0, ($v1)
/* 95CB64 80241964 30820010 */  andi      $v0, $a0, 0x10
/* 95CB68 80241968 10400003 */  beqz      $v0, .L80241978
/* 95CB6C 8024196C 00000000 */   nop      
/* 95CB70 80241970 00921025 */  or        $v0, $a0, $s2
/* 95CB74 80241974 AC620000 */  sw        $v0, ($v1)
.L80241978:
/* 95CB78 80241978 2A020100 */  slti      $v0, $s0, 0x100
/* 95CB7C 8024197C 1440FFF3 */  bnez      $v0, .L8024194C
/* 95CB80 80241980 00000000 */   nop      
/* 95CB84 80241984 AE200070 */  sw        $zero, 0x70($s1)
.L80241988:
/* 95CB88 80241988 8E220070 */  lw        $v0, 0x70($s1)
/* 95CB8C 8024198C 24420008 */  addiu     $v0, $v0, 8
/* 95CB90 80241990 AE220070 */  sw        $v0, 0x70($s1)
/* 95CB94 80241994 28420100 */  slti      $v0, $v0, 0x100
/* 95CB98 80241998 14400003 */  bnez      $v0, .L802419A8
/* 95CB9C 8024199C 0000202D */   daddu    $a0, $zero, $zero
/* 95CBA0 802419A0 240200FF */  addiu     $v0, $zero, 0xff
/* 95CBA4 802419A4 AE220070 */  sw        $v0, 0x70($s1)
.L802419A8:
/* 95CBA8 802419A8 0080282D */  daddu     $a1, $a0, $zero
/* 95CBAC 802419AC 92270073 */  lbu       $a3, 0x73($s1)
/* 95CBB0 802419B0 0C046F97 */  jal       set_background_color_blend
/* 95CBB4 802419B4 0080302D */   daddu    $a2, $a0, $zero
/* 95CBB8 802419B8 8E220070 */  lw        $v0, 0x70($s1)
/* 95CBBC 802419BC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 95CBC0 802419C0 8FB40020 */  lw        $s4, 0x20($sp)
/* 95CBC4 802419C4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 95CBC8 802419C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 95CBCC 802419CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 95CBD0 802419D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 95CBD4 802419D4 384200FF */  xori      $v0, $v0, 0xff
/* 95CBD8 802419D8 2C420001 */  sltiu     $v0, $v0, 1
/* 95CBDC 802419DC 00021040 */  sll       $v0, $v0, 1
/* 95CBE0 802419E0 03E00008 */  jr        $ra
/* 95CBE4 802419E4 27BD0028 */   addiu    $sp, $sp, 0x28
