.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80149974
/* E0074 80149974 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0078 80149978 44861000 */  mtc1      $a2, $f2
/* E007C 8014997C 44872000 */  mtc1      $a3, $f4
/* E0080 80149980 C7A00030 */  lwc1      $f0, 0x30($sp)
/* E0084 80149984 3C038016 */  lui       $v1, 0x8016
/* E0088 80149988 8C639AD0 */  lw        $v1, -0x6530($v1)
/* E008C 8014998C 0000302D */  daddu     $a2, $zero, $zero
/* E0090 80149990 AFBF0018 */  sw        $ra, 0x18($sp)
.L80149994:
/* E0094 80149994 8C620000 */  lw        $v0, ($v1)
/* E0098 80149998 30420001 */  andi      $v0, $v0, 1
/* E009C 8014999C 10400004 */  beqz      $v0, .L801499B0
/* E00A0 801499A0 24C60001 */   addiu    $a2, $a2, 1
/* E00A4 801499A4 28C2000A */  slti      $v0, $a2, 0xa
/* E00A8 801499A8 1440FFFA */  bnez      $v0, .L80149994
/* E00AC 801499AC 2463001C */   addiu    $v1, $v1, 0x1c
.L801499B0:
/* E00B0 801499B0 8C620000 */  lw        $v0, ($v1)
/* E00B4 801499B4 44061000 */  mfc1      $a2, $f2
/* E00B8 801499B8 44072000 */  mfc1      $a3, $f4
/* E00BC 801499BC AC650008 */  sw        $a1, 8($v1)
/* E00C0 801499C0 E4620010 */  swc1      $f2, 0x10($v1)
/* E00C4 801499C4 E4640014 */  swc1      $f4, 0x14($v1)
/* E00C8 801499C8 E4600018 */  swc1      $f0, 0x18($v1)
/* E00CC 801499CC AC640004 */  sw        $a0, 4($v1)
/* E00D0 801499D0 34420003 */  ori       $v0, $v0, 3
/* E00D4 801499D4 AC620000 */  sw        $v0, ($v1)
/* E00D8 801499D8 0C052757 */  jal       play_sound_at_position
/* E00DC 801499DC E7A00010 */   swc1     $f0, 0x10($sp)
/* E00E0 801499E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* E00E4 801499E4 03E00008 */  jr        $ra
/* E00E8 801499E8 27BD0020 */   addiu    $sp, $sp, 0x20
