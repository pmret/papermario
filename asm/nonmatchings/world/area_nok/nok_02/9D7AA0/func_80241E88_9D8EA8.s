.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E88_9D8EA8
/* 9D8EA8 80241E88 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9D8EAC 80241E8C AFB00010 */  sw        $s0, 0x10($sp)
/* 9D8EB0 80241E90 0080802D */  daddu     $s0, $a0, $zero
/* 9D8EB4 80241E94 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9D8EB8 80241E98 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9D8EBC 80241E9C AFB20018 */  sw        $s2, 0x18($sp)
/* 9D8EC0 80241EA0 10A00009 */  beqz      $a1, .L80241EC8
/* 9D8EC4 80241EA4 AFB10014 */   sw       $s1, 0x14($sp)
/* 9D8EC8 80241EA8 0000202D */  daddu     $a0, $zero, $zero
/* 9D8ECC 80241EAC 0080282D */  daddu     $a1, $a0, $zero
/* 9D8ED0 80241EB0 0080302D */  daddu     $a2, $a0, $zero
/* 9D8ED4 80241EB4 0C046F97 */  jal       set_background_color_blend
/* 9D8ED8 80241EB8 240700FF */   addiu    $a3, $zero, 0xff
/* 9D8EDC 80241EBC 240200FF */  addiu     $v0, $zero, 0xff
/* 9D8EE0 80241EC0 AE020070 */  sw        $v0, 0x70($s0)
/* 9D8EE4 80241EC4 AE000074 */  sw        $zero, 0x74($s0)
.L80241EC8:
/* 9D8EE8 80241EC8 8E020070 */  lw        $v0, 0x70($s0)
/* 9D8EEC 80241ECC 2442FFF8 */  addiu     $v0, $v0, -8
/* 9D8EF0 80241ED0 04410002 */  bgez      $v0, .L80241EDC
/* 9D8EF4 80241ED4 AE020070 */   sw       $v0, 0x70($s0)
/* 9D8EF8 80241ED8 AE000070 */  sw        $zero, 0x70($s0)
.L80241EDC:
/* 9D8EFC 80241EDC 0000202D */  daddu     $a0, $zero, $zero
/* 9D8F00 80241EE0 0080282D */  daddu     $a1, $a0, $zero
/* 9D8F04 80241EE4 92070073 */  lbu       $a3, 0x73($s0)
/* 9D8F08 80241EE8 0C046F97 */  jal       set_background_color_blend
/* 9D8F0C 80241EEC 0080302D */   daddu    $a2, $a0, $zero
/* 9D8F10 80241EF0 8E020070 */  lw        $v0, 0x70($s0)
/* 9D8F14 80241EF4 14400006 */  bnez      $v0, .L80241F10
/* 9D8F18 80241EF8 00000000 */   nop      
/* 9D8F1C 80241EFC 8E020074 */  lw        $v0, 0x74($s0)
/* 9D8F20 80241F00 14400003 */  bnez      $v0, .L80241F10
/* 9D8F24 80241F04 24020001 */   addiu    $v0, $zero, 1
/* 9D8F28 80241F08 080907F7 */  j         .L80241FDC
/* 9D8F2C 80241F0C AE020074 */   sw       $v0, 0x74($s0)
.L80241F10:
/* 9D8F30 80241F10 8E030074 */  lw        $v1, 0x74($s0)
/* 9D8F34 80241F14 24020001 */  addiu     $v0, $zero, 1
/* 9D8F38 80241F18 14620031 */  bne       $v1, $v0, .L80241FE0
/* 9D8F3C 80241F1C 0000102D */   daddu    $v0, $zero, $zero
/* 9D8F40 80241F20 0C04760B */  jal       func_8011D82C
/* 9D8F44 80241F24 0000202D */   daddu    $a0, $zero, $zero
/* 9D8F48 80241F28 0000802D */  daddu     $s0, $zero, $zero
/* 9D8F4C 80241F2C 2413FFFC */  addiu     $s3, $zero, -4
/* 9D8F50 80241F30 24120013 */  addiu     $s2, $zero, 0x13
/* 9D8F54 80241F34 3C11FF7F */  lui       $s1, 0xff7f
/* 9D8F58 80241F38 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 9D8F5C 80241F3C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 9D8F60 80241F40 3631FFFF */  ori       $s1, $s1, 0xffff
/* 9D8F64 80241F44 A0400000 */  sb        $zero, ($v0)
.L80241F48:
/* 9D8F68 80241F48 0C00E2B7 */  jal       get_npc_by_index
/* 9D8F6C 80241F4C 0200202D */   daddu    $a0, $s0, $zero
/* 9D8F70 80241F50 0040202D */  daddu     $a0, $v0, $zero
/* 9D8F74 80241F54 5080000B */  beql      $a0, $zero, .L80241F84
/* 9D8F78 80241F58 26100001 */   addiu    $s0, $s0, 1
/* 9D8F7C 80241F5C 8C820000 */  lw        $v0, ($a0)
/* 9D8F80 80241F60 50400008 */  beql      $v0, $zero, .L80241F84
/* 9D8F84 80241F64 26100001 */   addiu    $s0, $s0, 1
/* 9D8F88 80241F68 808300A4 */  lb        $v1, 0xa4($a0)
/* 9D8F8C 80241F6C 10730005 */  beq       $v1, $s3, .L80241F84
/* 9D8F90 80241F70 26100001 */   addiu    $s0, $s0, 1
/* 9D8F94 80241F74 10720003 */  beq       $v1, $s2, .L80241F84
/* 9D8F98 80241F78 00000000 */   nop      
/* 9D8F9C 80241F7C 00511024 */  and       $v0, $v0, $s1
/* 9D8FA0 80241F80 AC820000 */  sw        $v0, ($a0)
.L80241F84:
/* 9D8FA4 80241F84 2A020040 */  slti      $v0, $s0, 0x40
/* 9D8FA8 80241F88 1440FFEF */  bnez      $v0, .L80241F48
/* 9D8FAC 80241F8C 00000000 */   nop      
/* 9D8FB0 80241F90 0000802D */  daddu     $s0, $zero, $zero
/* 9D8FB4 80241F94 3C11F7FF */  lui       $s1, 0xf7ff
/* 9D8FB8 80241F98 3631FFFF */  ori       $s1, $s1, 0xffff
.L80241F9C:
/* 9D8FBC 80241F9C 0C04C3D6 */  jal       get_item_entity
/* 9D8FC0 80241FA0 0200202D */   daddu    $a0, $s0, $zero
/* 9D8FC4 80241FA4 0040182D */  daddu     $v1, $v0, $zero
/* 9D8FC8 80241FA8 10600007 */  beqz      $v1, .L80241FC8
/* 9D8FCC 80241FAC 26100001 */   addiu    $s0, $s0, 1
/* 9D8FD0 80241FB0 8C640000 */  lw        $a0, ($v1)
/* 9D8FD4 80241FB4 30820010 */  andi      $v0, $a0, 0x10
/* 9D8FD8 80241FB8 10400003 */  beqz      $v0, .L80241FC8
/* 9D8FDC 80241FBC 00000000 */   nop      
/* 9D8FE0 80241FC0 00911024 */  and       $v0, $a0, $s1
/* 9D8FE4 80241FC4 AC620000 */  sw        $v0, ($v1)
.L80241FC8:
/* 9D8FE8 80241FC8 2A020100 */  slti      $v0, $s0, 0x100
/* 9D8FEC 80241FCC 1440FFF3 */  bnez      $v0, .L80241F9C
/* 9D8FF0 80241FD0 24020002 */   addiu    $v0, $zero, 2
/* 9D8FF4 80241FD4 080907F8 */  j         .L80241FE0
/* 9D8FF8 80241FD8 00000000 */   nop      
.L80241FDC:
/* 9D8FFC 80241FDC 0000102D */  daddu     $v0, $zero, $zero
.L80241FE0:
/* 9D9000 80241FE0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9D9004 80241FE4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9D9008 80241FE8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9D900C 80241FEC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9010 80241FF0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9014 80241FF4 03E00008 */  jr        $ra
/* 9D9018 80241FF8 27BD0028 */   addiu    $sp, $sp, 0x28
