.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DB4C
/* 28F4C 8004DB4C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 28F50 8004DB50 AFB3001C */  sw        $s3, 0x1c($sp)
/* 28F54 8004DB54 0080982D */  daddu     $s3, $a0, $zero
/* 28F58 8004DB58 AFB20018 */  sw        $s2, 0x18($sp)
/* 28F5C 8004DB5C AFBF0024 */  sw        $ra, 0x24($sp)
/* 28F60 8004DB60 AFB40020 */  sw        $s4, 0x20($sp)
/* 28F64 8004DB64 AFB10014 */  sw        $s1, 0x14($sp)
/* 28F68 8004DB68 AFB00010 */  sw        $s0, 0x10($sp)
/* 28F6C 8004DB6C 8E700000 */  lw        $s0, ($s3)
/* 28F70 8004DB70 8E710004 */  lw        $s1, 4($s3)
/* 28F74 8004DB74 9674000E */  lhu       $s4, 0xe($s3)
/* 28F78 8004DB78 12000037 */  beqz      $s0, .L8004DC58
/* 28F7C 8004DB7C 0000902D */   daddu    $s2, $zero, $zero
/* 28F80 8004DB80 2622FF06 */  addiu     $v0, $s1, -0xfa
/* 28F84 8004DB84 2C422617 */  sltiu     $v0, $v0, 0x2617
/* 28F88 8004DB88 50400034 */  beql      $v0, $zero, .L8004DC5C
/* 28F8C 8004DB8C 24120004 */   addiu    $s2, $zero, 4
/* 28F90 8004DB90 0C0135E5 */  jal       snd_get_player_with_song_name
/* 28F94 8004DB94 0200202D */   daddu    $a0, $s0, $zero
/* 28F98 8004DB98 0040282D */  daddu     $a1, $v0, $zero
/* 28F9C 8004DB9C 50A0002F */  beql      $a1, $zero, .L8004DC5C
/* 28FA0 8004DBA0 24120002 */   addiu    $s2, $zero, 2
/* 28FA4 8004DBA4 8CA6001C */  lw        $a2, 0x1c($a1)
/* 28FA8 8004DBA8 14D0002D */  bne       $a2, $s0, .L8004DC60
/* 28FAC 8004DBAC 0240102D */   daddu    $v0, $s2, $zero
/* 28FB0 8004DBB0 90A20221 */  lbu       $v0, 0x221($a1)
/* 28FB4 8004DBB4 1040002A */  beqz      $v0, .L8004DC60
/* 28FB8 8004DBB8 0240102D */   daddu    $v0, $s2, $zero
/* 28FBC 8004DBBC 90A20220 */  lbu       $v0, 0x220($a1)
/* 28FC0 8004DBC0 14400027 */  bnez      $v0, .L8004DC60
/* 28FC4 8004DBC4 0240102D */   daddu    $v0, $s2, $zero
/* 28FC8 8004DBC8 00111140 */  sll       $v0, $s1, 5
/* 28FCC 8004DBCC 00511023 */  subu      $v0, $v0, $s1
/* 28FD0 8004DBD0 00021080 */  sll       $v0, $v0, 2
/* 28FD4 8004DBD4 00511021 */  addu      $v0, $v0, $s1
/* 28FD8 8004DBD8 000210C0 */  sll       $v0, $v0, 3
/* 28FDC 8004DBDC 3C03B65C */  lui       $v1, 0xb65c
/* 28FE0 8004DBE0 34636D59 */  ori       $v1, $v1, 0x6d59
/* 28FE4 8004DBE4 00430019 */  multu     $v0, $v1
/* 28FE8 8004DBE8 8CA2002C */  lw        $v0, 0x2c($a1)
/* 28FEC 8004DBEC 00001810 */  mfhi      $v1
/* 28FF0 8004DBF0 00032302 */  srl       $a0, $v1, 0xc
/* 28FF4 8004DBF4 00141C00 */  sll       $v1, $s4, 0x10
/* 28FF8 8004DBF8 00621823 */  subu      $v1, $v1, $v0
/* 28FFC 8004DBFC 00041400 */  sll       $v0, $a0, 0x10
/* 29000 8004DC00 00021403 */  sra       $v0, $v0, 0x10
/* 29004 8004DC04 14400002 */  bnez      $v0, .L8004DC10
/* 29008 8004DC08 0062001A */   div      $zero, $v1, $v0
/* 2900C 8004DC0C 0007000D */  break     7
.L8004DC10:
/* 29010 8004DC10 2401FFFF */   addiu    $at, $zero, -1
/* 29014 8004DC14 14410004 */  bne       $v0, $at, .L8004DC28
/* 29018 8004DC18 3C018000 */   lui      $at, 0x8000
/* 2901C 8004DC1C 14610002 */  bne       $v1, $at, .L8004DC28
/* 29020 8004DC20 00000000 */   nop
/* 29024 8004DC24 0006000D */  break     6
.L8004DC28:
/* 29028 8004DC28 00001812 */   mflo     $v1
/* 2902C 8004DC2C A4B40034 */  sh        $s4, 0x34($a1)
/* 29030 8004DC30 A4A40036 */  sh        $a0, 0x36($a1)
/* 29034 8004DC34 ACA30030 */  sw        $v1, 0x30($a1)
/* 29038 8004DC38 8E620010 */  lw        $v0, 0x10($s3)
/* 2903C 8004DC3C ACA20038 */  sw        $v0, 0x38($a1)
/* 29040 8004DC40 8E630014 */  lw        $v1, 0x14($s3)
/* 29044 8004DC44 24020001 */  addiu     $v0, $zero, 1
/* 29048 8004DC48 50620004 */  beql      $v1, $v0, .L8004DC5C
/* 2904C 8004DC4C ACA60020 */   sw       $a2, 0x20($a1)
/* 29050 8004DC50 08013718 */  j         .L8004DC60
/* 29054 8004DC54 0240102D */   daddu    $v0, $s2, $zero
.L8004DC58:
/* 29058 8004DC58 24120003 */  addiu     $s2, $zero, 3
.L8004DC5C:
/* 2905C 8004DC5C 0240102D */  daddu     $v0, $s2, $zero
.L8004DC60:
/* 29060 8004DC60 8FBF0024 */  lw        $ra, 0x24($sp)
/* 29064 8004DC64 8FB40020 */  lw        $s4, 0x20($sp)
/* 29068 8004DC68 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2906C 8004DC6C 8FB20018 */  lw        $s2, 0x18($sp)
/* 29070 8004DC70 8FB10014 */  lw        $s1, 0x14($sp)
/* 29074 8004DC74 8FB00010 */  lw        $s0, 0x10($sp)
/* 29078 8004DC78 03E00008 */  jr        $ra
/* 2907C 8004DC7C 27BD0028 */   addiu    $sp, $sp, 0x28
