.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A58
/* A3AF38 80241A58 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3AF3C 80241A5C AFB00018 */  sw        $s0, 0x18($sp)
/* A3AF40 80241A60 0080802D */  daddu     $s0, $a0, $zero
/* A3AF44 80241A64 10A00005 */  beqz      $a1, .L80241A7C
/* A3AF48 80241A68 AFBF001C */   sw       $ra, 0x1c($sp)
/* A3AF4C 80241A6C 24020040 */  addiu     $v0, $zero, 0x40
/* A3AF50 80241A70 AE020070 */  sw        $v0, 0x70($s0)
/* A3AF54 80241A74 AE020078 */  sw        $v0, 0x78($s0)
/* A3AF58 80241A78 AE000074 */  sw        $zero, 0x74($s0)
.L80241A7C:
/* A3AF5C 80241A7C 8E020074 */  lw        $v0, 0x74($s0)
/* A3AF60 80241A80 1440001A */  bnez      $v0, .L80241AEC
/* A3AF64 80241A84 00000000 */   nop      
/* A3AF68 80241A88 8E020070 */  lw        $v0, 0x70($s0)
/* A3AF6C 80241A8C 24420004 */  addiu     $v0, $v0, 4
/* A3AF70 80241A90 AE020070 */  sw        $v0, 0x70($s0)
/* A3AF74 80241A94 8E020078 */  lw        $v0, 0x78($s0)
/* A3AF78 80241A98 8E030070 */  lw        $v1, 0x70($s0)
/* A3AF7C 80241A9C 24420004 */  addiu     $v0, $v0, 4
/* A3AF80 80241AA0 28630080 */  slti      $v1, $v1, 0x80
/* A3AF84 80241AA4 14600003 */  bnez      $v1, .L80241AB4
/* A3AF88 80241AA8 AE020078 */   sw       $v0, 0x78($s0)
/* A3AF8C 80241AAC 2402007F */  addiu     $v0, $zero, 0x7f
/* A3AF90 80241AB0 AE020070 */  sw        $v0, 0x70($s0)
.L80241AB4:
/* A3AF94 80241AB4 8E020078 */  lw        $v0, 0x78($s0)
/* A3AF98 80241AB8 28420080 */  slti      $v0, $v0, 0x80
/* A3AF9C 80241ABC 14400002 */  bnez      $v0, .L80241AC8
/* A3AFA0 80241AC0 2402007F */   addiu    $v0, $zero, 0x7f
/* A3AFA4 80241AC4 AE020078 */  sw        $v0, 0x78($s0)
.L80241AC8:
/* A3AFA8 80241AC8 8E030070 */  lw        $v1, 0x70($s0)
/* A3AFAC 80241ACC 2402007F */  addiu     $v0, $zero, 0x7f
/* A3AFB0 80241AD0 14620014 */  bne       $v1, $v0, .L80241B24
/* A3AFB4 80241AD4 00000000 */   nop      
/* A3AFB8 80241AD8 8E020078 */  lw        $v0, 0x78($s0)
/* A3AFBC 80241ADC 14430011 */  bne       $v0, $v1, .L80241B24
/* A3AFC0 80241AE0 24020001 */   addiu    $v0, $zero, 1
/* A3AFC4 80241AE4 080906C9 */  j         .L80241B24
/* A3AFC8 80241AE8 AE020074 */   sw       $v0, 0x74($s0)
.L80241AEC:
/* A3AFCC 80241AEC 8E020070 */  lw        $v0, 0x70($s0)
/* A3AFD0 80241AF0 2442FFFC */  addiu     $v0, $v0, -4
/* A3AFD4 80241AF4 AE020070 */  sw        $v0, 0x70($s0)
/* A3AFD8 80241AF8 8E020078 */  lw        $v0, 0x78($s0)
/* A3AFDC 80241AFC 8E030070 */  lw        $v1, 0x70($s0)
/* A3AFE0 80241B00 2442FFFC */  addiu     $v0, $v0, -4
/* A3AFE4 80241B04 28630040 */  slti      $v1, $v1, 0x40
/* A3AFE8 80241B08 10600003 */  beqz      $v1, .L80241B18
/* A3AFEC 80241B0C AE020078 */   sw       $v0, 0x78($s0)
/* A3AFF0 80241B10 24020040 */  addiu     $v0, $zero, 0x40
/* A3AFF4 80241B14 AE020070 */  sw        $v0, 0x70($s0)
.L80241B18:
/* A3AFF8 80241B18 8E020078 */  lw        $v0, 0x78($s0)
/* A3AFFC 80241B1C 04420001 */  bltzl     $v0, .L80241B24
/* A3B000 80241B20 AE000078 */   sw       $zero, 0x78($s0)
.L80241B24:
/* A3B004 80241B24 92040073 */  lbu       $a0, 0x73($s0)
/* A3B008 80241B28 9207007B */  lbu       $a3, 0x7b($s0)
/* A3B00C 80241B2C 0080282D */  daddu     $a1, $a0, $zero
/* A3B010 80241B30 AFA70010 */  sw        $a3, 0x10($sp)
/* A3B014 80241B34 9202007B */  lbu       $v0, 0x7b($s0)
/* A3B018 80241B38 0080302D */  daddu     $a2, $a0, $zero
/* A3B01C 80241B3C 0C046FE6 */  jal       func_8011BF98
/* A3B020 80241B40 AFA20014 */   sw       $v0, 0x14($sp)
/* A3B024 80241B44 8E030070 */  lw        $v1, 0x70($s0)
/* A3B028 80241B48 24020040 */  addiu     $v0, $zero, 0x40
/* A3B02C 80241B4C 14620005 */  bne       $v1, $v0, .L80241B64
/* A3B030 80241B50 0000102D */   daddu    $v0, $zero, $zero
/* A3B034 80241B54 8E030078 */  lw        $v1, 0x78($s0)
/* A3B038 80241B58 10600002 */  beqz      $v1, .L80241B64
/* A3B03C 80241B5C 24020002 */   addiu    $v0, $zero, 2
/* A3B040 80241B60 0000102D */  daddu     $v0, $zero, $zero
.L80241B64:
/* A3B044 80241B64 8FBF001C */  lw        $ra, 0x1c($sp)
/* A3B048 80241B68 8FB00018 */  lw        $s0, 0x18($sp)
/* A3B04C 80241B6C 03E00008 */  jr        $ra
/* A3B050 80241B70 27BD0020 */   addiu    $sp, $sp, 0x20
