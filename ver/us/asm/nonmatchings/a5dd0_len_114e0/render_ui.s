.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_ui
/* A9658 80112F58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A965C 80112F5C AFB00010 */  sw        $s0, 0x10($sp)
/* A9660 80112F60 3C108015 */  lui       $s0, %hi(gMainGameState)
/* A9664 80112F64 26101700 */  addiu     $s0, $s0, %lo(gMainGameState)
/* A9668 80112F68 AFB10014 */  sw        $s1, 0x14($sp)
/* A966C 80112F6C 0000882D */  daddu     $s1, $zero, $zero
/* A9670 80112F70 AFBF0018 */  sw        $ra, 0x18($sp)
.L80112F74:
/* A9674 80112F74 96030000 */  lhu       $v1, ($s0)
/* A9678 80112F78 5060000A */  beql      $v1, $zero, .L80112FA4
/* A967C 80112F7C 26310001 */   addiu    $s1, $s1, 1
/* A9680 80112F80 30620004 */  andi      $v0, $v1, 4
/* A9684 80112F84 14400007 */  bnez      $v0, .L80112FA4
/* A9688 80112F88 26310001 */   addiu    $s1, $s1, 1
/* A968C 80112F8C 30620010 */  andi      $v0, $v1, 0x10
/* A9690 80112F90 14400004 */  bnez      $v0, .L80112FA4
/* A9694 80112F94 00000000 */   nop
/* A9698 80112F98 8E020010 */  lw        $v0, 0x10($s0)
/* A969C 80112F9C 0040F809 */  jalr      $v0
/* A96A0 80112FA0 00000000 */   nop
.L80112FA4:
/* A96A4 80112FA4 2A220002 */  slti      $v0, $s1, 2
/* A96A8 80112FA8 1440FFF2 */  bnez      $v0, .L80112F74
/* A96AC 80112FAC 26100018 */   addiu    $s0, $s0, 0x18
/* A96B0 80112FB0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A96B4 80112FB4 8FB10014 */  lw        $s1, 0x14($sp)
/* A96B8 80112FB8 8FB00010 */  lw        $s0, 0x10($sp)
/* A96BC 80112FBC 03E00008 */  jr        $ra
/* A96C0 80112FC0 27BD0020 */   addiu    $sp, $sp, 0x20
