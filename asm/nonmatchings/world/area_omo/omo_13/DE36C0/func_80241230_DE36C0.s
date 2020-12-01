.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241230_DE36C0
/* DE36C0 80241230 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE36C4 80241234 AFB00010 */  sw        $s0, 0x10($sp)
/* DE36C8 80241238 3C108024 */  lui       $s0, %hi(D_80242C70)
/* DE36CC 8024123C 26102C70 */  addiu     $s0, $s0, %lo(D_80242C70)
/* DE36D0 80241240 AFBF0018 */  sw        $ra, 0x18($sp)
/* DE36D4 80241244 AFB10014 */  sw        $s1, 0x14($sp)
/* DE36D8 80241248 8E020000 */  lw        $v0, ($s0)
/* DE36DC 8024124C 14400010 */  bnez      $v0, .L80241290
/* DE36E0 80241250 0080882D */   daddu    $s1, $a0, $zero
/* DE36E4 80241254 0C00AB39 */  jal       heap_malloc
/* DE36E8 80241258 24040040 */   addiu    $a0, $zero, 0x40
/* DE36EC 8024125C AE020000 */  sw        $v0, ($s0)
/* DE36F0 80241260 0000182D */  daddu     $v1, $zero, $zero
/* DE36F4 80241264 0040282D */  daddu     $a1, $v0, $zero
/* DE36F8 80241268 0220202D */  daddu     $a0, $s1, $zero
.L8024126C:
/* DE36FC 8024126C 8C820084 */  lw        $v0, 0x84($a0)
/* DE3700 80241270 24840004 */  addiu     $a0, $a0, 4
/* DE3704 80241274 24630001 */  addiu     $v1, $v1, 1
/* DE3708 80241278 ACA20000 */  sw        $v0, ($a1)
/* DE370C 8024127C 28620010 */  slti      $v0, $v1, 0x10
/* DE3710 80241280 1440FFFA */  bnez      $v0, .L8024126C
/* DE3714 80241284 24A50004 */   addiu    $a1, $a1, 4
/* DE3718 80241288 080904B3 */  j         .L802412CC
/* DE371C 8024128C 00000000 */   nop      
.L80241290:
/* DE3720 80241290 0000182D */  daddu     $v1, $zero, $zero
/* DE3724 80241294 0040282D */  daddu     $a1, $v0, $zero
/* DE3728 80241298 0220202D */  daddu     $a0, $s1, $zero
.L8024129C:
/* DE372C 8024129C 8CA20000 */  lw        $v0, ($a1)
/* DE3730 802412A0 24A50004 */  addiu     $a1, $a1, 4
/* DE3734 802412A4 24630001 */  addiu     $v1, $v1, 1
/* DE3738 802412A8 AC820084 */  sw        $v0, 0x84($a0)
/* DE373C 802412AC 28620010 */  slti      $v0, $v1, 0x10
/* DE3740 802412B0 1440FFFA */  bnez      $v0, .L8024129C
/* DE3744 802412B4 24840004 */   addiu    $a0, $a0, 4
/* DE3748 802412B8 3C108024 */  lui       $s0, %hi(D_80242C70)
/* DE374C 802412BC 26102C70 */  addiu     $s0, $s0, %lo(D_80242C70)
/* DE3750 802412C0 0C00AB4B */  jal       heap_free
/* DE3754 802412C4 8E040000 */   lw       $a0, ($s0)
/* DE3758 802412C8 AE000000 */  sw        $zero, ($s0)
.L802412CC:
/* DE375C 802412CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE3760 802412D0 8FB10014 */  lw        $s1, 0x14($sp)
/* DE3764 802412D4 8FB00010 */  lw        $s0, 0x10($sp)
/* DE3768 802412D8 24020002 */  addiu     $v0, $zero, 2
/* DE376C 802412DC 03E00008 */  jr        $ra
/* DE3770 802412E0 27BD0020 */   addiu    $sp, $sp, 0x20
