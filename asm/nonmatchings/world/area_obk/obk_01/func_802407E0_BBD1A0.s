.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407E0_BBD980
/* BBD980 802407E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBD984 802407E4 AFB00010 */  sw        $s0, 0x10($sp)
/* BBD988 802407E8 3C108024 */  lui       $s0, 0x8024
/* BBD98C 802407EC 261040F0 */  addiu     $s0, $s0, 0x40f0
/* BBD990 802407F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BBD994 802407F4 AFB10014 */  sw        $s1, 0x14($sp)
/* BBD998 802407F8 8E020000 */  lw        $v0, ($s0)
/* BBD99C 802407FC 14400010 */  bnez      $v0, .L80240840
/* BBD9A0 80240800 0080882D */   daddu    $s1, $a0, $zero
/* BBD9A4 80240804 0C00AB39 */  jal       heap_malloc
/* BBD9A8 80240808 24040040 */   addiu    $a0, $zero, 0x40
/* BBD9AC 8024080C AE020000 */  sw        $v0, ($s0)
/* BBD9B0 80240810 0000182D */  daddu     $v1, $zero, $zero
/* BBD9B4 80240814 0040282D */  daddu     $a1, $v0, $zero
/* BBD9B8 80240818 0220202D */  daddu     $a0, $s1, $zero
.L8024081C:
/* BBD9BC 8024081C 8C820084 */  lw        $v0, 0x84($a0)
/* BBD9C0 80240820 24840004 */  addiu     $a0, $a0, 4
/* BBD9C4 80240824 24630001 */  addiu     $v1, $v1, 1
/* BBD9C8 80240828 ACA20000 */  sw        $v0, ($a1)
/* BBD9CC 8024082C 28620010 */  slti      $v0, $v1, 0x10
/* BBD9D0 80240830 1440FFFA */  bnez      $v0, .L8024081C
/* BBD9D4 80240834 24A50004 */   addiu    $a1, $a1, 4
/* BBD9D8 80240838 0809021F */  j         .L8024087C
/* BBD9DC 8024083C 00000000 */   nop      
.L80240840:
/* BBD9E0 80240840 0000182D */  daddu     $v1, $zero, $zero
/* BBD9E4 80240844 0040282D */  daddu     $a1, $v0, $zero
/* BBD9E8 80240848 0220202D */  daddu     $a0, $s1, $zero
.L8024084C:
/* BBD9EC 8024084C 8CA20000 */  lw        $v0, ($a1)
/* BBD9F0 80240850 24A50004 */  addiu     $a1, $a1, 4
/* BBD9F4 80240854 24630001 */  addiu     $v1, $v1, 1
/* BBD9F8 80240858 AC820084 */  sw        $v0, 0x84($a0)
/* BBD9FC 8024085C 28620010 */  slti      $v0, $v1, 0x10
/* BBDA00 80240860 1440FFFA */  bnez      $v0, .L8024084C
/* BBDA04 80240864 24840004 */   addiu    $a0, $a0, 4
/* BBDA08 80240868 3C108024 */  lui       $s0, 0x8024
/* BBDA0C 8024086C 261040F0 */  addiu     $s0, $s0, 0x40f0
/* BBDA10 80240870 0C00AB4B */  jal       heap_free
/* BBDA14 80240874 8E040000 */   lw       $a0, ($s0)
/* BBDA18 80240878 AE000000 */  sw        $zero, ($s0)
.L8024087C:
/* BBDA1C 8024087C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BBDA20 80240880 8FB10014 */  lw        $s1, 0x14($sp)
/* BBDA24 80240884 8FB00010 */  lw        $s0, 0x10($sp)
/* BBDA28 80240888 24020002 */  addiu     $v0, $zero, 2
/* BBDA2C 8024088C 03E00008 */  jr        $ra
/* BBDA30 80240890 27BD0020 */   addiu    $sp, $sp, 0x20
