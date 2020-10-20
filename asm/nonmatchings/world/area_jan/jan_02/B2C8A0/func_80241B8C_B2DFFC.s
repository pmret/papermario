.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B8C_B2DFFC
/* B2DFFC 80241B8C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B2E000 80241B90 AFB00010 */  sw        $s0, 0x10($sp)
/* B2E004 80241B94 0080802D */  daddu     $s0, $a0, $zero
/* B2E008 80241B98 AFBF0020 */  sw        $ra, 0x20($sp)
/* B2E00C 80241B9C AFB3001C */  sw        $s3, 0x1c($sp)
/* B2E010 80241BA0 AFB20018 */  sw        $s2, 0x18($sp)
/* B2E014 80241BA4 10A00009 */  beqz      $a1, .L80241BCC
/* B2E018 80241BA8 AFB10014 */   sw       $s1, 0x14($sp)
/* B2E01C 80241BAC 0000202D */  daddu     $a0, $zero, $zero
/* B2E020 80241BB0 0080282D */  daddu     $a1, $a0, $zero
/* B2E024 80241BB4 0080302D */  daddu     $a2, $a0, $zero
/* B2E028 80241BB8 0C046F97 */  jal       set_background_color_blend
/* B2E02C 80241BBC 240700FF */   addiu    $a3, $zero, 0xff
/* B2E030 80241BC0 240200FF */  addiu     $v0, $zero, 0xff
/* B2E034 80241BC4 AE020070 */  sw        $v0, 0x70($s0)
/* B2E038 80241BC8 AE000074 */  sw        $zero, 0x74($s0)
.L80241BCC:
/* B2E03C 80241BCC 8E020070 */  lw        $v0, 0x70($s0)
/* B2E040 80241BD0 2442FFF8 */  addiu     $v0, $v0, -8
/* B2E044 80241BD4 04410002 */  bgez      $v0, .L80241BE0
/* B2E048 80241BD8 AE020070 */   sw       $v0, 0x70($s0)
/* B2E04C 80241BDC AE000070 */  sw        $zero, 0x70($s0)
.L80241BE0:
/* B2E050 80241BE0 0000202D */  daddu     $a0, $zero, $zero
/* B2E054 80241BE4 0080282D */  daddu     $a1, $a0, $zero
/* B2E058 80241BE8 92070073 */  lbu       $a3, 0x73($s0)
/* B2E05C 80241BEC 0C046F97 */  jal       set_background_color_blend
/* B2E060 80241BF0 0080302D */   daddu    $a2, $a0, $zero
/* B2E064 80241BF4 8E020070 */  lw        $v0, 0x70($s0)
/* B2E068 80241BF8 14400006 */  bnez      $v0, .L80241C14
/* B2E06C 80241BFC 00000000 */   nop      
/* B2E070 80241C00 8E020074 */  lw        $v0, 0x74($s0)
/* B2E074 80241C04 14400003 */  bnez      $v0, .L80241C14
/* B2E078 80241C08 24020001 */   addiu    $v0, $zero, 1
/* B2E07C 80241C0C 08090738 */  j         .L80241CE0
/* B2E080 80241C10 AE020074 */   sw       $v0, 0x74($s0)
.L80241C14:
/* B2E084 80241C14 8E030074 */  lw        $v1, 0x74($s0)
/* B2E088 80241C18 24020001 */  addiu     $v0, $zero, 1
/* B2E08C 80241C1C 14620031 */  bne       $v1, $v0, .L80241CE4
/* B2E090 80241C20 0000102D */   daddu    $v0, $zero, $zero
/* B2E094 80241C24 0C04760B */  jal       func_8011D82C
/* B2E098 80241C28 0000202D */   daddu    $a0, $zero, $zero
/* B2E09C 80241C2C 0000802D */  daddu     $s0, $zero, $zero
/* B2E0A0 80241C30 2413FFFC */  addiu     $s3, $zero, -4
/* B2E0A4 80241C34 24120005 */  addiu     $s2, $zero, 5
/* B2E0A8 80241C38 3C11FF7F */  lui       $s1, 0xff7f
/* B2E0AC 80241C3C 3C028015 */  lui       $v0, 0x8015
/* B2E0B0 80241C40 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* B2E0B4 80241C44 3631FFFF */  ori       $s1, $s1, 0xffff
/* B2E0B8 80241C48 A0400000 */  sb        $zero, ($v0)
.L80241C4C:
/* B2E0BC 80241C4C 0C00E2B7 */  jal       get_npc_by_index
/* B2E0C0 80241C50 0200202D */   daddu    $a0, $s0, $zero
/* B2E0C4 80241C54 0040202D */  daddu     $a0, $v0, $zero
/* B2E0C8 80241C58 5080000B */  beql      $a0, $zero, .L80241C88
/* B2E0CC 80241C5C 26100001 */   addiu    $s0, $s0, 1
/* B2E0D0 80241C60 8C820000 */  lw        $v0, ($a0)
/* B2E0D4 80241C64 50400008 */  beql      $v0, $zero, .L80241C88
/* B2E0D8 80241C68 26100001 */   addiu    $s0, $s0, 1
/* B2E0DC 80241C6C 808300A4 */  lb        $v1, 0xa4($a0)
/* B2E0E0 80241C70 10730005 */  beq       $v1, $s3, .L80241C88
/* B2E0E4 80241C74 26100001 */   addiu    $s0, $s0, 1
/* B2E0E8 80241C78 10720003 */  beq       $v1, $s2, .L80241C88
/* B2E0EC 80241C7C 00000000 */   nop      
/* B2E0F0 80241C80 00511024 */  and       $v0, $v0, $s1
/* B2E0F4 80241C84 AC820000 */  sw        $v0, ($a0)
.L80241C88:
/* B2E0F8 80241C88 2A020040 */  slti      $v0, $s0, 0x40
/* B2E0FC 80241C8C 1440FFEF */  bnez      $v0, .L80241C4C
/* B2E100 80241C90 00000000 */   nop      
/* B2E104 80241C94 0000802D */  daddu     $s0, $zero, $zero
/* B2E108 80241C98 3C11F7FF */  lui       $s1, 0xf7ff
/* B2E10C 80241C9C 3631FFFF */  ori       $s1, $s1, 0xffff
.L80241CA0:
/* B2E110 80241CA0 0C04C3D6 */  jal       get_item_entity
/* B2E114 80241CA4 0200202D */   daddu    $a0, $s0, $zero
/* B2E118 80241CA8 0040182D */  daddu     $v1, $v0, $zero
/* B2E11C 80241CAC 10600007 */  beqz      $v1, .L80241CCC
/* B2E120 80241CB0 26100001 */   addiu    $s0, $s0, 1
/* B2E124 80241CB4 8C640000 */  lw        $a0, ($v1)
/* B2E128 80241CB8 30820010 */  andi      $v0, $a0, 0x10
/* B2E12C 80241CBC 10400003 */  beqz      $v0, .L80241CCC
/* B2E130 80241CC0 00000000 */   nop      
/* B2E134 80241CC4 00911024 */  and       $v0, $a0, $s1
/* B2E138 80241CC8 AC620000 */  sw        $v0, ($v1)
.L80241CCC:
/* B2E13C 80241CCC 2A020100 */  slti      $v0, $s0, 0x100
/* B2E140 80241CD0 1440FFF3 */  bnez      $v0, .L80241CA0
/* B2E144 80241CD4 24020002 */   addiu    $v0, $zero, 2
/* B2E148 80241CD8 08090739 */  j         .L80241CE4
/* B2E14C 80241CDC 00000000 */   nop      
.L80241CE0:
/* B2E150 80241CE0 0000102D */  daddu     $v0, $zero, $zero
.L80241CE4:
/* B2E154 80241CE4 8FBF0020 */  lw        $ra, 0x20($sp)
/* B2E158 80241CE8 8FB3001C */  lw        $s3, 0x1c($sp)
/* B2E15C 80241CEC 8FB20018 */  lw        $s2, 0x18($sp)
/* B2E160 80241CF0 8FB10014 */  lw        $s1, 0x14($sp)
/* B2E164 80241CF4 8FB00010 */  lw        $s0, 0x10($sp)
/* B2E168 80241CF8 03E00008 */  jr        $ra
/* B2E16C 80241CFC 27BD0028 */   addiu    $sp, $sp, 0x28
