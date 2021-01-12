.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FE4_E17D64
/* E17D64 80241FE4 27BDFF88 */  addiu     $sp, $sp, -0x78
/* E17D68 80241FE8 AFBF0058 */  sw        $ra, 0x58($sp)
/* E17D6C 80241FEC AFB70054 */  sw        $s7, 0x54($sp)
/* E17D70 80241FF0 AFB60050 */  sw        $s6, 0x50($sp)
/* E17D74 80241FF4 AFB5004C */  sw        $s5, 0x4c($sp)
/* E17D78 80241FF8 AFB40048 */  sw        $s4, 0x48($sp)
/* E17D7C 80241FFC AFB30044 */  sw        $s3, 0x44($sp)
/* E17D80 80242000 AFB20040 */  sw        $s2, 0x40($sp)
/* E17D84 80242004 AFB1003C */  sw        $s1, 0x3c($sp)
/* E17D88 80242008 AFB00038 */  sw        $s0, 0x38($sp)
/* E17D8C 8024200C F7B80070 */  sdc1      $f24, 0x70($sp)
/* E17D90 80242010 F7B60068 */  sdc1      $f22, 0x68($sp)
/* E17D94 80242014 F7B40060 */  sdc1      $f20, 0x60($sp)
/* E17D98 80242018 0C00FB3A */  jal       get_enemy
/* E17D9C 8024201C 0000202D */   daddu    $a0, $zero, $zero
/* E17DA0 80242020 0040882D */  daddu     $s1, $v0, $zero
/* E17DA4 80242024 24030004 */  addiu     $v1, $zero, 4
/* E17DA8 80242028 8E220078 */  lw        $v0, 0x78($s1)
/* E17DAC 8024202C 8E24006C */  lw        $a0, 0x6c($s1)
/* E17DB0 80242030 14430035 */  bne       $v0, $v1, .L80242108
/* E17DB4 80242034 0000902D */   daddu    $s2, $zero, $zero
/* E17DB8 80242038 2417FFFF */  addiu     $s7, $zero, -1
/* E17DBC 8024203C 27B60028 */  addiu     $s6, $sp, 0x28
/* E17DC0 80242040 27B5002C */  addiu     $s5, $sp, 0x2c
/* E17DC4 80242044 27B40030 */  addiu     $s4, $sp, 0x30
/* E17DC8 80242048 0080982D */  daddu     $s3, $a0, $zero
.L8024204C:
/* E17DCC 8024204C 8E640040 */  lw        $a0, 0x40($s3)
/* E17DD0 80242050 50970028 */  beql      $a0, $s7, .L802420F4
/* E17DD4 80242054 26520001 */   addiu    $s2, $s2, 1
/* E17DD8 80242058 0C00FB3A */  jal       get_enemy
/* E17DDC 8024205C 00000000 */   nop
/* E17DE0 80242060 84440008 */  lh        $a0, 8($v0)
/* E17DE4 80242064 0C00EABB */  jal       get_npc_unsafe
/* E17DE8 80242068 0040882D */   daddu    $s1, $v0, $zero
/* E17DEC 8024206C 0040802D */  daddu     $s0, $v0, $zero
/* E17DF0 80242070 8E020000 */  lw        $v0, ($s0)
/* E17DF4 80242074 30420002 */  andi      $v0, $v0, 2
/* E17DF8 80242078 5440001E */  bnel      $v0, $zero, .L802420F4
/* E17DFC 8024207C 26520001 */   addiu    $s2, $s2, 1
/* E17E00 80242080 AFB60010 */  sw        $s6, 0x10($sp)
/* E17E04 80242084 AFB50014 */  sw        $s5, 0x14($sp)
/* E17E08 80242088 AFB40018 */  sw        $s4, 0x18($sp)
/* E17E0C 8024208C 8E050038 */  lw        $a1, 0x38($s0)
/* E17E10 80242090 8E06003C */  lw        $a2, 0x3c($s0)
/* E17E14 80242094 8E070040 */  lw        $a3, 0x40($s0)
/* E17E18 80242098 0C00B94E */  jal       get_screen_coords
/* E17E1C 8024209C 0000202D */   daddu    $a0, $zero, $zero
/* E17E20 802420A0 8FA20028 */  lw        $v0, 0x28($sp)
/* E17E24 802420A4 2442FFFF */  addiu     $v0, $v0, -1
/* E17E28 802420A8 2C42013F */  sltiu     $v0, $v0, 0x13f
/* E17E2C 802420AC 1040000A */  beqz      $v0, .L802420D8
/* E17E30 802420B0 00000000 */   nop
/* E17E34 802420B4 AFA00010 */  sw        $zero, 0x10($sp)
/* E17E38 802420B8 AFA00014 */  sw        $zero, 0x14($sp)
/* E17E3C 802420BC 8E050038 */  lw        $a1, 0x38($s0)
/* E17E40 802420C0 8E06003C */  lw        $a2, 0x3c($s0)
/* E17E44 802420C4 8E070040 */  lw        $a3, 0x40($s0)
/* E17E48 802420C8 0C01BECC */  jal       fx_walk_normal
/* E17E4C 802420CC 24040001 */   addiu    $a0, $zero, 1
/* E17E50 802420D0 0C05272D */  jal       play_sound
/* E17E54 802420D4 24040283 */   addiu    $a0, $zero, 0x283
.L802420D8:
/* E17E58 802420D8 8E020000 */  lw        $v0, ($s0)
/* E17E5C 802420DC 0200202D */  daddu     $a0, $s0, $zero
/* E17E60 802420E0 34420002 */  ori       $v0, $v0, 2
/* E17E64 802420E4 0C00EAFF */  jal       disable_npc_shadow
/* E17E68 802420E8 AC820000 */   sw       $v0, ($a0)
/* E17E6C 802420EC AE20006C */  sw        $zero, 0x6c($s1)
/* E17E70 802420F0 26520001 */  addiu     $s2, $s2, 1
.L802420F4:
/* E17E74 802420F4 2A420023 */  slti      $v0, $s2, 0x23
/* E17E78 802420F8 1440FFD4 */  bnez      $v0, .L8024204C
/* E17E7C 802420FC 2673001C */   addiu    $s3, $s3, 0x1c
/* E17E80 80242100 0809088F */  j         .L8024223C
/* E17E84 80242104 24020002 */   addiu    $v0, $zero, 2
.L80242108:
/* E17E88 80242108 24160012 */  addiu     $s6, $zero, 0x12
/* E17E8C 8024210C 2415001E */  addiu     $s5, $zero, 0x1e
/* E17E90 80242110 27B30034 */  addiu     $s3, $sp, 0x34
/* E17E94 80242114 24140025 */  addiu     $s4, $zero, 0x25
/* E17E98 80242118 0080882D */  daddu     $s1, $a0, $zero
/* E17E9C 8024211C 4480A000 */  mtc1      $zero, $f20
/* E17EA0 80242120 3C013F80 */  lui       $at, 0x3f80
/* E17EA4 80242124 4481C000 */  mtc1      $at, $f24
/* E17EA8 80242128 3C014000 */  lui       $at, 0x4000
/* E17EAC 8024212C 4481B000 */  mtc1      $at, $f22
.L80242130:
/* E17EB0 80242130 8E240040 */  lw        $a0, 0x40($s1)
/* E17EB4 80242134 2402FFFF */  addiu     $v0, $zero, -1
/* E17EB8 80242138 5082003C */  beql      $a0, $v0, .L8024222C
/* E17EBC 8024213C 2631001C */   addiu    $s1, $s1, 0x1c
/* E17EC0 80242140 0C00FB3A */  jal       get_enemy
/* E17EC4 80242144 00000000 */   nop
/* E17EC8 80242148 0C00EABB */  jal       get_npc_unsafe
/* E17ECC 8024214C 84440008 */   lh       $a0, 8($v0)
/* E17ED0 80242150 0040802D */  daddu     $s0, $v0, $zero
/* E17ED4 80242154 8E020000 */  lw        $v0, ($s0)
/* E17ED8 80242158 30420002 */  andi      $v0, $v0, 2
/* E17EDC 8024215C 54400033 */  bnel      $v0, $zero, .L8024222C
/* E17EE0 80242160 2631001C */   addiu    $s1, $s1, 0x1c
/* E17EE4 80242164 8E230034 */  lw        $v1, 0x34($s1)
/* E17EE8 80242168 10600005 */  beqz      $v1, .L80242180
/* E17EEC 8024216C 24020001 */   addiu    $v0, $zero, 1
/* E17EF0 80242170 10620017 */  beq       $v1, $v0, .L802421D0
/* E17EF4 80242174 00000000 */   nop
/* E17EF8 80242178 0809088B */  j         .L8024222C
/* E17EFC 8024217C 2631001C */   addiu    $s1, $s1, 0x1c
.L80242180:
/* E17F00 80242180 8E22002C */  lw        $v0, 0x2c($s1)
/* E17F04 80242184 10560028 */  beq       $v0, $s6, .L80242228
/* E17F08 80242188 24040002 */   addiu    $a0, $zero, 2
/* E17F0C 8024218C AE36002C */  sw        $s6, 0x2c($s1)
/* E17F10 80242190 860200A8 */  lh        $v0, 0xa8($s0)
/* E17F14 80242194 4406A000 */  mfc1      $a2, $f20
/* E17F18 80242198 44820000 */  mtc1      $v0, $f0
/* E17F1C 8024219C 00000000 */  nop
/* E17F20 802421A0 46800020 */  cvt.s.w   $f0, $f0
/* E17F24 802421A4 44070000 */  mfc1      $a3, $f0
/* E17F28 802421A8 0200282D */  daddu     $a1, $s0, $zero
/* E17F2C 802421AC E7B80010 */  swc1      $f24, 0x10($sp)
/* E17F30 802421B0 E7B60014 */  swc1      $f22, 0x14($sp)
/* E17F34 802421B4 E7B40018 */  swc1      $f20, 0x18($sp)
/* E17F38 802421B8 AFB5001C */  sw        $s5, 0x1c($sp)
/* E17F3C 802421BC 0C01BFA4 */  jal       fx_emote
/* E17F40 802421C0 AFB30020 */   sw       $s3, 0x20($sp)
/* E17F44 802421C4 3C02002B */  lui       $v0, 0x2b
/* E17F48 802421C8 08090887 */  j         .L8024221C
/* E17F4C 802421CC 3442000E */   ori      $v0, $v0, 0xe
.L802421D0:
/* E17F50 802421D0 8E22002C */  lw        $v0, 0x2c($s1)
/* E17F54 802421D4 10540014 */  beq       $v0, $s4, .L80242228
/* E17F58 802421D8 24040002 */   addiu    $a0, $zero, 2
/* E17F5C 802421DC AE34002C */  sw        $s4, 0x2c($s1)
/* E17F60 802421E0 860200A8 */  lh        $v0, 0xa8($s0)
/* E17F64 802421E4 4406A000 */  mfc1      $a2, $f20
/* E17F68 802421E8 44820000 */  mtc1      $v0, $f0
/* E17F6C 802421EC 00000000 */  nop
/* E17F70 802421F0 46800020 */  cvt.s.w   $f0, $f0
/* E17F74 802421F4 44070000 */  mfc1      $a3, $f0
/* E17F78 802421F8 0200282D */  daddu     $a1, $s0, $zero
/* E17F7C 802421FC E7B80010 */  swc1      $f24, 0x10($sp)
/* E17F80 80242200 E7B60014 */  swc1      $f22, 0x14($sp)
/* E17F84 80242204 E7B40018 */  swc1      $f20, 0x18($sp)
/* E17F88 80242208 AFB5001C */  sw        $s5, 0x1c($sp)
/* E17F8C 8024220C 0C01BFA4 */  jal       fx_emote
/* E17F90 80242210 AFB30020 */   sw       $s3, 0x20($sp)
/* E17F94 80242214 3C02002C */  lui       $v0, 0x2c
/* E17F98 80242218 3442001C */  ori       $v0, $v0, 0x1c
.L8024221C:
/* E17F9C 8024221C 0200202D */  daddu     $a0, $s0, $zero
/* E17FA0 80242220 0C00EAE8 */  jal       enable_npc_shadow
/* E17FA4 80242224 AC820028 */   sw       $v0, 0x28($a0)
.L80242228:
/* E17FA8 80242228 2631001C */  addiu     $s1, $s1, 0x1c
.L8024222C:
/* E17FAC 8024222C 26520001 */  addiu     $s2, $s2, 1
/* E17FB0 80242230 2A420023 */  slti      $v0, $s2, 0x23
/* E17FB4 80242234 1440FFBE */  bnez      $v0, .L80242130
/* E17FB8 80242238 0000102D */   daddu    $v0, $zero, $zero
.L8024223C:
/* E17FBC 8024223C 8FBF0058 */  lw        $ra, 0x58($sp)
/* E17FC0 80242240 8FB70054 */  lw        $s7, 0x54($sp)
/* E17FC4 80242244 8FB60050 */  lw        $s6, 0x50($sp)
/* E17FC8 80242248 8FB5004C */  lw        $s5, 0x4c($sp)
/* E17FCC 8024224C 8FB40048 */  lw        $s4, 0x48($sp)
/* E17FD0 80242250 8FB30044 */  lw        $s3, 0x44($sp)
/* E17FD4 80242254 8FB20040 */  lw        $s2, 0x40($sp)
/* E17FD8 80242258 8FB1003C */  lw        $s1, 0x3c($sp)
/* E17FDC 8024225C 8FB00038 */  lw        $s0, 0x38($sp)
/* E17FE0 80242260 D7B80070 */  ldc1      $f24, 0x70($sp)
/* E17FE4 80242264 D7B60068 */  ldc1      $f22, 0x68($sp)
/* E17FE8 80242268 D7B40060 */  ldc1      $f20, 0x60($sp)
/* E17FEC 8024226C 03E00008 */  jr        $ra
/* E17FF0 80242270 27BD0078 */   addiu    $sp, $sp, 0x78
