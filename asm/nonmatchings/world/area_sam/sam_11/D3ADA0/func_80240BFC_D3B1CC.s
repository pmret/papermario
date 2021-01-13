.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BFC_D3B1CC
/* D3B1CC 80240BFC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D3B1D0 80240C00 AFB10014 */  sw        $s1, 0x14($sp)
/* D3B1D4 80240C04 0080882D */  daddu     $s1, $a0, $zero
/* D3B1D8 80240C08 AFBF0024 */  sw        $ra, 0x24($sp)
/* D3B1DC 80240C0C AFB40020 */  sw        $s4, 0x20($sp)
/* D3B1E0 80240C10 AFB3001C */  sw        $s3, 0x1c($sp)
/* D3B1E4 80240C14 AFB20018 */  sw        $s2, 0x18($sp)
/* D3B1E8 80240C18 10A00033 */  beqz      $a1, .L80240CE8
/* D3B1EC 80240C1C AFB00010 */   sw       $s0, 0x10($sp)
/* D3B1F0 80240C20 0C04760B */  jal       func_8011D82C
/* D3B1F4 80240C24 24040001 */   addiu    $a0, $zero, 1
/* D3B1F8 80240C28 0000202D */  daddu     $a0, $zero, $zero
/* D3B1FC 80240C2C 0080282D */  daddu     $a1, $a0, $zero
/* D3B200 80240C30 0080302D */  daddu     $a2, $a0, $zero
/* D3B204 80240C34 0080382D */  daddu     $a3, $a0, $zero
/* D3B208 80240C38 0080802D */  daddu     $s0, $a0, $zero
/* D3B20C 80240C3C 2414FFFC */  addiu     $s4, $zero, -4
/* D3B210 80240C40 24130011 */  addiu     $s3, $zero, 0x11
/* D3B214 80240C44 3C120080 */  lui       $s2, 0x80
/* D3B218 80240C48 3C038015 */  lui       $v1, %hi(D_801512F0)
/* D3B21C 80240C4C 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* D3B220 80240C50 24020001 */  addiu     $v0, $zero, 1
/* D3B224 80240C54 0C046F97 */  jal       set_background_color_blend
/* D3B228 80240C58 A0620000 */   sb       $v0, ($v1)
.L80240C5C:
/* D3B22C 80240C5C 0C00E2B7 */  jal       get_npc_by_index
/* D3B230 80240C60 0200202D */   daddu    $a0, $s0, $zero
/* D3B234 80240C64 0040202D */  daddu     $a0, $v0, $zero
/* D3B238 80240C68 5080000B */  beql      $a0, $zero, .L80240C98
/* D3B23C 80240C6C 26100001 */   addiu    $s0, $s0, 1
/* D3B240 80240C70 8C820000 */  lw        $v0, ($a0)
/* D3B244 80240C74 50400008 */  beql      $v0, $zero, .L80240C98
/* D3B248 80240C78 26100001 */   addiu    $s0, $s0, 1
/* D3B24C 80240C7C 808300A4 */  lb        $v1, 0xa4($a0)
/* D3B250 80240C80 10740005 */  beq       $v1, $s4, .L80240C98
/* D3B254 80240C84 26100001 */   addiu    $s0, $s0, 1
/* D3B258 80240C88 10730003 */  beq       $v1, $s3, .L80240C98
/* D3B25C 80240C8C 00000000 */   nop
/* D3B260 80240C90 00521025 */  or        $v0, $v0, $s2
/* D3B264 80240C94 AC820000 */  sw        $v0, ($a0)
.L80240C98:
/* D3B268 80240C98 2A020040 */  slti      $v0, $s0, 0x40
/* D3B26C 80240C9C 1440FFEF */  bnez      $v0, .L80240C5C
/* D3B270 80240CA0 00000000 */   nop
/* D3B274 80240CA4 0000802D */  daddu     $s0, $zero, $zero
/* D3B278 80240CA8 3C120800 */  lui       $s2, 0x800
.L80240CAC:
/* D3B27C 80240CAC 0C04C3D6 */  jal       get_item_entity
/* D3B280 80240CB0 0200202D */   daddu    $a0, $s0, $zero
/* D3B284 80240CB4 0040182D */  daddu     $v1, $v0, $zero
/* D3B288 80240CB8 10600007 */  beqz      $v1, .L80240CD8
/* D3B28C 80240CBC 26100001 */   addiu    $s0, $s0, 1
/* D3B290 80240CC0 8C640000 */  lw        $a0, ($v1)
/* D3B294 80240CC4 30820010 */  andi      $v0, $a0, 0x10
/* D3B298 80240CC8 10400003 */  beqz      $v0, .L80240CD8
/* D3B29C 80240CCC 00000000 */   nop
/* D3B2A0 80240CD0 00921025 */  or        $v0, $a0, $s2
/* D3B2A4 80240CD4 AC620000 */  sw        $v0, ($v1)
.L80240CD8:
/* D3B2A8 80240CD8 2A020100 */  slti      $v0, $s0, 0x100
/* D3B2AC 80240CDC 1440FFF3 */  bnez      $v0, .L80240CAC
/* D3B2B0 80240CE0 00000000 */   nop
/* D3B2B4 80240CE4 AE200070 */  sw        $zero, 0x70($s1)
.L80240CE8:
/* D3B2B8 80240CE8 8E220070 */  lw        $v0, 0x70($s1)
/* D3B2BC 80240CEC 24420008 */  addiu     $v0, $v0, 8
/* D3B2C0 80240CF0 AE220070 */  sw        $v0, 0x70($s1)
/* D3B2C4 80240CF4 28420100 */  slti      $v0, $v0, 0x100
/* D3B2C8 80240CF8 14400003 */  bnez      $v0, .L80240D08
/* D3B2CC 80240CFC 0000202D */   daddu    $a0, $zero, $zero
/* D3B2D0 80240D00 240200FF */  addiu     $v0, $zero, 0xff
/* D3B2D4 80240D04 AE220070 */  sw        $v0, 0x70($s1)
.L80240D08:
/* D3B2D8 80240D08 0080282D */  daddu     $a1, $a0, $zero
/* D3B2DC 80240D0C 92270073 */  lbu       $a3, 0x73($s1)
/* D3B2E0 80240D10 0C046F97 */  jal       set_background_color_blend
/* D3B2E4 80240D14 0080302D */   daddu    $a2, $a0, $zero
/* D3B2E8 80240D18 8E220070 */  lw        $v0, 0x70($s1)
/* D3B2EC 80240D1C 8FBF0024 */  lw        $ra, 0x24($sp)
/* D3B2F0 80240D20 8FB40020 */  lw        $s4, 0x20($sp)
/* D3B2F4 80240D24 8FB3001C */  lw        $s3, 0x1c($sp)
/* D3B2F8 80240D28 8FB20018 */  lw        $s2, 0x18($sp)
/* D3B2FC 80240D2C 8FB10014 */  lw        $s1, 0x14($sp)
/* D3B300 80240D30 8FB00010 */  lw        $s0, 0x10($sp)
/* D3B304 80240D34 384200FF */  xori      $v0, $v0, 0xff
/* D3B308 80240D38 2C420001 */  sltiu     $v0, $v0, 1
/* D3B30C 80240D3C 00021040 */  sll       $v0, $v0, 1
/* D3B310 80240D40 03E00008 */  jr        $ra
/* D3B314 80240D44 27BD0028 */   addiu    $sp, $sp, 0x28
