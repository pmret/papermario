.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240630_7EB340
/* 7EB340 80240630 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EB344 80240634 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EB348 80240638 3C108024 */  lui       $s0, %hi(D_80245DC0)
/* 7EB34C 8024063C 26105DC0 */  addiu     $s0, $s0, %lo(D_80245DC0)
/* 7EB350 80240640 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EB354 80240644 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EB358 80240648 8E020000 */  lw        $v0, ($s0)
/* 7EB35C 8024064C 14400010 */  bnez      $v0, .L80240690
/* 7EB360 80240650 0080882D */   daddu    $s1, $a0, $zero
/* 7EB364 80240654 0C00AB39 */  jal       heap_malloc
/* 7EB368 80240658 24040040 */   addiu    $a0, $zero, 0x40
/* 7EB36C 8024065C AE020000 */  sw        $v0, ($s0)
/* 7EB370 80240660 0000182D */  daddu     $v1, $zero, $zero
/* 7EB374 80240664 0040282D */  daddu     $a1, $v0, $zero
/* 7EB378 80240668 0220202D */  daddu     $a0, $s1, $zero
.L8024066C:
/* 7EB37C 8024066C 8C820084 */  lw        $v0, 0x84($a0)
/* 7EB380 80240670 24840004 */  addiu     $a0, $a0, 4
/* 7EB384 80240674 24630001 */  addiu     $v1, $v1, 1
/* 7EB388 80240678 ACA20000 */  sw        $v0, ($a1)
/* 7EB38C 8024067C 28620010 */  slti      $v0, $v1, 0x10
/* 7EB390 80240680 1440FFFA */  bnez      $v0, .L8024066C
/* 7EB394 80240684 24A50004 */   addiu    $a1, $a1, 4
/* 7EB398 80240688 080901B3 */  j         .L802406CC
/* 7EB39C 8024068C 00000000 */   nop      
.L80240690:
/* 7EB3A0 80240690 0000182D */  daddu     $v1, $zero, $zero
/* 7EB3A4 80240694 0040282D */  daddu     $a1, $v0, $zero
/* 7EB3A8 80240698 0220202D */  daddu     $a0, $s1, $zero
.L8024069C:
/* 7EB3AC 8024069C 8CA20000 */  lw        $v0, ($a1)
/* 7EB3B0 802406A0 24A50004 */  addiu     $a1, $a1, 4
/* 7EB3B4 802406A4 24630001 */  addiu     $v1, $v1, 1
/* 7EB3B8 802406A8 AC820084 */  sw        $v0, 0x84($a0)
/* 7EB3BC 802406AC 28620010 */  slti      $v0, $v1, 0x10
/* 7EB3C0 802406B0 1440FFFA */  bnez      $v0, .L8024069C
/* 7EB3C4 802406B4 24840004 */   addiu    $a0, $a0, 4
/* 7EB3C8 802406B8 3C108024 */  lui       $s0, %hi(D_80245DC0)
/* 7EB3CC 802406BC 26105DC0 */  addiu     $s0, $s0, %lo(D_80245DC0)
/* 7EB3D0 802406C0 0C00AB4B */  jal       heap_free
/* 7EB3D4 802406C4 8E040000 */   lw       $a0, ($s0)
/* 7EB3D8 802406C8 AE000000 */  sw        $zero, ($s0)
.L802406CC:
/* 7EB3DC 802406CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EB3E0 802406D0 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EB3E4 802406D4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EB3E8 802406D8 24020002 */  addiu     $v0, $zero, 2
/* 7EB3EC 802406DC 03E00008 */  jr        $ra
/* 7EB3F0 802406E0 27BD0020 */   addiu    $sp, $sp, 0x20
