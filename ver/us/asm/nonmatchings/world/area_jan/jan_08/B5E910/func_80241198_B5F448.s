.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkFunc23
/* B5F448 80241198 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5F44C 8024119C AFB10014 */  sw        $s1, 0x14($sp)
/* B5F450 802411A0 0080882D */  daddu     $s1, $a0, $zero
/* B5F454 802411A4 AFB20018 */  sw        $s2, 0x18($sp)
/* B5F458 802411A8 AFBF001C */  sw        $ra, 0x1c($sp)
/* B5F45C 802411AC AFB00010 */  sw        $s0, 0x10($sp)
/* B5F460 802411B0 8E30000C */  lw        $s0, 0xc($s1)
/* B5F464 802411B4 10A00010 */  beqz      $a1, .L802411F8
/* B5F468 802411B8 0000902D */   daddu    $s2, $zero, $zero
/* B5F46C 802411BC 8E050000 */  lw        $a1, ($s0)
/* B5F470 802411C0 0C0B1EAF */  jal       get_variable
/* B5F474 802411C4 26100004 */   addiu    $s0, $s0, 4
/* B5F478 802411C8 AE220084 */  sw        $v0, 0x84($s1)
/* B5F47C 802411CC 8E050000 */  lw        $a1, ($s0)
/* B5F480 802411D0 0C0B1EAF */  jal       get_variable
/* B5F484 802411D4 0220202D */   daddu    $a0, $s1, $zero
/* B5F488 802411D8 0240202D */  daddu     $a0, $s2, $zero
/* B5F48C 802411DC 240500D0 */  addiu     $a1, $zero, 0xd0
/* B5F490 802411E0 00A0302D */  daddu     $a2, $a1, $zero
/* B5F494 802411E4 00A0382D */  daddu     $a3, $a1, $zero
/* B5F498 802411E8 AE220088 */  sw        $v0, 0x88($s1)
/* B5F49C 802411EC AE200070 */  sw        $zero, 0x70($s1)
/* B5F4A0 802411F0 0C04DF84 */  jal       set_transition_stencil_color
/* B5F4A4 802411F4 AE200074 */   sw       $zero, 0x74($s1)
.L802411F8:
/* B5F4A8 802411F8 8E230070 */  lw        $v1, 0x70($s1)
/* B5F4AC 802411FC 24040001 */  addiu     $a0, $zero, 1
/* B5F4B0 80241200 10640019 */  beq       $v1, $a0, .L80241268
/* B5F4B4 80241204 28620002 */   slti     $v0, $v1, 2
/* B5F4B8 80241208 10400005 */  beqz      $v0, .L80241220
/* B5F4BC 8024120C 24020002 */   addiu    $v0, $zero, 2
/* B5F4C0 80241210 10600007 */  beqz      $v1, .L80241230
/* B5F4C4 80241214 240500FF */   addiu    $a1, $zero, 0xff
/* B5F4C8 80241218 080904AA */  j         .L802412A8
/* B5F4CC 8024121C 00000000 */   nop
.L80241220:
/* B5F4D0 80241220 10620019 */  beq       $v1, $v0, .L80241288
/* B5F4D4 80241224 00000000 */   nop
/* B5F4D8 80241228 080904AA */  j         .L802412A8
/* B5F4DC 8024122C 00000000 */   nop
.L80241230:
/* B5F4E0 80241230 8E220074 */  lw        $v0, 0x74($s1)
/* B5F4E4 80241234 14450004 */  bne       $v0, $a1, .L80241248
/* B5F4E8 80241238 00000000 */   nop
/* B5F4EC 8024123C AE240070 */  sw        $a0, 0x70($s1)
/* B5F4F0 80241240 AE200078 */  sw        $zero, 0x78($s1)
/* B5F4F4 80241244 8E220074 */  lw        $v0, 0x74($s1)
.L80241248:
/* B5F4F8 80241248 8E230084 */  lw        $v1, 0x84($s1)
/* B5F4FC 8024124C 00431021 */  addu      $v0, $v0, $v1
/* B5F500 80241250 AE220074 */  sw        $v0, 0x74($s1)
/* B5F504 80241254 28420100 */  slti      $v0, $v0, 0x100
/* B5F508 80241258 50400013 */  beql      $v0, $zero, .L802412A8
/* B5F50C 8024125C AE250074 */   sw       $a1, 0x74($s1)
/* B5F510 80241260 080904AA */  j         .L802412A8
/* B5F514 80241264 00000000 */   nop
.L80241268:
/* B5F518 80241268 8E220078 */  lw        $v0, 0x78($s1)
/* B5F51C 8024126C 24420001 */  addiu     $v0, $v0, 1
/* B5F520 80241270 AE220078 */  sw        $v0, 0x78($s1)
/* B5F524 80241274 28420002 */  slti      $v0, $v0, 2
/* B5F528 80241278 1440000B */  bnez      $v0, .L802412A8
/* B5F52C 8024127C 24020002 */   addiu    $v0, $zero, 2
/* B5F530 80241280 080904AA */  j         .L802412A8
/* B5F534 80241284 AE220070 */   sw       $v0, 0x70($s1)
.L80241288:
/* B5F538 80241288 8E230074 */  lw        $v1, 0x74($s1)
/* B5F53C 8024128C 50600001 */  beql      $v1, $zero, .L80241294
/* B5F540 80241290 24120001 */   addiu    $s2, $zero, 1
.L80241294:
/* B5F544 80241294 8E220088 */  lw        $v0, 0x88($s1)
/* B5F548 80241298 00621023 */  subu      $v0, $v1, $v0
/* B5F54C 8024129C 04410002 */  bgez      $v0, .L802412A8
/* B5F550 802412A0 AE220074 */   sw       $v0, 0x74($s1)
/* B5F554 802412A4 AE200074 */  sw        $zero, 0x74($s1)
.L802412A8:
/* B5F558 802412A8 C6200074 */  lwc1      $f0, 0x74($s1)
/* B5F55C 802412AC 46800020 */  cvt.s.w   $f0, $f0
/* B5F560 802412B0 44050000 */  mfc1      $a1, $f0
/* B5F564 802412B4 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* B5F568 802412B8 24040001 */   addiu    $a0, $zero, 1
/* B5F56C 802412BC 0240102D */  daddu     $v0, $s2, $zero
/* B5F570 802412C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* B5F574 802412C4 8FB20018 */  lw        $s2, 0x18($sp)
/* B5F578 802412C8 8FB10014 */  lw        $s1, 0x14($sp)
/* B5F57C 802412CC 8FB00010 */  lw        $s0, 0x10($sp)
/* B5F580 802412D0 03E00008 */  jr        $ra
/* B5F584 802412D4 27BD0020 */   addiu    $sp, $sp, 0x20
