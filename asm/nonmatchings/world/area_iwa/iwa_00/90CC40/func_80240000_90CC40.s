.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_90CC40
/* 90CC40 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 90CC44 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* 90CC48 80240008 3C108024 */  lui       $s0, %hi(D_80240FF8_90DC38)
/* 90CC4C 8024000C 26100FF8 */  addiu     $s0, $s0, %lo(D_80240FF8_90DC38)
/* 90CC50 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* 90CC54 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* 90CC58 80240018 8E020000 */  lw        $v0, ($s0)
/* 90CC5C 8024001C 14400010 */  bnez      $v0, .L80240060
/* 90CC60 80240020 0080882D */   daddu    $s1, $a0, $zero
/* 90CC64 80240024 0C00AB39 */  jal       heap_malloc
/* 90CC68 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* 90CC6C 8024002C AE020000 */  sw        $v0, ($s0)
/* 90CC70 80240030 0000182D */  daddu     $v1, $zero, $zero
/* 90CC74 80240034 0040282D */  daddu     $a1, $v0, $zero
/* 90CC78 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* 90CC7C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* 90CC80 80240040 24840004 */  addiu     $a0, $a0, 4
/* 90CC84 80240044 24630001 */  addiu     $v1, $v1, 1
/* 90CC88 80240048 ACA20000 */  sw        $v0, ($a1)
/* 90CC8C 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* 90CC90 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* 90CC94 80240054 24A50004 */   addiu    $a1, $a1, 4
/* 90CC98 80240058 08090027 */  j         .L8024009C
/* 90CC9C 8024005C 00000000 */   nop
.L80240060:
/* 90CCA0 80240060 0000182D */  daddu     $v1, $zero, $zero
/* 90CCA4 80240064 0040282D */  daddu     $a1, $v0, $zero
/* 90CCA8 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* 90CCAC 8024006C 8CA20000 */  lw        $v0, ($a1)
/* 90CCB0 80240070 24A50004 */  addiu     $a1, $a1, 4
/* 90CCB4 80240074 24630001 */  addiu     $v1, $v1, 1
/* 90CCB8 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* 90CCBC 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* 90CCC0 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* 90CCC4 80240084 24840004 */   addiu    $a0, $a0, 4
/* 90CCC8 80240088 3C108024 */  lui       $s0, %hi(D_80240FF8_90DC38)
/* 90CCCC 8024008C 26100FF8 */  addiu     $s0, $s0, %lo(D_80240FF8_90DC38)
/* 90CCD0 80240090 0C00AB4B */  jal       heap_free
/* 90CCD4 80240094 8E040000 */   lw       $a0, ($s0)
/* 90CCD8 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* 90CCDC 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 90CCE0 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 90CCE4 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 90CCE8 802400A8 24020002 */  addiu     $v0, $zero, 2
/* 90CCEC 802400AC 03E00008 */  jr        $ra
/* 90CCF0 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
