.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FC8_B36B98
/* B36B98 80241FC8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B36B9C 80241FCC AFB10014 */  sw        $s1, 0x14($sp)
/* B36BA0 80241FD0 0080882D */  daddu     $s1, $a0, $zero
/* B36BA4 80241FD4 AFBF0024 */  sw        $ra, 0x24($sp)
/* B36BA8 80241FD8 AFB40020 */  sw        $s4, 0x20($sp)
/* B36BAC 80241FDC AFB3001C */  sw        $s3, 0x1c($sp)
/* B36BB0 80241FE0 AFB20018 */  sw        $s2, 0x18($sp)
/* B36BB4 80241FE4 10A00033 */  beqz      $a1, .L802420B4
/* B36BB8 80241FE8 AFB00010 */   sw       $s0, 0x10($sp)
/* B36BBC 80241FEC 0C04760B */  jal       func_8011D82C
/* B36BC0 80241FF0 24040001 */   addiu    $a0, $zero, 1
/* B36BC4 80241FF4 0000202D */  daddu     $a0, $zero, $zero
/* B36BC8 80241FF8 0080282D */  daddu     $a1, $a0, $zero
/* B36BCC 80241FFC 0080302D */  daddu     $a2, $a0, $zero
/* B36BD0 80242000 0080382D */  daddu     $a3, $a0, $zero
/* B36BD4 80242004 0080802D */  daddu     $s0, $a0, $zero
/* B36BD8 80242008 2414FFFC */  addiu     $s4, $zero, -4
/* B36BDC 8024200C 24130011 */  addiu     $s3, $zero, 0x11
/* B36BE0 80242010 3C120080 */  lui       $s2, 0x80
/* B36BE4 80242014 3C038015 */  lui       $v1, %hi(D_801512F0)
/* B36BE8 80242018 8C6312F0 */  lw        $v1, %lo(D_801512F0)($v1)
/* B36BEC 8024201C 24020001 */  addiu     $v0, $zero, 1
/* B36BF0 80242020 0C046F97 */  jal       set_background_color_blend
/* B36BF4 80242024 A0620000 */   sb       $v0, ($v1)
.L80242028:
/* B36BF8 80242028 0C00E2B7 */  jal       get_npc_by_index
/* B36BFC 8024202C 0200202D */   daddu    $a0, $s0, $zero
/* B36C00 80242030 0040202D */  daddu     $a0, $v0, $zero
/* B36C04 80242034 5080000B */  beql      $a0, $zero, .L80242064
/* B36C08 80242038 26100001 */   addiu    $s0, $s0, 1
/* B36C0C 8024203C 8C820000 */  lw        $v0, ($a0)
/* B36C10 80242040 50400008 */  beql      $v0, $zero, .L80242064
/* B36C14 80242044 26100001 */   addiu    $s0, $s0, 1
/* B36C18 80242048 808300A4 */  lb        $v1, 0xa4($a0)
/* B36C1C 8024204C 10740005 */  beq       $v1, $s4, .L80242064
/* B36C20 80242050 26100001 */   addiu    $s0, $s0, 1
/* B36C24 80242054 10730003 */  beq       $v1, $s3, .L80242064
/* B36C28 80242058 00000000 */   nop      
/* B36C2C 8024205C 00521025 */  or        $v0, $v0, $s2
/* B36C30 80242060 AC820000 */  sw        $v0, ($a0)
.L80242064:
/* B36C34 80242064 2A020040 */  slti      $v0, $s0, 0x40
/* B36C38 80242068 1440FFEF */  bnez      $v0, .L80242028
/* B36C3C 8024206C 00000000 */   nop      
/* B36C40 80242070 0000802D */  daddu     $s0, $zero, $zero
/* B36C44 80242074 3C120800 */  lui       $s2, 0x800
.L80242078:
/* B36C48 80242078 0C04C3D6 */  jal       get_item_entity
/* B36C4C 8024207C 0200202D */   daddu    $a0, $s0, $zero
/* B36C50 80242080 0040182D */  daddu     $v1, $v0, $zero
/* B36C54 80242084 10600007 */  beqz      $v1, .L802420A4
/* B36C58 80242088 26100001 */   addiu    $s0, $s0, 1
/* B36C5C 8024208C 8C640000 */  lw        $a0, ($v1)
/* B36C60 80242090 30820010 */  andi      $v0, $a0, 0x10
/* B36C64 80242094 10400003 */  beqz      $v0, .L802420A4
/* B36C68 80242098 00000000 */   nop      
/* B36C6C 8024209C 00921025 */  or        $v0, $a0, $s2
/* B36C70 802420A0 AC620000 */  sw        $v0, ($v1)
.L802420A4:
/* B36C74 802420A4 2A020100 */  slti      $v0, $s0, 0x100
/* B36C78 802420A8 1440FFF3 */  bnez      $v0, .L80242078
/* B36C7C 802420AC 00000000 */   nop      
/* B36C80 802420B0 AE200070 */  sw        $zero, 0x70($s1)
.L802420B4:
/* B36C84 802420B4 8E220070 */  lw        $v0, 0x70($s1)
/* B36C88 802420B8 24420008 */  addiu     $v0, $v0, 8
/* B36C8C 802420BC AE220070 */  sw        $v0, 0x70($s1)
/* B36C90 802420C0 28420100 */  slti      $v0, $v0, 0x100
/* B36C94 802420C4 14400003 */  bnez      $v0, .L802420D4
/* B36C98 802420C8 0000202D */   daddu    $a0, $zero, $zero
/* B36C9C 802420CC 240200FF */  addiu     $v0, $zero, 0xff
/* B36CA0 802420D0 AE220070 */  sw        $v0, 0x70($s1)
.L802420D4:
/* B36CA4 802420D4 0080282D */  daddu     $a1, $a0, $zero
/* B36CA8 802420D8 92270073 */  lbu       $a3, 0x73($s1)
/* B36CAC 802420DC 0C046F97 */  jal       set_background_color_blend
/* B36CB0 802420E0 0080302D */   daddu    $a2, $a0, $zero
/* B36CB4 802420E4 8E220070 */  lw        $v0, 0x70($s1)
/* B36CB8 802420E8 8FBF0024 */  lw        $ra, 0x24($sp)
/* B36CBC 802420EC 8FB40020 */  lw        $s4, 0x20($sp)
/* B36CC0 802420F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* B36CC4 802420F4 8FB20018 */  lw        $s2, 0x18($sp)
/* B36CC8 802420F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B36CCC 802420FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B36CD0 80242100 384200FF */  xori      $v0, $v0, 0xff
/* B36CD4 80242104 2C420001 */  sltiu     $v0, $v0, 1
/* B36CD8 80242108 00021040 */  sll       $v0, $v0, 1
/* B36CDC 8024210C 03E00008 */  jr        $ra
/* B36CE0 80242110 27BD0028 */   addiu    $sp, $sp, 0x28
