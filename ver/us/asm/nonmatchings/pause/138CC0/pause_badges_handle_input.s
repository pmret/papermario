.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_badges_handle_input
/* 13C3E8 802490A8 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentPage)
/* 13C3EC 802490AC 8C630280 */  lw        $v1, %lo(gBadgeMenuCurrentPage)($v1)
/* 13C3F0 802490B0 3C098027 */  lui       $t1, %hi(gBadgeMenuSelectedIndex)
/* 13C3F4 802490B4 8D290378 */  lw        $t1, %lo(gBadgeMenuSelectedIndex)($t1)
/* 13C3F8 802490B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13C3FC 802490BC AFBF001C */  sw        $ra, 0x1c($sp)
/* 13C400 802490C0 AFB20018 */  sw        $s2, 0x18($sp)
/* 13C404 802490C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 13C408 802490C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 13C40C 802490CC 00031040 */  sll       $v0, $v1, 1
/* 13C410 802490D0 00431021 */  addu      $v0, $v0, $v1
/* 13C414 802490D4 00021080 */  sll       $v0, $v0, 2
/* 13C418 802490D8 3C018027 */  lui       $at, %hi(D_8027028A)
/* 13C41C 802490DC 00220821 */  addu      $at, $at, $v0
/* 13C420 802490E0 9022028A */  lbu       $v0, %lo(D_8027028A)($at)
/* 13C424 802490E4 3C038027 */  lui       $v1, %hi(gPauseMenuPressedButtons)
/* 13C428 802490E8 8C6300C4 */  lw        $v1, %lo(gPauseMenuPressedButtons)($v1)
/* 13C42C 802490EC 14400002 */  bnez      $v0, .L802490F8
/* 13C430 802490F0 0122001A */   div      $zero, $t1, $v0
/* 13C434 802490F4 0007000D */  break     7
.L802490F8:
/* 13C438 802490F8 2401FFFF */   addiu    $at, $zero, -1
/* 13C43C 802490FC 14410004 */  bne       $v0, $at, .L80249110
/* 13C440 80249100 3C018000 */   lui      $at, 0x8000
/* 13C444 80249104 15210002 */  bne       $t1, $at, .L80249110
/* 13C448 80249108 00000000 */   nop
/* 13C44C 8024910C 0006000D */  break     6
.L80249110:
/* 13C450 80249110 00002812 */   mflo     $a1
/* 13C454 80249114 00004010 */  mfhi      $t0
/* 13C458 80249118 30628000 */  andi      $v0, $v1, 0x8000
/* 13C45C 8024911C 1040003F */  beqz      $v0, .L8024921C
/* 13C460 80249120 00000000 */   nop
/* 13C464 80249124 3C128027 */  lui       $s2, %hi(gBadgeMenuBShowNotEnoughBP)
/* 13C468 80249128 265203A0 */  addiu     $s2, $s2, %lo(gBadgeMenuBShowNotEnoughBP)
/* 13C46C 8024912C 8E420000 */  lw        $v0, ($s2)
/* 13C470 80249130 10400003 */  beqz      $v0, .L80249140
/* 13C474 80249134 00000000 */   nop
/* 13C478 80249138 08092581 */  j         .L80249604
/* 13C47C 8024913C AE400000 */   sw       $zero, ($s2)
.L80249140:
/* 13C480 80249140 3C048027 */  lui       $a0, %hi(gBadgeMenuLevel)
/* 13C484 80249144 24840398 */  addiu     $a0, $a0, %lo(gBadgeMenuLevel)
/* 13C488 80249148 8C820000 */  lw        $v0, ($a0)
/* 13C48C 8024914C 14400010 */  bnez      $v0, .L80249190
/* 13C490 80249150 00091040 */   sll      $v0, $t1, 1
/* 13C494 80249154 3C038027 */  lui       $v1, %hi(gBadgeMenuItemIDs)
/* 13C498 80249158 00621821 */  addu      $v1, $v1, $v0
/* 13C49C 8024915C 84630180 */  lh        $v1, %lo(gBadgeMenuItemIDs)($v1)
/* 13C4A0 80249160 24027FFE */  addiu     $v0, $zero, 0x7ffe
/* 13C4A4 80249164 14620005 */  bne       $v1, $v0, .L8024917C
/* 13C4A8 80249168 24020001 */   addiu    $v0, $zero, 1
/* 13C4AC 8024916C 0C05272D */  jal       sfx_play_sound
/* 13C4B0 80249170 2404021D */   addiu    $a0, $zero, 0x21d
/* 13C4B4 80249174 08092581 */  j         .L80249604
/* 13C4B8 80249178 00000000 */   nop
.L8024917C:
/* 13C4BC 8024917C AC820000 */  sw        $v0, ($a0)
/* 13C4C0 80249180 0C05272D */  jal       sfx_play_sound
/* 13C4C4 80249184 240400C9 */   addiu    $a0, $zero, 0xc9
/* 13C4C8 80249188 08092581 */  j         .L80249604
/* 13C4CC 8024918C 00000000 */   nop
.L80249190:
/* 13C4D0 80249190 3C118027 */  lui       $s1, %hi(gBadgeMenuItemIDs)
/* 13C4D4 80249194 02228821 */  addu      $s1, $s1, $v0
/* 13C4D8 80249198 86310180 */  lh        $s1, %lo(gBadgeMenuItemIDs)($s1)
/* 13C4DC 8024919C 0C091CCE */  jal       pause_badges_try_equip
/* 13C4E0 802491A0 0220202D */   daddu    $a0, $s1, $zero
/* 13C4E4 802491A4 0040802D */  daddu     $s0, $v0, $zero
/* 13C4E8 802491A8 24020001 */  addiu     $v0, $zero, 1
/* 13C4EC 802491AC 12020013 */  beq       $s0, $v0, .L802491FC
/* 13C4F0 802491B0 2A020002 */   slti     $v0, $s0, 2
/* 13C4F4 802491B4 50400005 */  beql      $v0, $zero, .L802491CC
/* 13C4F8 802491B8 24020002 */   addiu    $v0, $zero, 2
/* 13C4FC 802491BC 12000009 */  beqz      $s0, .L802491E4
/* 13C500 802491C0 00000000 */   nop
/* 13C504 802491C4 08092581 */  j         .L80249604
/* 13C508 802491C8 00000000 */   nop
.L802491CC:
/* 13C50C 802491CC 1202000B */  beq       $s0, $v0, .L802491FC
/* 13C510 802491D0 24020003 */   addiu    $v0, $zero, 3
/* 13C514 802491D4 1202000D */  beq       $s0, $v0, .L8024920C
/* 13C518 802491D8 00000000 */   nop
/* 13C51C 802491DC 08092581 */  j         .L80249604
/* 13C520 802491E0 00000000 */   nop
.L802491E4:
/* 13C524 802491E4 0C05272D */  jal       sfx_play_sound
/* 13C528 802491E8 24040006 */   addiu    $a0, $zero, 6
/* 13C52C 802491EC 0C091CAC */  jal       pause_badges_try_remove
/* 13C530 802491F0 0220202D */   daddu    $a0, $s1, $zero
/* 13C534 802491F4 08092581 */  j         .L80249604
/* 13C538 802491F8 00000000 */   nop
.L802491FC:
/* 13C53C 802491FC 0C05272D */  jal       sfx_play_sound
/* 13C540 80249200 2404021D */   addiu    $a0, $zero, 0x21d
/* 13C544 80249204 08092581 */  j         .L80249604
/* 13C548 80249208 AE500000 */   sw       $s0, ($s2)
.L8024920C:
/* 13C54C 8024920C 0C05272D */  jal       sfx_play_sound
/* 13C550 80249210 24040005 */   addiu    $a0, $zero, 5
/* 13C554 80249214 08092581 */  j         .L80249604
/* 13C558 80249218 00000000 */   nop
.L8024921C:
/* 13C55C 8024921C 14600005 */  bnez      $v1, .L80249234
/* 13C560 80249220 00000000 */   nop
/* 13C564 80249224 3C028027 */  lui       $v0, %hi(gPauseMenuHeldButtons)
/* 13C568 80249228 8C4200C0 */  lw        $v0, %lo(gPauseMenuHeldButtons)($v0)
/* 13C56C 8024922C 10400003 */  beqz      $v0, .L8024923C
/* 13C570 80249230 00000000 */   nop
.L80249234:
/* 13C574 80249234 3C018027 */  lui       $at, %hi(gBadgeMenuBShowNotEnoughBP)
/* 13C578 80249238 AC2003A0 */  sw        $zero, %lo(gBadgeMenuBShowNotEnoughBP)($at)
.L8024923C:
/* 13C57C 8024923C 3C028027 */  lui       $v0, %hi(gBadgeMenuNumItems)
/* 13C580 80249240 84420384 */  lh        $v0, %lo(gBadgeMenuNumItems)($v0)
/* 13C584 80249244 104000B1 */  beqz      $v0, .L8024950C
/* 13C588 80249248 00000000 */   nop
/* 13C58C 8024924C 3C028027 */  lui       $v0, %hi(gBadgeMenuLevel)
/* 13C590 80249250 8C420398 */  lw        $v0, %lo(gBadgeMenuLevel)($v0)
/* 13C594 80249254 14400015 */  bnez      $v0, .L802492AC
/* 13C598 80249258 3C020001 */   lui      $v0, 1
/* 13C59C 8024925C 3C108027 */  lui       $s0, %hi(gBadgeMenuCurrentTab)
/* 13C5A0 80249260 2610039C */  addiu     $s0, $s0, %lo(gBadgeMenuCurrentTab)
/* 13C5A4 80249264 3C028027 */  lui       $v0, %hi(gPauseMenuHeldButtons)
/* 13C5A8 80249268 8C4200C0 */  lw        $v0, %lo(gPauseMenuHeldButtons)($v0)
/* 13C5AC 8024926C 3C030003 */  lui       $v1, 3
/* 13C5B0 80249270 00431024 */  and       $v0, $v0, $v1
/* 13C5B4 80249274 8E030000 */  lw        $v1, ($s0)
/* 13C5B8 80249278 10400002 */  beqz      $v0, .L80249284
/* 13C5BC 8024927C 38620001 */   xori     $v0, $v1, 1
/* 13C5C0 80249280 AE020000 */  sw        $v0, ($s0)
.L80249284:
/* 13C5C4 80249284 8E020000 */  lw        $v0, ($s0)
/* 13C5C8 80249288 106200A0 */  beq       $v1, $v0, .L8024950C
/* 13C5CC 8024928C 00000000 */   nop
/* 13C5D0 80249290 0C05272D */  jal       sfx_play_sound
/* 13C5D4 80249294 240400C8 */   addiu    $a0, $zero, 0xc8
/* 13C5D8 80249298 8E040000 */  lw        $a0, ($s0)
/* 13C5DC 8024929C 0C092363 */  jal       pause_badges_load_badges
/* 13C5E0 802492A0 00000000 */   nop
/* 13C5E4 802492A4 08092543 */  j         .L8024950C
/* 13C5E8 802492A8 00000000 */   nop
.L802492AC:
/* 13C5EC 802492AC 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13C5F0 802492B0 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13C5F4 802492B4 34422000 */  ori       $v0, $v0, 0x2000
/* 13C5F8 802492B8 00621024 */  and       $v0, $v1, $v0
/* 13C5FC 802492BC 10400022 */  beqz      $v0, .L80249348
/* 13C600 802492C0 3C020001 */   lui      $v0, 1
/* 13C604 802492C4 00621024 */  and       $v0, $v1, $v0
/* 13C608 802492C8 10400011 */  beqz      $v0, .L80249310
/* 13C60C 802492CC 24A5FFFF */   addiu    $a1, $a1, -1
/* 13C610 802492D0 04A20001 */  bltzl     $a1, .L802492D8
/* 13C614 802492D4 0000282D */   daddu    $a1, $zero, $zero
.L802492D8:
/* 13C618 802492D8 3C048027 */  lui       $a0, %hi(gBadgeMenuCurrentPage)
/* 13C61C 802492DC 24840280 */  addiu     $a0, $a0, %lo(gBadgeMenuCurrentPage)
/* 13C620 802492E0 8C830000 */  lw        $v1, ($a0)
/* 13C624 802492E4 00031040 */  sll       $v0, $v1, 1
/* 13C628 802492E8 00431021 */  addu      $v0, $v0, $v1
/* 13C62C 802492EC 00021080 */  sll       $v0, $v0, 2
/* 13C630 802492F0 3C018027 */  lui       $at, %hi(D_80270289)
/* 13C634 802492F4 00220821 */  addu      $at, $at, $v0
/* 13C638 802492F8 90220289 */  lbu       $v0, %lo(D_80270289)($at)
/* 13C63C 802492FC 00A2102A */  slt       $v0, $a1, $v0
/* 13C640 80249300 10400011 */  beqz      $v0, .L80249348
/* 13C644 80249304 2462FFFF */   addiu    $v0, $v1, -1
/* 13C648 80249308 080924D2 */  j         .L80249348
/* 13C64C 8024930C AC820000 */   sw       $v0, ($a0)
.L80249310:
/* 13C650 80249310 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentPage)
/* 13C654 80249314 24630280 */  addiu     $v1, $v1, %lo(gBadgeMenuCurrentPage)
/* 13C658 80249318 8C620000 */  lw        $v0, ($v1)
/* 13C65C 8024931C 2442FFFF */  addiu     $v0, $v0, -1
/* 13C660 80249320 04410002 */  bgez      $v0, .L8024932C
/* 13C664 80249324 AC620000 */   sw       $v0, ($v1)
/* 13C668 80249328 AC600000 */  sw        $zero, ($v1)
.L8024932C:
/* 13C66C 8024932C 8C630000 */  lw        $v1, ($v1)
/* 13C670 80249330 00031040 */  sll       $v0, $v1, 1
/* 13C674 80249334 00431021 */  addu      $v0, $v0, $v1
/* 13C678 80249338 00021080 */  sll       $v0, $v0, 2
/* 13C67C 8024933C 3C058027 */  lui       $a1, %hi(D_80270289)
/* 13C680 80249340 00A22821 */  addu      $a1, $a1, $v0
/* 13C684 80249344 90A50289 */  lbu       $a1, %lo(D_80270289)($a1)
.L80249348:
/* 13C688 80249348 3C020002 */  lui       $v0, 2
/* 13C68C 8024934C 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13C690 80249350 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13C694 80249354 34420010 */  ori       $v0, $v0, 0x10
/* 13C698 80249358 00621024 */  and       $v0, $v1, $v0
/* 13C69C 8024935C 10400030 */  beqz      $v0, .L80249420
/* 13C6A0 80249360 3C020002 */   lui      $v0, 2
/* 13C6A4 80249364 00621024 */  and       $v0, $v1, $v0
/* 13C6A8 80249368 1040001C */  beqz      $v0, .L802493DC
/* 13C6AC 8024936C 00000000 */   nop
/* 13C6B0 80249370 3C068027 */  lui       $a2, %hi(gBadgeMenuCurrentPage)
/* 13C6B4 80249374 24C60280 */  addiu     $a2, $a2, %lo(gBadgeMenuCurrentPage)
/* 13C6B8 80249378 8CC40000 */  lw        $a0, ($a2)
/* 13C6BC 8024937C 3C078027 */  lui       $a3, %hi(gBadgeMenuPages)
/* 13C6C0 80249380 24E70288 */  addiu     $a3, $a3, %lo(gBadgeMenuPages)
/* 13C6C4 80249384 00041040 */  sll       $v0, $a0, 1
/* 13C6C8 80249388 00441021 */  addu      $v0, $v0, $a0
/* 13C6CC 8024938C 00021080 */  sll       $v0, $v0, 2
/* 13C6D0 80249390 00471021 */  addu      $v0, $v0, $a3
/* 13C6D4 80249394 90430001 */  lbu       $v1, 1($v0)
/* 13C6D8 80249398 90420003 */  lbu       $v0, 3($v0)
/* 13C6DC 8024939C 24A50001 */  addiu     $a1, $a1, 1
/* 13C6E0 802493A0 00621821 */  addu      $v1, $v1, $v0
/* 13C6E4 802493A4 00A3182A */  slt       $v1, $a1, $v1
/* 13C6E8 802493A8 1460001D */  bnez      $v1, .L80249420
/* 13C6EC 802493AC 24820001 */   addiu    $v0, $a0, 1
/* 13C6F0 802493B0 00021840 */  sll       $v1, $v0, 1
/* 13C6F4 802493B4 00621821 */  addu      $v1, $v1, $v0
/* 13C6F8 802493B8 00031880 */  sll       $v1, $v1, 2
/* 13C6FC 802493BC 00671821 */  addu      $v1, $v1, $a3
/* 13C700 802493C0 ACC20000 */  sw        $v0, ($a2)
/* 13C704 802493C4 90620000 */  lbu       $v0, ($v1)
/* 13C708 802493C8 14400015 */  bnez      $v0, .L80249420
/* 13C70C 802493CC 00000000 */   nop
/* 13C710 802493D0 ACC40000 */  sw        $a0, ($a2)
/* 13C714 802493D4 08092508 */  j         .L80249420
/* 13C718 802493D8 24A5FFFF */   addiu    $a1, $a1, -1
.L802493DC:
/* 13C71C 802493DC 3C068027 */  lui       $a2, %hi(gBadgeMenuCurrentPage)
/* 13C720 802493E0 24C60280 */  addiu     $a2, $a2, %lo(gBadgeMenuCurrentPage)
/* 13C724 802493E4 8CC70000 */  lw        $a3, ($a2)
/* 13C728 802493E8 3C048027 */  lui       $a0, %hi(gBadgeMenuPages)
/* 13C72C 802493EC 24840288 */  addiu     $a0, $a0, %lo(gBadgeMenuPages)
/* 13C730 802493F0 24E30001 */  addiu     $v1, $a3, 1
/* 13C734 802493F4 00031040 */  sll       $v0, $v1, 1
/* 13C738 802493F8 00431021 */  addu      $v0, $v0, $v1
/* 13C73C 802493FC 00021080 */  sll       $v0, $v0, 2
/* 13C740 80249400 ACC30000 */  sw        $v1, ($a2)
/* 13C744 80249404 00441821 */  addu      $v1, $v0, $a0
/* 13C748 80249408 90620000 */  lbu       $v0, ($v1)
/* 13C74C 8024940C 14400003 */  bnez      $v0, .L8024941C
/* 13C750 80249410 00000000 */   nop
/* 13C754 80249414 08092508 */  j         .L80249420
/* 13C758 80249418 ACC70000 */   sw       $a3, ($a2)
.L8024941C:
/* 13C75C 8024941C 90650001 */  lbu       $a1, 1($v1)
.L80249420:
/* 13C760 80249420 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentPage)
/* 13C764 80249424 8C630280 */  lw        $v1, %lo(gBadgeMenuCurrentPage)($v1)
/* 13C768 80249428 00031040 */  sll       $v0, $v1, 1
/* 13C76C 8024942C 00431021 */  addu      $v0, $v0, $v1
/* 13C770 80249430 00021080 */  sll       $v0, $v0, 2
/* 13C774 80249434 3C048027 */  lui       $a0, %hi(D_8027028A)
/* 13C778 80249438 00822021 */  addu      $a0, $a0, $v0
/* 13C77C 8024943C 9084028A */  lbu       $a0, %lo(D_8027028A)($a0)
/* 13C780 80249440 00A40018 */  mult      $a1, $a0
/* 13C784 80249444 00005012 */  mflo      $t2
/* 13C788 80249448 000A1040 */  sll       $v0, $t2, 1
/* 13C78C 8024944C 3C038027 */  lui       $v1, %hi(gBadgeMenuItemIDs)
/* 13C790 80249450 00621821 */  addu      $v1, $v1, $v0
/* 13C794 80249454 84630180 */  lh        $v1, %lo(gBadgeMenuItemIDs)($v1)
/* 13C798 80249458 24027FFE */  addiu     $v0, $zero, 0x7ffe
/* 13C79C 8024945C 10620012 */  beq       $v1, $v0, .L802494A8
/* 13C7A0 80249460 3C020004 */   lui      $v0, 4
/* 13C7A4 80249464 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13C7A8 80249468 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13C7AC 8024946C 00621024 */  and       $v0, $v1, $v0
/* 13C7B0 80249470 10400006 */  beqz      $v0, .L8024948C
/* 13C7B4 80249474 3C020008 */   lui      $v0, 8
/* 13C7B8 80249478 2508FFFF */  addiu     $t0, $t0, -1
/* 13C7BC 8024947C 0502000B */  bltzl     $t0, .L802494AC
/* 13C7C0 80249480 2488FFFF */   addiu    $t0, $a0, -1
/* 13C7C4 80249484 0809252B */  j         .L802494AC
/* 13C7C8 80249488 00000000 */   nop
.L8024948C:
/* 13C7CC 8024948C 00621024 */  and       $v0, $v1, $v0
/* 13C7D0 80249490 10400006 */  beqz      $v0, .L802494AC
/* 13C7D4 80249494 00000000 */   nop
/* 13C7D8 80249498 25080001 */  addiu     $t0, $t0, 1
/* 13C7DC 8024949C 0104102A */  slt       $v0, $t0, $a0
/* 13C7E0 802494A0 14400002 */  bnez      $v0, .L802494AC
/* 13C7E4 802494A4 00000000 */   nop
.L802494A8:
/* 13C7E8 802494A8 0000402D */  daddu     $t0, $zero, $zero
.L802494AC:
/* 13C7EC 802494AC 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentPage)
/* 13C7F0 802494B0 8C630280 */  lw        $v1, %lo(gBadgeMenuCurrentPage)($v1)
/* 13C7F4 802494B4 00031040 */  sll       $v0, $v1, 1
/* 13C7F8 802494B8 00431021 */  addu      $v0, $v0, $v1
/* 13C7FC 802494BC 00021080 */  sll       $v0, $v0, 2
/* 13C800 802494C0 3C018027 */  lui       $at, %hi(D_8027028A)
/* 13C804 802494C4 00220821 */  addu      $at, $at, $v0
/* 13C808 802494C8 9022028A */  lbu       $v0, %lo(D_8027028A)($at)
/* 13C80C 802494CC 00A20018 */  mult      $a1, $v0
/* 13C810 802494D0 3C108027 */  lui       $s0, %hi(gBadgeMenuSelectedIndex)
/* 13C814 802494D4 26100378 */  addiu     $s0, $s0, %lo(gBadgeMenuSelectedIndex)
/* 13C818 802494D8 00005012 */  mflo      $t2
/* 13C81C 802494DC 010A1021 */  addu      $v0, $t0, $t2
/* 13C820 802494E0 10490003 */  beq       $v0, $t1, .L802494F0
/* 13C824 802494E4 AE020000 */   sw       $v0, ($s0)
/* 13C828 802494E8 0C05272D */  jal       sfx_play_sound
/* 13C82C 802494EC 240400C7 */   addiu    $a0, $zero, 0xc7
.L802494F0:
/* 13C830 802494F0 8E020000 */  lw        $v0, ($s0)
/* 13C834 802494F4 00021040 */  sll       $v0, $v0, 1
/* 13C838 802494F8 3C018027 */  lui       $at, %hi(gBadgeMenuItemIDs)
/* 13C83C 802494FC 00220821 */  addu      $at, $at, $v0
/* 13C840 80249500 84220180 */  lh        $v0, %lo(gBadgeMenuItemIDs)($at)
/* 13C844 80249504 3C018027 */  lui       $at, %hi(gBadgeMenuSelectedItemID)
/* 13C848 80249508 AC220380 */  sw        $v0, %lo(gBadgeMenuSelectedItemID)($at)
.L8024950C:
/* 13C84C 8024950C 3C038027 */  lui       $v1, %hi(gBadgeMenuLevel)
/* 13C850 80249510 8C630398 */  lw        $v1, %lo(gBadgeMenuLevel)($v1)
/* 13C854 80249514 24020001 */  addiu     $v0, $zero, 1
/* 13C858 80249518 14620014 */  bne       $v1, $v0, .L8024956C
/* 13C85C 8024951C 00000000 */   nop
/* 13C860 80249520 3C038027 */  lui       $v1, %hi(gBadgeMenuSelectedItemID)
/* 13C864 80249524 8C630380 */  lw        $v1, %lo(gBadgeMenuSelectedItemID)($v1)
/* 13C868 80249528 24628002 */  addiu     $v0, $v1, -0x7ffe
/* 13C86C 8024952C 2C420002 */  sltiu     $v0, $v0, 2
/* 13C870 80249530 1440000A */  bnez      $v0, .L8024955C
/* 13C874 80249534 00000000 */   nop
/* 13C878 80249538 10600008 */  beqz      $v1, .L8024955C
/* 13C87C 8024953C 00031140 */   sll      $v0, $v1, 5
/* 13C880 80249540 3C018008 */  lui       $at, %hi(gItemTable+0x10)
/* 13C884 80249544 00220821 */  addu      $at, $at, $v0
/* 13C888 80249548 8C2278F0 */  lw        $v0, %lo(gItemTable+0x10)($at)
/* 13C88C 8024954C 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13C890 80249550 AC2200C8 */  sw        $v0, %lo(gPauseMenuCurrentDescString)($at)
/* 13C894 80249554 08092566 */  j         .L80249598
/* 13C898 80249558 00000000 */   nop
.L8024955C:
/* 13C89C 8024955C 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13C8A0 80249560 AC2000C8 */  sw        $zero, %lo(gPauseMenuCurrentDescString)($at)
/* 13C8A4 80249564 08092564 */  j         .L80249590
/* 13C8A8 80249568 00000000 */   nop
.L8024956C:
/* 13C8AC 8024956C 3C028027 */  lui       $v0, %hi(gBadgeMenuCurrentTab)
/* 13C8B0 80249570 8C42039C */  lw        $v0, %lo(gBadgeMenuCurrentTab)($v0)
/* 13C8B4 80249574 14400002 */  bnez      $v0, .L80249580
/* 13C8B8 80249578 2404004D */   addiu    $a0, $zero, 0x4d
/* 13C8BC 8024957C 2404004C */  addiu     $a0, $zero, 0x4c
.L80249580:
/* 13C8C0 80249580 0C093BA0 */  jal       pause_get_menu_string
/* 13C8C4 80249584 00000000 */   nop
/* 13C8C8 80249588 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13C8CC 8024958C AC2200C8 */  sw        $v0, %lo(gPauseMenuCurrentDescString)($at)
.L80249590:
/* 13C8D0 80249590 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 13C8D4 80249594 AC2000CC */  sw        $zero, %lo(gPauseMenuCurrentDescIconScript)($at)
.L80249598:
/* 13C8D8 80249598 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 13C8DC 8024959C 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 13C8E0 802495A0 30424000 */  andi      $v0, $v0, 0x4000
/* 13C8E4 802495A4 10400017 */  beqz      $v0, .L80249604
/* 13C8E8 802495A8 00000000 */   nop
/* 13C8EC 802495AC 3C108027 */  lui       $s0, %hi(gBadgeMenuLevel)
/* 13C8F0 802495B0 26100398 */  addiu     $s0, $s0, %lo(gBadgeMenuLevel)
/* 13C8F4 802495B4 8E020000 */  lw        $v0, ($s0)
/* 13C8F8 802495B8 14400007 */  bnez      $v0, .L802495D8
/* 13C8FC 802495BC 00000000 */   nop
/* 13C900 802495C0 0C05272D */  jal       sfx_play_sound
/* 13C904 802495C4 240400CA */   addiu    $a0, $zero, 0xca
/* 13C908 802495C8 3C018027 */  lui       $at, %hi(gPauseMenuCurrentTab)
/* 13C90C 802495CC A02000D4 */  sb        $zero, %lo(gPauseMenuCurrentTab)($at)
/* 13C910 802495D0 08092581 */  j         .L80249604
/* 13C914 802495D4 00000000 */   nop
.L802495D8:
/* 13C918 802495D8 0C05272D */  jal       sfx_play_sound
/* 13C91C 802495DC 240400CA */   addiu    $a0, $zero, 0xca
/* 13C920 802495E0 0C039E1B */  jal       enforce_hpfp_limits
/* 13C924 802495E4 AE000000 */   sw       $zero, ($s0)
/* 13C928 802495E8 3C038027 */  lui       $v1, %hi(gBadgeMenuCurrentTab)
/* 13C92C 802495EC 8C63039C */  lw        $v1, %lo(gBadgeMenuCurrentTab)($v1)
/* 13C930 802495F0 24020001 */  addiu     $v0, $zero, 1
/* 13C934 802495F4 14620003 */  bne       $v1, $v0, .L80249604
/* 13C938 802495F8 00000000 */   nop
/* 13C93C 802495FC 0C092363 */  jal       pause_badges_load_badges
/* 13C940 80249600 0040202D */   daddu    $a0, $v0, $zero
.L80249604:
/* 13C944 80249604 8FBF001C */  lw        $ra, 0x1c($sp)
/* 13C948 80249608 8FB20018 */  lw        $s2, 0x18($sp)
/* 13C94C 8024960C 8FB10014 */  lw        $s1, 0x14($sp)
/* 13C950 80249610 8FB00010 */  lw        $s0, 0x10($sp)
/* 13C954 80249614 03E00008 */  jr        $ra
/* 13C958 80249618 27BD0020 */   addiu    $sp, $sp, 0x20
