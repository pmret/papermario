.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE6E8_319438
/* 319438 802BE6E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 31943C 802BE6EC AFB00010 */  sw        $s0, 0x10($sp)
/* 319440 802BE6F0 0080802D */  daddu     $s0, $a0, $zero
/* 319444 802BE6F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 319448 802BE6F8 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 31944C 802BE6FC 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 319450 802BE700 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* 319454 802BE704 2442EBB0 */  addiu     $v0, $v0, %lo(D_8010EBB0)
/* 319458 802BE708 AFBF0020 */  sw        $ra, 0x20($sp)
/* 31945C 802BE70C AFB3001C */  sw        $s3, 0x1c($sp)
/* 319460 802BE710 AFB20018 */  sw        $s2, 0x18($sp)
/* 319464 802BE714 80430000 */  lb        $v1, ($v0)
/* 319468 802BE718 1060004F */  beqz      $v1, .L802BE858
/* 31946C 802BE71C 0040902D */   daddu    $s2, $v0, $zero
/* 319470 802BE720 3C02802C */  lui       $v0, %hi(D_802BE92C)
/* 319474 802BE724 8C42E92C */  lw        $v0, %lo(D_802BE92C)($v0)
/* 319478 802BE728 50400004 */  beql      $v0, $zero, .L802BE73C
/* 31947C 802BE72C 0000202D */   daddu    $a0, $zero, $zero
/* 319480 802BE730 0C038069 */  jal       enable_player_input
/* 319484 802BE734 00000000 */   nop
/* 319488 802BE738 0000202D */  daddu     $a0, $zero, $zero
.L802BE73C:
/* 31948C 802BE73C 8E220000 */  lw        $v0, ($s1)
/* 319490 802BE740 2403FFFD */  addiu     $v1, $zero, -3
/* 319494 802BE744 3C01802C */  lui       $at, %hi(D_802BE928)
/* 319498 802BE748 AC20E928 */  sw        $zero, %lo(D_802BE928)($at)
/* 31949C 802BE74C 00431024 */  and       $v0, $v0, $v1
/* 3194A0 802BE750 AE220000 */  sw        $v0, ($s1)
/* 3194A4 802BE754 8E020000 */  lw        $v0, ($s0)
/* 3194A8 802BE758 2403F7FF */  addiu     $v1, $zero, -0x801
/* 3194AC 802BE75C AE00001C */  sw        $zero, 0x1c($s0)
/* 3194B0 802BE760 00431024 */  and       $v0, $v0, $v1
/* 3194B4 802BE764 0C039769 */  jal       set_action_state
/* 3194B8 802BE768 AE020000 */   sw       $v0, ($s0)
/* 3194BC 802BE76C 0C03BD17 */  jal       partner_clear_player_tracking
/* 3194C0 802BE770 0200202D */   daddu    $a0, $s0, $zero
/* 3194C4 802BE774 C6200028 */  lwc1      $f0, 0x28($s1)
/* 3194C8 802BE778 A2400000 */  sb        $zero, ($s2)
/* 3194CC 802BE77C A2400003 */  sb        $zero, 3($s2)
/* 3194D0 802BE780 3C02802C */  lui       $v0, %hi(D_802BE920)
/* 3194D4 802BE784 8C42E920 */  lw        $v0, %lo(D_802BE920)($v0)
/* 3194D8 802BE788 E6000038 */  swc1      $f0, 0x38($s0)
/* 3194DC 802BE78C C620002C */  lwc1      $f0, 0x2c($s1)
/* 3194E0 802BE790 26120038 */  addiu     $s2, $s0, 0x38
/* 3194E4 802BE794 E600003C */  swc1      $f0, 0x3c($s0)
/* 3194E8 802BE798 C6200030 */  lwc1      $f0, 0x30($s1)
/* 3194EC 802BE79C 26130040 */  addiu     $s3, $s0, 0x40
/* 3194F0 802BE7A0 14400006 */  bnez      $v0, .L802BE7BC
/* 3194F4 802BE7A4 E6000040 */   swc1     $f0, 0x40($s0)
/* 3194F8 802BE7A8 C6200080 */  lwc1      $f0, 0x80($s1)
/* 3194FC 802BE7AC 3C0142B4 */  lui       $at, 0x42b4
/* 319500 802BE7B0 44816000 */  mtc1      $at, $f12
/* 319504 802BE7B4 080AF9F4 */  j         .L802BE7D0
/* 319508 802BE7B8 460C0300 */   add.s    $f12, $f0, $f12
.L802BE7BC:
/* 31950C 802BE7BC C6200080 */  lwc1      $f0, 0x80($s1)
/* 319510 802BE7C0 3C0142B4 */  lui       $at, 0x42b4
/* 319514 802BE7C4 44816000 */  mtc1      $at, $f12
/* 319518 802BE7C8 00000000 */  nop
/* 31951C 802BE7CC 460C0301 */  sub.s     $f12, $f0, $f12
.L802BE7D0:
/* 319520 802BE7D0 0C00A6C9 */  jal       clamp_angle
/* 319524 802BE7D4 00000000 */   nop
/* 319528 802BE7D8 862200B2 */  lh        $v0, 0xb2($s1)
/* 31952C 802BE7DC 04420001 */  bltzl     $v0, .L802BE7E4
/* 319530 802BE7E0 24420003 */   addiu    $v0, $v0, 3
.L802BE7E4:
/* 319534 802BE7E4 0240202D */  daddu     $a0, $s2, $zero
/* 319538 802BE7E8 00021083 */  sra       $v0, $v0, 2
/* 31953C 802BE7EC 44821000 */  mtc1      $v0, $f2
/* 319540 802BE7F0 00000000 */  nop
/* 319544 802BE7F4 468010A0 */  cvt.s.w   $f2, $f2
/* 319548 802BE7F8 44070000 */  mfc1      $a3, $f0
/* 31954C 802BE7FC 44061000 */  mfc1      $a2, $f2
/* 319550 802BE800 0C00A7E7 */  jal       add_vec2D_polar
/* 319554 802BE804 0260282D */   daddu    $a1, $s3, $zero
/* 319558 802BE808 3C020003 */  lui       $v0, 3
/* 31955C 802BE80C 34420003 */  ori       $v0, $v0, 3
/* 319560 802BE810 AE00001C */  sw        $zero, 0x1c($s0)
/* 319564 802BE814 C620002C */  lwc1      $f0, 0x2c($s1)
/* 319568 802BE818 0200202D */  daddu     $a0, $s0, $zero
/* 31956C 802BE81C AE000044 */  sw        $zero, 0x44($s0)
/* 319570 802BE820 AE00004C */  sw        $zero, 0x4c($s0)
/* 319574 802BE824 AE020028 */  sw        $v0, 0x28($s0)
/* 319578 802BE828 0C03BD17 */  jal       partner_clear_player_tracking
/* 31957C 802BE82C E600003C */   swc1     $f0, 0x3c($s0)
/* 319580 802BE830 0C00EB6B */  jal       disable_npc_blur
/* 319584 802BE834 0200202D */   daddu    $a0, $s0, $zero
/* 319588 802BE838 3C03802C */  lui       $v1, %hi(D_802BE924)
/* 31958C 802BE83C 2463E924 */  addiu     $v1, $v1, %lo(D_802BE924)
/* 319590 802BE840 8C620000 */  lw        $v0, ($v1)
/* 319594 802BE844 10400004 */  beqz      $v0, .L802BE858
/* 319598 802BE848 00000000 */   nop
/* 31959C 802BE84C AC600000 */  sw        $zero, ($v1)
/* 3195A0 802BE850 0C05271B */  jal       sfx_stop_sound
/* 3195A4 802BE854 3C048000 */   lui      $a0, 0x8000
.L802BE858:
/* 3195A8 802BE858 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3195AC 802BE85C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3195B0 802BE860 8FB20018 */  lw        $s2, 0x18($sp)
/* 3195B4 802BE864 8FB10014 */  lw        $s1, 0x14($sp)
/* 3195B8 802BE868 8FB00010 */  lw        $s0, 0x10($sp)
/* 3195BC 802BE86C 03E00008 */  jr        $ra
/* 3195C0 802BE870 27BD0028 */   addiu    $sp, $sp, 0x28
/* 3195C4 802BE874 00000000 */  nop
/* 3195C8 802BE878 00000000 */  nop
/* 3195CC 802BE87C 00000000 */  nop
