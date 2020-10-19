.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AF8
/* 92ADA8 80240AF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 92ADAC 80240AFC AFB00010 */  sw        $s0, 0x10($sp)
/* 92ADB0 80240B00 0080802D */  daddu     $s0, $a0, $zero
/* 92ADB4 80240B04 AFBF0018 */  sw        $ra, 0x18($sp)
/* 92ADB8 80240B08 AFB10014 */  sw        $s1, 0x14($sp)
/* 92ADBC 80240B0C 8E02000C */  lw        $v0, 0xc($s0)
/* 92ADC0 80240B10 8C510000 */  lw        $s1, ($v0)
/* 92ADC4 80240B14 0C0B1EAF */  jal       get_variable
/* 92ADC8 80240B18 0220282D */   daddu    $a1, $s1, $zero
/* 92ADCC 80240B1C 3C03FFF0 */  lui       $v1, 0xfff0
/* 92ADD0 80240B20 3463FFFF */  ori       $v1, $v1, 0xffff
/* 92ADD4 80240B24 0200202D */  daddu     $a0, $s0, $zero
/* 92ADD8 80240B28 00431024 */  and       $v0, $v0, $v1
/* 92ADDC 80240B2C 00021140 */  sll       $v0, $v0, 5
/* 92ADE0 80240B30 3C068008 */  lui       $a2, %hi(gItemTable)
/* 92ADE4 80240B34 00C23021 */  addu      $a2, $a2, $v0
/* 92ADE8 80240B38 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 92ADEC 80240B3C 0C0B2026 */  jal       set_variable
/* 92ADF0 80240B40 0220282D */   daddu    $a1, $s1, $zero
/* 92ADF4 80240B44 8FBF0018 */  lw        $ra, 0x18($sp)
/* 92ADF8 80240B48 8FB10014 */  lw        $s1, 0x14($sp)
/* 92ADFC 80240B4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 92AE00 80240B50 24020002 */  addiu     $v0, $zero, 2
/* 92AE04 80240B54 03E00008 */  jr        $ra
/* 92AE08 80240B58 27BD0020 */   addiu    $sp, $sp, 0x20
