.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_EC2240
/* EC2240 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC2244 80240044 AFB00010 */  sw        $s0, 0x10($sp)
/* EC2248 80240048 3C108024 */  lui       $s0, %hi(D_80240F28)
/* EC224C 8024004C 26100F28 */  addiu     $s0, $s0, %lo(D_80240F28)
/* EC2250 80240050 AFBF0018 */  sw        $ra, 0x18($sp)
/* EC2254 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* EC2258 80240058 8E020000 */  lw        $v0, ($s0)
/* EC225C 8024005C 14400010 */  bnez      $v0, .L802400A0
/* EC2260 80240060 0080882D */   daddu    $s1, $a0, $zero
/* EC2264 80240064 0C00AFF5 */  jal       func_8002BFD4
/* EC2268 80240068 24040040 */   addiu    $a0, $zero, 0x40
/* EC226C 8024006C AE020000 */  sw        $v0, ($s0)
/* EC2270 80240070 0000182D */  daddu     $v1, $zero, $zero
/* EC2274 80240074 0040282D */  daddu     $a1, $v0, $zero
/* EC2278 80240078 0220202D */  daddu     $a0, $s1, $zero
.L8024007C:
/* EC227C 8024007C 8C820084 */  lw        $v0, 0x84($a0)
/* EC2280 80240080 24840004 */  addiu     $a0, $a0, 4
/* EC2284 80240084 24630001 */  addiu     $v1, $v1, 1
/* EC2288 80240088 ACA20000 */  sw        $v0, ($a1)
/* EC228C 8024008C 28620010 */  slti      $v0, $v1, 0x10
/* EC2290 80240090 1440FFFA */  bnez      $v0, .L8024007C
/* EC2294 80240094 24A50004 */   addiu    $a1, $a1, 4
/* EC2298 80240098 08090037 */  j         .L802400DC
/* EC229C 8024009C 00000000 */   nop      
.L802400A0:
/* EC22A0 802400A0 0000182D */  daddu     $v1, $zero, $zero
/* EC22A4 802400A4 0040282D */  daddu     $a1, $v0, $zero
/* EC22A8 802400A8 0220202D */  daddu     $a0, $s1, $zero
.L802400AC:
/* EC22AC 802400AC 8CA20000 */  lw        $v0, ($a1)
/* EC22B0 802400B0 24A50004 */  addiu     $a1, $a1, 4
/* EC22B4 802400B4 24630001 */  addiu     $v1, $v1, 1
/* EC22B8 802400B8 AC820084 */  sw        $v0, 0x84($a0)
/* EC22BC 802400BC 28620010 */  slti      $v0, $v1, 0x10
/* EC22C0 802400C0 1440FFFA */  bnez      $v0, .L802400AC
/* EC22C4 802400C4 24840004 */   addiu    $a0, $a0, 4
/* EC22C8 802400C8 3C108024 */  lui       $s0, %hi(D_80240F28)
/* EC22CC 802400CC 26100F28 */  addiu     $s0, $s0, %lo(D_80240F28)
/* EC22D0 802400D0 0C00B007 */  jal       func_8002C01C
/* EC22D4 802400D4 8E040000 */   lw       $a0, ($s0)
/* EC22D8 802400D8 AE000000 */  sw        $zero, ($s0)
.L802400DC:
/* EC22DC 802400DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC22E0 802400E0 8FB10014 */  lw        $s1, 0x14($sp)
/* EC22E4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* EC22E8 802400E8 24020002 */  addiu     $v0, $zero, 2
/* EC22EC 802400EC 03E00008 */  jr        $ra
/* EC22F0 802400F0 27BD0020 */   addiu    $sp, $sp, 0x20
