.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802EB298
.double 0.1

glabel D_802EB2A0
.double 0.02, 0.0

.section .text

glabel entity_HeartBlockContent_anim_beating
/* 106BA4 802E5324 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 106BA8 802E5328 AFB10014 */  sw        $s1, 0x14($sp)
/* 106BAC 802E532C 0080882D */  daddu     $s1, $a0, $zero
/* 106BB0 802E5330 AFBF0018 */  sw        $ra, 0x18($sp)
/* 106BB4 802E5334 AFB00010 */  sw        $s0, 0x10($sp)
/* 106BB8 802E5338 0C0B92C4 */  jal       entity_HeartBlockContent_set_initial_pos
/* 106BBC 802E533C 8E300040 */   lw       $s0, 0x40($s1)
/* 106BC0 802E5340 C6200054 */  lwc1      $f0, 0x54($s1)
/* 106BC4 802E5344 3C013FF0 */  lui       $at, 0x3ff0
/* 106BC8 802E5348 44812800 */  mtc1      $at, $f5
/* 106BCC 802E534C 44802000 */  mtc1      $zero, $f4
/* 106BD0 802E5350 460000A1 */  cvt.d.s   $f2, $f0
/* 106BD4 802E5354 4624103C */  c.lt.d    $f2, $f4
/* 106BD8 802E5358 00000000 */  nop
/* 106BDC 802E535C 45010026 */  bc1t      .L802E53F8
/* 106BE0 802E5360 24020001 */   addiu    $v0, $zero, 1
/* 106BE4 802E5364 92030008 */  lbu       $v1, 8($s0)
/* 106BE8 802E5368 10620010 */  beq       $v1, $v0, .L802E53AC
/* 106BEC 802E536C 28620002 */   slti     $v0, $v1, 2
/* 106BF0 802E5370 50400005 */  beql      $v0, $zero, .L802E5388
/* 106BF4 802E5374 28620011 */   slti     $v0, $v1, 0x11
/* 106BF8 802E5378 10600007 */  beqz      $v1, .L802E5398
/* 106BFC 802E537C 00000000 */   nop
/* 106C00 802E5380 080B94FC */  j         .L802E53F0
/* 106C04 802E5384 A2000008 */   sb       $zero, 8($s0)
.L802E5388:
/* 106C08 802E5388 50400019 */  beql      $v0, $zero, .L802E53F0
/* 106C0C 802E538C A2000008 */   sb       $zero, 8($s0)
/* 106C10 802E5390 080B94F9 */  j         .L802E53E4
/* 106C14 802E5394 00000000 */   nop
.L802E5398:
/* 106C18 802E5398 3C01802F */  lui       $at, %hi(D_802EB298)
/* 106C1C 802E539C D420B298 */  ldc1      $f0, %lo(D_802EB298)($at)
/* 106C20 802E53A0 46201000 */  add.d     $f0, $f2, $f0
/* 106C24 802E53A4 080B94F8 */  j         .L802E53E0
/* 106C28 802E53A8 46200020 */   cvt.s.d  $f0, $f0
.L802E53AC:
/* 106C2C 802E53AC 3C01802F */  lui       $at, %hi(D_802EB2A0)
/* 106C30 802E53B0 D420B2A0 */  ldc1      $f0, %lo(D_802EB2A0)($at)
/* 106C34 802E53B4 46201001 */  sub.d     $f0, $f2, $f0
/* 106C38 802E53B8 46200020 */  cvt.s.d   $f0, $f0
/* 106C3C 802E53BC E6200054 */  swc1      $f0, 0x54($s1)
/* 106C40 802E53C0 46000021 */  cvt.d.s   $f0, $f0
/* 106C44 802E53C4 4624003E */  c.le.d    $f0, $f4
/* 106C48 802E53C8 00000000 */  nop
/* 106C4C 802E53CC 45000008 */  bc1f      .L802E53F0
/* 106C50 802E53D0 00000000 */   nop
/* 106C54 802E53D4 3C013F80 */  lui       $at, 0x3f80
/* 106C58 802E53D8 44810000 */  mtc1      $at, $f0
/* 106C5C 802E53DC 00000000 */  nop
.L802E53E0:
/* 106C60 802E53E0 E6200054 */  swc1      $f0, 0x54($s1)
.L802E53E4:
/* 106C64 802E53E4 92020008 */  lbu       $v0, 8($s0)
/* 106C68 802E53E8 24420001 */  addiu     $v0, $v0, 1
/* 106C6C 802E53EC A2020008 */  sb        $v0, 8($s0)
.L802E53F0:
/* 106C70 802E53F0 C6200054 */  lwc1      $f0, 0x54($s1)
/* 106C74 802E53F4 E6200058 */  swc1      $f0, 0x58($s1)
.L802E53F8:
/* 106C78 802E53F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 106C7C 802E53FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 106C80 802E5400 8FB00010 */  lw        $s0, 0x10($sp)
/* 106C84 802E5404 03E00008 */  jr        $ra
/* 106C88 802E5408 27BD0020 */   addiu    $sp, $sp, 0x20
