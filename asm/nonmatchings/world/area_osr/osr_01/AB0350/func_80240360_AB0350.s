.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_AB0350
/* AB0350 80240360 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AB0354 80240364 AFB00010 */  sw        $s0, 0x10($sp)
/* AB0358 80240368 3C108024 */  lui       $s0, %hi(func_802411B8_887578)
/* AB035C 8024036C 261011B8 */  addiu     $s0, $s0, %lo(func_802411B8_887578)
/* AB0360 80240370 AFBF0018 */  sw        $ra, 0x18($sp)
/* AB0364 80240374 AFB10014 */  sw        $s1, 0x14($sp)
/* AB0368 80240378 8E020000 */  lw        $v0, ($s0)
/* AB036C 8024037C 14400010 */  bnez      $v0, .L802403C0
/* AB0370 80240380 0080882D */   daddu    $s1, $a0, $zero
/* AB0374 80240384 0C00AB39 */  jal       heap_malloc
/* AB0378 80240388 24040040 */   addiu    $a0, $zero, 0x40
/* AB037C 8024038C AE020000 */  sw        $v0, ($s0)
/* AB0380 80240390 0000182D */  daddu     $v1, $zero, $zero
/* AB0384 80240394 0040282D */  daddu     $a1, $v0, $zero
/* AB0388 80240398 0220202D */  daddu     $a0, $s1, $zero
.L8024039C:
/* AB038C 8024039C 8C820084 */  lw        $v0, 0x84($a0)
/* AB0390 802403A0 24840004 */  addiu     $a0, $a0, 4
/* AB0394 802403A4 24630001 */  addiu     $v1, $v1, 1
/* AB0398 802403A8 ACA20000 */  sw        $v0, ($a1)
/* AB039C 802403AC 28620010 */  slti      $v0, $v1, 0x10
/* AB03A0 802403B0 1440FFFA */  bnez      $v0, .L8024039C
/* AB03A4 802403B4 24A50004 */   addiu    $a1, $a1, 4
/* AB03A8 802403B8 080900FF */  j         .L802403FC
/* AB03AC 802403BC 00000000 */   nop      
.L802403C0:
/* AB03B0 802403C0 0000182D */  daddu     $v1, $zero, $zero
/* AB03B4 802403C4 0040282D */  daddu     $a1, $v0, $zero
/* AB03B8 802403C8 0220202D */  daddu     $a0, $s1, $zero
.L802403CC:
/* AB03BC 802403CC 8CA20000 */  lw        $v0, ($a1)
/* AB03C0 802403D0 24A50004 */  addiu     $a1, $a1, 4
/* AB03C4 802403D4 24630001 */  addiu     $v1, $v1, 1
/* AB03C8 802403D8 AC820084 */  sw        $v0, 0x84($a0)
/* AB03CC 802403DC 28620010 */  slti      $v0, $v1, 0x10
/* AB03D0 802403E0 1440FFFA */  bnez      $v0, .L802403CC
/* AB03D4 802403E4 24840004 */   addiu    $a0, $a0, 4
/* AB03D8 802403E8 3C108024 */  lui       $s0, %hi(func_802411B8_887578)
/* AB03DC 802403EC 261011B8 */  addiu     $s0, $s0, %lo(func_802411B8_887578)
/* AB03E0 802403F0 0C00AB4B */  jal       heap_free
/* AB03E4 802403F4 8E040000 */   lw       $a0, ($s0)
/* AB03E8 802403F8 AE000000 */  sw        $zero, ($s0)
.L802403FC:
/* AB03EC 802403FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* AB03F0 80240400 8FB10014 */  lw        $s1, 0x14($sp)
/* AB03F4 80240404 8FB00010 */  lw        $s0, 0x10($sp)
/* AB03F8 80240408 24020002 */  addiu     $v0, $zero, 2
/* AB03FC 8024040C 03E00008 */  jr        $ra
/* AB0400 80240410 27BD0020 */   addiu    $sp, $sp, 0x20
