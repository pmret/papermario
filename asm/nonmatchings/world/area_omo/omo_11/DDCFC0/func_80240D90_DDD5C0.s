.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D90_DDD5C0
/* DDD5C0 80240D90 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* DDD5C4 80240D94 AFB60040 */  sw        $s6, 0x40($sp)
/* DDD5C8 80240D98 0080B02D */  daddu     $s6, $a0, $zero
/* DDD5CC 80240D9C AFB00028 */  sw        $s0, 0x28($sp)
/* DDD5D0 80240DA0 00A0802D */  daddu     $s0, $a1, $zero
/* DDD5D4 80240DA4 AFBF0044 */  sw        $ra, 0x44($sp)
/* DDD5D8 80240DA8 AFB5003C */  sw        $s5, 0x3c($sp)
/* DDD5DC 80240DAC AFB40038 */  sw        $s4, 0x38($sp)
/* DDD5E0 80240DB0 AFB30034 */  sw        $s3, 0x34($sp)
/* DDD5E4 80240DB4 AFB20030 */  sw        $s2, 0x30($sp)
/* DDD5E8 80240DB8 AFB1002C */  sw        $s1, 0x2c($sp)
/* DDD5EC 80240DBC F7B80058 */  sdc1      $f24, 0x58($sp)
/* DDD5F0 80240DC0 F7B60050 */  sdc1      $f22, 0x50($sp)
/* DDD5F4 80240DC4 F7B40048 */  sdc1      $f20, 0x48($sp)
/* DDD5F8 80240DC8 8ED3000C */  lw        $s3, 0xc($s6)
/* DDD5FC 80240DCC 0C00EAD2 */  jal       get_npc_safe
/* DDD600 80240DD0 2404FFFC */   addiu    $a0, $zero, -4
/* DDD604 80240DD4 27A50018 */  addiu     $a1, $sp, 0x18
/* DDD608 80240DD8 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* DDD60C 80240DDC 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* DDD610 80240DE0 27A6001C */  addiu     $a2, $sp, 0x1c
/* DDD614 80240DE4 00041880 */  sll       $v1, $a0, 2
/* DDD618 80240DE8 00641821 */  addu      $v1, $v1, $a0
/* DDD61C 80240DEC 00031880 */  sll       $v1, $v1, 2
/* DDD620 80240DF0 00641823 */  subu      $v1, $v1, $a0
/* DDD624 80240DF4 000320C0 */  sll       $a0, $v1, 3
/* DDD628 80240DF8 00641821 */  addu      $v1, $v1, $a0
/* DDD62C 80240DFC 000318C0 */  sll       $v1, $v1, 3
/* DDD630 80240E00 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* DDD634 80240E04 00230821 */  addu      $at, $at, $v1
/* DDD638 80240E08 C42C1DEC */  lwc1      $f12, %lo(D_800B1DEC)($at)
/* DDD63C 80240E0C 0C00A88D */  jal       sin_cos_deg
/* DDD640 80240E10 0040A82D */   daddu    $s5, $v0, $zero
/* DDD644 80240E14 1200005D */  beqz      $s0, .L80240F8C
/* DDD648 80240E18 00000000 */   nop      
/* DDD64C 80240E1C 0C00AB0A */  jal       general_heap_malloc
/* DDD650 80240E20 24040068 */   addiu    $a0, $zero, 0x68
/* DDD654 80240E24 0040902D */  daddu     $s2, $v0, $zero
/* DDD658 80240E28 02C0202D */  daddu     $a0, $s6, $zero
/* DDD65C 80240E2C 0000882D */  daddu     $s1, $zero, $zero
/* DDD660 80240E30 2414FFFF */  addiu     $s4, $zero, -1
/* DDD664 80240E34 AED20060 */  sw        $s2, 0x60($s6)
/* DDD668 80240E38 8E650000 */  lw        $a1, ($s3)
/* DDD66C 80240E3C 3C014148 */  lui       $at, 0x4148
/* DDD670 80240E40 4481C000 */  mtc1      $at, $f24
/* DDD674 80240E44 3C013F80 */  lui       $at, 0x3f80
/* DDD678 80240E48 4481B000 */  mtc1      $at, $f22
/* DDD67C 80240E4C 4480A000 */  mtc1      $zero, $f20
/* DDD680 80240E50 0C0B1EAF */  jal       get_variable
/* DDD684 80240E54 0240802D */   daddu    $s0, $s2, $zero
/* DDD688 80240E58 0C04417A */  jal       get_entity_by_index
/* DDD68C 80240E5C 0040202D */   daddu    $a0, $v0, $zero
/* DDD690 80240E60 AE42005C */  sw        $v0, 0x5c($s2)
.L80240E64:
/* DDD694 80240E64 8E42005C */  lw        $v0, 0x5c($s2)
/* DDD698 80240E68 C440004C */  lwc1      $f0, 0x4c($v0)
/* DDD69C 80240E6C 0000202D */  daddu     $a0, $zero, $zero
/* DDD6A0 80240E70 E7B60010 */  swc1      $f22, 0x10($sp)
/* DDD6A4 80240E74 AFB40014 */  sw        $s4, 0x14($sp)
/* DDD6A8 80240E78 46180000 */  add.s     $f0, $f0, $f24
/* DDD6AC 80240E7C 8C450048 */  lw        $a1, 0x48($v0)
/* DDD6B0 80240E80 8C470050 */  lw        $a3, 0x50($v0)
/* DDD6B4 80240E84 44060000 */  mfc1      $a2, $f0
/* DDD6B8 80240E88 0C01C5BC */  jal       func_800716F0
/* DDD6BC 80240E8C 26310001 */   addiu    $s1, $s1, 1
/* DDD6C0 80240E90 AE020008 */  sw        $v0, 8($s0)
/* DDD6C4 80240E94 E614002C */  swc1      $f20, 0x2c($s0)
/* DDD6C8 80240E98 E6140020 */  swc1      $f20, 0x20($s0)
/* DDD6CC 80240E9C E6140014 */  swc1      $f20, 0x14($s0)
/* DDD6D0 80240EA0 E6140050 */  swc1      $f20, 0x50($s0)
/* DDD6D4 80240EA4 E6140044 */  swc1      $f20, 0x44($s0)
/* DDD6D8 80240EA8 E6140038 */  swc1      $f20, 0x38($s0)
/* DDD6DC 80240EAC 2A220003 */  slti      $v0, $s1, 3
/* DDD6E0 80240EB0 1440FFEC */  bnez      $v0, .L80240E64
/* DDD6E4 80240EB4 26100004 */   addiu    $s0, $s0, 4
/* DDD6E8 80240EB8 0000882D */  daddu     $s1, $zero, $zero
/* DDD6EC 80240EBC 0240802D */  daddu     $s0, $s2, $zero
/* DDD6F0 80240EC0 3C148024 */  lui       $s4, %hi(D_80241E98)
/* DDD6F4 80240EC4 26941E98 */  addiu     $s4, $s4, %lo(D_80241E98)
/* DDD6F8 80240EC8 3C014248 */  lui       $at, 0x4248
/* DDD6FC 80240ECC 4481A000 */  mtc1      $at, $f20
/* DDD700 80240ED0 24130044 */  addiu     $s3, $zero, 0x44
/* DDD704 80240ED4 AE400000 */  sw        $zero, ($s2)
/* DDD708 80240ED8 AE400004 */  sw        $zero, 4($s2)
/* DDD70C 80240EDC AE400060 */  sw        $zero, 0x60($s2)
/* DDD710 80240EE0 AE400064 */  sw        $zero, 0x64($s2)
.L80240EE4:
/* DDD714 80240EE4 27A40020 */  addiu     $a0, $sp, 0x20
/* DDD718 80240EE8 4406A000 */  mfc1      $a2, $f20
/* DDD71C 80240EEC 8E870000 */  lw        $a3, ($s4)
/* DDD720 80240EF0 02532821 */  addu      $a1, $s2, $s3
/* DDD724 80240EF4 0C00A7E7 */  jal       add_vec2D_polar
/* DDD728 80240EF8 AFA00020 */   sw       $zero, 0x20($sp)
/* DDD72C 80240EFC C7A2001C */  lwc1      $f2, 0x1c($sp)
/* DDD730 80240F00 C7A40020 */  lwc1      $f4, 0x20($sp)
/* DDD734 80240F04 46041082 */  mul.s     $f2, $f2, $f4
/* DDD738 80240F08 00000000 */  nop       
/* DDD73C 80240F0C C7A00018 */  lwc1      $f0, 0x18($sp)
/* DDD740 80240F10 46040002 */  mul.s     $f0, $f0, $f4
/* DDD744 80240F14 00000000 */  nop       
/* DDD748 80240F18 E6020038 */  swc1      $f2, 0x38($s0)
/* DDD74C 80240F1C E6000050 */  swc1      $f0, 0x50($s0)
/* DDD750 80240F20 8E42005C */  lw        $v0, 0x5c($s2)
/* DDD754 80240F24 C6000038 */  lwc1      $f0, 0x38($s0)
/* DDD758 80240F28 C4420048 */  lwc1      $f2, 0x48($v0)
/* DDD75C 80240F2C 46001080 */  add.s     $f2, $f2, $f0
/* DDD760 80240F30 C6A00038 */  lwc1      $f0, 0x38($s5)
/* DDD764 80240F34 46020001 */  sub.s     $f0, $f0, $f2
/* DDD768 80240F38 E6000038 */  swc1      $f0, 0x38($s0)
/* DDD76C 80240F3C 8E42005C */  lw        $v0, 0x5c($s2)
/* DDD770 80240F40 C6000044 */  lwc1      $f0, 0x44($s0)
/* DDD774 80240F44 C442004C */  lwc1      $f2, 0x4c($v0)
/* DDD778 80240F48 46001080 */  add.s     $f2, $f2, $f0
/* DDD77C 80240F4C C6A0003C */  lwc1      $f0, 0x3c($s5)
/* DDD780 80240F50 46020001 */  sub.s     $f0, $f0, $f2
/* DDD784 80240F54 E6000044 */  swc1      $f0, 0x44($s0)
/* DDD788 80240F58 8E42005C */  lw        $v0, 0x5c($s2)
/* DDD78C 80240F5C C6000050 */  lwc1      $f0, 0x50($s0)
/* DDD790 80240F60 C4420050 */  lwc1      $f2, 0x50($v0)
/* DDD794 80240F64 26940004 */  addiu     $s4, $s4, 4
/* DDD798 80240F68 46001080 */  add.s     $f2, $f2, $f0
/* DDD79C 80240F6C C6A00040 */  lwc1      $f0, 0x40($s5)
/* DDD7A0 80240F70 26730004 */  addiu     $s3, $s3, 4
/* DDD7A4 80240F74 46020001 */  sub.s     $f0, $f0, $f2
/* DDD7A8 80240F78 26310001 */  addiu     $s1, $s1, 1
/* DDD7AC 80240F7C 2A220003 */  slti      $v0, $s1, 3
/* DDD7B0 80240F80 E6000050 */  swc1      $f0, 0x50($s0)
/* DDD7B4 80240F84 1440FFD7 */  bnez      $v0, .L80240EE4
/* DDD7B8 80240F88 26100004 */   addiu    $s0, $s0, 4
.L80240F8C:
/* DDD7BC 80240F8C 8ED20060 */  lw        $s2, 0x60($s6)
/* DDD7C0 80240F90 8E430000 */  lw        $v1, ($s2)
/* DDD7C4 80240F94 24020001 */  addiu     $v0, $zero, 1
/* DDD7C8 80240F98 10620038 */  beq       $v1, $v0, .L8024107C
/* DDD7CC 80240F9C 28620002 */   slti     $v0, $v1, 2
/* DDD7D0 80240FA0 50400005 */  beql      $v0, $zero, .L80240FB8
/* DDD7D4 80240FA4 24020002 */   addiu    $v0, $zero, 2
/* DDD7D8 80240FA8 10600007 */  beqz      $v1, .L80240FC8
/* DDD7DC 80240FAC 24040005 */   addiu    $a0, $zero, 5
/* DDD7E0 80240FB0 08090458 */  j         .L80241160
/* DDD7E4 80240FB4 00000000 */   nop      
.L80240FB8:
/* DDD7E8 80240FB8 10620058 */  beq       $v1, $v0, .L8024111C
/* DDD7EC 80240FBC 00000000 */   nop      
/* DDD7F0 80240FC0 08090458 */  j         .L80241160
/* DDD7F4 80240FC4 00000000 */   nop      
.L80240FC8:
/* DDD7F8 80240FC8 0000882D */  daddu     $s1, $zero, $zero
/* DDD7FC 80240FCC 3C148024 */  lui       $s4, %hi(D_80241E98)
/* DDD800 80240FD0 26941E98 */  addiu     $s4, $s4, %lo(D_80241E98)
/* DDD804 80240FD4 24130020 */  addiu     $s3, $zero, 0x20
/* DDD808 80240FD8 3C064248 */  lui       $a2, 0x4248
/* DDD80C 80240FDC 44800000 */  mtc1      $zero, $f0
/* DDD810 80240FE0 24020014 */  addiu     $v0, $zero, 0x14
/* DDD814 80240FE4 AFA20010 */  sw        $v0, 0x10($sp)
/* DDD818 80240FE8 44050000 */  mfc1      $a1, $f0
/* DDD81C 80240FEC 8E470060 */  lw        $a3, 0x60($s2)
/* DDD820 80240FF0 4485B000 */  mtc1      $a1, $f22
/* DDD824 80240FF4 0C00A8ED */  jal       update_lerp
/* DDD828 80240FF8 0240802D */   daddu    $s0, $s2, $zero
/* DDD82C 80240FFC 46000506 */  mov.s     $f20, $f0
.L80241000:
/* DDD830 80241000 4406A000 */  mfc1      $a2, $f20
/* DDD834 80241004 27A40020 */  addiu     $a0, $sp, 0x20
/* DDD838 80241008 E6160020 */  swc1      $f22, 0x20($s0)
/* DDD83C 8024100C 8E870000 */  lw        $a3, ($s4)
/* DDD840 80241010 02532821 */  addu      $a1, $s2, $s3
/* DDD844 80241014 0C00A7E7 */  jal       add_vec2D_polar
/* DDD848 80241018 E7B60020 */   swc1     $f22, 0x20($sp)
/* DDD84C 8024101C C7A4001C */  lwc1      $f4, 0x1c($sp)
/* DDD850 80241020 C7A00020 */  lwc1      $f0, 0x20($sp)
/* DDD854 80241024 46002102 */  mul.s     $f4, $f4, $f0
/* DDD858 80241028 00000000 */  nop       
/* DDD85C 8024102C C7A20018 */  lwc1      $f2, 0x18($sp)
/* DDD860 80241030 26940004 */  addiu     $s4, $s4, 4
/* DDD864 80241034 46001082 */  mul.s     $f2, $f2, $f0
/* DDD868 80241038 00000000 */  nop       
/* DDD86C 8024103C 26730004 */  addiu     $s3, $s3, 4
/* DDD870 80241040 26310001 */  addiu     $s1, $s1, 1
/* DDD874 80241044 2A220003 */  slti      $v0, $s1, 3
/* DDD878 80241048 E6040014 */  swc1      $f4, 0x14($s0)
/* DDD87C 8024104C E602002C */  swc1      $f2, 0x2c($s0)
/* DDD880 80241050 1440FFEB */  bnez      $v0, .L80241000
/* DDD884 80241054 26100004 */   addiu    $s0, $s0, 4
/* DDD888 80241058 8E420060 */  lw        $v0, 0x60($s2)
/* DDD88C 8024105C 24420001 */  addiu     $v0, $v0, 1
/* DDD890 80241060 AE420060 */  sw        $v0, 0x60($s2)
/* DDD894 80241064 28420015 */  slti      $v0, $v0, 0x15
/* DDD898 80241068 1440003D */  bnez      $v0, .L80241160
/* DDD89C 8024106C 24020001 */   addiu    $v0, $zero, 1
/* DDD8A0 80241070 AE420000 */  sw        $v0, ($s2)
/* DDD8A4 80241074 08090458 */  j         .L80241160
/* DDD8A8 80241078 AE400060 */   sw       $zero, 0x60($s2)
.L8024107C:
/* DDD8AC 8024107C 0000882D */  daddu     $s1, $zero, $zero
/* DDD8B0 80241080 3C148024 */  lui       $s4, %hi(D_80241E98)
/* DDD8B4 80241084 26941E98 */  addiu     $s4, $s4, %lo(D_80241E98)
/* DDD8B8 80241088 24130020 */  addiu     $s3, $zero, 0x20
/* DDD8BC 8024108C 0240802D */  daddu     $s0, $s2, $zero
/* DDD8C0 80241090 3C014248 */  lui       $at, 0x4248
/* DDD8C4 80241094 4481A000 */  mtc1      $at, $f20
/* DDD8C8 80241098 4480B000 */  mtc1      $zero, $f22
.L8024109C:
/* DDD8CC 8024109C 4406A000 */  mfc1      $a2, $f20
/* DDD8D0 802410A0 27A40020 */  addiu     $a0, $sp, 0x20
/* DDD8D4 802410A4 E6160020 */  swc1      $f22, 0x20($s0)
/* DDD8D8 802410A8 8E870000 */  lw        $a3, ($s4)
/* DDD8DC 802410AC 02532821 */  addu      $a1, $s2, $s3
/* DDD8E0 802410B0 0C00A7E7 */  jal       add_vec2D_polar
/* DDD8E4 802410B4 E7B60020 */   swc1     $f22, 0x20($sp)
/* DDD8E8 802410B8 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* DDD8EC 802410BC C7A00020 */  lwc1      $f0, 0x20($sp)
/* DDD8F0 802410C0 46002102 */  mul.s     $f4, $f4, $f0
/* DDD8F4 802410C4 00000000 */  nop       
/* DDD8F8 802410C8 C7A20018 */  lwc1      $f2, 0x18($sp)
/* DDD8FC 802410CC 26940004 */  addiu     $s4, $s4, 4
/* DDD900 802410D0 46001082 */  mul.s     $f2, $f2, $f0
/* DDD904 802410D4 00000000 */  nop       
/* DDD908 802410D8 26730004 */  addiu     $s3, $s3, 4
/* DDD90C 802410DC 26310001 */  addiu     $s1, $s1, 1
/* DDD910 802410E0 2A220003 */  slti      $v0, $s1, 3
/* DDD914 802410E4 E6040014 */  swc1      $f4, 0x14($s0)
/* DDD918 802410E8 E602002C */  swc1      $f2, 0x2c($s0)
/* DDD91C 802410EC 1440FFEB */  bnez      $v0, .L8024109C
/* DDD920 802410F0 26100004 */   addiu    $s0, $s0, 4
/* DDD924 802410F4 8E420060 */  lw        $v0, 0x60($s2)
/* DDD928 802410F8 24420001 */  addiu     $v0, $v0, 1
/* DDD92C 802410FC AE420060 */  sw        $v0, 0x60($s2)
/* DDD930 80241100 28420010 */  slti      $v0, $v0, 0x10
/* DDD934 80241104 14400016 */  bnez      $v0, .L80241160
/* DDD938 80241108 2402000F */   addiu    $v0, $zero, 0xf
/* DDD93C 8024110C AE420060 */  sw        $v0, 0x60($s2)
/* DDD940 80241110 24020002 */  addiu     $v0, $zero, 2
/* DDD944 80241114 08090458 */  j         .L80241160
/* DDD948 80241118 AE420000 */   sw       $v0, ($s2)
.L8024111C:
/* DDD94C 8024111C 8E420060 */  lw        $v0, 0x60($s2)
/* DDD950 80241120 24420001 */  addiu     $v0, $v0, 1
/* DDD954 80241124 AE420060 */  sw        $v0, 0x60($s2)
/* DDD958 80241128 2842001F */  slti      $v0, $v0, 0x1f
/* DDD95C 8024112C 1440000C */  bnez      $v0, .L80241160
/* DDD960 80241130 0000882D */   daddu    $s1, $zero, $zero
/* DDD964 80241134 0240282D */  daddu     $a1, $s2, $zero
.L80241138:
/* DDD968 80241138 8CA20008 */  lw        $v0, 8($a1)
/* DDD96C 8024113C 8C430000 */  lw        $v1, ($v0)
/* DDD970 80241140 26310001 */  addiu     $s1, $s1, 1
/* DDD974 80241144 34630010 */  ori       $v1, $v1, 0x10
/* DDD978 80241148 AC430000 */  sw        $v1, ($v0)
/* DDD97C 8024114C 2A220003 */  slti      $v0, $s1, 3
/* DDD980 80241150 1440FFF9 */  bnez      $v0, .L80241138
/* DDD984 80241154 24A50004 */   addiu    $a1, $a1, 4
/* DDD988 80241158 080904A5 */  j         .L80241294
/* DDD98C 8024115C 24020002 */   addiu    $v0, $zero, 2
.L80241160:
/* DDD990 80241160 8E430004 */  lw        $v1, 4($s2)
/* DDD994 80241164 10600005 */  beqz      $v1, .L8024117C
/* DDD998 80241168 24020001 */   addiu    $v0, $zero, 1
/* DDD99C 8024116C 1062000B */  beq       $v1, $v0, .L8024119C
/* DDD9A0 80241170 0000882D */   daddu    $s1, $zero, $zero
/* DDD9A4 80241174 08090494 */  j         .L80241250
/* DDD9A8 80241178 0240282D */   daddu    $a1, $s2, $zero
.L8024117C:
/* DDD9AC 8024117C 8E420064 */  lw        $v0, 0x64($s2)
/* DDD9B0 80241180 24420001 */  addiu     $v0, $v0, 1
/* DDD9B4 80241184 AE420064 */  sw        $v0, 0x64($s2)
/* DDD9B8 80241188 28420010 */  slti      $v0, $v0, 0x10
/* DDD9BC 8024118C 1440002F */  bnez      $v0, .L8024124C
/* DDD9C0 80241190 0000882D */   daddu    $s1, $zero, $zero
/* DDD9C4 80241194 08090490 */  j         .L80241240
/* DDD9C8 80241198 24020001 */   addiu    $v0, $zero, 1
.L8024119C:
/* DDD9CC 8024119C 4480A000 */  mtc1      $zero, $f20
/* DDD9D0 802411A0 24130014 */  addiu     $s3, $zero, 0x14
/* DDD9D4 802411A4 0240802D */  daddu     $s0, $s2, $zero
.L802411A8:
/* DDD9D8 802411A8 4405A000 */  mfc1      $a1, $f20
/* DDD9DC 802411AC AFB30010 */  sw        $s3, 0x10($sp)
/* DDD9E0 802411B0 8E060038 */  lw        $a2, 0x38($s0)
/* DDD9E4 802411B4 8E470064 */  lw        $a3, 0x64($s2)
/* DDD9E8 802411B8 0C00A8ED */  jal       update_lerp
/* DDD9EC 802411BC 24040001 */   addiu    $a0, $zero, 1
/* DDD9F0 802411C0 C6020014 */  lwc1      $f2, 0x14($s0)
/* DDD9F4 802411C4 46001080 */  add.s     $f2, $f2, $f0
/* DDD9F8 802411C8 4405A000 */  mfc1      $a1, $f20
/* DDD9FC 802411CC E6020014 */  swc1      $f2, 0x14($s0)
/* DDDA00 802411D0 AFB30010 */  sw        $s3, 0x10($sp)
/* DDDA04 802411D4 8E060044 */  lw        $a2, 0x44($s0)
/* DDDA08 802411D8 8E470064 */  lw        $a3, 0x64($s2)
/* DDDA0C 802411DC 0C00A8ED */  jal       update_lerp
/* DDDA10 802411E0 24040001 */   addiu    $a0, $zero, 1
/* DDDA14 802411E4 C6020020 */  lwc1      $f2, 0x20($s0)
/* DDDA18 802411E8 46001080 */  add.s     $f2, $f2, $f0
/* DDDA1C 802411EC 4405A000 */  mfc1      $a1, $f20
/* DDDA20 802411F0 E6020020 */  swc1      $f2, 0x20($s0)
/* DDDA24 802411F4 AFB30010 */  sw        $s3, 0x10($sp)
/* DDDA28 802411F8 8E060050 */  lw        $a2, 0x50($s0)
/* DDDA2C 802411FC 8E470064 */  lw        $a3, 0x64($s2)
/* DDDA30 80241200 0C00A8ED */  jal       update_lerp
/* DDDA34 80241204 24040001 */   addiu    $a0, $zero, 1
/* DDDA38 80241208 C602002C */  lwc1      $f2, 0x2c($s0)
/* DDDA3C 8024120C 46001080 */  add.s     $f2, $f2, $f0
/* DDDA40 80241210 26310001 */  addiu     $s1, $s1, 1
/* DDDA44 80241214 2A220003 */  slti      $v0, $s1, 3
/* DDDA48 80241218 E602002C */  swc1      $f2, 0x2c($s0)
/* DDDA4C 8024121C 1440FFE2 */  bnez      $v0, .L802411A8
/* DDDA50 80241220 26100004 */   addiu    $s0, $s0, 4
/* DDDA54 80241224 8E420064 */  lw        $v0, 0x64($s2)
/* DDDA58 80241228 24420001 */  addiu     $v0, $v0, 1
/* DDDA5C 8024122C AE420064 */  sw        $v0, 0x64($s2)
/* DDDA60 80241230 28420015 */  slti      $v0, $v0, 0x15
/* DDDA64 80241234 14400005 */  bnez      $v0, .L8024124C
/* DDDA68 80241238 0000882D */   daddu    $s1, $zero, $zero
/* DDDA6C 8024123C 24020002 */  addiu     $v0, $zero, 2
.L80241240:
/* DDDA70 80241240 AE420004 */  sw        $v0, 4($s2)
/* DDDA74 80241244 AE400064 */  sw        $zero, 0x64($s2)
/* DDDA78 80241248 0000882D */  daddu     $s1, $zero, $zero
.L8024124C:
/* DDDA7C 8024124C 0240282D */  daddu     $a1, $s2, $zero
.L80241250:
/* DDDA80 80241250 8CA20008 */  lw        $v0, 8($a1)
/* DDDA84 80241254 C4A00014 */  lwc1      $f0, 0x14($a1)
/* DDDA88 80241258 8C42000C */  lw        $v0, 0xc($v0)
/* DDDA8C 8024125C E4400010 */  swc1      $f0, 0x10($v0)
/* DDDA90 80241260 8CA20008 */  lw        $v0, 8($a1)
/* DDDA94 80241264 C4A00020 */  lwc1      $f0, 0x20($a1)
/* DDDA98 80241268 8C42000C */  lw        $v0, 0xc($v0)
/* DDDA9C 8024126C 26310001 */  addiu     $s1, $s1, 1
/* DDDAA0 80241270 E4400014 */  swc1      $f0, 0x14($v0)
/* DDDAA4 80241274 8CA20008 */  lw        $v0, 8($a1)
/* DDDAA8 80241278 C4A0002C */  lwc1      $f0, 0x2c($a1)
/* DDDAAC 8024127C 8C42000C */  lw        $v0, 0xc($v0)
/* DDDAB0 80241280 E4400018 */  swc1      $f0, 0x18($v0)
/* DDDAB4 80241284 2A220003 */  slti      $v0, $s1, 3
/* DDDAB8 80241288 1440FFF1 */  bnez      $v0, .L80241250
/* DDDABC 8024128C 24A50004 */   addiu    $a1, $a1, 4
/* DDDAC0 80241290 0000102D */  daddu     $v0, $zero, $zero
.L80241294:
/* DDDAC4 80241294 8FBF0044 */  lw        $ra, 0x44($sp)
/* DDDAC8 80241298 8FB60040 */  lw        $s6, 0x40($sp)
/* DDDACC 8024129C 8FB5003C */  lw        $s5, 0x3c($sp)
/* DDDAD0 802412A0 8FB40038 */  lw        $s4, 0x38($sp)
/* DDDAD4 802412A4 8FB30034 */  lw        $s3, 0x34($sp)
/* DDDAD8 802412A8 8FB20030 */  lw        $s2, 0x30($sp)
/* DDDADC 802412AC 8FB1002C */  lw        $s1, 0x2c($sp)
/* DDDAE0 802412B0 8FB00028 */  lw        $s0, 0x28($sp)
/* DDDAE4 802412B4 D7B80058 */  ldc1      $f24, 0x58($sp)
/* DDDAE8 802412B8 D7B60050 */  ldc1      $f22, 0x50($sp)
/* DDDAEC 802412BC D7B40048 */  ldc1      $f20, 0x48($sp)
/* DDDAF0 802412C0 03E00008 */  jr        $ra
/* DDDAF4 802412C4 27BD0060 */   addiu    $sp, $sp, 0x60
