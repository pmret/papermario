.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DDC_94038C
/* 94038C 80240DDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 940390 80240DE0 AFB00010 */  sw        $s0, 0x10($sp)
/* 940394 80240DE4 3C108024 */  lui       $s0, 0x8024
/* 940398 80240DE8 26101FF4 */  addiu     $s0, $s0, 0x1ff4
/* 94039C 80240DEC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9403A0 80240DF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9403A4 80240DF4 8E020000 */  lw        $v0, ($s0)
/* 9403A8 80240DF8 14400010 */  bnez      $v0, .L80240E3C
/* 9403AC 80240DFC 0080882D */   daddu    $s1, $a0, $zero
/* 9403B0 80240E00 0C00AB39 */  jal       heap_malloc
/* 9403B4 80240E04 24040040 */   addiu    $a0, $zero, 0x40
/* 9403B8 80240E08 AE020000 */  sw        $v0, ($s0)
/* 9403BC 80240E0C 0000182D */  daddu     $v1, $zero, $zero
/* 9403C0 80240E10 0040282D */  daddu     $a1, $v0, $zero
/* 9403C4 80240E14 0220202D */  daddu     $a0, $s1, $zero
.L80240E18:
/* 9403C8 80240E18 8C820084 */  lw        $v0, 0x84($a0)
/* 9403CC 80240E1C 24840004 */  addiu     $a0, $a0, 4
/* 9403D0 80240E20 24630001 */  addiu     $v1, $v1, 1
/* 9403D4 80240E24 ACA20000 */  sw        $v0, ($a1)
/* 9403D8 80240E28 28620010 */  slti      $v0, $v1, 0x10
/* 9403DC 80240E2C 1440FFFA */  bnez      $v0, .L80240E18
/* 9403E0 80240E30 24A50004 */   addiu    $a1, $a1, 4
/* 9403E4 80240E34 0809039E */  j         .L80240E78
/* 9403E8 80240E38 00000000 */   nop      
.L80240E3C:
/* 9403EC 80240E3C 0000182D */  daddu     $v1, $zero, $zero
/* 9403F0 80240E40 0040282D */  daddu     $a1, $v0, $zero
/* 9403F4 80240E44 0220202D */  daddu     $a0, $s1, $zero
.L80240E48:
/* 9403F8 80240E48 8CA20000 */  lw        $v0, ($a1)
/* 9403FC 80240E4C 24A50004 */  addiu     $a1, $a1, 4
/* 940400 80240E50 24630001 */  addiu     $v1, $v1, 1
/* 940404 80240E54 AC820084 */  sw        $v0, 0x84($a0)
/* 940408 80240E58 28620010 */  slti      $v0, $v1, 0x10
/* 94040C 80240E5C 1440FFFA */  bnez      $v0, .L80240E48
/* 940410 80240E60 24840004 */   addiu    $a0, $a0, 4
/* 940414 80240E64 3C108024 */  lui       $s0, 0x8024
/* 940418 80240E68 26101FF4 */  addiu     $s0, $s0, 0x1ff4
/* 94041C 80240E6C 0C00AB4B */  jal       heap_free
/* 940420 80240E70 8E040000 */   lw       $a0, ($s0)
/* 940424 80240E74 AE000000 */  sw        $zero, ($s0)
.L80240E78:
/* 940428 80240E78 8FBF0018 */  lw        $ra, 0x18($sp)
/* 94042C 80240E7C 8FB10014 */  lw        $s1, 0x14($sp)
/* 940430 80240E80 8FB00010 */  lw        $s0, 0x10($sp)
/* 940434 80240E84 24020002 */  addiu     $v0, $zero, 2
/* 940438 80240E88 03E00008 */  jr        $ra
/* 94043C 80240E8C 27BD0020 */   addiu    $sp, $sp, 0x20
