.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BA8_7EB8B8
/* 7EB8B8 80240BA8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7EB8BC 80240BAC AFB00010 */  sw        $s0, 0x10($sp)
/* 7EB8C0 80240BB0 0080802D */  daddu     $s0, $a0, $zero
/* 7EB8C4 80240BB4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7EB8C8 80240BB8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7EB8CC 80240BBC AFB20018 */  sw        $s2, 0x18($sp)
/* 7EB8D0 80240BC0 10A00009 */  beqz      $a1, .L80240BE8
/* 7EB8D4 80240BC4 AFB10014 */   sw       $s1, 0x14($sp)
/* 7EB8D8 80240BC8 0000202D */  daddu     $a0, $zero, $zero
/* 7EB8DC 80240BCC 0080282D */  daddu     $a1, $a0, $zero
/* 7EB8E0 80240BD0 0080302D */  daddu     $a2, $a0, $zero
/* 7EB8E4 80240BD4 0C046F97 */  jal       set_background_color_blend
/* 7EB8E8 80240BD8 240700FF */   addiu    $a3, $zero, 0xff
/* 7EB8EC 80240BDC 240200FF */  addiu     $v0, $zero, 0xff
/* 7EB8F0 80240BE0 AE020070 */  sw        $v0, 0x70($s0)
/* 7EB8F4 80240BE4 AE000074 */  sw        $zero, 0x74($s0)
.L80240BE8:
/* 7EB8F8 80240BE8 8E020070 */  lw        $v0, 0x70($s0)
/* 7EB8FC 80240BEC 2442FFF8 */  addiu     $v0, $v0, -8
/* 7EB900 80240BF0 04410002 */  bgez      $v0, .L80240BFC
/* 7EB904 80240BF4 AE020070 */   sw       $v0, 0x70($s0)
/* 7EB908 80240BF8 AE000070 */  sw        $zero, 0x70($s0)
.L80240BFC:
/* 7EB90C 80240BFC 0000202D */  daddu     $a0, $zero, $zero
/* 7EB910 80240C00 0080282D */  daddu     $a1, $a0, $zero
/* 7EB914 80240C04 92070073 */  lbu       $a3, 0x73($s0)
/* 7EB918 80240C08 0C046F97 */  jal       set_background_color_blend
/* 7EB91C 80240C0C 0080302D */   daddu    $a2, $a0, $zero
/* 7EB920 80240C10 8E020070 */  lw        $v0, 0x70($s0)
/* 7EB924 80240C14 14400006 */  bnez      $v0, .L80240C30
/* 7EB928 80240C18 00000000 */   nop      
/* 7EB92C 80240C1C 8E020074 */  lw        $v0, 0x74($s0)
/* 7EB930 80240C20 14400003 */  bnez      $v0, .L80240C30
/* 7EB934 80240C24 24020001 */   addiu    $v0, $zero, 1
/* 7EB938 80240C28 0809033F */  j         .L80240CFC
/* 7EB93C 80240C2C AE020074 */   sw       $v0, 0x74($s0)
.L80240C30:
/* 7EB940 80240C30 8E030074 */  lw        $v1, 0x74($s0)
/* 7EB944 80240C34 24020001 */  addiu     $v0, $zero, 1
/* 7EB948 80240C38 14620031 */  bne       $v1, $v0, .L80240D00
/* 7EB94C 80240C3C 0000102D */   daddu    $v0, $zero, $zero
/* 7EB950 80240C40 0C04760B */  jal       func_8011D82C
/* 7EB954 80240C44 0000202D */   daddu    $a0, $zero, $zero
/* 7EB958 80240C48 0000802D */  daddu     $s0, $zero, $zero
/* 7EB95C 80240C4C 2413FFFC */  addiu     $s3, $zero, -4
/* 7EB960 80240C50 24120006 */  addiu     $s2, $zero, 6
/* 7EB964 80240C54 3C11FF7F */  lui       $s1, 0xff7f
/* 7EB968 80240C58 3C028015 */  lui       $v0, 0x8015
/* 7EB96C 80240C5C 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* 7EB970 80240C60 3631FFFF */  ori       $s1, $s1, 0xffff
/* 7EB974 80240C64 A0400000 */  sb        $zero, ($v0)
.L80240C68:
/* 7EB978 80240C68 0C00E2B7 */  jal       get_npc_by_index
/* 7EB97C 80240C6C 0200202D */   daddu    $a0, $s0, $zero
/* 7EB980 80240C70 0040202D */  daddu     $a0, $v0, $zero
/* 7EB984 80240C74 5080000B */  beql      $a0, $zero, .L80240CA4
/* 7EB988 80240C78 26100001 */   addiu    $s0, $s0, 1
/* 7EB98C 80240C7C 8C820000 */  lw        $v0, ($a0)
/* 7EB990 80240C80 50400008 */  beql      $v0, $zero, .L80240CA4
/* 7EB994 80240C84 26100001 */   addiu    $s0, $s0, 1
/* 7EB998 80240C88 808300A4 */  lb        $v1, 0xa4($a0)
/* 7EB99C 80240C8C 10730005 */  beq       $v1, $s3, .L80240CA4
/* 7EB9A0 80240C90 26100001 */   addiu    $s0, $s0, 1
/* 7EB9A4 80240C94 10720003 */  beq       $v1, $s2, .L80240CA4
/* 7EB9A8 80240C98 00000000 */   nop      
/* 7EB9AC 80240C9C 00511024 */  and       $v0, $v0, $s1
/* 7EB9B0 80240CA0 AC820000 */  sw        $v0, ($a0)
.L80240CA4:
/* 7EB9B4 80240CA4 2A020040 */  slti      $v0, $s0, 0x40
/* 7EB9B8 80240CA8 1440FFEF */  bnez      $v0, .L80240C68
/* 7EB9BC 80240CAC 00000000 */   nop      
/* 7EB9C0 80240CB0 0000802D */  daddu     $s0, $zero, $zero
/* 7EB9C4 80240CB4 3C11F7FF */  lui       $s1, 0xf7ff
/* 7EB9C8 80240CB8 3631FFFF */  ori       $s1, $s1, 0xffff
.L80240CBC:
/* 7EB9CC 80240CBC 0C04C3D6 */  jal       get_item_entity
/* 7EB9D0 80240CC0 0200202D */   daddu    $a0, $s0, $zero
/* 7EB9D4 80240CC4 0040182D */  daddu     $v1, $v0, $zero
/* 7EB9D8 80240CC8 10600007 */  beqz      $v1, .L80240CE8
/* 7EB9DC 80240CCC 26100001 */   addiu    $s0, $s0, 1
/* 7EB9E0 80240CD0 8C640000 */  lw        $a0, ($v1)
/* 7EB9E4 80240CD4 30820010 */  andi      $v0, $a0, 0x10
/* 7EB9E8 80240CD8 10400003 */  beqz      $v0, .L80240CE8
/* 7EB9EC 80240CDC 00000000 */   nop      
/* 7EB9F0 80240CE0 00911024 */  and       $v0, $a0, $s1
/* 7EB9F4 80240CE4 AC620000 */  sw        $v0, ($v1)
.L80240CE8:
/* 7EB9F8 80240CE8 2A020100 */  slti      $v0, $s0, 0x100
/* 7EB9FC 80240CEC 1440FFF3 */  bnez      $v0, .L80240CBC
/* 7EBA00 80240CF0 24020002 */   addiu    $v0, $zero, 2
/* 7EBA04 80240CF4 08090340 */  j         .L80240D00
/* 7EBA08 80240CF8 00000000 */   nop      
.L80240CFC:
/* 7EBA0C 80240CFC 0000102D */  daddu     $v0, $zero, $zero
.L80240D00:
/* 7EBA10 80240D00 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7EBA14 80240D04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7EBA18 80240D08 8FB20018 */  lw        $s2, 0x18($sp)
/* 7EBA1C 80240D0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EBA20 80240D10 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EBA24 80240D14 03E00008 */  jr        $ra
/* 7EBA28 80240D18 27BD0028 */   addiu    $sp, $sp, 0x28
