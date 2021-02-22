.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054750
/* 2FB50 80054750 3C028008 */  lui       $v0, %hi(D_80078E24)
/* 2FB54 80054754 8C428E24 */  lw        $v0, %lo(D_80078E24)($v0)
/* 2FB58 80054758 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 2FB5C 8005475C AFB60070 */  sw        $s6, 0x70($sp)
/* 2FB60 80054760 0080B02D */  daddu     $s6, $a0, $zero
/* 2FB64 80054764 AFB30064 */  sw        $s3, 0x64($sp)
/* 2FB68 80054768 00A0982D */  daddu     $s3, $a1, $zero
/* 2FB6C 8005476C AFB40068 */  sw        $s4, 0x68($sp)
/* 2FB70 80054770 27B40018 */  addiu     $s4, $sp, 0x18
/* 2FB74 80054774 AFBE0078 */  sw        $fp, 0x78($sp)
/* 2FB78 80054778 0000F02D */  daddu     $fp, $zero, $zero
/* 2FB7C 8005477C AFB1005C */  sw        $s1, 0x5c($sp)
/* 2FB80 80054780 2411000B */  addiu     $s1, $zero, 0xb
/* 2FB84 80054784 AFB20060 */  sw        $s2, 0x60($sp)
/* 2FB88 80054788 24120001 */  addiu     $s2, $zero, 1
/* 2FB8C 8005478C AFBF007C */  sw        $ra, 0x7c($sp)
/* 2FB90 80054790 AFB70074 */  sw        $s7, 0x74($sp)
/* 2FB94 80054794 AFB5006C */  sw        $s5, 0x6c($sp)
/* 2FB98 80054798 AFB00058 */  sw        $s0, 0x58($sp)
/* 2FB9C 8005479C AFA60088 */  sw        $a2, 0x88($sp)
/* 2FBA0 800547A0 AFA7008C */  sw        $a3, 0x8c($sp)
/* 2FBA4 800547A4 8C570018 */  lw        $s7, 0x18($v0)
/* 2FBA8 800547A8 2402000B */  addiu     $v0, $zero, 0xb
.L800547AC:
/* 2FBAC 800547AC 1222000A */  beq       $s1, $v0, .L800547D8
/* 2FBB0 800547B0 2E22000C */   sltiu    $v0, $s1, 0xc
/* 2FBB4 800547B4 54400042 */  bnel      $v0, $zero, .L800548C0
/* 2FBB8 800547B8 0000902D */   daddu    $s2, $zero, $zero
/* 2FBBC 800547BC 24020015 */  addiu     $v0, $zero, 0x15
/* 2FBC0 800547C0 12220015 */  beq       $s1, $v0, .L80054818
/* 2FBC4 800547C4 2402001F */   addiu    $v0, $zero, 0x1f
/* 2FBC8 800547C8 52220035 */  beql      $s1, $v0, .L800548A0
/* 2FBCC 800547CC AFA00010 */   sw       $zero, 0x10($sp)
/* 2FBD0 800547D0 08015230 */  j         .L800548C0
/* 2FBD4 800547D4 0000902D */   daddu    $s2, $zero, $zero
.L800547D8:
/* 2FBD8 800547D8 27A50018 */  addiu     $a1, $sp, 0x18
/* 2FBDC 800547DC 8EC40000 */  lw        $a0, ($s6)
/* 2FBE0 800547E0 0C0152AC */  jal       func_80054AB0
/* 2FBE4 800547E4 24060040 */   addiu    $a2, $zero, 0x40
/* 2FBE8 800547E8 96830000 */  lhu       $v1, ($s4)
/* 2FBEC 800547EC 2402424B */  addiu     $v0, $zero, 0x424b
/* 2FBF0 800547F0 54620033 */  bnel      $v1, $v0, .L800548C0
/* 2FBF4 800547F4 0000902D */   daddu    $s2, $zero, $zero
/* 2FBF8 800547F8 8E820004 */  lw        $v0, 4($s4)
/* 2FBFC 800547FC 1040002F */  beqz      $v0, .L800548BC
/* 2FC00 80054800 24024352 */   addiu    $v0, $zero, 0x4352
/* 2FC04 80054804 9683000C */  lhu       $v1, 0xc($s4)
/* 2FC08 80054808 5462002D */  bnel      $v1, $v0, .L800548C0
/* 2FC0C 8005480C 0000902D */   daddu    $s2, $zero, $zero
/* 2FC10 80054810 08015230 */  j         .L800548C0
/* 2FC14 80054814 24110015 */   addiu    $s1, $zero, 0x15
.L80054818:
/* 2FC18 80054818 16600005 */  bnez      $s3, .L80054830
/* 2FC1C 8005481C 02E0202D */   daddu    $a0, $s7, $zero
/* 2FC20 80054820 8E860004 */  lw        $a2, 4($s4)
/* 2FC24 80054824 0C015F10 */  jal       func_80057C40
/* 2FC28 80054828 24050001 */   addiu    $a1, $zero, 1
/* 2FC2C 8005482C 0040982D */  daddu     $s3, $v0, $zero
.L80054830:
/* 2FC30 80054830 8EC40000 */  lw        $a0, ($s6)
/* 2FC34 80054834 8E860004 */  lw        $a2, 4($s4)
/* 2FC38 80054838 0C0152AC */  jal       func_80054AB0
/* 2FC3C 8005483C 0260282D */   daddu    $a1, $s3, $zero
/* 2FC40 80054840 8FA4008C */  lw        $a0, 0x8c($sp)
/* 2FC44 80054844 8FA50088 */  lw        $a1, 0x88($sp)
/* 2FC48 80054848 0C0150FD */  jal       func_800543F4
/* 2FC4C 8005484C 0000802D */   daddu    $s0, $zero, $zero
/* 2FC50 80054850 0040A82D */  daddu     $s5, $v0, $zero
/* 2FC54 80054854 02A0182D */  daddu     $v1, $s5, $zero
/* 2FC58 80054858 0200282D */  daddu     $a1, $s0, $zero
/* 2FC5C 8005485C 0280202D */  daddu     $a0, $s4, $zero
.L80054860:
/* 2FC60 80054860 94820012 */  lhu       $v0, 0x12($a0)
/* 2FC64 80054864 10400004 */  beqz      $v0, .L80054878
/* 2FC68 80054868 00531021 */   addu     $v0, $v0, $s3
/* 2FC6C 8005486C 26100001 */  addiu     $s0, $s0, 1
/* 2FC70 80054870 0801521F */  j         .L8005487C
/* 2FC74 80054874 AC620000 */   sw       $v0, ($v1)
.L80054878:
/* 2FC78 80054878 AC600000 */  sw        $zero, ($v1)
.L8005487C:
/* 2FC7C 8005487C 24630004 */  addiu     $v1, $v1, 4
/* 2FC80 80054880 24A50001 */  addiu     $a1, $a1, 1
/* 2FC84 80054884 2CA20010 */  sltiu     $v0, $a1, 0x10
/* 2FC88 80054888 1440FFF5 */  bnez      $v0, .L80054860
/* 2FC8C 8005488C 24840002 */   addiu    $a0, $a0, 2
/* 2FC90 80054890 5200000B */  beql      $s0, $zero, .L800548C0
/* 2FC94 80054894 0000902D */   daddu    $s2, $zero, $zero
/* 2FC98 80054898 08015230 */  j         .L800548C0
/* 2FC9C 8005489C 2411001F */   addiu    $s1, $zero, 0x1f
.L800548A0:
/* 2FCA0 800548A0 0260202D */  daddu     $a0, $s3, $zero
/* 2FCA4 800548A4 0260282D */  daddu     $a1, $s3, $zero
/* 2FCA8 800548A8 02A0302D */  daddu     $a2, $s5, $zero
/* 2FCAC 800548AC 0C0151AA */  jal       func_800546A8
/* 2FCB0 800548B0 24070010 */   addiu    $a3, $zero, 0x10
/* 2FCB4 800548B4 08015230 */  j         .L800548C0
/* 2FCB8 800548B8 0000882D */   daddu    $s1, $zero, $zero
.L800548BC:
/* 2FCBC 800548BC 0000902D */  daddu     $s2, $zero, $zero
.L800548C0:
/* 2FCC0 800548C0 1640FFBA */  bnez      $s2, .L800547AC
/* 2FCC4 800548C4 2402000B */   addiu    $v0, $zero, 0xb
/* 2FCC8 800548C8 0260102D */  daddu     $v0, $s3, $zero
/* 2FCCC 800548CC 8FBF007C */  lw        $ra, 0x7c($sp)
/* 2FCD0 800548D0 8FBE0078 */  lw        $fp, 0x78($sp)
/* 2FCD4 800548D4 8FB70074 */  lw        $s7, 0x74($sp)
/* 2FCD8 800548D8 8FB60070 */  lw        $s6, 0x70($sp)
/* 2FCDC 800548DC 8FB5006C */  lw        $s5, 0x6c($sp)
/* 2FCE0 800548E0 8FB40068 */  lw        $s4, 0x68($sp)
/* 2FCE4 800548E4 8FB30064 */  lw        $s3, 0x64($sp)
/* 2FCE8 800548E8 8FB20060 */  lw        $s2, 0x60($sp)
/* 2FCEC 800548EC 8FB1005C */  lw        $s1, 0x5c($sp)
/* 2FCF0 800548F0 8FB00058 */  lw        $s0, 0x58($sp)
/* 2FCF4 800548F4 03E00008 */  jr        $ra
/* 2FCF8 800548F8 27BD0080 */   addiu    $sp, $sp, 0x80
