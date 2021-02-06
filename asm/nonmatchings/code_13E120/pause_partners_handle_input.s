.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_partners_handle_input
/* 13F678 8024C338 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 13F67C 8024C33C AFB10014 */  sw        $s1, 0x14($sp)
/* 13F680 8024C340 3C118027 */  lui       $s1, %hi(D_802706B0)
/* 13F684 8024C344 263106B0 */  addiu     $s1, $s1, %lo(D_802706B0)
/* 13F688 8024C348 AFBF0018 */  sw        $ra, 0x18($sp)
/* 13F68C 8024C34C AFB00010 */  sw        $s0, 0x10($sp)
/* 13F690 8024C350 8E220000 */  lw        $v0, ($s1)
/* 13F694 8024C354 28420002 */  slti      $v0, $v0, 2
/* 13F698 8024C358 14400047 */  bnez      $v0, .L8024C478
/* 13F69C 8024C35C 00000000 */   nop
/* 13F6A0 8024C360 3C028027 */  lui       $v0, %hi(D_802706AC)
/* 13F6A4 8024C364 8C4206AC */  lw        $v0, %lo(D_802706AC)($v0)
/* 13F6A8 8024C368 10400006 */  beqz      $v0, .L8024C384
/* 13F6AC 8024C36C 00000000 */   nop
/* 13F6B0 8024C370 3C028027 */  lui       $v0, %hi(gPauseMenuHeldButtons)
/* 13F6B4 8024C374 8C4200C0 */  lw        $v0, %lo(gPauseMenuHeldButtons)($v0)
/* 13F6B8 8024C378 30422010 */  andi      $v0, $v0, 0x2010
/* 13F6BC 8024C37C 1040003E */  beqz      $v0, .L8024C478
/* 13F6C0 8024C380 00000000 */   nop
.L8024C384:
/* 13F6C4 8024C384 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13F6C8 8024C388 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13F6CC 8024C38C 3C020004 */  lui       $v0, 4
/* 13F6D0 8024C390 00621024 */  and       $v0, $v1, $v0
/* 13F6D4 8024C394 10400002 */  beqz      $v0, .L8024C3A0
/* 13F6D8 8024C398 0000802D */   daddu    $s0, $zero, $zero
/* 13F6DC 8024C39C 2410FFFF */  addiu     $s0, $zero, -1
.L8024C3A0:
/* 13F6E0 8024C3A0 3C020008 */  lui       $v0, 8
/* 13F6E4 8024C3A4 00621024 */  and       $v0, $v1, $v0
/* 13F6E8 8024C3A8 54400001 */  bnel      $v0, $zero, .L8024C3B0
/* 13F6EC 8024C3AC 26100001 */   addiu    $s0, $s0, 1
.L8024C3B0:
/* 13F6F0 8024C3B0 30622000 */  andi      $v0, $v1, 0x2000
/* 13F6F4 8024C3B4 54400001 */  bnel      $v0, $zero, .L8024C3BC
/* 13F6F8 8024C3B8 2610FFFF */   addiu    $s0, $s0, -1
.L8024C3BC:
/* 13F6FC 8024C3BC 30620010 */  andi      $v0, $v1, 0x10
/* 13F700 8024C3C0 54400001 */  bnel      $v0, $zero, .L8024C3C8
/* 13F704 8024C3C4 26100001 */   addiu    $s0, $s0, 1
.L8024C3C8:
/* 13F708 8024C3C8 1200002B */  beqz      $s0, .L8024C478
/* 13F70C 8024C3CC 00000000 */   nop
/* 13F710 8024C3D0 0C05272D */  jal       play_sound
/* 13F714 8024C3D4 240400C7 */   addiu    $a0, $zero, 0xc7
/* 13F718 8024C3D8 3C048027 */  lui       $a0, %hi(D_802706A0)
/* 13F71C 8024C3DC 248406A0 */  addiu     $a0, $a0, %lo(D_802706A0)
/* 13F720 8024C3E0 8C820000 */  lw        $v0, ($a0)
/* 13F724 8024C3E4 00501821 */  addu      $v1, $v0, $s0
/* 13F728 8024C3E8 0461000F */  bgez      $v1, .L8024C428
/* 13F72C 8024C3EC AC830000 */   sw       $v1, ($a0)
/* 13F730 8024C3F0 3C038027 */  lui       $v1, %hi(D_802706A8)
/* 13F734 8024C3F4 246306A8 */  addiu     $v1, $v1, %lo(D_802706A8)
/* 13F738 8024C3F8 C4600000 */  lwc1      $f0, ($v1)
/* 13F73C 8024C3FC 8E220000 */  lw        $v0, ($s1)
/* 13F740 8024C400 3C0143B4 */  lui       $at, 0x43b4
/* 13F744 8024C404 44811000 */  mtc1      $at, $f2
/* 13F748 8024C408 2442FFFF */  addiu     $v0, $v0, -1
/* 13F74C 8024C40C 4602003C */  c.lt.s    $f0, $f2
/* 13F750 8024C410 00000000 */  nop
/* 13F754 8024C414 45000016 */  bc1f      .L8024C470
/* 13F758 8024C418 AC820000 */   sw       $v0, ($a0)
/* 13F75C 8024C41C 46020000 */  add.s     $f0, $f0, $f2
/* 13F760 8024C420 0809311C */  j         .L8024C470
/* 13F764 8024C424 E4600000 */   swc1     $f0, ($v1)
.L8024C428:
/* 13F768 8024C428 8E220000 */  lw        $v0, ($s1)
/* 13F76C 8024C42C 0062102A */  slt       $v0, $v1, $v0
/* 13F770 8024C430 1440000F */  bnez      $v0, .L8024C470
/* 13F774 8024C434 00000000 */   nop
/* 13F778 8024C438 3C028027 */  lui       $v0, %hi(D_802706A8)
/* 13F77C 8024C43C 244206A8 */  addiu     $v0, $v0, %lo(D_802706A8)
/* 13F780 8024C440 C4420000 */  lwc1      $f2, ($v0)
/* 13F784 8024C444 44800000 */  mtc1      $zero, $f0
/* 13F788 8024C448 00000000 */  nop
/* 13F78C 8024C44C 4602003C */  c.lt.s    $f0, $f2
/* 13F790 8024C450 00000000 */  nop
/* 13F794 8024C454 45000006 */  bc1f      .L8024C470
/* 13F798 8024C458 AC800000 */   sw       $zero, ($a0)
/* 13F79C 8024C45C 3C0143B4 */  lui       $at, 0x43b4
/* 13F7A0 8024C460 44810000 */  mtc1      $at, $f0
/* 13F7A4 8024C464 00000000 */  nop
/* 13F7A8 8024C468 46001001 */  sub.s     $f0, $f2, $f0
/* 13F7AC 8024C46C E4400000 */  swc1      $f0, ($v0)
.L8024C470:
/* 13F7B0 8024C470 3C018027 */  lui       $at, %hi(D_802706A4)
/* 13F7B4 8024C474 AC2006A4 */  sw        $zero, %lo(D_802706A4)($at)
.L8024C478:
/* 13F7B8 8024C478 0C039D59 */  jal       get_player_data
/* 13F7BC 8024C47C 00000000 */   nop
/* 13F7C0 8024C480 3C038027 */  lui       $v1, %hi(D_802706A0)
/* 13F7C4 8024C484 8C6306A0 */  lw        $v1, %lo(D_802706A0)($v1)
/* 13F7C8 8024C488 00031880 */  sll       $v1, $v1, 2
/* 13F7CC 8024C48C 3C018027 */  lui       $at, %hi(D_80270680)
/* 13F7D0 8024C490 00230821 */  addu      $at, $at, $v1
/* 13F7D4 8024C494 8C230680 */  lw        $v1, %lo(D_80270680)($at)
/* 13F7D8 8024C498 00031880 */  sll       $v1, $v1, 2
/* 13F7DC 8024C49C 3C018025 */  lui       $at, %hi(D_8024F6B0)
/* 13F7E0 8024C4A0 00230821 */  addu      $at, $at, $v1
/* 13F7E4 8024C4A4 8C23F6B0 */  lw        $v1, %lo(D_8024F6B0)($at)
/* 13F7E8 8024C4A8 000318C0 */  sll       $v1, $v1, 3
/* 13F7EC 8024C4AC 00431021 */  addu      $v0, $v0, $v1
/* 13F7F0 8024C4B0 80430015 */  lb        $v1, 0x15($v0)
/* 13F7F4 8024C4B4 24020002 */  addiu     $v0, $zero, 2
/* 13F7F8 8024C4B8 14620003 */  bne       $v1, $v0, .L8024C4C8
/* 13F7FC 8024C4BC 24020001 */   addiu    $v0, $zero, 1
/* 13F800 8024C4C0 08093138 */  j         .L8024C4E0
/* 13F804 8024C4C4 24030004 */   addiu    $v1, $zero, 4
.L8024C4C8:
/* 13F808 8024C4C8 14620003 */  bne       $v1, $v0, .L8024C4D8
/* 13F80C 8024C4CC 00000000 */   nop
/* 13F810 8024C4D0 08093138 */  j         .L8024C4E0
/* 13F814 8024C4D4 24030003 */   addiu    $v1, $zero, 3
.L8024C4D8:
/* 13F818 8024C4D8 50600001 */  beql      $v1, $zero, .L8024C4E0
/* 13F81C 8024C4DC 24030002 */   addiu    $v1, $zero, 2
.L8024C4E0:
/* 13F820 8024C4E0 00031040 */  sll       $v0, $v1, 1
/* 13F824 8024C4E4 00431021 */  addu      $v0, $v0, $v1
/* 13F828 8024C4E8 00021080 */  sll       $v0, $v0, 2
/* 13F82C 8024C4EC 00431021 */  addu      $v0, $v0, $v1
/* 13F830 8024C4F0 3C108027 */  lui       $s0, %hi(D_802706AC)
/* 13F834 8024C4F4 8E1006AC */  lw        $s0, %lo(D_802706AC)($s0)
/* 13F838 8024C4F8 2442001E */  addiu     $v0, $v0, 0x1e
/* 13F83C 8024C4FC 3C018016 */  lui       $at, %hi(D_8015A1E2)
/* 13F840 8024C500 A422A1E2 */  sh        $v0, %lo(D_8015A1E2)($at)
/* 13F844 8024C504 24020001 */  addiu     $v0, $zero, 1
/* 13F848 8024C508 16020043 */  bne       $s0, $v0, .L8024C618
/* 13F84C 8024C50C 00000000 */   nop
/* 13F850 8024C510 3C118027 */  lui       $s1, %hi(D_802706A4)
/* 13F854 8024C514 8E3106A4 */  lw        $s1, %lo(D_802706A4)($s1)
/* 13F858 8024C518 0C039D59 */  jal       get_player_data
/* 13F85C 8024C51C 00000000 */   nop
/* 13F860 8024C520 3C038027 */  lui       $v1, %hi(D_802706A0)
/* 13F864 8024C524 8C6306A0 */  lw        $v1, %lo(D_802706A0)($v1)
/* 13F868 8024C528 00031880 */  sll       $v1, $v1, 2
/* 13F86C 8024C52C 3C018027 */  lui       $at, %hi(D_80270680)
/* 13F870 8024C530 00230821 */  addu      $at, $at, $v1
/* 13F874 8024C534 8C230680 */  lw        $v1, %lo(D_80270680)($at)
/* 13F878 8024C538 00031880 */  sll       $v1, $v1, 2
/* 13F87C 8024C53C 3C018025 */  lui       $at, %hi(D_8024F6B0)
/* 13F880 8024C540 00230821 */  addu      $at, $at, $v1
/* 13F884 8024C544 8C23F6B0 */  lw        $v1, %lo(D_8024F6B0)($at)
/* 13F888 8024C548 000318C0 */  sll       $v1, $v1, 3
/* 13F88C 8024C54C 00431021 */  addu      $v0, $v0, $v1
/* 13F890 8024C550 80440015 */  lb        $a0, 0x15($v0)
/* 13F894 8024C554 24020002 */  addiu     $v0, $zero, 2
/* 13F898 8024C558 14820003 */  bne       $a0, $v0, .L8024C568
/* 13F89C 8024C55C 00000000 */   nop
/* 13F8A0 8024C560 08093160 */  j         .L8024C580
/* 13F8A4 8024C564 24040004 */   addiu    $a0, $zero, 4
.L8024C568:
/* 13F8A8 8024C568 14900003 */  bne       $a0, $s0, .L8024C578
/* 13F8AC 8024C56C 00000000 */   nop
/* 13F8B0 8024C570 08093160 */  j         .L8024C580
/* 13F8B4 8024C574 24040003 */   addiu    $a0, $zero, 3
.L8024C578:
/* 13F8B8 8024C578 50800001 */  beql      $a0, $zero, .L8024C580
/* 13F8BC 8024C57C 24040002 */   addiu    $a0, $zero, 2
.L8024C580:
/* 13F8C0 8024C580 3C058027 */  lui       $a1, %hi(gPauseMenuHeldButtons)
/* 13F8C4 8024C584 24A500C0 */  addiu     $a1, $a1, %lo(gPauseMenuHeldButtons)
/* 13F8C8 8024C588 8CA20000 */  lw        $v0, ($a1)
/* 13F8CC 8024C58C 3C030001 */  lui       $v1, 1
/* 13F8D0 8024C590 00431024 */  and       $v0, $v0, $v1
/* 13F8D4 8024C594 10400006 */  beqz      $v0, .L8024C5B0
/* 13F8D8 8024C598 00000000 */   nop
/* 13F8DC 8024C59C 3C038027 */  lui       $v1, %hi(D_802706A4)
/* 13F8E0 8024C5A0 246306A4 */  addiu     $v1, $v1, %lo(D_802706A4)
/* 13F8E4 8024C5A4 8C620000 */  lw        $v0, ($v1)
/* 13F8E8 8024C5A8 2442FFFF */  addiu     $v0, $v0, -1
/* 13F8EC 8024C5AC AC620000 */  sw        $v0, ($v1)
.L8024C5B0:
/* 13F8F0 8024C5B0 8CA20000 */  lw        $v0, ($a1)
/* 13F8F4 8024C5B4 3C030002 */  lui       $v1, 2
/* 13F8F8 8024C5B8 00431024 */  and       $v0, $v0, $v1
/* 13F8FC 8024C5BC 10400006 */  beqz      $v0, .L8024C5D8
/* 13F900 8024C5C0 00000000 */   nop
/* 13F904 8024C5C4 3C038027 */  lui       $v1, %hi(D_802706A4)
/* 13F908 8024C5C8 246306A4 */  addiu     $v1, $v1, %lo(D_802706A4)
/* 13F90C 8024C5CC 8C620000 */  lw        $v0, ($v1)
/* 13F910 8024C5D0 24420001 */  addiu     $v0, $v0, 1
/* 13F914 8024C5D4 AC620000 */  sw        $v0, ($v1)
.L8024C5D8:
/* 13F918 8024C5D8 3C038027 */  lui       $v1, %hi(D_802706A4)
/* 13F91C 8024C5DC 246306A4 */  addiu     $v1, $v1, %lo(D_802706A4)
/* 13F920 8024C5E0 8C620000 */  lw        $v0, ($v1)
/* 13F924 8024C5E4 04410004 */  bgez      $v0, .L8024C5F8
/* 13F928 8024C5E8 0044102A */   slt      $v0, $v0, $a0
/* 13F92C 8024C5EC 2482FFFF */  addiu     $v0, $a0, -1
/* 13F930 8024C5F0 08093180 */  j         .L8024C600
/* 13F934 8024C5F4 AC620000 */   sw       $v0, ($v1)
.L8024C5F8:
/* 13F938 8024C5F8 50400001 */  beql      $v0, $zero, .L8024C600
/* 13F93C 8024C5FC AC600000 */   sw       $zero, ($v1)
.L8024C600:
/* 13F940 8024C600 3C028027 */  lui       $v0, %hi(D_802706A4)
/* 13F944 8024C604 8C4206A4 */  lw        $v0, %lo(D_802706A4)($v0)
/* 13F948 8024C608 10510003 */  beq       $v0, $s1, .L8024C618
/* 13F94C 8024C60C 00000000 */   nop
/* 13F950 8024C610 0C05272D */  jal       play_sound
/* 13F954 8024C614 240400C7 */   addiu    $a0, $zero, 0xc7
.L8024C618:
/* 13F958 8024C618 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 13F95C 8024C61C 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 13F960 8024C620 30428000 */  andi      $v0, $v0, 0x8000
/* 13F964 8024C624 1040000E */  beqz      $v0, .L8024C660
/* 13F968 8024C628 00000000 */   nop
/* 13F96C 8024C62C 3C038027 */  lui       $v1, %hi(D_802706AC)
/* 13F970 8024C630 246306AC */  addiu     $v1, $v1, %lo(D_802706AC)
/* 13F974 8024C634 8C620000 */  lw        $v0, ($v1)
/* 13F978 8024C638 14400009 */  bnez      $v0, .L8024C660
/* 13F97C 8024C63C 24020001 */   addiu    $v0, $zero, 1
/* 13F980 8024C640 AC620000 */  sw        $v0, ($v1)
/* 13F984 8024C644 0C05272D */  jal       play_sound
/* 13F988 8024C648 240400C9 */   addiu    $a0, $zero, 0xc9
/* 13F98C 8024C64C 24040024 */  addiu     $a0, $zero, 0x24
/* 13F990 8024C650 0C051F9F */  jal       set_window_update
/* 13F994 8024C654 24050001 */   addiu    $a1, $zero, 1
/* 13F998 8024C658 080931E4 */  j         .L8024C790
/* 13F99C 8024C65C 00000000 */   nop
.L8024C660:
/* 13F9A0 8024C660 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 13F9A4 8024C664 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 13F9A8 8024C668 30424000 */  andi      $v0, $v0, 0x4000
/* 13F9AC 8024C66C 10400013 */  beqz      $v0, .L8024C6BC
/* 13F9B0 8024C670 00000000 */   nop
/* 13F9B4 8024C674 3C038027 */  lui       $v1, %hi(D_802706AC)
/* 13F9B8 8024C678 246306AC */  addiu     $v1, $v1, %lo(D_802706AC)
/* 13F9BC 8024C67C 8C620000 */  lw        $v0, ($v1)
/* 13F9C0 8024C680 54400007 */  bnel      $v0, $zero, .L8024C6A0
/* 13F9C4 8024C684 AC600000 */   sw       $zero, ($v1)
/* 13F9C8 8024C688 3C018027 */  lui       $at, %hi(gPauseMenuCurrentTab)
/* 13F9CC 8024C68C A02000D4 */  sb        $zero, %lo(gPauseMenuCurrentTab)($at)
/* 13F9D0 8024C690 0C05272D */  jal       play_sound
/* 13F9D4 8024C694 240400CA */   addiu    $a0, $zero, 0xca
/* 13F9D8 8024C698 080931E4 */  j         .L8024C790
/* 13F9DC 8024C69C 00000000 */   nop
.L8024C6A0:
/* 13F9E0 8024C6A0 0C05272D */  jal       play_sound
/* 13F9E4 8024C6A4 240400CA */   addiu    $a0, $zero, 0xca
/* 13F9E8 8024C6A8 24040024 */  addiu     $a0, $zero, 0x24
/* 13F9EC 8024C6AC 0C051F9F */  jal       set_window_update
/* 13F9F0 8024C6B0 24050002 */   addiu    $a1, $zero, 2
/* 13F9F4 8024C6B4 080931E4 */  j         .L8024C790
/* 13F9F8 8024C6B8 00000000 */   nop
.L8024C6BC:
/* 13F9FC 8024C6BC 3C028027 */  lui       $v0, %hi(D_802706AC)
/* 13FA00 8024C6C0 8C4206AC */  lw        $v0, %lo(D_802706AC)($v0)
/* 13FA04 8024C6C4 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 13FA08 8024C6C8 AC2000CC */  sw        $zero, %lo(gPauseMenuCurrentDescIconScript)($at)
/* 13FA0C 8024C6CC 1440000C */  bnez      $v0, .L8024C700
/* 13FA10 8024C6D0 00000000 */   nop
/* 13FA14 8024C6D4 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13FA18 8024C6D8 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13FA1C 8024C6DC 00021080 */  sll       $v0, $v0, 2
/* 13FA20 8024C6E0 3C018027 */  lui       $at, %hi(D_80270680)
/* 13FA24 8024C6E4 00220821 */  addu      $at, $at, $v0
/* 13FA28 8024C6E8 8C220680 */  lw        $v0, %lo(D_80270680)($at)
/* 13FA2C 8024C6EC 00021080 */  sll       $v0, $v0, 2
/* 13FA30 8024C6F0 3C018025 */  lui       $at, %hi(D_8024F6D0)
/* 13FA34 8024C6F4 00220821 */  addu      $at, $at, $v0
/* 13FA38 8024C6F8 080931E2 */  j         .L8024C788
/* 13FA3C 8024C6FC 8C22F6D0 */   lw       $v0, %lo(D_8024F6D0)($at)
.L8024C700:
/* 13FA40 8024C700 3C048027 */  lui       $a0, %hi(D_802706A4)
/* 13FA44 8024C704 8C8406A4 */  lw        $a0, %lo(D_802706A4)($a0)
/* 13FA48 8024C708 1480000D */  bnez      $a0, .L8024C740
/* 13FA4C 8024C70C 00000000 */   nop
/* 13FA50 8024C710 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13FA54 8024C714 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13FA58 8024C718 00021080 */  sll       $v0, $v0, 2
/* 13FA5C 8024C71C 3C018027 */  lui       $at, %hi(D_80270680)
/* 13FA60 8024C720 00220821 */  addu      $at, $at, $v0
/* 13FA64 8024C724 8C220680 */  lw        $v0, %lo(D_80270680)($at)
/* 13FA68 8024C728 00021080 */  sll       $v0, $v0, 2
/* 13FA6C 8024C72C 3C038025 */  lui       $v1, %hi(D_8024F6F0)
/* 13FA70 8024C730 00621821 */  addu      $v1, $v1, $v0
/* 13FA74 8024C734 8C63F6F0 */  lw        $v1, %lo(D_8024F6F0)($v1)
/* 13FA78 8024C738 080931DD */  j         .L8024C774
/* 13FA7C 8024C73C 00031080 */   sll      $v0, $v1, 2
.L8024C740:
/* 13FA80 8024C740 3C028027 */  lui       $v0, %hi(D_802706A0)
/* 13FA84 8024C744 8C4206A0 */  lw        $v0, %lo(D_802706A0)($v0)
/* 13FA88 8024C748 00021080 */  sll       $v0, $v0, 2
/* 13FA8C 8024C74C 3C018027 */  lui       $at, %hi(D_80270680)
/* 13FA90 8024C750 00220821 */  addu      $at, $at, $v0
/* 13FA94 8024C754 8C220680 */  lw        $v0, %lo(D_80270680)($at)
/* 13FA98 8024C758 00021080 */  sll       $v0, $v0, 2
/* 13FA9C 8024C75C 3C038025 */  lui       $v1, %hi(D_8024F6F0)
/* 13FAA0 8024C760 00621821 */  addu      $v1, $v1, $v0
/* 13FAA4 8024C764 8C63F6F0 */  lw        $v1, %lo(D_8024F6F0)($v1)
/* 13FAA8 8024C768 24820002 */  addiu     $v0, $a0, 2
/* 13FAAC 8024C76C 00621821 */  addu      $v1, $v1, $v0
/* 13FAB0 8024C770 00031080 */  sll       $v0, $v1, 2
.L8024C774:
/* 13FAB4 8024C774 00431021 */  addu      $v0, $v0, $v1
/* 13FAB8 8024C778 00021080 */  sll       $v0, $v0, 2
/* 13FABC 8024C77C 3C018009 */  lui       $at, %hi(D_8008F06C)
/* 13FAC0 8024C780 00220821 */  addu      $at, $at, $v0
/* 13FAC4 8024C784 8C22F06C */  lw        $v0, %lo(D_8008F06C)($at)
.L8024C788:
/* 13FAC8 8024C788 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13FACC 8024C78C AC2200C8 */  sw        $v0, %lo(gPauseMenuCurrentDescString)($at)
.L8024C790:
/* 13FAD0 8024C790 8FBF0018 */  lw        $ra, 0x18($sp)
/* 13FAD4 8024C794 8FB10014 */  lw        $s1, 0x14($sp)
/* 13FAD8 8024C798 8FB00010 */  lw        $s0, 0x10($sp)
/* 13FADC 8024C79C 03E00008 */  jr        $ra
/* 13FAE0 8024C7A0 27BD0020 */   addiu    $sp, $sp, 0x20
