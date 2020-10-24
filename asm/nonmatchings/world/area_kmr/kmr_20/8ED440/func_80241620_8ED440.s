.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241620_8ED440
/* 8ED440 80241620 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ED444 80241624 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED448 80241628 3C108025 */  lui       $s0, 0x8025
/* 8ED44C 8024162C 2610A908 */  addiu     $s0, $s0, -0x56f8
/* 8ED450 80241630 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8ED454 80241634 AFB10014 */  sw        $s1, 0x14($sp)
/* 8ED458 80241638 8E020000 */  lw        $v0, ($s0)
/* 8ED45C 8024163C 14400010 */  bnez      $v0, .L80241680
/* 8ED460 80241640 0080882D */   daddu    $s1, $a0, $zero
/* 8ED464 80241644 0C00AB39 */  jal       heap_malloc
/* 8ED468 80241648 24040040 */   addiu    $a0, $zero, 0x40
/* 8ED46C 8024164C AE020000 */  sw        $v0, ($s0)
/* 8ED470 80241650 0000182D */  daddu     $v1, $zero, $zero
/* 8ED474 80241654 0040282D */  daddu     $a1, $v0, $zero
/* 8ED478 80241658 0220202D */  daddu     $a0, $s1, $zero
.L8024165C:
/* 8ED47C 8024165C 8C820084 */  lw        $v0, 0x84($a0)
/* 8ED480 80241660 24840004 */  addiu     $a0, $a0, 4
/* 8ED484 80241664 24630001 */  addiu     $v1, $v1, 1
/* 8ED488 80241668 ACA20000 */  sw        $v0, ($a1)
/* 8ED48C 8024166C 28620010 */  slti      $v0, $v1, 0x10
/* 8ED490 80241670 1440FFFA */  bnez      $v0, .L8024165C
/* 8ED494 80241674 24A50004 */   addiu    $a1, $a1, 4
/* 8ED498 80241678 080905AF */  j         .L802416BC
/* 8ED49C 8024167C 00000000 */   nop      
.L80241680:
/* 8ED4A0 80241680 0000182D */  daddu     $v1, $zero, $zero
/* 8ED4A4 80241684 0040282D */  daddu     $a1, $v0, $zero
/* 8ED4A8 80241688 0220202D */  daddu     $a0, $s1, $zero
.L8024168C:
/* 8ED4AC 8024168C 8CA20000 */  lw        $v0, ($a1)
/* 8ED4B0 80241690 24A50004 */  addiu     $a1, $a1, 4
/* 8ED4B4 80241694 24630001 */  addiu     $v1, $v1, 1
/* 8ED4B8 80241698 AC820084 */  sw        $v0, 0x84($a0)
/* 8ED4BC 8024169C 28620010 */  slti      $v0, $v1, 0x10
/* 8ED4C0 802416A0 1440FFFA */  bnez      $v0, .L8024168C
/* 8ED4C4 802416A4 24840004 */   addiu    $a0, $a0, 4
/* 8ED4C8 802416A8 3C108025 */  lui       $s0, 0x8025
/* 8ED4CC 802416AC 2610A908 */  addiu     $s0, $s0, -0x56f8
/* 8ED4D0 802416B0 0C00AB4B */  jal       heap_free
/* 8ED4D4 802416B4 8E040000 */   lw       $a0, ($s0)
/* 8ED4D8 802416B8 AE000000 */  sw        $zero, ($s0)
.L802416BC:
/* 8ED4DC 802416BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8ED4E0 802416C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ED4E4 802416C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED4E8 802416C8 24020002 */  addiu     $v0, $zero, 2
/* 8ED4EC 802416CC 03E00008 */  jr        $ra
/* 8ED4F0 802416D0 27BD0020 */   addiu    $sp, $sp, 0x20
