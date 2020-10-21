.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF4_A618C4
/* A618C4 80240EF4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A618C8 80240EF8 AFB3003C */  sw        $s3, 0x3c($sp)
/* A618CC 80240EFC 0080982D */  daddu     $s3, $a0, $zero
/* A618D0 80240F00 AFBF0048 */  sw        $ra, 0x48($sp)
/* A618D4 80240F04 AFB50044 */  sw        $s5, 0x44($sp)
/* A618D8 80240F08 AFB40040 */  sw        $s4, 0x40($sp)
/* A618DC 80240F0C AFB20038 */  sw        $s2, 0x38($sp)
/* A618E0 80240F10 AFB10034 */  sw        $s1, 0x34($sp)
/* A618E4 80240F14 AFB00030 */  sw        $s0, 0x30($sp)
/* A618E8 80240F18 8E720148 */  lw        $s2, 0x148($s3)
/* A618EC 80240F1C 86440008 */  lh        $a0, 8($s2)
/* A618F0 80240F20 8E70000C */  lw        $s0, 0xc($s3)
/* A618F4 80240F24 0C00EABB */  jal       get_npc_unsafe
/* A618F8 80240F28 00A0882D */   daddu    $s1, $a1, $zero
/* A618FC 80240F2C 0260202D */  daddu     $a0, $s3, $zero
/* A61900 80240F30 8E050000 */  lw        $a1, ($s0)
/* A61904 80240F34 0C0B1EAF */  jal       get_variable
/* A61908 80240F38 0040A02D */   daddu    $s4, $v0, $zero
/* A6190C 80240F3C AFA00010 */  sw        $zero, 0x10($sp)
/* A61910 80240F40 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A61914 80240F44 8C630030 */  lw        $v1, 0x30($v1)
/* A61918 80240F48 AFA30014 */  sw        $v1, 0x14($sp)
/* A6191C 80240F4C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A61920 80240F50 8C63001C */  lw        $v1, 0x1c($v1)
/* A61924 80240F54 AFA30018 */  sw        $v1, 0x18($sp)
/* A61928 80240F58 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A6192C 80240F5C 8C630024 */  lw        $v1, 0x24($v1)
/* A61930 80240F60 AFA3001C */  sw        $v1, 0x1c($sp)
/* A61934 80240F64 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A61938 80240F68 8C630028 */  lw        $v1, 0x28($v1)
/* A6193C 80240F6C 27B50010 */  addiu     $s5, $sp, 0x10
/* A61940 80240F70 AFA30020 */  sw        $v1, 0x20($sp)
/* A61944 80240F74 8E4300D0 */  lw        $v1, 0xd0($s2)
/* A61948 80240F78 3C014220 */  lui       $at, 0x4220
/* A6194C 80240F7C 44810000 */  mtc1      $at, $f0
/* A61950 80240F80 8C63002C */  lw        $v1, 0x2c($v1)
/* A61954 80240F84 0040802D */  daddu     $s0, $v0, $zero
/* A61958 80240F88 E7A00028 */  swc1      $f0, 0x28($sp)
/* A6195C 80240F8C A7A0002C */  sh        $zero, 0x2c($sp)
/* A61960 80240F90 16200005 */  bnez      $s1, .L80240FA8
/* A61964 80240F94 AFA30024 */   sw       $v1, 0x24($sp)
/* A61968 80240F98 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A6196C 80240F9C 30420004 */  andi      $v0, $v0, 4
/* A61970 80240FA0 1040002F */  beqz      $v0, .L80241060
/* A61974 80240FA4 00000000 */   nop      
.L80240FA8:
/* A61978 80240FA8 2404F7FF */  addiu     $a0, $zero, -0x801
/* A6197C 80240FAC AE600070 */  sw        $zero, 0x70($s3)
/* A61980 80240FB0 A680008E */  sh        $zero, 0x8e($s4)
/* A61984 80240FB4 8E4200CC */  lw        $v0, 0xcc($s2)
/* A61988 80240FB8 8E830000 */  lw        $v1, ($s4)
/* A6198C 80240FBC 8C420000 */  lw        $v0, ($v0)
/* A61990 80240FC0 00641824 */  and       $v1, $v1, $a0
/* A61994 80240FC4 AE830000 */  sw        $v1, ($s4)
/* A61998 80240FC8 AE820028 */  sw        $v0, 0x28($s4)
/* A6199C 80240FCC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* A619A0 80240FD0 8C420034 */  lw        $v0, 0x34($v0)
/* A619A4 80240FD4 54400005 */  bnel      $v0, $zero, .L80240FEC
/* A619A8 80240FD8 2402FDFF */   addiu    $v0, $zero, -0x201
/* A619AC 80240FDC 34620200 */  ori       $v0, $v1, 0x200
/* A619B0 80240FE0 2403FFF7 */  addiu     $v1, $zero, -9
/* A619B4 80240FE4 080903FD */  j         .L80240FF4
/* A619B8 80240FE8 00431024 */   and      $v0, $v0, $v1
.L80240FEC:
/* A619BC 80240FEC 00621024 */  and       $v0, $v1, $v0
/* A619C0 80240FF0 34420008 */  ori       $v0, $v0, 8
.L80240FF4:
/* A619C4 80240FF4 AE820000 */  sw        $v0, ($s4)
/* A619C8 80240FF8 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A619CC 80240FFC 30420004 */  andi      $v0, $v0, 4
/* A619D0 80241000 10400008 */  beqz      $v0, .L80241024
/* A619D4 80241004 24020063 */   addiu    $v0, $zero, 0x63
/* A619D8 80241008 AE620070 */  sw        $v0, 0x70($s3)
/* A619DC 8024100C AE600074 */  sw        $zero, 0x74($s3)
/* A619E0 80241010 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A619E4 80241014 2403FFFB */  addiu     $v1, $zero, -5
/* A619E8 80241018 00431024 */  and       $v0, $v0, $v1
/* A619EC 8024101C 0809040F */  j         .L8024103C
/* A619F0 80241020 AE4200B0 */   sw       $v0, 0xb0($s2)
.L80241024:
/* A619F4 80241024 8E420000 */  lw        $v0, ($s2)
/* A619F8 80241028 3C034000 */  lui       $v1, 0x4000
/* A619FC 8024102C 00431024 */  and       $v0, $v0, $v1
/* A61A00 80241030 10400002 */  beqz      $v0, .L8024103C
/* A61A04 80241034 2402000C */   addiu    $v0, $zero, 0xc
/* A61A08 80241038 AE620070 */  sw        $v0, 0x70($s3)
.L8024103C:
/* A61A0C 8024103C 3C05BFFF */  lui       $a1, 0xbfff
/* A61A10 80241040 34A5FFFF */  ori       $a1, $a1, 0xffff
/* A61A14 80241044 2404FFFB */  addiu     $a0, $zero, -5
/* A61A18 80241048 8E4200B0 */  lw        $v0, 0xb0($s2)
/* A61A1C 8024104C 8E430000 */  lw        $v1, ($s2)
/* A61A20 80241050 00441024 */  and       $v0, $v0, $a0
/* A61A24 80241054 00651824 */  and       $v1, $v1, $a1
/* A61A28 80241058 AE4200B0 */  sw        $v0, 0xb0($s2)
/* A61A2C 8024105C AE430000 */  sw        $v1, ($s2)
.L80241060:
/* A61A30 80241060 8E630070 */  lw        $v1, 0x70($s3)
/* A61A34 80241064 2C620064 */  sltiu     $v0, $v1, 0x64
/* A61A38 80241068 10400060 */  beqz      $v0, .L802411EC
/* A61A3C 8024106C 00031080 */   sll      $v0, $v1, 2
/* A61A40 80241070 3C018024 */  lui       $at, 0x8024
/* A61A44 80241074 00220821 */  addu      $at, $at, $v0
/* A61A48 80241078 8C2234C8 */  lw        $v0, 0x34c8($at)
/* A61A4C 8024107C 00400008 */  jr        $v0
/* A61A50 80241080 00000000 */   nop      
/* A61A54 80241084 0260202D */  daddu     $a0, $s3, $zero
/* A61A58 80241088 0200282D */  daddu     $a1, $s0, $zero
/* A61A5C 8024108C 0C012568 */  jal       func_800495A0
/* A61A60 80241090 02A0302D */   daddu    $a2, $s5, $zero
/* A61A64 80241094 0260202D */  daddu     $a0, $s3, $zero
/* A61A68 80241098 0200282D */  daddu     $a1, $s0, $zero
/* A61A6C 8024109C 0C0125AE */  jal       func_800496B8
/* A61A70 802410A0 02A0302D */   daddu    $a2, $s5, $zero
/* A61A74 802410A4 0809047B */  j         .L802411EC
/* A61A78 802410A8 00000000 */   nop      
/* A61A7C 802410AC 0260202D */  daddu     $a0, $s3, $zero
/* A61A80 802410B0 0200282D */  daddu     $a1, $s0, $zero
/* A61A84 802410B4 0C0126D1 */  jal       func_80049B44
/* A61A88 802410B8 02A0302D */   daddu    $a2, $s5, $zero
/* A61A8C 802410BC 0260202D */  daddu     $a0, $s3, $zero
/* A61A90 802410C0 0200282D */  daddu     $a1, $s0, $zero
/* A61A94 802410C4 0C012701 */  jal       func_80049C04
/* A61A98 802410C8 02A0302D */   daddu    $a2, $s5, $zero
/* A61A9C 802410CC 0809047B */  j         .L802411EC
/* A61AA0 802410D0 00000000 */   nop      
/* A61AA4 802410D4 0260202D */  daddu     $a0, $s3, $zero
/* A61AA8 802410D8 0200282D */  daddu     $a1, $s0, $zero
/* A61AAC 802410DC 0C01278F */  jal       func_80049E3C
/* A61AB0 802410E0 02A0302D */   daddu    $a2, $s5, $zero
/* A61AB4 802410E4 0260202D */  daddu     $a0, $s3, $zero
/* A61AB8 802410E8 0200282D */  daddu     $a1, $s0, $zero
/* A61ABC 802410EC 0C0127B3 */  jal       func_80049ECC
/* A61AC0 802410F0 02A0302D */   daddu    $a2, $s5, $zero
/* A61AC4 802410F4 0809047B */  j         .L802411EC
/* A61AC8 802410F8 00000000 */   nop      
/* A61ACC 802410FC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A61AD0 80241100 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A61AD4 80241104 C68C0038 */  lwc1      $f12, 0x38($s4)
/* A61AD8 80241108 C68E0040 */  lwc1      $f14, 0x40($s4)
/* A61ADC 8024110C 8C460028 */  lw        $a2, 0x28($v0)
/* A61AE0 80241110 0C00A7B5 */  jal       dist2D
/* A61AE4 80241114 8C470030 */   lw       $a3, 0x30($v0)
/* A61AE8 80241118 8E42006C */  lw        $v0, 0x6c($s2)
/* A61AEC 8024111C 10400008 */  beqz      $v0, .L80241140
/* A61AF0 80241120 46000086 */   mov.s    $f2, $f0
/* A61AF4 80241124 44820000 */  mtc1      $v0, $f0
/* A61AF8 80241128 00000000 */  nop       
/* A61AFC 8024112C 46800020 */  cvt.s.w   $f0, $f0
/* A61B00 80241130 4602003C */  c.lt.s    $f0, $f2
/* A61B04 80241134 00000000 */  nop       
/* A61B08 80241138 4500000B */  bc1f      .L80241168
/* A61B0C 8024113C 0260202D */   daddu    $a0, $s3, $zero
.L80241140:
/* A61B10 80241140 0260202D */  daddu     $a0, $s3, $zero
/* A61B14 80241144 8E050024 */  lw        $a1, 0x24($s0)
/* A61B18 80241148 8E060028 */  lw        $a2, 0x28($s0)
/* A61B1C 8024114C 0C09007C */  jal       func_802401F0_A60BC0
/* A61B20 80241150 02A0382D */   daddu    $a3, $s5, $zero
/* A61B24 80241154 8E630070 */  lw        $v1, 0x70($s3)
/* A61B28 80241158 2402000C */  addiu     $v0, $zero, 0xc
/* A61B2C 8024115C 14620023 */  bne       $v1, $v0, .L802411EC
/* A61B30 80241160 00000000 */   nop      
/* A61B34 80241164 0260202D */  daddu     $a0, $s3, $zero
.L80241168:
/* A61B38 80241168 0200282D */  daddu     $a1, $s0, $zero
/* A61B3C 8024116C 0C0127DF */  jal       func_80049F7C
/* A61B40 80241170 02A0302D */   daddu    $a2, $s5, $zero
/* A61B44 80241174 0260202D */  daddu     $a0, $s3, $zero
/* A61B48 80241178 0200282D */  daddu     $a1, $s0, $zero
/* A61B4C 8024117C 0C012849 */  jal       func_8004A124
/* A61B50 80241180 02A0302D */   daddu    $a2, $s5, $zero
/* A61B54 80241184 0809047B */  j         .L802411EC
/* A61B58 80241188 00000000 */   nop      
/* A61B5C 8024118C 0260202D */  daddu     $a0, $s3, $zero
/* A61B60 80241190 0200282D */  daddu     $a1, $s0, $zero
/* A61B64 80241194 0C0128FA */  jal       func_8004A3E8
/* A61B68 80241198 02A0302D */   daddu    $a2, $s5, $zero
/* A61B6C 8024119C 0809047B */  j         .L802411EC
/* A61B70 802411A0 00000000 */   nop      
/* A61B74 802411A4 0C0900CD */  jal       func_80240334_A60D04
/* A61B78 802411A8 0260202D */   daddu    $a0, $s3, $zero
/* A61B7C 802411AC 0809047B */  j         .L802411EC
/* A61B80 802411B0 00000000 */   nop      
/* A61B84 802411B4 0C09010D */  jal       func_80240434_A60E04
/* A61B88 802411B8 0260202D */   daddu    $a0, $s3, $zero
/* A61B8C 802411BC 0809047B */  j         .L802411EC
/* A61B90 802411C0 00000000 */   nop      
/* A61B94 802411C4 0C09011E */  jal       func_80240478_A60E48
/* A61B98 802411C8 0260202D */   daddu    $a0, $s3, $zero
/* A61B9C 802411CC 0809047B */  j         .L802411EC
/* A61BA0 802411D0 00000000 */   nop      
/* A61BA4 802411D4 0C090146 */  jal       func_80240518_A60EE8
/* A61BA8 802411D8 0260202D */   daddu    $a0, $s3, $zero
/* A61BAC 802411DC 0809047B */  j         .L802411EC
/* A61BB0 802411E0 00000000 */   nop      
/* A61BB4 802411E4 0C0129CF */  jal       func_8004A73C
/* A61BB8 802411E8 0260202D */   daddu    $a0, $s3, $zero
.L802411EC:
/* A61BBC 802411EC 8FBF0048 */  lw        $ra, 0x48($sp)
/* A61BC0 802411F0 8FB50044 */  lw        $s5, 0x44($sp)
/* A61BC4 802411F4 8FB40040 */  lw        $s4, 0x40($sp)
/* A61BC8 802411F8 8FB3003C */  lw        $s3, 0x3c($sp)
/* A61BCC 802411FC 8FB20038 */  lw        $s2, 0x38($sp)
/* A61BD0 80241200 8FB10034 */  lw        $s1, 0x34($sp)
/* A61BD4 80241204 8FB00030 */  lw        $s0, 0x30($sp)
/* A61BD8 80241208 0000102D */  daddu     $v0, $zero, $zero
/* A61BDC 8024120C 03E00008 */  jr        $ra
/* A61BE0 80241210 27BD0050 */   addiu    $sp, $sp, 0x50
