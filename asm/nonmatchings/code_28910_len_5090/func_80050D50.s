.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050D50
/* 2C150 80050D50 0080302D */  daddu     $a2, $a0, $zero
/* 2C154 80050D54 240300FF */  addiu     $v1, $zero, 0xff
/* 2C158 80050D58 90C2002A */  lbu       $v0, 0x2a($a2)
/* 2C15C 80050D5C 94C50028 */  lhu       $a1, 0x28($a2)
/* 2C160 80050D60 14430004 */  bne       $v0, $v1, .L80050D74
/* 2C164 80050D64 24A2FF06 */   addiu    $v0, $a1, -0xfa
/* 2C168 80050D68 80C20038 */  lb        $v0, 0x38($a2)
/* 2C16C 80050D6C A0C2002A */  sb        $v0, 0x2a($a2)
/* 2C170 80050D70 24A2FF06 */  addiu     $v0, $a1, -0xfa
.L80050D74:
/* 2C174 80050D74 3042FFFF */  andi      $v0, $v0, 0xffff
/* 2C178 80050D78 2C422617 */  sltiu     $v0, $v0, 0x2617
/* 2C17C 80050D7C 10400022 */  beqz      $v0, .L80050E08
/* 2C180 80050D80 3C041CF0 */   lui      $a0, 0x1cf0
/* 2C184 80050D84 34846ADB */  ori       $a0, $a0, 0x6adb
/* 2C188 80050D88 30A3FFFF */  andi      $v1, $a1, 0xffff
/* 2C18C 80050D8C 00031080 */  sll       $v0, $v1, 2
/* 2C190 80050D90 00431021 */  addu      $v0, $v0, $v1
/* 2C194 80050D94 00021040 */  sll       $v0, $v0, 1
/* 2C198 80050D98 00440019 */  multu     $v0, $a0
/* 2C19C 80050D9C 90C3002B */  lbu       $v1, 0x2b($a2)
/* 2C1A0 80050DA0 00002010 */  mfhi      $a0
/* 2C1A4 80050DA4 00441023 */  subu      $v0, $v0, $a0
/* 2C1A8 80050DA8 00021042 */  srl       $v0, $v0, 1
/* 2C1AC 80050DAC 00822021 */  addu      $a0, $a0, $v0
/* 2C1B0 80050DB0 90C2002A */  lbu       $v0, 0x2a($a2)
/* 2C1B4 80050DB4 00042182 */  srl       $a0, $a0, 6
/* 2C1B8 80050DB8 00621823 */  subu      $v1, $v1, $v0
/* 2C1BC 80050DBC 00031E00 */  sll       $v1, $v1, 0x18
/* 2C1C0 80050DC0 3082FFFF */  andi      $v0, $a0, 0xffff
/* 2C1C4 80050DC4 14400002 */  bnez      $v0, .L80050DD0
/* 2C1C8 80050DC8 0062001A */   div      $zero, $v1, $v0
/* 2C1CC 80050DCC 0007000D */  break     7
.L80050DD0:
/* 2C1D0 80050DD0 2401FFFF */   addiu    $at, $zero, -1
/* 2C1D4 80050DD4 14410004 */  bne       $v0, $at, .L80050DE8
/* 2C1D8 80050DD8 3C018000 */   lui      $at, 0x8000
/* 2C1DC 80050DDC 14610002 */  bne       $v1, $at, .L80050DE8
/* 2C1E0 80050DE0 00000000 */   nop
/* 2C1E4 80050DE4 0006000D */  break     6
.L80050DE8:
/* 2C1E8 80050DE8 00001812 */   mflo     $v1
/* 2C1EC 80050DEC 90C5002B */  lbu       $a1, 0x2b($a2)
/* 2C1F0 80050DF0 90C2002A */  lbu       $v0, 0x2a($a2)
/* 2C1F4 80050DF4 A0C50042 */  sb        $a1, 0x42($a2)
/* 2C1F8 80050DF8 A4C40040 */  sh        $a0, 0x40($a2)
/* 2C1FC 80050DFC 00021600 */  sll       $v0, $v0, 0x18
/* 2C200 80050E00 ACC20038 */  sw        $v0, 0x38($a2)
/* 2C204 80050E04 ACC3003C */  sw        $v1, 0x3c($a2)
.L80050E08:
/* 2C208 80050E08 A4C00028 */  sh        $zero, 0x28($a2)
/* 2C20C 80050E0C A0C0002A */  sb        $zero, 0x2a($a2)
/* 2C210 80050E10 03E00008 */  jr        $ra
/* 2C214 80050E14 A0C0002B */   sb       $zero, 0x2b($a2)
