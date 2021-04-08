.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802BCF50_E2D680
.word L802BB224_E2B954, L802BB24C_E2B97C, L802BB2CC_E2B9FC, L802BB398_E2BAC8, L802BB440_E2BB70, L802BB468_E2BB98, L802BB4E0_E2BC10, L802BB56C_E2BC9C, L802BB5A0_E2BCD0, 0

glabel D_802BCF78_E2D6A8
.double 0.2

glabel D_802BCF80_E2D6B0
.double 0.2

glabel D_802BCF88_E2D6B8
.double 90.0

glabel D_802BCF90_E2D6C0
.double 90.0, 0.0

.section .text

glabel func_802BB1E8_E2B918
/* E2B918 802BB1E8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E2B91C 802BB1EC AFB1001C */  sw        $s1, 0x1c($sp)
/* E2B920 802BB1F0 0080882D */  daddu     $s1, $a0, $zero
/* E2B924 802BB1F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* E2B928 802BB1F8 AFB00018 */  sw        $s0, 0x18($sp)
/* E2B92C 802BB1FC 8E300040 */  lw        $s0, 0x40($s1)
/* E2B930 802BB200 82030012 */  lb        $v1, 0x12($s0)
/* E2B934 802BB204 2C620009 */  sltiu     $v0, $v1, 9
/* E2B938 802BB208 104000F2 */  beqz      $v0, .L802BB5D4
/* E2B93C 802BB20C 00031080 */   sll      $v0, $v1, 2
/* E2B940 802BB210 3C01802C */  lui       $at, %hi(jtbl_802BCF50_E2D680)
/* E2B944 802BB214 00220821 */  addu      $at, $at, $v0
/* E2B948 802BB218 8C22CF50 */  lw        $v0, %lo(jtbl_802BCF50_E2D680)($at)
/* E2B94C 802BB21C 00400008 */  jr        $v0
/* E2B950 802BB220 00000000 */   nop
glabel L802BB224_E2B954
/* E2B954 802BB224 0C0AEC11 */  jal       func_802BB044_E2B774
/* E2B958 802BB228 0220202D */   daddu    $a0, $s1, $zero
/* E2B95C 802BB22C 8E220000 */  lw        $v0, ($s1)
/* E2B960 802BB230 3C030010 */  lui       $v1, 0x10
/* E2B964 802BB234 00431024 */  and       $v0, $v0, $v1
/* E2B968 802BB238 104000E6 */  beqz      $v0, .L802BB5D4
/* E2B96C 802BB23C 24040269 */   addiu    $a0, $zero, 0x269
/* E2B970 802BB240 92020012 */  lbu       $v0, 0x12($s0)
/* E2B974 802BB244 080AED57 */  j         .L802BB55C
/* E2B978 802BB248 24420001 */   addiu    $v0, $v0, 1
glabel L802BB24C_E2B97C
/* E2B97C 802BB24C C6000004 */  lwc1      $f0, 4($s0)
/* E2B980 802BB250 3C0140A0 */  lui       $at, 0x40a0
/* E2B984 802BB254 44811000 */  mtc1      $at, $f2
/* E2B988 802BB258 00000000 */  nop
/* E2B98C 802BB25C 46020000 */  add.s     $f0, $f0, $f2
/* E2B990 802BB260 3C0141A0 */  lui       $at, 0x41a0
/* E2B994 802BB264 44811000 */  mtc1      $at, $f2
/* E2B998 802BB268 00000000 */  nop
/* E2B99C 802BB26C 4600103E */  c.le.s    $f2, $f0
/* E2B9A0 802BB270 00000000 */  nop
/* E2B9A4 802BB274 450000D7 */  bc1f      .L802BB5D4
/* E2B9A8 802BB278 E6000004 */   swc1     $f0, 4($s0)
/* E2B9AC 802BB27C 92020012 */  lbu       $v0, 0x12($s0)
/* E2B9B0 802BB280 E6020004 */  swc1      $f2, 4($s0)
/* E2B9B4 802BB284 24420001 */  addiu     $v0, $v0, 1
/* E2B9B8 802BB288 A2020012 */  sb        $v0, 0x12($s0)
/* E2B9BC 802BB28C C6200068 */  lwc1      $f0, 0x68($s1)
/* E2B9C0 802BB290 3C014028 */  lui       $at, 0x4028
/* E2B9C4 802BB294 44811800 */  mtc1      $at, $f3
/* E2B9C8 802BB298 44801000 */  mtc1      $zero, $f2
/* E2B9CC 802BB29C 46000021 */  cvt.d.s   $f0, $f0
/* E2B9D0 802BB2A0 46220000 */  add.d     $f0, $f0, $f2
/* E2B9D4 802BB2A4 3C013E4C */  lui       $at, 0x3e4c
/* E2B9D8 802BB2A8 3421CCCD */  ori       $at, $at, 0xcccd
/* E2B9DC 802BB2AC 44812000 */  mtc1      $at, $f4
/* E2B9E0 802BB2B0 3C01C000 */  lui       $at, 0xc000
/* E2B9E4 802BB2B4 44811000 */  mtc1      $at, $f2
/* E2B9E8 802BB2B8 46200020 */  cvt.s.d   $f0, $f0
/* E2B9EC 802BB2BC E6200068 */  swc1      $f0, 0x68($s1)
/* E2B9F0 802BB2C0 E6020008 */  swc1      $f2, 8($s0)
/* E2B9F4 802BB2C4 080AED75 */  j         .L802BB5D4
/* E2B9F8 802BB2C8 E604000C */   swc1     $f4, 0xc($s0)
glabel L802BB2CC_E2B9FC
/* E2B9FC 802BB2CC C600000C */  lwc1      $f0, 0xc($s0)
/* E2BA00 802BB2D0 3C01802C */  lui       $at, %hi(D_802BCF78_E2D6A8)
/* E2BA04 802BB2D4 D422CF78 */  ldc1      $f2, %lo(D_802BCF78_E2D6A8)($at)
/* E2BA08 802BB2D8 46000021 */  cvt.d.s   $f0, $f0
/* E2BA0C 802BB2DC 46220000 */  add.d     $f0, $f0, $f2
/* E2BA10 802BB2E0 46200020 */  cvt.s.d   $f0, $f0
/* E2BA14 802BB2E4 E600000C */  swc1      $f0, 0xc($s0)
/* E2BA18 802BB2E8 C6220060 */  lwc1      $f2, 0x60($s1)
/* E2BA1C 802BB2EC 46001080 */  add.s     $f2, $f2, $f0
/* E2BA20 802BB2F0 E6220060 */  swc1      $f2, 0x60($s1)
/* E2BA24 802BB2F4 C6000008 */  lwc1      $f0, 8($s0)
/* E2BA28 802BB2F8 3C013FF0 */  lui       $at, 0x3ff0
/* E2BA2C 802BB2FC 44811800 */  mtc1      $at, $f3
/* E2BA30 802BB300 44801000 */  mtc1      $zero, $f2
/* E2BA34 802BB304 46000021 */  cvt.d.s   $f0, $f0
/* E2BA38 802BB308 46220001 */  sub.d     $f0, $f0, $f2
/* E2BA3C 802BB30C 46200020 */  cvt.s.d   $f0, $f0
/* E2BA40 802BB310 E6000008 */  swc1      $f0, 8($s0)
/* E2BA44 802BB314 C622004C */  lwc1      $f2, 0x4c($s1)
/* E2BA48 802BB318 46001080 */  add.s     $f2, $f2, $f0
/* E2BA4C 802BB31C C620006C */  lwc1      $f0, 0x6c($s1)
/* E2BA50 802BB320 4600103E */  c.le.s    $f2, $f0
/* E2BA54 802BB324 00000000 */  nop
/* E2BA58 802BB328 450000AA */  bc1f      .L802BB5D4
/* E2BA5C 802BB32C E622004C */   swc1     $f2, 0x4c($s1)
/* E2BA60 802BB330 E620004C */  swc1      $f0, 0x4c($s1)
/* E2BA64 802BB334 3C0140A0 */  lui       $at, 0x40a0
/* E2BA68 802BB338 44810000 */  mtc1      $at, $f0
/* E2BA6C 802BB33C 92020012 */  lbu       $v0, 0x12($s0)
/* E2BA70 802BB340 3C014040 */  lui       $at, 0x4040
/* E2BA74 802BB344 44811000 */  mtc1      $at, $f2
/* E2BA78 802BB348 24420001 */  addiu     $v0, $v0, 1
/* E2BA7C 802BB34C E6000008 */  swc1      $f0, 8($s0)
/* E2BA80 802BB350 E602000C */  swc1      $f2, 0xc($s0)
/* E2BA84 802BB354 A2020012 */  sb        $v0, 0x12($s0)
/* E2BA88 802BB358 C624004C */  lwc1      $f4, 0x4c($s1)
/* E2BA8C 802BB35C 3C0141C8 */  lui       $at, 0x41c8
/* E2BA90 802BB360 44810000 */  mtc1      $at, $f0
/* E2BA94 802BB364 3C014120 */  lui       $at, 0x4120
/* E2BA98 802BB368 44811000 */  mtc1      $at, $f2
/* E2BA9C 802BB36C 46002100 */  add.s     $f4, $f4, $f0
/* E2BAA0 802BB370 E7A20010 */  swc1      $f2, 0x10($sp)
/* E2BAA4 802BB374 8E250048 */  lw        $a1, 0x48($s1)
/* E2BAA8 802BB378 8E270050 */  lw        $a3, 0x50($s1)
/* E2BAAC 802BB37C 44062000 */  mfc1      $a2, $f4
/* E2BAB0 802BB380 0C01BFBC */  jal       func_8006FEF0
/* E2BAB4 802BB384 0000202D */   daddu    $a0, $zero, $zero
/* E2BAB8 802BB388 8E220000 */  lw        $v0, ($s1)
/* E2BABC 802BB38C 34420020 */  ori       $v0, $v0, 0x20
/* E2BAC0 802BB390 080AED75 */  j         .L802BB5D4
/* E2BAC4 802BB394 AE220000 */   sw       $v0, ($s1)
glabel L802BB398_E2BAC8
/* E2BAC8 802BB398 C600000C */  lwc1      $f0, 0xc($s0)
/* E2BACC 802BB39C 3C01802C */  lui       $at, %hi(D_802BCF80_E2D6B0)
/* E2BAD0 802BB3A0 D422CF80 */  ldc1      $f2, %lo(D_802BCF80_E2D6B0)($at)
/* E2BAD4 802BB3A4 46000021 */  cvt.d.s   $f0, $f0
/* E2BAD8 802BB3A8 46220000 */  add.d     $f0, $f0, $f2
/* E2BADC 802BB3AC 46200020 */  cvt.s.d   $f0, $f0
/* E2BAE0 802BB3B0 E600000C */  swc1      $f0, 0xc($s0)
/* E2BAE4 802BB3B4 C6220060 */  lwc1      $f2, 0x60($s1)
/* E2BAE8 802BB3B8 46001080 */  add.s     $f2, $f2, $f0
/* E2BAEC 802BB3BC E6220060 */  swc1      $f2, 0x60($s1)
/* E2BAF0 802BB3C0 C6000008 */  lwc1      $f0, 8($s0)
/* E2BAF4 802BB3C4 3C014000 */  lui       $at, 0x4000
/* E2BAF8 802BB3C8 44811800 */  mtc1      $at, $f3
/* E2BAFC 802BB3CC 44801000 */  mtc1      $zero, $f2
/* E2BB00 802BB3D0 46000021 */  cvt.d.s   $f0, $f0
/* E2BB04 802BB3D4 46220001 */  sub.d     $f0, $f0, $f2
/* E2BB08 802BB3D8 46200020 */  cvt.s.d   $f0, $f0
/* E2BB0C 802BB3DC E6000008 */  swc1      $f0, 8($s0)
/* E2BB10 802BB3E0 C622004C */  lwc1      $f2, 0x4c($s1)
/* E2BB14 802BB3E4 46001080 */  add.s     $f2, $f2, $f0
/* E2BB18 802BB3E8 C620006C */  lwc1      $f0, 0x6c($s1)
/* E2BB1C 802BB3EC 4600103E */  c.le.s    $f2, $f0
/* E2BB20 802BB3F0 00000000 */  nop
/* E2BB24 802BB3F4 45000077 */  bc1f      .L802BB5D4
/* E2BB28 802BB3F8 E622004C */   swc1     $f2, 0x4c($s1)
/* E2BB2C 802BB3FC 2404026A */  addiu     $a0, $zero, 0x26a
/* E2BB30 802BB400 E620004C */  swc1      $f0, 0x4c($s1)
/* E2BB34 802BB404 3C014120 */  lui       $at, 0x4120
/* E2BB38 802BB408 44810000 */  mtc1      $at, $f0
/* E2BB3C 802BB40C 3C013E4C */  lui       $at, 0x3e4c
/* E2BB40 802BB410 3421CCCD */  ori       $at, $at, 0xcccd
/* E2BB44 802BB414 44811000 */  mtc1      $at, $f2
/* E2BB48 802BB418 92030012 */  lbu       $v1, 0x12($s0)
/* E2BB4C 802BB41C 24020002 */  addiu     $v0, $zero, 2
/* E2BB50 802BB420 A2020011 */  sb        $v0, 0x11($s0)
/* E2BB54 802BB424 24630001 */  addiu     $v1, $v1, 1
/* E2BB58 802BB428 E6000008 */  swc1      $f0, 8($s0)
/* E2BB5C 802BB42C E602000C */  swc1      $f2, 0xc($s0)
/* E2BB60 802BB430 0C05272D */  jal       sfx_play_sound
/* E2BB64 802BB434 A2030012 */   sb       $v1, 0x12($s0)
/* E2BB68 802BB438 080AED75 */  j         .L802BB5D4
/* E2BB6C 802BB43C 00000000 */   nop
glabel L802BB440_E2BB70
/* E2BB70 802BB440 92020011 */  lbu       $v0, 0x11($s0)
/* E2BB74 802BB444 2442FFFF */  addiu     $v0, $v0, -1
/* E2BB78 802BB448 A2020011 */  sb        $v0, 0x11($s0)
/* E2BB7C 802BB44C 00021600 */  sll       $v0, $v0, 0x18
/* E2BB80 802BB450 1C400060 */  bgtz      $v0, .L802BB5D4
/* E2BB84 802BB454 00000000 */   nop
/* E2BB88 802BB458 92020012 */  lbu       $v0, 0x12($s0)
/* E2BB8C 802BB45C 24420001 */  addiu     $v0, $v0, 1
/* E2BB90 802BB460 080AED75 */  j         .L802BB5D4
/* E2BB94 802BB464 A2020012 */   sb       $v0, 0x12($s0)
glabel L802BB468_E2BB98
/* E2BB98 802BB468 C600000C */  lwc1      $f0, 0xc($s0)
/* E2BB9C 802BB46C 46000000 */  add.s     $f0, $f0, $f0
/* E2BBA0 802BB470 3C0141F0 */  lui       $at, 0x41f0
/* E2BBA4 802BB474 44811000 */  mtc1      $at, $f2
/* E2BBA8 802BB478 00000000 */  nop
/* E2BBAC 802BB47C 4600103C */  c.lt.s    $f2, $f0
/* E2BBB0 802BB480 00000000 */  nop
/* E2BBB4 802BB484 45000002 */  bc1f      .L802BB490
/* E2BBB8 802BB488 E600000C */   swc1     $f0, 0xc($s0)
/* E2BBBC 802BB48C E602000C */  swc1      $f2, 0xc($s0)
.L802BB490:
/* E2BBC0 802BB490 C6240060 */  lwc1      $f4, 0x60($s1)
/* E2BBC4 802BB494 C600000C */  lwc1      $f0, 0xc($s0)
/* E2BBC8 802BB498 46002100 */  add.s     $f4, $f4, $f0
/* E2BBCC 802BB49C 3C01802C */  lui       $at, %hi(D_802BCF88_E2D6B8)
/* E2BBD0 802BB4A0 D422CF88 */  ldc1      $f2, %lo(D_802BCF88_E2D6B8)($at)
/* E2BBD4 802BB4A4 46002021 */  cvt.d.s   $f0, $f4
/* E2BBD8 802BB4A8 4620103E */  c.le.d    $f2, $f0
/* E2BBDC 802BB4AC 00000000 */  nop
/* E2BBE0 802BB4B0 45000048 */  bc1f      .L802BB5D4
/* E2BBE4 802BB4B4 E6240060 */   swc1     $f4, 0x60($s1)
/* E2BBE8 802BB4B8 3C0142B4 */  lui       $at, 0x42b4
/* E2BBEC 802BB4BC 44810000 */  mtc1      $at, $f0
/* E2BBF0 802BB4C0 2404026A */  addiu     $a0, $zero, 0x26a
/* E2BBF4 802BB4C4 E6200060 */  swc1      $f0, 0x60($s1)
/* E2BBF8 802BB4C8 92020012 */  lbu       $v0, 0x12($s0)
/* E2BBFC 802BB4CC 3C01C1A0 */  lui       $at, 0xc1a0
/* E2BC00 802BB4D0 44810000 */  mtc1      $at, $f0
/* E2BC04 802BB4D4 24420001 */  addiu     $v0, $v0, 1
/* E2BC08 802BB4D8 080AED57 */  j         .L802BB55C
/* E2BC0C 802BB4DC E600000C */   swc1     $f0, 0xc($s0)
glabel L802BB4E0_E2BC10
/* E2BC10 802BB4E0 C600000C */  lwc1      $f0, 0xc($s0)
/* E2BC14 802BB4E4 3C014120 */  lui       $at, 0x4120
/* E2BC18 802BB4E8 44811000 */  mtc1      $at, $f2
/* E2BC1C 802BB4EC 00000000 */  nop
/* E2BC20 802BB4F0 46020000 */  add.s     $f0, $f0, $f2
/* E2BC24 802BB4F4 3C0141F0 */  lui       $at, 0x41f0
/* E2BC28 802BB4F8 44811000 */  mtc1      $at, $f2
/* E2BC2C 802BB4FC 00000000 */  nop
/* E2BC30 802BB500 4600103C */  c.lt.s    $f2, $f0
/* E2BC34 802BB504 00000000 */  nop
/* E2BC38 802BB508 45000002 */  bc1f      .L802BB514
/* E2BC3C 802BB50C E600000C */   swc1     $f0, 0xc($s0)
/* E2BC40 802BB510 E602000C */  swc1      $f2, 0xc($s0)
.L802BB514:
/* E2BC44 802BB514 C6240060 */  lwc1      $f4, 0x60($s1)
/* E2BC48 802BB518 C600000C */  lwc1      $f0, 0xc($s0)
/* E2BC4C 802BB51C 46002100 */  add.s     $f4, $f4, $f0
/* E2BC50 802BB520 3C01802C */  lui       $at, %hi(D_802BCF90_E2D6C0)
/* E2BC54 802BB524 D422CF90 */  ldc1      $f2, %lo(D_802BCF90_E2D6C0)($at)
/* E2BC58 802BB528 46002021 */  cvt.d.s   $f0, $f4
/* E2BC5C 802BB52C 4620103E */  c.le.d    $f2, $f0
/* E2BC60 802BB530 00000000 */  nop
/* E2BC64 802BB534 45000027 */  bc1f      .L802BB5D4
/* E2BC68 802BB538 E6240060 */   swc1     $f4, 0x60($s1)
/* E2BC6C 802BB53C 3C0142B4 */  lui       $at, 0x42b4
/* E2BC70 802BB540 44810000 */  mtc1      $at, $f0
/* E2BC74 802BB544 2404026A */  addiu     $a0, $zero, 0x26a
/* E2BC78 802BB548 E6200060 */  swc1      $f0, 0x60($s1)
/* E2BC7C 802BB54C 92020012 */  lbu       $v0, 0x12($s0)
/* E2BC80 802BB550 24030005 */  addiu     $v1, $zero, 5
/* E2BC84 802BB554 A2030011 */  sb        $v1, 0x11($s0)
/* E2BC88 802BB558 24420001 */  addiu     $v0, $v0, 1
.L802BB55C:
/* E2BC8C 802BB55C 0C05272D */  jal       sfx_play_sound
/* E2BC90 802BB560 A2020012 */   sb       $v0, 0x12($s0)
/* E2BC94 802BB564 080AED75 */  j         .L802BB5D4
/* E2BC98 802BB568 00000000 */   nop
glabel L802BB56C_E2BC9C
/* E2BC9C 802BB56C 92020011 */  lbu       $v0, 0x11($s0)
/* E2BCA0 802BB570 2442FFFF */  addiu     $v0, $v0, -1
/* E2BCA4 802BB574 A2020011 */  sb        $v0, 0x11($s0)
/* E2BCA8 802BB578 00021600 */  sll       $v0, $v0, 0x18
/* E2BCAC 802BB57C 1C400015 */  bgtz      $v0, .L802BB5D4
/* E2BCB0 802BB580 0220202D */   daddu    $a0, $s1, $zero
/* E2BCB4 802BB584 92020012 */  lbu       $v0, 0x12($s0)
/* E2BCB8 802BB588 24420001 */  addiu     $v0, $v0, 1
/* E2BCBC 802BB58C 0C04419E */  jal       func_80110678
/* E2BCC0 802BB590 A2020012 */   sb       $v0, 0x12($s0)
/* E2BCC4 802BB594 24020005 */  addiu     $v0, $zero, 5
/* E2BCC8 802BB598 080AED75 */  j         .L802BB5D4
/* E2BCCC 802BB59C A2020011 */   sb       $v0, 0x11($s0)
glabel L802BB5A0_E2BCD0
/* E2BCD0 802BB5A0 92020011 */  lbu       $v0, 0x11($s0)
/* E2BCD4 802BB5A4 2442FFFF */  addiu     $v0, $v0, -1
/* E2BCD8 802BB5A8 A2020011 */  sb        $v0, 0x11($s0)
/* E2BCDC 802BB5AC 00021600 */  sll       $v0, $v0, 0x18
/* E2BCE0 802BB5B0 1C400008 */  bgtz      $v0, .L802BB5D4
/* E2BCE4 802BB5B4 0220202D */   daddu    $a0, $s1, $zero
/* E2BCE8 802BB5B8 92020012 */  lbu       $v0, 0x12($s0)
/* E2BCEC 802BB5BC 24420001 */  addiu     $v0, $v0, 1
/* E2BCF0 802BB5C0 A2020012 */  sb        $v0, 0x12($s0)
/* E2BCF4 802BB5C4 8E220000 */  lw        $v0, ($s1)
/* E2BCF8 802BB5C8 34420021 */  ori       $v0, $v0, 0x21
/* E2BCFC 802BB5CC 0C043F5A */  jal       exec_entity_updatecmd
/* E2BD00 802BB5D0 AE220000 */   sw       $v0, ($s1)
.L802BB5D4:
/* E2BD04 802BB5D4 92020012 */  lbu       $v0, 0x12($s0)
/* E2BD08 802BB5D8 2442FFFE */  addiu     $v0, $v0, -2
/* E2BD0C 802BB5DC 2C420007 */  sltiu     $v0, $v0, 7
/* E2BD10 802BB5E0 1040000D */  beqz      $v0, .L802BB618
/* E2BD14 802BB5E4 00000000 */   nop
/* E2BD18 802BB5E8 92020010 */  lbu       $v0, 0x10($s0)
/* E2BD1C 802BB5EC 24420001 */  addiu     $v0, $v0, 1
/* E2BD20 802BB5F0 A2020010 */  sb        $v0, 0x10($s0)
/* E2BD24 802BB5F4 30420001 */  andi      $v0, $v0, 1
/* E2BD28 802BB5F8 10400004 */  beqz      $v0, .L802BB60C
/* E2BD2C 802BB5FC 2403FFFE */   addiu    $v1, $zero, -2
/* E2BD30 802BB600 8E220000 */  lw        $v0, ($s1)
/* E2BD34 802BB604 080AED85 */  j         .L802BB614
/* E2BD38 802BB608 34420001 */   ori      $v0, $v0, 1
.L802BB60C:
/* E2BD3C 802BB60C 8E220000 */  lw        $v0, ($s1)
/* E2BD40 802BB610 00431024 */  and       $v0, $v0, $v1
.L802BB614:
/* E2BD44 802BB614 AE220000 */  sw        $v0, ($s1)
.L802BB618:
/* E2BD48 802BB618 8FBF0020 */  lw        $ra, 0x20($sp)
/* E2BD4C 802BB61C 8FB1001C */  lw        $s1, 0x1c($sp)
/* E2BD50 802BB620 8FB00018 */  lw        $s0, 0x18($sp)
/* E2BD54 802BB624 03E00008 */  jr        $ra
/* E2BD58 802BB628 27BD0028 */   addiu    $sp, $sp, 0x28
