.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402C8_8CABC8
/* 8CABC8 802402C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8CABCC 802402CC AFB00010 */  sw        $s0, 0x10($sp)
/* 8CABD0 802402D0 3C108024 */  lui       $s0, %hi(D_802429F4_8CD2F4)
/* 8CABD4 802402D4 261029F4 */  addiu     $s0, $s0, %lo(D_802429F4_8CD2F4)
/* 8CABD8 802402D8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8CABDC 802402DC AFB10014 */  sw        $s1, 0x14($sp)
/* 8CABE0 802402E0 8E020000 */  lw        $v0, ($s0)
/* 8CABE4 802402E4 14400010 */  bnez      $v0, .L80240328
/* 8CABE8 802402E8 0080882D */   daddu    $s1, $a0, $zero
/* 8CABEC 802402EC 0C00AB39 */  jal       heap_malloc
/* 8CABF0 802402F0 24040040 */   addiu    $a0, $zero, 0x40
/* 8CABF4 802402F4 AE020000 */  sw        $v0, ($s0)
/* 8CABF8 802402F8 0000182D */  daddu     $v1, $zero, $zero
/* 8CABFC 802402FC 0040282D */  daddu     $a1, $v0, $zero
/* 8CAC00 80240300 0220202D */  daddu     $a0, $s1, $zero
.L80240304:
/* 8CAC04 80240304 8C820084 */  lw        $v0, 0x84($a0)
/* 8CAC08 80240308 24840004 */  addiu     $a0, $a0, 4
/* 8CAC0C 8024030C 24630001 */  addiu     $v1, $v1, 1
/* 8CAC10 80240310 ACA20000 */  sw        $v0, ($a1)
/* 8CAC14 80240314 28620010 */  slti      $v0, $v1, 0x10
/* 8CAC18 80240318 1440FFFA */  bnez      $v0, .L80240304
/* 8CAC1C 8024031C 24A50004 */   addiu    $a1, $a1, 4
/* 8CAC20 80240320 080900D9 */  j         .L80240364
/* 8CAC24 80240324 00000000 */   nop
.L80240328:
/* 8CAC28 80240328 0000182D */  daddu     $v1, $zero, $zero
/* 8CAC2C 8024032C 0040282D */  daddu     $a1, $v0, $zero
/* 8CAC30 80240330 0220202D */  daddu     $a0, $s1, $zero
.L80240334:
/* 8CAC34 80240334 8CA20000 */  lw        $v0, ($a1)
/* 8CAC38 80240338 24A50004 */  addiu     $a1, $a1, 4
/* 8CAC3C 8024033C 24630001 */  addiu     $v1, $v1, 1
/* 8CAC40 80240340 AC820084 */  sw        $v0, 0x84($a0)
/* 8CAC44 80240344 28620010 */  slti      $v0, $v1, 0x10
/* 8CAC48 80240348 1440FFFA */  bnez      $v0, .L80240334
/* 8CAC4C 8024034C 24840004 */   addiu    $a0, $a0, 4
/* 8CAC50 80240350 3C108024 */  lui       $s0, %hi(D_802429F4_8CD2F4)
/* 8CAC54 80240354 261029F4 */  addiu     $s0, $s0, %lo(D_802429F4_8CD2F4)
/* 8CAC58 80240358 0C00AB4B */  jal       heap_free
/* 8CAC5C 8024035C 8E040000 */   lw       $a0, ($s0)
/* 8CAC60 80240360 AE000000 */  sw        $zero, ($s0)
.L80240364:
/* 8CAC64 80240364 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8CAC68 80240368 8FB10014 */  lw        $s1, 0x14($sp)
/* 8CAC6C 8024036C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CAC70 80240370 24020002 */  addiu     $v0, $zero, 2
/* 8CAC74 80240374 03E00008 */  jr        $ra
/* 8CAC78 80240378 27BD0020 */   addiu    $sp, $sp, 0x20
