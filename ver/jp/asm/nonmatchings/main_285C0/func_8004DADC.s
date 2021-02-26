.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DADC
/* 28EDC 8004DADC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 28EE0 8004DAE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 28EE4 8004DAE4 0080982D */  daddu     $s3, $a0, $zero
/* 28EE8 8004DAE8 AFB20018 */  sw        $s2, 0x18($sp)
/* 28EEC 8004DAEC AFBF0024 */  sw        $ra, 0x24($sp)
/* 28EF0 8004DAF0 AFB40020 */  sw        $s4, 0x20($sp)
/* 28EF4 8004DAF4 AFB10014 */  sw        $s1, 0x14($sp)
/* 28EF8 8004DAF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 28EFC 8004DAFC 8E740000 */  lw        $s4, ($s3)
/* 28F00 8004DB00 8E700010 */  lw        $s0, 0x10($s3)
/* 28F04 8004DB04 12800055 */  beqz      $s4, .L8004DC5C
/* 28F08 8004DB08 0000902D */   daddu    $s2, $zero, $zero
/* 28F0C 8004DB0C 8E620014 */  lw        $v0, 0x14($s3)
/* 28F10 8004DB10 14400045 */  bnez      $v0, .L8004DC28
/* 28F14 8004DB14 00000000 */   nop
/* 28F18 8004DB18 0C014F05 */  jal       func_80053C14
/* 28F1C 8004DB1C 0200202D */   daddu    $a0, $s0, $zero
/* 28F20 8004DB20 0040882D */  daddu     $s1, $v0, $zero
/* 28F24 8004DB24 1220003E */  beqz      $s1, .L8004DC20
/* 28F28 8004DB28 001010C0 */   sll      $v0, $s0, 3
/* 28F2C 8004DB2C 8E230000 */  lw        $v1, ($s1)
/* 28F30 8004DB30 00622021 */  addu      $a0, $v1, $v0
/* 28F34 8004DB34 90830070 */  lbu       $v1, 0x70($a0)
/* 28F38 8004DB38 24020001 */  addiu     $v0, $zero, 1
/* 28F3C 8004DB3C 54620048 */  bnel      $v1, $v0, .L8004DC60
/* 28F40 8004DB40 24120004 */   addiu    $s2, $zero, 4
/* 28F44 8004DB44 90840071 */  lbu       $a0, 0x71($a0)
/* 28F48 8004DB48 0C014FBE */  jal       func_80053EF8
/* 28F4C 8004DB4C 00000000 */   nop
/* 28F50 8004DB50 0040802D */  daddu     $s0, $v0, $zero
/* 28F54 8004DB54 52000042 */  beql      $s0, $zero, .L8004DC60
/* 28F58 8004DB58 24120006 */   addiu    $s2, $zero, 6
/* 28F5C 8004DB5C 0C0135F6 */  jal       func_8004D7D8
/* 28F60 8004DB60 0200202D */   daddu    $a0, $s0, $zero
/* 28F64 8004DB64 1440003E */  bnez      $v0, .L8004DC60
/* 28F68 8004DB68 24120007 */   addiu    $s2, $zero, 7
/* 28F6C 8004DB6C 8E240028 */  lw        $a0, 0x28($s1)
/* 28F70 8004DB70 0C014EC2 */  jal       func_80053B08
/* 28F74 8004DB74 8E250064 */   lw       $a1, 0x64($s1)
/* 28F78 8004DB78 8E650004 */  lw        $a1, 4($s3)
/* 28F7C 8004DB7C 10A00008 */  beqz      $a1, .L8004DBA0
/* 28F80 8004DB80 0040902D */   daddu    $s2, $v0, $zero
/* 28F84 8004DB84 28A22711 */  slti      $v0, $a1, 0x2711
/* 28F88 8004DB88 14400003 */  bnez      $v0, .L8004DB98
/* 28F8C 8004DB8C 28A200FA */   slti     $v0, $a1, 0xfa
/* 28F90 8004DB90 080136E8 */  j         .L8004DBA0
/* 28F94 8004DB94 24052710 */   addiu    $a1, $zero, 0x2710
.L8004DB98:
/* 28F98 8004DB98 54400001 */  bnel      $v0, $zero, .L8004DBA0
/* 28F9C 8004DB9C 240500FA */   addiu    $a1, $zero, 0xfa
.L8004DBA0:
/* 28FA0 8004DBA0 8E630008 */  lw        $v1, 8($s3)
/* 28FA4 8004DBA4 28620080 */  slti      $v0, $v1, 0x80
/* 28FA8 8004DBA8 50400001 */  beql      $v0, $zero, .L8004DBB0
/* 28FAC 8004DBAC 2403007F */   addiu    $v1, $zero, 0x7f
.L8004DBB0:
/* 28FB0 8004DBB0 10600002 */  beqz      $v1, .L8004DBBC
/* 28FB4 8004DBB4 00031200 */   sll      $v0, $v1, 8
/* 28FB8 8004DBB8 344300FF */  ori       $v1, $v0, 0xff
.L8004DBBC:
/* 28FBC 8004DBBC 8E64000C */  lw        $a0, 0xc($s3)
/* 28FC0 8004DBC0 28820080 */  slti      $v0, $a0, 0x80
/* 28FC4 8004DBC4 50400001 */  beql      $v0, $zero, .L8004DBCC
/* 28FC8 8004DBC8 2404007F */   addiu    $a0, $zero, 0x7f
.L8004DBCC:
/* 28FCC 8004DBCC 10800003 */  beqz      $a0, .L8004DBDC
/* 28FD0 8004DBD0 00041200 */   sll      $v0, $a0, 8
/* 28FD4 8004DBD4 080136F8 */  j         .L8004DBE0
/* 28FD8 8004DBD8 344400FF */   ori      $a0, $v0, 0xff
.L8004DBDC:
/* 28FDC 8004DBDC 24047FFF */  addiu     $a0, $zero, 0x7fff
.L8004DBE0:
/* 28FE0 8004DBE0 8E020000 */  lw        $v0, ($s0)
/* 28FE4 8004DBE4 AC500074 */  sw        $s0, 0x74($v0)
/* 28FE8 8004DBE8 8E020000 */  lw        $v0, ($s0)
/* 28FEC 8004DBEC AC510078 */  sw        $s1, 0x78($v0)
/* 28FF0 8004DBF0 8E020000 */  lw        $v0, ($s0)
/* 28FF4 8004DBF4 AC54007C */  sw        $s4, 0x7c($v0)
/* 28FF8 8004DBF8 8E020000 */  lw        $v0, ($s0)
/* 28FFC 8004DBFC AC450084 */  sw        $a1, 0x84($v0)
/* 29000 8004DC00 8E020000 */  lw        $v0, ($s0)
/* 29004 8004DC04 AC430088 */  sw        $v1, 0x88($v0)
/* 29008 8004DC08 8E020000 */  lw        $v0, ($s0)
/* 2900C 8004DC0C AC44008C */  sw        $a0, 0x8c($v0)
/* 29010 8004DC10 8E030000 */  lw        $v1, ($s0)
/* 29014 8004DC14 24020001 */  addiu     $v0, $zero, 1
/* 29018 8004DC18 08013718 */  j         .L8004DC60
/* 2901C 8004DC1C AC620080 */   sw       $v0, 0x80($v1)
.L8004DC20:
/* 29020 8004DC20 08013718 */  j         .L8004DC60
/* 29024 8004DC24 24120004 */   addiu    $s2, $zero, 4
.L8004DC28:
/* 29028 8004DC28 0C013511 */  jal       func_8004D444
/* 2902C 8004DC2C 0280202D */   daddu    $a0, $s4, $zero
/* 29030 8004DC30 0040802D */  daddu     $s0, $v0, $zero
/* 29034 8004DC34 1200000B */  beqz      $s0, .L8004DC64
/* 29038 8004DC38 0240102D */   daddu    $v0, $s2, $zero
/* 2903C 8004DC3C 8E02001C */  lw        $v0, 0x1c($s0)
/* 29040 8004DC40 16820008 */  bne       $s4, $v0, .L8004DC64
/* 29044 8004DC44 0240102D */   daddu    $v0, $s2, $zero
/* 29048 8004DC48 92020220 */  lbu       $v0, 0x220($s0)
/* 2904C 8004DC4C 54400004 */  bnel      $v0, $zero, .L8004DC60
/* 29050 8004DC50 A2000220 */   sb       $zero, 0x220($s0)
/* 29054 8004DC54 08013719 */  j         .L8004DC64
/* 29058 8004DC58 0240102D */   daddu    $v0, $s2, $zero
.L8004DC5C:
/* 2905C 8004DC5C 24120003 */  addiu     $s2, $zero, 3
.L8004DC60:
/* 29060 8004DC60 0240102D */  daddu     $v0, $s2, $zero
.L8004DC64:
/* 29064 8004DC64 8FBF0024 */  lw        $ra, 0x24($sp)
/* 29068 8004DC68 8FB40020 */  lw        $s4, 0x20($sp)
/* 2906C 8004DC6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 29070 8004DC70 8FB20018 */  lw        $s2, 0x18($sp)
/* 29074 8004DC74 8FB10014 */  lw        $s1, 0x14($sp)
/* 29078 8004DC78 8FB00010 */  lw        $s0, 0x10($sp)
/* 2907C 8004DC7C 03E00008 */  jr        $ra
/* 29080 8004DC80 27BD0028 */   addiu    $sp, $sp, 0x28
