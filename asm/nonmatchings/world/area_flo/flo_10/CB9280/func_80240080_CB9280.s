.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240080_CB9280
/* CB9280 80240080 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CB9284 80240084 AFB00010 */  sw        $s0, 0x10($sp)
/* CB9288 80240088 3C108024 */  lui       $s0, %hi(D_80241CB0)
/* CB928C 8024008C 26101CB0 */  addiu     $s0, $s0, %lo(D_80241CB0)
/* CB9290 80240090 AFBF0018 */  sw        $ra, 0x18($sp)
/* CB9294 80240094 AFB10014 */  sw        $s1, 0x14($sp)
/* CB9298 80240098 8E020000 */  lw        $v0, ($s0)
/* CB929C 8024009C 14400010 */  bnez      $v0, .L802400E0
/* CB92A0 802400A0 0080882D */   daddu    $s1, $a0, $zero
/* CB92A4 802400A4 0C00AB39 */  jal       heap_malloc
/* CB92A8 802400A8 24040040 */   addiu    $a0, $zero, 0x40
/* CB92AC 802400AC AE020000 */  sw        $v0, ($s0)
/* CB92B0 802400B0 0000182D */  daddu     $v1, $zero, $zero
/* CB92B4 802400B4 0040282D */  daddu     $a1, $v0, $zero
/* CB92B8 802400B8 0220202D */  daddu     $a0, $s1, $zero
.L802400BC:
/* CB92BC 802400BC 8C820084 */  lw        $v0, 0x84($a0)
/* CB92C0 802400C0 24840004 */  addiu     $a0, $a0, 4
/* CB92C4 802400C4 24630001 */  addiu     $v1, $v1, 1
/* CB92C8 802400C8 ACA20000 */  sw        $v0, ($a1)
/* CB92CC 802400CC 28620010 */  slti      $v0, $v1, 0x10
/* CB92D0 802400D0 1440FFFA */  bnez      $v0, .L802400BC
/* CB92D4 802400D4 24A50004 */   addiu    $a1, $a1, 4
/* CB92D8 802400D8 08090047 */  j         .L8024011C
/* CB92DC 802400DC 00000000 */   nop      
.L802400E0:
/* CB92E0 802400E0 0000182D */  daddu     $v1, $zero, $zero
/* CB92E4 802400E4 0040282D */  daddu     $a1, $v0, $zero
/* CB92E8 802400E8 0220202D */  daddu     $a0, $s1, $zero
.L802400EC:
/* CB92EC 802400EC 8CA20000 */  lw        $v0, ($a1)
/* CB92F0 802400F0 24A50004 */  addiu     $a1, $a1, 4
/* CB92F4 802400F4 24630001 */  addiu     $v1, $v1, 1
/* CB92F8 802400F8 AC820084 */  sw        $v0, 0x84($a0)
/* CB92FC 802400FC 28620010 */  slti      $v0, $v1, 0x10
/* CB9300 80240100 1440FFFA */  bnez      $v0, .L802400EC
/* CB9304 80240104 24840004 */   addiu    $a0, $a0, 4
/* CB9308 80240108 3C108024 */  lui       $s0, %hi(D_80241CB0)
/* CB930C 8024010C 26101CB0 */  addiu     $s0, $s0, %lo(D_80241CB0)
/* CB9310 80240110 0C00AB4B */  jal       heap_free
/* CB9314 80240114 8E040000 */   lw       $a0, ($s0)
/* CB9318 80240118 AE000000 */  sw        $zero, ($s0)
.L8024011C:
/* CB931C 8024011C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CB9320 80240120 8FB10014 */  lw        $s1, 0x14($sp)
/* CB9324 80240124 8FB00010 */  lw        $s0, 0x10($sp)
/* CB9328 80240128 24020002 */  addiu     $v0, $zero, 2
/* CB932C 8024012C 03E00008 */  jr        $ra
/* CB9330 80240130 27BD0020 */   addiu    $sp, $sp, 0x20
