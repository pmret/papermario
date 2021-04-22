.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005FC40
/* 3B040 8005FC40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3B044 8005FC44 AFB00010 */  sw        $s0, 0x10($sp)
/* 3B048 8005FC48 0080802D */  daddu     $s0, $a0, $zero
/* 3B04C 8005FC4C AFB10014 */  sw        $s1, 0x14($sp)
/* 3B050 8005FC50 00A0882D */  daddu     $s1, $a1, $zero
/* 3B054 8005FC54 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3B058 8005FC58 0C018244 */  jal       func_80060910
/* 3B05C 8005FC5C 24040001 */   addiu    $a0, $zero, 1
/* 3B060 8005FC60 0220202D */  daddu     $a0, $s1, $zero
/* 3B064 8005FC64 00101880 */  sll       $v1, $s0, 2
/* 3B068 8005FC68 00701821 */  addu      $v1, $v1, $s0
/* 3B06C 8005FC6C 00032840 */  sll       $a1, $v1, 1
/* 3B070 8005FC70 3C03800B */  lui       $v1, %hi(D_800B1D27)
/* 3B074 8005FC74 00651821 */  addu      $v1, $v1, $a1
/* 3B078 8005FC78 90631D27 */  lbu       $v1, %lo(D_800B1D27)($v1)
/* 3B07C 8005FC7C 308400FF */  andi      $a0, $a0, 0xff
/* 3B080 8005FC80 30660080 */  andi      $a2, $v1, 0x80
/* 3B084 8005FC84 24030001 */  addiu     $v1, $zero, 1
/* 3B088 8005FC88 1083000C */  beq       $a0, $v1, .L8005FCBC
/* 3B08C 8005FC8C 0040382D */   daddu    $a3, $v0, $zero
/* 3B090 8005FC90 28820002 */  slti      $v0, $a0, 2
/* 3B094 8005FC94 10400005 */  beqz      $v0, .L8005FCAC
/* 3B098 8005FC98 24020002 */   addiu    $v0, $zero, 2
/* 3B09C 8005FC9C 1080000D */  beqz      $a0, .L8005FCD4
/* 3B0A0 8005FCA0 02261025 */   or       $v0, $s1, $a2
/* 3B0A4 8005FCA4 08017F4A */  j         .L8005FD28
/* 3B0A8 8005FCA8 00000000 */   nop
.L8005FCAC:
/* 3B0AC 8005FCAC 1082000E */  beq       $a0, $v0, .L8005FCE8
/* 3B0B0 8005FCB0 02261025 */   or       $v0, $s1, $a2
/* 3B0B4 8005FCB4 08017F4A */  j         .L8005FD28
/* 3B0B8 8005FCB8 00000000 */   nop
.L8005FCBC:
/* 3B0BC 8005FCBC 3C03800B */  lui       $v1, %hi(D_800B1D29)
/* 3B0C0 8005FCC0 00651821 */  addu      $v1, $v1, $a1
/* 3B0C4 8005FCC4 90631D29 */  lbu       $v1, %lo(D_800B1D29)($v1)
/* 3B0C8 8005FCC8 24020002 */  addiu     $v0, $zero, 2
/* 3B0CC 8005FCCC 14620016 */  bne       $v1, $v0, .L8005FD28
/* 3B0D0 8005FCD0 02261025 */   or       $v0, $s1, $a2
.L8005FCD4:
/* 3B0D4 8005FCD4 3C01800B */  lui       $at, %hi(D_800B1D27)
/* 3B0D8 8005FCD8 00250821 */  addu      $at, $at, $a1
/* 3B0DC 8005FCDC A0221D27 */  sb        $v0, %lo(D_800B1D27)($at)
/* 3B0E0 8005FCE0 08017F4A */  j         .L8005FD28
/* 3B0E4 8005FCE4 00000000 */   nop
.L8005FCE8:
/* 3B0E8 8005FCE8 3C01800B */  lui       $at, %hi(D_800B1D27)
/* 3B0EC 8005FCEC 00250821 */  addu      $at, $at, $a1
/* 3B0F0 8005FCF0 A0221D27 */  sb        $v0, %lo(D_800B1D27)($at)
/* 3B0F4 8005FCF4 3C02800B */  lui       $v0, %hi(D_800B1D29)
/* 3B0F8 8005FCF8 00451021 */  addu      $v0, $v0, $a1
/* 3B0FC 8005FCFC 90421D29 */  lbu       $v0, %lo(D_800B1D29)($v0)
/* 3B100 8005FD00 14440006 */  bne       $v0, $a0, .L8005FD1C
/* 3B104 8005FD04 00000000 */   nop
/* 3B108 8005FD08 3C01800B */  lui       $at, %hi(D_800B1D28)
/* 3B10C 8005FD0C 00250821 */  addu      $at, $at, $a1
/* 3B110 8005FD10 A0231D28 */  sb        $v1, %lo(D_800B1D28)($at)
/* 3B114 8005FD14 08017F4A */  j         .L8005FD28
/* 3B118 8005FD18 00000000 */   nop
.L8005FD1C:
/* 3B11C 8005FD1C 3C01800B */  lui       $at, %hi(D_800B1D28)
/* 3B120 8005FD20 00250821 */  addu      $at, $at, $a1
/* 3B124 8005FD24 A0201D28 */  sb        $zero, %lo(D_800B1D28)($at)
.L8005FD28:
/* 3B128 8005FD28 0C018244 */  jal       func_80060910
/* 3B12C 8005FD2C 00E0202D */   daddu    $a0, $a3, $zero
/* 3B130 8005FD30 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3B134 8005FD34 8FB10014 */  lw        $s1, 0x14($sp)
/* 3B138 8005FD38 8FB00010 */  lw        $s0, 0x10($sp)
/* 3B13C 8005FD3C 03E00008 */  jr        $ra
/* 3B140 8005FD40 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3B144 8005FD44 00000000 */  nop
/* 3B148 8005FD48 00000000 */  nop
/* 3B14C 8005FD4C 00000000 */  nop
