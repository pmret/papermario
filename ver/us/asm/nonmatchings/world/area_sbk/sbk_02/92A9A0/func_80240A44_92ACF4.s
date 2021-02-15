.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A44_92ACF4
/* 92ACF4 80240A44 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 92ACF8 80240A48 AFB00010 */  sw        $s0, 0x10($sp)
/* 92ACFC 80240A4C 3C108024 */  lui       $s0, %hi(D_802441D8_92E488)
/* 92AD00 80240A50 261041D8 */  addiu     $s0, $s0, %lo(D_802441D8_92E488)
/* 92AD04 80240A54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 92AD08 80240A58 AFB10014 */  sw        $s1, 0x14($sp)
/* 92AD0C 80240A5C 8E020000 */  lw        $v0, ($s0)
/* 92AD10 80240A60 14400010 */  bnez      $v0, .L80240AA4
/* 92AD14 80240A64 0080882D */   daddu    $s1, $a0, $zero
/* 92AD18 80240A68 0C00AB39 */  jal       heap_malloc
/* 92AD1C 80240A6C 24040040 */   addiu    $a0, $zero, 0x40
/* 92AD20 80240A70 AE020000 */  sw        $v0, ($s0)
/* 92AD24 80240A74 0000182D */  daddu     $v1, $zero, $zero
/* 92AD28 80240A78 0040282D */  daddu     $a1, $v0, $zero
/* 92AD2C 80240A7C 0220202D */  daddu     $a0, $s1, $zero
.L80240A80:
/* 92AD30 80240A80 8C820084 */  lw        $v0, 0x84($a0)
/* 92AD34 80240A84 24840004 */  addiu     $a0, $a0, 4
/* 92AD38 80240A88 24630001 */  addiu     $v1, $v1, 1
/* 92AD3C 80240A8C ACA20000 */  sw        $v0, ($a1)
/* 92AD40 80240A90 28620010 */  slti      $v0, $v1, 0x10
/* 92AD44 80240A94 1440FFFA */  bnez      $v0, .L80240A80
/* 92AD48 80240A98 24A50004 */   addiu    $a1, $a1, 4
/* 92AD4C 80240A9C 080902B8 */  j         .L80240AE0
/* 92AD50 80240AA0 00000000 */   nop
.L80240AA4:
/* 92AD54 80240AA4 0000182D */  daddu     $v1, $zero, $zero
/* 92AD58 80240AA8 0040282D */  daddu     $a1, $v0, $zero
/* 92AD5C 80240AAC 0220202D */  daddu     $a0, $s1, $zero
.L80240AB0:
/* 92AD60 80240AB0 8CA20000 */  lw        $v0, ($a1)
/* 92AD64 80240AB4 24A50004 */  addiu     $a1, $a1, 4
/* 92AD68 80240AB8 24630001 */  addiu     $v1, $v1, 1
/* 92AD6C 80240ABC AC820084 */  sw        $v0, 0x84($a0)
/* 92AD70 80240AC0 28620010 */  slti      $v0, $v1, 0x10
/* 92AD74 80240AC4 1440FFFA */  bnez      $v0, .L80240AB0
/* 92AD78 80240AC8 24840004 */   addiu    $a0, $a0, 4
/* 92AD7C 80240ACC 3C108024 */  lui       $s0, %hi(D_802441D8_92E488)
/* 92AD80 80240AD0 261041D8 */  addiu     $s0, $s0, %lo(D_802441D8_92E488)
/* 92AD84 80240AD4 0C00AB4B */  jal       heap_free
/* 92AD88 80240AD8 8E040000 */   lw       $a0, ($s0)
/* 92AD8C 80240ADC AE000000 */  sw        $zero, ($s0)
.L80240AE0:
/* 92AD90 80240AE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 92AD94 80240AE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 92AD98 80240AE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 92AD9C 80240AEC 24020002 */  addiu     $v0, $zero, 2
/* 92ADA0 80240AF0 03E00008 */  jr        $ra
/* 92ADA4 80240AF4 27BD0020 */   addiu    $sp, $sp, 0x20
