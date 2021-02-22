.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A4534
/* 4192C4 802A4534 3C02802B */  lui       $v0, %hi(D_802AD258)
/* 4192C8 802A4538 8C42D258 */  lw        $v0, %lo(D_802AD258)($v0)
/* 4192CC 802A453C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4192D0 802A4540 AFB1001C */  sw        $s1, 0x1c($sp)
/* 4192D4 802A4544 24D10006 */  addiu     $s1, $a2, 6
/* 4192D8 802A4548 AFB20020 */  sw        $s2, 0x20($sp)
/* 4192DC 802A454C 24B2000B */  addiu     $s2, $a1, 0xb
/* 4192E0 802A4550 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4192E4 802A4554 10400004 */  beqz      $v0, .L802A4568
/* 4192E8 802A4558 AFB00018 */   sw       $s0, 0x18($sp)
/* 4192EC 802A455C 3C10001D */  lui       $s0, 0x1d
/* 4192F0 802A4560 080A9161 */  j         .L802A4584
/* 4192F4 802A4564 361000C3 */   ori      $s0, $s0, 0xc3
.L802A4568:
/* 4192F8 802A4568 3C10001D */  lui       $s0, 0x1d
/* 4192FC 802A456C 3C02802B */  lui       $v0, %hi(battle_menu_hasSpiritsMenu)
/* 419300 802A4570 8C42D4A0 */  lw        $v0, %lo(battle_menu_hasSpiritsMenu)($v0)
/* 419304 802A4574 14400003 */  bnez      $v0, .L802A4584
/* 419308 802A4578 361000A0 */   ori      $s0, $s0, 0xa0
/* 41930C 802A457C 3C10001D */  lui       $s0, 0x1d
/* 419310 802A4580 3610009F */  ori       $s0, $s0, 0x9f
.L802A4584:
/* 419314 802A4584 0C04992C */  jal       get_msg_lines
/* 419318 802A4588 0200202D */   daddu    $a0, $s0, $zero
/* 41931C 802A458C 0200202D */  daddu     $a0, $s0, $zero
/* 419320 802A4590 2442FFFF */  addiu     $v0, $v0, -1
/* 419324 802A4594 00021040 */  sll       $v0, $v0, 1
/* 419328 802A4598 3C06802B */  lui       $a2, %hi(D_802AB344)
/* 41932C 802A459C 00C23021 */  addu      $a2, $a2, $v0
/* 419330 802A45A0 84C6B344 */  lh        $a2, %lo(D_802AB344)($a2)
/* 419334 802A45A4 2402000F */  addiu     $v0, $zero, 0xf
/* 419338 802A45A8 0240282D */  daddu     $a1, $s2, $zero
/* 41933C 802A45AC 240700FF */  addiu     $a3, $zero, 0xff
/* 419340 802A45B0 AFA20010 */  sw        $v0, 0x10($sp)
/* 419344 802A45B4 AFA00014 */  sw        $zero, 0x14($sp)
/* 419348 802A45B8 0C04993B */  jal       draw_msg
/* 41934C 802A45BC 02263021 */   addu     $a2, $s1, $a2
/* 419350 802A45C0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 419354 802A45C4 8FB20020 */  lw        $s2, 0x20($sp)
/* 419358 802A45C8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 41935C 802A45CC 8FB00018 */  lw        $s0, 0x18($sp)
/* 419360 802A45D0 03E00008 */  jr        $ra
/* 419364 802A45D4 27BD0028 */   addiu    $sp, $sp, 0x28
