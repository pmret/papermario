.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401CC_D86BCC
/* D86BCC 802401CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D86BD0 802401D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* D86BD4 802401D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* D86BD8 802401D8 AFB00018 */  sw        $s0, 0x18($sp)
/* D86BDC 802401DC 8C910084 */  lw        $s1, 0x84($a0)
/* D86BE0 802401E0 86230044 */  lh        $v1, 0x44($s1)
/* D86BE4 802401E4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D86BE8 802401E8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D86BEC 802401EC 2C620005 */  sltiu     $v0, $v1, 5
/* D86BF0 802401F0 1040008A */  beqz      $v0, .L8024041C
/* D86BF4 802401F4 00031080 */   sll      $v0, $v1, 2
/* D86BF8 802401F8 3C018024 */  lui       $at, %hi(jtbl_80242CB0_D896B0)
/* D86BFC 802401FC 00220821 */  addu      $at, $at, $v0
/* D86C00 80240200 8C222CB0 */  lw        $v0, %lo(jtbl_80242CB0_D896B0)($at)
/* D86C04 80240204 00400008 */  jr        $v0
/* D86C08 80240208 00000000 */   nop
glabel L8024020C_D86C0C
/* D86C0C 8024020C 8E22003C */  lw        $v0, 0x3c($s1)
/* D86C10 80240210 86270046 */  lh        $a3, 0x46($s1)
/* D86C14 80240214 AFA20010 */  sw        $v0, 0x10($sp)
/* D86C18 80240218 8E250010 */  lw        $a1, 0x10($s1)
/* D86C1C 8024021C 8E26001C */  lw        $a2, 0x1c($s1)
/* D86C20 80240220 0C00A8ED */  jal       update_lerp
/* D86C24 80240224 24040005 */   addiu    $a0, $zero, 5
/* D86C28 80240228 86270046 */  lh        $a3, 0x46($s1)
/* D86C2C 8024022C 8E22003C */  lw        $v0, 0x3c($s1)
/* D86C30 80240230 E6200004 */  swc1      $f0, 4($s1)
/* D86C34 80240234 AFA20010 */  sw        $v0, 0x10($sp)
/* D86C38 80240238 8E25000C */  lw        $a1, 0xc($s1)
/* D86C3C 8024023C 8E260018 */  lw        $a2, 0x18($s1)
/* D86C40 80240240 0C00A8ED */  jal       update_lerp
/* D86C44 80240244 0000202D */   daddu    $a0, $zero, $zero
/* D86C48 80240248 86270046 */  lh        $a3, 0x46($s1)
/* D86C4C 8024024C 8E22003C */  lw        $v0, 0x3c($s1)
/* D86C50 80240250 E6200000 */  swc1      $f0, ($s1)
/* D86C54 80240254 AFA20010 */  sw        $v0, 0x10($sp)
/* D86C58 80240258 8E250014 */  lw        $a1, 0x14($s1)
/* D86C5C 8024025C 8E260020 */  lw        $a2, 0x20($s1)
/* D86C60 80240260 0C00A8ED */  jal       update_lerp
/* D86C64 80240264 0000202D */   daddu    $a0, $zero, $zero
/* D86C68 80240268 8E220050 */  lw        $v0, 0x50($s1)
/* D86C6C 8024026C E6200008 */  swc1      $f0, 8($s1)
/* D86C70 80240270 C6200000 */  lwc1      $f0, ($s1)
/* D86C74 80240274 8C42000C */  lw        $v0, 0xc($v0)
/* D86C78 80240278 E4400008 */  swc1      $f0, 8($v0)
/* D86C7C 8024027C 8E220050 */  lw        $v0, 0x50($s1)
/* D86C80 80240280 C6200004 */  lwc1      $f0, 4($s1)
/* D86C84 80240284 8C42000C */  lw        $v0, 0xc($v0)
/* D86C88 80240288 E440000C */  swc1      $f0, 0xc($v0)
/* D86C8C 8024028C 8E220050 */  lw        $v0, 0x50($s1)
/* D86C90 80240290 C6200008 */  lwc1      $f0, 8($s1)
/* D86C94 80240294 8C42000C */  lw        $v0, 0xc($v0)
/* D86C98 80240298 E4400010 */  swc1      $f0, 0x10($v0)
/* D86C9C 8024029C 96220046 */  lhu       $v0, 0x46($s1)
/* D86CA0 802402A0 8E23003C */  lw        $v1, 0x3c($s1)
/* D86CA4 802402A4 24420001 */  addiu     $v0, $v0, 1
/* D86CA8 802402A8 A6220046 */  sh        $v0, 0x46($s1)
/* D86CAC 802402AC 00021400 */  sll       $v0, $v0, 0x10
/* D86CB0 802402B0 00021403 */  sra       $v0, $v0, 0x10
/* D86CB4 802402B4 0043102A */  slt       $v0, $v0, $v1
/* D86CB8 802402B8 14400058 */  bnez      $v0, .L8024041C
/* D86CBC 802402BC 24020001 */   addiu    $v0, $zero, 1
/* D86CC0 802402C0 A6220044 */  sh        $v0, 0x44($s1)
/* D86CC4 802402C4 08090107 */  j         .L8024041C
/* D86CC8 802402C8 A6200046 */   sh       $zero, 0x46($s1)
glabel L802402CC_D86CCC
/* D86CCC 802402CC 96220046 */  lhu       $v0, 0x46($s1)
/* D86CD0 802402D0 24420001 */  addiu     $v0, $v0, 1
/* D86CD4 802402D4 A6220046 */  sh        $v0, 0x46($s1)
/* D86CD8 802402D8 00021400 */  sll       $v0, $v0, 0x10
/* D86CDC 802402DC 00021403 */  sra       $v0, $v0, 0x10
/* D86CE0 802402E0 2842003C */  slti      $v0, $v0, 0x3c
/* D86CE4 802402E4 1440004D */  bnez      $v0, .L8024041C
/* D86CE8 802402E8 24020002 */   addiu    $v0, $zero, 2
/* D86CEC 802402EC 8E230050 */  lw        $v1, 0x50($s1)
/* D86CF0 802402F0 A6220044 */  sh        $v0, 0x44($s1)
/* D86CF4 802402F4 A6200046 */  sh        $zero, 0x46($s1)
/* D86CF8 802402F8 8C63000C */  lw        $v1, 0xc($v1)
/* D86CFC 802402FC 24020001 */  addiu     $v0, $zero, 1
/* D86D00 80240300 AC620070 */  sw        $v0, 0x70($v1)
/* D86D04 80240304 8E220050 */  lw        $v0, 0x50($s1)
/* D86D08 80240308 8C42000C */  lw        $v0, 0xc($v0)
/* D86D0C 8024030C 08090107 */  j         .L8024041C
/* D86D10 80240310 AC400074 */   sw       $zero, 0x74($v0)
glabel L80240314_D86D14
/* D86D14 80240314 96220046 */  lhu       $v0, 0x46($s1)
/* D86D18 80240318 24420001 */  addiu     $v0, $v0, 1
/* D86D1C 8024031C A6220046 */  sh        $v0, 0x46($s1)
/* D86D20 80240320 00021400 */  sll       $v0, $v0, 0x10
/* D86D24 80240324 00021403 */  sra       $v0, $v0, 0x10
/* D86D28 80240328 2842003C */  slti      $v0, $v0, 0x3c
/* D86D2C 8024032C 1440003B */  bnez      $v0, .L8024041C
/* D86D30 80240330 00000000 */   nop
/* D86D34 80240334 3C013F80 */  lui       $at, 0x3f80
/* D86D38 80240338 44810000 */  mtc1      $at, $f0
/* D86D3C 8024033C AFA00014 */  sw        $zero, 0x14($sp)
/* D86D40 80240340 E7A00010 */  swc1      $f0, 0x10($sp)
/* D86D44 80240344 8E250018 */  lw        $a1, 0x18($s1)
/* D86D48 80240348 8E26001C */  lw        $a2, 0x1c($s1)
/* D86D4C 8024034C 8E270020 */  lw        $a3, 0x20($s1)
/* D86D50 80240350 0C01C9AC */  jal       func_800726B0
/* D86D54 80240354 24040001 */   addiu    $a0, $zero, 1
/* D86D58 80240358 AE220054 */  sw        $v0, 0x54($s1)
/* D86D5C 8024035C 8C43000C */  lw        $v1, 0xc($v0)
/* D86D60 80240360 9222003B */  lbu       $v0, 0x3b($s1)
/* D86D64 80240364 A0620034 */  sb        $v0, 0x34($v1)
/* D86D68 80240368 8E220054 */  lw        $v0, 0x54($s1)
/* D86D6C 8024036C 8C42000C */  lw        $v0, 0xc($v0)
/* D86D70 80240370 AC400020 */  sw        $zero, 0x20($v0)
/* D86D74 80240374 8E250018 */  lw        $a1, 0x18($s1)
/* D86D78 80240378 8E260028 */  lw        $a2, 0x28($s1)
/* D86D7C 8024037C 8E270020 */  lw        $a3, 0x20($s1)
/* D86D80 80240380 0C044898 */  jal       create_shadow_type
/* D86D84 80240384 0000202D */   daddu    $a0, $zero, $zero
/* D86D88 80240388 3C014210 */  lui       $at, 0x4210
/* D86D8C 8024038C 44810000 */  mtc1      $at, $f0
/* D86D90 80240390 AE220040 */  sw        $v0, 0x40($s1)
/* D86D94 80240394 24020003 */  addiu     $v0, $zero, 3
/* D86D98 80240398 A6220044 */  sh        $v0, 0x44($s1)
/* D86D9C 8024039C 24020001 */  addiu     $v0, $zero, 1
/* D86DA0 802403A0 A6200046 */  sh        $zero, 0x46($s1)
/* D86DA4 802403A4 AE20002C */  sw        $zero, 0x2c($s1)
/* D86DA8 802403A8 A6220048 */  sh        $v0, 0x48($s1)
/* D86DAC 802403AC 08090107 */  j         .L8024041C
/* D86DB0 802403B0 E6200030 */   swc1     $f0, 0x30($s1)
glabel L802403B4_D86DB4
/* D86DB4 802403B4 0000202D */  daddu     $a0, $zero, $zero
/* D86DB8 802403B8 3C054210 */  lui       $a1, 0x4210
/* D86DBC 802403BC 3C064198 */  lui       $a2, 0x4198
/* D86DC0 802403C0 86270046 */  lh        $a3, 0x46($s1)
/* D86DC4 802403C4 24020078 */  addiu     $v0, $zero, 0x78
/* D86DC8 802403C8 0C00A8ED */  jal       update_lerp
/* D86DCC 802403CC AFA20010 */   sw       $v0, 0x10($sp)
/* D86DD0 802403D0 96220046 */  lhu       $v0, 0x46($s1)
/* D86DD4 802403D4 E6200030 */  swc1      $f0, 0x30($s1)
/* D86DD8 802403D8 24420001 */  addiu     $v0, $v0, 1
/* D86DDC 802403DC A6220046 */  sh        $v0, 0x46($s1)
/* D86DE0 802403E0 00021400 */  sll       $v0, $v0, 0x10
/* D86DE4 802403E4 00021403 */  sra       $v0, $v0, 0x10
/* D86DE8 802403E8 28420078 */  slti      $v0, $v0, 0x78
/* D86DEC 802403EC 1440000B */  bnez      $v0, .L8024041C
/* D86DF0 802403F0 24030001 */   addiu    $v1, $zero, 1
/* D86DF4 802403F4 C620002C */  lwc1      $f0, 0x2c($s1)
/* D86DF8 802403F8 24020002 */  addiu     $v0, $zero, 2
/* D86DFC 802403FC A6220048 */  sh        $v0, 0x48($s1)
/* D86E00 80240400 24020004 */  addiu     $v0, $zero, 4
/* D86E04 80240404 A620004C */  sh        $zero, 0x4c($s1)
/* D86E08 80240408 A623004A */  sh        $v1, 0x4a($s1)
/* D86E0C 8024040C A623004E */  sh        $v1, 0x4e($s1)
/* D86E10 80240410 A6220044 */  sh        $v0, 0x44($s1)
/* D86E14 80240414 A6200046 */  sh        $zero, 0x46($s1)
/* D86E18 80240418 E6200034 */  swc1      $f0, 0x34($s1)
.L8024041C:
glabel L8024041C_D86E1C
/* D86E1C 8024041C 8623004A */  lh        $v1, 0x4a($s1)
/* D86E20 80240420 24020001 */  addiu     $v0, $zero, 1
/* D86E24 80240424 10620005 */  beq       $v1, $v0, .L8024043C
/* D86E28 80240428 24020002 */   addiu    $v0, $zero, 2
/* D86E2C 8024042C 1062001E */  beq       $v1, $v0, .L802404A8
/* D86E30 80240430 00000000 */   nop
/* D86E34 80240434 08090154 */  j         .L80240550
/* D86E38 80240438 00000000 */   nop
.L8024043C:
/* D86E3C 8024043C 8627004C */  lh        $a3, 0x4c($s1)
/* D86E40 80240440 24100078 */  addiu     $s0, $zero, 0x78
/* D86E44 80240444 AFB00010 */  sw        $s0, 0x10($sp)
/* D86E48 80240448 8E250034 */  lw        $a1, 0x34($s1)
/* D86E4C 8024044C 3C0644B4 */  lui       $a2, 0x44b4
/* D86E50 80240450 0C00A8ED */  jal       update_lerp
/* D86E54 80240454 24040004 */   addiu    $a0, $zero, 4
/* D86E58 80240458 8627004C */  lh        $a3, 0x4c($s1)
/* D86E5C 8024045C E620002C */  swc1      $f0, 0x2c($s1)
/* D86E60 80240460 AFB00010 */  sw        $s0, 0x10($sp)
/* D86E64 80240464 8E25001C */  lw        $a1, 0x1c($s1)
/* D86E68 80240468 8E260024 */  lw        $a2, 0x24($s1)
/* D86E6C 8024046C 0C00A8ED */  jal       update_lerp
/* D86E70 80240470 2404000A */   addiu    $a0, $zero, 0xa
/* D86E74 80240474 9622004C */  lhu       $v0, 0x4c($s1)
/* D86E78 80240478 E6200004 */  swc1      $f0, 4($s1)
/* D86E7C 8024047C 24420001 */  addiu     $v0, $v0, 1
/* D86E80 80240480 A622004C */  sh        $v0, 0x4c($s1)
/* D86E84 80240484 00021400 */  sll       $v0, $v0, 0x10
/* D86E88 80240488 00021403 */  sra       $v0, $v0, 0x10
/* D86E8C 8024048C 0050102A */  slt       $v0, $v0, $s0
/* D86E90 80240490 1440002F */  bnez      $v0, .L80240550
/* D86E94 80240494 2402010E */   addiu    $v0, $zero, 0x10e
/* D86E98 80240498 A622004C */  sh        $v0, 0x4c($s1)
/* D86E9C 8024049C 24020002 */  addiu     $v0, $zero, 2
/* D86EA0 802404A0 08090153 */  j         .L8024054C
/* D86EA4 802404A4 A622004A */   sh       $v0, 0x4a($s1)
.L802404A8:
/* D86EA8 802404A8 8622004C */  lh        $v0, 0x4c($s1)
/* D86EAC 802404AC 44826000 */  mtc1      $v0, $f12
/* D86EB0 802404B0 00000000 */  nop
/* D86EB4 802404B4 0C00A8BB */  jal       sin_deg
/* D86EB8 802404B8 46806320 */   cvt.s.w  $f12, $f12
/* D86EBC 802404BC 3C013F80 */  lui       $at, 0x3f80
/* D86EC0 802404C0 44811000 */  mtc1      $at, $f2
/* D86EC4 802404C4 00000000 */  nop
/* D86EC8 802404C8 46020000 */  add.s     $f0, $f0, $f2
/* D86ECC 802404CC 46000000 */  add.s     $f0, $f0, $f0
/* D86ED0 802404D0 C6220024 */  lwc1      $f2, 0x24($s1)
/* D86ED4 802404D4 8622004C */  lh        $v0, 0x4c($s1)
/* D86ED8 802404D8 46001080 */  add.s     $f2, $f2, $f0
/* D86EDC 802404DC 24420008 */  addiu     $v0, $v0, 8
/* D86EE0 802404E0 44826000 */  mtc1      $v0, $f12
/* D86EE4 802404E4 00000000 */  nop
/* D86EE8 802404E8 46806320 */  cvt.s.w   $f12, $f12
/* D86EEC 802404EC 0C00A6C9 */  jal       clamp_angle
/* D86EF0 802404F0 E6220004 */   swc1     $f2, 4($s1)
/* D86EF4 802404F4 4600010D */  trunc.w.s $f4, $f0
/* D86EF8 802404F8 44022000 */  mfc1      $v0, $f4
/* D86EFC 802404FC C6200004 */  lwc1      $f0, 4($s1)
/* D86F00 80240500 A622004C */  sh        $v0, 0x4c($s1)
/* D86F04 80240504 C60C0028 */  lwc1      $f12, 0x28($s0)
/* D86F08 80240508 8E060030 */  lw        $a2, 0x30($s0)
/* D86F0C 8024050C 3C0141A0 */  lui       $at, 0x41a0
/* D86F10 80240510 44817000 */  mtc1      $at, $f14
/* D86F14 80240514 E7A00010 */  swc1      $f0, 0x10($sp)
/* D86F18 80240518 C602002C */  lwc1      $f2, 0x2c($s0)
/* D86F1C 8024051C C6200008 */  lwc1      $f0, 8($s1)
/* D86F20 80240520 E7A00014 */  swc1      $f0, 0x14($sp)
/* D86F24 80240524 8E270000 */  lw        $a3, ($s1)
/* D86F28 80240528 0C00A7CB */  jal       dist3D
/* D86F2C 8024052C 460E1380 */   add.s    $f14, $f2, $f14
/* D86F30 80240530 3C0141F0 */  lui       $at, 0x41f0
/* D86F34 80240534 44811000 */  mtc1      $at, $f2
/* D86F38 80240538 00000000 */  nop
/* D86F3C 8024053C 4600103C */  c.lt.s    $f2, $f0
/* D86F40 80240540 00000000 */  nop
/* D86F44 80240544 45010002 */  bc1t      .L80240550
/* D86F48 80240548 24020003 */   addiu    $v0, $zero, 3
.L8024054C:
/* D86F4C 8024054C A622004E */  sh        $v0, 0x4e($s1)
.L80240550:
/* D86F50 80240550 86230048 */  lh        $v1, 0x48($s1)
/* D86F54 80240554 24020001 */  addiu     $v0, $zero, 1
/* D86F58 80240558 10620005 */  beq       $v1, $v0, .L80240570
/* D86F5C 8024055C 24020002 */   addiu    $v0, $zero, 2
/* D86F60 80240560 10620008 */  beq       $v1, $v0, .L80240584
/* D86F64 80240564 00000000 */   nop
/* D86F68 80240568 08090171 */  j         .L802405C4
/* D86F6C 8024056C 00000000 */   nop
.L80240570:
/* D86F70 80240570 C620002C */  lwc1      $f0, 0x2c($s1)
/* D86F74 80240574 C62C0030 */  lwc1      $f12, 0x30($s1)
/* D86F78 80240578 0C00A6C9 */  jal       clamp_angle
/* D86F7C 8024057C 460C0300 */   add.s    $f12, $f0, $f12
/* D86F80 80240580 E620002C */  swc1      $f0, 0x2c($s1)
.L80240584:
/* D86F84 80240584 8E220054 */  lw        $v0, 0x54($s1)
/* D86F88 80240588 C620002C */  lwc1      $f0, 0x2c($s1)
/* D86F8C 8024058C 8C42000C */  lw        $v0, 0xc($v0)
/* D86F90 80240590 E4400024 */  swc1      $f0, 0x24($v0)
/* D86F94 80240594 8E220054 */  lw        $v0, 0x54($s1)
/* D86F98 80240598 C6200018 */  lwc1      $f0, 0x18($s1)
/* D86F9C 8024059C 8C42000C */  lw        $v0, 0xc($v0)
/* D86FA0 802405A0 E4400004 */  swc1      $f0, 4($v0)
/* D86FA4 802405A4 8E220054 */  lw        $v0, 0x54($s1)
/* D86FA8 802405A8 C6200004 */  lwc1      $f0, 4($s1)
/* D86FAC 802405AC 8C42000C */  lw        $v0, 0xc($v0)
/* D86FB0 802405B0 E4400008 */  swc1      $f0, 8($v0)
/* D86FB4 802405B4 8E220054 */  lw        $v0, 0x54($s1)
/* D86FB8 802405B8 C6200020 */  lwc1      $f0, 0x20($s1)
/* D86FBC 802405BC 8C42000C */  lw        $v0, 0xc($v0)
/* D86FC0 802405C0 E440000C */  swc1      $f0, 0xc($v0)
.L802405C4:
/* D86FC4 802405C4 8FBF0020 */  lw        $ra, 0x20($sp)
/* D86FC8 802405C8 8FB1001C */  lw        $s1, 0x1c($sp)
/* D86FCC 802405CC 8FB00018 */  lw        $s0, 0x18($sp)
/* D86FD0 802405D0 0000102D */  daddu     $v0, $zero, $zero
/* D86FD4 802405D4 03E00008 */  jr        $ra
/* D86FD8 802405D8 27BD0028 */   addiu    $sp, $sp, 0x28
