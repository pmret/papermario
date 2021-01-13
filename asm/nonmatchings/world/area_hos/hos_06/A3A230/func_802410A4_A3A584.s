.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410A4_A3A584
/* A3A584 802410A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3A588 802410A8 AFB00010 */  sw        $s0, 0x10($sp)
/* A3A58C 802410AC 3C108024 */  lui       $s0, %hi(D_8024476C)
/* A3A590 802410B0 2610476C */  addiu     $s0, $s0, %lo(D_8024476C)
/* A3A594 802410B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* A3A598 802410B8 AFB10014 */  sw        $s1, 0x14($sp)
/* A3A59C 802410BC 8E020000 */  lw        $v0, ($s0)
/* A3A5A0 802410C0 14400010 */  bnez      $v0, .L80241104
/* A3A5A4 802410C4 0080882D */   daddu    $s1, $a0, $zero
/* A3A5A8 802410C8 0C00AB39 */  jal       heap_malloc
/* A3A5AC 802410CC 24040040 */   addiu    $a0, $zero, 0x40
/* A3A5B0 802410D0 AE020000 */  sw        $v0, ($s0)
/* A3A5B4 802410D4 0000182D */  daddu     $v1, $zero, $zero
/* A3A5B8 802410D8 0040282D */  daddu     $a1, $v0, $zero
/* A3A5BC 802410DC 0220202D */  daddu     $a0, $s1, $zero
.L802410E0:
/* A3A5C0 802410E0 8C820084 */  lw        $v0, 0x84($a0)
/* A3A5C4 802410E4 24840004 */  addiu     $a0, $a0, 4
/* A3A5C8 802410E8 24630001 */  addiu     $v1, $v1, 1
/* A3A5CC 802410EC ACA20000 */  sw        $v0, ($a1)
/* A3A5D0 802410F0 28620010 */  slti      $v0, $v1, 0x10
/* A3A5D4 802410F4 1440FFFA */  bnez      $v0, .L802410E0
/* A3A5D8 802410F8 24A50004 */   addiu    $a1, $a1, 4
/* A3A5DC 802410FC 08090450 */  j         .L80241140
/* A3A5E0 80241100 00000000 */   nop
.L80241104:
/* A3A5E4 80241104 0000182D */  daddu     $v1, $zero, $zero
/* A3A5E8 80241108 0040282D */  daddu     $a1, $v0, $zero
/* A3A5EC 8024110C 0220202D */  daddu     $a0, $s1, $zero
.L80241110:
/* A3A5F0 80241110 8CA20000 */  lw        $v0, ($a1)
/* A3A5F4 80241114 24A50004 */  addiu     $a1, $a1, 4
/* A3A5F8 80241118 24630001 */  addiu     $v1, $v1, 1
/* A3A5FC 8024111C AC820084 */  sw        $v0, 0x84($a0)
/* A3A600 80241120 28620010 */  slti      $v0, $v1, 0x10
/* A3A604 80241124 1440FFFA */  bnez      $v0, .L80241110
/* A3A608 80241128 24840004 */   addiu    $a0, $a0, 4
/* A3A60C 8024112C 3C108024 */  lui       $s0, %hi(D_8024476C)
/* A3A610 80241130 2610476C */  addiu     $s0, $s0, %lo(D_8024476C)
/* A3A614 80241134 0C00AB4B */  jal       heap_free
/* A3A618 80241138 8E040000 */   lw       $a0, ($s0)
/* A3A61C 8024113C AE000000 */  sw        $zero, ($s0)
.L80241140:
/* A3A620 80241140 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3A624 80241144 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A628 80241148 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A62C 8024114C 24020002 */  addiu     $v0, $zero, 2
/* A3A630 80241150 03E00008 */  jr        $ra
/* A3A634 80241154 27BD0020 */   addiu    $sp, $sp, 0x20
