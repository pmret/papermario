.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FD0_A3B4B0
/* A3B4B0 80241FD0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3B4B4 80241FD4 AFB00010 */  sw        $s0, 0x10($sp)
/* A3B4B8 80241FD8 3C108024 */  lui       $s0, %hi(D_80245E80)
/* A3B4BC 80241FDC 26105E80 */  addiu     $s0, $s0, %lo(D_80245E80)
/* A3B4C0 80241FE0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A3B4C4 80241FE4 AFB10014 */  sw        $s1, 0x14($sp)
/* A3B4C8 80241FE8 8E020000 */  lw        $v0, ($s0)
/* A3B4CC 80241FEC 14400010 */  bnez      $v0, .L80242030
/* A3B4D0 80241FF0 0080882D */   daddu    $s1, $a0, $zero
/* A3B4D4 80241FF4 0C00AB39 */  jal       heap_malloc
/* A3B4D8 80241FF8 24040040 */   addiu    $a0, $zero, 0x40
/* A3B4DC 80241FFC AE020000 */  sw        $v0, ($s0)
/* A3B4E0 80242000 0000182D */  daddu     $v1, $zero, $zero
/* A3B4E4 80242004 0040282D */  daddu     $a1, $v0, $zero
/* A3B4E8 80242008 0220202D */  daddu     $a0, $s1, $zero
.L8024200C:
/* A3B4EC 8024200C 8C820084 */  lw        $v0, 0x84($a0)
/* A3B4F0 80242010 24840004 */  addiu     $a0, $a0, 4
/* A3B4F4 80242014 24630001 */  addiu     $v1, $v1, 1
/* A3B4F8 80242018 ACA20000 */  sw        $v0, ($a1)
/* A3B4FC 8024201C 28620010 */  slti      $v0, $v1, 0x10
/* A3B500 80242020 1440FFFA */  bnez      $v0, .L8024200C
/* A3B504 80242024 24A50004 */   addiu    $a1, $a1, 4
/* A3B508 80242028 0809081B */  j         .L8024206C
/* A3B50C 8024202C 00000000 */   nop      
.L80242030:
/* A3B510 80242030 0000182D */  daddu     $v1, $zero, $zero
/* A3B514 80242034 0040282D */  daddu     $a1, $v0, $zero
/* A3B518 80242038 0220202D */  daddu     $a0, $s1, $zero
.L8024203C:
/* A3B51C 8024203C 8CA20000 */  lw        $v0, ($a1)
/* A3B520 80242040 24A50004 */  addiu     $a1, $a1, 4
/* A3B524 80242044 24630001 */  addiu     $v1, $v1, 1
/* A3B528 80242048 AC820084 */  sw        $v0, 0x84($a0)
/* A3B52C 8024204C 28620010 */  slti      $v0, $v1, 0x10
/* A3B530 80242050 1440FFFA */  bnez      $v0, .L8024203C
/* A3B534 80242054 24840004 */   addiu    $a0, $a0, 4
/* A3B538 80242058 3C108024 */  lui       $s0, %hi(D_80245E80)
/* A3B53C 8024205C 26105E80 */  addiu     $s0, $s0, %lo(D_80245E80)
/* A3B540 80242060 0C00AB4B */  jal       heap_free
/* A3B544 80242064 8E040000 */   lw       $a0, ($s0)
/* A3B548 80242068 AE000000 */  sw        $zero, ($s0)
.L8024206C:
/* A3B54C 8024206C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3B550 80242070 8FB10014 */  lw        $s1, 0x14($sp)
/* A3B554 80242074 8FB00010 */  lw        $s0, 0x10($sp)
/* A3B558 80242078 24020002 */  addiu     $v0, $zero, 2
/* A3B55C 8024207C 03E00008 */  jr        $ra
/* A3B560 80242080 27BD0020 */   addiu    $sp, $sp, 0x20
