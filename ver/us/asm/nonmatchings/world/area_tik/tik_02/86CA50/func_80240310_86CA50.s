.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240310_86CA50
/* 86CA50 80240310 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 86CA54 80240314 AFB00010 */  sw        $s0, 0x10($sp)
/* 86CA58 80240318 3C108024 */  lui       $s0, %hi(D_802410C0_86D800)
/* 86CA5C 8024031C 261010C0 */  addiu     $s0, $s0, %lo(D_802410C0_86D800)
/* 86CA60 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* 86CA64 80240324 AFB10014 */  sw        $s1, 0x14($sp)
/* 86CA68 80240328 8E020000 */  lw        $v0, ($s0)
/* 86CA6C 8024032C 14400010 */  bnez      $v0, .L80240370
/* 86CA70 80240330 0080882D */   daddu    $s1, $a0, $zero
/* 86CA74 80240334 0C00AB39 */  jal       heap_malloc
/* 86CA78 80240338 24040040 */   addiu    $a0, $zero, 0x40
/* 86CA7C 8024033C AE020000 */  sw        $v0, ($s0)
/* 86CA80 80240340 0000182D */  daddu     $v1, $zero, $zero
/* 86CA84 80240344 0040282D */  daddu     $a1, $v0, $zero
/* 86CA88 80240348 0220202D */  daddu     $a0, $s1, $zero
.L8024034C:
/* 86CA8C 8024034C 8C820084 */  lw        $v0, 0x84($a0)
/* 86CA90 80240350 24840004 */  addiu     $a0, $a0, 4
/* 86CA94 80240354 24630001 */  addiu     $v1, $v1, 1
/* 86CA98 80240358 ACA20000 */  sw        $v0, ($a1)
/* 86CA9C 8024035C 28620010 */  slti      $v0, $v1, 0x10
/* 86CAA0 80240360 1440FFFA */  bnez      $v0, .L8024034C
/* 86CAA4 80240364 24A50004 */   addiu    $a1, $a1, 4
/* 86CAA8 80240368 080900EB */  j         .L802403AC
/* 86CAAC 8024036C 00000000 */   nop
.L80240370:
/* 86CAB0 80240370 0000182D */  daddu     $v1, $zero, $zero
/* 86CAB4 80240374 0040282D */  daddu     $a1, $v0, $zero
/* 86CAB8 80240378 0220202D */  daddu     $a0, $s1, $zero
.L8024037C:
/* 86CABC 8024037C 8CA20000 */  lw        $v0, ($a1)
/* 86CAC0 80240380 24A50004 */  addiu     $a1, $a1, 4
/* 86CAC4 80240384 24630001 */  addiu     $v1, $v1, 1
/* 86CAC8 80240388 AC820084 */  sw        $v0, 0x84($a0)
/* 86CACC 8024038C 28620010 */  slti      $v0, $v1, 0x10
/* 86CAD0 80240390 1440FFFA */  bnez      $v0, .L8024037C
/* 86CAD4 80240394 24840004 */   addiu    $a0, $a0, 4
/* 86CAD8 80240398 3C108024 */  lui       $s0, %hi(D_802410C0_86D800)
/* 86CADC 8024039C 261010C0 */  addiu     $s0, $s0, %lo(D_802410C0_86D800)
/* 86CAE0 802403A0 0C00AB4B */  jal       heap_free
/* 86CAE4 802403A4 8E040000 */   lw       $a0, ($s0)
/* 86CAE8 802403A8 AE000000 */  sw        $zero, ($s0)
.L802403AC:
/* 86CAEC 802403AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 86CAF0 802403B0 8FB10014 */  lw        $s1, 0x14($sp)
/* 86CAF4 802403B4 8FB00010 */  lw        $s0, 0x10($sp)
/* 86CAF8 802403B8 24020002 */  addiu     $v0, $zero, 2
/* 86CAFC 802403BC 03E00008 */  jr        $ra
/* 86CB00 802403C0 27BD0020 */   addiu    $sp, $sp, 0x20
