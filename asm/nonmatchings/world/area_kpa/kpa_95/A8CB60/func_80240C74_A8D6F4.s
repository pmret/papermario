.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C74_A8D6F4
/* A8D6F4 80240C74 27BDFF98 */  addiu     $sp, $sp, -0x68
/* A8D6F8 80240C78 AFB40058 */  sw        $s4, 0x58($sp)
/* A8D6FC 80240C7C 0080A02D */  daddu     $s4, $a0, $zero
/* A8D700 80240C80 AFBF0060 */  sw        $ra, 0x60($sp)
/* A8D704 80240C84 AFB5005C */  sw        $s5, 0x5c($sp)
/* A8D708 80240C88 AFB30054 */  sw        $s3, 0x54($sp)
/* A8D70C 80240C8C AFB20050 */  sw        $s2, 0x50($sp)
/* A8D710 80240C90 AFB1004C */  sw        $s1, 0x4c($sp)
/* A8D714 80240C94 AFB00048 */  sw        $s0, 0x48($sp)
/* A8D718 80240C98 8E910148 */  lw        $s1, 0x148($s4)
/* A8D71C 80240C9C 86240008 */  lh        $a0, 8($s1)
/* A8D720 80240CA0 0C00EABB */  jal       get_npc_unsafe
/* A8D724 80240CA4 00A0802D */   daddu    $s0, $a1, $zero
/* A8D728 80240CA8 8E83000C */  lw        $v1, 0xc($s4)
/* A8D72C 80240CAC 0280202D */  daddu     $a0, $s4, $zero
/* A8D730 80240CB0 8C650000 */  lw        $a1, ($v1)
/* A8D734 80240CB4 0C0B1EAF */  jal       get_variable
/* A8D738 80240CB8 0040902D */   daddu    $s2, $v0, $zero
/* A8D73C 80240CBC AFA00018 */  sw        $zero, 0x18($sp)
/* A8D740 80240CC0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8D744 80240CC4 8C630094 */  lw        $v1, 0x94($v1)
/* A8D748 80240CC8 AFA3001C */  sw        $v1, 0x1c($sp)
/* A8D74C 80240CCC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8D750 80240CD0 8C630080 */  lw        $v1, 0x80($v1)
/* A8D754 80240CD4 AFA30020 */  sw        $v1, 0x20($sp)
/* A8D758 80240CD8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8D75C 80240CDC 8C630088 */  lw        $v1, 0x88($v1)
/* A8D760 80240CE0 AFA30024 */  sw        $v1, 0x24($sp)
/* A8D764 80240CE4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8D768 80240CE8 8C63008C */  lw        $v1, 0x8c($v1)
/* A8D76C 80240CEC 27B50018 */  addiu     $s5, $sp, 0x18
/* A8D770 80240CF0 AFA30028 */  sw        $v1, 0x28($sp)
/* A8D774 80240CF4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* A8D778 80240CF8 3C014282 */  lui       $at, 0x4282
/* A8D77C 80240CFC 44810000 */  mtc1      $at, $f0
/* A8D780 80240D00 8C630090 */  lw        $v1, 0x90($v1)
/* A8D784 80240D04 0040982D */  daddu     $s3, $v0, $zero
/* A8D788 80240D08 E7A00030 */  swc1      $f0, 0x30($sp)
/* A8D78C 80240D0C A7A00034 */  sh        $zero, 0x34($sp)
/* A8D790 80240D10 16000005 */  bnez      $s0, .L80240D28
/* A8D794 80240D14 AFA3002C */   sw       $v1, 0x2c($sp)
/* A8D798 80240D18 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A8D79C 80240D1C 30420004 */  andi      $v0, $v0, 4
/* A8D7A0 80240D20 10400044 */  beqz      $v0, .L80240E34
/* A8D7A4 80240D24 00000000 */   nop      
.L80240D28:
/* A8D7A8 80240D28 2404F7FF */  addiu     $a0, $zero, -0x801
/* A8D7AC 80240D2C AE800070 */  sw        $zero, 0x70($s4)
/* A8D7B0 80240D30 A640008E */  sh        $zero, 0x8e($s2)
/* A8D7B4 80240D34 8E2200CC */  lw        $v0, 0xcc($s1)
/* A8D7B8 80240D38 8E430000 */  lw        $v1, ($s2)
/* A8D7BC 80240D3C 8C420000 */  lw        $v0, ($v0)
/* A8D7C0 80240D40 00641824 */  and       $v1, $v1, $a0
/* A8D7C4 80240D44 AE430000 */  sw        $v1, ($s2)
/* A8D7C8 80240D48 AE420028 */  sw        $v0, 0x28($s2)
/* A8D7CC 80240D4C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* A8D7D0 80240D50 8C420098 */  lw        $v0, 0x98($v0)
/* A8D7D4 80240D54 54400005 */  bnel      $v0, $zero, .L80240D6C
/* A8D7D8 80240D58 2402FDFF */   addiu    $v0, $zero, -0x201
/* A8D7DC 80240D5C 34620200 */  ori       $v0, $v1, 0x200
/* A8D7E0 80240D60 2403FFF7 */  addiu     $v1, $zero, -9
/* A8D7E4 80240D64 0809035D */  j         .L80240D74
/* A8D7E8 80240D68 00431024 */   and      $v0, $v0, $v1
.L80240D6C:
/* A8D7EC 80240D6C 00621024 */  and       $v0, $v1, $v0
/* A8D7F0 80240D70 34420008 */  ori       $v0, $v0, 8
.L80240D74:
/* A8D7F4 80240D74 AE420000 */  sw        $v0, ($s2)
/* A8D7F8 80240D78 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A8D7FC 80240D7C 30420004 */  andi      $v0, $v0, 4
/* A8D800 80240D80 10400008 */  beqz      $v0, .L80240DA4
/* A8D804 80240D84 24020063 */   addiu    $v0, $zero, 0x63
/* A8D808 80240D88 AE820070 */  sw        $v0, 0x70($s4)
/* A8D80C 80240D8C AE800074 */  sw        $zero, 0x74($s4)
/* A8D810 80240D90 8E2200B0 */  lw        $v0, 0xb0($s1)
/* A8D814 80240D94 2403FFFB */  addiu     $v1, $zero, -5
/* A8D818 80240D98 00431024 */  and       $v0, $v0, $v1
/* A8D81C 80240D9C 08090374 */  j         .L80240DD0
/* A8D820 80240DA0 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240DA4:
/* A8D824 80240DA4 8E220000 */  lw        $v0, ($s1)
/* A8D828 80240DA8 3C034000 */  lui       $v1, 0x4000
/* A8D82C 80240DAC 00431024 */  and       $v0, $v0, $v1
/* A8D830 80240DB0 10400007 */  beqz      $v0, .L80240DD0
/* A8D834 80240DB4 3C03BFFF */   lui      $v1, 0xbfff
/* A8D838 80240DB8 2402000C */  addiu     $v0, $zero, 0xc
/* A8D83C 80240DBC AE820070 */  sw        $v0, 0x70($s4)
/* A8D840 80240DC0 8E220000 */  lw        $v0, ($s1)
/* A8D844 80240DC4 3463FFFF */  ori       $v1, $v1, 0xffff
/* A8D848 80240DC8 00431024 */  and       $v0, $v0, $v1
/* A8D84C 80240DCC AE220000 */  sw        $v0, ($s1)
.L80240DD0:
/* A8D850 80240DD0 27A50038 */  addiu     $a1, $sp, 0x38
/* A8D854 80240DD4 27A6003C */  addiu     $a2, $sp, 0x3c
/* A8D858 80240DD8 C6400038 */  lwc1      $f0, 0x38($s2)
/* A8D85C 80240DDC 864200A8 */  lh        $v0, 0xa8($s2)
/* A8D860 80240DE0 3C0142C8 */  lui       $at, 0x42c8
/* A8D864 80240DE4 44812000 */  mtc1      $at, $f4
/* A8D868 80240DE8 44823000 */  mtc1      $v0, $f6
/* A8D86C 80240DEC 00000000 */  nop       
/* A8D870 80240DF0 468031A0 */  cvt.s.w   $f6, $f6
/* A8D874 80240DF4 27A20044 */  addiu     $v0, $sp, 0x44
/* A8D878 80240DF8 E7A00038 */  swc1      $f0, 0x38($sp)
/* A8D87C 80240DFC C640003C */  lwc1      $f0, 0x3c($s2)
/* A8D880 80240E00 C6420040 */  lwc1      $f2, 0x40($s2)
/* A8D884 80240E04 46060000 */  add.s     $f0, $f0, $f6
/* A8D888 80240E08 E7A40044 */  swc1      $f4, 0x44($sp)
/* A8D88C 80240E0C E7A20040 */  swc1      $f2, 0x40($sp)
/* A8D890 80240E10 E7A0003C */  swc1      $f0, 0x3c($sp)
/* A8D894 80240E14 AFA20010 */  sw        $v0, 0x10($sp)
/* A8D898 80240E18 8E440080 */  lw        $a0, 0x80($s2)
/* A8D89C 80240E1C 0C0372DF */  jal       func_800DCB7C
/* A8D8A0 80240E20 27A70040 */   addiu    $a3, $sp, 0x40
/* A8D8A4 80240E24 10400003 */  beqz      $v0, .L80240E34
/* A8D8A8 80240E28 00000000 */   nop      
/* A8D8AC 80240E2C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* A8D8B0 80240E30 E640003C */  swc1      $f0, 0x3c($s2)
.L80240E34:
/* A8D8B4 80240E34 8E830070 */  lw        $v1, 0x70($s4)
/* A8D8B8 80240E38 2C620064 */  sltiu     $v0, $v1, 0x64
/* A8D8BC 80240E3C 10400042 */  beqz      $v0, .L80240F48
/* A8D8C0 80240E40 00031080 */   sll      $v0, $v1, 2
/* A8D8C4 80240E44 3C018024 */  lui       $at, %hi(D_80245A10)
/* A8D8C8 80240E48 00220821 */  addu      $at, $at, $v0
/* A8D8CC 80240E4C 8C225A10 */  lw        $v0, %lo(D_80245A10)($at)
/* A8D8D0 80240E50 00400008 */  jr        $v0
/* A8D8D4 80240E54 00000000 */   nop      
/* A8D8D8 80240E58 0280202D */  daddu     $a0, $s4, $zero
/* A8D8DC 80240E5C 0260282D */  daddu     $a1, $s3, $zero
/* A8D8E0 80240E60 0C090038 */  jal       func_802400E0_A8CB60
/* A8D8E4 80240E64 02A0302D */   daddu    $a2, $s5, $zero
/* A8D8E8 80240E68 0280202D */  daddu     $a0, $s4, $zero
/* A8D8EC 80240E6C 0260282D */  daddu     $a1, $s3, $zero
/* A8D8F0 80240E70 0C09008E */  jal       func_80240238_A8CCB8
/* A8D8F4 80240E74 02A0302D */   daddu    $a2, $s5, $zero
/* A8D8F8 80240E78 080903D2 */  j         .L80240F48
/* A8D8FC 80240E7C 00000000 */   nop      
/* A8D900 80240E80 0280202D */  daddu     $a0, $s4, $zero
/* A8D904 80240E84 0260282D */  daddu     $a1, $s3, $zero
/* A8D908 80240E88 0C090138 */  jal       kpa_95_UnkNpcAIFunc1
/* A8D90C 80240E8C 02A0302D */   daddu    $a2, $s5, $zero
/* A8D910 80240E90 0280202D */  daddu     $a0, $s4, $zero
/* A8D914 80240E94 0260282D */  daddu     $a1, $s3, $zero
/* A8D918 80240E98 0C090168 */  jal       func_802405A0_A8D020
/* A8D91C 80240E9C 02A0302D */   daddu    $a2, $s5, $zero
/* A8D920 80240EA0 080903D2 */  j         .L80240F48
/* A8D924 80240EA4 00000000 */   nop      
/* A8D928 80240EA8 0280202D */  daddu     $a0, $s4, $zero
/* A8D92C 80240EAC 0260282D */  daddu     $a1, $s3, $zero
/* A8D930 80240EB0 0C0901D7 */  jal       func_8024075C_A8D1DC
/* A8D934 80240EB4 02A0302D */   daddu    $a2, $s5, $zero
/* A8D938 80240EB8 080903D2 */  j         .L80240F48
/* A8D93C 80240EBC 00000000 */   nop      
/* A8D940 80240EC0 0280202D */  daddu     $a0, $s4, $zero
/* A8D944 80240EC4 0260282D */  daddu     $a1, $s3, $zero
/* A8D948 80240EC8 0C090204 */  jal       kpa_95_NpcJumpFunc2
/* A8D94C 80240ECC 02A0302D */   daddu    $a2, $s5, $zero
/* A8D950 80240ED0 0280202D */  daddu     $a0, $s4, $zero
/* A8D954 80240ED4 0260282D */  daddu     $a1, $s3, $zero
/* A8D958 80240ED8 0C090221 */  jal       kpa_95_NpcJumpFunc
/* A8D95C 80240EDC 02A0302D */   daddu    $a2, $s5, $zero
/* A8D960 80240EE0 080903D2 */  j         .L80240F48
/* A8D964 80240EE4 00000000 */   nop      
/* A8D968 80240EE8 0280202D */  daddu     $a0, $s4, $zero
/* A8D96C 80240EEC 0260282D */  daddu     $a1, $s3, $zero
/* A8D970 80240EF0 0C09023F */  jal       func_802408FC_A8D37C
/* A8D974 80240EF4 02A0302D */   daddu    $a2, $s5, $zero
/* A8D978 80240EF8 0280202D */  daddu     $a0, $s4, $zero
/* A8D97C 80240EFC 0260282D */  daddu     $a1, $s3, $zero
/* A8D980 80240F00 0C09028B */  jal       func_80240A2C_A8D4AC
/* A8D984 80240F04 02A0302D */   daddu    $a2, $s5, $zero
/* A8D988 80240F08 080903D2 */  j         .L80240F48
/* A8D98C 80240F0C 00000000 */   nop      
/* A8D990 80240F10 0280202D */  daddu     $a0, $s4, $zero
/* A8D994 80240F14 0260282D */  daddu     $a1, $s3, $zero
/* A8D998 80240F18 0C0902D3 */  jal       kpa_95_UnkNpcDurationFlagFunc
/* A8D99C 80240F1C 02A0302D */   daddu    $a2, $s5, $zero
/* A8D9A0 80240F20 080903D2 */  j         .L80240F48
/* A8D9A4 80240F24 00000000 */   nop      
/* A8D9A8 80240F28 0280202D */  daddu     $a0, $s4, $zero
/* A8D9AC 80240F2C 0260282D */  daddu     $a1, $s3, $zero
/* A8D9B0 80240F30 0C0902ED */  jal       func_80240BB4_A8D634
/* A8D9B4 80240F34 02A0302D */   daddu    $a2, $s5, $zero
/* A8D9B8 80240F38 080903D2 */  j         .L80240F48
/* A8D9BC 80240F3C 00000000 */   nop      
/* A8D9C0 80240F40 0C0129CF */  jal       func_8004A73C
/* A8D9C4 80240F44 0280202D */   daddu    $a0, $s4, $zero
.L80240F48:
/* A8D9C8 80240F48 8FBF0060 */  lw        $ra, 0x60($sp)
/* A8D9CC 80240F4C 8FB5005C */  lw        $s5, 0x5c($sp)
/* A8D9D0 80240F50 8FB40058 */  lw        $s4, 0x58($sp)
/* A8D9D4 80240F54 8FB30054 */  lw        $s3, 0x54($sp)
/* A8D9D8 80240F58 8FB20050 */  lw        $s2, 0x50($sp)
/* A8D9DC 80240F5C 8FB1004C */  lw        $s1, 0x4c($sp)
/* A8D9E0 80240F60 8FB00048 */  lw        $s0, 0x48($sp)
/* A8D9E4 80240F64 0000102D */  daddu     $v0, $zero, $zero
/* A8D9E8 80240F68 03E00008 */  jr        $ra
/* A8D9EC 80240F6C 27BD0068 */   addiu    $sp, $sp, 0x68
