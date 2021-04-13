.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD4_C9EAF4
/* C9EAF4 80240BD4 27BDFF98 */  addiu     $sp, $sp, -0x68
/* C9EAF8 80240BD8 AFB40058 */  sw        $s4, 0x58($sp)
/* C9EAFC 80240BDC 0080A02D */  daddu     $s4, $a0, $zero
/* C9EB00 80240BE0 AFBF0060 */  sw        $ra, 0x60($sp)
/* C9EB04 80240BE4 AFB5005C */  sw        $s5, 0x5c($sp)
/* C9EB08 80240BE8 AFB30054 */  sw        $s3, 0x54($sp)
/* C9EB0C 80240BEC AFB20050 */  sw        $s2, 0x50($sp)
/* C9EB10 80240BF0 AFB1004C */  sw        $s1, 0x4c($sp)
/* C9EB14 80240BF4 AFB00048 */  sw        $s0, 0x48($sp)
/* C9EB18 80240BF8 8E910148 */  lw        $s1, 0x148($s4)
/* C9EB1C 80240BFC 86240008 */  lh        $a0, 8($s1)
/* C9EB20 80240C00 0C00EABB */  jal       get_npc_unsafe
/* C9EB24 80240C04 00A0802D */   daddu    $s0, $a1, $zero
/* C9EB28 80240C08 8E83000C */  lw        $v1, 0xc($s4)
/* C9EB2C 80240C0C 0280202D */  daddu     $a0, $s4, $zero
/* C9EB30 80240C10 8C650000 */  lw        $a1, ($v1)
/* C9EB34 80240C14 0C0B1EAF */  jal       get_variable
/* C9EB38 80240C18 0040902D */   daddu    $s2, $v0, $zero
/* C9EB3C 80240C1C AFA00018 */  sw        $zero, 0x18($sp)
/* C9EB40 80240C20 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C9EB44 80240C24 8C630094 */  lw        $v1, 0x94($v1)
/* C9EB48 80240C28 AFA3001C */  sw        $v1, 0x1c($sp)
/* C9EB4C 80240C2C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C9EB50 80240C30 8C630080 */  lw        $v1, 0x80($v1)
/* C9EB54 80240C34 AFA30020 */  sw        $v1, 0x20($sp)
/* C9EB58 80240C38 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C9EB5C 80240C3C 8C630088 */  lw        $v1, 0x88($v1)
/* C9EB60 80240C40 AFA30024 */  sw        $v1, 0x24($sp)
/* C9EB64 80240C44 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C9EB68 80240C48 8C63008C */  lw        $v1, 0x8c($v1)
/* C9EB6C 80240C4C 27B50018 */  addiu     $s5, $sp, 0x18
/* C9EB70 80240C50 AFA30028 */  sw        $v1, 0x28($sp)
/* C9EB74 80240C54 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C9EB78 80240C58 3C014282 */  lui       $at, 0x4282
/* C9EB7C 80240C5C 44810000 */  mtc1      $at, $f0
/* C9EB80 80240C60 8C630090 */  lw        $v1, 0x90($v1)
/* C9EB84 80240C64 0040982D */  daddu     $s3, $v0, $zero
/* C9EB88 80240C68 E7A00030 */  swc1      $f0, 0x30($sp)
/* C9EB8C 80240C6C A7A00034 */  sh        $zero, 0x34($sp)
/* C9EB90 80240C70 16000005 */  bnez      $s0, .L80240C88
/* C9EB94 80240C74 AFA3002C */   sw       $v1, 0x2c($sp)
/* C9EB98 80240C78 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C9EB9C 80240C7C 30420004 */  andi      $v0, $v0, 4
/* C9EBA0 80240C80 10400044 */  beqz      $v0, .L80240D94
/* C9EBA4 80240C84 00000000 */   nop
.L80240C88:
/* C9EBA8 80240C88 2404F7FF */  addiu     $a0, $zero, -0x801
/* C9EBAC 80240C8C AE800070 */  sw        $zero, 0x70($s4)
/* C9EBB0 80240C90 A640008E */  sh        $zero, 0x8e($s2)
/* C9EBB4 80240C94 8E2200CC */  lw        $v0, 0xcc($s1)
/* C9EBB8 80240C98 8E430000 */  lw        $v1, ($s2)
/* C9EBBC 80240C9C 8C420000 */  lw        $v0, ($v0)
/* C9EBC0 80240CA0 00641824 */  and       $v1, $v1, $a0
/* C9EBC4 80240CA4 AE430000 */  sw        $v1, ($s2)
/* C9EBC8 80240CA8 AE420028 */  sw        $v0, 0x28($s2)
/* C9EBCC 80240CAC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C9EBD0 80240CB0 8C420098 */  lw        $v0, 0x98($v0)
/* C9EBD4 80240CB4 54400005 */  bnel      $v0, $zero, .L80240CCC
/* C9EBD8 80240CB8 2402FDFF */   addiu    $v0, $zero, -0x201
/* C9EBDC 80240CBC 34620200 */  ori       $v0, $v1, 0x200
/* C9EBE0 80240CC0 2403FFF7 */  addiu     $v1, $zero, -9
/* C9EBE4 80240CC4 08090335 */  j         .L80240CD4
/* C9EBE8 80240CC8 00431024 */   and      $v0, $v0, $v1
.L80240CCC:
/* C9EBEC 80240CCC 00621024 */  and       $v0, $v1, $v0
/* C9EBF0 80240CD0 34420008 */  ori       $v0, $v0, 8
.L80240CD4:
/* C9EBF4 80240CD4 AE420000 */  sw        $v0, ($s2)
/* C9EBF8 80240CD8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C9EBFC 80240CDC 30420004 */  andi      $v0, $v0, 4
/* C9EC00 80240CE0 10400008 */  beqz      $v0, .L80240D04
/* C9EC04 80240CE4 24020063 */   addiu    $v0, $zero, 0x63
/* C9EC08 80240CE8 AE820070 */  sw        $v0, 0x70($s4)
/* C9EC0C 80240CEC AE800074 */  sw        $zero, 0x74($s4)
/* C9EC10 80240CF0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C9EC14 80240CF4 2403FFFB */  addiu     $v1, $zero, -5
/* C9EC18 80240CF8 00431024 */  and       $v0, $v0, $v1
/* C9EC1C 80240CFC 0809034C */  j         .L80240D30
/* C9EC20 80240D00 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240D04:
/* C9EC24 80240D04 8E220000 */  lw        $v0, ($s1)
/* C9EC28 80240D08 3C034000 */  lui       $v1, 0x4000
/* C9EC2C 80240D0C 00431024 */  and       $v0, $v0, $v1
/* C9EC30 80240D10 10400007 */  beqz      $v0, .L80240D30
/* C9EC34 80240D14 3C03BFFF */   lui      $v1, 0xbfff
/* C9EC38 80240D18 2402000C */  addiu     $v0, $zero, 0xc
/* C9EC3C 80240D1C AE820070 */  sw        $v0, 0x70($s4)
/* C9EC40 80240D20 8E220000 */  lw        $v0, ($s1)
/* C9EC44 80240D24 3463FFFF */  ori       $v1, $v1, 0xffff
/* C9EC48 80240D28 00431024 */  and       $v0, $v0, $v1
/* C9EC4C 80240D2C AE220000 */  sw        $v0, ($s1)
.L80240D30:
/* C9EC50 80240D30 27A50038 */  addiu     $a1, $sp, 0x38
/* C9EC54 80240D34 27A6003C */  addiu     $a2, $sp, 0x3c
/* C9EC58 80240D38 C6400038 */  lwc1      $f0, 0x38($s2)
/* C9EC5C 80240D3C 864200A8 */  lh        $v0, 0xa8($s2)
/* C9EC60 80240D40 3C0142C8 */  lui       $at, 0x42c8
/* C9EC64 80240D44 44812000 */  mtc1      $at, $f4
/* C9EC68 80240D48 44823000 */  mtc1      $v0, $f6
/* C9EC6C 80240D4C 00000000 */  nop
/* C9EC70 80240D50 468031A0 */  cvt.s.w   $f6, $f6
/* C9EC74 80240D54 27A20044 */  addiu     $v0, $sp, 0x44
/* C9EC78 80240D58 E7A00038 */  swc1      $f0, 0x38($sp)
/* C9EC7C 80240D5C C640003C */  lwc1      $f0, 0x3c($s2)
/* C9EC80 80240D60 C6420040 */  lwc1      $f2, 0x40($s2)
/* C9EC84 80240D64 46060000 */  add.s     $f0, $f0, $f6
/* C9EC88 80240D68 E7A40044 */  swc1      $f4, 0x44($sp)
/* C9EC8C 80240D6C E7A20040 */  swc1      $f2, 0x40($sp)
/* C9EC90 80240D70 E7A0003C */  swc1      $f0, 0x3c($sp)
/* C9EC94 80240D74 AFA20010 */  sw        $v0, 0x10($sp)
/* C9EC98 80240D78 8E440080 */  lw        $a0, 0x80($s2)
/* C9EC9C 80240D7C 0C0372DF */  jal       func_800DCB7C
/* C9ECA0 80240D80 27A70040 */   addiu    $a3, $sp, 0x40
/* C9ECA4 80240D84 10400003 */  beqz      $v0, .L80240D94
/* C9ECA8 80240D88 00000000 */   nop
/* C9ECAC 80240D8C C7A0003C */  lwc1      $f0, 0x3c($sp)
/* C9ECB0 80240D90 E640003C */  swc1      $f0, 0x3c($s2)
.L80240D94:
/* C9ECB4 80240D94 8E830070 */  lw        $v1, 0x70($s4)
/* C9ECB8 80240D98 2C620064 */  sltiu     $v0, $v1, 0x64
/* C9ECBC 80240D9C 10400042 */  beqz      $v0, L80240EA8_C9EDC8
/* C9ECC0 80240DA0 00031080 */   sll      $v0, $v1, 2
/* C9ECC4 80240DA4 3C018025 */  lui       $at, %hi(jtbl_802491D0_CA70F0)
/* C9ECC8 80240DA8 00220821 */  addu      $at, $at, $v0
/* C9ECCC 80240DAC 8C2291D0 */  lw        $v0, %lo(jtbl_802491D0_CA70F0)($at)
/* C9ECD0 80240DB0 00400008 */  jr        $v0
/* C9ECD4 80240DB4 00000000 */   nop
glabel L80240DB8_C9ECD8
/* C9ECD8 80240DB8 0280202D */  daddu     $a0, $s4, $zero
/* C9ECDC 80240DBC 0260282D */  daddu     $a1, $s3, $zero
/* C9ECE0 80240DC0 0C090010 */  jal       func_80240040_C9DF60
/* C9ECE4 80240DC4 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DC8_C9ECE8
/* C9ECE8 80240DC8 0280202D */  daddu     $a0, $s4, $zero
/* C9ECEC 80240DCC 0260282D */  daddu     $a1, $s3, $zero
/* C9ECF0 80240DD0 0C090066 */  jal       flo_00_UnkFunc13
/* C9ECF4 80240DD4 02A0302D */   daddu    $a2, $s5, $zero
/* C9ECF8 80240DD8 080903AA */  j         L80240EA8_C9EDC8
/* C9ECFC 80240DDC 00000000 */   nop
glabel L80240DE0_C9ED00
/* C9ED00 80240DE0 0280202D */  daddu     $a0, $s4, $zero
/* C9ED04 80240DE4 0260282D */  daddu     $a1, $s3, $zero
/* C9ED08 80240DE8 0C090110 */  jal       flo_00_UnkNpcAIFunc1
/* C9ED0C 80240DEC 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240DF0_C9ED10
/* C9ED10 80240DF0 0280202D */  daddu     $a0, $s4, $zero
/* C9ED14 80240DF4 0260282D */  daddu     $a1, $s3, $zero
/* C9ED18 80240DF8 0C090140 */  jal       flo_00_UnkFunc14
/* C9ED1C 80240DFC 02A0302D */   daddu    $a2, $s5, $zero
/* C9ED20 80240E00 080903AA */  j         L80240EA8_C9EDC8
/* C9ED24 80240E04 00000000 */   nop
glabel L80240E08_C9ED28
/* C9ED28 80240E08 0280202D */  daddu     $a0, $s4, $zero
/* C9ED2C 80240E0C 0260282D */  daddu     $a1, $s3, $zero
/* C9ED30 80240E10 0C0901AF */  jal       func_802406BC_C9E5DC
/* C9ED34 80240E14 02A0302D */   daddu    $a2, $s5, $zero
/* C9ED38 80240E18 080903AA */  j         L80240EA8_C9EDC8
/* C9ED3C 80240E1C 00000000 */   nop
glabel L80240E20_C9ED40
/* C9ED40 80240E20 0280202D */  daddu     $a0, $s4, $zero
/* C9ED44 80240E24 0260282D */  daddu     $a1, $s3, $zero
/* C9ED48 80240E28 0C0901DC */  jal       flo_00_NpcJumpFunc2
/* C9ED4C 80240E2C 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240E30_C9ED50
/* C9ED50 80240E30 0280202D */  daddu     $a0, $s4, $zero
/* C9ED54 80240E34 0260282D */  daddu     $a1, $s3, $zero
/* C9ED58 80240E38 0C0901F9 */  jal       flo_00_NpcJumpFunc
/* C9ED5C 80240E3C 02A0302D */   daddu    $a2, $s5, $zero
/* C9ED60 80240E40 080903AA */  j         L80240EA8_C9EDC8
/* C9ED64 80240E44 00000000 */   nop
glabel L80240E48_C9ED68
/* C9ED68 80240E48 0280202D */  daddu     $a0, $s4, $zero
/* C9ED6C 80240E4C 0260282D */  daddu     $a1, $s3, $zero
/* C9ED70 80240E50 0C090217 */  jal       flo_00_UnkNpcAIFunc13
/* C9ED74 80240E54 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240E58_C9ED78
/* C9ED78 80240E58 0280202D */  daddu     $a0, $s4, $zero
/* C9ED7C 80240E5C 0260282D */  daddu     $a1, $s3, $zero
/* C9ED80 80240E60 0C090263 */  jal       flo_00_UnkFunc15
/* C9ED84 80240E64 02A0302D */   daddu    $a2, $s5, $zero
/* C9ED88 80240E68 080903AA */  j         L80240EA8_C9EDC8
/* C9ED8C 80240E6C 00000000 */   nop
glabel L80240E70_C9ED90
/* C9ED90 80240E70 0280202D */  daddu     $a0, $s4, $zero
/* C9ED94 80240E74 0260282D */  daddu     $a1, $s3, $zero
/* C9ED98 80240E78 0C0902AB */  jal       flo_00_UnkNpcDurationFlagFunc
/* C9ED9C 80240E7C 02A0302D */   daddu    $a2, $s5, $zero
/* C9EDA0 80240E80 080903AA */  j         L80240EA8_C9EDC8
/* C9EDA4 80240E84 00000000 */   nop
glabel L80240E88_C9EDA8
/* C9EDA8 80240E88 0280202D */  daddu     $a0, $s4, $zero
/* C9EDAC 80240E8C 0260282D */  daddu     $a1, $s3, $zero
/* C9EDB0 80240E90 0C0902C5 */  jal       flo_00_UnkFunc16
/* C9EDB4 80240E94 02A0302D */   daddu    $a2, $s5, $zero
/* C9EDB8 80240E98 080903AA */  j         L80240EA8_C9EDC8
/* C9EDBC 80240E9C 00000000 */   nop
glabel L80240EA0_C9EDC0
/* C9EDC0 80240EA0 0C0129CF */  jal       func_8004A73C
/* C9EDC4 80240EA4 0280202D */   daddu    $a0, $s4, $zero
glabel L80240EA8_C9EDC8
/* C9EDC8 80240EA8 8FBF0060 */  lw        $ra, 0x60($sp)
/* C9EDCC 80240EAC 8FB5005C */  lw        $s5, 0x5c($sp)
/* C9EDD0 80240EB0 8FB40058 */  lw        $s4, 0x58($sp)
/* C9EDD4 80240EB4 8FB30054 */  lw        $s3, 0x54($sp)
/* C9EDD8 80240EB8 8FB20050 */  lw        $s2, 0x50($sp)
/* C9EDDC 80240EBC 8FB1004C */  lw        $s1, 0x4c($sp)
/* C9EDE0 80240EC0 8FB00048 */  lw        $s0, 0x48($sp)
/* C9EDE4 80240EC4 0000102D */  daddu     $v0, $zero, $zero
/* C9EDE8 80240EC8 03E00008 */  jr        $ra
/* C9EDEC 80240ECC 27BD0068 */   addiu    $sp, $sp, 0x68
