.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E90_B85010
/* B85010 80240E90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B85014 80240E94 AFB00010 */  sw        $s0, 0x10($sp)
/* B85018 80240E98 3C108024 */  lui       $s0, 0x8024
/* B8501C 80240E9C 261025BC */  addiu     $s0, $s0, 0x25bc
/* B85020 80240EA0 AFBF0018 */  sw        $ra, 0x18($sp)
/* B85024 80240EA4 AFB10014 */  sw        $s1, 0x14($sp)
/* B85028 80240EA8 8E020000 */  lw        $v0, ($s0)
/* B8502C 80240EAC 14400010 */  bnez      $v0, .L80240EF0
/* B85030 80240EB0 0080882D */   daddu    $s1, $a0, $zero
/* B85034 80240EB4 0C00AB39 */  jal       heap_malloc
/* B85038 80240EB8 24040040 */   addiu    $a0, $zero, 0x40
/* B8503C 80240EBC AE020000 */  sw        $v0, ($s0)
/* B85040 80240EC0 0000182D */  daddu     $v1, $zero, $zero
/* B85044 80240EC4 0040282D */  daddu     $a1, $v0, $zero
/* B85048 80240EC8 0220202D */  daddu     $a0, $s1, $zero
.L80240ECC:
/* B8504C 80240ECC 8C820084 */  lw        $v0, 0x84($a0)
/* B85050 80240ED0 24840004 */  addiu     $a0, $a0, 4
/* B85054 80240ED4 24630001 */  addiu     $v1, $v1, 1
/* B85058 80240ED8 ACA20000 */  sw        $v0, ($a1)
/* B8505C 80240EDC 28620010 */  slti      $v0, $v1, 0x10
/* B85060 80240EE0 1440FFFA */  bnez      $v0, .L80240ECC
/* B85064 80240EE4 24A50004 */   addiu    $a1, $a1, 4
/* B85068 80240EE8 080903CB */  j         .L80240F2C
/* B8506C 80240EEC 00000000 */   nop      
.L80240EF0:
/* B85070 80240EF0 0000182D */  daddu     $v1, $zero, $zero
/* B85074 80240EF4 0040282D */  daddu     $a1, $v0, $zero
/* B85078 80240EF8 0220202D */  daddu     $a0, $s1, $zero
.L80240EFC:
/* B8507C 80240EFC 8CA20000 */  lw        $v0, ($a1)
/* B85080 80240F00 24A50004 */  addiu     $a1, $a1, 4
/* B85084 80240F04 24630001 */  addiu     $v1, $v1, 1
/* B85088 80240F08 AC820084 */  sw        $v0, 0x84($a0)
/* B8508C 80240F0C 28620010 */  slti      $v0, $v1, 0x10
/* B85090 80240F10 1440FFFA */  bnez      $v0, .L80240EFC
/* B85094 80240F14 24840004 */   addiu    $a0, $a0, 4
/* B85098 80240F18 3C108024 */  lui       $s0, 0x8024
/* B8509C 80240F1C 261025BC */  addiu     $s0, $s0, 0x25bc
/* B850A0 80240F20 0C00AB4B */  jal       heap_free
/* B850A4 80240F24 8E040000 */   lw       $a0, ($s0)
/* B850A8 80240F28 AE000000 */  sw        $zero, ($s0)
.L80240F2C:
/* B850AC 80240F2C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B850B0 80240F30 8FB10014 */  lw        $s1, 0x14($sp)
/* B850B4 80240F34 8FB00010 */  lw        $s0, 0x10($sp)
/* B850B8 80240F38 24020002 */  addiu     $v0, $zero, 2
/* B850BC 80240F3C 03E00008 */  jr        $ra
/* B850C0 80240F40 27BD0020 */   addiu    $sp, $sp, 0x20
