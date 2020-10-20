.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240050_BC7EB0
/* BC7EB0 80240050 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC7EB4 80240054 AFB10014 */  sw        $s1, 0x14($sp)
/* BC7EB8 80240058 0080882D */  daddu     $s1, $a0, $zero
/* BC7EBC 8024005C AFBF0018 */  sw        $ra, 0x18($sp)
/* BC7EC0 80240060 AFB00010 */  sw        $s0, 0x10($sp)
/* BC7EC4 80240064 0C00EABB */  jal       get_npc_unsafe
/* BC7EC8 80240068 8E24014C */   lw       $a0, 0x14c($s1)
/* BC7ECC 8024006C 24040004 */  addiu     $a0, $zero, 4
/* BC7ED0 80240070 0C00AB39 */  jal       heap_malloc
/* BC7ED4 80240074 0040802D */   daddu    $s0, $v0, $zero
/* BC7ED8 80240078 3C0142FA */  lui       $at, 0x42fa
/* BC7EDC 8024007C 44810000 */  mtc1      $at, $f0
/* BC7EE0 80240080 3C01C45A */  lui       $at, 0xc45a
/* BC7EE4 80240084 3421C000 */  ori       $at, $at, 0xc000
/* BC7EE8 80240088 44811000 */  mtc1      $at, $f2
/* BC7EEC 8024008C 0040182D */  daddu     $v1, $v0, $zero
/* BC7EF0 80240090 AE030020 */  sw        $v1, 0x20($s0)
/* BC7EF4 80240094 AC600000 */  sw        $zero, ($v1)
/* BC7EF8 80240098 2403003C */  addiu     $v1, $zero, 0x3c
/* BC7EFC 8024009C AE00000C */  sw        $zero, 0xc($s0)
/* BC7F00 802400A0 AE000038 */  sw        $zero, 0x38($s0)
/* BC7F04 802400A4 AE000040 */  sw        $zero, 0x40($s0)
/* BC7F08 802400A8 A603008E */  sh        $v1, 0x8e($s0)
/* BC7F0C 802400AC E6000010 */  swc1      $f0, 0x10($s0)
/* BC7F10 802400B0 E602003C */  swc1      $f2, 0x3c($s0)
/* BC7F14 802400B4 AE200074 */  sw        $zero, 0x74($s1)
/* BC7F18 802400B8 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC7F1C 802400BC 8FB10014 */  lw        $s1, 0x14($sp)
/* BC7F20 802400C0 8FB00010 */  lw        $s0, 0x10($sp)
/* BC7F24 802400C4 24020002 */  addiu     $v0, $zero, 2
/* BC7F28 802400C8 03E00008 */  jr        $ra
/* BC7F2C 802400CC 27BD0020 */   addiu    $sp, $sp, 0x20
