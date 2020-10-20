.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802401AC_BECF9C
/* BECF9C 802401AC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BECFA0 802401B0 AFBF0020 */  sw        $ra, 0x20($sp)
/* BECFA4 802401B4 AFB1001C */  sw        $s1, 0x1c($sp)
/* BECFA8 802401B8 AFB00018 */  sw        $s0, 0x18($sp)
/* BECFAC 802401BC 8C910084 */  lw        $s1, 0x84($a0)
/* BECFB0 802401C0 86230044 */  lh        $v1, 0x44($s1)
/* BECFB4 802401C4 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* BECFB8 802401C8 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* BECFBC 802401CC 2C620005 */  sltiu     $v0, $v1, 5
/* BECFC0 802401D0 1040008A */  beqz      $v0, .L802403FC
/* BECFC4 802401D4 00031080 */   sll      $v0, $v1, 2
/* BECFC8 802401D8 3C018024 */  lui       $at, 0x8024
/* BECFCC 802401DC 00220821 */  addu      $at, $at, $v0
/* BECFD0 802401E0 8C227900 */  lw        $v0, 0x7900($at)
/* BECFD4 802401E4 00400008 */  jr        $v0
/* BECFD8 802401E8 00000000 */   nop      
/* BECFDC 802401EC 8E22003C */  lw        $v0, 0x3c($s1)
/* BECFE0 802401F0 86270046 */  lh        $a3, 0x46($s1)
/* BECFE4 802401F4 AFA20010 */  sw        $v0, 0x10($sp)
/* BECFE8 802401F8 8E250010 */  lw        $a1, 0x10($s1)
/* BECFEC 802401FC 8E26001C */  lw        $a2, 0x1c($s1)
/* BECFF0 80240200 0C00A8ED */  jal       update_lerp
/* BECFF4 80240204 24040005 */   addiu    $a0, $zero, 5
/* BECFF8 80240208 86270046 */  lh        $a3, 0x46($s1)
/* BECFFC 8024020C 8E22003C */  lw        $v0, 0x3c($s1)
/* BED000 80240210 E6200004 */  swc1      $f0, 4($s1)
/* BED004 80240214 AFA20010 */  sw        $v0, 0x10($sp)
/* BED008 80240218 8E25000C */  lw        $a1, 0xc($s1)
/* BED00C 8024021C 8E260018 */  lw        $a2, 0x18($s1)
/* BED010 80240220 0C00A8ED */  jal       update_lerp
/* BED014 80240224 0000202D */   daddu    $a0, $zero, $zero
/* BED018 80240228 86270046 */  lh        $a3, 0x46($s1)
/* BED01C 8024022C 8E22003C */  lw        $v0, 0x3c($s1)
/* BED020 80240230 E6200000 */  swc1      $f0, ($s1)
/* BED024 80240234 AFA20010 */  sw        $v0, 0x10($sp)
/* BED028 80240238 8E250014 */  lw        $a1, 0x14($s1)
/* BED02C 8024023C 8E260020 */  lw        $a2, 0x20($s1)
/* BED030 80240240 0C00A8ED */  jal       update_lerp
/* BED034 80240244 0000202D */   daddu    $a0, $zero, $zero
/* BED038 80240248 8E220050 */  lw        $v0, 0x50($s1)
/* BED03C 8024024C E6200008 */  swc1      $f0, 8($s1)
/* BED040 80240250 C6200000 */  lwc1      $f0, ($s1)
/* BED044 80240254 8C42000C */  lw        $v0, 0xc($v0)
/* BED048 80240258 E4400008 */  swc1      $f0, 8($v0)
/* BED04C 8024025C 8E220050 */  lw        $v0, 0x50($s1)
/* BED050 80240260 C6200004 */  lwc1      $f0, 4($s1)
/* BED054 80240264 8C42000C */  lw        $v0, 0xc($v0)
/* BED058 80240268 E440000C */  swc1      $f0, 0xc($v0)
/* BED05C 8024026C 8E220050 */  lw        $v0, 0x50($s1)
/* BED060 80240270 C6200008 */  lwc1      $f0, 8($s1)
/* BED064 80240274 8C42000C */  lw        $v0, 0xc($v0)
/* BED068 80240278 E4400010 */  swc1      $f0, 0x10($v0)
/* BED06C 8024027C 96220046 */  lhu       $v0, 0x46($s1)
/* BED070 80240280 8E23003C */  lw        $v1, 0x3c($s1)
/* BED074 80240284 24420001 */  addiu     $v0, $v0, 1
/* BED078 80240288 A6220046 */  sh        $v0, 0x46($s1)
/* BED07C 8024028C 00021400 */  sll       $v0, $v0, 0x10
/* BED080 80240290 00021403 */  sra       $v0, $v0, 0x10
/* BED084 80240294 0043102A */  slt       $v0, $v0, $v1
/* BED088 80240298 14400058 */  bnez      $v0, .L802403FC
/* BED08C 8024029C 24020001 */   addiu    $v0, $zero, 1
/* BED090 802402A0 A6220044 */  sh        $v0, 0x44($s1)
/* BED094 802402A4 080900FF */  j         .L802403FC
/* BED098 802402A8 A6200046 */   sh       $zero, 0x46($s1)
/* BED09C 802402AC 96220046 */  lhu       $v0, 0x46($s1)
/* BED0A0 802402B0 24420001 */  addiu     $v0, $v0, 1
/* BED0A4 802402B4 A6220046 */  sh        $v0, 0x46($s1)
/* BED0A8 802402B8 00021400 */  sll       $v0, $v0, 0x10
/* BED0AC 802402BC 00021403 */  sra       $v0, $v0, 0x10
/* BED0B0 802402C0 2842003C */  slti      $v0, $v0, 0x3c
/* BED0B4 802402C4 1440004D */  bnez      $v0, .L802403FC
/* BED0B8 802402C8 24020002 */   addiu    $v0, $zero, 2
/* BED0BC 802402CC 8E230050 */  lw        $v1, 0x50($s1)
/* BED0C0 802402D0 A6220044 */  sh        $v0, 0x44($s1)
/* BED0C4 802402D4 A6200046 */  sh        $zero, 0x46($s1)
/* BED0C8 802402D8 8C63000C */  lw        $v1, 0xc($v1)
/* BED0CC 802402DC 24020001 */  addiu     $v0, $zero, 1
/* BED0D0 802402E0 AC620070 */  sw        $v0, 0x70($v1)
/* BED0D4 802402E4 8E220050 */  lw        $v0, 0x50($s1)
/* BED0D8 802402E8 8C42000C */  lw        $v0, 0xc($v0)
/* BED0DC 802402EC 080900FF */  j         .L802403FC
/* BED0E0 802402F0 AC400074 */   sw       $zero, 0x74($v0)
/* BED0E4 802402F4 96220046 */  lhu       $v0, 0x46($s1)
/* BED0E8 802402F8 24420001 */  addiu     $v0, $v0, 1
/* BED0EC 802402FC A6220046 */  sh        $v0, 0x46($s1)
/* BED0F0 80240300 00021400 */  sll       $v0, $v0, 0x10
/* BED0F4 80240304 00021403 */  sra       $v0, $v0, 0x10
/* BED0F8 80240308 2842003C */  slti      $v0, $v0, 0x3c
/* BED0FC 8024030C 1440003B */  bnez      $v0, .L802403FC
/* BED100 80240310 00000000 */   nop      
/* BED104 80240314 3C013F80 */  lui       $at, 0x3f80
/* BED108 80240318 44810000 */  mtc1      $at, $f0
/* BED10C 8024031C AFA00014 */  sw        $zero, 0x14($sp)
/* BED110 80240320 E7A00010 */  swc1      $f0, 0x10($sp)
/* BED114 80240324 8E250018 */  lw        $a1, 0x18($s1)
/* BED118 80240328 8E26001C */  lw        $a2, 0x1c($s1)
/* BED11C 8024032C 8E270020 */  lw        $a3, 0x20($s1)
/* BED120 80240330 0C01C9AC */  jal       func_800726B0
/* BED124 80240334 24040001 */   addiu    $a0, $zero, 1
/* BED128 80240338 AE220054 */  sw        $v0, 0x54($s1)
/* BED12C 8024033C 8C43000C */  lw        $v1, 0xc($v0)
/* BED130 80240340 9222003B */  lbu       $v0, 0x3b($s1)
/* BED134 80240344 A0620034 */  sb        $v0, 0x34($v1)
/* BED138 80240348 8E220054 */  lw        $v0, 0x54($s1)
/* BED13C 8024034C 8C42000C */  lw        $v0, 0xc($v0)
/* BED140 80240350 AC400020 */  sw        $zero, 0x20($v0)
/* BED144 80240354 8E250018 */  lw        $a1, 0x18($s1)
/* BED148 80240358 8E260028 */  lw        $a2, 0x28($s1)
/* BED14C 8024035C 8E270020 */  lw        $a3, 0x20($s1)
/* BED150 80240360 0C044898 */  jal       create_shadow_type
/* BED154 80240364 0000202D */   daddu    $a0, $zero, $zero
/* BED158 80240368 3C014210 */  lui       $at, 0x4210
/* BED15C 8024036C 44810000 */  mtc1      $at, $f0
/* BED160 80240370 AE220040 */  sw        $v0, 0x40($s1)
/* BED164 80240374 24020003 */  addiu     $v0, $zero, 3
/* BED168 80240378 A6220044 */  sh        $v0, 0x44($s1)
/* BED16C 8024037C 24020001 */  addiu     $v0, $zero, 1
/* BED170 80240380 A6200046 */  sh        $zero, 0x46($s1)
/* BED174 80240384 AE20002C */  sw        $zero, 0x2c($s1)
/* BED178 80240388 A6220048 */  sh        $v0, 0x48($s1)
/* BED17C 8024038C 080900FF */  j         .L802403FC
/* BED180 80240390 E6200030 */   swc1     $f0, 0x30($s1)
/* BED184 80240394 0000202D */  daddu     $a0, $zero, $zero
/* BED188 80240398 3C054210 */  lui       $a1, 0x4210
/* BED18C 8024039C 3C064198 */  lui       $a2, 0x4198
/* BED190 802403A0 86270046 */  lh        $a3, 0x46($s1)
/* BED194 802403A4 24020078 */  addiu     $v0, $zero, 0x78
/* BED198 802403A8 0C00A8ED */  jal       update_lerp
/* BED19C 802403AC AFA20010 */   sw       $v0, 0x10($sp)
/* BED1A0 802403B0 96220046 */  lhu       $v0, 0x46($s1)
/* BED1A4 802403B4 E6200030 */  swc1      $f0, 0x30($s1)
/* BED1A8 802403B8 24420001 */  addiu     $v0, $v0, 1
/* BED1AC 802403BC A6220046 */  sh        $v0, 0x46($s1)
/* BED1B0 802403C0 00021400 */  sll       $v0, $v0, 0x10
/* BED1B4 802403C4 00021403 */  sra       $v0, $v0, 0x10
/* BED1B8 802403C8 28420078 */  slti      $v0, $v0, 0x78
/* BED1BC 802403CC 1440000B */  bnez      $v0, .L802403FC
/* BED1C0 802403D0 24030001 */   addiu    $v1, $zero, 1
/* BED1C4 802403D4 C620002C */  lwc1      $f0, 0x2c($s1)
/* BED1C8 802403D8 24020002 */  addiu     $v0, $zero, 2
/* BED1CC 802403DC A6220048 */  sh        $v0, 0x48($s1)
/* BED1D0 802403E0 24020004 */  addiu     $v0, $zero, 4
/* BED1D4 802403E4 A620004C */  sh        $zero, 0x4c($s1)
/* BED1D8 802403E8 A623004A */  sh        $v1, 0x4a($s1)
/* BED1DC 802403EC A623004E */  sh        $v1, 0x4e($s1)
/* BED1E0 802403F0 A6220044 */  sh        $v0, 0x44($s1)
/* BED1E4 802403F4 A6200046 */  sh        $zero, 0x46($s1)
/* BED1E8 802403F8 E6200034 */  swc1      $f0, 0x34($s1)
.L802403FC:
/* BED1EC 802403FC 8623004A */  lh        $v1, 0x4a($s1)
/* BED1F0 80240400 24020001 */  addiu     $v0, $zero, 1
/* BED1F4 80240404 10620005 */  beq       $v1, $v0, .L8024041C
/* BED1F8 80240408 24020002 */   addiu    $v0, $zero, 2
/* BED1FC 8024040C 1062001E */  beq       $v1, $v0, .L80240488
/* BED200 80240410 00000000 */   nop      
/* BED204 80240414 0809014C */  j         .L80240530
/* BED208 80240418 00000000 */   nop      
.L8024041C:
/* BED20C 8024041C 8627004C */  lh        $a3, 0x4c($s1)
/* BED210 80240420 24100078 */  addiu     $s0, $zero, 0x78
/* BED214 80240424 AFB00010 */  sw        $s0, 0x10($sp)
/* BED218 80240428 8E250034 */  lw        $a1, 0x34($s1)
/* BED21C 8024042C 3C0644B4 */  lui       $a2, 0x44b4
/* BED220 80240430 0C00A8ED */  jal       update_lerp
/* BED224 80240434 24040004 */   addiu    $a0, $zero, 4
/* BED228 80240438 8627004C */  lh        $a3, 0x4c($s1)
/* BED22C 8024043C E620002C */  swc1      $f0, 0x2c($s1)
/* BED230 80240440 AFB00010 */  sw        $s0, 0x10($sp)
/* BED234 80240444 8E25001C */  lw        $a1, 0x1c($s1)
/* BED238 80240448 8E260024 */  lw        $a2, 0x24($s1)
/* BED23C 8024044C 0C00A8ED */  jal       update_lerp
/* BED240 80240450 2404000A */   addiu    $a0, $zero, 0xa
/* BED244 80240454 9622004C */  lhu       $v0, 0x4c($s1)
/* BED248 80240458 E6200004 */  swc1      $f0, 4($s1)
/* BED24C 8024045C 24420001 */  addiu     $v0, $v0, 1
/* BED250 80240460 A622004C */  sh        $v0, 0x4c($s1)
/* BED254 80240464 00021400 */  sll       $v0, $v0, 0x10
/* BED258 80240468 00021403 */  sra       $v0, $v0, 0x10
/* BED25C 8024046C 0050102A */  slt       $v0, $v0, $s0
/* BED260 80240470 1440002F */  bnez      $v0, .L80240530
/* BED264 80240474 2402010E */   addiu    $v0, $zero, 0x10e
/* BED268 80240478 A622004C */  sh        $v0, 0x4c($s1)
/* BED26C 8024047C 24020002 */  addiu     $v0, $zero, 2
/* BED270 80240480 0809014B */  j         .L8024052C
/* BED274 80240484 A622004A */   sh       $v0, 0x4a($s1)
.L80240488:
/* BED278 80240488 8622004C */  lh        $v0, 0x4c($s1)
/* BED27C 8024048C 44826000 */  mtc1      $v0, $f12
/* BED280 80240490 00000000 */  nop       
/* BED284 80240494 0C00A8BB */  jal       sin_deg
/* BED288 80240498 46806320 */   cvt.s.w  $f12, $f12
/* BED28C 8024049C 3C013F80 */  lui       $at, 0x3f80
/* BED290 802404A0 44811000 */  mtc1      $at, $f2
/* BED294 802404A4 00000000 */  nop       
/* BED298 802404A8 46020000 */  add.s     $f0, $f0, $f2
/* BED29C 802404AC 46000000 */  add.s     $f0, $f0, $f0
/* BED2A0 802404B0 C6220024 */  lwc1      $f2, 0x24($s1)
/* BED2A4 802404B4 8622004C */  lh        $v0, 0x4c($s1)
/* BED2A8 802404B8 46001080 */  add.s     $f2, $f2, $f0
/* BED2AC 802404BC 24420008 */  addiu     $v0, $v0, 8
/* BED2B0 802404C0 44826000 */  mtc1      $v0, $f12
/* BED2B4 802404C4 00000000 */  nop       
/* BED2B8 802404C8 46806320 */  cvt.s.w   $f12, $f12
/* BED2BC 802404CC 0C00A6C9 */  jal       clamp_angle
/* BED2C0 802404D0 E6220004 */   swc1     $f2, 4($s1)
/* BED2C4 802404D4 4600010D */  trunc.w.s $f4, $f0
/* BED2C8 802404D8 44022000 */  mfc1      $v0, $f4
/* BED2CC 802404DC C6200004 */  lwc1      $f0, 4($s1)
/* BED2D0 802404E0 A622004C */  sh        $v0, 0x4c($s1)
/* BED2D4 802404E4 C60C0028 */  lwc1      $f12, 0x28($s0)
/* BED2D8 802404E8 8E060030 */  lw        $a2, 0x30($s0)
/* BED2DC 802404EC 3C0141A0 */  lui       $at, 0x41a0
/* BED2E0 802404F0 44817000 */  mtc1      $at, $f14
/* BED2E4 802404F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* BED2E8 802404F8 C602002C */  lwc1      $f2, 0x2c($s0)
/* BED2EC 802404FC C6200008 */  lwc1      $f0, 8($s1)
/* BED2F0 80240500 E7A00014 */  swc1      $f0, 0x14($sp)
/* BED2F4 80240504 8E270000 */  lw        $a3, ($s1)
/* BED2F8 80240508 0C00A7CB */  jal       dist3D
/* BED2FC 8024050C 460E1380 */   add.s    $f14, $f2, $f14
/* BED300 80240510 3C0141F0 */  lui       $at, 0x41f0
/* BED304 80240514 44811000 */  mtc1      $at, $f2
/* BED308 80240518 00000000 */  nop       
/* BED30C 8024051C 4600103C */  c.lt.s    $f2, $f0
/* BED310 80240520 00000000 */  nop       
/* BED314 80240524 45010002 */  bc1t      .L80240530
/* BED318 80240528 24020003 */   addiu    $v0, $zero, 3
.L8024052C:
/* BED31C 8024052C A622004E */  sh        $v0, 0x4e($s1)
.L80240530:
/* BED320 80240530 86230048 */  lh        $v1, 0x48($s1)
/* BED324 80240534 24020001 */  addiu     $v0, $zero, 1
/* BED328 80240538 10620005 */  beq       $v1, $v0, .L80240550
/* BED32C 8024053C 24020002 */   addiu    $v0, $zero, 2
/* BED330 80240540 10620008 */  beq       $v1, $v0, .L80240564
/* BED334 80240544 00000000 */   nop      
/* BED338 80240548 08090169 */  j         .L802405A4
/* BED33C 8024054C 00000000 */   nop      
.L80240550:
/* BED340 80240550 C620002C */  lwc1      $f0, 0x2c($s1)
/* BED344 80240554 C62C0030 */  lwc1      $f12, 0x30($s1)
/* BED348 80240558 0C00A6C9 */  jal       clamp_angle
/* BED34C 8024055C 460C0300 */   add.s    $f12, $f0, $f12
/* BED350 80240560 E620002C */  swc1      $f0, 0x2c($s1)
.L80240564:
/* BED354 80240564 8E220054 */  lw        $v0, 0x54($s1)
/* BED358 80240568 C620002C */  lwc1      $f0, 0x2c($s1)
/* BED35C 8024056C 8C42000C */  lw        $v0, 0xc($v0)
/* BED360 80240570 E4400024 */  swc1      $f0, 0x24($v0)
/* BED364 80240574 8E220054 */  lw        $v0, 0x54($s1)
/* BED368 80240578 C6200018 */  lwc1      $f0, 0x18($s1)
/* BED36C 8024057C 8C42000C */  lw        $v0, 0xc($v0)
/* BED370 80240580 E4400004 */  swc1      $f0, 4($v0)
/* BED374 80240584 8E220054 */  lw        $v0, 0x54($s1)
/* BED378 80240588 C6200004 */  lwc1      $f0, 4($s1)
/* BED37C 8024058C 8C42000C */  lw        $v0, 0xc($v0)
/* BED380 80240590 E4400008 */  swc1      $f0, 8($v0)
/* BED384 80240594 8E220054 */  lw        $v0, 0x54($s1)
/* BED388 80240598 C6200020 */  lwc1      $f0, 0x20($s1)
/* BED38C 8024059C 8C42000C */  lw        $v0, 0xc($v0)
/* BED390 802405A0 E440000C */  swc1      $f0, 0xc($v0)
.L802405A4:
/* BED394 802405A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* BED398 802405A8 8FB1001C */  lw        $s1, 0x1c($sp)
/* BED39C 802405AC 8FB00018 */  lw        $s0, 0x18($sp)
/* BED3A0 802405B0 0000102D */  daddu     $v0, $zero, $zero
/* BED3A4 802405B4 03E00008 */  jr        $ra
/* BED3A8 802405B8 27BD0028 */   addiu    $sp, $sp, 0x28
