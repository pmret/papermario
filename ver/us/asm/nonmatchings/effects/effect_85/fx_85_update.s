.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_85_update
/* 3AAA2C E00AA10C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3AAA30 E00AA110 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3AAA34 E00AA114 AFB00010 */  sw        $s0, 0x10($sp)
/* 3AAA38 E00AA118 F7BA0030 */  sdc1      $f26, 0x30($sp)
/* 3AAA3C E00AA11C F7B80028 */  sdc1      $f24, 0x28($sp)
/* 3AAA40 E00AA120 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 3AAA44 E00AA124 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 3AAA48 E00AA128 8C830000 */  lw        $v1, ($a0)
/* 3AAA4C E00AA12C 8C90000C */  lw        $s0, 0xc($a0)
/* 3AAA50 E00AA130 30620010 */  andi      $v0, $v1, 0x10
/* 3AAA54 E00AA134 10400005 */  beqz      $v0, .LE00AA14C
/* 3AAA58 E00AA138 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3AAA5C E00AA13C 00621024 */  and       $v0, $v1, $v0
/* 3AAA60 E00AA140 AC820000 */  sw        $v0, ($a0)
/* 3AAA64 E00AA144 24020384 */  addiu     $v0, $zero, 0x384
/* 3AAA68 E00AA148 AE020004 */  sw        $v0, 4($s0)
.LE00AA14C:
/* 3AAA6C E00AA14C 8E030004 */  lw        $v1, 4($s0)
/* 3AAA70 E00AA150 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3AAA74 E00AA154 10400002 */  beqz      $v0, .LE00AA160
/* 3AAA78 E00AA158 2462FFFF */   addiu    $v0, $v1, -1
/* 3AAA7C E00AA15C AE020004 */  sw        $v0, 4($s0)
.LE00AA160:
/* 3AAA80 E00AA160 8E020008 */  lw        $v0, 8($s0)
/* 3AAA84 E00AA164 8E030004 */  lw        $v1, 4($s0)
/* 3AAA88 E00AA168 24420001 */  addiu     $v0, $v0, 1
/* 3AAA8C E00AA16C 04610005 */  bgez      $v1, .LE00AA184
/* 3AAA90 E00AA170 AE020008 */   sw       $v0, 8($s0)
/* 3AAA94 E00AA174 0C080128 */  jal       shim_remove_effect
/* 3AAA98 E00AA178 00000000 */   nop
/* 3AAA9C E00AA17C 0802A8E8 */  j         .LE00AA3A0
/* 3AAAA0 E00AA180 00000000 */   nop
.LE00AA184:
/* 3AAAA4 E00AA184 28620010 */  slti      $v0, $v1, 0x10
/* 3AAAA8 E00AA188 10400002 */  beqz      $v0, .LE00AA194
/* 3AAAAC E00AA18C 00031100 */   sll      $v0, $v1, 4
/* 3AAAB0 E00AA190 AE020024 */  sw        $v0, 0x24($s0)
.LE00AA194:
/* 3AAAB4 E00AA194 8E020030 */  lw        $v0, 0x30($s0)
/* 3AAAB8 E00AA198 2442FFFF */  addiu     $v0, $v0, -1
/* 3AAABC E00AA19C 1C40006D */  bgtz      $v0, .LE00AA354
/* 3AAAC0 E00AA1A0 AE020030 */   sw       $v0, 0x30($s0)
/* 3AAAC4 E00AA1A4 0C080138 */  jal       shim_rand_int
/* 3AAAC8 E00AA1A8 24040167 */   addiu    $a0, $zero, 0x167
/* 3AAACC E00AA1AC 4482A000 */  mtc1      $v0, $f20
/* 3AAAD0 E00AA1B0 00000000 */  nop
/* 3AAAD4 E00AA1B4 4680A520 */  cvt.s.w   $f20, $f20
/* 3AAAD8 E00AA1B8 0C080140 */  jal       shim_sin_deg
/* 3AAADC E00AA1BC 4600A306 */   mov.s    $f12, $f20
/* 3AAAE0 E00AA1C0 C6020034 */  lwc1      $f2, 0x34($s0)
/* 3AAAE4 E00AA1C4 46001082 */  mul.s     $f2, $f2, $f0
/* 3AAAE8 E00AA1C8 00000000 */  nop
/* 3AAAEC E00AA1CC C6000038 */  lwc1      $f0, 0x38($s0)
/* 3AAAF0 E00AA1D0 C6180018 */  lwc1      $f24, 0x18($s0)
/* 3AAAF4 E00AA1D4 4600028D */  trunc.w.s $f10, $f0
/* 3AAAF8 E00AA1D8 44045000 */  mfc1      $a0, $f10
/* 3AAAFC E00AA1DC 0C080138 */  jal       shim_rand_int
/* 3AAB00 E00AA1E0 4602C600 */   add.s    $f24, $f24, $f2
/* 3AAB04 E00AA1E4 4600A306 */  mov.s     $f12, $f20
/* 3AAB08 E00AA1E8 C616001C */  lwc1      $f22, 0x1c($s0)
/* 3AAB0C E00AA1EC 44820000 */  mtc1      $v0, $f0
/* 3AAB10 E00AA1F0 00000000 */  nop
/* 3AAB14 E00AA1F4 46800020 */  cvt.s.w   $f0, $f0
/* 3AAB18 E00AA1F8 0C080144 */  jal       shim_cos_deg
/* 3AAB1C E00AA1FC 4600B580 */   add.s    $f22, $f22, $f0
/* 3AAB20 E00AA200 C6020034 */  lwc1      $f2, 0x34($s0)
/* 3AAB24 E00AA204 46001082 */  mul.s     $f2, $f2, $f0
/* 3AAB28 E00AA208 00000000 */  nop
/* 3AAB2C E00AA20C C6140020 */  lwc1      $f20, 0x20($s0)
/* 3AAB30 E00AA210 24040064 */  addiu     $a0, $zero, 0x64
/* 3AAB34 E00AA214 0C080138 */  jal       shim_rand_int
/* 3AAB38 E00AA218 4602A500 */   add.s    $f20, $f20, $f2
/* 3AAB3C E00AA21C C604000C */  lwc1      $f4, 0xc($s0)
/* 3AAB40 E00AA220 4604C601 */  sub.s     $f24, $f24, $f4
/* 3AAB44 E00AA224 C6060010 */  lwc1      $f6, 0x10($s0)
/* 3AAB48 E00AA228 4606B581 */  sub.s     $f22, $f22, $f6
/* 3AAB4C E00AA22C C6080014 */  lwc1      $f8, 0x14($s0)
/* 3AAB50 E00AA230 44801000 */  mtc1      $zero, $f2
/* 3AAB54 E00AA234 4608A501 */  sub.s     $f20, $f20, $f8
/* 3AAB58 E00AA238 2442000A */  addiu     $v0, $v0, 0xa
/* 3AAB5C E00AA23C 4602C032 */  c.eq.s    $f24, $f2
/* 3AAB60 E00AA240 00000000 */  nop
/* 3AAB64 E00AA244 4500001E */  bc1f      .LE00AA2C0
/* 3AAB68 E00AA248 AE020030 */   sw       $v0, 0x30($s0)
/* 3AAB6C E00AA24C 4602B032 */  c.eq.s    $f22, $f2
/* 3AAB70 E00AA250 00000000 */  nop
/* 3AAB74 E00AA254 4500001A */  bc1f      .LE00AA2C0
/* 3AAB78 E00AA258 00000000 */   nop
/* 3AAB7C E00AA25C 4602A032 */  c.eq.s    $f20, $f2
/* 3AAB80 E00AA260 00000000 */  nop
/* 3AAB84 E00AA264 45000016 */  bc1f      .LE00AA2C0
/* 3AAB88 E00AA268 00000000 */   nop
/* 3AAB8C E00AA26C C6000018 */  lwc1      $f0, 0x18($s0)
/* 3AAB90 E00AA270 46040601 */  sub.s     $f24, $f0, $f4
/* 3AAB94 E00AA274 C600001C */  lwc1      $f0, 0x1c($s0)
/* 3AAB98 E00AA278 46060581 */  sub.s     $f22, $f0, $f6
/* 3AAB9C E00AA27C C6000020 */  lwc1      $f0, 0x20($s0)
/* 3AABA0 E00AA280 4602C032 */  c.eq.s    $f24, $f2
/* 3AABA4 E00AA284 00000000 */  nop
/* 3AABA8 E00AA288 4500000D */  bc1f      .LE00AA2C0
/* 3AABAC E00AA28C 46080501 */   sub.s    $f20, $f0, $f8
/* 3AABB0 E00AA290 4602B032 */  c.eq.s    $f22, $f2
/* 3AABB4 E00AA294 00000000 */  nop
/* 3AABB8 E00AA298 45000009 */  bc1f      .LE00AA2C0
/* 3AABBC E00AA29C 00000000 */   nop
/* 3AABC0 E00AA2A0 4602A032 */  c.eq.s    $f20, $f2
/* 3AABC4 E00AA2A4 00000000 */  nop
/* 3AABC8 E00AA2A8 45000005 */  bc1f      .LE00AA2C0
/* 3AABCC E00AA2AC 00000000 */   nop
/* 3AABD0 E00AA2B0 3C013F80 */  lui       $at, 0x3f80
/* 3AABD4 E00AA2B4 4481C000 */  mtc1      $at, $f24
/* 3AABD8 E00AA2B8 46001506 */  mov.s     $f20, $f2
/* 3AABDC E00AA2BC 46001586 */  mov.s     $f22, $f2
.LE00AA2C0:
/* 3AABE0 E00AA2C0 4618C002 */  mul.s     $f0, $f24, $f24
/* 3AABE4 E00AA2C4 00000000 */  nop
/* 3AABE8 E00AA2C8 4616B082 */  mul.s     $f2, $f22, $f22
/* 3AABEC E00AA2CC 00000000 */  nop
/* 3AABF0 E00AA2D0 4614A102 */  mul.s     $f4, $f20, $f20
/* 3AABF4 E00AA2D4 00000000 */  nop
/* 3AABF8 E00AA2D8 46020000 */  add.s     $f0, $f0, $f2
/* 3AABFC E00AA2DC 46040300 */  add.s     $f12, $f0, $f4
/* 3AAC00 E00AA2E0 4480D000 */  mtc1      $zero, $f26
/* 3AAC04 E00AA2E4 00000000 */  nop
/* 3AAC08 E00AA2E8 461A6032 */  c.eq.s    $f12, $f26
/* 3AAC0C E00AA2EC 00000000 */  nop
/* 3AAC10 E00AA2F0 45010007 */  bc1t      .LE00AA310
/* 3AAC14 E00AA2F4 00000000 */   nop
/* 3AAC18 E00AA2F8 0C080154 */  jal       shim_sqrtf
/* 3AAC1C E00AA2FC 00000000 */   nop
/* 3AAC20 E00AA300 3C013F80 */  lui       $at, 0x3f80
/* 3AAC24 E00AA304 44811000 */  mtc1      $at, $f2
/* 3AAC28 E00AA308 00000000 */  nop
/* 3AAC2C E00AA30C 46001303 */  div.s     $f12, $f2, $f0
.LE00AA310:
/* 3AAC30 E00AA310 460CC602 */  mul.s     $f24, $f24, $f12
/* 3AAC34 E00AA314 00000000 */  nop
/* 3AAC38 E00AA318 460CA502 */  mul.s     $f20, $f20, $f12
/* 3AAC3C E00AA31C 00000000 */  nop
/* 3AAC40 E00AA320 460CB582 */  mul.s     $f22, $f22, $f12
/* 3AAC44 E00AA324 00000000 */  nop
/* 3AAC48 E00AA328 4600D306 */  mov.s     $f12, $f26
/* 3AAC4C E00AA32C E618003C */  swc1      $f24, 0x3c($s0)
/* 3AAC50 E00AA330 4600C006 */  mov.s     $f0, $f24
/* 3AAC54 E00AA334 4407A000 */  mfc1      $a3, $f20
/* 3AAC58 E00AA338 46000007 */  neg.s     $f0, $f0
/* 3AAC5C E00AA33C 44060000 */  mfc1      $a2, $f0
/* 3AAC60 E00AA340 46006386 */  mov.s     $f14, $f12
/* 3AAC64 E00AA344 E6160040 */  swc1      $f22, 0x40($s0)
/* 3AAC68 E00AA348 0C080148 */  jal       shim_atan2
/* 3AAC6C E00AA34C E6140044 */   swc1     $f20, 0x44($s0)
/* 3AAC70 E00AA350 E6000028 */  swc1      $f0, 0x28($s0)
.LE00AA354:
/* 3AAC74 E00AA354 8E03002C */  lw        $v1, 0x2c($s0)
/* 3AAC78 E00AA358 24620003 */  addiu     $v0, $v1, 3
/* 3AAC7C E00AA35C AE02002C */  sw        $v0, 0x2c($s0)
/* 3AAC80 E00AA360 2842001E */  slti      $v0, $v0, 0x1e
/* 3AAC84 E00AA364 14400002 */  bnez      $v0, .LE00AA370
/* 3AAC88 E00AA368 2462FFE5 */   addiu    $v0, $v1, -0x1b
/* 3AAC8C E00AA36C AE02002C */  sw        $v0, 0x2c($s0)
.LE00AA370:
/* 3AAC90 E00AA370 C606000C */  lwc1      $f6, 0xc($s0)
/* 3AAC94 E00AA374 C600003C */  lwc1      $f0, 0x3c($s0)
/* 3AAC98 E00AA378 C6040010 */  lwc1      $f4, 0x10($s0)
/* 3AAC9C E00AA37C 46003180 */  add.s     $f6, $f6, $f0
/* 3AACA0 E00AA380 C6000040 */  lwc1      $f0, 0x40($s0)
/* 3AACA4 E00AA384 C6020014 */  lwc1      $f2, 0x14($s0)
/* 3AACA8 E00AA388 46002100 */  add.s     $f4, $f4, $f0
/* 3AACAC E00AA38C C6000044 */  lwc1      $f0, 0x44($s0)
/* 3AACB0 E00AA390 46001080 */  add.s     $f2, $f2, $f0
/* 3AACB4 E00AA394 E606000C */  swc1      $f6, 0xc($s0)
/* 3AACB8 E00AA398 E6040010 */  swc1      $f4, 0x10($s0)
/* 3AACBC E00AA39C E6020014 */  swc1      $f2, 0x14($s0)
.LE00AA3A0:
/* 3AACC0 E00AA3A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3AACC4 E00AA3A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 3AACC8 E00AA3A8 D7BA0030 */  ldc1      $f26, 0x30($sp)
/* 3AACCC E00AA3AC D7B80028 */  ldc1      $f24, 0x28($sp)
/* 3AACD0 E00AA3B0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 3AACD4 E00AA3B4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 3AACD8 E00AA3B8 03E00008 */  jr        $ra
/* 3AACDC E00AA3BC 27BD0038 */   addiu    $sp, $sp, 0x38
