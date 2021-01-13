.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240830_A2AA70
/* A2AA70 80240830 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2AA74 80240834 3C028011 */  lui       $v0, %hi(gPlayerData)
/* A2AA78 80240838 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* A2AA7C 8024083C AFBF0010 */  sw        $ra, 0x10($sp)
/* A2AA80 80240840 90450003 */  lbu       $a1, 3($v0)
/* A2AA84 80240844 90460006 */  lbu       $a2, 6($v0)
/* A2AA88 80240848 8044028E */  lb        $a0, 0x28e($v0)
/* A2AA8C 8024084C 24030001 */  addiu     $v1, $zero, 1
/* A2AA90 80240850 A0430292 */  sb        $v1, 0x292($v0)
/* A2AA94 80240854 00042200 */  sll       $a0, $a0, 8
/* A2AA98 80240858 A0450002 */  sb        $a1, 2($v0)
/* A2AA9C 8024085C A0460005 */  sb        $a2, 5($v0)
/* A2AAA0 80240860 0C03A6DB */  jal       sync_status_menu
/* A2AAA4 80240864 A4440290 */   sh       $a0, 0x290($v0)
/* A2AAA8 80240868 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2AAAC 8024086C 24020002 */  addiu     $v0, $zero, 2
/* A2AAB0 80240870 03E00008 */  jr        $ra
/* A2AAB4 80240874 27BD0018 */   addiu    $sp, $sp, 0x18
/* A2AAB8 80240878 00000000 */  nop
/* A2AABC 8024087C 00000000 */  nop
