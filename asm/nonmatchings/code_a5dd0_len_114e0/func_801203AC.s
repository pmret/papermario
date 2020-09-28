.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801203AC
/* B6AAC 801203AC 27BDFE00 */  addiu     $sp, $sp, -0x200
/* B6AB0 801203B0 2402F7FF */  addiu     $v0, $zero, -0x801
/* B6AB4 801203B4 00822024 */  and       $a0, $a0, $v0
/* B6AB8 801203B8 3C028015 */  lui       $v0, 0x8015
/* B6ABC 801203BC 8C423A40 */  lw        $v0, 0x3a40($v0)
/* B6AC0 801203C0 00042080 */  sll       $a0, $a0, 2
/* B6AC4 801203C4 AFBF01FC */  sw        $ra, 0x1fc($sp)
/* B6AC8 801203C8 AFB001F8 */  sw        $s0, 0x1f8($sp)
/* B6ACC 801203CC 00822021 */  addu      $a0, $a0, $v0
/* B6AD0 801203D0 8C900000 */  lw        $s0, ($a0)
/* B6AD4 801203D4 1200000E */  beqz      $s0, .L80120410
/* B6AD8 801203D8 00A0182D */   daddu    $v1, $a1, $zero
/* B6ADC 801203DC 8E020000 */  lw        $v0, ($s0)
/* B6AE0 801203E0 1040000B */  beqz      $v0, .L80120410
/* B6AE4 801203E4 0200282D */   daddu    $a1, $s0, $zero
/* B6AE8 801203E8 0000302D */  daddu     $a2, $zero, $zero
/* B6AEC 801203EC 3C018015 */  lui       $at, 0x8015
/* B6AF0 801203F0 AC233B68 */  sw        $v1, 0x3b68($at)
/* B6AF4 801203F4 8C640000 */  lw        $a0, ($v1)
/* B6AF8 801203F8 0C04808D */  jal       func_80120234
/* B6AFC 801203FC 27A70010 */   addiu    $a3, $sp, 0x10
/* B6B00 80120400 0200202D */  daddu     $a0, $s0, $zero
/* B6B04 80120404 27A50010 */  addiu     $a1, $sp, 0x10
/* B6B08 80120408 0C047FED */  jal       func_8011FFB4
/* B6B0C 8012040C 2406007A */   addiu    $a2, $zero, 0x7a
.L80120410:
/* B6B10 80120410 8FBF01FC */  lw        $ra, 0x1fc($sp)
/* B6B14 80120414 8FB001F8 */  lw        $s0, 0x1f8($sp)
/* B6B18 80120418 03E00008 */  jr        $ra
/* B6B1C 8012041C 27BD0200 */   addiu    $sp, $sp, 0x200
