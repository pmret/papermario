.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BCEBF0
/* BCEBF0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BCEBF4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* BCEBF8 80240008 3C108024 */  lui       $s0, %hi(D_80241FB0)
/* BCEBFC 8024000C 26101FB0 */  addiu     $s0, $s0, %lo(D_80241FB0)
/* BCEC00 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* BCEC04 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* BCEC08 80240018 8E020000 */  lw        $v0, ($s0)
/* BCEC0C 8024001C 14400010 */  bnez      $v0, .L80240060
/* BCEC10 80240020 0080882D */   daddu    $s1, $a0, $zero
/* BCEC14 80240024 0C00AB39 */  jal       heap_malloc
/* BCEC18 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* BCEC1C 8024002C AE020000 */  sw        $v0, ($s0)
/* BCEC20 80240030 0000182D */  daddu     $v1, $zero, $zero
/* BCEC24 80240034 0040282D */  daddu     $a1, $v0, $zero
/* BCEC28 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* BCEC2C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* BCEC30 80240040 24840004 */  addiu     $a0, $a0, 4
/* BCEC34 80240044 24630001 */  addiu     $v1, $v1, 1
/* BCEC38 80240048 ACA20000 */  sw        $v0, ($a1)
/* BCEC3C 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* BCEC40 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* BCEC44 80240054 24A50004 */   addiu    $a1, $a1, 4
/* BCEC48 80240058 08090027 */  j         .L8024009C
/* BCEC4C 8024005C 00000000 */   nop      
.L80240060:
/* BCEC50 80240060 0000182D */  daddu     $v1, $zero, $zero
/* BCEC54 80240064 0040282D */  daddu     $a1, $v0, $zero
/* BCEC58 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* BCEC5C 8024006C 8CA20000 */  lw        $v0, ($a1)
/* BCEC60 80240070 24A50004 */  addiu     $a1, $a1, 4
/* BCEC64 80240074 24630001 */  addiu     $v1, $v1, 1
/* BCEC68 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* BCEC6C 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* BCEC70 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* BCEC74 80240084 24840004 */   addiu    $a0, $a0, 4
/* BCEC78 80240088 3C108024 */  lui       $s0, %hi(D_80241FB0)
/* BCEC7C 8024008C 26101FB0 */  addiu     $s0, $s0, %lo(D_80241FB0)
/* BCEC80 80240090 0C00AB4B */  jal       heap_free
/* BCEC84 80240094 8E040000 */   lw       $a0, ($s0)
/* BCEC88 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* BCEC8C 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BCEC90 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* BCEC94 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* BCEC98 802400A8 24020002 */  addiu     $v0, $zero, 2
/* BCEC9C 802400AC 03E00008 */  jr        $ra
/* BCECA0 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
