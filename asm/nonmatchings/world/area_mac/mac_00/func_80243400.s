.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243400
/* 7EE110 80243400 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EE114 80243404 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EE118 80243408 3C108025 */  lui       $s0, 0x8025
/* 7EE11C 8024340C 2610ECE8 */  addiu     $s0, $s0, -0x1318
/* 7EE120 80243410 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EE124 80243414 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EE128 80243418 8E020000 */  lw        $v0, ($s0)
/* 7EE12C 8024341C 14400010 */  bnez      $v0, .L80243460
/* 7EE130 80243420 0080882D */   daddu    $s1, $a0, $zero
/* 7EE134 80243424 0C00AB39 */  jal       heap_malloc
/* 7EE138 80243428 24040040 */   addiu    $a0, $zero, 0x40
/* 7EE13C 8024342C AE020000 */  sw        $v0, ($s0)
/* 7EE140 80243430 0000182D */  daddu     $v1, $zero, $zero
/* 7EE144 80243434 0040282D */  daddu     $a1, $v0, $zero
/* 7EE148 80243438 0220202D */  daddu     $a0, $s1, $zero
.L8024343C:
/* 7EE14C 8024343C 8C820084 */  lw        $v0, 0x84($a0)
/* 7EE150 80243440 24840004 */  addiu     $a0, $a0, 4
/* 7EE154 80243444 24630001 */  addiu     $v1, $v1, 1
/* 7EE158 80243448 ACA20000 */  sw        $v0, ($a1)
/* 7EE15C 8024344C 28620010 */  slti      $v0, $v1, 0x10
/* 7EE160 80243450 1440FFFA */  bnez      $v0, .L8024343C
/* 7EE164 80243454 24A50004 */   addiu    $a1, $a1, 4
/* 7EE168 80243458 08090D27 */  j         .L8024349C
/* 7EE16C 8024345C 00000000 */   nop      
.L80243460:
/* 7EE170 80243460 0000182D */  daddu     $v1, $zero, $zero
/* 7EE174 80243464 0040282D */  daddu     $a1, $v0, $zero
/* 7EE178 80243468 0220202D */  daddu     $a0, $s1, $zero
.L8024346C:
/* 7EE17C 8024346C 8CA20000 */  lw        $v0, ($a1)
/* 7EE180 80243470 24A50004 */  addiu     $a1, $a1, 4
/* 7EE184 80243474 24630001 */  addiu     $v1, $v1, 1
/* 7EE188 80243478 AC820084 */  sw        $v0, 0x84($a0)
/* 7EE18C 8024347C 28620010 */  slti      $v0, $v1, 0x10
/* 7EE190 80243480 1440FFFA */  bnez      $v0, .L8024346C
/* 7EE194 80243484 24840004 */   addiu    $a0, $a0, 4
/* 7EE198 80243488 3C108025 */  lui       $s0, 0x8025
/* 7EE19C 8024348C 2610ECE8 */  addiu     $s0, $s0, -0x1318
/* 7EE1A0 80243490 0C00AB4B */  jal       heap_free
/* 7EE1A4 80243494 8E040000 */   lw       $a0, ($s0)
/* 7EE1A8 80243498 AE000000 */  sw        $zero, ($s0)
.L8024349C:
/* 7EE1AC 8024349C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EE1B0 802434A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EE1B4 802434A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EE1B8 802434A8 24020002 */  addiu     $v0, $zero, 2
/* 7EE1BC 802434AC 03E00008 */  jr        $ra
/* 7EE1C0 802434B0 27BD0020 */   addiu    $sp, $sp, 0x20
