.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D0_D3ADA0
/* D3ADA0 802407D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3ADA4 802407D4 AFB00010 */  sw        $s0, 0x10($sp)
/* D3ADA8 802407D8 3C108024 */  lui       $s0, %hi(D_80244F78)
/* D3ADAC 802407DC 26104F78 */  addiu     $s0, $s0, %lo(D_80244F78)
/* D3ADB0 802407E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* D3ADB4 802407E4 AFB10014 */  sw        $s1, 0x14($sp)
/* D3ADB8 802407E8 8E020000 */  lw        $v0, ($s0)
/* D3ADBC 802407EC 14400010 */  bnez      $v0, .L80240830
/* D3ADC0 802407F0 0080882D */   daddu    $s1, $a0, $zero
/* D3ADC4 802407F4 0C00AB39 */  jal       heap_malloc
/* D3ADC8 802407F8 24040040 */   addiu    $a0, $zero, 0x40
/* D3ADCC 802407FC AE020000 */  sw        $v0, ($s0)
/* D3ADD0 80240800 0000182D */  daddu     $v1, $zero, $zero
/* D3ADD4 80240804 0040282D */  daddu     $a1, $v0, $zero
/* D3ADD8 80240808 0220202D */  daddu     $a0, $s1, $zero
.L8024080C:
/* D3ADDC 8024080C 8C820084 */  lw        $v0, 0x84($a0)
/* D3ADE0 80240810 24840004 */  addiu     $a0, $a0, 4
/* D3ADE4 80240814 24630001 */  addiu     $v1, $v1, 1
/* D3ADE8 80240818 ACA20000 */  sw        $v0, ($a1)
/* D3ADEC 8024081C 28620010 */  slti      $v0, $v1, 0x10
/* D3ADF0 80240820 1440FFFA */  bnez      $v0, .L8024080C
/* D3ADF4 80240824 24A50004 */   addiu    $a1, $a1, 4
/* D3ADF8 80240828 0809021B */  j         .L8024086C
/* D3ADFC 8024082C 00000000 */   nop
.L80240830:
/* D3AE00 80240830 0000182D */  daddu     $v1, $zero, $zero
/* D3AE04 80240834 0040282D */  daddu     $a1, $v0, $zero
/* D3AE08 80240838 0220202D */  daddu     $a0, $s1, $zero
.L8024083C:
/* D3AE0C 8024083C 8CA20000 */  lw        $v0, ($a1)
/* D3AE10 80240840 24A50004 */  addiu     $a1, $a1, 4
/* D3AE14 80240844 24630001 */  addiu     $v1, $v1, 1
/* D3AE18 80240848 AC820084 */  sw        $v0, 0x84($a0)
/* D3AE1C 8024084C 28620010 */  slti      $v0, $v1, 0x10
/* D3AE20 80240850 1440FFFA */  bnez      $v0, .L8024083C
/* D3AE24 80240854 24840004 */   addiu    $a0, $a0, 4
/* D3AE28 80240858 3C108024 */  lui       $s0, %hi(D_80244F78)
/* D3AE2C 8024085C 26104F78 */  addiu     $s0, $s0, %lo(D_80244F78)
/* D3AE30 80240860 0C00AB4B */  jal       heap_free
/* D3AE34 80240864 8E040000 */   lw       $a0, ($s0)
/* D3AE38 80240868 AE000000 */  sw        $zero, ($s0)
.L8024086C:
/* D3AE3C 8024086C 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3AE40 80240870 8FB10014 */  lw        $s1, 0x14($sp)
/* D3AE44 80240874 8FB00010 */  lw        $s0, 0x10($sp)
/* D3AE48 80240878 24020002 */  addiu     $v0, $zero, 2
/* D3AE4C 8024087C 03E00008 */  jr        $ra
/* D3AE50 80240880 27BD0020 */   addiu    $sp, $sp, 0x20
