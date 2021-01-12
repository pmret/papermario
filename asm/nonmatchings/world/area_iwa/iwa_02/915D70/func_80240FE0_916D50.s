.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FE0_916D50
/* 916D50 80240FE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 916D54 80240FE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 916D58 80240FE8 3C108024 */  lui       $s0, %hi(D_80241DA8)
/* 916D5C 80240FEC 26101DA8 */  addiu     $s0, $s0, %lo(D_80241DA8)
/* 916D60 80240FF0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 916D64 80240FF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 916D68 80240FF8 8E020000 */  lw        $v0, ($s0)
/* 916D6C 80240FFC 14400010 */  bnez      $v0, .L80241040
/* 916D70 80241000 0080882D */   daddu    $s1, $a0, $zero
/* 916D74 80241004 0C00AB39 */  jal       heap_malloc
/* 916D78 80241008 24040040 */   addiu    $a0, $zero, 0x40
/* 916D7C 8024100C AE020000 */  sw        $v0, ($s0)
/* 916D80 80241010 0000182D */  daddu     $v1, $zero, $zero
/* 916D84 80241014 0040282D */  daddu     $a1, $v0, $zero
/* 916D88 80241018 0220202D */  daddu     $a0, $s1, $zero
.L8024101C:
/* 916D8C 8024101C 8C820084 */  lw        $v0, 0x84($a0)
/* 916D90 80241020 24840004 */  addiu     $a0, $a0, 4
/* 916D94 80241024 24630001 */  addiu     $v1, $v1, 1
/* 916D98 80241028 ACA20000 */  sw        $v0, ($a1)
/* 916D9C 8024102C 28620010 */  slti      $v0, $v1, 0x10
/* 916DA0 80241030 1440FFFA */  bnez      $v0, .L8024101C
/* 916DA4 80241034 24A50004 */   addiu    $a1, $a1, 4
/* 916DA8 80241038 0809041F */  j         .L8024107C
/* 916DAC 8024103C 00000000 */   nop
.L80241040:
/* 916DB0 80241040 0000182D */  daddu     $v1, $zero, $zero
/* 916DB4 80241044 0040282D */  daddu     $a1, $v0, $zero
/* 916DB8 80241048 0220202D */  daddu     $a0, $s1, $zero
.L8024104C:
/* 916DBC 8024104C 8CA20000 */  lw        $v0, ($a1)
/* 916DC0 80241050 24A50004 */  addiu     $a1, $a1, 4
/* 916DC4 80241054 24630001 */  addiu     $v1, $v1, 1
/* 916DC8 80241058 AC820084 */  sw        $v0, 0x84($a0)
/* 916DCC 8024105C 28620010 */  slti      $v0, $v1, 0x10
/* 916DD0 80241060 1440FFFA */  bnez      $v0, .L8024104C
/* 916DD4 80241064 24840004 */   addiu    $a0, $a0, 4
/* 916DD8 80241068 3C108024 */  lui       $s0, %hi(D_80241DA8)
/* 916DDC 8024106C 26101DA8 */  addiu     $s0, $s0, %lo(D_80241DA8)
/* 916DE0 80241070 0C00AB4B */  jal       heap_free
/* 916DE4 80241074 8E040000 */   lw       $a0, ($s0)
/* 916DE8 80241078 AE000000 */  sw        $zero, ($s0)
.L8024107C:
/* 916DEC 8024107C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 916DF0 80241080 8FB10014 */  lw        $s1, 0x14($sp)
/* 916DF4 80241084 8FB00010 */  lw        $s0, 0x10($sp)
/* 916DF8 80241088 24020002 */  addiu     $v0, $zero, 2
/* 916DFC 8024108C 03E00008 */  jr        $ra
/* 916E00 80241090 27BD0020 */   addiu    $sp, $sp, 0x20
