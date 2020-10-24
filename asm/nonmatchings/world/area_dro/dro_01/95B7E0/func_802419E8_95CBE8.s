.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419E8_95CBE8
/* 95CBE8 802419E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 95CBEC 802419EC AFB00010 */  sw        $s0, 0x10($sp)
/* 95CBF0 802419F0 0080802D */  daddu     $s0, $a0, $zero
/* 95CBF4 802419F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 95CBF8 802419F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 95CBFC 802419FC AFB20018 */  sw        $s2, 0x18($sp)
/* 95CC00 80241A00 10A00009 */  beqz      $a1, .L80241A28
/* 95CC04 80241A04 AFB10014 */   sw       $s1, 0x14($sp)
/* 95CC08 80241A08 0000202D */  daddu     $a0, $zero, $zero
/* 95CC0C 80241A0C 0080282D */  daddu     $a1, $a0, $zero
/* 95CC10 80241A10 0080302D */  daddu     $a2, $a0, $zero
/* 95CC14 80241A14 0C046F97 */  jal       set_background_color_blend
/* 95CC18 80241A18 240700FF */   addiu    $a3, $zero, 0xff
/* 95CC1C 80241A1C 240200FF */  addiu     $v0, $zero, 0xff
/* 95CC20 80241A20 AE020070 */  sw        $v0, 0x70($s0)
/* 95CC24 80241A24 AE000074 */  sw        $zero, 0x74($s0)
.L80241A28:
/* 95CC28 80241A28 8E020070 */  lw        $v0, 0x70($s0)
/* 95CC2C 80241A2C 2442FFF8 */  addiu     $v0, $v0, -8
/* 95CC30 80241A30 04410002 */  bgez      $v0, .L80241A3C
/* 95CC34 80241A34 AE020070 */   sw       $v0, 0x70($s0)
/* 95CC38 80241A38 AE000070 */  sw        $zero, 0x70($s0)
.L80241A3C:
/* 95CC3C 80241A3C 0000202D */  daddu     $a0, $zero, $zero
/* 95CC40 80241A40 0080282D */  daddu     $a1, $a0, $zero
/* 95CC44 80241A44 92070073 */  lbu       $a3, 0x73($s0)
/* 95CC48 80241A48 0C046F97 */  jal       set_background_color_blend
/* 95CC4C 80241A4C 0080302D */   daddu    $a2, $a0, $zero
/* 95CC50 80241A50 8E020070 */  lw        $v0, 0x70($s0)
/* 95CC54 80241A54 14400006 */  bnez      $v0, .L80241A70
/* 95CC58 80241A58 00000000 */   nop      
/* 95CC5C 80241A5C 8E020074 */  lw        $v0, 0x74($s0)
/* 95CC60 80241A60 14400003 */  bnez      $v0, .L80241A70
/* 95CC64 80241A64 24020001 */   addiu    $v0, $zero, 1
/* 95CC68 80241A68 080906CF */  j         .L80241B3C
/* 95CC6C 80241A6C AE020074 */   sw       $v0, 0x74($s0)
.L80241A70:
/* 95CC70 80241A70 8E030074 */  lw        $v1, 0x74($s0)
/* 95CC74 80241A74 24020001 */  addiu     $v0, $zero, 1
/* 95CC78 80241A78 14620031 */  bne       $v1, $v0, .L80241B40
/* 95CC7C 80241A7C 0000102D */   daddu    $v0, $zero, $zero
/* 95CC80 80241A80 0C04760B */  jal       func_8011D82C
/* 95CC84 80241A84 0000202D */   daddu    $a0, $zero, $zero
/* 95CC88 80241A88 0000802D */  daddu     $s0, $zero, $zero
/* 95CC8C 80241A8C 2413FFFC */  addiu     $s3, $zero, -4
/* 95CC90 80241A90 2412000A */  addiu     $s2, $zero, 0xa
/* 95CC94 80241A94 3C11FF7F */  lui       $s1, 0xff7f
/* 95CC98 80241A98 3C028015 */  lui       $v0, 0x8015
/* 95CC9C 80241A9C 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* 95CCA0 80241AA0 3631FFFF */  ori       $s1, $s1, 0xffff
/* 95CCA4 80241AA4 A0400000 */  sb        $zero, ($v0)
.L80241AA8:
/* 95CCA8 80241AA8 0C00E2B7 */  jal       get_npc_by_index
/* 95CCAC 80241AAC 0200202D */   daddu    $a0, $s0, $zero
/* 95CCB0 80241AB0 0040202D */  daddu     $a0, $v0, $zero
/* 95CCB4 80241AB4 5080000B */  beql      $a0, $zero, .L80241AE4
/* 95CCB8 80241AB8 26100001 */   addiu    $s0, $s0, 1
/* 95CCBC 80241ABC 8C820000 */  lw        $v0, ($a0)
/* 95CCC0 80241AC0 50400008 */  beql      $v0, $zero, .L80241AE4
/* 95CCC4 80241AC4 26100001 */   addiu    $s0, $s0, 1
/* 95CCC8 80241AC8 808300A4 */  lb        $v1, 0xa4($a0)
/* 95CCCC 80241ACC 10730005 */  beq       $v1, $s3, .L80241AE4
/* 95CCD0 80241AD0 26100001 */   addiu    $s0, $s0, 1
/* 95CCD4 80241AD4 10720003 */  beq       $v1, $s2, .L80241AE4
/* 95CCD8 80241AD8 00000000 */   nop      
/* 95CCDC 80241ADC 00511024 */  and       $v0, $v0, $s1
/* 95CCE0 80241AE0 AC820000 */  sw        $v0, ($a0)
.L80241AE4:
/* 95CCE4 80241AE4 2A020040 */  slti      $v0, $s0, 0x40
/* 95CCE8 80241AE8 1440FFEF */  bnez      $v0, .L80241AA8
/* 95CCEC 80241AEC 00000000 */   nop      
/* 95CCF0 80241AF0 0000802D */  daddu     $s0, $zero, $zero
/* 95CCF4 80241AF4 3C11F7FF */  lui       $s1, 0xf7ff
/* 95CCF8 80241AF8 3631FFFF */  ori       $s1, $s1, 0xffff
.L80241AFC:
/* 95CCFC 80241AFC 0C04C3D6 */  jal       get_item_entity
/* 95CD00 80241B00 0200202D */   daddu    $a0, $s0, $zero
/* 95CD04 80241B04 0040182D */  daddu     $v1, $v0, $zero
/* 95CD08 80241B08 10600007 */  beqz      $v1, .L80241B28
/* 95CD0C 80241B0C 26100001 */   addiu    $s0, $s0, 1
/* 95CD10 80241B10 8C640000 */  lw        $a0, ($v1)
/* 95CD14 80241B14 30820010 */  andi      $v0, $a0, 0x10
/* 95CD18 80241B18 10400003 */  beqz      $v0, .L80241B28
/* 95CD1C 80241B1C 00000000 */   nop      
/* 95CD20 80241B20 00911024 */  and       $v0, $a0, $s1
/* 95CD24 80241B24 AC620000 */  sw        $v0, ($v1)
.L80241B28:
/* 95CD28 80241B28 2A020100 */  slti      $v0, $s0, 0x100
/* 95CD2C 80241B2C 1440FFF3 */  bnez      $v0, .L80241AFC
/* 95CD30 80241B30 24020002 */   addiu    $v0, $zero, 2
/* 95CD34 80241B34 080906D0 */  j         .L80241B40
/* 95CD38 80241B38 00000000 */   nop      
.L80241B3C:
/* 95CD3C 80241B3C 0000102D */  daddu     $v0, $zero, $zero
.L80241B40:
/* 95CD40 80241B40 8FBF0020 */  lw        $ra, 0x20($sp)
/* 95CD44 80241B44 8FB3001C */  lw        $s3, 0x1c($sp)
/* 95CD48 80241B48 8FB20018 */  lw        $s2, 0x18($sp)
/* 95CD4C 80241B4C 8FB10014 */  lw        $s1, 0x14($sp)
/* 95CD50 80241B50 8FB00010 */  lw        $s0, 0x10($sp)
/* 95CD54 80241B54 03E00008 */  jr        $ra
/* 95CD58 80241B58 27BD0028 */   addiu    $sp, $sp, 0x28
