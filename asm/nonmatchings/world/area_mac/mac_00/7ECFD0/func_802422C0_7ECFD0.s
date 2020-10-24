.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422C0_7ECFD0
/* 7ECFD0 802422C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7ECFD4 802422C4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECFD8 802422C8 0080802D */  daddu     $s0, $a0, $zero
/* 7ECFDC 802422CC AFB20018 */  sw        $s2, 0x18($sp)
/* 7ECFE0 802422D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 7ECFE4 802422D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ECFE8 802422D8 8E02000C */  lw        $v0, 0xc($s0)
/* 7ECFEC 802422DC 10A00008 */  beqz      $a1, .L80242300
/* 7ECFF0 802422E0 0000902D */   daddu    $s2, $zero, $zero
/* 7ECFF4 802422E4 8C450000 */  lw        $a1, ($v0)
/* 7ECFF8 802422E8 0C0B1EAF */  jal       get_variable
/* 7ECFFC 802422EC 00000000 */   nop      
/* 7ED000 802422F0 AE020070 */  sw        $v0, 0x70($s0)
/* 7ED004 802422F4 AE000074 */  sw        $zero, 0x74($s0)
/* 7ED008 802422F8 8C420014 */  lw        $v0, 0x14($v0)
/* 7ED00C 802422FC AE020078 */  sw        $v0, 0x78($s0)
.L80242300:
/* 7ED010 80242300 8E050078 */  lw        $a1, 0x78($s0)
/* 7ED014 80242304 8E110070 */  lw        $s1, 0x70($s0)
/* 7ED018 80242308 0C0B1EAF */  jal       get_variable
/* 7ED01C 8024230C 0200202D */   daddu    $a0, $s0, $zero
/* 7ED020 80242310 10400006 */  beqz      $v0, .L8024232C
/* 7ED024 80242314 24030002 */   addiu    $v1, $zero, 2
/* 7ED028 80242318 8E020074 */  lw        $v0, 0x74($s0)
/* 7ED02C 8024231C 10430027 */  beq       $v0, $v1, .L802423BC
/* 7ED030 80242320 00000000 */   nop      
/* 7ED034 80242324 080908EE */  j         .L802423B8
/* 7ED038 80242328 AE030074 */   sw       $v1, 0x74($s0)
.L8024232C:
/* 7ED03C 8024232C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 7ED040 80242330 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 7ED044 80242334 8E260000 */  lw        $a2, ($s1)
/* 7ED048 80242338 8E270004 */  lw        $a3, 4($s1)
/* 7ED04C 8024233C C44C0028 */  lwc1      $f12, 0x28($v0)
/* 7ED050 80242340 0C00A7B5 */  jal       dist2D
/* 7ED054 80242344 C44E0030 */   lwc1     $f14, 0x30($v0)
/* 7ED058 80242348 8E030074 */  lw        $v1, 0x74($s0)
/* 7ED05C 8024234C 24040001 */  addiu     $a0, $zero, 1
/* 7ED060 80242350 10640013 */  beq       $v1, $a0, .L802423A0
/* 7ED064 80242354 46000086 */   mov.s    $f2, $f0
/* 7ED068 80242358 28620002 */  slti      $v0, $v1, 2
/* 7ED06C 8024235C 50400005 */  beql      $v0, $zero, .L80242374
/* 7ED070 80242360 24020002 */   addiu    $v0, $zero, 2
/* 7ED074 80242364 10600007 */  beqz      $v1, .L80242384
/* 7ED078 80242368 00000000 */   nop      
/* 7ED07C 8024236C 080908EF */  j         .L802423BC
/* 7ED080 80242370 00000000 */   nop      
.L80242374:
/* 7ED084 80242374 50620010 */  beql      $v1, $v0, .L802423B8
/* 7ED088 80242378 AE040074 */   sw       $a0, 0x74($s0)
/* 7ED08C 8024237C 080908EF */  j         .L802423BC
/* 7ED090 80242380 00000000 */   nop      
.L80242384:
/* 7ED094 80242384 C6200008 */  lwc1      $f0, 8($s1)
/* 7ED098 80242388 4600103C */  c.lt.s    $f2, $f0
/* 7ED09C 8024238C 00000000 */  nop       
/* 7ED0A0 80242390 4500000A */  bc1f      .L802423BC
/* 7ED0A4 80242394 00000000 */   nop      
/* 7ED0A8 80242398 080908EE */  j         .L802423B8
/* 7ED0AC 8024239C AE040074 */   sw       $a0, 0x74($s0)
.L802423A0:
/* 7ED0B0 802423A0 C620000C */  lwc1      $f0, 0xc($s1)
/* 7ED0B4 802423A4 4602003C */  c.lt.s    $f0, $f2
/* 7ED0B8 802423A8 00000000 */  nop       
/* 7ED0BC 802423AC 45000003 */  bc1f      .L802423BC
/* 7ED0C0 802423B0 00000000 */   nop      
/* 7ED0C4 802423B4 AE000074 */  sw        $zero, 0x74($s0)
.L802423B8:
/* 7ED0C8 802423B8 24120001 */  addiu     $s2, $zero, 1
.L802423BC:
/* 7ED0CC 802423BC 12400005 */  beqz      $s2, .L802423D4
/* 7ED0D0 802423C0 00000000 */   nop      
/* 7ED0D4 802423C4 8E250010 */  lw        $a1, 0x10($s1)
/* 7ED0D8 802423C8 86060076 */  lh        $a2, 0x76($s0)
/* 7ED0DC 802423CC 0C052A95 */  jal       func_8014AA54
/* 7ED0E0 802423D0 0000202D */   daddu    $a0, $zero, $zero
.L802423D4:
/* 7ED0E4 802423D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7ED0E8 802423D8 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ED0EC 802423DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ED0F0 802423E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ED0F4 802423E4 0000102D */  daddu     $v0, $zero, $zero
/* 7ED0F8 802423E8 03E00008 */  jr        $ra
/* 7ED0FC 802423EC 27BD0020 */   addiu    $sp, $sp, 0x20
