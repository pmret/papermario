.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_998304
/* 998304 80240394 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 998308 80240398 AFB3005C */  sw        $s3, 0x5c($sp)
/* 99830C 8024039C 0080982D */  daddu     $s3, $a0, $zero
/* 998310 802403A0 AFBF0068 */  sw        $ra, 0x68($sp)
/* 998314 802403A4 AFB50064 */  sw        $s5, 0x64($sp)
/* 998318 802403A8 AFB40060 */  sw        $s4, 0x60($sp)
/* 99831C 802403AC AFB20058 */  sw        $s2, 0x58($sp)
/* 998320 802403B0 AFB10054 */  sw        $s1, 0x54($sp)
/* 998324 802403B4 AFB00050 */  sw        $s0, 0x50($sp)
/* 998328 802403B8 8E710148 */  lw        $s1, 0x148($s3)
/* 99832C 802403BC 86240008 */  lh        $a0, 8($s1)
/* 998330 802403C0 0C00EABB */  jal       get_npc_unsafe
/* 998334 802403C4 00A0802D */   daddu    $s0, $a1, $zero
/* 998338 802403C8 8E63000C */  lw        $v1, 0xc($s3)
/* 99833C 802403CC 0260202D */  daddu     $a0, $s3, $zero
/* 998340 802403D0 8C650000 */  lw        $a1, ($v1)
/* 998344 802403D4 0C0B1EAF */  jal       get_variable
/* 998348 802403D8 0040902D */   daddu    $s2, $v0, $zero
/* 99834C 802403DC AFA00028 */  sw        $zero, 0x28($sp)
/* 998350 802403E0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 998354 802403E4 8C630030 */  lw        $v1, 0x30($v1)
/* 998358 802403E8 AFA3002C */  sw        $v1, 0x2c($sp)
/* 99835C 802403EC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 998360 802403F0 8C63001C */  lw        $v1, 0x1c($v1)
/* 998364 802403F4 AFA30030 */  sw        $v1, 0x30($sp)
/* 998368 802403F8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 99836C 802403FC 8C630024 */  lw        $v1, 0x24($v1)
/* 998370 80240400 AFA30034 */  sw        $v1, 0x34($sp)
/* 998374 80240404 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 998378 80240408 8C630028 */  lw        $v1, 0x28($v1)
/* 99837C 8024040C 27B50028 */  addiu     $s5, $sp, 0x28
/* 998380 80240410 AFA30038 */  sw        $v1, 0x38($sp)
/* 998384 80240414 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 998388 80240418 3C0142C8 */  lui       $at, 0x42c8
/* 99838C 8024041C 44810000 */  mtc1      $at, $f0
/* 998390 80240420 8C63002C */  lw        $v1, 0x2c($v1)
/* 998394 80240424 0040A02D */  daddu     $s4, $v0, $zero
/* 998398 80240428 E7A00040 */  swc1      $f0, 0x40($sp)
/* 99839C 8024042C A7A00044 */  sh        $zero, 0x44($sp)
/* 9983A0 80240430 12000009 */  beqz      $s0, .L80240458
/* 9983A4 80240434 AFA3003C */   sw       $v1, 0x3c($sp)
/* 9983A8 80240438 864300A8 */  lh        $v1, 0xa8($s2)
/* 9983AC 8024043C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9983B0 80240440 AE20008C */  sw        $zero, 0x8c($s1)
/* 9983B4 80240444 A22000B5 */  sb        $zero, 0xb5($s1)
/* 9983B8 80240448 34420008 */  ori       $v0, $v0, 8
/* 9983BC 8024044C AE230084 */  sw        $v1, 0x84($s1)
/* 9983C0 80240450 0809011A */  j         .L80240468
/* 9983C4 80240454 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240458:
/* 9983C8 80240458 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9983CC 8024045C 30420004 */  andi      $v0, $v0, 4
/* 9983D0 80240460 10400047 */  beqz      $v0, .L80240580
/* 9983D4 80240464 00000000 */   nop
.L80240468:
/* 9983D8 80240468 AE600070 */  sw        $zero, 0x70($s3)
/* 9983DC 8024046C A640008E */  sh        $zero, 0x8e($s2)
/* 9983E0 80240470 8E2300CC */  lw        $v1, 0xcc($s1)
/* 9983E4 80240474 2404F7FF */  addiu     $a0, $zero, -0x801
/* 9983E8 80240478 A2200007 */  sb        $zero, 7($s1)
/* 9983EC 8024047C 8E420000 */  lw        $v0, ($s2)
/* 9983F0 80240480 8C630000 */  lw        $v1, ($v1)
/* 9983F4 80240484 00441024 */  and       $v0, $v0, $a0
/* 9983F8 80240488 AE420000 */  sw        $v0, ($s2)
/* 9983FC 8024048C AE430028 */  sw        $v1, 0x28($s2)
/* 998400 80240490 96220086 */  lhu       $v0, 0x86($s1)
/* 998404 80240494 A64200A8 */  sh        $v0, 0xa8($s2)
/* 998408 80240498 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 99840C 8024049C AE200090 */  sw        $zero, 0x90($s1)
/* 998410 802404A0 8C420034 */  lw        $v0, 0x34($v0)
/* 998414 802404A4 14400006 */  bnez      $v0, .L802404C0
/* 998418 802404A8 2403FDFF */   addiu    $v1, $zero, -0x201
/* 99841C 802404AC 8E420000 */  lw        $v0, ($s2)
/* 998420 802404B0 2403FFF7 */  addiu     $v1, $zero, -9
/* 998424 802404B4 34420200 */  ori       $v0, $v0, 0x200
/* 998428 802404B8 08090133 */  j         .L802404CC
/* 99842C 802404BC 00431024 */   and      $v0, $v0, $v1
.L802404C0:
/* 998430 802404C0 8E420000 */  lw        $v0, ($s2)
/* 998434 802404C4 00431024 */  and       $v0, $v0, $v1
/* 998438 802404C8 34420008 */  ori       $v0, $v0, 8
.L802404CC:
/* 99843C 802404CC AE420000 */  sw        $v0, ($s2)
/* 998440 802404D0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 998444 802404D4 30420004 */  andi      $v0, $v0, 4
/* 998448 802404D8 1040001E */  beqz      $v0, .L80240554
/* 99844C 802404DC 24040002 */   addiu    $a0, $zero, 2
/* 998450 802404E0 0240282D */  daddu     $a1, $s2, $zero
/* 998454 802404E4 0000302D */  daddu     $a2, $zero, $zero
/* 998458 802404E8 24020063 */  addiu     $v0, $zero, 0x63
/* 99845C 802404EC AE620070 */  sw        $v0, 0x70($s3)
/* 998460 802404F0 AE600074 */  sw        $zero, 0x74($s3)
/* 998464 802404F4 864300A8 */  lh        $v1, 0xa8($s2)
/* 998468 802404F8 3C013F80 */  lui       $at, 0x3f80
/* 99846C 802404FC 44810000 */  mtc1      $at, $f0
/* 998470 80240500 3C014000 */  lui       $at, 0x4000
/* 998474 80240504 44811000 */  mtc1      $at, $f2
/* 998478 80240508 3C01C1A0 */  lui       $at, 0xc1a0
/* 99847C 8024050C 44812000 */  mtc1      $at, $f4
/* 998480 80240510 24020028 */  addiu     $v0, $zero, 0x28
/* 998484 80240514 AFA2001C */  sw        $v0, 0x1c($sp)
/* 998488 80240518 44833000 */  mtc1      $v1, $f6
/* 99848C 8024051C 00000000 */  nop
/* 998490 80240520 468031A0 */  cvt.s.w   $f6, $f6
/* 998494 80240524 44073000 */  mfc1      $a3, $f6
/* 998498 80240528 27A20048 */  addiu     $v0, $sp, 0x48
/* 99849C 8024052C AFA20020 */  sw        $v0, 0x20($sp)
/* 9984A0 80240530 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9984A4 80240534 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9984A8 80240538 0C01BFA4 */  jal       fx_emote
/* 9984AC 8024053C E7A40018 */   swc1     $f4, 0x18($sp)
/* 9984B0 80240540 8E2200B0 */  lw        $v0, 0xb0($s1)
/* 9984B4 80240544 2403FFFB */  addiu     $v1, $zero, -5
/* 9984B8 80240548 00431024 */  and       $v0, $v0, $v1
/* 9984BC 8024054C 08090160 */  j         .L80240580
/* 9984C0 80240550 AE2200B0 */   sw       $v0, 0xb0($s1)
.L80240554:
/* 9984C4 80240554 8E220000 */  lw        $v0, ($s1)
/* 9984C8 80240558 3C034000 */  lui       $v1, 0x4000
/* 9984CC 8024055C 00431024 */  and       $v0, $v0, $v1
/* 9984D0 80240560 10400007 */  beqz      $v0, .L80240580
/* 9984D4 80240564 3C03BFFF */   lui      $v1, 0xbfff
/* 9984D8 80240568 2402000C */  addiu     $v0, $zero, 0xc
/* 9984DC 8024056C AE620070 */  sw        $v0, 0x70($s3)
/* 9984E0 80240570 8E220000 */  lw        $v0, ($s1)
/* 9984E4 80240574 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9984E8 80240578 00431024 */  and       $v0, $v0, $v1
/* 9984EC 8024057C AE220000 */  sw        $v0, ($s1)
.L80240580:
/* 9984F0 80240580 8E220090 */  lw        $v0, 0x90($s1)
/* 9984F4 80240584 1840000C */  blez      $v0, .L802405B8
/* 9984F8 80240588 2442FFFF */   addiu    $v0, $v0, -1
/* 9984FC 8024058C 14400087 */  bnez      $v0, .L802407AC
/* 998500 80240590 AE220090 */   sw       $v0, 0x90($s1)
/* 998504 80240594 3C03FFAA */  lui       $v1, 0xffaa
/* 998508 80240598 8E420028 */  lw        $v0, 0x28($s2)
/* 99850C 8024059C 3463FFD2 */  ori       $v1, $v1, 0xffd2
/* 998510 802405A0 00431021 */  addu      $v0, $v0, $v1
/* 998514 802405A4 2C420002 */  sltiu     $v0, $v0, 2
/* 998518 802405A8 10400003 */  beqz      $v0, .L802405B8
/* 99851C 802405AC 3C020055 */   lui      $v0, 0x55
/* 998520 802405B0 3442000C */  ori       $v0, $v0, 0xc
/* 998524 802405B4 AE420028 */  sw        $v0, 0x28($s2)
.L802405B8:
/* 998528 802405B8 8E630070 */  lw        $v1, 0x70($s3)
/* 99852C 802405BC 2402000C */  addiu     $v0, $zero, 0xc
/* 998530 802405C0 10620048 */  beq       $v1, $v0, .L802406E4
/* 998534 802405C4 2862000D */   slti     $v0, $v1, 0xd
/* 998538 802405C8 1040000F */  beqz      $v0, .L80240608
/* 99853C 802405CC 24100001 */   addiu    $s0, $zero, 1
/* 998540 802405D0 1070001E */  beq       $v1, $s0, .L8024064C
/* 998544 802405D4 28620002 */   slti     $v0, $v1, 2
/* 998548 802405D8 10400005 */  beqz      $v0, .L802405F0
/* 99854C 802405DC 24020002 */   addiu    $v0, $zero, 2
/* 998550 802405E0 10600015 */  beqz      $v1, .L80240638
/* 998554 802405E4 0260202D */   daddu    $a0, $s3, $zero
/* 998558 802405E8 080901D0 */  j         .L80240740
/* 99855C 802405EC 00000000 */   nop
.L802405F0:
/* 998560 802405F0 1062001C */  beq       $v1, $v0, .L80240664
/* 998564 802405F4 24020003 */   addiu    $v0, $zero, 3
/* 998568 802405F8 10620035 */  beq       $v1, $v0, .L802406D0
/* 99856C 802405FC 0260202D */   daddu    $a0, $s3, $zero
/* 998570 80240600 080901D0 */  j         .L80240740
/* 998574 80240604 00000000 */   nop
.L80240608:
/* 998578 80240608 2402000E */  addiu     $v0, $zero, 0xe
/* 99857C 8024060C 1062003F */  beq       $v1, $v0, .L8024070C
/* 998580 80240610 0062102A */   slt      $v0, $v1, $v0
/* 998584 80240614 14400038 */  bnez      $v0, .L802406F8
/* 998588 80240618 0260202D */   daddu    $a0, $s3, $zero
/* 99858C 8024061C 2402000F */  addiu     $v0, $zero, 0xf
/* 998590 80240620 10620040 */  beq       $v1, $v0, .L80240724
/* 998594 80240624 24020063 */   addiu    $v0, $zero, 0x63
/* 998598 80240628 10620043 */  beq       $v1, $v0, .L80240738
/* 99859C 8024062C 00000000 */   nop
/* 9985A0 80240630 080901D0 */  j         .L80240740
/* 9985A4 80240634 00000000 */   nop
.L80240638:
/* 9985A8 80240638 0280282D */  daddu     $a1, $s4, $zero
/* 9985AC 8024063C 0C012568 */  jal       func_800495A0
/* 9985B0 80240640 02A0302D */   daddu    $a2, $s5, $zero
/* 9985B4 80240644 96220086 */  lhu       $v0, 0x86($s1)
/* 9985B8 80240648 A64200A8 */  sh        $v0, 0xa8($s2)
.L8024064C:
/* 9985BC 8024064C 0260202D */  daddu     $a0, $s3, $zero
/* 9985C0 80240650 0280282D */  daddu     $a1, $s4, $zero
/* 9985C4 80240654 0C0125AE */  jal       func_800496B8
/* 9985C8 80240658 02A0302D */   daddu    $a2, $s5, $zero
/* 9985CC 8024065C 080901D0 */  j         .L80240740
/* 9985D0 80240660 00000000 */   nop
.L80240664:
/* 9985D4 80240664 0260202D */  daddu     $a0, $s3, $zero
/* 9985D8 80240668 0280282D */  daddu     $a1, $s4, $zero
/* 9985DC 8024066C 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* 9985E0 80240670 02A0302D */   daddu    $a2, $s5, $zero
/* 9985E4 80240674 8E230088 */  lw        $v1, 0x88($s1)
/* 9985E8 80240678 24020006 */  addiu     $v0, $zero, 6
/* 9985EC 8024067C 14620014 */  bne       $v1, $v0, .L802406D0
/* 9985F0 80240680 0260202D */   daddu    $a0, $s3, $zero
/* 9985F4 80240684 0C00A67F */  jal       rand_int
/* 9985F8 80240688 24040064 */   addiu    $a0, $zero, 0x64
/* 9985FC 8024068C 28420021 */  slti      $v0, $v0, 0x21
/* 998600 80240690 5040000F */  beql      $v0, $zero, .L802406D0
/* 998604 80240694 0260202D */   daddu    $a0, $s3, $zero
/* 998608 80240698 8E22008C */  lw        $v0, 0x8c($s1)
/* 99860C 8024069C 10400005 */  beqz      $v0, .L802406B4
/* 998610 802406A0 3C020055 */   lui      $v0, 0x55
/* 998614 802406A4 3442002F */  ori       $v0, $v0, 0x2f
/* 998618 802406A8 AE20008C */  sw        $zero, 0x8c($s1)
/* 99861C 802406AC 080901B0 */  j         .L802406C0
/* 998620 802406B0 A22000B5 */   sb       $zero, 0xb5($s1)
.L802406B4:
/* 998624 802406B4 3442002E */  ori       $v0, $v0, 0x2e
/* 998628 802406B8 AE30008C */  sw        $s0, 0x8c($s1)
/* 99862C 802406BC A23000B5 */  sb        $s0, 0xb5($s1)
.L802406C0:
/* 998630 802406C0 AE420028 */  sw        $v0, 0x28($s2)
/* 998634 802406C4 24020007 */  addiu     $v0, $zero, 7
/* 998638 802406C8 080901EB */  j         .L802407AC
/* 99863C 802406CC AE220090 */   sw       $v0, 0x90($s1)
.L802406D0:
/* 998640 802406D0 0280282D */  daddu     $a1, $s4, $zero
/* 998644 802406D4 0C012701 */  jal       func_80049C04
/* 998648 802406D8 02A0302D */   daddu    $a2, $s5, $zero
/* 99864C 802406DC 080901D0 */  j         .L80240740
/* 998650 802406E0 00000000 */   nop
.L802406E4:
/* 998654 802406E4 0260202D */  daddu     $a0, $s3, $zero
/* 998658 802406E8 0280282D */  daddu     $a1, $s4, $zero
/* 99865C 802406EC 0C090000 */  jal       isk_18_set_script_owner_npc_anim
/* 998660 802406F0 02A0302D */   daddu    $a2, $s5, $zero
/* 998664 802406F4 0260202D */  daddu     $a0, $s3, $zero
.L802406F8:
/* 998668 802406F8 0280282D */  daddu     $a1, $s4, $zero
/* 99866C 802406FC 0C09001F */  jal       func_8024007C_997FEC
/* 998670 80240700 02A0302D */   daddu    $a2, $s5, $zero
/* 998674 80240704 080901D0 */  j         .L80240740
/* 998678 80240708 00000000 */   nop
.L8024070C:
/* 99867C 8024070C 0260202D */  daddu     $a0, $s3, $zero
/* 998680 80240710 0280282D */  daddu     $a1, $s4, $zero
/* 998684 80240714 0C09006C */  jal       isk_18_UnkNpcAIFunc12
/* 998688 80240718 02A0302D */   daddu    $a2, $s5, $zero
/* 99868C 8024071C 080901D0 */  j         .L80240740
/* 998690 80240720 00000000 */   nop
.L80240724:
/* 998694 80240724 0280282D */  daddu     $a1, $s4, $zero
/* 998698 80240728 0C0900C5 */  jal       isk_18_set_script_owner_npc_col_height
/* 99869C 8024072C 02A0302D */   daddu    $a2, $s5, $zero
/* 9986A0 80240730 080901D0 */  j         .L80240740
/* 9986A4 80240734 00000000 */   nop
.L80240738:
/* 9986A8 80240738 0C0129CF */  jal       func_8004A73C
/* 9986AC 8024073C 0260202D */   daddu    $a0, $s3, $zero
.L80240740:
/* 9986B0 80240740 8E230088 */  lw        $v1, 0x88($s1)
/* 9986B4 80240744 24020006 */  addiu     $v0, $zero, 6
/* 9986B8 80240748 14620019 */  bne       $v1, $v0, .L802407B0
/* 9986BC 8024074C 0000102D */   daddu    $v0, $zero, $zero
/* 9986C0 80240750 8E22008C */  lw        $v0, 0x8c($s1)
/* 9986C4 80240754 10400003 */  beqz      $v0, .L80240764
/* 9986C8 80240758 24020001 */   addiu    $v0, $zero, 1
/* 9986CC 8024075C 080901DA */  j         .L80240768
/* 9986D0 80240760 A22200B5 */   sb       $v0, 0xb5($s1)
.L80240764:
/* 9986D4 80240764 A22000B5 */  sb        $zero, 0xb5($s1)
.L80240768:
/* 9986D8 80240768 8E22008C */  lw        $v0, 0x8c($s1)
/* 9986DC 8024076C 1040000F */  beqz      $v0, .L802407AC
/* 9986E0 80240770 3C03FFAA */   lui      $v1, 0xffaa
/* 9986E4 80240774 8E420028 */  lw        $v0, 0x28($s2)
/* 9986E8 80240778 3463FFFC */  ori       $v1, $v1, 0xfffc
/* 9986EC 8024077C 00431821 */  addu      $v1, $v0, $v1
/* 9986F0 80240780 2C620015 */  sltiu     $v0, $v1, 0x15
/* 9986F4 80240784 10400009 */  beqz      $v0, .L802407AC
/* 9986F8 80240788 00031080 */   sll      $v0, $v1, 2
/* 9986FC 8024078C 3C018024 */  lui       $at, %hi(jtbl_80241778_9996E8)
/* 998700 80240790 00220821 */  addu      $at, $at, $v0
/* 998704 80240794 8C221778 */  lw        $v0, %lo(jtbl_80241778_9996E8)($at)
/* 998708 80240798 00400008 */  jr        $v0
/* 99870C 8024079C 00000000 */   nop
glabel L802407A0_998710
/* 998710 802407A0 8E420028 */  lw        $v0, 0x28($s2)
/* 998714 802407A4 24420001 */  addiu     $v0, $v0, 1
/* 998718 802407A8 AE420028 */  sw        $v0, 0x28($s2)
.L802407AC:
glabel L802407AC_99871C
/* 99871C 802407AC 0000102D */  daddu     $v0, $zero, $zero
.L802407B0:
/* 998720 802407B0 8FBF0068 */  lw        $ra, 0x68($sp)
/* 998724 802407B4 8FB50064 */  lw        $s5, 0x64($sp)
/* 998728 802407B8 8FB40060 */  lw        $s4, 0x60($sp)
/* 99872C 802407BC 8FB3005C */  lw        $s3, 0x5c($sp)
/* 998730 802407C0 8FB20058 */  lw        $s2, 0x58($sp)
/* 998734 802407C4 8FB10054 */  lw        $s1, 0x54($sp)
/* 998738 802407C8 8FB00050 */  lw        $s0, 0x50($sp)
/* 99873C 802407CC 03E00008 */  jr        $ra
/* 998740 802407D0 27BD0070 */   addiu    $sp, $sp, 0x70
