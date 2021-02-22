.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412C8_DDDAF8
/* DDDAF8 802412C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDDAFC 802412CC AFB10014 */  sw        $s1, 0x14($sp)
/* DDDB00 802412D0 0080882D */  daddu     $s1, $a0, $zero
/* DDDB04 802412D4 AFB20018 */  sw        $s2, 0x18($sp)
/* DDDB08 802412D8 AFBF001C */  sw        $ra, 0x1c($sp)
/* DDDB0C 802412DC AFB00010 */  sw        $s0, 0x10($sp)
/* DDDB10 802412E0 8E30000C */  lw        $s0, 0xc($s1)
/* DDDB14 802412E4 10A00010 */  beqz      $a1, .L80241328
/* DDDB18 802412E8 0000902D */   daddu    $s2, $zero, $zero
/* DDDB1C 802412EC 8E050000 */  lw        $a1, ($s0)
/* DDDB20 802412F0 0C0B1EAF */  jal       get_variable
/* DDDB24 802412F4 26100004 */   addiu    $s0, $s0, 4
/* DDDB28 802412F8 AE220084 */  sw        $v0, 0x84($s1)
/* DDDB2C 802412FC 8E050000 */  lw        $a1, ($s0)
/* DDDB30 80241300 0C0B1EAF */  jal       get_variable
/* DDDB34 80241304 0220202D */   daddu    $a0, $s1, $zero
/* DDDB38 80241308 0240202D */  daddu     $a0, $s2, $zero
/* DDDB3C 8024130C 240500D0 */  addiu     $a1, $zero, 0xd0
/* DDDB40 80241310 00A0302D */  daddu     $a2, $a1, $zero
/* DDDB44 80241314 00A0382D */  daddu     $a3, $a1, $zero
/* DDDB48 80241318 AE220088 */  sw        $v0, 0x88($s1)
/* DDDB4C 8024131C AE200070 */  sw        $zero, 0x70($s1)
/* DDDB50 80241320 0C04DF84 */  jal       set_transition_stencil_color
/* DDDB54 80241324 AE200074 */   sw       $zero, 0x74($s1)
.L80241328:
/* DDDB58 80241328 8E230070 */  lw        $v1, 0x70($s1)
/* DDDB5C 8024132C 24040001 */  addiu     $a0, $zero, 1
/* DDDB60 80241330 10640019 */  beq       $v1, $a0, .L80241398
/* DDDB64 80241334 28620002 */   slti     $v0, $v1, 2
/* DDDB68 80241338 10400005 */  beqz      $v0, .L80241350
/* DDDB6C 8024133C 24020002 */   addiu    $v0, $zero, 2
/* DDDB70 80241340 10600007 */  beqz      $v1, .L80241360
/* DDDB74 80241344 240500FF */   addiu    $a1, $zero, 0xff
/* DDDB78 80241348 080904F6 */  j         .L802413D8
/* DDDB7C 8024134C 00000000 */   nop
.L80241350:
/* DDDB80 80241350 10620019 */  beq       $v1, $v0, .L802413B8
/* DDDB84 80241354 00000000 */   nop
/* DDDB88 80241358 080904F6 */  j         .L802413D8
/* DDDB8C 8024135C 00000000 */   nop
.L80241360:
/* DDDB90 80241360 8E220074 */  lw        $v0, 0x74($s1)
/* DDDB94 80241364 14450004 */  bne       $v0, $a1, .L80241378
/* DDDB98 80241368 00000000 */   nop
/* DDDB9C 8024136C AE240070 */  sw        $a0, 0x70($s1)
/* DDDBA0 80241370 AE200078 */  sw        $zero, 0x78($s1)
/* DDDBA4 80241374 8E220074 */  lw        $v0, 0x74($s1)
.L80241378:
/* DDDBA8 80241378 8E230084 */  lw        $v1, 0x84($s1)
/* DDDBAC 8024137C 00431021 */  addu      $v0, $v0, $v1
/* DDDBB0 80241380 AE220074 */  sw        $v0, 0x74($s1)
/* DDDBB4 80241384 28420100 */  slti      $v0, $v0, 0x100
/* DDDBB8 80241388 50400013 */  beql      $v0, $zero, .L802413D8
/* DDDBBC 8024138C AE250074 */   sw       $a1, 0x74($s1)
/* DDDBC0 80241390 080904F6 */  j         .L802413D8
/* DDDBC4 80241394 00000000 */   nop
.L80241398:
/* DDDBC8 80241398 8E220078 */  lw        $v0, 0x78($s1)
/* DDDBCC 8024139C 24420001 */  addiu     $v0, $v0, 1
/* DDDBD0 802413A0 AE220078 */  sw        $v0, 0x78($s1)
/* DDDBD4 802413A4 28420002 */  slti      $v0, $v0, 2
/* DDDBD8 802413A8 1440000B */  bnez      $v0, .L802413D8
/* DDDBDC 802413AC 24020002 */   addiu    $v0, $zero, 2
/* DDDBE0 802413B0 080904F6 */  j         .L802413D8
/* DDDBE4 802413B4 AE220070 */   sw       $v0, 0x70($s1)
.L802413B8:
/* DDDBE8 802413B8 8E230074 */  lw        $v1, 0x74($s1)
/* DDDBEC 802413BC 50600001 */  beql      $v1, $zero, .L802413C4
/* DDDBF0 802413C0 24120001 */   addiu    $s2, $zero, 1
.L802413C4:
/* DDDBF4 802413C4 8E220088 */  lw        $v0, 0x88($s1)
/* DDDBF8 802413C8 00621023 */  subu      $v0, $v1, $v0
/* DDDBFC 802413CC 04410002 */  bgez      $v0, .L802413D8
/* DDDC00 802413D0 AE220074 */   sw       $v0, 0x74($s1)
/* DDDC04 802413D4 AE200074 */  sw        $zero, 0x74($s1)
.L802413D8:
/* DDDC08 802413D8 C6200074 */  lwc1      $f0, 0x74($s1)
/* DDDC0C 802413DC 46800020 */  cvt.s.w   $f0, $f0
/* DDDC10 802413E0 44050000 */  mfc1      $a1, $f0
/* DDDC14 802413E4 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* DDDC18 802413E8 24040001 */   addiu    $a0, $zero, 1
/* DDDC1C 802413EC 0240102D */  daddu     $v0, $s2, $zero
/* DDDC20 802413F0 8FBF001C */  lw        $ra, 0x1c($sp)
/* DDDC24 802413F4 8FB20018 */  lw        $s2, 0x18($sp)
/* DDDC28 802413F8 8FB10014 */  lw        $s1, 0x14($sp)
/* DDDC2C 802413FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DDDC30 80241400 03E00008 */  jr        $ra
/* DDDC34 80241404 27BD0020 */   addiu    $sp, $sp, 0x20
