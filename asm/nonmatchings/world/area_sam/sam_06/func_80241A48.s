.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A48
/* D218D8 80241A48 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D218DC 80241A4C AFB00010 */  sw        $s0, 0x10($sp)
/* D218E0 80241A50 3C108024 */  lui       $s0, 0x8024
/* D218E4 80241A54 261043D0 */  addiu     $s0, $s0, 0x43d0
/* D218E8 80241A58 AFBF0018 */  sw        $ra, 0x18($sp)
/* D218EC 80241A5C AFB10014 */  sw        $s1, 0x14($sp)
/* D218F0 80241A60 8E020000 */  lw        $v0, ($s0)
/* D218F4 80241A64 14400010 */  bnez      $v0, .L80241AA8
/* D218F8 80241A68 0080882D */   daddu    $s1, $a0, $zero
/* D218FC 80241A6C 0C00AB39 */  jal       heap_malloc
/* D21900 80241A70 24040040 */   addiu    $a0, $zero, 0x40
/* D21904 80241A74 AE020000 */  sw        $v0, ($s0)
/* D21908 80241A78 0000182D */  daddu     $v1, $zero, $zero
/* D2190C 80241A7C 0040282D */  daddu     $a1, $v0, $zero
/* D21910 80241A80 0220202D */  daddu     $a0, $s1, $zero
.L80241A84:
/* D21914 80241A84 8C820084 */  lw        $v0, 0x84($a0)
/* D21918 80241A88 24840004 */  addiu     $a0, $a0, 4
/* D2191C 80241A8C 24630001 */  addiu     $v1, $v1, 1
/* D21920 80241A90 ACA20000 */  sw        $v0, ($a1)
/* D21924 80241A94 28620010 */  slti      $v0, $v1, 0x10
/* D21928 80241A98 1440FFFA */  bnez      $v0, .L80241A84
/* D2192C 80241A9C 24A50004 */   addiu    $a1, $a1, 4
/* D21930 80241AA0 080906B9 */  j         .L80241AE4
/* D21934 80241AA4 00000000 */   nop      
.L80241AA8:
/* D21938 80241AA8 0000182D */  daddu     $v1, $zero, $zero
/* D2193C 80241AAC 0040282D */  daddu     $a1, $v0, $zero
/* D21940 80241AB0 0220202D */  daddu     $a0, $s1, $zero
.L80241AB4:
/* D21944 80241AB4 8CA20000 */  lw        $v0, ($a1)
/* D21948 80241AB8 24A50004 */  addiu     $a1, $a1, 4
/* D2194C 80241ABC 24630001 */  addiu     $v1, $v1, 1
/* D21950 80241AC0 AC820084 */  sw        $v0, 0x84($a0)
/* D21954 80241AC4 28620010 */  slti      $v0, $v1, 0x10
/* D21958 80241AC8 1440FFFA */  bnez      $v0, .L80241AB4
/* D2195C 80241ACC 24840004 */   addiu    $a0, $a0, 4
/* D21960 80241AD0 3C108024 */  lui       $s0, 0x8024
/* D21964 80241AD4 261043D0 */  addiu     $s0, $s0, 0x43d0
/* D21968 80241AD8 0C00AB4B */  jal       heap_free
/* D2196C 80241ADC 8E040000 */   lw       $a0, ($s0)
/* D21970 80241AE0 AE000000 */  sw        $zero, ($s0)
.L80241AE4:
/* D21974 80241AE4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D21978 80241AE8 8FB10014 */  lw        $s1, 0x14($sp)
/* D2197C 80241AEC 8FB00010 */  lw        $s0, 0x10($sp)
/* D21980 80241AF0 24020002 */  addiu     $v0, $zero, 2
/* D21984 80241AF4 03E00008 */  jr        $ra
/* D21988 80241AF8 27BD0020 */   addiu    $sp, $sp, 0x20
