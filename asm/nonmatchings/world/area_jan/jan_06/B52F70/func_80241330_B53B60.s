.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241330_B53B60
/* B53B60 80241330 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* B53B64 80241334 AFB3003C */  sw        $s3, 0x3c($sp)
/* B53B68 80241338 0080982D */  daddu     $s3, $a0, $zero
/* B53B6C 8024133C AFBF0048 */  sw        $ra, 0x48($sp)
/* B53B70 80241340 AFB50044 */  sw        $s5, 0x44($sp)
/* B53B74 80241344 AFB40040 */  sw        $s4, 0x40($sp)
/* B53B78 80241348 AFB20038 */  sw        $s2, 0x38($sp)
/* B53B7C 8024134C AFB10034 */  sw        $s1, 0x34($sp)
/* B53B80 80241350 AFB00030 */  sw        $s0, 0x30($sp)
/* B53B84 80241354 8E720148 */  lw        $s2, 0x148($s3)
/* B53B88 80241358 86440008 */  lh        $a0, 8($s2)
/* B53B8C 8024135C 8E70000C */  lw        $s0, 0xc($s3)
/* B53B90 80241360 0C00EABB */  jal       get_npc_unsafe
/* B53B94 80241364 00A0882D */   daddu    $s1, $a1, $zero
/* B53B98 80241368 8E050000 */  lw        $a1, ($s0)
/* B53B9C 8024136C 26100004 */  addiu     $s0, $s0, 4
/* B53BA0 80241370 0260202D */  daddu     $a0, $s3, $zero
/* B53BA4 80241374 0C0B1EAF */  jal       get_variable
/* B53BA8 80241378 0040A82D */   daddu    $s5, $v0, $zero
/* B53BAC 8024137C 0260202D */  daddu     $a0, $s3, $zero
/* B53BB0 80241380 8E050000 */  lw        $a1, ($s0)
/* B53BB4 80241384 0C0B1EAF */  jal       get_variable
/* B53BB8 80241388 0040A02D */   daddu    $s4, $v0, $zero
/* B53BBC 8024138C AE420094 */  sw        $v0, 0x94($s2)
/* B53BC0 80241390 AFA00010 */  sw        $zero, 0x10($sp)
/* B53BC4 80241394 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B53BC8 80241398 8C420030 */  lw        $v0, 0x30($v0)
/* B53BCC 8024139C AFA20014 */  sw        $v0, 0x14($sp)
/* B53BD0 802413A0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B53BD4 802413A4 8C42001C */  lw        $v0, 0x1c($v0)
/* B53BD8 802413A8 AFA20018 */  sw        $v0, 0x18($sp)
/* B53BDC 802413AC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B53BE0 802413B0 8C420024 */  lw        $v0, 0x24($v0)
/* B53BE4 802413B4 AFA2001C */  sw        $v0, 0x1c($sp)
/* B53BE8 802413B8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B53BEC 802413BC 8C420028 */  lw        $v0, 0x28($v0)
/* B53BF0 802413C0 AFA20020 */  sw        $v0, 0x20($sp)
/* B53BF4 802413C4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* B53BF8 802413C8 3C0142C8 */  lui       $at, 0x42c8
/* B53BFC 802413CC 44810000 */  mtc1      $at, $f0
/* B53C00 802413D0 8C42002C */  lw        $v0, 0x2c($v0)
/* B53C04 802413D4 27B00010 */  addiu     $s0, $sp, 0x10
/* B53C08 802413D8 E7A00028 */  swc1      $f0, 0x28($sp)
/* B53C0C 802413DC A7A0002C */  sh        $zero, 0x2c($sp)
/* B53C10 802413E0 12200019 */  beqz      $s1, .L80241448
/* B53C14 802413E4 AFA20024 */   sw       $v0, 0x24($sp)
/* B53C18 802413E8 AE600070 */  sw        $zero, 0x70($s3)
/* B53C1C 802413EC A6A0008E */  sh        $zero, 0x8e($s5)
/* B53C20 802413F0 AE600074 */  sw        $zero, 0x74($s3)
/* B53C24 802413F4 8EA20000 */  lw        $v0, ($s5)
/* B53C28 802413F8 2403F7FF */  addiu     $v1, $zero, -0x801
/* B53C2C 802413FC 00431024 */  and       $v0, $v0, $v1
/* B53C30 80241400 2403FDFF */  addiu     $v1, $zero, -0x201
/* B53C34 80241404 00431024 */  and       $v0, $v0, $v1
/* B53C38 80241408 34420008 */  ori       $v0, $v0, 8
/* B53C3C 8024140C AEA20000 */  sw        $v0, ($s5)
/* B53C40 80241410 8E4200B0 */  lw        $v0, 0xb0($s2)
/* B53C44 80241414 34420018 */  ori       $v0, $v0, 0x18
/* B53C48 80241418 AE4200B0 */  sw        $v0, 0xb0($s2)
/* B53C4C 8024141C 8E420000 */  lw        $v0, ($s2)
/* B53C50 80241420 3C034000 */  lui       $v1, 0x4000
/* B53C54 80241424 00431024 */  and       $v0, $v0, $v1
/* B53C58 80241428 10400007 */  beqz      $v0, .L80241448
/* B53C5C 8024142C 3C03BFFF */   lui      $v1, 0xbfff
/* B53C60 80241430 2402000C */  addiu     $v0, $zero, 0xc
/* B53C64 80241434 AE620070 */  sw        $v0, 0x70($s3)
/* B53C68 80241438 8E420000 */  lw        $v0, ($s2)
/* B53C6C 8024143C 3463FFFF */  ori       $v1, $v1, 0xffff
/* B53C70 80241440 00431024 */  and       $v0, $v0, $v1
/* B53C74 80241444 AE420000 */  sw        $v0, ($s2)
.L80241448:
/* B53C78 80241448 8E4300B0 */  lw        $v1, 0xb0($s2)
/* B53C7C 8024144C 30620004 */  andi      $v0, $v1, 4
/* B53C80 80241450 10400007 */  beqz      $v0, .L80241470
/* B53C84 80241454 00000000 */   nop      
/* B53C88 80241458 824200B4 */  lb        $v0, 0xb4($s2)
/* B53C8C 8024145C 14400034 */  bnez      $v0, .L80241530
/* B53C90 80241460 0000102D */   daddu    $v0, $zero, $zero
/* B53C94 80241464 2402FFFB */  addiu     $v0, $zero, -5
/* B53C98 80241468 00621024 */  and       $v0, $v1, $v0
/* B53C9C 8024146C AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241470:
/* B53CA0 80241470 8E630070 */  lw        $v1, 0x70($s3)
/* B53CA4 80241474 2C62000F */  sltiu     $v0, $v1, 0xf
/* B53CA8 80241478 1040002C */  beqz      $v0, .L8024152C
/* B53CAC 8024147C 00031080 */   sll      $v0, $v1, 2
/* B53CB0 80241480 3C018024 */  lui       $at, 0x8024
/* B53CB4 80241484 00220821 */  addu      $at, $at, $v0
/* B53CB8 80241488 8C226CB8 */  lw        $v0, 0x6cb8($at)
/* B53CBC 8024148C 00400008 */  jr        $v0
/* B53CC0 80241490 00000000 */   nop      
/* B53CC4 80241494 0260202D */  daddu     $a0, $s3, $zero
/* B53CC8 80241498 0280282D */  daddu     $a1, $s4, $zero
/* B53CCC 8024149C 0C0901D0 */  jal       func_80240740_B52F70
/* B53CD0 802414A0 0200302D */   daddu    $a2, $s0, $zero
/* B53CD4 802414A4 0260202D */  daddu     $a0, $s3, $zero
/* B53CD8 802414A8 0280282D */  daddu     $a1, $s4, $zero
/* B53CDC 802414AC 0C09025C */  jal       func_80240970_B531A0
/* B53CE0 802414B0 0200302D */   daddu    $a2, $s0, $zero
/* B53CE4 802414B4 0809054C */  j         .L80241530
/* B53CE8 802414B8 0000102D */   daddu    $v0, $zero, $zero
/* B53CEC 802414BC 0260202D */  daddu     $a0, $s3, $zero
/* B53CF0 802414C0 0280282D */  daddu     $a1, $s4, $zero
/* B53CF4 802414C4 0C09032A */  jal       func_80240CA8_B534D8
/* B53CF8 802414C8 0200302D */   daddu    $a2, $s0, $zero
/* B53CFC 802414CC 8E630070 */  lw        $v1, 0x70($s3)
/* B53D00 802414D0 24020003 */  addiu     $v0, $zero, 3
/* B53D04 802414D4 14620016 */  bne       $v1, $v0, .L80241530
/* B53D08 802414D8 0000102D */   daddu    $v0, $zero, $zero
/* B53D0C 802414DC 0260202D */  daddu     $a0, $s3, $zero
/* B53D10 802414E0 0280282D */  daddu     $a1, $s4, $zero
/* B53D14 802414E4 0C09035A */  jal       delete_player_actor
/* B53D18 802414E8 0200302D */   daddu    $a2, $s0, $zero
/* B53D1C 802414EC 0809054C */  j         .L80241530
/* B53D20 802414F0 0000102D */   daddu    $v0, $zero, $zero
/* B53D24 802414F4 0260202D */  daddu     $a0, $s3, $zero
/* B53D28 802414F8 0280282D */  daddu     $a1, $s4, $zero
/* B53D2C 802414FC 0C0903C3 */  jal       func_80240F0C_B5373C
/* B53D30 80241500 0200302D */   daddu    $a2, $s0, $zero
/* B53D34 80241504 0260202D */  daddu     $a0, $s3, $zero
/* B53D38 80241508 0280282D */  daddu     $a1, $s4, $zero
/* B53D3C 8024150C 0C0903FB */  jal       func_80240FEC_B5381C
/* B53D40 80241510 0200302D */   daddu    $a2, $s0, $zero
/* B53D44 80241514 0809054C */  j         .L80241530
/* B53D48 80241518 0000102D */   daddu    $v0, $zero, $zero
/* B53D4C 8024151C 0260202D */  daddu     $a0, $s3, $zero
/* B53D50 80241520 0280282D */  daddu     $a1, $s4, $zero
/* B53D54 80241524 0C0904BB */  jal       func_802412EC_B53B1C
/* B53D58 80241528 0200302D */   daddu    $a2, $s0, $zero
.L8024152C:
/* B53D5C 8024152C 0000102D */  daddu     $v0, $zero, $zero
.L80241530:
/* B53D60 80241530 8FBF0048 */  lw        $ra, 0x48($sp)
/* B53D64 80241534 8FB50044 */  lw        $s5, 0x44($sp)
/* B53D68 80241538 8FB40040 */  lw        $s4, 0x40($sp)
/* B53D6C 8024153C 8FB3003C */  lw        $s3, 0x3c($sp)
/* B53D70 80241540 8FB20038 */  lw        $s2, 0x38($sp)
/* B53D74 80241544 8FB10034 */  lw        $s1, 0x34($sp)
/* B53D78 80241548 8FB00030 */  lw        $s0, 0x30($sp)
/* B53D7C 8024154C 03E00008 */  jr        $ra
/* B53D80 80241550 27BD0050 */   addiu    $sp, $sp, 0x50
