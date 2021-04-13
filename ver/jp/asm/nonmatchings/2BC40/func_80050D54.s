.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050D54
/* 2C154 80050D54 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 2C158 80050D58 AFB3001C */  sw        $s3, 0x1c($sp)
/* 2C15C 80050D5C 0080982D */  daddu     $s3, $a0, $zero
/* 2C160 80050D60 AFB00010 */  sw        $s0, 0x10($sp)
/* 2C164 80050D64 00A0802D */  daddu     $s0, $a1, $zero
/* 2C168 80050D68 AFB10014 */  sw        $s1, 0x14($sp)
/* 2C16C 80050D6C 00C0882D */  daddu     $s1, $a2, $zero
/* 2C170 80050D70 00111100 */  sll       $v0, $s1, 4
/* 2C174 80050D74 00511023 */  subu      $v0, $v0, $s1
/* 2C178 80050D78 000210C0 */  sll       $v0, $v0, 3
/* 2C17C 80050D7C 00511021 */  addu      $v0, $v0, $s1
/* 2C180 80050D80 00021080 */  sll       $v0, $v0, 2
/* 2C184 80050D84 24420024 */  addiu     $v0, $v0, 0x24
/* 2C188 80050D88 AFB20018 */  sw        $s2, 0x18($sp)
/* 2C18C 80050D8C 02629021 */  addu      $s2, $s3, $v0
/* 2C190 80050D90 0240202D */  daddu     $a0, $s2, $zero
/* 2C194 80050D94 240501E4 */  addiu     $a1, $zero, 0x1e4
/* 2C198 80050D98 AFBF0020 */  sw        $ra, 0x20($sp)
/* 2C19C 80050D9C 0C0152D0 */  jal       func_80054B40
/* 2C1A0 80050DA0 0000302D */   daddu    $a2, $zero, $zero
/* 2C1A4 80050DA4 AE500000 */  sw        $s0, ($s2)
/* 2C1A8 80050DA8 96030010 */  lhu       $v1, 0x10($s0)
/* 2C1AC 80050DAC 24020001 */  addiu     $v0, $zero, 1
/* 2C1B0 80050DB0 AE420018 */  sw        $v0, 0x18($s2)
/* 2C1B4 80050DB4 3C027F00 */  lui       $v0, 0x7f00
/* 2C1B8 80050DB8 AE420038 */  sw        $v0, 0x38($s2)
/* 2C1BC 80050DBC 2402007F */  addiu     $v0, $zero, 0x7f
/* 2C1C0 80050DC0 A2420042 */  sb        $v0, 0x42($s2)
/* 2C1C4 80050DC4 0200102D */  daddu     $v0, $s0, $zero
/* 2C1C8 80050DC8 A2510014 */  sb        $s1, 0x14($s2)
/* 2C1CC 80050DCC 02038021 */  addu      $s0, $s0, $v1
/* 2C1D0 80050DD0 AE500008 */  sw        $s0, 8($s2)
/* 2C1D4 80050DD4 AE500010 */  sw        $s0, 0x10($s2)
/* 2C1D8 80050DD8 AE50000C */  sw        $s0, 0xc($s2)
/* 2C1DC 80050DDC AE500004 */  sw        $s0, 4($s2)
/* 2C1E0 80050DE0 8C420008 */  lw        $v0, 8($v0)
/* 2C1E4 80050DE4 8E430000 */  lw        $v1, ($s2)
/* 2C1E8 80050DE8 AE420020 */  sw        $v0, 0x20($s2)
/* 2C1EC 80050DEC 9062000C */  lbu       $v0, 0xc($v1)
/* 2C1F0 80050DF0 AE420030 */  sw        $v0, 0x30($s2)
/* 2C1F4 80050DF4 24420010 */  addiu     $v0, $v0, 0x10
/* 2C1F8 80050DF8 AE420034 */  sw        $v0, 0x34($s2)
/* 2C1FC 80050DFC 2C420019 */  sltiu     $v0, $v0, 0x19
/* 2C200 80050E00 14400003 */  bnez      $v0, .L80050E10
/* 2C204 80050E04 0000282D */   daddu    $a1, $zero, $zero
/* 2C208 80050E08 24020018 */  addiu     $v0, $zero, 0x18
/* 2C20C 80050E0C AE420034 */  sw        $v0, 0x34($s2)
.L80050E10:
/* 2C210 80050E10 3C067FFF */  lui       $a2, 0x7fff
/* 2C214 80050E14 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 2C218 80050E18 24070040 */  addiu     $a3, $zero, 0x40
/* 2C21C 80050E1C 24040044 */  addiu     $a0, $zero, 0x44
.L80050E20:
/* 2C220 80050E20 02441821 */  addu      $v1, $s2, $a0
/* 2C224 80050E24 8E620000 */  lw        $v0, ($s3)
/* 2C228 80050E28 8C420004 */  lw        $v0, 4($v0)
/* 2C22C 80050E2C 24A50001 */  addiu     $a1, $a1, 1
/* 2C230 80050E30 AC660018 */  sw        $a2, 0x18($v1)
/* 2C234 80050E34 A0670024 */  sb        $a3, 0x24($v1)
/* 2C238 80050E38 AC620000 */  sw        $v0, ($v1)
/* 2C23C 80050E3C 28A2000A */  slti      $v0, $a1, 0xa
/* 2C240 80050E40 1440FFF7 */  bnez      $v0, .L80050E20
/* 2C244 80050E44 24840028 */   addiu    $a0, $a0, 0x28
/* 2C248 80050E48 24020001 */  addiu     $v0, $zero, 1
/* 2C24C 80050E4C A2420043 */  sb        $v0, 0x43($s2)
/* 2C250 80050E50 8FBF0020 */  lw        $ra, 0x20($sp)
/* 2C254 80050E54 8FB3001C */  lw        $s3, 0x1c($sp)
/* 2C258 80050E58 8FB20018 */  lw        $s2, 0x18($sp)
/* 2C25C 80050E5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 2C260 80050E60 8FB00010 */  lw        $s0, 0x10($sp)
/* 2C264 80050E64 03E00008 */  jr        $ra
/* 2C268 80050E68 27BD0028 */   addiu    $sp, $sp, 0x28
