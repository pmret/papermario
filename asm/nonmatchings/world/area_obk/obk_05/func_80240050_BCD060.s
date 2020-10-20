.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_BCD0B0
/* BCD0B0 80240050 27BDFF70 */  addiu     $sp, $sp, -0x90
/* BCD0B4 80240054 AFB20070 */  sw        $s2, 0x70($sp)
/* BCD0B8 80240058 AFB30074 */  sw        $s3, 0x74($sp)
/* BCD0BC 8024005C 3C138011 */  lui       $s3, %hi(gPlayerStatus)
/* BCD0C0 80240060 2673EFC8 */  addiu     $s3, $s3, %lo(gPlayerStatus)
/* BCD0C4 80240064 AFB00068 */  sw        $s0, 0x68($sp)
/* BCD0C8 80240068 3C108016 */  lui       $s0, 0x8016
/* BCD0CC 8024006C 2610A550 */  addiu     $s0, $s0, -0x5ab0
/* BCD0D0 80240070 AFBF0078 */  sw        $ra, 0x78($sp)
/* BCD0D4 80240074 AFB1006C */  sw        $s1, 0x6c($sp)
/* BCD0D8 80240078 F7B60088 */  sdc1      $f22, 0x88($sp)
/* BCD0DC 8024007C F7B40080 */  sdc1      $f20, 0x80($sp)
/* BCD0E0 80240080 10A00014 */  beqz      $a1, .L802400D4
/* BCD0E4 80240084 0080902D */   daddu    $s2, $a0, $zero
/* BCD0E8 80240088 0C00AB39 */  jal       heap_malloc
/* BCD0EC 8024008C 24040020 */   addiu    $a0, $zero, 0x20
/* BCD0F0 80240090 3C013DCC */  lui       $at, 0x3dcc
/* BCD0F4 80240094 3421CCCD */  ori       $at, $at, 0xcccd
/* BCD0F8 80240098 44810000 */  mtc1      $at, $f0
/* BCD0FC 8024009C 3C014040 */  lui       $at, 0x4040
/* BCD100 802400A0 44811000 */  mtc1      $at, $f2
/* BCD104 802400A4 0040882D */  daddu     $s1, $v0, $zero
/* BCD108 802400A8 AE510074 */  sw        $s1, 0x74($s2)
/* BCD10C 802400AC AE200000 */  sw        $zero, ($s1)
/* BCD110 802400B0 AE20000C */  sw        $zero, 0xc($s1)
/* BCD114 802400B4 AE200008 */  sw        $zero, 8($s1)
/* BCD118 802400B8 AE200010 */  sw        $zero, 0x10($s1)
/* BCD11C 802400BC AE200014 */  sw        $zero, 0x14($s1)
/* BCD120 802400C0 E6200004 */  swc1      $f0, 4($s1)
/* BCD124 802400C4 E6220018 */  swc1      $f2, 0x18($s1)
/* BCD128 802400C8 AE400070 */  sw        $zero, 0x70($s2)
/* BCD12C 802400CC AE400078 */  sw        $zero, 0x78($s2)
/* BCD130 802400D0 AE40007C */  sw        $zero, 0x7c($s2)
.L802400D4:
/* BCD134 802400D4 24040001 */  addiu     $a0, $zero, 1
/* BCD138 802400D8 8E430070 */  lw        $v1, 0x70($s2)
/* BCD13C 802400DC 8E510074 */  lw        $s1, 0x74($s2)
/* BCD140 802400E0 10640022 */  beq       $v1, $a0, .L8024016C
/* BCD144 802400E4 28620002 */   slti     $v0, $v1, 2
/* BCD148 802400E8 50400005 */  beql      $v0, $zero, .L80240100
/* BCD14C 802400EC 24020002 */   addiu    $v0, $zero, 2
/* BCD150 802400F0 10600007 */  beqz      $v1, .L80240110
/* BCD154 802400F4 2402000A */   addiu    $v0, $zero, 0xa
/* BCD158 802400F8 0809015C */  j         .L80240570
/* BCD15C 802400FC 00000000 */   nop      
.L80240100:
/* BCD160 80240100 106200BF */  beq       $v1, $v0, .L80240400
/* BCD164 80240104 2402000A */   addiu    $v0, $zero, 0xa
/* BCD168 80240108 0809015C */  j         .L80240570
/* BCD16C 8024010C 00000000 */   nop      
.L80240110:
/* BCD170 80240110 86030002 */  lh        $v1, 2($s0)
/* BCD174 80240114 50620001 */  beql      $v1, $v0, .L8024011C
/* BCD178 80240118 AE440070 */   sw       $a0, 0x70($s2)
.L8024011C:
/* BCD17C 8024011C 86030002 */  lh        $v1, 2($s0)
/* BCD180 80240120 24020009 */  addiu     $v0, $zero, 9
/* BCD184 80240124 50620001 */  beql      $v1, $v0, .L8024012C
/* BCD188 80240128 AE440070 */   sw       $a0, 0x70($s2)
.L8024012C:
/* BCD18C 8024012C 3C013DCC */  lui       $at, 0x3dcc
/* BCD190 80240130 3421CCCD */  ori       $at, $at, 0xcccd
/* BCD194 80240134 44810000 */  mtc1      $at, $f0
/* BCD198 80240138 3C014040 */  lui       $at, 0x4040
/* BCD19C 8024013C 44811000 */  mtc1      $at, $f2
/* BCD1A0 80240140 3C0141A0 */  lui       $at, 0x41a0
/* BCD1A4 80240144 44812000 */  mtc1      $at, $f4
/* BCD1A8 80240148 AE200000 */  sw        $zero, ($s1)
/* BCD1AC 8024014C AE20000C */  sw        $zero, 0xc($s1)
/* BCD1B0 80240150 AE200010 */  sw        $zero, 0x10($s1)
/* BCD1B4 80240154 AE200014 */  sw        $zero, 0x14($s1)
/* BCD1B8 80240158 AE200008 */  sw        $zero, 8($s1)
/* BCD1BC 8024015C E6200004 */  swc1      $f0, 4($s1)
/* BCD1C0 80240160 E6220018 */  swc1      $f2, 0x18($s1)
/* BCD1C4 80240164 0809015C */  j         .L80240570
/* BCD1C8 80240168 E624001C */   swc1     $f4, 0x1c($s1)
.L8024016C:
/* BCD1CC 8024016C 86030002 */  lh        $v1, 2($s0)
/* BCD1D0 80240170 2402000A */  addiu     $v0, $zero, 0xa
/* BCD1D4 80240174 10620006 */  beq       $v1, $v0, .L80240190
/* BCD1D8 80240178 24020009 */   addiu    $v0, $zero, 9
/* BCD1DC 8024017C 10620004 */  beq       $v1, $v0, .L80240190
/* BCD1E0 80240180 24020078 */   addiu    $v0, $zero, 0x78
/* BCD1E4 80240184 AE42007C */  sw        $v0, 0x7c($s2)
/* BCD1E8 80240188 24020002 */  addiu     $v0, $zero, 2
/* BCD1EC 8024018C AE420070 */  sw        $v0, 0x70($s2)
.L80240190:
/* BCD1F0 80240190 C6200008 */  lwc1      $f0, 8($s1)
/* BCD1F4 80240194 3C0140A0 */  lui       $at, 0x40a0
/* BCD1F8 80240198 44811000 */  mtc1      $at, $f2
/* BCD1FC 8024019C 46000005 */  abs.s     $f0, $f0
/* BCD200 802401A0 4602003C */  c.lt.s    $f0, $f2
/* BCD204 802401A4 00000000 */  nop       
/* BCD208 802401A8 4500000D */  bc1f      .L802401E0
/* BCD20C 802401AC 00000000 */   nop      
/* BCD210 802401B0 C6600028 */  lwc1      $f0, 0x28($s3)
/* BCD214 802401B4 44801000 */  mtc1      $zero, $f2
/* BCD218 802401B8 44801800 */  mtc1      $zero, $f3
/* BCD21C 802401BC 46000021 */  cvt.d.s   $f0, $f0
/* BCD220 802401C0 46201081 */  sub.d     $f2, $f2, $f0
/* BCD224 802401C4 3C014348 */  lui       $at, 0x4348
/* BCD228 802401C8 44810000 */  mtc1      $at, $f0
/* BCD22C 802401CC 462010A0 */  cvt.s.d   $f2, $f2
/* BCD230 802401D0 46001085 */  abs.s     $f2, $f2
/* BCD234 802401D4 46001083 */  div.s     $f2, $f2, $f0
/* BCD238 802401D8 0809007D */  j         .L802401F4
/* BCD23C 802401DC E6220004 */   swc1     $f2, 4($s1)
.L802401E0:
/* BCD240 802401E0 3C013DCC */  lui       $at, 0x3dcc
/* BCD244 802401E4 3421CCCD */  ori       $at, $at, 0xcccd
/* BCD248 802401E8 44810000 */  mtc1      $at, $f0
/* BCD24C 802401EC 00000000 */  nop       
/* BCD250 802401F0 E6200004 */  swc1      $f0, 4($s1)
.L802401F4:
/* BCD254 802401F4 C6600028 */  lwc1      $f0, 0x28($s3)
/* BCD258 802401F8 44802000 */  mtc1      $zero, $f4
/* BCD25C 802401FC 44802800 */  mtc1      $zero, $f5
/* BCD260 80240200 46000021 */  cvt.d.s   $f0, $f0
/* BCD264 80240204 4624003E */  c.le.d    $f0, $f4
/* BCD268 80240208 00000000 */  nop       
/* BCD26C 8024020C 45000024 */  bc1f      .L802402A0
/* BCD270 80240210 00000000 */   nop      
/* BCD274 80240214 C6200010 */  lwc1      $f0, 0x10($s1)
/* BCD278 80240218 C6220004 */  lwc1      $f2, 4($s1)
/* BCD27C 8024021C 46020000 */  add.s     $f0, $f0, $f2
/* BCD280 80240220 E6200010 */  swc1      $f0, 0x10($s1)
/* BCD284 80240224 C6600028 */  lwc1      $f0, 0x28($s3)
/* BCD288 80240228 46000021 */  cvt.d.s   $f0, $f0
/* BCD28C 8024022C 46202001 */  sub.d     $f0, $f4, $f0
/* BCD290 80240230 46200020 */  cvt.s.d   $f0, $f0
/* BCD294 80240234 46000005 */  abs.s     $f0, $f0
/* BCD298 80240238 46000002 */  mul.s     $f0, $f0, $f0
/* BCD29C 8024023C 00000000 */  nop       
/* BCD2A0 80240240 3C014248 */  lui       $at, 0x4248
/* BCD2A4 80240244 44811000 */  mtc1      $at, $f2
/* BCD2A8 80240248 3C014170 */  lui       $at, 0x4170
/* BCD2AC 8024024C 44812000 */  mtc1      $at, $f4
/* BCD2B0 80240250 46020003 */  div.s     $f0, $f0, $f2
/* BCD2B4 80240254 4600203C */  c.lt.s    $f4, $f0
/* BCD2B8 80240258 00000000 */  nop       
/* BCD2BC 8024025C 45000002 */  bc1f      .L80240268
/* BCD2C0 80240260 E620001C */   swc1     $f0, 0x1c($s1)
/* BCD2C4 80240264 E624001C */  swc1      $f4, 0x1c($s1)
.L80240268:
/* BCD2C8 80240268 C6220008 */  lwc1      $f2, 8($s1)
/* BCD2CC 8024026C C620001C */  lwc1      $f0, 0x1c($s1)
/* BCD2D0 80240270 4602003C */  c.lt.s    $f0, $f2
/* BCD2D4 80240274 00000000 */  nop       
/* BCD2D8 80240278 45000031 */  bc1f      .L80240340
/* BCD2DC 8024027C 00000000 */   nop      
/* BCD2E0 80240280 C6200004 */  lwc1      $f0, 4($s1)
/* BCD2E4 80240284 C6220018 */  lwc1      $f2, 0x18($s1)
/* BCD2E8 80240288 46020002 */  mul.s     $f0, $f0, $f2
/* BCD2EC 8024028C 00000000 */  nop       
/* BCD2F0 80240290 C6220014 */  lwc1      $f2, 0x14($s1)
/* BCD2F4 80240294 46001080 */  add.s     $f2, $f2, $f0
/* BCD2F8 80240298 080900D0 */  j         .L80240340
/* BCD2FC 8024029C E6220014 */   swc1     $f2, 0x14($s1)
.L802402A0:
/* BCD300 802402A0 C6200014 */  lwc1      $f0, 0x14($s1)
/* BCD304 802402A4 C6220004 */  lwc1      $f2, 4($s1)
/* BCD308 802402A8 46020000 */  add.s     $f0, $f0, $f2
/* BCD30C 802402AC E6200014 */  swc1      $f0, 0x14($s1)
/* BCD310 802402B0 C6600028 */  lwc1      $f0, 0x28($s3)
/* BCD314 802402B4 46000021 */  cvt.d.s   $f0, $f0
/* BCD318 802402B8 46202001 */  sub.d     $f0, $f4, $f0
/* BCD31C 802402BC 3C013F00 */  lui       $at, 0x3f00
/* BCD320 802402C0 44811000 */  mtc1      $at, $f2
/* BCD324 802402C4 46200020 */  cvt.s.d   $f0, $f0
/* BCD328 802402C8 46000005 */  abs.s     $f0, $f0
/* BCD32C 802402CC 46000007 */  neg.s     $f0, $f0
/* BCD330 802402D0 46020002 */  mul.s     $f0, $f0, $f2
/* BCD334 802402D4 00000000 */  nop       
/* BCD338 802402D8 46000002 */  mul.s     $f0, $f0, $f0
/* BCD33C 802402DC 00000000 */  nop       
/* BCD340 802402E0 3C01C0A0 */  lui       $at, 0xc0a0
/* BCD344 802402E4 44812000 */  mtc1      $at, $f4
/* BCD348 802402E8 3C014248 */  lui       $at, 0x4248
/* BCD34C 802402EC 44811000 */  mtc1      $at, $f2
/* BCD350 802402F0 46000007 */  neg.s     $f0, $f0
/* BCD354 802402F4 46020003 */  div.s     $f0, $f0, $f2
/* BCD358 802402F8 4604003C */  c.lt.s    $f0, $f4
/* BCD35C 802402FC 00000000 */  nop       
/* BCD360 80240300 45000002 */  bc1f      .L8024030C
/* BCD364 80240304 E620001C */   swc1     $f0, 0x1c($s1)
/* BCD368 80240308 E624001C */  swc1      $f4, 0x1c($s1)
.L8024030C:
/* BCD36C 8024030C C6220008 */  lwc1      $f2, 8($s1)
/* BCD370 80240310 C620001C */  lwc1      $f0, 0x1c($s1)
/* BCD374 80240314 4600103C */  c.lt.s    $f2, $f0
/* BCD378 80240318 00000000 */  nop       
/* BCD37C 8024031C 45000008 */  bc1f      .L80240340
/* BCD380 80240320 00000000 */   nop      
/* BCD384 80240324 C6200004 */  lwc1      $f0, 4($s1)
/* BCD388 80240328 C6220018 */  lwc1      $f2, 0x18($s1)
/* BCD38C 8024032C 46020002 */  mul.s     $f0, $f0, $f2
/* BCD390 80240330 00000000 */  nop       
/* BCD394 80240334 C6220010 */  lwc1      $f2, 0x10($s1)
/* BCD398 80240338 46001080 */  add.s     $f2, $f2, $f0
/* BCD39C 8024033C E6220010 */  swc1      $f2, 0x10($s1)
.L80240340:
/* BCD3A0 80240340 C6200010 */  lwc1      $f0, 0x10($s1)
/* BCD3A4 80240344 3C014059 */  lui       $at, 0x4059
/* BCD3A8 80240348 44812800 */  mtc1      $at, $f5
/* BCD3AC 8024034C 44802000 */  mtc1      $zero, $f4
/* BCD3B0 80240350 460000A1 */  cvt.d.s   $f2, $f0
/* BCD3B4 80240354 4622203C */  c.lt.d    $f4, $f2
/* BCD3B8 80240358 00000000 */  nop       
/* BCD3BC 8024035C 4500000F */  bc1f      .L8024039C
/* BCD3C0 80240360 00000000 */   nop      
/* BCD3C4 80240364 C6200014 */  lwc1      $f0, 0x14($s1)
/* BCD3C8 80240368 46000021 */  cvt.d.s   $f0, $f0
/* BCD3CC 8024036C 4620203C */  c.lt.d    $f4, $f0
/* BCD3D0 80240370 00000000 */  nop       
/* BCD3D4 80240374 45000009 */  bc1f      .L8024039C
/* BCD3D8 80240378 00000000 */   nop      
/* BCD3DC 8024037C C6200014 */  lwc1      $f0, 0x14($s1)
/* BCD3E0 80240380 46241081 */  sub.d     $f2, $f2, $f4
/* BCD3E4 80240384 46000021 */  cvt.d.s   $f0, $f0
/* BCD3E8 80240388 46240001 */  sub.d     $f0, $f0, $f4
/* BCD3EC 8024038C 462010A0 */  cvt.s.d   $f2, $f2
/* BCD3F0 80240390 E6220010 */  swc1      $f2, 0x10($s1)
/* BCD3F4 80240394 46200020 */  cvt.s.d   $f0, $f0
/* BCD3F8 80240398 E6200014 */  swc1      $f0, 0x14($s1)
.L8024039C:
/* BCD3FC 8024039C C6240010 */  lwc1      $f4, 0x10($s1)
/* BCD400 802403A0 C6220014 */  lwc1      $f2, 0x14($s1)
/* BCD404 802403A4 46022001 */  sub.s     $f0, $f4, $f2
/* BCD408 802403A8 3C013FF8 */  lui       $at, 0x3ff8
/* BCD40C 802403AC 44813800 */  mtc1      $at, $f7
/* BCD410 802403B0 44803000 */  mtc1      $zero, $f6
/* BCD414 802403B4 46000005 */  abs.s     $f0, $f0
/* BCD418 802403B8 46000021 */  cvt.d.s   $f0, $f0
/* BCD41C 802403BC 4620303C */  c.lt.d    $f6, $f0
/* BCD420 802403C0 00000000 */  nop       
/* BCD424 802403C4 45000063 */  bc1f      .L80240554
/* BCD428 802403C8 00000000 */   nop      
/* BCD42C 802403CC 4602203C */  c.lt.s    $f4, $f2
/* BCD430 802403D0 00000000 */  nop       
/* BCD434 802403D4 45020006 */  bc1fl     .L802403F0
/* BCD438 802403D8 46001021 */   cvt.d.s  $f0, $f2
/* BCD43C 802403DC 46002021 */  cvt.d.s   $f0, $f4
/* BCD440 802403E0 46260000 */  add.d     $f0, $f0, $f6
/* BCD444 802403E4 46200020 */  cvt.s.d   $f0, $f0
/* BCD448 802403E8 08090155 */  j         .L80240554
/* BCD44C 802403EC E6200014 */   swc1     $f0, 0x14($s1)
.L802403F0:
/* BCD450 802403F0 46260000 */  add.d     $f0, $f0, $f6
/* BCD454 802403F4 46200020 */  cvt.s.d   $f0, $f0
/* BCD458 802403F8 08090155 */  j         .L80240554
/* BCD45C 802403FC E6200010 */   swc1     $f0, 0x10($s1)
.L80240400:
/* BCD460 80240400 86030002 */  lh        $v1, 2($s0)
/* BCD464 80240404 50620001 */  beql      $v1, $v0, .L8024040C
/* BCD468 80240408 AE440070 */   sw       $a0, 0x70($s2)
.L8024040C:
/* BCD46C 8024040C 86030002 */  lh        $v1, 2($s0)
/* BCD470 80240410 24020009 */  addiu     $v0, $zero, 9
/* BCD474 80240414 50620001 */  beql      $v1, $v0, .L8024041C
/* BCD478 80240418 AE440070 */   sw       $a0, 0x70($s2)
.L8024041C:
/* BCD47C 8024041C 3C013DCC */  lui       $at, 0x3dcc
/* BCD480 80240420 3421CCCD */  ori       $at, $at, 0xcccd
/* BCD484 80240424 44810000 */  mtc1      $at, $f0
/* BCD488 80240428 C6220010 */  lwc1      $f2, 0x10($s1)
/* BCD48C 8024042C C6240008 */  lwc1      $f4, 8($s1)
/* BCD490 80240430 AE20001C */  sw        $zero, 0x1c($s1)
/* BCD494 80240434 46001080 */  add.s     $f2, $f2, $f0
/* BCD498 80240438 E6200004 */  swc1      $f0, 4($s1)
/* BCD49C 8024043C C620001C */  lwc1      $f0, 0x1c($s1)
/* BCD4A0 80240440 4604003C */  c.lt.s    $f0, $f4
/* BCD4A4 80240444 00000000 */  nop       
/* BCD4A8 80240448 45000008 */  bc1f      .L8024046C
/* BCD4AC 8024044C E6220010 */   swc1     $f2, 0x10($s1)
/* BCD4B0 80240450 C6200004 */  lwc1      $f0, 4($s1)
/* BCD4B4 80240454 C6220018 */  lwc1      $f2, 0x18($s1)
/* BCD4B8 80240458 46020002 */  mul.s     $f0, $f0, $f2
/* BCD4BC 8024045C 00000000 */  nop       
/* BCD4C0 80240460 C6220014 */  lwc1      $f2, 0x14($s1)
/* BCD4C4 80240464 46001080 */  add.s     $f2, $f2, $f0
/* BCD4C8 80240468 E6220014 */  swc1      $f2, 0x14($s1)
.L8024046C:
/* BCD4CC 8024046C C6200010 */  lwc1      $f0, 0x10($s1)
/* BCD4D0 80240470 3C014059 */  lui       $at, 0x4059
/* BCD4D4 80240474 44812800 */  mtc1      $at, $f5
/* BCD4D8 80240478 44802000 */  mtc1      $zero, $f4
/* BCD4DC 8024047C 460000A1 */  cvt.d.s   $f2, $f0
/* BCD4E0 80240480 4622203C */  c.lt.d    $f4, $f2
/* BCD4E4 80240484 00000000 */  nop       
/* BCD4E8 80240488 4500000F */  bc1f      .L802404C8
/* BCD4EC 8024048C 00000000 */   nop      
/* BCD4F0 80240490 C6200014 */  lwc1      $f0, 0x14($s1)
/* BCD4F4 80240494 46000021 */  cvt.d.s   $f0, $f0
/* BCD4F8 80240498 4620203C */  c.lt.d    $f4, $f0
/* BCD4FC 8024049C 00000000 */  nop       
/* BCD500 802404A0 45000009 */  bc1f      .L802404C8
/* BCD504 802404A4 00000000 */   nop      
/* BCD508 802404A8 C6200014 */  lwc1      $f0, 0x14($s1)
/* BCD50C 802404AC 46241081 */  sub.d     $f2, $f2, $f4
/* BCD510 802404B0 46000021 */  cvt.d.s   $f0, $f0
/* BCD514 802404B4 46240001 */  sub.d     $f0, $f0, $f4
/* BCD518 802404B8 462010A0 */  cvt.s.d   $f2, $f2
/* BCD51C 802404BC E6220010 */  swc1      $f2, 0x10($s1)
/* BCD520 802404C0 46200020 */  cvt.s.d   $f0, $f0
/* BCD524 802404C4 E6200014 */  swc1      $f0, 0x14($s1)
.L802404C8:
/* BCD528 802404C8 C6240010 */  lwc1      $f4, 0x10($s1)
/* BCD52C 802404CC C6220014 */  lwc1      $f2, 0x14($s1)
/* BCD530 802404D0 46022001 */  sub.s     $f0, $f4, $f2
/* BCD534 802404D4 3C013FE0 */  lui       $at, 0x3fe0
/* BCD538 802404D8 44813800 */  mtc1      $at, $f7
/* BCD53C 802404DC 44803000 */  mtc1      $zero, $f6
/* BCD540 802404E0 46000005 */  abs.s     $f0, $f0
/* BCD544 802404E4 46000021 */  cvt.d.s   $f0, $f0
/* BCD548 802404E8 4620303C */  c.lt.d    $f6, $f0
/* BCD54C 802404EC 00000000 */  nop       
/* BCD550 802404F0 4500000D */  bc1f      .L80240528
/* BCD554 802404F4 00000000 */   nop      
/* BCD558 802404F8 4602203C */  c.lt.s    $f4, $f2
/* BCD55C 802404FC 00000000 */  nop       
/* BCD560 80240500 45020006 */  bc1fl     .L8024051C
/* BCD564 80240504 46001021 */   cvt.d.s  $f0, $f2
/* BCD568 80240508 46002021 */  cvt.d.s   $f0, $f4
/* BCD56C 8024050C 46260000 */  add.d     $f0, $f0, $f6
/* BCD570 80240510 46200020 */  cvt.s.d   $f0, $f0
/* BCD574 80240514 0809014A */  j         .L80240528
/* BCD578 80240518 E6200014 */   swc1     $f0, 0x14($s1)
.L8024051C:
/* BCD57C 8024051C 46260000 */  add.d     $f0, $f0, $f6
/* BCD580 80240520 46200020 */  cvt.s.d   $f0, $f0
/* BCD584 80240524 E6200010 */  swc1      $f0, 0x10($s1)
.L80240528:
/* BCD588 80240528 8E42007C */  lw        $v0, 0x7c($s2)
/* BCD58C 8024052C 04410008 */  bgez      $v0, .L80240550
/* BCD590 80240530 2442FFFF */   addiu    $v0, $v0, -1
/* BCD594 80240534 44800000 */  mtc1      $zero, $f0
/* BCD598 80240538 00000000 */  nop       
/* BCD59C 8024053C E6200014 */  swc1      $f0, 0x14($s1)
/* BCD5A0 80240540 E6200010 */  swc1      $f0, 0x10($s1)
/* BCD5A4 80240544 E6200000 */  swc1      $f0, ($s1)
/* BCD5A8 80240548 08090155 */  j         .L80240554
/* BCD5AC 8024054C E6200008 */   swc1     $f0, 8($s1)
.L80240550:
/* BCD5B0 80240550 AE42007C */  sw        $v0, 0x7c($s2)
.L80240554:
/* BCD5B4 80240554 C6200010 */  lwc1      $f0, 0x10($s1)
/* BCD5B8 80240558 C6220014 */  lwc1      $f2, 0x14($s1)
/* BCD5BC 8024055C 46020001 */  sub.s     $f0, $f0, $f2
/* BCD5C0 80240560 C6220008 */  lwc1      $f2, 8($s1)
/* BCD5C4 80240564 46001080 */  add.s     $f2, $f2, $f0
/* BCD5C8 80240568 E6200000 */  swc1      $f0, ($s1)
/* BCD5CC 8024056C E6220008 */  swc1      $f2, 8($s1)
.L80240570:
/* BCD5D0 80240570 C6220008 */  lwc1      $f2, 8($s1)
/* BCD5D4 80240574 3C01C0E0 */  lui       $at, 0xc0e0
/* BCD5D8 80240578 44810000 */  mtc1      $at, $f0
/* BCD5DC 8024057C 00000000 */  nop       
/* BCD5E0 80240580 4600103E */  c.le.s    $f2, $f0
/* BCD5E4 80240584 00000000 */  nop       
/* BCD5E8 80240588 45000013 */  bc1f      .L802405D8
/* BCD5EC 8024058C 2410FFFF */   addiu    $s0, $zero, -1
/* BCD5F0 80240590 8E420078 */  lw        $v0, 0x78($s2)
/* BCD5F4 80240594 10500011 */  beq       $v0, $s0, .L802405DC
/* BCD5F8 80240598 27A50058 */   addiu    $a1, $sp, 0x58
/* BCD5FC 8024059C 2404000A */  addiu     $a0, $zero, 0xa
/* BCD600 802405A0 27A6005C */  addiu     $a2, $sp, 0x5c
/* BCD604 802405A4 0C016F84 */  jal       get_collider_center
/* BCD608 802405A8 27A70060 */   addiu    $a3, $sp, 0x60
/* BCD60C 802405AC 240401D6 */  addiu     $a0, $zero, 0x1d6
/* BCD610 802405B0 C7A00058 */  lwc1      $f0, 0x58($sp)
/* BCD614 802405B4 C7A2005C */  lwc1      $f2, 0x5c($sp)
/* BCD618 802405B8 44060000 */  mfc1      $a2, $f0
/* BCD61C 802405BC 44071000 */  mfc1      $a3, $f2
/* BCD620 802405C0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* BCD624 802405C4 0000282D */  daddu     $a1, $zero, $zero
/* BCD628 802405C8 0C052757 */  jal       play_sound_at_position
/* BCD62C 802405CC E7A00010 */   swc1     $f0, 0x10($sp)
/* BCD630 802405D0 08090177 */  j         .L802405DC
/* BCD634 802405D4 AE500078 */   sw       $s0, 0x78($s2)
.L802405D8:
/* BCD638 802405D8 AE400078 */  sw        $zero, 0x78($s2)
.L802405DC:
/* BCD63C 802405DC C6200008 */  lwc1      $f0, 8($s1)
/* BCD640 802405E0 46000002 */  mul.s     $f0, $f0, $f0
/* BCD644 802405E4 00000000 */  nop       
/* BCD648 802405E8 3C0142B4 */  lui       $at, 0x42b4
/* BCD64C 802405EC 44811000 */  mtc1      $at, $f2
/* BCD650 802405F0 2404001B */  addiu     $a0, $zero, 0x1b
/* BCD654 802405F4 46020003 */  div.s     $f0, $f0, $f2
/* BCD658 802405F8 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BCD65C 802405FC E620000C */   swc1     $f0, 0xc($s1)
/* BCD660 80240600 0C046B4C */  jal       get_model_from_list_index
/* BCD664 80240604 0040202D */   daddu    $a0, $v0, $zero
/* BCD668 80240608 0040182D */  daddu     $v1, $v0, $zero
/* BCD66C 8024060C 24700058 */  addiu     $s0, $v1, 0x58
/* BCD670 80240610 4480A000 */  mtc1      $zero, $f20
/* BCD674 80240614 94620000 */  lhu       $v0, ($v1)
/* BCD678 80240618 4405A000 */  mfc1      $a1, $f20
/* BCD67C 8024061C 4407A000 */  mfc1      $a3, $f20
/* BCD680 80240620 34421400 */  ori       $v0, $v0, 0x1400
/* BCD684 80240624 A4620000 */  sh        $v0, ($v1)
/* BCD688 80240628 8E26000C */  lw        $a2, 0xc($s1)
/* BCD68C 8024062C 3C013F80 */  lui       $at, 0x3f80
/* BCD690 80240630 4481B000 */  mtc1      $at, $f22
/* BCD694 80240634 0C019E40 */  jal       guTranslateF
/* BCD698 80240638 0200202D */   daddu    $a0, $s0, $zero
/* BCD69C 8024063C E7B60010 */  swc1      $f22, 0x10($sp)
/* BCD6A0 80240640 8E250008 */  lw        $a1, 8($s1)
/* BCD6A4 80240644 4406A000 */  mfc1      $a2, $f20
/* BCD6A8 80240648 4407A000 */  mfc1      $a3, $f20
/* BCD6AC 8024064C 0C019EC8 */  jal       guRotateF
/* BCD6B0 80240650 27A40018 */   addiu    $a0, $sp, 0x18
/* BCD6B4 80240654 0200202D */  daddu     $a0, $s0, $zero
/* BCD6B8 80240658 27A50018 */  addiu     $a1, $sp, 0x18
/* BCD6BC 8024065C 0C019D80 */  jal       guMtxCatF
/* BCD6C0 80240660 0080302D */   daddu    $a2, $a0, $zero
/* BCD6C4 80240664 0C016E89 */  jal       update_collider_transform
/* BCD6C8 80240668 2404000A */   addiu    $a0, $zero, 0xa
/* BCD6CC 8024066C 0C016E89 */  jal       update_collider_transform
/* BCD6D0 80240670 24040009 */   addiu    $a0, $zero, 9
/* BCD6D4 80240674 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BCD6D8 80240678 2404001A */   addiu    $a0, $zero, 0x1a
/* BCD6DC 8024067C 0C046B4C */  jal       get_model_from_list_index
/* BCD6E0 80240680 0040202D */   daddu    $a0, $v0, $zero
/* BCD6E4 80240684 0040182D */  daddu     $v1, $v0, $zero
/* BCD6E8 80240688 24700058 */  addiu     $s0, $v1, 0x58
/* BCD6EC 8024068C 4405A000 */  mfc1      $a1, $f20
/* BCD6F0 80240690 94620000 */  lhu       $v0, ($v1)
/* BCD6F4 80240694 4407A000 */  mfc1      $a3, $f20
/* BCD6F8 80240698 34421400 */  ori       $v0, $v0, 0x1400
/* BCD6FC 8024069C A4620000 */  sh        $v0, ($v1)
/* BCD700 802406A0 8E26000C */  lw        $a2, 0xc($s1)
/* BCD704 802406A4 0C019E40 */  jal       guTranslateF
/* BCD708 802406A8 0200202D */   daddu    $a0, $s0, $zero
/* BCD70C 802406AC E7B60010 */  swc1      $f22, 0x10($sp)
/* BCD710 802406B0 8E250008 */  lw        $a1, 8($s1)
/* BCD714 802406B4 4406A000 */  mfc1      $a2, $f20
/* BCD718 802406B8 4407A000 */  mfc1      $a3, $f20
/* BCD71C 802406BC 0C019EC8 */  jal       guRotateF
/* BCD720 802406C0 27A40018 */   addiu    $a0, $sp, 0x18
/* BCD724 802406C4 0200202D */  daddu     $a0, $s0, $zero
/* BCD728 802406C8 27A50018 */  addiu     $a1, $sp, 0x18
/* BCD72C 802406CC 0C019D80 */  jal       guMtxCatF
/* BCD730 802406D0 0080302D */   daddu    $a2, $a0, $zero
/* BCD734 802406D4 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BCD738 802406D8 24040019 */   addiu    $a0, $zero, 0x19
/* BCD73C 802406DC 0C046B4C */  jal       get_model_from_list_index
/* BCD740 802406E0 0040202D */   daddu    $a0, $v0, $zero
/* BCD744 802406E4 0040182D */  daddu     $v1, $v0, $zero
/* BCD748 802406E8 24700058 */  addiu     $s0, $v1, 0x58
/* BCD74C 802406EC 4405A000 */  mfc1      $a1, $f20
/* BCD750 802406F0 94620000 */  lhu       $v0, ($v1)
/* BCD754 802406F4 4407A000 */  mfc1      $a3, $f20
/* BCD758 802406F8 34421400 */  ori       $v0, $v0, 0x1400
/* BCD75C 802406FC A4620000 */  sh        $v0, ($v1)
/* BCD760 80240700 8E26000C */  lw        $a2, 0xc($s1)
/* BCD764 80240704 0C019E40 */  jal       guTranslateF
/* BCD768 80240708 0200202D */   daddu    $a0, $s0, $zero
/* BCD76C 8024070C 4406A000 */  mfc1      $a2, $f20
/* BCD770 80240710 27A40018 */  addiu     $a0, $sp, 0x18
/* BCD774 80240714 E7B60010 */  swc1      $f22, 0x10($sp)
/* BCD778 80240718 8E250008 */  lw        $a1, 8($s1)
/* BCD77C 8024071C 0C019EC8 */  jal       guRotateF
/* BCD780 80240720 00C0382D */   daddu    $a3, $a2, $zero
/* BCD784 80240724 0200202D */  daddu     $a0, $s0, $zero
/* BCD788 80240728 27A50018 */  addiu     $a1, $sp, 0x18
/* BCD78C 8024072C 0C019D80 */  jal       guMtxCatF
/* BCD790 80240730 0080302D */   daddu    $a2, $a0, $zero
/* BCD794 80240734 0C016E89 */  jal       update_collider_transform
/* BCD798 80240738 24040008 */   addiu    $a0, $zero, 8
/* BCD79C 8024073C 8FBF0078 */  lw        $ra, 0x78($sp)
/* BCD7A0 80240740 8FB30074 */  lw        $s3, 0x74($sp)
/* BCD7A4 80240744 8FB20070 */  lw        $s2, 0x70($sp)
/* BCD7A8 80240748 8FB1006C */  lw        $s1, 0x6c($sp)
/* BCD7AC 8024074C 8FB00068 */  lw        $s0, 0x68($sp)
/* BCD7B0 80240750 D7B60088 */  ldc1      $f22, 0x88($sp)
/* BCD7B4 80240754 D7B40080 */  ldc1      $f20, 0x80($sp)
/* BCD7B8 80240758 0000102D */  daddu     $v0, $zero, $zero
/* BCD7BC 8024075C 03E00008 */  jr        $ra
/* BCD7C0 80240760 27BD0090 */   addiu    $sp, $sp, 0x90
/* BCD7C4 80240764 00000000 */  nop       
/* BCD7C8 80240768 00000000 */  nop       
/* BCD7CC 8024076C 00000000 */  nop       
