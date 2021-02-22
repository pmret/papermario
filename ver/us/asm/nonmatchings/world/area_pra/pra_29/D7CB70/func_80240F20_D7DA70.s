.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D7DA70
/* D7DA70 80240F20 8FAC0010 */  lw        $t4, 0x10($sp)
/* D7DA74 80240F24 240300FF */  addiu     $v1, $zero, 0xff
/* D7DA78 80240F28 0180502D */  daddu     $t2, $t4, $zero
/* D7DA7C 80240F2C 29420100 */  slti      $v0, $t2, 0x100
/* D7DA80 80240F30 14400002 */  bnez      $v0, .L80240F3C
/* D7DA84 80240F34 006C5823 */   subu     $t3, $v1, $t4
/* D7DA88 80240F38 0060502D */  daddu     $t2, $v1, $zero
.L80240F3C:
/* D7DA8C 80240F3C 0000482D */  daddu     $t1, $zero, $zero
/* D7DA90 80240F40 18E00059 */  blez      $a3, .L802410A8
/* D7DA94 80240F44 006A6823 */   subu     $t5, $v1, $t2
/* D7DA98 80240F48 3C088080 */  lui       $t0, 0x8080
/* D7DA9C 80240F4C 35088081 */  ori       $t0, $t0, 0x8081
.L80240F50:
/* D7DAA0 80240F50 84820000 */  lh        $v0, ($a0)
/* D7DAA4 80240F54 004B0018 */  mult      $v0, $t3
/* D7DAA8 80240F58 00001812 */  mflo      $v1
/* D7DAAC 80240F5C 84A20000 */  lh        $v0, ($a1)
/* D7DAB0 80240F60 00000000 */  nop
/* D7DAB4 80240F64 004C0018 */  mult      $v0, $t4
/* D7DAB8 80240F68 00001012 */  mflo      $v0
/* D7DABC 80240F6C 00621821 */  addu      $v1, $v1, $v0
/* D7DAC0 80240F70 00000000 */  nop
/* D7DAC4 80240F74 00680018 */  mult      $v1, $t0
/* D7DAC8 80240F78 00001010 */  mfhi      $v0
/* D7DACC 80240F7C 00431021 */  addu      $v0, $v0, $v1
/* D7DAD0 80240F80 000211C3 */  sra       $v0, $v0, 7
/* D7DAD4 80240F84 00031FC3 */  sra       $v1, $v1, 0x1f
/* D7DAD8 80240F88 00431023 */  subu      $v0, $v0, $v1
/* D7DADC 80240F8C A4C20000 */  sh        $v0, ($a2)
/* D7DAE0 80240F90 84820002 */  lh        $v0, 2($a0)
/* D7DAE4 80240F94 004B0018 */  mult      $v0, $t3
/* D7DAE8 80240F98 00001812 */  mflo      $v1
/* D7DAEC 80240F9C 84A20002 */  lh        $v0, 2($a1)
/* D7DAF0 80240FA0 00000000 */  nop
/* D7DAF4 80240FA4 004C0018 */  mult      $v0, $t4
/* D7DAF8 80240FA8 00001012 */  mflo      $v0
/* D7DAFC 80240FAC 00621821 */  addu      $v1, $v1, $v0
/* D7DB00 80240FB0 00000000 */  nop
/* D7DB04 80240FB4 00680018 */  mult      $v1, $t0
/* D7DB08 80240FB8 00001010 */  mfhi      $v0
/* D7DB0C 80240FBC 00431021 */  addu      $v0, $v0, $v1
/* D7DB10 80240FC0 000211C3 */  sra       $v0, $v0, 7
/* D7DB14 80240FC4 00031FC3 */  sra       $v1, $v1, 0x1f
/* D7DB18 80240FC8 00431023 */  subu      $v0, $v0, $v1
/* D7DB1C 80240FCC A4C20002 */  sh        $v0, 2($a2)
/* D7DB20 80240FD0 84820004 */  lh        $v0, 4($a0)
/* D7DB24 80240FD4 004B0018 */  mult      $v0, $t3
/* D7DB28 80240FD8 00001812 */  mflo      $v1
/* D7DB2C 80240FDC 84A20004 */  lh        $v0, 4($a1)
/* D7DB30 80240FE0 00000000 */  nop
/* D7DB34 80240FE4 004C0018 */  mult      $v0, $t4
/* D7DB38 80240FE8 00001012 */  mflo      $v0
/* D7DB3C 80240FEC 00621821 */  addu      $v1, $v1, $v0
/* D7DB40 80240FF0 00000000 */  nop
/* D7DB44 80240FF4 00680018 */  mult      $v1, $t0
/* D7DB48 80240FF8 00001010 */  mfhi      $v0
/* D7DB4C 80240FFC 00431021 */  addu      $v0, $v0, $v1
/* D7DB50 80241000 000211C3 */  sra       $v0, $v0, 7
/* D7DB54 80241004 00031FC3 */  sra       $v1, $v1, 0x1f
/* D7DB58 80241008 00431023 */  subu      $v0, $v0, $v1
/* D7DB5C 8024100C A4C20004 */  sh        $v0, 4($a2)
/* D7DB60 80241010 84820008 */  lh        $v0, 8($a0)
/* D7DB64 80241014 004D0018 */  mult      $v0, $t5
/* D7DB68 80241018 00001812 */  mflo      $v1
/* D7DB6C 8024101C 84A20008 */  lh        $v0, 8($a1)
/* D7DB70 80241020 00000000 */  nop
/* D7DB74 80241024 004A0018 */  mult      $v0, $t2
/* D7DB78 80241028 00001012 */  mflo      $v0
/* D7DB7C 8024102C 00621821 */  addu      $v1, $v1, $v0
/* D7DB80 80241030 00000000 */  nop
/* D7DB84 80241034 00680018 */  mult      $v1, $t0
/* D7DB88 80241038 00001010 */  mfhi      $v0
/* D7DB8C 8024103C 00431021 */  addu      $v0, $v0, $v1
/* D7DB90 80241040 000211C3 */  sra       $v0, $v0, 7
/* D7DB94 80241044 00031FC3 */  sra       $v1, $v1, 0x1f
/* D7DB98 80241048 00431023 */  subu      $v0, $v0, $v1
/* D7DB9C 8024104C A4C20008 */  sh        $v0, 8($a2)
/* D7DBA0 80241050 8482000A */  lh        $v0, 0xa($a0)
/* D7DBA4 80241054 004D0018 */  mult      $v0, $t5
/* D7DBA8 80241058 00001812 */  mflo      $v1
/* D7DBAC 8024105C 84A2000A */  lh        $v0, 0xa($a1)
/* D7DBB0 80241060 00000000 */  nop
/* D7DBB4 80241064 004A0018 */  mult      $v0, $t2
/* D7DBB8 80241068 00001012 */  mflo      $v0
/* D7DBBC 8024106C 00621821 */  addu      $v1, $v1, $v0
/* D7DBC0 80241070 00000000 */  nop
/* D7DBC4 80241074 00680018 */  mult      $v1, $t0
/* D7DBC8 80241078 25290001 */  addiu     $t1, $t1, 1
/* D7DBCC 8024107C 24840010 */  addiu     $a0, $a0, 0x10
/* D7DBD0 80241080 24A50010 */  addiu     $a1, $a1, 0x10
/* D7DBD4 80241084 00001010 */  mfhi      $v0
/* D7DBD8 80241088 00431021 */  addu      $v0, $v0, $v1
/* D7DBDC 8024108C 000211C3 */  sra       $v0, $v0, 7
/* D7DBE0 80241090 00031FC3 */  sra       $v1, $v1, 0x1f
/* D7DBE4 80241094 00431023 */  subu      $v0, $v0, $v1
/* D7DBE8 80241098 A4C2000A */  sh        $v0, 0xa($a2)
/* D7DBEC 8024109C 0127102A */  slt       $v0, $t1, $a3
/* D7DBF0 802410A0 1440FFAB */  bnez      $v0, .L80240F50
/* D7DBF4 802410A4 24C60010 */   addiu    $a2, $a2, 0x10
.L802410A8:
/* D7DBF8 802410A8 03E00008 */  jr        $ra
/* D7DBFC 802410AC 00000000 */   nop
