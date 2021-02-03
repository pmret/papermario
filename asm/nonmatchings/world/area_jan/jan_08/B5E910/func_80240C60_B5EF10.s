.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C60_B5EF10
/* B5EF10 80240C60 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* B5EF14 80240C64 AFB60040 */  sw        $s6, 0x40($sp)
/* B5EF18 80240C68 0080B02D */  daddu     $s6, $a0, $zero
/* B5EF1C 80240C6C AFB00028 */  sw        $s0, 0x28($sp)
/* B5EF20 80240C70 00A0802D */  daddu     $s0, $a1, $zero
/* B5EF24 80240C74 AFBF0044 */  sw        $ra, 0x44($sp)
/* B5EF28 80240C78 AFB5003C */  sw        $s5, 0x3c($sp)
/* B5EF2C 80240C7C AFB40038 */  sw        $s4, 0x38($sp)
/* B5EF30 80240C80 AFB30034 */  sw        $s3, 0x34($sp)
/* B5EF34 80240C84 AFB20030 */  sw        $s2, 0x30($sp)
/* B5EF38 80240C88 AFB1002C */  sw        $s1, 0x2c($sp)
/* B5EF3C 80240C8C F7B80058 */  sdc1      $f24, 0x58($sp)
/* B5EF40 80240C90 F7B60050 */  sdc1      $f22, 0x50($sp)
/* B5EF44 80240C94 F7B40048 */  sdc1      $f20, 0x48($sp)
/* B5EF48 80240C98 8ED3000C */  lw        $s3, 0xc($s6)
/* B5EF4C 80240C9C 0C00EAD2 */  jal       get_npc_safe
/* B5EF50 80240CA0 2404FFFC */   addiu    $a0, $zero, -4
/* B5EF54 80240CA4 27A50018 */  addiu     $a1, $sp, 0x18
/* B5EF58 80240CA8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* B5EF5C 80240CAC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* B5EF60 80240CB0 27A6001C */  addiu     $a2, $sp, 0x1c
/* B5EF64 80240CB4 00041880 */  sll       $v1, $a0, 2
/* B5EF68 80240CB8 00641821 */  addu      $v1, $v1, $a0
/* B5EF6C 80240CBC 00031880 */  sll       $v1, $v1, 2
/* B5EF70 80240CC0 00641823 */  subu      $v1, $v1, $a0
/* B5EF74 80240CC4 000320C0 */  sll       $a0, $v1, 3
/* B5EF78 80240CC8 00641821 */  addu      $v1, $v1, $a0
/* B5EF7C 80240CCC 000318C0 */  sll       $v1, $v1, 3
/* B5EF80 80240CD0 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* B5EF84 80240CD4 00230821 */  addu      $at, $at, $v1
/* B5EF88 80240CD8 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* B5EF8C 80240CDC 0C00A88D */  jal       sin_cos_deg
/* B5EF90 80240CE0 0040A82D */   daddu    $s5, $v0, $zero
/* B5EF94 80240CE4 1200005D */  beqz      $s0, .L80240E5C
/* B5EF98 80240CE8 00000000 */   nop
/* B5EF9C 80240CEC 0C00AB0A */  jal       general_heap_malloc
/* B5EFA0 80240CF0 24040068 */   addiu    $a0, $zero, 0x68
/* B5EFA4 80240CF4 0040902D */  daddu     $s2, $v0, $zero
/* B5EFA8 80240CF8 02C0202D */  daddu     $a0, $s6, $zero
/* B5EFAC 80240CFC 0000882D */  daddu     $s1, $zero, $zero
/* B5EFB0 80240D00 2414FFFF */  addiu     $s4, $zero, -1
/* B5EFB4 80240D04 AED20060 */  sw        $s2, 0x60($s6)
/* B5EFB8 80240D08 8E650000 */  lw        $a1, ($s3)
/* B5EFBC 80240D0C 3C014148 */  lui       $at, 0x4148
/* B5EFC0 80240D10 4481C000 */  mtc1      $at, $f24
/* B5EFC4 80240D14 3C013F80 */  lui       $at, 0x3f80
/* B5EFC8 80240D18 4481B000 */  mtc1      $at, $f22
/* B5EFCC 80240D1C 4480A000 */  mtc1      $zero, $f20
/* B5EFD0 80240D20 0C0B1EAF */  jal       get_variable
/* B5EFD4 80240D24 0240802D */   daddu    $s0, $s2, $zero
/* B5EFD8 80240D28 0C04417A */  jal       get_entity_by_index
/* B5EFDC 80240D2C 0040202D */   daddu    $a0, $v0, $zero
/* B5EFE0 80240D30 AE42005C */  sw        $v0, 0x5c($s2)
.L80240D34:
/* B5EFE4 80240D34 8E42005C */  lw        $v0, 0x5c($s2)
/* B5EFE8 80240D38 C440004C */  lwc1      $f0, 0x4c($v0)
/* B5EFEC 80240D3C 0000202D */  daddu     $a0, $zero, $zero
/* B5EFF0 80240D40 E7B60010 */  swc1      $f22, 0x10($sp)
/* B5EFF4 80240D44 AFB40014 */  sw        $s4, 0x14($sp)
/* B5EFF8 80240D48 46180000 */  add.s     $f0, $f0, $f24
/* B5EFFC 80240D4C 8C450048 */  lw        $a1, 0x48($v0)
/* B5F000 80240D50 8C470050 */  lw        $a3, 0x50($v0)
/* B5F004 80240D54 44060000 */  mfc1      $a2, $f0
/* B5F008 80240D58 0C01C5BC */  jal       func_800716F0
/* B5F00C 80240D5C 26310001 */   addiu    $s1, $s1, 1
/* B5F010 80240D60 AE020008 */  sw        $v0, 8($s0)
/* B5F014 80240D64 E614002C */  swc1      $f20, 0x2c($s0)
/* B5F018 80240D68 E6140020 */  swc1      $f20, 0x20($s0)
/* B5F01C 80240D6C E6140014 */  swc1      $f20, 0x14($s0)
/* B5F020 80240D70 E6140050 */  swc1      $f20, 0x50($s0)
/* B5F024 80240D74 E6140044 */  swc1      $f20, 0x44($s0)
/* B5F028 80240D78 E6140038 */  swc1      $f20, 0x38($s0)
/* B5F02C 80240D7C 2A220003 */  slti      $v0, $s1, 3
/* B5F030 80240D80 1440FFEC */  bnez      $v0, .L80240D34
/* B5F034 80240D84 26100004 */   addiu    $s0, $s0, 4
/* B5F038 80240D88 0000882D */  daddu     $s1, $zero, $zero
/* B5F03C 80240D8C 0240802D */  daddu     $s0, $s2, $zero
/* B5F040 80240D90 3C148024 */  lui       $s4, %hi(D_80243E58_B62108)
/* B5F044 80240D94 26943E58 */  addiu     $s4, $s4, %lo(D_80243E58_B62108)
/* B5F048 80240D98 3C014248 */  lui       $at, 0x4248
/* B5F04C 80240D9C 4481A000 */  mtc1      $at, $f20
/* B5F050 80240DA0 24130044 */  addiu     $s3, $zero, 0x44
/* B5F054 80240DA4 AE400000 */  sw        $zero, ($s2)
/* B5F058 80240DA8 AE400004 */  sw        $zero, 4($s2)
/* B5F05C 80240DAC AE400060 */  sw        $zero, 0x60($s2)
/* B5F060 80240DB0 AE400064 */  sw        $zero, 0x64($s2)
.L80240DB4:
/* B5F064 80240DB4 27A40020 */  addiu     $a0, $sp, 0x20
/* B5F068 80240DB8 4406A000 */  mfc1      $a2, $f20
/* B5F06C 80240DBC 8E870000 */  lw        $a3, ($s4)
/* B5F070 80240DC0 02532821 */  addu      $a1, $s2, $s3
/* B5F074 80240DC4 0C00A7E7 */  jal       add_vec2D_polar
/* B5F078 80240DC8 AFA00020 */   sw       $zero, 0x20($sp)
/* B5F07C 80240DCC C7A2001C */  lwc1      $f2, 0x1c($sp)
/* B5F080 80240DD0 C7A40020 */  lwc1      $f4, 0x20($sp)
/* B5F084 80240DD4 46041082 */  mul.s     $f2, $f2, $f4
/* B5F088 80240DD8 00000000 */  nop
/* B5F08C 80240DDC C7A00018 */  lwc1      $f0, 0x18($sp)
/* B5F090 80240DE0 46040002 */  mul.s     $f0, $f0, $f4
/* B5F094 80240DE4 00000000 */  nop
/* B5F098 80240DE8 E6020038 */  swc1      $f2, 0x38($s0)
/* B5F09C 80240DEC E6000050 */  swc1      $f0, 0x50($s0)
/* B5F0A0 80240DF0 8E42005C */  lw        $v0, 0x5c($s2)
/* B5F0A4 80240DF4 C6000038 */  lwc1      $f0, 0x38($s0)
/* B5F0A8 80240DF8 C4420048 */  lwc1      $f2, 0x48($v0)
/* B5F0AC 80240DFC 46001080 */  add.s     $f2, $f2, $f0
/* B5F0B0 80240E00 C6A00038 */  lwc1      $f0, 0x38($s5)
/* B5F0B4 80240E04 46020001 */  sub.s     $f0, $f0, $f2
/* B5F0B8 80240E08 E6000038 */  swc1      $f0, 0x38($s0)
/* B5F0BC 80240E0C 8E42005C */  lw        $v0, 0x5c($s2)
/* B5F0C0 80240E10 C6000044 */  lwc1      $f0, 0x44($s0)
/* B5F0C4 80240E14 C442004C */  lwc1      $f2, 0x4c($v0)
/* B5F0C8 80240E18 46001080 */  add.s     $f2, $f2, $f0
/* B5F0CC 80240E1C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* B5F0D0 80240E20 46020001 */  sub.s     $f0, $f0, $f2
/* B5F0D4 80240E24 E6000044 */  swc1      $f0, 0x44($s0)
/* B5F0D8 80240E28 8E42005C */  lw        $v0, 0x5c($s2)
/* B5F0DC 80240E2C C6000050 */  lwc1      $f0, 0x50($s0)
/* B5F0E0 80240E30 C4420050 */  lwc1      $f2, 0x50($v0)
/* B5F0E4 80240E34 26940004 */  addiu     $s4, $s4, 4
/* B5F0E8 80240E38 46001080 */  add.s     $f2, $f2, $f0
/* B5F0EC 80240E3C C6A00040 */  lwc1      $f0, 0x40($s5)
/* B5F0F0 80240E40 26730004 */  addiu     $s3, $s3, 4
/* B5F0F4 80240E44 46020001 */  sub.s     $f0, $f0, $f2
/* B5F0F8 80240E48 26310001 */  addiu     $s1, $s1, 1
/* B5F0FC 80240E4C 2A220003 */  slti      $v0, $s1, 3
/* B5F100 80240E50 E6000050 */  swc1      $f0, 0x50($s0)
/* B5F104 80240E54 1440FFD7 */  bnez      $v0, .L80240DB4
/* B5F108 80240E58 26100004 */   addiu    $s0, $s0, 4
.L80240E5C:
/* B5F10C 80240E5C 8ED20060 */  lw        $s2, 0x60($s6)
/* B5F110 80240E60 8E430000 */  lw        $v1, ($s2)
/* B5F114 80240E64 24020001 */  addiu     $v0, $zero, 1
/* B5F118 80240E68 10620038 */  beq       $v1, $v0, .L80240F4C
/* B5F11C 80240E6C 28620002 */   slti     $v0, $v1, 2
/* B5F120 80240E70 50400005 */  beql      $v0, $zero, .L80240E88
/* B5F124 80240E74 24020002 */   addiu    $v0, $zero, 2
/* B5F128 80240E78 10600007 */  beqz      $v1, .L80240E98
/* B5F12C 80240E7C 24040005 */   addiu    $a0, $zero, 5
/* B5F130 80240E80 0809040C */  j         .L80241030
/* B5F134 80240E84 00000000 */   nop
.L80240E88:
/* B5F138 80240E88 10620058 */  beq       $v1, $v0, .L80240FEC
/* B5F13C 80240E8C 00000000 */   nop
/* B5F140 80240E90 0809040C */  j         .L80241030
/* B5F144 80240E94 00000000 */   nop
.L80240E98:
/* B5F148 80240E98 0000882D */  daddu     $s1, $zero, $zero
/* B5F14C 80240E9C 3C148024 */  lui       $s4, %hi(D_80243E58_B62108)
/* B5F150 80240EA0 26943E58 */  addiu     $s4, $s4, %lo(D_80243E58_B62108)
/* B5F154 80240EA4 24130020 */  addiu     $s3, $zero, 0x20
/* B5F158 80240EA8 3C064248 */  lui       $a2, 0x4248
/* B5F15C 80240EAC 44800000 */  mtc1      $zero, $f0
/* B5F160 80240EB0 24020014 */  addiu     $v0, $zero, 0x14
/* B5F164 80240EB4 AFA20010 */  sw        $v0, 0x10($sp)
/* B5F168 80240EB8 44050000 */  mfc1      $a1, $f0
/* B5F16C 80240EBC 8E470060 */  lw        $a3, 0x60($s2)
/* B5F170 80240EC0 4485B000 */  mtc1      $a1, $f22
/* B5F174 80240EC4 0C00A8ED */  jal       update_lerp
/* B5F178 80240EC8 0240802D */   daddu    $s0, $s2, $zero
/* B5F17C 80240ECC 46000506 */  mov.s     $f20, $f0
.L80240ED0:
/* B5F180 80240ED0 4406A000 */  mfc1      $a2, $f20
/* B5F184 80240ED4 27A40020 */  addiu     $a0, $sp, 0x20
/* B5F188 80240ED8 E6160020 */  swc1      $f22, 0x20($s0)
/* B5F18C 80240EDC 8E870000 */  lw        $a3, ($s4)
/* B5F190 80240EE0 02532821 */  addu      $a1, $s2, $s3
/* B5F194 80240EE4 0C00A7E7 */  jal       add_vec2D_polar
/* B5F198 80240EE8 E7B60020 */   swc1     $f22, 0x20($sp)
/* B5F19C 80240EEC C7A4001C */  lwc1      $f4, 0x1c($sp)
/* B5F1A0 80240EF0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* B5F1A4 80240EF4 46002102 */  mul.s     $f4, $f4, $f0
/* B5F1A8 80240EF8 00000000 */  nop
/* B5F1AC 80240EFC C7A20018 */  lwc1      $f2, 0x18($sp)
/* B5F1B0 80240F00 26940004 */  addiu     $s4, $s4, 4
/* B5F1B4 80240F04 46001082 */  mul.s     $f2, $f2, $f0
/* B5F1B8 80240F08 00000000 */  nop
/* B5F1BC 80240F0C 26730004 */  addiu     $s3, $s3, 4
/* B5F1C0 80240F10 26310001 */  addiu     $s1, $s1, 1
/* B5F1C4 80240F14 2A220003 */  slti      $v0, $s1, 3
/* B5F1C8 80240F18 E6040014 */  swc1      $f4, 0x14($s0)
/* B5F1CC 80240F1C E602002C */  swc1      $f2, 0x2c($s0)
/* B5F1D0 80240F20 1440FFEB */  bnez      $v0, .L80240ED0
/* B5F1D4 80240F24 26100004 */   addiu    $s0, $s0, 4
/* B5F1D8 80240F28 8E420060 */  lw        $v0, 0x60($s2)
/* B5F1DC 80240F2C 24420001 */  addiu     $v0, $v0, 1
/* B5F1E0 80240F30 AE420060 */  sw        $v0, 0x60($s2)
/* B5F1E4 80240F34 28420015 */  slti      $v0, $v0, 0x15
/* B5F1E8 80240F38 1440003D */  bnez      $v0, .L80241030
/* B5F1EC 80240F3C 24020001 */   addiu    $v0, $zero, 1
/* B5F1F0 80240F40 AE420000 */  sw        $v0, ($s2)
/* B5F1F4 80240F44 0809040C */  j         .L80241030
/* B5F1F8 80240F48 AE400060 */   sw       $zero, 0x60($s2)
.L80240F4C:
/* B5F1FC 80240F4C 0000882D */  daddu     $s1, $zero, $zero
/* B5F200 80240F50 3C148024 */  lui       $s4, %hi(D_80243E58_B62108)
/* B5F204 80240F54 26943E58 */  addiu     $s4, $s4, %lo(D_80243E58_B62108)
/* B5F208 80240F58 24130020 */  addiu     $s3, $zero, 0x20
/* B5F20C 80240F5C 0240802D */  daddu     $s0, $s2, $zero
/* B5F210 80240F60 3C014248 */  lui       $at, 0x4248
/* B5F214 80240F64 4481A000 */  mtc1      $at, $f20
/* B5F218 80240F68 4480B000 */  mtc1      $zero, $f22
.L80240F6C:
/* B5F21C 80240F6C 4406A000 */  mfc1      $a2, $f20
/* B5F220 80240F70 27A40020 */  addiu     $a0, $sp, 0x20
/* B5F224 80240F74 E6160020 */  swc1      $f22, 0x20($s0)
/* B5F228 80240F78 8E870000 */  lw        $a3, ($s4)
/* B5F22C 80240F7C 02532821 */  addu      $a1, $s2, $s3
/* B5F230 80240F80 0C00A7E7 */  jal       add_vec2D_polar
/* B5F234 80240F84 E7B60020 */   swc1     $f22, 0x20($sp)
/* B5F238 80240F88 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* B5F23C 80240F8C C7A00020 */  lwc1      $f0, 0x20($sp)
/* B5F240 80240F90 46002102 */  mul.s     $f4, $f4, $f0
/* B5F244 80240F94 00000000 */  nop
/* B5F248 80240F98 C7A20018 */  lwc1      $f2, 0x18($sp)
/* B5F24C 80240F9C 26940004 */  addiu     $s4, $s4, 4
/* B5F250 80240FA0 46001082 */  mul.s     $f2, $f2, $f0
/* B5F254 80240FA4 00000000 */  nop
/* B5F258 80240FA8 26730004 */  addiu     $s3, $s3, 4
/* B5F25C 80240FAC 26310001 */  addiu     $s1, $s1, 1
/* B5F260 80240FB0 2A220003 */  slti      $v0, $s1, 3
/* B5F264 80240FB4 E6040014 */  swc1      $f4, 0x14($s0)
/* B5F268 80240FB8 E602002C */  swc1      $f2, 0x2c($s0)
/* B5F26C 80240FBC 1440FFEB */  bnez      $v0, .L80240F6C
/* B5F270 80240FC0 26100004 */   addiu    $s0, $s0, 4
/* B5F274 80240FC4 8E420060 */  lw        $v0, 0x60($s2)
/* B5F278 80240FC8 24420001 */  addiu     $v0, $v0, 1
/* B5F27C 80240FCC AE420060 */  sw        $v0, 0x60($s2)
/* B5F280 80240FD0 28420010 */  slti      $v0, $v0, 0x10
/* B5F284 80240FD4 14400016 */  bnez      $v0, .L80241030
/* B5F288 80240FD8 2402000F */   addiu    $v0, $zero, 0xf
/* B5F28C 80240FDC AE420060 */  sw        $v0, 0x60($s2)
/* B5F290 80240FE0 24020002 */  addiu     $v0, $zero, 2
/* B5F294 80240FE4 0809040C */  j         .L80241030
/* B5F298 80240FE8 AE420000 */   sw       $v0, ($s2)
.L80240FEC:
/* B5F29C 80240FEC 8E420060 */  lw        $v0, 0x60($s2)
/* B5F2A0 80240FF0 24420001 */  addiu     $v0, $v0, 1
/* B5F2A4 80240FF4 AE420060 */  sw        $v0, 0x60($s2)
/* B5F2A8 80240FF8 2842001F */  slti      $v0, $v0, 0x1f
/* B5F2AC 80240FFC 1440000C */  bnez      $v0, .L80241030
/* B5F2B0 80241000 0000882D */   daddu    $s1, $zero, $zero
/* B5F2B4 80241004 0240282D */  daddu     $a1, $s2, $zero
.L80241008:
/* B5F2B8 80241008 8CA20008 */  lw        $v0, 8($a1)
/* B5F2BC 8024100C 8C430000 */  lw        $v1, ($v0)
/* B5F2C0 80241010 26310001 */  addiu     $s1, $s1, 1
/* B5F2C4 80241014 34630010 */  ori       $v1, $v1, 0x10
/* B5F2C8 80241018 AC430000 */  sw        $v1, ($v0)
/* B5F2CC 8024101C 2A220003 */  slti      $v0, $s1, 3
/* B5F2D0 80241020 1440FFF9 */  bnez      $v0, .L80241008
/* B5F2D4 80241024 24A50004 */   addiu    $a1, $a1, 4
/* B5F2D8 80241028 08090459 */  j         .L80241164
/* B5F2DC 8024102C 24020002 */   addiu    $v0, $zero, 2
.L80241030:
/* B5F2E0 80241030 8E430004 */  lw        $v1, 4($s2)
/* B5F2E4 80241034 10600005 */  beqz      $v1, .L8024104C
/* B5F2E8 80241038 24020001 */   addiu    $v0, $zero, 1
/* B5F2EC 8024103C 1062000B */  beq       $v1, $v0, .L8024106C
/* B5F2F0 80241040 0000882D */   daddu    $s1, $zero, $zero
/* B5F2F4 80241044 08090448 */  j         .L80241120
/* B5F2F8 80241048 0240282D */   daddu    $a1, $s2, $zero
.L8024104C:
/* B5F2FC 8024104C 8E420064 */  lw        $v0, 0x64($s2)
/* B5F300 80241050 24420001 */  addiu     $v0, $v0, 1
/* B5F304 80241054 AE420064 */  sw        $v0, 0x64($s2)
/* B5F308 80241058 28420010 */  slti      $v0, $v0, 0x10
/* B5F30C 8024105C 1440002F */  bnez      $v0, .L8024111C
/* B5F310 80241060 0000882D */   daddu    $s1, $zero, $zero
/* B5F314 80241064 08090444 */  j         .L80241110
/* B5F318 80241068 24020001 */   addiu    $v0, $zero, 1
.L8024106C:
/* B5F31C 8024106C 4480A000 */  mtc1      $zero, $f20
/* B5F320 80241070 24130014 */  addiu     $s3, $zero, 0x14
/* B5F324 80241074 0240802D */  daddu     $s0, $s2, $zero
.L80241078:
/* B5F328 80241078 4405A000 */  mfc1      $a1, $f20
/* B5F32C 8024107C AFB30010 */  sw        $s3, 0x10($sp)
/* B5F330 80241080 8E060038 */  lw        $a2, 0x38($s0)
/* B5F334 80241084 8E470064 */  lw        $a3, 0x64($s2)
/* B5F338 80241088 0C00A8ED */  jal       update_lerp
/* B5F33C 8024108C 24040001 */   addiu    $a0, $zero, 1
/* B5F340 80241090 C6020014 */  lwc1      $f2, 0x14($s0)
/* B5F344 80241094 46001080 */  add.s     $f2, $f2, $f0
/* B5F348 80241098 4405A000 */  mfc1      $a1, $f20
/* B5F34C 8024109C E6020014 */  swc1      $f2, 0x14($s0)
/* B5F350 802410A0 AFB30010 */  sw        $s3, 0x10($sp)
/* B5F354 802410A4 8E060044 */  lw        $a2, 0x44($s0)
/* B5F358 802410A8 8E470064 */  lw        $a3, 0x64($s2)
/* B5F35C 802410AC 0C00A8ED */  jal       update_lerp
/* B5F360 802410B0 24040001 */   addiu    $a0, $zero, 1
/* B5F364 802410B4 C6020020 */  lwc1      $f2, 0x20($s0)
/* B5F368 802410B8 46001080 */  add.s     $f2, $f2, $f0
/* B5F36C 802410BC 4405A000 */  mfc1      $a1, $f20
/* B5F370 802410C0 E6020020 */  swc1      $f2, 0x20($s0)
/* B5F374 802410C4 AFB30010 */  sw        $s3, 0x10($sp)
/* B5F378 802410C8 8E060050 */  lw        $a2, 0x50($s0)
/* B5F37C 802410CC 8E470064 */  lw        $a3, 0x64($s2)
/* B5F380 802410D0 0C00A8ED */  jal       update_lerp
/* B5F384 802410D4 24040001 */   addiu    $a0, $zero, 1
/* B5F388 802410D8 C602002C */  lwc1      $f2, 0x2c($s0)
/* B5F38C 802410DC 46001080 */  add.s     $f2, $f2, $f0
/* B5F390 802410E0 26310001 */  addiu     $s1, $s1, 1
/* B5F394 802410E4 2A220003 */  slti      $v0, $s1, 3
/* B5F398 802410E8 E602002C */  swc1      $f2, 0x2c($s0)
/* B5F39C 802410EC 1440FFE2 */  bnez      $v0, .L80241078
/* B5F3A0 802410F0 26100004 */   addiu    $s0, $s0, 4
/* B5F3A4 802410F4 8E420064 */  lw        $v0, 0x64($s2)
/* B5F3A8 802410F8 24420001 */  addiu     $v0, $v0, 1
/* B5F3AC 802410FC AE420064 */  sw        $v0, 0x64($s2)
/* B5F3B0 80241100 28420015 */  slti      $v0, $v0, 0x15
/* B5F3B4 80241104 14400005 */  bnez      $v0, .L8024111C
/* B5F3B8 80241108 0000882D */   daddu    $s1, $zero, $zero
/* B5F3BC 8024110C 24020002 */  addiu     $v0, $zero, 2
.L80241110:
/* B5F3C0 80241110 AE420004 */  sw        $v0, 4($s2)
/* B5F3C4 80241114 AE400064 */  sw        $zero, 0x64($s2)
/* B5F3C8 80241118 0000882D */  daddu     $s1, $zero, $zero
.L8024111C:
/* B5F3CC 8024111C 0240282D */  daddu     $a1, $s2, $zero
.L80241120:
/* B5F3D0 80241120 8CA20008 */  lw        $v0, 8($a1)
/* B5F3D4 80241124 C4A00014 */  lwc1      $f0, 0x14($a1)
/* B5F3D8 80241128 8C42000C */  lw        $v0, 0xc($v0)
/* B5F3DC 8024112C E4400010 */  swc1      $f0, 0x10($v0)
/* B5F3E0 80241130 8CA20008 */  lw        $v0, 8($a1)
/* B5F3E4 80241134 C4A00020 */  lwc1      $f0, 0x20($a1)
/* B5F3E8 80241138 8C42000C */  lw        $v0, 0xc($v0)
/* B5F3EC 8024113C 26310001 */  addiu     $s1, $s1, 1
/* B5F3F0 80241140 E4400014 */  swc1      $f0, 0x14($v0)
/* B5F3F4 80241144 8CA20008 */  lw        $v0, 8($a1)
/* B5F3F8 80241148 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* B5F3FC 8024114C 8C42000C */  lw        $v0, 0xc($v0)
/* B5F400 80241150 E4400018 */  swc1      $f0, 0x18($v0)
/* B5F404 80241154 2A220003 */  slti      $v0, $s1, 3
/* B5F408 80241158 1440FFF1 */  bnez      $v0, .L80241120
/* B5F40C 8024115C 24A50004 */   addiu    $a1, $a1, 4
/* B5F410 80241160 0000102D */  daddu     $v0, $zero, $zero
.L80241164:
/* B5F414 80241164 8FBF0044 */  lw        $ra, 0x44($sp)
/* B5F418 80241168 8FB60040 */  lw        $s6, 0x40($sp)
/* B5F41C 8024116C 8FB5003C */  lw        $s5, 0x3c($sp)
/* B5F420 80241170 8FB40038 */  lw        $s4, 0x38($sp)
/* B5F424 80241174 8FB30034 */  lw        $s3, 0x34($sp)
/* B5F428 80241178 8FB20030 */  lw        $s2, 0x30($sp)
/* B5F42C 8024117C 8FB1002C */  lw        $s1, 0x2c($sp)
/* B5F430 80241180 8FB00028 */  lw        $s0, 0x28($sp)
/* B5F434 80241184 D7B80058 */  ldc1      $f24, 0x58($sp)
/* B5F438 80241188 D7B60050 */  ldc1      $f22, 0x50($sp)
/* B5F43C 8024118C D7B40048 */  ldc1      $f20, 0x48($sp)
/* B5F440 80241190 03E00008 */  jr        $ra
/* B5F444 80241194 27BD0060 */   addiu    $sp, $sp, 0x60
