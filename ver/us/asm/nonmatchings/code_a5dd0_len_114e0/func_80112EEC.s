.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80112EEC
/* A95EC 80112EEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A95F0 80112EF0 AFB00010 */  sw        $s0, 0x10($sp)
/* A95F4 80112EF4 3C108015 */  lui       $s0, %hi(gMainGameState)
/* A95F8 80112EF8 26101700 */  addiu     $s0, $s0, %lo(gMainGameState)
/* A95FC 80112EFC AFB10014 */  sw        $s1, 0x14($sp)
/* A9600 80112F00 0000882D */  daddu     $s1, $zero, $zero
/* A9604 80112F04 AFBF0018 */  sw        $ra, 0x18($sp)
.L80112F08:
/* A9608 80112F08 96030000 */  lhu       $v1, ($s0)
/* A960C 80112F0C 5060000A */  beql      $v1, $zero, .L80112F38
/* A9610 80112F10 26310001 */   addiu    $s1, $s1, 1
/* A9614 80112F14 30620004 */  andi      $v0, $v1, 4
/* A9618 80112F18 14400007 */  bnez      $v0, .L80112F38
/* A961C 80112F1C 26310001 */   addiu    $s1, $s1, 1
/* A9620 80112F20 30620010 */  andi      $v0, $v1, 0x10
/* A9624 80112F24 14400004 */  bnez      $v0, .L80112F38
/* A9628 80112F28 00000000 */   nop
/* A962C 80112F2C 8E02000C */  lw        $v0, 0xc($s0)
/* A9630 80112F30 0040F809 */  jalr      $v0
/* A9634 80112F34 00000000 */   nop
.L80112F38:
/* A9638 80112F38 2A220002 */  slti      $v0, $s1, 2
/* A963C 80112F3C 1440FFF2 */  bnez      $v0, .L80112F08
/* A9640 80112F40 26100018 */   addiu    $s0, $s0, 0x18
/* A9644 80112F44 8FBF0018 */  lw        $ra, 0x18($sp)
/* A9648 80112F48 8FB10014 */  lw        $s1, 0x14($sp)
/* A964C 80112F4C 8FB00010 */  lw        $s0, 0x10($sp)
/* A9650 80112F50 03E00008 */  jr        $ra
/* A9654 80112F54 27BD0020 */   addiu    $sp, $sp, 0x20
