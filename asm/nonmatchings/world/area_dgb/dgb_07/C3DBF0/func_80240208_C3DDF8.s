.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240208_C3DDF8
/* C3DDF8 80240208 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C3DDFC 8024020C AFBF0024 */  sw        $ra, 0x24($sp)
/* C3DE00 80240210 AFB40020 */  sw        $s4, 0x20($sp)
/* C3DE04 80240214 AFB3001C */  sw        $s3, 0x1c($sp)
/* C3DE08 80240218 AFB20018 */  sw        $s2, 0x18($sp)
/* C3DE0C 8024021C AFB10014 */  sw        $s1, 0x14($sp)
/* C3DE10 80240220 AFB00010 */  sw        $s0, 0x10($sp)
/* C3DE14 80240224 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C3DE18 80240228 8C900148 */  lw        $s0, 0x148($a0)
/* C3DE1C 8024022C 86040008 */  lh        $a0, 8($s0)
/* C3DE20 80240230 0C00EABB */  jal       get_npc_unsafe
/* C3DE24 80240234 24110001 */   addiu    $s1, $zero, 1
/* C3DE28 80240238 86040008 */  lh        $a0, 8($s0)
/* C3DE2C 8024023C 0040802D */  daddu     $s0, $v0, $zero
/* C3DE30 80240240 3C05800B */  lui       $a1, %hi(gCameras)
/* C3DE34 80240244 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* C3DE38 80240248 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C3DE3C 8024024C 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C3DE40 80240250 00912021 */  addu      $a0, $a0, $s1
/* C3DE44 80240254 00031080 */  sll       $v0, $v1, 2
/* C3DE48 80240258 00431021 */  addu      $v0, $v0, $v1
/* C3DE4C 8024025C 00021080 */  sll       $v0, $v0, 2
/* C3DE50 80240260 00431023 */  subu      $v0, $v0, $v1
/* C3DE54 80240264 000218C0 */  sll       $v1, $v0, 3
/* C3DE58 80240268 00431021 */  addu      $v0, $v0, $v1
/* C3DE5C 8024026C 000210C0 */  sll       $v0, $v0, 3
/* C3DE60 80240270 0C00FB3A */  jal       get_enemy
/* C3DE64 80240274 00459021 */   addu     $s2, $v0, $a1
/* C3DE68 80240278 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* C3DE6C 8024027C 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* C3DE70 80240280 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3DE74 80240284 8E830000 */  lw        $v1, ($s4)
/* C3DE78 80240288 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3DE7C 8024028C 8C660028 */  lw        $a2, 0x28($v1)
/* C3DE80 80240290 8C670030 */  lw        $a3, 0x30($v1)
/* C3DE84 80240294 0C00A7B5 */  jal       dist2D
/* C3DE88 80240298 0040982D */   daddu    $s3, $v0, $zero
/* C3DE8C 8024029C C6620074 */  lwc1      $f2, 0x74($s3)
/* C3DE90 802402A0 468010A0 */  cvt.s.w   $f2, $f2
/* C3DE94 802402A4 4600103C */  c.lt.s    $f2, $f0
/* C3DE98 802402A8 00000000 */  nop
/* C3DE9C 802402AC 45030001 */  bc1tl     .L802402B4
/* C3DEA0 802402B0 0000882D */   daddu    $s1, $zero, $zero
.L802402B4:
/* C3DEA4 802402B4 C64C006C */  lwc1      $f12, 0x6c($s2)
/* C3DEA8 802402B8 C60E000C */  lwc1      $f14, 0xc($s0)
/* C3DEAC 802402BC 3C014387 */  lui       $at, 0x4387
/* C3DEB0 802402C0 4481A000 */  mtc1      $at, $f20
/* C3DEB4 802402C4 0C00A70A */  jal       get_clamped_angle_diff
/* C3DEB8 802402C8 00000000 */   nop
/* C3DEBC 802402CC 0C00A6C9 */  jal       clamp_angle
/* C3DEC0 802402D0 46000306 */   mov.s    $f12, $f0
/* C3DEC4 802402D4 3C018024 */  lui       $at, %hi(D_80241E90_C3FA80)
/* C3DEC8 802402D8 D4221E90 */  ldc1      $f2, %lo(D_80241E90_C3FA80)($at)
/* C3DECC 802402DC 46000021 */  cvt.d.s   $f0, $f0
/* C3DED0 802402E0 4622003C */  c.lt.d    $f0, $f2
/* C3DED4 802402E4 00000000 */  nop
/* C3DED8 802402E8 45000003 */  bc1f      .L802402F8
/* C3DEDC 802402EC 00000000 */   nop
/* C3DEE0 802402F0 3C0142B4 */  lui       $at, 0x42b4
/* C3DEE4 802402F4 4481A000 */  mtc1      $at, $f20
.L802402F8:
/* C3DEE8 802402F8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C3DEEC 802402FC 8E820000 */  lw        $v0, ($s4)
/* C3DEF0 80240300 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C3DEF4 80240304 8C460028 */  lw        $a2, 0x28($v0)
/* C3DEF8 80240308 0C00A720 */  jal       atan2
/* C3DEFC 8024030C 8C470030 */   lw       $a3, 0x30($v0)
/* C3DF00 80240310 4600A306 */  mov.s     $f12, $f20
/* C3DF04 80240314 0C00A70A */  jal       get_clamped_angle_diff
/* C3DF08 80240318 46000386 */   mov.s    $f14, $f0
/* C3DF0C 8024031C C6620078 */  lwc1      $f2, 0x78($s3)
/* C3DF10 80240320 468010A0 */  cvt.s.w   $f2, $f2
/* C3DF14 80240324 46000005 */  abs.s     $f0, $f0
/* C3DF18 80240328 4600103C */  c.lt.s    $f2, $f0
/* C3DF1C 8024032C 00000000 */  nop
/* C3DF20 80240330 45030001 */  bc1tl     .L80240338
/* C3DF24 80240334 0000882D */   daddu    $s1, $zero, $zero
.L80240338:
/* C3DF28 80240338 8E820000 */  lw        $v0, ($s4)
/* C3DF2C 8024033C C600003C */  lwc1      $f0, 0x3c($s0)
/* C3DF30 80240340 C442002C */  lwc1      $f2, 0x2c($v0)
/* C3DF34 80240344 860200A8 */  lh        $v0, 0xa8($s0)
/* C3DF38 80240348 46020001 */  sub.s     $f0, $f0, $f2
/* C3DF3C 8024034C 44821000 */  mtc1      $v0, $f2
/* C3DF40 80240350 00000000 */  nop
/* C3DF44 80240354 468010A1 */  cvt.d.w   $f2, $f2
/* C3DF48 80240358 46221080 */  add.d     $f2, $f2, $f2
/* C3DF4C 8024035C 46000005 */  abs.s     $f0, $f0
/* C3DF50 80240360 46000021 */  cvt.d.s   $f0, $f0
/* C3DF54 80240364 4620103E */  c.le.d    $f2, $f0
/* C3DF58 80240368 00000000 */  nop
/* C3DF5C 8024036C 45030001 */  bc1tl     .L80240374
/* C3DF60 80240370 0000882D */   daddu    $s1, $zero, $zero
.L80240374:
/* C3DF64 80240374 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* C3DF68 80240378 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* C3DF6C 8024037C 24020009 */  addiu     $v0, $zero, 9
/* C3DF70 80240380 50620001 */  beql      $v1, $v0, .L80240388
/* C3DF74 80240384 0000882D */   daddu    $s1, $zero, $zero
.L80240388:
/* C3DF78 80240388 24020007 */  addiu     $v0, $zero, 7
/* C3DF7C 8024038C 50620001 */  beql      $v1, $v0, .L80240394
/* C3DF80 80240390 0000882D */   daddu    $s1, $zero, $zero
.L80240394:
/* C3DF84 80240394 0220102D */  daddu     $v0, $s1, $zero
/* C3DF88 80240398 8FBF0024 */  lw        $ra, 0x24($sp)
/* C3DF8C 8024039C 8FB40020 */  lw        $s4, 0x20($sp)
/* C3DF90 802403A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C3DF94 802403A4 8FB20018 */  lw        $s2, 0x18($sp)
/* C3DF98 802403A8 8FB10014 */  lw        $s1, 0x14($sp)
/* C3DF9C 802403AC 8FB00010 */  lw        $s0, 0x10($sp)
/* C3DFA0 802403B0 D7B40028 */  ldc1      $f20, 0x28($sp)
/* C3DFA4 802403B4 03E00008 */  jr        $ra
/* C3DFA8 802403B8 27BD0030 */   addiu    $sp, $sp, 0x30
