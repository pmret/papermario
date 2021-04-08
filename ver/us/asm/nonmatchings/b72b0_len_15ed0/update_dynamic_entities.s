.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_dynamic_entities
/* B9B04 80123404 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9B08 80123408 AFB00010 */  sw        $s0, 0x10($sp)
/* B9B0C 8012340C 0000802D */  daddu     $s0, $zero, $zero
/* B9B10 80123410 AFB10014 */  sw        $s1, 0x14($sp)
/* B9B14 80123414 2411FFFD */  addiu     $s1, $zero, -3
/* B9B18 80123418 AFBF0018 */  sw        $ra, 0x18($sp)
.L8012341C:
/* B9B1C 8012341C 3C038015 */  lui       $v1, %hi(gCurrentDynamicEntityListPtr)
/* B9B20 80123420 8C634420 */  lw        $v1, %lo(gCurrentDynamicEntityListPtr)($v1)
/* B9B24 80123424 00101080 */  sll       $v0, $s0, 2
/* B9B28 80123428 00431021 */  addu      $v0, $v0, $v1
/* B9B2C 8012342C 8C440000 */  lw        $a0, ($v0)
/* B9B30 80123430 50800007 */  beql      $a0, $zero, .L80123450
/* B9B34 80123434 26100001 */   addiu    $s0, $s0, 1
/* B9B38 80123438 8C820000 */  lw        $v0, ($a0)
/* B9B3C 8012343C 8C830004 */  lw        $v1, 4($a0)
/* B9B40 80123440 00511024 */  and       $v0, $v0, $s1
/* B9B44 80123444 0060F809 */  jalr      $v1
/* B9B48 80123448 AC820000 */   sw       $v0, ($a0)
/* B9B4C 8012344C 26100001 */  addiu     $s0, $s0, 1
.L80123450:
/* B9B50 80123450 2A020010 */  slti      $v0, $s0, 0x10
/* B9B54 80123454 1440FFF1 */  bnez      $v0, .L8012341C
/* B9B58 80123458 00000000 */   nop
/* B9B5C 8012345C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B9B60 80123460 8FB10014 */  lw        $s1, 0x14($sp)
/* B9B64 80123464 8FB00010 */  lw        $s0, 0x10($sp)
/* B9B68 80123468 03E00008 */  jr        $ra
/* B9B6C 8012346C 27BD0020 */   addiu    $sp, $sp, 0x20
