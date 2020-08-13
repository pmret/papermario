.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800DDD94
/* 077244 800DDD94 27BDFF90 */  addiu $sp, $sp, -0x70
/* 077248 800DDD98 F7B40058 */  sdc1  $f20, 0x58($sp)
/* 07724C 800DDD9C C7B4008C */  lwc1  $f20, 0x8c($sp)
/* 077250 800DDDA0 C7A40080 */  lwc1  $f4, 0x80($sp)
/* 077254 800DDDA4 AFB7004C */  sw    $s7, 0x4c($sp)
/* 077258 800DDDA8 0080B82D */  daddu $s7, $a0, $zero
/* 07725C 800DDDAC AFB10034 */  sw    $s1, 0x34($sp)
/* 077260 800DDDB0 00A0882D */  daddu $s1, $a1, $zero
/* 077264 800DDDB4 AFB60048 */  sw    $s6, 0x48($sp)
/* 077268 800DDDB8 00C0B02D */  daddu $s6, $a2, $zero
/* 07726C 800DDDBC AFB20038 */  sw    $s2, 0x38($sp)
/* 077270 800DDDC0 00E0902D */  daddu $s2, $a3, $zero
/* 077274 800DDDC4 AFB40040 */  sw    $s4, 0x40($sp)
/* 077278 800DDDC8 0000A02D */  daddu $s4, $zero, $zero
/* 07727C 800DDDCC F7B80068 */  sdc1  $f24, 0x68($sp)
/* 077280 800DDDD0 C7B80084 */  lwc1  $f24, 0x84($sp)
/* 077284 800DDDD4 C7A20088 */  lwc1  $f2, 0x88($sp)
/* 077288 800DDDD8 AFBF0050 */  sw    $ra, 0x50($sp)
/* 07728C 800DDDDC AFB50044 */  sw    $s5, 0x44($sp)
/* 077290 800DDDE0 AFB3003C */  sw    $s3, 0x3c($sp)
/* 077294 800DDDE4 AFB00030 */  sw    $s0, 0x30($sp)
/* 077298 800DDDE8 F7B60060 */  sdc1  $f22, 0x60($sp)
/* 07729C 800DDDEC C6200000 */  lwc1  $f0, ($s1)
/* 0772A0 800DDDF0 27B50020 */  addiu $s5, $sp, 0x20
/* 0772A4 800DDDF4 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0772A8 800DDDF8 C6C00000 */  lwc1  $f0, ($s6)
/* 0772AC 800DDDFC 02A0282D */  daddu $a1, $s5, $zero
/* 0772B0 800DDE00 46020000 */  add.s $f0, $f0, $f2
/* 0772B4 800DDE04 3C013F80 */  lui   $at, 0x3f80
/* 0772B8 800DDE08 44811000 */  mtc1  $at, $f2
/* 0772BC 800DDE0C 27B30024 */  addiu $s3, $sp, 0x24
/* 0772C0 800DDE10 46020001 */  sub.s $f0, $f0, $f2
/* 0772C4 800DDE14 3C013F00 */  lui   $at, 0x3f00
/* 0772C8 800DDE18 44811000 */  mtc1  $at, $f2
/* 0772CC 800DDE1C 0260302D */  daddu $a2, $s3, $zero
/* 0772D0 800DDE20 4602A502 */  mul.s $f20, $f20, $f2
/* 0772D4 800DDE24 00000000 */  nop   
/* 0772D8 800DDE28 27B00028 */  addiu $s0, $sp, 0x28
/* 0772DC 800DDE2C 0200382D */  daddu $a3, $s0, $zero
/* 0772E0 800DDE30 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0772E4 800DDE34 C6400000 */  lwc1  $f0, ($s2)
/* 0772E8 800DDE38 46002585 */  abs.s $f22, $f4
/* 0772EC 800DDE3C E7A00028 */  swc1  $f0, 0x28($sp)
/* 0772F0 800DDE40 E7B60010 */  swc1  $f22, 0x10($sp)
/* 0772F4 800DDE44 E7B80014 */  swc1  $f24, 0x14($sp)
/* 0772F8 800DDE48 0C037586 */  jal   func_800DD618
/* 0772FC 800DDE4C E7B40018 */   swc1  $f20, 0x18($sp)
/* 077300 800DDE50 04400006 */  bltz  $v0, .L800DDE6C
/* 077304 800DDE54 00000000 */   nop   
/* 077308 800DDE58 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07730C 800DDE5C E6200000 */  swc1  $f0, ($s1)
/* 077310 800DDE60 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 077314 800DDE64 24140004 */  addiu $s4, $zero, 4
/* 077318 800DDE68 E6400000 */  swc1  $f0, ($s2)
.L800DDE6C:
/* 07731C 800DDE6C C6200000 */  lwc1  $f0, ($s1)
/* 077320 800DDE70 3C0141A0 */  lui   $at, 0x41a0
/* 077324 800DDE74 44811000 */  mtc1  $at, $f2
/* 077328 800DDE78 E7A00020 */  swc1  $f0, 0x20($sp)
/* 07732C 800DDE7C C6C00000 */  lwc1  $f0, ($s6)
/* 077330 800DDE80 02E0202D */  daddu $a0, $s7, $zero
/* 077334 800DDE84 46020000 */  add.s $f0, $f0, $f2
/* 077338 800DDE88 02A0282D */  daddu $a1, $s5, $zero
/* 07733C 800DDE8C 0260302D */  daddu $a2, $s3, $zero
/* 077340 800DDE90 E7A00024 */  swc1  $f0, 0x24($sp)
/* 077344 800DDE94 C6400000 */  lwc1  $f0, ($s2)
/* 077348 800DDE98 0200382D */  daddu $a3, $s0, $zero
/* 07734C 800DDE9C E7A00028 */  swc1  $f0, 0x28($sp)
/* 077350 800DDEA0 E7B60010 */  swc1  $f22, 0x10($sp)
/* 077354 800DDEA4 E7B80014 */  swc1  $f24, 0x14($sp)
/* 077358 800DDEA8 0C037586 */  jal   func_800DD618
/* 07735C 800DDEAC E7B40018 */   swc1  $f20, 0x18($sp)
/* 077360 800DDEB0 04400006 */  bltz  $v0, .L800DDECC
/* 077364 800DDEB4 00000000 */   nop   
/* 077368 800DDEB8 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07736C 800DDEBC E6200000 */  swc1  $f0, ($s1)
/* 077370 800DDEC0 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 077374 800DDEC4 24140003 */  addiu $s4, $zero, 3
/* 077378 800DDEC8 E6400000 */  swc1  $f0, ($s2)
.L800DDECC:
/* 07737C 800DDECC C6200000 */  lwc1  $f0, ($s1)
/* 077380 800DDED0 3C014170 */  lui   $at, 0x4170
/* 077384 800DDED4 342128F6 */  ori   $at, $at, 0x28f6
/* 077388 800DDED8 44811000 */  mtc1  $at, $f2
/* 07738C 800DDEDC E7A00020 */  swc1  $f0, 0x20($sp)
/* 077390 800DDEE0 C6C00000 */  lwc1  $f0, ($s6)
/* 077394 800DDEE4 02E0202D */  daddu $a0, $s7, $zero
/* 077398 800DDEE8 46020000 */  add.s $f0, $f0, $f2
/* 07739C 800DDEEC 02A0282D */  daddu $a1, $s5, $zero
/* 0773A0 800DDEF0 0260302D */  daddu $a2, $s3, $zero
/* 0773A4 800DDEF4 E7A00024 */  swc1  $f0, 0x24($sp)
/* 0773A8 800DDEF8 C6400000 */  lwc1  $f0, ($s2)
/* 0773AC 800DDEFC 0200382D */  daddu $a3, $s0, $zero
/* 0773B0 800DDF00 E7A00028 */  swc1  $f0, 0x28($sp)
/* 0773B4 800DDF04 E7B60010 */  swc1  $f22, 0x10($sp)
/* 0773B8 800DDF08 E7B80014 */  swc1  $f24, 0x14($sp)
/* 0773BC 800DDF0C 0C037586 */  jal   func_800DD618
/* 0773C0 800DDF10 E7B40018 */   swc1  $f20, 0x18($sp)
/* 0773C4 800DDF14 04400006 */  bltz  $v0, .L800DDF30
/* 0773C8 800DDF18 00000000 */   nop   
/* 0773CC 800DDF1C C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0773D0 800DDF20 E6200000 */  swc1  $f0, ($s1)
/* 0773D4 800DDF24 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 0773D8 800DDF28 24140002 */  addiu $s4, $zero, 2
/* 0773DC 800DDF2C E6400000 */  swc1  $f0, ($s2)
.L800DDF30:
/* 0773E0 800DDF30 C6200000 */  lwc1  $f0, ($s1)
/* 0773E4 800DDF34 3C014120 */  lui   $at, 0x4120
/* 0773E8 800DDF38 342128F6 */  ori   $at, $at, 0x28f6
/* 0773EC 800DDF3C 44811000 */  mtc1  $at, $f2
/* 0773F0 800DDF40 E7A00020 */  swc1  $f0, 0x20($sp)
/* 0773F4 800DDF44 C6C00000 */  lwc1  $f0, ($s6)
/* 0773F8 800DDF48 02E0202D */  daddu $a0, $s7, $zero
/* 0773FC 800DDF4C 46020000 */  add.s $f0, $f0, $f2
/* 077400 800DDF50 02A0282D */  daddu $a1, $s5, $zero
/* 077404 800DDF54 0260302D */  daddu $a2, $s3, $zero
/* 077408 800DDF58 E7A00024 */  swc1  $f0, 0x24($sp)
/* 07740C 800DDF5C C6400000 */  lwc1  $f0, ($s2)
/* 077410 800DDF60 0200382D */  daddu $a3, $s0, $zero
/* 077414 800DDF64 E7A00028 */  swc1  $f0, 0x28($sp)
/* 077418 800DDF68 E7B60010 */  swc1  $f22, 0x10($sp)
/* 07741C 800DDF6C E7B80014 */  swc1  $f24, 0x14($sp)
/* 077420 800DDF70 0C037586 */  jal   func_800DD618
/* 077424 800DDF74 E7B40018 */   swc1  $f20, 0x18($sp)
/* 077428 800DDF78 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 07742C 800DDF7C E6200000 */  swc1  $f0, ($s1)
/* 077430 800DDF80 C7A00028 */  lwc1  $f0, 0x28($sp)
/* 077434 800DDF84 04400002 */  bltz  $v0, .L800DDF90
/* 077438 800DDF88 E6400000 */   swc1  $f0, ($s2)
/* 07743C 800DDF8C 24140001 */  addiu $s4, $zero, 1
.L800DDF90:
/* 077440 800DDF90 0280102D */  daddu $v0, $s4, $zero
/* 077444 800DDF94 8FBF0050 */  lw    $ra, 0x50($sp)
/* 077448 800DDF98 8FB7004C */  lw    $s7, 0x4c($sp)
/* 07744C 800DDF9C 8FB60048 */  lw    $s6, 0x48($sp)
/* 077450 800DDFA0 8FB50044 */  lw    $s5, 0x44($sp)
/* 077454 800DDFA4 8FB40040 */  lw    $s4, 0x40($sp)
/* 077458 800DDFA8 8FB3003C */  lw    $s3, 0x3c($sp)
/* 07745C 800DDFAC 8FB20038 */  lw    $s2, 0x38($sp)
/* 077460 800DDFB0 8FB10034 */  lw    $s1, 0x34($sp)
/* 077464 800DDFB4 8FB00030 */  lw    $s0, 0x30($sp)
/* 077468 800DDFB8 D7B80068 */  ldc1  $f24, 0x68($sp)
/* 07746C 800DDFBC D7B60060 */  ldc1  $f22, 0x60($sp)
/* 077470 800DDFC0 D7B40058 */  ldc1  $f20, 0x58($sp)
/* 077474 800DDFC4 03E00008 */  jr    $ra
/* 077478 800DDFC8 27BD0070 */   addiu $sp, $sp, 0x70

/* 07747C 800DDFCC 00000000 */  nop   
