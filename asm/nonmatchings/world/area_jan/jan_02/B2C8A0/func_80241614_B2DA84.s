.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241614_B2DA84
/* B2DA84 80241614 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2DA88 80241618 AFB00010 */  sw        $s0, 0x10($sp)
/* B2DA8C 8024161C 3C108024 */  lui       $s0, %hi(D_802431E4)
/* B2DA90 80241620 261031E4 */  addiu     $s0, $s0, %lo(D_802431E4)
/* B2DA94 80241624 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2DA98 80241628 AFB10014 */  sw        $s1, 0x14($sp)
/* B2DA9C 8024162C 8E020000 */  lw        $v0, ($s0)
/* B2DAA0 80241630 14400010 */  bnez      $v0, .L80241674
/* B2DAA4 80241634 0080882D */   daddu    $s1, $a0, $zero
/* B2DAA8 80241638 0C00AB39 */  jal       heap_malloc
/* B2DAAC 8024163C 24040040 */   addiu    $a0, $zero, 0x40
/* B2DAB0 80241640 AE020000 */  sw        $v0, ($s0)
/* B2DAB4 80241644 0000182D */  daddu     $v1, $zero, $zero
/* B2DAB8 80241648 0040282D */  daddu     $a1, $v0, $zero
/* B2DABC 8024164C 0220202D */  daddu     $a0, $s1, $zero
.L80241650:
/* B2DAC0 80241650 8C820084 */  lw        $v0, 0x84($a0)
/* B2DAC4 80241654 24840004 */  addiu     $a0, $a0, 4
/* B2DAC8 80241658 24630001 */  addiu     $v1, $v1, 1
/* B2DACC 8024165C ACA20000 */  sw        $v0, ($a1)
/* B2DAD0 80241660 28620010 */  slti      $v0, $v1, 0x10
/* B2DAD4 80241664 1440FFFA */  bnez      $v0, .L80241650
/* B2DAD8 80241668 24A50004 */   addiu    $a1, $a1, 4
/* B2DADC 8024166C 080905AC */  j         .L802416B0
/* B2DAE0 80241670 00000000 */   nop      
.L80241674:
/* B2DAE4 80241674 0000182D */  daddu     $v1, $zero, $zero
/* B2DAE8 80241678 0040282D */  daddu     $a1, $v0, $zero
/* B2DAEC 8024167C 0220202D */  daddu     $a0, $s1, $zero
.L80241680:
/* B2DAF0 80241680 8CA20000 */  lw        $v0, ($a1)
/* B2DAF4 80241684 24A50004 */  addiu     $a1, $a1, 4
/* B2DAF8 80241688 24630001 */  addiu     $v1, $v1, 1
/* B2DAFC 8024168C AC820084 */  sw        $v0, 0x84($a0)
/* B2DB00 80241690 28620010 */  slti      $v0, $v1, 0x10
/* B2DB04 80241694 1440FFFA */  bnez      $v0, .L80241680
/* B2DB08 80241698 24840004 */   addiu    $a0, $a0, 4
/* B2DB0C 8024169C 3C108024 */  lui       $s0, %hi(D_802431E4)
/* B2DB10 802416A0 261031E4 */  addiu     $s0, $s0, %lo(D_802431E4)
/* B2DB14 802416A4 0C00AB4B */  jal       heap_free
/* B2DB18 802416A8 8E040000 */   lw       $a0, ($s0)
/* B2DB1C 802416AC AE000000 */  sw        $zero, ($s0)
.L802416B0:
/* B2DB20 802416B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2DB24 802416B4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2DB28 802416B8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2DB2C 802416BC 24020002 */  addiu     $v0, $zero, 2
/* B2DB30 802416C0 03E00008 */  jr        $ra
/* B2DB34 802416C4 27BD0020 */   addiu    $sp, $sp, 0x20
