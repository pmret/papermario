.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401AC_DE891C
/* DE891C 802401AC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* DE8920 802401B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* DE8924 802401B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* DE8928 802401B8 AFB00018 */  sw        $s0, 0x18($sp)
/* DE892C 802401BC 8C910084 */  lw        $s1, 0x84($a0)
/* DE8930 802401C0 86230044 */  lh        $v1, 0x44($s1)
/* DE8934 802401C4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* DE8938 802401C8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* DE893C 802401CC 2C620005 */  sltiu     $v0, $v1, 5
/* DE8940 802401D0 1040008A */  beqz      $v0, L802403FC_DE8B6C
/* DE8944 802401D4 00031080 */   sll      $v0, $v1, 2
/* DE8948 802401D8 3C018024 */  lui       $at, %hi(jtbl_80243730_DEBEA0)
/* DE894C 802401DC 00220821 */  addu      $at, $at, $v0
/* DE8950 802401E0 8C223730 */  lw        $v0, %lo(jtbl_80243730_DEBEA0)($at)
/* DE8954 802401E4 00400008 */  jr        $v0
/* DE8958 802401E8 00000000 */   nop
glabel L802401EC_DE895C
/* DE895C 802401EC 8E22003C */  lw        $v0, 0x3c($s1)
/* DE8960 802401F0 86270046 */  lh        $a3, 0x46($s1)
/* DE8964 802401F4 AFA20010 */  sw        $v0, 0x10($sp)
/* DE8968 802401F8 8E250010 */  lw        $a1, 0x10($s1)
/* DE896C 802401FC 8E26001C */  lw        $a2, 0x1c($s1)
/* DE8970 80240200 0C00A8ED */  jal       update_lerp
/* DE8974 80240204 24040005 */   addiu    $a0, $zero, 5
/* DE8978 80240208 86270046 */  lh        $a3, 0x46($s1)
/* DE897C 8024020C 8E22003C */  lw        $v0, 0x3c($s1)
/* DE8980 80240210 E6200004 */  swc1      $f0, 4($s1)
/* DE8984 80240214 AFA20010 */  sw        $v0, 0x10($sp)
/* DE8988 80240218 8E25000C */  lw        $a1, 0xc($s1)
/* DE898C 8024021C 8E260018 */  lw        $a2, 0x18($s1)
/* DE8990 80240220 0C00A8ED */  jal       update_lerp
/* DE8994 80240224 0000202D */   daddu    $a0, $zero, $zero
/* DE8998 80240228 86270046 */  lh        $a3, 0x46($s1)
/* DE899C 8024022C 8E22003C */  lw        $v0, 0x3c($s1)
/* DE89A0 80240230 E6200000 */  swc1      $f0, ($s1)
/* DE89A4 80240234 AFA20010 */  sw        $v0, 0x10($sp)
/* DE89A8 80240238 8E250014 */  lw        $a1, 0x14($s1)
/* DE89AC 8024023C 8E260020 */  lw        $a2, 0x20($s1)
/* DE89B0 80240240 0C00A8ED */  jal       update_lerp
/* DE89B4 80240244 0000202D */   daddu    $a0, $zero, $zero
/* DE89B8 80240248 8E220050 */  lw        $v0, 0x50($s1)
/* DE89BC 8024024C E6200008 */  swc1      $f0, 8($s1)
/* DE89C0 80240250 C6200000 */  lwc1      $f0, ($s1)
/* DE89C4 80240254 8C42000C */  lw        $v0, 0xc($v0)
/* DE89C8 80240258 E4400008 */  swc1      $f0, 8($v0)
/* DE89CC 8024025C 8E220050 */  lw        $v0, 0x50($s1)
/* DE89D0 80240260 C6200004 */  lwc1      $f0, 4($s1)
/* DE89D4 80240264 8C42000C */  lw        $v0, 0xc($v0)
/* DE89D8 80240268 E440000C */  swc1      $f0, 0xc($v0)
/* DE89DC 8024026C 8E220050 */  lw        $v0, 0x50($s1)
/* DE89E0 80240270 C6200008 */  lwc1      $f0, 8($s1)
/* DE89E4 80240274 8C42000C */  lw        $v0, 0xc($v0)
/* DE89E8 80240278 E4400010 */  swc1      $f0, 0x10($v0)
/* DE89EC 8024027C 96220046 */  lhu       $v0, 0x46($s1)
/* DE89F0 80240280 8E23003C */  lw        $v1, 0x3c($s1)
/* DE89F4 80240284 24420001 */  addiu     $v0, $v0, 1
/* DE89F8 80240288 A6220046 */  sh        $v0, 0x46($s1)
/* DE89FC 8024028C 00021400 */  sll       $v0, $v0, 0x10
/* DE8A00 80240290 00021403 */  sra       $v0, $v0, 0x10
/* DE8A04 80240294 0043102A */  slt       $v0, $v0, $v1
/* DE8A08 80240298 14400058 */  bnez      $v0, L802403FC_DE8B6C
/* DE8A0C 8024029C 24020001 */   addiu    $v0, $zero, 1
/* DE8A10 802402A0 A6220044 */  sh        $v0, 0x44($s1)
/* DE8A14 802402A4 080900FF */  j         L802403FC_DE8B6C
/* DE8A18 802402A8 A6200046 */   sh       $zero, 0x46($s1)
glabel L802402AC_DE8A1C
/* DE8A1C 802402AC 96220046 */  lhu       $v0, 0x46($s1)
/* DE8A20 802402B0 24420001 */  addiu     $v0, $v0, 1
/* DE8A24 802402B4 A6220046 */  sh        $v0, 0x46($s1)
/* DE8A28 802402B8 00021400 */  sll       $v0, $v0, 0x10
/* DE8A2C 802402BC 00021403 */  sra       $v0, $v0, 0x10
/* DE8A30 802402C0 2842003C */  slti      $v0, $v0, 0x3c
/* DE8A34 802402C4 1440004D */  bnez      $v0, L802403FC_DE8B6C
/* DE8A38 802402C8 24020002 */   addiu    $v0, $zero, 2
/* DE8A3C 802402CC 8E230050 */  lw        $v1, 0x50($s1)
/* DE8A40 802402D0 A6220044 */  sh        $v0, 0x44($s1)
/* DE8A44 802402D4 A6200046 */  sh        $zero, 0x46($s1)
/* DE8A48 802402D8 8C63000C */  lw        $v1, 0xc($v1)
/* DE8A4C 802402DC 24020001 */  addiu     $v0, $zero, 1
/* DE8A50 802402E0 AC620070 */  sw        $v0, 0x70($v1)
/* DE8A54 802402E4 8E220050 */  lw        $v0, 0x50($s1)
/* DE8A58 802402E8 8C42000C */  lw        $v0, 0xc($v0)
/* DE8A5C 802402EC 080900FF */  j         L802403FC_DE8B6C
/* DE8A60 802402F0 AC400074 */   sw       $zero, 0x74($v0)
glabel L802402F4_DE8A64
/* DE8A64 802402F4 96220046 */  lhu       $v0, 0x46($s1)
/* DE8A68 802402F8 24420001 */  addiu     $v0, $v0, 1
/* DE8A6C 802402FC A6220046 */  sh        $v0, 0x46($s1)
/* DE8A70 80240300 00021400 */  sll       $v0, $v0, 0x10
/* DE8A74 80240304 00021403 */  sra       $v0, $v0, 0x10
/* DE8A78 80240308 2842003C */  slti      $v0, $v0, 0x3c
/* DE8A7C 8024030C 1440003B */  bnez      $v0, L802403FC_DE8B6C
/* DE8A80 80240310 00000000 */   nop
/* DE8A84 80240314 3C013F80 */  lui       $at, 0x3f80
/* DE8A88 80240318 44810000 */  mtc1      $at, $f0
/* DE8A8C 8024031C AFA00014 */  sw        $zero, 0x14($sp)
/* DE8A90 80240320 E7A00010 */  swc1      $f0, 0x10($sp)
/* DE8A94 80240324 8E250018 */  lw        $a1, 0x18($s1)
/* DE8A98 80240328 8E26001C */  lw        $a2, 0x1c($s1)
/* DE8A9C 8024032C 8E270020 */  lw        $a3, 0x20($s1)
/* DE8AA0 80240330 0C01C9AC */  jal       func_800726B0
/* DE8AA4 80240334 24040001 */   addiu    $a0, $zero, 1
/* DE8AA8 80240338 AE220054 */  sw        $v0, 0x54($s1)
/* DE8AAC 8024033C 8C43000C */  lw        $v1, 0xc($v0)
/* DE8AB0 80240340 9222003B */  lbu       $v0, 0x3b($s1)
/* DE8AB4 80240344 A0620034 */  sb        $v0, 0x34($v1)
/* DE8AB8 80240348 8E220054 */  lw        $v0, 0x54($s1)
/* DE8ABC 8024034C 8C42000C */  lw        $v0, 0xc($v0)
/* DE8AC0 80240350 AC400020 */  sw        $zero, 0x20($v0)
/* DE8AC4 80240354 8E250018 */  lw        $a1, 0x18($s1)
/* DE8AC8 80240358 8E260028 */  lw        $a2, 0x28($s1)
/* DE8ACC 8024035C 8E270020 */  lw        $a3, 0x20($s1)
/* DE8AD0 80240360 0C044898 */  jal       create_shadow_type
/* DE8AD4 80240364 0000202D */   daddu    $a0, $zero, $zero
/* DE8AD8 80240368 3C014210 */  lui       $at, 0x4210
/* DE8ADC 8024036C 44810000 */  mtc1      $at, $f0
/* DE8AE0 80240370 AE220040 */  sw        $v0, 0x40($s1)
/* DE8AE4 80240374 24020003 */  addiu     $v0, $zero, 3
/* DE8AE8 80240378 A6220044 */  sh        $v0, 0x44($s1)
/* DE8AEC 8024037C 24020001 */  addiu     $v0, $zero, 1
/* DE8AF0 80240380 A6200046 */  sh        $zero, 0x46($s1)
/* DE8AF4 80240384 AE20002C */  sw        $zero, 0x2c($s1)
/* DE8AF8 80240388 A6220048 */  sh        $v0, 0x48($s1)
/* DE8AFC 8024038C 080900FF */  j         L802403FC_DE8B6C
/* DE8B00 80240390 E6200030 */   swc1     $f0, 0x30($s1)
glabel L80240394_DE8B04
/* DE8B04 80240394 0000202D */  daddu     $a0, $zero, $zero
/* DE8B08 80240398 3C054210 */  lui       $a1, 0x4210
/* DE8B0C 8024039C 3C064198 */  lui       $a2, 0x4198
/* DE8B10 802403A0 86270046 */  lh        $a3, 0x46($s1)
/* DE8B14 802403A4 24020078 */  addiu     $v0, $zero, 0x78
/* DE8B18 802403A8 0C00A8ED */  jal       update_lerp
/* DE8B1C 802403AC AFA20010 */   sw       $v0, 0x10($sp)
/* DE8B20 802403B0 96220046 */  lhu       $v0, 0x46($s1)
/* DE8B24 802403B4 E6200030 */  swc1      $f0, 0x30($s1)
/* DE8B28 802403B8 24420001 */  addiu     $v0, $v0, 1
/* DE8B2C 802403BC A6220046 */  sh        $v0, 0x46($s1)
/* DE8B30 802403C0 00021400 */  sll       $v0, $v0, 0x10
/* DE8B34 802403C4 00021403 */  sra       $v0, $v0, 0x10
/* DE8B38 802403C8 28420078 */  slti      $v0, $v0, 0x78
/* DE8B3C 802403CC 1440000B */  bnez      $v0, L802403FC_DE8B6C
/* DE8B40 802403D0 24030001 */   addiu    $v1, $zero, 1
/* DE8B44 802403D4 C620002C */  lwc1      $f0, 0x2c($s1)
/* DE8B48 802403D8 24020002 */  addiu     $v0, $zero, 2
/* DE8B4C 802403DC A6220048 */  sh        $v0, 0x48($s1)
/* DE8B50 802403E0 24020004 */  addiu     $v0, $zero, 4
/* DE8B54 802403E4 A620004C */  sh        $zero, 0x4c($s1)
/* DE8B58 802403E8 A623004A */  sh        $v1, 0x4a($s1)
/* DE8B5C 802403EC A623004E */  sh        $v1, 0x4e($s1)
/* DE8B60 802403F0 A6220044 */  sh        $v0, 0x44($s1)
/* DE8B64 802403F4 A6200046 */  sh        $zero, 0x46($s1)
/* DE8B68 802403F8 E6200034 */  swc1      $f0, 0x34($s1)
glabel L802403FC_DE8B6C
/* DE8B6C 802403FC 8623004A */  lh        $v1, 0x4a($s1)
/* DE8B70 80240400 24020001 */  addiu     $v0, $zero, 1
/* DE8B74 80240404 10620005 */  beq       $v1, $v0, .L8024041C
/* DE8B78 80240408 24020002 */   addiu    $v0, $zero, 2
/* DE8B7C 8024040C 1062001E */  beq       $v1, $v0, .L80240488
/* DE8B80 80240410 00000000 */   nop
/* DE8B84 80240414 0809014C */  j         .L80240530
/* DE8B88 80240418 00000000 */   nop
.L8024041C:
/* DE8B8C 8024041C 8627004C */  lh        $a3, 0x4c($s1)
/* DE8B90 80240420 24100078 */  addiu     $s0, $zero, 0x78
/* DE8B94 80240424 AFB00010 */  sw        $s0, 0x10($sp)
/* DE8B98 80240428 8E250034 */  lw        $a1, 0x34($s1)
/* DE8B9C 8024042C 3C0644B4 */  lui       $a2, 0x44b4
/* DE8BA0 80240430 0C00A8ED */  jal       update_lerp
/* DE8BA4 80240434 24040004 */   addiu    $a0, $zero, 4
/* DE8BA8 80240438 8627004C */  lh        $a3, 0x4c($s1)
/* DE8BAC 8024043C E620002C */  swc1      $f0, 0x2c($s1)
/* DE8BB0 80240440 AFB00010 */  sw        $s0, 0x10($sp)
/* DE8BB4 80240444 8E25001C */  lw        $a1, 0x1c($s1)
/* DE8BB8 80240448 8E260024 */  lw        $a2, 0x24($s1)
/* DE8BBC 8024044C 0C00A8ED */  jal       update_lerp
/* DE8BC0 80240450 2404000A */   addiu    $a0, $zero, 0xa
/* DE8BC4 80240454 9622004C */  lhu       $v0, 0x4c($s1)
/* DE8BC8 80240458 E6200004 */  swc1      $f0, 4($s1)
/* DE8BCC 8024045C 24420001 */  addiu     $v0, $v0, 1
/* DE8BD0 80240460 A622004C */  sh        $v0, 0x4c($s1)
/* DE8BD4 80240464 00021400 */  sll       $v0, $v0, 0x10
/* DE8BD8 80240468 00021403 */  sra       $v0, $v0, 0x10
/* DE8BDC 8024046C 0050102A */  slt       $v0, $v0, $s0
/* DE8BE0 80240470 1440002F */  bnez      $v0, .L80240530
/* DE8BE4 80240474 2402010E */   addiu    $v0, $zero, 0x10e
/* DE8BE8 80240478 A622004C */  sh        $v0, 0x4c($s1)
/* DE8BEC 8024047C 24020002 */  addiu     $v0, $zero, 2
/* DE8BF0 80240480 0809014B */  j         .L8024052C
/* DE8BF4 80240484 A622004A */   sh       $v0, 0x4a($s1)
.L80240488:
/* DE8BF8 80240488 8622004C */  lh        $v0, 0x4c($s1)
/* DE8BFC 8024048C 44826000 */  mtc1      $v0, $f12
/* DE8C00 80240490 00000000 */  nop
/* DE8C04 80240494 0C00A8BB */  jal       sin_deg
/* DE8C08 80240498 46806320 */   cvt.s.w  $f12, $f12
/* DE8C0C 8024049C 3C013F80 */  lui       $at, 0x3f80
/* DE8C10 802404A0 44811000 */  mtc1      $at, $f2
/* DE8C14 802404A4 00000000 */  nop
/* DE8C18 802404A8 46020000 */  add.s     $f0, $f0, $f2
/* DE8C1C 802404AC 46000000 */  add.s     $f0, $f0, $f0
/* DE8C20 802404B0 C6220024 */  lwc1      $f2, 0x24($s1)
/* DE8C24 802404B4 8622004C */  lh        $v0, 0x4c($s1)
/* DE8C28 802404B8 46001080 */  add.s     $f2, $f2, $f0
/* DE8C2C 802404BC 24420008 */  addiu     $v0, $v0, 8
/* DE8C30 802404C0 44826000 */  mtc1      $v0, $f12
/* DE8C34 802404C4 00000000 */  nop
/* DE8C38 802404C8 46806320 */  cvt.s.w   $f12, $f12
/* DE8C3C 802404CC 0C00A6C9 */  jal       clamp_angle
/* DE8C40 802404D0 E6220004 */   swc1     $f2, 4($s1)
/* DE8C44 802404D4 4600010D */  trunc.w.s $f4, $f0
/* DE8C48 802404D8 44022000 */  mfc1      $v0, $f4
/* DE8C4C 802404DC C6200004 */  lwc1      $f0, 4($s1)
/* DE8C50 802404E0 A622004C */  sh        $v0, 0x4c($s1)
/* DE8C54 802404E4 C60C0028 */  lwc1      $f12, 0x28($s0)
/* DE8C58 802404E8 8E060030 */  lw        $a2, 0x30($s0)
/* DE8C5C 802404EC 3C0141A0 */  lui       $at, 0x41a0
/* DE8C60 802404F0 44817000 */  mtc1      $at, $f14
/* DE8C64 802404F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* DE8C68 802404F8 C602002C */  lwc1      $f2, 0x2c($s0)
/* DE8C6C 802404FC C6200008 */  lwc1      $f0, 8($s1)
/* DE8C70 80240500 E7A00014 */  swc1      $f0, 0x14($sp)
/* DE8C74 80240504 8E270000 */  lw        $a3, ($s1)
/* DE8C78 80240508 0C00A7CB */  jal       dist3D
/* DE8C7C 8024050C 460E1380 */   add.s    $f14, $f2, $f14
/* DE8C80 80240510 3C0141F0 */  lui       $at, 0x41f0
/* DE8C84 80240514 44811000 */  mtc1      $at, $f2
/* DE8C88 80240518 00000000 */  nop
/* DE8C8C 8024051C 4600103C */  c.lt.s    $f2, $f0
/* DE8C90 80240520 00000000 */  nop
/* DE8C94 80240524 45010002 */  bc1t      .L80240530
/* DE8C98 80240528 24020003 */   addiu    $v0, $zero, 3
.L8024052C:
/* DE8C9C 8024052C A622004E */  sh        $v0, 0x4e($s1)
.L80240530:
/* DE8CA0 80240530 86230048 */  lh        $v1, 0x48($s1)
/* DE8CA4 80240534 24020001 */  addiu     $v0, $zero, 1
/* DE8CA8 80240538 10620005 */  beq       $v1, $v0, .L80240550
/* DE8CAC 8024053C 24020002 */   addiu    $v0, $zero, 2
/* DE8CB0 80240540 10620008 */  beq       $v1, $v0, .L80240564
/* DE8CB4 80240544 00000000 */   nop
/* DE8CB8 80240548 08090169 */  j         .L802405A4
/* DE8CBC 8024054C 00000000 */   nop
.L80240550:
/* DE8CC0 80240550 C620002C */  lwc1      $f0, 0x2c($s1)
/* DE8CC4 80240554 C62C0030 */  lwc1      $f12, 0x30($s1)
/* DE8CC8 80240558 0C00A6C9 */  jal       clamp_angle
/* DE8CCC 8024055C 460C0300 */   add.s    $f12, $f0, $f12
/* DE8CD0 80240560 E620002C */  swc1      $f0, 0x2c($s1)
.L80240564:
/* DE8CD4 80240564 8E220054 */  lw        $v0, 0x54($s1)
/* DE8CD8 80240568 C620002C */  lwc1      $f0, 0x2c($s1)
/* DE8CDC 8024056C 8C42000C */  lw        $v0, 0xc($v0)
/* DE8CE0 80240570 E4400024 */  swc1      $f0, 0x24($v0)
/* DE8CE4 80240574 8E220054 */  lw        $v0, 0x54($s1)
/* DE8CE8 80240578 C6200018 */  lwc1      $f0, 0x18($s1)
/* DE8CEC 8024057C 8C42000C */  lw        $v0, 0xc($v0)
/* DE8CF0 80240580 E4400004 */  swc1      $f0, 4($v0)
/* DE8CF4 80240584 8E220054 */  lw        $v0, 0x54($s1)
/* DE8CF8 80240588 C6200004 */  lwc1      $f0, 4($s1)
/* DE8CFC 8024058C 8C42000C */  lw        $v0, 0xc($v0)
/* DE8D00 80240590 E4400008 */  swc1      $f0, 8($v0)
/* DE8D04 80240594 8E220054 */  lw        $v0, 0x54($s1)
/* DE8D08 80240598 C6200020 */  lwc1      $f0, 0x20($s1)
/* DE8D0C 8024059C 8C42000C */  lw        $v0, 0xc($v0)
/* DE8D10 802405A0 E440000C */  swc1      $f0, 0xc($v0)
.L802405A4:
/* DE8D14 802405A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* DE8D18 802405A8 8FB1001C */  lw        $s1, 0x1c($sp)
/* DE8D1C 802405AC 8FB00018 */  lw        $s0, 0x18($sp)
/* DE8D20 802405B0 0000102D */  daddu     $v0, $zero, $zero
/* DE8D24 802405B4 03E00008 */  jr        $ra
/* DE8D28 802405B8 27BD0028 */   addiu    $sp, $sp, 0x28
