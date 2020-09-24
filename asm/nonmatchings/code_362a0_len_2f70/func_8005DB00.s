.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DB00
/* 38F00 8005DB00 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 38F04 8005DB04 AFB20018 */  sw        $s2, 0x18($sp)
/* 38F08 8005DB08 0080902D */  daddu     $s2, $a0, $zero
/* 38F0C 8005DB0C AFBF0020 */  sw        $ra, 0x20($sp)
/* 38F10 8005DB10 AFB3001C */  sw        $s3, 0x1c($sp)
/* 38F14 8005DB14 AFB10014 */  sw        $s1, 0x14($sp)
/* 38F18 8005DB18 AFB00010 */  sw        $s0, 0x10($sp)
/* 38F1C 8005DB1C 8E420148 */  lw        $v0, 0x148($s2)
/* 38F20 8005DB20 84440008 */  lh        $a0, 8($v0)
/* 38F24 8005DB24 0C00EABB */  jal       get_npc_unsafe
/* 38F28 8005DB28 00A0802D */   daddu    $s0, $a1, $zero
/* 38F2C 8005DB2C 3C138011 */  lui       $s3, 0x8011
/* 38F30 8005DB30 2673EFC8 */  addiu     $s3, $s3, -0x1038
/* 38F34 8005DB34 12000002 */  beqz      $s0, .L8005DB40
/* 38F38 8005DB38 0040882D */   daddu    $s1, $v0, $zero
/* 38F3C 8005DB3C AE400070 */  sw        $zero, 0x70($s2)
.L8005DB40:
/* 38F40 8005DB40 8E440070 */  lw        $a0, 0x70($s2)
/* 38F44 8005DB44 10800005 */  beqz      $a0, .L8005DB5C
/* 38F48 8005DB48 24020001 */   addiu    $v0, $zero, 1
/* 38F4C 8005DB4C 1082001F */  beq       $a0, $v0, .L8005DBCC
/* 38F50 8005DB50 0000102D */   daddu    $v0, $zero, $zero
/* 38F54 8005DB54 0801774E */  j         .L8005DD38
/* 38F58 8005DB58 00000000 */   nop      
.L8005DB5C:
/* 38F5C 8005DB5C 0240202D */  daddu     $a0, $s2, $zero
/* 38F60 8005DB60 3C05FE36 */  lui       $a1, 0xfe36
/* 38F64 8005DB64 0C0B210B */  jal       get_float_variable
/* 38F68 8005DB68 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 38F6C 8005DB6C 0240202D */  daddu     $a0, $s2, $zero
/* 38F70 8005DB70 3C05FE36 */  lui       $a1, 0xfe36
/* 38F74 8005DB74 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 38F78 8005DB78 0C0B1EAF */  jal       get_variable
/* 38F7C 8005DB7C E6200010 */   swc1     $f0, 0x10($s1)
/* 38F80 8005DB80 0240202D */  daddu     $a0, $s2, $zero
/* 38F84 8005DB84 3C05FE36 */  lui       $a1, 0xfe36
/* 38F88 8005DB88 34A53C82 */  ori       $a1, $a1, 0x3c82
/* 38F8C 8005DB8C 0C0B1EAF */  jal       get_variable
/* 38F90 8005DB90 A622008E */   sh       $v0, 0x8e($s1)
/* 38F94 8005DB94 0240202D */  daddu     $a0, $s2, $zero
/* 38F98 8005DB98 3C05FE36 */  lui       $a1, 0xfe36
/* 38F9C 8005DB9C 34A53C83 */  ori       $a1, $a1, 0x3c83
/* 38FA0 8005DBA0 0C0B1EAF */  jal       get_variable
/* 38FA4 8005DBA4 AE420074 */   sw       $v0, 0x74($s2)
/* 38FA8 8005DBA8 00021FC2 */  srl       $v1, $v0, 0x1f
/* 38FAC 8005DBAC 00621821 */  addu      $v1, $v1, $v0
/* 38FB0 8005DBB0 8E4200AC */  lw        $v0, 0xac($s2)
/* 38FB4 8005DBB4 00031843 */  sra       $v1, $v1, 1
/* 38FB8 8005DBB8 AE430078 */  sw        $v1, 0x78($s2)
/* 38FBC 8005DBBC AE220028 */  sw        $v0, 0x28($s1)
/* 38FC0 8005DBC0 24020001 */  addiu     $v0, $zero, 1
/* 38FC4 8005DBC4 0801774D */  j         .L8005DD34
/* 38FC8 8005DBC8 AE420070 */   sw       $v0, 0x70($s2)
.L8005DBCC:
/* 38FCC 8005DBCC 3C028011 */  lui       $v0, 0x8011
/* 38FD0 8005DBD0 2442EBB0 */  addiu     $v0, $v0, -0x1450
/* 38FD4 8005DBD4 80430003 */  lb        $v1, 3($v0)
/* 38FD8 8005DBD8 24020009 */  addiu     $v0, $zero, 9
/* 38FDC 8005DBDC 10620056 */  beq       $v1, $v0, .L8005DD38
/* 38FE0 8005DBE0 0000102D */   daddu    $v0, $zero, $zero
/* 38FE4 8005DBE4 8622008E */  lh        $v0, 0x8e($s1)
/* 38FE8 8005DBE8 10400005 */  beqz      $v0, .L8005DC00
/* 38FEC 8005DBEC 00000000 */   nop      
/* 38FF0 8005DBF0 1044002C */  beq       $v0, $a0, .L8005DCA4
/* 38FF4 8005DBF4 0000102D */   daddu    $v0, $zero, $zero
/* 38FF8 8005DBF8 0801774E */  j         .L8005DD38
/* 38FFC 8005DBFC 00000000 */   nop      
.L8005DC00:
/* 39000 8005DC00 C6620028 */  lwc1      $f2, 0x28($s3)
/* 39004 8005DC04 C6200038 */  lwc1      $f0, 0x38($s1)
/* 39008 8005DC08 46001081 */  sub.s     $f2, $f2, $f0
/* 3900C 8005DC0C 46021082 */  mul.s     $f2, $f2, $f2
/* 39010 8005DC10 00000000 */  nop       
/* 39014 8005DC14 C666002C */  lwc1      $f6, 0x2c($s3)
/* 39018 8005DC18 C620003C */  lwc1      $f0, 0x3c($s1)
/* 3901C 8005DC1C 46003181 */  sub.s     $f6, $f6, $f0
/* 39020 8005DC20 46063182 */  mul.s     $f6, $f6, $f6
/* 39024 8005DC24 00000000 */  nop       
/* 39028 8005DC28 C6240040 */  lwc1      $f4, 0x40($s1)
/* 3902C 8005DC2C C6600030 */  lwc1      $f0, 0x30($s3)
/* 39030 8005DC30 46040001 */  sub.s     $f0, $f0, $f4
/* 39034 8005DC34 46000002 */  mul.s     $f0, $f0, $f0
/* 39038 8005DC38 00000000 */  nop       
/* 3903C 8005DC3C 46061080 */  add.s     $f2, $f2, $f6
/* 39040 8005DC40 46001300 */  add.s     $f12, $f2, $f0
/* 39044 8005DC44 46006104 */  sqrt.s    $f4, $f12
/* 39048 8005DC48 46042032 */  c.eq.s    $f4, $f4
/* 3904C 8005DC4C 00000000 */  nop       
/* 39050 8005DC50 45010004 */  bc1t      .L8005DC64
/* 39054 8005DC54 00000000 */   nop      
/* 39058 8005DC58 0C0187BC */  jal       sqrtf
/* 3905C 8005DC5C 00000000 */   nop      
/* 39060 8005DC60 46000106 */  mov.s     $f4, $f0
.L8005DC64:
/* 39064 8005DC64 C6200010 */  lwc1      $f0, 0x10($s1)
/* 39068 8005DC68 4600203E */  c.le.s    $f4, $f0
/* 3906C 8005DC6C 00000000 */  nop       
/* 39070 8005DC70 45000031 */  bc1f      .L8005DD38
/* 39074 8005DC74 0000102D */   daddu    $v0, $zero, $zero
/* 39078 8005DC78 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 3907C 8005DC7C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 39080 8005DC80 8E660028 */  lw        $a2, 0x28($s3)
/* 39084 8005DC84 0C00A720 */  jal       atan2
/* 39088 8005DC88 8E670030 */   lw       $a3, 0x30($s3)
/* 3908C 8005DC8C 8E430074 */  lw        $v1, 0x74($s2)
/* 39090 8005DC90 2402FFFF */  addiu     $v0, $zero, -1
/* 39094 8005DC94 10620016 */  beq       $v1, $v0, .L8005DCF0
/* 39098 8005DC98 00000000 */   nop      
/* 3909C 8005DC9C 0801773E */  j         .L8005DCF8
/* 390A0 8005DCA0 00000000 */   nop      
.L8005DCA4:
/* 390A4 8005DCA4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 390A8 8005DCA8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 390AC 8005DCAC 8E660028 */  lw        $a2, 0x28($s3)
/* 390B0 8005DCB0 0C00A7B5 */  jal       dist2D
/* 390B4 8005DCB4 8E670030 */   lw       $a3, 0x30($s3)
/* 390B8 8005DCB8 C6220010 */  lwc1      $f2, 0x10($s1)
/* 390BC 8005DCBC 4602003E */  c.le.s    $f0, $f2
/* 390C0 8005DCC0 00000000 */  nop       
/* 390C4 8005DCC4 4500001C */  bc1f      .L8005DD38
/* 390C8 8005DCC8 0000102D */   daddu    $v0, $zero, $zero
/* 390CC 8005DCCC C62C0038 */  lwc1      $f12, 0x38($s1)
/* 390D0 8005DCD0 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 390D4 8005DCD4 8E660028 */  lw        $a2, 0x28($s3)
/* 390D8 8005DCD8 0C00A720 */  jal       atan2
/* 390DC 8005DCDC 8E670030 */   lw       $a3, 0x30($s3)
/* 390E0 8005DCE0 8E430074 */  lw        $v1, 0x74($s2)
/* 390E4 8005DCE4 2402FFFF */  addiu     $v0, $zero, -1
/* 390E8 8005DCE8 14620003 */  bne       $v1, $v0, .L8005DCF8
/* 390EC 8005DCEC 00000000 */   nop      
.L8005DCF0:
/* 390F0 8005DCF0 08017741 */  j         .L8005DD04
/* 390F4 8005DCF4 C62C000C */   lwc1     $f12, 0xc($s1)
.L8005DCF8:
/* 390F8 8005DCF8 44836000 */  mtc1      $v1, $f12
/* 390FC 8005DCFC 00000000 */  nop       
/* 39100 8005DD00 46806320 */  cvt.s.w   $f12, $f12
.L8005DD04:
/* 39104 8005DD04 0C00A70A */  jal       get_clamped_angle_diff
/* 39108 8005DD08 46000386 */   mov.s    $f14, $f0
/* 3910C 8005DD0C C6420078 */  lwc1      $f2, 0x78($s2)
/* 39110 8005DD10 468010A0 */  cvt.s.w   $f2, $f2
/* 39114 8005DD14 46000005 */  abs.s     $f0, $f0
/* 39118 8005DD18 4602003C */  c.lt.s    $f0, $f2
/* 3911C 8005DD1C 00000000 */  nop       
/* 39120 8005DD20 45000004 */  bc1f      .L8005DD34
/* 39124 8005DD24 24020001 */   addiu    $v0, $zero, 1
/* 39128 8005DD28 AE420084 */  sw        $v0, 0x84($s2)
/* 3912C 8005DD2C 0801774E */  j         .L8005DD38
/* 39130 8005DD30 24020002 */   addiu    $v0, $zero, 2
.L8005DD34:
/* 39134 8005DD34 0000102D */  daddu     $v0, $zero, $zero
.L8005DD38:
/* 39138 8005DD38 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3913C 8005DD3C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 39140 8005DD40 8FB20018 */  lw        $s2, 0x18($sp)
/* 39144 8005DD44 8FB10014 */  lw        $s1, 0x14($sp)
/* 39148 8005DD48 8FB00010 */  lw        $s0, 0x10($sp)
/* 3914C 8005DD4C 03E00008 */  jr        $ra
/* 39150 8005DD50 27BD0028 */   addiu    $sp, $sp, 0x28
