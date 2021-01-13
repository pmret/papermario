.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802434F4_9AB8E4
/* 9AB8E4 802434F4 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 9AB8E8 802434F8 AFB20030 */  sw        $s2, 0x30($sp)
/* 9AB8EC 802434FC 0080902D */  daddu     $s2, $a0, $zero
/* 9AB8F0 80243500 AFBF0034 */  sw        $ra, 0x34($sp)
/* 9AB8F4 80243504 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9AB8F8 80243508 AFB00028 */  sw        $s0, 0x28($sp)
/* 9AB8FC 8024350C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 9AB900 80243510 8E510148 */  lw        $s1, 0x148($s2)
/* 9AB904 80243514 0C00EABB */  jal       get_npc_unsafe
/* 9AB908 80243518 86240008 */   lh       $a0, 8($s1)
/* 9AB90C 8024351C 0040802D */  daddu     $s0, $v0, $zero
/* 9AB910 80243520 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9AB914 80243524 C6000014 */  lwc1      $f0, 0x14($s0)
/* 9AB918 80243528 0200202D */  daddu     $a0, $s0, $zero
/* 9AB91C 8024352C 46002100 */  add.s     $f4, $f4, $f0
/* 9AB920 80243530 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9AB924 80243534 8E050018 */  lw        $a1, 0x18($s0)
/* 9AB928 80243538 46041080 */  add.s     $f2, $f2, $f4
/* 9AB92C 8024353C 8E06000C */  lw        $a2, 0xc($s0)
/* 9AB930 80243540 C6200078 */  lwc1      $f0, 0x78($s1)
/* 9AB934 80243544 46800020 */  cvt.s.w   $f0, $f0
/* 9AB938 80243548 E602003C */  swc1      $f2, 0x3c($s0)
/* 9AB93C 8024354C 3C014059 */  lui       $at, 0x4059
/* 9AB940 80243550 44811800 */  mtc1      $at, $f3
/* 9AB944 80243554 44801000 */  mtc1      $zero, $f2
/* 9AB948 80243558 46000021 */  cvt.d.s   $f0, $f0
/* 9AB94C 8024355C E604001C */  swc1      $f4, 0x1c($s0)
/* 9AB950 80243560 46220003 */  div.d     $f0, $f0, $f2
/* 9AB954 80243564 0C00EA95 */  jal       npc_move_heading
/* 9AB958 80243568 46200520 */   cvt.s.d  $f20, $f0
/* 9AB95C 8024356C 27A50018 */  addiu     $a1, $sp, 0x18
/* 9AB960 80243570 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9AB964 80243574 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9AB968 80243578 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9AB96C 8024357C C6040040 */  lwc1      $f4, 0x40($s0)
/* 9AB970 80243580 3C01447A */  lui       $at, 0x447a
/* 9AB974 80243584 44813000 */  mtc1      $at, $f6
/* 9AB978 80243588 27A20024 */  addiu     $v0, $sp, 0x24
/* 9AB97C 8024358C E7A00018 */  swc1      $f0, 0x18($sp)
/* 9AB980 80243590 E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9AB984 80243594 E7A40020 */  swc1      $f4, 0x20($sp)
/* 9AB988 80243598 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9AB98C 8024359C AFA20010 */  sw        $v0, 0x10($sp)
/* 9AB990 802435A0 8E040080 */  lw        $a0, 0x80($s0)
/* 9AB994 802435A4 0C0372DF */  jal       func_800DCB7C
/* 9AB998 802435A8 27A70020 */   addiu    $a3, $sp, 0x20
/* 9AB99C 802435AC 10400003 */  beqz      $v0, .L802435BC
/* 9AB9A0 802435B0 4600A086 */   mov.s    $f2, $f20
/* 9AB9A4 802435B4 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9AB9A8 802435B8 46140080 */  add.s     $f2, $f0, $f20
.L802435BC:
/* 9AB9AC 802435BC C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AB9B0 802435C0 4602003C */  c.lt.s    $f0, $f2
/* 9AB9B4 802435C4 00000000 */  nop
/* 9AB9B8 802435C8 45010009 */  bc1t      .L802435F0
/* 9AB9BC 802435CC 2402000A */   addiu    $v0, $zero, 0xa
/* 9AB9C0 802435D0 A602008E */  sh        $v0, 0x8e($s0)
/* 9AB9C4 802435D4 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9AB9C8 802435D8 8C42002C */  lw        $v0, 0x2c($v0)
/* 9AB9CC 802435DC AE020028 */  sw        $v0, 0x28($s0)
/* 9AB9D0 802435E0 9622008E */  lhu       $v0, 0x8e($s1)
/* 9AB9D4 802435E4 A60200A8 */  sh        $v0, 0xa8($s0)
/* 9AB9D8 802435E8 2402000F */  addiu     $v0, $zero, 0xf
/* 9AB9DC 802435EC AE420070 */  sw        $v0, 0x70($s2)
.L802435F0:
/* 9AB9E0 802435F0 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9AB9E4 802435F4 8FB20030 */  lw        $s2, 0x30($sp)
/* 9AB9E8 802435F8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9AB9EC 802435FC 8FB00028 */  lw        $s0, 0x28($sp)
/* 9AB9F0 80243600 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 9AB9F4 80243604 03E00008 */  jr        $ra
/* 9AB9F8 80243608 27BD0040 */   addiu    $sp, $sp, 0x40
