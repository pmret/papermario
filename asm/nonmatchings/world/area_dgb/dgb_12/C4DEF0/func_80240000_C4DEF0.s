.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C4DEF0
/* C4DEF0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C4DEF4 80240004 AFB00010 */  sw        $s0, 0x10($sp)
/* C4DEF8 80240008 3C108024 */  lui       $s0, 0x8024
/* C4DEFC 8024000C 26100870 */  addiu     $s0, $s0, 0x870
/* C4DF00 80240010 AFBF0018 */  sw        $ra, 0x18($sp)
/* C4DF04 80240014 AFB10014 */  sw        $s1, 0x14($sp)
/* C4DF08 80240018 8E020000 */  lw        $v0, ($s0)
/* C4DF0C 8024001C 14400010 */  bnez      $v0, .L80240060
/* C4DF10 80240020 0080882D */   daddu    $s1, $a0, $zero
/* C4DF14 80240024 0C00AB39 */  jal       heap_malloc
/* C4DF18 80240028 24040040 */   addiu    $a0, $zero, 0x40
/* C4DF1C 8024002C AE020000 */  sw        $v0, ($s0)
/* C4DF20 80240030 0000182D */  daddu     $v1, $zero, $zero
/* C4DF24 80240034 0040282D */  daddu     $a1, $v0, $zero
/* C4DF28 80240038 0220202D */  daddu     $a0, $s1, $zero
.L8024003C:
/* C4DF2C 8024003C 8C820084 */  lw        $v0, 0x84($a0)
/* C4DF30 80240040 24840004 */  addiu     $a0, $a0, 4
/* C4DF34 80240044 24630001 */  addiu     $v1, $v1, 1
/* C4DF38 80240048 ACA20000 */  sw        $v0, ($a1)
/* C4DF3C 8024004C 28620010 */  slti      $v0, $v1, 0x10
/* C4DF40 80240050 1440FFFA */  bnez      $v0, .L8024003C
/* C4DF44 80240054 24A50004 */   addiu    $a1, $a1, 4
/* C4DF48 80240058 08090027 */  j         .L8024009C
/* C4DF4C 8024005C 00000000 */   nop      
.L80240060:
/* C4DF50 80240060 0000182D */  daddu     $v1, $zero, $zero
/* C4DF54 80240064 0040282D */  daddu     $a1, $v0, $zero
/* C4DF58 80240068 0220202D */  daddu     $a0, $s1, $zero
.L8024006C:
/* C4DF5C 8024006C 8CA20000 */  lw        $v0, ($a1)
/* C4DF60 80240070 24A50004 */  addiu     $a1, $a1, 4
/* C4DF64 80240074 24630001 */  addiu     $v1, $v1, 1
/* C4DF68 80240078 AC820084 */  sw        $v0, 0x84($a0)
/* C4DF6C 8024007C 28620010 */  slti      $v0, $v1, 0x10
/* C4DF70 80240080 1440FFFA */  bnez      $v0, .L8024006C
/* C4DF74 80240084 24840004 */   addiu    $a0, $a0, 4
/* C4DF78 80240088 3C108024 */  lui       $s0, 0x8024
/* C4DF7C 8024008C 26100870 */  addiu     $s0, $s0, 0x870
/* C4DF80 80240090 0C00AB4B */  jal       heap_free
/* C4DF84 80240094 8E040000 */   lw       $a0, ($s0)
/* C4DF88 80240098 AE000000 */  sw        $zero, ($s0)
.L8024009C:
/* C4DF8C 8024009C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C4DF90 802400A0 8FB10014 */  lw        $s1, 0x14($sp)
/* C4DF94 802400A4 8FB00010 */  lw        $s0, 0x10($sp)
/* C4DF98 802400A8 24020002 */  addiu     $v0, $zero, 2
/* C4DF9C 802400AC 03E00008 */  jr        $ra
/* C4DFA0 802400B0 27BD0020 */   addiu    $sp, $sp, 0x20
