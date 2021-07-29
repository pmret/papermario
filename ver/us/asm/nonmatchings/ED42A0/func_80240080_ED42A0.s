.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240080_ED42A0
/* ED42A0 80240080 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ED42A4 80240084 AFB00010 */  sw        $s0, 0x10($sp)
/* ED42A8 80240088 3C108024 */  lui       $s0, %hi(D_80241DA0_ED5FC0)
/* ED42AC 8024008C 26101DA0 */  addiu     $s0, $s0, %lo(D_80241DA0_ED5FC0)
/* ED42B0 80240090 AFBF0018 */  sw        $ra, 0x18($sp)
/* ED42B4 80240094 AFB10014 */  sw        $s1, 0x14($sp)
/* ED42B8 80240098 8E020000 */  lw        $v0, ($s0)
/* ED42BC 8024009C 14400010 */  bnez      $v0, .L802400E0
/* ED42C0 802400A0 0080882D */   daddu    $s1, $a0, $zero
/* ED42C4 802400A4 0C00AFF5 */  jal       func_8002BFD4
/* ED42C8 802400A8 24040040 */   addiu    $a0, $zero, 0x40
/* ED42CC 802400AC AE020000 */  sw        $v0, ($s0)
/* ED42D0 802400B0 0000182D */  daddu     $v1, $zero, $zero
/* ED42D4 802400B4 0040282D */  daddu     $a1, $v0, $zero
/* ED42D8 802400B8 0220202D */  daddu     $a0, $s1, $zero
.L802400BC:
/* ED42DC 802400BC 8C820084 */  lw        $v0, 0x84($a0)
/* ED42E0 802400C0 24840004 */  addiu     $a0, $a0, 4
/* ED42E4 802400C4 24630001 */  addiu     $v1, $v1, 1
/* ED42E8 802400C8 ACA20000 */  sw        $v0, ($a1)
/* ED42EC 802400CC 28620010 */  slti      $v0, $v1, 0x10
/* ED42F0 802400D0 1440FFFA */  bnez      $v0, .L802400BC
/* ED42F4 802400D4 24A50004 */   addiu    $a1, $a1, 4
/* ED42F8 802400D8 08090047 */  j         .L8024011C
/* ED42FC 802400DC 00000000 */   nop
.L802400E0:
/* ED4300 802400E0 0000182D */  daddu     $v1, $zero, $zero
/* ED4304 802400E4 0040282D */  daddu     $a1, $v0, $zero
/* ED4308 802400E8 0220202D */  daddu     $a0, $s1, $zero
.L802400EC:
/* ED430C 802400EC 8CA20000 */  lw        $v0, ($a1)
/* ED4310 802400F0 24A50004 */  addiu     $a1, $a1, 4
/* ED4314 802400F4 24630001 */  addiu     $v1, $v1, 1
/* ED4318 802400F8 AC820084 */  sw        $v0, 0x84($a0)
/* ED431C 802400FC 28620010 */  slti      $v0, $v1, 0x10
/* ED4320 80240100 1440FFFA */  bnez      $v0, .L802400EC
/* ED4324 80240104 24840004 */   addiu    $a0, $a0, 4
/* ED4328 80240108 3C108024 */  lui       $s0, %hi(D_80241DA0_ED5FC0)
/* ED432C 8024010C 26101DA0 */  addiu     $s0, $s0, %lo(D_80241DA0_ED5FC0)
/* ED4330 80240110 0C00B007 */  jal       func_8002C01C
/* ED4334 80240114 8E040000 */   lw       $a0, ($s0)
/* ED4338 80240118 AE000000 */  sw        $zero, ($s0)
.L8024011C:
/* ED433C 8024011C 8FBF0018 */  lw        $ra, 0x18($sp)
/* ED4340 80240120 8FB10014 */  lw        $s1, 0x14($sp)
/* ED4344 80240124 8FB00010 */  lw        $s0, 0x10($sp)
/* ED4348 80240128 24020002 */  addiu     $v0, $zero, 2
/* ED434C 8024012C 03E00008 */  jr        $ra
/* ED4350 80240130 27BD0020 */   addiu    $sp, $sp, 0x20
