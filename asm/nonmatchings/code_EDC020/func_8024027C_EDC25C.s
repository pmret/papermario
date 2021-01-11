.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024027C_EDC25C
/* EDC25C 8024027C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDC260 80240280 AFB00010 */  sw        $s0, 0x10($sp)
/* EDC264 80240284 3C108024 */  lui       $s0, %hi(func_802417EC_C5BF2C)
/* EDC268 80240288 261017EC */  addiu     $s0, $s0, %lo(func_802417EC_C5BF2C)
/* EDC26C 8024028C AFBF0018 */  sw        $ra, 0x18($sp)
/* EDC270 80240290 AFB10014 */  sw        $s1, 0x14($sp)
/* EDC274 80240294 8E020000 */  lw        $v0, ($s0)
/* EDC278 80240298 14400010 */  bnez      $v0, .L802402DC
/* EDC27C 8024029C 0080882D */   daddu    $s1, $a0, $zero
/* EDC280 802402A0 0C00AFF5 */  jal       func_8002BFD4
/* EDC284 802402A4 24040040 */   addiu    $a0, $zero, 0x40
/* EDC288 802402A8 AE020000 */  sw        $v0, ($s0)
/* EDC28C 802402AC 0000182D */  daddu     $v1, $zero, $zero
/* EDC290 802402B0 0040282D */  daddu     $a1, $v0, $zero
/* EDC294 802402B4 0220202D */  daddu     $a0, $s1, $zero
.L802402B8:
/* EDC298 802402B8 8C820084 */  lw        $v0, 0x84($a0)
/* EDC29C 802402BC 24840004 */  addiu     $a0, $a0, 4
/* EDC2A0 802402C0 24630001 */  addiu     $v1, $v1, 1
/* EDC2A4 802402C4 ACA20000 */  sw        $v0, ($a1)
/* EDC2A8 802402C8 28620010 */  slti      $v0, $v1, 0x10
/* EDC2AC 802402CC 1440FFFA */  bnez      $v0, .L802402B8
/* EDC2B0 802402D0 24A50004 */   addiu    $a1, $a1, 4
/* EDC2B4 802402D4 080900C6 */  j         .L80240318
/* EDC2B8 802402D8 00000000 */   nop      
.L802402DC:
/* EDC2BC 802402DC 0000182D */  daddu     $v1, $zero, $zero
/* EDC2C0 802402E0 0040282D */  daddu     $a1, $v0, $zero
/* EDC2C4 802402E4 0220202D */  daddu     $a0, $s1, $zero
.L802402E8:
/* EDC2C8 802402E8 8CA20000 */  lw        $v0, ($a1)
/* EDC2CC 802402EC 24A50004 */  addiu     $a1, $a1, 4
/* EDC2D0 802402F0 24630001 */  addiu     $v1, $v1, 1
/* EDC2D4 802402F4 AC820084 */  sw        $v0, 0x84($a0)
/* EDC2D8 802402F8 28620010 */  slti      $v0, $v1, 0x10
/* EDC2DC 802402FC 1440FFFA */  bnez      $v0, .L802402E8
/* EDC2E0 80240300 24840004 */   addiu    $a0, $a0, 4
/* EDC2E4 80240304 3C108024 */  lui       $s0, %hi(func_802417EC_C5BF2C)
/* EDC2E8 80240308 261017EC */  addiu     $s0, $s0, %lo(func_802417EC_C5BF2C)
/* EDC2EC 8024030C 0C00B007 */  jal       func_8002C01C
/* EDC2F0 80240310 8E040000 */   lw       $a0, ($s0)
/* EDC2F4 80240314 AE000000 */  sw        $zero, ($s0)
.L80240318:
/* EDC2F8 80240318 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDC2FC 8024031C 8FB10014 */  lw        $s1, 0x14($sp)
/* EDC300 80240320 8FB00010 */  lw        $s0, 0x10($sp)
/* EDC304 80240324 24020002 */  addiu     $v0, $zero, 2
/* EDC308 80240328 03E00008 */  jr        $ra
/* EDC30C 8024032C 27BD0020 */   addiu    $sp, $sp, 0x20
