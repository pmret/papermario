.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002DB84
/* 8F84 8002DB84 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8F88 8002DB88 AFB60040 */  sw        $s6, 0x40($sp)
/* 8F8C 8002DB8C 27B60010 */  addiu     $s6, $sp, 0x10
/* 8F90 8002DB90 24030003 */  addiu     $v1, $zero, 3
/* 8F94 8002DB94 3C013F80 */  lui       $at, 0x3f80
/* 8F98 8002DB98 44810000 */  mtc1      $at, $f0
/* 8F9C 8002DB9C 3C02800B */  lui       $v0, %hi(D_800B2D68)
/* 8FA0 8002DBA0 24422D68 */  addiu     $v0, $v0, %lo(D_800B2D68)
/* 8FA4 8002DBA4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 8FA8 8002DBA8 AFB5003C */  sw        $s5, 0x3c($sp)
/* 8FAC 8002DBAC AFB40038 */  sw        $s4, 0x38($sp)
/* 8FB0 8002DBB0 AFB30034 */  sw        $s3, 0x34($sp)
/* 8FB4 8002DBB4 AFB20030 */  sw        $s2, 0x30($sp)
/* 8FB8 8002DBB8 AFB1002C */  sw        $s1, 0x2c($sp)
/* 8FBC 8002DBBC AFB00028 */  sw        $s0, 0x28($sp)
/* 8FC0 8002DBC0 3C01800A */  lui       $at, %hi(D_8009A5CC)
/* 8FC4 8002DBC4 E420A5CC */  swc1      $f0, %lo(D_8009A5CC)($at)
.L8002DBC8:
/* 8FC8 8002DBC8 A4400000 */  sh        $zero, ($v0)
/* 8FCC 8002DBCC 2463FFFF */  addiu     $v1, $v1, -1
/* 8FD0 8002DBD0 0461FFFD */  bgez      $v1, .L8002DBC8
/* 8FD4 8002DBD4 2442FAA8 */   addiu    $v0, $v0, -0x558
/* 8FD8 8002DBD8 02C0202D */  daddu     $a0, $s6, $zero
/* 8FDC 8002DBDC 24150002 */  addiu     $s5, $zero, 2
/* 8FE0 8002DBE0 241100A0 */  addiu     $s1, $zero, 0xa0
/* 8FE4 8002DBE4 24100078 */  addiu     $s0, $zero, 0x78
/* 8FE8 8002DBE8 24140008 */  addiu     $s4, $zero, 8
/* 8FEC 8002DBEC 24134000 */  addiu     $s3, $zero, 0x4000
/* 8FF0 8002DBF0 24120032 */  addiu     $s2, $zero, 0x32
/* 8FF4 8002DBF4 A6D50000 */  sh        $s5, ($s6)
/* 8FF8 8002DBF8 A2C00002 */  sb        $zero, 2($s6)
/* 8FFC 8002DBFC A6D10004 */  sh        $s1, 4($s6)
/* 9000 8002DC00 A6D00006 */  sh        $s0, 6($s6)
/* 9004 8002DC04 A6C00008 */  sh        $zero, 8($s6)
/* 9008 8002DC08 A6C0000A */  sh        $zero, 0xa($s6)
/* 900C 8002DC0C A6D4000C */  sh        $s4, 0xc($s6)
/* 9010 8002DC10 A6D3000E */  sh        $s3, 0xe($s6)
/* 9014 8002DC14 0C00B77F */  jal       func_8002DDFC
/* 9018 8002DC18 A6D20010 */   sh       $s2, 0x10($s6)
/* 901C 8002DC1C 02C0202D */  daddu     $a0, $s6, $zero
/* 9020 8002DC20 A6D50000 */  sh        $s5, ($s6)
/* 9024 8002DC24 A2C00002 */  sb        $zero, 2($s6)
/* 9028 8002DC28 A6D10004 */  sh        $s1, 4($s6)
/* 902C 8002DC2C A6D00006 */  sh        $s0, 6($s6)
/* 9030 8002DC30 A6D10008 */  sh        $s1, 8($s6)
/* 9034 8002DC34 A6C0000A */  sh        $zero, 0xa($s6)
/* 9038 8002DC38 A6D4000C */  sh        $s4, 0xc($s6)
/* 903C 8002DC3C A6D3000E */  sh        $s3, 0xe($s6)
/* 9040 8002DC40 0C00B77F */  jal       func_8002DDFC
/* 9044 8002DC44 A6D20010 */   sh       $s2, 0x10($s6)
/* 9048 8002DC48 02C0202D */  daddu     $a0, $s6, $zero
/* 904C 8002DC4C A6D50000 */  sh        $s5, ($s6)
/* 9050 8002DC50 A2C00002 */  sb        $zero, 2($s6)
/* 9054 8002DC54 A6D10004 */  sh        $s1, 4($s6)
/* 9058 8002DC58 A6D00006 */  sh        $s0, 6($s6)
/* 905C 8002DC5C A6C00008 */  sh        $zero, 8($s6)
/* 9060 8002DC60 A6D0000A */  sh        $s0, 0xa($s6)
/* 9064 8002DC64 A6D4000C */  sh        $s4, 0xc($s6)
/* 9068 8002DC68 A6D3000E */  sh        $s3, 0xe($s6)
/* 906C 8002DC6C 0C00B77F */  jal       func_8002DDFC
/* 9070 8002DC70 A6D20010 */   sh       $s2, 0x10($s6)
/* 9074 8002DC74 02C0202D */  daddu     $a0, $s6, $zero
/* 9078 8002DC78 A4950000 */  sh        $s5, ($a0)
/* 907C 8002DC7C A0800002 */  sb        $zero, 2($a0)
/* 9080 8002DC80 A4910004 */  sh        $s1, 4($a0)
/* 9084 8002DC84 A4900006 */  sh        $s0, 6($a0)
/* 9088 8002DC88 A4910008 */  sh        $s1, 8($a0)
/* 908C 8002DC8C A490000A */  sh        $s0, 0xa($a0)
/* 9090 8002DC90 A494000C */  sh        $s4, 0xc($a0)
/* 9094 8002DC94 A493000E */  sh        $s3, 0xe($a0)
/* 9098 8002DC98 0C00B77F */  jal       func_8002DDFC
/* 909C 8002DC9C A4920010 */   sh       $s2, 0x10($a0)
/* 90A0 8002DCA0 8FBF0044 */  lw        $ra, 0x44($sp)
/* 90A4 8002DCA4 8FB60040 */  lw        $s6, 0x40($sp)
/* 90A8 8002DCA8 8FB5003C */  lw        $s5, 0x3c($sp)
/* 90AC 8002DCAC 8FB40038 */  lw        $s4, 0x38($sp)
/* 90B0 8002DCB0 8FB30034 */  lw        $s3, 0x34($sp)
/* 90B4 8002DCB4 8FB20030 */  lw        $s2, 0x30($sp)
/* 90B8 8002DCB8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 90BC 8002DCBC 8FB00028 */  lw        $s0, 0x28($sp)
/* 90C0 8002DCC0 03E00008 */  jr        $ra
/* 90C4 8002DCC4 27BD0048 */   addiu    $sp, $sp, 0x48
