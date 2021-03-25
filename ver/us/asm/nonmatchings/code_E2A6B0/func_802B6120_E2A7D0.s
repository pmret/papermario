.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802B6D90_E2B440
.word L802B62B8_E2A968, L802B6324_E2A9D4, L802B6370_E2AA20, L802B63B0_E2AA60, L802B63DC_E2AA8C, L802B64E0_E2AB90, L802B67F8_E2AEA8, L802B6510_E2ABC0, L802B661C_E2ACCC, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B6680_E2AD30, L802B66BC_E2AD6C, L802B67F8_E2AEA8, L802B682C_E2AEDC, L802B6968_E2B018, L802B69F0_E2B0A0, L802B69A4_E2B054, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69B4_E2B064, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69F0_E2B0A0, L802B69C8_E2B078, 0

glabel D_802B6E60_E2B510
.double 2.35

glabel D_802B6E68_E2B518
.double 2.35

glabel D_802B6E70_E2B520
.double 2.35

glabel D_802B6E78_E2B528
.double 2.35

.section .text

glabel func_802B6120_E2A7D0
/* E2A7D0 802B6120 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* E2A7D4 802B6124 AFB10024 */  sw        $s1, 0x24($sp)
/* E2A7D8 802B6128 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E2A7DC 802B612C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2A7E0 802B6130 AFB20028 */  sw        $s2, 0x28($sp)
/* E2A7E4 802B6134 3C12802B */  lui       $s2, %hi(D_802B6E80)
/* E2A7E8 802B6138 26526E80 */  addiu     $s2, $s2, %lo(D_802B6E80)
/* E2A7EC 802B613C 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E2A7F0 802B6140 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E2A7F4 802B6144 3C04800B */  lui       $a0, %hi(gCameras)
/* E2A7F8 802B6148 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* E2A7FC 802B614C AFBF0030 */  sw        $ra, 0x30($sp)
/* E2A800 802B6150 AFB3002C */  sw        $s3, 0x2c($sp)
/* E2A804 802B6154 AFB00020 */  sw        $s0, 0x20($sp)
/* E2A808 802B6158 F7B80048 */  sdc1      $f24, 0x48($sp)
/* E2A80C 802B615C F7B60040 */  sdc1      $f22, 0x40($sp)
/* E2A810 802B6160 F7B40038 */  sdc1      $f20, 0x38($sp)
/* E2A814 802B6164 00031080 */  sll       $v0, $v1, 2
/* E2A818 802B6168 00431021 */  addu      $v0, $v0, $v1
/* E2A81C 802B616C 00021080 */  sll       $v0, $v0, 2
/* E2A820 802B6170 00431023 */  subu      $v0, $v0, $v1
/* E2A824 802B6174 000218C0 */  sll       $v1, $v0, 3
/* E2A828 802B6178 00431021 */  addu      $v0, $v0, $v1
/* E2A82C 802B617C 000210C0 */  sll       $v0, $v0, 3
/* E2A830 802B6180 8E230000 */  lw        $v1, ($s1)
/* E2A834 802B6184 04610043 */  bgez      $v1, .L802B6294
/* E2A838 802B6188 00449821 */   addu     $s3, $v0, $a0
/* E2A83C 802B618C 3C027FFF */  lui       $v0, 0x7fff
/* E2A840 802B6190 3442FFFF */  ori       $v0, $v0, 0xffff
/* E2A844 802B6194 0240202D */  daddu     $a0, $s2, $zero
/* E2A848 802B6198 24050024 */  addiu     $a1, $zero, 0x24
/* E2A84C 802B619C 00621024 */  and       $v0, $v1, $v0
/* E2A850 802B61A0 0C00A580 */  jal       mem_clear
/* E2A854 802B61A4 AE220000 */   sw       $v0, ($s1)
/* E2A858 802B61A8 0C038045 */  jal       disable_player_static_collisions
/* E2A85C 802B61AC 00000000 */   nop
/* E2A860 802B61B0 3C01C000 */  lui       $at, 0xc000
/* E2A864 802B61B4 44812000 */  mtc1      $at, $f4
/* E2A868 802B61B8 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* E2A86C 802B61BC 3C0142B4 */  lui       $at, 0x42b4
/* E2A870 802B61C0 44810000 */  mtc1      $at, $f0
/* E2A874 802B61C4 2643001C */  addiu     $v1, $s2, 0x1c
/* E2A878 802B61C8 A62000C0 */  sh        $zero, 0xc0($s1)
/* E2A87C 802B61CC A62000C2 */  sh        $zero, 0xc2($s1)
/* E2A880 802B61D0 AE200054 */  sw        $zero, 0x54($s1)
/* E2A884 802B61D4 4602003E */  c.le.s    $f0, $f2
/* E2A888 802B61D8 00000000 */  nop
/* E2A88C 802B61DC 4500000A */  bc1f      .L802B6208
/* E2A890 802B61E0 AE20008C */   sw       $zero, 0x8c($s1)
/* E2A894 802B61E4 3C014387 */  lui       $at, 0x4387
/* E2A898 802B61E8 44810000 */  mtc1      $at, $f0
/* E2A89C 802B61EC 00000000 */  nop
/* E2A8A0 802B61F0 4600103C */  c.lt.s    $f2, $f0
/* E2A8A4 802B61F4 00000000 */  nop
/* E2A8A8 802B61F8 45000003 */  bc1f      .L802B6208
/* E2A8AC 802B61FC 00000000 */   nop
/* E2A8B0 802B6200 3C014000 */  lui       $at, 0x4000
/* E2A8B4 802B6204 44812000 */  mtc1      $at, $f4
.L802B6208:
/* E2A8B8 802B6208 8E220004 */  lw        $v0, 4($s1)
/* E2A8BC 802B620C 30422000 */  andi      $v0, $v0, 0x2000
/* E2A8C0 802B6210 14400009 */  bnez      $v0, .L802B6238
/* E2A8C4 802B6214 E4640000 */   swc1     $f4, ($v1)
/* E2A8C8 802B6218 24020014 */  addiu     $v0, $zero, 0x14
/* E2A8CC 802B621C A6220008 */  sh        $v0, 8($s1)
/* E2A8D0 802B6220 2402000F */  addiu     $v0, $zero, 0xf
/* E2A8D4 802B6224 A22000B6 */  sb        $zero, 0xb6($s1)
/* E2A8D8 802B6228 0C0AD800 */  jal       func_802B6000_E2A6B0
/* E2A8DC 802B622C AE420008 */   sw       $v0, 8($s2)
/* E2A8E0 802B6230 080AD8A5 */  j         .L802B6294
/* E2A8E4 802B6234 AE420000 */   sw       $v0, ($s2)
.L802B6238:
/* E2A8E8 802B6238 3C048011 */  lui       $a0, %hi(D_8010C96C)
/* E2A8EC 802B623C 8C84C96C */  lw        $a0, %lo(D_8010C96C)($a0)
/* E2A8F0 802B6240 24020014 */  addiu     $v0, $zero, 0x14
/* E2A8F4 802B6244 A22200B6 */  sb        $v0, 0xb6($s1)
/* E2A8F8 802B6248 24020028 */  addiu     $v0, $zero, 0x28
/* E2A8FC 802B624C A6220008 */  sh        $v0, 8($s1)
/* E2A900 802B6250 24020001 */  addiu     $v0, $zero, 1
/* E2A904 802B6254 AE420004 */  sw        $v0, 4($s2)
/* E2A908 802B6258 2402000C */  addiu     $v0, $zero, 0xc
/* E2A90C 802B625C 0C00E2B7 */  jal       get_npc_by_index
/* E2A910 802B6260 AE42000C */   sw       $v0, 0xc($s2)
/* E2A914 802B6264 0040802D */  daddu     $s0, $v0, $zero
/* E2A918 802B6268 240400FD */  addiu     $a0, $zero, 0xfd
/* E2A91C 802B626C 0000282D */  daddu     $a1, $zero, $zero
/* E2A920 802B6270 8E020000 */  lw        $v0, ($s0)
/* E2A924 802B6274 3C030004 */  lui       $v1, 4
/* E2A928 802B6278 00431025 */  or        $v0, $v0, $v1
/* E2A92C 802B627C AE020000 */  sw        $v0, ($s0)
/* E2A930 802B6280 8E220000 */  lw        $v0, ($s1)
/* E2A934 802B6284 3C030010 */  lui       $v1, 0x10
/* E2A938 802B6288 00431025 */  or        $v0, $v0, $v1
/* E2A93C 802B628C 0C052736 */  jal       play_sound_at_player
/* E2A940 802B6290 AE220000 */   sw       $v0, ($s1)
.L802B6294:
/* E2A944 802B6294 822300B6 */  lb        $v1, 0xb6($s1)
/* E2A948 802B6298 2C620033 */  sltiu     $v0, $v1, 0x33
/* E2A94C 802B629C 104001D4 */  beqz      $v0, L802B69F0_E2B0A0
/* E2A950 802B62A0 00031080 */   sll      $v0, $v1, 2
/* E2A954 802B62A4 3C01802B */  lui       $at, %hi(jtbl_802B6D90_E2B440)
/* E2A958 802B62A8 00220821 */  addu      $at, $at, $v0
/* E2A95C 802B62AC 8C226D90 */  lw        $v0, %lo(jtbl_802B6D90_E2B440)($at)
/* E2A960 802B62B0 00400008 */  jr        $v0
/* E2A964 802B62B4 00000000 */   nop
glabel L802B62B8_E2A968
/* E2A968 802B62B8 C6220090 */  lwc1      $f2, 0x90($s1)
/* E2A96C 802B62BC 44800000 */  mtc1      $zero, $f0
/* E2A970 802B62C0 00000000 */  nop
/* E2A974 802B62C4 46001032 */  c.eq.s    $f2, $f0
/* E2A978 802B62C8 00000000 */  nop
/* E2A97C 802B62CC 45000015 */  bc1f      L802B6324_E2A9D4
/* E2A980 802B62D0 00000000 */   nop
/* E2A984 802B62D4 0C0399B1 */  jal       func_800E66C4
/* E2A988 802B62D8 00000000 */   nop
/* E2A98C 802B62DC 0441000A */  bgez      $v0, .L802B6308
/* E2A990 802B62E0 3C04000C */   lui      $a0, 0xc
/* E2A994 802B62E4 0C037FBF */  jal       func_800DFEFC
/* E2A998 802B62E8 34840024 */   ori      $a0, $a0, 0x24
/* E2A99C 802B62EC 24040092 */  addiu     $a0, $zero, 0x92
/* E2A9A0 802B62F0 0C052736 */  jal       play_sound_at_player
/* E2A9A4 802B62F4 0000282D */   daddu    $a1, $zero, $zero
/* E2A9A8 802B62F8 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2A9AC 802B62FC 24420001 */  addiu     $v0, $v0, 1
/* E2A9B0 802B6300 080AD8C9 */  j         L802B6324_E2A9D4
/* E2A9B4 802B6304 A22200B6 */   sb       $v0, 0xb6($s1)
.L802B6308:
/* E2A9B8 802B6308 0C037FBF */  jal       func_800DFEFC
/* E2A9BC 802B630C 34840027 */   ori      $a0, $a0, 0x27
/* E2A9C0 802B6310 24020032 */  addiu     $v0, $zero, 0x32
/* E2A9C4 802B6314 A22200B6 */  sb        $v0, 0xb6($s1)
/* E2A9C8 802B6318 2402000A */  addiu     $v0, $zero, 0xa
/* E2A9CC 802B631C A6220008 */  sh        $v0, 8($s1)
/* E2A9D0 802B6320 AE400008 */  sw        $zero, 8($s2)
glabel L802B6324_E2A9D4
/* E2A9D4 802B6324 96220008 */  lhu       $v0, 8($s1)
/* E2A9D8 802B6328 2442FFFF */  addiu     $v0, $v0, -1
/* E2A9DC 802B632C A6220008 */  sh        $v0, 8($s1)
/* E2A9E0 802B6330 00021400 */  sll       $v0, $v0, 0x10
/* E2A9E4 802B6334 144001AE */  bnez      $v0, L802B69F0_E2B0A0
/* E2A9E8 802B6338 3C04000C */   lui      $a0, 0xc
/* E2A9EC 802B633C 0C037FBF */  jal       func_800DFEFC
/* E2A9F0 802B6340 34840025 */   ori      $a0, $a0, 0x25
/* E2A9F4 802B6344 8E430000 */  lw        $v1, ($s2)
/* E2A9F8 802B6348 24020002 */  addiu     $v0, $zero, 2
/* E2A9FC 802B634C 14600004 */  bnez      $v1, .L802B6360
/* E2AA00 802B6350 A22200B6 */   sb       $v0, 0xb6($s1)
/* E2AA04 802B6354 24020028 */  addiu     $v0, $zero, 0x28
/* E2AA08 802B6358 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AA0C 802B635C A22200B6 */   sb       $v0, 0xb6($s1)
.L802B6360:
/* E2AA10 802B6360 0C009C22 */  jal       func_80027088
/* E2AA14 802B6364 24040002 */   addiu    $a0, $zero, 2
/* E2AA18 802B6368 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AA1C 802B636C 00000000 */   nop
glabel L802B6370_E2AA20
/* E2AA20 802B6370 962200BC */  lhu       $v0, 0xbc($s1)
/* E2AA24 802B6374 1040019E */  beqz      $v0, L802B69F0_E2B0A0
/* E2AA28 802B6378 240400FD */   addiu    $a0, $zero, 0xfd
/* E2AA2C 802B637C 0000282D */  daddu     $a1, $zero, $zero
/* E2AA30 802B6380 2402000C */  addiu     $v0, $zero, 0xc
/* E2AA34 802B6384 3C060010 */  lui       $a2, 0x10
/* E2AA38 802B6388 A6220008 */  sh        $v0, 8($s1)
/* E2AA3C 802B638C 8E220000 */  lw        $v0, ($s1)
/* E2AA40 802B6390 922300B6 */  lbu       $v1, 0xb6($s1)
/* E2AA44 802B6394 00461025 */  or        $v0, $v0, $a2
/* E2AA48 802B6398 24630001 */  addiu     $v1, $v1, 1
/* E2AA4C 802B639C AE220000 */  sw        $v0, ($s1)
/* E2AA50 802B63A0 0C052736 */  jal       play_sound_at_player
/* E2AA54 802B63A4 A22300B6 */   sb       $v1, 0xb6($s1)
/* E2AA58 802B63A8 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AA5C 802B63AC 00000000 */   nop
glabel L802B63B0_E2AA60
/* E2AA60 802B63B0 96220008 */  lhu       $v0, 8($s1)
/* E2AA64 802B63B4 2442FFFF */  addiu     $v0, $v0, -1
/* E2AA68 802B63B8 A6220008 */  sh        $v0, 8($s1)
/* E2AA6C 802B63BC 00021400 */  sll       $v0, $v0, 0x10
/* E2AA70 802B63C0 14400116 */  bnez      $v0, .L802B681C
/* E2AA74 802B63C4 2402000A */   addiu    $v0, $zero, 0xa
/* E2AA78 802B63C8 A6220008 */  sh        $v0, 8($s1)
/* E2AA7C 802B63CC 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2AA80 802B63D0 2403000A */  addiu     $v1, $zero, 0xa
/* E2AA84 802B63D4 080ADA05 */  j         .L802B6814
/* E2AA88 802B63D8 AE43000C */   sw       $v1, 0xc($s2)
glabel L802B63DC_E2AA8C
/* E2AA8C 802B63DC C63400A8 */  lwc1      $f20, 0xa8($s1)
/* E2AA90 802B63E0 0C0ADB3C */  jal       func_802B6CF0_E2B3A0
/* E2AA94 802B63E4 00000000 */   nop
/* E2AA98 802B63E8 C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2AA9C 802B63EC C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AAA0 802B63F0 46006301 */  sub.s     $f12, $f12, $f0
/* E2AAA4 802B63F4 3C0142B4 */  lui       $at, 0x42b4
/* E2AAA8 802B63F8 44810000 */  mtc1      $at, $f0
/* E2AAAC 802B63FC 0C00A6C9 */  jal       clamp_angle
/* E2AAB0 802B6400 46006301 */   sub.s    $f12, $f12, $f0
/* E2AAB4 802B6404 86220008 */  lh        $v0, 8($s1)
/* E2AAB8 802B6408 96230008 */  lhu       $v1, 8($s1)
/* E2AABC 802B640C 144000F7 */  bnez      $v0, .L802B67EC
/* E2AAC0 802B6410 E6200080 */   swc1     $f0, 0x80($s1)
/* E2AAC4 802B6414 C642001C */  lwc1      $f2, 0x1c($s2)
/* E2AAC8 802B6418 44800000 */  mtc1      $zero, $f0
/* E2AACC 802B641C 00000000 */  nop
/* E2AAD0 802B6420 4602003C */  c.lt.s    $f0, $f2
/* E2AAD4 802B6424 00000000 */  nop
/* E2AAD8 802B6428 45000010 */  bc1f      .L802B646C
/* E2AADC 802B642C 0000102D */   daddu    $v0, $zero, $zero
/* E2AAE0 802B6430 3C014387 */  lui       $at, 0x4387
/* E2AAE4 802B6434 44811000 */  mtc1      $at, $f2
/* E2AAE8 802B6438 00000000 */  nop
/* E2AAEC 802B643C 4602A03C */  c.lt.s    $f20, $f2
/* E2AAF0 802B6440 00000000 */  nop
/* E2AAF4 802B6444 45000006 */  bc1f      .L802B6460
/* E2AAF8 802B6448 00000000 */   nop
/* E2AAFC 802B644C C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AB00 802B6450 4600103E */  c.le.s    $f2, $f0
/* E2AB04 802B6454 00000000 */  nop
/* E2AB08 802B6458 45030001 */  bc1tl     .L802B6460
/* E2AB0C 802B645C 24020001 */   addiu    $v0, $zero, 1
.L802B6460:
/* E2AB10 802B6460 C642001C */  lwc1      $f2, 0x1c($s2)
/* E2AB14 802B6464 44800000 */  mtc1      $zero, $f0
/* E2AB18 802B6468 00000000 */  nop
.L802B646C:
/* E2AB1C 802B646C 4600103C */  c.lt.s    $f2, $f0
/* E2AB20 802B6470 00000000 */  nop
/* E2AB24 802B6474 4500000D */  bc1f      .L802B64AC
/* E2AB28 802B6478 00000000 */   nop
/* E2AB2C 802B647C 3C014387 */  lui       $at, 0x4387
/* E2AB30 802B6480 44811000 */  mtc1      $at, $f2
/* E2AB34 802B6484 00000000 */  nop
/* E2AB38 802B6488 4614103C */  c.lt.s    $f2, $f20
/* E2AB3C 802B648C 00000000 */  nop
/* E2AB40 802B6490 45000006 */  bc1f      .L802B64AC
/* E2AB44 802B6494 00000000 */   nop
/* E2AB48 802B6498 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AB4C 802B649C 4602003E */  c.le.s    $f0, $f2
/* E2AB50 802B64A0 00000000 */  nop
/* E2AB54 802B64A4 45030001 */  bc1tl     .L802B64AC
/* E2AB58 802B64A8 24020001 */   addiu    $v0, $zero, 1
.L802B64AC:
/* E2AB5C 802B64AC 10400150 */  beqz      $v0, L802B69F0_E2B0A0
/* E2AB60 802B64B0 24020006 */   addiu    $v0, $zero, 6
/* E2AB64 802B64B4 8224000D */  lb        $a0, 0xd($s1)
/* E2AB68 802B64B8 A22200B6 */  sb        $v0, 0xb6($s1)
/* E2AB6C 802B64BC 24020002 */  addiu     $v0, $zero, 2
/* E2AB70 802B64C0 0C03995F */  jal       make_disguise_npc
/* E2AB74 802B64C4 A6220008 */   sh       $v0, 8($s1)
/* E2AB78 802B64C8 10400149 */  beqz      $v0, L802B69F0_E2B0A0
/* E2AB7C 802B64CC 24020005 */   addiu    $v0, $zero, 5
/* E2AB80 802B64D0 0C039940 */  jal       func_800E6500
/* E2AB84 802B64D4 A22200B6 */   sb       $v0, 0xb6($s1)
/* E2AB88 802B64D8 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AB8C 802B64DC 00000000 */   nop
glabel L802B64E0_E2AB90
/* E2AB90 802B64E0 8E220004 */  lw        $v0, 4($s1)
/* E2AB94 802B64E4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E2AB98 802B64E8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E2AB9C 802B64EC 34422000 */  ori       $v0, $v0, 0x2000
/* E2ABA0 802B64F0 AE220004 */  sw        $v0, 4($s1)
/* E2ABA4 802B64F4 9062007E */  lbu       $v0, 0x7e($v1)
/* E2ABA8 802B64F8 34420002 */  ori       $v0, $v0, 2
/* E2ABAC 802B64FC A062007E */  sb        $v0, 0x7e($v1)
/* E2ABB0 802B6500 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2ABB4 802B6504 24420001 */  addiu     $v0, $v0, 1
/* E2ABB8 802B6508 080AD9FE */  j         L802B67F8_E2AEA8
/* E2ABBC 802B650C A22200B6 */   sb       $v0, 0xb6($s1)
glabel L802B6510_E2ABC0
/* E2ABC0 802B6510 C640001C */  lwc1      $f0, 0x1c($s2)
/* E2ABC4 802B6514 44802000 */  mtc1      $zero, $f4
/* E2ABC8 802B6518 00000000 */  nop
/* E2ABCC 802B651C 4600203C */  c.lt.s    $f4, $f0
/* E2ABD0 802B6520 00000000 */  nop
/* E2ABD4 802B6524 4500001B */  bc1f      .L802B6594
/* E2ABD8 802B6528 00000000 */   nop
/* E2ABDC 802B652C C6400020 */  lwc1      $f0, 0x20($s2)
/* E2ABE0 802B6530 3C01802B */  lui       $at, %hi(D_802B6E60_E2B510)
/* E2ABE4 802B6534 D4226E60 */  ldc1      $f2, %lo(D_802B6E60_E2B510)($at)
/* E2ABE8 802B6538 46000021 */  cvt.d.s   $f0, $f0
/* E2ABEC 802B653C 46220001 */  sub.d     $f0, $f0, $f2
/* E2ABF0 802B6540 46200020 */  cvt.s.d   $f0, $f0
/* E2ABF4 802B6544 4604003E */  c.le.s    $f0, $f4
/* E2ABF8 802B6548 00000000 */  nop
/* E2ABFC 802B654C 450000F9 */  bc1f      .L802B6934
/* E2AC00 802B6550 E6400020 */   swc1     $f0, 0x20($s2)
/* E2AC04 802B6554 3C048011 */  lui       $a0, %hi(D_8010C96C)
/* E2AC08 802B6558 8C84C96C */  lw        $a0, %lo(D_8010C96C)($a0)
/* E2AC0C 802B655C 2402000A */  addiu     $v0, $zero, 0xa
/* E2AC10 802B6560 E6440020 */  swc1      $f4, 0x20($s2)
/* E2AC14 802B6564 A6220008 */  sh        $v0, 8($s1)
/* E2AC18 802B6568 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2AC1C 802B656C 3C014334 */  lui       $at, 0x4334
/* E2AC20 802B6570 44810000 */  mtc1      $at, $f0
/* E2AC24 802B6574 24420001 */  addiu     $v0, $v0, 1
/* E2AC28 802B6578 A22200B6 */  sb        $v0, 0xb6($s1)
/* E2AC2C 802B657C 0C00E2B7 */  jal       get_npc_by_index
/* E2AC30 802B6580 E62000A8 */   swc1     $f0, 0xa8($s1)
/* E2AC34 802B6584 0040802D */  daddu     $s0, $v0, $zero
/* E2AC38 802B6588 24020001 */  addiu     $v0, $zero, 1
/* E2AC3C 802B658C 080AD97B */  j         .L802B65EC
/* E2AC40 802B6590 A6020088 */   sh       $v0, 0x88($s0)
.L802B6594:
/* E2AC44 802B6594 C6400020 */  lwc1      $f0, 0x20($s2)
/* E2AC48 802B6598 3C01802B */  lui       $at, %hi(D_802B6E68_E2B518)
/* E2AC4C 802B659C D4226E68 */  ldc1      $f2, %lo(D_802B6E68_E2B518)($at)
/* E2AC50 802B65A0 46000021 */  cvt.d.s   $f0, $f0
/* E2AC54 802B65A4 46220000 */  add.d     $f0, $f0, $f2
/* E2AC58 802B65A8 46200020 */  cvt.s.d   $f0, $f0
/* E2AC5C 802B65AC 4600203E */  c.le.s    $f4, $f0
/* E2AC60 802B65B0 00000000 */  nop
/* E2AC64 802B65B4 450000DF */  bc1f      .L802B6934
/* E2AC68 802B65B8 E6400020 */   swc1     $f0, 0x20($s2)
/* E2AC6C 802B65BC 3C048011 */  lui       $a0, %hi(D_8010C96C)
/* E2AC70 802B65C0 8C84C96C */  lw        $a0, %lo(D_8010C96C)($a0)
/* E2AC74 802B65C4 E6440020 */  swc1      $f4, 0x20($s2)
/* E2AC78 802B65C8 922300B6 */  lbu       $v1, 0xb6($s1)
/* E2AC7C 802B65CC 2402000A */  addiu     $v0, $zero, 0xa
/* E2AC80 802B65D0 A6220008 */  sh        $v0, 8($s1)
/* E2AC84 802B65D4 E62400A8 */  swc1      $f4, 0xa8($s1)
/* E2AC88 802B65D8 24630001 */  addiu     $v1, $v1, 1
/* E2AC8C 802B65DC 0C00E2B7 */  jal       get_npc_by_index
/* E2AC90 802B65E0 A22300B6 */   sb       $v1, 0xb6($s1)
/* E2AC94 802B65E4 0040802D */  daddu     $s0, $v0, $zero
/* E2AC98 802B65E8 A6000088 */  sh        $zero, 0x88($s0)
.L802B65EC:
/* E2AC9C 802B65EC C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2ACA0 802B65F0 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2ACA4 802B65F4 46006301 */  sub.s     $f12, $f12, $f0
/* E2ACA8 802B65F8 3C0142B4 */  lui       $at, 0x42b4
/* E2ACAC 802B65FC 44810000 */  mtc1      $at, $f0
/* E2ACB0 802B6600 0C00A6C9 */  jal       clamp_angle
/* E2ACB4 802B6604 46006301 */   sub.s    $f12, $f12, $f0
/* E2ACB8 802B6608 4600018D */  trunc.w.s $f6, $f0
/* E2ACBC 802B660C 44023000 */  mfc1      $v0, $f6
/* E2ACC0 802B6610 E600000C */  swc1      $f0, 0xc($s0)
/* E2ACC4 802B6614 080ADA4D */  j         .L802B6934
/* E2ACC8 802B6618 A602008A */   sh       $v0, 0x8a($s0)
glabel L802B661C_E2ACCC
/* E2ACCC 802B661C 96220008 */  lhu       $v0, 8($s1)
/* E2ACD0 802B6620 2442FFFF */  addiu     $v0, $v0, -1
/* E2ACD4 802B6624 A6220008 */  sh        $v0, 8($s1)
/* E2ACD8 802B6628 00021400 */  sll       $v0, $v0, 0x10
/* E2ACDC 802B662C 144000F0 */  bnez      $v0, L802B69F0_E2B0A0
/* E2ACE0 802B6630 00000000 */   nop
/* E2ACE4 802B6634 0C009C22 */  jal       func_80027088
/* E2ACE8 802B6638 0000202D */   daddu    $a0, $zero, $zero
/* E2ACEC 802B663C 3C048011 */  lui       $a0, %hi(D_8010C96C)
/* E2ACF0 802B6640 8C84C96C */  lw        $a0, %lo(D_8010C96C)($a0)
/* E2ACF4 802B6644 0C00E2B7 */  jal       get_npc_by_index
/* E2ACF8 802B6648 00000000 */   nop
/* E2ACFC 802B664C 0040802D */  daddu     $s0, $v0, $zero
/* E2AD00 802B6650 3C03FFFB */  lui       $v1, 0xfffb
/* E2AD04 802B6654 3463FFFF */  ori       $v1, $v1, 0xffff
/* E2AD08 802B6658 3C05FFEF */  lui       $a1, 0xffef
/* E2AD0C 802B665C 8E020000 */  lw        $v0, ($s0)
/* E2AD10 802B6660 34A5FFFF */  ori       $a1, $a1, 0xffff
/* E2AD14 802B6664 00431024 */  and       $v0, $v0, $v1
/* E2AD18 802B6668 AE020000 */  sw        $v0, ($s0)
/* E2AD1C 802B666C 8E220000 */  lw        $v0, ($s1)
/* E2AD20 802B6670 0000202D */  daddu     $a0, $zero, $zero
/* E2AD24 802B6674 00451024 */  and       $v0, $v0, $a1
/* E2AD28 802B6678 080ADA78 */  j         .L802B69E0
/* E2AD2C 802B667C AE220000 */   sw       $v0, ($s1)
glabel L802B6680_E2AD30
/* E2AD30 802B6680 96220008 */  lhu       $v0, 8($s1)
/* E2AD34 802B6684 2442FFFF */  addiu     $v0, $v0, -1
/* E2AD38 802B6688 A6220008 */  sh        $v0, 8($s1)
/* E2AD3C 802B668C 00021400 */  sll       $v0, $v0, 0x10
/* E2AD40 802B6690 14400004 */  bnez      $v0, .L802B66A4
/* E2AD44 802B6694 00000000 */   nop
/* E2AD48 802B6698 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2AD4C 802B669C 24420001 */  addiu     $v0, $v0, 1
/* E2AD50 802B66A0 A22200B6 */  sb        $v0, 0xb6($s1)
.L802B66A4:
/* E2AD54 802B66A4 0C0ADB3C */  jal       func_802B6CF0_E2B3A0
/* E2AD58 802B66A8 00000000 */   nop
/* E2AD5C 802B66AC C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2AD60 802B66B0 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AD64 802B66B4 080ADA54 */  j         .L802B6950
/* E2AD68 802B66B8 46006301 */   sub.s    $f12, $f12, $f0
glabel L802B66BC_E2AD6C
/* E2AD6C 802B66BC C63400A8 */  lwc1      $f20, 0xa8($s1)
/* E2AD70 802B66C0 0C0ADB3C */  jal       func_802B6CF0_E2B3A0
/* E2AD74 802B66C4 00000000 */   nop
/* E2AD78 802B66C8 C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2AD7C 802B66CC C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AD80 802B66D0 46006301 */  sub.s     $f12, $f12, $f0
/* E2AD84 802B66D4 3C0142B4 */  lui       $at, 0x42b4
/* E2AD88 802B66D8 44810000 */  mtc1      $at, $f0
/* E2AD8C 802B66DC 0C00A6C9 */  jal       clamp_angle
/* E2AD90 802B66E0 46006301 */   sub.s    $f12, $f12, $f0
/* E2AD94 802B66E4 86220008 */  lh        $v0, 8($s1)
/* E2AD98 802B66E8 96230008 */  lhu       $v1, 8($s1)
/* E2AD9C 802B66EC 1440003F */  bnez      $v0, .L802B67EC
/* E2ADA0 802B66F0 E6200080 */   swc1     $f0, 0x80($s1)
/* E2ADA4 802B66F4 C642001C */  lwc1      $f2, 0x1c($s2)
/* E2ADA8 802B66F8 44800000 */  mtc1      $zero, $f0
/* E2ADAC 802B66FC 00000000 */  nop
/* E2ADB0 802B6700 4602003C */  c.lt.s    $f0, $f2
/* E2ADB4 802B6704 00000000 */  nop
/* E2ADB8 802B6708 45000010 */  bc1f      .L802B674C
/* E2ADBC 802B670C 0000102D */   daddu    $v0, $zero, $zero
/* E2ADC0 802B6710 3C014387 */  lui       $at, 0x4387
/* E2ADC4 802B6714 44811000 */  mtc1      $at, $f2
/* E2ADC8 802B6718 00000000 */  nop
/* E2ADCC 802B671C 4602A03C */  c.lt.s    $f20, $f2
/* E2ADD0 802B6720 00000000 */  nop
/* E2ADD4 802B6724 45000006 */  bc1f      .L802B6740
/* E2ADD8 802B6728 00000000 */   nop
/* E2ADDC 802B672C C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2ADE0 802B6730 4600103E */  c.le.s    $f2, $f0
/* E2ADE4 802B6734 00000000 */  nop
/* E2ADE8 802B6738 45030001 */  bc1tl     .L802B6740
/* E2ADEC 802B673C 24020001 */   addiu    $v0, $zero, 1
.L802B6740:
/* E2ADF0 802B6740 C642001C */  lwc1      $f2, 0x1c($s2)
/* E2ADF4 802B6744 44800000 */  mtc1      $zero, $f0
/* E2ADF8 802B6748 00000000 */  nop
.L802B674C:
/* E2ADFC 802B674C 4600103C */  c.lt.s    $f2, $f0
/* E2AE00 802B6750 00000000 */  nop
/* E2AE04 802B6754 4500000D */  bc1f      .L802B678C
/* E2AE08 802B6758 00000000 */   nop
/* E2AE0C 802B675C 3C014387 */  lui       $at, 0x4387
/* E2AE10 802B6760 44811000 */  mtc1      $at, $f2
/* E2AE14 802B6764 00000000 */  nop
/* E2AE18 802B6768 4614103C */  c.lt.s    $f2, $f20
/* E2AE1C 802B676C 00000000 */  nop
/* E2AE20 802B6770 45000006 */  bc1f      .L802B678C
/* E2AE24 802B6774 00000000 */   nop
/* E2AE28 802B6778 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AE2C 802B677C 4602003E */  c.le.s    $f0, $f2
/* E2AE30 802B6780 00000000 */  nop
/* E2AE34 802B6784 45030001 */  bc1tl     .L802B678C
/* E2AE38 802B6788 24020001 */   addiu    $v0, $zero, 1
.L802B678C:
/* E2AE3C 802B678C 10400098 */  beqz      $v0, L802B69F0_E2B0A0
/* E2AE40 802B6790 24030002 */   addiu    $v1, $zero, 2
/* E2AE44 802B6794 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2AE48 802B6798 A6230008 */  sh        $v1, 8($s1)
/* E2AE4C 802B679C 2403DFFF */  addiu     $v1, $zero, -0x2001
/* E2AE50 802B67A0 24420001 */  addiu     $v0, $v0, 1
/* E2AE54 802B67A4 A22200B6 */  sb        $v0, 0xb6($s1)
/* E2AE58 802B67A8 8E220004 */  lw        $v0, 4($s1)
/* E2AE5C 802B67AC 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* E2AE60 802B67B0 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* E2AE64 802B67B4 00431024 */  and       $v0, $v0, $v1
/* E2AE68 802B67B8 AE220004 */  sw        $v0, 4($s1)
/* E2AE6C 802B67BC 9082007E */  lbu       $v0, 0x7e($a0)
/* E2AE70 802B67C0 304200FD */  andi      $v0, $v0, 0xfd
/* E2AE74 802B67C4 A082007E */  sb        $v0, 0x7e($a0)
/* E2AE78 802B67C8 3C048011 */  lui       $a0, %hi(D_8010C96C)
/* E2AE7C 802B67CC 8C84C96C */  lw        $a0, %lo(D_8010C96C)($a0)
/* E2AE80 802B67D0 0C00E228 */  jal       free_npc_by_index
/* E2AE84 802B67D4 A220000C */   sb       $zero, 0xc($s1)
/* E2AE88 802B67D8 24020037 */  addiu     $v0, $zero, 0x37
/* E2AE8C 802B67DC A62200B0 */  sh        $v0, 0xb0($s1)
/* E2AE90 802B67E0 24020026 */  addiu     $v0, $zero, 0x26
/* E2AE94 802B67E4 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AE98 802B67E8 A62200B2 */   sh       $v0, 0xb2($s1)
.L802B67EC:
/* E2AE9C 802B67EC 2462FFFF */  addiu     $v0, $v1, -1
/* E2AEA0 802B67F0 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AEA4 802B67F4 A6220008 */   sh       $v0, 8($s1)
glabel L802B67F8_E2AEA8
/* E2AEA8 802B67F8 96220008 */  lhu       $v0, 8($s1)
/* E2AEAC 802B67FC 2442FFFF */  addiu     $v0, $v0, -1
/* E2AEB0 802B6800 A6220008 */  sh        $v0, 8($s1)
/* E2AEB4 802B6804 00021400 */  sll       $v0, $v0, 0x10
/* E2AEB8 802B6808 14400004 */  bnez      $v0, .L802B681C
/* E2AEBC 802B680C 00000000 */   nop
/* E2AEC0 802B6810 922200B6 */  lbu       $v0, 0xb6($s1)
.L802B6814:
/* E2AEC4 802B6814 24420001 */  addiu     $v0, $v0, 1
/* E2AEC8 802B6818 A22200B6 */  sb        $v0, 0xb6($s1)
.L802B681C:
/* E2AECC 802B681C 0C0ADB3C */  jal       func_802B6CF0_E2B3A0
/* E2AED0 802B6820 00000000 */   nop
/* E2AED4 802B6824 080ADA7C */  j         L802B69F0_E2B0A0
/* E2AED8 802B6828 00000000 */   nop
glabel L802B682C_E2AEDC
/* E2AEDC 802B682C C640001C */  lwc1      $f0, 0x1c($s2)
/* E2AEE0 802B6830 44802000 */  mtc1      $zero, $f4
/* E2AEE4 802B6834 00000000 */  nop
/* E2AEE8 802B6838 4600203C */  c.lt.s    $f4, $f0
/* E2AEEC 802B683C 00000000 */  nop
/* E2AEF0 802B6840 4500001D */  bc1f      .L802B68B8
/* E2AEF4 802B6844 00000000 */   nop
/* E2AEF8 802B6848 C6400020 */  lwc1      $f0, 0x20($s2)
/* E2AEFC 802B684C 3C01802B */  lui       $at, %hi(D_802B6E70_E2B520)
/* E2AF00 802B6850 D4226E70 */  ldc1      $f2, %lo(D_802B6E70_E2B520)($at)
/* E2AF04 802B6854 46000021 */  cvt.d.s   $f0, $f0
/* E2AF08 802B6858 46220001 */  sub.d     $f0, $f0, $f2
/* E2AF0C 802B685C 46200020 */  cvt.s.d   $f0, $f0
/* E2AF10 802B6860 4604003E */  c.le.s    $f0, $f4
/* E2AF14 802B6864 00000000 */  nop
/* E2AF18 802B6868 45000032 */  bc1f      .L802B6934
/* E2AF1C 802B686C E6400020 */   swc1     $f0, 0x20($s2)
/* E2AF20 802B6870 2402000A */  addiu     $v0, $zero, 0xa
/* E2AF24 802B6874 E6440020 */  swc1      $f4, 0x20($s2)
/* E2AF28 802B6878 A6220008 */  sh        $v0, 8($s1)
/* E2AF2C 802B687C 922200B6 */  lbu       $v0, 0xb6($s1)
/* E2AF30 802B6880 3C014334 */  lui       $at, 0x4334
/* E2AF34 802B6884 44810000 */  mtc1      $at, $f0
/* E2AF38 802B6888 24420001 */  addiu     $v0, $v0, 1
/* E2AF3C 802B688C A22200B6 */  sb        $v0, 0xb6($s1)
/* E2AF40 802B6890 E62000A8 */  swc1      $f0, 0xa8($s1)
/* E2AF44 802B6894 C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2AF48 802B6898 46006301 */  sub.s     $f12, $f12, $f0
/* E2AF4C 802B689C 3C0142B4 */  lui       $at, 0x42b4
/* E2AF50 802B68A0 44810000 */  mtc1      $at, $f0
/* E2AF54 802B68A4 24020001 */  addiu     $v0, $zero, 1
/* E2AF58 802B68A8 3C018011 */  lui       $at, %hi(D_8010C95C)
/* E2AF5C 802B68AC AC22C95C */  sw        $v0, %lo(D_8010C95C)($at)
/* E2AF60 802B68B0 080ADA47 */  j         .L802B691C
/* E2AF64 802B68B4 46006301 */   sub.s    $f12, $f12, $f0
.L802B68B8:
/* E2AF68 802B68B8 C6400020 */  lwc1      $f0, 0x20($s2)
/* E2AF6C 802B68BC 3C01802B */  lui       $at, %hi(D_802B6E78_E2B528)
/* E2AF70 802B68C0 D4226E78 */  ldc1      $f2, %lo(D_802B6E78_E2B528)($at)
/* E2AF74 802B68C4 46000021 */  cvt.d.s   $f0, $f0
/* E2AF78 802B68C8 46220000 */  add.d     $f0, $f0, $f2
/* E2AF7C 802B68CC 46200020 */  cvt.s.d   $f0, $f0
/* E2AF80 802B68D0 4600203E */  c.le.s    $f4, $f0
/* E2AF84 802B68D4 00000000 */  nop
/* E2AF88 802B68D8 45000016 */  bc1f      .L802B6934
/* E2AF8C 802B68DC E6400020 */   swc1     $f0, 0x20($s2)
/* E2AF90 802B68E0 E6440020 */  swc1      $f4, 0x20($s2)
/* E2AF94 802B68E4 922300B6 */  lbu       $v1, 0xb6($s1)
/* E2AF98 802B68E8 2402000A */  addiu     $v0, $zero, 0xa
/* E2AF9C 802B68EC A6220008 */  sh        $v0, 8($s1)
/* E2AFA0 802B68F0 E62400A8 */  swc1      $f4, 0xa8($s1)
/* E2AFA4 802B68F4 24630001 */  addiu     $v1, $v1, 1
/* E2AFA8 802B68F8 A22300B6 */  sb        $v1, 0xb6($s1)
/* E2AFAC 802B68FC C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2AFB0 802B6900 46046301 */  sub.s     $f12, $f12, $f4
/* E2AFB4 802B6904 3C0142B4 */  lui       $at, 0x42b4
/* E2AFB8 802B6908 44810000 */  mtc1      $at, $f0
/* E2AFBC 802B690C 00000000 */  nop
/* E2AFC0 802B6910 46006301 */  sub.s     $f12, $f12, $f0
/* E2AFC4 802B6914 3C018011 */  lui       $at, %hi(D_8010C95C)
/* E2AFC8 802B6918 AC20C95C */  sw        $zero, %lo(D_8010C95C)($at)
.L802B691C:
/* E2AFCC 802B691C 0C00A6C9 */  jal       clamp_angle
/* E2AFD0 802B6920 00000000 */   nop
/* E2AFD4 802B6924 4600018D */  trunc.w.s $f6, $f0
/* E2AFD8 802B6928 3C01800F */  lui       $at, %hi(D_800F7B40)
/* E2AFDC 802B692C E4267B40 */  swc1      $f6, %lo(D_800F7B40)($at)
/* E2AFE0 802B6930 E6200084 */  swc1      $f0, 0x84($s1)
.L802B6934:
/* E2AFE4 802B6934 C62000A8 */  lwc1      $f0, 0xa8($s1)
/* E2AFE8 802B6938 C64C0020 */  lwc1      $f12, 0x20($s2)
/* E2AFEC 802B693C 0C00A6C9 */  jal       clamp_angle
/* E2AFF0 802B6940 460C0300 */   add.s    $f12, $f0, $f12
/* E2AFF4 802B6944 E62000A8 */  swc1      $f0, 0xa8($s1)
/* E2AFF8 802B6948 C66C006C */  lwc1      $f12, 0x6c($s3)
/* E2AFFC 802B694C 46006301 */  sub.s     $f12, $f12, $f0
.L802B6950:
/* E2B000 802B6950 3C0142B4 */  lui       $at, 0x42b4
/* E2B004 802B6954 44810000 */  mtc1      $at, $f0
/* E2B008 802B6958 0C00A6C9 */  jal       clamp_angle
/* E2B00C 802B695C 46006301 */   sub.s    $f12, $f12, $f0
/* E2B010 802B6960 080ADA7C */  j         L802B69F0_E2B0A0
/* E2B014 802B6964 E6200080 */   swc1     $f0, 0x80($s1)
glabel L802B6968_E2B018
/* E2B018 802B6968 96220008 */  lhu       $v0, 8($s1)
/* E2B01C 802B696C 2442FFFF */  addiu     $v0, $v0, -1
/* E2B020 802B6970 A6220008 */  sh        $v0, 8($s1)
/* E2B024 802B6974 00021400 */  sll       $v0, $v0, 0x10
/* E2B028 802B6978 1440001D */  bnez      $v0, L802B69F0_E2B0A0
/* E2B02C 802B697C 00000000 */   nop
/* E2B030 802B6980 0C009C22 */  jal       func_80027088
/* E2B034 802B6984 0000202D */   daddu    $a0, $zero, $zero
/* E2B038 802B6988 3C03FFEF */  lui       $v1, 0xffef
/* E2B03C 802B698C 3463FFFF */  ori       $v1, $v1, 0xffff
/* E2B040 802B6990 8E220000 */  lw        $v0, ($s1)
/* E2B044 802B6994 0000202D */  daddu     $a0, $zero, $zero
/* E2B048 802B6998 00431024 */  and       $v0, $v0, $v1
/* E2B04C 802B699C 080ADA78 */  j         .L802B69E0
/* E2B050 802B69A0 AE220000 */   sw       $v0, ($s1)
glabel L802B69A4_E2B054
/* E2B054 802B69A4 0C0398E9 */  jal       func_800E63A4
/* E2B058 802B69A8 0000202D */   daddu    $a0, $zero, $zero
/* E2B05C 802B69AC 080ADA7A */  j         .L802B69E8
/* E2B060 802B69B0 00000000 */   nop
glabel L802B69B4_E2B064
/* E2B064 802B69B4 962200BC */  lhu       $v0, 0xbc($s1)
/* E2B068 802B69B8 1040000D */  beqz      $v0, L802B69F0_E2B0A0
/* E2B06C 802B69BC 0000202D */   daddu    $a0, $zero, $zero
/* E2B070 802B69C0 080ADA78 */  j         .L802B69E0
/* E2B074 802B69C4 00000000 */   nop
glabel L802B69C8_E2B078
/* E2B078 802B69C8 96220008 */  lhu       $v0, 8($s1)
/* E2B07C 802B69CC 2442FFFF */  addiu     $v0, $v0, -1
/* E2B080 802B69D0 A6220008 */  sh        $v0, 8($s1)
/* E2B084 802B69D4 00021400 */  sll       $v0, $v0, 0x10
/* E2B088 802B69D8 14400005 */  bnez      $v0, L802B69F0_E2B0A0
/* E2B08C 802B69DC 0000202D */   daddu    $a0, $zero, $zero
.L802B69E0:
/* E2B090 802B69E0 0C039769 */  jal       set_action_state
/* E2B094 802B69E4 00000000 */   nop
.L802B69E8:
/* E2B098 802B69E8 0C038050 */  jal       enable_player_static_collisions
/* E2B09C 802B69EC 00000000 */   nop
glabel L802B69F0_E2B0A0
/* E2B0A0 802B69F0 8E430008 */  lw        $v1, 8($s2)
/* E2B0A4 802B69F4 18600084 */  blez      $v1, .L802B6C08
/* E2B0A8 802B69F8 2402000A */   addiu    $v0, $zero, 0xa
/* E2B0AC 802B69FC 2463FFFF */  addiu     $v1, $v1, -1
/* E2B0B0 802B6A00 14620042 */  bne       $v1, $v0, .L802B6B0C
/* E2B0B4 802B6A04 AE430008 */   sw       $v1, 8($s2)
/* E2B0B8 802B6A08 C62200A8 */  lwc1      $f2, 0xa8($s1)
/* E2B0BC 802B6A0C 3C0142B4 */  lui       $at, 0x42b4
/* E2B0C0 802B6A10 44810000 */  mtc1      $at, $f0
/* E2B0C4 802B6A14 00000000 */  nop
/* E2B0C8 802B6A18 4602003E */  c.le.s    $f0, $f2
/* E2B0CC 802B6A1C 00000000 */  nop
/* E2B0D0 802B6A20 45000016 */  bc1f      .L802B6A7C
/* E2B0D4 802B6A24 00000000 */   nop
/* E2B0D8 802B6A28 3C014387 */  lui       $at, 0x4387
/* E2B0DC 802B6A2C 44812000 */  mtc1      $at, $f4
/* E2B0E0 802B6A30 00000000 */  nop
/* E2B0E4 802B6A34 4604103C */  c.lt.s    $f2, $f4
/* E2B0E8 802B6A38 00000000 */  nop
/* E2B0EC 802B6A3C 4500000F */  bc1f      .L802B6A7C
/* E2B0F0 802B6A40 00000000 */   nop
/* E2B0F4 802B6A44 C660006C */  lwc1      $f0, 0x6c($s3)
/* E2B0F8 802B6A48 46040001 */  sub.s     $f0, $f0, $f4
/* E2B0FC 802B6A4C 3C0140C9 */  lui       $at, 0x40c9
/* E2B100 802B6A50 34210FD0 */  ori       $at, $at, 0xfd0
/* E2B104 802B6A54 44811000 */  mtc1      $at, $f2
/* E2B108 802B6A58 00000000 */  nop
/* E2B10C 802B6A5C 46020002 */  mul.s     $f0, $f0, $f2
/* E2B110 802B6A60 00000000 */  nop
/* E2B114 802B6A64 3C0143B4 */  lui       $at, 0x43b4
/* E2B118 802B6A68 44811000 */  mtc1      $at, $f2
/* E2B11C 802B6A6C 3C014238 */  lui       $at, 0x4238
/* E2B120 802B6A70 4481B000 */  mtc1      $at, $f22
/* E2B124 802B6A74 080ADAAF */  j         .L802B6ABC
/* E2B128 802B6A78 46020503 */   div.s    $f20, $f0, $f2
.L802B6A7C:
/* E2B12C 802B6A7C C662006C */  lwc1      $f2, 0x6c($s3)
/* E2B130 802B6A80 3C0142B4 */  lui       $at, 0x42b4
/* E2B134 802B6A84 44810000 */  mtc1      $at, $f0
/* E2B138 802B6A88 00000000 */  nop
/* E2B13C 802B6A8C 46001081 */  sub.s     $f2, $f2, $f0
/* E2B140 802B6A90 3C0140C9 */  lui       $at, 0x40c9
/* E2B144 802B6A94 34210FD0 */  ori       $at, $at, 0xfd0
/* E2B148 802B6A98 44810000 */  mtc1      $at, $f0
/* E2B14C 802B6A9C 00000000 */  nop
/* E2B150 802B6AA0 46001082 */  mul.s     $f2, $f2, $f0
/* E2B154 802B6AA4 00000000 */  nop
/* E2B158 802B6AA8 3C0143B4 */  lui       $at, 0x43b4
/* E2B15C 802B6AAC 44810000 */  mtc1      $at, $f0
/* E2B160 802B6AB0 3C0141F0 */  lui       $at, 0x41f0
/* E2B164 802B6AB4 4481B000 */  mtc1      $at, $f22
/* E2B168 802B6AB8 46001503 */  div.s     $f20, $f2, $f0
.L802B6ABC:
/* E2B16C 802B6ABC 0C00A85B */  jal       sin_rad
/* E2B170 802B6AC0 4600A306 */   mov.s    $f12, $f20
/* E2B174 802B6AC4 4600B002 */  mul.s     $f0, $f22, $f0
/* E2B178 802B6AC8 00000000 */  nop
/* E2B17C 802B6ACC C6220028 */  lwc1      $f2, 0x28($s1)
/* E2B180 802B6AD0 46001080 */  add.s     $f2, $f2, $f0
/* E2B184 802B6AD4 4600A306 */  mov.s     $f12, $f20
/* E2B188 802B6AD8 0C00A874 */  jal       cos_rad
/* E2B18C 802B6ADC E6420010 */   swc1     $f2, 0x10($s2)
/* E2B190 802B6AE0 4600B002 */  mul.s     $f0, $f22, $f0
/* E2B194 802B6AE4 00000000 */  nop
/* E2B198 802B6AE8 C624002C */  lwc1      $f4, 0x2c($s1)
/* E2B19C 802B6AEC 3C0141A0 */  lui       $at, 0x41a0
/* E2B1A0 802B6AF0 44811000 */  mtc1      $at, $f2
/* E2B1A4 802B6AF4 00000000 */  nop
/* E2B1A8 802B6AF8 46022101 */  sub.s     $f4, $f4, $f2
/* E2B1AC 802B6AFC C6220030 */  lwc1      $f2, 0x30($s1)
/* E2B1B0 802B6B00 46001081 */  sub.s     $f2, $f2, $f0
/* E2B1B4 802B6B04 E6440014 */  swc1      $f4, 0x14($s2)
/* E2B1B8 802B6B08 E6420018 */  swc1      $f2, 0x18($s2)
.L802B6B0C:
/* E2B1BC 802B6B0C 8E430008 */  lw        $v1, 8($s2)
/* E2B1C0 802B6B10 2862000B */  slti      $v0, $v1, 0xb
/* E2B1C4 802B6B14 10400050 */  beqz      $v0, .L802B6C58
/* E2B1C8 802B6B18 30620001 */   andi     $v0, $v1, 1
/* E2B1CC 802B6B1C 1040004E */  beqz      $v0, .L802B6C58
/* E2B1D0 802B6B20 00000000 */   nop
/* E2B1D4 802B6B24 C6420010 */  lwc1      $f2, 0x10($s2)
/* E2B1D8 802B6B28 3C014100 */  lui       $at, 0x4100
/* E2B1DC 802B6B2C 44810000 */  mtc1      $at, $f0
/* E2B1E0 802B6B30 00000000 */  nop
/* E2B1E4 802B6B34 46001081 */  sub.s     $f2, $f2, $f0
/* E2B1E8 802B6B38 3C014248 */  lui       $at, 0x4248
/* E2B1EC 802B6B3C 44810000 */  mtc1      $at, $f0
/* E2B1F0 802B6B40 44051000 */  mfc1      $a1, $f2
/* E2B1F4 802B6B44 C6420014 */  lwc1      $f2, 0x14($s2)
/* E2B1F8 802B6B48 46001080 */  add.s     $f2, $f2, $f0
/* E2B1FC 802B6B4C 8E470018 */  lw        $a3, 0x18($s2)
/* E2B200 802B6B50 3C014000 */  lui       $at, 0x4000
/* E2B204 802B6B54 44810000 */  mtc1      $at, $f0
/* E2B208 802B6B58 44061000 */  mfc1      $a2, $f2
/* E2B20C 802B6B5C 24040003 */  addiu     $a0, $zero, 3
/* E2B210 802B6B60 0C01BFBC */  jal       func_8006FEF0
/* E2B214 802B6B64 E7A00010 */   swc1     $f0, 0x10($sp)
/* E2B218 802B6B68 C660006C */  lwc1      $f0, 0x6c($s3)
/* E2B21C 802B6B6C C62200A8 */  lwc1      $f2, 0xa8($s1)
/* E2B220 802B6B70 46020000 */  add.s     $f0, $f0, $f2
/* E2B224 802B6B74 3C0142B4 */  lui       $at, 0x42b4
/* E2B228 802B6B78 44811000 */  mtc1      $at, $f2
/* E2B22C 802B6B7C 00000000 */  nop
/* E2B230 802B6B80 46020001 */  sub.s     $f0, $f0, $f2
/* E2B234 802B6B84 3C0140C9 */  lui       $at, 0x40c9
/* E2B238 802B6B88 34210FD0 */  ori       $at, $at, 0xfd0
/* E2B23C 802B6B8C 44811000 */  mtc1      $at, $f2
/* E2B240 802B6B90 00000000 */  nop
/* E2B244 802B6B94 46020002 */  mul.s     $f0, $f0, $f2
/* E2B248 802B6B98 00000000 */  nop
/* E2B24C 802B6B9C C6560010 */  lwc1      $f22, 0x10($s2)
/* E2B250 802B6BA0 3C0143B4 */  lui       $at, 0x43b4
/* E2B254 802B6BA4 44811000 */  mtc1      $at, $f2
/* E2B258 802B6BA8 4600B5A1 */  cvt.d.s   $f22, $f22
/* E2B25C 802B6BAC 46020503 */  div.s     $f20, $f0, $f2
/* E2B260 802B6BB0 0C00A85B */  jal       sin_rad
/* E2B264 802B6BB4 4600A306 */   mov.s    $f12, $f20
/* E2B268 802B6BB8 3C014024 */  lui       $at, 0x4024
/* E2B26C 802B6BBC 4481C800 */  mtc1      $at, $f25
/* E2B270 802B6BC0 4480C000 */  mtc1      $zero, $f24
/* E2B274 802B6BC4 46000021 */  cvt.d.s   $f0, $f0
/* E2B278 802B6BC8 46380002 */  mul.d     $f0, $f0, $f24
/* E2B27C 802B6BCC 00000000 */  nop
/* E2B280 802B6BD0 4600A306 */  mov.s     $f12, $f20
/* E2B284 802B6BD4 C6540018 */  lwc1      $f20, 0x18($s2)
/* E2B288 802B6BD8 4620B580 */  add.d     $f22, $f22, $f0
/* E2B28C 802B6BDC 4600A521 */  cvt.d.s   $f20, $f20
/* E2B290 802B6BE0 4620B5A0 */  cvt.s.d   $f22, $f22
/* E2B294 802B6BE4 0C00A874 */  jal       cos_rad
/* E2B298 802B6BE8 E6560010 */   swc1     $f22, 0x10($s2)
/* E2B29C 802B6BEC 46000021 */  cvt.d.s   $f0, $f0
/* E2B2A0 802B6BF0 46380002 */  mul.d     $f0, $f0, $f24
/* E2B2A4 802B6BF4 00000000 */  nop
/* E2B2A8 802B6BF8 4620A501 */  sub.d     $f20, $f20, $f0
/* E2B2AC 802B6BFC 4620A520 */  cvt.s.d   $f20, $f20
/* E2B2B0 802B6C00 080ADB16 */  j         .L802B6C58
/* E2B2B4 802B6C04 E6540018 */   swc1     $f20, 0x18($s2)
.L802B6C08:
/* E2B2B8 802B6C08 14600013 */  bnez      $v1, .L802B6C58
/* E2B2BC 802B6C0C 2402FFFF */   addiu    $v0, $zero, -1
/* E2B2C0 802B6C10 8E430000 */  lw        $v1, ($s2)
/* E2B2C4 802B6C14 10600010 */  beqz      $v1, .L802B6C58
/* E2B2C8 802B6C18 AE420008 */   sw       $v0, 8($s2)
/* E2B2CC 802B6C1C 3C013F80 */  lui       $at, 0x3f80
/* E2B2D0 802B6C20 44810000 */  mtc1      $at, $f0
/* E2B2D4 802B6C24 0060102D */  daddu     $v0, $v1, $zero
/* E2B2D8 802B6C28 E7A00010 */  swc1      $f0, 0x10($sp)
/* E2B2DC 802B6C2C 8442008A */  lh        $v0, 0x8a($v0)
/* E2B2E0 802B6C30 44820000 */  mtc1      $v0, $f0
/* E2B2E4 802B6C34 00000000 */  nop
/* E2B2E8 802B6C38 46800020 */  cvt.s.w   $f0, $f0
/* E2B2EC 802B6C3C E7A00014 */  swc1      $f0, 0x14($sp)
/* E2B2F0 802B6C40 8C650038 */  lw        $a1, 0x38($v1)
/* E2B2F4 802B6C44 8C66003C */  lw        $a2, 0x3c($v1)
/* E2B2F8 802B6C48 8224000D */  lb        $a0, 0xd($s1)
/* E2B2FC 802B6C4C 8C670040 */  lw        $a3, 0x40($v1)
/* E2B300 802B6C50 0C01CA84 */  jal       func_80072A10
/* E2B304 802B6C54 2484FFFF */   addiu    $a0, $a0, -1
.L802B6C58:
/* E2B308 802B6C58 8E43000C */  lw        $v1, 0xc($s2)
/* E2B30C 802B6C5C 1060001A */  beqz      $v1, .L802B6CC8
/* E2B310 802B6C60 2862000B */   slti     $v0, $v1, 0xb
/* E2B314 802B6C64 10400015 */  beqz      $v0, .L802B6CBC
/* E2B318 802B6C68 2402000A */   addiu    $v0, $zero, 0xa
/* E2B31C 802B6C6C 14620003 */  bne       $v1, $v0, .L802B6C7C
/* E2B320 802B6C70 240400FE */   addiu    $a0, $zero, 0xfe
/* E2B324 802B6C74 0C052736 */  jal       play_sound_at_player
/* E2B328 802B6C78 0000282D */   daddu    $a1, $zero, $zero
.L802B6C7C:
/* E2B32C 802B6C7C 8E42000C */  lw        $v0, 0xc($s2)
/* E2B330 802B6C80 30420003 */  andi      $v0, $v0, 3
/* E2B334 802B6C84 1440000D */  bnez      $v0, .L802B6CBC
/* E2B338 802B6C88 24040004 */   addiu    $a0, $zero, 4
/* E2B33C 802B6C8C 8E250028 */  lw        $a1, 0x28($s1)
/* E2B340 802B6C90 8E26002C */  lw        $a2, 0x2c($s1)
/* E2B344 802B6C94 8E270030 */  lw        $a3, 0x30($s1)
/* E2B348 802B6C98 3C014248 */  lui       $at, 0x4248
/* E2B34C 802B6C9C 44810000 */  mtc1      $at, $f0
/* E2B350 802B6CA0 24020028 */  addiu     $v0, $zero, 0x28
/* E2B354 802B6CA4 AFA20018 */  sw        $v0, 0x18($sp)
/* E2B358 802B6CA8 2402001E */  addiu     $v0, $zero, 0x1e
/* E2B35C 802B6CAC AFA2001C */  sw        $v0, 0x1c($sp)
/* E2B360 802B6CB0 E7A00010 */  swc1      $f0, 0x10($sp)
/* E2B364 802B6CB4 0C01C154 */  jal       func_80070550
/* E2B368 802B6CB8 E7A00014 */   swc1     $f0, 0x14($sp)
.L802B6CBC:
/* E2B36C 802B6CBC 8E42000C */  lw        $v0, 0xc($s2)
/* E2B370 802B6CC0 2442FFFF */  addiu     $v0, $v0, -1
/* E2B374 802B6CC4 AE42000C */  sw        $v0, 0xc($s2)
.L802B6CC8:
/* E2B378 802B6CC8 8FBF0030 */  lw        $ra, 0x30($sp)
/* E2B37C 802B6CCC 8FB3002C */  lw        $s3, 0x2c($sp)
/* E2B380 802B6CD0 8FB20028 */  lw        $s2, 0x28($sp)
/* E2B384 802B6CD4 8FB10024 */  lw        $s1, 0x24($sp)
/* E2B388 802B6CD8 8FB00020 */  lw        $s0, 0x20($sp)
/* E2B38C 802B6CDC D7B80048 */  ldc1      $f24, 0x48($sp)
/* E2B390 802B6CE0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* E2B394 802B6CE4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* E2B398 802B6CE8 03E00008 */  jr        $ra
/* E2B39C 802B6CEC 27BD0050 */   addiu    $sp, $sp, 0x50
