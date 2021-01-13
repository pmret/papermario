.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240910_C68A40
/* C68A40 80240910 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* C68A44 80240914 AFB60040 */  sw        $s6, 0x40($sp)
/* C68A48 80240918 0080B02D */  daddu     $s6, $a0, $zero
/* C68A4C 8024091C AFB00028 */  sw        $s0, 0x28($sp)
/* C68A50 80240920 00A0802D */  daddu     $s0, $a1, $zero
/* C68A54 80240924 AFBF0044 */  sw        $ra, 0x44($sp)
/* C68A58 80240928 AFB5003C */  sw        $s5, 0x3c($sp)
/* C68A5C 8024092C AFB40038 */  sw        $s4, 0x38($sp)
/* C68A60 80240930 AFB30034 */  sw        $s3, 0x34($sp)
/* C68A64 80240934 AFB20030 */  sw        $s2, 0x30($sp)
/* C68A68 80240938 AFB1002C */  sw        $s1, 0x2c($sp)
/* C68A6C 8024093C F7B80058 */  sdc1      $f24, 0x58($sp)
/* C68A70 80240940 F7B60050 */  sdc1      $f22, 0x50($sp)
/* C68A74 80240944 F7B40048 */  sdc1      $f20, 0x48($sp)
/* C68A78 80240948 8ED3000C */  lw        $s3, 0xc($s6)
/* C68A7C 8024094C 0C00EAD2 */  jal       get_npc_safe
/* C68A80 80240950 2404FFFC */   addiu    $a0, $zero, -4
/* C68A84 80240954 27A50018 */  addiu     $a1, $sp, 0x18
/* C68A88 80240958 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C68A8C 8024095C 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C68A90 80240960 27A6001C */  addiu     $a2, $sp, 0x1c
/* C68A94 80240964 00041880 */  sll       $v1, $a0, 2
/* C68A98 80240968 00641821 */  addu      $v1, $v1, $a0
/* C68A9C 8024096C 00031880 */  sll       $v1, $v1, 2
/* C68AA0 80240970 00641823 */  subu      $v1, $v1, $a0
/* C68AA4 80240974 000320C0 */  sll       $a0, $v1, 3
/* C68AA8 80240978 00641821 */  addu      $v1, $v1, $a0
/* C68AAC 8024097C 000318C0 */  sll       $v1, $v1, 3
/* C68AB0 80240980 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* C68AB4 80240984 00230821 */  addu      $at, $at, $v1
/* C68AB8 80240988 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* C68ABC 8024098C 0C00A88D */  jal       sin_cos_deg
/* C68AC0 80240990 0040A82D */   daddu    $s5, $v0, $zero
/* C68AC4 80240994 1200005D */  beqz      $s0, .L80240B0C
/* C68AC8 80240998 00000000 */   nop
/* C68ACC 8024099C 0C00AB0A */  jal       general_heap_malloc
/* C68AD0 802409A0 24040068 */   addiu    $a0, $zero, 0x68
/* C68AD4 802409A4 0040902D */  daddu     $s2, $v0, $zero
/* C68AD8 802409A8 02C0202D */  daddu     $a0, $s6, $zero
/* C68ADC 802409AC 0000882D */  daddu     $s1, $zero, $zero
/* C68AE0 802409B0 2414FFFF */  addiu     $s4, $zero, -1
/* C68AE4 802409B4 AED20060 */  sw        $s2, 0x60($s6)
/* C68AE8 802409B8 8E650000 */  lw        $a1, ($s3)
/* C68AEC 802409BC 3C014148 */  lui       $at, 0x4148
/* C68AF0 802409C0 4481C000 */  mtc1      $at, $f24
/* C68AF4 802409C4 3C013F80 */  lui       $at, 0x3f80
/* C68AF8 802409C8 4481B000 */  mtc1      $at, $f22
/* C68AFC 802409CC 4480A000 */  mtc1      $zero, $f20
/* C68B00 802409D0 0C0B1EAF */  jal       get_variable
/* C68B04 802409D4 0240802D */   daddu    $s0, $s2, $zero
/* C68B08 802409D8 0C04417A */  jal       get_entity_by_index
/* C68B0C 802409DC 0040202D */   daddu    $a0, $v0, $zero
/* C68B10 802409E0 AE42005C */  sw        $v0, 0x5c($s2)
.L802409E4:
/* C68B14 802409E4 8E42005C */  lw        $v0, 0x5c($s2)
/* C68B18 802409E8 C440004C */  lwc1      $f0, 0x4c($v0)
/* C68B1C 802409EC 0000202D */  daddu     $a0, $zero, $zero
/* C68B20 802409F0 E7B60010 */  swc1      $f22, 0x10($sp)
/* C68B24 802409F4 AFB40014 */  sw        $s4, 0x14($sp)
/* C68B28 802409F8 46180000 */  add.s     $f0, $f0, $f24
/* C68B2C 802409FC 8C450048 */  lw        $a1, 0x48($v0)
/* C68B30 80240A00 8C470050 */  lw        $a3, 0x50($v0)
/* C68B34 80240A04 44060000 */  mfc1      $a2, $f0
/* C68B38 80240A08 0C01C5BC */  jal       func_800716F0
/* C68B3C 80240A0C 26310001 */   addiu    $s1, $s1, 1
/* C68B40 80240A10 AE020008 */  sw        $v0, 8($s0)
/* C68B44 80240A14 E614002C */  swc1      $f20, 0x2c($s0)
/* C68B48 80240A18 E6140020 */  swc1      $f20, 0x20($s0)
/* C68B4C 80240A1C E6140014 */  swc1      $f20, 0x14($s0)
/* C68B50 80240A20 E6140050 */  swc1      $f20, 0x50($s0)
/* C68B54 80240A24 E6140044 */  swc1      $f20, 0x44($s0)
/* C68B58 80240A28 E6140038 */  swc1      $f20, 0x38($s0)
/* C68B5C 80240A2C 2A220003 */  slti      $v0, $s1, 3
/* C68B60 80240A30 1440FFEC */  bnez      $v0, .L802409E4
/* C68B64 80240A34 26100004 */   addiu    $s0, $s0, 4
/* C68B68 80240A38 0000882D */  daddu     $s1, $zero, $zero
/* C68B6C 80240A3C 0240802D */  daddu     $s0, $s2, $zero
/* C68B70 80240A40 3C148024 */  lui       $s4, %hi(D_80241C98)
/* C68B74 80240A44 26941C98 */  addiu     $s4, $s4, %lo(D_80241C98)
/* C68B78 80240A48 3C014248 */  lui       $at, 0x4248
/* C68B7C 80240A4C 4481A000 */  mtc1      $at, $f20
/* C68B80 80240A50 24130044 */  addiu     $s3, $zero, 0x44
/* C68B84 80240A54 AE400000 */  sw        $zero, ($s2)
/* C68B88 80240A58 AE400004 */  sw        $zero, 4($s2)
/* C68B8C 80240A5C AE400060 */  sw        $zero, 0x60($s2)
/* C68B90 80240A60 AE400064 */  sw        $zero, 0x64($s2)
.L80240A64:
/* C68B94 80240A64 27A40020 */  addiu     $a0, $sp, 0x20
/* C68B98 80240A68 4406A000 */  mfc1      $a2, $f20
/* C68B9C 80240A6C 8E870000 */  lw        $a3, ($s4)
/* C68BA0 80240A70 02532821 */  addu      $a1, $s2, $s3
/* C68BA4 80240A74 0C00A7E7 */  jal       add_vec2D_polar
/* C68BA8 80240A78 AFA00020 */   sw       $zero, 0x20($sp)
/* C68BAC 80240A7C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* C68BB0 80240A80 C7A40020 */  lwc1      $f4, 0x20($sp)
/* C68BB4 80240A84 46041082 */  mul.s     $f2, $f2, $f4
/* C68BB8 80240A88 00000000 */  nop
/* C68BBC 80240A8C C7A00018 */  lwc1      $f0, 0x18($sp)
/* C68BC0 80240A90 46040002 */  mul.s     $f0, $f0, $f4
/* C68BC4 80240A94 00000000 */  nop
/* C68BC8 80240A98 E6020038 */  swc1      $f2, 0x38($s0)
/* C68BCC 80240A9C E6000050 */  swc1      $f0, 0x50($s0)
/* C68BD0 80240AA0 8E42005C */  lw        $v0, 0x5c($s2)
/* C68BD4 80240AA4 C6000038 */  lwc1      $f0, 0x38($s0)
/* C68BD8 80240AA8 C4420048 */  lwc1      $f2, 0x48($v0)
/* C68BDC 80240AAC 46001080 */  add.s     $f2, $f2, $f0
/* C68BE0 80240AB0 C6A00038 */  lwc1      $f0, 0x38($s5)
/* C68BE4 80240AB4 46020001 */  sub.s     $f0, $f0, $f2
/* C68BE8 80240AB8 E6000038 */  swc1      $f0, 0x38($s0)
/* C68BEC 80240ABC 8E42005C */  lw        $v0, 0x5c($s2)
/* C68BF0 80240AC0 C6000044 */  lwc1      $f0, 0x44($s0)
/* C68BF4 80240AC4 C442004C */  lwc1      $f2, 0x4c($v0)
/* C68BF8 80240AC8 46001080 */  add.s     $f2, $f2, $f0
/* C68BFC 80240ACC C6A0003C */  lwc1      $f0, 0x3c($s5)
/* C68C00 80240AD0 46020001 */  sub.s     $f0, $f0, $f2
/* C68C04 80240AD4 E6000044 */  swc1      $f0, 0x44($s0)
/* C68C08 80240AD8 8E42005C */  lw        $v0, 0x5c($s2)
/* C68C0C 80240ADC C6000050 */  lwc1      $f0, 0x50($s0)
/* C68C10 80240AE0 C4420050 */  lwc1      $f2, 0x50($v0)
/* C68C14 80240AE4 26940004 */  addiu     $s4, $s4, 4
/* C68C18 80240AE8 46001080 */  add.s     $f2, $f2, $f0
/* C68C1C 80240AEC C6A00040 */  lwc1      $f0, 0x40($s5)
/* C68C20 80240AF0 26730004 */  addiu     $s3, $s3, 4
/* C68C24 80240AF4 46020001 */  sub.s     $f0, $f0, $f2
/* C68C28 80240AF8 26310001 */  addiu     $s1, $s1, 1
/* C68C2C 80240AFC 2A220003 */  slti      $v0, $s1, 3
/* C68C30 80240B00 E6000050 */  swc1      $f0, 0x50($s0)
/* C68C34 80240B04 1440FFD7 */  bnez      $v0, .L80240A64
/* C68C38 80240B08 26100004 */   addiu    $s0, $s0, 4
.L80240B0C:
/* C68C3C 80240B0C 8ED20060 */  lw        $s2, 0x60($s6)
/* C68C40 80240B10 8E430000 */  lw        $v1, ($s2)
/* C68C44 80240B14 24020001 */  addiu     $v0, $zero, 1
/* C68C48 80240B18 10620038 */  beq       $v1, $v0, .L80240BFC
/* C68C4C 80240B1C 28620002 */   slti     $v0, $v1, 2
/* C68C50 80240B20 50400005 */  beql      $v0, $zero, .L80240B38
/* C68C54 80240B24 24020002 */   addiu    $v0, $zero, 2
/* C68C58 80240B28 10600007 */  beqz      $v1, .L80240B48
/* C68C5C 80240B2C 24040005 */   addiu    $a0, $zero, 5
/* C68C60 80240B30 08090338 */  j         .L80240CE0
/* C68C64 80240B34 00000000 */   nop
.L80240B38:
/* C68C68 80240B38 10620058 */  beq       $v1, $v0, .L80240C9C
/* C68C6C 80240B3C 00000000 */   nop
/* C68C70 80240B40 08090338 */  j         .L80240CE0
/* C68C74 80240B44 00000000 */   nop
.L80240B48:
/* C68C78 80240B48 0000882D */  daddu     $s1, $zero, $zero
/* C68C7C 80240B4C 3C148024 */  lui       $s4, %hi(D_80241C98)
/* C68C80 80240B50 26941C98 */  addiu     $s4, $s4, %lo(D_80241C98)
/* C68C84 80240B54 24130020 */  addiu     $s3, $zero, 0x20
/* C68C88 80240B58 3C064248 */  lui       $a2, 0x4248
/* C68C8C 80240B5C 44800000 */  mtc1      $zero, $f0
/* C68C90 80240B60 24020014 */  addiu     $v0, $zero, 0x14
/* C68C94 80240B64 AFA20010 */  sw        $v0, 0x10($sp)
/* C68C98 80240B68 44050000 */  mfc1      $a1, $f0
/* C68C9C 80240B6C 8E470060 */  lw        $a3, 0x60($s2)
/* C68CA0 80240B70 4485B000 */  mtc1      $a1, $f22
/* C68CA4 80240B74 0C00A8ED */  jal       update_lerp
/* C68CA8 80240B78 0240802D */   daddu    $s0, $s2, $zero
/* C68CAC 80240B7C 46000506 */  mov.s     $f20, $f0
.L80240B80:
/* C68CB0 80240B80 4406A000 */  mfc1      $a2, $f20
/* C68CB4 80240B84 27A40020 */  addiu     $a0, $sp, 0x20
/* C68CB8 80240B88 E6160020 */  swc1      $f22, 0x20($s0)
/* C68CBC 80240B8C 8E870000 */  lw        $a3, ($s4)
/* C68CC0 80240B90 02532821 */  addu      $a1, $s2, $s3
/* C68CC4 80240B94 0C00A7E7 */  jal       add_vec2D_polar
/* C68CC8 80240B98 E7B60020 */   swc1     $f22, 0x20($sp)
/* C68CCC 80240B9C C7A4001C */  lwc1      $f4, 0x1c($sp)
/* C68CD0 80240BA0 C7A00020 */  lwc1      $f0, 0x20($sp)
/* C68CD4 80240BA4 46002102 */  mul.s     $f4, $f4, $f0
/* C68CD8 80240BA8 00000000 */  nop
/* C68CDC 80240BAC C7A20018 */  lwc1      $f2, 0x18($sp)
/* C68CE0 80240BB0 26940004 */  addiu     $s4, $s4, 4
/* C68CE4 80240BB4 46001082 */  mul.s     $f2, $f2, $f0
/* C68CE8 80240BB8 00000000 */  nop
/* C68CEC 80240BBC 26730004 */  addiu     $s3, $s3, 4
/* C68CF0 80240BC0 26310001 */  addiu     $s1, $s1, 1
/* C68CF4 80240BC4 2A220003 */  slti      $v0, $s1, 3
/* C68CF8 80240BC8 E6040014 */  swc1      $f4, 0x14($s0)
/* C68CFC 80240BCC E602002C */  swc1      $f2, 0x2c($s0)
/* C68D00 80240BD0 1440FFEB */  bnez      $v0, .L80240B80
/* C68D04 80240BD4 26100004 */   addiu    $s0, $s0, 4
/* C68D08 80240BD8 8E420060 */  lw        $v0, 0x60($s2)
/* C68D0C 80240BDC 24420001 */  addiu     $v0, $v0, 1
/* C68D10 80240BE0 AE420060 */  sw        $v0, 0x60($s2)
/* C68D14 80240BE4 28420015 */  slti      $v0, $v0, 0x15
/* C68D18 80240BE8 1440003D */  bnez      $v0, .L80240CE0
/* C68D1C 80240BEC 24020001 */   addiu    $v0, $zero, 1
/* C68D20 80240BF0 AE420000 */  sw        $v0, ($s2)
/* C68D24 80240BF4 08090338 */  j         .L80240CE0
/* C68D28 80240BF8 AE400060 */   sw       $zero, 0x60($s2)
.L80240BFC:
/* C68D2C 80240BFC 0000882D */  daddu     $s1, $zero, $zero
/* C68D30 80240C00 3C148024 */  lui       $s4, %hi(D_80241C98)
/* C68D34 80240C04 26941C98 */  addiu     $s4, $s4, %lo(D_80241C98)
/* C68D38 80240C08 24130020 */  addiu     $s3, $zero, 0x20
/* C68D3C 80240C0C 0240802D */  daddu     $s0, $s2, $zero
/* C68D40 80240C10 3C014248 */  lui       $at, 0x4248
/* C68D44 80240C14 4481A000 */  mtc1      $at, $f20
/* C68D48 80240C18 4480B000 */  mtc1      $zero, $f22
.L80240C1C:
/* C68D4C 80240C1C 4406A000 */  mfc1      $a2, $f20
/* C68D50 80240C20 27A40020 */  addiu     $a0, $sp, 0x20
/* C68D54 80240C24 E6160020 */  swc1      $f22, 0x20($s0)
/* C68D58 80240C28 8E870000 */  lw        $a3, ($s4)
/* C68D5C 80240C2C 02532821 */  addu      $a1, $s2, $s3
/* C68D60 80240C30 0C00A7E7 */  jal       add_vec2D_polar
/* C68D64 80240C34 E7B60020 */   swc1     $f22, 0x20($sp)
/* C68D68 80240C38 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* C68D6C 80240C3C C7A00020 */  lwc1      $f0, 0x20($sp)
/* C68D70 80240C40 46002102 */  mul.s     $f4, $f4, $f0
/* C68D74 80240C44 00000000 */  nop
/* C68D78 80240C48 C7A20018 */  lwc1      $f2, 0x18($sp)
/* C68D7C 80240C4C 26940004 */  addiu     $s4, $s4, 4
/* C68D80 80240C50 46001082 */  mul.s     $f2, $f2, $f0
/* C68D84 80240C54 00000000 */  nop
/* C68D88 80240C58 26730004 */  addiu     $s3, $s3, 4
/* C68D8C 80240C5C 26310001 */  addiu     $s1, $s1, 1
/* C68D90 80240C60 2A220003 */  slti      $v0, $s1, 3
/* C68D94 80240C64 E6040014 */  swc1      $f4, 0x14($s0)
/* C68D98 80240C68 E602002C */  swc1      $f2, 0x2c($s0)
/* C68D9C 80240C6C 1440FFEB */  bnez      $v0, .L80240C1C
/* C68DA0 80240C70 26100004 */   addiu    $s0, $s0, 4
/* C68DA4 80240C74 8E420060 */  lw        $v0, 0x60($s2)
/* C68DA8 80240C78 24420001 */  addiu     $v0, $v0, 1
/* C68DAC 80240C7C AE420060 */  sw        $v0, 0x60($s2)
/* C68DB0 80240C80 28420010 */  slti      $v0, $v0, 0x10
/* C68DB4 80240C84 14400016 */  bnez      $v0, .L80240CE0
/* C68DB8 80240C88 2402000F */   addiu    $v0, $zero, 0xf
/* C68DBC 80240C8C AE420060 */  sw        $v0, 0x60($s2)
/* C68DC0 80240C90 24020002 */  addiu     $v0, $zero, 2
/* C68DC4 80240C94 08090338 */  j         .L80240CE0
/* C68DC8 80240C98 AE420000 */   sw       $v0, ($s2)
.L80240C9C:
/* C68DCC 80240C9C 8E420060 */  lw        $v0, 0x60($s2)
/* C68DD0 80240CA0 24420001 */  addiu     $v0, $v0, 1
/* C68DD4 80240CA4 AE420060 */  sw        $v0, 0x60($s2)
/* C68DD8 80240CA8 2842001F */  slti      $v0, $v0, 0x1f
/* C68DDC 80240CAC 1440000C */  bnez      $v0, .L80240CE0
/* C68DE0 80240CB0 0000882D */   daddu    $s1, $zero, $zero
/* C68DE4 80240CB4 0240282D */  daddu     $a1, $s2, $zero
.L80240CB8:
/* C68DE8 80240CB8 8CA20008 */  lw        $v0, 8($a1)
/* C68DEC 80240CBC 8C430000 */  lw        $v1, ($v0)
/* C68DF0 80240CC0 26310001 */  addiu     $s1, $s1, 1
/* C68DF4 80240CC4 34630010 */  ori       $v1, $v1, 0x10
/* C68DF8 80240CC8 AC430000 */  sw        $v1, ($v0)
/* C68DFC 80240CCC 2A220003 */  slti      $v0, $s1, 3
/* C68E00 80240CD0 1440FFF9 */  bnez      $v0, .L80240CB8
/* C68E04 80240CD4 24A50004 */   addiu    $a1, $a1, 4
/* C68E08 80240CD8 08090385 */  j         .L80240E14
/* C68E0C 80240CDC 24020002 */   addiu    $v0, $zero, 2
.L80240CE0:
/* C68E10 80240CE0 8E430004 */  lw        $v1, 4($s2)
/* C68E14 80240CE4 10600005 */  beqz      $v1, .L80240CFC
/* C68E18 80240CE8 24020001 */   addiu    $v0, $zero, 1
/* C68E1C 80240CEC 1062000B */  beq       $v1, $v0, .L80240D1C
/* C68E20 80240CF0 0000882D */   daddu    $s1, $zero, $zero
/* C68E24 80240CF4 08090374 */  j         .L80240DD0
/* C68E28 80240CF8 0240282D */   daddu    $a1, $s2, $zero
.L80240CFC:
/* C68E2C 80240CFC 8E420064 */  lw        $v0, 0x64($s2)
/* C68E30 80240D00 24420001 */  addiu     $v0, $v0, 1
/* C68E34 80240D04 AE420064 */  sw        $v0, 0x64($s2)
/* C68E38 80240D08 28420010 */  slti      $v0, $v0, 0x10
/* C68E3C 80240D0C 1440002F */  bnez      $v0, .L80240DCC
/* C68E40 80240D10 0000882D */   daddu    $s1, $zero, $zero
/* C68E44 80240D14 08090370 */  j         .L80240DC0
/* C68E48 80240D18 24020001 */   addiu    $v0, $zero, 1
.L80240D1C:
/* C68E4C 80240D1C 4480A000 */  mtc1      $zero, $f20
/* C68E50 80240D20 24130014 */  addiu     $s3, $zero, 0x14
/* C68E54 80240D24 0240802D */  daddu     $s0, $s2, $zero
.L80240D28:
/* C68E58 80240D28 4405A000 */  mfc1      $a1, $f20
/* C68E5C 80240D2C AFB30010 */  sw        $s3, 0x10($sp)
/* C68E60 80240D30 8E060038 */  lw        $a2, 0x38($s0)
/* C68E64 80240D34 8E470064 */  lw        $a3, 0x64($s2)
/* C68E68 80240D38 0C00A8ED */  jal       update_lerp
/* C68E6C 80240D3C 24040001 */   addiu    $a0, $zero, 1
/* C68E70 80240D40 C6020014 */  lwc1      $f2, 0x14($s0)
/* C68E74 80240D44 46001080 */  add.s     $f2, $f2, $f0
/* C68E78 80240D48 4405A000 */  mfc1      $a1, $f20
/* C68E7C 80240D4C E6020014 */  swc1      $f2, 0x14($s0)
/* C68E80 80240D50 AFB30010 */  sw        $s3, 0x10($sp)
/* C68E84 80240D54 8E060044 */  lw        $a2, 0x44($s0)
/* C68E88 80240D58 8E470064 */  lw        $a3, 0x64($s2)
/* C68E8C 80240D5C 0C00A8ED */  jal       update_lerp
/* C68E90 80240D60 24040001 */   addiu    $a0, $zero, 1
/* C68E94 80240D64 C6020020 */  lwc1      $f2, 0x20($s0)
/* C68E98 80240D68 46001080 */  add.s     $f2, $f2, $f0
/* C68E9C 80240D6C 4405A000 */  mfc1      $a1, $f20
/* C68EA0 80240D70 E6020020 */  swc1      $f2, 0x20($s0)
/* C68EA4 80240D74 AFB30010 */  sw        $s3, 0x10($sp)
/* C68EA8 80240D78 8E060050 */  lw        $a2, 0x50($s0)
/* C68EAC 80240D7C 8E470064 */  lw        $a3, 0x64($s2)
/* C68EB0 80240D80 0C00A8ED */  jal       update_lerp
/* C68EB4 80240D84 24040001 */   addiu    $a0, $zero, 1
/* C68EB8 80240D88 C602002C */  lwc1      $f2, 0x2c($s0)
/* C68EBC 80240D8C 46001080 */  add.s     $f2, $f2, $f0
/* C68EC0 80240D90 26310001 */  addiu     $s1, $s1, 1
/* C68EC4 80240D94 2A220003 */  slti      $v0, $s1, 3
/* C68EC8 80240D98 E602002C */  swc1      $f2, 0x2c($s0)
/* C68ECC 80240D9C 1440FFE2 */  bnez      $v0, .L80240D28
/* C68ED0 80240DA0 26100004 */   addiu    $s0, $s0, 4
/* C68ED4 80240DA4 8E420064 */  lw        $v0, 0x64($s2)
/* C68ED8 80240DA8 24420001 */  addiu     $v0, $v0, 1
/* C68EDC 80240DAC AE420064 */  sw        $v0, 0x64($s2)
/* C68EE0 80240DB0 28420015 */  slti      $v0, $v0, 0x15
/* C68EE4 80240DB4 14400005 */  bnez      $v0, .L80240DCC
/* C68EE8 80240DB8 0000882D */   daddu    $s1, $zero, $zero
/* C68EEC 80240DBC 24020002 */  addiu     $v0, $zero, 2
.L80240DC0:
/* C68EF0 80240DC0 AE420004 */  sw        $v0, 4($s2)
/* C68EF4 80240DC4 AE400064 */  sw        $zero, 0x64($s2)
/* C68EF8 80240DC8 0000882D */  daddu     $s1, $zero, $zero
.L80240DCC:
/* C68EFC 80240DCC 0240282D */  daddu     $a1, $s2, $zero
.L80240DD0:
/* C68F00 80240DD0 8CA20008 */  lw        $v0, 8($a1)
/* C68F04 80240DD4 C4A00014 */  lwc1      $f0, 0x14($a1)
/* C68F08 80240DD8 8C42000C */  lw        $v0, 0xc($v0)
/* C68F0C 80240DDC E4400010 */  swc1      $f0, 0x10($v0)
/* C68F10 80240DE0 8CA20008 */  lw        $v0, 8($a1)
/* C68F14 80240DE4 C4A00020 */  lwc1      $f0, 0x20($a1)
/* C68F18 80240DE8 8C42000C */  lw        $v0, 0xc($v0)
/* C68F1C 80240DEC 26310001 */  addiu     $s1, $s1, 1
/* C68F20 80240DF0 E4400014 */  swc1      $f0, 0x14($v0)
/* C68F24 80240DF4 8CA20008 */  lw        $v0, 8($a1)
/* C68F28 80240DF8 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* C68F2C 80240DFC 8C42000C */  lw        $v0, 0xc($v0)
/* C68F30 80240E00 E4400018 */  swc1      $f0, 0x18($v0)
/* C68F34 80240E04 2A220003 */  slti      $v0, $s1, 3
/* C68F38 80240E08 1440FFF1 */  bnez      $v0, .L80240DD0
/* C68F3C 80240E0C 24A50004 */   addiu    $a1, $a1, 4
/* C68F40 80240E10 0000102D */  daddu     $v0, $zero, $zero
.L80240E14:
/* C68F44 80240E14 8FBF0044 */  lw        $ra, 0x44($sp)
/* C68F48 80240E18 8FB60040 */  lw        $s6, 0x40($sp)
/* C68F4C 80240E1C 8FB5003C */  lw        $s5, 0x3c($sp)
/* C68F50 80240E20 8FB40038 */  lw        $s4, 0x38($sp)
/* C68F54 80240E24 8FB30034 */  lw        $s3, 0x34($sp)
/* C68F58 80240E28 8FB20030 */  lw        $s2, 0x30($sp)
/* C68F5C 80240E2C 8FB1002C */  lw        $s1, 0x2c($sp)
/* C68F60 80240E30 8FB00028 */  lw        $s0, 0x28($sp)
/* C68F64 80240E34 D7B80058 */  ldc1      $f24, 0x58($sp)
/* C68F68 80240E38 D7B60050 */  ldc1      $f22, 0x50($sp)
/* C68F6C 80240E3C D7B40048 */  ldc1      $f20, 0x48($sp)
/* C68F70 80240E40 03E00008 */  jr        $ra
/* C68F74 80240E44 27BD0060 */   addiu    $sp, $sp, 0x60
