.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024259C_C8804C
/* C8804C 8024259C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C88050 802425A0 AFB00010 */  sw        $s0, 0x10($sp)
/* C88054 802425A4 3C108024 */  lui       $s0, 0x8024
/* C88058 802425A8 26104074 */  addiu     $s0, $s0, 0x4074
/* C8805C 802425AC AFBF0018 */  sw        $ra, 0x18($sp)
/* C88060 802425B0 AFB10014 */  sw        $s1, 0x14($sp)
/* C88064 802425B4 8E020000 */  lw        $v0, ($s0)
/* C88068 802425B8 14400010 */  bnez      $v0, .L802425FC
/* C8806C 802425BC 0080882D */   daddu    $s1, $a0, $zero
/* C88070 802425C0 0C00AB39 */  jal       heap_malloc
/* C88074 802425C4 24040040 */   addiu    $a0, $zero, 0x40
/* C88078 802425C8 AE020000 */  sw        $v0, ($s0)
/* C8807C 802425CC 0000182D */  daddu     $v1, $zero, $zero
/* C88080 802425D0 0040282D */  daddu     $a1, $v0, $zero
/* C88084 802425D4 0220202D */  daddu     $a0, $s1, $zero
.L802425D8:
/* C88088 802425D8 8C820084 */  lw        $v0, 0x84($a0)
/* C8808C 802425DC 24840004 */  addiu     $a0, $a0, 4
/* C88090 802425E0 24630001 */  addiu     $v1, $v1, 1
/* C88094 802425E4 ACA20000 */  sw        $v0, ($a1)
/* C88098 802425E8 28620010 */  slti      $v0, $v1, 0x10
/* C8809C 802425EC 1440FFFA */  bnez      $v0, .L802425D8
/* C880A0 802425F0 24A50004 */   addiu    $a1, $a1, 4
/* C880A4 802425F4 0809098E */  j         .L80242638
/* C880A8 802425F8 00000000 */   nop      
.L802425FC:
/* C880AC 802425FC 0000182D */  daddu     $v1, $zero, $zero
/* C880B0 80242600 0040282D */  daddu     $a1, $v0, $zero
/* C880B4 80242604 0220202D */  daddu     $a0, $s1, $zero
.L80242608:
/* C880B8 80242608 8CA20000 */  lw        $v0, ($a1)
/* C880BC 8024260C 24A50004 */  addiu     $a1, $a1, 4
/* C880C0 80242610 24630001 */  addiu     $v1, $v1, 1
/* C880C4 80242614 AC820084 */  sw        $v0, 0x84($a0)
/* C880C8 80242618 28620010 */  slti      $v0, $v1, 0x10
/* C880CC 8024261C 1440FFFA */  bnez      $v0, .L80242608
/* C880D0 80242620 24840004 */   addiu    $a0, $a0, 4
/* C880D4 80242624 3C108024 */  lui       $s0, 0x8024
/* C880D8 80242628 26104074 */  addiu     $s0, $s0, 0x4074
/* C880DC 8024262C 0C00AB4B */  jal       heap_free
/* C880E0 80242630 8E040000 */   lw       $a0, ($s0)
/* C880E4 80242634 AE000000 */  sw        $zero, ($s0)
.L80242638:
/* C880E8 80242638 8FBF0018 */  lw        $ra, 0x18($sp)
/* C880EC 8024263C 8FB10014 */  lw        $s1, 0x14($sp)
/* C880F0 80242640 8FB00010 */  lw        $s0, 0x10($sp)
/* C880F4 80242644 24020002 */  addiu     $v0, $zero, 2
/* C880F8 80242648 03E00008 */  jr        $ra
/* C880FC 8024264C 27BD0020 */   addiu    $sp, $sp, 0x20
