.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A9B44
/* 41E8D4 802A9B44 3C03800E */  lui       $v1, %hi(gBattleStatus+0x46C)
/* 41E8D8 802A9B48 8C63C4DC */  lw        $v1, %lo(gBattleStatus+0x46C)($v1)
/* 41E8DC 802A9B4C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 41E8E0 802A9B50 AFB20018 */  sw        $s2, 0x18($sp)
/* 41E8E4 802A9B54 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 41E8E8 802A9B58 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 41E8EC 802A9B5C AFBF001C */  sw        $ra, 0x1c($sp)
/* 41E8F0 802A9B60 AFB10014 */  sw        $s1, 0x14($sp)
/* 41E8F4 802A9B64 AFB00010 */  sw        $s0, 0x10($sp)
/* 41E8F8 802A9B68 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 41E8FC 802A9B6C F7B60028 */  sdc1      $f22, 0x28($sp)
/* 41E900 802A9B70 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 41E904 802A9B74 8E5000D8 */  lw        $s0, 0xd8($s2)
/* 41E908 802A9B78 8E5100DC */  lw        $s1, 0xdc($s2)
/* 41E90C 802A9B7C 2C62000C */  sltiu     $v0, $v1, 0xc
/* 41E910 802A9B80 1040012D */  beqz      $v0, .L802AA038
/* 41E914 802A9B84 00031080 */   sll      $v0, $v1, 2
/* 41E918 802A9B88 3C01802B */  lui       $at, 0x802b
/* 41E91C 802A9B8C 00220821 */  addu      $at, $at, $v0
/* 41E920 802A9B90 8C22CBB0 */  lw        $v0, -0x3450($at)
/* 41E924 802A9B94 00400008 */  jr        $v0
/* 41E928 802A9B98 00000000 */   nop      
/* 41E92C 802A9B9C 0C093903 */  jal       func_8024E40C
/* 41E930 802A9BA0 24040002 */   addiu    $a0, $zero, 2
/* 41E934 802A9BA4 0C093936 */  jal       move_cam_over
/* 41E938 802A9BA8 2404000A */   addiu    $a0, $zero, 0xa
/* 41E93C 802A9BAC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 41E940 802A9BB0 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 41E944 802A9BB4 3C030010 */  lui       $v1, 0x10
/* 41E948 802A9BB8 00431024 */  and       $v0, $v0, $v1
/* 41E94C 802A9BBC 14400003 */  bnez      $v0, .L802A9BCC
/* 41E950 802A9BC0 2402000A */   addiu    $v0, $zero, 0xa
/* 41E954 802A9BC4 080AA80C */  j         .L802AA030
/* 41E958 802A9BC8 2402000B */   addiu    $v0, $zero, 0xb
.L802A9BCC:
/* 41E95C 802A9BCC C6000138 */  lwc1      $f0, 0x138($s0)
/* 41E960 802A9BD0 C6020140 */  lwc1      $f2, 0x140($s0)
/* 41E964 802A9BD4 E600000C */  swc1      $f0, 0xc($s0)
/* 41E968 802A9BD8 E6020014 */  swc1      $f2, 0x14($s0)
/* 41E96C 802A9BDC C6200138 */  lwc1      $f0, 0x138($s1)
/* 41E970 802A9BE0 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E974 802A9BE4 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41E978 802A9BE8 E6000018 */  swc1      $f0, 0x18($s0)
/* 41E97C 802A9BEC C6200140 */  lwc1      $f0, 0x140($s1)
/* 41E980 802A9BF0 24020004 */  addiu     $v0, $zero, 4
/* 41E984 802A9BF4 A6020070 */  sh        $v0, 0x70($s0)
/* 41E988 802A9BF8 AE000054 */  sw        $zero, 0x54($s0)
/* 41E98C 802A9BFC 080AA80E */  j         .L802AA038
/* 41E990 802A9C00 E6000020 */   swc1     $f0, 0x20($s0)
/* 41E994 802A9C04 86020070 */  lh        $v0, 0x70($s0)
/* 41E998 802A9C08 10400022 */  beqz      $v0, .L802A9C94
/* 41E99C 802A9C0C 00000000 */   nop      
/* 41E9A0 802A9C10 C6000018 */  lwc1      $f0, 0x18($s0)
/* 41E9A4 802A9C14 C6080144 */  lwc1      $f8, 0x144($s0)
/* 41E9A8 802A9C18 C6020020 */  lwc1      $f2, 0x20($s0)
/* 41E9AC 802A9C1C 46080001 */  sub.s     $f0, $f0, $f8
/* 41E9B0 802A9C20 C604014C */  lwc1      $f4, 0x14c($s0)
/* 41E9B4 802A9C24 46041081 */  sub.s     $f2, $f2, $f4
/* 41E9B8 802A9C28 44823000 */  mtc1      $v0, $f6
/* 41E9BC 802A9C2C 00000000 */  nop       
/* 41E9C0 802A9C30 468031A0 */  cvt.s.w   $f6, $f6
/* 41E9C4 802A9C34 46060003 */  div.s     $f0, $f0, $f6
/* 41E9C8 802A9C38 46004200 */  add.s     $f8, $f8, $f0
/* 41E9CC 802A9C3C 46003006 */  mov.s     $f0, $f6
/* 41E9D0 802A9C40 46061083 */  div.s     $f2, $f2, $f6
/* 41E9D4 802A9C44 C600000C */  lwc1      $f0, 0xc($s0)
/* 41E9D8 802A9C48 46022100 */  add.s     $f4, $f4, $f2
/* 41E9DC 802A9C4C E6080144 */  swc1      $f8, 0x144($s0)
/* 41E9E0 802A9C50 E604014C */  swc1      $f4, 0x14c($s0)
/* 41E9E4 802A9C54 C6240144 */  lwc1      $f4, 0x144($s1)
/* 41E9E8 802A9C58 46040001 */  sub.s     $f0, $f0, $f4
/* 41E9EC 802A9C5C 46003086 */  mov.s     $f2, $f6
/* 41E9F0 802A9C60 46060003 */  div.s     $f0, $f0, $f6
/* 41E9F4 802A9C64 46002100 */  add.s     $f4, $f4, $f0
/* 41E9F8 802A9C68 E6240144 */  swc1      $f4, 0x144($s1)
/* 41E9FC 802A9C6C C6000014 */  lwc1      $f0, 0x14($s0)
/* 41EA00 802A9C70 C624014C */  lwc1      $f4, 0x14c($s1)
/* 41EA04 802A9C74 86020070 */  lh        $v0, 0x70($s0)
/* 41EA08 802A9C78 46040001 */  sub.s     $f0, $f0, $f4
/* 41EA0C 802A9C7C 44821000 */  mtc1      $v0, $f2
/* 41EA10 802A9C80 00000000 */  nop       
/* 41EA14 802A9C84 468010A0 */  cvt.s.w   $f2, $f2
/* 41EA18 802A9C88 46020003 */  div.s     $f0, $f0, $f2
/* 41EA1C 802A9C8C 46002100 */  add.s     $f4, $f4, $f0
/* 41EA20 802A9C90 E624014C */  swc1      $f4, 0x14c($s1)
.L802A9C94:
/* 41EA24 802A9C94 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41EA28 802A9C98 3C0140C9 */  lui       $at, 0x40c9
/* 41EA2C 802A9C9C 34210FD0 */  ori       $at, $at, 0xfd0
/* 41EA30 802A9CA0 4481B000 */  mtc1      $at, $f22
/* 41EA34 802A9CA4 00000000 */  nop       
/* 41EA38 802A9CA8 46166302 */  mul.s     $f12, $f12, $f22
/* 41EA3C 802A9CAC 00000000 */  nop       
/* 41EA40 802A9CB0 3C0143B4 */  lui       $at, 0x43b4
/* 41EA44 802A9CB4 4481C000 */  mtc1      $at, $f24
/* 41EA48 802A9CB8 3C014180 */  lui       $at, 0x4180
/* 41EA4C 802A9CBC 4481A000 */  mtc1      $at, $f20
/* 41EA50 802A9CC0 0C00A85B */  jal       sin_rad
/* 41EA54 802A9CC4 46186303 */   div.s    $f12, $f12, $f24
/* 41EA58 802A9CC8 46140002 */  mul.s     $f0, $f0, $f20
/* 41EA5C 802A9CCC 00000000 */  nop       
/* 41EA60 802A9CD0 C602014C */  lwc1      $f2, 0x14c($s0)
/* 41EA64 802A9CD4 46001081 */  sub.s     $f2, $f2, $f0
/* 41EA68 802A9CD8 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41EA6C 802A9CDC 46006307 */  neg.s     $f12, $f12
/* 41EA70 802A9CE0 0C00A6C9 */  jal       clamp_angle
/* 41EA74 802A9CE4 E602014C */   swc1     $f2, 0x14c($s0)
/* 41EA78 802A9CE8 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41EA7C 802A9CEC 46166302 */  mul.s     $f12, $f12, $f22
/* 41EA80 802A9CF0 00000000 */  nop       
/* 41EA84 802A9CF4 E600018C */  swc1      $f0, 0x18c($s0)
/* 41EA88 802A9CF8 0C00A85B */  jal       sin_rad
/* 41EA8C 802A9CFC 46186303 */   div.s    $f12, $f12, $f24
/* 41EA90 802A9D00 46140002 */  mul.s     $f0, $f0, $f20
/* 41EA94 802A9D04 00000000 */  nop       
/* 41EA98 802A9D08 C622014C */  lwc1      $f2, 0x14c($s1)
/* 41EA9C 802A9D0C 46001080 */  add.s     $f2, $f2, $f0
/* 41EAA0 802A9D10 E622014C */  swc1      $f2, 0x14c($s1)
/* 41EAA4 802A9D14 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41EAA8 802A9D18 0C00A6C9 */  jal       clamp_angle
/* 41EAAC 802A9D1C 46006307 */   neg.s    $f12, $f12
/* 41EAB0 802A9D20 E620018C */  swc1      $f0, 0x18c($s1)
/* 41EAB4 802A9D24 C6000054 */  lwc1      $f0, 0x54($s0)
/* 41EAB8 802A9D28 3C0142B4 */  lui       $at, 0x42b4
/* 41EABC 802A9D2C 44811000 */  mtc1      $at, $f2
/* 41EAC0 802A9D30 86020070 */  lh        $v0, 0x70($s0)
/* 41EAC4 802A9D34 46020000 */  add.s     $f0, $f0, $f2
/* 41EAC8 802A9D38 96030070 */  lhu       $v1, 0x70($s0)
/* 41EACC 802A9D3C 10400004 */  beqz      $v0, .L802A9D50
/* 41EAD0 802A9D40 E6000054 */   swc1     $f0, 0x54($s0)
/* 41EAD4 802A9D44 2462FFFF */  addiu     $v0, $v1, -1
/* 41EAD8 802A9D48 080AA80E */  j         .L802AA038
/* 41EADC 802A9D4C A6020070 */   sh       $v0, 0x70($s0)
.L802A9D50:
/* 41EAE0 802A9D50 C6000018 */  lwc1      $f0, 0x18($s0)
/* 41EAE4 802A9D54 C6020020 */  lwc1      $f2, 0x20($s0)
/* 41EAE8 802A9D58 C604000C */  lwc1      $f4, 0xc($s0)
/* 41EAEC 802A9D5C E6000144 */  swc1      $f0, 0x144($s0)
/* 41EAF0 802A9D60 E602014C */  swc1      $f2, 0x14c($s0)
/* 41EAF4 802A9D64 E6240144 */  swc1      $f4, 0x144($s1)
/* 41EAF8 802A9D68 C6000014 */  lwc1      $f0, 0x14($s0)
/* 41EAFC 802A9D6C E620014C */  swc1      $f0, 0x14c($s1)
/* 41EB00 802A9D70 C6000144 */  lwc1      $f0, 0x144($s0)
/* 41EB04 802A9D74 C602014C */  lwc1      $f2, 0x14c($s0)
/* 41EB08 802A9D78 3C04FFEF */  lui       $a0, 0xffef
/* 41EB0C 802A9D7C E6000138 */  swc1      $f0, 0x138($s0)
/* 41EB10 802A9D80 E6020140 */  swc1      $f2, 0x140($s0)
/* 41EB14 802A9D84 C6200144 */  lwc1      $f0, 0x144($s1)
/* 41EB18 802A9D88 C622014C */  lwc1      $f2, 0x14c($s1)
/* 41EB1C 802A9D8C 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 41EB20 802A9D90 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 41EB24 802A9D94 E6200138 */  swc1      $f0, 0x138($s1)
/* 41EB28 802A9D98 E6220140 */  swc1      $f2, 0x140($s1)
/* 41EB2C 802A9D9C 8C620000 */  lw        $v0, ($v1)
/* 41EB30 802A9DA0 3484FFFF */  ori       $a0, $a0, 0xffff
/* 41EB34 802A9DA4 00441024 */  and       $v0, $v0, $a0
/* 41EB38 802A9DA8 AC620000 */  sw        $v0, ($v1)
/* 41EB3C 802A9DAC 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 41EB40 802A9DB0 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 41EB44 802A9DB4 8C620000 */  lw        $v0, ($v1)
/* 41EB48 802A9DB8 3C04FBFF */  lui       $a0, 0xfbff
/* 41EB4C 802A9DBC 34420002 */  ori       $v0, $v0, 2
/* 41EB50 802A9DC0 AC620000 */  sw        $v0, ($v1)
/* 41EB54 802A9DC4 8E020000 */  lw        $v0, ($s0)
/* 41EB58 802A9DC8 3484FFFF */  ori       $a0, $a0, 0xffff
/* 41EB5C 802A9DCC 00441024 */  and       $v0, $v0, $a0
/* 41EB60 802A9DD0 3C040800 */  lui       $a0, 0x800
/* 41EB64 802A9DD4 00441025 */  or        $v0, $v0, $a0
/* 41EB68 802A9DD8 12200006 */  beqz      $s1, .L802A9DF4
/* 41EB6C 802A9DDC AE020000 */   sw       $v0, ($s0)
/* 41EB70 802A9DE0 8E220000 */  lw        $v0, ($s1)
/* 41EB74 802A9DE4 3C030400 */  lui       $v1, 0x400
/* 41EB78 802A9DE8 00431025 */  or        $v0, $v0, $v1
/* 41EB7C 802A9DEC 00441025 */  or        $v0, $v0, $a0
/* 41EB80 802A9DF0 AE220000 */  sw        $v0, ($s1)
.L802A9DF4:
/* 41EB84 802A9DF4 24020008 */  addiu     $v0, $zero, 8
/* 41EB88 802A9DF8 3C07802B */  lui       $a3, 0x802b
/* 41EB8C 802A9DFC 24E7D0D0 */  addiu     $a3, $a3, -0x2f30
/* 41EB90 802A9E00 A640017C */  sh        $zero, 0x17c($s2)
/* 41EB94 802A9E04 3C01802B */  lui       $at, 0x802b
/* 41EB98 802A9E08 AC22D0B8 */  sw        $v0, -0x2f48($at)
/* 41EB9C 802A9E0C 24020001 */  addiu     $v0, $zero, 1
/* 41EBA0 802A9E10 3C08802B */  lui       $t0, 0x802b
/* 41EBA4 802A9E14 2508D0E8 */  addiu     $t0, $t0, -0x2f18
/* 41EBA8 802A9E18 3C06802B */  lui       $a2, 0x802b
/* 41EBAC 802A9E1C 24C6B720 */  addiu     $a2, $a2, -0x48e0
/* 41EBB0 802A9E20 3C05802B */  lui       $a1, 0x802b
/* 41EBB4 802A9E24 24A5D078 */  addiu     $a1, $a1, -0x2f88
/* 41EBB8 802A9E28 ACE20000 */  sw        $v0, ($a3)
/* 41EBBC 802A9E2C AD000000 */  sw        $zero, ($t0)
/* 41EBC0 802A9E30 8CC30000 */  lw        $v1, ($a2)
/* 41EBC4 802A9E34 96420070 */  lhu       $v0, 0x70($s2)
/* 41EBC8 802A9E38 3C04802B */  lui       $a0, 0x802b
/* 41EBCC 802A9E3C 8C84B728 */  lw        $a0, -0x48d8($a0)
/* 41EBD0 802A9E40 30420100 */  andi      $v0, $v0, 0x100
/* 41EBD4 802A9E44 ACA30000 */  sw        $v1, ($a1)
/* 41EBD8 802A9E48 3C01802B */  lui       $at, 0x802b
/* 41EBDC 802A9E4C AC24D090 */  sw        $a0, -0x2f70($at)
/* 41EBE0 802A9E50 14400006 */  bnez      $v0, .L802A9E6C
/* 41EBE4 802A9E54 0000882D */   daddu    $s1, $zero, $zero
/* 41EBE8 802A9E58 ACE00000 */  sw        $zero, ($a3)
/* 41EBEC 802A9E5C 8CC30004 */  lw        $v1, 4($a2)
/* 41EBF0 802A9E60 24020048 */  addiu     $v0, $zero, 0x48
/* 41EBF4 802A9E64 AD020000 */  sw        $v0, ($t0)
/* 41EBF8 802A9E68 ACA30000 */  sw        $v1, ($a1)
.L802A9E6C:
/* 41EBFC 802A9E6C 0C0AA6CC */  jal       func_802A9B30
/* 41EC00 802A9E70 24100001 */   addiu    $s0, $zero, 1
/* 41EC04 802A9E74 10400005 */  beqz      $v0, .L802A9E8C
/* 41EC08 802A9E78 24020002 */   addiu    $v0, $zero, 2
/* 41EC0C 802A9E7C 3C01802B */  lui       $at, 0x802b
/* 41EC10 802A9E80 AC30D104 */  sw        $s0, -0x2efc($at)
/* 41EC14 802A9E84 080AA7A6 */  j         .L802A9E98
/* 41EC18 802A9E88 00511023 */   subu     $v0, $v0, $s1
.L802A9E8C:
/* 41EC1C 802A9E8C 3C01802B */  lui       $at, 0x802b
/* 41EC20 802A9E90 AC20D104 */  sw        $zero, -0x2efc($at)
/* 41EC24 802A9E94 00511023 */  subu      $v0, $v0, $s1
.L802A9E98:
/* 41EC28 802A9E98 3C01802B */  lui       $at, 0x802b
/* 41EC2C 802A9E9C AC30D0AC */  sw        $s0, -0x2f54($at)
/* 41EC30 802A9EA0 3C01802B */  lui       $at, 0x802b
/* 41EC34 802A9EA4 AC20D0A8 */  sw        $zero, -0x2f58($at)
/* 41EC38 802A9EA8 3C01802B */  lui       $at, 0x802b
/* 41EC3C 802A9EAC AC20D0B0 */  sw        $zero, -0x2f50($at)
/* 41EC40 802A9EB0 3C01802B */  lui       $at, 0x802b
/* 41EC44 802A9EB4 AC22D100 */  sw        $v0, -0x2f00($at)
/* 41EC48 802A9EB8 0C0A8400 */  jal       func_802A1000
/* 41EC4C 802A9EBC 00000000 */   nop      
/* 41EC50 802A9EC0 24020008 */  addiu     $v0, $zero, 8
/* 41EC54 802A9EC4 3C01802B */  lui       $at, 0x802b
/* 41EC58 802A9EC8 AC22CC60 */  sw        $v0, -0x33a0($at)
/* 41EC5C 802A9ECC 080AA80C */  j         .L802AA030
/* 41EC60 802A9ED0 24020001 */   addiu    $v0, $zero, 1
/* 41EC64 802A9ED4 0000202D */  daddu     $a0, $zero, $zero
/* 41EC68 802A9ED8 0080282D */  daddu     $a1, $a0, $zero
/* 41EC6C 802A9EDC 3C06000C */  lui       $a2, 0xc
/* 41EC70 802A9EE0 0C098F3F */  jal       set_animation
/* 41EC74 802A9EE4 34C60009 */   ori      $a2, $a2, 9
/* 41EC78 802A9EE8 0C0A846C */  jal       func_802A11B0
/* 41EC7C 802A9EEC 00000000 */   nop      
/* 41EC80 802A9EF0 3C11802B */  lui       $s1, 0x802b
/* 41EC84 802A9EF4 2631CC60 */  addiu     $s1, $s1, -0x33a0
/* 41EC88 802A9EF8 8E230000 */  lw        $v1, ($s1)
/* 41EC8C 802A9EFC 10600004 */  beqz      $v1, .L802A9F10
/* 41EC90 802A9F00 0040802D */   daddu    $s0, $v0, $zero
/* 41EC94 802A9F04 2462FFFF */  addiu     $v0, $v1, -1
/* 41EC98 802A9F08 080AA80E */  j         .L802AA038
/* 41EC9C 802A9F0C AE220000 */   sw       $v0, ($s1)
.L802A9F10:
/* 41ECA0 802A9F10 12000049 */  beqz      $s0, .L802AA038
/* 41ECA4 802A9F14 0000202D */   daddu    $a0, $zero, $zero
/* 41ECA8 802A9F18 0080282D */  daddu     $a1, $a0, $zero
/* 41ECAC 802A9F1C 3C06000A */  lui       $a2, 0xa
/* 41ECB0 802A9F20 0C098F3F */  jal       set_animation
/* 41ECB4 802A9F24 34C60002 */   ori      $a2, $a2, 2
/* 41ECB8 802A9F28 2602FFFF */  addiu     $v0, $s0, -1
/* 41ECBC 802A9F2C 00021080 */  sll       $v0, $v0, 2
/* 41ECC0 802A9F30 3C01802B */  lui       $at, 0x802b
/* 41ECC4 802A9F34 00220821 */  addu      $at, $at, $v0
/* 41ECC8 802A9F38 9022D0BB */  lbu       $v0, -0x2f45($at)
/* 41ECCC 802A9F3C 0C0A840C */  jal       func_802A1030
/* 41ECD0 802A9F40 A2420048 */   sb       $v0, 0x48($s2)
/* 41ECD4 802A9F44 24020008 */  addiu     $v0, $zero, 8
/* 41ECD8 802A9F48 AE220000 */  sw        $v0, ($s1)
/* 41ECDC 802A9F4C 24020004 */  addiu     $v0, $zero, 4
/* 41ECE0 802A9F50 3C01802B */  lui       $at, 0x802b
/* 41ECE4 802A9F54 AC22CC6C */  sw        $v0, -0x3394($at)
/* 41ECE8 802A9F58 080AA80C */  j         .L802AA030
/* 41ECEC 802A9F5C 24020002 */   addiu    $v0, $zero, 2
/* 41ECF0 802A9F60 0C0A846C */  jal       func_802A11B0
/* 41ECF4 802A9F64 00000000 */   nop      
/* 41ECF8 802A9F68 10400033 */  beqz      $v0, .L802AA038
/* 41ECFC 802A9F6C 24040011 */   addiu    $a0, $zero, 0x11
/* 41ED00 802A9F70 24020004 */  addiu     $v0, $zero, 4
/* 41ED04 802A9F74 A642006C */  sh        $v0, 0x6c($s2)
/* 41ED08 802A9F78 24020005 */  addiu     $v0, $zero, 5
/* 41ED0C 802A9F7C A642006E */  sh        $v0, 0x6e($s2)
/* 41ED10 802A9F80 24020008 */  addiu     $v0, $zero, 8
/* 41ED14 802A9F84 A2420178 */  sb        $v0, 0x178($s2)
/* 41ED18 802A9F88 24020081 */  addiu     $v0, $zero, 0x81
/* 41ED1C 802A9F8C A642017C */  sh        $v0, 0x17c($s2)
/* 41ED20 802A9F90 3C038009 */  lui       $v1, 0x8009
/* 41ED24 802A9F94 8C63FA78 */  lw        $v1, -0x588($v1)
/* 41ED28 802A9F98 2402000A */  addiu     $v0, $zero, 0xa
/* 41ED2C 802A9F9C A642017A */  sh        $v0, 0x17a($s2)
/* 41ED30 802A9FA0 0C090464 */  jal       func_80241190
/* 41ED34 802A9FA4 AE430184 */   sw       $v1, 0x184($s2)
/* 41ED38 802A9FA8 080AA80E */  j         .L802AA038
/* 41ED3C 802A9FAC 00000000 */   nop      
/* 41ED40 802A9FB0 0C0A8414 */  jal       func_802A1050
/* 41ED44 802A9FB4 00000000 */   nop      
/* 41ED48 802A9FB8 24020001 */  addiu     $v0, $zero, 1
/* 41ED4C 802A9FBC 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41ED50 802A9FC0 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41ED54 802A9FC4 0C0AA6D1 */  jal       func_802A9B44
/* 41ED58 802A9FC8 00000000 */   nop      
/* 41ED5C 802A9FCC 0C0AA6D1 */  jal       func_802A9B44
/* 41ED60 802A9FD0 00000000 */   nop      
/* 41ED64 802A9FD4 080AA80E */  j         .L802AA038
/* 41ED68 802A9FD8 00000000 */   nop      
/* 41ED6C 802A9FDC 0C0A842E */  jal       func_802A10B8
/* 41ED70 802A9FE0 00000000 */   nop      
/* 41ED74 802A9FE4 080AA80E */  j         .L802AA038
/* 41ED78 802A9FE8 00000000 */   nop      
/* 41ED7C 802A9FEC 24040050 */  addiu     $a0, $zero, 0x50
/* 41ED80 802A9FF0 2405003C */  addiu     $a1, $zero, 0x3c
/* 41ED84 802A9FF4 0C093E81 */  jal       show_variable_battle_message
/* 41ED88 802A9FF8 0000302D */   daddu    $a2, $zero, $zero
/* 41ED8C 802A9FFC 24020001 */  addiu     $v0, $zero, 1
/* 41ED90 802AA000 3C01802B */  lui       $at, 0x802b
/* 41ED94 802AA004 A022D607 */  sb        $v0, -0x29f9($at)
/* 41ED98 802AA008 080AA80C */  j         .L802AA030
/* 41ED9C 802AA00C 24020009 */   addiu    $v0, $zero, 9
/* 41EDA0 802AA010 0C093EAD */  jal       is_popup_displayed
/* 41EDA4 802AA014 00000000 */   nop      
/* 41EDA8 802AA018 14400007 */  bnez      $v0, .L802AA038
/* 41EDAC 802AA01C 24020001 */   addiu    $v0, $zero, 1
/* 41EDB0 802AA020 3C01802B */  lui       $at, 0x802b
/* 41EDB4 802AA024 A020D607 */  sb        $zero, -0x29f9($at)
/* 41EDB8 802AA028 3C01802B */  lui       $at, 0x802b
/* 41EDBC 802AA02C AC20CC60 */  sw        $zero, -0x33a0($at)
.L802AA030:
/* 41EDC0 802AA030 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41EDC4 802AA034 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
.L802AA038:
/* 41EDC8 802AA038 8FBF001C */  lw        $ra, 0x1c($sp)
/* 41EDCC 802AA03C 8FB20018 */  lw        $s2, 0x18($sp)
/* 41EDD0 802AA040 8FB10014 */  lw        $s1, 0x14($sp)
/* 41EDD4 802AA044 8FB00010 */  lw        $s0, 0x10($sp)
/* 41EDD8 802AA048 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 41EDDC 802AA04C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 41EDE0 802AA050 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 41EDE4 802AA054 03E00008 */  jr        $ra
/* 41EDE8 802AA058 27BD0038 */   addiu    $sp, $sp, 0x38
