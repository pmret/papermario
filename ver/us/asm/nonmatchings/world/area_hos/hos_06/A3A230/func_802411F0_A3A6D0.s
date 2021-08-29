.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411F0_A3A6D0
/* A3A6D0 802411F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3A6D4 802411F4 AFB00010 */  sw        $s0, 0x10($sp)
/* A3A6D8 802411F8 0000802D */  daddu     $s0, $zero, $zero
/* A3A6DC 802411FC AFB10014 */  sw        $s1, 0x14($sp)
/* A3A6E0 80241200 3C11F971 */  lui       $s1, 0xf971
/* A3A6E4 80241204 36318883 */  ori       $s1, $s1, 0x8883
/* A3A6E8 80241208 AFBF0018 */  sw        $ra, 0x18($sp)
/* A3A6EC 8024120C 0000202D */  daddu     $a0, $zero, $zero
.L80241210:
/* A3A6F0 80241210 02112821 */  addu      $a1, $s0, $s1
/* A3A6F4 80241214 0C0B2026 */  jal       evt_set_variable
/* A3A6F8 80241218 0080302D */   daddu    $a2, $a0, $zero
/* A3A6FC 8024121C 26100001 */  addiu     $s0, $s0, 1
/* A3A700 80241220 2E02004F */  sltiu     $v0, $s0, 0x4f
/* A3A704 80241224 1440FFFA */  bnez      $v0, .L80241210
/* A3A708 80241228 0000202D */   daddu    $a0, $zero, $zero
/* A3A70C 8024122C 0000802D */  daddu     $s0, $zero, $zero
/* A3A710 80241230 3C11F971 */  lui       $s1, 0xf971
/* A3A714 80241234 363188E4 */  ori       $s1, $s1, 0x88e4
.L80241238:
/* A3A718 80241238 02112821 */  addu      $a1, $s0, $s1
/* A3A71C 8024123C 0C0B2026 */  jal       evt_set_variable
/* A3A720 80241240 0080302D */   daddu    $a2, $a0, $zero
/* A3A724 80241244 26100001 */  addiu     $s0, $s0, 1
/* A3A728 80241248 2E020010 */  sltiu     $v0, $s0, 0x10
/* A3A72C 8024124C 1440FFFA */  bnez      $v0, .L80241238
/* A3A730 80241250 0000202D */   daddu    $a0, $zero, $zero
/* A3A734 80241254 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3A738 80241258 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A73C 8024125C 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A740 80241260 24020002 */  addiu     $v0, $zero, 2
/* A3A744 80241264 03E00008 */  jr        $ra
/* A3A748 80241268 27BD0020 */   addiu    $sp, $sp, 0x20
