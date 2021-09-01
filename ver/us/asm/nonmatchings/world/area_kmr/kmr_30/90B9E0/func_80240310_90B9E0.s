.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_90B9E0
/* 90B9E0 80240310 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 90B9E4 80240314 AFBF002C */  sw        $ra, 0x2c($sp)
/* 90B9E8 80240318 AFB60028 */  sw        $s6, 0x28($sp)
/* 90B9EC 8024031C AFB50024 */  sw        $s5, 0x24($sp)
/* 90B9F0 80240320 AFB40020 */  sw        $s4, 0x20($sp)
/* 90B9F4 80240324 AFB3001C */  sw        $s3, 0x1c($sp)
/* 90B9F8 80240328 AFB20018 */  sw        $s2, 0x18($sp)
/* 90B9FC 8024032C AFB10014 */  sw        $s1, 0x14($sp)
/* 90BA00 80240330 AFB00010 */  sw        $s0, 0x10($sp)
/* 90BA04 80240334 8C82000C */  lw        $v0, 0xc($a0)
/* 90BA08 80240338 8C450000 */  lw        $a1, ($v0)
/* 90BA0C 8024033C 0C0B1EAF */  jal       evt_get_variable
/* 90BA10 80240340 241000FF */   addiu    $s0, $zero, 0xff
/* 90BA14 80240344 240400FF */  addiu     $a0, $zero, 0xff
/* 90BA18 80240348 0C00A67F */  jal       rand_int
/* 90BA1C 8024034C 0040982D */   daddu    $s3, $v0, $zero
/* 90BA20 80240350 0040882D */  daddu     $s1, $v0, $zero
/* 90BA24 80240354 0C00A67F */  jal       rand_int
/* 90BA28 80240358 02112023 */   subu     $a0, $s0, $s1
/* 90BA2C 8024035C 0040902D */  daddu     $s2, $v0, $zero
/* 90BA30 80240360 02128023 */  subu      $s0, $s0, $s2
/* 90BA34 80240364 0C00A67F */  jal       rand_int
/* 90BA38 80240368 02112023 */   subu     $a0, $s0, $s1
/* 90BA3C 8024036C 0040802D */  daddu     $s0, $v0, $zero
/* 90BA40 80240370 0C00A67F */  jal       rand_int
/* 90BA44 80240374 24040080 */   addiu    $a0, $zero, 0x80
/* 90BA48 80240378 0222B021 */  addu      $s6, $s1, $v0
/* 90BA4C 8024037C 0C00A67F */  jal       rand_int
/* 90BA50 80240380 24040080 */   addiu    $a0, $zero, 0x80
/* 90BA54 80240384 0242A821 */  addu      $s5, $s2, $v0
/* 90BA58 80240388 0C00A67F */  jal       rand_int
/* 90BA5C 8024038C 24040080 */   addiu    $a0, $zero, 0x80
/* 90BA60 80240390 0202A021 */  addu      $s4, $s0, $v0
/* 90BA64 80240394 2AC20100 */  slti      $v0, $s6, 0x100
/* 90BA68 80240398 50400001 */  beql      $v0, $zero, .L802403A0
/* 90BA6C 8024039C 241600FF */   addiu    $s6, $zero, 0xff
.L802403A0:
/* 90BA70 802403A0 2AA20100 */  slti      $v0, $s5, 0x100
/* 90BA74 802403A4 50400001 */  beql      $v0, $zero, .L802403AC
/* 90BA78 802403A8 241500FF */   addiu    $s5, $zero, 0xff
.L802403AC:
/* 90BA7C 802403AC 2A820100 */  slti      $v0, $s4, 0x100
/* 90BA80 802403B0 50400001 */  beql      $v0, $zero, .L802403B8
/* 90BA84 802403B4 241400FF */   addiu    $s4, $zero, 0xff
.L802403B8:
/* 90BA88 802403B8 0C00A67F */  jal       rand_int
/* 90BA8C 802403BC 24040080 */   addiu    $a0, $zero, 0x80
/* 90BA90 802403C0 02228821 */  addu      $s1, $s1, $v0
/* 90BA94 802403C4 0C00A67F */  jal       rand_int
/* 90BA98 802403C8 24040080 */   addiu    $a0, $zero, 0x80
/* 90BA9C 802403CC 02429021 */  addu      $s2, $s2, $v0
/* 90BAA0 802403D0 0C00A67F */  jal       rand_int
/* 90BAA4 802403D4 24040080 */   addiu    $a0, $zero, 0x80
/* 90BAA8 802403D8 02028021 */  addu      $s0, $s0, $v0
/* 90BAAC 802403DC 2A220100 */  slti      $v0, $s1, 0x100
/* 90BAB0 802403E0 50400001 */  beql      $v0, $zero, .L802403E8
/* 90BAB4 802403E4 241100FF */   addiu    $s1, $zero, 0xff
.L802403E8:
/* 90BAB8 802403E8 2A420100 */  slti      $v0, $s2, 0x100
/* 90BABC 802403EC 50400001 */  beql      $v0, $zero, .L802403F4
/* 90BAC0 802403F0 241200FF */   addiu    $s2, $zero, 0xff
.L802403F4:
/* 90BAC4 802403F4 2A020100 */  slti      $v0, $s0, 0x100
/* 90BAC8 802403F8 50400001 */  beql      $v0, $zero, .L80240400
/* 90BACC 802403FC 241000FF */   addiu    $s0, $zero, 0xff
.L80240400:
/* 90BAD0 80240400 8E62000C */  lw        $v0, 0xc($s3)
/* 90BAD4 80240404 AC560024 */  sw        $s6, 0x24($v0)
/* 90BAD8 80240408 8E62000C */  lw        $v0, 0xc($s3)
/* 90BADC 8024040C AC550028 */  sw        $s5, 0x28($v0)
/* 90BAE0 80240410 8E62000C */  lw        $v0, 0xc($s3)
/* 90BAE4 80240414 AC54002C */  sw        $s4, 0x2c($v0)
/* 90BAE8 80240418 8E62000C */  lw        $v0, 0xc($s3)
/* 90BAEC 8024041C AC510034 */  sw        $s1, 0x34($v0)
/* 90BAF0 80240420 8E62000C */  lw        $v0, 0xc($s3)
/* 90BAF4 80240424 AC520038 */  sw        $s2, 0x38($v0)
/* 90BAF8 80240428 8E63000C */  lw        $v1, 0xc($s3)
/* 90BAFC 8024042C AC70003C */  sw        $s0, 0x3c($v1)
/* 90BB00 80240430 8FBF002C */  lw        $ra, 0x2c($sp)
/* 90BB04 80240434 8FB60028 */  lw        $s6, 0x28($sp)
/* 90BB08 80240438 8FB50024 */  lw        $s5, 0x24($sp)
/* 90BB0C 8024043C 8FB40020 */  lw        $s4, 0x20($sp)
/* 90BB10 80240440 8FB3001C */  lw        $s3, 0x1c($sp)
/* 90BB14 80240444 8FB20018 */  lw        $s2, 0x18($sp)
/* 90BB18 80240448 8FB10014 */  lw        $s1, 0x14($sp)
/* 90BB1C 8024044C 8FB00010 */  lw        $s0, 0x10($sp)
/* 90BB20 80240450 24020002 */  addiu     $v0, $zero, 2
/* 90BB24 80240454 03E00008 */  jr        $ra
/* 90BB28 80240458 27BD0030 */   addiu    $sp, $sp, 0x30
