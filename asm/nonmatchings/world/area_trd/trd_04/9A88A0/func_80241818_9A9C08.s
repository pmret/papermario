.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241818_9A9C08
/* 9A9C08 80241818 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 9A9C0C 8024181C AFB40058 */  sw        $s4, 0x58($sp)
/* 9A9C10 80241820 0080A02D */  daddu     $s4, $a0, $zero
/* 9A9C14 80241824 AFBF0060 */  sw        $ra, 0x60($sp)
/* 9A9C18 80241828 AFB5005C */  sw        $s5, 0x5c($sp)
/* 9A9C1C 8024182C AFB30054 */  sw        $s3, 0x54($sp)
/* 9A9C20 80241830 AFB20050 */  sw        $s2, 0x50($sp)
/* 9A9C24 80241834 AFB1004C */  sw        $s1, 0x4c($sp)
/* 9A9C28 80241838 AFB00048 */  sw        $s0, 0x48($sp)
/* 9A9C2C 8024183C 8E910148 */  lw        $s1, 0x148($s4)
/* 9A9C30 80241840 86240008 */  lh        $a0, 8($s1)
/* 9A9C34 80241844 0C00EABB */  jal       get_npc_unsafe
/* 9A9C38 80241848 00A0802D */   daddu    $s0, $a1, $zero
/* 9A9C3C 8024184C 8E83000C */  lw        $v1, 0xc($s4)
/* 9A9C40 80241850 0280202D */  daddu     $a0, $s4, $zero
/* 9A9C44 80241854 8C650000 */  lw        $a1, ($v1)
/* 9A9C48 80241858 0C0B1EAF */  jal       get_variable
/* 9A9C4C 8024185C 0040902D */   daddu    $s2, $v0, $zero
/* 9A9C50 80241860 AFA00018 */  sw        $zero, 0x18($sp)
/* 9A9C54 80241864 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9C58 80241868 8C630094 */  lw        $v1, 0x94($v1)
/* 9A9C5C 8024186C AFA3001C */  sw        $v1, 0x1c($sp)
/* 9A9C60 80241870 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9C64 80241874 8C630080 */  lw        $v1, 0x80($v1)
/* 9A9C68 80241878 AFA30020 */  sw        $v1, 0x20($sp)
/* 9A9C6C 8024187C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9C70 80241880 8C630088 */  lw        $v1, 0x88($v1)
/* 9A9C74 80241884 AFA30024 */  sw        $v1, 0x24($sp)
/* 9A9C78 80241888 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9C7C 8024188C 8C63008C */  lw        $v1, 0x8c($v1)
/* 9A9C80 80241890 27B50018 */  addiu     $s5, $sp, 0x18
/* 9A9C84 80241894 AFA30028 */  sw        $v1, 0x28($sp)
/* 9A9C88 80241898 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9A9C8C 8024189C 3C014282 */  lui       $at, 0x4282
/* 9A9C90 802418A0 44810000 */  mtc1      $at, $f0
/* 9A9C94 802418A4 8C630090 */  lw        $v1, 0x90($v1)
/* 9A9C98 802418A8 0040982D */  daddu     $s3, $v0, $zero
/* 9A9C9C 802418AC E7A00030 */  swc1      $f0, 0x30($sp)
/* 9A9CA0 802418B0 A7A00034 */  sh        $zero, 0x34($sp)
/* 9A9CA4 802418B4 16000005 */  bnez      $s0, .L802418CC
/* 9A9CA8 802418B8 AFA3002C */   sw       $v1, 0x2c($sp)
/* 9A9CAC 802418BC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A9CB0 802418C0 30420004 */  andi      $v0, $v0, 4
/* 9A9CB4 802418C4 10400044 */  beqz      $v0, .L802419D8
/* 9A9CB8 802418C8 00000000 */   nop      
.L802418CC:
/* 9A9CBC 802418CC 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9A9CC0 802418D0 AE800070 */  sw        $zero, 0x70($s4)
/* 9A9CC4 802418D4 A640008E */  sh        $zero, 0x8e($s2)
/* 9A9CC8 802418D8 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9A9CCC 802418DC 8E430000 */  lw        $v1, ($s2)
/* 9A9CD0 802418E0 8C420000 */  lw        $v0, ($v0)
/* 9A9CD4 802418E4 00641824 */  and       $v1, $v1, $a0
/* 9A9CD8 802418E8 AE430000 */  sw        $v1, ($s2)
/* 9A9CDC 802418EC AE420028 */  sw        $v0, 0x28($s2)
/* 9A9CE0 802418F0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 9A9CE4 802418F4 8C420098 */  lw        $v0, 0x98($v0)
/* 9A9CE8 802418F8 54400005 */  bnel      $v0, $zero, .L80241910
/* 9A9CEC 802418FC 2402FDFF */   addiu    $v0, $zero, -0x201
/* 9A9CF0 80241900 34620200 */  ori       $v0, $v1, 0x200
/* 9A9CF4 80241904 2403FFF7 */  addiu     $v1, $zero, -9
/* 9A9CF8 80241908 08090646 */  j         .L80241918
/* 9A9CFC 8024190C 00431024 */   and      $v0, $v0, $v1
.L80241910:
/* 9A9D00 80241910 00621024 */  and       $v0, $v1, $v0
/* 9A9D04 80241914 34420008 */  ori       $v0, $v0, 8
.L80241918:
/* 9A9D08 80241918 AE420000 */  sw        $v0, ($s2)
/* 9A9D0C 8024191C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A9D10 80241920 30420004 */  andi      $v0, $v0, 4
/* 9A9D14 80241924 10400008 */  beqz      $v0, .L80241948
/* 9A9D18 80241928 24020063 */   addiu    $v0, $zero, 0x63
/* 9A9D1C 8024192C AE820070 */  sw        $v0, 0x70($s4)
/* 9A9D20 80241930 AE800074 */  sw        $zero, 0x74($s4)
/* 9A9D24 80241934 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9A9D28 80241938 2403FFFB */  addiu     $v1, $zero, -5
/* 9A9D2C 8024193C 00431024 */  and       $v0, $v0, $v1
/* 9A9D30 80241940 0809065D */  j         .L80241974
/* 9A9D34 80241944 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80241948:
/* 9A9D38 80241948 8E220000 */  lw        $v0, ($s1)
/* 9A9D3C 8024194C 3C034000 */  lui       $v1, 0x4000
/* 9A9D40 80241950 00431024 */  and       $v0, $v0, $v1
/* 9A9D44 80241954 10400007 */  beqz      $v0, .L80241974
/* 9A9D48 80241958 3C03BFFF */   lui      $v1, 0xbfff
/* 9A9D4C 8024195C 2402000C */  addiu     $v0, $zero, 0xc
/* 9A9D50 80241960 AE820070 */  sw        $v0, 0x70($s4)
/* 9A9D54 80241964 8E220000 */  lw        $v0, ($s1)
/* 9A9D58 80241968 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9A9D5C 8024196C 00431024 */  and       $v0, $v0, $v1
/* 9A9D60 80241970 AE220000 */  sw        $v0, ($s1)
.L80241974:
/* 9A9D64 80241974 27A50038 */  addiu     $a1, $sp, 0x38
/* 9A9D68 80241978 27A6003C */  addiu     $a2, $sp, 0x3c
/* 9A9D6C 8024197C C6400038 */  lwc1      $f0, 0x38($s2)
/* 9A9D70 80241980 864200A8 */  lh        $v0, 0xa8($s2)
/* 9A9D74 80241984 3C0142C8 */  lui       $at, 0x42c8
/* 9A9D78 80241988 44812000 */  mtc1      $at, $f4
/* 9A9D7C 8024198C 44823000 */  mtc1      $v0, $f6
/* 9A9D80 80241990 00000000 */  nop       
/* 9A9D84 80241994 468031A0 */  cvt.s.w   $f6, $f6
/* 9A9D88 80241998 27A20044 */  addiu     $v0, $sp, 0x44
/* 9A9D8C 8024199C E7A00038 */  swc1      $f0, 0x38($sp)
/* 9A9D90 802419A0 C640003C */  lwc1      $f0, 0x3c($s2)
/* 9A9D94 802419A4 C6420040 */  lwc1      $f2, 0x40($s2)
/* 9A9D98 802419A8 46060000 */  add.s     $f0, $f0, $f6
/* 9A9D9C 802419AC E7A40044 */  swc1      $f4, 0x44($sp)
/* 9A9DA0 802419B0 E7A20040 */  swc1      $f2, 0x40($sp)
/* 9A9DA4 802419B4 E7A0003C */  swc1      $f0, 0x3c($sp)
/* 9A9DA8 802419B8 AFA20010 */  sw        $v0, 0x10($sp)
/* 9A9DAC 802419BC 8E440080 */  lw        $a0, 0x80($s2)
/* 9A9DB0 802419C0 0C0372DF */  jal       func_800DCB7C
/* 9A9DB4 802419C4 27A70040 */   addiu    $a3, $sp, 0x40
/* 9A9DB8 802419C8 10400003 */  beqz      $v0, .L802419D8
/* 9A9DBC 802419CC 00000000 */   nop      
/* 9A9DC0 802419D0 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* 9A9DC4 802419D4 E640003C */  swc1      $f0, 0x3c($s2)
.L802419D8:
/* 9A9DC8 802419D8 8E830070 */  lw        $v1, 0x70($s4)
/* 9A9DCC 802419DC 2C620064 */  sltiu     $v0, $v1, 0x64
/* 9A9DD0 802419E0 10400042 */  beqz      $v0, .L80241AEC
/* 9A9DD4 802419E4 00031080 */   sll      $v0, $v1, 2
/* 9A9DD8 802419E8 3C018024 */  lui       $at, 0x8024
/* 9A9DDC 802419EC 00220821 */  addu      $at, $at, $v0
/* 9A9DE0 802419F0 8C225F50 */  lw        $v0, 0x5f50($at)
/* 9A9DE4 802419F4 00400008 */  jr        $v0
/* 9A9DE8 802419F8 00000000 */   nop      
/* 9A9DEC 802419FC 0280202D */  daddu     $a0, $s4, $zero
/* 9A9DF0 80241A00 0260282D */  daddu     $a1, $s3, $zero
/* 9A9DF4 80241A04 0C090321 */  jal       func_80240C84_9A9074
/* 9A9DF8 80241A08 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9DFC 80241A0C 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E00 80241A10 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E04 80241A14 0C090377 */  jal       func_80240DDC_9A91CC
/* 9A9E08 80241A18 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E0C 80241A1C 080906BB */  j         .L80241AEC
/* 9A9E10 80241A20 00000000 */   nop      
/* 9A9E14 80241A24 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E18 80241A28 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E1C 80241A2C 0C090421 */  jal       UnkNpcAIFunc1
/* 9A9E20 80241A30 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E24 80241A34 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E28 80241A38 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E2C 80241A3C 0C090451 */  jal       func_80241144_9A9534
/* 9A9E30 80241A40 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E34 80241A44 080906BB */  j         .L80241AEC
/* 9A9E38 80241A48 00000000 */   nop      
/* 9A9E3C 80241A4C 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E40 80241A50 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E44 80241A54 0C0904C0 */  jal       func_80241300_9A96F0
/* 9A9E48 80241A58 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E4C 80241A5C 080906BB */  j         .L80241AEC
/* 9A9E50 80241A60 00000000 */   nop      
/* 9A9E54 80241A64 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E58 80241A68 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E5C 80241A6C 0C0904ED */  jal       func_802413B4_9A97A4
/* 9A9E60 80241A70 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E64 80241A74 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E68 80241A78 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E6C 80241A7C 0C09050A */  jal       func_80241428_9A9818
/* 9A9E70 80241A80 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E74 80241A84 080906BB */  j         .L80241AEC
/* 9A9E78 80241A88 00000000 */   nop      
/* 9A9E7C 80241A8C 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E80 80241A90 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E84 80241A94 0C090528 */  jal       func_802414A0_9A9890
/* 9A9E88 80241A98 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E8C 80241A9C 0280202D */  daddu     $a0, $s4, $zero
/* 9A9E90 80241AA0 0260282D */  daddu     $a1, $s3, $zero
/* 9A9E94 80241AA4 0C090574 */  jal       func_802415D0_9A99C0
/* 9A9E98 80241AA8 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9E9C 80241AAC 080906BB */  j         .L80241AEC
/* 9A9EA0 80241AB0 00000000 */   nop      
/* 9A9EA4 80241AB4 0280202D */  daddu     $a0, $s4, $zero
/* 9A9EA8 80241AB8 0260282D */  daddu     $a1, $s3, $zero
/* 9A9EAC 80241ABC 0C0905BC */  jal       func_802416F0_9A9AE0
/* 9A9EB0 80241AC0 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9EB4 80241AC4 080906BB */  j         .L80241AEC
/* 9A9EB8 80241AC8 00000000 */   nop      
/* 9A9EBC 80241ACC 0280202D */  daddu     $a0, $s4, $zero
/* 9A9EC0 80241AD0 0260282D */  daddu     $a1, $s3, $zero
/* 9A9EC4 80241AD4 0C0905D6 */  jal       func_80241758_9A9B48
/* 9A9EC8 80241AD8 02A0302D */   daddu    $a2, $s5, $zero
/* 9A9ECC 80241ADC 080906BB */  j         .L80241AEC
/* 9A9ED0 80241AE0 00000000 */   nop      
/* 9A9ED4 80241AE4 0C0129CF */  jal       func_8004A73C
/* 9A9ED8 80241AE8 0280202D */   daddu    $a0, $s4, $zero
.L80241AEC:
/* 9A9EDC 80241AEC 8FBF0060 */  lw        $ra, 0x60($sp)
/* 9A9EE0 80241AF0 8FB5005C */  lw        $s5, 0x5c($sp)
/* 9A9EE4 80241AF4 8FB40058 */  lw        $s4, 0x58($sp)
/* 9A9EE8 80241AF8 8FB30054 */  lw        $s3, 0x54($sp)
/* 9A9EEC 80241AFC 8FB20050 */  lw        $s2, 0x50($sp)
/* 9A9EF0 80241B00 8FB1004C */  lw        $s1, 0x4c($sp)
/* 9A9EF4 80241B04 8FB00048 */  lw        $s0, 0x48($sp)
/* 9A9EF8 80241B08 0000102D */  daddu     $v0, $zero, $zero
/* 9A9EFC 80241B0C 03E00008 */  jr        $ra
/* 9A9F00 80241B10 27BD0068 */   addiu    $sp, $sp, 0x68
