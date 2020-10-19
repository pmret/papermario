.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240858
/* BC4AD8 80240858 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC4ADC 8024085C AFB00010 */  sw        $s0, 0x10($sp)
/* BC4AE0 80240860 0080802D */  daddu     $s0, $a0, $zero
/* BC4AE4 80240864 AFBF0014 */  sw        $ra, 0x14($sp)
/* BC4AE8 80240868 0C00EABB */  jal       get_npc_unsafe
/* BC4AEC 8024086C 8E04008C */   lw       $a0, 0x8c($s0)
/* BC4AF0 80240870 0040282D */  daddu     $a1, $v0, $zero
/* BC4AF4 80240874 8E040094 */  lw        $a0, 0x94($s0)
/* BC4AF8 80240878 8CA30028 */  lw        $v1, 0x28($a1)
/* BC4AFC 8024087C ACA40028 */  sw        $a0, 0x28($a1)
/* BC4B00 80240880 8FBF0014 */  lw        $ra, 0x14($sp)
/* BC4B04 80240884 8FB00010 */  lw        $s0, 0x10($sp)
/* BC4B08 80240888 24020002 */  addiu     $v0, $zero, 2
/* BC4B0C 8024088C 3C018024 */  lui       $at, 0x8024
/* BC4B10 80240890 AC233DA4 */  sw        $v1, 0x3da4($at)
/* BC4B14 80240894 03E00008 */  jr        $ra
/* BC4B18 80240898 27BD0018 */   addiu    $sp, $sp, 0x18
