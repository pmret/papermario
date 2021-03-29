.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B62CC_E24BEC
/* E24BEC 802B62CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E24BF0 802B62D0 AFB1001C */  sw        $s1, 0x1c($sp)
/* E24BF4 802B62D4 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* E24BF8 802B62D8 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* E24BFC 802B62DC AFB00018 */  sw        $s0, 0x18($sp)
/* E24C00 802B62E0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24C04 802B62E4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24C08 802B62E8 AFBF0024 */  sw        $ra, 0x24($sp)
/* E24C0C 802B62EC AFB20020 */  sw        $s2, 0x20($sp)
/* E24C10 802B62F0 8E030000 */  lw        $v1, ($s0)
/* E24C14 802B62F4 0461001A */  bgez      $v1, .L802B6360
/* E24C18 802B62F8 0220902D */   daddu    $s2, $s1, $zero
/* E24C1C 802B62FC 3C027FFF */  lui       $v0, 0x7fff
/* E24C20 802B6300 3442FFFF */  ori       $v0, $v0, 0xffff
/* E24C24 802B6304 24040148 */  addiu     $a0, $zero, 0x148
/* E24C28 802B6308 0000282D */  daddu     $a1, $zero, $zero
/* E24C2C 802B630C 00621024 */  and       $v0, $v1, $v0
/* E24C30 802B6310 C6000028 */  lwc1      $f0, 0x28($s0)
/* E24C34 802B6314 C6020030 */  lwc1      $f2, 0x30($s0)
/* E24C38 802B6318 2403FFF1 */  addiu     $v1, $zero, -0xf
/* E24C3C 802B631C AE020000 */  sw        $v0, ($s0)
/* E24C40 802B6320 00431024 */  and       $v0, $v0, $v1
/* E24C44 802B6324 A20000B6 */  sb        $zero, 0xb6($s0)
/* E24C48 802B6328 A60000C0 */  sh        $zero, 0xc0($s0)
/* E24C4C 802B632C A60000C2 */  sh        $zero, 0xc2($s0)
/* E24C50 802B6330 AE020000 */  sw        $v0, ($s0)
/* E24C54 802B6334 E6000044 */  swc1      $f0, 0x44($s0)
/* E24C58 802B6338 0C052736 */  jal       sfx_play_sound_at_player
/* E24C5C 802B633C E6020048 */   swc1     $f2, 0x48($s0)
/* E24C60 802B6340 96220002 */  lhu       $v0, 2($s1)
/* E24C64 802B6344 30424000 */  andi      $v0, $v0, 0x4000
/* E24C68 802B6348 14400004 */  bnez      $v0, .L802B635C
/* E24C6C 802B634C 2402FFFF */   addiu    $v0, $zero, -1
/* E24C70 802B6350 0C03954C */  jal       func_800E5530
/* E24C74 802B6354 00000000 */   nop
/* E24C78 802B6358 2402FFFF */  addiu     $v0, $zero, -1
.L802B635C:
/* E24C7C 802B635C A6420004 */  sh        $v0, 4($s2)
.L802B6360:
/* E24C80 802B6360 C6000054 */  lwc1      $f0, 0x54($s0)
/* E24C84 802B6364 3C013F19 */  lui       $at, 0x3f19
/* E24C88 802B6368 3421999A */  ori       $at, $at, 0x999a
/* E24C8C 802B636C 44811000 */  mtc1      $at, $f2
/* E24C90 802B6370 27A40010 */  addiu     $a0, $sp, 0x10
/* E24C94 802B6374 46020002 */  mul.s     $f0, $f0, $f2
/* E24C98 802B6378 00000000 */  nop
/* E24C9C 802B637C 920200B6 */  lbu       $v0, 0xb6($s0)
/* E24CA0 802B6380 27A50014 */  addiu     $a1, $sp, 0x14
/* E24CA4 802B6384 24420001 */  addiu     $v0, $v0, 1
/* E24CA8 802B6388 A20200B6 */  sb        $v0, 0xb6($s0)
/* E24CAC 802B638C 0C0388C1 */  jal       input_to_move_vector
/* E24CB0 802B6390 E6000054 */   swc1     $f0, 0x54($s0)
/* E24CB4 802B6394 C7A00014 */  lwc1      $f0, 0x14($sp)
/* E24CB8 802B6398 44801000 */  mtc1      $zero, $f2
/* E24CBC 802B639C 00000000 */  nop
/* E24CC0 802B63A0 46020032 */  c.eq.s    $f0, $f2
/* E24CC4 802B63A4 00000000 */  nop
/* E24CC8 802B63A8 45010020 */  bc1t      .L802B642C
/* E24CCC 802B63AC 0000202D */   daddu    $a0, $zero, $zero
/* E24CD0 802B63B0 45010003 */  bc1t      .L802B63C0
/* E24CD4 802B63B4 00000000 */   nop
/* E24CD8 802B63B8 C7A00010 */  lwc1      $f0, 0x10($sp)
/* E24CDC 802B63BC E6000080 */  swc1      $f0, 0x80($s0)
.L802B63C0:
/* E24CE0 802B63C0 8E0200E8 */  lw        $v0, 0xe8($s0)
/* E24CE4 802B63C4 00420018 */  mult      $v0, $v0
/* E24CE8 802B63C8 00001812 */  mflo      $v1
/* E24CEC 802B63CC 8E0200EC */  lw        $v0, 0xec($s0)
/* E24CF0 802B63D0 00000000 */  nop
/* E24CF4 802B63D4 00420018 */  mult      $v0, $v0
/* E24CF8 802B63D8 00003812 */  mflo      $a3
/* E24CFC 802B63DC 00671021 */  addu      $v0, $v1, $a3
/* E24D00 802B63E0 44826000 */  mtc1      $v0, $f12
/* E24D04 802B63E4 00000000 */  nop
/* E24D08 802B63E8 46806320 */  cvt.s.w   $f12, $f12
/* E24D0C 802B63EC 46006084 */  sqrt.s    $f2, $f12
/* E24D10 802B63F0 46021032 */  c.eq.s    $f2, $f2
/* E24D14 802B63F4 00000000 */  nop
/* E24D18 802B63F8 45010004 */  bc1t      .L802B640C
/* E24D1C 802B63FC 00000000 */   nop
/* E24D20 802B6400 0C0187BC */  jal       sqrtf
/* E24D24 802B6404 00000000 */   nop
/* E24D28 802B6408 46000086 */  mov.s     $f2, $f0
.L802B640C:
/* E24D2C 802B640C 3C01425C */  lui       $at, 0x425c
/* E24D30 802B6410 44810000 */  mtc1      $at, $f0
/* E24D34 802B6414 00000000 */  nop
/* E24D38 802B6418 4602003C */  c.lt.s    $f0, $f2
/* E24D3C 802B641C 00000000 */  nop
/* E24D40 802B6420 45000002 */  bc1f      .L802B642C
/* E24D44 802B6424 24040001 */   addiu    $a0, $zero, 1
/* E24D48 802B6428 24040002 */  addiu     $a0, $zero, 2
.L802B642C:
/* E24D4C 802B642C 0C039769 */  jal       set_action_state
/* E24D50 802B6430 00000000 */   nop
/* E24D54 802B6434 8FBF0024 */  lw        $ra, 0x24($sp)
/* E24D58 802B6438 8FB20020 */  lw        $s2, 0x20($sp)
/* E24D5C 802B643C 8FB1001C */  lw        $s1, 0x1c($sp)
/* E24D60 802B6440 8FB00018 */  lw        $s0, 0x18($sp)
/* E24D64 802B6444 03E00008 */  jr        $ra
/* E24D68 802B6448 27BD0028 */   addiu    $sp, $sp, 0x28
