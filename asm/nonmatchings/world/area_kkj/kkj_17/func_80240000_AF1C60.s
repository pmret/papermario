.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_AF1C60
/* AF1C60 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AF1C64 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* AF1C68 80240008 3C108024 */  lui       $s0, 0x8024
/* AF1C6C 8024000C 261008C0 */  addiu     $s0, $s0, 0x8c0
/* AF1C70 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* AF1C74 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* AF1C78 80240018 8E020000 */  lw        $v0, ($s0)
/* AF1C7C 8024001C 14400010 */  bnez      $v0, .L80240060
/* AF1C80 80240020 0080882D */   daddu    $s1, $a0, $zero
/* AF1C84 80240024 0C00AB39 */  jal       heap_malloc
/* AF1C88 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* AF1C8C 8024002C AE020000 */  sw        $v0, ($s0)
/* AF1C90 80240030 0000182D */  daddu     $v1, $zero, $zero
/* AF1C94 80240034 0040282D */  daddu     $a1, $v0, $zero
/* AF1C98 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* AF1C9C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* AF1CA0 80240040 24840004 */  addiu     $a0, $a0, 4
/* AF1CA4 80240044 24630001 */  addiu     $v1, $v1, 1
/* AF1CA8 80240048 ACA20000 */  sw        $v0, ($a1)
/* AF1CAC 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* AF1CB0 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* AF1CB4 80240054 24A50004 */   addiu    $a1, $a1, 4
/* AF1CB8 80240058 08090027 */  j         .L8024009C
/* AF1CBC 8024005C 00000000 */   nop      
.L80240060:
/* AF1CC0 80240060 0000182D */  daddu     $v1, $zero, $zero
/* AF1CC4 80240064 0040282D */  daddu     $a1, $v0, $zero
/* AF1CC8 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* AF1CCC 8024006C 8CA20000 */  lw        $v0, ($a1)
/* AF1CD0 80240070 24A50004 */  addiu     $a1, $a1, 4
/* AF1CD4 80240074 24630001 */  addiu     $v1, $v1, 1
/* AF1CD8 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* AF1CDC 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* AF1CE0 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* AF1CE4 80240084 24840004 */   addiu    $a0, $a0, 4
/* AF1CE8 80240088 3C108024 */  lui       $s0, 0x8024
/* AF1CEC 8024008C 261008C0 */  addiu     $s0, $s0, 0x8c0
/* AF1CF0 80240090 0C00AB4B */  jal       heap_free
/* AF1CF4 80240094 8E040000 */   lw       $a0, ($s0)
/* AF1CF8 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* AF1CFC 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* AF1D00 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* AF1D04 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* AF1D08 802400A8 24020002 */  addiu     $v0, $zero, 2
/* AF1D0C 802400AC 03E00008 */  jr        $ra
/* AF1D10 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
