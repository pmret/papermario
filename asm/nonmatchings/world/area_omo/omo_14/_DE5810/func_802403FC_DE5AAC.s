.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403FC_DE5AAC
/* DE5AAC 802403FC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DE5AB0 80240400 AFB10014 */  sw        $s1, 0x14($sp)
/* DE5AB4 80240404 0080882D */  daddu     $s1, $a0, $zero
/* DE5AB8 80240408 AFBF001C */  sw        $ra, 0x1c($sp)
/* DE5ABC 8024040C AFB20018 */  sw        $s2, 0x18($sp)
/* DE5AC0 80240410 AFB00010 */  sw        $s0, 0x10($sp)
/* DE5AC4 80240414 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DE5AC8 80240418 F7B40020 */  sdc1      $f20, 0x20($sp)
/* DE5ACC 8024041C 8E220148 */  lw        $v0, 0x148($s1)
/* DE5AD0 80240420 84440008 */  lh        $a0, 8($v0)
/* DE5AD4 80240424 0C00EABB */  jal       get_npc_unsafe
/* DE5AD8 80240428 8E30000C */   lw       $s0, 0xc($s1)
/* DE5ADC 8024042C 8E050000 */  lw        $a1, ($s0)
/* DE5AE0 80240430 26100004 */  addiu     $s0, $s0, 4
/* DE5AE4 80240434 0220202D */  daddu     $a0, $s1, $zero
/* DE5AE8 80240438 0C0B210B */  jal       get_float_variable
/* DE5AEC 8024043C 0040902D */   daddu    $s2, $v0, $zero
/* DE5AF0 80240440 0220202D */  daddu     $a0, $s1, $zero
/* DE5AF4 80240444 8E050000 */  lw        $a1, ($s0)
/* DE5AF8 80240448 0C0B210B */  jal       get_float_variable
/* DE5AFC 8024044C 46000586 */   mov.s    $f22, $f0
/* DE5B00 80240450 46000506 */  mov.s     $f20, $f0
/* DE5B04 80240454 C64C0038 */  lwc1      $f12, 0x38($s2)
/* DE5B08 80240458 C64E0040 */  lwc1      $f14, 0x40($s2)
/* DE5B0C 8024045C 4406B000 */  mfc1      $a2, $f22
/* DE5B10 80240460 4407A000 */  mfc1      $a3, $f20
/* DE5B14 80240464 0C00A7B5 */  jal       dist2D
/* DE5B18 80240468 00000000 */   nop      
/* DE5B1C 8024046C C6420018 */  lwc1      $f2, 0x18($s2)
/* DE5B20 80240470 4600103C */  c.lt.s    $f2, $f0
/* DE5B24 80240474 00000000 */  nop       
/* DE5B28 80240478 45000031 */  bc1f      .L80240540
/* DE5B2C 8024047C 00000000 */   nop      
/* DE5B30 80240480 8E420000 */  lw        $v0, ($s2)
/* DE5B34 80240484 30422000 */  andi      $v0, $v0, 0x2000
/* DE5B38 80240488 10400022 */  beqz      $v0, .L80240514
/* DE5B3C 8024048C 00000000 */   nop      
/* DE5B40 80240490 C642000C */  lwc1      $f2, 0xc($s2)
/* DE5B44 80240494 3C014334 */  lui       $at, 0x4334
/* DE5B48 80240498 44810000 */  mtc1      $at, $f0
/* DE5B4C 8024049C 00000000 */  nop       
/* DE5B50 802404A0 4600103C */  c.lt.s    $f2, $f0
/* DE5B54 802404A4 00000000 */  nop       
/* DE5B58 802404A8 4500000D */  bc1f      .L802404E0
/* DE5B5C 802404AC 00000000 */   nop      
/* DE5B60 802404B0 C6420040 */  lwc1      $f2, 0x40($s2)
/* DE5B64 802404B4 44800000 */  mtc1      $zero, $f0
/* DE5B68 802404B8 3C014307 */  lui       $at, 0x4307
/* DE5B6C 802404BC 44812000 */  mtc1      $at, $f4
/* DE5B70 802404C0 4602003C */  c.lt.s    $f0, $f2
/* DE5B74 802404C4 00000000 */  nop       
/* DE5B78 802404C8 45020019 */  bc1fl     .L80240530
/* DE5B7C 802404CC E644000C */   swc1     $f4, 0xc($s2)
/* DE5B80 802404D0 3C014234 */  lui       $at, 0x4234
/* DE5B84 802404D4 44812000 */  mtc1      $at, $f4
/* DE5B88 802404D8 0809014C */  j         .L80240530
/* DE5B8C 802404DC E644000C */   swc1     $f4, 0xc($s2)
.L802404E0:
/* DE5B90 802404E0 C6420040 */  lwc1      $f2, 0x40($s2)
/* DE5B94 802404E4 44800000 */  mtc1      $zero, $f0
/* DE5B98 802404E8 3C014361 */  lui       $at, 0x4361
/* DE5B9C 802404EC 44812000 */  mtc1      $at, $f4
/* DE5BA0 802404F0 4602003C */  c.lt.s    $f0, $f2
/* DE5BA4 802404F4 00000000 */  nop       
/* DE5BA8 802404F8 4502000D */  bc1fl     .L80240530
/* DE5BAC 802404FC E644000C */   swc1     $f4, 0xc($s2)
/* DE5BB0 80240500 3C01439D */  lui       $at, 0x439d
/* DE5BB4 80240504 34218000 */  ori       $at, $at, 0x8000
/* DE5BB8 80240508 44812000 */  mtc1      $at, $f4
/* DE5BBC 8024050C 0809014C */  j         .L80240530
/* DE5BC0 80240510 E644000C */   swc1     $f4, 0xc($s2)
.L80240514:
/* DE5BC4 80240514 C64C0038 */  lwc1      $f12, 0x38($s2)
/* DE5BC8 80240518 C64E0040 */  lwc1      $f14, 0x40($s2)
/* DE5BCC 8024051C 4406B000 */  mfc1      $a2, $f22
/* DE5BD0 80240520 4407A000 */  mfc1      $a3, $f20
/* DE5BD4 80240524 0C00A720 */  jal       atan2
/* DE5BD8 80240528 00000000 */   nop      
/* DE5BDC 8024052C E640000C */  swc1      $f0, 0xc($s2)
.L80240530:
/* DE5BE0 80240530 8E450018 */  lw        $a1, 0x18($s2)
/* DE5BE4 80240534 8E46000C */  lw        $a2, 0xc($s2)
/* DE5BE8 80240538 0C00EA95 */  jal       npc_move_heading
/* DE5BEC 8024053C 0240202D */   daddu    $a0, $s2, $zero
.L80240540:
/* DE5BF0 80240540 8FBF001C */  lw        $ra, 0x1c($sp)
/* DE5BF4 80240544 8FB20018 */  lw        $s2, 0x18($sp)
/* DE5BF8 80240548 8FB10014 */  lw        $s1, 0x14($sp)
/* DE5BFC 8024054C 8FB00010 */  lw        $s0, 0x10($sp)
/* DE5C00 80240550 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DE5C04 80240554 D7B40020 */  ldc1      $f20, 0x20($sp)
/* DE5C08 80240558 24020002 */  addiu     $v0, $zero, 2
/* DE5C0C 8024055C 03E00008 */  jr        $ra
/* DE5C10 80240560 27BD0030 */   addiu    $sp, $sp, 0x30
