.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422A0_A2C4E0
/* A2C4E0 802422A0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* A2C4E4 802422A4 AFB00018 */  sw        $s0, 0x18($sp)
/* A2C4E8 802422A8 0080802D */  daddu     $s0, $a0, $zero
/* A2C4EC 802422AC AFB1001C */  sw        $s1, 0x1c($sp)
/* A2C4F0 802422B0 00A0882D */  daddu     $s1, $a1, $zero
/* A2C4F4 802422B4 AFBF0028 */  sw        $ra, 0x28($sp)
/* A2C4F8 802422B8 AFB30024 */  sw        $s3, 0x24($sp)
/* A2C4FC 802422BC AFB20020 */  sw        $s2, 0x20($sp)
/* A2C500 802422C0 F7B60038 */  sdc1      $f22, 0x38($sp)
/* A2C504 802422C4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* A2C508 802422C8 0C0B36B0 */  jal       resolve_npc
/* A2C50C 802422CC 24050007 */   addiu    $a1, $zero, 7
/* A2C510 802422D0 0200202D */  daddu     $a0, $s0, $zero
/* A2C514 802422D4 24050008 */  addiu     $a1, $zero, 8
/* A2C518 802422D8 0C0B36B0 */  jal       resolve_npc
/* A2C51C 802422DC 0040902D */   daddu    $s2, $v0, $zero
/* A2C520 802422E0 12200007 */  beqz      $s1, .L80242300
/* A2C524 802422E4 0040982D */   daddu    $s3, $v0, $zero
/* A2C528 802422E8 C6400038 */  lwc1      $f0, 0x38($s2)
/* A2C52C 802422EC C6420040 */  lwc1      $f2, 0x40($s2)
/* A2C530 802422F0 3C018025 */  lui       $at, 0x8025
/* A2C534 802422F4 E420F2D8 */  swc1      $f0, -0xd28($at)
/* A2C538 802422F8 3C018025 */  lui       $at, 0x8025
/* A2C53C 802422FC E422F2DC */  swc1      $f2, -0xd24($at)
.L80242300:
/* A2C540 80242300 24040003 */  addiu     $a0, $zero, 3
/* A2C544 80242304 3C108025 */  lui       $s0, 0x8025
/* A2C548 80242308 26109A7C */  addiu     $s0, $s0, -0x6584
/* A2C54C 8024230C C6000000 */  lwc1      $f0, ($s0)
/* A2C550 80242310 46800020 */  cvt.s.w   $f0, $f0
/* A2C554 80242314 3C058025 */  lui       $a1, 0x8025
/* A2C558 80242318 8CA5F2D8 */  lw        $a1, -0xd28($a1)
/* A2C55C 8024231C 4480A000 */  mtc1      $zero, $f20
/* A2C560 80242320 44070000 */  mfc1      $a3, $f0
/* A2C564 80242324 3C014220 */  lui       $at, 0x4220
/* A2C568 80242328 4481B000 */  mtc1      $at, $f22
/* A2C56C 8024232C 4406A000 */  mfc1      $a2, $f20
/* A2C570 80242330 26420038 */  addiu     $v0, $s2, 0x38
/* A2C574 80242334 AFA20014 */  sw        $v0, 0x14($sp)
/* A2C578 80242338 0C090439 */  jal       func_802410E4_A2B324
/* A2C57C 8024233C E7B60010 */   swc1     $f22, 0x10($sp)
/* A2C580 80242340 C6000000 */  lwc1      $f0, ($s0)
/* A2C584 80242344 46800020 */  cvt.s.w   $f0, $f0
/* A2C588 80242348 24040003 */  addiu     $a0, $zero, 3
/* A2C58C 8024234C 3C058025 */  lui       $a1, 0x8025
/* A2C590 80242350 8CA5F2DC */  lw        $a1, -0xd24($a1)
/* A2C594 80242354 4406A000 */  mfc1      $a2, $f20
/* A2C598 80242358 44070000 */  mfc1      $a3, $f0
/* A2C59C 8024235C 26420040 */  addiu     $v0, $s2, 0x40
/* A2C5A0 80242360 E7B60010 */  swc1      $f22, 0x10($sp)
/* A2C5A4 80242364 0C090439 */  jal       func_802410E4_A2B324
/* A2C5A8 80242368 AFA20014 */   sw       $v0, 0x14($sp)
/* A2C5AC 8024236C C6400038 */  lwc1      $f0, 0x38($s2)
/* A2C5B0 80242370 E6600038 */  swc1      $f0, 0x38($s3)
/* A2C5B4 80242374 C6400040 */  lwc1      $f0, 0x40($s2)
/* A2C5B8 80242378 E6600040 */  swc1      $f0, 0x40($s3)
/* A2C5BC 8024237C C6400038 */  lwc1      $f0, 0x38($s2)
/* A2C5C0 80242380 8E030000 */  lw        $v1, ($s0)
/* A2C5C4 80242384 C6420040 */  lwc1      $f2, 0x40($s2)
/* A2C5C8 80242388 24630001 */  addiu     $v1, $v1, 1
/* A2C5CC 8024238C E640006C */  swc1      $f0, 0x6c($s2)
/* A2C5D0 80242390 E6420074 */  swc1      $f2, 0x74($s2)
/* A2C5D4 80242394 C6600038 */  lwc1      $f0, 0x38($s3)
/* A2C5D8 80242398 C6620040 */  lwc1      $f2, 0x40($s3)
/* A2C5DC 8024239C 28620029 */  slti      $v0, $v1, 0x29
/* A2C5E0 802423A0 AE030000 */  sw        $v1, ($s0)
/* A2C5E4 802423A4 E660006C */  swc1      $f0, 0x6c($s3)
/* A2C5E8 802423A8 E6620074 */  swc1      $f2, 0x74($s3)
/* A2C5EC 802423AC 8FBF0028 */  lw        $ra, 0x28($sp)
/* A2C5F0 802423B0 8FB30024 */  lw        $s3, 0x24($sp)
/* A2C5F4 802423B4 8FB20020 */  lw        $s2, 0x20($sp)
/* A2C5F8 802423B8 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2C5FC 802423BC 8FB00018 */  lw        $s0, 0x18($sp)
/* A2C600 802423C0 D7B60038 */  ldc1      $f22, 0x38($sp)
/* A2C604 802423C4 D7B40030 */  ldc1      $f20, 0x30($sp)
/* A2C608 802423C8 38420001 */  xori      $v0, $v0, 1
/* A2C60C 802423CC 03E00008 */  jr        $ra
/* A2C610 802423D0 27BD0040 */   addiu    $sp, $sp, 0x40
