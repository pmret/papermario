.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel delete_player_actor_9C6148
/* 9C6148 80240D68 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C614C 80240D6C AFB00010 */  sw        $s0, 0x10($sp)
/* 9C6150 80240D70 3C108024 */  lui       $s0, %hi(D_80245F44)
/* 9C6154 80240D74 26105F44 */  addiu     $s0, $s0, %lo(D_80245F44)
/* 9C6158 80240D78 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C615C 80240D7C AFB10014 */  sw        $s1, 0x14($sp)
/* 9C6160 80240D80 8E020000 */  lw        $v0, ($s0)
/* 9C6164 80240D84 14400010 */  bnez      $v0, .L80240DC8
/* 9C6168 80240D88 0080882D */   daddu    $s1, $a0, $zero
/* 9C616C 80240D8C 0C00AB39 */  jal       heap_malloc
/* 9C6170 80240D90 24040040 */   addiu    $a0, $zero, 0x40
/* 9C6174 80240D94 AE020000 */  sw        $v0, ($s0)
/* 9C6178 80240D98 0000182D */  daddu     $v1, $zero, $zero
/* 9C617C 80240D9C 0040282D */  daddu     $a1, $v0, $zero
/* 9C6180 80240DA0 0220202D */  daddu     $a0, $s1, $zero
.L80240DA4:
/* 9C6184 80240DA4 8C820084 */  lw        $v0, 0x84($a0)
/* 9C6188 80240DA8 24840004 */  addiu     $a0, $a0, 4
/* 9C618C 80240DAC 24630001 */  addiu     $v1, $v1, 1
/* 9C6190 80240DB0 ACA20000 */  sw        $v0, ($a1)
/* 9C6194 80240DB4 28620010 */  slti      $v0, $v1, 0x10
/* 9C6198 80240DB8 1440FFFA */  bnez      $v0, .L80240DA4
/* 9C619C 80240DBC 24A50004 */   addiu    $a1, $a1, 4
/* 9C61A0 80240DC0 08090381 */  j         .L80240E04
/* 9C61A4 80240DC4 00000000 */   nop      
.L80240DC8:
/* 9C61A8 80240DC8 0000182D */  daddu     $v1, $zero, $zero
/* 9C61AC 80240DCC 0040282D */  daddu     $a1, $v0, $zero
/* 9C61B0 80240DD0 0220202D */  daddu     $a0, $s1, $zero
.L80240DD4:
/* 9C61B4 80240DD4 8CA20000 */  lw        $v0, ($a1)
/* 9C61B8 80240DD8 24A50004 */  addiu     $a1, $a1, 4
/* 9C61BC 80240DDC 24630001 */  addiu     $v1, $v1, 1
/* 9C61C0 80240DE0 AC820084 */  sw        $v0, 0x84($a0)
/* 9C61C4 80240DE4 28620010 */  slti      $v0, $v1, 0x10
/* 9C61C8 80240DE8 1440FFFA */  bnez      $v0, .L80240DD4
/* 9C61CC 80240DEC 24840004 */   addiu    $a0, $a0, 4
/* 9C61D0 80240DF0 3C108024 */  lui       $s0, %hi(D_80245F44)
/* 9C61D4 80240DF4 26105F44 */  addiu     $s0, $s0, %lo(D_80245F44)
/* 9C61D8 80240DF8 0C00AB4B */  jal       heap_free
/* 9C61DC 80240DFC 8E040000 */   lw       $a0, ($s0)
/* 9C61E0 80240E00 AE000000 */  sw        $zero, ($s0)
.L80240E04:
/* 9C61E4 80240E04 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C61E8 80240E08 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C61EC 80240E0C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C61F0 80240E10 24020002 */  addiu     $v0, $zero, 2
/* 9C61F4 80240E14 03E00008 */  jr        $ra
/* 9C61F8 80240E18 27BD0020 */   addiu    $sp, $sp, 0x20
