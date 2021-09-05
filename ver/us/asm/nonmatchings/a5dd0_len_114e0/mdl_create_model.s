.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel mdl_create_model
/* AC90C 8011620C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* AC910 80116210 AFB40040 */  sw        $s4, 0x40($sp)
/* AC914 80116214 0080A02D */  daddu     $s4, $a0, $zero
/* AC918 80116218 AFBF0044 */  sw        $ra, 0x44($sp)
/* AC91C 8011621C AFB3003C */  sw        $s3, 0x3c($sp)
/* AC920 80116220 AFB20038 */  sw        $s2, 0x38($sp)
/* AC924 80116224 AFB10034 */  sw        $s1, 0x34($sp)
/* AC928 80116228 AFB00030 */  sw        $s0, 0x30($sp)
/* AC92C 8011622C 8E920004 */  lw        $s2, 4($s4)
/* AC930 80116230 2405005F */  addiu     $a1, $zero, 0x5f
/* AC934 80116234 0C0456C3 */  jal       get_model_property
/* AC938 80116238 0240202D */   daddu    $a0, $s2, $zero
/* AC93C 8011623C 0040802D */  daddu     $s0, $v0, $zero
/* AC940 80116240 12000023 */  beqz      $s0, .L801162D0
/* AC944 80116244 0000982D */   daddu    $s3, $zero, $zero
/* AC948 80116248 9202000B */  lbu       $v0, 0xb($s0)
/* AC94C 8011624C 00028902 */  srl       $s1, $v0, 4
/* AC950 80116250 1220001F */  beqz      $s1, .L801162D0
/* AC954 80116254 0240202D */   daddu    $a0, $s2, $zero
/* AC958 80116258 0C0456C3 */  jal       get_model_property
/* AC95C 8011625C 24050061 */   addiu    $a1, $zero, 0x61
/* AC960 80116260 0040802D */  daddu     $s0, $v0, $zero
/* AC964 80116264 12000019 */  beqz      $s0, .L801162CC
/* AC968 80116268 27A20020 */   addiu    $v0, $sp, 0x20
/* AC96C 8011626C C6000008 */  lwc1      $f0, 8($s0)
/* AC970 80116270 C602002C */  lwc1      $f2, 0x2c($s0)
/* AC974 80116274 46020000 */  add.s     $f0, $f0, $f2
/* AC978 80116278 3C013F00 */  lui       $at, 0x3f00
/* AC97C 8011627C 44812000 */  mtc1      $at, $f4
/* AC980 80116280 00000000 */  nop
/* AC984 80116284 46040002 */  mul.s     $f0, $f0, $f4
/* AC988 80116288 00000000 */  nop
/* AC98C 8011628C C6020044 */  lwc1      $f2, 0x44($s0)
/* AC990 80116290 44050000 */  mfc1      $a1, $f0
/* AC994 80116294 C6000020 */  lwc1      $f0, 0x20($s0)
/* AC998 80116298 46020000 */  add.s     $f0, $f0, $f2
/* AC99C 8011629C 46040002 */  mul.s     $f0, $f0, $f4
/* AC9A0 801162A0 00000000 */  nop
/* AC9A4 801162A4 44070000 */  mfc1      $a3, $f0
/* AC9A8 801162A8 3C013F80 */  lui       $at, 0x3f80
/* AC9AC 801162AC 44810000 */  mtc1      $at, $f0
/* AC9B0 801162B0 AFA20014 */  sw        $v0, 0x14($sp)
/* AC9B4 801162B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* AC9B8 801162B8 8E060014 */  lw        $a2, 0x14($s0)
/* AC9BC 801162BC 0C01C124 */  jal       playFX_20
/* AC9C0 801162C0 2624FFFF */   addiu    $a0, $s1, -1
/* AC9C4 801162C4 08045995 */  j         .L80116654
/* AC9C8 801162C8 00000000 */   nop
.L801162CC:
/* AC9CC 801162CC 0000982D */  daddu     $s3, $zero, $zero
.L801162D0:
/* AC9D0 801162D0 3C108015 */  lui       $s0, %hi(gCurrentModels)
/* AC9D4 801162D4 261012CC */  addiu     $s0, $s0, %lo(gCurrentModels)
/* AC9D8 801162D8 8E030000 */  lw        $v1, ($s0)
.L801162DC:
/* AC9DC 801162DC 8C620000 */  lw        $v0, ($v1)
/* AC9E0 801162E0 10400005 */  beqz      $v0, .L801162F8
/* AC9E4 801162E4 00000000 */   nop
/* AC9E8 801162E8 26730001 */  addiu     $s3, $s3, 1
/* AC9EC 801162EC 2A620100 */  slti      $v0, $s3, 0x100
/* AC9F0 801162F0 1440FFFA */  bnez      $v0, .L801162DC
/* AC9F4 801162F4 24630004 */   addiu    $v1, $v1, 4
.L801162F8:
/* AC9F8 801162F8 0C00AB39 */  jal       heap_malloc
/* AC9FC 801162FC 240400B0 */   addiu    $a0, $zero, 0xb0
/* ACA00 80116300 00131880 */  sll       $v1, $s3, 2
/* ACA04 80116304 8E040000 */  lw        $a0, ($s0)
/* ACA08 80116308 0040882D */  daddu     $s1, $v0, $zero
/* ACA0C 8011630C 00641821 */  addu      $v1, $v1, $a0
/* ACA10 80116310 AC710000 */  sw        $s1, ($v1)
/* ACA14 80116314 96820000 */  lhu       $v0, ($s4)
/* ACA18 80116318 3C038015 */  lui       $v1, %hi(D_80153226)
/* ACA1C 8011631C 94633226 */  lhu       $v1, %lo(D_80153226)($v1)
/* ACA20 80116320 34420001 */  ori       $v0, $v0, 1
/* ACA24 80116324 A6230002 */  sh        $v1, 2($s1)
/* ACA28 80116328 A6220000 */  sh        $v0, ($s1)
/* ACA2C 8011632C 8E820004 */  lw        $v0, 4($s4)
/* ACA30 80116330 2405005F */  addiu     $a1, $zero, 0x5f
/* ACA34 80116334 AE220008 */  sw        $v0, 8($s1)
/* ACA38 80116338 0040902D */  daddu     $s2, $v0, $zero
/* ACA3C 8011633C 8E820008 */  lw        $v0, 8($s4)
/* ACA40 80116340 0240202D */  daddu     $a0, $s2, $zero
/* ACA44 80116344 A22000A7 */  sb        $zero, 0xa7($s1)
/* ACA48 80116348 0C0456C3 */  jal       get_model_property
/* ACA4C 8011634C AE22000C */   sw       $v0, 0xc($s1)
/* ACA50 80116350 0040802D */  daddu     $s0, $v0, $zero
/* ACA54 80116354 52000004 */  beql      $s0, $zero, .L80116368
/* ACA58 80116358 A22000A4 */   sb       $zero, 0xa4($s1)
/* ACA5C 8011635C 9202000B */  lbu       $v0, 0xb($s0)
/* ACA60 80116360 3042000F */  andi      $v0, $v0, 0xf
/* ACA64 80116364 A22200A4 */  sb        $v0, 0xa4($s1)
.L80116368:
/* ACA68 80116368 A22000A5 */  sb        $zero, 0xa5($s1)
/* ACA6C 8011636C 8E430000 */  lw        $v1, ($s2)
/* ACA70 80116370 24020005 */  addiu     $v0, $zero, 5
/* ACA74 80116374 10620005 */  beq       $v1, $v0, .L8011638C
/* ACA78 80116378 0240202D */   daddu    $a0, $s2, $zero
/* ACA7C 8011637C 0C0456C3 */  jal       get_model_property
/* ACA80 80116380 2405005C */   addiu    $a1, $zero, 0x5c
/* ACA84 80116384 080458E8 */  j         .L801163A0
/* ACA88 80116388 0040802D */   daddu    $s0, $v0, $zero
.L8011638C:
/* ACA8C 8011638C 0C0456C3 */  jal       get_model_property
/* ACA90 80116390 24050060 */   addiu    $a1, $zero, 0x60
/* ACA94 80116394 0040802D */  daddu     $s0, $v0, $zero
/* ACA98 80116398 12000006 */  beqz      $s0, .L801163B4
/* ACA9C 8011639C 2610000C */   addiu    $s0, $s0, 0xc
.L801163A0:
/* ACAA0 801163A0 12000005 */  beqz      $s0, .L801163B8
/* ACAA4 801163A4 24020001 */   addiu    $v0, $zero, 1
/* ACAA8 801163A8 9202000B */  lbu       $v0, 0xb($s0)
/* ACAAC 801163AC 080458EF */  j         .L801163BC
/* ACAB0 801163B0 A22200A6 */   sb       $v0, 0xa6($s1)
.L801163B4:
/* ACAB4 801163B4 24020001 */  addiu     $v0, $zero, 1
.L801163B8:
/* ACAB8 801163B8 A22200A6 */  sb        $v0, 0xa6($s1)
.L801163BC:
/* ACABC 801163BC 3C028015 */  lui       $v0, %hi(mdl_treeIterPos)
/* ACAC0 801163C0 8C423224 */  lw        $v0, %lo(mdl_treeIterPos)($v0)
/* ACAC4 801163C4 3C03800A */  lui       $v1, %hi(mdl_currentModelTreeNodeInfo)
/* ACAC8 801163C8 8C63A5F4 */  lw        $v1, %lo(mdl_currentModelTreeNodeInfo)($v1)
/* ACACC 801163CC 00021080 */  sll       $v0, $v0, 2
/* ACAD0 801163D0 00431021 */  addu      $v0, $v0, $v1
/* ACAD4 801163D4 90420002 */  lbu       $v0, 2($v0)
/* ACAD8 801163D8 A22000A9 */  sb        $zero, 0xa9($s1)
/* ACADC 801163DC A22200A8 */  sb        $v0, 0xa8($s1)
/* ACAE0 801163E0 0C046F85 */  jal       is_identity_fixed_mtx
/* ACAE4 801163E4 8E84000C */   lw       $a0, 0xc($s4)
/* ACAE8 801163E8 14400021 */  bnez      $v0, .L80116470
/* ACAEC 801163EC 26240018 */   addiu    $a0, $s1, 0x18
/* ACAF0 801163F0 0C00AB39 */  jal       heap_malloc
/* ACAF4 801163F4 24040040 */   addiu    $a0, $zero, 0x40
/* ACAF8 801163F8 AE220004 */  sw        $v0, 4($s1)
/* ACAFC 801163FC 8E84000C */  lw        $a0, 0xc($s4)
/* ACB00 80116400 24830040 */  addiu     $v1, $a0, 0x40
.L80116404:
/* ACB04 80116404 8C880000 */  lw        $t0, ($a0)
/* ACB08 80116408 8C890004 */  lw        $t1, 4($a0)
/* ACB0C 8011640C 8C8A0008 */  lw        $t2, 8($a0)
/* ACB10 80116410 8C8B000C */  lw        $t3, 0xc($a0)
/* ACB14 80116414 AC480000 */  sw        $t0, ($v0)
/* ACB18 80116418 AC490004 */  sw        $t1, 4($v0)
/* ACB1C 8011641C AC4A0008 */  sw        $t2, 8($v0)
/* ACB20 80116420 AC4B000C */  sw        $t3, 0xc($v0)
/* ACB24 80116424 24840010 */  addiu     $a0, $a0, 0x10
/* ACB28 80116428 1483FFF6 */  bne       $a0, $v1, .L80116404
/* ACB2C 8011642C 24420010 */   addiu    $v0, $v0, 0x10
/* ACB30 80116430 8E220004 */  lw        $v0, 4($s1)
/* ACB34 80116434 26230018 */  addiu     $v1, $s1, 0x18
/* ACB38 80116438 24440040 */  addiu     $a0, $v0, 0x40
.L8011643C:
/* ACB3C 8011643C 8C480000 */  lw        $t0, ($v0)
/* ACB40 80116440 8C490004 */  lw        $t1, 4($v0)
/* ACB44 80116444 8C4A0008 */  lw        $t2, 8($v0)
/* ACB48 80116448 8C4B000C */  lw        $t3, 0xc($v0)
/* ACB4C 8011644C AC680000 */  sw        $t0, ($v1)
/* ACB50 80116450 AC690004 */  sw        $t1, 4($v1)
/* ACB54 80116454 AC6A0008 */  sw        $t2, 8($v1)
/* ACB58 80116458 AC6B000C */  sw        $t3, 0xc($v1)
/* ACB5C 8011645C 24420010 */  addiu     $v0, $v0, 0x10
/* ACB60 80116460 1444FFF6 */  bne       $v0, $a0, .L8011643C
/* ACB64 80116464 24630010 */   addiu    $v1, $v1, 0x10
/* ACB68 80116468 08045921 */  j         .L80116484
/* ACB6C 8011646C 00000000 */   nop
.L80116470:
/* ACB70 80116470 0C019D10 */  jal       guMtxIdent
/* ACB74 80116474 AE200004 */   sw       $zero, 4($s1)
/* ACB78 80116478 96220000 */  lhu       $v0, ($s1)
/* ACB7C 8011647C 34422000 */  ori       $v0, $v0, 0x2000
/* ACB80 80116480 A6220000 */  sh        $v0, ($s1)
.L80116484:
/* ACB84 80116484 0C019D28 */  jal       guMtxIdentF
/* ACB88 80116488 26240058 */   addiu    $a0, $s1, 0x58
/* ACB8C 8011648C AE200010 */  sw        $zero, 0x10($s1)
/* ACB90 80116490 0240202D */  daddu     $a0, $s2, $zero
/* ACB94 80116494 0C0456C3 */  jal       get_model_property
/* ACB98 80116498 24050061 */   addiu    $a1, $zero, 0x61
/* ACB9C 8011649C 0040802D */  daddu     $s0, $v0, $zero
/* ACBA0 801164A0 12000017 */  beqz      $s0, .L80116500
/* ACBA4 801164A4 00000000 */   nop
/* ACBA8 801164A8 C6060008 */  lwc1      $f6, 8($s0)
/* ACBAC 801164AC C600002C */  lwc1      $f0, 0x2c($s0)
/* ACBB0 801164B0 46003180 */  add.s     $f6, $f6, $f0
/* ACBB4 801164B4 3C013F00 */  lui       $at, 0x3f00
/* ACBB8 801164B8 44814000 */  mtc1      $at, $f8
/* ACBBC 801164BC 00000000 */  nop
/* ACBC0 801164C0 46083182 */  mul.s     $f6, $f6, $f8
/* ACBC4 801164C4 00000000 */  nop
/* ACBC8 801164C8 C6040014 */  lwc1      $f4, 0x14($s0)
/* ACBCC 801164CC C6000038 */  lwc1      $f0, 0x38($s0)
/* ACBD0 801164D0 46002100 */  add.s     $f4, $f4, $f0
/* ACBD4 801164D4 46082102 */  mul.s     $f4, $f4, $f8
/* ACBD8 801164D8 00000000 */  nop
/* ACBDC 801164DC C6020044 */  lwc1      $f2, 0x44($s0)
/* ACBE0 801164E0 C6000020 */  lwc1      $f0, 0x20($s0)
/* ACBE4 801164E4 46020000 */  add.s     $f0, $f0, $f2
/* ACBE8 801164E8 46080002 */  mul.s     $f0, $f0, $f8
/* ACBEC 801164EC 00000000 */  nop
/* ACBF0 801164F0 E7A60024 */  swc1      $f6, 0x24($sp)
/* ACBF4 801164F4 E7A40028 */  swc1      $f4, 0x28($sp)
/* ACBF8 801164F8 08045945 */  j         .L80116514
/* ACBFC 801164FC E7A0002C */   swc1     $f0, 0x2c($sp)
.L80116500:
/* ACC00 80116500 44800000 */  mtc1      $zero, $f0
/* ACC04 80116504 00000000 */  nop
/* ACC08 80116508 E7A0002C */  swc1      $f0, 0x2c($sp)
/* ACC0C 8011650C E7A00028 */  swc1      $f0, 0x28($sp)
/* ACC10 80116510 E7A00024 */  swc1      $f0, 0x24($sp)
.L80116514:
/* ACC14 80116514 8E220004 */  lw        $v0, 4($s1)
/* ACC18 80116518 1040000F */  beqz      $v0, .L80116558
/* ACC1C 8011651C 27A20024 */   addiu    $v0, $sp, 0x24
/* ACC20 80116520 C7A00024 */  lwc1      $f0, 0x24($sp)
/* ACC24 80116524 C7A20028 */  lwc1      $f2, 0x28($sp)
/* ACC28 80116528 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ACC2C 8011652C AFA20010 */  sw        $v0, 0x10($sp)
/* ACC30 80116530 27A20028 */  addiu     $v0, $sp, 0x28
/* ACC34 80116534 AFA20014 */  sw        $v0, 0x14($sp)
/* ACC38 80116538 27A2002C */  addiu     $v0, $sp, 0x2c
/* ACC3C 8011653C AFA20018 */  sw        $v0, 0x18($sp)
/* ACC40 80116540 8E240004 */  lw        $a0, 4($s1)
/* ACC44 80116544 44050000 */  mfc1      $a1, $f0
/* ACC48 80116548 44061000 */  mfc1      $a2, $f2
/* ACC4C 8011654C 44072000 */  mfc1      $a3, $f4
/* ACC50 80116550 0C019E78 */  jal       guMtxXFML
/* ACC54 80116554 00000000 */   nop
.L80116558:
/* ACC58 80116558 C7A00024 */  lwc1      $f0, 0x24($sp)
/* ACC5C 8011655C C7A20028 */  lwc1      $f2, 0x28($sp)
/* ACC60 80116560 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* ACC64 80116564 E6200098 */  swc1      $f0, 0x98($s1)
/* ACC68 80116568 E622009C */  swc1      $f2, 0x9c($s1)
/* ACC6C 8011656C E62400A0 */  swc1      $f4, 0xa0($s1)
/* ACC70 80116570 C602002C */  lwc1      $f2, 0x2c($s0)
/* ACC74 80116574 C6000008 */  lwc1      $f0, 8($s0)
/* ACC78 80116578 46001301 */  sub.s     $f12, $f2, $f0
/* ACC7C 8011657C 3C013FE0 */  lui       $at, 0x3fe0
/* ACC80 80116580 44812800 */  mtc1      $at, $f5
/* ACC84 80116584 44802000 */  mtc1      $zero, $f4
/* ACC88 80116588 460061A1 */  cvt.d.s   $f6, $f12
/* ACC8C 8011658C 46243182 */  mul.d     $f6, $f6, $f4
/* ACC90 80116590 00000000 */  nop
/* ACC94 80116594 C6020038 */  lwc1      $f2, 0x38($s0)
/* ACC98 80116598 C6000014 */  lwc1      $f0, 0x14($s0)
/* ACC9C 8011659C 46001281 */  sub.s     $f10, $f2, $f0
/* ACCA0 801165A0 460050A1 */  cvt.d.s   $f2, $f10
/* ACCA4 801165A4 46241082 */  mul.d     $f2, $f2, $f4
/* ACCA8 801165A8 00000000 */  nop
/* ACCAC 801165AC C6080044 */  lwc1      $f8, 0x44($s0)
/* ACCB0 801165B0 C6000020 */  lwc1      $f0, 0x20($s0)
/* ACCB4 801165B4 46004201 */  sub.s     $f8, $f8, $f0
/* ACCB8 801165B8 46004021 */  cvt.d.s   $f0, $f8
/* ACCBC 801165BC 46240002 */  mul.d     $f0, $f0, $f4
/* ACCC0 801165C0 00000000 */  nop
/* ACCC4 801165C4 4620338D */  trunc.w.d $f14, $f6
/* ACCC8 801165C8 E60E0004 */  swc1      $f14, 4($s0)
/* ACCCC 801165CC 4620138D */  trunc.w.d $f14, $f2
/* ACCD0 801165D0 E60E0010 */  swc1      $f14, 0x10($s0)
/* ACCD4 801165D4 4620038D */  trunc.w.d $f14, $f0
/* ACCD8 801165D8 E60E001C */  swc1      $f14, 0x1c($s0)
/* ACCDC 801165DC 8E220004 */  lw        $v0, 4($s1)
/* ACCE0 801165E0 E7AC0024 */  swc1      $f12, 0x24($sp)
/* ACCE4 801165E4 E7AA0028 */  swc1      $f10, 0x28($sp)
/* ACCE8 801165E8 14400013 */  bnez      $v0, .L80116638
/* ACCEC 801165EC E7A8002C */   swc1     $f8, 0x2c($sp)
/* ACCF0 801165F0 3C0142C8 */  lui       $at, 0x42c8
/* ACCF4 801165F4 44810000 */  mtc1      $at, $f0
/* ACCF8 801165F8 00000000 */  nop
/* ACCFC 801165FC 4600603C */  c.lt.s    $f12, $f0
/* ACD00 80116600 00000000 */  nop
/* ACD04 80116604 4500000C */  bc1f      .L80116638
/* ACD08 80116608 00000000 */   nop
/* ACD0C 8011660C 4600503C */  c.lt.s    $f10, $f0
/* ACD10 80116610 00000000 */  nop
/* ACD14 80116614 45000008 */  bc1f      .L80116638
/* ACD18 80116618 00000000 */   nop
/* ACD1C 8011661C 4600403C */  c.lt.s    $f8, $f0
/* ACD20 80116620 00000000 */  nop
/* ACD24 80116624 45000004 */  bc1f      .L80116638
/* ACD28 80116628 00000000 */   nop
/* ACD2C 8011662C 96220000 */  lhu       $v0, ($s1)
/* ACD30 80116630 34420200 */  ori       $v0, $v0, 0x200
/* ACD34 80116634 A6220000 */  sh        $v0, ($s1)
.L80116638:
/* ACD38 80116638 3C028015 */  lui       $v0, %hi(mdl_treeIterPos)
/* ACD3C 8011663C 8C423224 */  lw        $v0, %lo(mdl_treeIterPos)($v0)
/* ACD40 80116640 3C03800A */  lui       $v1, %hi(mdl_currentModelTreeNodeInfo)
/* ACD44 80116644 8C63A5F4 */  lw        $v1, %lo(mdl_currentModelTreeNodeInfo)($v1)
/* ACD48 80116648 00021080 */  sll       $v0, $v0, 2
/* ACD4C 8011664C 00431021 */  addu      $v0, $v0, $v1
/* ACD50 80116650 A0530000 */  sb        $s3, ($v0)
.L80116654:
/* ACD54 80116654 8FBF0044 */  lw        $ra, 0x44($sp)
/* ACD58 80116658 8FB40040 */  lw        $s4, 0x40($sp)
/* ACD5C 8011665C 8FB3003C */  lw        $s3, 0x3c($sp)
/* ACD60 80116660 8FB20038 */  lw        $s2, 0x38($sp)
/* ACD64 80116664 8FB10034 */  lw        $s1, 0x34($sp)
/* ACD68 80116668 8FB00030 */  lw        $s0, 0x30($sp)
/* ACD6C 8011666C 03E00008 */  jr        $ra
/* ACD70 80116670 27BD0048 */   addiu    $sp, $sp, 0x48
