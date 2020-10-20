.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FCC_C5C70C
/* C5C70C 80241FCC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5C710 80241FD0 AFB00010 */  sw        $s0, 0x10($sp)
/* C5C714 80241FD4 3C108024 */  lui       $s0, 0x8024
/* C5C718 80241FD8 26104A10 */  addiu     $s0, $s0, 0x4a10
/* C5C71C 80241FDC AFBF0018 */  sw        $ra, 0x18($sp)
/* C5C720 80241FE0 AFB10014 */  sw        $s1, 0x14($sp)
/* C5C724 80241FE4 8E020000 */  lw        $v0, ($s0)
/* C5C728 80241FE8 14400010 */  bnez      $v0, .L8024202C
/* C5C72C 80241FEC 0080882D */   daddu    $s1, $a0, $zero
/* C5C730 80241FF0 0C00AB39 */  jal       heap_malloc
/* C5C734 80241FF4 24040040 */   addiu    $a0, $zero, 0x40
/* C5C738 80241FF8 AE020000 */  sw        $v0, ($s0)
/* C5C73C 80241FFC 0000182D */  daddu     $v1, $zero, $zero
/* C5C740 80242000 0040282D */  daddu     $a1, $v0, $zero
/* C5C744 80242004 0220202D */  daddu     $a0, $s1, $zero
.L80242008:
/* C5C748 80242008 8C820084 */  lw        $v0, 0x84($a0)
/* C5C74C 8024200C 24840004 */  addiu     $a0, $a0, 4
/* C5C750 80242010 24630001 */  addiu     $v1, $v1, 1
/* C5C754 80242014 ACA20000 */  sw        $v0, ($a1)
/* C5C758 80242018 28620010 */  slti      $v0, $v1, 0x10
/* C5C75C 8024201C 1440FFFA */  bnez      $v0, .L80242008
/* C5C760 80242020 24A50004 */   addiu    $a1, $a1, 4
/* C5C764 80242024 0809081A */  j         .L80242068
/* C5C768 80242028 00000000 */   nop      
.L8024202C:
/* C5C76C 8024202C 0000182D */  daddu     $v1, $zero, $zero
/* C5C770 80242030 0040282D */  daddu     $a1, $v0, $zero
/* C5C774 80242034 0220202D */  daddu     $a0, $s1, $zero
.L80242038:
/* C5C778 80242038 8CA20000 */  lw        $v0, ($a1)
/* C5C77C 8024203C 24A50004 */  addiu     $a1, $a1, 4
/* C5C780 80242040 24630001 */  addiu     $v1, $v1, 1
/* C5C784 80242044 AC820084 */  sw        $v0, 0x84($a0)
/* C5C788 80242048 28620010 */  slti      $v0, $v1, 0x10
/* C5C78C 8024204C 1440FFFA */  bnez      $v0, .L80242038
/* C5C790 80242050 24840004 */   addiu    $a0, $a0, 4
/* C5C794 80242054 3C108024 */  lui       $s0, 0x8024
/* C5C798 80242058 26104A10 */  addiu     $s0, $s0, 0x4a10
/* C5C79C 8024205C 0C00AB4B */  jal       heap_free
/* C5C7A0 80242060 8E040000 */   lw       $a0, ($s0)
/* C5C7A4 80242064 AE000000 */  sw        $zero, ($s0)
.L80242068:
/* C5C7A8 80242068 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5C7AC 8024206C 8FB10014 */  lw        $s1, 0x14($sp)
/* C5C7B0 80242070 8FB00010 */  lw        $s0, 0x10($sp)
/* C5C7B4 80242074 24020002 */  addiu     $v0, $zero, 2
/* C5C7B8 80242078 03E00008 */  jr        $ra
/* C5C7BC 8024207C 27BD0020 */   addiu    $sp, $sp, 0x20
