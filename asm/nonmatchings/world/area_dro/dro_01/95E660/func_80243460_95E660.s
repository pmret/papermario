.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243460_95E660
/* 95E660 80243460 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95E664 80243464 AFB00010 */  sw        $s0, 0x10($sp)
/* 95E668 80243468 3C108025 */  lui       $s0, 0x8025
/* 95E66C 8024346C 2610B5B0 */  addiu     $s0, $s0, -0x4a50
/* 95E670 80243470 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95E674 80243474 AFB10014 */  sw        $s1, 0x14($sp)
/* 95E678 80243478 8E020000 */  lw        $v0, ($s0)
/* 95E67C 8024347C 14400010 */  bnez      $v0, .L802434C0
/* 95E680 80243480 0080882D */   daddu    $s1, $a0, $zero
/* 95E684 80243484 0C00AB39 */  jal       heap_malloc
/* 95E688 80243488 24040040 */   addiu    $a0, $zero, 0x40
/* 95E68C 8024348C AE020000 */  sw        $v0, ($s0)
/* 95E690 80243490 0000182D */  daddu     $v1, $zero, $zero
/* 95E694 80243494 0040282D */  daddu     $a1, $v0, $zero
/* 95E698 80243498 0220202D */  daddu     $a0, $s1, $zero
.L8024349C:
/* 95E69C 8024349C 8C820084 */  lw        $v0, 0x84($a0)
/* 95E6A0 802434A0 24840004 */  addiu     $a0, $a0, 4
/* 95E6A4 802434A4 24630001 */  addiu     $v1, $v1, 1
/* 95E6A8 802434A8 ACA20000 */  sw        $v0, ($a1)
/* 95E6AC 802434AC 28620010 */  slti      $v0, $v1, 0x10
/* 95E6B0 802434B0 1440FFFA */  bnez      $v0, .L8024349C
/* 95E6B4 802434B4 24A50004 */   addiu    $a1, $a1, 4
/* 95E6B8 802434B8 08090D3F */  j         .L802434FC
/* 95E6BC 802434BC 00000000 */   nop      
.L802434C0:
/* 95E6C0 802434C0 0000182D */  daddu     $v1, $zero, $zero
/* 95E6C4 802434C4 0040282D */  daddu     $a1, $v0, $zero
/* 95E6C8 802434C8 0220202D */  daddu     $a0, $s1, $zero
.L802434CC:
/* 95E6CC 802434CC 8CA20000 */  lw        $v0, ($a1)
/* 95E6D0 802434D0 24A50004 */  addiu     $a1, $a1, 4
/* 95E6D4 802434D4 24630001 */  addiu     $v1, $v1, 1
/* 95E6D8 802434D8 AC820084 */  sw        $v0, 0x84($a0)
/* 95E6DC 802434DC 28620010 */  slti      $v0, $v1, 0x10
/* 95E6E0 802434E0 1440FFFA */  bnez      $v0, .L802434CC
/* 95E6E4 802434E4 24840004 */   addiu    $a0, $a0, 4
/* 95E6E8 802434E8 3C108025 */  lui       $s0, 0x8025
/* 95E6EC 802434EC 2610B5B0 */  addiu     $s0, $s0, -0x4a50
/* 95E6F0 802434F0 0C00AB4B */  jal       heap_free
/* 95E6F4 802434F4 8E040000 */   lw       $a0, ($s0)
/* 95E6F8 802434F8 AE000000 */  sw        $zero, ($s0)
.L802434FC:
/* 95E6FC 802434FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95E700 80243500 8FB10014 */  lw        $s1, 0x14($sp)
/* 95E704 80243504 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E708 80243508 24020002 */  addiu     $v0, $zero, 2
/* 95E70C 8024350C 03E00008 */  jr        $ra
/* 95E710 80243510 27BD0020 */   addiu    $sp, $sp, 0x20
