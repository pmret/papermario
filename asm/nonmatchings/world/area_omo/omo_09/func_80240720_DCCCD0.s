.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240720_DCD3F0
/* DCD3F0 80240720 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCD3F4 80240724 AFB00010 */  sw        $s0, 0x10($sp)
/* DCD3F8 80240728 3C108024 */  lui       $s0, 0x8024
/* DCD3FC 8024072C 26107010 */  addiu     $s0, $s0, 0x7010
/* DCD400 80240730 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCD404 80240734 AFB10014 */  sw        $s1, 0x14($sp)
/* DCD408 80240738 8E020000 */  lw        $v0, ($s0)
/* DCD40C 8024073C 14400010 */  bnez      $v0, .L80240780
/* DCD410 80240740 0080882D */   daddu    $s1, $a0, $zero
/* DCD414 80240744 0C00AB39 */  jal       heap_malloc
/* DCD418 80240748 24040040 */   addiu    $a0, $zero, 0x40
/* DCD41C 8024074C AE020000 */  sw        $v0, ($s0)
/* DCD420 80240750 0000182D */  daddu     $v1, $zero, $zero
/* DCD424 80240754 0040282D */  daddu     $a1, $v0, $zero
/* DCD428 80240758 0220202D */  daddu     $a0, $s1, $zero
.L8024075C:
/* DCD42C 8024075C 8C820084 */  lw        $v0, 0x84($a0)
/* DCD430 80240760 24840004 */  addiu     $a0, $a0, 4
/* DCD434 80240764 24630001 */  addiu     $v1, $v1, 1
/* DCD438 80240768 ACA20000 */  sw        $v0, ($a1)
/* DCD43C 8024076C 28620010 */  slti      $v0, $v1, 0x10
/* DCD440 80240770 1440FFFA */  bnez      $v0, .L8024075C
/* DCD444 80240774 24A50004 */   addiu    $a1, $a1, 4
/* DCD448 80240778 080901EF */  j         .L802407BC
/* DCD44C 8024077C 00000000 */   nop      
.L80240780:
/* DCD450 80240780 0000182D */  daddu     $v1, $zero, $zero
/* DCD454 80240784 0040282D */  daddu     $a1, $v0, $zero
/* DCD458 80240788 0220202D */  daddu     $a0, $s1, $zero
.L8024078C:
/* DCD45C 8024078C 8CA20000 */  lw        $v0, ($a1)
/* DCD460 80240790 24A50004 */  addiu     $a1, $a1, 4
/* DCD464 80240794 24630001 */  addiu     $v1, $v1, 1
/* DCD468 80240798 AC820084 */  sw        $v0, 0x84($a0)
/* DCD46C 8024079C 28620010 */  slti      $v0, $v1, 0x10
/* DCD470 802407A0 1440FFFA */  bnez      $v0, .L8024078C
/* DCD474 802407A4 24840004 */   addiu    $a0, $a0, 4
/* DCD478 802407A8 3C108024 */  lui       $s0, 0x8024
/* DCD47C 802407AC 26107010 */  addiu     $s0, $s0, 0x7010
/* DCD480 802407B0 0C00AB4B */  jal       heap_free
/* DCD484 802407B4 8E040000 */   lw       $a0, ($s0)
/* DCD488 802407B8 AE000000 */  sw        $zero, ($s0)
.L802407BC:
/* DCD48C 802407BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCD490 802407C0 8FB10014 */  lw        $s1, 0x14($sp)
/* DCD494 802407C4 8FB00010 */  lw        $s0, 0x10($sp)
/* DCD498 802407C8 24020002 */  addiu     $v0, $zero, 2
/* DCD49C 802407CC 03E00008 */  jr        $ra
/* DCD4A0 802407D0 27BD0020 */   addiu    $sp, $sp, 0x20
