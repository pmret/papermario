.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024061C_CAC80C
/* CAC80C 8024061C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAC810 80240620 AFB00010 */  sw        $s0, 0x10($sp)
/* CAC814 80240624 3C108024 */  lui       $s0, %hi(D_80241BB0)
/* CAC818 80240628 26101BB0 */  addiu     $s0, $s0, %lo(D_80241BB0)
/* CAC81C 8024062C AFBF0018 */  sw        $ra, 0x18($sp)
/* CAC820 80240630 AFB10014 */  sw        $s1, 0x14($sp)
/* CAC824 80240634 8E020000 */  lw        $v0, ($s0)
/* CAC828 80240638 14400010 */  bnez      $v0, .L8024067C
/* CAC82C 8024063C 0080882D */   daddu    $s1, $a0, $zero
/* CAC830 80240640 0C00AB39 */  jal       heap_malloc
/* CAC834 80240644 24040040 */   addiu    $a0, $zero, 0x40
/* CAC838 80240648 AE020000 */  sw        $v0, ($s0)
/* CAC83C 8024064C 0000182D */  daddu     $v1, $zero, $zero
/* CAC840 80240650 0040282D */  daddu     $a1, $v0, $zero
/* CAC844 80240654 0220202D */  daddu     $a0, $s1, $zero
.L80240658:
/* CAC848 80240658 8C820084 */  lw        $v0, 0x84($a0)
/* CAC84C 8024065C 24840004 */  addiu     $a0, $a0, 4
/* CAC850 80240660 24630001 */  addiu     $v1, $v1, 1
/* CAC854 80240664 ACA20000 */  sw        $v0, ($a1)
/* CAC858 80240668 28620010 */  slti      $v0, $v1, 0x10
/* CAC85C 8024066C 1440FFFA */  bnez      $v0, .L80240658
/* CAC860 80240670 24A50004 */   addiu    $a1, $a1, 4
/* CAC864 80240674 080901AE */  j         .L802406B8
/* CAC868 80240678 00000000 */   nop
.L8024067C:
/* CAC86C 8024067C 0000182D */  daddu     $v1, $zero, $zero
/* CAC870 80240680 0040282D */  daddu     $a1, $v0, $zero
/* CAC874 80240684 0220202D */  daddu     $a0, $s1, $zero
.L80240688:
/* CAC878 80240688 8CA20000 */  lw        $v0, ($a1)
/* CAC87C 8024068C 24A50004 */  addiu     $a1, $a1, 4
/* CAC880 80240690 24630001 */  addiu     $v1, $v1, 1
/* CAC884 80240694 AC820084 */  sw        $v0, 0x84($a0)
/* CAC888 80240698 28620010 */  slti      $v0, $v1, 0x10
/* CAC88C 8024069C 1440FFFA */  bnez      $v0, .L80240688
/* CAC890 802406A0 24840004 */   addiu    $a0, $a0, 4
/* CAC894 802406A4 3C108024 */  lui       $s0, %hi(D_80241BB0)
/* CAC898 802406A8 26101BB0 */  addiu     $s0, $s0, %lo(D_80241BB0)
/* CAC89C 802406AC 0C00AB4B */  jal       heap_free
/* CAC8A0 802406B0 8E040000 */   lw       $a0, ($s0)
/* CAC8A4 802406B4 AE000000 */  sw        $zero, ($s0)
.L802406B8:
/* CAC8A8 802406B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAC8AC 802406BC 8FB10014 */  lw        $s1, 0x14($sp)
/* CAC8B0 802406C0 8FB00010 */  lw        $s0, 0x10($sp)
/* CAC8B4 802406C4 24020002 */  addiu     $v0, $zero, 2
/* CAC8B8 802406C8 03E00008 */  jr        $ra
/* CAC8BC 802406CC 27BD0020 */   addiu    $sp, $sp, 0x20
