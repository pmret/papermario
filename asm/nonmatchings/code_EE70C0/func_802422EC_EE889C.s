.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422EC_EE889C
/* EE889C 802422EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE88A0 802422F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* EE88A4 802422F4 8C82000C */  lw        $v0, 0xc($a0)
/* EE88A8 802422F8 0C0B53A3 */  jal       func_802D4E8C
/* EE88AC 802422FC 8C450000 */   lw       $a1, ($v0)
/* EE88B0 80242300 0040182D */  daddu     $v1, $v0, $zero
/* EE88B4 80242304 10600012 */  beqz      $v1, .L80242350
/* EE88B8 80242308 0000202D */   daddu    $a0, $zero, $zero
/* EE88BC 8024230C 8C620000 */  lw        $v0, ($v1)
/* EE88C0 80242310 5040000A */  beql      $v0, $zero, .L8024233C
/* EE88C4 80242314 00041080 */   sll      $v0, $a0, 2
/* EE88C8 80242318 3C058024 */  lui       $a1, %hi(D_802453E0_EEB990)
/* EE88CC 8024231C 24A553E0 */  addiu     $a1, $a1, %lo(D_802453E0_EEB990)
.L80242320:
/* EE88D0 80242320 24630004 */  addiu     $v1, $v1, 4
/* EE88D4 80242324 24840001 */  addiu     $a0, $a0, 1
/* EE88D8 80242328 ACA20000 */  sw        $v0, ($a1)
/* EE88DC 8024232C 8C620000 */  lw        $v0, ($v1)
/* EE88E0 80242330 1440FFFB */  bnez      $v0, .L80242320
/* EE88E4 80242334 24A50004 */   addiu    $a1, $a1, 4
/* EE88E8 80242338 00041080 */  sll       $v0, $a0, 2
.L8024233C:
/* EE88EC 8024233C 3C018024 */  lui       $at, %hi(D_802453E0_EEB990)
/* EE88F0 80242340 00220821 */  addu      $at, $at, $v0
/* EE88F4 80242344 AC2053E0 */  sw        $zero, %lo(D_802453E0_EEB990)($at)
/* EE88F8 80242348 080908DE */  j         .L80242378
/* EE88FC 8024234C 00000000 */   nop
.L80242350:
/* EE8900 80242350 3C038024 */  lui       $v1, %hi(D_802453E0_EEB990)
/* EE8904 80242354 246353E0 */  addiu     $v1, $v1, %lo(D_802453E0_EEB990)
/* EE8908 80242358 0060282D */  daddu     $a1, $v1, $zero
.L8024235C:
/* EE890C 8024235C 24820080 */  addiu     $v0, $a0, 0x80
/* EE8910 80242360 AC620000 */  sw        $v0, ($v1)
/* EE8914 80242364 24630004 */  addiu     $v1, $v1, 4
/* EE8918 80242368 24840001 */  addiu     $a0, $a0, 1
/* EE891C 8024236C 2882005B */  slti      $v0, $a0, 0x5b
/* EE8920 80242370 1440FFFA */  bnez      $v0, .L8024235C
/* EE8924 80242374 ACA0016C */   sw       $zero, 0x16c($a1)
.L80242378:
/* EE8928 80242378 8FBF0010 */  lw        $ra, 0x10($sp)
/* EE892C 8024237C 24020002 */  addiu     $v0, $zero, 2
/* EE8930 80242380 03E00008 */  jr        $ra
/* EE8934 80242384 27BD0018 */   addiu    $sp, $sp, 0x18
/* EE8938 80242388 00000000 */  nop
/* EE893C 8024238C 00000000 */  nop
