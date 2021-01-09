.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B8C_BA530C
/* BA530C 80240B8C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BA5310 80240B90 AFB20038 */  sw        $s2, 0x38($sp)
/* BA5314 80240B94 0080902D */  daddu     $s2, $a0, $zero
/* BA5318 80240B98 AFBF0048 */  sw        $ra, 0x48($sp)
/* BA531C 80240B9C AFB50044 */  sw        $s5, 0x44($sp)
/* BA5320 80240BA0 AFB40040 */  sw        $s4, 0x40($sp)
/* BA5324 80240BA4 AFB3003C */  sw        $s3, 0x3c($sp)
/* BA5328 80240BA8 AFB10034 */  sw        $s1, 0x34($sp)
/* BA532C 80240BAC AFB00030 */  sw        $s0, 0x30($sp)
/* BA5330 80240BB0 8E510148 */  lw        $s1, 0x148($s2)
/* BA5334 80240BB4 86240008 */  lh        $a0, 8($s1)
/* BA5338 80240BB8 0C00EABB */  jal       get_npc_unsafe
/* BA533C 80240BBC 00A0802D */   daddu    $s0, $a1, $zero
/* BA5340 80240BC0 8E43000C */  lw        $v1, 0xc($s2)
/* BA5344 80240BC4 0240202D */  daddu     $a0, $s2, $zero
/* BA5348 80240BC8 8C650000 */  lw        $a1, ($v1)
/* BA534C 80240BCC 0C0B1EAF */  jal       get_variable
/* BA5350 80240BD0 0040A82D */   daddu    $s5, $v0, $zero
/* BA5354 80240BD4 AFA00010 */  sw        $zero, 0x10($sp)
/* BA5358 80240BD8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA535C 80240BDC 8C630030 */  lw        $v1, 0x30($v1)
/* BA5360 80240BE0 AFA30014 */  sw        $v1, 0x14($sp)
/* BA5364 80240BE4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA5368 80240BE8 8C63001C */  lw        $v1, 0x1c($v1)
/* BA536C 80240BEC AFA30018 */  sw        $v1, 0x18($sp)
/* BA5370 80240BF0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA5374 80240BF4 8C630024 */  lw        $v1, 0x24($v1)
/* BA5378 80240BF8 AFA3001C */  sw        $v1, 0x1c($sp)
/* BA537C 80240BFC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA5380 80240C00 8C630028 */  lw        $v1, 0x28($v1)
/* BA5384 80240C04 27B40010 */  addiu     $s4, $sp, 0x10
/* BA5388 80240C08 AFA30020 */  sw        $v1, 0x20($sp)
/* BA538C 80240C0C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BA5390 80240C10 3C014282 */  lui       $at, 0x4282
/* BA5394 80240C14 44810000 */  mtc1      $at, $f0
/* BA5398 80240C18 8C63002C */  lw        $v1, 0x2c($v1)
/* BA539C 80240C1C 0040982D */  daddu     $s3, $v0, $zero
/* BA53A0 80240C20 E7A00028 */  swc1      $f0, 0x28($sp)
/* BA53A4 80240C24 A7A0002C */  sh        $zero, 0x2c($sp)
/* BA53A8 80240C28 16000005 */  bnez      $s0, .L80240C40
/* BA53AC 80240C2C AFA30024 */   sw       $v1, 0x24($sp)
/* BA53B0 80240C30 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA53B4 80240C34 30420004 */  andi      $v0, $v0, 4
/* BA53B8 80240C38 10400020 */  beqz      $v0, .L80240CBC
/* BA53BC 80240C3C 00000000 */   nop      
.L80240C40:
/* BA53C0 80240C40 2404F7FF */  addiu     $a0, $zero, -0x801
/* BA53C4 80240C44 AE400070 */  sw        $zero, 0x70($s2)
/* BA53C8 80240C48 A6A0008E */  sh        $zero, 0x8e($s5)
/* BA53CC 80240C4C 8E2200CC */  lw        $v0, 0xcc($s1)
/* BA53D0 80240C50 8EA30000 */  lw        $v1, ($s5)
/* BA53D4 80240C54 8C420000 */  lw        $v0, ($v0)
/* BA53D8 80240C58 00641824 */  and       $v1, $v1, $a0
/* BA53DC 80240C5C AEA30000 */  sw        $v1, ($s5)
/* BA53E0 80240C60 AEA20028 */  sw        $v0, 0x28($s5)
/* BA53E4 80240C64 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BA53E8 80240C68 8C420034 */  lw        $v0, 0x34($v0)
/* BA53EC 80240C6C 54400005 */  bnel      $v0, $zero, .L80240C84
/* BA53F0 80240C70 2402FDFF */   addiu    $v0, $zero, -0x201
/* BA53F4 80240C74 34620200 */  ori       $v0, $v1, 0x200
/* BA53F8 80240C78 2403FFF7 */  addiu     $v1, $zero, -9
/* BA53FC 80240C7C 08090323 */  j         .L80240C8C
/* BA5400 80240C80 00431024 */   and      $v0, $v0, $v1
.L80240C84:
/* BA5404 80240C84 00621024 */  and       $v0, $v1, $v0
/* BA5408 80240C88 34420008 */  ori       $v0, $v0, 8
.L80240C8C:
/* BA540C 80240C8C AEA20000 */  sw        $v0, ($s5)
/* BA5410 80240C90 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA5414 80240C94 30420004 */  andi      $v0, $v0, 4
/* BA5418 80240C98 10400007 */  beqz      $v0, .L80240CB8
/* BA541C 80240C9C 24020063 */   addiu    $v0, $zero, 0x63
/* BA5420 80240CA0 AE420070 */  sw        $v0, 0x70($s2)
/* BA5424 80240CA4 AE400074 */  sw        $zero, 0x74($s2)
/* BA5428 80240CA8 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA542C 80240CAC 2403FFFB */  addiu     $v1, $zero, -5
/* BA5430 80240CB0 00431024 */  and       $v0, $v0, $v1
/* BA5434 80240CB4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240CB8:
/* BA5438 80240CB8 AE20006C */  sw        $zero, 0x6c($s1)
.L80240CBC:
/* BA543C 80240CBC 8E420070 */  lw        $v0, 0x70($s2)
/* BA5440 80240CC0 2842001E */  slti      $v0, $v0, 0x1e
/* BA5444 80240CC4 10400009 */  beqz      $v0, .L80240CEC
/* BA5448 80240CC8 00000000 */   nop      
/* BA544C 80240CCC 8E22006C */  lw        $v0, 0x6c($s1)
/* BA5450 80240CD0 14400006 */  bnez      $v0, .L80240CEC
/* BA5454 80240CD4 00000000 */   nop      
/* BA5458 80240CD8 0C0901DE */  jal       func_80240778_BA4EF8
/* BA545C 80240CDC 0240202D */   daddu    $a0, $s2, $zero
/* BA5460 80240CE0 10400002 */  beqz      $v0, .L80240CEC
/* BA5464 80240CE4 2402001E */   addiu    $v0, $zero, 0x1e
/* BA5468 80240CE8 AE420070 */  sw        $v0, 0x70($s2)
.L80240CEC:
/* BA546C 80240CEC 8E430070 */  lw        $v1, 0x70($s2)
/* BA5470 80240CF0 2C620064 */  sltiu     $v0, $v1, 0x64
/* BA5474 80240CF4 10400048 */  beqz      $v0, .L80240E18
/* BA5478 80240CF8 00031080 */   sll      $v0, $v1, 2
/* BA547C 80240CFC 3C018024 */  lui       $at, %hi(func_802457B8)
/* BA5480 80240D00 00220821 */  addu      $at, $at, $v0
/* BA5484 80240D04 8C2257B8 */  lw        $v0, %lo(func_802457B8)($at)
/* BA5488 80240D08 00400008 */  jr        $v0
/* BA548C 80240D0C 00000000 */   nop      
/* BA5490 80240D10 0240202D */  daddu     $a0, $s2, $zero
/* BA5494 80240D14 0260282D */  daddu     $a1, $s3, $zero
/* BA5498 80240D18 0C012568 */  jal       func_800495A0
/* BA549C 80240D1C 0280302D */   daddu    $a2, $s4, $zero
/* BA54A0 80240D20 0240202D */  daddu     $a0, $s2, $zero
/* BA54A4 80240D24 0260282D */  daddu     $a1, $s3, $zero
/* BA54A8 80240D28 0C0125AE */  jal       func_800496B8
/* BA54AC 80240D2C 0280302D */   daddu    $a2, $s4, $zero
/* BA54B0 80240D30 08090386 */  j         .L80240E18
/* BA54B4 80240D34 00000000 */   nop      
/* BA54B8 80240D38 0240202D */  daddu     $a0, $s2, $zero
/* BA54BC 80240D3C 0260282D */  daddu     $a1, $s3, $zero
/* BA54C0 80240D40 0C0126D1 */  jal       func_80049B44
/* BA54C4 80240D44 0280302D */   daddu    $a2, $s4, $zero
/* BA54C8 80240D48 0240202D */  daddu     $a0, $s2, $zero
/* BA54CC 80240D4C 0260282D */  daddu     $a1, $s3, $zero
/* BA54D0 80240D50 0C012701 */  jal       func_80049C04
/* BA54D4 80240D54 0280302D */   daddu    $a2, $s4, $zero
/* BA54D8 80240D58 08090386 */  j         .L80240E18
/* BA54DC 80240D5C 00000000 */   nop      
/* BA54E0 80240D60 0240202D */  daddu     $a0, $s2, $zero
/* BA54E4 80240D64 0260282D */  daddu     $a1, $s3, $zero
/* BA54E8 80240D68 0C01278F */  jal       func_80049E3C
/* BA54EC 80240D6C 0280302D */   daddu    $a2, $s4, $zero
/* BA54F0 80240D70 0240202D */  daddu     $a0, $s2, $zero
/* BA54F4 80240D74 0260282D */  daddu     $a1, $s3, $zero
/* BA54F8 80240D78 0C0127B3 */  jal       func_80049ECC
/* BA54FC 80240D7C 0280302D */   daddu    $a2, $s4, $zero
/* BA5500 80240D80 08090386 */  j         .L80240E18
/* BA5504 80240D84 00000000 */   nop      
/* BA5508 80240D88 0240202D */  daddu     $a0, $s2, $zero
/* BA550C 80240D8C 0260282D */  daddu     $a1, $s3, $zero
/* BA5510 80240D90 0C0127DF */  jal       func_80049F7C
/* BA5514 80240D94 0280302D */   daddu    $a2, $s4, $zero
/* BA5518 80240D98 0240202D */  daddu     $a0, $s2, $zero
/* BA551C 80240D9C 0260282D */  daddu     $a1, $s3, $zero
/* BA5520 80240DA0 0C012849 */  jal       func_8004A124
/* BA5524 80240DA4 0280302D */   daddu    $a2, $s4, $zero
/* BA5528 80240DA8 08090386 */  j         .L80240E18
/* BA552C 80240DAC 00000000 */   nop      
/* BA5530 80240DB0 0240202D */  daddu     $a0, $s2, $zero
/* BA5534 80240DB4 0260282D */  daddu     $a1, $s3, $zero
/* BA5538 80240DB8 0C0128FA */  jal       func_8004A3E8
/* BA553C 80240DBC 0280302D */   daddu    $a2, $s4, $zero
/* BA5540 80240DC0 08090386 */  j         .L80240E18
/* BA5544 80240DC4 00000000 */   nop      
/* BA5548 80240DC8 0C09015C */  jal       func_80240570_BA4CF0
/* BA554C 80240DCC 0240202D */   daddu    $a0, $s2, $zero
/* BA5550 80240DD0 0C090177 */  jal       func_802405DC_BA4D5C
/* BA5554 80240DD4 0240202D */   daddu    $a0, $s2, $zero
/* BA5558 80240DD8 8E430070 */  lw        $v1, 0x70($s2)
/* BA555C 80240DDC 24020020 */  addiu     $v0, $zero, 0x20
/* BA5560 80240DE0 1462000D */  bne       $v1, $v0, .L80240E18
/* BA5564 80240DE4 00000000 */   nop      
/* BA5568 80240DE8 0C090193 */  jal       func_8024064C_BA4DCC
/* BA556C 80240DEC 0240202D */   daddu    $a0, $s2, $zero
/* BA5570 80240DF0 8E430070 */  lw        $v1, 0x70($s2)
/* BA5574 80240DF4 24020021 */  addiu     $v0, $zero, 0x21
/* BA5578 80240DF8 14620007 */  bne       $v1, $v0, .L80240E18
/* BA557C 80240DFC 00000000 */   nop      
/* BA5580 80240E00 0C0901C9 */  jal       func_80240724_BA4EA4
/* BA5584 80240E04 0240202D */   daddu    $a0, $s2, $zero
/* BA5588 80240E08 08090386 */  j         .L80240E18
/* BA558C 80240E0C 00000000 */   nop      
/* BA5590 80240E10 0C0129CF */  jal       func_8004A73C
/* BA5594 80240E14 0240202D */   daddu    $a0, $s2, $zero
.L80240E18:
/* BA5598 80240E18 8FBF0048 */  lw        $ra, 0x48($sp)
/* BA559C 80240E1C 8FB50044 */  lw        $s5, 0x44($sp)
/* BA55A0 80240E20 8FB40040 */  lw        $s4, 0x40($sp)
/* BA55A4 80240E24 8FB3003C */  lw        $s3, 0x3c($sp)
/* BA55A8 80240E28 8FB20038 */  lw        $s2, 0x38($sp)
/* BA55AC 80240E2C 8FB10034 */  lw        $s1, 0x34($sp)
/* BA55B0 80240E30 8FB00030 */  lw        $s0, 0x30($sp)
/* BA55B4 80240E34 0000102D */  daddu     $v0, $zero, $zero
/* BA55B8 80240E38 03E00008 */  jr        $ra
/* BA55BC 80240E3C 27BD0050 */   addiu    $sp, $sp, 0x50
