.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054AA0
/* 2FEA0 80054AA0 3C028008 */  lui       $v0, %hi(D_80078E54)
/* 2FEA4 80054AA4 8C428E54 */  lw        $v0, %lo(D_80078E54)($v0)
/* 2FEA8 80054AA8 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 2FEAC 80054AAC AFB60070 */  sw        $s6, 0x70($sp)
/* 2FEB0 80054AB0 0080B02D */  daddu     $s6, $a0, $zero
/* 2FEB4 80054AB4 AFB30064 */  sw        $s3, 0x64($sp)
/* 2FEB8 80054AB8 00A0982D */  daddu     $s3, $a1, $zero
/* 2FEBC 80054ABC AFB40068 */  sw        $s4, 0x68($sp)
/* 2FEC0 80054AC0 27B40018 */  addiu     $s4, $sp, 0x18
/* 2FEC4 80054AC4 AFBE0078 */  sw        $fp, 0x78($sp)
/* 2FEC8 80054AC8 0000F02D */  daddu     $fp, $zero, $zero
/* 2FECC 80054ACC AFB1005C */  sw        $s1, 0x5c($sp)
/* 2FED0 80054AD0 2411000B */  addiu     $s1, $zero, 0xb
/* 2FED4 80054AD4 AFB20060 */  sw        $s2, 0x60($sp)
/* 2FED8 80054AD8 24120001 */  addiu     $s2, $zero, 1
/* 2FEDC 80054ADC AFBF007C */  sw        $ra, 0x7c($sp)
/* 2FEE0 80054AE0 AFB70074 */  sw        $s7, 0x74($sp)
/* 2FEE4 80054AE4 AFB5006C */  sw        $s5, 0x6c($sp)
/* 2FEE8 80054AE8 AFB00058 */  sw        $s0, 0x58($sp)
/* 2FEEC 80054AEC AFA60088 */  sw        $a2, 0x88($sp)
/* 2FEF0 80054AF0 AFA7008C */  sw        $a3, 0x8c($sp)
/* 2FEF4 80054AF4 8C570018 */  lw        $s7, 0x18($v0)
/* 2FEF8 80054AF8 2402000B */  addiu     $v0, $zero, 0xb
.L80054AFC:
/* 2FEFC 80054AFC 1222000A */  beq       $s1, $v0, .L80054B28
/* 2FF00 80054B00 2E22000C */   sltiu    $v0, $s1, 0xc
/* 2FF04 80054B04 54400042 */  bnel      $v0, $zero, .L80054C10
/* 2FF08 80054B08 0000902D */   daddu    $s2, $zero, $zero
/* 2FF0C 80054B0C 24020015 */  addiu     $v0, $zero, 0x15
/* 2FF10 80054B10 12220015 */  beq       $s1, $v0, .L80054B68
/* 2FF14 80054B14 2402001F */   addiu    $v0, $zero, 0x1f
/* 2FF18 80054B18 52220035 */  beql      $s1, $v0, .L80054BF0
/* 2FF1C 80054B1C AFA00010 */   sw       $zero, 0x10($sp)
/* 2FF20 80054B20 08015304 */  j         .L80054C10
/* 2FF24 80054B24 0000902D */   daddu    $s2, $zero, $zero
.L80054B28:
/* 2FF28 80054B28 27A50018 */  addiu     $a1, $sp, 0x18
/* 2FF2C 80054B2C 8EC40000 */  lw        $a0, ($s6)
/* 2FF30 80054B30 0C015380 */  jal       snd_read_rom
/* 2FF34 80054B34 24060040 */   addiu    $a2, $zero, 0x40
/* 2FF38 80054B38 96830000 */  lhu       $v1, ($s4)
/* 2FF3C 80054B3C 2402424B */  addiu     $v0, $zero, 0x424b
/* 2FF40 80054B40 54620033 */  bnel      $v1, $v0, .L80054C10
/* 2FF44 80054B44 0000902D */   daddu    $s2, $zero, $zero
/* 2FF48 80054B48 8E820004 */  lw        $v0, 4($s4)
/* 2FF4C 80054B4C 1040002F */  beqz      $v0, .L80054C0C
/* 2FF50 80054B50 24024352 */   addiu    $v0, $zero, 0x4352
/* 2FF54 80054B54 9683000C */  lhu       $v1, 0xc($s4)
/* 2FF58 80054B58 5462002D */  bnel      $v1, $v0, .L80054C10
/* 2FF5C 80054B5C 0000902D */   daddu    $s2, $zero, $zero
/* 2FF60 80054B60 08015304 */  j         .L80054C10
/* 2FF64 80054B64 24110015 */   addiu    $s1, $zero, 0x15
.L80054B68:
/* 2FF68 80054B68 16600005 */  bnez      $s3, .L80054B80
/* 2FF6C 80054B6C 02E0202D */   daddu    $a0, $s7, $zero
/* 2FF70 80054B70 8E860004 */  lw        $a2, 4($s4)
/* 2FF74 80054B74 0C015FE4 */  jal       alHeapAlloc
/* 2FF78 80054B78 24050001 */   addiu    $a1, $zero, 1
/* 2FF7C 80054B7C 0040982D */  daddu     $s3, $v0, $zero
.L80054B80:
/* 2FF80 80054B80 8EC40000 */  lw        $a0, ($s6)
/* 2FF84 80054B84 8E860004 */  lw        $a2, 4($s4)
/* 2FF88 80054B88 0C015380 */  jal       snd_read_rom
/* 2FF8C 80054B8C 0260282D */   daddu    $a1, $s3, $zero
/* 2FF90 80054B90 8FA4008C */  lw        $a0, 0x8c($sp)
/* 2FF94 80054B94 8FA50088 */  lw        $a1, 0x88($sp)
/* 2FF98 80054B98 0C0151D1 */  jal       snd_get_BK_instruments
/* 2FF9C 80054B9C 0000802D */   daddu    $s0, $zero, $zero
/* 2FFA0 80054BA0 0040A82D */  daddu     $s5, $v0, $zero
/* 2FFA4 80054BA4 02A0182D */  daddu     $v1, $s5, $zero
/* 2FFA8 80054BA8 0200282D */  daddu     $a1, $s0, $zero
/* 2FFAC 80054BAC 0280202D */  daddu     $a0, $s4, $zero
.L80054BB0:
/* 2FFB0 80054BB0 94820012 */  lhu       $v0, 0x12($a0)
/* 2FFB4 80054BB4 10400004 */  beqz      $v0, .L80054BC8
/* 2FFB8 80054BB8 00531021 */   addu     $v0, $v0, $s3
/* 2FFBC 80054BBC 26100001 */  addiu     $s0, $s0, 1
/* 2FFC0 80054BC0 080152F3 */  j         .L80054BCC
/* 2FFC4 80054BC4 AC620000 */   sw       $v0, ($v1)
.L80054BC8:
/* 2FFC8 80054BC8 AC600000 */  sw        $zero, ($v1)
.L80054BCC:
/* 2FFCC 80054BCC 24630004 */  addiu     $v1, $v1, 4
/* 2FFD0 80054BD0 24A50001 */  addiu     $a1, $a1, 1
/* 2FFD4 80054BD4 2CA20010 */  sltiu     $v0, $a1, 0x10
/* 2FFD8 80054BD8 1440FFF5 */  bnez      $v0, .L80054BB0
/* 2FFDC 80054BDC 24840002 */   addiu    $a0, $a0, 2
/* 2FFE0 80054BE0 5200000B */  beql      $s0, $zero, .L80054C10
/* 2FFE4 80054BE4 0000902D */   daddu    $s2, $zero, $zero
/* 2FFE8 80054BE8 08015304 */  j         .L80054C10
/* 2FFEC 80054BEC 2411001F */   addiu    $s1, $zero, 0x1f
.L80054BF0:
/* 2FFF0 80054BF0 0260202D */  daddu     $a0, $s3, $zero
/* 2FFF4 80054BF4 0260282D */  daddu     $a1, $s3, $zero
/* 2FFF8 80054BF8 02A0302D */  daddu     $a2, $s5, $zero
/* 2FFFC 80054BFC 0C01527E */  jal       snd_swizzle_BK_instruments
/* 30000 80054C00 24070010 */   addiu    $a3, $zero, 0x10
/* 30004 80054C04 08015304 */  j         .L80054C10
/* 30008 80054C08 0000882D */   daddu    $s1, $zero, $zero
.L80054C0C:
/* 3000C 80054C0C 0000902D */  daddu     $s2, $zero, $zero
.L80054C10:
/* 30010 80054C10 1640FFBA */  bnez      $s2, .L80054AFC
/* 30014 80054C14 2402000B */   addiu    $v0, $zero, 0xb
/* 30018 80054C18 0260102D */  daddu     $v0, $s3, $zero
/* 3001C 80054C1C 8FBF007C */  lw        $ra, 0x7c($sp)
/* 30020 80054C20 8FBE0078 */  lw        $fp, 0x78($sp)
/* 30024 80054C24 8FB70074 */  lw        $s7, 0x74($sp)
/* 30028 80054C28 8FB60070 */  lw        $s6, 0x70($sp)
/* 3002C 80054C2C 8FB5006C */  lw        $s5, 0x6c($sp)
/* 30030 80054C30 8FB40068 */  lw        $s4, 0x68($sp)
/* 30034 80054C34 8FB30064 */  lw        $s3, 0x64($sp)
/* 30038 80054C38 8FB20060 */  lw        $s2, 0x60($sp)
/* 3003C 80054C3C 8FB1005C */  lw        $s1, 0x5c($sp)
/* 30040 80054C40 8FB00058 */  lw        $s0, 0x58($sp)
/* 30044 80054C44 03E00008 */  jr        $ra
/* 30048 80054C48 27BD0080 */   addiu    $sp, $sp, 0x80
