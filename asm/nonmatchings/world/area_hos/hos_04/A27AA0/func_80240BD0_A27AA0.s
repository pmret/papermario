.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BD0_A27AA0
/* A27AA0 80240BD0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A27AA4 80240BD4 3C038024 */  lui       $v1, %hi(D_80243258_A2A128)
/* A27AA8 80240BD8 24633258 */  addiu     $v1, $v1, %lo(D_80243258_A2A128)
/* A27AAC 80240BDC AFBF0034 */  sw        $ra, 0x34($sp)
/* A27AB0 80240BE0 AFB20030 */  sw        $s2, 0x30($sp)
/* A27AB4 80240BE4 AFB1002C */  sw        $s1, 0x2c($sp)
/* A27AB8 80240BE8 AFB00028 */  sw        $s0, 0x28($sp)
/* A27ABC 80240BEC 8C620000 */  lw        $v0, ($v1)
/* A27AC0 80240BF0 14400007 */  bnez      $v0, .L80240C10
/* A27AC4 80240BF4 00000000 */   nop
/* A27AC8 80240BF8 3C028007 */  lui       $v0, %hi(D_800779B0)
/* A27ACC 80240BFC 904279B0 */  lbu       $v0, %lo(D_800779B0)($v0)
/* A27AD0 80240C00 00021080 */  sll       $v0, $v0, 2
/* A27AD4 80240C04 00441021 */  addu      $v0, $v0, $a0
/* A27AD8 80240C08 8C420000 */  lw        $v0, ($v0)
/* A27ADC 80240C0C AC620000 */  sw        $v0, ($v1)
.L80240C10:
/* A27AE0 80240C10 3C038024 */  lui       $v1, %hi(D_80243250_A2A120)
/* A27AE4 80240C14 8C633250 */  lw        $v1, %lo(D_80243250_A2A120)($v1)
/* A27AE8 80240C18 2C620005 */  sltiu     $v0, $v1, 5
/* A27AEC 80240C1C 10400050 */  beqz      $v0, .L80240D60
/* A27AF0 80240C20 00031080 */   sll      $v0, $v1, 2
/* A27AF4 80240C24 3C018024 */  lui       $at, %hi(jtbl_80243358_A2A228)
/* A27AF8 80240C28 00220821 */  addu      $at, $at, $v0
/* A27AFC 80240C2C 8C223358 */  lw        $v0, %lo(jtbl_80243358_A2A228)($at)
/* A27B00 80240C30 00400008 */  jr        $v0
/* A27B04 80240C34 00000000 */   nop
glabel L80240C38_A27B08
/* A27B08 80240C38 3C048024 */  lui       $a0, %hi(D_80243258_A2A128)
/* A27B0C 80240C3C 8C843258 */  lw        $a0, %lo(D_80243258_A2A128)($a0)
/* A27B10 80240C40 8C830000 */  lw        $v1, ($a0)
/* A27B14 80240C44 2402FFFF */  addiu     $v0, $zero, -1
/* A27B18 80240C48 14620004 */  bne       $v1, $v0, .L80240C5C
/* A27B1C 80240C4C 24020004 */   addiu    $v0, $zero, 4
/* A27B20 80240C50 8C830004 */  lw        $v1, 4($a0)
/* A27B24 80240C54 08090323 */  j         .L80240C8C
/* A27B28 80240C58 00000000 */   nop
.L80240C5C:
/* A27B2C 80240C5C 3C038024 */  lui       $v1, %hi(D_80243254_A2A124)
/* A27B30 80240C60 24633254 */  addiu     $v1, $v1, %lo(D_80243254_A2A124)
/* A27B34 80240C64 8C620000 */  lw        $v0, ($v1)
/* A27B38 80240C68 2442000A */  addiu     $v0, $v0, 0xa
/* A27B3C 80240C6C AC620000 */  sw        $v0, ($v1)
/* A27B40 80240C70 28420100 */  slti      $v0, $v0, 0x100
/* A27B44 80240C74 5440003B */  bnel      $v0, $zero, .L80240D64
/* A27B48 80240C78 24040001 */   addiu    $a0, $zero, 1
/* A27B4C 80240C7C 240200FF */  addiu     $v0, $zero, 0xff
/* A27B50 80240C80 AC620000 */  sw        $v0, ($v1)
/* A27B54 80240C84 8C830004 */  lw        $v1, 4($a0)
/* A27B58 80240C88 24020001 */  addiu     $v0, $zero, 1
.L80240C8C:
/* A27B5C 80240C8C 3C018024 */  lui       $at, %hi(D_80243250_A2A120)
/* A27B60 80240C90 AC223250 */  sw        $v0, %lo(D_80243250_A2A120)($at)
/* A27B64 80240C94 3C018024 */  lui       $at, %hi(func_80243380_826640)
/* A27B68 80240C98 AC233380 */  sw        $v1, %lo(func_80243380_826640)($at)
/* A27B6C 80240C9C 08090359 */  j         .L80240D64
/* A27B70 80240CA0 24040001 */   addiu    $a0, $zero, 1
glabel L80240CA4_A27B74
/* A27B74 80240CA4 3C038024 */  lui       $v1, %hi(func_80243380_826640)
/* A27B78 80240CA8 24633380 */  addiu     $v1, $v1, %lo(func_80243380_826640)
/* A27B7C 80240CAC 8C620000 */  lw        $v0, ($v1)
/* A27B80 80240CB0 1440001B */  bnez      $v0, .L80240D20
/* A27B84 80240CB4 2442FFFF */   addiu    $v0, $v0, -1
/* A27B88 80240CB8 24020002 */  addiu     $v0, $zero, 2
/* A27B8C 80240CBC 3C018024 */  lui       $at, %hi(D_80243250_A2A120)
/* A27B90 80240CC0 AC223250 */  sw        $v0, %lo(D_80243250_A2A120)($at)
/* A27B94 80240CC4 08090359 */  j         .L80240D64
/* A27B98 80240CC8 24040001 */   addiu    $a0, $zero, 1
glabel L80240CCC_A27B9C
/* A27B9C 80240CCC 3C048024 */  lui       $a0, %hi(D_80243254_A2A124)
/* A27BA0 80240CD0 24843254 */  addiu     $a0, $a0, %lo(D_80243254_A2A124)
/* A27BA4 80240CD4 8C820000 */  lw        $v0, ($a0)
/* A27BA8 80240CD8 2442FFF6 */  addiu     $v0, $v0, -0xa
/* A27BAC 80240CDC 04410020 */  bgez      $v0, .L80240D60
/* A27BB0 80240CE0 AC820000 */   sw       $v0, ($a0)
/* A27BB4 80240CE4 3C028024 */  lui       $v0, %hi(D_80243258_A2A128)
/* A27BB8 80240CE8 24423258 */  addiu     $v0, $v0, %lo(D_80243258_A2A128)
/* A27BBC 80240CEC 8C430000 */  lw        $v1, ($v0)
/* A27BC0 80240CF0 AC800000 */  sw        $zero, ($a0)
/* A27BC4 80240CF4 8C640008 */  lw        $a0, 8($v1)
/* A27BC8 80240CF8 24630008 */  addiu     $v1, $v1, 8
/* A27BCC 80240CFC 10800011 */  beqz      $a0, .L80240D44
/* A27BD0 80240D00 AC430000 */   sw       $v1, ($v0)
/* A27BD4 80240D04 08090356 */  j         .L80240D58
/* A27BD8 80240D08 00000000 */   nop
glabel L80240D0C_A27BDC
/* A27BDC 80240D0C 3C038024 */  lui       $v1, %hi(func_80243380_826640)
/* A27BE0 80240D10 24633380 */  addiu     $v1, $v1, %lo(func_80243380_826640)
/* A27BE4 80240D14 8C620000 */  lw        $v0, ($v1)
/* A27BE8 80240D18 10400003 */  beqz      $v0, .L80240D28
/* A27BEC 80240D1C 2442FFFF */   addiu    $v0, $v0, -1
.L80240D20:
/* A27BF0 80240D20 08090358 */  j         .L80240D60
/* A27BF4 80240D24 AC620000 */   sw       $v0, ($v1)
.L80240D28:
/* A27BF8 80240D28 3C028024 */  lui       $v0, %hi(D_80243258_A2A128)
/* A27BFC 80240D2C 24423258 */  addiu     $v0, $v0, %lo(D_80243258_A2A128)
/* A27C00 80240D30 8C430000 */  lw        $v1, ($v0)
/* A27C04 80240D34 8C640008 */  lw        $a0, 8($v1)
/* A27C08 80240D38 24630008 */  addiu     $v1, $v1, 8
/* A27C0C 80240D3C 14800006 */  bnez      $a0, .L80240D58
/* A27C10 80240D40 AC430000 */   sw       $v1, ($v0)
.L80240D44:
/* A27C14 80240D44 24020003 */  addiu     $v0, $zero, 3
/* A27C18 80240D48 3C018024 */  lui       $at, %hi(D_80243250_A2A120)
/* A27C1C 80240D4C AC223250 */  sw        $v0, %lo(D_80243250_A2A120)($at)
/* A27C20 80240D50 08090359 */  j         .L80240D64
/* A27C24 80240D54 24040001 */   addiu    $a0, $zero, 1
.L80240D58:
/* A27C28 80240D58 3C018024 */  lui       $at, %hi(D_80243250_A2A120)
/* A27C2C 80240D5C AC203250 */  sw        $zero, %lo(D_80243250_A2A120)($at)
.L80240D60:
glabel L80240D60_A27C30
/* A27C30 80240D60 24040001 */  addiu     $a0, $zero, 1
.L80240D64:
/* A27C34 80240D64 27B00018 */  addiu     $s0, $sp, 0x18
/* A27C38 80240D68 0200282D */  daddu     $a1, $s0, $zero
/* A27C3C 80240D6C 0C04DF70 */  jal       func_80137DC0
/* A27C40 80240D70 27A6001C */   addiu    $a2, $sp, 0x1c
/* A27C44 80240D74 0000202D */  daddu     $a0, $zero, $zero
/* A27C48 80240D78 0200282D */  daddu     $a1, $s0, $zero
/* A27C4C 80240D7C 0C04DF70 */  jal       func_80137DC0
/* A27C50 80240D80 27A60020 */   addiu    $a2, $sp, 0x20
/* A27C54 80240D84 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* A27C58 80240D88 3C01437F */  lui       $at, 0x437f
/* A27C5C 80240D8C 44812000 */  mtc1      $at, $f4
/* A27C60 80240D90 00000000 */  nop
/* A27C64 80240D94 46022081 */  sub.s     $f2, $f4, $f2
/* A27C68 80240D98 3C018024 */  lui       $at, %hi(D_80243254_A2A124)
/* A27C6C 80240D9C C4203254 */  lwc1      $f0, %lo(D_80243254_A2A124)($at)
/* A27C70 80240DA0 46800020 */  cvt.s.w   $f0, $f0
/* A27C74 80240DA4 46020002 */  mul.s     $f0, $f0, $f2
/* A27C78 80240DA8 00000000 */  nop
/* A27C7C 80240DAC C7A20020 */  lwc1      $f2, 0x20($sp)
/* A27C80 80240DB0 46022081 */  sub.s     $f2, $f4, $f2
/* A27C84 80240DB4 46020002 */  mul.s     $f0, $f0, $f2
/* A27C88 80240DB8 00000000 */  nop
/* A27C8C 80240DBC 46040003 */  div.s     $f0, $f0, $f4
/* A27C90 80240DC0 46040003 */  div.s     $f0, $f0, $f4
/* A27C94 80240DC4 4600018D */  trunc.w.s $f6, $f0
/* A27C98 80240DC8 44113000 */  mfc1      $s1, $f6
/* A27C9C 80240DCC 00000000 */  nop
/* A27CA0 80240DD0 1A200015 */  blez      $s1, .L80240E28
/* A27CA4 80240DD4 00000000 */   nop
/* A27CA8 80240DD8 3C128024 */  lui       $s2, %hi(D_80243258_A2A128)
/* A27CAC 80240DDC 26523258 */  addiu     $s2, $s2, %lo(D_80243258_A2A128)
/* A27CB0 80240DE0 8E420000 */  lw        $v0, ($s2)
/* A27CB4 80240DE4 8C440000 */  lw        $a0, ($v0)
/* A27CB8 80240DE8 1080000F */  beqz      $a0, .L80240E28
/* A27CBC 80240DEC 00000000 */   nop
/* A27CC0 80240DF0 0C04992C */  jal       get_msg_lines
/* A27CC4 80240DF4 0000802D */   daddu    $s0, $zero, $zero
/* A27CC8 80240DF8 28420002 */  slti      $v0, $v0, 2
/* A27CCC 80240DFC 50400001 */  beql      $v0, $zero, .L80240E04
/* A27CD0 80240E00 2410FFF9 */   addiu    $s0, $zero, -7
.L80240E04:
/* A27CD4 80240E04 0000282D */  daddu     $a1, $zero, $zero
/* A27CD8 80240E08 260600C4 */  addiu     $a2, $s0, 0xc4
/* A27CDC 80240E0C 8E430000 */  lw        $v1, ($s2)
/* A27CE0 80240E10 2402FFFF */  addiu     $v0, $zero, -1
/* A27CE4 80240E14 AFA20010 */  sw        $v0, 0x10($sp)
/* A27CE8 80240E18 AFA00014 */  sw        $zero, 0x14($sp)
/* A27CEC 80240E1C 8C640000 */  lw        $a0, ($v1)
/* A27CF0 80240E20 0C04993B */  jal       draw_string
/* A27CF4 80240E24 0220382D */   daddu    $a3, $s1, $zero
.L80240E28:
/* A27CF8 80240E28 8FBF0034 */  lw        $ra, 0x34($sp)
/* A27CFC 80240E2C 8FB20030 */  lw        $s2, 0x30($sp)
/* A27D00 80240E30 8FB1002C */  lw        $s1, 0x2c($sp)
/* A27D04 80240E34 8FB00028 */  lw        $s0, 0x28($sp)
/* A27D08 80240E38 03E00008 */  jr        $ra
/* A27D0C 80240E3C 27BD0038 */   addiu    $sp, $sp, 0x38
