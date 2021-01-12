.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412B0_BE0040
/* BE0040 802412B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE0044 802412B4 AFB00010 */  sw        $s0, 0x10($sp)
/* BE0048 802412B8 3C108024 */  lui       $s0, %hi(D_80241C68)
/* BE004C 802412BC 26101C68 */  addiu     $s0, $s0, %lo(D_80241C68)
/* BE0050 802412C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* BE0054 802412C4 AFB10014 */  sw        $s1, 0x14($sp)
/* BE0058 802412C8 8E020000 */  lw        $v0, ($s0)
/* BE005C 802412CC 14400010 */  bnez      $v0, .L80241310
/* BE0060 802412D0 0080882D */   daddu    $s1, $a0, $zero
/* BE0064 802412D4 0C00AB39 */  jal       heap_malloc
/* BE0068 802412D8 24040040 */   addiu    $a0, $zero, 0x40
/* BE006C 802412DC AE020000 */  sw        $v0, ($s0)
/* BE0070 802412E0 0000182D */  daddu     $v1, $zero, $zero
/* BE0074 802412E4 0040282D */  daddu     $a1, $v0, $zero
/* BE0078 802412E8 0220202D */  daddu     $a0, $s1, $zero
.L802412EC:
/* BE007C 802412EC 8C820084 */  lw        $v0, 0x84($a0)
/* BE0080 802412F0 24840004 */  addiu     $a0, $a0, 4
/* BE0084 802412F4 24630001 */  addiu     $v1, $v1, 1
/* BE0088 802412F8 ACA20000 */  sw        $v0, ($a1)
/* BE008C 802412FC 28620010 */  slti      $v0, $v1, 0x10
/* BE0090 80241300 1440FFFA */  bnez      $v0, .L802412EC
/* BE0094 80241304 24A50004 */   addiu    $a1, $a1, 4
/* BE0098 80241308 080904D3 */  j         .L8024134C
/* BE009C 8024130C 00000000 */   nop
.L80241310:
/* BE00A0 80241310 0000182D */  daddu     $v1, $zero, $zero
/* BE00A4 80241314 0040282D */  daddu     $a1, $v0, $zero
/* BE00A8 80241318 0220202D */  daddu     $a0, $s1, $zero
.L8024131C:
/* BE00AC 8024131C 8CA20000 */  lw        $v0, ($a1)
/* BE00B0 80241320 24A50004 */  addiu     $a1, $a1, 4
/* BE00B4 80241324 24630001 */  addiu     $v1, $v1, 1
/* BE00B8 80241328 AC820084 */  sw        $v0, 0x84($a0)
/* BE00BC 8024132C 28620010 */  slti      $v0, $v1, 0x10
/* BE00C0 80241330 1440FFFA */  bnez      $v0, .L8024131C
/* BE00C4 80241334 24840004 */   addiu    $a0, $a0, 4
/* BE00C8 80241338 3C108024 */  lui       $s0, %hi(D_80241C68)
/* BE00CC 8024133C 26101C68 */  addiu     $s0, $s0, %lo(D_80241C68)
/* BE00D0 80241340 0C00AB4B */  jal       heap_free
/* BE00D4 80241344 8E040000 */   lw       $a0, ($s0)
/* BE00D8 80241348 AE000000 */  sw        $zero, ($s0)
.L8024134C:
/* BE00DC 8024134C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BE00E0 80241350 8FB10014 */  lw        $s1, 0x14($sp)
/* BE00E4 80241354 8FB00010 */  lw        $s0, 0x10($sp)
/* BE00E8 80241358 24020002 */  addiu     $v0, $zero, 2
/* BE00EC 8024135C 03E00008 */  jr        $ra
/* BE00F0 80241360 27BD0020 */   addiu    $sp, $sp, 0x20
