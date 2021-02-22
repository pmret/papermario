.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407F0_A0C4E0
/* A0C4E0 802407F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A0C4E4 802407F4 AFB00010 */  sw        $s0, 0x10($sp)
/* A0C4E8 802407F8 3C108024 */  lui       $s0, %hi(D_80242970_A0E660)
/* A0C4EC 802407FC 26102970 */  addiu     $s0, $s0, %lo(D_80242970_A0E660)
/* A0C4F0 80240800 AFBF0018 */  sw        $ra, 0x18($sp)
/* A0C4F4 80240804 AFB10014 */  sw        $s1, 0x14($sp)
/* A0C4F8 80240808 8E020000 */  lw        $v0, ($s0)
/* A0C4FC 8024080C 14400010 */  bnez      $v0, .L80240850
/* A0C500 80240810 0080882D */   daddu    $s1, $a0, $zero
/* A0C504 80240814 0C00AB39 */  jal       heap_malloc
/* A0C508 80240818 24040040 */   addiu    $a0, $zero, 0x40
/* A0C50C 8024081C AE020000 */  sw        $v0, ($s0)
/* A0C510 80240820 0000182D */  daddu     $v1, $zero, $zero
/* A0C514 80240824 0040282D */  daddu     $a1, $v0, $zero
/* A0C518 80240828 0220202D */  daddu     $a0, $s1, $zero
.L8024082C:
/* A0C51C 8024082C 8C820084 */  lw        $v0, 0x84($a0)
/* A0C520 80240830 24840004 */  addiu     $a0, $a0, 4
/* A0C524 80240834 24630001 */  addiu     $v1, $v1, 1
/* A0C528 80240838 ACA20000 */  sw        $v0, ($a1)
/* A0C52C 8024083C 28620010 */  slti      $v0, $v1, 0x10
/* A0C530 80240840 1440FFFA */  bnez      $v0, .L8024082C
/* A0C534 80240844 24A50004 */   addiu    $a1, $a1, 4
/* A0C538 80240848 08090223 */  j         .L8024088C
/* A0C53C 8024084C 00000000 */   nop
.L80240850:
/* A0C540 80240850 0000182D */  daddu     $v1, $zero, $zero
/* A0C544 80240854 0040282D */  daddu     $a1, $v0, $zero
/* A0C548 80240858 0220202D */  daddu     $a0, $s1, $zero
.L8024085C:
/* A0C54C 8024085C 8CA20000 */  lw        $v0, ($a1)
/* A0C550 80240860 24A50004 */  addiu     $a1, $a1, 4
/* A0C554 80240864 24630001 */  addiu     $v1, $v1, 1
/* A0C558 80240868 AC820084 */  sw        $v0, 0x84($a0)
/* A0C55C 8024086C 28620010 */  slti      $v0, $v1, 0x10
/* A0C560 80240870 1440FFFA */  bnez      $v0, .L8024085C
/* A0C564 80240874 24840004 */   addiu    $a0, $a0, 4
/* A0C568 80240878 3C108024 */  lui       $s0, %hi(D_80242970_A0E660)
/* A0C56C 8024087C 26102970 */  addiu     $s0, $s0, %lo(D_80242970_A0E660)
/* A0C570 80240880 0C00AB4B */  jal       heap_free
/* A0C574 80240884 8E040000 */   lw       $a0, ($s0)
/* A0C578 80240888 AE000000 */  sw        $zero, ($s0)
.L8024088C:
/* A0C57C 8024088C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A0C580 80240890 8FB10014 */  lw        $s1, 0x14($sp)
/* A0C584 80240894 8FB00010 */  lw        $s0, 0x10($sp)
/* A0C588 80240898 24020002 */  addiu     $v0, $zero, 2
/* A0C58C 8024089C 03E00008 */  jr        $ra
/* A0C590 802408A0 27BD0020 */   addiu    $sp, $sp, 0x20
