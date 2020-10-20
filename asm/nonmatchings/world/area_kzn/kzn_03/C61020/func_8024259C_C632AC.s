.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024259C_C632AC
/* C632AC 8024259C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C632B0 802425A0 AFB00010 */  sw        $s0, 0x10($sp)
/* C632B4 802425A4 3C108024 */  lui       $s0, 0x8024
/* C632B8 802425A8 261041A0 */  addiu     $s0, $s0, 0x41a0
/* C632BC 802425AC AFBF0018 */  sw        $ra, 0x18($sp)
/* C632C0 802425B0 AFB10014 */  sw        $s1, 0x14($sp)
/* C632C4 802425B4 8E020000 */  lw        $v0, ($s0)
/* C632C8 802425B8 14400010 */  bnez      $v0, .L802425FC
/* C632CC 802425BC 0080882D */   daddu    $s1, $a0, $zero
/* C632D0 802425C0 0C00AB39 */  jal       heap_malloc
/* C632D4 802425C4 24040040 */   addiu    $a0, $zero, 0x40
/* C632D8 802425C8 AE020000 */  sw        $v0, ($s0)
/* C632DC 802425CC 0000182D */  daddu     $v1, $zero, $zero
/* C632E0 802425D0 0040282D */  daddu     $a1, $v0, $zero
/* C632E4 802425D4 0220202D */  daddu     $a0, $s1, $zero
.L802425D8:
/* C632E8 802425D8 8C820084 */  lw        $v0, 0x84($a0)
/* C632EC 802425DC 24840004 */  addiu     $a0, $a0, 4
/* C632F0 802425E0 24630001 */  addiu     $v1, $v1, 1
/* C632F4 802425E4 ACA20000 */  sw        $v0, ($a1)
/* C632F8 802425E8 28620010 */  slti      $v0, $v1, 0x10
/* C632FC 802425EC 1440FFFA */  bnez      $v0, .L802425D8
/* C63300 802425F0 24A50004 */   addiu    $a1, $a1, 4
/* C63304 802425F4 0809098E */  j         .L80242638
/* C63308 802425F8 00000000 */   nop      
.L802425FC:
/* C6330C 802425FC 0000182D */  daddu     $v1, $zero, $zero
/* C63310 80242600 0040282D */  daddu     $a1, $v0, $zero
/* C63314 80242604 0220202D */  daddu     $a0, $s1, $zero
.L80242608:
/* C63318 80242608 8CA20000 */  lw        $v0, ($a1)
/* C6331C 8024260C 24A50004 */  addiu     $a1, $a1, 4
/* C63320 80242610 24630001 */  addiu     $v1, $v1, 1
/* C63324 80242614 AC820084 */  sw        $v0, 0x84($a0)
/* C63328 80242618 28620010 */  slti      $v0, $v1, 0x10
/* C6332C 8024261C 1440FFFA */  bnez      $v0, .L80242608
/* C63330 80242620 24840004 */   addiu    $a0, $a0, 4
/* C63334 80242624 3C108024 */  lui       $s0, 0x8024
/* C63338 80242628 261041A0 */  addiu     $s0, $s0, 0x41a0
/* C6333C 8024262C 0C00AB4B */  jal       heap_free
/* C63340 80242630 8E040000 */   lw       $a0, ($s0)
/* C63344 80242634 AE000000 */  sw        $zero, ($s0)
.L80242638:
/* C63348 80242638 8FBF0018 */  lw        $ra, 0x18($sp)
/* C6334C 8024263C 8FB10014 */  lw        $s1, 0x14($sp)
/* C63350 80242640 8FB00010 */  lw        $s0, 0x10($sp)
/* C63354 80242644 24020002 */  addiu     $v0, $zero, 2
/* C63358 80242648 03E00008 */  jr        $ra
/* C6335C 8024264C 27BD0020 */   addiu    $sp, $sp, 0x20
