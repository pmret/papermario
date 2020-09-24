.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel step_current_game_mode
/* A9578 80112E78 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A957C 80112E7C AFB00010 */  sw        $s0, 0x10($sp)
/* A9580 80112E80 3C108015 */  lui       $s0, 0x8015
/* A9584 80112E84 26101700 */  addiu     $s0, $s0, 0x1700
/* A9588 80112E88 AFB10014 */  sw        $s1, 0x14($sp)
/* A958C 80112E8C 0000882D */  daddu     $s1, $zero, $zero
/* A9590 80112E90 AFBF0018 */  sw        $ra, 0x18($sp)
.L80112E94:
/* A9594 80112E94 96040000 */  lhu       $a0, ($s0)
/* A9598 80112E98 5080000C */  beql      $a0, $zero, .L80112ECC
/* A959C 80112E9C 26310001 */   addiu    $s1, $s1, 1
/* A95A0 80112EA0 30820004 */  andi      $v0, $a0, 4
/* A95A4 80112EA4 54400009 */  bnel      $v0, $zero, .L80112ECC
/* A95A8 80112EA8 26310001 */   addiu    $s1, $s1, 1
/* A95AC 80112EAC 30820008 */  andi      $v0, $a0, 8
/* A95B0 80112EB0 54400006 */  bnel      $v0, $zero, .L80112ECC
/* A95B4 80112EB4 26310001 */   addiu    $s1, $s1, 1
/* A95B8 80112EB8 8E030008 */  lw        $v1, 8($s0)
/* A95BC 80112EBC 3082FFFD */  andi      $v0, $a0, 0xfffd
/* A95C0 80112EC0 0060F809 */  jalr      $v1
/* A95C4 80112EC4 A6020000 */   sh       $v0, ($s0)
/* A95C8 80112EC8 26310001 */  addiu     $s1, $s1, 1
.L80112ECC:
/* A95CC 80112ECC 2A220002 */  slti      $v0, $s1, 2
/* A95D0 80112ED0 1440FFF0 */  bnez      $v0, .L80112E94
/* A95D4 80112ED4 26100018 */   addiu    $s0, $s0, 0x18
/* A95D8 80112ED8 8FBF0018 */  lw        $ra, 0x18($sp)
/* A95DC 80112EDC 8FB10014 */  lw        $s1, 0x14($sp)
/* A95E0 80112EE0 8FB00010 */  lw        $s0, 0x10($sp)
/* A95E4 80112EE4 03E00008 */  jr        $ra
/* A95E8 80112EE8 27BD0020 */   addiu    $sp, $sp, 0x20
