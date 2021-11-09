.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FFC_E0635C
/* E0635C 80240FFC 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* E06360 80241000 AFB00088 */  sw        $s0, 0x88($sp)
/* E06364 80241004 00A0802D */  daddu     $s0, $a1, $zero
/* E06368 80241008 0000202D */  daddu     $a0, $zero, $zero
/* E0636C 8024100C 0080282D */  daddu     $a1, $a0, $zero
/* E06370 80241010 0080302D */  daddu     $a2, $a0, $zero
/* E06374 80241014 0080382D */  daddu     $a3, $a0, $zero
/* E06378 80241018 AFBF00A0 */  sw        $ra, 0xa0($sp)
/* E0637C 8024101C AFB5009C */  sw        $s5, 0x9c($sp)
/* E06380 80241020 AFB40098 */  sw        $s4, 0x98($sp)
/* E06384 80241024 AFB30094 */  sw        $s3, 0x94($sp)
/* E06388 80241028 AFB20090 */  sw        $s2, 0x90($sp)
/* E0638C 8024102C AFB1008C */  sw        $s1, 0x8c($sp)
/* E06390 80241030 F7B600B0 */  sdc1      $f22, 0xb0($sp)
/* E06394 80241034 F7B400A8 */  sdc1      $f20, 0xa8($sp)
/* E06398 80241038 C6140010 */  lwc1      $f20, 0x10($s0)
/* E0639C 8024103C 4680A520 */  cvt.s.w   $f20, $f20
/* E063A0 80241040 C6160014 */  lwc1      $f22, 0x14($s0)
/* E063A4 80241044 4680B5A0 */  cvt.s.w   $f22, $f22
/* E063A8 80241048 AFA00010 */  sw        $zero, 0x10($sp)
/* E063AC 8024104C AFA00014 */  sw        $zero, 0x14($sp)
/* E063B0 80241050 0C04EAA7 */  jal       sprfx_update
/* E063B4 80241054 AFA00018 */   sw       $zero, 0x18($sp)
/* E063B8 80241058 27B40048 */  addiu     $s4, $sp, 0x48
/* E063BC 8024105C 0280202D */  daddu     $a0, $s4, $zero
/* E063C0 80241060 0000382D */  daddu     $a3, $zero, $zero
/* E063C4 80241064 3C150001 */  lui       $s5, 1
/* E063C8 80241068 4600B587 */  neg.s     $f22, $f22
/* E063CC 8024106C 4405A000 */  mfc1      $a1, $f20
/* E063D0 80241070 4406B000 */  mfc1      $a2, $f22
/* E063D4 80241074 0C019E40 */  jal       guTranslateF
/* E063D8 80241078 36B51630 */   ori      $s5, $s5, 0x1630
/* E063DC 8024107C 0280202D */  daddu     $a0, $s4, $zero
/* E063E0 80241080 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* E063E4 80241084 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* E063E8 80241088 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* E063EC 8024108C 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* E063F0 80241090 96250000 */  lhu       $a1, ($s1)
/* E063F4 80241094 8E420000 */  lw        $v0, ($s2)
/* E063F8 80241098 00052980 */  sll       $a1, $a1, 6
/* E063FC 8024109C 00B52821 */  addu      $a1, $a1, $s5
/* E06400 802410A0 0C019D40 */  jal       guMtxF2L
/* E06404 802410A4 00452821 */   addu     $a1, $v0, $a1
/* E06408 802410A8 3C02DA38 */  lui       $v0, 0xda38
/* E0640C 802410AC 34420002 */  ori       $v0, $v0, 2
/* E06410 802410B0 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* E06414 802410B4 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* E06418 802410B8 8E680000 */  lw        $t0, ($s3)
/* E0641C 802410BC 96290000 */  lhu       $t1, ($s1)
/* E06420 802410C0 0100202D */  daddu     $a0, $t0, $zero
/* E06424 802410C4 AC820000 */  sw        $v0, ($a0)
/* E06428 802410C8 3122FFFF */  andi      $v0, $t1, 0xffff
/* E0642C 802410CC 00021180 */  sll       $v0, $v0, 6
/* E06430 802410D0 00551021 */  addu      $v0, $v0, $s5
/* E06434 802410D4 8E430000 */  lw        $v1, ($s2)
/* E06438 802410D8 25080008 */  addiu     $t0, $t0, 8
/* E0643C 802410DC 00621821 */  addu      $v1, $v1, $v0
/* E06440 802410E0 3C028000 */  lui       $v0, 0x8000
/* E06444 802410E4 00621821 */  addu      $v1, $v1, $v0
/* E06448 802410E8 27A20038 */  addiu     $v0, $sp, 0x38
/* E0644C 802410EC AC830004 */  sw        $v1, 4($a0)
/* E06450 802410F0 AFA20010 */  sw        $v0, 0x10($sp)
/* E06454 802410F4 8E040004 */  lw        $a0, 4($s0)
/* E06458 802410F8 8E050008 */  lw        $a1, 8($s0)
/* E0645C 802410FC 8E060000 */  lw        $a2, ($s0)
/* E06460 80241100 8E07000C */  lw        $a3, 0xc($s0)
/* E06464 80241104 25290001 */  addiu     $t1, $t1, 1
/* E06468 80241108 AE680000 */  sw        $t0, ($s3)
/* E0646C 8024110C 0C04BA38 */  jal       msg_get_glyph
/* E06470 80241110 A6290000 */   sh       $t1, ($s1)
/* E06474 80241114 0000202D */  daddu     $a0, $zero, $zero
/* E06478 80241118 27A50020 */  addiu     $a1, $sp, 0x20
/* E0647C 8024111C 3C060005 */  lui       $a2, 5
/* E06480 80241120 34C60040 */  ori       $a2, $a2, 0x40
/* E06484 80241124 0280382D */  daddu     $a3, $s4, $zero
/* E06488 80241128 93A20042 */  lbu       $v0, 0x42($sp)
/* E0648C 8024112C 3C013FE0 */  lui       $at, 0x3fe0
/* E06490 80241130 44810800 */  mtc1      $at, $f1
/* E06494 80241134 44800000 */  mtc1      $zero, $f0
/* E06498 80241138 8FA30038 */  lw        $v1, 0x38($sp)
/* E0649C 8024113C 8FA8003C */  lw        $t0, 0x3c($sp)
/* E064A0 80241140 93A90040 */  lbu       $t1, 0x40($sp)
/* E064A4 80241144 93AA0041 */  lbu       $t2, 0x41($sp)
/* E064A8 80241148 44821000 */  mtc1      $v0, $f2
/* E064AC 8024114C 00000000 */  nop
/* E064B0 80241150 468010A1 */  cvt.d.w   $f2, $f2
/* E064B4 80241154 46201082 */  mul.d     $f2, $f2, $f0
/* E064B8 80241158 00000000 */  nop
/* E064BC 8024115C A7A0002E */  sh        $zero, 0x2e($sp)
/* E064C0 80241160 240200FF */  addiu     $v0, $zero, 0xff
/* E064C4 80241164 A3A20030 */  sb        $v0, 0x30($sp)
/* E064C8 80241168 AFA30020 */  sw        $v1, 0x20($sp)
/* E064CC 8024116C AFA80024 */  sw        $t0, 0x24($sp)
/* E064D0 80241170 A7A90028 */  sh        $t1, 0x28($sp)
/* E064D4 80241174 A7AA002A */  sh        $t2, 0x2a($sp)
/* E064D8 80241178 46201087 */  neg.d     $f2, $f2
/* E064DC 8024117C 4620110D */  trunc.w.d $f4, $f2
/* E064E0 80241180 44022000 */  mfc1      $v0, $f4
/* E064E4 80241184 0C04EBDC */  jal       sprfx_appendGfx_component
/* E064E8 80241188 A7A2002C */   sh       $v0, 0x2c($sp)
/* E064EC 8024118C 3C04D838 */  lui       $a0, 0xd838
/* E064F0 80241190 8E620000 */  lw        $v0, ($s3)
/* E064F4 80241194 34840002 */  ori       $a0, $a0, 2
/* E064F8 80241198 0040182D */  daddu     $v1, $v0, $zero
/* E064FC 8024119C 24420008 */  addiu     $v0, $v0, 8
/* E06500 802411A0 AE620000 */  sw        $v0, ($s3)
/* E06504 802411A4 24020040 */  addiu     $v0, $zero, 0x40
/* E06508 802411A8 AC640000 */  sw        $a0, ($v1)
/* E0650C 802411AC AC620004 */  sw        $v0, 4($v1)
/* E06510 802411B0 8FBF00A0 */  lw        $ra, 0xa0($sp)
/* E06514 802411B4 8FB5009C */  lw        $s5, 0x9c($sp)
/* E06518 802411B8 8FB40098 */  lw        $s4, 0x98($sp)
/* E0651C 802411BC 8FB30094 */  lw        $s3, 0x94($sp)
/* E06520 802411C0 8FB20090 */  lw        $s2, 0x90($sp)
/* E06524 802411C4 8FB1008C */  lw        $s1, 0x8c($sp)
/* E06528 802411C8 8FB00088 */  lw        $s0, 0x88($sp)
/* E0652C 802411CC D7B600B0 */  ldc1      $f22, 0xb0($sp)
/* E06530 802411D0 D7B400A8 */  ldc1      $f20, 0xa8($sp)
/* E06534 802411D4 03E00008 */  jr        $ra
/* E06538 802411D8 27BD00B8 */   addiu    $sp, $sp, 0xb8
