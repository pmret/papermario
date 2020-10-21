.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AF0_A6FED0
/* A6FED0 80241AF0 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A6FED4 80241AF4 AFB40048 */  sw        $s4, 0x48($sp)
/* A6FED8 80241AF8 0080A02D */  daddu     $s4, $a0, $zero
/* A6FEDC 80241AFC AFBF004C */  sw        $ra, 0x4c($sp)
/* A6FEE0 80241B00 AFB30044 */  sw        $s3, 0x44($sp)
/* A6FEE4 80241B04 AFB20040 */  sw        $s2, 0x40($sp)
/* A6FEE8 80241B08 AFB1003C */  sw        $s1, 0x3c($sp)
/* A6FEEC 80241B0C AFB00038 */  sw        $s0, 0x38($sp)
/* A6FEF0 80241B10 F7B40050 */  sdc1      $f20, 0x50($sp)
/* A6FEF4 80241B14 8E910148 */  lw        $s1, 0x148($s4)
/* A6FEF8 80241B18 00A0902D */  daddu     $s2, $a1, $zero
/* A6FEFC 80241B1C 86240008 */  lh        $a0, 8($s1)
/* A6FF00 80241B20 0C00EABB */  jal       get_npc_unsafe
/* A6FF04 80241B24 00C0982D */   daddu    $s3, $a2, $zero
/* A6FF08 80241B28 0040802D */  daddu     $s0, $v0, $zero
/* A6FF0C 80241B2C 9602008E */  lhu       $v0, 0x8e($s0)
/* A6FF10 80241B30 2442FFFF */  addiu     $v0, $v0, -1
/* A6FF14 80241B34 A602008E */  sh        $v0, 0x8e($s0)
/* A6FF18 80241B38 00021400 */  sll       $v0, $v0, 0x10
/* A6FF1C 80241B3C 14400021 */  bnez      $v0, .L80241BC4
/* A6FF20 80241B40 0280202D */   daddu    $a0, $s4, $zero
/* A6FF24 80241B44 24040002 */  addiu     $a0, $zero, 2
/* A6FF28 80241B48 0200282D */  daddu     $a1, $s0, $zero
/* A6FF2C 80241B4C 0000302D */  daddu     $a2, $zero, $zero
/* A6FF30 80241B50 8E2200CC */  lw        $v0, 0xcc($s1)
/* A6FF34 80241B54 3C013F80 */  lui       $at, 0x3f80
/* A6FF38 80241B58 44810000 */  mtc1      $at, $f0
/* A6FF3C 80241B5C 3C014000 */  lui       $at, 0x4000
/* A6FF40 80241B60 44811000 */  mtc1      $at, $f2
/* A6FF44 80241B64 8C430000 */  lw        $v1, ($v0)
/* A6FF48 80241B68 860200A8 */  lh        $v0, 0xa8($s0)
/* A6FF4C 80241B6C 3C01C1A0 */  lui       $at, 0xc1a0
/* A6FF50 80241B70 44812000 */  mtc1      $at, $f4
/* A6FF54 80241B74 44824000 */  mtc1      $v0, $f8
/* A6FF58 80241B78 00000000 */  nop       
/* A6FF5C 80241B7C 46804220 */  cvt.s.w   $f8, $f8
/* A6FF60 80241B80 44074000 */  mfc1      $a3, $f8
/* A6FF64 80241B84 2402000C */  addiu     $v0, $zero, 0xc
/* A6FF68 80241B88 AE030028 */  sw        $v1, 0x28($s0)
/* A6FF6C 80241B8C AFA2001C */  sw        $v0, 0x1c($sp)
/* A6FF70 80241B90 27A20028 */  addiu     $v0, $sp, 0x28
/* A6FF74 80241B94 E7A00010 */  swc1      $f0, 0x10($sp)
/* A6FF78 80241B98 E7A20014 */  swc1      $f2, 0x14($sp)
/* A6FF7C 80241B9C E7A40018 */  swc1      $f4, 0x18($sp)
/* A6FF80 80241BA0 0C01BFA4 */  jal       fx_emote
/* A6FF84 80241BA4 AFA20020 */   sw       $v0, 0x20($sp)
/* A6FF88 80241BA8 8E2200CC */  lw        $v0, 0xcc($s1)
/* A6FF8C 80241BAC 8C430000 */  lw        $v1, ($v0)
/* A6FF90 80241BB0 2402000F */  addiu     $v0, $zero, 0xf
/* A6FF94 80241BB4 A602008E */  sh        $v0, 0x8e($s0)
/* A6FF98 80241BB8 24020032 */  addiu     $v0, $zero, 0x32
/* A6FF9C 80241BBC 08090725 */  j         .L80241C94
/* A6FFA0 80241BC0 AE030028 */   sw       $v1, 0x28($s0)
.L80241BC4:
/* A6FFA4 80241BC4 8E450024 */  lw        $a1, 0x24($s2)
/* A6FFA8 80241BC8 8E460028 */  lw        $a2, 0x28($s2)
/* A6FFAC 80241BCC 0C0902B9 */  jal       func_80240AE4_A6EEC4
/* A6FFB0 80241BD0 0260382D */   daddu    $a3, $s3, $zero
/* A6FFB4 80241BD4 24030001 */  addiu     $v1, $zero, 1
/* A6FFB8 80241BD8 1443002F */  bne       $v0, $v1, .L80241C98
/* A6FFBC 80241BDC 00000000 */   nop      
/* A6FFC0 80241BE0 8602008C */  lh        $v0, 0x8c($s0)
/* A6FFC4 80241BE4 1440002C */  bnez      $v0, .L80241C98
/* A6FFC8 80241BE8 0200202D */   daddu    $a0, $s0, $zero
/* A6FFCC 80241BEC 240520D4 */  addiu     $a1, $zero, 0x20d4
/* A6FFD0 80241BF0 0C012530 */  jal       func_800494C0
/* A6FFD4 80241BF4 0000302D */   daddu    $a2, $zero, $zero
/* A6FFD8 80241BF8 27A4002C */  addiu     $a0, $sp, 0x2c
/* A6FFDC 80241BFC 27A50030 */  addiu     $a1, $sp, 0x30
/* A6FFE0 80241C00 3C0641F0 */  lui       $a2, 0x41f0
/* A6FFE4 80241C04 C6020034 */  lwc1      $f2, 0x34($s0)
/* A6FFE8 80241C08 3C014387 */  lui       $at, 0x4387
/* A6FFEC 80241C0C 44810000 */  mtc1      $at, $f0
/* A6FFF0 80241C10 8E2200CC */  lw        $v0, 0xcc($s1)
/* A6FFF4 80241C14 C614003C */  lwc1      $f20, 0x3c($s0)
/* A6FFF8 80241C18 46020001 */  sub.s     $f0, $f0, $f2
/* A6FFFC 80241C1C 3C0141E8 */  lui       $at, 0x41e8
/* A70000 80241C20 44812000 */  mtc1      $at, $f4
/* A70004 80241C24 C6060038 */  lwc1      $f6, 0x38($s0)
/* A70008 80241C28 4604A500 */  add.s     $f20, $f20, $f4
/* A7000C 80241C2C 3C013F80 */  lui       $at, 0x3f80
/* A70010 80241C30 44811000 */  mtc1      $at, $f2
/* A70014 80241C34 44070000 */  mfc1      $a3, $f0
/* A70018 80241C38 C6000040 */  lwc1      $f0, 0x40($s0)
/* A7001C 80241C3C 8C420020 */  lw        $v0, 0x20($v0)
/* A70020 80241C40 46020000 */  add.s     $f0, $f0, $f2
/* A70024 80241C44 E7A6002C */  swc1      $f6, 0x2c($sp)
/* A70028 80241C48 AE020028 */  sw        $v0, 0x28($s0)
/* A7002C 80241C4C 0C00A7E7 */  jal       add_vec2D_polar
/* A70030 80241C50 E7A00030 */   swc1     $f0, 0x30($sp)
/* A70034 80241C54 0000202D */  daddu     $a0, $zero, $zero
/* A70038 80241C58 4406A000 */  mfc1      $a2, $f20
/* A7003C 80241C5C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A70040 80241C60 C7A20030 */  lwc1      $f2, 0x30($sp)
/* A70044 80241C64 44050000 */  mfc1      $a1, $f0
/* A70048 80241C68 44071000 */  mfc1      $a3, $f2
/* A7004C 80241C6C 3C013DCC */  lui       $at, 0x3dcc
/* A70050 80241C70 3421CCCD */  ori       $at, $at, 0xcccd
/* A70054 80241C74 44810000 */  mtc1      $at, $f0
/* A70058 80241C78 2402000D */  addiu     $v0, $zero, 0xd
/* A7005C 80241C7C AFA20014 */  sw        $v0, 0x14($sp)
/* A70060 80241C80 0C01BFEC */  jal       func_8006FFB0
/* A70064 80241C84 E7A00010 */   swc1     $f0, 0x10($sp)
/* A70068 80241C88 2402000F */  addiu     $v0, $zero, 0xf
/* A7006C 80241C8C A602008E */  sh        $v0, 0x8e($s0)
/* A70070 80241C90 24020016 */  addiu     $v0, $zero, 0x16
.L80241C94:
/* A70074 80241C94 AE820070 */  sw        $v0, 0x70($s4)
.L80241C98:
/* A70078 80241C98 8FBF004C */  lw        $ra, 0x4c($sp)
/* A7007C 80241C9C 8FB40048 */  lw        $s4, 0x48($sp)
/* A70080 80241CA0 8FB30044 */  lw        $s3, 0x44($sp)
/* A70084 80241CA4 8FB20040 */  lw        $s2, 0x40($sp)
/* A70088 80241CA8 8FB1003C */  lw        $s1, 0x3c($sp)
/* A7008C 80241CAC 8FB00038 */  lw        $s0, 0x38($sp)
/* A70090 80241CB0 D7B40050 */  ldc1      $f20, 0x50($sp)
/* A70094 80241CB4 03E00008 */  jr        $ra
/* A70098 80241CB8 27BD0058 */   addiu    $sp, $sp, 0x58
