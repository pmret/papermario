.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421D4
/* 88ADA4 802421D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 88ADA8 802421D8 0080102D */  daddu     $v0, $a0, $zero
/* 88ADAC 802421DC AFB00010 */  sw        $s0, 0x10($sp)
/* 88ADB0 802421E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 88ADB4 802421E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 88ADB8 802421E8 8C44014C */  lw        $a0, 0x14c($v0)
/* 88ADBC 802421EC 8C510148 */  lw        $s1, 0x148($v0)
/* 88ADC0 802421F0 0C00EAD2 */  jal       get_npc_safe
/* 88ADC4 802421F4 00A0802D */   daddu    $s0, $a1, $zero
/* 88ADC8 802421F8 56000001 */  bnel      $s0, $zero, .L80242200
/* 88ADCC 802421FC A04000AB */   sb       $zero, 0xab($v0)
.L80242200:
/* 88ADD0 80242200 8C420000 */  lw        $v0, ($v0)
/* 88ADD4 80242204 30421000 */  andi      $v0, $v0, 0x1000
/* 88ADD8 80242208 1040000A */  beqz      $v0, .L80242234
/* 88ADDC 8024220C 0000102D */   daddu    $v0, $zero, $zero
/* 88ADE0 80242210 82220004 */  lb        $v0, 4($s1)
/* 88ADE4 80242214 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* 88ADE8 80242218 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* 88ADEC 8024221C 00021080 */  sll       $v0, $v0, 2
/* 88ADF0 80242220 00431021 */  addu      $v0, $v0, $v1
/* 88ADF4 80242224 8C440028 */  lw        $a0, 0x28($v0)
/* 88ADF8 80242228 9623006E */  lhu       $v1, 0x6e($s1)
/* 88ADFC 8024222C 24020002 */  addiu     $v0, $zero, 2
/* 88AE00 80242230 A4830044 */  sh        $v1, 0x44($a0)
.L80242234:
/* 88AE04 80242234 8FBF0018 */  lw        $ra, 0x18($sp)
/* 88AE08 80242238 8FB10014 */  lw        $s1, 0x14($sp)
/* 88AE0C 8024223C 8FB00010 */  lw        $s0, 0x10($sp)
/* 88AE10 80242240 03E00008 */  jr        $ra
/* 88AE14 80242244 27BD0020 */   addiu    $sp, $sp, 0x20
/* 88AE18 80242248 00000000 */  nop       
/* 88AE1C 8024224C 00000000 */  nop       
