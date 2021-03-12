.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BDE88_317DA8
.word 0x802BD8EC, 0x802BD90C, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD858, 0x802BD870, 0x802BD974, 0x802BD858, 0x802BD870, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD88C, 0x802BD8BC, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD974, 0x802BD92C, 0x802BD94C

.section .text

glabel func_802BD5D8_3174F8
/* 3174F8 802BD5D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3174FC 802BD5DC AFB10014 */  sw        $s1, 0x14($sp)
/* 317500 802BD5E0 0080882D */  daddu     $s1, $a0, $zero
/* 317504 802BD5E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 317508 802BD5E8 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 31750C 802BD5EC 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 317510 802BD5F0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 317514 802BD5F4 AFB40020 */  sw        $s4, 0x20($sp)
/* 317518 802BD5F8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31751C 802BD5FC AFB20018 */  sw        $s2, 0x18($sp)
/* 317520 802BD600 10A0001C */  beqz      $a1, .L802BD674
/* 317524 802BD604 8E32014C */   lw       $s2, 0x14c($s1)
/* 317528 802BD608 0C0AF559 */  jal       func_802BD564_317484
/* 31752C 802BD60C 0240202D */   daddu    $a0, $s2, $zero
/* 317530 802BD610 3C04802C */  lui       $a0, %hi(D_802BDF30)
/* 317534 802BD614 2484DF30 */  addiu     $a0, $a0, %lo(D_802BDF30)
/* 317538 802BD618 3C01802C */  lui       $at, %hi(func_802BDF64_3248B4)
/* 31753C 802BD61C AC20DF64 */  sw        $zero, %lo(func_802BDF64_3248B4)($at)
/* 317540 802BD620 AC800000 */  sw        $zero, ($a0)
/* 317544 802BD624 8E020004 */  lw        $v0, 4($s0)
/* 317548 802BD628 3C05802C */  lui       $a1, %hi(D_802BDF34)
/* 31754C 802BD62C 24A5DF34 */  addiu     $a1, $a1, %lo(D_802BDF34)
/* 317550 802BD630 30420020 */  andi      $v0, $v0, 0x20
/* 317554 802BD634 10400008 */  beqz      $v0, .L802BD658
/* 317558 802BD638 ACA00000 */   sw       $zero, ($a1)
/* 31755C 802BD63C 3C02802B */  lui       $v0, %hi(D_802B79A8_E21858)
/* 317560 802BD640 8C4279A8 */  lw        $v0, %lo(D_802B79A8_E21858)($v0)
/* 317564 802BD644 8C430000 */  lw        $v1, ($v0)
/* 317568 802BD648 24020001 */  addiu     $v0, $zero, 1
/* 31756C 802BD64C AC820000 */  sw        $v0, ($a0)
/* 317570 802BD650 3C01802C */  lui       $at, %hi(D_802BDF38)
/* 317574 802BD654 AC23DF38 */  sw        $v1, %lo(D_802BDF38)($at)
.L802BD658:
/* 317578 802BD658 8E020004 */  lw        $v0, 4($s0)
/* 31757C 802BD65C 30420010 */  andi      $v0, $v0, 0x10
/* 317580 802BD660 10400002 */  beqz      $v0, .L802BD66C
/* 317584 802BD664 24020001 */   addiu    $v0, $zero, 1
/* 317588 802BD668 ACA20000 */  sw        $v0, ($a1)
.L802BD66C:
/* 31758C 802BD66C 24020028 */  addiu     $v0, $zero, 0x28
/* 317590 802BD670 AE220070 */  sw        $v0, 0x70($s1)
.L802BD674:
/* 317594 802BD674 8E230070 */  lw        $v1, 0x70($s1)
/* 317598 802BD678 24130001 */  addiu     $s3, $zero, 1
/* 31759C 802BD67C 10730053 */  beq       $v1, $s3, .L802BD7CC
/* 3175A0 802BD680 28620002 */   slti     $v0, $v1, 2
/* 3175A4 802BD684 10400005 */  beqz      $v0, .L802BD69C
/* 3175A8 802BD688 24020028 */   addiu    $v0, $zero, 0x28
/* 3175AC 802BD68C 10600030 */  beqz      $v1, .L802BD750
/* 3175B0 802BD690 2402000A */   addiu    $v0, $zero, 0xa
/* 3175B4 802BD694 080AF6A3 */  j         .L802BDA8C
/* 3175B8 802BD698 00000000 */   nop
.L802BD69C:
/* 3175BC 802BD69C 10620005 */  beq       $v1, $v0, .L802BD6B4
/* 3175C0 802BD6A0 24020029 */   addiu    $v0, $zero, 0x29
/* 3175C4 802BD6A4 10620018 */  beq       $v1, $v0, .L802BD708
/* 3175C8 802BD6A8 00000000 */   nop
/* 3175CC 802BD6AC 080AF6A1 */  j         .L802BDA84
/* 3175D0 802BD6B0 00000000 */   nop
.L802BD6B4:
/* 3175D4 802BD6B4 8E420000 */  lw        $v0, ($s2)
/* 3175D8 802BD6B8 30421000 */  andi      $v0, $v0, 0x1000
/* 3175DC 802BD6BC 10400004 */  beqz      $v0, .L802BD6D0
/* 3175E0 802BD6C0 2402FFFF */   addiu    $v0, $zero, -1
/* 3175E4 802BD6C4 82020015 */  lb        $v0, 0x15($s0)
/* 3175E8 802BD6C8 10400004 */  beqz      $v0, .L802BD6DC
/* 3175EC 802BD6CC 2402FFFF */   addiu    $v0, $zero, -1
.L802BD6D0:
/* 3175F0 802BD6D0 AE220084 */  sw        $v0, 0x84($s1)
.L802BD6D4:
/* 3175F4 802BD6D4 080AF6C4 */  j         .L802BDB10
/* 3175F8 802BD6D8 24020002 */   addiu    $v0, $zero, 2
.L802BD6DC:
/* 3175FC 802BD6DC 24020003 */  addiu     $v0, $zero, 3
/* 317600 802BD6E0 0C03805E */  jal       disable_player_input
/* 317604 802BD6E4 AE220074 */   sw       $v0, 0x74($s1)
/* 317608 802BD6E8 82030015 */  lb        $v1, 0x15($s0)
/* 31760C 802BD6EC 8E220070 */  lw        $v0, 0x70($s1)
/* 317610 802BD6F0 3C01802C */  lui       $at, %hi(func_802BDF64_3248B4)
/* 317614 802BD6F4 AC33DF64 */  sw        $s3, %lo(func_802BDF64_3248B4)($at)
/* 317618 802BD6F8 24420001 */  addiu     $v0, $v0, 1
/* 31761C 802BD6FC AE230078 */  sw        $v1, 0x78($s1)
/* 317620 802BD700 080AF6A1 */  j         .L802BDA84
/* 317624 802BD704 AE220070 */   sw       $v0, 0x70($s1)
.L802BD708:
/* 317628 802BD708 8E220074 */  lw        $v0, 0x74($s1)
/* 31762C 802BD70C 10400003 */  beqz      $v0, .L802BD71C
/* 317630 802BD710 2442FFFF */   addiu    $v0, $v0, -1
/* 317634 802BD714 080AF6A1 */  j         .L802BDA84
/* 317638 802BD718 AE220074 */   sw       $v0, 0x74($s1)
.L802BD71C:
/* 31763C 802BD71C 82030015 */  lb        $v1, 0x15($s0)
/* 317640 802BD720 8E220078 */  lw        $v0, 0x78($s1)
/* 317644 802BD724 0043102A */  slt       $v0, $v0, $v1
/* 317648 802BD728 10400007 */  beqz      $v0, .L802BD748
/* 31764C 802BD72C 2402FFFF */   addiu    $v0, $zero, -1
/* 317650 802BD730 0C038069 */  jal       enable_player_input
/* 317654 802BD734 AE220084 */   sw       $v0, 0x84($s1)
/* 317658 802BD738 3C01802C */  lui       $at, %hi(func_802BDF64_3248B4)
/* 31765C 802BD73C AC20DF64 */  sw        $zero, %lo(func_802BDF64_3248B4)($at)
/* 317660 802BD740 080AF6C4 */  j         .L802BDB10
/* 317664 802BD744 24020002 */   addiu    $v0, $zero, 2
.L802BD748:
/* 317668 802BD748 080AF6A1 */  j         .L802BDA84
/* 31766C 802BD74C AE200070 */   sw       $zero, 0x70($s1)
.L802BD750:
/* 317670 802BD750 0C009C22 */  jal       func_80027088
/* 317674 802BD754 24040001 */   addiu    $a0, $zero, 1
/* 317678 802BD758 3C03FDFF */  lui       $v1, 0xfdff
/* 31767C 802BD75C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 317680 802BD760 3C040001 */  lui       $a0, 1
/* 317684 802BD764 8E020000 */  lw        $v0, ($s0)
/* 317688 802BD768 34840001 */  ori       $a0, $a0, 1
/* 31768C 802BD76C 00431024 */  and       $v0, $v0, $v1
/* 317690 802BD770 AE020000 */  sw        $v0, ($s0)
/* 317694 802BD774 AE440028 */  sw        $a0, 0x28($s2)
/* 317698 802BD778 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 31769C 802BD77C C42C1DEC */  lwc1      $f12, %lo(gCameras+0x6C)($at)
/* 3176A0 802BD780 C60000A8 */  lwc1      $f0, 0xa8($s0)
/* 3176A4 802BD784 46006300 */  add.s     $f12, $f12, $f0
/* 3176A8 802BD788 3C0142B4 */  lui       $at, 0x42b4
/* 3176AC 802BD78C 44810000 */  mtc1      $at, $f0
/* 3176B0 802BD790 0C00A6C9 */  jal       clamp_angle
/* 3176B4 802BD794 46006301 */   sub.s    $f12, $f12, $f0
/* 3176B8 802BD798 E640000C */  swc1      $f0, 0xc($s2)
/* 3176BC 802BD79C 3C018011 */  lui       $at, %hi(D_8010EBB0)
/* 3176C0 802BD7A0 A033EBB0 */  sb        $s3, %lo(D_8010EBB0)($at)
/* 3176C4 802BD7A4 0C03A5EE */  jal       close_status_menu
/* 3176C8 802BD7A8 00000000 */   nop
/* 3176CC 802BD7AC 3C02802C */  lui       $v0, %hi(D_802BDF30)
/* 3176D0 802BD7B0 8C42DF30 */  lw        $v0, %lo(D_802BDF30)($v0)
/* 3176D4 802BD7B4 10400004 */  beqz      $v0, .L802BD7C8
/* 3176D8 802BD7B8 24020014 */   addiu    $v0, $zero, 0x14
/* 3176DC 802BD7BC AE200084 */  sw        $zero, 0x84($s1)
/* 3176E0 802BD7C0 080AF6A1 */  j         .L802BDA84
/* 3176E4 802BD7C4 AE220070 */   sw       $v0, 0x70($s1)
.L802BD7C8:
/* 3176E8 802BD7C8 AE330070 */  sw        $s3, 0x70($s1)
.L802BD7CC:
/* 3176EC 802BD7CC 3C04802C */  lui       $a0, %hi(D_802BDF60)
/* 3176F0 802BD7D0 8C84DF60 */  lw        $a0, %lo(D_802BDF60)($a0)
/* 3176F4 802BD7D4 0480008A */  bltz      $a0, .L802BDA00
/* 3176F8 802BD7D8 30824000 */   andi     $v0, $a0, 0x4000
/* 3176FC 802BD7DC 10400070 */  beqz      $v0, .L802BD9A0
/* 317700 802BD7E0 00000000 */   nop
/* 317704 802BD7E4 0C0441A9 */  jal       get_entity_type
/* 317708 802BD7E8 2410FFFF */   addiu    $s0, $zero, -1
/* 31770C 802BD7EC 0040282D */  daddu     $a1, $v0, $zero
/* 317710 802BD7F0 3C03802C */  lui       $v1, %hi(D_802BDC40_317B60)
/* 317714 802BD7F4 2463DC40 */  addiu     $v1, $v1, %lo(D_802BDC40_317B60)
/* 317718 802BD7F8 8C620000 */  lw        $v0, ($v1)
/* 31771C 802BD7FC 10500066 */  beq       $v0, $s0, .L802BD998
/* 317720 802BD800 24A4FFF7 */   addiu    $a0, $a1, -9
/* 317724 802BD804 0060A02D */  daddu     $s4, $v1, $zero
/* 317728 802BD808 3C03802C */  lui       $v1, %hi(D_802BDE88_317DA8)
/* 31772C 802BD80C 2463DE88 */  addiu     $v1, $v1, %lo(D_802BDE88_317DA8)
/* 317730 802BD810 00041080 */  sll       $v0, $a0, 2
/* 317734 802BD814 00434821 */  addu      $t1, $v0, $v1
/* 317738 802BD818 3C068011 */  lui       $a2, %hi(gPlayerData)
/* 31773C 802BD81C 24C6F290 */  addiu     $a2, $a2, %lo(gPlayerData)
/* 317740 802BD820 24070001 */  addiu     $a3, $zero, 1
/* 317744 802BD824 24080002 */  addiu     $t0, $zero, 2
/* 317748 802BD828 0200982D */  daddu     $s3, $s0, $zero
/* 31774C 802BD82C 0280182D */  daddu     $v1, $s4, $zero
/* 317750 802BD830 24120004 */  addiu     $s2, $zero, 4
/* 317754 802BD834 8C620000 */  lw        $v0, ($v1)
.L802BD838:
/* 317758 802BD838 54450054 */  bnel      $v0, $a1, .L802BD98C
/* 31775C 802BD83C 24630008 */   addiu    $v1, $v1, 8
/* 317760 802BD840 2C82002A */  sltiu     $v0, $a0, 0x2a
/* 317764 802BD844 1040004B */  beqz      $v0, .L802BD974
/* 317768 802BD848 00000000 */   nop
/* 31776C 802BD84C 8D220000 */  lw        $v0, ($t1)
/* 317770 802BD850 00400008 */  jr        $v0
/* 317774 802BD854 00000000 */   nop
/* 317778 802BD858 80C20001 */  lb        $v0, 1($a2)
/* 31777C 802BD85C 18400045 */  blez      $v0, .L802BD974
/* 317780 802BD860 00000000 */   nop
/* 317784 802BD864 3C10001B */  lui       $s0, 0x1b
/* 317788 802BD868 080AF65D */  j         .L802BD974
/* 31778C 802BD86C 36100002 */   ori      $s0, $s0, 2
/* 317790 802BD870 80C20001 */  lb        $v0, 1($a2)
/* 317794 802BD874 28420002 */  slti      $v0, $v0, 2
/* 317798 802BD878 1440003E */  bnez      $v0, .L802BD974
/* 31779C 802BD87C 00000000 */   nop
/* 3177A0 802BD880 3C10001B */  lui       $s0, 0x1b
/* 3177A4 802BD884 080AF65D */  j         .L802BD974
/* 3177A8 802BD888 36100004 */   ori      $s0, $s0, 4
/* 3177AC 802BD88C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 3177B0 802BD890 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 3177B4 802BD894 14470004 */  bne       $v0, $a3, .L802BD8A8
/* 3177B8 802BD898 00000000 */   nop
/* 3177BC 802BD89C 3C10001B */  lui       $s0, 0x1b
/* 3177C0 802BD8A0 080AF65D */  j         .L802BD974
/* 3177C4 802BD8A4 36100018 */   ori      $s0, $s0, 0x18
.L802BD8A8:
/* 3177C8 802BD8A8 14480032 */  bne       $v0, $t0, .L802BD974
/* 3177CC 802BD8AC 00000000 */   nop
/* 3177D0 802BD8B0 3C10001B */  lui       $s0, 0x1b
/* 3177D4 802BD8B4 080AF65D */  j         .L802BD974
/* 3177D8 802BD8B8 36100019 */   ori      $s0, $s0, 0x19
/* 3177DC 802BD8BC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 3177E0 802BD8C0 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 3177E4 802BD8C4 14470004 */  bne       $v0, $a3, .L802BD8D8
/* 3177E8 802BD8C8 00000000 */   nop
/* 3177EC 802BD8CC 3C10001B */  lui       $s0, 0x1b
/* 3177F0 802BD8D0 080AF65D */  j         .L802BD974
/* 3177F4 802BD8D4 3610001B */   ori      $s0, $s0, 0x1b
.L802BD8D8:
/* 3177F8 802BD8D8 14480026 */  bne       $v0, $t0, .L802BD974
/* 3177FC 802BD8DC 00000000 */   nop
/* 317800 802BD8E0 3C10001B */  lui       $s0, 0x1b
/* 317804 802BD8E4 080AF65D */  j         .L802BD974
/* 317808 802BD8E8 3610001C */   ori      $s0, $s0, 0x1c
/* 31780C 802BD8EC 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 317810 802BD8F0 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 317814 802BD8F4 28420002 */  slti      $v0, $v0, 2
/* 317818 802BD8F8 1440001E */  bnez      $v0, .L802BD974
/* 31781C 802BD8FC 00000000 */   nop
/* 317820 802BD900 3C10001B */  lui       $s0, 0x1b
/* 317824 802BD904 080AF65D */  j         .L802BD974
/* 317828 802BD908 3610000D */   ori      $s0, $s0, 0xd
/* 31782C 802BD90C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 317830 802BD910 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 317834 802BD914 28420002 */  slti      $v0, $v0, 2
/* 317838 802BD918 14400016 */  bnez      $v0, .L802BD974
/* 31783C 802BD91C 00000000 */   nop
/* 317840 802BD920 3C10001B */  lui       $s0, 0x1b
/* 317844 802BD924 080AF65D */  j         .L802BD974
/* 317848 802BD928 3610000F */   ori      $s0, $s0, 0xf
/* 31784C 802BD92C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 317850 802BD930 8042F290 */  lb        $v0, %lo(gPlayerData)($v0)
/* 317854 802BD934 28420002 */  slti      $v0, $v0, 2
/* 317858 802BD938 1440000E */  bnez      $v0, .L802BD974
/* 31785C 802BD93C 00000000 */   nop
/* 317860 802BD940 3C10001B */  lui       $s0, 0x1b
/* 317864 802BD944 080AF65D */  j         .L802BD974
/* 317868 802BD948 3610001E */   ori      $s0, $s0, 0x1e
/* 31786C 802BD94C 3C04802C */  lui       $a0, %hi(D_802BDF60)
/* 317870 802BD950 8C84DF60 */  lw        $a0, %lo(D_802BDF60)($a0)
/* 317874 802BD954 0C04417A */  jal       get_entity_by_index
/* 317878 802BD958 30843FFF */   andi     $a0, $a0, 0x3fff
/* 31787C 802BD95C 8C420040 */  lw        $v0, 0x40($v0)
/* 317880 802BD960 8C420010 */  lw        $v0, 0x10($v0)
/* 317884 802BD964 14530003 */  bne       $v0, $s3, .L802BD974
/* 317888 802BD968 00000000 */   nop
/* 31788C 802BD96C 3C10001B */  lui       $s0, 0x1b
/* 317890 802BD970 36100016 */  ori       $s0, $s0, 0x16
.L802BD974:
/* 317894 802BD974 56130058 */  bnel      $s0, $s3, .L802BDAD8
/* 317898 802BD978 AE300084 */   sw       $s0, 0x84($s1)
/* 31789C 802BD97C 02541021 */  addu      $v0, $s2, $s4
/* 3178A0 802BD980 8C420000 */  lw        $v0, ($v0)
/* 3178A4 802BD984 080AF6B6 */  j         .L802BDAD8
/* 3178A8 802BD988 AE220084 */   sw       $v0, 0x84($s1)
.L802BD98C:
/* 3178AC 802BD98C 8C620000 */  lw        $v0, ($v1)
/* 3178B0 802BD990 1453FFA9 */  bne       $v0, $s3, .L802BD838
/* 3178B4 802BD994 26520008 */   addiu    $s2, $s2, 8
.L802BD998:
/* 3178B8 802BD998 3C04802C */  lui       $a0, %hi(D_802BDF60)
/* 3178BC 802BD99C 8C84DF60 */  lw        $a0, %lo(D_802BDF60)($a0)
.L802BD9A0:
/* 3178C0 802BD9A0 04800017 */  bltz      $a0, .L802BDA00
/* 3178C4 802BD9A4 30822000 */   andi     $v0, $a0, 0x2000
/* 3178C8 802BD9A8 10400015 */  beqz      $v0, .L802BDA00
/* 3178CC 802BD9AC 00000000 */   nop
/* 3178D0 802BD9B0 0C00EABB */  jal       get_npc_unsafe
/* 3178D4 802BD9B4 30841FFF */   andi     $a0, $a0, 0x1fff
/* 3178D8 802BD9B8 3C01802C */  lui       $at, %hi(D_802BDF38)
/* 3178DC 802BD9BC AC22DF38 */  sw        $v0, %lo(D_802BDF38)($at)
/* 3178E0 802BD9C0 0C00FB3A */  jal       get_enemy
/* 3178E4 802BD9C4 804400A4 */   lb       $a0, 0xa4($v0)
/* 3178E8 802BD9C8 8C4200D8 */  lw        $v0, 0xd8($v0)
/* 3178EC 802BD9CC 1040FF41 */  beqz      $v0, .L802BD6D4
/* 3178F0 802BD9D0 0040802D */   daddu    $s0, $v0, $zero
/* 3178F4 802BD9D4 3C02EFE8 */  lui       $v0, 0xefe8
/* 3178F8 802BD9D8 34422080 */  ori       $v0, $v0, 0x2080
/* 3178FC 802BD9DC 0202102A */  slt       $v0, $s0, $v0
/* 317900 802BD9E0 50400005 */  beql      $v0, $zero, .L802BD9F8
/* 317904 802BD9E4 AE300084 */   sw       $s0, 0x84($s1)
/* 317908 802BD9E8 0200F809 */  jalr      $s0
/* 31790C 802BD9EC 00000000 */   nop
/* 317910 802BD9F0 080AF5B5 */  j         .L802BD6D4
/* 317914 802BD9F4 AE220084 */   sw       $v0, 0x84($s1)
.L802BD9F8:
/* 317918 802BD9F8 080AF5B5 */  j         .L802BD6D4
/* 31791C 802BD9FC AE200088 */   sw       $zero, 0x88($s1)
.L802BDA00:
/* 317920 802BDA00 3C02802C */  lui       $v0, %hi(D_802BDF34)
/* 317924 802BDA04 8C42DF34 */  lw        $v0, %lo(D_802BDF34)($v0)
/* 317928 802BDA08 10400003 */  beqz      $v0, .L802BDA18
/* 31792C 802BDA0C 3C03001B */   lui      $v1, 0x1b
/* 317930 802BDA10 080AF6BF */  j         .L802BDAFC
/* 317934 802BDA14 34630025 */   ori      $v1, $v1, 0x25
.L802BDA18:
/* 317938 802BDA18 3C04802C */  lui       $a0, %hi(D_802BDF60)
/* 31793C 802BDA1C 8C84DF60 */  lw        $a0, %lo(D_802BDF60)($a0)
/* 317940 802BDA20 04800004 */  bltz      $a0, .L802BDA34
/* 317944 802BDA24 0000282D */   daddu    $a1, $zero, $zero
/* 317948 802BDA28 0C0AF440 */  jal       func_802BD100_317020
/* 31794C 802BDA2C 00000000 */   nop
/* 317950 802BDA30 0040282D */  daddu     $a1, $v0, $zero
.L802BDA34:
/* 317954 802BDA34 14A00010 */  bnez      $a1, .L802BDA78
/* 317958 802BDA38 24020001 */   addiu    $v0, $zero, 1
/* 31795C 802BDA3C 0C016AFA */  jal       get_current_map_header
/* 317960 802BDA40 00000000 */   nop
/* 317964 802BDA44 8C50003C */  lw        $s0, 0x3c($v0)
/* 317968 802BDA48 1200FF22 */  beqz      $s0, .L802BD6D4
/* 31796C 802BDA4C 3C02EFE8 */   lui      $v0, 0xefe8
/* 317970 802BDA50 34422080 */  ori       $v0, $v0, 0x2080
/* 317974 802BDA54 0202102A */  slt       $v0, $s0, $v0
/* 317978 802BDA58 50400005 */  beql      $v0, $zero, .L802BDA70
/* 31797C 802BDA5C AE300084 */   sw       $s0, 0x84($s1)
/* 317980 802BDA60 0200F809 */  jalr      $s0
/* 317984 802BDA64 00000000 */   nop
/* 317988 802BDA68 080AF5B5 */  j         .L802BD6D4
/* 31798C 802BDA6C AE220084 */   sw       $v0, 0x84($s1)
.L802BDA70:
/* 317990 802BDA70 080AF5B5 */  j         .L802BD6D4
/* 317994 802BDA74 AE200088 */   sw       $zero, 0x88($s1)
.L802BDA78:
/* 317998 802BDA78 AE250084 */  sw        $a1, 0x84($s1)
/* 31799C 802BDA7C 080AF5B5 */  j         .L802BD6D4
/* 3179A0 802BDA80 AE220088 */   sw       $v0, 0x88($s1)
.L802BDA84:
/* 3179A4 802BDA84 8E230070 */  lw        $v1, 0x70($s1)
/* 3179A8 802BDA88 2402000A */  addiu     $v0, $zero, 0xa
.L802BDA8C:
/* 3179AC 802BDA8C 10620005 */  beq       $v1, $v0, .L802BDAA4
/* 3179B0 802BDA90 24020014 */   addiu    $v0, $zero, 0x14
/* 3179B4 802BDA94 10620012 */  beq       $v1, $v0, .L802BDAE0
/* 3179B8 802BDA98 0000102D */   daddu    $v0, $zero, $zero
/* 3179BC 802BDA9C 080AF6C4 */  j         .L802BDB10
/* 3179C0 802BDAA0 00000000 */   nop
.L802BDAA4:
/* 3179C4 802BDAA4 0C016AFA */  jal       get_current_map_header
/* 3179C8 802BDAA8 00000000 */   nop
/* 3179CC 802BDAAC 8C50003C */  lw        $s0, 0x3c($v0)
/* 3179D0 802BDAB0 12000016 */  beqz      $s0, .L802BDB0C
/* 3179D4 802BDAB4 3C02EFE8 */   lui      $v0, 0xefe8
/* 3179D8 802BDAB8 34422080 */  ori       $v0, $v0, 0x2080
/* 3179DC 802BDABC 0202102A */  slt       $v0, $s0, $v0
/* 3179E0 802BDAC0 50400005 */  beql      $v0, $zero, .L802BDAD8
/* 3179E4 802BDAC4 AE300084 */   sw       $s0, 0x84($s1)
/* 3179E8 802BDAC8 0200F809 */  jalr      $s0
/* 3179EC 802BDACC 00000000 */   nop
/* 3179F0 802BDAD0 080AF5B5 */  j         .L802BD6D4
/* 3179F4 802BDAD4 AE220084 */   sw       $v0, 0x84($s1)
.L802BDAD8:
/* 3179F8 802BDAD8 080AF5B5 */  j         .L802BD6D4
/* 3179FC 802BDADC AE200088 */   sw       $zero, 0x88($s1)
.L802BDAE0:
/* 317A00 802BDAE0 3C02802C */  lui       $v0, %hi(D_802BDF38)
/* 317A04 802BDAE4 8C42DF38 */  lw        $v0, %lo(D_802BDF38)($v0)
/* 317A08 802BDAE8 0C00FB3A */  jal       get_enemy
/* 317A0C 802BDAEC 804400A4 */   lb       $a0, 0xa4($v0)
/* 317A10 802BDAF0 8C4300D8 */  lw        $v1, 0xd8($v0)
/* 317A14 802BDAF4 10600006 */  beqz      $v1, .L802BDB10
/* 317A18 802BDAF8 0000102D */   daddu    $v0, $zero, $zero
.L802BDAFC:
/* 317A1C 802BDAFC 24020002 */  addiu     $v0, $zero, 2
/* 317A20 802BDB00 AE230084 */  sw        $v1, 0x84($s1)
/* 317A24 802BDB04 080AF6C4 */  j         .L802BDB10
/* 317A28 802BDB08 AE200088 */   sw       $zero, 0x88($s1)
.L802BDB0C:
/* 317A2C 802BDB0C 0000102D */  daddu     $v0, $zero, $zero
.L802BDB10:
/* 317A30 802BDB10 8FBF0024 */  lw        $ra, 0x24($sp)
/* 317A34 802BDB14 8FB40020 */  lw        $s4, 0x20($sp)
/* 317A38 802BDB18 8FB3001C */  lw        $s3, 0x1c($sp)
/* 317A3C 802BDB1C 8FB20018 */  lw        $s2, 0x18($sp)
/* 317A40 802BDB20 8FB10014 */  lw        $s1, 0x14($sp)
/* 317A44 802BDB24 8FB00010 */  lw        $s0, 0x10($sp)
/* 317A48 802BDB28 03E00008 */  jr        $ra
/* 317A4C 802BDB2C 27BD0028 */   addiu    $sp, $sp, 0x28
