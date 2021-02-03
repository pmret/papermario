.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240170_BC43F0
/* BC43F0 80240170 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC43F4 80240174 AFB00010 */  sw        $s0, 0x10($sp)
/* BC43F8 80240178 3C108024 */  lui       $s0, %hi(D_80242ECC_BC714C)
/* BC43FC 8024017C 26102ECC */  addiu     $s0, $s0, %lo(D_80242ECC_BC714C)
/* BC4400 80240180 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC4404 80240184 AFB10014 */  sw        $s1, 0x14($sp)
/* BC4408 80240188 8E020000 */  lw        $v0, ($s0)
/* BC440C 8024018C 14400010 */  bnez      $v0, .L802401D0
/* BC4410 80240190 0080882D */   daddu    $s1, $a0, $zero
/* BC4414 80240194 0C00AB39 */  jal       heap_malloc
/* BC4418 80240198 24040040 */   addiu    $a0, $zero, 0x40
/* BC441C 8024019C AE020000 */  sw        $v0, ($s0)
/* BC4420 802401A0 0000182D */  daddu     $v1, $zero, $zero
/* BC4424 802401A4 0040282D */  daddu     $a1, $v0, $zero
/* BC4428 802401A8 0220202D */  daddu     $a0, $s1, $zero
.L802401AC:
/* BC442C 802401AC 8C820084 */  lw        $v0, 0x84($a0)
/* BC4430 802401B0 24840004 */  addiu     $a0, $a0, 4
/* BC4434 802401B4 24630001 */  addiu     $v1, $v1, 1
/* BC4438 802401B8 ACA20000 */  sw        $v0, ($a1)
/* BC443C 802401BC 28620010 */  slti      $v0, $v1, 0x10
/* BC4440 802401C0 1440FFFA */  bnez      $v0, .L802401AC
/* BC4444 802401C4 24A50004 */   addiu    $a1, $a1, 4
/* BC4448 802401C8 08090083 */  j         .L8024020C
/* BC444C 802401CC 00000000 */   nop
.L802401D0:
/* BC4450 802401D0 0000182D */  daddu     $v1, $zero, $zero
/* BC4454 802401D4 0040282D */  daddu     $a1, $v0, $zero
/* BC4458 802401D8 0220202D */  daddu     $a0, $s1, $zero
.L802401DC:
/* BC445C 802401DC 8CA20000 */  lw        $v0, ($a1)
/* BC4460 802401E0 24A50004 */  addiu     $a1, $a1, 4
/* BC4464 802401E4 24630001 */  addiu     $v1, $v1, 1
/* BC4468 802401E8 AC820084 */  sw        $v0, 0x84($a0)
/* BC446C 802401EC 28620010 */  slti      $v0, $v1, 0x10
/* BC4470 802401F0 1440FFFA */  bnez      $v0, .L802401DC
/* BC4474 802401F4 24840004 */   addiu    $a0, $a0, 4
/* BC4478 802401F8 3C108024 */  lui       $s0, %hi(D_80242ECC_BC714C)
/* BC447C 802401FC 26102ECC */  addiu     $s0, $s0, %lo(D_80242ECC_BC714C)
/* BC4480 80240200 0C00AB4B */  jal       heap_free
/* BC4484 80240204 8E040000 */   lw       $a0, ($s0)
/* BC4488 80240208 AE000000 */  sw        $zero, ($s0)
.L8024020C:
/* BC448C 8024020C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC4490 80240210 8FB10014 */  lw        $s1, 0x14($sp)
/* BC4494 80240214 8FB00010 */  lw        $s0, 0x10($sp)
/* BC4498 80240218 24020002 */  addiu     $v0, $zero, 2
/* BC449C 8024021C 03E00008 */  jr        $ra
/* BC44A0 80240220 27BD0020 */   addiu    $sp, $sp, 0x20
