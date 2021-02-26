.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002DCC8
/* 90C8 8002DCC8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 90CC 8002DCCC AFB60040 */  sw        $s6, 0x40($sp)
/* 90D0 8002DCD0 27B60010 */  addiu     $s6, $sp, 0x10
/* 90D4 8002DCD4 24030003 */  addiu     $v1, $zero, 3
/* 90D8 8002DCD8 3C02800B */  lui       $v0, %hi(D_800B2D68)
/* 90DC 8002DCDC 24422D68 */  addiu     $v0, $v0, %lo(D_800B2D68)
/* 90E0 8002DCE0 AFBF0044 */  sw        $ra, 0x44($sp)
/* 90E4 8002DCE4 AFB5003C */  sw        $s5, 0x3c($sp)
/* 90E8 8002DCE8 AFB40038 */  sw        $s4, 0x38($sp)
/* 90EC 8002DCEC AFB30034 */  sw        $s3, 0x34($sp)
/* 90F0 8002DCF0 AFB20030 */  sw        $s2, 0x30($sp)
/* 90F4 8002DCF4 AFB1002C */  sw        $s1, 0x2c($sp)
/* 90F8 8002DCF8 AFB00028 */  sw        $s0, 0x28($sp)
.L8002DCFC:
/* 90FC 8002DCFC A4400000 */  sh        $zero, ($v0)
/* 9100 8002DD00 2463FFFF */  addiu     $v1, $v1, -1
/* 9104 8002DD04 0461FFFD */  bgez      $v1, .L8002DCFC
/* 9108 8002DD08 2442FAA8 */   addiu    $v0, $v0, -0x558
/* 910C 8002DD0C 02C0202D */  daddu     $a0, $s6, $zero
/* 9110 8002DD10 24150002 */  addiu     $s5, $zero, 2
/* 9114 8002DD14 241100A0 */  addiu     $s1, $zero, 0xa0
/* 9118 8002DD18 24100078 */  addiu     $s0, $zero, 0x78
/* 911C 8002DD1C 24140008 */  addiu     $s4, $zero, 8
/* 9120 8002DD20 24134000 */  addiu     $s3, $zero, 0x4000
/* 9124 8002DD24 24120032 */  addiu     $s2, $zero, 0x32
/* 9128 8002DD28 A6D50000 */  sh        $s5, ($s6)
/* 912C 8002DD2C A2C00002 */  sb        $zero, 2($s6)
/* 9130 8002DD30 A6D10004 */  sh        $s1, 4($s6)
/* 9134 8002DD34 A6D00006 */  sh        $s0, 6($s6)
/* 9138 8002DD38 A6C00008 */  sh        $zero, 8($s6)
/* 913C 8002DD3C A6C0000A */  sh        $zero, 0xa($s6)
/* 9140 8002DD40 A6D4000C */  sh        $s4, 0xc($s6)
/* 9144 8002DD44 A6D3000E */  sh        $s3, 0xe($s6)
/* 9148 8002DD48 0C00B77F */  jal       func_8002DDFC
/* 914C 8002DD4C A6D20010 */   sh       $s2, 0x10($s6)
/* 9150 8002DD50 02C0202D */  daddu     $a0, $s6, $zero
/* 9154 8002DD54 A6D50000 */  sh        $s5, ($s6)
/* 9158 8002DD58 A2C00002 */  sb        $zero, 2($s6)
/* 915C 8002DD5C A6D10004 */  sh        $s1, 4($s6)
/* 9160 8002DD60 A6D00006 */  sh        $s0, 6($s6)
/* 9164 8002DD64 A6D10008 */  sh        $s1, 8($s6)
/* 9168 8002DD68 A6C0000A */  sh        $zero, 0xa($s6)
/* 916C 8002DD6C A6D4000C */  sh        $s4, 0xc($s6)
/* 9170 8002DD70 A6D3000E */  sh        $s3, 0xe($s6)
/* 9174 8002DD74 0C00B77F */  jal       func_8002DDFC
/* 9178 8002DD78 A6D20010 */   sh       $s2, 0x10($s6)
/* 917C 8002DD7C 02C0202D */  daddu     $a0, $s6, $zero
/* 9180 8002DD80 A6D50000 */  sh        $s5, ($s6)
/* 9184 8002DD84 A2C00002 */  sb        $zero, 2($s6)
/* 9188 8002DD88 A6D10004 */  sh        $s1, 4($s6)
/* 918C 8002DD8C A6D00006 */  sh        $s0, 6($s6)
/* 9190 8002DD90 A6C00008 */  sh        $zero, 8($s6)
/* 9194 8002DD94 A6D0000A */  sh        $s0, 0xa($s6)
/* 9198 8002DD98 A6D4000C */  sh        $s4, 0xc($s6)
/* 919C 8002DD9C A6D3000E */  sh        $s3, 0xe($s6)
/* 91A0 8002DDA0 0C00B77F */  jal       func_8002DDFC
/* 91A4 8002DDA4 A6D20010 */   sh       $s2, 0x10($s6)
/* 91A8 8002DDA8 02C0202D */  daddu     $a0, $s6, $zero
/* 91AC 8002DDAC A4950000 */  sh        $s5, ($a0)
/* 91B0 8002DDB0 A0800002 */  sb        $zero, 2($a0)
/* 91B4 8002DDB4 A4910004 */  sh        $s1, 4($a0)
/* 91B8 8002DDB8 A4900006 */  sh        $s0, 6($a0)
/* 91BC 8002DDBC A4910008 */  sh        $s1, 8($a0)
/* 91C0 8002DDC0 A490000A */  sh        $s0, 0xa($a0)
/* 91C4 8002DDC4 A494000C */  sh        $s4, 0xc($a0)
/* 91C8 8002DDC8 A493000E */  sh        $s3, 0xe($a0)
/* 91CC 8002DDCC 0C00B77F */  jal       func_8002DDFC
/* 91D0 8002DDD0 A4920010 */   sh       $s2, 0x10($a0)
/* 91D4 8002DDD4 8FBF0044 */  lw        $ra, 0x44($sp)
/* 91D8 8002DDD8 8FB60040 */  lw        $s6, 0x40($sp)
/* 91DC 8002DDDC 8FB5003C */  lw        $s5, 0x3c($sp)
/* 91E0 8002DDE0 8FB40038 */  lw        $s4, 0x38($sp)
/* 91E4 8002DDE4 8FB30034 */  lw        $s3, 0x34($sp)
/* 91E8 8002DDE8 8FB20030 */  lw        $s2, 0x30($sp)
/* 91EC 8002DDEC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 91F0 8002DDF0 8FB00028 */  lw        $s0, 0x28($sp)
/* 91F4 8002DDF4 03E00008 */  jr        $ra
/* 91F8 8002DDF8 27BD0048 */   addiu    $sp, $sp, 0x48
