.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_91E5B0
/* 91E5B0 80240040 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91E5B4 80240044 AFB00010 */  sw        $s0, 0x10($sp)
/* 91E5B8 80240048 3C108024 */  lui       $s0, %hi(D_80241DD0)
/* 91E5BC 8024004C 26101DD0 */  addiu     $s0, $s0, %lo(D_80241DD0)
/* 91E5C0 80240050 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91E5C4 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* 91E5C8 80240058 8E020000 */  lw        $v0, ($s0)
/* 91E5CC 8024005C 14400010 */  bnez      $v0, .L802400A0
/* 91E5D0 80240060 0080882D */   daddu    $s1, $a0, $zero
/* 91E5D4 80240064 0C00AB39 */  jal       heap_malloc
/* 91E5D8 80240068 24040040 */   addiu    $a0, $zero, 0x40
/* 91E5DC 8024006C AE020000 */  sw        $v0, ($s0)
/* 91E5E0 80240070 0000182D */  daddu     $v1, $zero, $zero
/* 91E5E4 80240074 0040282D */  daddu     $a1, $v0, $zero
/* 91E5E8 80240078 0220202D */  daddu     $a0, $s1, $zero
.L8024007C:
/* 91E5EC 8024007C 8C820084 */  lw        $v0, 0x84($a0)
/* 91E5F0 80240080 24840004 */  addiu     $a0, $a0, 4
/* 91E5F4 80240084 24630001 */  addiu     $v1, $v1, 1
/* 91E5F8 80240088 ACA20000 */  sw        $v0, ($a1)
/* 91E5FC 8024008C 28620010 */  slti      $v0, $v1, 0x10
/* 91E600 80240090 1440FFFA */  bnez      $v0, .L8024007C
/* 91E604 80240094 24A50004 */   addiu    $a1, $a1, 4
/* 91E608 80240098 08090037 */  j         .L802400DC
/* 91E60C 8024009C 00000000 */   nop
.L802400A0:
/* 91E610 802400A0 0000182D */  daddu     $v1, $zero, $zero
/* 91E614 802400A4 0040282D */  daddu     $a1, $v0, $zero
/* 91E618 802400A8 0220202D */  daddu     $a0, $s1, $zero
.L802400AC:
/* 91E61C 802400AC 8CA20000 */  lw        $v0, ($a1)
/* 91E620 802400B0 24A50004 */  addiu     $a1, $a1, 4
/* 91E624 802400B4 24630001 */  addiu     $v1, $v1, 1
/* 91E628 802400B8 AC820084 */  sw        $v0, 0x84($a0)
/* 91E62C 802400BC 28620010 */  slti      $v0, $v1, 0x10
/* 91E630 802400C0 1440FFFA */  bnez      $v0, .L802400AC
/* 91E634 802400C4 24840004 */   addiu    $a0, $a0, 4
/* 91E638 802400C8 3C108024 */  lui       $s0, %hi(D_80241DD0)
/* 91E63C 802400CC 26101DD0 */  addiu     $s0, $s0, %lo(D_80241DD0)
/* 91E640 802400D0 0C00AB4B */  jal       heap_free
/* 91E644 802400D4 8E040000 */   lw       $a0, ($s0)
/* 91E648 802400D8 AE000000 */  sw        $zero, ($s0)
.L802400DC:
/* 91E64C 802400DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91E650 802400E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 91E654 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 91E658 802400E8 24020002 */  addiu     $v0, $zero, 2
/* 91E65C 802400EC 03E00008 */  jr        $ra
/* 91E660 802400F0 27BD0020 */   addiu    $sp, $sp, 0x20
