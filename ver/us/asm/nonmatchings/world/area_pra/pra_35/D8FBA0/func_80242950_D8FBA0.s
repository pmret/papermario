.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242950_D8FBA0
/* D8FBA0 80242950 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8FBA4 80242954 AFB00010 */  sw        $s0, 0x10($sp)
/* D8FBA8 80242958 3C108024 */  lui       $s0, %hi(D_80243DE0_D91030)
/* D8FBAC 8024295C 26103DE0 */  addiu     $s0, $s0, %lo(D_80243DE0_D91030)
/* D8FBB0 80242960 AFBF0018 */  sw        $ra, 0x18($sp)
/* D8FBB4 80242964 AFB10014 */  sw        $s1, 0x14($sp)
/* D8FBB8 80242968 8E020000 */  lw        $v0, ($s0)
/* D8FBBC 8024296C 14400010 */  bnez      $v0, .L802429B0
/* D8FBC0 80242970 0080882D */   daddu    $s1, $a0, $zero
/* D8FBC4 80242974 0C00AB39 */  jal       heap_malloc
/* D8FBC8 80242978 24040040 */   addiu    $a0, $zero, 0x40
/* D8FBCC 8024297C AE020000 */  sw        $v0, ($s0)
/* D8FBD0 80242980 0000182D */  daddu     $v1, $zero, $zero
/* D8FBD4 80242984 0040282D */  daddu     $a1, $v0, $zero
/* D8FBD8 80242988 0220202D */  daddu     $a0, $s1, $zero
.L8024298C:
/* D8FBDC 8024298C 8C820084 */  lw        $v0, 0x84($a0)
/* D8FBE0 80242990 24840004 */  addiu     $a0, $a0, 4
/* D8FBE4 80242994 24630001 */  addiu     $v1, $v1, 1
/* D8FBE8 80242998 ACA20000 */  sw        $v0, ($a1)
/* D8FBEC 8024299C 28620010 */  slti      $v0, $v1, 0x10
/* D8FBF0 802429A0 1440FFFA */  bnez      $v0, .L8024298C
/* D8FBF4 802429A4 24A50004 */   addiu    $a1, $a1, 4
/* D8FBF8 802429A8 08090A7B */  j         .L802429EC
/* D8FBFC 802429AC 00000000 */   nop
.L802429B0:
/* D8FC00 802429B0 0000182D */  daddu     $v1, $zero, $zero
/* D8FC04 802429B4 0040282D */  daddu     $a1, $v0, $zero
/* D8FC08 802429B8 0220202D */  daddu     $a0, $s1, $zero
.L802429BC:
/* D8FC0C 802429BC 8CA20000 */  lw        $v0, ($a1)
/* D8FC10 802429C0 24A50004 */  addiu     $a1, $a1, 4
/* D8FC14 802429C4 24630001 */  addiu     $v1, $v1, 1
/* D8FC18 802429C8 AC820084 */  sw        $v0, 0x84($a0)
/* D8FC1C 802429CC 28620010 */  slti      $v0, $v1, 0x10
/* D8FC20 802429D0 1440FFFA */  bnez      $v0, .L802429BC
/* D8FC24 802429D4 24840004 */   addiu    $a0, $a0, 4
/* D8FC28 802429D8 3C108024 */  lui       $s0, %hi(D_80243DE0_D91030)
/* D8FC2C 802429DC 26103DE0 */  addiu     $s0, $s0, %lo(D_80243DE0_D91030)
/* D8FC30 802429E0 0C00AB4B */  jal       heap_free
/* D8FC34 802429E4 8E040000 */   lw       $a0, ($s0)
/* D8FC38 802429E8 AE000000 */  sw        $zero, ($s0)
.L802429EC:
/* D8FC3C 802429EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8FC40 802429F0 8FB10014 */  lw        $s1, 0x14($sp)
/* D8FC44 802429F4 8FB00010 */  lw        $s0, 0x10($sp)
/* D8FC48 802429F8 24020002 */  addiu     $v0, $zero, 2
/* D8FC4C 802429FC 03E00008 */  jr        $ra
/* D8FC50 80242A00 27BD0020 */   addiu    $sp, $sp, 0x20
