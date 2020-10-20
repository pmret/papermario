.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240940_BC87A0
/* BC87A0 80240940 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC87A4 80240944 AFB00010 */  sw        $s0, 0x10($sp)
/* BC87A8 80240948 3C108024 */  lui       $s0, 0x8024
/* BC87AC 8024094C 26103A10 */  addiu     $s0, $s0, 0x3a10
/* BC87B0 80240950 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC87B4 80240954 AFB10014 */  sw        $s1, 0x14($sp)
/* BC87B8 80240958 8E020000 */  lw        $v0, ($s0)
/* BC87BC 8024095C 14400010 */  bnez      $v0, .L802409A0
/* BC87C0 80240960 0080882D */   daddu    $s1, $a0, $zero
/* BC87C4 80240964 0C00AB39 */  jal       heap_malloc
/* BC87C8 80240968 24040040 */   addiu    $a0, $zero, 0x40
/* BC87CC 8024096C AE020000 */  sw        $v0, ($s0)
/* BC87D0 80240970 0000182D */  daddu     $v1, $zero, $zero
/* BC87D4 80240974 0040282D */  daddu     $a1, $v0, $zero
/* BC87D8 80240978 0220202D */  daddu     $a0, $s1, $zero
.L8024097C:
/* BC87DC 8024097C 8C820084 */  lw        $v0, 0x84($a0)
/* BC87E0 80240980 24840004 */  addiu     $a0, $a0, 4
/* BC87E4 80240984 24630001 */  addiu     $v1, $v1, 1
/* BC87E8 80240988 ACA20000 */  sw        $v0, ($a1)
/* BC87EC 8024098C 28620010 */  slti      $v0, $v1, 0x10
/* BC87F0 80240990 1440FFFA */  bnez      $v0, .L8024097C
/* BC87F4 80240994 24A50004 */   addiu    $a1, $a1, 4
/* BC87F8 80240998 08090277 */  j         .L802409DC
/* BC87FC 8024099C 00000000 */   nop      
.L802409A0:
/* BC8800 802409A0 0000182D */  daddu     $v1, $zero, $zero
/* BC8804 802409A4 0040282D */  daddu     $a1, $v0, $zero
/* BC8808 802409A8 0220202D */  daddu     $a0, $s1, $zero
.L802409AC:
/* BC880C 802409AC 8CA20000 */  lw        $v0, ($a1)
/* BC8810 802409B0 24A50004 */  addiu     $a1, $a1, 4
/* BC8814 802409B4 24630001 */  addiu     $v1, $v1, 1
/* BC8818 802409B8 AC820084 */  sw        $v0, 0x84($a0)
/* BC881C 802409BC 28620010 */  slti      $v0, $v1, 0x10
/* BC8820 802409C0 1440FFFA */  bnez      $v0, .L802409AC
/* BC8824 802409C4 24840004 */   addiu    $a0, $a0, 4
/* BC8828 802409C8 3C108024 */  lui       $s0, 0x8024
/* BC882C 802409CC 26103A10 */  addiu     $s0, $s0, 0x3a10
/* BC8830 802409D0 0C00AB4B */  jal       heap_free
/* BC8834 802409D4 8E040000 */   lw       $a0, ($s0)
/* BC8838 802409D8 AE000000 */  sw        $zero, ($s0)
.L802409DC:
/* BC883C 802409DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC8840 802409E0 8FB10014 */  lw        $s1, 0x14($sp)
/* BC8844 802409E4 8FB00010 */  lw        $s0, 0x10($sp)
/* BC8848 802409E8 24020002 */  addiu     $v0, $zero, 2
/* BC884C 802409EC 03E00008 */  jr        $ra
/* BC8850 802409F0 27BD0020 */   addiu    $sp, $sp, 0x20
