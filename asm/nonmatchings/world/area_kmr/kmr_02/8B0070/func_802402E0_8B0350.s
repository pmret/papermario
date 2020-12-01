.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402E0_8B0350
/* 8B0350 802402E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B0354 802402E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B0358 802402E8 0080882D */  daddu     $s1, $a0, $zero
/* 8B035C 802402EC AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B0360 802402F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B0364 802402F4 8E30000C */  lw        $s0, 0xc($s1)
/* 8B0368 802402F8 8E050000 */  lw        $a1, ($s0)
/* 8B036C 802402FC 0C0B1EAF */  jal       get_variable
/* 8B0370 80240300 26100004 */   addiu    $s0, $s0, 4
/* 8B0374 80240304 0220202D */  daddu     $a0, $s1, $zero
/* 8B0378 80240308 8E050000 */  lw        $a1, ($s0)
/* 8B037C 8024030C 0C0B1EAF */  jal       get_variable
/* 8B0380 80240310 0040802D */   daddu    $s0, $v0, $zero
/* 8B0384 80240314 0200202D */  daddu     $a0, $s0, $zero
/* 8B0388 80240318 00021080 */  sll       $v0, $v0, 2
/* 8B038C 8024031C 3C108024 */  lui       $s0, %hi(D_80244B2C)
/* 8B0390 80240320 02028021 */  addu      $s0, $s0, $v0
/* 8B0394 80240324 0C00FB3A */  jal       get_enemy
/* 8B0398 80240328 8E104B2C */   lw       $s0, %lo(D_80244B2C)($s0)
/* 8B039C 8024032C 0040302D */  daddu     $a2, $v0, $zero
/* 8B03A0 80240330 0000282D */  daddu     $a1, $zero, $zero
.L80240334:
/* 8B03A4 80240334 8E040000 */  lw        $a0, ($s0)
/* 8B03A8 80240338 00051080 */  sll       $v0, $a1, 2
/* 8B03AC 8024033C 8CC300D0 */  lw        $v1, 0xd0($a2)
/* 8B03B0 80240340 24A50001 */  addiu     $a1, $a1, 1
/* 8B03B4 80240344 00431021 */  addu      $v0, $v0, $v1
/* 8B03B8 80240348 AC440000 */  sw        $a0, ($v0)
/* 8B03BC 8024034C 28A2000E */  slti      $v0, $a1, 0xe
/* 8B03C0 80240350 1440FFF8 */  bnez      $v0, .L80240334
/* 8B03C4 80240354 26100004 */   addiu    $s0, $s0, 4
/* 8B03C8 80240358 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B03CC 8024035C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B03D0 80240360 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B03D4 80240364 24020002 */  addiu     $v0, $zero, 2
/* 8B03D8 80240368 03E00008 */  jr        $ra
/* 8B03DC 8024036C 27BD0020 */   addiu    $sp, $sp, 0x20
