.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242114_B36CE4
/* B36CE4 80242114 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B36CE8 80242118 AFB00010 */  sw        $s0, 0x10($sp)
/* B36CEC 8024211C 0080802D */  daddu     $s0, $a0, $zero
/* B36CF0 80242120 AFBF0020 */  sw        $ra, 0x20($sp)
/* B36CF4 80242124 AFB3001C */  sw        $s3, 0x1c($sp)
/* B36CF8 80242128 AFB20018 */  sw        $s2, 0x18($sp)
/* B36CFC 8024212C 10A00009 */  beqz      $a1, .L80242154
/* B36D00 80242130 AFB10014 */   sw       $s1, 0x14($sp)
/* B36D04 80242134 0000202D */  daddu     $a0, $zero, $zero
/* B36D08 80242138 0080282D */  daddu     $a1, $a0, $zero
/* B36D0C 8024213C 0080302D */  daddu     $a2, $a0, $zero
/* B36D10 80242140 0C046F97 */  jal       set_background_color_blend
/* B36D14 80242144 240700FF */   addiu    $a3, $zero, 0xff
/* B36D18 80242148 240200FF */  addiu     $v0, $zero, 0xff
/* B36D1C 8024214C AE020070 */  sw        $v0, 0x70($s0)
/* B36D20 80242150 AE000074 */  sw        $zero, 0x74($s0)
.L80242154:
/* B36D24 80242154 8E020070 */  lw        $v0, 0x70($s0)
/* B36D28 80242158 2442FFF8 */  addiu     $v0, $v0, -8
/* B36D2C 8024215C 04410002 */  bgez      $v0, .L80242168
/* B36D30 80242160 AE020070 */   sw       $v0, 0x70($s0)
/* B36D34 80242164 AE000070 */  sw        $zero, 0x70($s0)
.L80242168:
/* B36D38 80242168 0000202D */  daddu     $a0, $zero, $zero
/* B36D3C 8024216C 0080282D */  daddu     $a1, $a0, $zero
/* B36D40 80242170 92070073 */  lbu       $a3, 0x73($s0)
/* B36D44 80242174 0C046F97 */  jal       set_background_color_blend
/* B36D48 80242178 0080302D */   daddu    $a2, $a0, $zero
/* B36D4C 8024217C 8E020070 */  lw        $v0, 0x70($s0)
/* B36D50 80242180 14400006 */  bnez      $v0, .L8024219C
/* B36D54 80242184 00000000 */   nop      
/* B36D58 80242188 8E020074 */  lw        $v0, 0x74($s0)
/* B36D5C 8024218C 14400003 */  bnez      $v0, .L8024219C
/* B36D60 80242190 24020001 */   addiu    $v0, $zero, 1
/* B36D64 80242194 0809089A */  j         .L80242268
/* B36D68 80242198 AE020074 */   sw       $v0, 0x74($s0)
.L8024219C:
/* B36D6C 8024219C 8E030074 */  lw        $v1, 0x74($s0)
/* B36D70 802421A0 24020001 */  addiu     $v0, $zero, 1
/* B36D74 802421A4 14620031 */  bne       $v1, $v0, .L8024226C
/* B36D78 802421A8 0000102D */   daddu    $v0, $zero, $zero
/* B36D7C 802421AC 0C04760B */  jal       func_8011D82C
/* B36D80 802421B0 0000202D */   daddu    $a0, $zero, $zero
/* B36D84 802421B4 0000802D */  daddu     $s0, $zero, $zero
/* B36D88 802421B8 2413FFFC */  addiu     $s3, $zero, -4
/* B36D8C 802421BC 24120011 */  addiu     $s2, $zero, 0x11
/* B36D90 802421C0 3C11FF7F */  lui       $s1, 0xff7f
/* B36D94 802421C4 3C028015 */  lui       $v0, 0x8015
/* B36D98 802421C8 8C4212F0 */  lw        $v0, 0x12f0($v0)
/* B36D9C 802421CC 3631FFFF */  ori       $s1, $s1, 0xffff
/* B36DA0 802421D0 A0400000 */  sb        $zero, ($v0)
.L802421D4:
/* B36DA4 802421D4 0C00E2B7 */  jal       get_npc_by_index
/* B36DA8 802421D8 0200202D */   daddu    $a0, $s0, $zero
/* B36DAC 802421DC 0040202D */  daddu     $a0, $v0, $zero
/* B36DB0 802421E0 5080000B */  beql      $a0, $zero, .L80242210
/* B36DB4 802421E4 26100001 */   addiu    $s0, $s0, 1
/* B36DB8 802421E8 8C820000 */  lw        $v0, ($a0)
/* B36DBC 802421EC 50400008 */  beql      $v0, $zero, .L80242210
/* B36DC0 802421F0 26100001 */   addiu    $s0, $s0, 1
/* B36DC4 802421F4 808300A4 */  lb        $v1, 0xa4($a0)
/* B36DC8 802421F8 10730005 */  beq       $v1, $s3, .L80242210
/* B36DCC 802421FC 26100001 */   addiu    $s0, $s0, 1
/* B36DD0 80242200 10720003 */  beq       $v1, $s2, .L80242210
/* B36DD4 80242204 00000000 */   nop      
/* B36DD8 80242208 00511024 */  and       $v0, $v0, $s1
/* B36DDC 8024220C AC820000 */  sw        $v0, ($a0)
.L80242210:
/* B36DE0 80242210 2A020040 */  slti      $v0, $s0, 0x40
/* B36DE4 80242214 1440FFEF */  bnez      $v0, .L802421D4
/* B36DE8 80242218 00000000 */   nop      
/* B36DEC 8024221C 0000802D */  daddu     $s0, $zero, $zero
/* B36DF0 80242220 3C11F7FF */  lui       $s1, 0xf7ff
/* B36DF4 80242224 3631FFFF */  ori       $s1, $s1, 0xffff
.L80242228:
/* B36DF8 80242228 0C04C3D6 */  jal       get_item_entity
/* B36DFC 8024222C 0200202D */   daddu    $a0, $s0, $zero
/* B36E00 80242230 0040182D */  daddu     $v1, $v0, $zero
/* B36E04 80242234 10600007 */  beqz      $v1, .L80242254
/* B36E08 80242238 26100001 */   addiu    $s0, $s0, 1
/* B36E0C 8024223C 8C640000 */  lw        $a0, ($v1)
/* B36E10 80242240 30820010 */  andi      $v0, $a0, 0x10
/* B36E14 80242244 10400003 */  beqz      $v0, .L80242254
/* B36E18 80242248 00000000 */   nop      
/* B36E1C 8024224C 00911024 */  and       $v0, $a0, $s1
/* B36E20 80242250 AC620000 */  sw        $v0, ($v1)
.L80242254:
/* B36E24 80242254 2A020100 */  slti      $v0, $s0, 0x100
/* B36E28 80242258 1440FFF3 */  bnez      $v0, .L80242228
/* B36E2C 8024225C 24020002 */   addiu    $v0, $zero, 2
/* B36E30 80242260 0809089B */  j         .L8024226C
/* B36E34 80242264 00000000 */   nop      
.L80242268:
/* B36E38 80242268 0000102D */  daddu     $v0, $zero, $zero
.L8024226C:
/* B36E3C 8024226C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B36E40 80242270 8FB3001C */  lw        $s3, 0x1c($sp)
/* B36E44 80242274 8FB20018 */  lw        $s2, 0x18($sp)
/* B36E48 80242278 8FB10014 */  lw        $s1, 0x14($sp)
/* B36E4C 8024227C 8FB00010 */  lw        $s0, 0x10($sp)
/* B36E50 80242280 03E00008 */  jr        $ra
/* B36E54 80242284 27BD0028 */   addiu    $sp, $sp, 0x28
